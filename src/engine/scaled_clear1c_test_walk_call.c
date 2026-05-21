/**
 * Auto-split from misc_matchesNN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_pendingNodeType;

/* @addr 0x004460c0 (85b)
 *   clear walk and scaled[+0x1c]; load scaled[+0x0c]; if non-zero,
 *   set walk = 0x004460c0; call F; pause → ret;
 *   clear dirty bit 1; ret.
 */
extern void func_004bae90_nn(void);
void ScaledClear1cTestWalkCall_004460c0(void) {
    unsigned int cb;
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x1c) = 0;
    cb = *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x0c);
    g_walkCallback = (void (*)(void))cb;
    if (cb != 0) {
        g_walkCallback = (void (*)(void))ScaledClear1cTestWalkCall_004460c0;
        func_004bae90_nn();
        if (g_framePauseFlag != 0) {
            return;
        }
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffeu;
}
