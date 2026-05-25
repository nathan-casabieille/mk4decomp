/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_dispatchWalkVar_0053a404;

void DispatchSetWalk4_00492780(void) {
    unsigned int v;
    if (g_gtOtherFlag) return;
    v = g_dispatchWalkVar_0053a404;
    g_walkCallback = (void(*)(void))v;
    if (v) return;
    g_eventQueueCurrent = v;
    MStackPush3MaskBit_00492920();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        g_eventQueueCurrent = 1;
    }
    g_walkCallback = (void(*)(void))4;
    GuardedFourCallChain_004928c0();
}
