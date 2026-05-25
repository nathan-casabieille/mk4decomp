/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404c70 (66b)
 *   walk = arg2; eventQueueCurrent = 0xffff; call F; pause-test → ret;
 *   testb 1,[dirty]; jne ret; load arg1; eventQueueWorkType = arg2;
 *   pendingNodeType = arg1; call F2.
 */
extern void Thunk_0049cb70(void);
/* AllocNode declared in engine/scenegraph.h */
void SetWalkCurCallPauseDirty_00404c70(int arg1, int arg2) {
    g_walkCallback = (unsigned int)arg2;
    g_eventQueueCurrent = 0xffff;
    Thunk_0049cb70();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((g_xformDirtyFlags & 1) != 0) {
        return;
    }
    g_eventQueueWorkType = arg2;
    g_pendingNodeType = arg1;
    AllocNode();
}
