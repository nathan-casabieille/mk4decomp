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
#define MK4_TEX_SLOTS 16u            /* Helper_TexUpload puts the slot in bits
                                      * 16..19 of the texel index, so the page
                                      * is 16 x 256x256 = 2 MB. menu.tga goes
                                      * to slot 15; models use slot 0. */
#define MK4_TEX_SLOT_TEXELS 0x10000u

/* The engine allocates texture slots out of a sixteen-entry occupancy table at
 * 0x00ab4e00 (u16 per slot, non-zero = taken), scanning from the cursor at
 * 0x00ab4e74. Anything this backend preloads into the page has to be marked
 * there or LoadGeoAsset_Textures will hand the same slot to the first .geo it
 * reads and overwrite it. */
static int s_texMenuLoaded;

static void MK4_TexSlotReserve(unsigned slot)
{
    if (slot < MK4_TEX_SLOTS)
        *(unsigned short *)MK4_VA(unsigned short, 0x00ab4e00u + slot * 2u) = 0xffff;
}

/* Called from MK4_EngineStateInit, AFTER the engine has finished setting up -
 * its own init clears this table, so claiming during video init is wiped. On
 * a diagnostic scene the page is entirely this backend's, so every slot is
 * claimed; on the real frame path only the two it actually staged. */
void MK4_NativeVideoClaimTexSlots(void)
{
    unsigned s;

    if (getenv("MK4_SCENE") || getenv("MK4_TEX_SOLID") || getenv("MK4_TEX_ROWS")) {
        for (s = 0; s < MK4_TEX_SLOTS; s++)
            MK4_TexSlotReserve(s);
        return;
    }
    /* On the real frame path slot 0 belongs to the ENGINE - AppInit_Misc7
     * loads its font there, which is what the original does - so only the
     * menu staging is claimed. */
    if (s_texMenuLoaded)
        MK4_TexSlotReserve(15);
}
#define MK4_LUT_VA    0x01300000u     /* 16 x 128 KB shading pages, above it */
#define MK4_ENTRIES_VA 0x00f50000u    /* DrawEntry staging (g_dualC + 4) */

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

/* The renderer-mode globals are written AT THEIR VA, not through the
 * same-named C variable: every engine TU is arena-aliased now, so Renderer_GetMode
 * and DrawScene read the arena. Writing the C variable instead leaves the mode
 * at 0 and nothing dispatches - which is exactly what a half-aliased build
 * looks like from the outside (a frame that runs and draws nothing). */
#define MK4_MODE_CUR_VA      0x004f4b3cu   /* g_currentRendererMode */
#define MK4_MODE_CLAMPED_VA  0x004f4b38u   /* g_clampedRendererMode */

static int env_int(const char *name, int dflt)
{
    const char *v = getenv(name);
    return v ? (int)strtol(v, NULL, 0) : dflt;
}

/* --- the BeginFrame hook: hand the rasterisers their framebuffer ---------- */
void Renderer5_BeginFrame_SW_FS_Hi(int flag, int *base, int *pitch, int *unused)
{
    (void)flag;
    /* On Windows this LOCKS a DirectDraw back buffer, which the flip leaves
     * undefined - so the engine redraws the whole frame every time and never
     * clears. Here the framebuffer persists, so successive frames accumulate:
     * a menu sliding in leaves a copy at every position it passed through.
     * Clearing on entry is what the surface lock effectively gives. */
    memset(MK4_VA(void, MK4_FB_VA), 0, (unsigned)(s_w * s_h * 2));
    if (base)   *base  = (int)MK4_FB_VA;      /* a VA - the seam translates */
    if (pitch)  *pitch = s_w * 2;             /* RGB-555, 2 bytes per pixel */
    if (unused) *unused = 0;
}

/* BeginFrame hardcodes the viewport size per mode - 320x240 for mode 5, which
 * is the mode FlushDrawQueue's software path requires. But the projection adds
 * the screen centre as 0x140 / 0xf0 and Helper_DrawCursor's envelope rejects
 * x > 0x280 / y > 0x1e0, i.e. the engine's screen is 640x480. Left at 320x240
 * the rasterisers clip against half the frame while the pitch is for the full
 * one, so rows smear. Re-arm the size (SetViewport is engine code) right after
 * BeginFrame. */
extern void SetViewport(int x, int y, int w, int h);

/* The framebuffer's real geometry, for BeginFrame's viewport call. See the
 * MK4_ARENA block in src/engine/render.c. */
void MK4_NativeVideoViewportSize(int *w, int *h)
{
    if (w) *w = s_w;
    if (h) *h = s_h;
}

void MK4_NativeVideoArmViewport(void)
{
    SetViewport((int)MK4_FB_VA, s_w * 2, s_w, s_h);
}

/* Same, MINUS the queue reset. SetViewport also does g_drawQueueSize = 0, so
 * calling it between the emit and the draw stage throws the frame away - which
 * is exactly what happened the first time this was needed. The base and pitch
 * are per-DISPATCH scratch the emit path consumes, so they do need re-arming
 * there; the queue must not. */
void MK4_NativeVideoRearmFB(void)
{
    *(int *)MK4_VA(int, 0x00f85b50u) = (int)MK4_FB_VA;  /* g_viewportX = base  */
    *(int *)MK4_VA(int, 0x00f85b54u) = s_w * 2;         /* g_viewportY = pitch */
    *(int *)MK4_VA(int, 0x004ffd44u) = s_w;             /* g_viewportW */
    *(int *)MK4_VA(int, 0x004ffd48u) = s_h;             /* g_viewportH */
}

/* --- one-time setup ------------------------------------------------------ */
void MK4_NativeVideoInit(void)
{
    unsigned int k;
    unsigned char scale[16][32];
    int mode = env_int("MK4_VIDEO_MODE", 5);

    s_w = env_int("MK4_VIDEO_W", 640);
    s_h = env_int("MK4_VIDEO_H", 480);

    *(int *)MK4_VA(int, MK4_MODE_CUR_VA) = mode;
    *(int *)MK4_VA(int, MK4_MODE_CLAMPED_VA) = mode;

    memset(MK4_VA(void, MK4_FB_VA), 0, (unsigned)(s_w * s_h * 2));

    /* COSINE table - 4096 entries of cos * 2^28, indexed by BAM (0x1000 =
     * 2 PI), rounded half up. Read AppInit_PostJoy at 0x4b5a30: it is `fcos`,
     * not fsin, the scale is pow(2, 28) from the pair of doubles at 0x4d29d0
     * / 0x4d29d8, the step is 2 PI / 4096 at 0x4d29e0, and the `fsub` of the
     * -0.5 at 0x4d29e8 is the round-half-up.
     *
     * This was seeded with SIN for a long time, and the difference only shows
     * on a screen that goes through the camera transform. Work
     * BuildRotMatrix_OrderC through by hand for a ZERO angle triple: every
     * element is a product of two table reads, so tab[0] must be 1.0 for the
     * result to be the identity - mat[0] = (sz*sy)>>12, mat[4], mat[8] all
     * need it. With sin, tab[0] = 0 and a zero-angle camera came out as a
     * spurious 90 degree turn, [0 0 -4096 | 0 4096 0 | 4096 0 0], which is
     * exactly what MK4_TRACE_MAT reported on the character select. With cos
     * it is the identity, and a quarter turn about Y gives the clean
     * [0 0 4096 | 0 4096 0 | -4096 0 0]. */
    for (k = 0; k < 4096u; k++) {
        double a = (double)k * 6.283185307179586 / 4096.0;
        *(int *)MK4_VA(int, MK4_SIN_VA + k * 4) =
            (int)(cos(a) * 268435456.0 - (-0.5));
    }
    /* channel-average table: the original (BuildSortKeyLUT tail) fills
     * 0x300 entries even though three 5-bit channels sum to at most 93 */
    for (k = 0; k < 0x300u; k++)
        *(unsigned char *)MK4_VA(unsigned char, MK4_DIV3_VA + k) = (unsigned char)(k / 3);
    /* depth key -> bucket: the ORIGINAL's formula, from BuildSortKeyLUT
     * (0x4bf290): LUT[k] = k / (k*31/65536 + 1), truncated - hyperbolic
     * compression of the 16-bit key into ~0..2047 buckets, monotonic, with
     * resolution biased near.
     *
     * The previous seed here was clamp(k - 0x100, 0, 0x3ff). Same ORDER, but
     * it crushed every depth beyond 1279 into bucket 1023 - and a fight
     * arena's measured z runs 256..3072 with median 1789, so MOST of a
     * stage's triangles shared one bucket. A counting sort is stable, so
     * those all painted in EMISSION order, not depth order: chaotic overdraw
     * on every far surface, which reads on screen as streaky noise. The
     * fighters (z < ~1000) sorted fine, which is why the character gate
     * never caught it. Exact constants read from the image at 0x4d2a50/58/60:
     * 31.0, 1/65536, -1.0. */
    for (k = 0; k < 0x10000u; k++) {
        double v = (double)k / ((double)k * 31.0 / 65536.0 + 1.0);
        *(unsigned short *)MK4_VA(unsigned short, MK4_ZSORT_VA + k * 2) =
            (unsigned short)(int)v;
    }
    /* 16 shading pages: the ORIGINAL's builder, from Helper_PaletteInit
     * (0x4bf0c0), 1555 mode - the direction BuildSortKeyLUT(0) picks at
     * boot. Page p scales each 5-bit channel by (p+1)/16 through
     * ramp[v] = (v*(p+1)) >> 4, entries 0..0x7fff only; the top half of
     * every page stays ZERO (the original rep-stosd-clears the whole
     * region first), so a texel with bit 15 set looks up black. The
     * previous seed here scaled by p/15 and preserved bit 15 - close, but
     * an invention; see feedback_synthetic_seeds_are_suspects. */
    for (k = 0; k < 16u; k++) {
        unsigned int t;
        unsigned short *page = (unsigned short *)MK4_VA(unsigned short,
                                   MK4_LUT_VA + k * 0x20000u);
        unsigned int L;
        for (L = 0; L < 32u; L++)
            scale[k][L] = (unsigned char)((L * (k + 1)) >> 4);
        for (t = 0; t < 0x8000u; t++)
            page[t] = (unsigned short)(
                        ((unsigned)scale[k][(t >> 10) & 0x1f] << 10)
                      | ((unsigned)scale[k][(t >> 5) & 0x1f] << 5)
                      | (unsigned)scale[k][t & 0x1f]);
        for (t = 0x8000u; t < 0x10000u; t++)
            page[t] = 0;
    }
    /* Texture + shading-LUT bases. These are ARENA-ALIASED globals in the
     * render TUs (see alias_globals.py), so they must be written at their VA
     * here too - writing the same-named weak C variable would set a different
     * location and the rasterisers would read a null texture base. That is
     * exactly what crashed ScanlineTexBlit on the first attempt. */
    *(unsigned int *)MK4_VA(unsigned int, 0x00f85b34u) = MK4_TEX_VA;  /* 1400 */
    *(unsigned int *)MK4_VA(unsigned int, 0x00f4d028u) = MK4_LUT_VA;  /* 1340 */
    /* Pixel format, which is TryInitRenderer's to publish and therefore this
     * backend's: non-zero means 5-6-5, zero means 5-5-5. Everything here is
     * 5-5-5 - the framebuffer, MK4_PalBlit555, the .tga texels - but the flag
     * ships as 0xffffffff in .data, and left that way Helper_TexUpload folds
     * every uploaded page to 5-6-5 on the way in. The blitters then read those
     * texels back as 5-5-5, which reads as a green cast over the whole page. */
    *(unsigned int *)MK4_VA(unsigned int, 0x004ffd4cu) = 0;           /* 5-5-5 */
    /* The real menu art if it has been extracted, else a placeholder page.
     *
     * `c:\source\mk4\win\menu.tga` in FILESYS.DAT is a 256x256 16-bit TGA -
     * 1-5-5-5 little-endian, which IS the engine's texture format, so the
     * pixels go in as-is. TGA stores rows bottom-up unless bit 5 of the image
     * descriptor says otherwise, and this one does not, so the rows are
     * flipped on the way in.
     *
     * Note this is the SHARED texture page: 0xf85b34 is the one base every
     * blit reads, and the game refills it per screen. Loading the menu art
     * here is right for the menu and will need to become per-screen once
     * more of the asset path is converted.
     *
     * SUPERSEDED on the real frame path: AppInit_Misc1 is converted now, and
     * it does this load itself through FILESYS and Helper_TexUpload - and
     * then paints the cursor bars this copy knows nothing about. What is left
     * here is the placeholder page for the smoke scenes and the s_texMenuLoaded
     * flag that decides whether slot 15 is reserved against the first .geo. */
    {
        /* Only on the real frame path. The MK4_SCENE smoke scenes (rect, .geo)
         * stage their own content and the rect one in particular reads this
         * page directly, so replacing its bright placeholder with menu.tga -
         * which is 69% black - would just darken a test picture. */
        FILE *tf = (getenv("MK4_SCENE") || getenv("MK4_TEX_SOLID")
                    || getenv("MK4_TEX_ROWS")) ? NULL
                                       : fopen("build/assets/menu.tga", "rb");
        int loaded = 0;

        if (tf) {
            unsigned char hdr[18];

            if (fread(hdr, 1, sizeof hdr, tf) == sizeof hdr &&
                hdr[2] == 2 && hdr[16] == 16 &&
                (hdr[12] | (hdr[13] << 8)) == 256 &&
                (hdr[14] | (hdr[15] << 8)) == 256) {
                unsigned char row[256 * 2];
                int y;

                /* Slot 15, which is where AppInit_Misc1 uploads it -
                 * Helper_TexUpload's destination index is (slot << 16) | (y << 8) | x,
                 * so the menu font lives 15 * 64K texels into the page. */
                unsigned base = MK4_TEX_VA + 15u * MK4_TEX_SLOT_TEXELS * 2u;

                fseek(tf, 18 + hdr[0], SEEK_SET);       /* skip the ID field */
                for (y = 0; y < 256; y++) {
                    if (fread(row, 1, sizeof row, tf) != sizeof row)
                        break;
                    memcpy(MK4_VA(void, base + (unsigned)(255 - y) * 512u),
                           row, sizeof row);
                }
                loaded = (y == 256);
            }
            fclose(tf);
        }
        s_texMenuLoaded = loaded;
        if (loaded) {
            SDL_Log("native video: menu.tga loaded into the texture page");
        } else {
            /* MK4_TEX_SOLID=1 fills the page with one colour. It is a
             * diagnostic, and a decisive one: with it the rect scene renders
             * 61800 pixels of pure red, which proves ScanlineTexBlit reads
             * this page, while the menu barely changes - so the menu's panels
             * are drawn by a flat/blended branch and only its TEXT samples the
             * texture. */
            unsigned short fill = getenv("MK4_TEX_SOLID")
                                 ? (unsigned short)0x7c00u   /* solid red */
                                 : 0;
            /* MK4_TEX_ROWS=1 encodes the texture ROW in every texel, so the
             * rendered colour says which texture row each output pixel sampled.
             * A solid fill cannot show that - a uniform texture looks right at
             * any stride - which is exactly the blind spot MK4_TEX_SOLID has. */
            int rows = getenv("MK4_TEX_ROWS") != NULL;

            for (k = 0; k < 0x10000u; k++)   /* placeholder 256x256 RGB-555 */
                *(unsigned short *)MK4_VA(unsigned short, MK4_TEX_VA + k * 2) =
                    rows ? (unsigned short)((((k >> 8) & 0x1f) << 10) |
                                            ((((k >> 8) >> 5) & 0x1f) << 5))
                    : fill ? fill
                           : (unsigned short)((((k >> 4) & 0x1f) << 10) |
                                              ((k & 0x1f) << 5) | 0x10);
            SDL_Log("native video: no build/assets/menu.tga - placeholder page");
        }
    }

    /* MK4_GAMMA overrides the game's stored value for a run; otherwise the
     * GRAPHICS screen's own setting drives it through Helper_RendererPostInit. */
    { const char *g = getenv("MK4_GAMMA");
      extern void MK4_PalSetGammaRaw(int);
      if (g) { MK4_PalSetGammaRaw((int)strtol(g, NULL, 0));
               SDL_Log("native video: gamma override %s (diagnostic; the "
                       "game's own range is 2..0x62)", g); } }
    SDL_Log("native video: mode=%d %dx%d, fb@VA 0x%x, tables seeded "
            "(sin/div3/zsort/shading)", mode, s_w, s_h, MK4_FB_VA);
}

/* --- a scene source, while the game logic that fills the queue is unconverted
 * ------------------------------------------------------------------------
 * The engine fills its draw queue from the scene graph (RenderSceneNode, still
 * naked) driven by the game FSM (GameStateMachine, still naked). Until those
 * land, MK4_SCENE=rect submits a few primitives through the engine's OWN
 * enqueue (Helper_DrawCursor), so the frame exercises the real path:
 *   enqueue -> FlushDrawQueue's counting sort -> dispatch -> rasterisers.
 * This is a scene SOURCE, not a renderer: every pixel is drawn by engine code.
 */
extern void Helper_DrawCursor(void *entry);

static void put16(unsigned char *e, int off, int v)
{
    *(short *)(e + off) = (short)v;
}

void MK4_NativeSceneRects(int frame)
{
    static unsigned char entry[0x1c];
    int i;
    int dx = frame % 40;
    for (i = 0; i < 4; i++) {
        int x0 = 40 + i * 90 + dx, y0 = 60 + i * 40;
        int x1 = x0 + 150,         y1 = y0 + 130;
        memset(entry, 0, sizeof entry);
        put16(entry, 0x00, x0);  put16(entry, 0x02, y0);   /* v0 */
        put16(entry, 0x04, x1);  put16(entry, 0x06, y0);   /* v1 */
        put16(entry, 0x08, x1);  put16(entry, 0x0a, y1);   /* v2 */
        entry[0x0c] = 0;   entry[0x0d] = 0;                /* u0,v0 */
        entry[0x0e] = 80;  entry[0x0f] = 50;
        entry[0x10] = 80;  entry[0x11] = 50;
        put16(entry, 0x12, 0x180 + i * 8);                 /* depth key */
        put16(entry, 0x14, 0x7fff);                        /* colour */
        put16(entry, 0x1a, 0x20);                          /* RECT */
        Helper_DrawCursor(entry);
    }
}

/* --- a real .geo character, drawn by the engine's own emitter -------------
 * MK4_SCENE=<path>.geo loads a character asset into the arena and hands each
 * of its mesh blocks to DrawMeshBlock - engine code, co-exec verified - which
 * projects, shades, backface-culls and enqueues through Helper_DrawCursor.
 * The block layout is decoded in tools/geo_mesh.py: ofs_a / ofs_b at block+4 /
 * block+8 are relative TO THEIR OWN FIELD, so loading the file verbatim keeps
 * every offset valid. Only type-1 blocks are drawn; type-0 is a parallel
 * LOD/variant set that would render on top of itself. */
#define MK4_GEO_VA  0x01500000u

extern void DrawMeshBlock(int block, int a1, int a2);

static int s_geoBlocks[256], s_geoNBlocks, s_geoTris[256];

int MK4_NativeSceneGeoLoad(const char *path)
{
    FILE *f = fopen(path, "rb");
    unsigned char *base = (unsigned char *)MK4_VA(unsigned char, MK4_GEO_VA);
    unsigned int tex, o;
    long n;
    if (!f) { SDL_Log("scene: cannot open %s", path); return 0; }
    fseek(f, 0, SEEK_END); n = ftell(f); fseek(f, 0, SEEK_SET);
    if (fread(base, 1, (size_t)n, f) != (size_t)n) { fclose(f); return 0; }
    fclose(f);
    if (base[0] != '0' || base[1] != '.' || base[2] != '1' || base[3] != 'v') {
        SDL_Log("scene: %s is not a .geo", path); return 0; }
    tex = *(unsigned int *)(base + 4);
    s_geoNBlocks = 0;
    for (o = 0x0c; o + 16 <= tex && s_geoNBlocks < 256; o += 16) {
        unsigned short typ = *(unsigned short *)(base + o);
        unsigned short cnt = *(unsigned short *)(base + o + 2);
        int a = *(int *)(base + o + 4), b = *(int *)(base + o + 8);
        if ((typ != 0 && typ != 1) || cnt == 0) break;
        if (o + 4 + (unsigned)a >= tex || o + 8 + (unsigned)b >= tex) break;
        if (typ == 1) {
            s_geoTris[s_geoNBlocks] =
                (int)(MK4_GEO_VA + o + 12 + (unsigned)*(int *)(base + o + 12));
            s_geoBlocks[s_geoNBlocks++] = (int)(MK4_GEO_VA + o);
        }
    }
    /* the .geo texture half decodes to one 256x256 RGB-555 atlas; the raw dump
     * lives next to the asset (tools/geo_decode.py FILE 0 --raw out.bin) */
    {
        char tex_path[512];
        size_t L = strlen(path);
        FILE *tf;
        strncpy(tex_path, path, sizeof tex_path - 1);
        tex_path[sizeof tex_path - 1] = 0;
        if (L > 8 && strcmp(path + L - 8, "_geo.geo") == 0)
            strcpy(tex_path + L - 8, "_tex.bin");
        tf = fopen(tex_path, "rb");
        if (tf) {
            size_t got = fread(MK4_VA(void, MK4_TEX_VA), 1, 256u * 256u * 2u, tf);
            fclose(tf);

            SDL_Log("scene: texture atlas %lu bytes from %s",
                    (unsigned long)got, tex_path);
        } else {
            SDL_Log("scene: no %s - keeping the placeholder texture", tex_path);
        }
    }
    SDL_Log("scene: %s, %ld bytes, %d type-1 mesh blocks", path, n, s_geoNBlocks);
    return s_geoNBlocks > 0;
}

/* Neither emitter writes a draw entry's u/v bytes; a separate setup pass fills
 * the entry array at g_dualC+4 from the block's per-triangle table, in the same
 * order. Reproduced here so the rasterisers see real texture coordinates. */
static void geo_fill_uvs(int blk)
{
    unsigned char *tri = (unsigned char *)MK4_VA(unsigned char, (unsigned)s_geoTris[blk]);
    unsigned char *e = (unsigned char *)MK4_VA(unsigned char, MK4_ENTRIES_VA);
    unsigned short cnt = *(unsigned short *)MK4_VA(unsigned short,
                             (unsigned)s_geoBlocks[blk] + 2);
    int k, j;
    for (k = 0; k < (int)cnt; k++, tri += 8, e += 0x1c)
        for (j = 0; j < 6; j++)
            e[0xc + j] = tri[2 + j];
}

void MK4_NativeSceneGeo(int frame)
{
    double a = frame * 0.02, c = cos(a), sn = sin(a);
    int m[9], i;
    /* Q12 spin about Y; the Y row is NEGATED because model +Y is up and the
       screen's is down (the projection only adds the 0xf0 centre). */
    m[0] = (int)(c * 0x1000);   m[1] = 0;       m[2] = (int)(sn * 0x1000);
    m[3] = 0;                   m[4] = -0x1000; m[5] = 0;
    m[6] = (int)(-sn * 0x1000); m[7] = 0;       m[8] = (int)(c * 0x1000);
    for (i = 0; i < 9; i++)
        *(short *)MK4_VA(short, 0x007af990u + (unsigned)i * 2) = (short)m[i];

    *(int *)MK4_VA(int, 0x007af9a4u) = 0;        /* g_vtxTransX */
    *(int *)MK4_VA(int, 0x007af9a8u) = -0x0d;    /* g_vtxTransY: model centre */
    *(int *)MK4_VA(int, 0x007af9acu) = 0x280;    /* g_vtxTransZ: camera dist  */
    *(int *)MK4_VA(int, 0x007af92cu) = 0;        /* g_inLoopStep: emitter gate */
    *(int *)MK4_VA(int, 0x0054204cu) = MK4_ENTRIES_VA - 4;   /* g_dualC */
    *(int *)MK4_VA(int, 0x00543aa8u) = 1;        /* g_menuRestoreSlot: mesh path */
    *(int *)MK4_VA(int, 0x00ab4e60u) = 0x200;    /* no depth attenuation */
    *(int *)MK4_VA(int, 0x00ab4d9cu) = 0;        /* sort-key bias */
    *(int *)MK4_VA(int, 0x00ab4e28u) = 0;        /* no alt camera */

    /* Lighting. MatVec2Multiply (called by DrawMeshBlock) turns these into
     * the g_vtxLight0 and g_vtxLight1 vectors, which TransformVertex then reads per vertex.
     * The vertex colour drives the SHADE, and the shade picks a 128 KB page of
     * the shading LUT (level = average channel >> 4): page 15 leaves the texel
     * alone, page 0 is black - so a dim base renders the model completely
     * black, which is exactly what an unseeded colour does. */
    *(int *)MK4_VA(int, 0x007af9c0u) = 0x0180;   /* g_lightMat00 */
    *(int *)MK4_VA(int, 0x007af9c4u) = 0x0080;
    *(int *)MK4_VA(int, 0x007af9c8u) = 0x0040;
    *(int *)MK4_VA(int, 0x007af9ccu) = 0x0060;   /* g_dispatchSave1627 */
    *(int *)MK4_VA(int, 0x007af9d0u) = 0x0140;
    *(int *)MK4_VA(int, 0x007af9d4u) = 0x00a0;
    *(short *)MK4_VA(short, 0x007af9f0u) = 0x6318;  /* g_vtxColorPrev  24,24,24 */
    *(short *)MK4_VA(short, 0x007af9fcu) = 0x6318;  /* g_vtxColor   */
    *(short *)MK4_VA(short, 0x007af9f8u) = 0x6318;  /* g_vtxColorCopy */
    *(short *)MK4_VA(short, 0x007af9fau) = 0x6318;  /* g_vtxColorSaved */
    /* the six RGB scales are PACKED BYTES at 0x7af9f2..f7 - byte writes only */
    *(unsigned char *)MK4_VA(unsigned char, 0x007af9f2u) = 0x30;
    *(unsigned char *)MK4_VA(unsigned char, 0x007af9f3u) = 0x18;
    *(unsigned char *)MK4_VA(unsigned char, 0x007af9f4u) = 0x40;
    *(unsigned char *)MK4_VA(unsigned char, 0x007af9f5u) = 0x20;
    *(unsigned char *)MK4_VA(unsigned char, 0x007af9f6u) = 0x50;
    *(unsigned char *)MK4_VA(unsigned char, 0x007af9f7u) = 0x28;

    for (i = 0; i < s_geoNBlocks; i++) {
        geo_fill_uvs(i);
        DrawMeshBlock(s_geoBlocks[i], 0, 0);     /* the .geo MAIN path */
    }
    if (getenv("MK4_DUMP_QUEUE")) {
        unsigned q = *(unsigned *)MK4_VA(unsigned, 0x00f85b40u);
        unsigned k;
        SDL_Log("queue=%u  viewport base=0x%x pitch=%d w=%d h=%d", q,
                *(unsigned *)MK4_VA(unsigned, 0x00f85b50u),
                *(int *)MK4_VA(int, 0x00f85b54u),
                *(int *)MK4_VA(int, 0x004ffd44u),
                *(int *)MK4_VA(int, 0x004ffd48u));
        for (k = 0; k < q && k < 4; k++) {
            short *e = (short *)MK4_VA(short, 0x00f71310u + k * 0x1c);
            unsigned char *b = (unsigned char *)e;
            SDL_Log("  e%u v=(%d,%d)(%d,%d)(%d,%d) uv=%d,%d %d,%d %d,%d key=%d col=%04x typ=%04x",
                    k, e[0],e[1],e[2],e[3],e[4],e[5],
                    b[0xc],b[0xd],b[0xe],b[0xf],b[0x10],b[0x11],
                    (int)(unsigned short)e[9], (unsigned)(unsigned short)e[10],
                    (unsigned)(unsigned short)e[13]);
        }
    }
}

/* Dump one 256x256 texture page as an RGB PPM - the font atlas lives in
 * page 0 and the menu art in page 15. Diagnostic only. */
int MK4_NativeDumpTexPage(int slot, const char *path)
{
    unsigned int base = *(unsigned int *)MK4_VA(unsigned int, 0x00f85b34u);
    FILE *f = fopen(path, "wb");
    int x, y, nz = 0;

    if (!f) return 0;
    fprintf(f, "P6\n256 256\n255\n");
    for (y = 0; y < 256; y++)
        for (x = 0; x < 256; x++) {
            unsigned int addr = base + ((unsigned)slot * 65536u
                                        + (unsigned)y * 256u + (unsigned)x) * 2u;
            unsigned short t = *(unsigned short *)MK4_VA(unsigned short, addr);
            unsigned char rgb[3];
            if (t) nz++;
            rgb[0] = (unsigned char)(((t >> 10) & 0x1f) << 3);
            rgb[1] = (unsigned char)(((t >> 5) & 0x1f) << 3);
            rgb[2] = (unsigned char)((t & 0x1f) << 3);
            fwrite(rgb, 1, 3, f);
        }
    fclose(f);
    SDL_Log("atlas: page %d -> %s (%d non-zero texels)", slot, path, nz);
    return 1;
}

/* Helper_RendererPostInit(gamma): the GRAPHICS screen's GAMMA row calls this
 * on every step. The original re-applies a Win32 gamma ramp; this backend
 * applies the same value in its final blit. Previously a weak stub, which is
 * why the game's own brightness control did nothing natively. */
void Helper_RendererPostInit(int gamma)
{
    extern void MK4_PalSetGamma(int);
    MK4_PalSetGamma(gamma);
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
    /* Through the shading table, room for a loaded .geo above it, and then
     * the arena-resident scratch stack (mem_model.h) that carries packed
     * pointers to what were stack locals in the original. */
    /* ... and the CRT-heap window above it (engine_crtheap.c), which the
     * animation pack's single 1.1 MB allocation lives in. */
    return (0x01800000u - 0x00400000u);
}
