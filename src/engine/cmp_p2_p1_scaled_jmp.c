/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0048ee50 (35b)
 *   mov     eax, [g_player2NodeIdx]
 *   mov     ecx, [g_fightGroupHead]
 *   cmp     ecx, eax
 *   mov     [g_currentNodeIdx], eax
 *   jne     +0x0a
 *   mov     eax, [g_player1NodeIdx]
 *   mov     [g_currentNodeIdx], eax
 *   jmp     +0x1d
 */
extern void ScaledSubStore(void);
void CmpP2P1ScaledJmp(void) {
    g_currentNodeIdx = g_player2NodeIdx;
    if (g_fightGroupHead == g_player2NodeIdx) {
        g_currentNodeIdx = g_player1NodeIdx;
    }
    ScaledSubStore();
}
