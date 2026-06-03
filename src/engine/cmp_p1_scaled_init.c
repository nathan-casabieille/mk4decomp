/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004709c0 (31b)
 *   mov     ecx, [g_player1NodeIdx]
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_currentNodeIdx], eax
 *   mov     eax, [g_player1NodeIdx]
 *   cmp     ecx, eax
 *   je      .skip
 *   mov     [g_currentNodeIdx], eax
 * .skip:
 *   ret
 */
void CmpP1ScaledInit(void) {
    g_currentNodeIdx = g_player2NodeIdx;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_currentNodeIdx = g_player1NodeIdx;
    }
}
