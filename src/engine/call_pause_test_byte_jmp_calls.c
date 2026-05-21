/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_state_00537e94;
extern packed_ptr g_fightGroupHead;

/* @addr 0x004390f0 (62b)
 *   call F1; pause-test → ret
 *   testb 1,[dirty] ; je → call F2 ; pause → jne ret
 *   call F3; pause → jne ret; jmp T
 */
extern void MStackPush3CmpCall_0048eec0(void);
extern void SetJmp_00438f60(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void ScaledZeroFour_00490740(void);
extern void GuardedDispatch_0042c570(void);
void CallPauseTestByteJmpCalls_004390f0(void) {
    MStackPush3CmpCall_0048eec0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        SetJmp_00438f60();
        return;
    }
    FiveCallScaledChainTailJmp_0045f8d0();
    if (g_framePauseFlag) return;
    ScaledZeroFour_00490740();
    if (g_framePauseFlag) return;
    GuardedDispatch_0042c570();
}
