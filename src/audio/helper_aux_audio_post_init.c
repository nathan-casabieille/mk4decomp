/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004ac320 (128b audio) - timer setup helper (PostInit body):
 *   issues two iat-4d2244 calls (timeBeginPeriod and timeSetEvent
 *   style) to set up a timer; returns 1 on success, 0 on failure.
 *   Stashes audio pre-state and start-of-period markers.
 */
__declspec(naked) void Helper_AuxAudio_PostInit(void) {
    __asm {
        mov     eax, dword ptr [g_audioState08]
        sub     esp, 0x24
        test    eax, eax
        push    esi
        mov     esi, dword ptr [g_iat_004d2244]
        jne     skipBegin
        lea     eax, [esp + 0x14]
        mov     dword ptr [esp + 0x1c], 0x004f4684
        push    eax
        push    0x2100
        push    0x803
        push    0
        call    esi
        neg     eax
        sbb     eax, eax
        inc     eax
        mov     dword ptr [g_audioState08], eax
        je      failPath
        mov     ecx, dword ptr [esp + 0x18]
        mov     dword ptr [g_audioPreState], ecx
skipBegin:
        mov     eax, dword ptr [g_audioPreState]
        lea     edx, [esp + 4]
        push    edx
        push    0x100
        push    0x814
        push    eax
        mov     dword ptr [esp + 0x1c], 5
        call    esi
        test    eax, eax
        jne     failPath
        mov     eax, dword ptr [esp + 8]
        test    eax, eax
        je      failPath
        mov     eax, 1
        pop     esi
        add     esp, 0x24
        ret
failPath:
        xor     eax, eax
        pop     esi
        add     esp, 0x24
        ret
    }
}

