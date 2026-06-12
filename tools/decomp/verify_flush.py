#!/usr/bin/env python3
"""Seeded co-exec verification for FlushDrawQueue (the SW dispatcher, mode 5).

FlushDrawQueue: counting-sorts the draw queue by x0, then (in SW mode, when
Renderer_GetMode()==5) decodes each 0x1c-byte primitive record into the
g_dispatchSave vertex/uv/shade globals and dispatches to the right rasterizer.
The SW path is FPU-free. This harness seeds:
  - *(int*)0x4f4b3c = 5            (Renderer_GetMode returns SW mode 5)
  - g_drawQueueSize = N            (0xf85b40)
  - N 0x1c-byte records @0xf71322  (g_dispatchSave1398; x0 in 0..0x3ff = sort key)
  - g_viewportX=FB / Y=pitch / W / H, g_dispatchSave1400=TEX  (rasterizer inputs)
  - a framebuffer + texture
(g_div3Table @0xf70ff8 is already in the arena.) Runs orig bytes vs the compiled
twin in Unicorn; the rasterizer callees run as ORIGINAL bytes (argless). Compares
the framebuffer + sort buckets + g_dispatchSave globals.

  build/venv/bin/python tools/decomp/verify_flush.py
"""
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc

BASE = vc.BASE
FB = 0x00100000
TEX = 0x00180000
W, H = 64, 48
RENDER_MODE_VA = 0x4f4b3c
# g_dispatchSave1398 (0xf71322) is the SORT-KEY field at record+0x12; the dispatch
# uses (key_ptr - 0x12) as the record start, so records begin at 0xf71310.
REC = 0xf71310          # record start (stride 0x1c); key (sort) at REC+0x12


def setdw(arena, gl, name_or_va, val):
    va = name_or_va if isinstance(name_or_va, int) else gl[name_or_va]
    struct.pack_into('<I', arena, va - BASE, val & 0xffffffff)


def setw(arena, va, val):
    struct.pack_into('<H', arena, va - BASE, val & 0xffff)


def setb(arena, va, val):
    arena[va - BASE] = val & 0xff


def rect_record(a, idx, x0, y0, x1, y1, u0, v0, u1, v1, color, typ):
    """Seed one 0x1c primitive record at REC + idx*0x1c (rect/ScanlineTexBlit)."""
    r = REC + idx * 0x1c
    setw(a, r + 0, x0)        # +0  x0 (= sort key)
    setw(a, r + 2, y0)        # +2  y0
    setw(a, r + 4, 0)         # +4
    setw(a, r + 6, 0)         # +6
    setw(a, r + 8, x1)        # +8  x1 (rect right, via L_fda3)
    setw(a, r + 0xa, y1)      # +a  y1
    setb(a, r + 0xc, u0)      # +c  u0
    setb(a, r + 0xd, v0)      # +d  v0
    setb(a, r + 0xe, u1)      # +e
    setb(a, r + 0xf, v1)      # +f
    setb(a, r + 0x10, u1)     # +10
    setb(a, r + 0x11, v1)     # +11
    setw(a, r + 0x12, x0)     # +12 SORT KEY (counting-sort bucket, 0..0x3ff)
    setw(a, r + 0x14, color)  # +14 color0 (>=0x7fff => not paletted)
    setw(a, r + 0x16, 0)      # +16
    setw(a, r + 0x18, 0)      # +18
    setw(a, r + 0x1a, typ)    # +1a type/flags


def main():
    name = 'FlushDrawQueue'
    fn_va, gl = vt.load_maps()
    base = bytearray(vc.ARENA.read_bytes())
    pitch = W * 2

    t = vc.extract_twin_any(name)
    if not t:
        print(name, 'SKIP no-twin (FlushDrawQueue not yet transcribed)')
        return 1
    body, nargs, _ = t
    blob, entry, lb, err = vc.build_twin_blob(name, body, gl, fn_va, fn_self_va=fn_va[name])
    if blob is None:
        print(name, 'SKIP build:', err)
        return 1

    # scenarios: a few rect primitives (type 0x20 -> ScanlineTexBlit) at various x0
    def seed(a):
        setdw(a, gl, RENDER_MODE_VA, 5)         # SW mode
        setdw(a, gl, 'g_drawQueueSize', 2)
        setdw(a, gl, 'g_viewportX', FB)
        setdw(a, gl, 'g_viewportY', pitch)
        setdw(a, gl, 'g_viewportW', W)
        setdw(a, gl, 'g_viewportH', H)
        setdw(a, gl, 'g_dispatchSave1400', TEX)
        rect_record(a, 0, 8, 6, 40, 30, 0, 0, 24, 16, 0xffff, 0x20)
        rect_record(a, 1, 20, 10, 50, 40, 4, 2, 30, 20, 0xffff, 0x20)

    tex = bytearray(0x120000)
    for i in range(0, 0x120000, 2):
        v = (((i >> 1) % 255) + 1)
        tex[i] = v & 0xff
        tex[i + 1] = (v >> 8) & 0xff
    fb_init = bytearray(pitch * H)
    blob_lo, blob_hi = lb & ~3, (lb + len(blob) + 3) & ~3

    def run(load_twin):
        arena = bytearray(base)
        seed(arena)
        uc, full = vc.uc_new(arena)
        uc.mem_write(TEX, bytes(tex))
        uc.mem_write(FB, bytes(fb_init))
        if load_twin:
            if lb + len(blob) > full:
                uc.mem_map(lb & ~0xFFF, ((len(blob) + (lb & 0xFFF) + 0xFFF) & ~0xFFF))
            uc.mem_write(lb, blob)
        return vc.run_at(uc, fn_va[name], full, nargs)

    o_buf, o_term, _ = run(False)
    t_buf, t_term, _ = run(True)
    diffs = [o for o in range(0, len(o_buf), 4)
             if not (blob_lo <= o < blob_hi) and o_buf[o:o+4] != t_buf[o:o+4]]
    fb_nz = sum(1 for o in range(FB, FB + pitch * H, 2) if o_buf[o:o+2] != b'\x00\x00')
    print('%s: orig_term=%s twin_term=%s fb_nonzero=%d diffs=%d'
          % (name, o_term, t_term, fb_nz, len(diffs)))
    inv = {v: k for k, v in gl.items()}
    for o in diffs[:16]:
        va = o + BASE
        where = ('FB+0x%x' % (o - FB)) if FB <= o < FB + 0x10000 else inv.get(va, '0x%x' % va)
        print('  diff @%s: orig=%s twin=%s' % (where, o_buf[o:o+4].hex(), t_buf[o:o+4].hex()))
    if o_term and t_term and not diffs and fb_nz:
        print('  VERIFIED'); return 0
    return 1


if __name__ == '__main__':
    sys.exit(main())
