/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004227b0 (94b)
 *   g_eventQueueCurrent=4; g_scaledInit=0x53a328>>2; g_xformEntityIdx=0x53a788>>2;
 *   call CountdownClampWalk; if pause: ret;
 *   g_eventQueueCurrent=0x40; g_scaledInit=0x53e348>>2; g_xformEntityIdx=0x53e34c>>2;
 *   jmp CountdownClampWalk.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_clamp_0053a328;
extern unsigned int g_dispatchSave39;
extern unsigned int g_clamp_0053e348;
extern unsigned int g_dispatchClr1;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_clamp_0053a328 (*(unsigned int *)MK4_VA(unsigned int, 0x53a328u))
#define g_clamp_0053e348 (*(unsigned int *)MK4_VA(unsigned int, 0x53e348u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchClr1 (*(unsigned int *)MK4_VA(unsigned int, 0x53e34cu))
#define g_dispatchSave39 (*(unsigned int *)MK4_VA(unsigned int, 0x53a788u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif

extern void CountdownClampWalk(void);
void Helper_PostPlayerTick(void) {
    g_eventQueueCurrent = 4;
    g_currentNodeIdx = (unsigned int)MK4_UNPTR(&g_clamp_0053a328) >> 2;
    g_xformEntityIdx = (unsigned int)MK4_UNPTR(&g_dispatchSave39) >> 2;
    CountdownClampWalk();
    if (g_framePauseFlag != 0) return;
    g_eventQueueCurrent = 0x40;
    g_currentNodeIdx = (unsigned int)MK4_UNPTR(&g_clamp_0053e348) >> 2;
    g_xformEntityIdx = (unsigned int)MK4_UNPTR(&g_dispatchClr1) >> 2;
    CountdownClampWalk();
}

