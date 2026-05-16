/**
 * Thirty-fourth batch of one-off matches.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_state_00537e94;
extern packed_ptr g_fightGroupHead;

/* @addr 0x0044ef10 (64b): same shape as ScaledInitOrSelfPtr_00421f00,
 *                         store=own, jmp=0x44ef50 */
extern void PoseChainAdvanceCluster_0044ef50(void);
__declspec(naked) void ScaledInitOrSelfPtr_0044ef10(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   05h
        jmp     PoseChainAdvanceCluster_0044ef50
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x0044ef10
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}

/* @addr 0x00446640 (61b)
 *   mov     eax, [g_baseSel_00542060]
 *   xor     ecx, ecx
 *   mov     eax, [eax*4 + 0x30]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [eax*4 + 0x1c], ecx
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     eax, [ecx*4 + 0x20]
 *   and     ah, 0xfe
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x20], eax
 *   ret
 */
__declspec(naked) void ScaledLoad1cZeroAndFE_00446640(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        xor     ecx, ecx
        mov     eax, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0x1c], ecx
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [ecx*4 + 0x20]
        and     ah, 0xfe
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        ret
    }
}

/* @addr 0x00446880 (62b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x4c]
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     T
 *   nop * 9
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0f
 *   mov     eax, 0xfff
 *   mov     [g_walkCallback], eax
 *   mov     [g_state_00537e94], eax
 *   ret
 */
extern void MStackCall_00406340(void);
extern void Cmp2OrSet0b_0048e3e0(void);
__declspec(naked) void ScaledLoadJmpPauseSetMax_00446880(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x4c]
        mov     dword ptr [g_scaledInit_00542044], ecx
        jmp     MStackCall_00406340
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        call    Cmp2OrSet0b_0048e3e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0fh
        mov     eax, 0xfff
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_00537e94], eax
        ret
    }
}

/* @addr 0x004390f0 (62b)
 *   call F1; pause-test → ret
 *   testb 1,[dirty] ; je → call F2 ; pause → jne ret
 *   call F3; pause → jne ret; jmp T
 */
extern void MStackPush3CmpCall_0048eec0(void);
extern void SetJmp_00438f60(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void ScaledZeroFour_00490740(void);
extern void GuardedDispatch_0042c570(void);
__declspec(naked) void CallPauseTestByteJmpCalls_004390f0(void) {
    __asm {
        call    MStackPush3CmpCall_0048eec0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2fh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     SetJmp_00438f60
        call    FiveCallScaledChainTailJmp_0045f8d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    ScaledZeroFour_00490740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     GuardedDispatch_0042c570
        ret
    }
}

/* @addr 0x00451a60 (62b)
 *   call F1; pause → ret
 *   testb 4,[dirty]; je → ret
 *   call F2; pause → ret
 *   call F3; pause → ret
 *   mov [g_walkCallback], 0
 *   ret
 */
extern void SetJmp_00405420(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
__declspec(naked) void CallPauseTestByte4ZeroCB_00451a60(void) {
    __asm {
        call    SetJmp_00405420
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2fh
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   26h
        call    MStackPush2RunCountdown_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        call    MStackBracket7_DispatchAndChain_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ah
        mov     dword ptr [g_walkCallback], 0
        ret
    }
}

/* @addr 0x004353f0 (65b)
 *   call F1; test eax → jne ret
 *   call F2; pause → jne ret
 *   load g_walkCallback; test → jge skip → jmp T_inner
 *   load g_state_00535ddc; cmp 0x30000; store; jle → jmp T1; jmp T2
 *   ret
 */
extern void Cmp2CallDirtyCall_004398b0(void);
extern void Wrapper_00439310(void);
extern unsigned int g_state_00535ddc_y;
extern void TriEntryGateMain_00435440(void);
extern void GuardedSeq_00433bb0(void);
extern void PrefixThunkInstallSelf3State_00438f80(void);
__declspec(naked) void DualCallTestPauseRange_004353f0(void) {
    __asm {
        call    Cmp2CallDirtyCall_004398b0
        test    eax, eax
        _emit   75h
        _emit   37h
        call    Wrapper_00439310
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        mov     eax, dword ptr [g_walkCallback]
        test    eax, eax
        _emit   7dh
        _emit   05h
        jmp     TriEntryGateMain_00435440
        mov     eax, dword ptr [g_state_00535ddc_y]
        cmp     eax, 0x30000
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   05h
        jmp     GuardedSeq_00433bb0
        jmp     PrefixThunkInstallSelf3State_00438f80
        ret
    }
}

/* @addr 0x00466090 (61b)
 *   dec g_walkCallback; store both walk and g_state_0053a238
 *   je → jmp T1; mov [g_walkCallback], 6
 *   call F; pause → ret; push lit; call F2; add esp,4; ret
 */
extern unsigned int g_state_0053a238;
extern void TripleBlockInstallSelf_00465ef0(void);
extern void AndShlStore_00409280(void);
extern int ArgSarStoreJmp_004594f0(void *);
extern void *g_data_004ea990;
__declspec(naked) void DecCallPushCall_00466090(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_state_0053a238], eax
        _emit   74h
        _emit   05h
        jmp     TripleBlockInstallSelf_00465ef0
        mov     dword ptr [g_walkCallback], 6
        call    AndShlStore_00409280
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    OFFSET g_data_004ea990
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        ret
    }
}

/* @addr 0x0045fca0 (65b)
 *   call F; pause → ret
 *   load baseSel; mov eax,0x2001; store walk and [ecx*4+0x74]
 *   push lit; call F2; pause → ret; add esp,4; jmp T
 */
extern void SlotPhaseResetInstallChain_0048e0e0(void);
extern int IterStepScaledStore24_00428730(void *);
extern void *g_data_00542958;
extern void SelfInstallPhaseDispatch_0045fd30(void);
__declspec(naked) void CallPauseScaledStorePushCall_0045fca0(void) {
    __asm {
        call    SlotPhaseResetInstallChain_0048e0e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   32h
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x2001
        mov     dword ptr [g_walkCallback], eax
        push    OFFSET g_data_00542958
        mov     dword ptr [ecx*4 + 0x74], eax
        call    IterStepScaledStore24_00428730
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     SelfInstallPhaseDispatch_0045fd30
        ret
    }
}

/* @addr 0x00474010 (63b)
 *   inc g_state_004d57ac twice, push g_scaledInit_00542044 and g_fightGroupHead
 *   onto stack[idx*4]; mov g_scaledInit_00542044 = 0x7c; jmp T.
 */
extern void HalveChainTriplePop2_004740d0(void);
__declspec(naked) void DoubleStackPushAndJmp_00474010(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     dword ptr [g_scaledInit_00542044], 0x7c
        jmp     HalveChainTriplePop2_004740d0
    }
}

/* @addr 0x00460d80 (65b)
 *   load g_state_00538094; if non-zero zero g_walkCallback and ret.
 *   else load g_fightTableC0, g_fightGroupHead; not eax; store walk
 *   load [ecx*4 + 0x30]; cmp 1; store g_eventQueueCurrent
 *   if equal ret, else shr eax,8; store walk; ret.
 */
extern unsigned int g_state_00538094;
extern u32 g_fightTableC0;
__declspec(naked) void NotShrCmp1Store_00460d80(void) {
    __asm {
        mov     eax, dword ptr [g_state_00538094]
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     dword ptr [g_walkCallback], 0
        ret
        mov     eax, dword ptr [g_fightTableC0]
        mov     ecx, dword ptr [g_fightGroupHead]
        not     eax
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [ecx*4 + 0x30]
        cmp     ecx, 1
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   74h
        _emit   08h
        shr     eax, 8
        mov     dword ptr [g_walkCallback], eax
        ret
    }
}
