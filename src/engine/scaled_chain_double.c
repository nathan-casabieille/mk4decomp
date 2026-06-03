/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004911f0 (57b)
 *   scaled chain: baseSel*4 + 0x40 → g_scaledInit; deref *4 → g_eventQueueNotMask
 *   reload baseSel*4 + 0x44 → g_scaledInit; deref *4 → g_eventQueueChild
 */
void ScaledChainDouble(void) {
    unsigned int base = g_baseSel;
    unsigned int s1 = ((ScenegraphNode *)(base * 4))->child_b;
    unsigned int s2;
    g_currentNodeIdx = s1;
    g_eventQueueNotMask = *(unsigned int *)(s1 * 4);
    s2 = ((ScenegraphNode *)(base * 4))->child_c;
    g_currentNodeIdx = s2;
    g_eventQueueChild = *(unsigned int *)(s2 * 4);
}
