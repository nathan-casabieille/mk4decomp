/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004911f0 (57b)
 *   scaled chain: baseSel*4 + 0x40 → g_scaledInit; deref *4 → g_eventQueueNotMask
 *   reload baseSel*4 + 0x44 → g_scaledInit; deref *4 → g_eventQueueChild
 */
void ScaledChainDouble_004911f0(void) {
    unsigned int base = g_baseSel_00542060;
    unsigned int s1 = *(unsigned int *)(base * 4 + 0x40);
    unsigned int s2;
    g_scaledInit_00542044 = s1;
    g_eventQueueNotMask = *(unsigned int *)(s1 * 4);
    s2 = *(unsigned int *)(base * 4 + 0x44);
    g_scaledInit_00542044 = s2;
    g_eventQueueChild = *(unsigned int *)(s2 * 4);
}
