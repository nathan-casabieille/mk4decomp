/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004aeae0 (297b engine.install) - DSound mode-switch / window state setter.
 *   If new mode == current g_data_004f47a0 → no-op success path.
 *   If current is -1 and new is 0 → no-op success.
 *   Update mode. If new != 0 (set up): GetSysColorBrush(0x58c760), ShowCursor(0),
 *     call DSoundSetAxisPan123, set DSound cooperative level (vtbl+0x50, 0x55),
 *     set display mode (vtbl+0x54, 640x480x16), call DSoundSetAxisPan123,
 *     zero local format buffer (108 bytes), get caps (vtbl+0x30), validate 640x480.
 *   If new == 0 (release): release vtbl+0x4c, set cooperative back (vtbl+0x50, 0xc),
 *     restore cursor position via SetCursorPos, ShowCursor(1).
 */
__declspec(naked) void R2_Init4(void) {
    __asm {
        mov     ecx, dword ptr [g_data_004f47a0]
        mov     eax, [esp + 4]
        sub     esp, 0x6c
        cmp     ecx, eax
        push    edi
        jz      L_dms_okRet
        cmp     ecx, -1
        jne     short L_dms_doSwitch
        test    eax, eax
        jz      L_dms_okRet
    L_dms_doSwitch:
        test    eax, eax
        mov     dword ptr [g_data_004f47a0], eax
        jz      L_dms_release
        push    offset g_data_0058c760
        call    dword ptr [g_iat_004d21ac]
        push    0
        call    dword ptr [g_iat_004d219c]
        call    DSoundSetAxisPan123_004aec10
        mov     eax, dword ptr [g_data_0058c7ac]
        test    eax, eax
        jz      short L_dms_skipPair
        mov     edx, dword ptr [g_data_0058c7d8]
        mov     ecx, [eax]
        push    0x55
        push    edx
        push    eax
        call    dword ptr [ecx + 0x50]
        mov     dword ptr [g_data_0058c7dc], eax
        mov     eax, dword ptr [g_data_0058c7ac]
        test    eax, eax
        jz      short L_dms_skipPair
        mov     ecx, [eax]
        push    0x10
        push    0x1e0
        push    0x280
        push    eax
        call    dword ptr [ecx + 0x54]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dms_skipPair:
        call    DSoundSetAxisPan123_004aec10
        mov     ecx, 0x1b
        xor     eax, eax
        lea     edi, [esp + 4]
        rep     stosd
        mov     eax, dword ptr [g_data_0058c7ac]
        mov     dword ptr [esp + 4], 0x6c
        test    eax, eax
        jz      short L_dms_validate
        mov     edx, [eax]
        lea     ecx, [esp + 4]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x30]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dms_validate:
        cmp     dword ptr [esp + 0x10], 0x280
        jne     short L_dms_fail
        cmp     dword ptr [esp + 0xc], 0x1e0
        jz      L_dms_okRet
    L_dms_fail:
        xor     eax, eax
        pop     edi
        add     esp, 0x6c
        ret
    L_dms_release:
        mov     eax, dword ptr [g_data_0058c7ac]
        test    eax, eax
        jz      short L_dms_restoreCursor
        mov     edx, [eax]
        push    eax
        call    dword ptr [edx + 0x4c]
        mov     dword ptr [g_data_0058c7dc], eax
        mov     eax, dword ptr [g_data_0058c7ac]
        test    eax, eax
        jz      short L_dms_restoreCursor
        mov     edx, dword ptr [g_data_0058c7d8]
        mov     ecx, [eax]
        push    0xc
        push    edx
        push    eax
        call    dword ptr [ecx + 0x50]
        mov     dword ptr [g_data_0058c7dc], eax
    L_dms_restoreCursor:
        mov     eax, dword ptr [g_data_0058c764]
        mov     ecx, dword ptr [g_data_0058c760]
        push    eax
        push    ecx
        call    dword ptr [g_iat_004d21a4]
        push    1
        call    dword ptr [g_iat_004d219c]
    L_dms_okRet:
        mov     eax, 1
        pop     edi
        add     esp, 0x6c
        ret
    }
}

