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

extern void QuadStageStateDispatch_0042c3e0(void);
extern void InstallSelfDualEsi_0042c4f0(void);
extern void EightPackedSubInstallSelfWalk_0042b6f0(void);
extern void EsiAliasInstallChainCall_0042c490(void);
extern void StageEventDamageCluster_0042c5a0(void);
extern void MStackPush2ChainSwap_0048f090(void);
extern void CallPauseMStackPushSet3Jmp_00460d00(void);
extern void CallPauseMStackPushSet4Jmp_00460d40(void);

/* @addr 0x0042b6c0 */
__declspec(naked) void GuardedDispatch_0042b6c0(void) {
    __asm {
        call    QuadStageStateDispatch_0042c3e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        __asm _emit 75h __asm _emit 13h    /* jne SHORT ret_label */
        test    byte ptr [g_xformDirtyFlags], 1
        __asm _emit 74h __asm _emit 05h    /* je SHORT use_default */
        jmp     InstallSelfDualEsi_0042c4f0
        jmp     EightPackedSubInstallSelfWalk_0042b6f0
        ret
    }
}

/* @addr 0x0042c570 */
__declspec(naked) void GuardedDispatch_0042c570(void) {
    __asm {
        call    QuadStageStateDispatch_0042c3e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        __asm _emit 75h __asm _emit 13h
        test    byte ptr [g_xformDirtyFlags], 1
        __asm _emit 74h __asm _emit 05h
        jmp     EsiAliasInstallChainCall_0042c490
        jmp     StageEventDamageCluster_0042c5a0
        ret
    }
}

/* @addr 0x00460ca0 */
__declspec(naked) void GuardedDispatch_00460ca0(void) {
    __asm {
        call    MStackPush2ChainSwap_0048f090
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        __asm _emit 75h __asm _emit 13h
        test    byte ptr [g_xformDirtyFlags], 1
        __asm _emit 74h __asm _emit 05h
        jmp     CallPauseMStackPushSet3Jmp_00460d00
        jmp     CallPauseMStackPushSet4Jmp_00460d40
        ret
    }
}

/* @addr 0x00460cd0 */
__declspec(naked) void GuardedDispatch_00460cd0(void) {
    __asm {
        call    MStackPush2ChainSwap_0048f090
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        __asm _emit 75h __asm _emit 13h
        test    byte ptr [g_xformDirtyFlags], 1
        __asm _emit 74h __asm _emit 05h
        jmp     CallPauseMStackPushSet4Jmp_00460d40
        jmp     CallPauseMStackPushSet3Jmp_00460d00
        ret
    }
}
