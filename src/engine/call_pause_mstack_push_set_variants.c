/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern packed_ptr g_xformEntityIdx;
extern void SelfInstallPhaseDispatch_0045fd30(void);

/* @addr 0x0045fcf0 (52b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 0
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET T
 *   jmp     T2
 *   ret
 */
void CallPauseMStackPushSet0Jmp_0045fcf0(void) {
    unsigned int top;
    WalkCallbackSetClearDirty_0048e7d0();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))0;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&SelfInstallPhaseDispatch_0045fd30;
    func_004611f4();
}

/* @addr 0x0045ffc0 (52b): same shape, value=9 */
extern void func_0048e7d0_b(void);
extern void SelfInstallPhaseDispatch_00460000(void);
void CallPauseMStackPushSet9Jmp_0045ffc0(void) {
    unsigned int top;
    func_0048e7d0_b();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))9;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&SelfInstallPhaseDispatch_00460000;
    func_004700f4();
}

/* @addr 0x00460d00 (52b): same shape, value=3, OFFSET 0x00470480 */
extern void func_0048e4ce(void);
extern void CjInstallSelfRouter_00470480(void);
void CallPauseMStackPushSet3Jmp_00460d00(void) {
    unsigned int top;
    func_0048e4ce();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))3;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&CjInstallSelfRouter_00470480;
    func_0046f6e0();
}

/* @addr 0x00460d40 (52b): same shape, value=4 */
extern void func_0048e4ce_b(void);
void CallPauseMStackPushSet4Jmp_00460d40(void) {
    unsigned int top;
    func_0048e4ce_b();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))4;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&CjInstallSelfRouter_00470480;
    func_0046f6e0();
}
