#!/usr/bin/env python3
"""
Find twins whose comparisons lost their SIGN.

Every fixed-VA global is typed `unsigned int` - by alias_globals.py for the
native build, and by verify_coexec's gdef for the harness. That is fine for the
bit-twiddling the engine mostly does, but it silently INVERTS a signed test:

    g_x < 0     -> never true
    0 < g_x     -> becomes "g_x != 0"
    -1 < g_x    -> becomes "g_x >= 0xffffffff", i.e. almost never true

and it is invisible: it compiles, and co-exec still passes as long as no seed
drives the value negative. Both sides are then consistently wrong together.

A hit is only a real defect if the ORIGINAL branches on a signed condition, so
each one is cross-checked against the original's own jcc opcodes. Functions
whose original uses only unsigned branches (jb/jae/ja/jbe) are dropped - there
the unsigned C is correct.

Fix a real hit by casting at the comparison: `(int)g_x < 0`.

  build/venv/bin/python tools/decomp/audit_signed.py          # report
  build/venv/bin/python tools/decomp/audit_signed.py --fix    # insert the casts
"""
import re
import sys
from pathlib import Path

import capstone
import yaml

sys.path.insert(0, str(Path(__file__).resolve().parent))
import closure as C

ROOT = Path(__file__).resolve().parents[2]

SIGNED_JCC = {'jl', 'jle', 'jg', 'jge', 'js', 'jns'}

PATTERNS = [
    (r'\b(g_\w+)\s*<\s*0\b',   'g < 0 is never true'),
    (r'\b(g_\w+)\s*<=\s*0\b',  'g <= 0 collapses to == 0'),
    (r'\b0\s*<\s*(g_\w+)',     '0 < g collapses to != 0'),
    (r'\b0\s*>\s*(g_\w+)',     '0 > g is never true'),
    (r'\b(g_\w+)\s*>\s*0\b',   'g > 0 collapses to != 0'),
    (r'-1\s*<\s*(g_\w+)',      '-1 < g is almost never true'),
    (r'\b(g_\w+)\s*<\s*-\d',   'g < -N is never true'),
]


def cast_in(expr):
    """Insert `(int)` in front of the global inside one matched comparison."""
    return re.sub(r'\b(g_\w+)', r'(int)\1', expr, count=1)


def fix_file(path, signed):
    """Rewrite the NON_MATCHING blocks of one file; return the number of casts."""
    s = path.read_text(errors='ignore')
    out, pos, n = [], 0, 0
    for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
        j = s.find('#else', m.end())
        end = j if j > 0 else len(s)
        blk = s[m.end():end]
        # comments are scanned for globals by the harness, so never touch them
        spans = [(c.start(), c.end()) for c in re.finditer(r'/\*.*?\*/', blk, re.S)]

        def in_comment(i):
            return any(a <= i < b for a, b in spans)

        edits = []
        for pat, _ in PATTERNS:
            for mm in re.finditer(pat, blk):
                seg = blk[max(0, mm.start() - 12):mm.end()]
                if any(c in seg for c in ('(int)', '(s32)', '(short)', '(s16)')):
                    continue
                if in_comment(mm.start()):
                    continue
                edits.append((mm.start(), mm.end()))
        edits.sort()
        new, last = [], 0
        for a, b in edits:
            if a < last:
                continue
            new.append(blk[last:a])
            new.append(cast_in(blk[a:b]))
            last = b
            n += 1
        new.append(blk[last:])
        out.append(s[pos:m.end()])
        out.append(''.join(new))
        pos = end
    out.append(s[pos:])
    if n:
        path.write_text(''.join(out))
    return n


def signed_functions():
    """name -> True when the original's own bytes use a signed conditional."""
    cfg = yaml.safe_load((ROOT / 'config' / 'symbols.yaml').read_text())
    data, secs = C.load_image()
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    out = {}
    for f in cfg['functions']:
        if not f.get('size'):
            continue
        code = C.read_va(data, secs, f['addr'], f['size'])
        out[f['name']] = any(i.mnemonic in SIGNED_JCC
                             for i in md.disasm(code, f['addr'])) if code else False
    return out


def twin_bodies(path):
    """[(function name, body)] for each twin in a file."""
    s = path.read_text(errors='ignore')
    out = []
    for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
        j = s.find('#else', m.end())
        blk = s[m.end(): j if j > 0 else len(s)]
        blk = re.sub(r'/\*.*?\*/', '', blk, flags=re.S)
        for fm in re.finditer(r'(?m)^[A-Za-z_][\w *]*?\b(\w+)\s*\([^;{]*\)\s*\{', blk):
            k, depth = blk.index('{', fm.end() - 1), 0
            i = k
            while i < len(blk):
                depth += (blk[i] == '{') - (blk[i] == '}')
                if depth == 0:
                    break
                i += 1
            out.append((fm.group(1), blk[k:i + 1]))
    return out


def main():
    signed = signed_functions()
    if '--fix' in sys.argv:
        total, files = 0, 0
        for path in sorted(Path(ROOT / 'src').rglob('*.c')):
            if not any(signed.get(fn, False)
                       for fn, _ in twin_bodies(path)):
                continue
            n = fix_file(path, signed)
            if n:
                files += 1
                total += n
                print('  %-52s %d casts' % (str(path.relative_to(ROOT)), n))
        print('inserted %d (int) casts across %d files' % (total, files))
        return 0
    real, dropped = [], 0
    for path in sorted(Path(ROOT / 'src').rglob('*.c')):
        for fn, body in twin_bodies(path):
            for pat, why in PATTERNS:
                for m in re.finditer(pat, body):
                    seg = body[max(0, m.start() - 12):m.end()]
                    if any(c in seg for c in ('(int)', '(s32)', '(short)', '(s16)')):
                        continue
                    if not signed.get(fn, False):
                        dropped += 1
                        continue
                    real.append((str(path.relative_to(ROOT)), fn,
                                 m.group(0).strip(), why))

    print('unsigned-typed signed tests, cross-checked against the original: '
          '%d real, %d dropped (original branches unsigned)' % (len(real), dropped))
    seen = set()
    for p, fn, expr, why in real:
        if (p, fn, expr) in seen:
            continue
        seen.add((p, fn, expr))
        print('  %-46s %-34s %-26s %s'
              % (p.replace('src/', ''), fn, expr, why))
    return 1 if real else 0


if __name__ == '__main__':
    sys.exit(main())
