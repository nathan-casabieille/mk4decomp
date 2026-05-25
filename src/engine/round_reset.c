/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;

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
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

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
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_tickFlagF;
extern u32 g_dlSomeFlag2;
extern unsigned int g_quadEntryGate_0052d724;
extern unsigned int g_phaseTimer_00537e94;
extern unsigned int g_dst_00537ea4;
extern unsigned int g_dispatchSave_00537ef4;
extern unsigned int g_dispatchVar11_00537f04;
extern unsigned int g_hitPhase_00537f30;
extern unsigned int g_audioBank2State_00537f98;
extern unsigned int g_fightTickSavedSlot_005380d8;
extern unsigned int g_roundResetSlot_0053a3e4;
extern unsigned int g_phaseInstallSlot_0053a42c;
extern unsigned int g_audioStreamState_0053a430;
extern unsigned int g_phaseThunkArr_0053a474;
extern u32 g_dlSomeFlag1;
extern unsigned int g_dst_0053a6e0;
extern unsigned int g_phaseThunkSlot4_0053a6f8;
extern unsigned int g_phaseThunkState_0053a730;
extern unsigned int g_dispatchSave39_0053a788;
extern unsigned int g_dispatchClr1_0053e34c;
extern unsigned int g_installCountdownSlot2_00541d84;
extern unsigned int g_smState4Way_00541dc8;
extern unsigned int g_titleDemoState_00541df0;
extern unsigned int g_titleDemoState2_00541df4;
extern u32 g_dlState;
extern u32 g_dlAux;
extern unsigned int g_dispatchSave37_00541ee8;
extern unsigned int g_data_00541eec;
extern unsigned int g_data_00541ef0;
extern unsigned int g_data_00541ef4;
extern unsigned int g_data_00541ef8;
extern unsigned int g_data_00541efc;
extern unsigned int g_data_00541f00;
extern unsigned int g_clusterArr541f60_10;
extern unsigned int g_clusterArr541f60_11;
extern unsigned int g_clusterArr541f60_12;
extern unsigned int g_clusterArr541f60_13;
extern unsigned int g_clusterArr541f60_14;
extern unsigned int g_clusterArr541f60_15;
extern unsigned int g_clusterArr541f60_16;
extern unsigned int g_clusterArr541f60_17;
extern unsigned int g_clusterArr541f60_18;
extern unsigned int g_clusterArr541f60_19;
extern unsigned int g_clusterArr541f60_20;
extern unsigned int g_clusterArr541f60_21;
extern unsigned int g_clusterArr541f60_22;
extern unsigned int g_clusterArr541f60_23;
extern unsigned int g_clusterArr541f60_24;
extern unsigned int g_clusterArr541f60_25;
extern unsigned int g_clusterArr541f60_26;
extern unsigned int g_clusterArr541f60_27;
extern unsigned int g_clusterArr541f60_28;
extern unsigned int g_clusterArr541f60_29;
extern unsigned int g_clusterArr541f60_30;
extern unsigned int g_clusterArr541f60_31;
extern unsigned int g_clusterArr541f60_32;
extern unsigned int g_clusterArr541f60_0;
extern unsigned int g_clusterArr541f60_1;
extern unsigned int g_clusterArr541f60_2;
extern unsigned int g_clusterArr541f60_3;
extern unsigned int g_clusterArr541f60_4;
extern unsigned int g_clusterArr541f60_5;
extern unsigned int g_clusterArr541f60_6;
extern unsigned int g_clusterArr541f60_7;
extern unsigned int g_clusterArr541f60_8;
extern unsigned int g_clusterArr541f60_9;
extern unsigned int g_tripleEntryFlag_0054380c;
extern void Cmp2DirtyToggle_00423870(void);
extern void TestCmpZeroFour_004238b0(void);
extern void TriBranchFlagWrite_00422720(void);
extern void TwoStateCopyDup_004225f0(void);

__declspec(naked) void RoundReset_004223e0(void)
{
    __asm {
        push     ebx
        call     Cmp2DirtyToggle_00423870
        mov      eax, dword ptr [g_framePauseFlag]
        xor      ebx, ebx
        cmp      eax, ebx
        jne      L_25e9
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_240f
        call     TwoStateCopyDup_004225f0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_25e9
    L_240f:
        mov      eax, dword ptr [g_tickFlagF]
        cmp      eax, 2
        mov      dword ptr [g_walkCallback], eax
        jne      short L_242f
        call     TestCmpZeroFour_004238b0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_25e9
    L_242f:
        mov      eax, 0x10000
        mov      dword ptr [g_roundResetSlot_0053a3e4], eax
        mov      dword ptr [g_phaseThunkArr_0053a474], eax
        mov      eax, dword ptr [g_hitPhase_00537f30]
        cmp      eax, 1
        mov      dword ptr [g_walkCallback], eax
        jne      short L_2459
        mov      dword ptr [g_dst_0053a6e0], ebx
        mov      dword ptr [g_dst_00537ea4], ebx
    L_2459:
        mov      dword ptr [g_titleDemoState_00541df0], ebx
        mov      dword ptr [g_titleDemoState2_00541df4], ebx
        mov      byte ptr [g_tripleEntryFlag_0054380c], bl
        mov      dword ptr [g_phaseThunkSlot4_0053a6f8], ebx
        mov      dword ptr [g_dispatchSave39_0053a788], ebx
        mov      dword ptr [g_dispatchClr1_0053e34c], ebx
        mov      dword ptr [g_smState4Way_00541dc8], ebx
        mov      dword ptr [g_phaseTimer_00537e94], ebx
        mov      dword ptr [g_phaseInstallSlot_0053a42c], ebx
        mov      dword ptr [g_dispatchSave_00537ef4], ebx
        mov      dword ptr [g_audioBankSel_00537f94], ebx
        mov      dword ptr [g_quadEntryGate_0052d724], ebx
        mov      dword ptr [g_audioBank2State_00537f98], ebx
        mov      dword ptr [g_phaseThunkState_0053a730], ebx
        mov      dword ptr [g_installCountdownSlot2_00541d84], ebx
        mov      dword ptr [g_audioStreamState_0053a430], ebx
        mov      dword ptr [g_dispatchVar11_00537f04], ebx
        mov      dword ptr [g_dlSomeFlag1], ebx
        mov      dword ptr [g_dlSomeFlag2], ebx
        mov      dword ptr [g_dlState], ebx
        mov      dword ptr [g_dlAux], ebx
        mov      dword ptr [g_fightTickSavedSlot_005380d8], ebx
        mov      dword ptr [g_data_00541eec], ebx
        mov      dword ptr [g_dispatchSave37_00541ee8], ebx
        mov      dword ptr [g_data_00541ef4], ebx
        mov      dword ptr [g_data_00541ef0], ebx
        mov      dword ptr [g_data_00541efc], ebx
        mov      dword ptr [g_data_00541ef8], ebx
        mov      dword ptr [g_clusterArr541f60_10], ebx
        mov      dword ptr [g_data_00541f00], ebx
        mov      dword ptr [g_clusterArr541f60_12], ebx
        mov      dword ptr [g_clusterArr541f60_11], ebx
        mov      dword ptr [g_clusterArr541f60_14], ebx
        mov      dword ptr [g_clusterArr541f60_13], ebx
        mov      dword ptr [g_clusterArr541f60_16], ebx
        mov      dword ptr [g_clusterArr541f60_15], ebx
        mov      dword ptr [g_clusterArr541f60_18], ebx
        mov      dword ptr [g_clusterArr541f60_17], ebx
        mov      dword ptr [g_clusterArr541f60_20], ebx
        mov      dword ptr [g_clusterArr541f60_19], ebx
        mov      dword ptr [g_clusterArr541f60_22], ebx
        mov      dword ptr [g_clusterArr541f60_21], ebx
        mov      dword ptr [g_clusterArr541f60_24], ebx
        mov      dword ptr [g_clusterArr541f60_23], ebx
        mov      dword ptr [g_clusterArr541f60_26], ebx
        mov      dword ptr [g_clusterArr541f60_25], ebx
        mov      dword ptr [g_clusterArr541f60_28], ebx
        mov      dword ptr [g_clusterArr541f60_27], ebx
        mov      dword ptr [g_clusterArr541f60_30], ebx
        mov      dword ptr [g_clusterArr541f60_29], ebx
        mov      dword ptr [g_clusterArr541f60_32], ebx
        mov      dword ptr [g_clusterArr541f60_31], ebx
        mov      dword ptr [g_clusterArr541f60_1], ebx
        mov      dword ptr [g_clusterArr541f60_0], ebx
        mov      dword ptr [g_clusterArr541f60_3], ebx
        mov      dword ptr [g_clusterArr541f60_2], ebx
        mov      dword ptr [g_clusterArr541f60_5], ebx
        mov      dword ptr [g_clusterArr541f60_4], ebx
        mov      dword ptr [g_clusterArr541f60_7], ebx
        mov      dword ptr [g_clusterArr541f60_6], ebx
        mov      dword ptr [g_clusterArr541f60_9], ebx
        mov      dword ptr [g_clusterArr541f60_8], ebx
        call     TriBranchFlagWrite_00422720
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      short L_25e9
        mov      eax, dword ptr [g_gtFightTickCounter]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_fightTickSavedSlot_005380d8], eax
    L_25e9:
        pop      ebx
        ret
    }
}
