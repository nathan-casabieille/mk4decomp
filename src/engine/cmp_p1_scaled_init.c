/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004709c0 (31b)
 *   mov     ecx, [g_player1NodeIdx]
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [g_player1NodeIdx]
 *   cmp     ecx, eax
 *   je      .skip
 *   mov     [g_scaledInit_00542044], eax
 * .skip:
 *   ret
 */
void CmpP1ScaledInit_004709c0(void) {
    g_scaledInit_00542044 = g_player2NodeIdx;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_scaledInit_00542044 = g_player1NodeIdx;
    }
}
