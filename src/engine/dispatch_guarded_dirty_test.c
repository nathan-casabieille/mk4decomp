/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00492870 (73b)
 *   if [0x54356c] != 0 → ret;
 *   eax = [0x53a404]; mov walk = eax; if eax != 0 → ret;
 *   mov g_eventQueueCurrent = eax (=0); call F; pause → ret;
 *   cl = byte dirty; eax = 1; if (al & cl) == 0, jmp store-tail;
 *   eventQueueCurrent = 1; walk = 1; jmp T.
 */
extern unsigned int g_data_0053a404;
extern void MStackPush3MaskBit0_004929e0(void);
extern void GuardedFourCallChain_004928c0(void);
void DispatchGuardedDirtyTest_00492870(void) {
    unsigned int v;
    if (g_gtOtherFlag != 0) return;
    v = g_data_0053a404;
    g_walkCallback = (void (*)(void))v;
    if (v != 0) return;
    g_eventQueueCurrent = 0;
    MStackPush3MaskBit0_004929e0();
    if (g_framePauseFlag != 0) return;
    if (g_xformDirtyFlags & 1) {
        g_eventQueueCurrent = 1;
    }
    g_walkCallback = (void (*)(void))1;
    GuardedFourCallChain_004928c0();
}
