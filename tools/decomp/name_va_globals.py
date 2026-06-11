#!/usr/bin/env python3
"""Step 3 of the native memory model: make named-global access consistent.

Many twins read/write a named scalar global by its raw VA, e.g.
    *(unsigned int *)MK4_VA(unsigned int, 0x542044)
which under the arena reads the arena copy - a DIFFERENT location than the C
variable g_currentNodeIdx that other code uses by name (dual-copy bug). Rewrite
the deref form to the NAMED C global so all access shares one location:
    *(T *)MK4_VA(T, 0xVA)  ->  g_name        (VA uniquely named + C-defined)
Identity-preserving under the verifier/matching (g_name is gdef'd to *(uint*)VA,
== *(T*)VA), so verify_coexec stays VERIFIED. NON_MATCHING twin bodies only.
"""
import re, sys, yaml, collections
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]

e = yaml.safe_load((ROOT / 'config' / 'extras_map.yaml').read_text())
byva = collections.defaultdict(list)
for n, v in e.items():
    if isinstance(v, int) and n.startswith('g_'):
        byva[v].append(n)
uniq = {v: ns[0] for v, ns in byva.items() if len(ns) == 1}
defined = set(re.findall(r'extern\s+[\w ]+?\s+(g_\w+);',
                         (ROOT / 'include' / 'portable' / 'native_globals.h').read_text()))

DEREF = re.compile(r'\*\s*\(\s*(?:unsigned int|int|u32|uint)\s*\*\s*\)\s*'
                   r'MK4_VA\(\s*(?:unsigned int|int|u32|uint)\s*,\s*0x([0-9a-fA-F]+)u?\s*\)')

def rewrite_block(blk):
    n = 0
    def sub(m):
        nonlocal n
        va = int(m.group(1), 16)
        if va in uniq and uniq[va] in defined:
            n += 1
            return uniq[va]
        return m.group(0)
    return DEREF.sub(sub, blk), n

def process(path):
    s = Path(path).read_text(errors='ignore')
    out = []; i = 0; total = 0
    for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
        j = s.find('#else', m.end())
        if j < 0: j = s.find('#endif', m.end())
        if j < 0: continue
        out.append(s[i:m.end()])
        body, n = rewrite_block(s[m.end():j]); total += n
        out.append(body); i = j
    out.append(s[i:])
    if total: Path(path).write_text(''.join(out))
    return total

if __name__ == '__main__':
    tot = 0; nf = 0
    for p in sys.argv[1:]:
        n = process(p)
        if n: nf += 1; tot += n
    print('rewrote %d VA-derefs -> named globals across %d files' % (tot, nf))
