#!/usr/bin/env python3
"""Pre-screen naked function bodies for likely-convertibility to pure C.

For each `__declspec(naked) ... { __asm { ... } }` block found in the
given file(s), inspect the asm body for instruction patterns that
empirically resist MSVC SP3 codegen reproduction from natural C:

  HARD blockers (each strongly suggests "keep naked"):
    - byte ptr / al/bl/cl/dl ops      — register-byte ops MSVC won't emit
    - word ptr / ax/cx/dx 16-bit ops  — same, for word
    - fld/fst/fmul/fcom/fnstsw/...    — FPU instructions
    - raw _emit with non-jcc byte     — encoded cross-function refs
    - movsx / cdq / sete / setne      — sign-extend / setcc tricks
    - shrd / shld / rep stosd/movsd   — multi-precision / block ops
    - jmp eax / jmp [reg]             — computed branch
    - push esi/edi/ebx/ebp +pop later — callee-saved register scheduling
    - dec reg followed by je/jne      — flag-from-dec preservation
    - shl reg, 2; mov [reg+disp]      — packed_ptr-as-base via shift

  SOFT signals (one is OK, several together is a warning):
    - multiple stores to g_walkCallback (mid-function register reload)
    - cross-function near-jmp targets via OFFSET sym + addend

  EASY structure (no HARD blockers, simple control flow):
    - pure load/store + call/ret
    - call + pause-check + tail-jmp
    - dual-path if/else with simple jcc + ret

Usage:
    python3 tools/decomp/screen_naked.py src/engine/misc_matchesQQ.c
    python3 tools/decomp/screen_naked.py --json src/engine/*.c
"""
import argparse
import json
import re
import sys
from pathlib import Path

NAKED_RE = re.compile(
    r'__declspec\s*\(\s*naked\s*\)\s+'
    r'(\w+(?:\s*\*)?)\s+'                # return type
    r'(\w+)'                             # name
    r'\s*\([^)]*\)\s*\{\s*'
    r'__asm\s*\{'
    r'(.*?)'
    r'\}\s*\}',
    re.DOTALL,
)

BYTE_REG_RE = re.compile(r'\b(byte ptr|movsx\s+\w+\s*,\s*byte|\b[abcd][hl]\s*,|\b,[ \t]*[abcd][hl]\b)')
WORD_REG_RE = re.compile(r'\b(word ptr|movsx\s+\w+\s*,\s*word|\b[abcd]x\s*,|\b,[ \t]*[abcd]x\b)')
FPU_RE = re.compile(r'\b(fld|fst|fild|fistp|fadd|fsub|fmul|fdiv|fcom|fnstsw|fnclex|fyl2x|fldlg2|fchs|fxch|fstcw|fldcw|f2xm1)\b')
SETCC_RE = re.compile(r'\b(setne|sete|setge|setle|setl|setg|seta|setb|cdq)\b')
MULTI_PREC_RE = re.compile(r'\b(shrd|shld|rep\s+stosd|rep\s+movsd|adc|sbb)\b')
COMPUTED_JMP_RE = re.compile(r'\bjmp\s+(eax|ecx|edx|ebx|esi|edi|ebp|dword ptr)\b')
DEC_JCC_RE = re.compile(r'\bdec\s+e[a-d]x\b.*?\b(je|jne|jz|jnz)\b', re.DOTALL)

# Emit-jcc bytes (8-bit conditional jumps + short jmp): 70-7f, eb
EMIT_JCC = set('70 71 72 73 74 75 76 77 78 79 7a 7b 7c 7d 7e 7f eb'.split())


def classify(body):
    """Return dict of detected hard blockers + soft signals."""
    flags = []

    # Parse asm lines, stripping comments
    lines = []
    for raw in body.split('\n'):
        line = re.sub(r';.*$', '', raw).strip()
        if line:
            lines.append(line)

    body_text = '\n'.join(lines).lower()

    if BYTE_REG_RE.search(body_text):
        flags.append('byte_op')
    if WORD_REG_RE.search(body_text):
        flags.append('word_op')
    if FPU_RE.search(body_text):
        flags.append('fpu')
    if SETCC_RE.search(body_text):
        flags.append('setcc')
    if MULTI_PREC_RE.search(body_text):
        flags.append('multi_prec')
    if COMPUTED_JMP_RE.search(body_text):
        flags.append('computed_jmp')
    if DEC_JCC_RE.search(body_text):
        flags.append('dec_jcc')

    # Detect raw _emit with non-jcc payload
    for line in lines:
        if not line.lower().startswith('_emit'):
            continue
        m = re.search(r'_emit\s+0*([0-9a-fA-F]+)h?', line)
        if not m:
            continue
        b = m.group(1).lower().lstrip('0') or '0'
        # Accept jcc bytes (74-7f, eb) and the short-jmp follow-byte after a jcc
        if b not in EMIT_JCC:
            flags.append('raw_emit')
            break

    # Callee-saved push (any of esi/edi/ebx/ebp)
    pushes = [l for l in lines if re.match(r'^push\s+(esi|edi|ebx|ebp)\b', l, re.IGNORECASE)]
    if pushes:
        flags.append(f'push_callee_saved({len(pushes)})')

    # SHL by 2 followed by [reg + disp] base-pointer use (packed_ptr unpacking)
    if re.search(r'shl\s+e[a-d]x\s*,\s*2', body_text):
        flags.append('shl_then_base')

    # Multi-store to g_walkCallback (mid-function reload pattern)
    walk_stores = re.findall(r'mov\s+dword ptr\s*\[\s*g_walkCallback\s*\]\s*,', body_text)
    if len(walk_stores) >= 3:
        flags.append(f'multi_walk_store({len(walk_stores)})')

    return flags


def hard_blocker_score(flags):
    """Higher = harder. 0 = no blockers (easy candidate)."""
    HARD = {'byte_op', 'word_op', 'fpu', 'setcc', 'multi_prec',
            'computed_jmp', 'dec_jcc', 'raw_emit'}
    score = sum(1 for f in flags if f in HARD)
    # push callee-saved is a soft -1 (not always blocker)
    for f in flags:
        if f.startswith('push_callee_saved'):
            score += 1
    return score


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('files', nargs='+', help='Source files to scan')
    ap.add_argument('--json', action='store_true', help='Output JSON instead of human-readable')
    ap.add_argument('--easy-only', action='store_true',
                    help='Only show candidates with score == 0 (no hard blockers)')
    ap.add_argument('--max-lines', type=int, default=0,
                    help='Skip functions whose body exceeds this many asm lines')
    args = ap.parse_args()

    all_results = []
    for f in args.files:
        path = Path(f)
        if not path.exists():
            print(f'skip {f}: not found', file=sys.stderr)
            continue
        src = path.read_text()
        for match in NAKED_RE.finditer(src):
            ret_type = match.group(1)
            name = match.group(2)
            body = match.group(3)
            line_count = sum(1 for l in body.split('\n') if l.strip() and not l.strip().startswith(';'))
            if args.max_lines and line_count > args.max_lines:
                continue
            flags = classify(body)
            score = hard_blocker_score(flags)
            if args.easy_only and score > 0:
                continue
            all_results.append({
                'file': str(path.relative_to(Path.cwd())) if path.is_absolute() else str(path),
                'name': name,
                'return_type': ret_type,
                'asm_lines': line_count,
                'hard_score': score,
                'flags': flags,
            })

    # Sort by score (easy first), then by asm_lines (short first)
    all_results.sort(key=lambda r: (r['hard_score'], r['asm_lines'], r['name']))

    if args.json:
        print(json.dumps(all_results, indent=2))
        return

    print(f'{"score":>5} {"lines":>5}  {"name":<48} flags')
    print('-' * 90)
    for r in all_results:
        flagstr = ', '.join(r['flags']) if r['flags'] else '(none)'
        print(f'{r["hard_score"]:>5} {r["asm_lines"]:>5}  {r["name"]:<48} {flagstr}')

    print(f'\nTotal: {len(all_results)} naked functions')
    easy = sum(1 for r in all_results if r['hard_score'] == 0)
    print(f'Easy (score==0): {easy}')


if __name__ == '__main__':
    main()
