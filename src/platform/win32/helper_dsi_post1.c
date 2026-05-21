/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004c4110 (252b platform.win32) - DirectSound buffer create+release dispatcher.
 *   Reads IDirectSound* from g_data_00f9efcc (return if null).
 *   If arg0 != 0 (init path): calls vtbl methods +0x14/+0x20/+0x1c/+0x18, sets
 *     four "owned" byte-flags (g_data_00f9f000, _effc, _eff8, _eff4) on success.
 *   If arg0 == 0 (release path): for each owned flag, calls release vtbl +0x38,
 *     +0x44, +0x40, +0x3c; clear all four flags.
 */
__declspec(naked) void Helper_DSI_post1(void) {
    __asm {
        mov     eax, dword ptr [g_data_00f9efcc]
        push    ebx
        xor     ebx, ebx
        cmp     eax, ebx
        jz      L_dbd_done
        cmp     [esp + 8], ebx
        jz      L_dbd_release
        mov     ecx, [eax]
        push    ebx
        push    0x400
        push    offset g_data_00f9ebc8
        push    eax
        call    dword ptr [ecx + 0x14]
        neg     eax
        sbb     eax, eax
        push    offset g_data_00f9ebc0
        inc     eax
        mov     byte ptr [g_data_00f9f000], al
        mov     eax, dword ptr [g_data_00f9efcc]
        push    eax
        mov     edx, [eax]
        call    dword ptr [edx + 0x20]
        neg     eax
        sbb     eax, eax
        push    offset g_data_00f8fac4
        inc     eax
        mov     byte ptr [g_data_00f9effc], al
        mov     eax, dword ptr [g_data_00f9efcc]
        push    eax
        mov     ecx, [eax]
        call    dword ptr [ecx + 0x1c]
        neg     eax
        sbb     eax, eax
        push    offset g_data_00f9eb68
        inc     eax
        mov     byte ptr [g_data_00f9eff8], al
        mov     eax, dword ptr [g_data_00f9efcc]
        push    eax
        mov     edx, [eax]
        call    dword ptr [edx + 0x18]
        neg     eax
        sbb     eax, eax
        inc     eax
        mov     byte ptr [g_data_00f9eff4], al
        pop     ebx
        ret
    L_dbd_release:
        cmp     byte ptr [g_data_00f9f000], bl
        jz      short L_dbd_r2
        mov     ecx, [eax]
        push    offset g_data_00f9ebc8
        push    eax
        call    dword ptr [ecx + 0x38]
        mov     eax, dword ptr [g_data_00f9efcc]
    L_dbd_r2:
        cmp     byte ptr [g_data_00f9effc], bl
        jz      short L_dbd_r3
        mov     ecx, dword ptr [g_data_00f9ebc0]
        mov     edx, [eax]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x44]
        mov     eax, dword ptr [g_data_00f9efcc]
    L_dbd_r3:
        cmp     byte ptr [g_data_00f9eff8], bl
        jz      short L_dbd_r4
        mov     ecx, dword ptr [g_data_00f8fac4]
        mov     edx, [eax]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x40]
        mov     eax, dword ptr [g_data_00f9efcc]
    L_dbd_r4:
        cmp     byte ptr [g_data_00f9eff4], bl
        jz      short L_dbd_r_end
        mov     ecx, dword ptr [g_data_00f9eb68]
        mov     edx, [eax]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x3c]
    L_dbd_r_end:
        mov     byte ptr [g_data_00f9f000], bl
        mov     byte ptr [g_data_00f9effc], bl
        mov     byte ptr [g_data_00f9eff8], bl
        mov     byte ptr [g_data_00f9eff4], bl
    L_dbd_done:
        pop     ebx
        ret
    }
}

