#!/usr/bin/env python3
"""Find globals that live in TWO places at once under the arena build.

A game global at a fixed VA is reached one of two ways in the native build:
through an `#ifdef MK4_ARENA` alias (`#define g_x (*(unsigned int *)MK4_VA(...))`)
or, if a file forgets that alias, through the plain `extern` that the engine
headers still declare - which links against a REAL host symbol in __DATA.
Nothing warns: the shadowing macro is simply absent, or arrives too late in
the file to cover the code above it. The two storages then drift, and the
symptom appears far away - MStackPushTableWalk pushed onto a __DATA word while
its own caller pushed onto 0x4d57ac, and the split stack pointer crashed the
tower path at `arena + 4`.

Grepping for this over-reports by two orders of magnitude: most matches are
`extern` declarations inside `#ifndef MK4_ARENA`, or mentions in comments. The
only reliable evidence is the object file - if a translation unit compiled with
-DMK4_ARENA still emits an undefined reference to `_g_x`, that unit is on the
host side, full stop. So this compiles each native-build TU and reads its
undefined symbols.

Usage:  build/venv/bin/python tools/decomp/audit_split_globals.py [-v]
        make split-globals-audit
"""
import collections, glob, os, re, subprocess, sys, tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
LIST = os.path.join(ROOT, 'tools/decomp/native_full_srcs.txt')
EXE  = os.path.join(ROOT, 'build/MK4.native.full')

# Splits that are DELIBERATE. Each entry needs a reason, because the whole
# point of the audit is that an undocumented split is a bug.
EXPECTED = {
    'g_dispatchSave547': 'CRT init fn-ptr table, used by ADDRESS (_init_premain)',
    'g_dispatchSave548': 'CRT init fn-ptr table, used by ADDRESS (_init_premain)',
    'g_dispatchSave549': 'CRT init fn-ptr table, used by ADDRESS (_init_premain)',
    'g_dispatchSave550': 'CRT init fn-ptr table, used by ADDRESS (_init_premain)',
    'g_renderer2_active':     'D3D present path, dormant under SDL',
    'g_renderer2_paused':     'D3D present path, dormant under SDL',
    'g_renderer2_present_rc': 'D3D present path, dormant under SDL',
    'g_dispatchSave1620': 'GDI SetDIBitsToDevice path, dormant under SDL',
    'g_dispatchSave1621': 'GDI SetDIBitsToDevice path, dormant under SDL',
}

def main():
    verbose = '-v' in sys.argv
    files = [l.strip() for l in open(LIST) if l.strip()]

    alias_va, aliasers = {}, collections.defaultdict(set)
    pat = re.compile(r'^#define (\w+) \(\*\(unsigned int \*\)'
                     r'MK4_VA\(unsigned int, 0x([0-9a-f]+)u\)\)', re.M)
    for p in files:
        try: s = open(os.path.join(ROOT, p)).read()
        except OSError: continue
        for n, va in pat.findall(s):
            alias_va.setdefault(n, va)
            aliasers[n].add(p)

    nm = subprocess.run(['nm', '-m', EXE], capture_output=True, text=True).stdout
    host = set(re.findall(r'\(__DATA,__\w+\)\s+(?:weak )?external _(\w+)', nm))
    cand = {n for n in alias_va if n in host}

    cflags = ['-DNON_MATCHING', '-DMK4_ARENA', '-DTARGET_SDL', '-DMK4_NATIVE_FULL',
              '-I' + os.path.join(ROOT, 'include'), '-O2', '-w', '-c',
              # the same relaxations native-full compiles with (NATIVE_PORTFLAGS);
              # without them ~50 TUs fail to compile alone and go unaudited
              '-Wno-int-conversion', '-Wno-incompatible-pointer-types',
              '-Wno-int-to-pointer-cast', '-Wno-implicit-function-declaration']
    try:
        cflags += subprocess.run(['sdl2-config', '--cflags'], capture_output=True,
                                 text=True).stdout.split()
    except OSError:
        pass

    hits, skipped = collections.defaultdict(set), 0
    with tempfile.TemporaryDirectory() as td:
        for p in files:
            o = os.path.join(td, p.replace('/', '_')[:-2] + '.o')
            r = subprocess.run(['cc'] + cflags + [os.path.join(ROOT, p), '-o', o],
                               capture_output=True)
            if r.returncode != 0 or not os.path.exists(o):
                skipped += 1
                continue
            u = subprocess.run(['nm', '-u', o], capture_output=True, text=True).stdout
            for n in {m for m in re.findall(r'^\s*_(\w+)$', u, re.M)} & cand:
                hits[n].add(p)

    unexpected = {n: v for n, v in hits.items() if n not in EXPECTED}
    print("split-globals-audit: %d TUs analysed (%d would not compile alone)"
          % (len(files) - skipped, skipped))
    if verbose or not unexpected:
        for n in sorted(set(hits) & set(EXPECTED)):
            print("  ok  %-24s %s" % (n, EXPECTED[n]))
    if not unexpected:
        print("PASS - no undocumented split globals")
        return 0
    print("\nFAIL - %d global(s) reached BOTH as an arena alias and as a host\n"
          "symbol, with no documented reason:\n" % len(unexpected))
    for n in sorted(unexpected, key=lambda k: -len(aliasers[k])):
        print("  %-26s 0x%-8s aliased by %d file(s); host-side in:"
              % (n, alias_va[n], len(aliasers[n])))
        for p in sorted(unexpected[n]):
            print("      %s" % p)
    print("\nFix: add the `#define %s ... MK4_VA(...)` alias to the file(s)\n"
          "above, INSIDE its `#ifdef MK4_ARENA` block and ABOVE the code that\n"
          "uses it - a block placed below the code compiles clean and does\n"
          "nothing. If a split is intentional, add it to EXPECTED with a reason."
          % sorted(unexpected)[0])
    return 1

if __name__ == '__main__':
    sys.exit(main())
