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

/* @addr 0x00473070 (73b)
 *   Push g_eventQueueCurrent on stack[idx*4]; set g_eventQueueCurrent = -1;
 *   call F; pause-test → ret; pop stack value back into g_eventQueueCurrent.
 */
extern void Helper_TickFrame_PostFight(void);
void PushPopCurrentSetFFFFFFFF_00473070(void) {
    unsigned int top;
    top = g_state_004d57ac + 1;
    g_state_004d57ac = top;
    *(unsigned int *)(top * 4) = g_eventQueueCurrent;
    g_eventQueueCurrent = 0xffffffff;
    Helper_TickFrame_PostFight();
    if (g_framePauseFlag != 0) return;
    top = g_state_004d57ac;
    g_eventQueueCurrent = *(unsigned int *)(top * 4);
    g_state_004d57ac = top - 1;
}
