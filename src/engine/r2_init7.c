/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

__declspec(naked) void R2_Init7(void)
{
    __asm {
        sub     esp, 0x80
        push    ebx
        mov     ebx, dword ptr [g_data_0058c7bc]
        push    esi
        push    edi
        test    ebx, ebx
        mov     dword ptr [esp + 0x0C], 0
        je      L_dxic_after_obj1
        mov     eax, dword ptr [ebx]
        push    0
        push    offset g_data_0058c7c4
        push    ebx
        call    dword ptr [eax + 0x18]
        mov     ebx, dword ptr [g_data_0058c7bc]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dxic_after_obj1:
        mov     edx, dword ptr [g_data_0058c7c4]
        mov     esi, dword ptr [g_data_0058c7c0]
        test    edx, edx
        je      L_dxic_after_obj2
        test    esi, esi
        je      L_dxic_after_obj2
        mov     ecx, dword ptr [esi]
        push    edx
        push    esi
        call    dword ptr [ecx + 0x18]
        mov     ebx, dword ptr [g_data_0058c7bc]
        mov     edx, dword ptr [g_data_0058c7c4]
        mov     esi, dword ptr [g_data_0058c7c0]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dxic_after_obj2:
        mov     ecx, 0x0B
        xor     eax, eax
        lea     edi, [esp + 0x10]
        rep     stosd
        test    edx, edx
        mov     dword ptr [esp + 0x10], 0x2C
        mov     dword ptr [esp + 0x1C], 0x280
        mov     dword ptr [esp + 0x20], 0x01E0
        mov     dword ptr [esp + 0x2C], 0x44200000
        mov     dword ptr [esp + 0x30], 0x43F00000
        mov     dword ptr [esp + 0x34], eax
        mov     dword ptr [esp + 0x38], 0x3F800000
        je      L_dxic_after_obj3
        mov     eax, dword ptr [edx]
        lea     ecx, [esp + 0x10]
        push    ecx
        push    edx
        call    dword ptr [eax + 0x44]
        mov     edx, dword ptr [g_data_0058c7c4]
        mov     ebx, dword ptr [g_data_0058c7bc]
        mov     esi, dword ptr [g_data_0058c7c0]
        mov     dword ptr [g_data_0058c7dc], eax
        test    edx, edx
        je      L_dxic_after_obj3
        test    esi, esi
        je      L_dxic_after_obj3
        mov     eax, dword ptr [esi]
        push    edx
        push    esi
        call    dword ptr [eax + 0x34]
        mov     ebx, dword ptr [g_data_0058c7bc]
        mov     edx, dword ptr [g_data_0058c7c4]
        mov     esi, dword ptr [g_data_0058c7c0]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dxic_after_obj3:
        test    ebx, ebx
        je      L_dxic_after_obj4
        mov     ecx, dword ptr [ebx]
        push    0
        push    offset g_data_0058c7d4
        push    ebx
        call    dword ptr [ecx + 0x14]
        mov     edx, dword ptr [g_data_0058c7c4]
        mov     esi, dword ptr [g_data_0058c7c0]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dxic_after_obj4:
        mov     ecx, 0x14
        xor     eax, eax
        lea     edi, [esp + 0x3C]
        rep     stosd
        mov     eax, dword ptr [g_data_0058c7d4]
        mov     dword ptr [esp + 0x3C], 0x50
        test    eax, eax
        je      L_dxic_after_obj5
        mov     edx, dword ptr [eax]
        lea     ecx, [esp + 0x3C]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x0C]
        mov     edx, dword ptr [g_data_0058c7c4]
        mov     esi, dword ptr [g_data_0058c7c0]
        mov     dword ptr [g_data_0058c7dc], eax
        mov     eax, dword ptr [g_data_0058c7d4]
    L_dxic_after_obj5:
        test    esi, esi
        je      L_dxic_after_obj6
        test    eax, eax
        je      L_dxic_after_obj6
        mov     edx, dword ptr [eax]
        lea     ecx, [esp + 0x0C]
        push    ecx
        push    esi
        push    eax
        call    dword ptr [edx + 0x14]
        mov     edx, dword ptr [g_data_0058c7c4]
        mov     dword ptr [g_data_0058c7dc], eax
        mov     eax, dword ptr [g_data_0058c7d4]
    L_dxic_after_obj6:
        mov     ecx, dword ptr [esp + 0x0C]
        test    ecx, ecx
        je      L_dxic_after_obj7
        test    edx, edx
        je      L_dxic_fail
        mov     eax, dword ptr [edx]
        push    ecx
        push    edx
        call    dword ptr [eax + 0x20]
        mov     edx, dword ptr [g_data_0058c7c4]
        mov     dword ptr [g_data_0058c7dc], eax
        mov     eax, dword ptr [g_data_0058c7d4]
    L_dxic_after_obj7:
        test    edx, edx
        je      L_dxic_fail
        test    eax, eax
        je      L_dxic_fail
        mov     eax, dword ptr [esp + 0x0C]
        test    eax, eax
        je      L_dxic_fail
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0x80
        ret
    L_dxic_fail:
        pop     edi
        pop     esi
        xor     eax, eax
        pop     ebx
        add     esp, 0x80
        ret
    }
}

