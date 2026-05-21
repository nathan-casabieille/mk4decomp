/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00464320 (36b): same shape as 0x0042ee10 (Cmp7DirtyToggle) but cmp=9 */
extern unsigned int g_state_0052aac4_h;
void Cmp9DirtyToggle_00464320(void) {
    unsigned int state = g_state_0052aac4_h;
    g_walkCallback = (void(*)(void))state;
    if (state != 9) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}
