/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00438c50 (72b)
 *   call F1; pause → ret;
 *   if (dirty & 1): jmp T1.
 *   call F2; pause → ret;
 *   if (dirty & 1): jmp T2;
 *   else: walk = 9; jmp T3.
 */
extern void MStackPush3CmpCall(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void ScaledChain3c74Jmp(void);
extern void CallPauseDirtyConstJmp(void);
extern void StateDispatchYield(void);
void GuardedDirtyDispatch(void) {
    MStackPush3CmpCall();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        SetJmp_StateDispatchYield_00438f60();
        return;
    }
    ScaledChain3c74Jmp();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        CallPauseDirtyConstJmp();
        return;
    }
    g_walkCallback = (void(*)(void))9;
    StateDispatchYield();
}
