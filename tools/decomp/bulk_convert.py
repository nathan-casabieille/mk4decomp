#!/usr/bin/env python3
"""Bulk naked->C converter with verify-or-revert loop.

Iterates over `__declspec(naked) <ret> <name>(<args>) { __asm { ... } }`
function definitions in misc_matches*.c. For each, tries to apply known
pattern transformations. After each replacement, runs `make matching`;
if the build is byte-identical to orig, commits the change; otherwise
reverts the source and moves on.

Pattern catalog is conservative: a missing pattern leaves the function
naked. The goal is to grind through obvious cases without manual work.
"""
import argparse
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
TARGET_MD5 = "a3d2bf7f1222e5fcf8df93c7d8d8b5cf"
EXE_PATH = ROOT / "build" / "MK4.matching.exe"
RELOC_SITES_PATH = ROOT / "config" / "reloc_sites.yaml"

NAKED_RE = re.compile(
    r'(__declspec\s*\(\s*naked\s*\)\s+'           # __declspec(naked)
    r'\w+\s+'                                      # return type
    r'(\w+)'                                       # name
    r'\s*\([^)]*\)\s*\{\s*'                       # args + {
    r'__asm\s*\{'                                  # __asm {
    r'([^}]*)'                                     # body
    r'\}\s*\})',                                   # } }
    re.DOTALL
)


def md5sum(path):
    import hashlib
    h = hashlib.md5()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(65536), b""):
            h.update(chunk)
    return h.hexdigest()


def run_make_matching():
    """Run `make matching` and return (success, md5_or_err)."""
    res = subprocess.run(
        ["make", "matching"],
        cwd=ROOT,
        capture_output=True,
        text=True,
        timeout=300,
    )
    if res.returncode != 0:
        return False, f"make failed: {res.stderr[-500:]}"
    if not EXE_PATH.exists():
        return False, "exe missing"
    md5 = md5sum(EXE_PATH)
    if md5 != TARGET_MD5:
        return False, f"md5 mismatch: {md5}"
    return True, md5


def parse_asm_lines(body):
    """Return list of (mnemonic, operands) tuples for each asm line."""
    out = []
    for raw in body.split("\n"):
        line = raw.strip()
        if not line:
            continue
        # Split off comments
        line = re.sub(r';.*$', '', line).strip()
        if not line:
            continue
        # Split mnemonic + operands
        parts = line.split(None, 1)
        if len(parts) == 1:
            out.append((parts[0].lower(), ""))
        else:
            out.append((parts[0].lower(), parts[1].strip()))
    return out


# ---- Pattern matchers ----


def match_call_pause_tailjmp(lines):
    """Pattern: call F; mov eax,[g_framePauseFlag]; test eax,eax; _emit 75 05; jmp T; ret.

    Returns: dict(call_target=..., jmp_target=...) or None.
    """
    if len(lines) != 7:
        return None
    if lines[0][0] != "call":
        return None
    if not (lines[1][0] == "mov" and "g_framePauseFlag" in lines[1][1]):
        return None
    if lines[2] != ("test", "eax, eax"):
        return None
    if not (lines[3] == ("_emit", "75h") and lines[4] == ("_emit", "05h")):
        return None
    if lines[5][0] != "jmp":
        return None
    if lines[6][0] != "ret":
        return None
    return {
        "call_target": lines[0][1],
        "jmp_target": lines[5][1],
    }


def emit_call_pause_tailjmp(info):
    """Generate C body for Call+Pause+TailJmp."""
    return (
        f"    {info['call_target']}();\n"
        f"    if (g_framePauseFlag != 0) return;\n"
        f"    {info['jmp_target']}();\n"
    )


def match_set_walk_call_pause_tailjmp(lines):
    """Pattern: mov [g_walkCallback], IMM; call F; mov eax,[pause]; test; _emit 75 05; jmp T; ret."""
    if len(lines) != 8:
        return None
    if not (lines[0][0] == "mov" and "g_walkCallback" in lines[0][1]):
        return None
    m = re.search(r'\],\s*([\w0x]+)$', lines[0][1])
    if not m:
        return None
    if lines[1][0] != "call":
        return None
    if not (lines[2][0] == "mov" and "g_framePauseFlag" in lines[2][1]):
        return None
    if lines[3] != ("test", "eax, eax"):
        return None
    if not (lines[4] == ("_emit", "75h") and lines[5] == ("_emit", "05h")):
        return None
    if lines[6][0] != "jmp":
        return None
    if lines[7][0] != "ret":
        return None
    return {
        "imm": m.group(1),
        "call_target": lines[1][1],
        "jmp_target": lines[6][1],
    }


def emit_set_walk_call_pause_tailjmp(info):
    return (
        f"    g_walkCallback = (void (*)(void)){info['imm']};\n"
        f"    {info['call_target']}();\n"
        f"    if (g_framePauseFlag != 0) return;\n"
        f"    {info['jmp_target']}();\n"
    )


def match_multi_call_pause_tail(lines):
    """Generic: N stages of (optional set + call + pause-check), then final tail-jmp.

    Returns dict(stages=[(maybe_set_imm, call_target), ...], jmp_target=...) or None.
    """
    stages = []
    i = 0
    while i < len(lines):
        # Optional: mov [g_walkCallback], IMM
        set_imm = None
        if (i < len(lines) and lines[i][0] == "mov"
                and "g_walkCallback" in lines[i][1]
                and not lines[i][1].endswith(", eax")
                and not lines[i][1].endswith(", ecx")
                and not lines[i][1].endswith(", edx")):
            m = re.search(r'\],\s*([\w0x]+)$', lines[i][1])
            if m:
                set_imm = m.group(1)
                i += 1
        if i >= len(lines) or lines[i][0] != "call":
            return None
        call_target = lines[i][1]
        i += 1
        # Expect: mov eax, [pause]; test eax, eax; _emit 75 XX
        if i + 4 > len(lines):
            return None
        if not (lines[i][0] == "mov" and "g_framePauseFlag" in lines[i][1]):
            return None
        if lines[i+1] != ("test", "eax, eax"):
            return None
        if lines[i+2][0] != "_emit" or lines[i+2][1] != "75h":
            return None
        if lines[i+3][0] != "_emit":
            return None
        # Skip the test_emit sequence
        i += 4
        stages.append((set_imm, call_target))
        # Check if next is jmp T; ret (tail) or another stage
        if i + 2 == len(lines) and lines[i][0] == "jmp" and lines[i+1][0] == "ret":
            return {"stages": stages, "jmp_target": lines[i][1], "final_set": None}
        # Optional final set before tail-jmp
        if (i + 3 == len(lines) and lines[i][0] == "mov"
                and "g_walkCallback" in lines[i][1]
                and lines[i+1][0] == "jmp" and lines[i+2][0] == "ret"):
            m = re.search(r'\],\s*([\w0x]+)$', lines[i][1])
            if m:
                return {
                    "stages": stages,
                    "jmp_target": lines[i+1][1],
                    "final_set": m.group(1),
                }
    return None


def emit_multi_call_pause_tail(info):
    out = ""
    for set_imm, call in info["stages"]:
        if set_imm:
            out += f"    g_walkCallback = (void (*)(void)){set_imm};\n"
        out += f"    {call}();\n"
        out += f"    if (g_framePauseFlag != 0) return;\n"
    if info["final_set"]:
        out += f"    g_walkCallback = (void (*)(void)){info['final_set']};\n"
    out += f"    {info['jmp_target']}();\n"
    return out


def match_triple_field_copy(lines):
    """Pattern: 3 iterations of (load src_glb; load dst_glb; load arr[src_glb*4+SRC_N];
    store walkCallback; store arr[dst_glb*4+DST_N]); then ret OR tail-jmp.

    Each iteration reloads both src_glb and dst_glb via DIFFERENT registers (eax+ecx, then
    edx+ecx, then edx+ecx). MSVC re-emits the load pattern naturally for this 3-store-via-pointer
    pattern because g_walkCallback may alias the index globals (conservative MSVC alias analysis).

    Returns dict(src_glb, dst_glb, offsets=[(src_off1,dst_off1),...], tail=None|str).
    """
    # Two shapes: 16 lines (ends with ret), 17 lines (ends with jmp T then ret-impl).
    # The 3 iterations are 5 lines each = 15 lines; +1 for final ret OR +1 jmp.
    if len(lines) not in (16, 17):
        return None
    tail = None
    if lines[-1][0] == 'ret':
        body = lines[:-1]
    elif lines[-1][0] == 'jmp':
        tail = lines[-1][1]
        body = lines[:-1]
    else:
        return None
    if len(body) != 15:
        return None

    # Parse three 5-line blocks
    iters = []
    src_glb, dst_glb = None, None
    for k in range(3):
        chunk = body[k*5:(k+1)*5]
        # mov reg1, [src_glb]
        m1 = re.match(r'^(eax|edx),\s*dword ptr\s*\[(\w+)\]$', chunk[0][1])
        if chunk[0][0] != 'mov' or not m1:
            return None
        sg = m1.group(2)
        if src_glb is None:
            src_glb = sg
        elif src_glb != sg:
            return None
        # mov ecx, [dst_glb]
        m2 = re.match(r'^ecx,\s*dword ptr\s*\[(\w+)\]$', chunk[1][1])
        if chunk[1][0] != 'mov' or not m2:
            return None
        dg = m2.group(1)
        if dst_glb is None:
            dst_glb = dg
        elif dst_glb != dg:
            return None
        # mov eax, [<src_reg>*4 + SRC_OFF]
        reg_used = m1.group(1)
        m3 = re.match(rf'^eax,\s*dword ptr\s*\[{reg_used}\*4 \+ (\w+)\]$', chunk[2][1])
        if chunk[2][0] != 'mov' or not m3:
            return None
        src_off = int(m3.group(1), 0)
        # mov [g_walkCallback], eax
        if chunk[3] != ('mov', 'dword ptr [g_walkCallback], eax'):
            return None
        # mov [ecx*4 + DST_OFF], eax
        m5 = re.match(r'^dword ptr\s*\[ecx\*4 \+ (\w+)\],\s*eax$', chunk[4][1])
        if chunk[4][0] != 'mov' or not m5:
            return None
        dst_off = int(m5.group(1), 0)
        iters.append((src_off, dst_off))
    return {
        'src_glb': src_glb, 'dst_glb': dst_glb,
        'offsets': iters, 'tail': tail,
    }


def emit_triple_field_copy(info):
    out = "    unsigned int val;\n"
    for src_off, dst_off in info['offsets']:
        out += f"    val = *(unsigned int *)({info['src_glb']} * 4 + {src_off:#x});\n"
        out += f"    g_walkCallback = (void (*)(void))val;\n"
        out += f"    *(unsigned int *)({info['dst_glb']} * 4 + {dst_off:#x}) = val;\n"
    if info['tail']:
        out += f"    {info['tail']}();\n"
    return out


def match_xor_zero_n_globals(lines):
    """Pattern: xor eax, eax; mov [g_X], eax (xN); ret.

    Returns dict(globals=[...]) or None.
    """
    if len(lines) < 3 or lines[0] != ("xor", "eax, eax"):
        return None
    if lines[-1][0] != "ret":
        return None
    globals_list = []
    for i in range(1, len(lines) - 1):
        if lines[i][0] != "mov":
            return None
        m = re.match(r'dword ptr \[([\w_]+)\],\s*eax$', lines[i][1])
        if not m:
            return None
        globals_list.append(m.group(1))
    if not globals_list:
        return None
    return {"globals": globals_list}


def emit_xor_zero_n_globals(info):
    out = ""
    for g in info["globals"]:
        out += f"    {g} = 0;\n"
    return out


PATTERNS = [
    ("call_pause_tailjmp", match_call_pause_tailjmp, emit_call_pause_tailjmp),
    ("set_walk_call_pause_tailjmp", match_set_walk_call_pause_tailjmp, emit_set_walk_call_pause_tailjmp),
    ("multi_call_pause_tail", match_multi_call_pause_tail, emit_multi_call_pause_tail),
    ("xor_zero_n_globals", match_xor_zero_n_globals, emit_xor_zero_n_globals),
    ("triple_field_copy", match_triple_field_copy, emit_triple_field_copy),
]


def get_func_section(obj_path, func_name):
    """Read OBJ symbol table and return the section index for `_func_name`.

    Returns None if not found.
    """
    if not obj_path.exists():
        return None
    with open(obj_path, "rb") as f:
        data = f.read()
    symoff = struct.unpack_from("<I", data, 8)[0]
    nsym = struct.unpack_from("<I", data, 12)[0]
    strtbl_off = symoff + nsym * 18
    target = f"_{func_name}"
    for i in range(nsym):
        rec = data[symoff + i*18 : symoff + (i+1)*18]
        if rec[:4] == b"\x00\x00\x00\x00":
            off = struct.unpack_from("<I", rec, 4)[0]
            end = data.index(b"\x00", strtbl_off+off)
            name = data[strtbl_off+off:end].decode('ascii', 'replace')
        else:
            name = rec[:8].rstrip(b'\x00').decode('ascii', 'replace')
        value = struct.unpack_from("<I", rec, 8)[0]
        sec_num = struct.unpack_from("<h", rec, 12)[0]
        storage = rec[16]
        if name == target and storage == 2 and value == 0 and sec_num > 0:
            return sec_num
    return None


def bump_reloc_sites(obj_relative, min_section, delta=1):
    """Bump every reloc_sites entry referencing `obj_relative` with section >= min_section.

    Returns the previous file content (for restore on revert).
    """
    with open(RELOC_SITES_PATH) as f:
        original = f.read()
    new_lines = []
    pat = re.compile(rf'^({re.escape(obj_relative)}#)(\d+)(#.+)$')
    for line in original.split("\n"):
        m = pat.match(line)
        if m and int(m.group(2)) >= min_section:
            new_lines.append(f"{m.group(1)}{int(m.group(2)) + delta}{m.group(3)}")
        else:
            new_lines.append(line)
    with open(RELOC_SITES_PATH, "w") as f:
        f.write("\n".join(new_lines))
    return original


def restore_reloc_sites(original):
    with open(RELOC_SITES_PATH, "w") as f:
        f.write(original)


def try_convert(src_path):
    """Try to convert one naked function in `src_path`. Returns name or None."""
    with open(src_path) as f:
        src = f.read()
    # Compute obj path
    abs_path = src_path.resolve()
    rel_src = abs_path.relative_to(ROOT / "src").as_posix()  # engine/misc_matchesK.c
    obj_relative = rel_src[:-2] + ".obj"  # engine/misc_matchesK.obj
    obj_path = ROOT / "build" / "obj" / obj_relative

    for match in NAKED_RE.finditer(src):
        full_block = match.group(1)
        name = match.group(2)
        body = match.group(3)
        lines = parse_asm_lines(body)

        for pat_name, matcher, emitter in PATTERNS:
            info = matcher(lines)
            if info is None:
                continue
            # Build the replacement C function
            # Extract signature from full_block (before {)
            sig_match = re.match(
                r'__declspec\s*\(\s*naked\s*\)\s+(\w+\s+\w+\s*\([^)]*\))',
                full_block
            )
            if not sig_match:
                continue
            sig = sig_match.group(1)
            c_body = emitter(info)
            replacement = f"{sig} {{\n{c_body}}}"

            new_src = src[:match.start()] + replacement + src[match.end():]

            # Determine the section that will gain a .debug$F after conversion.
            # We bump every reloc_sites entry with section > sec_num.
            sec_num = get_func_section(obj_path, name)

            # Try it
            print(f"  trying {name} ({pat_name}, sec={sec_num})... ", end="", flush=True)
            shutil.copy(src_path, str(src_path) + ".bak")
            with open(src_path, "w") as f:
                f.write(new_src)
            reloc_backup = None
            if sec_num is not None:
                reloc_backup = bump_reloc_sites(obj_relative, sec_num + 1)
            ok, info_msg = run_make_matching()
            if ok:
                print("MATCH")
                Path(str(src_path) + ".bak").unlink()
                return name, pat_name
            else:
                print(f"FAIL ({info_msg[:80]})")
                shutil.move(str(src_path) + ".bak", str(src_path))
                if reloc_backup is not None:
                    restore_reloc_sites(reloc_backup)
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("files", nargs="*", help="Source files to scan")
    ap.add_argument("--max", type=int, default=0, help="Max conversions per file")
    args = ap.parse_args()

    if not args.files:
        import glob
        args.files = sorted(glob.glob(str(ROOT / "src/engine/misc_matches*.c")))

    # Initial sanity check
    ok, _ = run_make_matching()
    if not ok:
        print("ERROR: baseline build is not matching. Aborting.")
        sys.exit(1)

    converted_count = 0
    for f in args.files:
        path = Path(f)
        per_file = 0
        print(f"\n== {path.name} ==")
        while True:
            result = try_convert(path)
            if result is None:
                break
            converted_count += 1
            per_file += 1
            if args.max and per_file >= args.max:
                break

    print(f"\nTotal conversions: {converted_count}")


if __name__ == "__main__":
    main()
