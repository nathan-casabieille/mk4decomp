/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ac100 (31b)
 *   mov     eax, [g_player1NodeIdx]
 *   mov     ecx, [g_fightGroupHead]
 *   cmp     ecx, eax
 *   mov     [g_scaledInit_00542044], eax
 *   jne     +0x0a
 *   mov     eax, [g_player2NodeIdx]
 *   mov     [g_scaledInit_00542044], eax
 *   ret
 */
extern packed_ptr g_player1NodeIdx;
extern packed_ptr g_player2NodeIdx;
void CmpP1ScaledInitB_004ac100(void) {
    g_scaledInit_00542044 = g_player1NodeIdx;
    if (g_fightGroupHead == g_player1NodeIdx) {
        g_scaledInit_00542044 = g_player2NodeIdx;
    }
}
