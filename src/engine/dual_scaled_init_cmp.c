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
extern unsigned int g_data_00541e24;
void DualScaledInitCmp_0046dbd0(void) {
    g_pendingNodeType = g_player1NodeIdx;
    g_scaledInit_00542044 = (unsigned int)&g_data_00541e24 >> 2;
    g_scaledInit_00542048 = (unsigned int)&g_nodeSlotsHdr_end >> 2;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_scaledInit_00542044 = (unsigned int)&g_nodeSlotsHdr_end >> 2;
    }
}

/* @addr 0x0046df50 */
extern unsigned int g_dispatchSave13_00541e44;
extern unsigned int g_phaseThunkSlot3_0052aa88;
void DualScaledInitCmp_0046df50(void) {
    g_pendingNodeType = g_player1NodeIdx;
    g_scaledInit_00542044 = (unsigned int)&g_dispatchSave13_00541e44 >> 2;
    g_scaledInit_00542048 = (unsigned int)&g_phaseThunkSlot3_0052aa88 >> 2;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_scaledInit_00542044 = (unsigned int)&g_phaseThunkSlot3_0052aa88 >> 2;
    }
}
