/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00431d50 (74b)
 *   walk = 0x1921f - walk; mov g_eventQueueWorkType = walk; call F1;
 *   pause → ret; g_chainAccumCur = walk; call F2; pause → ret;
 *   g_eventQueueWorkType = walk; ret.
 */
extern unsigned int g_chainAccumCur;
extern void MStackMagicModMul10(void);
extern void ModMagicMul10Index(void);
void WalkCbSubMul10(void) {
    unsigned int v = 0x1921f - (unsigned int)g_walkCallback;
    g_walkCallback = (void(*)(void))v;
    g_eventQueueWorkType = v;
    MStackMagicModMul10();
    if (g_framePauseFlag) return;
    g_chainAccumCur = (unsigned int)g_walkCallback;
    ModMagicMul10Index();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = (unsigned int)g_walkCallback;
}
