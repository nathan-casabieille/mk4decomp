/**
 * Thirty-first batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x004390b0 (56b)
 *   mov     eax, [g_state_00535ddc]
 *   cmp     eax, 0xcccc
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     +0xca
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      +5
 *   jmp     T
 *   jmp     +9
 *   ret
 */
extern unsigned int g_state_00535ddc;
extern void func_0048ec10(void);
extern void func_00439183(void);
extern void func_004390e9(void);
extern void func_004390cf(void);
void CmpccccCallPauseDirtyJmp_004390b0(void) {
    unsigned int v = g_state_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if ((int)v > 0xcccc) {
        func_00439183();
        return;
    }
    func_0048ec10();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) != 0) {
        func_004390cf();
        return;
    }
    func_004390e9();
}

/* @addr 0x004396c0 (51b)
 *   mov     eax, [g_state_00535df0]
 *   mov     [g_eventQueueIdx], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x1a
 *   test    byte [g_xformDirtyFlags], 1
 *   jne     +0x11
 *   mov     ecx, [g_state_0053a2c0]
 *   mov     [g_eventQueueIdx], ecx
 *   jmp     +0x0e
 *   ret
 */
extern unsigned int g_state_00535df0;
extern unsigned int g_state_0053a2c0;
extern void func_004396f1(void);
extern void func_004396ff(void);
void StoreCallPauseDirtyStoreJmp_004396c0(void) {
    g_eventQueueIdx = g_state_00535df0;
    func_004396f1();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) != 0) return;
    g_eventQueueIdx = g_state_0053a2c0;
    func_004396ff();
}

/* @addr 0x004398b0 (54b)
 *   mov     eax, [0x0052aac4]
 *   cmp     eax, 2
 *   mov     [g_walkCallback], eax
 *   jne     +0x0b
 *   call    F1
 *   mov     eax, 1
 *   ret
 *   call    F2
 *   test    byte [g_xformDirtyFlags], 1
 *   jne     +0x0b
 *   call    F3
 *   mov     eax, 1
 *   ret
 *   xor     eax, eax
 *   ret
 */
extern unsigned int g_state_0052aac4_v;
extern void func_004399a3(void);
extern void func_00439902(void);
extern void func_00439986(void);
int Cmp2CallDirtyCall_004398b0(void) {
    unsigned int v = g_state_0052aac4_v;
    g_walkCallback = (void (*)(void))v;
    if (v == 2) {
        func_004399a3();
        return 1;
    }
    func_00439902();
    if ((g_xformDirtyFlags & 1) == 0) {
        func_00439986();
        return 1;
    }
    return 0;
}

/* @addr 0x0043a630 (58b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     edx, [g_xformDirtyFlags]
 *   mov     ecx, 4
 *   mov     eax, [eax*4 + 0]
 *   or      edx, ecx
 *   test    eax, eax
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [g_xformDirtyFlags], edx
 *   je      +0x11
 *   xor     edx, ecx
 *   test    eax, eax
 *   mov     [g_xformDirtyFlags], edx
 *   je      +5
 *   jmp     +7
 *   ret
 */
extern void func_0043a665(void);
__declspec(naked) void DirtyToggleScaledTest_0043a630(void) {
    __asm {
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     ecx, 4
        mov     eax, dword ptr [eax*4 + 0]
        or      edx, ecx
        test    eax, eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   11h
        xor     edx, ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   05h
        jmp     func_0043a665
        ret
    }
}

/* MStackPushSetImm + jmp variants - 4 stubs */
extern int g_matrixStackTop;
extern void func_0046cb00(void);
extern void func_0046cb20(void);
extern void func_0046cb40(void);
extern void func_004611f4(void);
extern void func_004700f4(void);
extern void func_0046f6e0(void);
extern void func_00472080(void);
extern void WalkCallbackSetClearDirty_0048e7d0(void);
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
extern void WalkCallbackSetClearDirty_0048e7d0(void);
extern void SelfInstallPhaseDispatch_0045fd30(void);

/* @addr 0x0045ffc0 (52b): same shape, value=9 */
extern void func_0048e7d0_b(void);
extern void SelfInstallPhaseDispatch_00460000(void);
__declspec(naked) void CallPauseMStackPushSet9Jmp_0045ffc0(void) {
    __asm {
        call    func_0048e7d0_b
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   25h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], 9
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET SelfInstallPhaseDispatch_00460000
        jmp     func_004700f4
        ret
    }
}

/* @addr 0x00460d00 (52b): same shape, value=3, OFFSET 0x00470480 */
extern void func_0048e4ce(void);
extern void CjInstallSelfRouter_00470480(void);
__declspec(naked) void CallPauseMStackPushSet3Jmp_00460d00(void) {
    __asm {
        call    func_0048e4ce
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   25h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], 3
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET CjInstallSelfRouter_00470480
        jmp     func_0046f6e0
        ret
    }
}

/* @addr 0x00460d40 (52b): same shape, value=4 */
extern void func_0048e4ce_b(void);
__declspec(naked) void CallPauseMStackPushSet4Jmp_00460d40(void) {
    __asm {
        call    func_0048e4ce_b
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   25h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_walkCallback], 4
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET CjInstallSelfRouter_00470480
        jmp     func_0046f6e0
        ret
    }
}

/* @addr 0x004464f0 already done - let me skip */

/* @addr 0x00464240 (60b)
 *   mov     eax, [0x0053a3c0]
 *   mov     [g_eventQueueCurrent], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x23
 *   mov     ecx, [g_eventQueueCurrent]
 *   mov     eax, [g_walkCallback]
 *   cmp     ecx, eax
 *   mov     eax, [g_xformDirtyFlags]
 *   jbe     +8
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_state_0053a3c0_v;
extern void func_00463ec0(void);
__declspec(naked) void StoreCallPauseCmpDirty_00464240(void) {
    __asm {
        mov     eax, dword ptr [g_state_0053a3c0_v]
        mov     dword ptr [g_eventQueueCurrent], eax
        call    func_00463ec0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   23h
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     eax, dword ptr [g_walkCallback]
        cmp     ecx, eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        _emit   76h
        _emit   08h
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
    }
}

/* @addr 0x0046b630 (59b)
 *   push    0x004eafb8
 *   call    F1
 *   add     esp, 4
 *   ret
 *   nop * 2
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, 0x2010
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x74], eax
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern int func_004594ec(void *);
extern void *g_data_004eafb8;
extern void Wrapper_0048a350(void);
extern void func_0046b687(void);
__declspec(naked) void DualEntryPushCall_0046b630(void) {
    __asm {
        push    OFFSET g_data_004eafb8
        call    func_004594ec
        add     esp, 4
        ret
        nop
        nop
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x2010
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    Wrapper_0048a350
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0046b687
        ret
    }
}

/* @addr 0x0046c520 (51b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x24
 *   mov     eax, [g_eventQueueWorkType]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0x0c]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     eax
 *   ret
 */
extern void func_0046e750(void);
__declspec(naked) void CallPauseTripleScaledJmp_0046c520(void) {
    __asm {
        call    func_0046e750
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   24h
        mov     eax, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0x0c]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     eax
        ret
    }
}

/* @addr 0x0046e2a0 (56b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x29
 *   test    byte [g_xformDirtyFlags], 4
 *   je      +0x1b
 *   mov     eax, [g_matrixStackTop]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], 0x0046e2e0
 *   jmp     T
 *   jmp     +9
 *   ret
 */
extern void func_00470450(void);
extern void PendingMatch_0046e2e0(void);
extern void func_0042b594(void);
extern void func_0046e2b3(void);
__declspec(naked) void CallPauseDirtyMStackPushFn_0046e2a0(void) {
    __asm {
        call    func_00470450
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   1bh
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET PendingMatch_0046e2e0
        jmp     func_0042b594
        jmp     func_0046e2b3
        ret
    }
}

/* @addr 0x00470980 (55b)
 *   mov     ecx, [g_gtPlayerProbe2]
 *   mov     eax, [g_player1NodeIdx]
 *   mov     [g_eventQueueIdx], ecx
 *   mov     ecx, [g_fightGroupHead]
 *   cmp     ecx, eax
 *   mov     [g_scaledInit_00542044], eax
 *   je      +0x16
 *   mov     edx, [g_player2NodeIdx]
 *   mov     eax, [g_gtPlayerProbe1]
 *   mov     [g_scaledInit_00542044], edx
 *   mov     [g_eventQueueIdx], eax
 *   ret
 */
extern packed_ptr g_player1NodeIdx;
extern packed_ptr g_player2NodeIdx;
extern u32 g_gtPlayerProbe1;
extern u32 g_gtPlayerProbe2;
extern packed_ptr g_fightGroupHead;
__declspec(naked) void CmpP1GTSetup_00470980(void) {
    __asm {
        mov     ecx, dword ptr [g_gtPlayerProbe2]
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     ecx, dword ptr [g_fightGroupHead]
        cmp     ecx, eax
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   74h
        _emit   16h
        mov     edx, dword ptr [g_player2NodeIdx]
        mov     eax, dword ptr [g_gtPlayerProbe1]
        mov     dword ptr [g_scaledInit_00542044], edx
        mov     dword ptr [g_eventQueueIdx], eax
        ret
    }
}

/* @addr 0x0047c5e0 (57b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, 0x200d
 *   mov     edx, 0x004ed3e0
 *   mov     [g_walkCallback], eax
 *   shr     edx, 2
 *   mov     [ecx*4 + 0x74], eax
 *   mov     [g_scaledInit_00542044], edx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     +8
 *   ret
 */
extern void func_0048f6f0(void);
extern void func_0047c61b(void);
__declspec(naked) void Set200dCallPauseJmp_0047c5e0(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x200d
        mov     edx, 0x004ed3e0
        mov     dword ptr [g_walkCallback], eax
        shr     edx, 2
        mov     dword ptr [ecx*4 + 0x74], eax
        mov     dword ptr [g_scaledInit_00542044], edx
        call    func_0048f6f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0047c61b
        ret
    }
}
