/**
 * TexturedTriRasterizeShaded - split out of five_block_dispatch_variants.c.
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
#define g_clipMaxScratch (*(unsigned int *)MK4_VA(unsigned int, 0xf70f78u))
#define g_clipMinScratch (*(unsigned int *)MK4_VA(unsigned int, 0xf70f70u))
#define g_dispatchSave1335 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d014u))
#define g_dispatchSave1336 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d018u))
#define g_dispatchSave1337 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d01cu))
#define g_dispatchSave1338 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d020u))
#define g_dispatchSave1339 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d024u))
#define g_dispatchSave1340 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d028u))
#define g_dispatchSave1341 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d02cu))
#define g_dispatchSave1342 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d030u))
#define g_dispatchSave1343 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d034u))
#define g_dispatchSave1345 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d040u))
#define g_dispatchSave1346 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d044u))
#define g_dispatchSave1359 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f54u))
#define g_dispatchSave1360 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f58u))
#define g_dispatchSave1361 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f5cu))
#define g_dispatchSave1362 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f60u))
#define g_dispatchSave1363 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f64u))
#define g_dispatchSave1364 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f68u))
#define g_dispatchSave1365 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f6cu))
#define g_dispatchSave1366 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f74u))
#define g_dispatchSave1367 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f7cu))
#define g_dispatchSave1370 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f84u))
#define g_dispatchSave1371 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f88u))
#define g_dispatchSave1374 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f98u))
#define g_dispatchSave1378 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fa8u))
#define g_dispatchSave1381 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fb8u))
#define g_dispatchSave1384 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fc8u))
#define g_dispatchSave1385 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fccu))
#define g_dispatchSave1386 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fd4u))
#define g_dispatchSave1387 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fd8u))
#define g_dispatchSave1389 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fdcu))
#define g_dispatchSave1390 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fe0u))
#define g_dispatchSave1393 (*(unsigned int *)MK4_VA(unsigned int, 0xf712f8u))
#define g_dispatchSave1394 (*(unsigned int *)MK4_VA(unsigned int, 0xf712fcu))
#define g_dispatchSave1400 (*(unsigned int *)MK4_VA(unsigned int, 0xf85b34u))
#define g_dispatchSave1403 (*(unsigned int *)MK4_VA(unsigned int, 0xf85b4cu))
#define g_dispatchSave1404 (*(unsigned int *)MK4_VA(unsigned int, 0xf85b58u))
#define g_viewportH (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd48u))
#define g_viewportW (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd44u))
#define g_viewportX (*(unsigned int *)MK4_VA(unsigned int, 0xf85b50u))
#define g_viewportY (*(unsigned int *)MK4_VA(unsigned int, 0xf85b54u))
#endif


#ifdef NON_MATCHING
/*
 * Portable C twin (path A). Faithful goto-based transcription; verified by
 * seeded co-exec (tools/decomp/verify_tri.py --shaded), not byte-match.
 * Gouraud-shaded affine textured triangle: same skeleton as TexturedTriRasterize
 * (edge-area, du/dx & dv/dx gradients, Y-sort, two-edge scanline walk) PLUS one
 * interpolated shade channel: vertex shades are 3 consecutive BYTES at
 * &g_dispatchSave1367, per-pixel gradient g_dispatchSave1341, edge gradient
 * g_dispatchSave1335, accumulators 1360 (edge) / 1386 (scanline) and per-pixel
 * step g_dispatchSave1390 (= 1341 >> 4, arithmetic). The inner loop reads the
 * texel then a 2D lighting LUT at base g_dispatchSave1340 indexed by
 * (shadeLevelHi << 16 | texel): the texel only briefly occupies the shade
 * accumulator's low 16 for the lookup and is restored (so - unlike
 * TexturedTriRasterize - there is NO texel-in-accumulator effect on U/V here).
 * Vertex pos/texcoord arrays via base pointers; shade via a byte base pointer.
 */
void TexturedTriRasterizeShaded(void)
{
    unsigned int eax, ebx, ecx, edx, esi, edi;
    unsigned int loc4, loc8;
    unsigned int *X = (unsigned int *)&g_dispatchSave1378;
    unsigned int *Y = (unsigned int *)&g_dispatchSave1381;
    unsigned int *U = (unsigned int *)&g_dispatchSave1371;
    unsigned int *V = (unsigned int *)&g_dispatchSave1374;
    unsigned char *S = (unsigned char *)&g_dispatchSave1367;

    if (g_viewportX == 0) return;
    edi = Y[2] - Y[0];
    ebx = Y[1] - Y[0];
    edx = X[2] - X[0];
    ecx = X[1] - X[0];
    edx = (unsigned int)((int)edx * (int)ebx);
    ecx = (unsigned int)((int)ecx * (int)edi);
    ecx = ecx - edx;                                    /* area */
    g_clipMinScratch = ecx;
    if ((int)ecx <= 0) return;

    edx = U[2] - U[0];                                  /* du/dx (1342) */
    esi = U[1] - U[0];
    edx = (unsigned int)((int)edx * (int)ebx);
    esi = (unsigned int)((int)esi * (int)edi);
    esi = esi - edx;
    { int n = (int)esi, ab = n < 0 ? -n : n;
      if (ab >= 0x80000) eax = (unsigned int)((int)(esi << 9) / (int)ecx) << 7;
      else               eax = (unsigned int)((int)(esi << 12) / (int)ecx) << 4; }
    g_dispatchSave1342 = eax;

    edx = V[2] - V[0];                                  /* dv/dx (1343) */
    esi = V[1] - V[0];
    edx = (unsigned int)((int)edx * (int)ebx);
    esi = (unsigned int)((int)esi * (int)edi);
    esi = esi - edx;
    { int n = (int)esi, ab = n < 0 ? -n : n;
      if (ab >= 0x80000) eax = (unsigned int)((int)(esi << 9) / (int)ecx) << 7;
      else               eax = (unsigned int)((int)(esi << 12) / (int)ecx) << 4; }
    g_dispatchSave1343 = eax;

    eax = S[0];                                         /* dShade/dx (1341) */
    edx = (unsigned int)S[2] - eax;
    edx = (unsigned int)((int)edx * (int)ebx);
    esi = (unsigned int)S[1] - eax;
    esi = (unsigned int)((int)esi * (int)edi);
    esi = esi - edx;
    { int n = (int)esi, ab = n < 0 ? -n : n;
      if (ab >= 0x80000) eax = (unsigned int)((int)(esi << 9) / (int)ecx) << 7;
      else               eax = (unsigned int)((int)(esi << 12) / (int)ecx) << 4; }
    g_dispatchSave1341 = eax;

    ecx = Y[1];                                         /* Y sort (edi=topidx, eax=minY) */
    eax = Y[0];
    edx = 0;
    edi = 0;
    g_dispatchSave1359 = edi;
    g_dispatchSave1365 = eax;
    g_dispatchSave1394 = eax;
    if ((int)ecx < (int)eax) {
        edi = 1;  g_dispatchSave1365 = ecx;  g_dispatchSave1359 = edi;  eax = ecx;
    } else {
        g_dispatchSave1394 = ecx;
    }
    ecx = Y[2];
    if ((int)ecx < (int)eax) {
        edi = 2;  g_dispatchSave1365 = ecx;  g_dispatchSave1359 = edi;  eax = ecx;
    }
    if ((int)ecx > (int)g_dispatchSave1394) g_dispatchSave1394 = ecx;
    if ((int)eax < (int)edx) { g_dispatchSave1365 = edx; eax = edx; }
    ecx = g_viewportH;
    if ((int)g_dispatchSave1394 > (int)ecx) g_dispatchSave1394 = ecx;

    ecx = (g_dispatchSave1403 & 0xf) << 0x11;
    ecx = ecx + g_dispatchSave1400;
    g_dispatchSave1366 = edi;
    g_dispatchSave1404 = ecx;
    ecx = (unsigned int)((int)g_viewportY * (int)eax);
    ecx = ecx + g_viewportX;
    g_dispatchSave1385 = edx;
    g_dispatchSave1346 = ecx;
    g_dispatchSave1364 = edx;
    if ((int)eax >= (int)g_dispatchSave1394) return;
    ebx = g_dispatchSave1361;
    goto L_2ecc;

L_2ec7:
    eax = g_dispatchSave1365;
L_2ecc:
    if ((int)g_dispatchSave1364 > (int)eax) goto L_3023;
L_2ed8:
    esi = edi - 1;
    if ((int)esi < 0) esi = 2;
    ecx = Y[esi];
    eax = Y[edi];
    loc4 = ecx;
    ecx = ecx - eax;
    loc8 = eax;
    if (ecx != 0) {
        eax = X[esi] - X[edi];
        ebx = U[edi];
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        g_dispatchSave1338 = eax;                       /* left dX/dy */
        eax = U[esi] - ebx;
        ebx = V[edi];
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        g_dispatchSave1336 = eax;                       /* left dU/dy */
        eax = V[esi] - ebx;
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        edx = S[edi];                                   /* shade[from] */
        g_dispatchSave1337 = eax;                       /* left dV/dy */
        eax = (unsigned int)S[esi] - edx;
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        g_dispatchSave1335 = eax;                       /* left dShade/dy */
    }
/* L_2f6a */
    edx = X[edi] << 16;
    ebx = U[edi] << 16;
    ecx = V[edi] << 16;
    eax = (unsigned int)S[edi] << 16;
    g_dispatchSave1360 = eax;                           /* shade accum */
    edi = loc8;                                         /* Y[from] */
    eax = g_dispatchSave1365;
    g_dispatchSave1363 = edx;
    g_dispatchSave1361 = ebx;
    g_dispatchSave1362 = ecx;
    eax = eax - edi;                                    /* minY - Y[from] */
    g_clipMaxScratch = eax;
    if (eax != 0) {
        edi = (unsigned int)((int)eax * (int)g_dispatchSave1338);
        edx = edx + edi;
        g_dispatchSave1363 = edx;
        edx = (unsigned int)((int)eax * (int)g_dispatchSave1336);
        ebx = ebx + edx;
        edx = (unsigned int)((int)eax * (int)g_dispatchSave1337);
        eax = (unsigned int)((int)eax * (int)g_dispatchSave1335);
        ecx = ecx + edx;
        g_dispatchSave1361 = ebx;
        g_dispatchSave1362 = ecx;
        ecx = g_dispatchSave1360;
        ecx = ecx + eax;
        g_dispatchSave1360 = ecx;
    }
/* L_3003 */
    eax = loc4;
    ecx = g_dispatchSave1365;
    edi = esi;
    g_dispatchSave1364 = eax;
    if ((int)eax <= (int)ecx) goto L_2ed8;
    g_dispatchSave1359 = edi;
    eax = ecx;
L_3023:
    if ((int)g_dispatchSave1385 > (int)eax) goto L_30ca;
L_302f:
    edx = g_dispatchSave1366;
    ecx = edx + 1;
    if ((int)ecx > 2) ecx = 0;
    esi = Y[ecx];
    edx = Y[edx];
    loc4 = esi;
    esi = esi - edx;
    loc8 = edx;
    if (esi != 0) {
        edx = g_dispatchSave1366;
        eax = X[ecx] - X[edx];
        eax = (unsigned int)((int)(eax << 16) / (int)esi);
        edx = loc8;
        g_dispatchSave1339 = eax;
        eax = g_dispatchSave1365;
    }
/* L_307e */
    esi = g_dispatchSave1366;
    esi = X[esi] << 16;
    eax = eax - edx;
    g_dispatchSave1384 = esi;
    g_clipMaxScratch = eax;
    if (eax != 0) {
        eax = (unsigned int)((int)eax * (int)g_dispatchSave1339);
        esi = esi + eax;
        g_dispatchSave1384 = esi;
    }
/* L_30ac */
    eax = g_dispatchSave1365;
    g_dispatchSave1366 = ecx;
    ecx = loc4;
    g_dispatchSave1385 = ecx;
    if ((int)ecx <= (int)eax) goto L_302f;
    goto L_30d0;
L_30ca:
    esi = g_dispatchSave1384;
L_30d0:
    ecx = g_dispatchSave1364;
    edx = g_dispatchSave1385;
    if ((int)ecx < (int)edx) edx = ecx;         /* edx = min(leftBottom, rightBottom) */
    ecx = edx;
    g_clipMinScratch = edx;
    ecx = ecx - eax;
    eax = g_dispatchSave1394;
    g_dispatchSave1393 = ecx;
    g_dispatchSave1365 = edx;
    if ((int)edx > (int)eax) {
        eax = eax - edx;
        ecx = ecx + eax;
        g_dispatchSave1393 = ecx;
    }
    if ((int)ecx <= 0) goto L_333c;
L_3113:
    eax = g_dispatchSave1363;
    edx = esi;
    edx = (unsigned int)((int)edx >> 16);
    eax = (unsigned int)((int)eax >> 16);
    ecx = edx;
    g_dispatchSave1370 = edx;
    ecx = ecx - eax;
    g_clipMinScratch = eax;
    g_clipMaxScratch = ecx;
    if ((int)ecx <= 0) goto L_32bd;
    if ((int)edx < 0) goto L_32bd;
    if ((int)eax >= (int)g_viewportW) goto L_32bd;
    edx = g_dispatchSave1362;
    ecx = ecx + eax;
    g_dispatchSave1389 = edx;
    edx = g_dispatchSave1360;
    g_dispatchSave1387 = ebx;
    g_dispatchSave1386 = edx;
    g_clipMaxScratch = ecx;
    if ((int)eax < 0) {                                 /* left clip (must not clobber ecx=rightX) */
        int leftX = (int)eax;
        esi = ebx - (unsigned int)(leftX * (int)g_dispatchSave1342);   /* U - leftX*du */
        g_dispatchSave1387 = esi;
        esi = g_dispatchSave1362 - (unsigned int)(leftX * (int)g_dispatchSave1343);  /* V - leftX*dv */
        g_dispatchSave1389 = esi;
        edx = g_dispatchSave1360 - (unsigned int)(leftX * (int)g_dispatchSave1341);  /* shade - leftX*dShade */
        g_dispatchSave1386 = edx;
        esi = g_dispatchSave1384;
        eax = 0;
    }
L_31c2:
    edx = g_dispatchSave1346 + eax * 2;
    g_dispatchSave1345 = edx;
    if ((int)ecx > (int)g_viewportW) { ecx = g_viewportW; g_clipMaxScratch = ecx; }
    ecx = ecx - eax;
    g_clipMinScratch = ecx;
    if ((int)ecx <= 0) goto L_32bd;
    {
        unsigned int uacc, vacc, ustep, vstep, tex, shade, span = ecx;
        /* ecx (uacc): U_frac<<16 | dv_int_byte<<8 | du_int_byte */
        uacc = ((g_dispatchSave1387 & 0xffff) << 16)
               | (((g_dispatchSave1343 >> 16) & 0xff) << 8)
               | ((g_dispatchSave1342 >> 16) & 0xff);
        ustep = (g_dispatchSave1342 & 0xffff) << 16;            /* du_frac<<16 */
        /* edx (tex): (1404>>1) high | V_int<<8 | U_int */
        tex = ((g_dispatchSave1404 >> 1) & 0xffff0000u)
              | (((g_dispatchSave1389 >> 16) & 0xff) << 8)
              | ((g_dispatchSave1387 >> 16) & 0xff);
        vstep = (g_dispatchSave1343 & 0xffff) << 16;            /* dv_frac<<16 */
        edi = g_dispatchSave1345;
        vacc = ((g_dispatchSave1389 & 0xffff) << 16) | (span & 0xffff);
        g_dispatchSave1390 = (unsigned int)((int)g_dispatchSave1341 >> 4);
        shade = (((g_dispatchSave1386 >> 3) + g_dispatchSave1340) >> 1);
        for (;;) {
            unsigned short texel = *(unsigned short *)MK4_PTR(tex * 2);
            if (texel != 0) {
                unsigned int ti = (shade & 0xffff0000u) | texel;
                *(unsigned short *)MK4_PTR(edi) =
                    *(unsigned short *)MK4_PTR(ti * 2);
            }
            {
                unsigned int s = vacc + vstep, c = s < vacc;
                unsigned int dh = ((tex >> 8) & 0xff) + ((uacc >> 8) & 0xff) + c;
                vacc = s;
                tex = (tex & 0xffff00ffu) | ((dh & 0xff) << 8);
            }
            {
                unsigned int s = uacc + ustep, c = s < uacc;
                unsigned int dl = (tex & 0xff) + (uacc & 0xff) + c;
                uacc = s;
                tex = (tex & 0xffffff00u) | (dl & 0xff);
            }
            shade = shade + g_dispatchSave1390;
            edi = edi + 2;
            vacc = (vacc & 0xffff0000u) | ((vacc - 1) & 0xffff);
            if (!((int)(short)(vacc & 0xffff) > 0)) break;
        }
    }
    edi = g_dispatchSave1359;
    ebx = g_dispatchSave1361;
    esi = g_dispatchSave1384;
L_32bd:
    edx = g_dispatchSave1346 + g_viewportY;
    g_dispatchSave1346 = edx;
    ecx = g_dispatchSave1363 + g_dispatchSave1338;
    g_dispatchSave1363 = ecx;
    esi = esi + g_dispatchSave1339;
    ebx = ebx + g_dispatchSave1336;
    edx = g_dispatchSave1362 + g_dispatchSave1337;
    g_dispatchSave1362 = edx;
    ecx = g_dispatchSave1360 + g_dispatchSave1335;
    eax = g_dispatchSave1393 - 1;
    g_dispatchSave1393 = eax;
    g_dispatchSave1384 = esi;
    g_dispatchSave1361 = ebx;
    g_dispatchSave1360 = ecx;
    if ((int)eax > 0) goto L_3113;
L_333c:
    eax = g_dispatchSave1394;
    ecx = g_dispatchSave1365;
    if ((int)ecx < (int)eax) goto L_2ec7;
    return;
}
#else
/* the naked branch stays in five_block_dispatch_variants.c */
#endif
