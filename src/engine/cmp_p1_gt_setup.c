/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_acc_00542078;

/* @addr 0x00470980 (55b)
 *   mov     ecx, [g_gtPlayerProbe2]
 *   mov     eax, [g_player1NodeIdx]
 *   mov     [g_eventQueueIdx], ecx
 *   mov     ecx, [g_fightGroupHead]
 *   cmp     ecx, eax
 *   mov     [g_currentNodeIdx], eax
 *   je      +0x16
 *   mov     edx, [g_player2NodeIdx]
 *   mov     eax, [g_gtPlayerProbe1]
 *   mov     [g_currentNodeIdx], edx
 *   mov     [g_eventQueueIdx], eax
 *   ret
 */
void CmpP1GTSetup(void) {
    unsigned int p1 = g_player1NodeIdx;
    g_xformEntityIdx = g_gtPlayerProbe2;
    g_currentNodeIdx = p1;
    if (g_fightGroupHead == p1) return;
    g_currentNodeIdx = g_player2NodeIdx;
    g_xformEntityIdx = g_gtPlayerProbe1;
}
