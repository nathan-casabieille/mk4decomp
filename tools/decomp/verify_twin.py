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
    # Map [0, FULL) so near-null packed-ptr derefs (zero indices in the
    # static initial state) read/write zero instead of faulting. Image
    # bytes live at BASE..; [0,BASE) and gaps are zero. Stack is separate.
    full = (BASE + len(arena) + 0xFFF) & ~0xFFF
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(0, full)
    uc.mem_write(BASE, bytes(arena))
    stack = 0x20000000
    uc.mem_map(stack, 0x20000)
    SENT = 0x00bad0de
    esp = stack + 0x10000
    uc.reg_write(UC_X86_REG_ESP, esp)
    uc.mem_write(esp, SENT.to_bytes(4, 'little'))   # return address
    # Lazily map data pages a wild (garbage-state) packed-ptr wanders into,
    # so the run completes; this is an equivalence check on a shared state,
    # not a realistic-input test. Code fetches are NOT lazily mapped.
    from unicorn import UC_HOOK_MEM_READ_UNMAPPED, UC_HOOK_MEM_WRITE_UNMAPPED

    def on_unmapped(uc, access, addr, sz, val, ud):
        try:
            uc.mem_map(addr & ~0xFFF, 0x1000)
        except Exception:
            pass
        return True
    uc.hook_add(UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED, on_unmapped)
    try:
        uc.emu_start(func_va, SENT, count=400000)
    except Exception as e:
        return None, 'unicorn: %s' % e
    return bytes(uc.mem_read(0, full)), None


def run_native(name, body, gl_va, full):
    globs = sorted(set(re.findall(r'\bg_[A-Za-z]\w*', body)))
    if any(g not in gl_va for g in globs):
        return None, 'unmapped global: %s' % [g for g in globs if g not in gl_va]
    defs = ''.join(
        '#define %s (*(unsigned int *)(g_mk4Arena + 0x%x))\n' % (g, gl_va[g] - BASE)
        for g in globs)
    # Allocate [0, FULL); g_mk4Arena = buf + BASE so MK4_PTR(va)=buf+va for
    # any va in [0, FULL) - matches the Unicorn map (near-null safe).
    # Back the arena with a sparse 4 GB anon mmap so a wild packed-ptr (from
    # garbage initial state) reads/writes zero instead of segfaulting -
    # matching the Unicorn lazy-map. Only touched pages commit.
    harness = (
        '#define NON_MATCHING 1\n#define MK4_ARENA 1\n'
        '#include "portable/ghidra_types.h"\n#include "portable/mem_model.h"\n'
        '#include "portable/arena.h"\n#include <stdio.h>\n#include <sys/mman.h>\n'
        + defs + body + '\n'
        'int main(void){\n'
        '  unsigned char *buf = mmap(0, 0x100000000ULL, PROT_READ|PROT_WRITE,'
        ' MAP_ANON|MAP_PRIVATE, -1, 0);\n'
        '  if(buf==MAP_FAILED) return 2;\n'
        '  FILE *f = fopen("%s","rb"); if(!f) return 2;\n' % ARENA +
        '  fread(buf + 0x%xu, 1, 0x%xu, f); fclose(f);\n' % (BASE, full - BASE) +
        '  g_mk4Arena = buf + 0x%xu; g_mk4ArenaSize = 0x%xu;\n' % (BASE, full) +
        '  %s();\n' % name +
        '  fwrite(buf, 1, 0x%xu, stdout);\n  return 0;\n}\n' % full)
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
    full = (BASE + len(arena) + 0xFFF) & ~0xFFF
    init = bytearray(full)
    init[BASE:BASE + len(arena)] = arena            # [0,BASE) stays zero
    uni, err = run_unicorn(fn_va[name], arena)
    if uni is None:
        return 'SKIP ' + err
    out, err = run_native(name, body, gl_va, full)
    if out is None:
        return 'SKIP ' + err

    def delta(buf):
        d = {}
        n = min(len(buf), full)
        for off in range(0, n, 4):
            if buf[off:off + 4] != init[off:off + 4]:
                d[off] = bytes(buf[off:off + 4])
        return d
    u, nat = delta(uni), delta(out)
    if u == nat:
        return 'VERIFIED (%d writes)' % len(nat)
    only_u = sorted(set(u) - set(nat))
    only_n = sorted(set(nat) - set(u))
    vdiff = sorted(o for o in set(u) & set(nat) if u[o] != nat[o])
    return 'MISMATCH uni_only=%s nat_only=%s val_diff=%s' % (
        [hex(o) for o in only_u[:4]], [hex(o) for o in only_n[:4]],
        [hex(o) for o in vdiff[:4]])


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
