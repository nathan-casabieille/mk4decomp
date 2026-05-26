/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00491950 (54b)
 *   set 5 to walk and g_tickFlagF; call F1; pause → ret;
 *   testb 1, dirty; jne ret-skip; jmp T;
 *   call F2; jmp T2.
 */
extern unsigned int g_tickFlagF;
extern void DualTestDirtyToggle_004282c0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern void IncCapped3e7_00491920(void);
extern void RoundStartCluster_004919c0(void);
void Set5CallPauseTestByteJmpCall_00491950(void) {
    g_walkCallback = (void (*)(void))5;
    g_tickFlagF = 5;
    DualTestDirtyToggle_004282c0();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((g_xformDirtyFlags & 1) == 0) {
        StackPopDispatchTagged_0041f780();
        return;
    }
    IncCapped3e7_00491920();
    RoundStartCluster_004919c0();
}
