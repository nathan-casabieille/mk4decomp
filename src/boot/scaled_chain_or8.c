/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404e50 (52b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x18]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0x28]
 *   mov     [g_xformEntityIdx], ecx
 *   mov     eax, [ecx*4 + 0]
 *   or      al, 8
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0], eax
 *   ret
 */
void ScaledChainOr8_00404e50(void) {
    unsigned int s;
    unsigned int e;
    unsigned int v;
    s = ((ScenegraphNode *)(g_fightGroupHead * 4))->child_chain;
    g_scaledInit_00542044 = s;
    e = ((ScenegraphNode *)(s * 4))->queue_idx;
    g_xformEntityIdx = e;
    v = *(unsigned int *)(e * 4) | 8;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(e * 4) = v;
}
