/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0048e550 (54b)
 *   mov     eax, [esp+4]
 *   mov     edx, [g_fightGroupHead]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     ecx, [eax*4 + 0]
 *   mov     [g_currentNodeIdx], ecx
 *   mov     ecx, [g_player1NodeIdx]
 *   cmp     edx, ecx
 *   je      +0x0c
 *   mov     eax, [eax*4 + 4]
 *   mov     [g_currentNodeIdx], eax
 *   ret
 */
void ArgScaledLoadCmpP1(int arg) {
    unsigned int idx = (unsigned int)(arg >> 2);
    g_eventQueueTotal = idx;
    g_currentNodeIdx = *(unsigned int *)(idx * 4);
    if (g_fightGroupHead == g_player1NodeIdx) return;
    g_currentNodeIdx = *(unsigned int *)(idx * 4 + 4);
}
