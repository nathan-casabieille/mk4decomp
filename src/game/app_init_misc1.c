/**
 * AppInit_Misc1 (0x004b6180) and its gradient stamper PaletteFillLineHybrid
 * (0x004b5ce0): the menu texture page, and the pulsing selection bar the
 * engine PAINTS INTO THAT PAGE ITSELF at boot.
 *
 * The port had the first half of this function open-coded in the SDL backend
 * (engine_video.c reads build/assets/menu.tga straight into slot 15) and the
 * second half nowhere at all, which is why the menu drew but its selection
 * cursor did not. DrawMenu's cursor quad is a RECT sampling texture slot 15,
 * column `pulse`, rows 0x50..0x5b - and rows 0x50..0x5b of menu.tga are black.
 * They are meant to be, because they are not artwork: this function draws 32
 * three-pixel-wide vertical gradient bars into them, one per pulse phase, and
 * only then uploads the page. With no bars the blitter samples zeros, and a
 * zero texel is the transparent value, so the cursor rendered as nothing.
 *
 * The link between the two is exact: the loop steps x by 3 from 1 to 94, and
 * DrawMenu picks its column with `pulse = g_menuExtraDelta * 3 + 1` over a
 * 0..0x1f counter - the same 32 columns.
 *
 * PaletteFillLineHybrid(x, y, dx, dy, r0,g0,b0, r1,g1,b1) draws into the
 * 256 x 256 16bpp staging buffer at 0x00f4d050 that Helper_TexUpload copies
 * out of, indexing it as (y << 8) | x with both coordinates masked to 8 bits.
 * It stamps a 3x3 cap of the start colour at (x,y) and one of the end colour
 * at (x+dx,y+dy) - caps only where the texel is still clear, so a bar already
 * drawn is never overpainted - then walks the major axis interpolating the
 * colour, writing the texel plus one neighbour either side across the minor
 * axis for a three-pixel-thick line.
 *
 * Colours arrive as floats in 0..31 and are packed RGB-555 with the channels
 * rounded half up: the original converts with `fsub -0.5` ahead of MSVC's
 * truncating __ftol, which is round-half-up spelled for an x87 stack.
 *
 * The matching build keeps the naked transcription below. PaletteFillLineHybrid
 * is only converted on the native side: symbols.yaml names
 * src/engine/palette_fill_line_hybrid.c as its destination, but that file does
 * not define it yet, so the matching build still takes it from the original
 * bytes and this twin is the first real body it has had.
 */

#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern int  FSYS_fopen(const char *path, const char *mode);
extern int  FSYS_fseek(int fh, unsigned int offset, int whence);
extern int  FSYS_fread(void *buf, unsigned int sz, unsigned int n, int fh);
extern int  FSYS_fclose(int fh);
extern void Helper_TexUpload(unsigned int slot, int x, int y, int w, int h);

/* MapVirtualKeyA(vk, MAPVK_VK_TO_CHAR) - the one Win32 call in this function,
 * supplied by the platform layer the way the rest of USER32 is. */
extern int MK4_MapVirtualKeyChar(int vk);

/* The staging buffer Helper_TexUpload reads from, as texels. */
#define g_texStage     ((unsigned short *)MK4_VA(unsigned short, 0x00f4d050u))
/* 256 key-label pointers, indexed by virtual-key code. */
#define g_keyNameTable ((unsigned int *)MK4_VA(unsigned int, 0x004f5398u))

#define MENU_TGA_PATH  ((const char *)MK4_PTR(0x004f613cu))   /* c:\source\mk4\win\menu.tga */
#define MODE_RB        ((const char *)MK4_PTR(0x004d505cu))   /* "rb" */

/* x87 truncation plus a -0.5 bias is round-half-up. */
static int pal_round(float v)
{
    return (int)((double)v - (-0.5));
}

static unsigned short pal_pack(float r, float g, float b)
{
    unsigned int c;

    c = (unsigned int)(pal_round(r) & 0x1f);
    c = (c << 5) | (unsigned int)(pal_round(g) & 0x1f);
    c = (c << 5) | (unsigned int)(pal_round(b) & 0x1f);
    return (unsigned short)c;
}

void PaletteFillLineHybrid(int x, int y, int dx, int dy,
                           float r0, float g0, float b0,
                           float r1, float g1, float b1)
{
    unsigned short *stage = g_texStage;
    int cs[3], ce[3];
    int rowa, rowb, k, i;
    int stepx, stepy, count;

    cs[0] = (x - 1) & 0xff;
    cs[1] = x & 0xff;
    cs[2] = (x + 1) & 0xff;
    ce[0] = (x + dx - 1) & 0xff;
    ce[1] = (x + dx) & 0xff;
    ce[2] = (x + dx + 1) & 0xff;

    /* the caps start one row above each endpoint and cover three rows */
    rowa = (y << 8) - 0x100;
    rowb = ((y + dy) << 8) - 0x100;

    for (k = 0; k < 3; k++) {
        int ra = rowa & 0xff00;
        int rb = rowb & 0xff00;

        for (i = 0; i < 3; i++)
            if (stage[ra | cs[i]] == 0)
                stage[ra | cs[i]] = pal_pack(r0, g0, b0);
        for (i = 0; i < 3; i++)
            if (stage[rb | ce[i]] == 0)
                stage[rb | ce[i]] = pal_pack(r1, g1, b1);
        rowa += 0x100;
        rowb += 0x100;
    }

    /* the longer delta picks the major axis; the caps above already covered
     * the degenerate case, so a non-positive span just stops here */
    if (dx < 1) {
        stepx = 0;
        stepy = 1;
        count = dy;
    } else {
        stepx = 1;
        stepy = 0;
        count = dx;
    }
    if (count <= 0)
        return;

    {
        int rowstep = stepy << 8;
        int row = y << 8;
        int cx = x, cy = y;
        float cr = r0, cg = g0, cb = b0;
        float dr = (r1 - r0) / (float)count;
        float dg = (g1 - g0) / (float)count;
        float db = (b1 - b0) / (float)count;

        while (count-- != 0) {
            unsigned short c = pal_pack(cr, cg, cb);
            int ybase = (cy & 0xff) << 8;
            int xcur = cx & 0xff;

            stage[ybase | xcur] = c;
            if (stepx != 0) {
                stage[((row - 0x100) & 0xff00) | xcur] = c;
                stage[((row + 0x100) & 0xff00) | xcur] = c;
            } else {
                stage[ybase | ((cx - 1) & 0xff)] = c;
                stage[ybase | ((cx + 1) & 0xff)] = c;
            }
            cx += stepx;
            cy += stepy;
            row += rowstep;
            cr += dr;
            cg += dg;
            cb += db;
        }
    }
}

void AppInit_Misc1(void)
{
    unsigned int *names = g_keyNameTable;
    unsigned char *dst;
    int fh, i, x;

    /* Give every key whose label is still the "." placeholder the character
     * its virtual-key code types. All of those entries point at the SAME one
     * character in .data, so the walk really does end up stamping a single
     * byte - that is the original's behaviour, not a transcription slip. */
    for (i = 0; i < 0x100; i++) {
        if (names[i] != 0) {
            char *s = (char *)MK4_PTR(names[i]);

            if (*s == '.')
                *s = (char)MK4_MapVirtualKeyChar(i);
        }
    }

    /* menu.tga is a 256x256 1-5-5-5 TGA, which IS the engine's texel format,
     * so its rows go in as they are read. The buffer fills BACKWARD because
     * the file stores rows bottom-up: reading the file's first row into the
     * buffer's last is the vertical flip. */
    fh = FSYS_fopen(MENU_TGA_PATH, MODE_RB);
    FSYS_fseek(fh, 0x12, 0);
    for (dst = (unsigned char *)MK4_VA(unsigned char, 0x00f6ce50u);
         dst >= (unsigned char *)MK4_VA(unsigned char, 0x00f4d050u);
         dst -= 0x200)
        FSYS_fread(dst, 0x200, 1, fh);
    FSYS_fclose(fh);
    Helper_TexUpload(0xf, 0, 0, 0x100, 0x100);

    /* 32 gradient bars at rows 0x50..0x59, columns 1, 4, 7 ... 94 - one per
     * value of DrawMenu's pulse counter. Each is dark blue at the top edge,
     * brightening to (31, i, i) at the middle row and fading back, so the
     * cursor sweeps red -> orange -> white as the counter runs. */
    i = 0;
    for (x = 1; x < 0x61; x += 3) {
        float t = (float)i * 5.0f * 0.2f;

        PaletteFillLineHybrid(x, 0x50, 0, 5, 0.0f, 0.0f, 1.0f, 30.0f, t, t);
        PaletteFillLineHybrid(x, 0x55, 0, 5, 30.0f, t, t, 0.0f, 0.0f, 1.0f);
        i++;
    }
    Helper_TexUpload(0xf, 0, 0, 0x100, 0x100);
}

#else   /* matching build: the original naked transcription */

#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b6180 (300b game.menu) - HUD font precache: trims dot-prefix names,
 *   opens font file, fread'd page-by-page into a backbuffer, then issues two
 *   matched draw passes via PaletteFillLineHybrid with float positions for each glyph.
 */
extern unsigned int g_dispatchSave529;
extern unsigned int g_dispatchSave528;
extern unsigned int g_dispatchVar40;
extern unsigned int g_dispatchSave526;
extern unsigned int g_dispatchSave525;
extern unsigned int g_dispatchSave524;
extern u16 g_texStripeBuf[];
extern unsigned int g_dispatchSave1348;
extern unsigned int g_iat_MapVirtualKeyA;
extern void FSYS_fclose(void);
extern void FSYS_fopen(void);
extern void FSYS_fread(void);
extern void FSYS_fseek(void);
extern void Helper_TexUpload(void);
extern void PaletteFillLineHybrid(void);

__declspec(naked) void AppInit_Misc1(void) {
    __asm {
        sub     esp, 8
        push    ebx
        mov     ebx, dword ptr [g_iat_MapVirtualKeyA]
        push    esi
        push    edi
        xor     edi, edi
        mov     esi, offset g_dispatchSave526
    L_hfp_namelp:
        mov     eax, [esi]
        test    eax, eax
        jz      short L_hfp_nameadv
        cmp     byte ptr [eax], 0x2e
        jne     short L_hfp_nameadv
        push    2
        push    edi
        call    ebx
        mov     ecx, [esi]
        mov     [ecx], al
    L_hfp_nameadv:
        add     esi, 4
        inc     edi
        cmp     esi, offset g_dispatchSave525
        jl      short L_hfp_namelp
        push    offset g_dispatchVar40
        push    offset g_dispatchSave524
        call    FSYS_fopen
        add     esp, 8
        mov     edi, eax
        push    0
        push    0x12
        push    edi
        call    FSYS_fseek
        add     esp, 0xc
        mov     esi, offset g_dispatchSave1348
    L_hfp_readlp:
        push    edi
        push    1
        push    0x200
        push    esi
        call    FSYS_fread
        sub     esi, 0x200
        add     esp, 0x10
        cmp     esi, offset g_texStripeBuf
        jge     short L_hfp_readlp
        push    edi
        call    FSYS_fclose
        add     esp, 4
        push    0x100
        push    0x100
        push    0
        push    0
        push    0x0f
        call    Helper_TexUpload
        add     esp, 0x14
        mov     dword ptr [esp + 0xc], 0
        mov     esi, 1
    L_hfp_glyph:
        fild    dword ptr [esp + 0xc]
        fmul    dword ptr [g_dispatchSave529]
        fmul    dword ptr [g_dispatchSave528]
        fstp    dword ptr [esp + 0x10]
        mov     edi, [esp + 0x10]
        push    edi
        push    edi
        push    0x41f00000
        push    0x3f800000
        push    0
        push    0
        push    5
        push    0
        push    0x50
        push    esi
        call    PaletteFillLineHybrid
        add     esp, 0x28
        push    0x3f800000
        push    0
        push    0
        push    edi
        push    edi
        push    0x41f00000
        push    5
        push    0
        push    0x55
        push    esi
        call    PaletteFillLineHybrid
        mov     edx, [esp + 0x34]
        add     esp, 0x28
        add     esi, 3
        inc     edx
        cmp     esi, 0x61
        mov     [esp + 0xc], edx
        jl      short L_hfp_glyph
        push    0x100
        push    0x100
        push    0
        push    0
        push    0x0f
        call    Helper_TexUpload
        add     esp, 0x14
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 8
        ret
    }
}

#endif  /* NON_MATCHING */
