/**
 * Auto-split from misc_matchesL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0049fa20 (36b): same shape as 0x0042ee10 / 0x00464320 - cmp 3 / dirty manip */
extern unsigned int g_state_0052aac4_l;
void Cmp3DirtyToggle_0049fa20(void) {
    unsigned int state = g_state_0052aac4_l;
    g_walkCallback = (void (*)(void))state;
    if (state != 3) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}
