/**
 * Build 3x3 rotation matrix - axis order B.
 *
 * Same machinery as the other two BuildRotMatrix variants but the
 * multiplication tree differs.
 */
#include "engine/scenegraph.h"

/*
 * @addr 0x004b3940
 */
__declspec(naked) void BuildRotMatrix_OrderB(s16 *angles, s16 *mat3x3)
{
    __asm {
        push    ecx
        mov     edx, dword ptr [esp + 8]
        push    ebx
        push    ebp
        push    esi
        movsx   ecx, word ptr [edx]
        movsx   esi, word ptr [edx + 2]
        mov     eax, ecx
        add     ecx, 0xfffffc00
        and     eax, 0xfff
        and     ecx, 0xfff
        movsx   edx, word ptr [edx + 4]
        mov     eax, dword ptr [eax*4 + g_sinTable]
        push    edi
        sar     eax, 16
        mov     dword ptr [esp + 0x18], eax
        mov     eax, dword ptr [ecx*4 + g_sinTable]
        mov     ecx, esi
        add     esi, 0xfffffc00
        and     esi, 0xfff
        and     ecx, 0xfff
        sar     eax, 16
        mov     ebx, dword ptr [esi*4 + g_sinTable]
        mov     ecx, dword ptr [ecx*4 + g_sinTable]
        mov     esi, edx
        add     edx, 0xfffffc00
        and     esi, 0xfff
        and     edx, 0xfff
        sar     ecx, 16
        mov     edi, dword ptr [esi*4 + g_sinTable]
        mov     edx, dword ptr [edx*4 + g_sinTable]
        sar     edi, 16
        mov     ebp, edi
        mov     esi, dword ptr [esp + 0x1c]
        imul    ebp, ecx
        sar     ebp, 12
        sar     edx, 16
        mov     word ptr [esi], bp
        mov     ebp, edx
        imul    ebp, ecx
        sar     ebp, 12
        sar     ebx, 16
        mov     word ptr [esi + 6], bp
        mov     dword ptr [esp + 0x10], ebx
        mov     ebp, ebx
        imul    ebx, edi
        sar     ebx, 12
        neg     ebp
        movsx   ebx, bx
        mov     word ptr [esi + 0xc], bp
        mov     ebp, eax
        mov     dword ptr [esp + 0x1c], ebx
        imul    ebp, ebx
        mov     ebx, edx
        imul    ebx, dword ptr [esp + 0x18]
        sub     ebp, ebx
        mov     ebx, dword ptr [esp + 0x18]
        imul    ebx, dword ptr [esp + 0x1c]
        sar     ebp, 12
        mov     word ptr [esi + 2], bp
        mov     ebp, edx
        imul    edx, dword ptr [esp + 0x10]
        imul    ebp, eax
        add     ebx, ebp
        mov     ebp, edi
        sar     edx, 12
        sar     ebx, 12
        movsx   edx, dx
        mov     word ptr [esi + 4], bx
        mov     ebx, eax
        mov     dword ptr [esp + 0x1c], edx
        imul    ebx, edx
        mov     edx, dword ptr [esp + 0x18]
        imul    ebp, edx
        add     ebx, ebp
        mov     ebp, eax
        sar     ebx, 12
        imul    ebp, edi
        mov     word ptr [esi + 8], bx
        mov     ebx, edx
        imul    ebx, dword ptr [esp + 0x1c]
        sub     ebx, ebp
        imul    eax, ecx
        imul    ecx, edx
        sar     ebx, 12
        sar     eax, 12
        sar     ecx, 12
        mov     word ptr [esi + 0xa], bx
        mov     word ptr [esi + 0xe], ax
        mov     word ptr [esi + 0x10], cx
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
