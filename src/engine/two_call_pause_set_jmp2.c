/**
 * Two-call pause-chain with state set + tail-jmp.
 */
#include "engine/scenegraph.h"

extern unsigned int g_acc_00542078;
extern u32 g_framePauseFlag;

/* @addr 0x00456180 (54b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x19
 *   mov     [g_acc_00542078], 2
 *   mov     [g_walkCallback], 3
 *   jmp     T
 *   ret
 */
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void GuardedSeq_DualSetShiftCall_then_MStackPush2CjMul10Triple(void);
void TwoCallPauseSetJmp2(void) {
    MStackPush2RunCountdown();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag != 0) return;
    g_acc_00542078 = 2;
    g_walkCallback = (void (*)(void))3;
    GuardedSeq_DualSetShiftCall_then_MStackPush2CjMul10Triple();
}
