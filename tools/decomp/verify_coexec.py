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

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x00400000
ARENA = ROOT / 'build' / 'arena.bin'
CC = 'i686-w64-mingw32-gcc'
OBJCOPY = 'i686-w64-mingw32-objcopy'
CODE = 0x70000000
STACK = 0x10000000


def build_twin_blob(name, body, gl_va):
    globs = sorted(set(re.findall(r'\bg_[A-Za-z]\w*', body)))
    if any(g not in gl_va for g in globs):
        return None, 'unmapped global'
    defs = ''.join('#define %s (*(unsigned int *)0x%xu)\n' % (g, gl_va[g])
                   for g in globs)
    # identity memory model (NO MK4_ARENA): MK4_VA(va)=(T*)va absolute.
    src = ('#define NON_MATCHING 1\n'
           '#include "portable/ghidra_types.h"\n#include "portable/mem_model.h"\n'
           + defs + body + '\n')
    with tempfile.TemporaryDirectory() as d:
        c = Path(d) / 't.c'
        c.write_text(src)
        o = Path(d) / 't.o'
        b = Path(d) / 't.bin'
        r = subprocess.run(
            [CC, '-m32', '-std=gnu89', '-c', '-O2', '-fno-stack-protector',
             '-fno-pic', '-ffreestanding', '-fno-asynchronous-unwind-tables',
             '-I' + str(ROOT / 'include'), '-w', str(c), '-o', str(o)],
            capture_output=True, text=True)
        if r.returncode:
            return None, 'compile: ' + (r.stderr.strip().splitlines() or [''])[-1]
        subprocess.run([OBJCOPY, '-O', 'binary', '--only-section=.text',
                        str(o), str(b)], capture_output=True)
        blob = b.read_bytes()
        if not blob:
            return None, 'empty .text'
        return blob, None


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


def verify(name, fn_va, gl_va, arena):
    if name not in fn_va:
        return 'SKIP no-addr'
    t = vt.extract_twin(name)
    if not t:
        return 'SKIP no-twin'
    body = t[0]
    blob, err = build_twin_blob(name, body, gl_va)
    if blob is None:
        return 'SKIP ' + err
    try:
        uc1, full = uc_new(arena)
        orig = run_at(uc1, fn_va[name], full)
        uc2, _ = uc_new(arena)
        uc2.mem_write(CODE, blob)
        twin = run_at(uc2, CODE, full)
    except Exception as e:
        return 'SKIP unicorn: %s' % e
    init = bytearray(full)
    init[BASE:BASE + len(arena)] = arena

    def delta(buf):
        return {o: bytes(buf[o:o+4]) for o in range(0, full, 4)
                if buf[o:o+4] != init[o:o+4]}
    do, dt = delta(orig), delta(twin)
    if do == dt:
        return 'VERIFIED (%d writes)' % len(do)
    ou = sorted(set(do) - set(dt))
    on = sorted(set(dt) - set(do))
    vd = sorted(o for o in set(do) & set(dt) if do[o] != dt[o])
    return 'MISMATCH orig_only=%s twin_only=%s vdiff=%s' % (
        [hex(o) for o in ou[:3]], [hex(o) for o in on[:3]], [hex(o) for o in vd[:3]])


def main():
    fn_va, gl_va = vt.load_maps()
    arena = ARENA.read_bytes()
    names = sys.argv[1:] or vt.leaf_twins()
    counts = {}
    for n in names:
        r = verify(n, fn_va, gl_va, arena)
        counts[r.split()[0]] = counts.get(r.split()[0], 0) + 1
        print('%-44s %s' % (n, r))
    print('\nsummary:', counts)


if __name__ == '__main__':
    main()
