#!/usr/bin/env python3
"""Co-exec a small pure function against the original, with literal arguments.

For leaf helpers - fixed-point math, CRT-style conversions - there is no state
to seed: the whole contract is "same arguments in, same EAX out". This runs the
original bytes and the compiled twin side by side over a list of argument
tuples and compares the return value (and any writes).

  build/venv/bin/python tools/decomp/verify_misc.py NAME a,b [a,b ...]
  build/venv/bin/python tools/decomp/verify_misc.py Mul10Tail        # built-ins
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc

CASES = {
    # signed 16.16 multiply: identity, halves, negatives, overflow
    'Mul10Tail': [(0x10000, 0x10000), (0x8000, 0x20000), (-0x10000, 0x30000),
                  (0x7fffffff, 2), (-5, -7), (0x1234, -0x5678), (0, 0x10000)],
}


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    name = sys.argv[1]
    if len(sys.argv) > 2:
        cases = [tuple(int(x, 0) for x in a.split(',')) for a in sys.argv[2:]]
    elif name in CASES:
        cases = CASES[name]
    else:
        print('no built-in cases for %s - pass them as a,b' % name)
        return 2

    fn_va, gl_va = vt.load_maps()
    base = bytearray(vc.ARENA.read_bytes())
    vc.ARG_BASE = 0x7af800
    rc = 0
    print(name)
    for args in cases:
        res = vc.verify(name, fn_va, gl_va, fn_va, bytearray(base), argvals=args)
        print('  %-28s %s' % (','.join(str(a) for a in args), res))
        if res.startswith('MISMATCH'):
            rc = 1
    return rc


if __name__ == '__main__':
    sys.exit(main())
