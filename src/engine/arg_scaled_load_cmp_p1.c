/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x0048e550 (54b)
 *   mov     eax, [esp+4]
 *   mov     edx, [g_fightGroupHead]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     ecx, [eax*4 + 0]
 *   mov     [g_walkCallback], ecx
 *   mov     ecx, [g_player1NodeIdx]
 *   cmp     edx, ecx
 *   je      +0x0c
 *   mov     eax, [eax*4 + 4]
 *   mov     [g_scaledInit_00542044], eax
 *   ret
 */
extern packed_ptr g_player1NodeIdx;
extern packed_ptr g_fightGroupHead;
void ArgScaledLoadCmpP1_0048e550(int arg) {
    unsigned int idx = (unsigned int)(arg >> 2);
    g_eventQueueTotal = idx;
    g_walkCallback = (void (*)(void))*(unsigned int *)(idx * 4);
    if (g_fightGroupHead == g_player1NodeIdx) return;
    g_scaledInit_00542044 = *(unsigned int *)(idx * 4 + 4);
}
