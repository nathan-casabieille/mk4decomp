/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004227b0 (94b)
 *   g_eventQueueCurrent=4; g_scaledInit=0x53a328>>2; g_xformEntityIdx=0x53a788>>2;
 *   call CountdownClampWalk_00422810; if pause: ret;
 *   g_eventQueueCurrent=0x40; g_scaledInit=0x53e348>>2; g_xformEntityIdx=0x53e34c>>2;
 *   jmp CountdownClampWalk_00422810.
 */
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_clamp_0053a328;
extern unsigned int g_data_0053a788;
extern unsigned int g_clamp_0053e348;
extern unsigned int g_data_0053e34c;
extern void CountdownClampWalk_00422810(void);
void Helper_PostPlayerTick(void) {
    g_eventQueueCurrent = 4;
    g_scaledInit_00542044 = (unsigned int)&g_clamp_0053a328 >> 2;
    g_xformEntityIdx = (unsigned int)&g_data_0053a788 >> 2;
    CountdownClampWalk_00422810();
    if (g_framePauseFlag != 0) return;
    g_eventQueueCurrent = 0x40;
    g_scaledInit_00542044 = (unsigned int)&g_clamp_0053e348 >> 2;
    g_xformEntityIdx = (unsigned int)&g_data_0053e34c >> 2;
    CountdownClampWalk_00422810();
}

