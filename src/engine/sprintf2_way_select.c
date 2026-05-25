/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00426550 (75b)
 *   eax = 0x53a1c0 >> 2 → g_scaledInit; eax = g_currentNodeFlags;
 *   if eax == 2: sprintf-style 3-arg call with format 0x4d56c8
 *   else format 0x4d56d0; both use 0x53a1c0 as buffer.
 */
extern unsigned int g_dispatchSave1177_004d56c8;
extern unsigned int g_dispatchSave1178_004d56d0;
extern unsigned int g_dispatchSave_0053a1c0;
extern void Helper_Sprintf(void *buf, void *fmt, unsigned int arg);
void Sprintf2WaySelect_00426550(void) {
    g_scaledInit_00542044 = (unsigned int)&g_dispatchSave_0053a1c0 >> 2;
    if (g_currentNodeFlags == 2) {
        Helper_Sprintf(&g_dispatchSave_0053a1c0, &g_dispatchSave1177_004d56c8, (unsigned int)g_walkCallback);
        return;
    }
    Helper_Sprintf(&g_dispatchSave_0053a1c0, &g_dispatchSave1178_004d56d0, (unsigned int)g_walkCallback);
}
