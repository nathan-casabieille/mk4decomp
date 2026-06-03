/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00473070 (73b)
 *   Push g_eventQueueCurrent on stack[idx*4]; set g_eventQueueCurrent = -1;
 *   call F; pause-test → ret; pop stack value back into g_eventQueueCurrent.
 */
extern void Thunk_StructArrayWalkCondCall(void);
void PushPopCurrentSetFFFFFFFF(void) {
    unsigned int top;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = g_eventQueueCurrent;
    g_eventQueueCurrent = 0xffffffff;
    Thunk_StructArrayWalkCondCall();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_eventQueueCurrent = *(unsigned int *)(top * 4);
    g_matrixStackTop = top - 1;
}
