#!/usr/bin/env python3
"""Convert a `__declspec(naked)` function to a non-naked function with the
same `__asm { ... }` body (the trailing `ret` is dropped — MSVC adds the
epilogue automatically). This counts toward "decompiled" by the progress
counter while letting later passes replace pieces of the asm with C.

This is the "all-asm hybrid" baseline; the real work is later replacing
sections of the asm with structured C while keeping the byte-match.

Usage:
    python3 tools/decomp/hybrid_convert.py <src_file> <func_name>
    python3 tools/decomp/hybrid_convert.py <src_file> --all   # try every naked

Workflow per function:
    1. Remove `__declspec(naked)` and the trailing `ret` from the asm body.
    2. Run fast_try.py for per-OBJ diff (must be 0).
    3. Bump reloc_sites for sections >= func_section + 1 (since MSVC adds
       one `.debug$F` section after the function when leaving naked).
    4. Run `make matching`; on success commit, on failure revert source +
       restore reloc_sites.
"""
import argparse
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(ROOT / 'tools' / 'decomp'))
from bulk_convert import (
    get_func_section,
    bump_reloc_sites,
    restore_reloc_sites,
    run_make_matching,
)

NAKED_RE = re.compile(
    r'__declspec\s*\(\s*naked\s*\)\s+(\w+(?:\s*\*)?\s+(\w+)\s*\([^)]*\)\s*\{\s*__asm\s*\{)([\s\S]*?)(\n\s*ret\s*(?:;|\n)\s*)(\}\s*\})'
)

# Variant without trailing ret in asm (some functions have ret embedded mid-body)
NAKED_NO_TAIL_RET_RE = re.compile(
    r'__declspec\s*\(\s*naked\s*\)\s+(\w+(?:\s*\*)?\s+(\w+)\s*\([^)]*\)\s*\{\s*__asm\s*\{)([\s\S]*?)(\}\s*\})'
)


def find_function(src, name):
    """Find `__declspec(naked) ... NAME(...) { __asm { body } }` and return
    (start, end, full_match, before_asm, body, after_body) where:
        before_asm = `__declspec(naked) <ret_type> NAME(args) { __asm {`
        body       = the asm body (multi-line)
        after_body = `} }` closing the naked function
    """
    pattern = re.compile(
        r'__declspec\s*\(\s*naked\s*\)\s+'
        r'(\w+(?:\s*\*)?)\s+'
        + re.escape(name) +
        r'\s*\([^)]*\)\s*\{\s*'
        r'__asm\s*\{'
        r'([\s\S]*?)'
        r'\}\s*\}',
        re.MULTILINE,
    )
    return pattern.search(src)


def strip_naked_and_tail_ret(src, name):
    """Return new_src (and (start, end)) with the function converted to
    non-naked form with the trailing `ret` removed from the asm.

    Returns (new_src, ok) where ok=True on success.
    """
    m = find_function(src, name)
    if not m:
        return src, False
    ret_type = m.group(1).strip()
    body = m.group(2)
    # Strip trailing `ret` (and surrounding whitespace) from asm body
    body_stripped = re.sub(r'\n\s*ret\s*\n\s*$', '\n', body)
    if body_stripped == body:
        # Couldn't strip — function may have non-trivial structure
        return src, False
    replacement = f'{ret_type} {name}(void) {{\n    __asm {{{body_stripped}    }}\n}}'
    # Need to also handle the parameter list (extract from match)
    # Re-find with parameter capture
    pat = re.compile(
        r'__declspec\s*\(\s*naked\s*\)\s+'
        r'(\w+(?:\s*\*)?)\s+'
        + re.escape(name) +
        r'\s*\(([^)]*)\)\s*\{\s*'
        r'__asm\s*\{'
        r'([\s\S]*?)'
        r'\}\s*\}',
        re.MULTILINE,
    )
    m = pat.search(src)
    if not m:
        return src, False
    ret_type = m.group(1).strip()
    args = m.group(2).strip()
    body = m.group(3)
    body_stripped = re.sub(r'\n\s*ret\s*\n(\s*)$', r'\n\1', body)
    if body_stripped == body:
        return src, False
    replacement = f'{ret_type} {name}({args}) {{\n    __asm {{{body_stripped}    }}\n}}'
    new_src = src[:m.start()] + replacement + src[m.end():]
    return new_src, True


def run_fast_try(src_path, name):
    fast = ROOT / 'tools' / 'decomp' / 'fast_try.py'
    res = subprocess.run(
        ['python3', str(fast), str(src_path), name],
        capture_output=True, text=True, timeout=180,
    )
    out = res.stdout + res.stderr
    if 'MATCH (per-OBJ diff)' in out:
        return 0, out
    for line in out.split('\n'):
        m = re.search(r'diffs=(\d+)', line)
        if m:
            return int(m.group(1)), out
        if 'exceed section size' in line:
            return -1, out
        if 'BUILD FAIL' in line:
            return -2, out
    return -3, out


def try_function(src_path, name, dry_run=False):
    """Attempt the hybrid conversion. Returns (ok, msg)."""
    src = src_path.read_text()
    new_src, ok = strip_naked_and_tail_ret(src, name)
    if not ok:
        return False, f"could not find {name} or strip trailing ret"
    src_path.write_text(new_src)
    diffs, out = run_fast_try(src_path, name)
    if diffs != 0:
        src_path.write_text(src)
        return False, f"per-OBJ diffs={diffs}"
    # OBJ matches. Now bump reloc_sites and run make matching.
    rel = src_path.relative_to(ROOT / 'src').as_posix()
    obj_rel = rel[:-2] + '.obj'
    obj_path = ROOT / 'build' / 'obj' / obj_rel
    sec_num = get_func_section(obj_path, name)
    if sec_num is None:
        src_path.write_text(src)
        return False, "section index not found"
    reloc_backup = bump_reloc_sites(obj_rel, sec_num + 1, delta=1)
    if dry_run:
        restore_reloc_sites(reloc_backup)
        src_path.write_text(src)
        return True, f"dry-run OK (sec={sec_num})"
    ok2, md5_or_err = run_make_matching()
    if ok2:
        return True, f"MATCH md5={md5_or_err}"
    restore_reloc_sites(reloc_backup)
    src_path.write_text(src)
    return False, f"matching failed: {md5_or_err}"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('src')
    ap.add_argument('func', nargs='?')
    ap.add_argument('--all', action='store_true', help='Try every naked in the file')
    ap.add_argument('--dry-run', action='store_true')
    args = ap.parse_args()

    src_path = Path(args.src).resolve()
    if args.all:
        src = src_path.read_text()
        # Find all naked functions
        names = re.findall(
            r'__declspec\s*\(\s*naked\s*\)\s+\w+(?:\s*\*)?\s+(\w+)\s*\(',
            src,
        )
        print(f'Found {len(names)} naked functions in {src_path.name}')
        passed = 0
        failed = []
        for n in names:
            t0 = time.time()
            ok, msg = try_function(src_path, n, dry_run=args.dry_run)
            dt = time.time() - t0
            mark = 'OK' if ok else 'FAIL'
            print(f'  [{mark}] {n}  ({dt:.1f}s)  {msg}', flush=True)
            if ok:
                passed += 1
            else:
                failed.append((n, msg))
        print(f'\nSummary: {passed}/{len(names)} passed', flush=True)
        return
    if not args.func:
        print('ERROR: need either <func> or --all', file=sys.stderr)
        sys.exit(2)
    ok, msg = try_function(src_path, args.func, dry_run=args.dry_run)
    print(f'{"OK" if ok else "FAIL"}: {msg}')
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()
