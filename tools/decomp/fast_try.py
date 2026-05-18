#!/usr/bin/env python3
"""Fast single-function conversion attempt.

After you've edited a source file replacing `__declspec(naked) {__asm{...}}`
with pure C, this script:

  1. Touches the source file to force rebuild.
  2. Compiles only the affected .obj via `make build/obj/<path>.obj`.
  3. Looks up the function's address & size from config/symbols.yaml.
  4. Runs diff_fn_obj.py on the rebuilt .obj for that symbol.
  5. Reports the diff count and bails fast if non-zero.

This skips the section-bump reloc_sites dance and the full synthesize.py
verification. Use this for rapid iteration on candidates; once diffs==0,
run `try_conv.py` for the authoritative full-EXE check.

Usage:
    python3 tools/decomp/fast_try.py <src_file> <func_name>

Exit codes:
    0 = diffs == 0 (likely a match, run full try_conv.py to confirm)
    1 = obj diffs > 0 (function doesn't match orig bytes)
    2 = build failed or symbol not found
"""
import os
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent

# Load symbols.yaml lazily; we just need addr+size for a given name.
def find_symbol(name):
    sympath = ROOT / 'config' / 'symbols.yaml'
    addr = None
    size = None
    cur_name = None
    cur_addr = None
    cur_size = None
    with open(sympath) as f:
        for line in f:
            s = line.strip()
            if s.startswith('- addr:'):
                if cur_name == name:
                    return cur_addr, cur_size
                cur_addr = int(s.split(':', 1)[1].strip(), 0)
                cur_name = None
                cur_size = None
            elif s.startswith('name:'):
                cur_name = s.split(':', 1)[1].strip()
            elif s.startswith('size:'):
                cur_size = int(s.split(':', 1)[1].strip(), 0)
        if cur_name == name:
            return cur_addr, cur_size
    return None, None


def main():
    if len(sys.argv) != 3:
        print(__doc__)
        sys.exit(2)
    src_path = Path(sys.argv[1]).resolve()
    name = sys.argv[2]
    rel = src_path.relative_to(ROOT / 'src').as_posix()
    obj_rel = rel[:-2] + '.obj'
    obj_path = ROOT / 'build' / 'obj' / obj_rel

    addr, size = find_symbol(name)
    if addr is None or size is None:
        print(f'ERROR: symbol {name} not found in config/symbols.yaml', file=sys.stderr)
        sys.exit(2)
    print(f'lookup: {name} @ 0x{addr:08x} size={size}')

    # Force rebuild by touching the source
    src_path.touch()

    t0 = time.time()
    print(f'compiling {obj_rel}...')
    res = subprocess.run(
        ['make', f'build/obj/{obj_rel}'],
        cwd=ROOT, capture_output=True, text=True, timeout=120,
    )
    t1 = time.time()
    if res.returncode != 0:
        print(f'BUILD FAIL ({t1-t0:.1f}s):')
        print(res.stdout[-2000:])
        print(res.stderr[-2000:], file=sys.stderr)
        sys.exit(2)
    print(f'compile: {t1-t0:.1f}s')

    # Run diff
    diff_script = ROOT / 'tools' / 'decomp' / 'diff_fn_obj.py'
    res = subprocess.run(
        ['python3', str(diff_script), str(obj_path), name, hex(addr), str(size)],
        capture_output=True, text=True, timeout=30,
    )
    # diff_fn_obj.py prints diff details on stdout but uses raise SystemExit
    # for size-mismatch errors which go to stderr.
    output = res.stdout + res.stderr
    print(output, end='')

    t2 = time.time()
    # Parse "diffs=N" from output
    for line in output.split('\n'):
        if 'diffs=' in line:
            try:
                diffs = int(line.split('diffs=')[1].split()[0].rstrip(':'))
            except (ValueError, IndexError):
                continue
            if diffs == 0:
                print(f'\nMATCH (per-OBJ diff). Total: {t2-t0:.1f}s. Run try_conv.py to confirm full synth.')
                sys.exit(0)
            else:
                print(f'\nFAIL: {diffs} byte diffs. Total: {t2-t0:.1f}s. Revert and retry.')
                sys.exit(1)
    # Size mismatch (rebuilt smaller or larger than orig)
    if 'exceed section size' in output:
        print(f'\nSIZE MISMATCH: MSVC compiled this function to fewer bytes than orig (or trailing data missing). Total: {t2-t0:.1f}s. Revert.')
        sys.exit(1)
    print('ERROR: could not parse diff output', file=sys.stderr)
    sys.exit(2)


if __name__ == '__main__':
    main()
