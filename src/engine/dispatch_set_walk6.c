/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* === Five 78b clones: dispatch at 0x004926e0 / 30 / 80 / d0 / 20 ===
 *
 * Same shape; only the final walk-value (6/5/4/3/2) and the
 * called helper (0x492920 vs 0x4929e0) differ.
 *
 *   if [0x54356c] != 0 → ret;
 *   eax = [0x53a404]; mov walk = eax; if eax != 0 → ret;
 *   mov eventQueueCurrent = eax; call F; pause → ret;
 *   cl = byte dirty; eax = 1; if (cl & al) != 0:
 *       eventQueueCurrent = 1.
 *   walk = N (literal); jmp T.
 */
extern unsigned int g_data_0053a404;
extern void MStackPush3MaskBit_00492920(void);
void DispatchSetWalk6_004926e0(void) {
    unsigned int v;
    if (g_gtOtherFlag) return;
    v = g_data_0053a404;
    g_walkCallback = (void(*)(void))v;
    if (v) return;
    g_eventQueueCurrent = v;
    MStackPush3MaskBit_00492920();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        g_eventQueueCurrent = 1;
    }
    g_walkCallback = (void(*)(void))6;
    GuardedFourCallChain_004928c0();
}
