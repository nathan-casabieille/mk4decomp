#!/usr/bin/env python3
"""Disassemble a function's ORIGINAL bytes straight out of build/arena.bin.

The arena blob is the original mapped image, so this is ground truth for
"what does the original actually do" - the reference when a Ghidra twin is
suspect (see the AlphaPal saga: re-transcribing blind costs far more than
reading the bytes).

  build/venv/bin/python tools/decomp/disasm_fn.py NAME [maxinsn]
  build/venv/bin/python tools/decomp/disasm_fn.py 0x4b2d20 [maxinsn]
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc
from capstone import Cs, CS_ARCH_X86, CS_MODE_32


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    what = sys.argv[1]
    limit = int(sys.argv[2]) if len(sys.argv) > 2 else 400
    fn_va, gl_va = vt.load_maps()
    va2name = {v: k for k, v in fn_va.items()}
    gl2name = {v: k for k, v in gl_va.items()}
    va = int(what, 0) if what.startswith('0x') else fn_va.get(what)
    if va is None:
        print('unknown function: %s' % what)
        return 2
    img = vc.ARENA.read_bytes()
    off = va - vc.BASE
    # Extent = up to the next function symbol. Stopping at the first `ret` is
    # wrong for anything with an early-return guard (DrawMeshBlock's first ret
    # is 25 instructions in, out of ~1500).
    nxt = min((v for v in fn_va.values() if v > va), default=va + 0x4000)
    code = img[off:off + min(nxt - va, 0x8000)]
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = False
    n = 0
    for ins in md.disasm(code, va):
        ann = ''
        # annotate call/jmp targets and absolute operands with symbol names
        for tok in ins.op_str.replace('[', ' ').replace(']', ' ').split():
            t = tok.strip(',+*')
            if t.startswith('0x'):
                try:
                    a = int(t, 16)
                except ValueError:
                    continue
                if a in va2name:
                    ann += '  ; -> %s' % va2name[a]
                elif a in gl2name:
                    ann += '  ; %s' % gl2name[a]
        print('%08x  %-22s %-34s%s' % (ins.address, ins.bytes.hex(), '%s %s' % (ins.mnemonic, ins.op_str), ann))
        n += 1
        if n >= limit:
            break
    return 0


if __name__ == '__main__':
    sys.exit(main())
