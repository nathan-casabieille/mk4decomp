/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004af020 (263b engine.install) - DSound slot init: per-slot capture/buffer setup.
 *   arg0 byte: slot index (0..0x10). If slot already has buffer ptr, return 1.
 *   Else: copy WAVEFORMAT template from g_data_00544298 (108 bytes); create a
 *   capture buffer via vtbl[+0x18]; query 8-byte interface via [+0x74]; query
 *   for GUID g_iid_004d28f0 via vtbl[0]; if global init succeeded and slot
 *   has valid pointers, register via [+0x0c]. Return 1 if all slots valid, 0 else.
 */
__declspec(naked) void R2_Init11(void) {
    __asm {
        mov     eax, [esp + 4]
        sub     esp, 0x78
        cmp     al, 0x10
        push    ebx
        push    esi
        push    edi
        jae     L_dss_fail
        and     eax, 0xff
        shl     eax, 2
        mov     ebx, eax
        mov     ecx, dword ptr [ebx + g_data_0058c768]
        lea     eax, [ebx + g_data_0058c768]
        test    ecx, ecx
        mov     [esp + 0xc], eax
        jz      short L_dss_setup
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0x78
        ret
    L_dss_setup:
        mov     eax, dword ptr [g_data_0058c7ac]
        mov     ecx, 0x1b
        mov     esi, offset g_data_00544298
        lea     edi, [esp + 0x18]
        rep     movsd
        lea     esi, [ebx + g_data_0058c720]
        test    eax, eax
        mov     dword ptr [esi], 0
        jz      short L_dss_step2
        mov     ecx, [eax]
        push    0
        lea     edx, [esp + 0x1c]
        push    esi
        push    edx
        push    eax
        call    dword ptr [ecx + 0x18]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dss_step2:
        mov     eax, [esi]
        mov     dword ptr [esp + 0x10], 0
        test    eax, eax
        mov     dword ptr [esp + 0x14], 0
        jz      short L_dss_step3
        mov     ecx, [eax]
        lea     edx, [esp + 0x10]
        push    edx
        push    8
        push    eax
        call    dword ptr [ecx + 0x74]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dss_step3:
        mov     eax, [esi]
        lea     edi, [ebx + g_data_00544258]
        test    eax, eax
        mov     dword ptr [edi], 0
        jz      short L_dss_step4
        mov     ecx, [eax]
        push    edi
        push    offset g_iid_004d28f0
        push    eax
        call    dword ptr [ecx]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dss_step4:
        mov     ecx, dword ptr [g_data_0058c7c0]
        test    ecx, ecx
        jz      short L_dss_validate
        mov     eax, [edi]
        test    eax, eax
        jz      short L_dss_validate
        mov     ebx, [esp + 0xc]
        mov     edx, [eax]
        push    ebx
        push    ecx
        push    eax
        call    dword ptr [edx + 0x0c]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dss_validate:
        cmp     dword ptr [esi], 0
        jz      short L_dss_fail
        cmp     dword ptr [edi], 0
        jz      short L_dss_fail
        mov     eax, [esp + 0xc]
        cmp     dword ptr [eax], 0
        jz      short L_dss_fail
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0x78
        ret
    L_dss_fail:
        pop     edi
        pop     esi
        xor     eax, eax
        pop     ebx
        add     esp, 0x78
        ret
    }
}

