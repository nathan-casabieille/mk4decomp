/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0048f910 (31b)
 *   mov     eax, [g_baseSel]
 *   mov     eax, [eax*4 + 0x3c]
 *   mov     [g_currentNodeIdx], eax
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   ret
 */
void ScaledChain3c74(void) {
    unsigned int v = ((ScenegraphNode *)(g_baseSel * 4))->child_a;
    g_currentNodeIdx = v;
    g_walkCallback = (void (*)(void))((ScenegraphNode *)(v * 4))->fsm_state;
}

/* @addr 0x0048f930 (31b): same shape with offset 0x7c instead of 0x74 */
void ScaledChain3c7c(void) {
    unsigned int v = ((ScenegraphNode *)(g_baseSel * 4))->child_a;
    g_currentNodeIdx = v;
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x7c);
}
