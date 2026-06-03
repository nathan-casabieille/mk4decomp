/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00480d20 (44b)
 *   mov     eax, [g_baseSel]
 *   mov     eax, [eax*4 + 0x38]
 *   mov     [g_currentNodeIdx], eax
 *   mov     ecx, [eax*4 + 0x54]
 *   mov     [g_walkCallback], ecx
 *   mov     edx, [eax*4 + 0x5c]
 *   mov     [g_eventQueueCurrent], edx
 *   ret
 */
void ScaledChainTwoStores(void) {
    unsigned int v = *(unsigned int *)(g_baseSel * 4 + 0x38);
    g_currentNodeIdx = v;
    g_walkCallback = (void (*)(void))((ScenegraphNode *)(v * 4))->position_x;
    g_eventQueueCurrent = ((ScenegraphNode *)(v * 4))->position_z;
}
