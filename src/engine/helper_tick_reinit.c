/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

__declspec(naked) void Helper_TickReinit(void)
{
    __asm {
        mov      eax, dword ptr [g_data_007af92c]
        sub      esp, 0x64
        push     ebx
        push     esi
        xor      esi, esi
        push     edi
        cmp      eax, esi
        jne      L_cc3c
        cmp      dword ptr [g_data_00ab51f4], esi
        je       L_cc3c
        call     Init16BitFields_004bcc50
        mov      eax, dword ptr [g_data_00ab51f4]
        mov      ecx, dword ptr [g_data_00ab4878]
        cdq
        mov      dword ptr [g_data_007af990], ecx
        mov      ecx, dword ptr [g_data_00ab4880]
        sub      eax, edx
        mov      edx, dword ptr [g_data_00ab487c]
        mov      dword ptr [g_data_007af998], ecx
        mov      cx, word ptr [g_data_00ab4888]
        mov      dword ptr [g_data_007af994], edx
        mov      edx, dword ptr [g_data_00ab4884]
        mov      word ptr [g_data_007af9a0], cx
        mov      ecx, dword ptr [g_data_0052ab10]
        mov      dword ptr [g_data_007af99c], edx
        mov      dword ptr [g_data_007af9a4], esi
        mov      dword ptr [g_data_007af9a8], esi
        mov      dword ptr [g_data_007af9ac], esi
        mov      dword ptr [g_data_00542044], ecx
        mov      edi, dword ptr [ecx*4 + 0x58]
        shl      edi, 8
        sar      edi, 0x10
        mov      ecx, edi
        mov      ebx, OFFSET g_data_00ab44f8
        neg      ecx
        mov      dword ptr [esp + 0xc], ecx
        mov      cl, 0x1c
        sar      eax, 1
        mov      byte ptr [esp + 0x5e], cl
        mov      byte ptr [esp + 0x60], cl
        mov      byte ptr [esp + 0x5c], cl
        mov      cl, 0x64
        cmp      eax, esi
        mov      dword ptr [esp + 0x18], edi
        mov      word ptr [esp + 0x64], si
        mov      word ptr [esp + 0x6a], 0xf
        mov      byte ptr [esp + 0x5f], cl
        mov      byte ptr [esp + 0x61], cl
        mov      byte ptr [esp + 0x5d], cl
        jle      L_cc3c
        push     ebp
        mov      dword ptr [esp + 0x18], eax
        jmp      L_c8c5
    L_c8c1:
        mov      edi, dword ptr [esp + 0x1c]
    L_c8c5:
        mov      edx, dword ptr [g_data_00ab4d58]
        mov      ecx, dword ptr [g_data_00ab4d60]
        mov      eax, dword ptr [g_data_00ab4d5c]
        mov      dword ptr [g_data_007af990], edx
        mov      edx, dword ptr [g_data_00ab4d64]
        mov      dword ptr [g_data_007af998], ecx
        movsx    ecx, word ptr [ebx]
        mov      dword ptr [g_data_007af99c], edx
        mov      dword ptr [g_data_007af994], eax
        movsx    edx, word ptr [ebx + 2]
        mov      ax, word ptr [g_data_00ab4d68]
        mov      dword ptr [esp + 0x24], ecx
        mov      word ptr [g_data_007af9a0], ax
        mov      dword ptr [esp + 0x28], edx
        movsx    eax, word ptr [ebx + 4]
        lea      ecx, [esp + 0x30]
        lea      edx, [esp + 0x24]
        push     ecx
        push     edx
        mov      dword ptr [esp + 0x34], eax
        call     Mat3x3VecMul_004b3630
        mov      eax, dword ptr [esp + 0x3c]
        mov      ecx, dword ptr [esp + 0x38]
        movsx    ebp, word ptr [g_data_00ab47f8]
        mov      dword ptr [g_data_00542048], eax
        add      eax, edi
        neg      eax
        mov      esi, eax
        mov      dword ptr [g_data_00542044], ecx
        imul     esi, ebp
        sar      esi, 0xc
        add      esi, ecx
        mov      edx, dword ptr [esp + 0x40]
        movsx    ecx, word ptr [g_data_00ab47fc]
        imul     eax, ecx
        sar      eax, 0xc
        add      ebx, 6
        add      eax, edx
        mov      dword ptr [g_data_0054204c], edx
        mov      dword ptr [esp + 0x28], eax
        movsx    edx, word ptr [ebx]
        movsx    eax, word ptr [ebx + 2]
        movsx    ecx, word ptr [ebx + 4]
        add      esp, 8
        mov      dword ptr [esp + 0x3c], edx
        mov      dword ptr [esp + 0x40], eax
        lea      edx, [esp + 0x48]
        lea      eax, [esp + 0x3c]
        push     edx
        push     eax
        mov      dword ptr [esp + 0x4c], ecx
        call     Mat3x3VecMul_004b3630
        mov      eax, dword ptr [esp + 0x54]
        mov      ecx, dword ptr [esp + 0x50]
        movsx    ebp, word ptr [g_data_00ab47f8]
        mov      dword ptr [g_data_00542048], eax
        add      eax, edi
        neg      eax
        mov      edi, eax
        mov      dword ptr [g_data_00542044], ecx
        imul     edi, ebp
        sar      edi, 0xc
        add      edi, ecx
        mov      edx, dword ptr [esp + 0x58]
        movsx    ecx, word ptr [g_data_00ab47fc]
        imul     eax, ecx
        sar      eax, 0xc
        add      eax, edx
        mov      dword ptr [g_data_0054204c], edx
        mov      ecx, eax
        mov      eax, edi
        sub      eax, esi
        add      esp, 8
        cdq
        and      edx, 3
        add      ebx, 6
        add      eax, edx
        mov      dword ptr [esp + 0x14], ecx
        mov      ebp, eax
        mov      eax, ecx
        sar      ebp, 2
        mov      ecx, dword ptr [esp + 0x20]
        sub      eax, ecx
        cdq
        and      edx, 3
        add      eax, edx
        mov      edx, esi
        sar      eax, 2
        sub      edx, eax
        mov      dword ptr [esp + 0x20], eax
        mov      word ptr [g_data_007af958], dx
        mov      dx, word ptr [esp + 0x10]
        mov      word ptr [g_data_007af95e], dx
        lea      edx, [ebp + ecx]
        mov      word ptr [g_data_007af964], dx
        lea      edx, [eax + esi]
        mov      word ptr [g_data_007af95a], dx
        mov      edx, dword ptr [esp + 0x10]
        sub      ecx, ebp
        mov      word ptr [g_data_007af960], dx
        mov      word ptr [g_data_007af966], cx
        mov      ecx, edi
        mov      word ptr [g_data_007af962], dx
        mov      edx, dword ptr [esp + 0x14]
        sub      ecx, eax
        mov      word ptr [g_data_007af95c], cx
        mov      ecx, dword ptr [g_data_00ab4878]
        lea      eax, [ebp + edx]
        mov      edx, dword ptr [g_data_00ab487c]
        mov      word ptr [g_data_007af968], ax
        mov      eax, dword ptr [g_data_00ab4880]
        mov      dword ptr [g_data_007af990], ecx
        mov      ecx, dword ptr [g_data_00ab4884]
        mov      dword ptr [g_data_007af994], edx
        mov      dx, word ptr [g_data_00ab4888]
        mov      dword ptr [g_data_007af998], eax
        mov      dword ptr [g_data_007af99c], ecx
        mov      word ptr [g_data_007af9a0], dx
        call     ProjectTwoVertices
        movsx    eax, word ptr [g_data_007af9b4]
        movsx    ecx, word ptr [g_data_007af9b6]
        movsx    edx, word ptr [g_data_007af9be]
        movsx    esi, word ptr [g_data_007af9b8]
        sub      edx, ecx
        sub      esi, eax
        imul     edx, esi
        movsx    esi, word ptr [g_data_007af9ba]
        sub      esi, ecx
        movsx    ecx, word ptr [g_data_007af9bc]
        sub      ecx, eax
        xor      eax, eax
        imul     esi, ecx
        mov      ecx, dword ptr [g_data_007af9b4]
        sub      edx, esi
        test     edx, edx
        mov      edx, dword ptr [g_data_007af9b8]
        mov      dword ptr [esp + 0x54], ecx
        mov      ecx, dword ptr [esp + 0x6e]
        mov      dword ptr [esp + 0x58], edx
        setle    al
        mov      dword ptr [g_data_007af9b0], eax
        mov      dl, byte ptr [g_data_007af9b0]
        mov      eax, dword ptr [g_data_007af9bc]
        and      edx, 1
        and      ecx, 0xfbff
        mov      dword ptr [esp + 0x5c], eax
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [esp + 0x6e], cx
        call     MaxOfThree_004b3d90
        mov      word ptr [esp + 0x66], ax
        mov      eax, dword ptr [g_data_007af984]
        test     eax, eax
        jle      L_cb5a
        mov      eax, dword ptr [g_data_007af988]
        test     eax, eax
        jle      L_cb5a
        mov      eax, dword ptr [g_data_007af98c]
        test     eax, eax
        jle      L_cb5a
        lea      eax, [esp + 0x54]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_cb5a:
        mov      eax, dword ptr [esp + 0x14]
        mov      edx, dword ptr [esp + 0x20]
        mov      ecx, dword ptr [esp + 0x10]
        sub      eax, ebp
        push     eax
        add      edx, edi
        push     ecx
        push     edx
        call     AdvanceTriStripRing
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_data_007af9b4]
        movsx    ecx, word ptr [g_data_007af9b6]
        movsx    edx, word ptr [g_data_007af9be]
        movsx    esi, word ptr [g_data_007af9b8]
        sub      edx, ecx
        sub      esi, eax
        imul     edx, esi
        movsx    esi, word ptr [g_data_007af9ba]
        sub      esi, ecx
        movsx    ecx, word ptr [g_data_007af9bc]
        sub      ecx, eax
        xor      eax, eax
        imul     esi, ecx
        mov      ecx, dword ptr [g_data_007af9b4]
        sub      edx, esi
        test     edx, edx
        mov      edx, dword ptr [g_data_007af9b8]
        mov      dword ptr [esp + 0x54], ecx
        mov      ecx, dword ptr [esp + 0x6e]
        mov      dword ptr [esp + 0x58], edx
        setle    al
        mov      dword ptr [g_data_007af9b0], eax
        mov      dl, byte ptr [g_data_007af9b0]
        mov      eax, dword ptr [g_data_007af9bc]
        and      edx, 1
        and      ecx, 0xfbff
        mov      dword ptr [esp + 0x5c], eax
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [esp + 0x6e], cx
        call     MaxOfThree_004b3d90
        mov      word ptr [esp + 0x66], ax
        mov      eax, dword ptr [g_data_007af984]
        test     eax, eax
        jle      L_cc2c
        mov      eax, dword ptr [g_data_007af988]
        test     eax, eax
        jle      L_cc2c
        mov      eax, dword ptr [g_data_007af98c]
        test     eax, eax
        jle      L_cc2c
        lea      eax, [esp + 0x54]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_cc2c:
        mov      eax, dword ptr [esp + 0x18]
        dec      eax
        mov      dword ptr [esp + 0x18], eax
        jne      L_c8c1
        pop      ebp
    L_cc3c:
        pop      edi
        pop      esi
        pop      ebx
        add      esp, 0x64
        ret
    }
}

