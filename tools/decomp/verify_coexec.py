#!/usr/bin/env python3
"""Co-execution verification: run the twin AS 32-bit code inside Unicorn.

The native-64-bit harness (verify_twin.py) can only run "seam-clean" twins;
Ghidra also emits raw 32-bit pointer derefs that need a 32-bit address
space. Wine reserves 0x400000 so a fixed-VA Wine runtime is out. Unicorn
lets us control the whole address space, so we run BOTH sides in it:

  - original: execute the function's own bytes at its VA in the arena
    (image mapped at 0x400000).
  - twin: compile the twin to 32-bit code with the IDENTITY memory model
    (globals #defined to absolute VAs, MK4_* = identity), so every access
    is an absolute VA into the same arena; load its .text into Unicorn and
    run it.

Diff the resulting arena bytes. Match => behavior-confirmed. Leaf
void(void) twins only for now (no arg setup, no callee linking).

Run with the unicorn venv:
  build/venv/bin/python tools/decomp/verify_coexec.py [NAME ...]
"""
import re
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt           # reuse load_maps / extract_twin / leaf_twins
import synthesize as syn           # reuse COFF parser
import struct

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x00400000
ARENA = ROOT / 'build' / 'arena.bin'
CC = 'i686-w64-mingw32-gcc'
OBJCOPY = 'i686-w64-mingw32-objcopy'
CODE = 0x70000000
STACK = 0x10000000


def _strip(n):
    return n[1:] if n.startswith('_') else n


def build_twin_blob(name, body, gl_va, name_to_va, fn_self_va=None):
    """Compile twin -> .text, relocated so external calls target the
    ORIGINAL function VAs (callees co-execute as original bytes in the
    arena) and intra-twin labels resolve within the loaded blob. When
    fn_self_va is given, the blob is based so the function lands at its own
    original VA (self-references match the original's stored pointers).
    Returns (blob, entry_offset, load_base, err)."""
    globs = sorted(set(re.findall(r'\bg_\w+', body)))
    if any(g not in gl_va for g in globs):
        return None, None, None, 'unmapped global'

    # Usage-aware #define so the lvalue at the global's VA has the right type
    # (mirrors the injector gate): a global called through `(*g)()` / `g()` is
    # a function pointer; one deref'd `*g` or indexed `g[i]` or pointer-assigned
    # holds a pointer; else a plain scalar. Same VA either way - only the type
    # of the lvalue differs so the C compiles.
    def gdef(g, va):
        if re.search(r'\(\s*\*\s*%s\s*\)\s*\(' % g, body) or re.search(r'\b%s\s*\(' % g, body):
            return '#define %s (*(unsigned int (**)())0x%xu)\n' % (g, va)
        deref = False
        for m in re.finditer(r'\*\s*%s\b' % g, body):
            j = m.start() - 1
            while j >= 0 and body[j] in ' \t':
                j -= 1
            if j < 0 or (body[j] not in '_)]' and not body[j].isalnum()):
                deref = True
        if deref or re.search(r'\b%s\s*\[' % g, body):
            return '#define %s (*(unsigned int **)0x%xu)\n' % (g, va)
        return '#define %s (*(unsigned int *)0x%xu)\n' % (g, va)
    defs = ''.join(gdef(g, gl_va[g]) for g in globs)
    src = ('#define NON_MATCHING 1\n'
           '#include "portable/ghidra_types.h"\n#include "portable/mem_model.h"\n'
           + defs + body + '\n')
    with tempfile.TemporaryDirectory() as d:
        c = Path(d) / 't.c'
        c.write_text(src)
        o = Path(d) / 't.o'
        r = subprocess.run(
            [CC, '-m32', '-std=gnu89', '-c', '-O2', '-fno-stack-protector',
             '-fno-pic', '-ffreestanding', '-fno-asynchronous-unwind-tables',
             '-I' + str(ROOT / 'include'), '-w', str(c), '-o', str(o)],
            capture_output=True, text=True)
        if r.returncode:
            return None, None, None, 'compile: ' + (r.stderr.strip().splitlines() or [''])[-1]
        syms, sections = syn.parse_obj_full(o.read_bytes())
    text = next((s for s in sections if s['name'].startswith('.text')), None)
    if text is None:
        return None, None, None, 'no .text'
    buf = bytearray(text['content'])
    entry = 0
    for s in syms:
        if s and _strip(s['name']) == name and s['sec'] > 0:
            entry = s['value']
    # Load the blob so the function's entry lands at its ORIGINAL VA. Then a
    # self-reference `&name` (e.g. a continuation storing its own function
    # pointer into a node field) relocates to the real VA and matches what the
    # original writes - otherwise the twin stores its blob address and we get a
    # spurious MISMATCH at the stored-pointer slot.
    load_base = (fn_self_va - entry) if fn_self_va is not None else CODE
    for r in text['relocs']:
        sym = syms[r['sym_idx']] if 0 <= r['sym_idx'] < len(syms) else None
        if sym is None:
            return None, None, None, 'bad sym'
        off, rt = r['va'], r['type']
        if sym['sec'] > 0:                         # defined in this obj (label)
            target = load_base + sym['value']
        else:                                      # external -> original VA
            tv = name_to_va.get(_strip(sym['name']))
            if tv is None:
                return None, None, None, 'unresolved call: %s' % _strip(sym['name'])
            target = tv
        if rt == 6 and off >= 1 and buf[off-1] in (0xe8, 0xe9):
            rt = 20
        existing = struct.unpack_from('<I', buf, off)[0]
        if rt == 6:
            struct.pack_into('<I', buf, off, (target + existing) & 0xffffffff)
        elif rt == 20:
            struct.pack_into('<I', buf, off,
                             (target - (load_base + off + 4) + existing) & 0xffffffff)
    return bytes(buf), entry, load_base, None


def uc_new(arena):
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
    from unicorn import UC_HOOK_MEM_READ_UNMAPPED, UC_HOOK_MEM_WRITE_UNMAPPED
    full = (BASE + len(arena) + 0xFFF) & ~0xFFF
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(0, full)
    uc.mem_write(BASE, bytes(arena))
    uc.mem_map(STACK, 0x40000)
    uc.mem_map(CODE, 0x100000)

    def on_unmapped(uc, access, addr, sz, val, ud):
        try:
            uc.mem_map(addr & ~0xFFF, 0x1000)
        except Exception:
            pass
        return True
    uc.hook_add(UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED, on_unmapped)
    return uc, full


def run_at(uc, eip, full):
    from unicorn.x86_const import UC_X86_REG_ESP
    SENT = 0x00bad0de
    esp = STACK + 0x20000
    uc.reg_write(UC_X86_REG_ESP, esp)
    uc.mem_write(esp, SENT.to_bytes(4, 'little'))
    uc.emu_start(eip, SENT, count=2000000)
    return bytes(uc.mem_read(0, full))


def verify(name, fn_va, gl_va, name_to_va, arena):
    if name not in fn_va:
        return 'SKIP no-addr'
    t = vt.extract_twin(name)
    if not t:
        return 'SKIP no-twin'
    body = t[0]
    blob, entry, load_base, err = build_twin_blob(
        name, body, gl_va, name_to_va, fn_self_va=fn_va[name])
    if blob is None:
        return 'SKIP ' + err
    try:
        uc1, full = uc_new(arena)
        orig = run_at(uc1, fn_va[name], full)
        uc2, _ = uc_new(arena)
        if load_base + len(blob) > full:           # blob outside arena map
            uc2.mem_map(load_base & ~0xFFF,
                        ((len(blob) + (load_base & 0xFFF) + 0xFFF) & ~0xFFF))
        uc2.mem_write(load_base, blob)             # twin lands at its own VA
        twin = run_at(uc2, fn_va[name], full)
    except Exception as e:
        return 'SKIP unicorn: %s' % e
    init = bytearray(full)
    init[BASE:BASE + len(arena)] = arena

    # Exclude the .text region where the twin blob was loaded: its bytes
    # differ from the original function's bytes there, but that is code, not a
    # data write. (delta is a DATA-write diff; the original never rewrites its
    # own code, so masking this range is symmetric and correct.)
    blob_lo = load_base & ~3
    blob_hi = (load_base + len(blob) + 3) & ~3

    def delta(buf):
        return {o: bytes(buf[o:o+4]) for o in range(0, full, 4)
                if not (blob_lo <= o < blob_hi) and buf[o:o+4] != init[o:o+4]}
    do, dt = delta(orig), delta(twin)
    if do == dt:
        return 'VERIFIED (%d writes)' % len(do)
    ou = sorted(set(do) - set(dt))
    on = sorted(set(dt) - set(do))
    vd = sorted(o for o in set(do) & set(dt) if do[o] != dt[o])
    return 'MISMATCH orig_only=%s twin_only=%s vdiff=%s' % (
        [hex(o) for o in ou[:3]], [hex(o) for o in on[:3]], [hex(o) for o in vd[:3]])


def all_twins():
    names = []
    for f in (ROOT / 'src').rglob('*.c'):
        s = f.read_text(errors='ignore')
        for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
            j = s.find('#else', m.end())
            if j < 0:
                continue
            nm = re.search(r'\b(\w+)\s*\(', s[m.end():j])
            if nm:
                names.append(nm.group(1))
    return names


def main():
    fn_va, gl_va = vt.load_maps()
    name_to_va = fn_va                 # load_maps' fn_va is already name -> VA
    arena = ARENA.read_bytes()
    names = sys.argv[1:] or all_twins()
    counts = {}
    for n in names:
        r = verify(n, fn_va, gl_va, name_to_va, arena)
        counts[r.split()[0]] = counts.get(r.split()[0], 0) + 1
        print('%-44s %s' % (n, r))
    print('\nsummary:', counts)


if __name__ == '__main__':
    main()
