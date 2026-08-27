#!/usr/bin/env python3
"""
Find VAs cast straight to host pointers, bypassing the arena seam.

A Ghidra twin dereferences a node field the way the original does:

    *(int *)(iVar2 + 0xd8)

where iVar2 holds a VA. Under the identity memory model that is right - a VA IS
the address. Under the arena it is a wild 32-bit pointer, and the process dies
on it: that is how the frame loop reached BootScheduledNodeTimerWalk and
stopped.

The compiler already knows every one of these. `-Wint-to-pointer-cast` fires on
exactly "cast to a pointer from a SMALLER integer type", and a 32-bit value
used as an address in this engine is a VA by construction. So the sites come
from clang's own diagnostics - file, line and column - rather than from a regex
guessing at C syntax, and the rewrite wraps the operand:

    *(int *)MK4_PTR(iVar2 + 0xd8)

Under the identity model MK4_PTR expands to `(void *)(unsigned long)(va)`, so
the matching build and every existing co-exec verification are unchanged.

FUNCTION-pointer casts are reported, never rewritten: a stored code VA needs
the MK4_ResolveCode trampoline, not the data seam, and which one applies is a
judgement call per site.

  build/venv/bin/python tools/decomp/audit_va_deref.py         # report
  build/venv/bin/python tools/decomp/audit_va_deref.py --fix   # rewrite
"""
import collections
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

CC = ['cc', '-DNON_MATCHING', '-DMK4_ARENA', '-DTARGET_SDL', '-DMK4_NATIVE_FULL',
      '-Iinclude', '-I/opt/homebrew/include', '-O1', '-c', '-o', '/dev/null',
      '-Wno-everything', '-Wint-to-pointer-cast']

DIAG = re.compile(r"^(.*?):(\d+):(\d+): warning: cast to '([^']*)'"
                  r"(?: \(aka '[^']*'\))? from smaller integer type")

# a cast whose target is a function pointer needs the CODE trampoline instead
FN_PTR = re.compile(r'\(\s*\*\s*\)|Method|code\b|void\s*\(')


def sources():
    out = [l.strip() for l in
           (ROOT / 'tools' / 'decomp' / 'native_full_srcs.txt').read_text().split('\n')
           if l.strip()]
    out += [str(p.relative_to(ROOT)) for p in (ROOT / 'src/platform/sdl').glob('*.c')]
    return [f for f in out if (ROOT / f).exists()]


def diagnostics(path):
    r = subprocess.run(CC + [path], capture_output=True, text=True, cwd=ROOT)
    hits = []
    for line in r.stderr.split('\n'):
        m = DIAG.match(line)
        if m:
            hits.append((int(m.group(2)), int(m.group(3)), m.group(4)))
    return hits


def operand_span(text, i):
    """Given the offset of `(TYPE *)operand`, return (start, end) of operand."""
    if text[i] != '(':
        return None
    depth, j = 0, i
    while j < len(text):                      # skip the cast's own parentheses
        depth += (text[j] == '(') - (text[j] == ')')
        j += 1
        if depth == 0:
            break
    while j < len(text) and text[j] in ' \t':
        j += 1
    if j >= len(text):
        return None
    if text[j] == '(':                        # parenthesised operand
        depth, k = 0, j
        while k < len(text):
            depth += (text[k] == '(') - (text[k] == ')')
            k += 1
            if depth == 0:
                return j, k
        return None
    m = re.compile(r'[A-Za-z_]\w*').match(text, j)   # bare identifier
    return (j, m.end()) if m else None


def main():
    fix = '--fix' in sys.argv
    total = skipped = files = 0
    for f in sources():
        hits = diagnostics(f)
        if not hits:
            continue
        path = ROOT / f
        lines = path.read_text().split('\n')
        n = fnptr = 0
        # right-to-left within a line so earlier columns stay valid
        for ln, col, ty in sorted(hits, key=lambda h: (-h[0], -h[1])):
            if ln - 1 >= len(lines):
                continue
            text = lines[ln - 1]
            if FN_PTR.search(ty):
                fnptr += 1
                continue
            span = operand_span(text, col - 1)
            if not span:
                continue
            a, b = span
            n += 1
            if fix:
                lines[ln - 1] = text[:a] + 'MK4_PTR(' + text[a:b] + ')' + text[b:]
        total += n
        skipped += fnptr
        files += 1
        if fix and n:
            body = '\n'.join(lines)
            if '#include "portable/mem_model.h"' not in body:
                ls = body.split('\n')
                stop = next((k for k, l in enumerate(ls)
                             if l.startswith('#ifdef NON_MATCHING')
                             or re.match(r'^[A-Za-z_][\w *]*\w\s*\(', l)), len(ls))
                head = [k for k, l in enumerate(ls[:stop]) if l.startswith('#include')]
                ls.insert((max(head) + 1) if head else 0,
                          '#include "portable/mem_model.h"')
                body = '\n'.join(ls)
            path.write_text(body)
        print('  %-52s %3d %s%s' % (f.replace('src/', ''), n,
                                    'rewritten' if fix else 'sites',
                                    '  (+%d function-pointer, left alone)' % fnptr
                                    if fnptr else ''))
    print('%s: %d sites in %d files; %d function-pointer casts reported only'
          % ('rewrote' if fix else 'found', total, files, skipped))
    return 0


if __name__ == '__main__':
    sys.exit(main())
