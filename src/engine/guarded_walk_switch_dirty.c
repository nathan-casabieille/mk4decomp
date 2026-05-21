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

/* @addr 0x0048ea40 (67b)
 *   call F1; pause → ret;
 *   eax = g_walkCallback; if == 0x2005, set dirty bit 0 → ret;
 *   if == 0x2002, set dirty bit 0 → ret; else clear bit 0 → ret.
 *   The second arm loads g_xformDirtyFlags BEFORE the conditional
 *   branch (codegen quirk: cmp flags preserved across load).
 */
extern void ScaledChain3c74_0048f910(void);
void GuardedWalkSwitchDirty_0048ea40(void) {
    unsigned int v;
    ScaledChain3c74_0048f910();
    if (g_framePauseFlag != 0) return;
    v = (unsigned int)g_walkCallback;
    if (v == 0x2005) {
        g_xformDirtyFlags |= 1;
        return;
    }
    if (v == 0x2002) {
        g_xformDirtyFlags |= 1;
    } else {
        g_xformDirtyFlags &= 0xFFFFFFFEu;
    }
}
