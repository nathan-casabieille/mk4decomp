/**
 * Set-walk=2 + double-call pause-chain dispatcher.
 */
#include "engine/scenegraph.h"

/* @addr 0x004535e0 (53b)
 *   mov     [g_walkCallback], 2
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     +0x13
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern u32 g_framePauseFlag;
extern void CallPauseScaledStoreXJmp_00453750(void);
extern void GuardedSeq_00453780(void);
extern void SetupVecFsmCluster_0043e3e0(void);
void Set2CallDirtyCallPauseJmp_004535e0(void) {
    g_walkCallback = (void (*)(void))2;
    CallPauseScaledStoreXJmp_00453750();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    GuardedSeq_00453780();
    if (g_framePauseFlag != 0) return;
    SetupVecFsmCluster_0043e3e0();
}
