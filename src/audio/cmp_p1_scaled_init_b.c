/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004ac100 (31b)
 *   mov     eax, [g_player1NodeIdx]
 *   mov     ecx, [g_fightGroupHead]
 *   cmp     ecx, eax
 *   mov     [g_currentNodeIdx], eax
 *   jne     +0x0a
 *   mov     eax, [g_player2NodeIdx]
 *   mov     [g_currentNodeIdx], eax
 *   ret
 */
extern packed_ptr g_player1NodeIdx;
extern packed_ptr g_player2NodeIdx;
void CmpP1ScaledInitB(void) {
    g_currentNodeIdx = g_player1NodeIdx;
    if (g_fightGroupHead == g_player1NodeIdx) {
        g_currentNodeIdx = g_player2NodeIdx;
    }
}
