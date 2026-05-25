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
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;
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
extern unsigned int g_rangeSqLimit_0053a180;
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
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_00535cfc;
extern unsigned int g_active_00537e88;
extern unsigned int g_data_00537f48;
extern unsigned int g_data_005380e0;
extern unsigned int g_data_0053a3e0;
extern unsigned int g_active_0053a408;
extern unsigned int g_data_0053a51c;
extern unsigned int g_data_0053a700;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542004;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_005433ec;
extern unsigned int g_data_00543568;
extern unsigned int g_data_00543714;
extern unsigned int g_data_0054371c;
extern void AudioInstallSelfStatePush_004aa8a0(void);
extern void ClearTwoCallSetStore_004a2270(void);
extern void DownloadPlayerChar(void);
extern void DualScaledStoreConst_004a22c0(void);
extern void IncOrZero9_00422080(void);
extern void InstallSelfTableWalk_004200d0(void);
extern void ScaledClearTripleCallJmp_004202c0(void);
extern void SixCallSeqPushImm_004a1d80(void);
extern void TablePushAccumTailJmp_00429e30(void);
extern void TableWalkBoundedCmp_004bd890(void);
extern void TestCmpZeroFour_004238b0(void);

__declspec(naked) void MatchStartCluster_004a23c0(void)
{
    __asm {
        /* === Helper 1 (0x4a23c0): match init === */
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      eax, OFFSET g_active_0053a408
        mov      ecx, OFFSET g_data_0053a3e0
        and      edx, 0xfffffffe
        shr      eax, 2
        shr      ecx, 2
        mov      dword ptr [g_xformDirtyFlags], edx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DualScaledStoreConst_004a22c0
        mov      edx, OFFSET g_active_00537e88
        mov      eax, OFFSET g_data_0053a700
        shr      edx, 2
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_xformEntityIdx], eax
        call     DualScaledStoreConst_004a22c0
        call     ClearTwoCallSetStore_004a2270
        mov      dword ptr [g_data_00542004], 0
        call     SixCallSeqPushImm_004a1d80
        mov      dword ptr [g_eventQueueWorkType], 0
        call     Push16Call_00489f50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2440
        jmp      InstallSelfTableWalk_004200d0
    L_2440:
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
        nop
        /* === Helper 2 (0x4a2450): round-start FSM step === */
    L_2450:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        je       L_2527
        mov      dword ptr [g_eventQueueWorkType], edi
        call     Push16Call_00489f50
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_260c
        mov      ecx, dword ptr [g_data_0053a51c]
        mov      dword ptr [g_walkCallback], ecx
        call     TablePushAccumTailJmp_00429e30
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_260c
        call     TestCmpZeroFour_004238b0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_260c
        mov      eax, dword ptr [g_data_00537f48]
        mov      edx, OFFSET g_data_00535cfc
        shr      edx, 2
        mov      ebx, 1
        mov      dword ptr [g_eventQueueEnd], edx
        mov      byte ptr [g_data_0054371c], bl
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], edi
        call     DownloadPlayerChar
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_260c
        mov      ecx, dword ptr [g_data_005380e0]
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_walkCallback], ecx
        call     DownloadPlayerChar
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_260c
        mov      byte ptr [g_data_0054371c], 0
        call     ScaledClearTripleCallJmp_004202c0
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_2527:
        mov      ebx, dword ptr [g_xformDirtyFlags]
        push     6
        and      ebx, 0xfffffffe
        mov      dword ptr [g_xformDirtyFlags], ebx
        call     TableWalkBoundedCmp_004bd890
        mov      edx, OFFSET g_active_0053a408
        mov      eax, OFFSET g_data_0053a3e0
        mov      ebx, 1
        add      esp, 4
        shr      edx, 2
        shr      eax, 2
        mov      dword ptr [g_data_00543714], ebx
        mov      dword ptr [g_data_005433ec], ebx
        mov      dword ptr [g_data_00543568], ebx
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_xformEntityIdx], eax
        call     DualScaledStoreConst_004a22c0
        mov      ecx, OFFSET g_active_00537e88
        mov      edx, OFFSET g_data_0053a700
        shr      ecx, 2
        shr      edx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_xformEntityIdx], edx
        call     DualScaledStoreConst_004a22c0
        call     ClearTwoCallSetStore_004a2270
        mov      dword ptr [g_data_00542004], edi
        mov      dword ptr [g_data_00537f48], edi
        mov      dword ptr [g_data_005380e0], edi
        call     IncOrZero9_00422080
        call     SixCallSeqPushImm_004a1d80
        mov      dword ptr [esi + 8], OFFSET L_2450
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET L_2450
        mov      dword ptr [eax*4 + 0x84], ebx
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     AudioInstallSelfStatePush_004aa8a0
        mov      dword ptr [g_framePauseFlag], ebx
    L_260c:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
