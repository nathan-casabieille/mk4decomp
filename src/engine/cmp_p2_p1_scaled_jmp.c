/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048ee50 (35b)
 *   mov     eax, [g_player2NodeIdx]
 *   mov     ecx, [g_fightGroupHead]
 *   cmp     ecx, eax
 *   mov     [g_scaledInit_00542044], eax
 *   jne     +0x0a
 *   mov     eax, [g_player1NodeIdx]
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     +0x1d
 */
extern void func_0048ee77(void);
void CmpP2P1ScaledJmp_0048ee50(void) {
    g_scaledInit_00542044 = g_player2NodeIdx;
    if (g_fightGroupHead == g_player2NodeIdx) {
        g_scaledInit_00542044 = g_player1NodeIdx;
    }
    func_0048ee77();
}
