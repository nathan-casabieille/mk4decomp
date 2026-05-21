/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x00470980 (55b)
 *   mov     ecx, [g_gtPlayerProbe2]
 *   mov     eax, [g_player1NodeIdx]
 *   mov     [g_eventQueueIdx], ecx
 *   mov     ecx, [g_fightGroupHead]
 *   cmp     ecx, eax
 *   mov     [g_scaledInit_00542044], eax
 *   je      +0x16
 *   mov     edx, [g_player2NodeIdx]
 *   mov     eax, [g_gtPlayerProbe1]
 *   mov     [g_scaledInit_00542044], edx
 *   mov     [g_eventQueueIdx], eax
 *   ret
 */
extern packed_ptr g_player1NodeIdx;
extern packed_ptr g_player2NodeIdx;
extern u32 g_gtPlayerProbe1;
extern u32 g_gtPlayerProbe2;
extern packed_ptr g_fightGroupHead;
void CmpP1GTSetup_00470980(void) {
    unsigned int p1 = g_player1NodeIdx;
    g_eventQueueIdx = g_gtPlayerProbe2;
    g_scaledInit_00542044 = p1;
    if (g_fightGroupHead == p1) return;
    g_scaledInit_00542044 = g_player2NodeIdx;
    g_eventQueueIdx = g_gtPlayerProbe1;
}
