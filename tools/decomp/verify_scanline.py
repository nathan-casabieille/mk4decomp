#!/usr/bin/env python3
"""Seeded co-exec verification for ScanlineTexBlit and sister scanline blitters.

verify_coexec runs against the static arena, where the framebuffer base
(g_viewportX) is 0 - so the blitter early-returns and "verifies" 0 writes, a
false positive (see feedback_seeded_coexec_node_walk_template). This harness
SEEDS a small framebuffer + texture + the renderer-state input globals, runs
the original function bytes AND the compiled twin in Unicorn, and compares the
resulting framebuffer + scratch globals. Match => the twin reproduces the blit
byte-for-byte (behavior-confirmed, NOT byte-match).

  build/venv/bin/python tools/decomp/verify_scanline.py [NAME]

Default NAME = ScanlineTexBlit.
"""
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc

BASE = vc.BASE                 # 0x400000
FB = 0x00100000                # framebuffer base (below BASE, inside [0, full))
TEX = 0x00180000               # texture base
PAL = 0x00300000               # palette base (paletted/CLUT variants)


def seed(arena, gl_va, pairs):
    missing = [n for n in pairs if n not in gl_va]
    if missing:
        print('WARN: globals absent from maps (not seeded):', missing)
    for name, val in pairs.items():
        if name in gl_va:
            struct.pack_into('<I', arena, gl_va[name] - BASE, val & 0xffffffff)


# Seed scenarios - each exercises a different control-flow path. W,H = 64,48.
# (x0,y0,x1,y1 = dest quad; gradients via U1/Q vs u0/P; texpage/sub vary the
# texture addressing). The clip cases (negative x0/y0, x1/y1 past the viewport)
# are essential: an unexercised branch proves nothing.
W, H = 64, 48
SCENARIOS = {
    # u0 = starting V (texture row); it advances by gradY per row, so the
    # texture page byte ((1374>>16)&0xff) is exercised across rows. (Do NOT seed
    # g_dispatchSave1375 - it aliases &1374+2 and is overwritten by the function's
    # own store of 1374<<16.) palsel exercises the CLUT base selector (1367).
    'no-clip':        dict(x0=8,  y0=6,  x1=40, y1=30, u0=0, U1=24, P=0,  Q=16),
    'left-clip':      dict(x0=-12, y0=6, x1=40, y1=30, u0=0, U1=24, P=2,  Q=16),
    'top-clip':       dict(x0=8,  y0=-9, x1=40, y1=30, u0=3, U1=24, P=0,  Q=16),
    'left+top-clip':  dict(x0=-7, y0=-5, x1=40, y1=30, u0=4, U1=24, P=5,  Q=16),
    'right-clip':     dict(x0=8,  y0=6,  x1=80, y1=30, u0=0, U1=40, P=0,  Q=16),
    'bottom-clip':    dict(x0=8,  y0=6,  x1=40, y1=60, u0=0, U1=24, P=0,  Q=40),
    'all-clip':       dict(x0=-4, y0=-3, x1=80, y1=60, u0=1, U1=48, P=2,  Q=48),
    'subtexel+page':  dict(x0=8,  y0=6,  x1=40, y1=30, u0=5, U1=24, P=0,  Q=40, sub=7),
    'palsel':         dict(x0=8,  y0=6,  x1=40, y1=30, u0=0, U1=24, P=0,  Q=16, palsel=0x10),
}


def build_arena(base_arena, gl_va, sc):
    arena = bytearray(base_arena)
    seed(arena, gl_va, {
        'g_viewportX': FB, 'g_viewportY': W * 2, 'g_viewportW': W, 'g_viewportH': H,
        'g_dispatchSave1378': sc['x0'], 'g_dispatchSave1381': sc['y0'],
        'g_dispatchSave1380': sc['x1'], 'g_dispatchSave1383': sc['y1'],
        'g_dispatchSave1374': sc['u0'], 'g_dispatchSave1373': sc['U1'],
        'g_dispatchSave1371': sc['P'],  'g_dispatchSave1377': sc['Q'],
        'g_dispatchSave1400': TEX, 'g_dispatchSave1403': sc.get('sub', 0),
        'g_dispatchSave1340': PAL, 'g_dispatchSave1367': sc.get('palsel', 0),
    })
    return arena


def main():
    name = sys.argv[1] if len(sys.argv) > 1 else 'ScanlineTexBlit'
    fn_va, gl_va = vt.load_maps()
    base_arena = bytearray(vc.ARENA.read_bytes())
    pitch = W * 2

    t = vc.extract_twin_any(name)
    if not t:
        print(name, 'SKIP no-twin')
        return 1
    body, nargs, returns_value = t
    blob, entry, load_base, err = vc.build_twin_blob(
        name, body, gl_va, fn_va, fn_self_va=fn_va[name])
    if blob is None:
        print(name, 'SKIP build:', err)
        return 1

    # Large texture of small non-zero values (1..255): used directly as 16bpp
    # color by ScanlineTexBlit, and as a CLUT index by the paletted variants
    # (texel/index 0 = transparent). The big span covers page/sub-texel
    # addressing without leaving mapped memory.
    TEXBYTES = 0x120000
    tex = bytearray(TEXBYTES)
    for i in range(0, TEXBYTES, 2):
        v = (((i >> 1) % 255) + 1)             # 1..255, never 0
        tex[i] = v & 0xff
        tex[i + 1] = (v >> 8) & 0xff
    # Palette: 0x40000 of distinct non-zero 16bpp colors (CLUT lookup target).
    PALBYTES = 0x40000
    pal = bytearray(PALBYTES)
    for i in range(0, PALBYTES, 2):
        v = (((i >> 1) * 7 + 0x1234) & 0x7fff) | 0x8000   # always != 0
        pal[i] = v & 0xff
        pal[i + 1] = (v >> 8) & 0xff
    blob_lo = load_base & ~3
    blob_hi = (load_base + len(blob) + 3) & ~3

    def run(arena, load_twin):
        uc, full = vc.uc_new(arena)
        uc.mem_write(TEX, bytes(tex))
        uc.mem_write(PAL, bytes(pal))
        uc.mem_write(FB, b'\x00' * (pitch * H))
        if load_twin:
            if load_base + len(blob) > full:
                uc.mem_map(load_base & ~0xFFF,
                           ((len(blob) + (load_base & 0xFFF) + 0xFFF) & ~0xFFF))
            uc.mem_write(load_base, blob)
        return vc.run_at(uc, fn_va[name], full, nargs)

    rc = 0
    print(name)
    for label, sc in SCENARIOS.items():
        arena = build_arena(base_arena, gl_va, sc)
        o_buf, o_term, _ = run(arena, False)
        t_buf, t_term, _ = run(arena, True)
        diffs = [off for off in range(0, len(o_buf), 4)
                 if not (blob_lo <= off < blob_hi)
                 and o_buf[off:off + 4] != t_buf[off:off + 4]]
        fb_nz = sum(1 for off in range(FB, FB + pitch * H, 2)
                    if o_buf[off:off + 2] != b'\x00\x00')
        ok = o_term and t_term and not diffs and fb_nz > 0
        print('  %-14s term=%d/%d fb_px=%-4d diffs=%-3d %s'
              % (label, o_term, t_term, fb_nz, len(diffs),
                 'OK' if ok else 'FAIL'))
        if not ok:
            rc = 1
            for off in diffs[:8]:
                if FB <= off < FB + 0x10000:
                    where = 'FB+0x%x' % (off - FB)
                elif TEX <= off < TEX + 0x10000:
                    where = 'TEX+0x%x' % (off - TEX)
                else:
                    where = '0x%x' % (off + BASE)
                print('      diff @%s: orig=%s twin=%s'
                      % (where, o_buf[off:off + 4].hex(), t_buf[off:off + 4].hex()))
    print('  =>', 'VERIFIED (all scenarios)' if rc == 0 else 'MISMATCH')
    return rc


if __name__ == '__main__':
    sys.exit(main())
