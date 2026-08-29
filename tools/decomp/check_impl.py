#!/usr/bin/env python3
"""Is a symbol REALLY implemented natively, or only weak-stubbed?

`nm build/MK4.native.full | grep " T _name"` does NOT answer this: the
weak stub in engine_autostubs.c produces a T entry of its own, so every
stubbed name looks implemented. Reading that as coverage makes a no-op
look like a conversion.

This walks the linked source list instead and reports, per name:
  REAL  <file>   a definition outside engine_autostubs.c
  STUB           only the weak stub
  ABSENT         neither

usage: check_impl.py NAME [NAME...]
       check_impl.py --all-stubs        audit every autostub
"""
import re, sys, pathlib

ROOT = pathlib.Path(__file__).resolve().parents[2]
SRCS = [ROOT / l.strip() for l in (ROOT/'tools/decomp/native_full_srcs.txt').read_text().splitlines()
        if l.strip()] + sorted((ROOT/'src/platform/sdl').glob('*.c')) + [ROOT/'src/portable/arena.c']
STUBF = ROOT/'src/platform/sdl/engine_autostubs.c'
STUBS = set(re.findall(r'weak\)\)\s+\w+\s+(\w+)\s*\(', STUBF.read_text()))

def definers(name):
    pat = re.compile(rf'^[A-Za-z_][\w \*]*\b{re.escape(name)}\s*\([^;]*\)\s*(\{{|$)', re.M)
    out = []
    for f in SRCS:
        if f == STUBF or not f.exists():
            continue
        try: t = f.read_text()
        except OSError: continue
        if name not in t:
            continue
        for m in pat.finditer(t):
            # skip declarations that are really externs
            line = t[t.rfind('\n', 0, m.start())+1:m.end()]
            if line.lstrip().startswith('extern'):
                continue
            out.append(f.relative_to(ROOT))
            break
    return out

def report(name):
    d = definers(name)
    if d:
        return f"REAL   {name:52s} {d[0]}" + (f"  (+{len(d)-1} more)" if len(d) > 1 else "")
    if name in STUBS:
        return f"STUB   {name:52s} weak no-op only"
    return f"ABSENT {name:52s} not linked at all"

if __name__ == '__main__':
    args = sys.argv[1:]
    if not args:
        print(__doc__); sys.exit(2)
    names = sorted(STUBS) if args[0] == '--all-stubs' else args
    lines = [report(n) for n in names]
    for l in lines: print(l)
    if args[0] == '--all-stubs':
        import collections
        c = collections.Counter(l.split()[0] for l in lines)
        print(f"\n{c['REAL']} REAL / {c['STUB']} stub-only / {c['ABSENT']} absent"
              f"   ({len(names)} autostub names)")
