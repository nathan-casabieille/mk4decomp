/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004afd10 (297b engine.install) - twin of R2_Init4 for 320x240 mode.
 *   Same structure, different state globals: 0x004f47a8 (mode), 0058c858 (saved coords),
 *   0058c860 (DSound), 0058c87c (window). Sets 320x240 (0x140 x 0xf0) instead of 640x480.
 *   Calls DialogProbeDispatch_004afe40 (sister helper).
 */
__declspec(naked) void DDraw3_CreateSurface(void) {
    __asm {
        mov     ecx, dword ptr [g_data_004f47a8]
        mov     eax, [esp + 4]
        sub     esp, 0x6c
        cmp     ecx, eax
        push    edi
        jz      L_dms2_okRet
        cmp     ecx, -1
        jne     short L_dms2_doSwitch
        test    eax, eax
        jz      L_dms2_okRet
    L_dms2_doSwitch:
        test    eax, eax
        mov     dword ptr [g_data_004f47a8], eax
        jz      L_dms2_release
        push    offset g_data_0058c858
        call    dword ptr [g_iat_004d21ac]
        push    0
        call    dword ptr [g_iat_004d219c]
        call    DialogProbeDispatch_004afe40
        mov     eax, dword ptr [g_data_0058c860]
        test    eax, eax
        jz      short L_dms2_skipPair
        mov     edx, dword ptr [g_data_0058c87c]
        mov     ecx, [eax]
        push    0x55
        push    edx
        push    eax
        call    dword ptr [ecx + 0x50]
        mov     dword ptr [g_data_0058c878], eax
        mov     eax, dword ptr [g_data_0058c860]
        test    eax, eax
        jz      short L_dms2_skipPair
        mov     ecx, [eax]
        push    0x10
        push    0xf0
        push    0x140
        push    eax
        call    dword ptr [ecx + 0x54]
        mov     dword ptr [g_data_0058c878], eax
    L_dms2_skipPair:
        call    DialogProbeDispatch_004afe40
        mov     ecx, 0x1b
        xor     eax, eax
        lea     edi, [esp + 4]
        rep     stosd
        mov     eax, dword ptr [g_data_0058c860]
        mov     dword ptr [esp + 4], 0x6c
        test    eax, eax
        jz      short L_dms2_validate
        mov     edx, [eax]
        lea     ecx, [esp + 4]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x30]
        mov     dword ptr [g_data_0058c878], eax
    L_dms2_validate:
        cmp     dword ptr [esp + 0x10], 0x140
        jne     short L_dms2_fail
        cmp     dword ptr [esp + 0xc], 0xf0
        jz      L_dms2_okRet
    L_dms2_fail:
        xor     eax, eax
        pop     edi
        add     esp, 0x6c
        ret
    L_dms2_release:
        mov     eax, dword ptr [g_data_0058c860]
        test    eax, eax
        jz      short L_dms2_restoreCursor
        mov     edx, [eax]
        push    eax
        call    dword ptr [edx + 0x4c]
        mov     dword ptr [g_data_0058c878], eax
        mov     eax, dword ptr [g_data_0058c860]
        test    eax, eax
        jz      short L_dms2_restoreCursor
        mov     edx, dword ptr [g_data_0058c87c]
        mov     ecx, [eax]
        push    0xc
        push    edx
        push    eax
        call    dword ptr [ecx + 0x50]
        mov     dword ptr [g_data_0058c878], eax
    L_dms2_restoreCursor:
        mov     eax, dword ptr [g_data_0058c85c]
        mov     ecx, dword ptr [g_data_0058c858]
        push    eax
        push    ecx
        call    dword ptr [g_iat_004d21a4]
        push    1
        call    dword ptr [g_iat_004d219c]
    L_dms2_okRet:
        mov     eax, 1
        pop     edi
        add     esp, 0x6c
        ret
    }
}

