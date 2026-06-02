/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004c4110 (252b platform.win32) - DirectSound buffer create+release dispatcher.
 *   Reads IDirectSound* from g_dsoundPrimary (return if null).
 *   If arg0 != 0 (init path): calls vtbl methods +0x14/+0x20/+0x1c/+0x18, sets
 *     four "owned" byte-flags (g_dispatchSave1421, _effc, _eff8, _eff4) on success.
 *   If arg0 == 0 (release path): for each owned flag, calls release vtbl +0x38,
 *     +0x44, +0x40, +0x3c; clear all four flags.
 */
extern unsigned int g_dispatchSave1406;
extern unsigned int g_dispatchSave1409;
extern unsigned int g_dispatchSave1413;
extern unsigned int g_dispatchSave1414;
extern void * g_dsoundPrimary;
extern unsigned int g_dispatchSave1418;
extern unsigned int g_dispatchSave1419;
extern unsigned int g_dispatchSave1420;
extern unsigned int g_dispatchSave1421;

__declspec(naked) void Helper_DSI_post1(void) {
    __asm {
        mov     eax, dword ptr [g_dsoundPrimary]
        push    ebx
        xor     ebx, ebx
        cmp     eax, ebx
        jz      L_dbd_done
        cmp     [esp + 8], ebx
        jz      L_dbd_release
        mov     ecx, [eax]
        push    ebx
        push    0x400
        push    offset g_dispatchSave1414
        push    eax
        call    dword ptr [ecx + 0x14]
        neg     eax
        sbb     eax, eax
        push    offset g_dispatchSave1413
        inc     eax
        mov     byte ptr [g_dispatchSave1421], al
        mov     eax, dword ptr [g_dsoundPrimary]
        push    eax
        mov     edx, [eax]
        call    dword ptr [edx + 0x20]
        neg     eax
        sbb     eax, eax
        push    offset g_dispatchSave1406
        inc     eax
        mov     byte ptr [g_dispatchSave1420], al
        mov     eax, dword ptr [g_dsoundPrimary]
        push    eax
        mov     ecx, [eax]
        call    dword ptr [ecx + 0x1c]
        neg     eax
        sbb     eax, eax
        push    offset g_dispatchSave1409
        inc     eax
        mov     byte ptr [g_dispatchSave1419], al
        mov     eax, dword ptr [g_dsoundPrimary]
        push    eax
        mov     edx, [eax]
        call    dword ptr [edx + 0x18]
        neg     eax
        sbb     eax, eax
        inc     eax
        mov     byte ptr [g_dispatchSave1418], al
        pop     ebx
        ret
    L_dbd_release:
        cmp     byte ptr [g_dispatchSave1421], bl
        jz      short L_dbd_r2
        mov     ecx, [eax]
        push    offset g_dispatchSave1414
        push    eax
        call    dword ptr [ecx + 0x38]
        mov     eax, dword ptr [g_dsoundPrimary]
    L_dbd_r2:
        cmp     byte ptr [g_dispatchSave1420], bl
        jz      short L_dbd_r3
        mov     ecx, dword ptr [g_dispatchSave1413]
        mov     edx, [eax]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x44]
        mov     eax, dword ptr [g_dsoundPrimary]
    L_dbd_r3:
        cmp     byte ptr [g_dispatchSave1419], bl
        jz      short L_dbd_r4
        mov     ecx, dword ptr [g_dispatchSave1406]
        mov     edx, [eax]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x40]
        mov     eax, dword ptr [g_dsoundPrimary]
    L_dbd_r4:
        cmp     byte ptr [g_dispatchSave1418], bl
        jz      short L_dbd_r_end
        mov     ecx, dword ptr [g_dispatchSave1409]
        mov     edx, [eax]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x3c]
    L_dbd_r_end:
        mov     byte ptr [g_dispatchSave1421], bl
        mov     byte ptr [g_dispatchSave1420], bl
        mov     byte ptr [g_dispatchSave1419], bl
        mov     byte ptr [g_dispatchSave1418], bl
    L_dbd_done:
        pop     ebx
        ret
    }
}

