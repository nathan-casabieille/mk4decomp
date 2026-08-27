/**
 * 2 "dual scaled init with conditional override" helpers (54b).
 *
 * Pattern:
 *   mov     ecx, [g_player1NodeIdx]
 *   mov     edx, [g_fightGroupHead]
 *   mov     eax, ADDR1
 *   mov     [g_pendingNodeType], ecx
 *   shr     eax, 2
 *   mov     [g_currentNodeIdx], eax
 *   mov     eax, ADDR2
 *   shr     eax, 2
 *   cmp     edx, ecx                          ; same as player1 group?
 *   mov     [g_xformEntityIdx], eax
 *   je      .ret
 *   mov     [g_currentNodeIdx], eax      ; override base if not p1
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;

/* @addr 0x0046dbd0 */
extern unsigned int g_installCountdownSlot;
void DualScaledInitCmp_0046dbd0(void) {
    g_pendingNodeType = g_player1NodeIdx;
    g_currentNodeIdx = (unsigned int)MK4_UNPTR(&g_installCountdownSlot) >> 2;
    g_xformEntityIdx = (unsigned int)MK4_UNPTR(&g_nodeSlotsHdr_end) >> 2;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_currentNodeIdx = (unsigned int)MK4_UNPTR(&g_nodeSlotsHdr_end) >> 2;
    }
}

/* @addr 0x0046df50 */
extern unsigned int g_dispatchSave13;
extern unsigned int g_phaseThunkSlot3;
void DualScaledInitCmp_0046df50(void) {
    g_pendingNodeType = g_player1NodeIdx;
    g_currentNodeIdx = (unsigned int)MK4_UNPTR(&g_dispatchSave13) >> 2;
    g_xformEntityIdx = (unsigned int)MK4_UNPTR(&g_phaseThunkSlot3) >> 2;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_currentNodeIdx = (unsigned int)MK4_UNPTR(&g_phaseThunkSlot3) >> 2;
    }
}
