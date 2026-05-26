/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00480d20 (44b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x38]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0x54]
 *   mov     [g_walkCallback], ecx
 *   mov     edx, [eax*4 + 0x5c]
 *   mov     [g_eventQueueCurrent], edx
 *   ret
 */
void ScaledChainTwoStores_00480d20(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x38);
    g_scaledInit_00542044 = v;
    g_walkCallback = (void (*)(void))((ScenegraphNode *)(v * 4))->position_x;
    g_eventQueueCurrent = ((ScenegraphNode *)(v * 4))->position_z;
}
