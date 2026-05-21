/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x004ba0e0 (66b)
 *   eax = g_xformEntityIdx[+0x14] * [0xab4e6c]; sar 8;
 *   clamp to [0, 0x100]; store at 0xab4e5c;
 *   then mov [0xab4e60] = g_tickW1; ret.
 */
extern int g_data_00ab4e6c;
extern int g_data_00ab4e5c;
extern int g_data_00ab4e60;
void ClampMulShiftStore_004ba0e0(void) {
    int v = (*(int *)(g_xformEntityIdx * 4 + 0x14) * g_data_00ab4e6c) >> 8;
    g_data_00ab4e5c = v;
    if (v < 0) {
        v = 0;
        g_data_00ab4e5c = v;
    }
    if (v > 0x100) {
        g_data_00ab4e5c = 0x100;
    }
    g_data_00ab4e60 = (int)g_tickW1;
}
