/**
 * 4 "guarded dispatch" helpers (34 bytes each).
 *
 * Pattern:
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label               ; bail if pause
 *   test    byte ptr [g_xformDirtyFlags], 1
 *   je      use_default
 *   jmp     special_target
 * use_default:
 *   jmp     default_target
 * ret_label:
 *   ret
 *
 * Each helper does some setup, gates the rest of the work on the
 * frame-pause flag, then chooses one of two tail-jump targets
 * based on whether bit 0 of g_xformDirtyFlags is set.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void QuadStageStateDispatch(void);
extern void InstallSelfDualEsi(void);
extern void EightPackedSubInstallSelfWalk(void);
extern void EsiAliasInstallChainCall(void);
extern void StageEventDamageCluster(void);
extern void MStackPush2ChainSwap(void);
extern void CallPauseMStackPushSet3Jmp(void);
extern void CallPauseMStackPushSet4Jmp(void);

/* @addr 0x0042b6c0 */
void GuardedDispatch_InstallSelfDualEsi(void) {
    QuadStageStateDispatch();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        InstallSelfDualEsi();
        return;
    }
    EightPackedSubInstallSelfWalk();
}

/* @addr 0x0042c570 */
void GuardedDispatch_EsiAliasInstallChainCall(void) {
    QuadStageStateDispatch();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        EsiAliasInstallChainCall();
        return;
    }
    StageEventDamageCluster();
}

/* @addr 0x00460ca0 */
void GuardedDispatch_CallPauseMStackPushSet3Jmp(void) {
    MStackPush2ChainSwap();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        CallPauseMStackPushSet3Jmp();
        return;
    }
    CallPauseMStackPushSet4Jmp();
}

/* @addr 0x00460cd0 */
void GuardedDispatch_CallPauseMStackPushSet4Jmp(void) {
    MStackPush2ChainSwap();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        CallPauseMStackPushSet4Jmp();
        return;
    }
    CallPauseMStackPushSet3Jmp();
}
