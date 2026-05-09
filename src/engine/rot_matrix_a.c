/**
 * Build 3x3 rotation matrix - axis order A.
 *
 * Same machinery as BuildRotMatrix_OrderC but the multiplication
 * tree differs - the orig stores into matrix slots in a different
 * order matching a different axis composition.
 */
#include "engine/scenegraph.h"

/*
 * @addr 0x004b3800
 */
__declspec(naked) void BuildRotMatrix_OrderA(s16 *angles, s16 *mat3x3)
{
    __asm {
        push    ecx                                       ; stack slot
        mov     eax, dword ptr [esp + 8]                  ; angles
        push    ebx
        push    ebp
        push    esi
        movsx   ecx, word ptr [eax]
        mov     edx, ecx
        add     ecx, 0xfffffc00
        and     edx, 0xfff
        and     ecx, 0xfff
        push    edi
        mov     esi, dword ptr [edx*4 + g_sinTable]
        mov     edx, dword ptr [ecx*4 + g_sinTable]
        movsx   ecx, word ptr [eax + 2]
        mov     edi, ecx
        add     ecx, 0xfffffc00
        and     ecx, 0xfff
        and     edi, 0xfff
        sar     esi, 16
        mov     ebx, dword ptr [ecx*4 + g_sinTable]
        mov     edi, dword ptr [edi*4 + g_sinTable]
        movsx   ecx, word ptr [eax + 4]
        sar     ebx, 16
        mov     ebp, ebx
        mov     eax, ecx
        imul    ebp, esi
        add     ecx, 0xfffffc00
        mov     dword ptr [esp + 0x18], esi
        mov     esi, dword ptr [esp + 0x1c]
        and     eax, 0xfff
        and     ecx, 0xfff
        mov     dword ptr [esp + 0x10], ebx
        mov     eax, dword ptr [eax*4 + g_sinTable]
        mov     ecx, dword ptr [ecx*4 + g_sinTable]
        sar     ebp, 12
        sar     edx, 16
        mov     word ptr [esi + 4], bp
        mov     ebp, edx
        neg     ebp
        imul    ebx, edx
        sar     edi, 16
        mov     word ptr [esi + 0xa], bp
        mov     ebp, edi
        imul    ebp, dword ptr [esp + 0x18]
        imul    edx, edi
        sar     ebx, 12
        sar     ebp, 12
        sar     ecx, 16
        movsx   ebx, bx
        mov     word ptr [esi + 0x10], bp
        mov     ebp, ecx
        sar     eax, 16
        imul    ebp, ebx
        mov     dword ptr [esp + 0x1c], ebx
        mov     ebx, eax
        imul    ebx, edi
        add     ebp, ebx
        mov     ebx, eax
        imul    ebx, dword ptr [esp + 0x1c]
        sar     ebp, 12
        mov     word ptr [esi], bp
        mov     ebp, ecx
        imul    ebp, edi
        sub     ebx, ebp
        mov     ebp, ecx
        sar     ebx, 12
        mov     word ptr [esi + 2], bx
        mov     ebx, dword ptr [esp + 0x18]
        imul    ebp, ebx
        sar     ebp, 12
        mov     word ptr [esi + 6], bp
        mov     ebp, eax
        imul    ebp, ebx
        mov     edi, dword ptr [esp + 0x10]
        mov     ebx, ecx
        sar     edx, 12
        sar     ebp, 12
        movsx   edx, dx
        mov     word ptr [esi + 8], bp
        mov     ebp, edi
        imul    ebx, edx
        imul    ebp, eax
        imul    eax, edx
        imul    ecx, edi
        sub     ebx, ebp
        add     eax, ecx
        sar     ebx, 12
        sar     eax, 12
        mov     word ptr [esi + 0xc], bx
        mov     word ptr [esi + 0xe], ax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    }
}
