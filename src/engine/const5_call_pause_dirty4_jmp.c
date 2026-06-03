/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004534e0 (39b)
 *   mov     [g_walkCallback], 5
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     .ret
 *   jmp     T
 *   ret
 */
extern void CallPauseScaledStoreXJmp(void);
extern void GuardedSeq_MStackPushTwoEntryChainCall_then_PoseCopyIdleCluster(void);
void Const5Call_PauseDirty4_Jmp(void) {
    g_walkCallback = (void(*)(void))5;
    CallPauseScaledStoreXJmp();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    GuardedSeq_MStackPushTwoEntryChainCall_then_PoseCopyIdleCluster();
}
