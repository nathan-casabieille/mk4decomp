#!/usr/bin/env python3
"""Post-process Ghidra-decompiled C toward a NON_MATCHING twin (Phase 3).

Stage 2 of the Ghidra pipeline (stage 1 = MK4Decompile.java -> raw C):
  - rename Ghidra placeholders to our symbols:
      FUN_<hex>  -> symbols.yaml function name at that VA
      DAT_<hex> / &DAT_<hex> -> extras_map global name at that VA
  - rewrite packed-ptr node access to the memory-model seam:
      *(T *)(EXPR * 4 + 0xN)  -> MK4_NODE_AT(T, EXPR, 0xN)
      *(T *)(EXPR * 4)        -> MK4_NODE_AT(T, EXPR, 0)

What it deliberately does NOT do yet (the careful, reviewed part - next
iteration): reconcile the guessed signature with our prototype, choose
final field types, and inject the result into the source file under
#ifdef NON_MATCHING. Output here is for review.

Usage:
  python3 tools/decomp/ghidra_postprocess.py build/ghidra_decomp/00401000.c
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def load_maps():
    import yaml
    fn_by_va = {}
    syms = yaml.safe_load((ROOT / 'config' / 'symbols.yaml').read_text())
    for s in syms.get('functions', []):
        a, n = s.get('addr'), s.get('name')
        if a is not None and n:
            fn_by_va[int(a)] = n
    gl_by_va = {}
    extras = yaml.safe_load((ROOT / 'config' / 'extras_map.yaml').read_text())
    for n, a in extras.items():
        if isinstance(a, int):
            gl_by_va.setdefault(int(a), n)   # first name wins (stable)
    return fn_by_va, gl_by_va


def postprocess(text, fn_by_va, gl_by_va):
    # FUN_00xxxxxx -> our function name (or leave if unknown)
    def fun_sub(m):
        va = int(m.group(1), 16)
        return fn_by_va.get(va, m.group(0))
    text = re.sub(r'FUN_([0-9a-fA-F]{8})', fun_sub, text)

    # &DAT_00xxxxxx -> &g_name ; DAT_00xxxxxx -> g_name
    def dat_sub(m):
        va = int(m.group(2), 16)
        name = gl_by_va.get(va)
        if not name:
            return m.group(0)
        return (m.group(1) or '') + name
    text = re.sub(r'(&)?DAT_([0-9a-fA-F]{8})', dat_sub, text)

    # packed-ptr node access -> seam (offset may be hex 0xN or decimal N)
    #   *(T *)(EXPR * 4 + N)
    text = re.sub(
        r'\*\(([\w ]+?) \*\)\(([A-Za-z_]\w*) \* 4 \+ (0x[0-9a-fA-F]+|\d+)\)',
        r'MK4_NODE_AT(\1, \2, \3)', text)
    #   *(T *)(EXPR * 4)
    text = re.sub(
        r'\*\(([\w ]+?) \*\)\(([A-Za-z_]\w*) \* 4\)',
        r'MK4_NODE_AT(\1, \2, 0)', text)
    return text


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return
    fn_by_va, gl_by_va = load_maps()
    for p in sys.argv[1:]:
        text = Path(p).read_text()
        print('=== %s ===' % p)
        print(postprocess(text, fn_by_va, gl_by_va))


if __name__ == '__main__':
    main()
