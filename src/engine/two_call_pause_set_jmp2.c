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
extern void MStackPush2RunCountdown_004089e0(void);
extern void func_00478f90(void);
extern void GuardedSeq_00473f70(void);
void TwoCallPauseSetJmp2_00456180(void) {
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag != 0) return;
    func_00478f90();
    if (g_framePauseFlag != 0) return;
    g_acc_00542078 = 2;
    g_walkCallback = (void (*)(void))3;
    GuardedSeq_00473f70();
}
