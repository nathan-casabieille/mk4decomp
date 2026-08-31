#!/usr/bin/env python3
"""Cross-check a twin's global references against the original's bytes.

A pure-C body that the matching build SYNTHESIZES rather than compiles is never
validated by `make matching`: it can name the wrong global and nothing notices
until the native build links it. DirtyPushCallPop was exactly that - it tested
g_walkCallback (0x54206c) where 0x004055b0 tests g_currentNodeIdx (0x542044).

This compares two sets for each function:
  - the absolute VAs its original bytes reference (capstone, any operand with a
    disp32 that lands in the image's data range)
  - the VAs the C body names, resolved through config/extras_map.yaml

and reports a function whose C references a VA the original never touches.
That is not proof of a bug on its own - a twin may legitimately reach a global
the original reaches through a register - but every hit is worth a look, and a
SYMMETRIC difference (C names X, original touches Y, neither the other) is the
signature of a mis-named global.

Usage:  build/venv/bin/python tools/decomp/audit_global_refs.py [NAME ...]
"""
import re
import sys
import pathlib

import capstone
import yaml

ROOT = pathlib.Path(__file__).resolve().parents[2]
BASE = 0x400000
DATA_HI = 0x00fa0000

arena = (ROOT / 'build' / 'arena.bin').read_bytes()
syms = yaml.safe_load((ROOT / 'config' / 'symbols.yaml').read_text())['functions']
extras = yaml.safe_load((ROOT / 'config' / 'extras_map.yaml').read_text()) or {}
name_to_va = {k: (v if isinstance(v, int) else int(str(v), 16))
              for k, v in extras.items()}

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

# Everything below the end of the last function is CODE. Call targets and
# jump-table entries land there and are not globals; counting them made every
# twin that calls anything look suspicious.
DATA_LO = max((f['addr'] if isinstance(f['addr'], int) else int(str(f['addr']), 16))
              + f.get('size', 0) for f in syms)
DATA_LO = (DATA_LO + 0xfff) & ~0xfff


def orig_global_refs(addr, size):
    """Absolute data VAs the original bytes reference."""
    out = set()
    for ins in md.disasm(arena[addr - BASE:addr - BASE + size], addr):
        for op in ins.operands:
            if op.type == capstone.x86.X86_OP_MEM:
                # ANY displacement in the data range, whatever the addressing
                # form. `[edx + 0x53e368]` and `[eax*4 + 0x7ab0dc]` are both a
                # global used as a table base, which is what the C names;
                # requiring base == 0 missed every one of them.
                d = op.mem.disp & 0xffffffff
                if DATA_LO <= d < DATA_HI:
                    out.add(d)
            elif op.type == capstone.x86.X86_OP_IMM:
                d = op.imm & 0xffffffff
                if DATA_LO <= d < DATA_HI:
                    out.add(d)
    return out


FNDEF = r'^(?:[A-Za-z_][\w *]*?\b)%s\s*\([^){]*\)\s*\{'


def strip_comments(s):
    """A VA quoted in a comment is documentation, not a reference - and the
    lifted twins document their own addresses, which made every one of them
    look like it named a global it never touches."""
    return re.sub(r'/\*.*?\*/', ' ', re.sub(r'//[^\n]*', ' ', s), flags=re.S)


def twin_body(path, name):
    """The NON_MATCHING body of `name` in `path`, or None."""
    s = strip_comments(path.read_text(errors='ignore'))
    for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
        j = s.find('\n#else', m.end())
        if j < 0:
            # a NATIVE-ONLY twin has no #else arm - take up to its #endif
            j = s.find('\n#endif', m.end())
        if j < 0:
            continue
        block = s[m.end():j]
        nm = re.search(FNDEF % re.escape(name), block, re.M)
        if not nm:
            continue
        i = block.index('{', nm.end() - 1)
        depth, k = 0, i
        while k < len(block):
            if block[k] == '{':
                depth += 1
            elif block[k] == '}':
                depth -= 1
                if depth == 0:
                    break
            k += 1
        return block[nm.start():k + 1]
    return None


def main():
    want = set(sys.argv[1:])
    listed = [l.strip() for l in
              (ROOT / 'tools' / 'decomp' / 'native_full_srcs.txt').read_text().split()]
    by_name = {f['name']: f for f in syms}
    hits = 0
    checked = 0

    for src in listed:
        path = ROOT / src
        if not path.exists():
            continue
        for name, f in by_name.items():
            if want and name not in want:
                continue
            body = twin_body(path, name)
            if body is None:
                continue
            addr = f['addr'] if isinstance(f['addr'], int) else int(str(f['addr']), 16)
            checked += 1
            ref = orig_global_refs(addr, f.get('size', 0))
            # VA 0 is a BASE-0 packed table (g_siblingTable and friends): the
            # original addresses it as `[ecx*4]` with no displacement at all,
            # so it can never appear in `ref` and is not evidence of anything.
            named = {name_to_va[g] for g in set(re.findall(r'\bg_\w+', body))
                     if g in name_to_va and name_to_va[g] != 0}
            # also count VAs the twin writes as literals (MK4_VA(T, 0x...))
            named |= {v for v in (int(h, 16) for h in
                                  re.findall(r'0x00([0-9a-f]{6})u?', body))
                      if DATA_LO <= v < DATA_HI}
            extra = {v for v in named if v not in ref}
            missing = {v for v in ref if v not in named}
            if extra and missing:
                hits += 1
                print('%-34s %s' % (name, src))
                print('    C names but original never touches: %s'
                      % ', '.join('0x%06x' % v for v in sorted(extra)))
                print('    original touches but C never names: %s'
                      % ', '.join('0x%06x' % v for v in sorted(missing)))
    print('\naudit-global-refs: %d twins checked, %d with a symmetric difference'
          % (checked, hits))


main()
