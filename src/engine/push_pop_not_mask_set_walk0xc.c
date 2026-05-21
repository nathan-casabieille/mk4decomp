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

/* @addr 0x0047d510 (73b)
 *   Push g_eventQueueNotMask on stack[idx*4]; set g_walkCallback = 0xc;
 *   call F; pause-test → ret; pop stack value back into g_eventQueueNotMask.
 */
extern void func_0048a150(void);
void PushPopNotMaskSetWalk0xc_0047d510(void) {
    unsigned int top;
    top = g_state_004d57ac + 1;
    g_state_004d57ac = top;
    *(unsigned int *)(top * 4) = g_eventQueueNotMask;
    g_walkCallback = (void (*)(void))0x0c;
    func_0048a150();
    if (g_framePauseFlag != 0) return;
    top = g_state_004d57ac;
    g_eventQueueNotMask = *(unsigned int *)(top * 4);
    g_state_004d57ac = top - 1;
}
