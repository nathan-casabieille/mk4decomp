#!/usr/bin/env python3
"""Generate a self-contained wasm32 C bundle of the verified SW render pipeline.

The portable-C render twins (FlushDrawQueue + the rasterizers) are faithful
32-bit code: they keep framebuffer/texture/record pointers in `unsigned int`
globals. That is exactly right for a wasm32 target, where `malloc` returns a
32-bit address and `long`/pointers are 32-bit, so the uint-pointer model is
lossless (it is NOT on macOS arm64 - see the pointer-width-fork memory note).

This collects the twin function BODIES (not the files - so the inline `extern`
decls and the matching `#else` naked bodies are skipped), emits each referenced
global as an lvalue aliased into a single linear arena via MK4_VA (so the vertex
arrays the triangle twins index as (&g_dispatchSave1378)[i] are contiguous by
construction), and writes one .c with a driver `main` that loads the original
data image, seeds a draw queue, runs FlushDrawQueue, and dumps the framebuffer.

  build/venv/bin/python tools/decomp/gen_wasm_render.py > build/wasm/mk4_render.c
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc

BASE = vc.BASE                    # 0x400000 = MK4_ORIG_IMAGE_BASE
# Scratch regions placed ABOVE the data image so MK4_VA offsets stay positive.
FB_VA = 0x01000000
TEX_VA = 0x01100000
# CLUT / lighting-LUT base (g_dispatchSave1340). The paletted blit indexes it as
# ((shade & 0xf0) << 13) + idx*2, so it must span 0xf0<<13 + 0x20000 = 2 MB.
PAL_VA = 0x01200000
PAL_SZ = 0x00200000
GEO_VA = 0x01400000   # a whole .geo asset, loaded verbatim
W, H = 320, 240                   # hand-seeded rect scene (arbitrary size)
# The ENGINE's screen is 640x480: the projection helpers add the screen centre
# as 0x140 / 0xf0, and Helper_DrawCursor's envelope test rejects x > 0x280 and
# y > 0x1e0. A mesh frame must therefore be rendered at 640x480 or the whole
# projected scene lands off the bottom-right of the framebuffer.
EMIT_W, EMIT_H = 640, 480
RENDER_MODE_VA = 0x4f4b3c
REC = 0xf71310                    # draw-queue record start (sort key at +0x12)


# Globals the ORIGINAL accesses 16 bits at a time (movsx/mov word). gdef
# defaults everything to 32-bit, which is wrong for a packed s16: its high word
# is the NEXT entry, so a dword read is polluted and a dword write clobbers the
# neighbour. Same opt-in set the co-exec harness uses (verify_project.WIDTH16),
# kept explicit rather than inferred - flipping a global to 16-bit changes
# results whenever bit 15 is set, so it must never be guessed.
WIDTH16 = {
    'g_mat3x3_007af990', 'g_mat3x3_007af992', 'g_mat3x3_007af994',
    'g_mat3x3_007af996', 'g_mat3x3_007af998', 'g_mat3x3_007af99a',
    'g_mat3x3_007af99c', 'g_mat3x3_007af99e', 'g_mat3x3_007af9a0',
    'g_vtxMat', 'g_wtMatExtraWord',
    'g_triStripX0', 'g_triStripX1', 'g_triStripX2',
    'g_dispatchSave1626', 'g_vtxIn1_y', 'g_vtxIn1_z',
    'g_vtxIn2_x', 'g_vtxIn2_y', 'g_vtxIn2_z',
}

# A definition of `name` that is NOT inside a #ifdef NON_MATCHING block, i.e. a
# function already converted to unconditional byte-matching pure C. These read
# as "no twin" to extract_twin_any (there is no NON_MATCHING block to find) but
# are perfectly usable portable C - AdvanceTriStripRing, MinOfThree and
# MaxOfThree are all in this category, and without them the emitter chain looks
# unbuildable when it is in fact complete.
def extract_pure_c(name):
    sig = re.compile(r'^[A-Za-z_][\w \*]*?\b%s\s*\(([^;{)]*)\)\s*\{' % re.escape(name),
                     re.M)
    for f in sorted((vc.ROOT / 'src').rglob('*.c')):
        s = f.read_text(errors='ignore')
        m = sig.search(s)
        if not m:
            continue
        # reject if this definition sits inside a #ifdef ... #endif region
        pre = s[:m.start()]
        if pre.count('#ifdef') + pre.count('#ifndef') + pre.count('#if ') > \
           pre.count('#endif'):
            continue
        i = s.index('{', m.end() - 1)
        k, depth = i, 0
        while k < len(s):
            if s[k] == '{':
                depth += 1
            elif s[k] == '}':
                depth -= 1
                if depth == 0:
                    return s[m.start():k + 1]
            k += 1
    return None


def collect(seed, fn_va):
    """Closure of twin bodies reachable from `seed` via direct calls."""
    bodies, order, need_stub = {}, [], set()
    work = list(seed)
    while work:
        name = work.pop(0)
        if name in bodies:
            continue
        t = vc.extract_twin_any(name)
        if t is None:
            pure = extract_pure_c(name)
            if pure is None:
                need_stub.add(name)
                continue
            t = (pure,)
        body = t[0]
        bodies[name] = body
        order.append(name)
        for callee in sorted(set(re.findall(r'\b([A-Za-z_]\w*)\b', body))):
            if callee != name and callee in fn_va and callee not in bodies:
                work.append(callee)
    return bodies, order, need_stub


def gdef_arena(g, va, alltext):
    """Body-usage-aware lvalue alias into the arena (mirrors verify_coexec.gdef
    but resolves to MK4_VA(...) instead of an absolute VA)."""
    if g in WIDTH16:
        # signed: the geometry path reads these with movsx, never movzx
        return '#define %s (*(short *)MK4_VA(short, 0x%xu))\n' % (g, va)
    if re.search(r'\(\s*\*\s*%s\s*\)\s*\(' % g, alltext) or \
       re.search(r'\b%s\s*\(' % g, alltext):
        return '#define %s (*(unsigned int (**)())MK4_VA(unsigned int, 0x%xu))\n' % (g, va)
    if re.search(r'\b%s\s*\[' % g, alltext):
        return '#define %s ((unsigned int *)MK4_VA(unsigned int, 0x%xu))\n' % (g, va)
    deref = False
    for m in re.finditer(r'\*\s*%s\b' % g, alltext):
        j = m.start() - 1
        while j >= 0 and alltext[j] in ' \t':
            j -= 1
        if j < 0 or (alltext[j] not in '_)]' and not alltext[j].isalnum()):
            deref = True
    if deref:
        return '#define %s (*(unsigned int **)MK4_VA(unsigned int, 0x%xu))\n' % (g, va)
    return '#define %s (*(unsigned int *)MK4_VA(unsigned int, 0x%xu))\n' % (g, va)


def main():
    fn_va, gl_va = vt.load_maps()
    # --emit drives the FULL chain: a real strip mesh through the projection
    # + emitter layer into the draw queue, then the sort/dispatch/rasterize
    # pipeline. Without it only the pipeline half runs, off hand-seeded records.
    emit = '--emit' in sys.argv or '--geo' in sys.argv
    geo = '--geo' in sys.argv
    if geo:
        seed = ['DrawMeshBlock', 'FlushDrawQueue']
    elif emit:
        seed = ['TristripBatchEmit', 'FlushDrawQueue']
    else:
        seed = ['FlushDrawQueue']
    bodies, order, need_stub = collect(seed, fn_va)
    # Renderer_GetMode is the only SW-path callee we satisfy ourselves.
    need_stub.discard('FlushDrawQueue')
    alltext = '\n'.join(bodies.values())
    globs = sorted(set(re.findall(r'\bg_\w+', alltext)))
    missing = [g for g in globs if g not in gl_va]

    out = []
    P = out.append
    P('/* GENERATED by tools/decomp/gen_wasm_render.py - do not edit. */')
    P('/* Self-contained wasm32 bundle of the verified SW render pipeline. */')
    P('#define NON_MATCHING 1')
    P('#define MK4_ARENA 1')
    P('#include <stdio.h>')
    P('#include <stdlib.h>')
    P('#include <string.h>')
    P('#include "types.h"')
    P('#include "portable/ghidra_types.h"')
    P('#include "portable/mem_model.h"')
    P('')
    P('unsigned char *g_mk4Arena = 0;       /* arena base (32-bit in wasm32) */')
    P('unsigned int   g_mk4ArenaSize = 0;')
    P('')
    # NOTE: the aliases are emitted PER FUNCTION, not once globally. The same
    # VA is legitimately viewed differently by different bodies -
    # AdvanceTriStripRing indexes g_triStripRingA[0..2] as an array while
    # TristripBatchEmit reads it as a scalar dword AND takes &g for a +2 word
    # access - so one shared macro cannot serve both. The co-exec verifier has
    # never hit this because it compiles a separate blob per function, each
    # with a gdef tuned to that body; scoping the macros reproduces exactly
    # that, and keeps every body byte-for-byte the verified source.
    P('')
    P('/* --- forward declarations --- */')
    for n in order:
        # Use the body's own signature: several collected functions take
        # arguments (TristripBatchEmit(mesh, parity, sortpick),
        # Helper_EmitLine(slot), Vec3ColorShiftClamp(entry, n)), so a blanket
        # `void f(void)` would be a conflicting declaration.
        sig = bodies[n][:bodies[n].index('{')].strip().rstrip()
        P('%s;' % ' '.join(sig.split()))
    if 'Renderer_GetMode' not in bodies:
        P('static int Renderer_GetMode(void);')
    P('')
    P('/* --- render twin bodies (verified portable C) --- */')
    for n in order:
        body = bodies[n]
        used = [g for g in sorted(set(re.findall(r'\bg_\w+', body))) if g in gl_va]
        P('/* ---- %s ---- */' % n)
        for g in used:
            P(gdef_arena(g, gl_va[g], body).rstrip())
        P(body)
        for g in used:
            P('#undef %s' % g)
        P('')
    if 'Renderer_GetMode' not in bodies:
        P('static int Renderer_GetMode(void) {')
        P('    return *(int *)MK4_VA(int, 0x%xu);' % RENDER_MODE_VA)
        P('}')
    P('')
    # ---- driver ----
    sdl = '--sdl' in sys.argv
    native = '--native' in sys.argv
    fmt = dict(fb_va=FB_VA, tex_va=TEX_VA, pal_va=PAL_VA, pal_sz=PAL_SZ,
               geo_va=GEO_VA,
               w=EMIT_W if emit else W, h=EMIT_H if emit else H,
               mode_va=RENDER_MODE_VA, rec=REC)
    P('/* ---- driver ---- */')
    DRIVER_GLOBALS = ['g_viewportX', 'g_viewportY', 'g_viewportW', 'g_viewportH',
                      'g_dispatchSave1400', 'g_dispatchSave1340', 'g_drawQueueSize',
                      'g_inLoopStep', 'g_dualC']
    for g in DRIVER_GLOBALS:
        if g in gl_va:
            P(gdef_arena(g, gl_va[g], '').rstrip())
    P(DRIVER_COMMON % fmt)
    if emit:
        P(DRIVER_EMIT % fmt)
        if geo:
            P(DRIVER_GEO % fmt)
            gp = sys.argv[sys.argv.index('--geo') + 1]
            # the raw atlas sits next to the asset: sc_geo.geo -> sc_tex.bin
            tp = gp.replace('_geo.geo', '_tex.bin')
            P('#define SCENE_INIT()   (mesh_init(), geo_tex_load("%s"), geo_load("%s"))'
              % (tp, gp))
            P('#define SCENE_FRAME(f) geo_frame(f)')
        else:
            P('#define SCENE_INIT()   mesh_init()')
            P('#define SCENE_FRAME(f) mesh_frame(f)')
    else:
        P('#define SCENE_INIT()   ((void)0)')
        P('#define SCENE_FRAME(f) do { seed_scene(f); FlushDrawQueue(); } while (0)')
    P((DRIVER_NATIVE if native else DRIVER_SDL if sdl else DRIVER_PPM) % fmt)
    sys.stdout.write('\n'.join(out) + '\n')
    sys.stderr.write('twins=%d  stubs_needed=%s  missing_globals=%s\n'
                     % (len(order), sorted(need_stub) or 'none', missing or 'none'))


DRIVER_COMMON = r'''
/* ---------------- driver (shared) ---------------- */
#define FB_VA   0x%(fb_va)xu
#define TEX_VA  0x%(tex_va)xu
#define PAL_VA  0x%(pal_va)xu
#define PAL_SZ  0x%(pal_sz)xu
#define GEO_VA  0x%(geo_va)xu
#define W       %(w)d
#define H       %(h)d
#define PITCH   (W * 2)
#define REC     0x%(rec)xu
#define MODE_VA 0x%(mode_va)xu

static void setw(unsigned int va, unsigned short v) {
    *(unsigned short *)MK4_VA(unsigned short, va) = v;
}
static void setb(unsigned int va, unsigned char v) {
    *(unsigned char *)MK4_VA(unsigned char, va) = v;
}
static void setdw(unsigned int va, unsigned int v) {
    *(unsigned int *)MK4_VA(unsigned int, va) = v;
}

/* one 0x1c-byte primitive record (mirrors verify_flush.rect_record) */
static void rec_prim(int idx, int x0, int y0, int x1, int y1,
                     int u0, int v0, int u1, int v1, int color, int typ) {
    unsigned int r = REC + (unsigned)idx * 0x1c;
    setw(r + 0, x0);   setw(r + 2, y0);
    setw(r + 4, x1);   setw(r + 6, y0);     /* V1 */
    setw(r + 8, x1);   setw(r + 0xa, y1);
    setb(r + 0xc, u0); setb(r + 0xd, v0);
    setb(r + 0xe, u1); setb(r + 0xf, v1);
    setb(r + 0x10, u1); setb(r + 0x11, v1);
    /* Sort key = screen x0. FlushDrawQueue buckets it into g_drawQueueBuckets,
       which has exactly 0x400 entries, so the key MUST be 0..0x3ff - the engine
       guarantees that upstream (Helper_DrawCursor rejects negative-x
       primitives; see verify_submit's reject-negx scenario). Clamp here so a
       bad seed can never scribble outside the bucket array: on wasm32 that OOB
       was invisible (one flat linear memory), on a 64-bit host it faults. */
    setw(r + 0x12, x0 < 0 ? 0 : (x0 > 0x3ff ? 0x3ff : x0));   /* sort key */
    setw(r + 0x14, color);
    setw(r + 0x16, 0); setw(r + 0x18, 0);
    setw(r + 0x1a, typ);
}

/* Load the original data image into one linear arena + carve a texture. */
static int arena_init(const char *img) {
    FILE *f = fopen(img, "rb");
    long n; unsigned int i;
    if (!f) { fprintf(stderr, "cannot open %%s\n", img); return 0; }
    fseek(f, 0, SEEK_END); n = ftell(f); fseek(f, 0, SEEK_SET);
    g_mk4ArenaSize = 0x1800000;               /* 24 MB: image + FB + TEX + PAL */
    g_mk4Arena = (unsigned char *)calloc(1, g_mk4ArenaSize);
    if (!g_mk4Arena) { fprintf(stderr, "calloc failed\n"); fclose(f); return 0; }
    if (fread(g_mk4Arena, 1, (size_t)n, f) != (size_t)n) {
        fprintf(stderr, "short read\n"); fclose(f); return 0; }
    fclose(f);
    for (i = 0; i < 0x100000; i += 2)         /* distinct non-zero RGB565 texels */
        *(unsigned short *)MK4_VA(unsigned short, TEX_VA + i) =
            (unsigned short)((((i >> 1) %% 255) + 1));
    /* Lighting LUT at g_dispatchSave1340. TexturedTriRasterizeShaded reads
           colour = LUT[ (shade & 0xffff0000) | texel ]
       with shade = ((shadeAcc >> 3) + LUT_base) >> 1, so the effective address
       is (LUT_base + (shadeAcc >> 3)) rounded DOWN to 128 KB, plus texel*2.
       That makes the table 16 PAGES of 128 KB - a full 16-bit -> 16-bit colour
       map per brightness level - selected by shadeAcc >> 20. The vertex shade
       byte is (avg channel) << 3, i.e. 0..248, so the level is shade >> 4 =
       0..15. 16 * 128 KB = 2 MB = exactly PAL_SZ.
       Left at 0 the lookup would deref VA 0, 4 MB BELOW the arena base -
       invisible on wasm32, an instant fault natively. */
    {
        unsigned char scale[16][32];
        unsigned int L, T;
        for (L = 0; L < 16; L++)
            for (T = 0; T < 32; T++)
                scale[L][T] = (unsigned char)((T * L) / 15);
        for (L = 0; L < 16; L++) {
            unsigned short *page =
                (unsigned short *)MK4_VA(unsigned short, PAL_VA + L * 0x20000u);
            for (T = 0; T < 0x10000u; T++)
                page[T] = (unsigned short)((T & 0x8000u)
                          | ((unsigned)scale[L][(T >> 10) & 0x1f] << 10)
                          | ((unsigned)scale[L][(T >> 5) & 0x1f] << 5)
                          | (unsigned)scale[L][T & 0x1f]);
        }
    }
    return 1;
}

/* Seed the renderer state + a small scene (rects + triangles). `frame` shifts
   the primitives so a main loop animates the same dispatch every tick. */
static void seed_scene(int frame) {
    int dx = frame %% 40, dy = frame / 2 %% 30;   /* keep every x0 on-screen */
    setdw(MODE_VA, 5);                                    /* SW mode */
    g_drawQueueSize = 7;
    /* These globals hold ORIGINAL VAs, not host pointers: the twins deref them
       through MK4_PTR, which is the identity on a flat 32-bit layout and adds
       the arena translation on a 64-bit host. Storing a truncated host pointer
       here (the old form) only worked because wasm32 pointers are 32-bit. */
    g_viewportX = FB_VA;
    g_viewportY = PITCH;  g_viewportW = W;  g_viewportH = H;
    g_dispatchSave1400 = TEX_VA;
    g_dispatchSave1340 = PAL_VA;          /* CLUT / lighting-LUT base */
    /* clear the framebuffer between frames */
    memset(MK4_VA(void, FB_VA), 0, PITCH * H);
    rec_prim(0,  20+dx,  20+dy, 160+dx, 120+dy, 0,0, 60,40, 0xffff, 0x20);
    rec_prim(1,  60+dx,  40+dy, 220+dx, 160+dy, 4,2, 80,50, 0x1000, 0x20);
    rec_prim(2, 100,     60+dy, 280,    200+dy, 1,1, 70,45, 0xffff, 0x20|0x80);
    rec_prim(3,  40+dx, 100,    200+dx, 220,    2,0, 64,36, 0xffff, 0x20|0x40);
    rec_prim(4, 130-dx,  30+dy, 300-dx, 210+dy, 0,0, 90,60, 0xffff, 0x00);
    rec_prim(5,  10,    140-dy, 150,    235-dy, 3,1, 55,40, 0x1000, 0x00);
    rec_prim(6,  80+dx,  80,    260+dx, 180,    5,3, 88,52, 0xffff, 0x180);
}
'''

DRIVER_PPM = r'''
/* ---------------- headless PPM driver (node) ---------------- */
int main(int argc, char **argv) {
    const char *img  = (argc > 1) ? argv[1] : "build/arena.bin";
    const char *outp = (argc > 2) ? argv[2] : "build/wasm/frame.ppm";
    unsigned short *fb;
    FILE *o; int x, y, nz = 0;
    if (!arena_init(img)) return 2;
    SCENE_INIT();
    SCENE_FRAME(0);
    fb = (unsigned short *)MK4_VA(unsigned short, FB_VA);
    o = fopen(outp, "wb");
    if (!o) { fprintf(stderr, "cannot write %%s\n", outp); return 2; }
    fprintf(o, "P6\n%%d %%d\n255\n", W, H);
    for (y = 0; y < H; y++) for (x = 0; x < W; x++) {
        unsigned short px = fb[y * W + x];
        unsigned char rgb[3];
        if (px) nz++;
        /* RGB-555: FlushDrawQueue's shade extraction masks the colour as
           (c>>10)&0x1f, (c>>5)&0x1f, c&0x1f - five bits per channel - and the
           .geo texture atlas decodes as 555 too. */
        rgb[0] = (unsigned char)(((px >> 10) & 0x1f) << 3);
        rgb[1] = (unsigned char)(((px >> 5)  & 0x1f) << 3);
        rgb[2] = (unsigned char)(( px        & 0x1f) << 3);
        fwrite(rgb, 1, 3, o);
    }
    fclose(o);
    fprintf(stderr, "wrote %%s (%%dx%%d, %%d non-zero px)\n", outp, W, H, nz);
    return 0;
}
'''

DRIVER_SDL = r'''
/* ---------------- SDL2 canvas driver (emscripten, browser) ---------------- */
#include <SDL2/SDL.h>
#include <emscripten.h>

static SDL_Renderer *g_ren;
static SDL_Texture  *g_tex;
static int g_frame;

static void tick(void) {
    SCENE_FRAME(g_frame++);
    /* the framebuffer is native RGB565 - upload straight into the texture */
    SDL_UpdateTexture(g_tex, NULL, MK4_VA(void, FB_VA), PITCH);
    SDL_RenderClear(g_ren);
    SDL_RenderCopy(g_ren, g_tex, NULL, NULL);
    SDL_RenderPresent(g_ren);
}

int main(int argc, char **argv) {
    SDL_Window *win;
    const char *img = (argc > 1) ? argv[1] : "build/arena.bin";
    if (!arena_init(img)) return 2;
    SCENE_INIT();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(W * 2, H * 2, 0, &win, &g_ren);
    SDL_RenderSetLogicalSize(g_ren, W, H);
    g_tex = SDL_CreateTexture(g_ren, SDL_PIXELFORMAT_RGB555,
                              SDL_TEXTUREACCESS_STREAMING, W, H);
    emscripten_set_main_loop(tick, 0, 1);
    return 0;
}
'''

DRIVER_NATIVE = r'''
/* ---------------- SDL2 desktop driver (native macOS / Linux) ----------------
   Same verified pipeline as the wasm bundle. The only reason this can run on a
   64-bit host at all is the MK4_PTR seam: every VA the twins carry in a 32-bit
   register-mirror local is translated at the deref, so the arena may live
   anywhere in a 64-bit address space (mmap of the low 4 GB is impossible on
   macOS arm64 - the whole region is __PAGEZERO). ------------------------- */
#include <SDL2/SDL.h>

int main(int argc, char **argv) {
    const char *img = (argc > 1) ? argv[1] : "build/arena.bin";
    SDL_Window *win; SDL_Renderer *ren; SDL_Texture *tex;
    int frame = 0, running = 1, scale = 3;

    if (!arena_init(img)) return 2;
    SCENE_INIT();
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init: %%s\n", SDL_GetError()); return 2; }
    win = SDL_CreateWindow("MK4 - verified SW render pipeline (native)",
                           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                           W * scale, H * scale, SDL_WINDOW_SHOWN);
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(ren, W, H);
    tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGB555,
                            SDL_TEXTUREACCESS_STREAMING, W, H);
    if (!win || !ren || !tex) {
        fprintf(stderr, "SDL setup: %%s\n", SDL_GetError()); return 2; }

    /* headless smoke mode: render N frames, report, exit (for CI / no display) */
    if (argc > 2 && argv[2][0] == '-' && argv[2][1] == 'n') {
        int n = atoi(argv[2] + 2), i, x, y, nz = 0;
        unsigned short *fb;
        for (i = 0; i < (n > 0 ? n : 1); i++) SCENE_FRAME(i);
        fb = (unsigned short *)MK4_VA(unsigned short, FB_VA);
        for (y = 0; y < H; y++) for (x = 0; x < W; x++) if (fb[y * W + x]) nz++;
        fprintf(stderr, "native: %%d frames, %%d non-zero px in last frame\n",
                (n > 0 ? n : 1), nz);
        SDL_Quit(); return nz ? 0 : 1;
    }

    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = 0;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) running = 0;
        }
        SCENE_FRAME(frame++);                 /* verified twins, end to end */
        SDL_UpdateTexture(tex, NULL, MK4_VA(void, FB_VA), PITCH);
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tex, NULL, NULL);
        SDL_RenderPresent(ren);
    }
    SDL_DestroyTexture(tex); SDL_DestroyRenderer(ren); SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
'''


DRIVER_EMIT = r'''
/* ---------------- mesh scene (the FULL verified chain) ----------------------
   seed_mesh() replaces the hand-seeded draw-queue records with a real triangle
   -strip mesh, so a frame runs the whole thing:

     mesh -> TristripBatchEmit -> ProjectTwoVertices / ProjectVertex /
             AdvanceTriStripRing -> backface test -> DrawEntry ->
             Vec3ColorShiftClamp -> Helper_DrawCursor -> FlushDrawQueue ->
             (sort) -> rasterizers -> framebuffer

   Every one of those is co-exec verified against the original bytes. The mesh
   layout is the one the emitter itself defines (see verify_emit.py):
     M+4 : s32 vtxOff   -> vertices   at M + 4 + vtxOff
     M+8 : s32 stripOff -> strip list at M + 8 + stripOff
     strips  : (u16 flags, s16 count) pairs, a NEGATIVE count terminates
     vertices: 6 s16 each (x,y,z + 3 payload); a strip opens on two vertices
               then walks count+1 more
   ------------------------------------------------------------------------- */
#include <math.h>

#define MESH_VA    0x00f40000u
#define ENTRIES_VA 0x00f50000u
#define LUT_VA     0x00b0d008u      /* g_zSortKeyLUT[65536] (u16) */
#define MAT_VA     0x007af990u      /* nine s16, +2 stride (Q12) */

static void mesh_setw(unsigned int va, int v) {
    *(short *)MK4_VA(short, va) = (short)v;
}
static void mesh_setdw(unsigned int va, int v) {
    *(int *)MK4_VA(int, va) = v;
}

/* A cylinder as triangle strips. The emitter consumes vertices STRICTLY
   sequentially - two to open a strip, then one per inner iteration, and it
   carries straight on into the next strip - so the vertex array must be
   written in exactly the order the strips walk it: for each strip, alternate
   between ring r and ring r+1 so consecutive triples form real triangles.
   (Laying each ring out contiguously instead gives a fan of near-degenerate
   slivers - 5 lit pixels for the whole mesh.) */
#define RINGS  4
#define SEG    8
#define RADIUS 0xC0
#define ZDIST  0x380   /* camera distance, applied as the TRANSLATION */
#define VPS    (2 * (SEG + 1))          /* vertices per strip */
#define NSTRIP (RINGS - 1)

static void mesh_build(void) {
    unsigned int vtx = MESH_VA + 0x100, strip = MESH_VA + 0x800;
    int r, k, i = 0;
    mesh_setdw(MESH_VA + 4, (int)(vtx - (MESH_VA + 4)));
    mesh_setdw(MESH_VA + 8, (int)(strip - (MESH_VA + 8)));
    for (r = 0; r < NSTRIP; r++) {
        for (k = 0; k <= SEG; k++) {
            int q, kk = k %% SEG;
            double a = 6.283185307 * kk / SEG;
            for (q = 0; q < 2; q++, i++) {
                unsigned int v = vtx + (unsigned)i * 12;
                int rr = r + q;
                mesh_setw(v + 0, (int)(cos(a) * RADIUS));
                mesh_setw(v + 2, (rr - RINGS / 2) * 0x60);
                /* centred on the ORIGIN: the matrix rotates about the
                   origin, so a mesh built at z = ZDIST would ORBIT out of
                   frame instead of spinning in place. The distance is added
                   afterwards by g_vtxTransZ. */
                mesh_setw(v + 4, (int)(sin(a) * RADIUS));
                mesh_setw(v + 6, (kk * 32) & 0xff);      /* payload: u / colour */
                mesh_setw(v + 8, (rr * 48) & 0xff);
                mesh_setw(v + 10, 0x300 + i);
            }
        }
        mesh_setw(strip + r * 4 + 0, 0x0001);
        mesh_setw(strip + r * 4 + 2, VPS - 3);   /* opens on 2, walks count+1 */
    }
    mesh_setw(strip + NSTRIP * 4 + 0, 0);
    mesh_setw(strip + NSTRIP * 4 + 2, -1);       /* negative count terminates */
}

#define DIV3_VA 0x00f70ff8u        /* g_div3Table */

static void mesh_init(void) {
    unsigned int k;
    /* SECOND runtime-built table that is all-zero in the static image (the
       z-sort LUT below is the first). FlushDrawQueue turns a vertex colour
       into a shade with
           shade = (g_div3Table[r + g + b] << 3) & 0xff
       so an empty table makes EVERY shade 0, which selects lighting-LUT page 0
       - solid black. Three 5-bit channels sum to at most 93. */
    for (k = 0; k < 0x100u; k++)
        *(unsigned char *)MK4_VA(unsigned char, DIV3_VA + k) = (unsigned char)(k / 3);
    /* Depth -> bucket table. FlushDrawQueue buckets on the +0x12 field that
       Helper_DrawCursor rewrites through this LUT, and there are exactly 0x400
       buckets, so every entry MUST land in 0..0x3ff. The static image has the
       table all-zero (the game fills it at runtime), which would collapse every
       primitive into bucket 0 - a ramp makes the sort actually order by depth. */
    for (k = 0; k < 0x10000u; k++)
        *(unsigned short *)MK4_VA(unsigned short, LUT_VA + k * 2) =
            (unsigned short)(k >> 6);
    mesh_build();
}

/* Q12 rotation about Y composed with a fixed tilt, written into the packed
   nine-s16 matrix the projection helpers read (movsx word, +2 stride). */
static void mesh_matrix(int frame) {
    /* Pure rotation about Y, Q12. Keeping the Y row at identity leaves every
       vertex at its own height and keeps the transformed Z strictly positive
       for the whole turn - mixing X/Z into the Y row (an earlier version) drove
       Z through the near-plane test and blanked the frame part of the way
       round. */
    double a = frame * 0.03, c = cos(a), s = sin(a);
    int m[9];
    m[0] = (int)(c * 0x1000);  m[1] = 0;      m[2] = (int)(s * 0x1000);
    m[3] = 0;                  m[4] = 0x1000; m[5] = 0;
    m[6] = (int)(-s * 0x1000); m[7] = 0;      m[8] = (int)(c * 0x1000);
    { int i; for (i = 0; i < 9; i++) mesh_setw(MAT_VA + (unsigned)i * 2, m[i]); }
}

/* g_viewportX / g_viewportY are per-DISPATCH scratch, not persistent state:
   FlushDrawQueue's rasterizers consume them (both read back as 0 afterwards).
   The engine re-establishes them every frame in its SW BeginFrame, so anything
   that dispatches more than once - e.g. one flush per mesh block - must re-arm
   them before EACH FlushDrawQueue or every dispatch after the first draws into
   a null framebuffer. */
static void viewport_arm(void) {
    g_viewportX = FB_VA;                     /* VAs, not host pointers */
    g_viewportY = PITCH;  g_viewportW = W;  g_viewportH = H;
}

static void seed_mesh(int frame) {
    setdw(MODE_VA, 5);                       /* SW mode */
    viewport_arm();
    g_dispatchSave1400 = TEX_VA;
    g_dispatchSave1340 = PAL_VA;
    g_inLoopStep = 0;                        /* the emitter gate */
    g_dualC = ENTRIES_VA - 4;                /* DrawEntries at g_dualC + 4 */
    g_drawQueueSize = 0;                     /* rebuild the queue each frame */
    mesh_matrix(frame);
    setdw(0x007af9a4u, 0x10);                /* g_vtxTransX */
    setdw(0x007af9a8u, 0x00);                /* g_vtxTransY */
    setdw(0x007af9acu, ZDIST);               /* g_vtxTransZ: push it in front */
    memset(MK4_VA(void, FB_VA), 0, PITCH * H);
}

static void mesh_frame(int frame) {
    seed_mesh(frame);
    TristripBatchEmit((int)MESH_VA, 0, 0);   /* project + emit + enqueue */
    viewport_arm();
    FlushDrawQueue();                        /* sort + dispatch + rasterize */
}
'''


DRIVER_GEO = r"""
/* ---------------- real .geo asset scene -------------------------------------
   Loads a character asset verbatim into the arena and hands each of its mesh
   blocks straight to the verified emitter. The block layout is decoded in
   tools/geo_mesh.py; the short version is that ofs_a / ofs_b are relative TO
   THEIR OWN FIELD, which is precisely what the emitter computes:
       vertices   at block + 4 + *(s32 *)(block + 4)
       strip list at block + 8 + *(s32 *)(block + 8)
   Loading the file verbatim therefore preserves every offset for free.

   type-1 and type-0 blocks are two parallel sets covering the same parts (an
   LOD or variant set - the per-part triangle counts repeat), so only type 1 is
   drawn or the model renders twice over itself.
   ------------------------------------------------------------------------- */
static int g_geoBlocks[256], g_geoNBlocks, g_geoTris[256];

/* The .geo texture half decodes to one 256x256 RGB-555 atlas (128 KB), which
   is exactly how the rasterizers address it: a texel is read at
   (tex_base/2 & 0xffff0000 | V<<8 | U) * 2, so 256 texels per row and the base
   VA must be 0x20000-aligned for that high-half trick to hold. TEX_VA is.
   Dump it with: tools/geo_decode.py FILE 0 --raw out.bin */
static int geo_tex_load(const char *path) {
    FILE *f = fopen(path, "rb");
    size_t n;
    if (!f) { fprintf(stderr, "no texture %%s (keeping the synthetic one)\n", path);
              return 0; }
    n = fread(MK4_VA(void, TEX_VA), 1, 256u * 256u * 2u, f);
    fclose(f);
    fprintf(stderr, "geo: texture atlas %%lu bytes -> TEX_VA\n", (unsigned long)n);
    return n == 256u * 256u * 2u;
}

static int geo_load(const char *path) {
    FILE *f = fopen(path, "rb");
    long n; unsigned int tex, o;
    unsigned char *base;
    if (!f) { fprintf(stderr, "cannot open %%s\n", path); return 0; }
    fseek(f, 0, SEEK_END); n = ftell(f); fseek(f, 0, SEEK_SET);
    base = (unsigned char *)MK4_VA(unsigned char, GEO_VA);
    if (fread(base, 1, (size_t)n, f) != (size_t)n) {
        fprintf(stderr, "short read\n"); fclose(f); return 0; }
    fclose(f);
    if (base[0] != '0' || base[1] != '.' || base[2] != '1' || base[3] != 'v') {
        fprintf(stderr, "not a .geo\n"); return 0; }
    tex = *(unsigned int *)(base + 4);
    g_geoNBlocks = 0;
    for (o = 0x0c; o + 16 <= tex && g_geoNBlocks < 256; o += 16) {
        unsigned short typ = *(unsigned short *)(base + o);
        unsigned short cnt = *(unsigned short *)(base + o + 2);
        int a = *(int *)(base + o + 4), b = *(int *)(base + o + 8);
        unsigned int va = o + 4 + (unsigned)a, sa = o + 8 + (unsigned)b;
        if ((typ != 0 && typ != 1) || cnt == 0) break;
        if (va >= tex || sa >= tex) break;
        if (typ == 1) {
            /* block + 12 + ofs_c is the per-TRIANGLE table: 8 bytes each,
               u8 pad / u8 tex_index / three (u,v) byte pairs. */
            g_geoTris[g_geoNBlocks] = (int)(GEO_VA + o + 12 + (unsigned)*(int *)(base + o + 12));
            g_geoBlocks[g_geoNBlocks++] = (int)(GEO_VA + o);
        }
    }
    fprintf(stderr, "geo: %%ld bytes, %%d type-1 mesh blocks\n", n, g_geoNBlocks);
    return g_geoNBlocks > 0;
}

/* Each mesh block is a body part in its OWN local space - the per-part
   placement lives in the scene graph (the .geo blocks are skeleton nodes), so
   drawing them all with one transform piles them on the origin. Until the node
   walk is converted, lay the parts out on a grid: it shows every block
   decoding and rasterizing, and it is honest about what is still missing. */
#define GEO_COLS 6
#define GEO_CELL 0x50

/* The lighting DrawMeshBlock needs. MatVec2Multiply (which it calls) turns
   g_lightMat00/01/02 + g_dispatchSave1627/28/29 and the transposed vertex
   matrix into g_vtxLight0_* / g_vtxLight1_*, which is exactly what
   TransformVertex then reads per vertex (g_lightMat20/21/22 and
   g_vtxLight0_x/y/z are the same three VAs). */
static void geo_lighting(void) {
    setdw(0x007af9c0u, 0x0180);  setdw(0x007af9c4u, 0x0080);  setdw(0x007af9c8u, 0x0040);
    setdw(0x007af9ccu, 0x0060);  setdw(0x007af9d0u, 0x0140);  setdw(0x007af9d4u, 0x00a0);
    /* Vertex colour drives the SHADE, and the shade picks a 128 KB page of the
       lighting LUT: level = (average channel) >> 4, so 0..15. Page 15 leaves
       the texel untouched (the atlas's own colours) and page 0 is black - a
       dim base therefore renders the model completely black. Start bright and
       let the lights vary it downward. */
    setw(0x007af9f0u, 0x6318);            /* g_vtxColorPrev: 24,24,24 */
    setw(0x007af9fcu, 0x6318);            /* g_vtxColor               */
    setw(0x007af9f8u, 0x6318);            /* g_vtxColorCopy           */
    setw(0x007af9fau, 0x6318);            /* g_vtxColorSaved          */
    /* the six RGB scales are PACKED BYTES at 0x7af9f2..f7 - byte writes only */
    setb(0x007af9f2u, 0x30); setb(0x007af9f3u, 0x18);   /* blue  light0 / light1 */
    setb(0x007af9f4u, 0x40); setb(0x007af9f5u, 0x20);   /* green */
    setb(0x007af9f6u, 0x50); setb(0x007af9f7u, 0x28);   /* red   */
    setdw(0x00543aa8u, 1);                /* g_menuRestoreSlot != 0 -> MESH path */
    setdw(0x00ab4e60u, 0x200);            /* g_dispatchSave1576: no attenuation  */
    setdw(0x00ab4d9cu, 0);                /* g_dispatchSave1559: sort-key bias   */
    setdw(0x00ab4e28u, 0);                /* g_dispatchSave1570: no alt cam      */
}

/* Neither emitter writes a draw entry's u/v bytes (+0xc..+0x11) - they only
   fill the fields that vary per frame and advance the cursor by 0x1c per
   TRIANGLE whether or not they submit. The entry array at g_dualC+4 is
   therefore a persistent per-mesh table that some setup pass populates from
   the block's triangle table, in the same triangle order. This reproduces
   that pass, so the rasterizers see real texture coordinates instead of
   whatever was left in the staging area. */
static void geo_fill_uvs(int blk) {
    unsigned char *tri = (unsigned char *)MK4_VA(unsigned char, (unsigned)g_geoTris[blk]);
    unsigned char *e = (unsigned char *)MK4_VA(unsigned char, ENTRIES_VA);
    unsigned short cnt = *(unsigned short *)MK4_VA(unsigned short,
                             (unsigned)g_geoBlocks[blk] + 2);
    int k, j;
    for (k = 0; k < (int)cnt; k++, tri += 8, e += 0x1c)
        for (j = 0; j < 6; j++)
            e[0xc + j] = tri[2 + j];
}

static void geo_frame(int frame) {
    int i;
    seed_mesh(frame);                     /* viewport, palette, gate, matrix */
    geo_lighting();
    setdw(0x007af9acu, 0x2c0);            /* g_vtxTransZ */
    for (i = 0; i < g_geoNBlocks; i++) {
        setdw(0x007af9a4u, (i %% GEO_COLS - GEO_COLS / 2) * GEO_CELL);      /* transX */
        setdw(0x007af9a8u, (i / GEO_COLS - g_geoNBlocks / GEO_COLS / 2) * GEO_CELL); /* transY */
        g_drawQueueSize = 0;              /* the emitter refills g_dualC+4 per block */
        geo_fill_uvs(i);                  /* the setup pass the emitters assume */
        DrawMeshBlock(g_geoBlocks[i], 0, 0);   /* the .geo MAIN path */
        viewport_arm();                   /* consumed by the previous dispatch */
        FlushDrawQueue();                 /* draw this block before the next */
    }
}
"""


if __name__ == '__main__':
    main()
