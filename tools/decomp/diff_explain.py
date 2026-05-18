#!/usr/bin/env python3
"""Classify diff bytes from diff_fn_obj.py and suggest fixes.

After fast_try.py reports diffs, this script analyzes the bytes
around each mismatch and tries to identify the class of issue:

  * register choice (a1 eax-form vs 8b 0d/15 reg-form)
  * sar vs shr (signed vs unsigned shift)
  * sub vs add-neg (sub imm32 vs add -imm32, both 5 bytes)
  * je <-> jne polarity (inverted condition)
  * call-vs-jmp tail (no tail-call-opt vs tail-call-opt)
  * add direction (03 c2 vs 03 d0 — same op, different result reg)
  * store-order (consecutive [m32] stores swapped)
  * shl vs SIB-scaled (c1 e0 02 + disp8 vs SIB *4 + disp32)
  * length-mismatch (rebuilt size != orig size — MSVC merged/optimized)

For each diff cluster, prints a brief diagnosis and a suggested
remediation (with reference to memory file when applicable).

Usage:
    python3 tools/decomp/diff_explain.py <obj> <symbol> <addr> <size>
or (piped from diff_fn_obj output):
    python3 tools/decomp/diff_explain.py --diff-line "orig=a1 new=8b" ...
"""
import struct
import sys
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent

# Diagnosis catalog: (orig_byte, new_byte, context_pattern, diagnosis, hint, memory_ref)
# context_pattern matches against (prev_byte, next_byte) tuple when present.
SINGLE_BYTE_DIAGNOSES = [
    # Shift direction (sar vs shr)
    (0xf8, 0xe8, "shr_vs_sar",
     "shr/sar mismatch: orig uses sar (signed), new uses shr (unsigned)",
     "declare the shifted value as 'int', not 'unsigned int'",
     "feedback_unsigned_for_shr_not_sar"),
    (0xe8, 0xf8, "sar_vs_shr",
     "shr/sar mismatch: orig uses shr (unsigned), new uses sar (signed)",
     "declare the shifted arg/value as 'unsigned int'",
     "feedback_unsigned_for_shr_not_sar"),
    # mov eax,[m32] short form (a1) vs generic (8b XX disp32)
    (0xa1, 0x8b,
     "a1_vs_8b_eax",
     "orig uses 'a1 imm32' (mov eax, [m32], 5b); new uses '8b reg32' (6b)",
     "MSVC prefers eax for first global load via a1; rearrange to put the variable in eax (declare it first / use it as primary)",
     "feedback_mov_eax_a1_form_choice"),
    (0x8b, 0xa1,
     "8b_vs_a1_eax",
     "orig uses generic 'mov reg, [m32]' (6b); new uses 'a1 imm32' (5b)",
     "MSVC inlined to eax; force a non-eax target by swapping local decl order or adding intermediate use of eax",
     "feedback_mov_eax_a1_form_choice"),
    # jcc polarity
    (0x74, 0x75, "je_vs_jne", "je <-> jne polarity inverted", "swap the condition (== <-> !=) OR restructure if/else", None),
    (0x75, 0x74, "jne_vs_je", "jne <-> je polarity inverted", "swap the condition (== <-> !=)", None),
    (0x7c, 0x7d, "jl_vs_jge", "jl <-> jge polarity", "invert the comparison (< <-> >=)", None),
    (0x7d, 0x7c, "jge_vs_jl", "jge <-> jl polarity", "invert the comparison", None),
    (0x7e, 0x7f, "jle_vs_jg", "jle <-> jg polarity", "invert the comparison", None),
    (0x7f, 0x7e, "jg_vs_jle", "jg <-> jle polarity", "invert the comparison", None),
    # sub vs add-neg
    (0x2d, 0x05, "sub_vs_add_neg", "orig: 'sub eax, imm32' (2d); new: 'add eax, -imm32' (05)",
     "MSVC SP3 picks one or the other based on heuristics; usually not coaxable",
     "feedback_sub_vs_add_neg"),
    (0x05, 0x2d, "add_neg_vs_sub", "orig: 'add eax, -imm32' (05); new: 'sub eax, imm32' (2d)",
     "swap the operand or use 'add x, -CONST' explicitly",
     "feedback_sub_vs_add_neg"),
    # call (e8) vs jmp (e9) at function end — tail call optimization
    (0xe9, 0xe8, "jmp_vs_call",
     "orig uses 'jmp' (tail-call optimized); new uses 'call'",
     "for the last call before ret/end, use 'return ((int(*)())F)();' to trigger MSVC tail-call",
     "feedback_int_return_for_pause_load"),
    (0xe8, 0xe9, "call_vs_jmp",
     "orig uses 'call'; new uses 'jmp' (tail-call optimized)",
     "place an instruction after the call to defeat tail-call-opt (e.g., assign to a global)",
     None),
    # store dest reg (89 0d ecx vs 89 15 edx vs 89 05 eax)
    (0x05, 0x0d, "store_eax_vs_ecx", "store dest reg: orig stores eax (89 05), new stores ecx (89 0d)",
     "swap local decl order so the stored value is in eax (often: declare it first)", None),
    (0x05, 0x15, "store_eax_vs_edx", "store dest reg: orig stores eax (89 05), new stores edx (89 15)",
     "swap local decl order so the stored value is in eax", None),
    (0x0d, 0x05, "store_ecx_vs_eax", "store dest reg: orig stores ecx (89 0d), new stores eax (89 05)",
     "force ecx by keeping a different variable in eax", None),
    (0x15, 0x05, "store_edx_vs_eax", "store dest reg: orig stores edx (89 15), new stores eax (89 05)",
     "force edx by keeping a different variable in eax", None),
    # a3 vs 89 05 (eax store short vs generic)
    (0xa3, 0x89, "a3_vs_89_eax", "orig 'a3 imm32' (5b) vs new '89 ?? imm32' (6b) for eax store",
     "MSVC chose to use ecx/edx for store; reorder to keep eax", None),
]

# 2-byte add-direction (03 c2 vs 03 d0)
ADD_REG_REG_MAP = {
    0xc0: ("eax", "eax"), 0xc1: ("eax", "ecx"), 0xc2: ("eax", "edx"), 0xc3: ("eax", "ebx"),
    0xc8: ("ecx", "eax"), 0xc9: ("ecx", "ecx"), 0xca: ("ecx", "edx"), 0xcb: ("ecx", "ebx"),
    0xd0: ("edx", "eax"), 0xd1: ("edx", "ecx"), 0xd2: ("edx", "edx"), 0xd3: ("edx", "ebx"),
    0xd8: ("ebx", "eax"), 0xd9: ("ebx", "ecx"), 0xda: ("ebx", "edx"), 0xdb: ("ebx", "ebx"),
}


def parse_diff_output(output):
    """Parse output from diff_fn_obj.py. Returns (orig_hex, new_hex, diffs)."""
    orig_hex = None
    new_hex = None
    diffs = []
    for line in output.split('\n'):
        m = re.match(r'\s*orig\s*:\s*([0-9a-fA-F]+)', line)
        if m:
            orig_hex = m.group(1)
            continue
        m = re.match(r'\s*rebuilt\s*:\s*([0-9a-fA-F]+)', line)
        if m:
            new_hex = m.group(1)
            continue
        m = re.match(r'\s*\+(0x[0-9a-fA-F]+):\s*orig=([0-9a-fA-F]+)\s+new=([0-9a-fA-F]+)', line)
        if m:
            diffs.append((int(m.group(1), 16), int(m.group(2), 16), int(m.group(3), 16)))
    return orig_hex, new_hex, diffs


def classify_diff(orig_bytes, new_bytes, offset, ob, nb):
    """Classify a single diff. Returns list of (diagnosis, hint, memory_ref)."""
    hits = []

    # Single-byte direct matches
    for (orig_b, new_b, tag, diag, hint, mem) in SINGLE_BYTE_DIAGNOSES:
        if ob == orig_b and nb == new_b:
            hits.append((tag, diag, hint, mem))

    # Context check: add direction (look for 03 prefix before the byte)
    prev = orig_bytes[offset-1] if offset > 0 and offset-1 < len(orig_bytes) else None
    if prev == 0x03 and ob in ADD_REG_REG_MAP and nb in ADD_REG_REG_MAP:
        dst_orig, src_orig = ADD_REG_REG_MAP[ob]
        dst_new, src_new = ADD_REG_REG_MAP[nb]
        if {dst_orig, src_orig} == {dst_new, src_new} and dst_orig != dst_new:
            hits.append((
                'add_direction',
                f'add direction: orig adds into {dst_orig}, new adds into {dst_new}',
                "swap operand order or use compound-assign on the right variable; usually not coaxable",
                None,
            ))

    # Context check: SIB byte (85 vs 8d) for [eax*4 + m32] vs [reg + m32]
    # 04 85 = [eax*4 + disp32], 04 8d = [ecx*4 + disp32]
    if prev == 0x04 and ob == 0x85 and nb == 0x8d:
        hits.append((
            'sib_eax_vs_ecx',
            'SIB index: orig uses [eax*4 + ...], new uses [ecx*4 + ...]',
            "swap local decl order to force the index into eax",
            "feedback_src_dst_decl_order_register",
        ))
    if prev == 0x04 and ob == 0x8d and nb == 0x85:
        hits.append((
            'sib_ecx_vs_eax',
            'SIB index: orig uses [ecx*4 + ...], new uses [eax*4 + ...]',
            "swap local decl order to force the index into ecx",
            "feedback_src_dst_decl_order_register",
        ))

    return hits


def explain(orig_hex, new_hex, diffs):
    if orig_hex is None or new_hex is None:
        print("ERROR: could not parse diff output", file=sys.stderr)
        return 1
    if len(orig_hex) != len(new_hex):
        print(f"SIZE MISMATCH: orig {len(orig_hex)//2} bytes vs rebuilt {len(new_hex)//2} bytes")
        print("MSVC merged/optimized away instructions (common with redundant loads, dec_jcc, or alias-store elimination).")
        return 0
    if not diffs:
        print("No diffs: function matches at the OBJ level. Run try_conv.py for full synth.")
        return 0

    orig_bytes = bytes.fromhex(orig_hex)
    new_bytes = bytes.fromhex(new_hex)
    print(f"Analyzing {len(diffs)} diff(s) in {len(orig_bytes)}-byte function:\n")

    # Cluster diffs into groups of consecutive bytes
    clusters = []
    cur = None
    for off, ob, nb in diffs:
        if cur is None or off > cur[-1][0] + 2:
            cur = [(off, ob, nb)]
            clusters.append(cur)
        else:
            cur.append((off, ob, nb))

    by_tag = {}
    for cluster in clusters:
        off, ob, nb = cluster[0]
        hits = classify_diff(orig_bytes, new_bytes, off, ob, nb)
        if not hits:
            # Try other bytes in the cluster too
            for cd in cluster[1:]:
                hits = classify_diff(orig_bytes, new_bytes, *cd)
                if hits:
                    break
        if not hits:
            print(f"  +{off:#06x}: orig={ob:02x} new={nb:02x}  (unclassified)")
            continue
        # Print first hit
        tag, diag, hint, mem = hits[0]
        print(f"  +{off:#06x}: {diag}")
        print(f"           hint: {hint}")
        if mem:
            print(f"           see:  memory/{mem}.md")
        by_tag[tag] = by_tag.get(tag, 0) + 1

    print()
    if by_tag:
        print("Summary by class:")
        for tag, n in sorted(by_tag.items(), key=lambda x: -x[1]):
            print(f"  {n:>3}  {tag}")

    # Recommend overall action
    print()
    classes = set(by_tag.keys())
    if classes & {"add_direction", "sub_vs_add_neg", "add_neg_vs_sub"}:
        print("ACTION: at least one diff is a non-coaxable register/operand-order issue. Likely keep naked.")
    elif classes & {"a1_vs_8b_eax", "8b_vs_a1_eax", "sib_eax_vs_ecx", "sib_ecx_vs_eax",
                    "store_eax_vs_ecx", "store_eax_vs_edx", "store_ecx_vs_eax", "store_edx_vs_eax"}:
        print("ACTION: register-allocation mismatch — try swapping local decl order or adding/removing intermediate locals.")
    elif classes & {"shr_vs_sar", "sar_vs_shr"}:
        print("ACTION: toggle int/unsigned int on the shifted value.")
    elif classes & {"je_vs_jne", "jne_vs_je", "jl_vs_jge", "jge_vs_jl", "jle_vs_jg", "jg_vs_jle"}:
        print("ACTION: invert the C condition polarity (! the test, or swap if/else).")
    elif classes & {"jmp_vs_call"}:
        print("ACTION: convert the final call to tail-call via 'return ((int(*)())F)();' (function declared int).")
    elif classes & {"call_vs_jmp"}:
        print("ACTION: prevent MSVC tail-call by adding a trailing store or non-tail return.")
    return 0


def main():
    if len(sys.argv) == 5 and not sys.argv[1].startswith('--'):
        # Run diff_fn_obj.py and analyze
        diff_script = ROOT / 'tools' / 'decomp' / 'diff_fn_obj.py'
        res = subprocess.run(
            ['python3', str(diff_script)] + sys.argv[1:],
            capture_output=True, text=True, timeout=30,
        )
        if res.returncode != 0:
            print(res.stdout)
            print(res.stderr, file=sys.stderr)
            sys.exit(res.returncode)
        print(res.stdout)
        orig_hex, new_hex, diffs = parse_diff_output(res.stdout)
        sys.exit(explain(orig_hex, new_hex, diffs))
    elif sys.argv[1:2] == ['--stdin']:
        text = sys.stdin.read()
        orig_hex, new_hex, diffs = parse_diff_output(text)
        sys.exit(explain(orig_hex, new_hex, diffs))
    else:
        print(__doc__)
        sys.exit(2)


if __name__ == '__main__':
    main()
