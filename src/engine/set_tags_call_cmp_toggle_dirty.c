/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00458c70 (77b)
 *   eventQueueCurrent = walk; pendingNodeType = (0x53a53c >> 2) + 0x3b;
 *   call F; if !pause: cmp g_eventQueueCurrent, walk;
 *   if jae: dirty |= 1; else: dirty &= ~1; ret.
 */
extern void ScaledMaskByte_004774d0(void);
extern unsigned int g_table_0053a53c;
void SetTagsCallCmpToggleDirty_00458c70(void) {
    g_eventQueueCurrent = (unsigned int)g_walkCallback;
    g_pendingNodeType = ((unsigned int)&g_table_0053a53c >> 2) + 0x3b;
    ScaledMaskByte_004774d0();
    if (g_framePauseFlag != 0) {
        return;
    }
    if (g_eventQueueCurrent < (unsigned int)g_walkCallback) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffeu;
    } else {
        g_xformDirtyFlags = g_xformDirtyFlags | 1;
    }
}
