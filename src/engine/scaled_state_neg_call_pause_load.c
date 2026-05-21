/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueEnd;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueWorkType;
extern u32 g_pendingNodeType;
extern u32 g_eventQueueNotMask;

/* @addr 0x00489e90 (70b)
 *   copy g_scaledInit → g_pendingNodeType; load g_state_0052d74c;
 *   if non-neg call F1; pause → ret; load g_state_00538068 → g_xformEntityIdx;
 *   if signed: jmp T1.
 */
extern unsigned int g_state_0052d74c;
extern unsigned int g_state_00538068;
extern void func_00489c60(void);
extern void func_00489c30(void);
void ScaledStateNegCallPauseLoad_00489e90(void) {
    int v;
    g_pendingNodeType = g_scaledInit_00542044;
    v = (int)g_state_0052d74c;
    g_walkCallback = (void (*)(void))v;
    if (v < 0) {
        func_00489c60();
        if (g_framePauseFlag != 0) return;
    }
    v = (int)g_state_00538068;
    g_pendingNodeType = g_xformEntityIdx;
    g_walkCallback = (void (*)(void))v;
    if (v < 0) {
        func_00489c30();
    }
}
