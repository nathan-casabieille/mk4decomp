/**
 * Twentieth batch of one-off matches.
 * Many MStackPushSetImmJmp variants and ScaledLoad variants.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048f910 (31b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x3c]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   ret
 */
void ScaledChain3c74_0048f910(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x3c);
    g_scaledInit_00542044 = v;
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x74);
}

/* @addr 0x0048f930 (31b): same shape with offset 0x7c instead of 0x74 */
void ScaledChain3c7c_0048f930(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x3c);
    g_scaledInit_00542044 = v;
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x7c);
}

/* MStackPushSetImmJmp family - 7 variants of:
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_acc_00542078]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   mov     [g_acc_00542078], IMM
 *   jmp     T
 */
extern unsigned int g_acc_00542078;
extern void func_0049036e(void);
extern void func_0049039e(void);
extern void func_004903ce(void);
extern void func_004903fe(void);
extern void func_0049042e(void);
extern void func_0049045e(void);
extern void func_0049048e(void);

#define MSTACK_PUSH_SET(IMM_VAL, FN)                                            \
    __asm {                                                                     \
        __asm mov     eax, dword ptr [g_matrixStackTop]                         \
        __asm mov     ecx, dword ptr [g_acc_00542078]                           \
        __asm inc     eax                                                       \
        __asm mov     dword ptr [g_matrixStackTop], eax                         \
        __asm mov     dword ptr [eax*4 + 0], ecx                                \
        __asm mov     dword ptr [g_acc_00542078], IMM_VAL                       \
        __asm jmp     FN                                                        \
    }

/* @addr 0x00490140 */
void MStackPushSet0200_00490140(void) {
    unsigned int acc = g_acc_00542078;
    unsigned int top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = acc;
    g_acc_00542078 = 0x0200;
    func_0049036e();
}
/* @addr 0x00490170 */
__declspec(naked) void MStackPushSet0080_00490170(void) { MSTACK_PUSH_SET(0x80, func_0049039e) }
/* @addr 0x004901a0 */
__declspec(naked) void MStackPushSet0008_004901a0(void) { MSTACK_PUSH_SET(8, func_004903ce) }
/* @addr 0x004901d0 */
__declspec(naked) void MStackPushSet0020_004901d0(void) { MSTACK_PUSH_SET(0x20, func_004903fe) }
/* @addr 0x00490200 */
__declspec(naked) void MStackPushSet0040_00490200(void) { MSTACK_PUSH_SET(0x40, func_0049042e) }
/* @addr 0x00490230 */
__declspec(naked) void MStackPushSet0004_00490230(void) { MSTACK_PUSH_SET(4, func_0049045e) }
/* @addr 0x00490260 */
__declspec(naked) void MStackPushSet0001_00490260(void) { MSTACK_PUSH_SET(1, func_0049048e) }

/* @addr 0x00490b10 (38b)
 *   mov     eax, [esp+4]
 *   sar     eax, 2
 *   mov     [g_eventQueueEnd], eax
 *   mov     ecx, [eax*4 + 0]
 *   inc     eax
 *   neg     ecx
 *   mov     [g_eventQueueEnd], eax
 *   mov     [g_walkCallback], ecx
 *   jmp     T
 */
extern void func_0049000a(void);
__declspec(naked) void IterStepNegStore_00490b10(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        neg     ecx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_0049000a
    }
}

/* @addr 0x00490b40 (44b)
 *   mov     eax, [esp+4]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     ecx, [eax*4 + 0]
 *   inc     eax
 *   mov     [g_eventQueueTotal], eax
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_pendingNodeType], ecx
 *   mov     [eax*4 + 0x44], ecx
 *   ret
 */
__declspec(naked) void IterStepDualStore_00490b40(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_eventQueueTotal], eax
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [eax*4 + 0x44], ecx
        ret
    }
}

/* @addr 0x00490c30 (43b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   jne     +0x0e
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void GuardedDualAndFlagToggle_0048f020(void);
extern void func_00490371(void);
extern void func_0049126c(void);
void DualCallPauseDirtyJmp_00490c30(void) {
    GuardedDualAndFlagToggle_0048f020();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) == 0) {
        func_00490371();
        if (g_framePauseFlag != 0) return;
    }
    func_0049126c();
}

/* @addr 0x00490e90 (43b)
 *   mov     eax, [g_fightGroupHead]
 *   xor     ecx, ecx
 *   shl     eax, 2
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x60], ecx
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax + 0x68], ecx
 *   mov     ecx, 0x0004c7ae
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x64], ecx
 *   ret
 */
__declspec(naked) void InitThreeFields_00490e90(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        xor     ecx, ecx
        shl     eax, 2
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x60], ecx
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x68], ecx
        mov     ecx, 0x0004c7ae
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x64], ecx
        ret
    }
}

/* @addr 0x00491080 (43b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_eventQueueIdx]
 *   mov     [eax*4 + 0x24], ecx
 *   mov     edx, [g_fightGroupHead]
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [edx*4 + 0x28], eax
 *   jmp     T
 */
extern void func_004907fa(void);
void DualScaledStoreZero_00491080(void) {
    *(unsigned int *)(g_fightGroupHead * 4 + 0x24) = g_eventQueueIdx;
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0;
    func_004907fa();
}

/* @addr 0x004911c0 (42b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_state_00542080]
 *   mov     ecx, [g_state_00542080]
 *   wait, that's two same loads - actually:
 *   a17c205400 = mov eax, [0x0054207c]
 *   8b0d80205400 = mov ecx, [0x00542080]
 *   a374205400 = mov [0x00542074], eax
 *   890d78205400 = mov [0x00542078], ecx
 *   jmp T
 */
extern unsigned int g_state_0054207c;
extern unsigned int g_state_00542080;
extern u32 g_eventQueueWorkType;
extern void func_004245d4(void);
extern void func_00404060(void);
void SwapTwoGlobals_004911c0(void) {
    unsigned int a, b;
    func_004245d4();
    if (g_framePauseFlag != 0) return;
    a = g_state_0054207c;
    b = g_state_00542080;
    g_eventQueueWorkType = a;
    g_acc_00542078 = b;
    func_00404060();
}

/* @addr 0x00491920 (34b)
 *   mov     eax, [g_state_00535de4]
 *   inc     eax
 *   cmp     eax, 0x3e7
 *   mov     [g_walkCallback], eax
 *   jle     +0x0a
 *   mov     eax, 0x3e7
 *   mov     [g_walkCallback], eax
 *   mov     [g_state_00535de4], eax
 *   ret
 */
extern unsigned int g_state_00535de4;
__declspec(naked) void IncCapped3e7_00491920(void) {
    __asm {
        mov     eax, dword ptr [g_state_00535de4]
        inc     eax
        cmp     eax, 0x03e7
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   0ah
        mov     eax, 0x03e7
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_00535de4], eax
        ret
    }
}

/* @addr 0x00491990 (44b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_state_0053a51c]
 *   mov     [g_walkCallback], eax
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern unsigned int g_state_0053a51c;
extern void GuardedScaledLookupCallJmp_004220a0(void);
extern void func_0042a330(void);
extern void func_0049199a(void);
void TwoCallStatePauseJmp_00491990(void) {
    GuardedScaledLookupCallJmp_004220a0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))g_state_0053a51c;
    func_0042a330();
    if (g_framePauseFlag != 0) return;
    func_0049199a();
}

/* @addr 0x00494800 (39b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, [eax*4 + 0x30]
 *   add     eax, ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     ecx, [eax*4 + 0]
 *   mov     [g_scaledInit_00542044], ecx
 *   ret
 */
__declspec(naked) void ScaledAddDeref_00494800(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, dword ptr [eax*4 + 0x30]
        add     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_scaledInit_00542044], ecx
        ret
    }
}

/* @addr 0x00495cf0 (38b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, 0x0303
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x74], eax
 *   mov     [g_state_0054207c], 0x0002000f
 *   jmp     T
 */
extern void func_0048d8d0(void);
__declspec(naked) void Const0303InitJmp_00495cf0(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x0303
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        mov     dword ptr [g_state_0054207c], 0x0002000f
        jmp     func_0048d8d0
    }
}

/* @addr 0x0048fa20 (44b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_scaledInit_00542044], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void CopyJmp_00406ba0(void);
extern void func_00490d30(void);
extern void func_0049020a(void);
void StoreCallPauseCallPauseJmp_0048fa20(void) {
    g_scaledInit_00542044 = g_fightGroupHead;
    CopyJmp_00406ba0();
    if (g_framePauseFlag != 0) return;
    func_00490d30();
    if (g_framePauseFlag != 0) return;
    func_0049020a();
}
