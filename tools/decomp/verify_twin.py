#!/usr/bin/env python3
"""Runtime differential verification of leaf void(void) NON_MATCHING twins.

For a leaf twin (no calls), run the ORIGINAL function under Unicorn on the
real image (arena mapped at its original VAs) and the PORTABLE twin
natively on the same arena, then diff the resulting memory. If the byte
deltas match, the twin is behavior-confirmed for that input state - it
graduates from "compiles" to "verified".

Both worlds operate on one shared address model: arena[VA - 0x400000].
The native harness routes the twin's named globals into the arena via
#defines, so its writes land at the same offsets Unicorn writes to.

Run with the unicorn venv:
  build/venv/bin/python tools/decomp/verify_twin.py [NAME ...]
With no args, verifies all leaf twins.
"""
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x00400000
ARENA = ROOT / 'build' / 'arena.bin'
KW = {'if', 'while', 'for', 'return', 'sizeof', 'switch', 'do', 'else'}


def load_maps():
    import yaml
    syms = yaml.safe_load((ROOT / 'config' / 'symbols.yaml').read_text())
    fn_va = {s['name']: int(s['addr']) for s in syms['functions']
             if s.get('name') and s.get('addr') is not None}
    gl_va = {}
    for n, a in yaml.safe_load((ROOT / 'config' / 'extras_map.yaml').read_text()).items():
        if isinstance(a, int):
            gl_va.setdefault(n, int(a))
    return fn_va, gl_va


def extract_twin(name):
    """Return (body_source, srcfile) for a leaf twin, or None."""
    for f in (ROOT / 'src').rglob('*.c'):
        s = f.read_text(errors='ignore')
        for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
            j = s.find('#else', m.end())
            if j < 0:
                continue
            block = s[m.end():j]
            nm = re.search(r'\bvoid\s+(%s)\s*\(\s*void\s*\)\s*\{' % re.escape(name), block)
            if not nm:
                continue
            # full function text (from 'void NAME' to the closing brace before #else)
            start = nm.start()
            depth = 0
            i = block.index('{', nm.end() - 1)
            k = i
            while k < len(block):
                if block[k] == '{':
                    depth += 1
                elif block[k] == '}':
                    depth -= 1
                    if depth == 0:
                        break
                k += 1
            return block[start:k + 1], f
    return None


def run_unicorn(func_va, arena):
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_MEM_WRITE
    from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP
    size = (len(arena) + 0xFFF) & ~0xFFF
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, size)
    uc.mem_write(BASE, bytes(arena))
    stack = 0x00100000
    uc.mem_map(stack, 0x10000)
    SENT = 0x00bad0de
    esp = stack + 0xF000
    uc.reg_write(UC_X86_REG_ESP, esp)
    uc.mem_write(esp, SENT.to_bytes(4, 'little'))   # return address
    writes = {}

    def on_write(uc, access, addr, sz, val, ud):
        if BASE <= addr < BASE + size:
            writes[addr] = (sz, val & ((1 << (sz * 8)) - 1))
    uc.hook_add(UC_HOOK_MEM_WRITE, on_write)
    try:
        uc.emu_start(func_va, SENT, count=200000)
    except Exception as e:
        return None, 'unicorn: %s' % e
    delta = {}
    for addr, (sz, val) in writes.items():
        delta[addr - BASE] = val.to_bytes(sz, 'little')
    return delta, None


def run_native(name, body, gl_va):
    globs = sorted(set(re.findall(r'\bg_[A-Za-z]\w*', body)))
    if any(g not in gl_va for g in globs):
        return None, 'unmapped global: %s' % [g for g in globs if g not in gl_va]
    defs = ''.join(
        '#define %s (*(unsigned int *)(g_mk4Arena + 0x%x))\n' % (g, gl_va[g] - BASE)
        for g in globs)
    harness = (
        '#define NON_MATCHING 1\n#define MK4_ARENA 1\n'
        '#include "portable/ghidra_types.h"\n#include "portable/mem_model.h"\n'
        '#include "portable/arena.h"\n#include <stdio.h>\n'
        + defs + body + '\n'
        'int main(void){\n'
        '  if(!MK4_ArenaInitFromFile("%s")) return 2;\n' % ARENA +
        '  %s();\n' % name +
        '  fwrite(g_mk4Arena,1,g_mk4ArenaSize,stdout);\n  return 0;\n}\n')
    with tempfile.TemporaryDirectory() as d:
        c = Path(d) / 'h.c'
        c.write_text(harness)
        exe = Path(d) / 'h'
        r = subprocess.run(
            ['cc', '-DNON_MATCHING', '-DMK4_ARENA', '-I' + str(ROOT / 'include'),
             '-w', str(c), str(ROOT / 'src' / 'portable' / 'arena.c'), '-o', str(exe)],
            capture_output=True, text=True)
        if r.returncode:
            return None, 'compile: ' + (r.stderr.strip().splitlines() or [''])[-1]
        run = subprocess.run([str(exe)], capture_output=True, cwd=str(ROOT))
        if run.returncode:
            return None, 'run rc=%d' % run.returncode
        return run.stdout, None


def verify(name, fn_va, gl_va, arena):
    if name not in fn_va:
        return 'SKIP no-addr'
    t = extract_twin(name)
    if not t:
        return 'SKIP no-twin'
    body, _ = t
    uni, err = run_unicorn(fn_va[name], arena)
    if uni is None:
        return 'SKIP ' + err
    out, err = run_native(name, body, gl_va)
    if out is None:
        return 'SKIP ' + err
    # native delta vs initial arena
    nat = {}
    for off in range(0, min(len(out), len(arena)), 4):
        if out[off:off + 4] != arena[off:off + 4]:
            nat[off] = bytes(out[off:off + 4])
    # normalize unicorn delta to 4-byte words that actually changed
    uni_n = {}
    for off, b in uni.items():
        word_off = off & ~3
        cur = bytearray(arena[word_off:word_off + 4])
        cur[off - word_off:off - word_off + len(b)] = b
        if bytes(cur) != arena[word_off:word_off + 4]:
            uni_n[word_off] = bytes(cur)
    if nat == uni_n:
        return 'VERIFIED (%d writes)' % len(nat)
    only_u = set(uni_n) - set(nat)
    only_n = set(nat) - set(uni_n)
    diff = {o for o in set(uni_n) & set(nat) if uni_n[o] != nat[o]}
    return 'MISMATCH uni_only=%s nat_only=%s val_diff=%s' % (
        sorted(hex(o) for o in only_u)[:4],
        sorted(hex(o) for o in only_n)[:4],
        sorted(hex(o) for o in diff)[:4])


def leaf_twins():
    out = []
    for f in (ROOT / 'src').rglob('*.c'):
        s = f.read_text(errors='ignore')
        for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
            j = s.find('#else', m.end())
            if j < 0:
                continue
            block = s[m.end():j]
            nm = re.search(r'\bvoid\s+(\w+)\s*\(\s*void\s*\)', block)
            if not nm:
                continue
            body = block[nm.end():]
            calls = [c for c in re.findall(r'\b([A-Za-z_]\w*)\s*\(', body)
                     if c not in KW and not c.startswith('MK4_')]
            if not calls:
                out.append(nm.group(1))
    return out


def main():
    fn_va, gl_va = load_maps()
    arena = ARENA.read_bytes()
    names = sys.argv[1:] or leaf_twins()
    counts = {}
    for n in names:
        r = verify(n, fn_va, gl_va, arena)
        tag = r.split()[0]
        counts[tag] = counts.get(tag, 0) + 1
        print('%-44s %s' % (n, r))
    print('\nsummary:', counts)


if __name__ == '__main__':
    main()
