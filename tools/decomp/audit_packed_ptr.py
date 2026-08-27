#!/usr/bin/env python3
"""
Find packed pointers built from a HOST address instead of a VA.

The engine addresses nodes by "packed pointer" = VA / 4, and a twin that needs
one for a global writes it the way the original does:

    g_fightGroupHead = (u32)&g_fightTableC0 >> 2;

Under the identity memory model that is right - a VA IS the address. Under the
arena it is not: `&g_fightTableC0` is a 64-bit HOST pointer, the cast truncates
it to its low 32 bits, and the result is a packed pointer to nowhere. The
consumer then dereferences it and the process dies.

That is not hypothetical. It is why MK4.native.full segfaulted in
FightFrameStep_Inner: FightFrameStep primed g_cj_0054205c this way, and the
index came out 0x19235429 where the VA wanted 0x135429 - the low 20 bits
matched, the rest was whatever the arena happened to be mapped at.

The fix is the seam: MK4_UNPTR(&x) is the VA that host pointer stands for, and
under the identity model it is exactly `(unsigned)(unsigned long)p`, so the
matching build's bytes and every existing co-exec verification are unchanged.
The outer cast is preserved so a signed `(int)&x >> 2` keeps its arithmetic
shift.

  build/venv/bin/python tools/decomp/audit_packed_ptr.py         # report
  build/venv/bin/python tools/decomp/audit_packed_ptr.py --fix   # rewrite
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

# (cast)&global[opt index] >> 2  - the shift is what makes it a packed pointer
PAT = re.compile(r'\((u32|unsigned int|uint|int|s32)\)\s*&\s*(g_\w+)((?:\[[^\]]*\])?)\s*>>\s*2')

COMMENT = re.compile(r'/\*.*?\*/|//[^\n]*', re.S)


def regions(text):
    """[(start, end)] of the parts of a file a twin actually compiles from:
    each NON_MATCHING block, or the whole file when it has none."""
    out = []
    for m in re.finditer(r'#ifdef NON_MATCHING\b', text):
        j = text.find('#else', m.end())
        out.append((m.end(), j if j > 0 else len(text)))
    return out or [(0, len(text))]


def scan(text):
    """[(start, end, matched text)] for every site outside a comment."""
    blanked = COMMENT.sub(lambda m: ' ' * (m.end() - m.start()), text)
    hits = []
    for lo, hi in regions(text):
        for m in PAT.finditer(blanked, lo, hi):
            hits.append((m.start(), m.end(), text[m.start():m.end()]))
    return hits


def needs_include(text):
    return '#include "portable/mem_model.h"' not in text


def main():
    fix = '--fix' in sys.argv
    total = files = 0
    for path in sorted(Path(ROOT / 'src').rglob('*.c')):
        text = path.read_text(errors='ignore')
        hits = scan(text)
        if not hits:
            continue
        files += 1
        total += len(hits)
        if not fix:
            print('  %-50s %2d  e.g. %s'
                  % (str(path.relative_to(ROOT / 'src')), len(hits), hits[0][2]))
            continue
        out, last = [], 0
        for a, b, _ in hits:
            out.append(text[last:a])
            out.append(PAT.sub(r'(\1)MK4_UNPTR(&\2\3) >> 2', text[a:b]))
            last = b
        out.append(text[last:])
        new = ''.join(out)
        if needs_include(new):
            # after the last include in the file's header region
            lines = new.split('\n')
            stop = next((k for k, l in enumerate(lines)
                         if l.startswith('#ifdef NON_MATCHING')
                         or re.match(r'^[A-Za-z_][\w *]*\w\s*\(', l)), len(lines))
            head = [k for k, l in enumerate(lines[:stop]) if l.startswith('#include')]
            at = (max(head) + 1) if head else 0
            lines.insert(at, '#include "portable/mem_model.h"')
            new = '\n'.join(lines)
        path.write_text(new)
        print('  %-50s %2d rewritten' % (str(path.relative_to(ROOT / 'src')), len(hits)))
    print('%s: %d sites in %d files' % ('rewrote' if fix else 'found', total, files))
    return 0 if (fix or total == 0) else 1


if __name__ == '__main__':
    sys.exit(main())
