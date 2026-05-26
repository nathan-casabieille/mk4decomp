/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00408860 (68b)
 *   load scaled+0x28 into walk; if non-zero clear dirty bit 4 and ret;
 *   else call F; pause → ret; load g_scaledInit and g_xformEntityIdx;
 *   store xformEntityIdx into [scaledInit*4 + 0x28]; ret.
 */
extern void MStackPush2Burst6Init_00405450(void);
void ScaledTestPauseStore_00408860(void) {
    unsigned int v = ((ScenegraphNode *)(g_scaledInit_00542044 * 4))->queue_idx;
    g_walkCallback = (void(*)(void))v;
    if (v) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFBu;
        return;
    }
    MStackPush2Burst6Init_00405450();
    if (g_framePauseFlag) return;
    ((ScenegraphNode *)(g_scaledInit_00542044 * 4))->queue_idx = g_xformEntityIdx;
}
