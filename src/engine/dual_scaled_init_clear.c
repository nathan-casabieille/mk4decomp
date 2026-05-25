/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x00433c10 (74b)
 *   Dual scaled-init helper: stores 0x53a1a0>>2 into g_scaledInit
 *   and 0x53a518>>2 into g_xformEntityIdx; if g_fightGroupHead !=
 *   [0x538158], also overrides g_scaledInit with the second value.
 *   Then clears g_walkCallback and the indexed slot.
 */
extern unsigned int g_player1NodeIdx;

__declspec(naked) void DualScaledInitClear_00433c10(void) {
    __asm {
        mov     edx, dword ptr [g_fightGroupHead]
        push    esi
        mov     esi, dword ptr [g_player1NodeIdx]
        mov     eax, 0x0053a1a0
        mov     ecx, 0x0053a518
        shr     eax, 2
        shr     ecx, 2
        cmp     edx, esi
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        _emit   74h
        _emit   07h
        mov     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax*4 + 0], 0
        pop     esi
        ret
    }
}
