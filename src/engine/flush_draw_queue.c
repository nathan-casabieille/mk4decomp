/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "portable/ghidra_types.h"
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern u32 g_drawQueueBuckets[];
extern unsigned int g_dispatchSave1349;
extern unsigned int g_dispatchSave1350;
#endif
extern unsigned int g_dispatchSave1352;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1356;
extern unsigned int g_dispatchSave1367;
extern unsigned int g_dispatchSave1368;
extern unsigned int g_dispatchSave1369;
extern unsigned int g_dispatchSave1371;
extern unsigned int g_dispatchSave1372;
extern unsigned int g_dispatchSave1373;
extern unsigned int g_dispatchSave1374;
extern unsigned int g_dispatchSave1376;
extern unsigned int g_dispatchSave1377;
extern unsigned int g_dispatchSave1378;
extern unsigned int g_dispatchSave1379;
extern unsigned int g_dispatchSave1380;
extern unsigned int g_dispatchSave1381;
extern unsigned int g_dispatchSave1382;
extern unsigned int g_dispatchSave1383;
extern unsigned int g_dispatchSave1398;
#endif
extern unsigned int g_dispatchSave1400;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern u32 g_drawQueueSize;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_dispatchSave1349 (*(unsigned int *)MK4_VA(unsigned int, 0xf6d052u))
#define g_dispatchSave1350 (*(unsigned int *)MK4_VA(unsigned int, 0xf6e050u))
#define g_dispatchSave1356 (*(unsigned int *)MK4_VA(unsigned int, 0xf6e068u))
#define g_dispatchSave1367 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f7cu))
#define g_dispatchSave1368 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f7du))
#define g_dispatchSave1369 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f7eu))
#define g_dispatchSave1371 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f88u))
#define g_dispatchSave1372 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f8cu))
#define g_dispatchSave1373 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f90u))
#define g_dispatchSave1374 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f98u))
#define g_dispatchSave1376 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f9cu))
#define g_dispatchSave1377 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fa0u))
#define g_dispatchSave1378 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fa8u))
#define g_dispatchSave1379 (*(unsigned int *)MK4_VA(unsigned int, 0xf70facu))
#define g_dispatchSave1380 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fb0u))
#define g_dispatchSave1381 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fb8u))
#define g_dispatchSave1382 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fbcu))
#define g_dispatchSave1383 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fc0u))
#define g_dispatchSave1398 (*(unsigned int *)MK4_VA(unsigned int, 0xf71322u))
#define g_dispatchSave1403 (*(unsigned int *)MK4_VA(unsigned int, 0xf85b4cu))
#define g_div3Table (*(unsigned int *)MK4_VA(unsigned int, 0xf70ff8u))
#define g_drawQueueBuckets (*(unsigned int *)MK4_VA(unsigned int, 0xf6d050u))
#define g_drawQueueSize (*(unsigned int *)MK4_VA(unsigned int, 0xf85b40u))
#define g_viewportX (*(unsigned int *)MK4_VA(unsigned int, 0xf85b50u))
#define g_viewportY (*(unsigned int *)MK4_VA(unsigned int, 0xf85b54u))
#endif

extern void BlitBlend16bpp(void);
extern void DecodeTableAllocaCall(void);
extern void GlideTriBatchEmit(void);
extern void GlideTriColorFlush(void);
extern void PadEnumDeviceRebind(void);
extern void ScanlineTexBlitAdditive(void);
extern void ScanlineTexBlitAlpha(void);
extern void ScanlineTexBlitInterlaced(void);
extern void ScanlineTexBlitPaletted(void);
extern void ScanlineTexBlit(void);
extern void TexturedTriRasterizeAlphaPal(void);
extern void TexturedTriRasterizeAlpha(void);
extern void TexturedTriRasterizeDithered(void);
extern void TexturedTriRasterizeShaded(void);
extern void TexturedTriRasterize(void);

#ifdef NON_MATCHING
/*
 * Portable C twin (path A). SW dispatcher. The mode-5 (software) path is
 * FPU-free; modes 1 (Glide+FPU) and 2 (PadEnum) and the non-5 SW variant
 * (L_ff9e) are stubbed (Renderer_GetMode()==5 in the SW build, so they are not
 * reached). Counting-sort the draw queue by the +0x12 key, then per sorted
 * 0x1c-byte record: decode verts/uv into the g_dispatchSave globals, compute the
 * per-vertex shade from RGB555 colours via g_div3Table, and dispatch to the
 * right (now-all-C) rasterizer by the +0x1a type. Verified by verify_flush.py.
 */
void FlushDrawQueue(void)
{
    unsigned int eax, ebx, ecx, edx, esi, edi;
    unsigned short *buckets = (unsigned short *)&g_drawQueueBuckets;
    unsigned char *div3 = (unsigned char *)&g_div3Table;
    unsigned char *rec0 = (unsigned char *)&g_dispatchSave1398 - 0x12; /* record 0 start */
    unsigned int *sorted = (unsigned int *)&g_dispatchSave1356;
    unsigned int sortidx, count;
    int i;
    /* --- counting sort --- */
    esi = g_drawQueueSize;
    ebx = 0;
    for (i = 0; i < 0x400 * 2; i++) buckets[i] = 0;     /* rep stosd 0x400 dwords */
    if ((int)esi > 0) {
        unsigned char *kp = (unsigned char *)&g_dispatchSave1398;   /* key field (rec+0x12) */
        for (edx = esi; edx != 0; edx--) {
            eax = *(unsigned short *)kp;
            buckets[eax]++;
            kp += 0x1c;
        }
    }
    {   /* prefix sum over [g_dispatchSave1349, g_dispatchSave1350) step 2 */
        unsigned char *p = (unsigned char *)&g_dispatchSave1349;
        unsigned char *end = (unsigned char *)&g_dispatchSave1350;
        for (; p < end; p += 2)
            *(unsigned short *)p = (unsigned short)(*(unsigned short *)p + *(unsigned short *)(p - 2));
    }
    eax = esi - 1;
    if ((int)eax >= 0) {            /* scatter (last record -> first) */
        unsigned char *kp = (unsigned char *)&g_dispatchSave1398 + eax * 0x1c;
        for (edx = eax + 1; edx != 0; edx--) {
            unsigned int recva = MK4_UNPTR(kp - 0x12);
            eax = *(unsigned short *)kp;
            kp -= 0x1c;
            buckets[eax]--;
            sorted[buckets[eax] & 0xffff] = recva;
        }
    }
    /* --- mode dispatch (Renderer_GetMode reads *0x4f4b3c) --- */
    if (Renderer_GetMode() == 1) goto done;             /* Glide+FPU path - stub */
    if (Renderer_GetMode() == 2) goto done;             /* PadEnum path - stub */
    if (Renderer_GetMode() != 5) goto done;             /* L_ff9e other-SW - stub */
    /* --- L_fc70: SW mode 5 per-primitive decode + dispatch --- */
    eax = g_drawQueueSize;
    if ((int)(eax - 1) < 0) goto done;
    sortidx = eax - 1;                                  /* index into sorted[] (backward) */
    count = eax;
    for (;;) {
        unsigned char *rec = (unsigned char *)MK4_PTR(sorted[sortidx]);
        unsigned int color0, typ;
        g_dispatchSave1378 = (unsigned int)(int)*(short *)(rec + 0);     /* x0 */
        g_dispatchSave1381 = (unsigned int)(int)*(short *)(rec + 2);     /* y0 */
        g_dispatchSave1371 = rec[0xc];                                  /* u0 */
        g_dispatchSave1374 = rec[0xd];                                  /* v0 */
        color0 = *(unsigned short *)(rec + 0x14);
        g_dispatchSave1367 = (unsigned char)((div3[(color0 & 0x1f) + ((color0 >> 5) & 0x1f) + ((color0 >> 0xa) & 0x1f)] << 3) & 0xff);
        if (!(rec[0x1a] & 0x10)) {
            *(unsigned short *)(rec + 0x16) = *(unsigned short *)(rec + 0x14);
            *(unsigned short *)(rec + 0x18) = *(unsigned short *)(rec + 0x16);
        }
        typ = *(unsigned short *)(rec + 0x1a);
        {
            unsigned int c1 = *(unsigned short *)(rec + 0x16);
            unsigned int c2 = *(unsigned short *)(rec + 0x18);
            unsigned int s1 = (unsigned char)((div3[(c1 & 0x1f) + ((c1 >> 5) & 0x1f) + ((c1 >> 0xa) & 0x1f)] << 3) & 0xff);
            unsigned int s2 = (unsigned char)((div3[(c2 & 0x1f) + ((c2 >> 5) & 0x1f) + ((c2 >> 0xa) & 0x1f)] << 3) & 0xff);
            if ((typ & 0x400) && !(typ & 0x20)) {     /* ch&4 && !cl&0x20 == (typ>>8)&4 && !(typ&0x2000)? */
                /* path A */
                g_dispatchSave1380 = (unsigned int)(int)*(short *)(rec + 4);
                g_dispatchSave1383 = (unsigned int)(int)*(short *)(rec + 6);
                g_dispatchSave1379 = (unsigned int)(int)*(short *)(rec + 8);
                g_dispatchSave1382 = (unsigned int)(int)*(short *)(rec + 0xa);
                g_dispatchSave1373 = rec[0xe];
                g_dispatchSave1377 = rec[0xf];
                g_dispatchSave1372 = rec[0x10];
                g_dispatchSave1376 = rec[0x11];
                g_dispatchSave1369 = (unsigned char)s1;
                g_dispatchSave1368 = (unsigned char)s2;
            } else {
                /* path B (L_fda3) */
                g_dispatchSave1379 = (unsigned int)(int)*(short *)(rec + 4);
                g_dispatchSave1382 = (unsigned int)(int)*(short *)(rec + 6);
                g_dispatchSave1380 = (unsigned int)(int)*(short *)(rec + 8);
                g_dispatchSave1383 = (unsigned int)(int)*(short *)(rec + 0xa);
                g_dispatchSave1372 = rec[0xe];
                g_dispatchSave1376 = rec[0xf];
                g_dispatchSave1373 = rec[0x10];
                g_dispatchSave1377 = rec[0x11];
                g_dispatchSave1368 = (unsigned char)s1;
                g_dispatchSave1369 = (unsigned char)s2;
            }
        }
        /* L_fe4f dispatch */
        g_dispatchSave1403 = typ & 0xf;
        if ((typ >> 5) & 1) {
            /* RECT: sort verts so x0<=x1, y0<=y1 (+ u/v) */
            edx = g_dispatchSave1380;
            edi = g_dispatchSave1373;
            if ((int)g_dispatchSave1378 > (int)edx) {
                ecx = g_dispatchSave1378;
                g_dispatchSave1380 = ecx; g_dispatchSave1378 = edx;
                ecx = g_dispatchSave1371;
                g_dispatchSave1373 = ecx; g_dispatchSave1371 = edi;
            }
            esi = g_dispatchSave1383;
            if ((int)g_dispatchSave1381 > (int)esi) {
                edx = g_dispatchSave1377;
                ecx = g_dispatchSave1381;
                g_dispatchSave1383 = ecx; g_dispatchSave1381 = esi;
                ecx = g_dispatchSave1374;
                g_dispatchSave1377 = ecx; g_dispatchSave1374 = edx;
            }
            if (*(unsigned short *)(rec + 0x14) < 0x7fff) {
                ScanlineTexBlitPaletted();
            } else {
                unsigned int m = typ & 0x180;
                if (m == 0x80 || m == 0x100 || m == 0x180) ScanlineTexBlitInterlaced();
                else if ((typ >> 6) & 1) BlitBlend16bpp();
                else ScanlineTexBlit();
            }
        } else {
            /* TRIANGLE */
            if (*(unsigned short *)(rec + 0x14) >= 0x7fff && !(typ & 0x10)) {
                unsigned int m = typ & 0x180;
                if (m == 0x80 || m == 0x100 || m == 0x180) TexturedTriRasterizeDithered();
                else TexturedTriRasterize();
            } else {
                TexturedTriRasterizeShaded();
            }
        }
        if (--count == 0) break;
        sortidx--;
    }
done:
    g_viewportX = 0;
    g_viewportY = 0;
}
#else
__declspec(naked) void FlushDrawQueue(void)
{
    __asm {
        sub      esp, 0x10
        push     ebx
        push     ebp
        mov      al, 0xff
        push     esi
        mov      esi, dword ptr [g_drawQueueSize]
        push     edi
        xor      ebx, ebx
        mov      byte ptr [esp + 0x11], al
        mov      byte ptr [esp + 0x12], al
        mov      byte ptr [esp + 0x15], al
        mov      byte ptr [esp + 0x16], al
        mov      byte ptr [esp + 0x17], al
        mov      ecx, 0x400
        xor      eax, eax
        mov      edi, OFFSET g_drawQueueBuckets
        cmp      esi, ebx
        mov      byte ptr [esp + 0x10], bl
        mov      byte ptr [esp + 0x13], 0x80
        mov      byte ptr [esp + 0x14], bl
        rep stosd
        jle      L_f4be
        mov      ecx, OFFSET g_dispatchSave1398
        mov      edx, esi
    L_f4ab:
        xor      eax, eax
        mov      ax, word ptr [ecx]
        add      ecx, 0x1c
        inc      word ptr [eax*2 + g_drawQueueBuckets]
        dec      edx
        jne      L_f4ab
    L_f4be:
        mov      eax, OFFSET g_dispatchSave1349
    L_f4c3:
        mov      cx, word ptr [eax - 2]
        add      word ptr [eax], cx
        add      eax, 2
        cmp      eax, OFFSET g_dispatchSave1350
        jl       L_f4c3
        lea      eax, [esi - 1]
        cmp      eax, ebx
        jl       L_f516
        mov      edx, eax
        shl      edx, 3
        sub      edx, eax
        lea      ecx, [edx*4 + g_dispatchSave1398]
        lea      edx, [eax + 1]
    L_f4ec:
        xor      eax, eax
        lea      esi, [ecx - 0x12]
        mov      ax, word ptr [ecx]
        sub      ecx, 0x1c
        dec      word ptr [eax*2 + g_drawQueueBuckets]
        mov      ax, word ptr [eax*2 + g_drawQueueBuckets]
        and      eax, 0xffff
        dec      edx
        mov      dword ptr [eax*4 + g_dispatchSave1356], esi
        jne      L_f4ec
    L_f516:
        call     Renderer_GetMode
        cmp      eax, 1
        jne      L_f8ad
        xor      esi, esi
        xor      edi, edi
    L_f528:
        cmp      byte ptr [esi + g_dispatchSave1352], bl
        je       L_f547
        mov      eax, dword ptr [g_dispatchSave1400]
        add      eax, edi
        push     eax
        push     esi
        call     DecodeTableAllocaCall
        add      esp, 8
        mov      byte ptr [esi + g_dispatchSave1352], bl
    L_f547:
        add      edi, 0x20000
        inc      esi
        cmp      edi, 0x200000
        jl       L_f528
        mov      ecx, dword ptr [g_drawQueueSize]
        lea      eax, [ecx - 1]
        cmp      eax, ebx
        jl       L_033d
        lea      ebp, [eax*4 + g_dispatchSave1356]
        inc      eax
        mov      dword ptr [esp + 0x14], eax
    L_f573:
        mov      eax, dword ptr [ebp]
        mov      cx, word ptr [eax + 0x1a]
        mov      dl, cl
        shr      dl, 5
        test     dl, 1
        je       L_f733
        mov      cx, word ptr [eax]
        mov      dx, word ptr [eax + 8]
        cmp      cx, dx
        jle      L_f5b8
        movsx    ecx, dx
        mov      dword ptr [g_dispatchSave1378], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax]
        mov      dword ptr [g_dispatchSave1380], edx
        mov      cl, byte ptr [eax + 0x10]
        mov      dword ptr [g_dispatchSave1371], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xc]
        jmp      L_f5db
    L_f5b8:
        movsx    ecx, cx
        mov      dword ptr [g_dispatchSave1378], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1380], edx
        mov      cl, byte ptr [eax + 0xc]
        mov      dword ptr [g_dispatchSave1371], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
    L_f5db:
        mov      dword ptr [g_dispatchSave1373], ecx
        mov      cx, word ptr [eax + 2]
        mov      dx, word ptr [eax + 0xa]
        cmp      cx, dx
        jle      L_f613
        movsx    ecx, dx
        mov      dword ptr [g_dispatchSave1381], ecx
        movsx    edx, word ptr [eax + 2]
        mov      dword ptr [g_dispatchSave1383], edx
        xor      edx, edx
        mov      dl, byte ptr [eax + 0x11]
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374], edx
        mov      bl, byte ptr [eax + 0xd]
        jmp      L_f636
    L_f613:
        movsx    ecx, cx
        mov      dword ptr [g_dispatchSave1381], ecx
        movsx    edx, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1383], edx
        xor      edx, edx
        mov      dl, byte ptr [eax + 0xd]
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374], edx
        mov      bl, byte ptr [eax + 0x11]
    L_f636:
        fild     dword ptr [g_dispatchSave1380]
        mov      dword ptr [g_dispatchSave1377], ebx
        mov      cx, word ptr [eax + 0x14]
        push     ecx
        push     ebx
        fstp     dword ptr [esp + 0x20]
        fild     dword ptr [g_dispatchSave1381]
        mov      bl, byte ptr [g_dispatchSave1373]
        mov      esi, dword ptr [esp + 0x20]
        push     ebx
        push     ecx
        fstp     dword ptr [esp + 0x2c]
        fild     dword ptr [g_dispatchSave1383]
        mov      edi, dword ptr [esp + 0x2c]
        mov      bl, dl
        fstp     dword ptr [esp]
        push     esi
        push     ecx
        push     ebx
        mov      bl, byte ptr [g_dispatchSave1373]
        push     ebx
        push     edi
        push     esi
        push     ecx
        mov      cl, byte ptr [g_dispatchSave1371]
        push     edx
        mov      dx, word ptr [eax + 0x1a]
        push     ecx
        fild     dword ptr [g_dispatchSave1378]
        shr      edx, 7
        and      edx, 3
        push     edi
        push     ecx
        mov      cl, byte ptr [esp + edx + 0x4c]
        mov      dl, byte ptr [eax + 0x1a]
        fstp     dword ptr [esp]
        and      dl, 0xf
        push     ecx
        push     edx
        call     GlideTriColorFlush
        fild     dword ptr [g_dispatchSave1383]
        mov      eax, dword ptr [ebp]
        mov      dl, byte ptr [g_dispatchSave1377]
        add      esp, 0x44
        mov      bl, dl
        fstp     dword ptr [esp + 0x1c]
        mov      cx, word ptr [eax + 0x14]
        mov      esi, dword ptr [esp + 0x1c]
        fild     dword ptr [g_dispatchSave1378]
        push     ecx
        push     ebx
        mov      bl, byte ptr [g_dispatchSave1371]
        fstp     dword ptr [esp + 0x20]
        mov      edi, dword ptr [esp + 0x20]
        push     ebx
        fild     dword ptr [g_dispatchSave1380]
        push     esi
        push     edi
        push     ecx
        push     edx
        mov      dl, byte ptr [g_dispatchSave1373]
        push     edx
        push     esi
        push     ecx
        mov      dl, bl
        fstp     dword ptr [esp]
        push     ecx
        mov      cl, byte ptr [g_dispatchSave1374]
        fild     dword ptr [g_dispatchSave1381]
        push     ecx
        push     edx
        push     ecx
        mov      cx, word ptr [eax + 0x1a]
        mov      al, byte ptr [eax + 0x1a]
        fstp     dword ptr [esp]
        shr      ecx, 7
        and      ecx, 3
        push     edi
        and      al, 0xf
        mov      dl, byte ptr [esp + ecx + 0x4c]
        push     edx
        push     eax
        call     GlideTriColorFlush
        add      esp, 0x44
        xor      ebx, ebx
        jmp      L_f887
    L_f733:
        test     cl, 0x10
        jne      L_f74b
        mov      cx, word ptr [eax + 0x14]
        mov      word ptr [eax + 0x16], cx
        mov      eax, dword ptr [ebp]
        mov      dx, word ptr [eax + 0x16]
        mov      word ptr [eax + 0x18], dx
    L_f74b:
        mov      eax, dword ptr [ebp]
        mov      cx, word ptr [eax + 0x1a]
        mov      edx, ecx
        shr      edx, 0xa
        test     dl, 1
        je       L_f7e7
        mov      dx, word ptr [eax + 0x16]
        push     edx
        mov      dl, byte ptr [eax + 0xf]
        push     edx
        mov      dl, byte ptr [eax + 0xe]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 6]
        mov      dword ptr [esp + 0x2c], edx
        fild     dword ptr [esp + 0x2c]
        movsx    edx, word ptr [eax + 4]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x2c], edx
        mov      dx, word ptr [eax + 0x18]
        fild     dword ptr [esp + 0x2c]
        push     ecx
        fstp     dword ptr [esp]
        push     edx
        mov      dl, byte ptr [eax + 0x11]
        push     edx
        mov      dl, byte ptr [eax + 0x10]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 0xa]
        mov      dword ptr [esp + 0x40], edx
        fild     dword ptr [esp + 0x40]
        movsx    edx, word ptr [eax + 8]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x40], edx
        mov      dx, word ptr [eax + 0x14]
        fild     dword ptr [esp + 0x40]
        push     ecx
        fstp     dword ptr [esp]
        push     edx
        mov      dl, byte ptr [eax + 0xd]
        push     edx
        mov      dl, byte ptr [eax + 0xc]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 2]
        mov      dword ptr [esp + 0x54], edx
        fild     dword ptr [esp + 0x54]
        movsx    edx, word ptr [eax]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x54], edx
        fild     dword ptr [esp + 0x54]
        jmp      L_f869
    L_f7e7:
        mov      dx, word ptr [eax + 0x18]
        push     edx
        mov      dl, byte ptr [eax + 0x11]
        push     edx
        mov      dl, byte ptr [eax + 0x10]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 0xa]
        mov      dword ptr [esp + 0x2c], edx
        fild     dword ptr [esp + 0x2c]
        movsx    edx, word ptr [eax + 8]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x2c], edx
        mov      dx, word ptr [eax + 0x16]
        fild     dword ptr [esp + 0x2c]
        push     ecx
        fstp     dword ptr [esp]
        push     edx
        mov      dl, byte ptr [eax + 0xf]
        push     edx
        mov      dl, byte ptr [eax + 0xe]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 6]
        mov      dword ptr [esp + 0x40], edx
        fild     dword ptr [esp + 0x40]
        movsx    edx, word ptr [eax + 4]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x40], edx
        mov      dx, word ptr [eax + 0x14]
        fild     dword ptr [esp + 0x40]
        push     ecx
        fstp     dword ptr [esp]
        push     edx
        mov      dl, byte ptr [eax + 0xd]
        push     edx
        mov      dl, byte ptr [eax + 0xc]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 2]
        mov      dword ptr [esp + 0x54], edx
        fild     dword ptr [esp + 0x54]
        movsx    edx, word ptr [eax]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x54], edx
        fild     dword ptr [esp + 0x54]
    L_f869:
        mov      dl, byte ptr [eax + 0x1a]
        push     ecx
        shr      ecx, 7
        fstp     dword ptr [esp]
        and      ecx, 3
        and      dl, 0xf
        mov      cl, byte ptr [esp + ecx + 0x4c]
        push     ecx
        push     edx
        call     GlideTriColorFlush
        add      esp, 0x44
    L_f887:
        mov      eax, dword ptr [esp + 0x14]
        sub      ebp, 4
        dec      eax
        mov      dword ptr [esp + 0x14], eax
        jne      L_f573
        mov      dword ptr [g_viewportX], ebx
        mov      dword ptr [g_viewportY], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x10
        ret
    L_f8ad:
        call     Renderer_GetMode
        cmp      eax, 2
        jne      L_fc44
        xor      esi, esi
        xor      edi, edi
    L_f8bf:
        cmp      byte ptr [esi + g_dispatchSave1352], bl
        je       L_f8de
        mov      eax, dword ptr [g_dispatchSave1400]
        add      eax, edi
        push     eax
        push     esi
        call     PadEnumDeviceRebind
        add      esp, 8
        mov      byte ptr [esi + g_dispatchSave1352], bl
    L_f8de:
        add      edi, 0x20000
        inc      esi
        cmp      edi, 0x200000
        jl       L_f8bf
        mov      ecx, dword ptr [g_drawQueueSize]
        lea      eax, [ecx - 1]
        cmp      eax, ebx
        jl       L_033d
        lea      ebp, [eax*4 + g_dispatchSave1356]
        inc      eax
        mov      dword ptr [esp + 0x10], eax
    L_f90a:
        mov      eax, dword ptr [ebp]
        mov      cx, word ptr [eax + 0x1a]
        mov      dl, cl
        shr      dl, 5
        test     dl, 1
        je       L_faca
        mov      cx, word ptr [eax]
        mov      dx, word ptr [eax + 8]
        cmp      cx, dx
        jle      L_f94f
        movsx    ecx, dx
        mov      dword ptr [g_dispatchSave1378], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax]
        mov      dword ptr [g_dispatchSave1380], edx
        mov      cl, byte ptr [eax + 0x10]
        mov      dword ptr [g_dispatchSave1371], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xc]
        jmp      L_f972
    L_f94f:
        movsx    ecx, cx
        mov      dword ptr [g_dispatchSave1378], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1380], edx
        mov      cl, byte ptr [eax + 0xc]
        mov      dword ptr [g_dispatchSave1371], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
    L_f972:
        mov      dword ptr [g_dispatchSave1373], ecx
        mov      cx, word ptr [eax + 2]
        mov      dx, word ptr [eax + 0xa]
        cmp      cx, dx
        jle      L_f9aa
        movsx    ecx, dx
        mov      dword ptr [g_dispatchSave1381], ecx
        movsx    edx, word ptr [eax + 2]
        mov      dword ptr [g_dispatchSave1383], edx
        xor      edx, edx
        mov      dl, byte ptr [eax + 0x11]
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374], edx
        mov      bl, byte ptr [eax + 0xd]
        jmp      L_f9cd
    L_f9aa:
        movsx    ecx, cx
        mov      dword ptr [g_dispatchSave1381], ecx
        movsx    edx, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1383], edx
        xor      edx, edx
        mov      dl, byte ptr [eax + 0xd]
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374], edx
        mov      bl, byte ptr [eax + 0x11]
    L_f9cd:
        fild     dword ptr [g_dispatchSave1380]
        mov      dword ptr [g_dispatchSave1377], ebx
        mov      cx, word ptr [eax + 0x14]
        push     ecx
        push     ebx
        fstp     dword ptr [esp + 0x20]
        fild     dword ptr [g_dispatchSave1381]
        mov      bl, byte ptr [g_dispatchSave1373]
        mov      esi, dword ptr [esp + 0x20]
        push     ebx
        push     ecx
        fstp     dword ptr [esp + 0x2c]
        fild     dword ptr [g_dispatchSave1383]
        mov      edi, dword ptr [esp + 0x2c]
        mov      bl, dl
        fstp     dword ptr [esp]
        push     esi
        push     ecx
        push     ebx
        mov      bl, byte ptr [g_dispatchSave1373]
        push     ebx
        push     edi
        push     esi
        push     ecx
        mov      cl, byte ptr [g_dispatchSave1371]
        push     edx
        mov      dx, word ptr [eax + 0x1a]
        push     ecx
        fild     dword ptr [g_dispatchSave1378]
        shr      edx, 7
        and      edx, 3
        push     edi
        push     ecx
        mov      cl, byte ptr [esp + edx + 0x50]
        mov      dl, byte ptr [eax + 0x1a]
        fstp     dword ptr [esp]
        and      dl, 0xf
        push     ecx
        push     edx
        call     GlideTriBatchEmit
        fild     dword ptr [g_dispatchSave1383]
        mov      eax, dword ptr [ebp]
        mov      dl, byte ptr [g_dispatchSave1377]
        add      esp, 0x44
        mov      bl, dl
        fstp     dword ptr [esp + 0x1c]
        mov      cx, word ptr [eax + 0x14]
        mov      esi, dword ptr [esp + 0x1c]
        fild     dword ptr [g_dispatchSave1378]
        push     ecx
        push     ebx
        mov      bl, byte ptr [g_dispatchSave1371]
        fstp     dword ptr [esp + 0x20]
        mov      edi, dword ptr [esp + 0x20]
        push     ebx
        fild     dword ptr [g_dispatchSave1380]
        push     esi
        push     edi
        push     ecx
        push     edx
        mov      dl, byte ptr [g_dispatchSave1373]
        push     edx
        push     esi
        push     ecx
        mov      dl, bl
        fstp     dword ptr [esp]
        push     ecx
        mov      cl, byte ptr [g_dispatchSave1374]
        fild     dword ptr [g_dispatchSave1381]
        push     ecx
        push     edx
        push     ecx
        mov      cx, word ptr [eax + 0x1a]
        mov      al, byte ptr [eax + 0x1a]
        fstp     dword ptr [esp]
        shr      ecx, 7
        and      ecx, 3
        push     edi
        and      al, 0xf
        mov      dl, byte ptr [esp + ecx + 0x50]
        push     edx
        push     eax
        call     GlideTriBatchEmit
        add      esp, 0x44
        xor      ebx, ebx
        jmp      L_fc1e
    L_faca:
        test     cl, 0x10
        jne      L_fae2
        mov      cx, word ptr [eax + 0x14]
        mov      word ptr [eax + 0x16], cx
        mov      eax, dword ptr [ebp]
        mov      dx, word ptr [eax + 0x16]
        mov      word ptr [eax + 0x18], dx
    L_fae2:
        mov      eax, dword ptr [ebp]
        mov      cx, word ptr [eax + 0x1a]
        mov      edx, ecx
        shr      edx, 0xa
        test     dl, 1
        je       L_fb7e
        mov      dx, word ptr [eax + 0x16]
        push     edx
        mov      dl, byte ptr [eax + 0xf]
        push     edx
        mov      dl, byte ptr [eax + 0xe]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 6]
        mov      dword ptr [esp + 0x2c], edx
        fild     dword ptr [esp + 0x2c]
        movsx    edx, word ptr [eax + 4]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x2c], edx
        mov      dx, word ptr [eax + 0x18]
        fild     dword ptr [esp + 0x2c]
        push     ecx
        fstp     dword ptr [esp]
        push     edx
        mov      dl, byte ptr [eax + 0x11]
        push     edx
        mov      dl, byte ptr [eax + 0x10]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 0xa]
        mov      dword ptr [esp + 0x40], edx
        fild     dword ptr [esp + 0x40]
        movsx    edx, word ptr [eax + 8]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x40], edx
        mov      dx, word ptr [eax + 0x14]
        fild     dword ptr [esp + 0x40]
        push     ecx
        fstp     dword ptr [esp]
        push     edx
        mov      dl, byte ptr [eax + 0xd]
        push     edx
        mov      dl, byte ptr [eax + 0xc]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 2]
        mov      dword ptr [esp + 0x54], edx
        fild     dword ptr [esp + 0x54]
        movsx    edx, word ptr [eax]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x54], edx
        fild     dword ptr [esp + 0x54]
        jmp      L_fc00
    L_fb7e:
        mov      dx, word ptr [eax + 0x18]
        push     edx
        mov      dl, byte ptr [eax + 0x11]
        push     edx
        mov      dl, byte ptr [eax + 0x10]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 0xa]
        mov      dword ptr [esp + 0x2c], edx
        fild     dword ptr [esp + 0x2c]
        movsx    edx, word ptr [eax + 8]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x2c], edx
        mov      dx, word ptr [eax + 0x16]
        fild     dword ptr [esp + 0x2c]
        push     ecx
        fstp     dword ptr [esp]
        push     edx
        mov      dl, byte ptr [eax + 0xf]
        push     edx
        mov      dl, byte ptr [eax + 0xe]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 6]
        mov      dword ptr [esp + 0x40], edx
        fild     dword ptr [esp + 0x40]
        movsx    edx, word ptr [eax + 4]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x40], edx
        mov      dx, word ptr [eax + 0x14]
        fild     dword ptr [esp + 0x40]
        push     ecx
        fstp     dword ptr [esp]
        push     edx
        mov      dl, byte ptr [eax + 0xd]
        push     edx
        mov      dl, byte ptr [eax + 0xc]
        push     edx
        push     ecx
        movsx    edx, word ptr [eax + 2]
        mov      dword ptr [esp + 0x54], edx
        fild     dword ptr [esp + 0x54]
        movsx    edx, word ptr [eax]
        fstp     dword ptr [esp]
        mov      dword ptr [esp + 0x54], edx
        fild     dword ptr [esp + 0x54]
    L_fc00:
        mov      dl, byte ptr [eax + 0x1a]
        push     ecx
        shr      ecx, 7
        fstp     dword ptr [esp]
        and      ecx, 3
        and      dl, 0xf
        mov      cl, byte ptr [esp + ecx + 0x50]
        push     ecx
        push     edx
        call     GlideTriBatchEmit
        add      esp, 0x44
    L_fc1e:
        mov      eax, dword ptr [esp + 0x10]
        sub      ebp, 4
        dec      eax
        mov      dword ptr [esp + 0x10], eax
        jne      L_f90a
        mov      dword ptr [g_viewportX], ebx
        mov      dword ptr [g_viewportY], ebx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x10
        ret
    L_fc44:
        call     Renderer_GetMode
        cmp      eax, 5
        jne      L_ff9e
        mov      eax, dword ptr [g_drawQueueSize]
        dec      eax
        cmp      eax, ebx
        jl       L_033d
        lea      edx, [eax*4 + g_dispatchSave1356]
        inc      eax
        mov      dword ptr [esp + 0x1c], edx
        mov      dword ptr [esp + 0x18], eax
    L_fc70:
        mov      ecx, dword ptr [edx]
        movsx    eax, word ptr [ecx]
        mov      dword ptr [g_dispatchSave1378], eax
        movsx    eax, word ptr [ecx + 2]
        mov      dword ptr [g_dispatchSave1381], eax
        xor      eax, eax
        mov      al, byte ptr [ecx + 0xc]
        mov      dword ptr [g_dispatchSave1371], eax
        xor      eax, eax
        mov      al, byte ptr [ecx + 0xd]
        mov      dword ptr [g_dispatchSave1374], eax
        xor      eax, eax
        mov      ax, word ptr [ecx + 0x14]
        mov      edi, eax
        mov      esi, eax
        shr      edi, 0xa
        and      esi, 0x1f
        and      edi, 0x1f
        shr      eax, 5
        add      esi, edi
        and      eax, 0x1f
        mov      al, byte ptr [esi + eax + g_div3Table]
        shl      al, 3
        mov      byte ptr [g_dispatchSave1367], al
        mov      al, byte ptr [ecx + 0x1a]
        test     al, 0x10
        jne      L_fcda
        mov      ax, word ptr [ecx + 0x14]
        mov      word ptr [ecx + 0x16], ax
        mov      eax, dword ptr [edx]
        mov      cx, word ptr [eax + 0x16]
        mov      word ptr [eax + 0x18], cx
    L_fcda:
        mov      eax, dword ptr [edx]
        mov      cx, word ptr [eax + 0x1a]
        test     ch, 4
        je       L_fda3
        test     cl, 0x20
        jne      L_fda3
        movsx    edx, word ptr [eax + 4]
        mov      dword ptr [g_dispatchSave1380], edx
        movsx    esi, word ptr [eax + 6]
        mov      dword ptr [g_dispatchSave1383], esi
        movsx    ecx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1379], ecx
        movsx    ecx, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1382], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xe]
        mov      edi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1373], edi
        mov      cl, byte ptr [eax + 0xf]
        mov      dword ptr [g_dispatchSave1377], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
        mov      dword ptr [g_dispatchSave1372], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x11]
        mov      dword ptr [g_dispatchSave1376], ecx
        xor      ecx, ecx
        mov      cx, word ptr [eax + 0x16]
        mov      ebp, ecx
        mov      ebx, ecx
        shr      ebp, 0xa
        and      ebx, 0x1f
        and      ebp, 0x1f
        shr      ecx, 5
        add      ebx, ebp
        and      ecx, 0x1f
        mov      cl, byte ptr [ebx + ecx + g_div3Table]
        shl      cl, 3
        mov      byte ptr [g_dispatchSave1369], cl
        xor      ecx, ecx
        mov      cx, word ptr [eax + 0x18]
        mov      ebp, ecx
        mov      ebx, ecx
        shr      ebp, 5
        and      ebx, 0x1f
        and      ebp, 0x1f
        shr      ecx, 0xa
        add      ebx, ebp
        and      ecx, 0x1f
        mov      cl, byte ptr [ebx + ecx + g_div3Table]
        shl      cl, 3
        mov      byte ptr [g_dispatchSave1368], cl
        jmp      L_fe4f
    L_fda3:
        movsx    edx, word ptr [eax + 4]
        mov      dword ptr [g_dispatchSave1379], edx
        movsx    ecx, word ptr [eax + 6]
        mov      dword ptr [g_dispatchSave1382], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1380], edx
        movsx    esi, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1383], esi
        mov      cl, byte ptr [eax + 0xe]
        mov      dword ptr [g_dispatchSave1372], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xf]
        mov      dword ptr [g_dispatchSave1376], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
        mov      edi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1373], edi
        mov      cl, byte ptr [eax + 0x11]
        mov      dword ptr [g_dispatchSave1377], ecx
        xor      ecx, ecx
        mov      cx, word ptr [eax + 0x16]
        mov      ebp, ecx
        mov      ebx, ecx
        shr      ebp, 0xa
        and      ebx, 0x1f
        and      ebp, 0x1f
        shr      ecx, 5
        add      ebx, ebp
        and      ecx, 0x1f
        mov      cl, byte ptr [ebx + ecx + g_div3Table]
        shl      cl, 3
        mov      byte ptr [g_dispatchSave1368], cl
        xor      ecx, ecx
        mov      cx, word ptr [eax + 0x18]
        mov      ebp, ecx
        mov      ebx, ecx
        shr      ebp, 5
        and      ebx, 0x1f
        and      ebp, 0x1f
        shr      ecx, 0xa
        add      ebx, ebp
        and      ecx, 0x1f
        mov      cl, byte ptr [ebx + ecx + g_div3Table]
        shl      cl, 3
        mov      byte ptr [g_dispatchSave1369], cl
    L_fe4f:
        mov      cl, byte ptr [eax + 0x1a]
        and      ecx, 0xf
        mov      dword ptr [g_dispatchSave1403], ecx
        mov      cx, word ptr [eax + 0x1a]
        mov      bl, cl
        shr      bl, 5
        test     bl, 1
        je       L_ff38
        mov      ecx, dword ptr [g_dispatchSave1378]
        cmp      ecx, edx
        jle      L_fea1
        xor      ecx, edx
        xor      edx, ecx
        xor      ecx, edx
        mov      dword ptr [g_dispatchSave1380], edx
        mov      dword ptr [g_dispatchSave1378], ecx
        mov      ecx, dword ptr [g_dispatchSave1371]
        xor      ecx, edi
        xor      edi, ecx
        xor      ecx, edi
        mov      dword ptr [g_dispatchSave1373], edi
        mov      dword ptr [g_dispatchSave1371], ecx
    L_fea1:
        mov      ecx, dword ptr [g_dispatchSave1381]
        cmp      ecx, esi
        jle      L_fedb
        mov      edx, dword ptr [g_dispatchSave1377]
        xor      ecx, esi
        xor      esi, ecx
        xor      ecx, esi
        mov      dword ptr [g_dispatchSave1383], esi
        mov      dword ptr [g_dispatchSave1381], ecx
        mov      ecx, dword ptr [g_dispatchSave1374]
        xor      ecx, edx
        xor      edx, ecx
        xor      ecx, edx
        mov      dword ptr [g_dispatchSave1377], edx
        mov      dword ptr [g_dispatchSave1374], ecx
    L_fedb:
        cmp      word ptr [eax + 0x14], 0x7fff
        jae      L_feed
        call     ScanlineTexBlitPaletted
        jmp      L_ff7f
    L_feed:
        mov      ax, word ptr [eax + 0x1a]
        mov      ecx, eax
        and      ecx, 0x180
        cmp      cx, 0x80
        jne      L_ff07
        call     ScanlineTexBlitInterlaced
        jmp      L_ff7f
    L_ff07:
        cmp      cx, 0x100
        jne      L_ff15
        call     ScanlineTexBlitInterlaced
        jmp      L_ff7f
    L_ff15:
        cmp      cx, 0x180
        jne      L_ff23
        call     ScanlineTexBlitInterlaced
        jmp      L_ff7f
    L_ff23:
        shr      al, 6
        test     al, 1
        je       L_ff31
        call     BlitBlend16bpp
        jmp      L_ff7f
    L_ff31:
        call     ScanlineTexBlit
        jmp      L_ff7f
    L_ff38:
        cmp      word ptr [eax + 0x14], 0x7fff
        jb       L_ff7a
        test     cl, 0x10
        jne      L_ff7a
        mov      eax, ecx
        and      eax, 0x180
        cmp      ax, 0x80
        jne      L_ff59
        call     TexturedTriRasterizeDithered
        jmp      L_ff7f
    L_ff59:
        cmp      ax, 0x100
        jne      L_ff66
        call     TexturedTriRasterizeDithered
        jmp      L_ff7f
    L_ff66:
        cmp      ax, 0x180
        jne      L_ff73
        call     TexturedTriRasterizeDithered
        jmp      L_ff7f
    L_ff73:
        call     TexturedTriRasterize
        jmp      L_ff7f
    L_ff7a:
        call     TexturedTriRasterizeShaded
    L_ff7f:
        mov      edx, dword ptr [esp + 0x1c]
        mov      eax, dword ptr [esp + 0x18]
        sub      edx, 4
        dec      eax
        mov      dword ptr [esp + 0x1c], edx
        mov      dword ptr [esp + 0x18], eax
        jne      L_fc70
        jmp      L_033b
    L_ff9e:
        mov      edx, dword ptr [g_drawQueueSize]
        lea      eax, [edx - 1]
        cmp      eax, ebx
        jl       L_033d
        lea      edx, [eax*4 + g_dispatchSave1356]
        inc      eax
        mov      dword ptr [esp + 0x1c], edx
        mov      dword ptr [esp + 0x18], eax
    L_ffbf:
        mov      ecx, dword ptr [edx]
        movsx    eax, word ptr [ecx]
        mov      dword ptr [g_dispatchSave1378], eax
        movsx    eax, word ptr [ecx + 2]
        mov      dword ptr [g_dispatchSave1381], eax
        xor      eax, eax
        mov      al, byte ptr [ecx + 0xc]
        mov      dword ptr [g_dispatchSave1371], eax
        xor      eax, eax
        mov      al, byte ptr [ecx + 0xd]
        mov      dword ptr [g_dispatchSave1374], eax
        xor      eax, eax
        mov      ax, word ptr [ecx + 0x14]
        mov      edi, eax
        mov      esi, eax
        shr      edi, 0xa
        and      esi, 0x1f
        and      edi, 0x1f
        shr      eax, 5
        add      esi, edi
        and      eax, 0x1f
        mov      al, byte ptr [esi + eax + g_div3Table]
        shl      al, 3
        mov      byte ptr [g_dispatchSave1367], al
        mov      al, byte ptr [ecx + 0x1a]
        test     al, 0x10
        jne      L_0029
        mov      ax, word ptr [ecx + 0x14]
        mov      word ptr [ecx + 0x16], ax
        mov      eax, dword ptr [edx]
        mov      cx, word ptr [eax + 0x16]
        mov      word ptr [eax + 0x18], cx
    L_0029:
        mov      eax, dword ptr [edx]
        mov      cx, word ptr [eax + 0x1a]
        test     ch, 4
        je       L_00f2
        test     cl, 0x20
        jne      L_00f2
        movsx    edx, word ptr [eax + 4]
        mov      dword ptr [g_dispatchSave1380], edx
        movsx    esi, word ptr [eax + 6]
        mov      dword ptr [g_dispatchSave1383], esi
        movsx    ecx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1379], ecx
        movsx    ecx, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1382], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xe]
        mov      edi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1373], edi
        mov      cl, byte ptr [eax + 0xf]
        mov      dword ptr [g_dispatchSave1377], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
        mov      dword ptr [g_dispatchSave1372], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x11]
        mov      dword ptr [g_dispatchSave1376], ecx
        xor      ecx, ecx
        mov      cx, word ptr [eax + 0x16]
        mov      ebx, ecx
        mov      ebp, ecx
        shr      ebx, 0xa
        shr      ebp, 5
        and      ebx, 0x1f
        and      ebp, 0x1f
        add      ebx, ebp
        and      ecx, 0x1f
        mov      cl, byte ptr [ebx + ecx + g_div3Table]
        shl      cl, 3
        mov      byte ptr [g_dispatchSave1369], cl
        xor      ecx, ecx
        mov      cx, word ptr [eax + 0x18]
        mov      ebp, ecx
        mov      ebx, ecx
        shr      ebp, 0xa
        and      ebx, 0x1f
        and      ebp, 0x1f
        shr      ecx, 5
        add      ebx, ebp
        and      ecx, 0x1f
        mov      cl, byte ptr [ebx + ecx + g_div3Table]
        shl      cl, 3
        mov      byte ptr [g_dispatchSave1368], cl
        jmp      L_019e
    L_00f2:
        movsx    edx, word ptr [eax + 4]
        mov      dword ptr [g_dispatchSave1379], edx
        movsx    ecx, word ptr [eax + 6]
        mov      dword ptr [g_dispatchSave1382], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1380], edx
        movsx    esi, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1383], esi
        mov      cl, byte ptr [eax + 0xe]
        mov      dword ptr [g_dispatchSave1372], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xf]
        mov      dword ptr [g_dispatchSave1376], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
        mov      edi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1373], edi
        mov      cl, byte ptr [eax + 0x11]
        mov      dword ptr [g_dispatchSave1377], ecx
        xor      ecx, ecx
        mov      cx, word ptr [eax + 0x16]
        mov      ebx, ecx
        mov      ebp, ecx
        shr      ebx, 0xa
        shr      ebp, 5
        and      ebx, 0x1f
        and      ebp, 0x1f
        add      ebx, ebp
        and      ecx, 0x1f
        mov      cl, byte ptr [ebx + ecx + g_div3Table]
        shl      cl, 3
        mov      byte ptr [g_dispatchSave1368], cl
        xor      ecx, ecx
        mov      cx, word ptr [eax + 0x18]
        mov      ebp, ecx
        mov      ebx, ecx
        shr      ebp, 0xa
        and      ebx, 0x1f
        and      ebp, 0x1f
        shr      ecx, 5
        add      ebx, ebp
        and      ecx, 0x1f
        mov      cl, byte ptr [ebx + ecx + g_div3Table]
        shl      cl, 3
        mov      byte ptr [g_dispatchSave1369], cl
    L_019e:
        test     byte ptr [eax + 0x1b], 2
        jne      L_01ee
        mov      ebx, dword ptr [g_dispatchSave1379]
        mov      ebp, dword ptr [g_dispatchSave1378]
        mov      ecx, dword ptr [g_dispatchSave1381]
        sar      ebx, 1
        mov      dword ptr [g_dispatchSave1379], ebx
        mov      ebx, dword ptr [g_dispatchSave1382]
        sar      ebp, 1
        sar      ecx, 1
        sar      ebx, 1
        sar      edx, 1
        sar      esi, 1
        mov      dword ptr [g_dispatchSave1378], ebp
        mov      dword ptr [g_dispatchSave1381], ecx
        mov      dword ptr [g_dispatchSave1382], ebx
        mov      dword ptr [g_dispatchSave1380], edx
        mov      dword ptr [g_dispatchSave1383], esi
        jmp      L_01fa
    L_01ee:
        mov      ecx, dword ptr [g_dispatchSave1381]
        mov      ebp, dword ptr [g_dispatchSave1378]
    L_01fa:
        mov      bl, byte ptr [eax + 0x1a]
        and      ebx, 0xf
        mov      dword ptr [g_dispatchSave1403], ebx
        mov      bx, word ptr [eax + 0x1a]
        mov      dword ptr [esp + 0x14], ebx
        shr      bl, 5
        test     bl, 1
        je       L_02d9
        cmp      ebp, edx
        jle      L_0248
        xor      ebp, edx
        xor      edx, ebp
        mov      dword ptr [g_dispatchSave1380], edx
        xor      ebp, edx
        mov      edx, dword ptr [g_dispatchSave1371]
        mov      dword ptr [g_dispatchSave1378], ebp
        xor      edx, edi
        xor      edi, edx
        xor      edx, edi
        mov      dword ptr [g_dispatchSave1373], edi
        mov      dword ptr [g_dispatchSave1371], edx
    L_0248:
        cmp      ecx, esi
        jle      L_027c
        mov      edx, dword ptr [g_dispatchSave1377]
        xor      ecx, esi
        xor      esi, ecx
        xor      ecx, esi
        mov      dword ptr [g_dispatchSave1383], esi
        mov      dword ptr [g_dispatchSave1381], ecx
        mov      ecx, dword ptr [g_dispatchSave1374]
        xor      ecx, edx
        xor      edx, ecx
        xor      ecx, edx
        mov      dword ptr [g_dispatchSave1377], edx
        mov      dword ptr [g_dispatchSave1374], ecx
    L_027c:
        cmp      word ptr [eax + 0x14], 0x7fff
        jae      L_028e
        call     ScanlineTexBlitPaletted
        jmp      L_0321
    L_028e:
        mov      ax, word ptr [eax + 0x1a]
        mov      ecx, eax
        and      ecx, 0x180
        cmp      cx, 0x80
        jne      L_02a8
        call     ScanlineTexBlitAdditive
        jmp      L_0321
    L_02a8:
        cmp      cx, 0x100
        jne      L_02b6
        call     ScanlineTexBlitInterlaced
        jmp      L_0321
    L_02b6:
        cmp      cx, 0x180
        jne      L_02c4
        call     ScanlineTexBlitAlpha
        jmp      L_0321
    L_02c4:
        shr      al, 6
        test     al, 1
        je       L_02d2
        call     BlitBlend16bpp
        jmp      L_0321
    L_02d2:
        call     ScanlineTexBlit
        jmp      L_0321
    L_02d9:
        cmp      word ptr [eax + 0x14], 0x7fff
        jb       L_031c
        mov      eax, dword ptr [esp + 0x14]
        test     al, 0x10
        jne      L_031c
        and      eax, 0x180
        cmp      ax, 0x80
        jne      L_02fb
        call     TexturedTriRasterizeAlphaPal
        jmp      L_0321
    L_02fb:
        cmp      ax, 0x100
        jne      L_0308
        call     TexturedTriRasterizeDithered
        jmp      L_0321
    L_0308:
        cmp      ax, 0x180
        jne      L_0315
        call     TexturedTriRasterizeAlpha
        jmp      L_0321
    L_0315:
        call     TexturedTriRasterize
        jmp      L_0321
    L_031c:
        call     TexturedTriRasterizeShaded
    L_0321:
        mov      edx, dword ptr [esp + 0x1c]
        mov      eax, dword ptr [esp + 0x18]
        sub      edx, 4
        dec      eax
        mov      dword ptr [esp + 0x1c], edx
        mov      dword ptr [esp + 0x18], eax
        jne      L_ffbf
    L_033b:
        xor      ebx, ebx
    L_033d:
        pop      edi
        pop      esi
        mov      dword ptr [g_viewportX], ebx
        mov      dword ptr [g_viewportY], ebx
        pop      ebp
        pop      ebx
        add      esp, 0x10
        ret
    }
}
#endif

