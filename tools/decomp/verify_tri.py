#!/usr/bin/env python3
"""Seeded co-exec verification for the triangle rasterizers (TexturedTriRasterize
and TexturedTriRasterizeShaded). Sibling of verify_scanline.py.

These take 3 vertices stored as consecutive-dword ARRAYS in the dispatch-save
scratch region: x = g_dispatchSave1378/1379/1380, y = 1381/1382/1383,
u = 1371/1372/1373, v = 1374/1376/1377 (plus shaded colour arrays for the Shaded
variant). The harness seeds a few non-degenerate triangles (positive edge-area,
various clip cases, both g_texturedTriVar modes), a framebuffer + texture, runs
the original bytes vs the compiled twin in Unicorn, and diffs FB + globals.

  build/venv/bin/python tools/decomp/verify_tri.py [NAME]

Default NAME = TexturedTriRasterize.
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
LUT = 0x00300000          # shaded: 2D lighting-table base (g_dispatchSave1340)
LUT_LO = 0x002a0000       # seed the whole [LUT_LO, BASE) region as the table
W, H = 64, 48

# Each triangle: 3 verts (x,y,u,v), positive edge area required (else rejected).
# area = (x1-x0)*(y2-y0) - (x2-x0)*(y1-y0) > 0.
TRIS = {
    'inside':     dict(x=(10, 50, 20), y=(8, 12, 40),  u=(0, 60, 10), v=(0, 5, 50)),
    'tall':       dict(x=(22, 36, 26), y=(5, 11, 43),  u=(2, 40, 8),  v=(1, 4, 48)),
    'wide':       dict(x=(6, 58, 30),  y=(10, 14, 38), u=(0, 80, 30), v=(0, 2, 30)),
    'clip-right': dict(x=(40, 80, 50), y=(8, 12, 40),  u=(0, 60, 10), v=(0, 5, 50)),
    'clip-left':  dict(x=(-10, 40, 5), y=(8, 12, 40),  u=(0, 60, 10), v=(0, 5, 50)),
    'clip-top':   dict(x=(10, 50, 20), y=(-6, 2, 40),  u=(0, 60, 10), v=(0, 5, 50)),
    'clip-bot':   dict(x=(10, 50, 20), y=(8, 12, 60),  u=(0, 60, 10), v=(0, 5, 50)),
    'mode0':      dict(x=(10, 50, 20), y=(8, 12, 40),  u=(0, 60, 10), v=(0, 5, 50), mode=0),
    'mode0-clip': dict(x=(-10, 80, 30), y=(-6, 12, 60), u=(0, 90, 40), v=(0, 6, 60), mode=0),
}


def seed(arena, gl_va, pairs):
    miss = [n for n in pairs if n not in gl_va]
    if miss:
        print('WARN absent globals:', miss)
    for n, v in pairs.items():
        if n in gl_va:
            struct.pack_into('<I', arena, gl_va[n] - BASE, v & 0xffffffff)


def build_arena(base_arena, gl_va, tri, shaded):
    a = bytearray(base_arena)
    x, y, u, v = tri['x'], tri['y'], tri['u'], tri['v']
    seed(a, gl_va, {
        'g_viewportX': FB, 'g_viewportY': W * 2, 'g_viewportW': W, 'g_viewportH': H,
        'g_dispatchSave1378': x[0], 'g_dispatchSave1379': x[1], 'g_dispatchSave1380': x[2],
        'g_dispatchSave1381': y[0], 'g_dispatchSave1382': y[1], 'g_dispatchSave1383': y[2],
        'g_dispatchSave1371': u[0], 'g_dispatchSave1372': u[1], 'g_dispatchSave1373': u[2],
        'g_dispatchSave1374': v[0], 'g_dispatchSave1376': v[1], 'g_dispatchSave1377': v[2],
        'g_dispatchSave1400': TEX, 'g_dispatchSave1403': tri.get('sub', 0),
        'g_texturedTriVar': tri.get('mode', 1),
    })
    if shaded:
        s = tri.get('s', (8, 40, 72))   # 3 vertex shade bytes (moderate -> LUT in range)
        # shade vertices = 3 consecutive bytes at &g_dispatchSave1367; pack into the dword.
        seed(a, gl_va, {
            'g_dispatchSave1367': (s[0] & 0xff) | ((s[1] & 0xff) << 8) | ((s[2] & 0xff) << 16),
            'g_dispatchSave1340': LUT,
        })
    return a


def main():
    name = sys.argv[1] if len(sys.argv) > 1 else 'TexturedTriRasterize'
    fn_va, gl_va = vt.load_maps()
    base = bytearray(vc.ARENA.read_bytes())
    pitch = W * 2

    shaded = 'Shaded' in name
    t = vc.extract_twin_any(name)
    if not t:
        print(name, 'SKIP no-twin')
        return 1
    body, nargs, _ = t
    blob, entry, load_base, err = vc.build_twin_blob(
        name, body, gl_va, fn_va, fn_self_va=fn_va[name])
    if blob is None:
        print(name, 'SKIP build:', err)
        return 1

    # texture (256 wide, 16bpp) + a bright framebuffer background.
    TEXBYTES = 0x120000
    tex = bytearray(TEXBYTES)
    for i in range(0, TEXBYTES, 2):
        val = (((i >> 1) % 255) + 1)
        tex[i] = val & 0xff
        tex[i + 1] = (val >> 8) & 0xff
    fb_init = bytearray(pitch * H)
    for i in range(0, pitch * H, 2):
        val = (((i >> 1) * 5 + 0x4000) & 0x7bde) | 0x4210
        fb_init[i] = val & 0xff
        fb_init[i + 1] = (val >> 8) & 0xff
    lut = None
    if shaded:    # 2D lighting LUT filling [LUT_LO, BASE), distinct non-zero colours
        lut = bytearray(BASE - LUT_LO)
        for i in range(0, len(lut), 2):
            val = (((i >> 1) * 3 + 0x111) & 0x7fff) | 0x8000
            lut[i] = val & 0xff
            lut[i + 1] = (val >> 8) & 0xff
    blob_lo, blob_hi = load_base & ~3, (load_base + len(blob) + 3) & ~3

    def run(arena, load_twin):
        uc, full = vc.uc_new(arena)
        uc.mem_write(TEX, bytes(tex))
        uc.mem_write(FB, bytes(fb_init))
        if shaded:
            uc.mem_write(LUT_LO, bytes(lut))
        if load_twin:
            if load_base + len(blob) > full:
                uc.mem_map(load_base & ~0xFFF,
                           ((len(blob) + (load_base & 0xFFF) + 0xFFF) & ~0xFFF))
            uc.mem_write(load_base, blob)
        return vc.run_at(uc, fn_va[name], full, nargs)

    rc = 0
    print(name)
    for label, tri in TRIS.items():
        arena = build_arena(base, gl_va, tri, shaded)
        o_buf, o_term, _ = run(arena, False)
        t_buf, t_term, _ = run(arena, True)
        diffs = [o for o in range(0, len(o_buf), 4)
                 if not (blob_lo <= o < blob_hi) and o_buf[o:o+4] != t_buf[o:o+4]]
        fb_mod = sum(1 for o in range(FB, FB + pitch * H, 2)
                     if o_buf[o:o+2] != fb_init[o-FB:o-FB+2])
        ok = o_term and t_term and not diffs and fb_mod > 0
        print('  %-12s term=%d/%d fb_mod=%-4d diffs=%-3d %s'
              % (label, o_term, t_term, fb_mod, len(diffs), 'OK' if ok else 'FAIL'))
        if not ok:
            rc = 1
            for o in diffs[:8]:
                where = ('FB+0x%x' % (o - FB)) if FB <= o < FB + 0x10000 else (
                    'TEX+0x%x' % (o - TEX)) if TEX <= o < TEX + 0x20000 else '0x%x' % (o + BASE)
                print('      diff @%s: orig=%s twin=%s'
                      % (where, o_buf[o:o+4].hex(), t_buf[o:o+4].hex()))
    print('  =>', 'VERIFIED (all triangles)' if rc == 0 else 'MISMATCH')
    return rc


if __name__ == '__main__':
    sys.exit(main())
