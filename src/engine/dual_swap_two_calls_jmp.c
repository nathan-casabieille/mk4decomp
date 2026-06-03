/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x0045d960 (78b)
 *   Dual-scaled-init helper: copies g_xformEntityIdx →
 *   g_eventQueueTotal, [0x53a498] → g_eventQueueWorkType;
 *   call F; pause → ret; copies g_scaledInit → g_eventQueueTotal,
 *   walk → g_eventQueueWorkType; call F again; pause → ret;
 *   jmp T.
 */
extern void ChainShiftRight8(void);
void DualSwapTwoCallsJmp(void) {
    g_eventQueueTotal = g_xformEntityIdx;
    g_eventQueueWorkType = g_gtFightTickCounter;
    ChainShiftRight8();
    if (g_framePauseFlag) return;
    g_eventQueueTotal = g_currentNodeIdx;
    g_eventQueueWorkType = (unsigned int)g_walkCallback;
    ChainShiftRight8();
    if (g_framePauseFlag) return;
    CallSetPause();
}
