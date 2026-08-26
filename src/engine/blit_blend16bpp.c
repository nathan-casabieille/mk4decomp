/**
 * BlitBlend16bpp - split out of five_block_dispatch_variants.c.
 *
 * The twin lives here so the native/WASM targets can link it:
 * five_block is 130k lines of mostly naked asm and native-full does not
 * compile it. The naked #else branch stays in five_block, so the matching
 * build is untouched and exactly one definition is active either way.
 */
#include "portable/ghidra_types.h"
#include "engine/scenegraph.h"
#include "game/tick.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_clipMinScratch (*(unsigned int *)MK4_VA(unsigned int, 0xf70f70u))
#define g_dispatchSave1345 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d040u))
#define g_dispatchSave1346 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d044u))
#define g_dispatchSave1357 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f4cu))
#define g_dispatchSave1358 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f50u))
#define g_dispatchSave1371 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f88u))
#define g_dispatchSave1373 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f90u))
#define g_dispatchSave1374 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f98u))
#define g_dispatchSave1377 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fa0u))
#define g_dispatchSave1378 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fa8u))
#define g_dispatchSave1380 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fb0u))
#define g_dispatchSave1381 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fb8u))
#define g_dispatchSave1383 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fc0u))
#define g_dispatchSave1387 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fd8u))
#define g_dispatchSave1400 (*(unsigned int *)MK4_VA(unsigned int, 0xf85b34u))
#define g_dispatchSave1403 (*(unsigned int *)MK4_VA(unsigned int, 0xf85b4cu))
#define g_dispatchSave1404 (*(unsigned int *)MK4_VA(unsigned int, 0xf85b58u))
#define g_dispatchSave1707 (*(unsigned int *)MK4_VA(unsigned int, 0xb2d008u))
#define g_dispatchSave1708 (*(unsigned int *)MK4_VA(unsigned int, 0xb2d00cu))
#define g_texturedTriVar (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd4cu))
#define g_viewportH (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd48u))
#define g_viewportW (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd44u))
#define g_viewportX (*(unsigned int *)MK4_VA(unsigned int, 0xf85b50u))
#define g_viewportY (*(unsigned int *)MK4_VA(unsigned int, 0xf85b54u))
#endif


#ifdef NON_MATCHING
/*
 * Portable C twin (path A). Faithful transcription of the naked branch below
 * PLUS the row-advance/exit tail that the matching build delegates to the
 * synth-filled stubs func_004c08d6 (row advance) / func_004c0911 (exit). The
 * original disassembly (orig bytes at 0x4c08d6/0x4c0911) supplied the tail.
 * Verified by seeded co-exec (tools/decomp/verify_scanline.py), not byte-match.
 *
 * 2-tap (2x2 box) textured blend blit: per output pixel it reads a dword (two
 * packed 565 texels) at the texture column and another a texture row below
 * (+0x200), vertically averages each packed pair, then horizontally adds the
 * two columns -> one output pixel. Two modes via g_texturedTriVar: masks
 * 0x7bef7bef/0xf7def7de (565) vs 0x3def3def/0x7bde7bde (555). The high texel of
 * the dword (bits 0xffff0000) gates transparency. Column = (1387>>16)&0xff,
 * V/page byte = (1374>>16)&0xff (layout-independent; see ScanlineTexBlit).
 *
 * The per-row column count (g_clipMinScratch) is seeded from edi (=w); the inner
 * loop overwrites edi with the dest pointer, so the loop-completion tail
 * (ColdLoopTail @0x4c08d0) reloads edi = g_dispatchSave1708 before each row
 * advance. (The w<=0 skip path goes straight to 0x4c08d6, edi already = w.)
 */
void BlitBlend16bpp(void)
{
    unsigned int eax, ebx, ecx, edx, esi, edi, ebp;

    ebx = g_viewportX;                          /* fb base */
    if (ebx == 0) return;
    ecx = g_dispatchSave1378;                   /* x0 */
    if ((int)ecx >= (int)g_viewportW) return;
    esi = g_dispatchSave1381;                   /* y0 */
    if ((int)esi >= (int)g_viewportH) return;
    eax = g_dispatchSave1380;                   /* x1 */
    if ((int)eax < 0) return;
    edx = g_dispatchSave1383;                   /* y1 */
    if ((int)edx < 0) return;
    eax -= ecx;                                 /* w */
    edx -= esi;                                 /* h */
    g_dispatchSave1708 = eax;
    g_dispatchSave1707 = edx;
    if ((int)eax < 1) return;
    if ((int)edx < 1) return;

    eax = g_dispatchSave1373 << 16;             /* U1fx */
    edx = g_dispatchSave1371 << 16;             /* Pfx */
    g_dispatchSave1373 = eax;
    eax = eax - edx;
    g_dispatchSave1371 = edx;
    ebp = g_dispatchSave1374;                   /* u0 */
    eax = (unsigned int)((int)eax / (int)g_dispatchSave1708);   /* gradX (/w) */
    edi = g_dispatchSave1377;                   /* Q */
    ebp <<= 16;  g_dispatchSave1374 = ebp;       /* u0fx */
    edi <<= 16;  g_dispatchSave1377 = edi;       /* Qfx */
    ebp = eax;                                  /* gradX */
    eax = edi;
    edi = g_dispatchSave1374;                   /* u0fx */
    g_dispatchSave1357 = ebp;                   /* gradX */
    eax = eax - edi;
    eax = (unsigned int)((int)eax / (int)g_dispatchSave1707);   /* gradY (/h) */
    g_dispatchSave1358 = eax;                   /* gradY */

    if ((int)ecx < 0) {                         /* left clip */
        edx = (unsigned int)((int)ebp * (int)ecx);
        edi = g_dispatchSave1371;
        edi = edi - edx;
        edx = g_dispatchSave1708;
        edx = edx + ecx;
        ecx = 0;
        g_dispatchSave1371 = edi;
        g_dispatchSave1708 = edx;
        g_dispatchSave1378 = ecx;
    }
    if ((int)esi < 0) {                         /* top clip */
        eax = (unsigned int)((int)eax * (int)esi);
        edx = g_dispatchSave1374;
        edx = edx - eax;
        eax = g_dispatchSave1707;
        eax = eax + esi;
        esi = 0;
        g_dispatchSave1374 = edx;
        g_dispatchSave1707 = eax;
        g_dispatchSave1381 = esi;
    }
    eax = g_viewportW;
    edx = g_dispatchSave1380;
    if (!((int)edx < (int)eax)) {               /* right clip */
        eax = eax - ecx;
        edi = eax;
        g_dispatchSave1708 = edi;
    } else {
        edi = g_dispatchSave1708;               /* w (column count) */
    }
    eax = g_viewportH;
    edx = g_dispatchSave1383;
    if (!((int)edx < (int)eax)) {               /* bottom clip */
        eax = eax - esi;
        g_dispatchSave1707 = eax;
    }
    eax = g_viewportY;
    eax = (unsigned int)((int)eax * (int)esi);  /* pitch*y0 */
    esi = g_dispatchSave1403;
    ebx = ebx + eax;                            /* fbbase + pitch*y0 */
    eax = g_dispatchSave1707;                   /* h */
    esi = esi & 0xf;
    ecx = ebx + ecx * 2;                        /* dest top-left */
    esi <<= 16;                                 /* sub-texel << 16 */
    g_dispatchSave1346 = ecx;
    g_dispatchSave1403 = esi;
    if ((int)eax <= 0) return;
    ebx = 2;                                    /* dest stride */

    for (;;) {
        /* row body (L_0781): esi = sub<<16 (carried/reloaded) */
        edx = ((g_dispatchSave1374 >> 16) & 0xff) << 8;  /* texpage/row byte */
        eax = g_dispatchSave1371;                        /* row U start */
        g_dispatchSave1387 = eax;
        edx = edx + esi;                                 /* + sub<<16 */
        g_dispatchSave1345 = ecx;                        /* dest ptr */
        g_clipMinScratch = edi;                          /* column count */
        edx = g_dispatchSave1400 + edx * 2;              /* tex row base */
        g_dispatchSave1404 = edx;
        if (g_texturedTriVar != 0) {                     /* mode != 0: 565 */
            if ((int)edi > 0) {
                do {
                    unsigned int col = ((unsigned int)((int)eax >> 16)) & 0xff;
                    ecx = *(unsigned int *)MK4_PTR(edx + col * 2);      /* tapA (2 px) */
                    if ((ecx & 0xffff0000u) != 0) {
                        eax = *(unsigned int *)MK4_PTR(edx + col * 2 + 0x200); /* tapB */
                        eax >>= 1;  ecx >>= 1;
                        eax &= 0x7bef7befu;  ecx &= 0x7bef7befu;
                        eax = (eax + ecx) & 0xf7def7deu;
                        eax >>= 1;
                        ecx = eax & 0xffff;
                        eax >>= 16;
                        ecx = ecx + eax;
                        *(unsigned short *)MK4_PTR(g_dispatchSave1345) = (unsigned short)ecx;
                        ebp = g_dispatchSave1357;
                        edx = g_dispatchSave1404;
                    }
                    ecx = g_clipMinScratch - 1;
                    eax = g_dispatchSave1387 + ebp;
                    edi = g_dispatchSave1345 + ebx;
                    g_clipMinScratch = ecx;
                    g_dispatchSave1387 = eax;
                    g_dispatchSave1345 = edi;
                } while ((int)ecx > 0);
            }
        } else {                                         /* mode == 0: 555 */
            if ((int)edi > 0) {
                do {
                    unsigned int col = ((unsigned int)((int)eax >> 16)) & 0xff;
                    ecx = *(unsigned int *)MK4_PTR(edx + col * 2);
                    if ((ecx & 0xffff0000u) != 0) {
                        eax = *(unsigned int *)MK4_PTR(edx + col * 2 + 0x200);
                        eax >>= 1;  ecx >>= 1;
                        eax &= 0x3def3defu;  ecx &= 0x3def3defu;
                        eax = (eax + ecx) & 0x7bde7bdeu;
                        eax >>= 1;
                        ecx = eax & 0xffff;
                        eax >>= 16;
                        ecx = ecx + eax;
                        *(unsigned short *)MK4_PTR(g_dispatchSave1345) = (unsigned short)ecx;
                        ebp = g_dispatchSave1357;
                        edx = g_dispatchSave1404;
                    }
                    ecx = g_clipMinScratch - 1;
                    eax = g_dispatchSave1387 + ebp;
                    edi = g_dispatchSave1345 + ebx;
                    g_clipMinScratch = ecx;
                    g_dispatchSave1387 = eax;
                    g_dispatchSave1345 = edi;
                } while ((int)ecx > 0);
            }
        }
        /* loop-completion tail (ColdLoopTail, 0x4c08d0): reload column count */
        edi = g_dispatchSave1708;                        /* w (the inner loop clobbered edi) */
        /* row advance (func_004c08d6) */
        ecx = g_dispatchSave1358;                        /* gradY */
        edx = g_dispatchSave1374;
        eax = g_dispatchSave1707;                        /* rows */
        esi = g_viewportY;                               /* pitch */
        edx = edx + ecx;                                 /* 1374 += gradY */
        ecx = g_dispatchSave1346;                        /* dest */
        eax = eax - 1;                                   /* rows-- */
        ecx = ecx + esi;                                 /* dest += pitch */
        g_dispatchSave1707 = eax;
        g_dispatchSave1374 = edx;
        g_dispatchSave1346 = ecx;
        if (!((int)eax > 0)) break;
        esi = g_dispatchSave1403;                        /* re-entry (0x4c077b): reload sub<<16 only */
    }
}
#else
/* the naked branch stays in five_block_dispatch_variants.c */
#endif
