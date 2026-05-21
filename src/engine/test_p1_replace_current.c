/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004751c0 (43b)
 *   mov     eax, [g_state_00537f48]
 *   mov     ecx, [g_eventQueueEnd]
 *   mov     [g_eventQueueCurrent], eax
 *   mov     eax, [g_player1NodeIdx]
 *   cmp     ecx, eax
 *   mov     [g_walkCallback], eax
 *   je      +0x0c
 *   mov     ecx, [g_state_005380e0]
 *   mov     [g_eventQueueCurrent], ecx
 *   ret
 */
extern s32 g_dlNalt1;       /* 0x00537f48 */
extern unsigned int g_state_005380e0;
void TestP1ReplaceCurrent_004751c0(void) {
    g_eventQueueCurrent = (unsigned int)g_dlNalt1;
    g_walkCallback = (void (*)(void))g_player1NodeIdx;
    if (g_eventQueueEnd == g_player1NodeIdx) return;
    g_eventQueueCurrent = g_state_005380e0;
}
