/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a2270 (72b)
 *   walk = 0; [0x541dc0] = 0; call F1; pause → ret;
 *   call F2; pause → ret; walk = 0x1000;
 *   store walk → [baseSel*4 + 0xc]; ret.
 */
extern unsigned int g_data_00541dc0;
extern unsigned int g_baseSel_00542060;
extern void BootInitGuardedCallChain_004265d0(void);
extern void ZeroMultiGlobalsCmp_00404680(void);
void ClearTwoCallSetStore_004a2270(void) {
    g_walkCallback = 0;
    g_data_00541dc0 = 0;
    BootInitGuardedCallChain_004265d0();
    if (g_framePauseFlag) return;
    ZeroMultiGlobalsCmp_00404680();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))0x1000;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x0c) = 0x1000;
}
