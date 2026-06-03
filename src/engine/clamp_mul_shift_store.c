/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004ba0e0 (66b)
 *   eax = g_xformEntityIdx[+0x14] * [0xab4e6c]; sar 8;
 *   clamp to [0, 0x100]; store at 0xab4e5c;
 *   then mov [0xab4e60] = g_tickW1; ret.
 */
extern int g_dispatchSave1577;
extern int g_dispatchSave1575;
extern int g_dispatchSave1576;
void ClampMulShiftStore(void) {
    int v = ((int)((ScenegraphNode *)(g_xformEntityIdx * 4))->not_mask * g_dispatchSave1577) >> 8;
    g_dispatchSave1575 = v;
    if (v < 0) {
        v = 0;
        g_dispatchSave1575 = v;
    }
    if (v > 0x100) {
        g_dispatchSave1575 = 0x100;
    }
    g_dispatchSave1576 = (int)g_tickW1;
}
