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

extern void CopyJmp_00406ba0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00428850(void);
extern void DualGuardPushInstallJmp_004288e0(void);

/* @addr 0x00428820 */
void CallPauseScaledStoreJmp_00428820(void) {
    CopyJmp_00406ba0();
    if (g_framePauseFlag) return;
    *(unsigned int*)(g_fightGroupHead * 4 + 0x28) = g_eventQueueCurrent;
    CallPauseDirty1JmpDirty4StackPush_00428850();
}

/* @addr 0x004288b0 */
void CallPauseScaledStoreJmp_004288b0(void) {
    CopyJmp_00406ba0();
    if (g_framePauseFlag) return;
    *(unsigned int*)(g_fightGroupHead * 4 + 0x28) = g_eventQueueCurrent;
    DualGuardPushInstallJmp_004288e0();
}
