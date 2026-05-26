/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0047d510 (73b)
 *   Push g_eventQueueNotMask on stack[idx*4]; set g_walkCallback = 0xc;
 *   call F; pause-test → ret; pop stack value back into g_eventQueueNotMask.
 */
extern void TableLookupCall_0048a160(void);
void PushPopNotMaskSetWalk0xc_0047d510(void) {
    unsigned int top;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_eventQueueNotMask;
    g_walkCallback = (void (*)(void))0x0c;
    TableLookupCall_0048a160();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_eventQueueNotMask = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}
