/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_dispatchWalkVar;

void DispatchSetWalk2(void) {
    unsigned int v;
    if (g_gtOtherFlag) return;
    v = g_dispatchWalkVar;
    g_walkCallback = (void(*)(void))v;
    if (v) return;
    g_eventQueueCurrent = v;
    MStackPush3MaskBit0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        g_eventQueueCurrent = 1;
    }
    g_walkCallback = (void(*)(void))2;
    GuardedFourCallChain();
}
