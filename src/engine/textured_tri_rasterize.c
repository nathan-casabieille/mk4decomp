/**
 * TexturedTriRasterize - split out of five_block_dispatch_variants.c.
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
#define g_dispatchSave1336 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d018u))
#define g_dispatchSave1337 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d01cu))
#define g_dispatchSave1338 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d020u))
#define g_dispatchSave1339 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d024u))
#define g_dispatchSave1342 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d030u))
#define g_dispatchSave1343 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d034u))
#define g_dispatchSave1345 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d040u))
#define g_dispatchSave1346 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d044u))
#define g_dispatchSave1359 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f54u))
#define g_dispatchSave1361 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f5cu))
#define g_dispatchSave1362 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f60u))
#define g_dispatchSave1363 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f64u))
#define g_dispatchSave1364 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f68u))
#define g_dispatchSave1365 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f6cu))
#define g_dispatchSave1366 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f74u))
#define g_dispatchSave1370 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f84u))
#define g_dispatchSave1371 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f88u))
#define g_dispatchSave1374 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f98u))
#define g_dispatchSave1378 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fa8u))
#define g_dispatchSave1381 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fb8u))
#define g_dispatchSave1384 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fc8u))
#define g_dispatchSave1385 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fccu))
#define g_dispatchSave1387 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fd8u))
#define g_dispatchSave1389 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fdcu))
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
 * Portable C twin (path A). Faithful goto-based transcription of the naked
 * branch below; verified by seeded co-exec (tools/decomp/verify_tri.py), not
 * byte-match. Affine textured triangle rasterizer:
 *   - edge-function area (cross product); reject if <= 0 (backface/degenerate),
 *   - du/dx, dv/dx gradients with a magnitude-based precision branch (the
 *     0x80000 test choosing <<12//area<<4 vs <<9//area<<7),
 *   - Y-sorted vertices, scanline-walk of the left + right edges (split at the
 *     middle vertex), per-scanline span with a dual-carry packed fixed-point
 *     texture walk (adc dh,bh steps V-int, adc dl,bl steps U-int).
 * Vertices are consecutive scratch dwords addressed as arrays via base pointers
 * (x=1378/1379/1380, y=1381/1382/1383, u=1371/1372/1373, v=1374/1376/1377),
 * exactly as the original's [idx*4 + g_dispatchSaveNNNN]. (Native build assumes
 * those dwords stay contiguous - a native_globals layout concern, not a
 * verification one.) The matching build delegates nothing here; this is the
 * whole function.
 */
void TexturedTriRasterize(void)
{
    unsigned int eax, ebx, ecx, edx, esi, edi;
    unsigned int loc4, loc8;
    unsigned int *X = (unsigned int *)&g_dispatchSave1378;   /* x[0..2] */
    unsigned int *Y = (unsigned int *)&g_dispatchSave1381;   /* y[0..2] */
    unsigned int *U = (unsigned int *)&g_dispatchSave1371;   /* u[0..2] */
    unsigned int *V = (unsigned int *)&g_dispatchSave1374;   /* v[0..2] */

    if (g_viewportX == 0) return;
    edi = Y[2] - Y[0];                                  /* y2-y0 */
    ebx = Y[1] - Y[0];                                  /* y1-y0 */
    edx = X[2] - X[0];                                  /* x2-x0 */
    ecx = X[1] - X[0];                                  /* x1-x0 */
    edx = (unsigned int)((int)edx * (int)ebx);
    ecx = (unsigned int)((int)ecx * (int)edi);
    ecx = ecx - edx;                                    /* area */
    g_clipMinScratch = ecx;
#ifdef TARGET_SDL
    /* MK4_TRACE_UV: the triangle's own inputs. u,v should sit in 0..255 for
     * a 256x256 page; a gradient that samples several texels per pixel is
     * either a tiny area or texture coords that are not in texel units. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int tris;
      if (getenv("MK4_TRACE_UV") && tris < 8 && (int)ecx > 4000) {
          tris++;
          SDL_Log("TRI area=%d x=[%d %d %d] y=[%d %d %d] u=[%d %d %d] v=[%d %d %d]",
                  (int)ecx, (int)X[0], (int)X[1], (int)X[2],
                  (int)Y[0], (int)Y[1], (int)Y[2],
                  (int)U[0], (int)U[1], (int)U[2],
                  (int)V[0], (int)V[1], (int)V[2]); } }
#endif
    if ((int)ecx <= 0) return;

    edx = U[2] - U[0];                                  /* --- du/dx (1342) --- */
    esi = U[1] - U[0];
    edx = (unsigned int)((int)edx * (int)ebx);
    esi = (unsigned int)((int)esi * (int)edi);
    esi = esi - edx;
    {
        int n = (int)esi, ab = n < 0 ? -n : n;
        if (ab >= 0x80000) eax = (unsigned int)((int)(esi << 9) / (int)ecx) << 7;
        else               eax = (unsigned int)((int)(esi << 12) / (int)ecx) << 4;
    }
    g_dispatchSave1342 = eax;

    edx = V[2] - V[0];                                  /* --- dv/dx (1343) --- */
    esi = V[1] - V[0];
    edx = (unsigned int)((int)edx * (int)ebx);
    esi = (unsigned int)((int)esi * (int)edi);
    esi = esi - edx;
    {
        int n = (int)esi, ab = n < 0 ? -n : n;
        if (ab >= 0x80000) eax = (unsigned int)((int)(esi << 9) / (int)ecx) << 7;
        else               eax = (unsigned int)((int)(esi << 12) / (int)ecx) << 4;
    }
    ecx = Y[0];                                         /* --- Y sort --- */
    g_dispatchSave1343 = eax;
    eax = Y[1];
    esi = 0;
    edx = 0;
    g_dispatchSave1359 = 0;
    g_dispatchSave1365 = ecx;
    g_dispatchSave1394 = ecx;
    if ((int)eax < (int)ecx) {
        g_dispatchSave1359 = 1;  edx = 1;  g_dispatchSave1365 = eax;  ecx = eax;
    } else {
        g_dispatchSave1394 = eax;
    }
    eax = Y[2];
    if ((int)eax < (int)ecx) {
        g_dispatchSave1359 = 2;  edx = 2;  g_dispatchSave1365 = eax;  ecx = eax;
    }
    if ((int)eax > (int)g_dispatchSave1394) g_dispatchSave1394 = eax;
    if ((int)ecx < (int)esi) { g_dispatchSave1365 = esi; ecx = esi; }
    eax = g_viewportH;
    if ((int)g_dispatchSave1394 > (int)eax) g_dispatchSave1394 = eax;

    eax = (g_dispatchSave1403 & 0xf) << 0x11;
    eax = eax + g_dispatchSave1400;
    g_dispatchSave1366 = edx;
    g_dispatchSave1404 = eax;
    eax = (unsigned int)((int)g_viewportY * (int)ecx);
    eax = eax + g_viewportX;
    g_dispatchSave1385 = esi;
    g_dispatchSave1346 = eax;
    g_dispatchSave1364 = esi;
    if ((int)ecx >= (int)g_dispatchSave1394) return;
    edi = g_dispatchSave1361;
    ebx = g_dispatchSave1362;
    edx = g_dispatchSave1359;
    goto L_15c2;

L_15bc:
    ecx = g_dispatchSave1365;
L_15c2:
    if ((int)g_dispatchSave1364 > (int)ecx) goto L_16e0;
L_15ce:
    esi = edx - 1;
    if ((int)esi < 0) esi = 2;
    ecx = Y[esi];
    eax = Y[edx];
    loc4 = ecx;
    ecx = ecx - eax;
    loc8 = eax;
    if (ecx != 0) {
        eax = X[esi] - X[edx];
        edi = g_dispatchSave1359;
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        ebx = U[edi];
        g_dispatchSave1338 = eax;
        eax = U[esi] - ebx;
        ebx = V[edi];
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        g_dispatchSave1336 = eax;
        eax = V[esi] - ebx;
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        edx = edi;
        g_dispatchSave1337 = eax;
    }
/* L_164b */
    eax = X[edx] << 16;
    edi = U[edx] << 16;
    ebx = V[edx] << 16;
    ecx = loc8;
    g_dispatchSave1363 = eax;
    eax = g_dispatchSave1365;
    g_dispatchSave1361 = edi;
    g_dispatchSave1362 = ebx;
    eax = eax - ecx;
    g_clipMaxScratch = eax;
    if (eax != 0) {
        ecx = eax;
        edx = g_dispatchSave1363;
        ecx = (unsigned int)((int)ecx * (int)g_dispatchSave1338);
        edx = edx + ecx;
        g_dispatchSave1363 = edx;
        edx = (unsigned int)((int)eax * (int)g_dispatchSave1336);
        eax = (unsigned int)((int)eax * (int)g_dispatchSave1337);
        edi = edi + edx;
        ebx = ebx + eax;
        g_dispatchSave1361 = edi;
        g_dispatchSave1362 = ebx;
    }
/* L_16c2 */
    eax = loc4;
    ecx = g_dispatchSave1365;
    g_dispatchSave1359 = esi;
    g_dispatchSave1364 = eax;
    edx = esi;
    if ((int)eax <= (int)ecx) goto L_15ce;
L_16e0:
    if ((int)g_dispatchSave1385 > (int)ecx) goto L_1799;
L_16ec:
    eax = g_dispatchSave1366 + 1;
    g_clipMinScratch = eax;
    if ((int)eax > 2) { eax = 0; g_clipMinScratch = 0; }
    ecx = g_dispatchSave1366;
    esi = Y[eax];
    loc4 = esi;
    ecx = Y[ecx];
    esi = esi - ecx;
    if (esi != 0) {
        edx = g_dispatchSave1366;
        eax = X[eax] - X[edx];
        eax = (unsigned int)((int)(eax << 16) / (int)esi);
        edx = g_dispatchSave1359;
        g_dispatchSave1339 = eax;
    }
/* L_1743 */
    eax = g_dispatchSave1366;
    esi = X[eax] << 16;
    eax = g_dispatchSave1365;
    eax = eax - ecx;
    g_dispatchSave1384 = esi;
    g_clipMaxScratch = eax;
    if (eax != 0) {
        eax = (unsigned int)((int)eax * (int)g_dispatchSave1339);
        esi = esi + eax;
        g_dispatchSave1384 = esi;
    }
/* L_1775 */
    ecx = g_clipMinScratch;
    eax = loc4;
    g_dispatchSave1366 = ecx;
    ecx = g_dispatchSave1365;
    g_dispatchSave1385 = eax;
    if ((int)eax <= (int)ecx) goto L_16ec;
    goto L_179f;
L_1799:
    esi = g_dispatchSave1384;
L_179f:
    eax = g_dispatchSave1364;
    ecx = g_dispatchSave1385;
    if ((int)eax >= (int)ecx) eax = ecx;
    g_clipMinScratch = eax;
    ecx = g_dispatchSave1365;
    eax = eax - ecx;
    ecx = g_dispatchSave1394;
    g_dispatchSave1393 = eax;
    eax = g_clipMinScratch;
    g_dispatchSave1365 = eax;
    if ((int)eax > (int)ecx) {
        ecx = ecx - eax;
        eax = g_dispatchSave1393;
        eax = eax + ecx;
        g_dispatchSave1393 = eax;
    }
    if ((int)g_dispatchSave1393 <= 0) goto L_1998;
L_17f1:
    eax = g_dispatchSave1363;
    edx = esi;
    edx = (unsigned int)((int)edx >> 16);
    eax = (unsigned int)((int)eax >> 16);
    ecx = edx;
    g_dispatchSave1370 = edx;
    ecx = ecx - eax;
    g_clipMinScratch = eax;
    g_clipMaxScratch = ecx;
    if ((int)ecx <= 0) goto L_192d;
    if ((int)edx < 0) goto L_192d;
    if ((int)eax >= (int)g_viewportW) goto L_192d;
    ecx = ecx + eax;
    g_dispatchSave1387 = edi;
    g_dispatchSave1389 = ebx;
    g_clipMaxScratch = ecx;
    if ((int)eax < 0) {
        edx = eax;
        eax = (unsigned int)((int)eax * (int)g_dispatchSave1343);
        edx = (unsigned int)((int)edx * (int)g_dispatchSave1342);
        esi = edi - edx;
        edx = ebx - eax;
        g_dispatchSave1387 = esi;
        esi = g_dispatchSave1384;
        g_dispatchSave1389 = edx;
        eax = 0;
    }
/* L_1873 */
    edx = g_dispatchSave1346 + eax * 2;
    g_dispatchSave1345 = edx;
    if ((int)ecx > (int)g_viewportW) { ecx = g_viewportW; g_clipMaxScratch = ecx; }
    ecx = ecx - eax;
    g_clipMinScratch = ecx;
    if ((int)ecx <= 0) goto L_192d;
    {
        unsigned int uacc, vacc, ustep, vspan, tex;
        unsigned int span = ecx;
        ustep = ((g_dispatchSave1342 & 0xffff) << 16)
                | (((g_dispatchSave1343 >> 16) & 0xff) << 8)
                | ((g_dispatchSave1342 >> 16) & 0xff);
        vspan = ((g_dispatchSave1343 & 0xffff) << 16) | (span & 0xffff);
        tex = (((g_dispatchSave1389 >> 16) & 0xff) << 8) | ((g_dispatchSave1387 >> 16) & 0xff);
        vacc = g_dispatchSave1389 << 16;
        uacc = g_dispatchSave1387 << 16;
        edi = g_dispatchSave1345;
        esi = g_dispatchSave1404;
#ifdef TARGET_SDL
        /* MK4_TRACE_UV: the (u,v) walk along one span. Streaky texturing
         * means one component is not advancing; this says which. */
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          static int spans;
          if (getenv("MK4_TRACE_UV") && spans < 6 && span > 24) {
              spans++;
              SDL_Log("UV span=%u tex0=%04x ustep=%08x vspan=%08x u0=%08x v0=%08x",
                      span, tex, ustep, vspan, uacc, vacc); } }
#endif
        for (;;) {
            unsigned short t = *(unsigned short *)MK4_PTR(esi + tex * 2);
            if (t != 0) *(unsigned short *)MK4_PTR(edi) = t;
            {
                unsigned int s = vacc + vspan, c = s < vacc;
                unsigned int dh = ((tex >> 8) & 0xff) + ((ustep >> 8) & 0xff) + c;
                vacc = s;
                tex = (tex & 0x00ff) | ((dh & 0xff) << 8);
            }
            {
                /* eax low 16 held the texel (mov ax, word[..]) before add eax,ebx;
                   the texel thus participates in the carry into U-frac. */
                unsigned int e = (uacc & 0xffff0000u) | t;
                unsigned int s = e + ustep, c = s < e;
                unsigned int dl = (tex & 0xff) + (ustep & 0xff) + c;
                uacc = s;
                tex = (tex & 0xff00) | (dl & 0xff);
            }
            edi = edi + 2;
#ifdef TARGET_SDL
            { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
              static int steps;
              if (getenv("MK4_TRACE_UV") && steps < 24 && vspan > 24) {
                  steps++;
                  SDL_Log("UV   step u=%3u v=%3u", tex & 0xff, (tex >> 8) & 0xff); } }
#endif
            vspan = (vspan & 0xffff0000u) | ((vspan - 1) & 0xffff);
            if (!((int)(short)(vspan & 0xffff) > 0)) break;
        }
    }
    edi = g_dispatchSave1361;
    ebx = g_dispatchSave1362;
    esi = g_dispatchSave1384;
L_192d:
    edx = g_dispatchSave1346 + g_viewportY;
    eax = g_dispatchSave1393 - 1;
    g_dispatchSave1346 = edx;
    ecx = g_dispatchSave1363 + g_dispatchSave1338;
    g_dispatchSave1363 = ecx;
    esi = esi + g_dispatchSave1339;
    edi = edi + g_dispatchSave1336;
    ebx = ebx + g_dispatchSave1337;
    g_dispatchSave1393 = eax;
    g_dispatchSave1384 = esi;
    g_dispatchSave1361 = edi;
    g_dispatchSave1362 = ebx;
    if ((int)eax > 0) goto L_17f1;
    edx = g_dispatchSave1359;
L_1998:
    eax = g_dispatchSave1394;
    ecx = g_dispatchSave1365;
    if ((int)ecx < (int)eax) goto L_15bc;
    return;
}
#else
/* the naked branch stays in five_block_dispatch_variants.c */
#endif
