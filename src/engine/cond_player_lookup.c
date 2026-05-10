/**
 * 3 "conditional player-table lookup" helpers (38 bytes each).
 *
 * Pattern:
 *   mov eax, [g_primary]
 *   mov ecx, [g_fightGroupHead]
 *   mov [g_dest], eax
 *   mov eax, [g_player1NodeIdx]
 *   cmp ecx, eax                  ; same group as player1?
 *   je  skip
 *   mov edx, [g_secondary]        ; else override with secondary
 *   mov [g_dest], edx
 * skip:
 *   ret
 *
 * Installs primary into the destination slot, then if the current
 * fight-group is not the player1 group, swaps in a secondary value.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_primary_0053a774;   /* 0x0053a774 */
extern unsigned int g_secondary_00535d04; /* 0x00535d04 */
extern unsigned int g_primary_0052d74c;   /* 0x0052d74c */
extern unsigned int g_secondary_00538068; /* 0x00538068 */
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048f270 */
__declspec(naked) void CondPlayerLookup_0048f270(void) {
    __asm {
        mov     eax, dword ptr [g_primary_0053a774]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_player1NodeIdx]
        cmp     ecx, eax
        _emit   74h
        _emit   0ch
        mov     edx, dword ptr [g_secondary_00535d04]
        mov     dword ptr [g_walkCallback], edx
        ret
    }
}

/* @addr 0x0048f950 */
__declspec(naked) void CondPlayerLookup_0048f950(void) {
    __asm {
        mov     eax, dword ptr [g_primary_0052d74c]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_player1NodeIdx]
        cmp     ecx, eax
        _emit   74h
        _emit   0ch
        mov     edx, dword ptr [g_secondary_00538068]
        mov     dword ptr [g_walkCallback], edx
        ret
    }
}

/* @addr 0x004ac120 */
__declspec(naked) void CondPlayerLookup_004ac120(void) {
    __asm {
        mov     eax, dword ptr [g_gtPlayerProbe2]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [g_player1NodeIdx]
        cmp     ecx, eax
        _emit   74h
        _emit   0ch
        mov     edx, dword ptr [g_gtPlayerProbe1]
        mov     dword ptr [g_scaledInit_00542044], edx
        ret
    }
}
