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

extern unsigned int g_data_00538158;
extern unsigned int g_data_0053815c;

/* @addr 0x004ac1a0 (80b)
 *   Three-step XOR toggle of dirty&4 across cmp checks. Each
 *   stage compares walk against a different global (538158, 538158
 *   again, 53815c) and either keeps or removes the bit-4 flag.
 */
void ThreeStageDirtyToggle_004ac1a0(void) {
    unsigned int dirty;
    g_xformDirtyFlags |= 4;
    if (g_walkCallback == g_data_00538158) return;
    dirty = g_xformDirtyFlags ^ 4;
    g_xformDirtyFlags = dirty;
    if (g_walkCallback == g_data_00538158) return;
    dirty |= 4;
    g_xformDirtyFlags = dirty;
    if (g_data_0053815c == (unsigned int)g_walkCallback) return;
    dirty ^= 4;
    g_xformDirtyFlags = dirty;
}
