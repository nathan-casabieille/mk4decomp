/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

void DispatchSetWalk3_004927d0(void) {
    unsigned int v;
    if (g_data_0054356c) return;
    v = g_data_0053a404;
    g_walkCallback = (void(*)(void))v;
    if (v) return;
    g_eventQueueCurrent = v;
    MStackPush3MaskBit0_004929e0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        g_eventQueueCurrent = 1;
    }
    g_walkCallback = (void(*)(void))3;
    GuardedFourCallChain_004928c0();
}
