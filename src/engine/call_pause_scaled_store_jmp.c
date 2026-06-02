/**
 * 2 "call + pause guard + scaled store + tail-jmp" helpers (38b).
 *
 * Pattern:
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_eventQueueCurrent]
 *   mov     [eax*4 + 0x28], ecx
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx(void);
extern void CallPauseDirty1JmpDirty4StackPush_00428850(void);
extern void DualGuardPushInstallJmp(void);

/* @addr 0x00428820 */
void CallPauseScaledStoreJmp_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_then_CallPauseDirty1JmpDirty4StackPush(void) {
    CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx();
    if (g_framePauseFlag) return;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = g_eventQueueCurrent;
    CallPauseDirty1JmpDirty4StackPush_00428850();
}

/* @addr 0x004288b0 */
void CallPauseScaledStoreJmp_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_then_DualGuardPushInstallJmp(void) {
    CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx();
    if (g_framePauseFlag) return;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = g_eventQueueCurrent;
    DualGuardPushInstallJmp();
}
