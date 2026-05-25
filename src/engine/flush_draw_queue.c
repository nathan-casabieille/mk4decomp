/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern u32 g_drawQueueBuckets[];
extern unsigned int g_dispatchSave1349_00f6d052;
extern unsigned int g_dispatchSave1350_00f6e050;
extern unsigned int g_dispatchSave1352_00f6e058;
extern unsigned int g_dispatchSave1356_00f6e068;
extern unsigned int g_dispatchSave1367_00f70f7c;
extern unsigned int g_dispatchSave1368_00f70f7d;
extern unsigned int g_dispatchSave1369_00f70f7e;
extern unsigned int g_dispatchSave1371_00f70f88;
extern unsigned int g_dispatchSave1372_00f70f8c;
extern unsigned int g_dispatchSave1373_00f70f90;
extern unsigned int g_dispatchSave1374_00f70f98;
extern unsigned int g_dispatchSave1376_00f70f9c;
extern unsigned int g_dispatchSave1377_00f70fa0;
extern unsigned int g_dispatchSave1378_00f70fa8;
extern unsigned int g_dispatchSave1379_00f70fac;
extern unsigned int g_dispatchSave1380_00f70fb0;
extern unsigned int g_dispatchSave1381_00f70fb8;
extern unsigned int g_dispatchSave1382_00f70fbc;
extern unsigned int g_dispatchSave1383_00f70fc0;
extern unsigned int g_dispatchSave1398_00f71322;
extern unsigned int g_dispatchSave1400_00f85b34;
extern u32 g_drawQueueSize;
extern unsigned int g_dispatchSave1403_00f85b4c;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern void BlitBlend16bpp_004c05e0(void);
extern void DecodeTableAllocaCall_004b4450(void);
extern void GlideTriBatchEmit_004adca0(void);
extern void GlideTriColorFlush_004b46f0(void);
extern void PadEnumDeviceRebind_004ad850(void);
extern void ScanlineTexBlitAdditive_004c0e10(void);
extern void ScanlineTexBlitAlpha_004c0b70(void);
extern void ScanlineTexBlitInterlaced_004c1130(void);
extern void ScanlineTexBlitPaletted_004c0360(void);
extern void ScanlineTexBlit_004c0920(void);
extern void TexturedTriRasterizeAlphaPal_004c1fe0(void);
extern void TexturedTriRasterizeAlpha_004c19c0(void);
extern void TexturedTriRasterizeDithered_004c2650(void);
extern void TexturedTriRasterizeShaded_004c2cb0(void);
extern void TexturedTriRasterize_004c13f0(void);

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
        mov      ecx, OFFSET g_dispatchSave1398_00f71322
        mov      edx, esi
    L_f4ab:
        xor      eax, eax
        mov      ax, word ptr [ecx]
        add      ecx, 0x1c
        inc      word ptr [eax*2 + g_drawQueueBuckets]
        dec      edx
        jne      L_f4ab
    L_f4be:
        mov      eax, OFFSET g_dispatchSave1349_00f6d052
    L_f4c3:
        mov      cx, word ptr [eax - 2]
        add      word ptr [eax], cx
        add      eax, 2
        cmp      eax, OFFSET g_dispatchSave1350_00f6e050
        jl       L_f4c3
        lea      eax, [esi - 1]
        cmp      eax, ebx
        jl       L_f516
        mov      edx, eax
        shl      edx, 3
        sub      edx, eax
        lea      ecx, [edx*4 + g_dispatchSave1398_00f71322]
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
        mov      dword ptr [eax*4 + g_dispatchSave1356_00f6e068], esi
        jne      L_f4ec
    L_f516:
        call     Renderer_GetMode
        cmp      eax, 1
        jne      L_f8ad
        xor      esi, esi
        xor      edi, edi
    L_f528:
        cmp      byte ptr [esi + g_dispatchSave1352_00f6e058], bl
        je       L_f547
        mov      eax, dword ptr [g_dispatchSave1400_00f85b34]
        add      eax, edi
        push     eax
        push     esi
        call     DecodeTableAllocaCall_004b4450
        add      esp, 8
        mov      byte ptr [esi + g_dispatchSave1352_00f6e058], bl
    L_f547:
        add      edi, 0x20000
        inc      esi
        cmp      edi, 0x200000
        jl       L_f528
        mov      ecx, dword ptr [g_drawQueueSize]
        lea      eax, [ecx - 1]
        cmp      eax, ebx
        jl       L_033d
        lea      ebp, [eax*4 + g_dispatchSave1356_00f6e068]
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
        mov      dword ptr [g_dispatchSave1378_00f70fa8], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax]
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        mov      cl, byte ptr [eax + 0x10]
        mov      dword ptr [g_dispatchSave1371_00f70f88], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xc]
        jmp      L_f5db
    L_f5b8:
        movsx    ecx, cx
        mov      dword ptr [g_dispatchSave1378_00f70fa8], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        mov      cl, byte ptr [eax + 0xc]
        mov      dword ptr [g_dispatchSave1371_00f70f88], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
    L_f5db:
        mov      dword ptr [g_dispatchSave1373_00f70f90], ecx
        mov      cx, word ptr [eax + 2]
        mov      dx, word ptr [eax + 0xa]
        cmp      cx, dx
        jle      L_f613
        movsx    ecx, dx
        mov      dword ptr [g_dispatchSave1381_00f70fb8], ecx
        movsx    edx, word ptr [eax + 2]
        mov      dword ptr [g_dispatchSave1383_00f70fc0], edx
        xor      edx, edx
        mov      dl, byte ptr [eax + 0x11]
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374_00f70f98], edx
        mov      bl, byte ptr [eax + 0xd]
        jmp      L_f636
    L_f613:
        movsx    ecx, cx
        mov      dword ptr [g_dispatchSave1381_00f70fb8], ecx
        movsx    edx, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1383_00f70fc0], edx
        xor      edx, edx
        mov      dl, byte ptr [eax + 0xd]
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374_00f70f98], edx
        mov      bl, byte ptr [eax + 0x11]
    L_f636:
        fild     dword ptr [g_dispatchSave1380_00f70fb0]
        mov      dword ptr [g_dispatchSave1377_00f70fa0], ebx
        mov      cx, word ptr [eax + 0x14]
        push     ecx
        push     ebx
        fstp     dword ptr [esp + 0x20]
        fild     dword ptr [g_dispatchSave1381_00f70fb8]
        mov      bl, byte ptr [g_dispatchSave1373_00f70f90]
        mov      esi, dword ptr [esp + 0x20]
        push     ebx
        push     ecx
        fstp     dword ptr [esp + 0x2c]
        fild     dword ptr [g_dispatchSave1383_00f70fc0]
        mov      edi, dword ptr [esp + 0x2c]
        mov      bl, dl
        fstp     dword ptr [esp]
        push     esi
        push     ecx
        push     ebx
        mov      bl, byte ptr [g_dispatchSave1373_00f70f90]
        push     ebx
        push     edi
        push     esi
        push     ecx
        mov      cl, byte ptr [g_dispatchSave1371_00f70f88]
        push     edx
        mov      dx, word ptr [eax + 0x1a]
        push     ecx
        fild     dword ptr [g_dispatchSave1378_00f70fa8]
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
        call     GlideTriColorFlush_004b46f0
        fild     dword ptr [g_dispatchSave1383_00f70fc0]
        mov      eax, dword ptr [ebp]
        mov      dl, byte ptr [g_dispatchSave1377_00f70fa0]
        add      esp, 0x44
        mov      bl, dl
        fstp     dword ptr [esp + 0x1c]
        mov      cx, word ptr [eax + 0x14]
        mov      esi, dword ptr [esp + 0x1c]
        fild     dword ptr [g_dispatchSave1378_00f70fa8]
        push     ecx
        push     ebx
        mov      bl, byte ptr [g_dispatchSave1371_00f70f88]
        fstp     dword ptr [esp + 0x20]
        mov      edi, dword ptr [esp + 0x20]
        push     ebx
        fild     dword ptr [g_dispatchSave1380_00f70fb0]
        push     esi
        push     edi
        push     ecx
        push     edx
        mov      dl, byte ptr [g_dispatchSave1373_00f70f90]
        push     edx
        push     esi
        push     ecx
        mov      dl, bl
        fstp     dword ptr [esp]
        push     ecx
        mov      cl, byte ptr [g_dispatchSave1374_00f70f98]
        fild     dword ptr [g_dispatchSave1381_00f70fb8]
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
        call     GlideTriColorFlush_004b46f0
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
        call     GlideTriColorFlush_004b46f0
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
        cmp      byte ptr [esi + g_dispatchSave1352_00f6e058], bl
        je       L_f8de
        mov      eax, dword ptr [g_dispatchSave1400_00f85b34]
        add      eax, edi
        push     eax
        push     esi
        call     PadEnumDeviceRebind_004ad850
        add      esp, 8
        mov      byte ptr [esi + g_dispatchSave1352_00f6e058], bl
    L_f8de:
        add      edi, 0x20000
        inc      esi
        cmp      edi, 0x200000
        jl       L_f8bf
        mov      ecx, dword ptr [g_drawQueueSize]
        lea      eax, [ecx - 1]
        cmp      eax, ebx
        jl       L_033d
        lea      ebp, [eax*4 + g_dispatchSave1356_00f6e068]
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
        mov      dword ptr [g_dispatchSave1378_00f70fa8], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax]
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        mov      cl, byte ptr [eax + 0x10]
        mov      dword ptr [g_dispatchSave1371_00f70f88], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xc]
        jmp      L_f972
    L_f94f:
        movsx    ecx, cx
        mov      dword ptr [g_dispatchSave1378_00f70fa8], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        mov      cl, byte ptr [eax + 0xc]
        mov      dword ptr [g_dispatchSave1371_00f70f88], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
    L_f972:
        mov      dword ptr [g_dispatchSave1373_00f70f90], ecx
        mov      cx, word ptr [eax + 2]
        mov      dx, word ptr [eax + 0xa]
        cmp      cx, dx
        jle      L_f9aa
        movsx    ecx, dx
        mov      dword ptr [g_dispatchSave1381_00f70fb8], ecx
        movsx    edx, word ptr [eax + 2]
        mov      dword ptr [g_dispatchSave1383_00f70fc0], edx
        xor      edx, edx
        mov      dl, byte ptr [eax + 0x11]
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374_00f70f98], edx
        mov      bl, byte ptr [eax + 0xd]
        jmp      L_f9cd
    L_f9aa:
        movsx    ecx, cx
        mov      dword ptr [g_dispatchSave1381_00f70fb8], ecx
        movsx    edx, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1383_00f70fc0], edx
        xor      edx, edx
        mov      dl, byte ptr [eax + 0xd]
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374_00f70f98], edx
        mov      bl, byte ptr [eax + 0x11]
    L_f9cd:
        fild     dword ptr [g_dispatchSave1380_00f70fb0]
        mov      dword ptr [g_dispatchSave1377_00f70fa0], ebx
        mov      cx, word ptr [eax + 0x14]
        push     ecx
        push     ebx
        fstp     dword ptr [esp + 0x20]
        fild     dword ptr [g_dispatchSave1381_00f70fb8]
        mov      bl, byte ptr [g_dispatchSave1373_00f70f90]
        mov      esi, dword ptr [esp + 0x20]
        push     ebx
        push     ecx
        fstp     dword ptr [esp + 0x2c]
        fild     dword ptr [g_dispatchSave1383_00f70fc0]
        mov      edi, dword ptr [esp + 0x2c]
        mov      bl, dl
        fstp     dword ptr [esp]
        push     esi
        push     ecx
        push     ebx
        mov      bl, byte ptr [g_dispatchSave1373_00f70f90]
        push     ebx
        push     edi
        push     esi
        push     ecx
        mov      cl, byte ptr [g_dispatchSave1371_00f70f88]
        push     edx
        mov      dx, word ptr [eax + 0x1a]
        push     ecx
        fild     dword ptr [g_dispatchSave1378_00f70fa8]
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
        call     GlideTriBatchEmit_004adca0
        fild     dword ptr [g_dispatchSave1383_00f70fc0]
        mov      eax, dword ptr [ebp]
        mov      dl, byte ptr [g_dispatchSave1377_00f70fa0]
        add      esp, 0x44
        mov      bl, dl
        fstp     dword ptr [esp + 0x1c]
        mov      cx, word ptr [eax + 0x14]
        mov      esi, dword ptr [esp + 0x1c]
        fild     dword ptr [g_dispatchSave1378_00f70fa8]
        push     ecx
        push     ebx
        mov      bl, byte ptr [g_dispatchSave1371_00f70f88]
        fstp     dword ptr [esp + 0x20]
        mov      edi, dword ptr [esp + 0x20]
        push     ebx
        fild     dword ptr [g_dispatchSave1380_00f70fb0]
        push     esi
        push     edi
        push     ecx
        push     edx
        mov      dl, byte ptr [g_dispatchSave1373_00f70f90]
        push     edx
        push     esi
        push     ecx
        mov      dl, bl
        fstp     dword ptr [esp]
        push     ecx
        mov      cl, byte ptr [g_dispatchSave1374_00f70f98]
        fild     dword ptr [g_dispatchSave1381_00f70fb8]
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
        call     GlideTriBatchEmit_004adca0
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
        call     GlideTriBatchEmit_004adca0
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
        lea      edx, [eax*4 + g_dispatchSave1356_00f6e068]
        inc      eax
        mov      dword ptr [esp + 0x1c], edx
        mov      dword ptr [esp + 0x18], eax
    L_fc70:
        mov      ecx, dword ptr [edx]
        movsx    eax, word ptr [ecx]
        mov      dword ptr [g_dispatchSave1378_00f70fa8], eax
        movsx    eax, word ptr [ecx + 2]
        mov      dword ptr [g_dispatchSave1381_00f70fb8], eax
        xor      eax, eax
        mov      al, byte ptr [ecx + 0xc]
        mov      dword ptr [g_dispatchSave1371_00f70f88], eax
        xor      eax, eax
        mov      al, byte ptr [ecx + 0xd]
        mov      dword ptr [g_dispatchSave1374_00f70f98], eax
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
        mov      byte ptr [g_dispatchSave1367_00f70f7c], al
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
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        movsx    esi, word ptr [eax + 6]
        mov      dword ptr [g_dispatchSave1383_00f70fc0], esi
        movsx    ecx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1379_00f70fac], ecx
        movsx    ecx, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1382_00f70fbc], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xe]
        mov      edi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1373_00f70f90], edi
        mov      cl, byte ptr [eax + 0xf]
        mov      dword ptr [g_dispatchSave1377_00f70fa0], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
        mov      dword ptr [g_dispatchSave1372_00f70f8c], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x11]
        mov      dword ptr [g_dispatchSave1376_00f70f9c], ecx
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
        mov      byte ptr [g_dispatchSave1369_00f70f7e], cl
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
        mov      byte ptr [g_dispatchSave1368_00f70f7d], cl
        jmp      L_fe4f
    L_fda3:
        movsx    edx, word ptr [eax + 4]
        mov      dword ptr [g_dispatchSave1379_00f70fac], edx
        movsx    ecx, word ptr [eax + 6]
        mov      dword ptr [g_dispatchSave1382_00f70fbc], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        movsx    esi, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1383_00f70fc0], esi
        mov      cl, byte ptr [eax + 0xe]
        mov      dword ptr [g_dispatchSave1372_00f70f8c], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xf]
        mov      dword ptr [g_dispatchSave1376_00f70f9c], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
        mov      edi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1373_00f70f90], edi
        mov      cl, byte ptr [eax + 0x11]
        mov      dword ptr [g_dispatchSave1377_00f70fa0], ecx
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
        mov      byte ptr [g_dispatchSave1368_00f70f7d], cl
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
        mov      byte ptr [g_dispatchSave1369_00f70f7e], cl
    L_fe4f:
        mov      cl, byte ptr [eax + 0x1a]
        and      ecx, 0xf
        mov      dword ptr [g_dispatchSave1403_00f85b4c], ecx
        mov      cx, word ptr [eax + 0x1a]
        mov      bl, cl
        shr      bl, 5
        test     bl, 1
        je       L_ff38
        mov      ecx, dword ptr [g_dispatchSave1378_00f70fa8]
        cmp      ecx, edx
        jle      L_fea1
        xor      ecx, edx
        xor      edx, ecx
        xor      ecx, edx
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        mov      dword ptr [g_dispatchSave1378_00f70fa8], ecx
        mov      ecx, dword ptr [g_dispatchSave1371_00f70f88]
        xor      ecx, edi
        xor      edi, ecx
        xor      ecx, edi
        mov      dword ptr [g_dispatchSave1373_00f70f90], edi
        mov      dword ptr [g_dispatchSave1371_00f70f88], ecx
    L_fea1:
        mov      ecx, dword ptr [g_dispatchSave1381_00f70fb8]
        cmp      ecx, esi
        jle      L_fedb
        mov      edx, dword ptr [g_dispatchSave1377_00f70fa0]
        xor      ecx, esi
        xor      esi, ecx
        xor      ecx, esi
        mov      dword ptr [g_dispatchSave1383_00f70fc0], esi
        mov      dword ptr [g_dispatchSave1381_00f70fb8], ecx
        mov      ecx, dword ptr [g_dispatchSave1374_00f70f98]
        xor      ecx, edx
        xor      edx, ecx
        xor      ecx, edx
        mov      dword ptr [g_dispatchSave1377_00f70fa0], edx
        mov      dword ptr [g_dispatchSave1374_00f70f98], ecx
    L_fedb:
        cmp      word ptr [eax + 0x14], 0x7fff
        jae      L_feed
        call     ScanlineTexBlitPaletted_004c0360
        jmp      L_ff7f
    L_feed:
        mov      ax, word ptr [eax + 0x1a]
        mov      ecx, eax
        and      ecx, 0x180
        cmp      cx, 0x80
        jne      L_ff07
        call     ScanlineTexBlitInterlaced_004c1130
        jmp      L_ff7f
    L_ff07:
        cmp      cx, 0x100
        jne      L_ff15
        call     ScanlineTexBlitInterlaced_004c1130
        jmp      L_ff7f
    L_ff15:
        cmp      cx, 0x180
        jne      L_ff23
        call     ScanlineTexBlitInterlaced_004c1130
        jmp      L_ff7f
    L_ff23:
        shr      al, 6
        test     al, 1
        je       L_ff31
        call     BlitBlend16bpp_004c05e0
        jmp      L_ff7f
    L_ff31:
        call     ScanlineTexBlit_004c0920
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
        call     TexturedTriRasterizeDithered_004c2650
        jmp      L_ff7f
    L_ff59:
        cmp      ax, 0x100
        jne      L_ff66
        call     TexturedTriRasterizeDithered_004c2650
        jmp      L_ff7f
    L_ff66:
        cmp      ax, 0x180
        jne      L_ff73
        call     TexturedTriRasterizeDithered_004c2650
        jmp      L_ff7f
    L_ff73:
        call     TexturedTriRasterize_004c13f0
        jmp      L_ff7f
    L_ff7a:
        call     TexturedTriRasterizeShaded_004c2cb0
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
        lea      edx, [eax*4 + g_dispatchSave1356_00f6e068]
        inc      eax
        mov      dword ptr [esp + 0x1c], edx
        mov      dword ptr [esp + 0x18], eax
    L_ffbf:
        mov      ecx, dword ptr [edx]
        movsx    eax, word ptr [ecx]
        mov      dword ptr [g_dispatchSave1378_00f70fa8], eax
        movsx    eax, word ptr [ecx + 2]
        mov      dword ptr [g_dispatchSave1381_00f70fb8], eax
        xor      eax, eax
        mov      al, byte ptr [ecx + 0xc]
        mov      dword ptr [g_dispatchSave1371_00f70f88], eax
        xor      eax, eax
        mov      al, byte ptr [ecx + 0xd]
        mov      dword ptr [g_dispatchSave1374_00f70f98], eax
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
        mov      byte ptr [g_dispatchSave1367_00f70f7c], al
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
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        movsx    esi, word ptr [eax + 6]
        mov      dword ptr [g_dispatchSave1383_00f70fc0], esi
        movsx    ecx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1379_00f70fac], ecx
        movsx    ecx, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1382_00f70fbc], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xe]
        mov      edi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1373_00f70f90], edi
        mov      cl, byte ptr [eax + 0xf]
        mov      dword ptr [g_dispatchSave1377_00f70fa0], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
        mov      dword ptr [g_dispatchSave1372_00f70f8c], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x11]
        mov      dword ptr [g_dispatchSave1376_00f70f9c], ecx
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
        mov      byte ptr [g_dispatchSave1369_00f70f7e], cl
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
        mov      byte ptr [g_dispatchSave1368_00f70f7d], cl
        jmp      L_019e
    L_00f2:
        movsx    edx, word ptr [eax + 4]
        mov      dword ptr [g_dispatchSave1379_00f70fac], edx
        movsx    ecx, word ptr [eax + 6]
        mov      dword ptr [g_dispatchSave1382_00f70fbc], ecx
        xor      ecx, ecx
        movsx    edx, word ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        movsx    esi, word ptr [eax + 0xa]
        mov      dword ptr [g_dispatchSave1383_00f70fc0], esi
        mov      cl, byte ptr [eax + 0xe]
        mov      dword ptr [g_dispatchSave1372_00f70f8c], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0xf]
        mov      dword ptr [g_dispatchSave1376_00f70f9c], ecx
        xor      ecx, ecx
        mov      cl, byte ptr [eax + 0x10]
        mov      edi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1373_00f70f90], edi
        mov      cl, byte ptr [eax + 0x11]
        mov      dword ptr [g_dispatchSave1377_00f70fa0], ecx
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
        mov      byte ptr [g_dispatchSave1368_00f70f7d], cl
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
        mov      byte ptr [g_dispatchSave1369_00f70f7e], cl
    L_019e:
        test     byte ptr [eax + 0x1b], 2
        jne      L_01ee
        mov      ebx, dword ptr [g_dispatchSave1379_00f70fac]
        mov      ebp, dword ptr [g_dispatchSave1378_00f70fa8]
        mov      ecx, dword ptr [g_dispatchSave1381_00f70fb8]
        sar      ebx, 1
        mov      dword ptr [g_dispatchSave1379_00f70fac], ebx
        mov      ebx, dword ptr [g_dispatchSave1382_00f70fbc]
        sar      ebp, 1
        sar      ecx, 1
        sar      ebx, 1
        sar      edx, 1
        sar      esi, 1
        mov      dword ptr [g_dispatchSave1378_00f70fa8], ebp
        mov      dword ptr [g_dispatchSave1381_00f70fb8], ecx
        mov      dword ptr [g_dispatchSave1382_00f70fbc], ebx
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        mov      dword ptr [g_dispatchSave1383_00f70fc0], esi
        jmp      L_01fa
    L_01ee:
        mov      ecx, dword ptr [g_dispatchSave1381_00f70fb8]
        mov      ebp, dword ptr [g_dispatchSave1378_00f70fa8]
    L_01fa:
        mov      bl, byte ptr [eax + 0x1a]
        and      ebx, 0xf
        mov      dword ptr [g_dispatchSave1403_00f85b4c], ebx
        mov      bx, word ptr [eax + 0x1a]
        mov      dword ptr [esp + 0x14], ebx
        shr      bl, 5
        test     bl, 1
        je       L_02d9
        cmp      ebp, edx
        jle      L_0248
        xor      ebp, edx
        xor      edx, ebp
        mov      dword ptr [g_dispatchSave1380_00f70fb0], edx
        xor      ebp, edx
        mov      edx, dword ptr [g_dispatchSave1371_00f70f88]
        mov      dword ptr [g_dispatchSave1378_00f70fa8], ebp
        xor      edx, edi
        xor      edi, edx
        xor      edx, edi
        mov      dword ptr [g_dispatchSave1373_00f70f90], edi
        mov      dword ptr [g_dispatchSave1371_00f70f88], edx
    L_0248:
        cmp      ecx, esi
        jle      L_027c
        mov      edx, dword ptr [g_dispatchSave1377_00f70fa0]
        xor      ecx, esi
        xor      esi, ecx
        xor      ecx, esi
        mov      dword ptr [g_dispatchSave1383_00f70fc0], esi
        mov      dword ptr [g_dispatchSave1381_00f70fb8], ecx
        mov      ecx, dword ptr [g_dispatchSave1374_00f70f98]
        xor      ecx, edx
        xor      edx, ecx
        xor      ecx, edx
        mov      dword ptr [g_dispatchSave1377_00f70fa0], edx
        mov      dword ptr [g_dispatchSave1374_00f70f98], ecx
    L_027c:
        cmp      word ptr [eax + 0x14], 0x7fff
        jae      L_028e
        call     ScanlineTexBlitPaletted_004c0360
        jmp      L_0321
    L_028e:
        mov      ax, word ptr [eax + 0x1a]
        mov      ecx, eax
        and      ecx, 0x180
        cmp      cx, 0x80
        jne      L_02a8
        call     ScanlineTexBlitAdditive_004c0e10
        jmp      L_0321
    L_02a8:
        cmp      cx, 0x100
        jne      L_02b6
        call     ScanlineTexBlitInterlaced_004c1130
        jmp      L_0321
    L_02b6:
        cmp      cx, 0x180
        jne      L_02c4
        call     ScanlineTexBlitAlpha_004c0b70
        jmp      L_0321
    L_02c4:
        shr      al, 6
        test     al, 1
        je       L_02d2
        call     BlitBlend16bpp_004c05e0
        jmp      L_0321
    L_02d2:
        call     ScanlineTexBlit_004c0920
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
        call     TexturedTriRasterizeAlphaPal_004c1fe0
        jmp      L_0321
    L_02fb:
        cmp      ax, 0x100
        jne      L_0308
        call     TexturedTriRasterizeDithered_004c2650
        jmp      L_0321
    L_0308:
        cmp      ax, 0x180
        jne      L_0315
        call     TexturedTriRasterizeAlpha_004c19c0
        jmp      L_0321
    L_0315:
        call     TexturedTriRasterize_004c13f0
        jmp      L_0321
    L_031c:
        call     TexturedTriRasterizeShaded_004c2cb0
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

