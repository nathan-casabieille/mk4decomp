#!/usr/bin/env python3
"""Make every weak function stub in engine_autostubs.c report when it is called.

engine_autostubs.c is generated. If it is ever rebuilt, re-run this - it is
idempotent, so running it on an already-stamped file changes nothing.

Rationale: MK4_TRACE_CODE only sees dispatch through MK4_ResolveCode. A
converted function that calls a hollow one directly in C never shows up
there, which is how the scene-construction path stayed invisible while
looking fully covered. See src/platform/sdl/engine_stubtrace.c.

    __attribute__((weak)) int Foo(){return 0;}
 -> __attribute__((weak)) int Foo(){MK4_StubHit("Foo");return 0;}
"""
import re, sys, pathlib

ROOT = pathlib.Path(__file__).resolve().parents[2]
F = ROOT / 'src/platform/sdl/engine_autostubs.c'

DECL = ('#ifdef MK4_NATIVE_FULL\n'
        'extern void MK4_StubHit(const char *);\n')

def main():
    s = F.read_text()
    if 'MK4_StubHit' not in s:
        # the file opens with #ifdef MK4_NATIVE_FULL; declare right after it
        s = s.replace('#ifdef MK4_NATIVE_FULL\n', DECL, 1)

    pat = re.compile(r'(__attribute__\(\(weak\)\)\s+\w+\s+(\w+)\(\)\{)(return 0;\})')
    n = 0
    def sub(m):
        nonlocal n
        n += 1
        return f'{m.group(1)}MK4_StubHit("{m.group(2)}");{m.group(3)}'
    s = pat.sub(sub, s)

    F.write_text(s)
    print(f'stamped {n} function stubs in {F.relative_to(ROOT)}')
    if n == 0:
        print('(already stamped, or the stub form changed - check the regex)')

if __name__ == '__main__':
    main()
