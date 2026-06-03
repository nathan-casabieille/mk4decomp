/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00452740 (37b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [g_eventQueueEnd]
 *   mov     [eax*4 + 0x64], ecx
 *   mov     edx, [g_baseSel]
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [edx*4 + 0x68], eax
 *   ret
 */
void DualScaledStore(void) {
    *(unsigned int *)(g_baseSel * 4 + 0x64) = g_eventQueueEnd;
    *(unsigned int *)(g_baseSel * 4 + 0x68) = g_eventQueueIdx;
}
