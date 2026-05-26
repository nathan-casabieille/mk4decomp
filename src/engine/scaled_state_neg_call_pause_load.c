/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00489e90 (70b)
 *   copy g_scaledInit → g_pendingNodeType; load g_primary_0052d74c;
 *   if non-neg call F1; pause → ret; load g_secondary_00538068 → g_xformEntityIdx;
 *   if signed: jmp T1.
 */
extern unsigned int g_primary_0052d74c;
extern unsigned int g_secondary_00538068;
extern void DualSubFromField_00489c70(void);
extern void DualSubFromField_00489c70(void);
void ScaledStateNegCallPauseLoad_00489e90(void) {
    int v;
    g_pendingNodeType = g_scaledInit_00542044;
    v = (int)g_primary_0052d74c;
    g_walkCallback = (void (*)(void))v;
    if (v < 0) {
        DualSubFromField_00489c70();
        if (g_framePauseFlag != 0) return;
    }
    v = (int)g_secondary_00538068;
    g_pendingNodeType = g_xformEntityIdx;
    g_walkCallback = (void (*)(void))v;
    if (v < 0) {
        DualSubFromField_00489c70();
    }
}
