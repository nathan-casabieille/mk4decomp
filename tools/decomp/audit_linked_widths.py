#!/usr/bin/env python3
"""Check that every LINKED twin spells its narrow globals at the real width.

config/global_widths.yaml records the C type of each fixed-VA global the
original only ever touches one or two bytes wide. A twin that names such a
global while its file gives it the 32-bit spelling reads or writes four bytes
at a two-byte address - for the working 3x3 that means every read pulls TWO
neighbouring elements, unsigned, and the arithmetic lands thousands of units
off. BboxProjectAndStash had exactly that.

The co-exec harnesses do NOT catch it on their own: they type globals
themselves (verify_project.py's WIDTH16, verify_frame_core.py's TYPES), so a
harness can report VERIFIED while the file the native build compiles still says
`unsigned int`.

This reads every TU in native_full_srcs.txt and reports a global that
  - global_widths.yaml calls narrow,
  - the file's NON_MATCHING code actually uses, and
  - the file spells 32 bits wide (or does not spell at all, so the generic
    alias pass gives it the 32-bit form).

It also reports the opposite mistake: an alias whose lvalue is a POINTER
type (`T **`), which on a 64-bit host is EIGHT bytes over an engine slot of
four - so a single write lands on the neighbouring global as well.
transform_accumulate.c had exactly that on 0x542048: writing it also wrote
0x54204c, the packed pointer the very next call reads, so an entire skeleton
transformed the same stale vector and rendered on one point (fd3a4eaf4).

Usage:  build/venv/bin/python tools/decomp/audit_linked_widths.py
"""
import re
import pathlib

import yaml

ROOT = pathlib.Path(__file__).resolve().parents[2]
widths = yaml.safe_load((ROOT / 'config' / 'global_widths.yaml').read_text()) or {}
extras = yaml.safe_load((ROOT / 'config' / 'extras_map.yaml').read_text()) or {}
addr = {k: (v if isinstance(v, int) else int(str(v), 16)) for k, v in extras.items()}
occupied = sorted(set(addr.values()))

SIZE = {'unsigned char': 1, 'signed char': 1, 'char': 1,
        'unsigned short': 2, 'short': 2}


def clobbers_a_neighbour(name, ctype):
    """A 32-bit store at a narrow global's address overwrites the three or two
    bytes after it. Only when ANOTHER known global lives in that window is the
    wide spelling actually destructive - a lone byte flag with nothing behind
    it reads and writes the same value either way. This is what separates the
    real defects from the 32-bit spellings that are merely untidy."""
    a = addr.get(name)
    if a is None:
        return False
    w = SIZE.get(ctype, 4)
    lo, hi = a + w, a + 4
    import bisect
    i = bisect.bisect_left(occupied, lo)
    return i < len(occupied) and occupied[i] < hi

NARROW = re.compile(r'\b(char|short)\b')


def narrow_spelling(text, name):
    """True if the file gives `name` a 1- or 2-byte spelling."""
    for m in re.finditer(r'#define\s+%s\s+\(\*\(([^)]*)\)' % re.escape(name), text):
        if NARROW.search(m.group(1)):
            return True
    for m in re.finditer(r'extern\s+([\w ]*?)\s+%s\s*[;\[]' % re.escape(name), text):
        if NARROW.search(m.group(1)):
            return True
    return False


def spelled_wide(text, name):
    """True if the file gives `name` a 32-bit spelling somewhere."""
    return bool(re.search(r'#define\s+%s\s+\(\*\(unsigned int' % re.escape(name), text)
                or re.search(r'extern\s+(unsigned\s+)?int\s+%s\s*[;\[]' % re.escape(name), text)
                or re.search(r'extern\s+u32\s+%s\s*[;\[]' % re.escape(name), text))


CAST = re.compile(r'\*\s*\(\s*(?:unsigned\s+|signed\s+)?(?:char|short)\s*\*\s*\)\s*&\s*$')


def native_text(s):
    """Only what the native build actually compiles: comments gone, and the
    __asm bodies of the matching side dropped. Assembly mentions a global by
    name on a bare line, and a doc comment lists them - both looked like wide
    uses and made this tool over-report."""
    s = re.sub(r'/\*.*?\*/', ' ', s, flags=re.S)
    s = re.sub(r'//[^\n]*', ' ', s)
    out, depth = [], 0
    for line in s.splitlines(True):
        if depth == 0 and '__asm' in line:
            depth = line.count('{') - line.count('}')
            if depth <= 0 and '{' in line:
                depth = 1
            continue
        if depth > 0:
            depth += line.count('{') - line.count('}')
            continue
        out.append(line)
    return ''.join(out)


def bare_uses(text, name):
    """Uses of `name` that are NOT immediately behind a narrowing cast.
    transform_vertex.c aliases the six RGB scales as `unsigned int` and then
    writes every single access as `*(unsigned char *)&g_vtxRGBScale1_r` - the
    declaration is wide, the ACCESS is a byte, and the file is correct. Only a
    bare use actually stores four bytes."""
    n = 0
    for m in re.finditer(r'\b%s\b' % re.escape(name), text):
        before = text[max(0, m.start() - 40):m.start()]
        if CAST.search(before):
            continue
        line = text[text.rfind('\n', 0, m.start()) + 1:m.start()]
        if line.lstrip().startswith(('#define', 'extern', '*', '/*')):
            continue
        n += 1
    return n


BULK = re.compile(r'\b(?:memset|memcpy|rep\s+stos)\b')


def main():
    srcs = [l.strip() for l in
            (ROOT / 'tools' / 'decomp' / 'native_full_srcs.txt').read_text().split()]
    hits = 0
    for src in srcs:
        path = ROOT / src
        if not path.exists():
            continue
        text = path.read_text(errors='ignore')
        native = native_text(text)
        # only the NON_MATCHING side is what the native build compiles
        bad = []
        for name, ctype in widths.items():
            if name not in text:
                continue
            if narrow_spelling(text, name):
                continue
            if not spelled_wide(text, name):
                continue
            n = bare_uses(native, name)
            if not (clobbers_a_neighbour(name, ctype) and n):
                continue
            # Using the address as a BLOCK BASE is wide by design:
            # AppInit_Misc3 memsets 0x2a dwords from 0x007af958, and the map
            # calls that address narrow because other code touches it as a word.
            if any(BULK.search(l) for l in native.splitlines() if name in l):
                continue
            bad.append((name, ctype, n))
        if bad:
            hits += 1
            print('%s' % src)
            for name, ctype, n in sorted(bad):
                print('    %-34s should be %-14s (0x%06x, %d bare use%s, a '
                      'neighbour is inside the 4 bytes a wide store would touch)'
                      % (name, ctype, addr[name], n, '' if n == 1 else 's'))
    print('\naudit-linked-widths: %d of %d linked TUs spell a narrow global 32 bits '
          'wide WHERE THAT CLOBBERS A NEIGHBOUR' % (hits, len(srcs)))


main()


# --- pointer-typed aliases: 8 bytes of lvalue over a 4-byte engine slot ----
PTR_ALIAS = re.compile(
    r'#define\s+(\w+)\s+\(\*\(\s*\w[\w ]*?\*\*\s*\)\s*MK4_VA\(\s*\w[\w ]*,\s*(0x[0-9a-fA-F]+)')


def audit_pointer_aliases():
    srcs = [l.strip() for l in (ROOT / 'tools/decomp/native_full_srcs.txt')
            .read_text().splitlines() if l.strip() and not l.lstrip().startswith('#')]
    hits = []
    for rel in srcs:
        p = ROOT / rel
        if not p.exists():
            continue
        for m in PTR_ALIAS.finditer(p.read_text(errors='ignore')):
            hits.append((rel, m.group(1), m.group(2)))
    if hits:
        print(f'\naudit-linked-widths: {len(hits)} POINTER-typed alias(es) - '
              f'an 8-byte lvalue over a 4-byte slot clobbers the next global:')
        for rel, sym, va in hits:
            print(f'   {rel}: {sym} at {va}')
    else:
        print('audit-linked-widths: no pointer-typed aliases '
              '(no 8-byte lvalue over an engine slot)')
    return len(hits)


audit_pointer_aliases()

