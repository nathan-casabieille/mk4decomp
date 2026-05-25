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
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_state_00542094;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_eventQueueChild;
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
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
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

extern void RoundStartCluster_0047b900(void);
extern void ScaledLoadIncJmp_00429840(void);
extern void StateMachineSharedTail_0047baf0(void);
extern void AerialPunchCluster_0047bc30(void);
extern void CmpEqInitCallElseJmp_0048d4b0(void);
extern void EsiInstallClampAddCall_0048fe40(void);
extern void MStackPushSet0008_004901a0(void);
extern void ScaledZeroFour_00490740(void);
extern unsigned int g_data_004ed1d8;

extern unsigned int g_data_0050f22c;
extern unsigned int g_data_0053a404;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_00543100;
extern void ArgSarStoreJmp_004594f0(void);
extern void AudioInstallSelfStatePush_004aa8a0(void);
extern void BootInitGuardedCallChain_004265d0(void);
extern void CallSetPause_0041f830(void);
extern void CjInstallSelfRouter_00470480(void);
extern void DualSectionInit_00492140(void);
extern void Eleven404b90_404c00_004266d0(void);
extern void GuardedSetupTailMStackJmp_00492210(void);
extern void MStackPushChainDispatchInit5_004925d0(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void RemapWalkAndJmp_00491e70(void);
extern void RemapWalkAndJmp_00491ec0(void);
extern void ScaledLoadIncJmp_00428d00(void);
extern void StateDispatchTable_00490fc0(void);
extern void Ten404c40_404bd0_00426780(void);
extern void UpperBodyComboFsmCluster_00492aa0(void);
extern void ZeroTripleJmp_00491e50(void);

__declspec(naked) void RoundStartCluster_0047b900(void)
{
    __asm {
        /* H1: 3-state FSM */
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       short L_b9cd
        dec      eax
        je       short L_b930
        call     CjInstallSelfRouter_00470480
        pop      edi
        pop      esi
        ret
    L_b930:
        call     ScaledZeroFour_00490740
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_ba4d
        call     StateDispatchTable_00490fc0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_ba4d
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [g_eventQueueNotMask], edi
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      dword ptr [g_currentNodeFlags], 0xccc
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_0047b900
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET RoundStartCluster_0047b900
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x2000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     EsiInstallClampAddCall_0048fe40
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b9cd:
        call     MStackPushSet0008_004901a0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_ba4d
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, 0x100e
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_0047b900
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET RoundStartCluster_0047b900
        add      ecx, 0x1000000
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     ScaledLoadIncJmp_00428d00
        mov      dword ptr [g_framePauseFlag], 1
    L_ba4d:
        pop      edi
        pop      esi
        ret
        /* H2: chime trigger */
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, 0x211
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_data_004ed1d8
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
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
        /* H3: scenario picker */
        call     ScaledLoadIncJmp_00429840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_baed
        mov      dword ptr [g_walkCallback], 0x11
        call     CmpEqInitCallElseJmp_0048d4b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_baed
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_bab4
        jmp      StateMachineSharedTail_0047baf0
    L_bab4:
        call     ScaledLoadIncJmp_00429840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_baed
        mov      dword ptr [g_walkCallback], 0x11
        call     CmpEqInitCallElseJmp_0048d4b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_baed
        test     byte ptr [g_xformDirtyFlags], 1
        jne      short L_bae8
        jmp      AerialPunchCluster_0047bc30
    L_bae8:
        jmp      StateMachineSharedTail_0047baf0
    L_baed:
        ret
    }
}

__declspec(naked) void RoundStartCluster_004919c0(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 3
        ja       L_1bf6
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_19ed:
        call     RemapWalkAndJmp_00491e70
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_eventQueueEnd], ecx
        call     RemapWalkAndJmp_00491ec0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_eventQueueIdx], edx
        call     GuardedSetupTailMStackJmp_00492210
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        call     MStackLoopFieldInit_00492280
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        call     MStackPushChainDispatchInit5_004925d0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        push     0x1a
        push     OFFSET UpperBodyComboFsmCluster_00492aa0 + 0xc0
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     0x1a
        push     OFFSET UpperBodyComboFsmCluster_00492aa0 + 0x230
        call     StoreTwoCall_0049cb40
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], 0x48
        call     Push16Call_00489f50
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [eax*4 + 0x6c], 0x62e97
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      eax, 0xfff9d169
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x6c], eax
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_004919c0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x25
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_1ae3:
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [edx*4 + 0x6c], edi
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [eax*4 + 0x6c], edi
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_004919c0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x8c
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_1b2b:
        mov      ebx, 1
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_data_0053a404], ebx
        call     UpperBodyComboFsmCluster_00492aa0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_004919c0
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, OFFSET RoundStartCluster_004919c0
        mov      dword ptr [ecx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x4000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     AudioInstallSelfStatePush_004aa8a0
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_1ba8:
        call     ZeroTripleJmp_00491e50
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        call     DualSectionInit_00492140
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        push     0x25f
        push     OFFSET L_1c20
        call     StoreTwoCall_0049cb40
        mov      ebx, 1
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_004919c0
        mov      dword ptr [esi + 0x84], ebx
        add      esp, 8
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_1bf6:
        call     BootInitGuardedCallChain_004265d0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        call     StackPopDispatchTagged_0041f780
    L_1c08:
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_jmptbl:
        _emit 0xa8
        _emit 0x1b
        _emit 0x49
        _emit 0x00
        _emit 0xed
        _emit 0x19
        _emit 0x49
        _emit 0x00
        _emit 0xe3
        _emit 0x1a
        _emit 0x49
        _emit 0x00
        _emit 0x2b
        _emit 0x1b
        _emit 0x49
        _emit 0x00
        nop
        nop
        nop
        nop
    L_1c20:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        je       L_1ccc
        call     Ten404c40_404bd0_00426780
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [ecx*4]
        inc      ecx
        cmp      eax, edi
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueEnd], ecx
        jne      L_1ca8
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      eax, OFFSET g_data_0050f22c
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [ecx*4 + 0x24], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x24], edx
        call     CallSetPause_0041f830
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_1ca8:
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [ecx*4 + 0x24], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x24], edx
        jmp      L_1e11
    L_1ccc:
        mov      eax, OFFSET g_data_00543100
        shr      eax, 2
        mov      dword ptr [g_eventQueueEnd], eax
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_eventQueueEnd], eax
        call     DispatcherComplex260_00407400
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        test     byte ptr [g_xformDirtyFlags], 4
        je       L_1d0f
        call     CallSetPause_0041f830
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_1d0f:
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueIdx], edx
        call     DispatcherComplex260_00407400
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_fightGroupHead], eax
        mov      dword ptr [ecx*4 + 0x54], edi
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x58], edi
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [eax*4 + 0x54], edi
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0x21
        mov      dword ptr [ecx*4 + 0x58], edi
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x30], eax
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_currentNodeIdx], edx
        call     MStackPushComplexCallPop_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      ebx, 0x14000
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [eax*4 + 0x5c], ebx
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackPushComplexCallPop_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [edx*4 + 0x5c], ebx
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_fightGroupHead], eax
    L_1e11:
        call     Eleven404b90_404c00_004266d0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_1c20
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 5
        mov      dword ptr [g_framePauseFlag], eax
    L_1e3f:
        pop      edi
        pop      esi
        pop      ebx
        ret      
    }
}
