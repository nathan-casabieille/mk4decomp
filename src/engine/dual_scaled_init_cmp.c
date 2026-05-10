/**
 * 2 "dual scaled init with conditional override" helpers (54b).
 *
 * Pattern:
 *   mov     ecx, [g_player1NodeIdx]
 *   mov     edx, [g_fightGroupHead]
 *   mov     eax, ADDR1
 *   mov     [g_pendingNodeType], ecx
 *   shr     eax, 2
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, ADDR2
 *   shr     eax, 2
 *   cmp     edx, ecx                          ; same as player1 group?
 *   mov     [g_scaledInit_00542048], eax
 *   je      .ret
 *   mov     [g_scaledInit_00542044], eax      ; override base if not p1
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_scaledInit_00542048;

/* @addr 0x0046dbd0 */
__declspec(naked) void DualScaledInitCmp_0046dbd0(void) {
    __asm {
        mov     ecx, dword ptr [g_player1NodeIdx]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0x00541e24
        mov     dword ptr [g_pendingNodeType], ecx
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, 0x00541e40
        shr     eax, 2
        cmp     edx, ecx
        mov     dword ptr [g_scaledInit_00542048], eax
        _emit   74h
        _emit   05h
        mov     dword ptr [g_scaledInit_00542044], eax
        ret
    }
}

/* @addr 0x0046df50 */
__declspec(naked) void DualScaledInitCmp_0046df50(void) {
    __asm {
        mov     ecx, dword ptr [g_player1NodeIdx]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0x00541e44
        mov     dword ptr [g_pendingNodeType], ecx
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, 0x0052aa88
        shr     eax, 2
        cmp     edx, ecx
        mov     dword ptr [g_scaledInit_00542048], eax
        _emit   74h
        _emit   05h
        mov     dword ptr [g_scaledInit_00542044], eax
        ret
    }
}
