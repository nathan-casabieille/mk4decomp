/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00438c50 (72b)
 *   call F1; pause → ret;
 *   if (dirty & 1): jmp T1.
 *   call F2; pause → ret;
 *   if (dirty & 1): jmp T2;
 *   else: walk = 9; jmp T3.
 */
extern void MStackPush3CmpCall_0048eec0(void);
extern void SetJmp_00438f60(void);
extern void ScaledChain3c74Jmp_0048e780(void);
extern void CallPauseDirtyConstJmp_00438ca0(void);
extern void StateDispatchYield_00471190(void);
void GuardedDirtyDispatch_00438c50(void) {
    MStackPush3CmpCall_0048eec0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        SetJmp_00438f60();
        return;
    }
    ScaledChain3c74Jmp_0048e780();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        CallPauseDirtyConstJmp_00438ca0();
        return;
    }
    g_walkCallback = (void(*)(void))9;
    StateDispatchYield_00471190();
}
