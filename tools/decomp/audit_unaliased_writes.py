#!/usr/bin/env python3
"""Find a linked native TU that WRITES an engine global without an arena alias.

The trap this catches, twice over in one session: a TU in
native_full_srcs.txt says `extern unsigned int g_currentNodeIdx;` and
assigns to it. Under the arena that assignment lands in the weak native
global of the same name (a host variable), NOT in the arena word at
0x542044 that every other TU reads through MK4_VA. The write is silently
private: nothing crashes, the value simply never arrives.

DualScaledLitInitJmp hit exactly this - it set the geo loader's record
index into a host variable, so the loader read zero and opened an empty
asset name.

A name is reported when
  - the TU is in native_full_srcs.txt (so it is really linked), and
  - the name has a known VA in config/extras_map.yaml, and
  - the file assigns to it, and
  - the file has no `#define <name> (*(...)MK4_VA(...))` alias.

`make unaliased-writes-audit`. The fix is normally
`tools/decomp/alias_globals.py <file>` - which guards the extern and adds
the alias, leaving the matching build untouched. Globals used by ADDRESS
(CRT-style init pointer tables) are the exception: they stay native.
"""
import pathlib
import re
import sys

import yaml

ROOT = pathlib.Path(__file__).resolve().parents[2]


def main():
    srcs = [l.strip() for l in
            (ROOT / 'tools' / 'decomp' / 'native_full_srcs.txt').read_text().split('\n')
            if l.strip()]
    gl = {n: a for n, a in
          yaml.safe_load((ROOT / 'config' / 'extras_map.yaml').read_text()).items()
          if isinstance(a, int)}

    seen, files = set(), 0
    for s in srcs:
        p = ROOT / s
        if not p.exists():
            continue
        files += 1
        t = p.read_text(errors='ignore')
        aliased = set(re.findall(r'#define (g_\w+) \(\*\(', t))
        for m in re.finditer(r'^\s*(g_\w+)\s*=[^=]', t, re.M):
            n = m.group(1)
            if n in gl and n not in aliased and (s, n) not in seen:
                seen.add((s, n))
                print(f'{s}: writes {n} ({gl[n]:#x}) with no arena alias')

    print(f'\naudit-unaliased-writes: {len(seen)} site(s) in {files} linked TUs')
    # Report-only, like the other audits: the remaining sites are a review
    # queue, not a build break. The render.c ones in particular are surface
    # handles the SDL backend owns, and moving them to arena aliases would
    # move the golden frames the byte gates compare against.
    return 0


if __name__ == '__main__':
    sys.exit(main())
