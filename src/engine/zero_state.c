/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x0048a1b0 (11b)
 *   mov     [g_state], 0
 *   ret
 */
extern unsigned int g_armedReloadA;
void ZeroState(void) {
    g_armedReloadA = 0;
}
