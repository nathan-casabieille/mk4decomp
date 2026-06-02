/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer;

/* @addr 0x004390f0 (62b)
 *   call F1; pause-test → ret
 *   testb 1,[dirty] ; je → call F2 ; pause → jne ret
 *   call F3; pause → jne ret; jmp T
 */
extern void MStackPush3CmpCall(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void FiveCallScaledChainTailJmp(void);
extern void ScaledZeroFour(void);
extern void GuardedDispatch_0042c570(void);
void CallPauseTestByteJmpCalls(void) {
    MStackPush3CmpCall();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        SetJmp_StateDispatchYield_00438f60();
        return;
    }
    FiveCallScaledChainTailJmp();
    if (g_framePauseFlag) return;
    ScaledZeroFour();
    if (g_framePauseFlag) return;
    GuardedDispatch_0042c570();
}
