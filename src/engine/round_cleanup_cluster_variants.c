/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_data_00542050;
extern unsigned int g_data_00542070;
extern unsigned int g_data_00542084;
extern unsigned int g_state_0054208c;
extern unsigned int g_state_00542088;
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_state_00542080;
extern u32 g_pendingNodeType;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_state_0054207c;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_state_00541fa4;
extern unsigned int g_state_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_state_0053a3c0;
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern void StoreIncrMStackPush6_004275c0(void);
extern void DispatcherComplex181_004263d0(void);
extern void RoundCleanupCluster_00427690(void);

/* @addr 0x00477920 (165b game) - poll-then-init pattern:
 *   poll: SaveCallRestore(0x22); SaveCallRestoreOrXor(0x22); while (state & 4): retry.
 *   walkCallback = max(g_x_0053a718, 0); call StoreIncrMStackPush6_004275c0; pause? ret.
 *   set fixed state (walkCallback=2, g_x_00542074=0x22, g_data_00542070=2,
 *   g_x_00542078=0, g_x_0054207c=0xff960000, g_currentNodeFlags=2);
 *   call DispatcherComplex181; pause? ret; call RoundCleanupCluster_00427690.
 */
extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004e7f40;
extern unsigned int g_data_004e7f50;
extern unsigned int g_data_004e7f60;
extern unsigned int g_data_004e7f70;
extern unsigned int g_data_00501250;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_00542054;
extern unsigned int g_data_00542058;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542060;
extern unsigned int g_data_00542074;
extern unsigned int g_data_00542078;
extern unsigned int g_data_0054207c;
extern unsigned int g_data_0054208c;
extern unsigned int g_x_0053a718;
extern unsigned int g_x_00542074;
extern unsigned int g_x_0054207c;
extern void ArgSarStoreJmp_004594f0(void);
extern void ChainGatedNegAccum_0048b740(void);
extern void DualScaledStore_00452740(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void InstallSelfPackedTailJmp_004751f0(void);
extern void MStackPush2GlobalSwap_00477400(void);
extern void PendingMatch_00455bd0(void);
extern void SaveCallRestoreOrXor_00404a00(void);
extern void SaveCallRestore_004049d0(void);
extern void SetJmp_004753a0(void);
extern void StoreLoadJmp_00404ef0(void);
extern void func_004569f0(void);

extern unsigned int g_data_004eef18;
extern unsigned int g_data_004eef20;
extern void DualEntryBitFlagDispatch_0048e820(void);
extern void GameLoaderHandlerCluster_004876f0(void);
extern void IterStepDualStore_00490b40(void);
extern void MStackPush3CallCascade_00486d90(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void MStackPushSet0004_00490230(void);
extern void RoundCleanupCluster_00487510(void);
extern void TableLookupCall_00489f60(void);

__declspec(naked) void PollThenInit_00477920(void) {
    __asm {
        push    ebx
        push    0x22
        call    SaveCallRestore_004049d0
        add     esp, 4
        push    0x22
        call    SaveCallRestoreOrXor_00404a00
        mov     al, byte ptr [g_state_0054208c]
        mov     bl, 4
        add     esp, 4
        _emit   84h
        _emit   0c3h
        _emit   75h
        _emit   1dh
loopPoll:
        push    0x22
        call    SaveCallRestore_004049d0
        add     esp, 4
        push    0x22
        call    SaveCallRestoreOrXor_00404a00
        mov     al, byte ptr [g_state_0054208c]
        add     esp, 4
        _emit   84h
        _emit   0c3h
        _emit   74h
        _emit   0e3h
        mov     eax, dword ptr [g_x_0053a718]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   7dh
        _emit   0ah
        mov     dword ptr [g_walkCallback], 0
        call    StoreIncrMStackPush6_004275c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   40h
        mov     eax, 2
        mov     dword ptr [g_x_00542074], 0x22
        mov     dword ptr [g_data_00542070], eax
        mov     dword ptr [g_acc_00542078], 0
        mov     dword ptr [g_x_0054207c], 0xff960000
        mov     dword ptr [g_currentNodeFlags], eax
        call    DispatcherComplex181_004263d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        call    RoundCleanupCluster_00427690
        pop     ebx
        ret
    }
}


__declspec(naked) void RoundCleanupCluster_00487510(void)
{
    __asm {
        /* H1: installer */
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, 1
        shl      eax, 2
        mov      dword ptr [eax + 0x84], 0
        mov      dword ptr [eax + 8], OFFSET RoundCleanupCluster_00487510
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_data_0054204c], 0x28
        mov      dword ptr [g_framePauseFlag], ecx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* H2: animate + tail-jump */
        mov      dword ptr [g_walkCallback], 0x27
        call     TableLookupCall_00489f60
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_758b
        mov      dword ptr [g_data_00542074], 1
        mov      dword ptr [g_data_0054207c], 2
        mov      dword ptr [g_walkCallback], 0x23d7
        jmp      MStackPush3CallCascade_00486d90
    L_758b:
        ret
        nop
        nop
        nop
        nop
        /* H3: load + sound */
        push     OFFSET g_data_004eef18
        call     IterStepDualStore_00490b40
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_75c1
        call     MStackPushSet0004_00490230
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_75c1
        push     OFFSET g_data_004eef20
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_75c1:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* H4 (L_75d0): big state dispatcher */
    L_75d0:
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_76c8
        dec      eax
        je       short L_765f
        dec      eax
        mov      ebx, 1
        je       short L_763f
        call     DualEntryBitFlagDispatch_0048e820
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_76ea
        test     byte ptr [g_data_0054208c], bl
        je       short L_7637
        call     MStackPush3CmpCall_0048eec0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_76ea
        test     byte ptr [g_data_0054208c], bl
        jne      short L_763f
    L_7637:
        call     FiveCallGuardSetTail_0046f6b0
        pop      esi
        pop      ebx
        ret
    L_763f:
        mov      dword ptr [esi + 8], OFFSET L_75d0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret
    L_765f:
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [ecx*4 + 0x60]
        cmp      eax, 0x10a
        mov      dword ptr [g_walkCallback], eax
        jne      short L_768b
        call     GameLoaderHandlerCluster_004876f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_76ea
        mov      eax, dword ptr [g_walkCallback]
    L_768b:
        cmp      eax, 0x10b
        jne      short L_76a0
        call     GameLoaderHandlerCluster_004876f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_76ea
    L_76a0:
        mov      dword ptr [esi + 8], OFFSET L_75d0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 5
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret
    L_76c8:
        mov      ebx, 1
        mov      dword ptr [esi + 8], OFFSET L_75d0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_data_0054204c], 8
        mov      dword ptr [g_framePauseFlag], ebx
    L_76ea:
        pop      esi
        pop      ebx
        ret
    }
}

__declspec(naked) void RoundCleanupCluster_00455920(void)
{
    __asm {
        /* === Helper 1 (0x455920): event 004e7f40 forwarder === */
    L_5920:
        push     OFFSET g_data_004e7f40
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret
        nop
        nop
        /* === Helper 2 (0x455930): counter loop calling helper 1 === */
        mov      eax, dword ptr [g_data_00542058]
        dec      eax
        mov      dword ptr [g_data_00542058], eax
        js       short L_5942
        /* force 5-byte NEAR jmp (orig is e9 de ff ff ff, not short jmp) */
        _emit    0xe9
        _emit    0xde
        _emit    0xff
        _emit    0xff
        _emit    0xff
    L_5942:
        push     OFFSET g_data_004e7f50
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret
        /* === Helper 3 (0x455950): main FSM w/ jump table === */
    L_5950:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 3
        ja       L_5abd
        jmp      dword ptr [eax*4 + L_jmptbl_5b28]
    L_597d:
        /* case 1: 4569f0 text dispatch */
        push     OFFSET func_004569f0
        call     StoreLoadJmp_00404ef0
        mov      dword ptr [esi + 8], OFFSET L_5950
        mov      dword ptr [esi + 0x84], 2
        add      esp, 4
        mov      dword ptr [g_data_0054204c], 0x64
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_59b2:
        /* case 2: install + state 3 */
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_0054205c], ecx
        mov      dword ptr [esi + 8], OFFSET L_5950
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_5950
        add      ecx, 0x3000000
        mov      dword ptr [edx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     InstallSelfPackedTailJmp_004751f0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_5a1d:
        /* case 3: install + state 4 */
        mov      eax, OFFSET g_data_00501250
        mov      edx, OFFSET L_5950
        shr      eax, 2
        mov      dword ptr [g_data_00542054], eax
        mov      dword ptr [esi + 8], OFFSET L_5950
        mov      ecx, dword ptr [g_data_00542060]
        add      edx, 0x4000000
        mov      dword ptr [ecx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     SetJmp_004753a0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_5a88:
        /* case 0: pre-stage */
        call     DualScaledStore_00452740
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_5b22
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_5950
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0x47
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret
    L_5abd:
        mov      ecx, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_00542078], 0x16666
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [g_data_0054207c], edi
        call     ChainGatedNegAccum_0048b740
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_5b22
        mov      edx, dword ptr [g_data_00542054]
        mov      eax, dword ptr [g_data_00542078]
        push     OFFSET g_data_004e7f60
        mov      dword ptr [edx*4 + 0x54], eax
        mov      ecx, dword ptr [g_data_00542054]
        mov      edx, dword ptr [g_data_0054207c]
        mov      dword ptr [ecx*4 + 0x5c], edx
        mov      eax, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_0054205c], eax
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_5b22:
        pop      edi
        pop      esi
        ret
        /* 3-byte align pad: lea ecx, [ecx] (8d 49 00) */
        _emit    0x8d
        _emit    0x49
        _emit    0x00
    L_jmptbl_5b28:
        /* 4 absolute-address entries */
        _emit 0x88
        _emit 0x5a
        _emit 0x45
        _emit 0x00
        _emit 0x7d
        _emit 0x59
        _emit 0x45
        _emit 0x00
        _emit 0xb2
        _emit 0x59
        _emit 0x45
        _emit 0x00
        _emit 0x1d
        _emit 0x5a
        _emit 0x45
        _emit 0x00
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 4 (0x455b3b): set 0x10 bit + event 004e7f70 === */
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [edx*4 + 0x64]
        mov      dword ptr [g_data_00542044], ecx
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       ah, 0x10
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [g_data_004d57ac], eax
        call     MStackPush2GlobalSwap_00477400
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5bb4
        push     OFFSET g_data_004e7f70
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_5bb4:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 5 (0x455bc0): init counter + jmp 00455bd0 === */
        mov      dword ptr [g_data_00542058], 0x16
        jmp      PendingMatch_00455bd0
    }
}
