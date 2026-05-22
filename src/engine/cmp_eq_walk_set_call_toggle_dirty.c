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

extern unsigned int g_data_00538158;

/* @addr 0x00439c60 (79b)
 *   if g_fightGroupHead == [0x538158]: walk = 0x46; else walk = 0x45.
 *   call F; pause → ret;
 *   if (dirty & 4): set bit 0 of dirty → ret; else clear bit 0 → ret.
 */
void CmpEqWalkSetCallToggleDirty_00439c60(void) {
    g_walkCallback = (void(*)(void))0x46;
    if (g_fightGroupHead != g_data_00538158) {
        g_walkCallback = (void(*)(void))0x45;
    }
    SetJmp_0049cb90();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) {
        g_xformDirtyFlags = g_xformDirtyFlags | 1;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
