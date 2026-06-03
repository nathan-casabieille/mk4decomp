/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x0048ea40 (67b)
 *   call F1; pause → ret;
 *   eax = g_walkCallback; if == 0x2005, set dirty bit 0 → ret;
 *   if == 0x2002, set dirty bit 0 → ret; else clear bit 0 → ret.
 *   The second arm loads g_xformDirtyFlags BEFORE the conditional
 *   branch (codegen quirk: cmp flags preserved across load).
 */
extern void ScaledChain3c74(void);
void GuardedWalkSwitchDirty(void) {
    unsigned int v;
    ScaledChain3c74();
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
