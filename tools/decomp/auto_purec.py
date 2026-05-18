#!/usr/bin/env python3
"""Attempt to convert hybrid functions (non-naked, body still __asm) to pure C.

Currently handles ONE simple pattern: cdecl call-chains where each call is a
straightforward "load args, push, call, add esp, store result" sequence with
no scheduling tricks. Generates C using the cast trick:
    ((unsigned int (*)(uint, uint))F)(arg1, arg2)

For each hybrid function in the given file:
  1. Parse asm body line-by-line.
  2. Recognize the call-chain pattern.
  3. Emit equivalent C.
  4. Run fast_try.py + make matching to verify.
  5. If match, leave the conversion; else revert.

Usage:
    python3 tools/decomp/auto_purec.py <src_file>
"""
import argparse
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(ROOT / 'tools' / 'decomp'))
from bulk_convert import run_make_matching


HYBRID_RE = re.compile(
    r'^(void (\w+)\(void\)\s*\{\s*\n\s*__asm\s*\{)(.*?)(\}\s*\n\s*\}\s*\n)',
    re.MULTILINE | re.DOTALL,
)


def parse_lines(body):
    lines = []
    for raw in body.split('\n'):
        l = re.sub(r';.*$', '', raw).strip()
        if l:
            lines.append(l)
    return lines


def is_simple_call_chain(lines):
    """Check if asm body is a sequence of simple call patterns:
    [mov reg, [g_X]]* push reg|imm call F [mov reg, [g_X]|[g_X],imm/reg]* add esp, N
    """
    # Quick checks
    allowed_re = re.compile(
        r'^(mov\s+(?:dword ptr\s+)?[^,]+,[^,]+|push\s+\w+|push\s+offset\s+\w+|push\s+0x[0-9a-fA-F]+|push\s+\d+|call\s+\w+|add\s+esp,\s*\d+|ret)$',
        re.IGNORECASE,
    )
    for l in lines:
        if not allowed_re.match(l):
            return False
    if not any(l.lower().startswith('call ') for l in lines):
        return False
    return True


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


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('src')
    args = ap.parse_args()
    src_path = Path(args.src).resolve()
    src = src_path.read_text()

    candidates = []
    for m in HYBRID_RE.finditer(src):
        name = m.group(2)
        body = m.group(3)
        lines = parse_lines(body)
        if not lines: continue
        if not is_simple_call_chain(lines): continue
        candidates.append(name)

    print(f'Found {len(candidates)} simple-call-chain hybrid candidates')
    for n in candidates:
        print(f'  {n}')


if __name__ == '__main__':
    main()
