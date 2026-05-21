/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00452740 (37b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [g_eventQueueEnd]
 *   mov     [eax*4 + 0x64], ecx
 *   mov     edx, [g_baseSel_00542060]
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [edx*4 + 0x68], eax
 *   ret
 */
void DualScaledStore_00452740(void) {
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x64) = g_eventQueueEnd;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x68) = g_eventQueueIdx;
}
