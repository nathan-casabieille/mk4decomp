/**
 * Native video route (TARGET=sdl).
 *
 * The engine's per-frame video path is entirely portable C already:
 *
 *     BeginFrame(flag)
 *       -> Renderer5_BeginFrame_SW_FS_Hi(flag, &base, &pitch, &unused)
 *       -> SetViewport(base, pitch, w, h)      // g_viewportX = base, Y = pitch
 *     DrawScene()
 *       -> FlushDrawQueue()                    // sort + dispatch + rasterise
 *       -> Renderer5_EndScene_SW_FS_Hi()       // a DirectDraw Flip on Win32
 *
 * On Windows the BeginFrame hook LOCKS a DirectDraw surface and hands its
 * address + pitch back; EndScene flips it. Both are COM, so both are naked in
 * the matching build and neither can run here. Providing the BeginFrame hook
 * natively IS the whole video route: point it at a framebuffer inside the
 * arena and the software rasterisers - which address the framebuffer through
 * the MK4_PTR seam by ORIGINAL VA - draw straight into it. The present side
 * is then just a blit, done by the platform layer after the frame body.
 *
 * Nothing in src/engine or src/game is touched: this file is the port's video
 * driver, exactly where a platform backend belongs.
 */
#include "platform/pal.h"
#include "portable/arena.h"
#include "portable/mem_model.h"

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

/* Scratch VAs above the original image (which ends near 0x00fa2000), so the
 * seam reaches them and every offset stays positive. */
#define MK4_FB_VA     0x01000000u
#define MK4_TEX_VA    0x01100000u
#define MK4_LUT_VA    0x01200000u     /* 16 x 128 KB shading pages */

/* Runtime-built tables: ALL THREE are zero in the static image because the
 * game fills them during boot, and the boot path is not converted yet. Each
 * one is load-bearing:
 *   g_sinTable    - every rotation matrix comes out zero without it
 *   g_div3Table   - vertex shade = (g_div3Table[r+g+b] << 3) & 0xff, so an
 *                   empty table makes every shade 0 -> shading page 0 -> black
 *   g_zSortKeyLUT - FlushDrawQueue's counting sort has exactly 0x400 buckets,
 *                   so this must map a depth key into 0..0x3ff or it scribbles
 */
#define MK4_SIN_VA    0x007b01a0u
#define MK4_DIV3_VA   0x00f70ff8u
#define MK4_ZSORT_VA  0x00b0d008u

/* Mode + geometry. BeginFrame hardcodes 320x240 for mode 5 and 640x480 for
 * mode 4; MK4_VIDEO_MODE / MK4_VIDEO_W / MK4_VIDEO_H let a run override the
 * mode and the presented size while the right combination is pinned down. */
static int s_w = 640, s_h = 480;

extern int g_currentRendererMode;
extern int g_clampedRendererMode;

static int env_int(const char *name, int dflt)
{
    const char *v = getenv(name);
    return v ? (int)strtol(v, NULL, 0) : dflt;
}

/* --- the BeginFrame hook: hand the rasterisers their framebuffer ---------- */
void Renderer5_BeginFrame_SW_FS_Hi(int flag, int *base, int *pitch, int *unused)
{
    (void)flag;
    if (base)   *base  = (int)MK4_FB_VA;      /* a VA - the seam translates */
    if (pitch)  *pitch = s_w * 2;             /* RGB-555, 2 bytes per pixel */
    if (unused) *unused = 0;
}

/* --- one-time setup ------------------------------------------------------ */
void MK4_NativeVideoInit(void)
{
    unsigned int k;
    unsigned char scale[16][32];
    int mode = env_int("MK4_VIDEO_MODE", 5);

    s_w = env_int("MK4_VIDEO_W", 640);
    s_h = env_int("MK4_VIDEO_H", 480);

    g_currentRendererMode = mode;
    g_clampedRendererMode = mode;

    memset(MK4_VA(void, MK4_FB_VA), 0, (unsigned)(s_w * s_h * 2));

    /* sine table: 4096 entries of sin * 2^28, indexed by BAM (0x1000 = 2 PI).
     * The builders read each entry >> 16 and multiply >> 12, i.e. Q12. */
    for (k = 0; k < 4096u; k++) {
        double a = (double)k * 6.283185307179586 / 4096.0;
        *(int *)MK4_VA(int, MK4_SIN_VA + k * 4) = (int)(sin(a) * 268435456.0);
    }
    /* channel-average table: three 5-bit channels sum to at most 93 */
    for (k = 0; k < 256u; k++)
        *(unsigned char *)MK4_VA(unsigned char, MK4_DIV3_VA + k) = (unsigned char)(k / 3);
    /* depth key -> bucket, biased so a scene's projected-Z range spreads over
     * the histogram instead of crushing into a handful of buckets */
    for (k = 0; k < 0x10000u; k++) {
        int v = (int)k - 0x100;
        if (v < 0) v = 0;
        if (v > 0x3ff) v = 0x3ff;
        *(unsigned short *)MK4_VA(unsigned short, MK4_ZSORT_VA + k * 2) = (unsigned short)v;
    }
    /* 16 shading pages of 64K entries: TexturedTriRasterizeShaded looks up
     * LUT[(shade & 0xffff0000) | texel], the page selected by shade >> 20. */
    for (k = 0; k < 16u; k++) {
        unsigned int t;
        unsigned short *page = (unsigned short *)MK4_VA(unsigned short,
                                   MK4_LUT_VA + k * 0x20000u);
        unsigned int L;
        for (L = 0; L < 32u; L++)
            scale[k][L] = (unsigned char)((L * k) / 15);
        for (t = 0; t < 0x10000u; t++)
            page[t] = (unsigned short)((t & 0x8000u)
                      | ((unsigned)scale[k][(t >> 10) & 0x1f] << 10)
                      | ((unsigned)scale[k][(t >> 5) & 0x1f] << 5)
                      | (unsigned)scale[k][t & 0x1f]);
    }
    SDL_Log("native video: mode=%d %dx%d, fb@VA 0x%x, tables seeded "
            "(sin/div3/zsort/shading)", mode, s_w, s_h, MK4_FB_VA);
}

/* --- present ------------------------------------------------------------- */
void MK4_NativeVideoPresent(void)
{
    MK4_PalBlit555((const unsigned short *)MK4_VA(unsigned short, MK4_FB_VA),
                   s_w, s_h);
}

/* Headless check: MK4_DUMP_PPM=path writes the last framebuffer as RGB-555.
 * Lets `make native-frame-check` assert the frame actually drew something
 * without needing a display. */
void MK4_NativeVideoDump(const char *path)
{
    const unsigned short *fb = (const unsigned short *)MK4_VA(unsigned short, MK4_FB_VA);
    FILE *f = fopen(path, "wb");
    int x, y, nz = 0;
    if (!f) return;
    fprintf(f, "P6\n%d %d\n255\n", s_w, s_h);
    for (y = 0; y < s_h; y++)
        for (x = 0; x < s_w; x++) {
            unsigned short px = fb[y * s_w + x];
            unsigned char rgb[3];
            if (px) nz++;
            rgb[0] = (unsigned char)(((px >> 10) & 0x1f) << 3);
            rgb[1] = (unsigned char)(((px >> 5) & 0x1f) << 3);
            rgb[2] = (unsigned char)((px & 0x1f) << 3);
            fwrite(rgb, 1, 3, f);
        }
    fclose(f);
    SDL_Log("native video: wrote %s (%dx%d, %d non-zero px)", path, s_w, s_h, nz);
}

unsigned MK4_NativeVideoArenaReserve(void)
{
    /* everything up to the end of the shading table must live in the arena */
    return (MK4_LUT_VA - 0x00400000u) + 16u * 0x20000u;
}
