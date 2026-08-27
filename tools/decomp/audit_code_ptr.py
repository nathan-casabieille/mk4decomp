#!/usr/bin/env python3
"""
Find indirect calls that jump to a raw VA instead of going through the
VA -> native-function trampoline.

The engine keeps callbacks in fixed-VA globals - g_walkCallback is the one the
scene walk runs through - and those globals are THIRTY-TWO BITS. A host
function pointer does not fit in one, so the value they hold can only ever be a
VA, and every call through them has to go via MK4_ResolveCode. A twin that
writes

    ((void (*)(void))saved_cb)()

is jumping to a 32-bit VA, which on this host is unmapped.

Calls whose target is a NAMED function are fine and are not reported: the cast
there only fixes up a signature, and the call is direct. Only a call through a
VARIABLE is a VA.

Under the identity memory model MK4_ResolveCode is `(void *)(unsigned long)va`,
so wrapping changes nothing for the matching build or for any existing co-exec
verification.

  build/venv/bin/python tools/decomp/audit_code_ptr.py         # report
  build/venv/bin/python tools/decomp/audit_code_ptr.py --fix   # wrap them
"""
import re
import sys
from pathlib import Path

import yaml

ROOT = Path(__file__).resolve().parents[2]

CALL = re.compile(r'\(\s*\(\s*(?:void|int|unsigned int|s32|u32)\s*'
                  r'\(\s*\*\s*\)\s*\([^)]*\)\s*\)\s*([A-Za-z_]\w*)\s*\)\s*\(')


def regions(text):
    out = []
    for m in re.finditer(r'#ifdef NON_MATCHING\b', text):
        j = text.find('#else', m.end())
        out.append((m.end(), j if j > 0 else len(text)))
    return out or [(0, len(text))]


def main():
    fix = '--fix' in sys.argv
    cfg = yaml.safe_load((ROOT / 'config' / 'symbols.yaml').read_text())
    known = {f['name'] for f in cfg['functions']} | {'MK4_ResolveCode'}
    total = files = 0

    for path in sorted((ROOT / 'src').rglob('*.c')):
        text = path.read_text(errors='ignore')
        blanked = re.sub(r'/\*.*?\*/|//[^\n]*', lambda m: ' ' * (m.end() - m.start()),
                         text, flags=re.S)
        spans = []
        for lo, hi in regions(text):
            for m in CALL.finditer(blanked, lo, hi):
                if m.group(1) not in known:
                    spans.append((m.start(1), m.end(1), m.group(1)))
        if not spans:
            continue
        files += 1
        total += len(spans)
        if not fix:
            print('  %-46s %s' % (str(path.relative_to(ROOT / 'src')),
                                  ', '.join(sorted({s[2] for s in spans}))))
            continue
        out, last = [], 0
        for a, b, name in sorted(spans):
            out.append(text[last:a])
            out.append('MK4_ResolveCode(' + name + ')')
            last = b
        out.append(text[last:])
        new = ''.join(out)
        if '#include "portable/mem_model.h"' not in new:
            lines = new.split('\n')
            stop = next((k for k, l in enumerate(lines)
                         if l.startswith('#ifdef NON_MATCHING')
                         or re.match(r'^[A-Za-z_][\w *]*\w\s*\(', l)), len(lines))
            head = [k for k, l in enumerate(lines[:stop]) if l.startswith('#include')]
            lines.insert((max(head) + 1) if head else 0,
                         '#include "portable/mem_model.h"')
            new = '\n'.join(lines)
        path.write_text(new)
        print('  %-46s %d wrapped' % (str(path.relative_to(ROOT / 'src')), len(spans)))

    print('%s: %d indirect calls in %d files'
          % ('wrapped' if fix else 'found', total, files))
    return 0


if __name__ == '__main__':
    sys.exit(main())
