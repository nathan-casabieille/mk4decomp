/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_data_004f48af;
extern unsigned int g_data_004f48cf;
extern unsigned int g_data_004f49f0;
extern unsigned int g_data_004f4a30;
extern void Helper_ChkStk(void);

__declspec(naked) void ECM_DecodeFrame_Huffman(void)
{
    __asm {
        mov      eax, 0x2434
        call     Helper_ChkStk
        mov      ecx, dword ptr [esp + 0x2438]
        push     ebx
        push     ebp
        push     esi
        mov      esi, dword ptr [ecx + 4]
        mov      edx, dword ptr [ecx + 8]
        mov      ebp, dword ptr [ecx]
        add      esi, 0xc
        push     edi
        lea      eax, [esi + edx - 1]
        cmp      eax, ebp
        jb       L_12c7
        mov      edi, dword ptr [ecx + 0xc]
        lea      ebx, [ebp + edi - 1]
        cmp      eax, ebx
        ja       L_12c7
        mov      eax, ebp
        sub      eax, edx
        add      eax, edi
        xor      edi, edi
        sub      esi, eax
    L_12ad:
        mov      dl, byte ptr [esi + eax]
        inc      edi
        mov      byte ptr [eax], dl
        mov      edx, dword ptr [ecx + 8]
        inc      eax
        cmp      edi, edx
        jb       L_12ad
        mov      edx, dword ptr [ecx + 0xc]
        mov      eax, dword ptr [ecx + 8]
        add      ebp, edx
        sub      ebp, eax
        mov      esi, ebp
    L_12c7:
        mov      edx, dword ptr [esi]
        mov      edi, dword ptr [esi + 4]
        mov      eax, dword ptr [ecx]
        add      esi, 4
        add      esi, 4
        mov      ebp, 0x20
        mov      dword ptr [esp + 0x20], edi
        mov      dword ptr [esp + 0x18], esi
        mov      dword ptr [esp + 0x2c], eax
        mov      dword ptr [esp + 0x38], 0
    L_12ed:
        dec      ebp
        jns      L_1318
        mov      ebx, edx
        mov      edx, edi
        mov      edi, dword ptr [esi]
        lea      ecx, [ebp + 1]
        mov      eax, edx
        add      esi, 4
        shl      eax, cl
        mov      ecx, ebp
        mov      dword ptr [esp + 0x20], edi
        neg      ecx
        shr      edx, cl
        add      eax, ebx
        mov      dword ptr [esp + 0x18], esi
        and      eax, 1
        add      ebp, 0x20
        jmp      L_131f
    L_1318:
        mov      eax, edx
        and      eax, 1
        shr      edx, 1
    L_131f:
        test     eax, eax
        jne      L_13d7
        sub      ebp, 0xf
        jns      L_1356
        mov      ecx, dword ptr [esi]
        mov      ebx, edx
        mov      edx, edi
        mov      dword ptr [esp + 0x20], ecx
        lea      ecx, [ebp + 0xf]
        mov      eax, edx
        shl      eax, cl
        mov      ecx, ebp
        add      esi, 4
        neg      ecx
        shr      edx, cl
        add      eax, ebx
        mov      dword ptr [esp + 0x18], esi
        and      eax, 0x7fff
        add      ebp, 0x20
        jmp      L_1360
    L_1356:
        mov      eax, edx
        and      eax, 0x7fff
        shr      edx, 0xf
    L_1360:
        mov      ecx, eax
        dec      eax
        test     ecx, ecx
        je       L_1b6c
        mov      ebx, dword ptr [esp + 0x20]
        inc      eax
        lea      esi, [ebp + 8]
        mov      dword ptr [esp + 0x30], eax
    L_1377:
        sub      esi, 8
        sub      ebp, 8
        cmp      esi, 8
        jge      L_13ae
        mov      eax, dword ptr [esp + 0x18]
        mov      edi, edx
        mov      edx, ebx
        mov      ecx, esi
        mov      ebx, dword ptr [eax]
        add      eax, 4
        mov      dword ptr [esp + 0x18], eax
        mov      eax, edx
        shl      eax, cl
        mov      ecx, ebp
        add      ebp, 0x20
        neg      ecx
        shr      edx, cl
        add      eax, edi
        and      eax, 0xff
        add      esi, 0x20
        jmp      L_13b8
    L_13ae:
        mov      eax, edx
        and      eax, 0xff
        shr      edx, 8
    L_13b8:
        mov      ecx, dword ptr [esp + 0x2c]
        mov      byte ptr [ecx], al
        mov      eax, dword ptr [esp + 0x30]
        inc      ecx
        dec      eax
        mov      dword ptr [esp + 0x2c], ecx
        mov      dword ptr [esp + 0x30], eax
        jne      L_1377
        mov      dword ptr [esp + 0x20], ebx
        jmp      L_1b6c
    L_13d7:
        mov      dword ptr [esp + 0x30], 1
    L_13df:
        lea      eax, [esp + 0x1244]
        mov      dword ptr [esp + 0x28], 8
        mov      dword ptr [esp + 0x3c], eax
        mov      eax, dword ptr [esp + 0x30]
        mov      ecx, eax
        dec      eax
        test     ecx, ecx
        mov      dword ptr [esp + 0x30], eax
        je       L_1414
        lea      eax, [esp + 0x1844]
        mov      dword ptr [esp + 0x28], 0xa
        mov      dword ptr [esp + 0x3c], eax
    L_1414:
        sub      ebp, 9
        jns      L_1449
        mov      eax, dword ptr [esp + 0x18]
        mov      esi, edx
        mov      edx, dword ptr [esp + 0x20]
        mov      ecx, dword ptr [eax]
        add      eax, 4
        mov      dword ptr [esp + 0x20], ecx
        mov      dword ptr [esp + 0x18], eax
        lea      ecx, [ebp + 9]
        mov      eax, edx
        shl      eax, cl
        mov      ecx, ebp
        neg      ecx
        shr      edx, cl
        add      eax, esi
        and      eax, 0x1ff
        add      ebp, 0x20
        jmp      L_1453
    L_1449:
        mov      eax, edx
        and      eax, 0x1ff
        shr      edx, 9
    L_1453:
        test     eax, eax
        mov      dword ptr [esp + 0x1c], eax
        je       L_193e
        mov      ebx, dword ptr [esp + 0x38]
        mov      ecx, 0x20
        xor      eax, eax
        lea      edi, [esp + 0x50]
        rep stosd
        mov      dword ptr [esp + 0x14], eax
        lea      eax, [esp + 0xd0]
        lea      edi, [ebp + 4]
        lea      esi, [ebp + 1]
        mov      dword ptr [esp + 0x10], eax
    L_1485:
        dec      ebp
        dec      esi
        dec      edi
        cmp      esi, 1
        jge      L_14c4
        mov      eax, dword ptr [esp + 0x18]
        mov      ebx, edx
        mov      edx, dword ptr [esp + 0x20]
        mov      ecx, dword ptr [eax]
        add      eax, 4
        mov      dword ptr [esp + 0x20], ecx
        mov      dword ptr [esp + 0x18], eax
        mov      eax, edx
        mov      ecx, esi
        shl      eax, cl
        mov      ecx, ebp
        add      ebp, 0x20
        neg      ecx
        shr      edx, cl
        add      eax, ebx
        mov      ebx, dword ptr [esp + 0x38]
        and      eax, 1
        add      esi, 0x20
        add      edi, 0x20
        jmp      L_14cb
    L_14c4:
        mov      eax, edx
        and      eax, 1
        shr      edx, 1
    L_14cb:
        cmp      eax, 1
        jne      L_1520
        sub      esi, 4
        sub      ebp, 4
        sub      edi, 4
        cmp      esi, eax
        jge      L_1514
        mov      ecx, dword ptr [esp + 0x18]
        mov      eax, edx
        mov      edx, dword ptr [esp + 0x20]
        add      esi, 0x20
        mov      ebx, dword ptr [ecx]
        add      ecx, 4
        mov      dword ptr [esp + 0x20], ebx
        mov      dword ptr [esp + 0x18], ecx
        mov      ebx, edx
        mov      ecx, edi
        shl      ebx, cl
        mov      ecx, ebp
        add      ebp, 0x20
        neg      ecx
        shr      edx, cl
        add      ebx, eax
        and      ebx, 0xf
        add      edi, 0x20
        mov      dword ptr [esp + 0x38], ebx
        jmp      L_1520
    L_1514:
        mov      ebx, edx
        and      ebx, 0xf
        mov      dword ptr [esp + 0x38], ebx
        shr      edx, 4
    L_1520:
        mov      ecx, dword ptr [esp + 0x14]
        mov      eax, dword ptr [esp + 0x10]
        inc      ecx
        mov      dword ptr [esp + 0x14], ecx
        mov      ecx, dword ptr [esp + ebx*4 + 0x4c]
        mov      dword ptr [eax], ebx
        add      eax, 4
        inc      ecx
        mov      dword ptr [esp + 0x10], eax
        mov      eax, dword ptr [esp + 0x14]
        mov      dword ptr [esp + ebx*4 + 0x4c], ecx
        mov      ecx, dword ptr [esp + 0x1c]
        cmp      eax, ecx
        jb       L_1485
        xor      ebx, ebx
        mov      dword ptr [esp + 0x34], edx
        mov      dword ptr [esp + 0x44], ebp
        mov      dword ptr [esp + 0x4c], ebx
        mov      dword ptr [esp + 0x14], 1
    L_1565:
        xor      eax, eax
        test     ecx, ecx
        jbe      L_1593
        lea      esi, [esp + ebx*4 + 0x9c8]
        lea      edi, [esp + 0xd0]
    L_1579:
        mov      ecx, dword ptr [esp + 0x14]
        cmp      dword ptr [edi], ecx
        jne      L_1587
        mov      dword ptr [esi], eax
        inc      ebx
        add      esi, 4
    L_1587:
        mov      ecx, dword ptr [esp + 0x1c]
        inc      eax
        add      edi, 4
        cmp      eax, ecx
        jb       L_1579
    L_1593:
        mov      eax, dword ptr [esp + 0x14]
        inc      eax
        cmp      eax, 0xf
        mov      dword ptr [esp + 0x14], eax
        jbe      L_1565
        xor      ecx, ecx
        lea      esi, [esp + 0x50]
        mov      dword ptr [esp + 0x14], ecx
        mov      eax, 1
        mov      dword ptr [esp + 0x10], esi
    L_15b4:
        mov      esi, dword ptr [esp + 0x10]
        mov      esi, dword ptr [esi]
        cmp      esi, 1
        jb       L_15d4
        lea      edi, [esp + ecx*4 + 0xd0]
        mov      ecx, esi
        rep stosd
        mov      ecx, dword ptr [esp + 0x14]
        add      ecx, esi
        mov      dword ptr [esp + 0x14], ecx
    L_15d4:
        mov      edi, dword ptr [esp + 0x10]
        inc      eax
        add      edi, 4
        cmp      eax, 0xf
        mov      dword ptr [esp + 0x10], edi
        jbe      L_15b4
        xor      eax, eax
        xor      edi, edi
        mov      dword ptr [esp + ecx*4 + 0xd0], eax
        mov      ecx, dword ptr [esp + 0xd0]
        cmp      ecx, eax
        mov      dword ptr [esp + 0x10], ecx
        mov      dword ptr [esp + 0x14], eax
        je       L_167d
    L_1603:
        lea      ebx, [eax*4]
        cmp      dword ptr [esp + ebx + 0xd0], ecx
        jne      L_166b
        mov      esi, 1
        shl      esi, cl
        mov      dword ptr [esp + 0x40], esi
        jmp      L_1624
    L_1620:
        mov      esi, dword ptr [esp + 0x40]
    L_1624:
        mov      eax, edi
        mov      dword ptr [esp + ebx + 0x54c], 0
        or       eax, esi
        lea      esi, [esp + ebx + 0x54c]
        inc      edi
    L_163b:
        mov      ebx, dword ptr [esi]
        mov      ecx, eax
        and      ecx, 1
        shr      eax, 1
        lea      ecx, [ecx + ebx*2]
        cmp      eax, 1
        mov      dword ptr [esi], ecx
        jne      L_163b
        mov      eax, dword ptr [esp + 0x14]
        mov      ecx, dword ptr [esp + 0x10]
        inc      eax
        mov      dword ptr [esp + 0x14], eax
        lea      ebx, [eax*4]
        cmp      dword ptr [esp + ebx + 0xd0], ecx
        je       L_1620
    L_166b:
        mov      esi, dword ptr [esp + eax*4 + 0xd0]
        shl      edi, 1
        inc      ecx
        test     esi, esi
        mov      dword ptr [esp + 0x10], ecx
        jne      L_1603
    L_167d:
        mov      edi, dword ptr [esp + 0x28]
        mov      esi, 1
        mov      ecx, edi
        xor      eax, eax
        shl      esi, cl
        mov      dword ptr [esp + 0x40], esi
    L_1690:
        mov      byte ptr [esp + eax + 0xe44], 0
        inc      eax
        cmp      eax, esi
        jb       L_1690
        mov      ecx, 1
        xor      ebx, ebx
        cmp      edi, ecx
        mov      dword ptr [esp + 0x14], ebx
        mov      dword ptr [esp + 0x10], ecx
        jbe      L_1742
        lea      eax, [esp + 0x50]
        mov      dword ptr [esp + 0x1c], eax
    L_16bc:
        mov      eax, dword ptr [esp + 0x1c]
        mov      eax, dword ptr [eax]
        cmp      eax, 1
        jb       L_1726
        mov      ebp, 1
        mov      dword ptr [esp + 0x24], eax
        shl      ebp, cl
        jmp      L_16d8
    L_16d4:
        mov      ecx, dword ptr [esp + 0x10]
    L_16d8:
        lea      edi, [ebx*4]
        lea      ebx, [ebp + ebp]
        mov      eax, dword ptr [esp + edi + 0x54c]
        mov      di, word ptr [esp + edi + 0x9c8]
        shl      di, 7
        add      ecx, edi
        mov      edi, dword ptr [esp + 0x3c]
        lea      edi, [edi + eax*2]
    L_16ff:
        mov      word ptr [edi], cx
        add      eax, ebp
        add      edi, ebx
        cmp      eax, esi
        jb       L_16ff
        mov      ebx, dword ptr [esp + 0x14]
        mov      eax, dword ptr [esp + 0x24]
        inc      ebx
        dec      eax
        mov      dword ptr [esp + 0x14], ebx
        mov      dword ptr [esp + 0x24], eax
        jne      L_16d4
        mov      ebp, dword ptr [esp + 0x44]
        mov      ecx, dword ptr [esp + 0x10]
    L_1726:
        mov      edi, dword ptr [esp + 0x1c]
        mov      eax, dword ptr [esp + 0x28]
        inc      ecx
        add      edi, 4
        cmp      ecx, eax
        mov      dword ptr [esp + 0x10], ecx
        mov      dword ptr [esp + 0x1c], edi
        jb       L_16bc
    L_1742:
        cmp      ecx, 0xf
        mov      dword ptr [esp + 0x48], ebx
        ja       L_17b3
        lea      eax, [esp + ecx*4 + 0x4c]
        mov      dword ptr [esp + 0x10], eax
        mov      eax, 0x10
        sub      eax, ecx
        mov      dword ptr [esp + 0x1c], eax
    L_175e:
        mov      ecx, dword ptr [esp + 0x10]
        mov      eax, dword ptr [ecx]
        cmp      eax, 1
        jb       L_179d
        mov      dword ptr [esp + 0x24], eax
    L_176d:
        mov      eax, dword ptr [esp + ebx*4 + 0x54c]
        mov      ecx, dword ptr [esp + ebx*4 + 0xd0]
        lea      edi, [esi - 1]
        and      eax, edi
        lea      edi, [esp + eax + 0xe44]
        xor      eax, eax
        mov      al, byte ptr [edi]
        cmp      ecx, eax
        jbe      L_1791
        mov      byte ptr [edi], cl
    L_1791:
        mov      eax, dword ptr [esp + 0x24]
        inc      ebx
        dec      eax
        mov      dword ptr [esp + 0x24], eax
        jne      L_176d
    L_179d:
        mov      ecx, dword ptr [esp + 0x10]
        mov      eax, dword ptr [esp + 0x1c]
        add      ecx, 4
        dec      eax
        mov      dword ptr [esp + 0x10], ecx
        mov      dword ptr [esp + 0x1c], eax
        jne      L_175e
    L_17b3:
        mov      eax, dword ptr [esp + 0x3c]
        mov      edi, dword ptr [esp + 0x28]
        xor      ebx, ebx
        xor      ecx, ecx
        mov      dword ptr [esp + 0x1c], ebx
        mov      dword ptr [esp + 0x14], ecx
        mov      dword ptr [esp + 0x10], eax
    L_17cb:
        mov      al, byte ptr [esp + ecx + 0xe44]
        test     al, al
        je       L_1824
        mov      ecx, eax
        and      ecx, 0xff
        sub      ecx, edi
        cmp      ecx, 7
        ja       L_1bb5
        mov      ebx, edi
        shl      ebx, 0xc
        sub      ebx, edi
        mov      dword ptr [esp + 0x24], ebx
        mov      ebx, dword ptr [esp + 0x1c]
        mov      edi, dword ptr [esp + 0x24]
        movzx    ax, al
        lea      edi, [edi + ebx*8]
        add      edi, eax
        mov      eax, dword ptr [esp + 0x10]
        shl      edi, 4
        mov      word ptr [eax], di
        mov      eax, 1
        mov      edi, dword ptr [esp + 0x28]
        shl      eax, cl
        mov      ecx, dword ptr [esp + 0x14]
        add      ebx, eax
        mov      dword ptr [esp + 0x1c], ebx
    L_1824:
        mov      eax, dword ptr [esp + 0x10]
        inc      ecx
        add      eax, 2
        cmp      ecx, esi
        mov      dword ptr [esp + 0x14], ecx
        mov      dword ptr [esp + 0x10], eax
        jb       L_17cb
        cmp      ebx, 0x1ff
        ja       L_1bce
        mov      eax, dword ptr [esp + 0x48]
        cmp      edi, 0xf
        mov      dword ptr [esp + 0x14], eax
        ja       L_193e
        mov      ecx, dword ptr [esp + 0x28]
        lea      edi, [esp + ecx*4 + 0x4c]
        mov      dword ptr [esp + 0x10], edi
        mov      edi, 0x10
        sub      edi, ecx
        mov      dword ptr [esp + 0x1c], edi
    L_186c:
        mov      ecx, dword ptr [esp + 0x10]
        mov      ecx, dword ptr [ecx]
        cmp      ecx, 1
        jb       L_1924
        lea      ebp, [esp + eax*4 + 0xd0]
        mov      dword ptr [esp + 0x24], ecx
        jmp      L_188c
    L_1888:
        mov      esi, dword ptr [esp + 0x40]
    L_188c:
        mov      ebx, dword ptr [esp + 0x3c]
        lea      edi, [eax*4]
        lea      eax, [esi - 1]
        mov      edx, dword ptr [esp + edi + 0x54c]
        mov      ecx, edx
        and      ecx, eax
        xor      eax, eax
        mov      ax, word ptr [ebx + ecx*2]
        mov      ecx, eax
        shr      ecx, 7
        add      ecx, esi
        shr      eax, 4
        lea      ebx, [ebx + ecx*2]
        mov      ecx, dword ptr [esp + 0x28]
        shr      edx, cl
        and      eax, 7
        mov      ecx, eax
        mov      eax, dword ptr [esp + 0x28]
        mov      esi, edx
        mov      dx, word ptr [esp + edi + 0x9c8]
        mov      edi, 1
        shl      edi, cl
        mov      ecx, dword ptr [ebp]
        shl      dx, 7
        add      dx, word ptr [ebp]
        sub      ecx, eax
        mov      eax, 1
        shl      eax, cl
        lea      ecx, [ebx + esi*2]
    L_18ef:
        lea      ebx, [eax + eax]
        mov      word ptr [ecx], dx
        add      esi, eax
        add      ecx, ebx
        cmp      esi, edi
        jb       L_18ef
        mov      eax, dword ptr [esp + 0x14]
        mov      ecx, dword ptr [esp + 0x24]
        inc      eax
        add      ebp, 4
        dec      ecx
        mov      dword ptr [esp + 0x14], eax
        mov      dword ptr [esp + 0x24], ecx
        jne      L_1888
        mov      edx, dword ptr [esp + 0x34]
        mov      ebp, dword ptr [esp + 0x44]
        mov      esi, dword ptr [esp + 0x40]
    L_1924:
        mov      edi, dword ptr [esp + 0x10]
        mov      ecx, dword ptr [esp + 0x1c]
        add      edi, 4
        dec      ecx
        mov      dword ptr [esp + 0x10], edi
        mov      dword ptr [esp + 0x1c], ecx
        jne      L_186c
    L_193e:
        mov      eax, dword ptr [esp + 0x30]
        test     eax, eax
        jge      L_13df
        mov      edi, dword ptr [esp + 0x20]
    L_194e:
        cmp      ebp, 0xf
        jge      L_195d
        mov      eax, edi
        mov      ecx, ebp
        shl      eax, cl
        add      eax, edx
        jmp      L_195f
    L_195d:
        mov      eax, edx
    L_195f:
        mov      ecx, eax
        xor      ebx, ebx
        and      ecx, 0x3ff
        mov      bx, word ptr [esp + ecx*2 + 0x1844]
        test     bl, 0xf
        jne      L_199a
        mov      ecx, ebx
        mov      esi, 1
        shr      ecx, 4
        and      ecx, 7
        shl      esi, cl
        shr      eax, 0xa
        shr      ebx, 7
        dec      esi
        and      esi, eax
        add      esi, ebx
        xor      ebx, ebx
        mov      bx, word ptr [esp + esi*2 + 0x2044]
    L_199a:
        mov      ecx, ebx
        and      ecx, 0xf
        sub      ebp, ecx
        jns      L_19bd
        mov      eax, dword ptr [esp + 0x18]
        mov      ecx, ebp
        mov      edx, edi
        mov      edi, dword ptr [eax]
        add      eax, 4
        neg      ecx
        shr      edx, cl
        mov      dword ptr [esp + 0x18], eax
        add      ebp, 0x20
        jmp      L_19bf
    L_19bd:
        shr      edx, cl
    L_19bf:
        shr      ebx, 7
        cmp      ebx, 0x100
        jae      L_19da
        mov      eax, dword ptr [esp + 0x2c]
        mov      byte ptr [eax], bl
        inc      eax
        mov      dword ptr [esp + 0x2c], eax
        jmp      L_194e
    L_19da:
        je       L_1b68
        mov      al, byte ptr [ebx + g_data_004f48cf]
        xor      esi, esi
        test     al, al
        je       L_1a43
        and      eax, 0xff
        sub      ebp, eax
        jns      L_1a35
        mov      ecx, dword ptr [esp + 0x18]
        mov      dword ptr [esp + 0x1c], edx
        mov      edx, edi
        mov      edi, dword ptr [ecx]
        add      ecx, 4
        mov      dword ptr [esp + 0x18], ecx
        lea      ecx, [ebp + eax]
        mov      esi, edx
        shl      esi, cl
        mov      ecx, dword ptr [esp + 0x1c]
        add      esi, ecx
        mov      ecx, 1
        mov      dword ptr [esp + 0x34], ecx
        mov      ecx, eax
        mov      eax, dword ptr [esp + 0x34]
        shl      eax, cl
        mov      ecx, ebp
        neg      ecx
        shr      edx, cl
        dec      eax
        and      esi, eax
        add      ebp, 0x20
        jmp      L_1a43
    L_1a35:
        mov      esi, 1
        mov      ecx, eax
        shl      esi, cl
        dec      esi
        and      esi, edx
        shr      edx, cl
    L_1a43:
        xor      ecx, ecx
        cmp      ebp, 0xf
        mov      cl, byte ptr [ebx + g_data_004f48af]
        lea      eax, [ecx + esi + 3]
        mov      dword ptr [esp + 0x10], eax
        jge      L_1a62
        mov      eax, edi
        mov      ecx, ebp
        shl      eax, cl
        add      eax, edx
        jmp      L_1a64
    L_1a62:
        mov      eax, edx
    L_1a64:
        mov      ecx, eax
        xor      ebx, ebx
        and      ecx, 0xff
        mov      bx, word ptr [esp + ecx*2 + 0x1244]
        test     bl, 0xf
        jne      L_1a9f
        mov      ecx, ebx
        mov      esi, 1
        shr      ecx, 4
        and      ecx, 7
        shl      esi, cl
        shr      eax, 8
        shr      ebx, 7
        dec      esi
        and      esi, eax
        add      esi, ebx
        xor      ebx, ebx
        mov      bx, word ptr [esp + esi*2 + 0x1444]
    L_1a9f:
        mov      ecx, ebx
        and      ecx, 0xf
        sub      ebp, ecx
        jns      L_1ac2
        mov      eax, dword ptr [esp + 0x18]
        mov      ecx, ebp
        mov      edx, edi
        mov      edi, dword ptr [eax]
        add      eax, 4
        neg      ecx
        shr      edx, cl
        mov      dword ptr [esp + 0x18], eax
        add      ebp, 0x20
        jmp      L_1ac4
    L_1ac2:
        shr      edx, cl
    L_1ac4:
        shr      ebx, 7
        xor      eax, eax
        mov      cl, byte ptr [ebx + g_data_004f4a30]
        test     cl, cl
        je       L_1b28
        movsx    esi, cl
        sub      ebp, esi
        jns      L_1b1a
        mov      eax, dword ptr [esp + 0x18]
        mov      dword ptr [esp + 0x1c], edx
        mov      edx, edi
        lea      ecx, [ebp + esi]
        mov      edi, dword ptr [eax]
        add      eax, 4
        mov      dword ptr [esp + 0x18], eax
        mov      eax, edx
        shl      eax, cl
        mov      ecx, dword ptr [esp + 0x1c]
        add      eax, ecx
        mov      ecx, 1
        mov      dword ptr [esp + 0x34], ecx
        mov      ecx, esi
        mov      esi, dword ptr [esp + 0x34]
        shl      esi, cl
        mov      ecx, ebp
        neg      ecx
        shr      edx, cl
        dec      esi
        and      eax, esi
        add      ebp, 0x20
        jmp      L_1b28
    L_1b1a:
        mov      eax, 1
        mov      ecx, esi
        shl      eax, cl
        dec      eax
        and      eax, edx
        shr      edx, cl
    L_1b28:
        mov      esi, dword ptr [esp + 0x2c]
        xor      ecx, ecx
        mov      cx, word ptr [ebx*2 + g_data_004f49f0]
        add      ecx, eax
        mov      eax, esi
        sub      eax, ecx
        dec      eax
        test     ecx, ecx
        mov      ecx, dword ptr [esp + 0x10]
        jne      L_1b56
    L_1b45:
        mov      bl, byte ptr [eax]
        mov      byte ptr [esi], bl
        inc      esi
        dec      ecx
        jne      L_1b45
        mov      dword ptr [esp + 0x2c], esi
        jmp      L_194e
    L_1b56:
        mov      bl, byte ptr [eax]
        mov      byte ptr [esi], bl
        inc      esi
        inc      eax
        dec      ecx
        jne      L_1b56
        mov      dword ptr [esp + 0x2c], esi
        jmp      L_194e
    L_1b68:
        mov      dword ptr [esp + 0x20], edi
    L_1b6c:
        dec      ebp
        jns      L_1b9d
        mov      eax, dword ptr [esp + 0x18]
        mov      esi, edx
        mov      edx, dword ptr [esp + 0x20]
        mov      ecx, dword ptr [eax]
        add      eax, 4
        mov      dword ptr [esp + 0x20], ecx
        mov      dword ptr [esp + 0x18], eax
        lea      ecx, [ebp + 1]
        mov      eax, edx
        shl      eax, cl
        mov      ecx, ebp
        neg      ecx
        shr      edx, cl
        add      eax, esi
        and      eax, 1
        add      ebp, 0x20
        jmp      L_1ba4
    L_1b9d:
        mov      eax, edx
        and      eax, 1
        shr      edx, 1
    L_1ba4:
        test     eax, eax
        jne      L_1bdc
        mov      esi, dword ptr [esp + 0x18]
        mov      edi, dword ptr [esp + 0x20]
        jmp      L_12ed
    L_1bb5:
        mov      edx, dword ptr [esp + 0x2448]
        mov      dword ptr [edx + 0x1c], 0xfffffff7
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x2434
        ret
    L_1bce:
        mov      eax, dword ptr [esp + 0x2448]
        mov      dword ptr [eax + 0x1c], 0xfffffff7
    L_1bdc:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x2434
        ret
    }
}

