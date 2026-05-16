/**
 * 6 "guarded push-call" wrappers.
 *
 * Pattern (28 bytes):
 *   call PreFunc                ; e8 + reloc
 *   mov eax, [g_framePauseFlag]
 *   test eax, eax
 *   jne short skip              ; 75 0d
 *   push ARG                     ; 68 + imm32
 *   call Target                 ; e8 + reloc
 *   add esp, 4
 * skip:
 *   ret
 */
#include "game/tick.h"   /* g_framePauseFlag */

/* Externs. */
extern void CopyJmp_00406ba0(void);
extern void Thunk_00433950(void);
extern void ScaledLoadInstallOrCall_00433960(void);
extern int  PackedAdvanceCallTailJmp_004392c0(int arg);
extern void CopyJmp_0043a620(void);
extern int  ArgSarStoreJmp_004594f0(int arg);
extern void Wrapper_0048a370(void);
extern void DualMul10AndDispatchChain_0049c220(void);
extern int  ArgSar_Set0_Jmp_0049c6f0(int arg);

/* @addr 0x004338a0 */
void GuardedPushCall_004338a0(void) {
    ScaledLoadInstallOrCall_00433960();
    if (g_framePauseFlag) return;
    PackedAdvanceCallTailJmp_004392c0(0x004e4480);
}

/* @addr 0x004338c0 */
void GuardedPushCall_004338c0(void) {
    Thunk_00433950();
    if (g_framePauseFlag) return;
    PackedAdvanceCallTailJmp_004392c0(0x004e44a8);
}

/* @addr 0x0043b980 */
void GuardedPushCall_0043b980(void) {
    CopyJmp_0043a620();
    if (g_framePauseFlag) return;
    ArgSarStoreJmp_004594f0(0x004e4c48);
}

/* @addr 0x0046a560 */
void GuardedPushCall_0046a560(void) {
    CopyJmp_00406ba0();
    if (g_framePauseFlag) return;
    ArgSarStoreJmp_004594f0(0x004eabc8);
}

/* @addr 0x00482990 */
void GuardedPushCall_00482990(void) {
    Wrapper_0048a370();
    if (g_framePauseFlag) return;
    ArgSarStoreJmp_004594f0(0x004ee158);
}

/* @addr 0x0049c200 */
void GuardedPushCall_0049c200(void) {
    DualMul10AndDispatchChain_0049c220();
    if (g_framePauseFlag) return;
    ArgSar_Set0_Jmp_0049c6f0(0x004f2758);
}
