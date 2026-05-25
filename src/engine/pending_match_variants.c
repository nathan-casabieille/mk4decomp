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
extern unsigned int g_x_0052aac4;

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

/* @addr 0x00426d30 (81b)
 *   Push g_eventQueueEnd on mstack; replace it with 0x4e2670>>2;
 *   push 0x23c and 0x00426da0 as args; call StoreTwoCall_0049cb40;
 *   pop g_eventQueueEnd; pop mstack; ret.
 *   The 0x426da0 imm is the in-body label of GameMusicState4Way_00426d90.
 */
extern unsigned int g_data_004e2670;
void PushSetEventQueueCallStore_00426d30(void) {
    unsigned int top;
    top = g_state_004d57ac + 1;
    g_state_004d57ac = top;
    *(unsigned int *)(top * 4) = g_eventQueueEnd;
    g_eventQueueEnd = (unsigned int)&g_data_004e2670 >> 2;
    StoreTwoCall_0049cb40(0x00426da0, 0x23c);
    top = g_state_004d57ac;
    g_eventQueueEnd = *(unsigned int *)(top * 4);
    g_state_004d57ac = top - 1;
}

/* @addr 0x004b8ec0 (92b)
 *   eax = arg0; g_data_00ab4d9c = eax;
 *   ecx = eax + 0x200; edx = eax + 0x400;
 *   g_data_00ab4da0 = ecx; g_data_00ab4da4 = edx;
 *   ecx = eax + 0x580; edx = eax + 0x680;
 *   g_data_00ab4da8 = ecx; g_data_00ab4dac = edx;
 *   ecx = eax + 0x720; edx = eax + 0x780;
 *   eax += 0x7c0; g_data_00ab4db0=ecx; g_data_00ab4db4=edx;
 *   g_data_00ab4db8=eax; ret.
 */
extern unsigned int g_state_00ab4d9c;
extern unsigned int g_state_00ab4da0;
extern unsigned int g_state_00ab4da4;
extern unsigned int g_state_00ab4da8;
extern unsigned int g_state_00ab4dac;
extern unsigned int g_state_00ab4db0;
extern unsigned int g_state_00ab4db4;
extern unsigned int g_state_00ab4db8;
extern void MStackBracket5_LinkedListUnlink_00409aa0(void);
extern void CountdownClampWalk_00422810(void);
extern void DownloadPlayerChar(void);
extern void DualWalkRange_00468440(void);
extern void BootDispatchSlotInit_004071a0(void);
extern void CjInstallSelfRouter_00470480(void);
extern void ScaledChainCallPauseSetJmp_0048f8e0(void);
extern void MStackBracket2_TreeWalkRecursive_00405e70(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void CallPauseScaledStoreCopyJmp_00461220(void);
extern void ScaledArrStore_00429980(void);
extern void MStackPushComplexCallPop_00406430(void);
extern unsigned int g_state_0053a51c;
extern unsigned int g_state_0052aac4;
extern unsigned int g_data_00537f30;
extern void StreamChainStringInstall_00457900(void);
extern void StorePauseImulShr16_004ab630(void);
extern void Mul10TailPairMidChain_00476a20(void);
extern void NotShrCmp1Store_00460d80(void);
extern void Wrapper_0048a3a0(void);
extern void Wrapper_0048a350(void);
extern void PendingMatch_0042b930(void);
extern void FpuSqrtMul_004ab350(void);
extern unsigned int g_data_0053a498;
extern unsigned int g_state_004d50a8;
extern unsigned int g_dualB_00538038;
extern unsigned int g_dualB_0053803c;
extern unsigned int g_state_00541dc4;
extern void TripleSubVec3_004250f0(void);
extern void Mul10SumSqrt_00425830(void);
extern void MStackPushTableWalk_00493a20(void);
extern void LoadCmpAddrJmp_00493ed0(void);
extern void ScaledInitOrSelfPtrSetType_0046a5e0(void);
extern void ScaledStoreCSet58Jmp_004708a0(void);
extern void CjTableThresholdDispatch_00488f00(void);
extern void GateDispatch6c_00494580(void);
extern void TwoEntryWrapperGuarded_004826f0(void);
extern void DualGatedStateYield_0048fc80(void);
extern void DualScaledInitCmp_0046dbd0(void);
extern void FlagCascadeStateSet_0048ec30(void);
extern void MoveDispatch4StateFsm_00494a60(void);
extern void IdCascadeBitSet_00439760(void);
extern void Scaled3StorePushCallJmp_00438220(void);
extern void Thunk_00439e30(void);
extern void StateDispatchYield_00471190(void);
extern unsigned int g_data_0053a478;
extern unsigned int g_state_00537e98;
extern void PushPopState70Mask_00490650(void);
extern void Thunk_0049cba0(void);
extern void CopyJmp_0048ee80(void);
extern void ScaledChain3c74_0048f910(void);
extern void ScaledChain3c7c_0048f930(void);
extern void MStackCall_00406340(void);
extern void PendingMatch_0046cd30(void);
extern void Phase3InstallPackedSelf_00471010(void);
extern void ZeroSlotsGatedDispatch_00423720(void);
extern void GuardedSeq_004297b0(void);
extern void ScaledInitOrSelfPtr_00428950(void);
extern void MStackPush2ChainSwap_0048f090(void);
extern void CopyJmp_00406ba0(void);
extern void DivLongPushCall_004ab320(void);
extern void ScaledDecPop_00404c40(void);
extern void ScaledDecPop_00404bd0(void);
extern void TripleMul10VecJmpFpu_00424990(void);
extern void DownloadPlayerChar_Variant(void);
extern void TripleStateSwapCall_0048cc40(void);
extern void Atan2QuadrantLookup_004245b0(void);
extern void InstallSelfChainSet2011_00439ec0(void);
extern void GuardedChainPushSetCallPop_00406bb0(void);
extern void MStackPushSet0001_00490260(void);
extern void ScaledInit_0048f720(void);
extern void ScaledZero44_00491500(void);
extern void ScaledChainNegStore_00470310(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void CallPauseScaledDecJmp_00429750(void);
extern void PushPop84TripleCall_00438b90(void);
extern void Vec3DeltaDualMul10_004394a0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void ScaledLitLoadCall_00480fe0(void);
extern void Thunk_0043a540(void);
extern void HitReactionDispatcher_0045f650(void);
extern void Cmp2DirtyToggle_00423870(void);
extern void ScaledClear1cTestWalkCall_004460c0(void);
extern void MStackBracket4_ListInsertZeroFill_00408600(void);
extern void MStackPush3LinkedListWalk_004088b0(void);
extern void MStackScopedSlotSetupPair_0040a520(void);
extern void ChainSetupBitToggle_00491290(void);
extern void MstackPopScaledChainPlusThunks_00471250(void);
extern void InstallSelfCmdStreamInterp_00494290(void);
extern void DirtyDoubleDeref_00408cb0(void);
extern void DispatchSwitchWalkCmp_00438bf0(void);
extern void Wrapper_00438c40(void);
extern void ScaledAndCheckJmp_00470f60(void);
extern void AudioVolumeRescale_004ab690(void);
extern void CallPauseConstStoreJmp_004350f0(void);
extern void InstallSelfPair_00435110(void);
extern void MStackPushSet6Jmp_00438470(void);
extern void MStackPushSet0Jmp_004384b0(void);
extern void GuardedSeq_00473ef0(void);
extern void GuardedSeq_00473f10(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StateGateMStackOverlap_00438690(void);
extern void ChainDecCondStoreCallJmp_00434880(void);
extern void ScaledAddDeref_00494800(void);
extern void MStackPush2ChainLLInsert_00406790(void);
extern void ScaledLitAddJmp_00480fb0(void);
extern void MStackPushDispatchBitGate_00407330(void);
extern void PushDualDerefClearPop_004092a0(void);
extern void MStackPushTwoEntryChainCall_004058c0(void);
extern void PushPopScaled18_004059a0(void);
extern void PushCallSet2147Jmp_00439320(void);
extern void TableLookupCall_00489ff0(void);
extern void CmpEqInitCallElseJmp_0048d4b0(void);
extern void MStackAngleRatioSubchain_00476af0(void);
extern void PushStackAllocCall_00425900(void);
extern void DualScaledInitClear_00433c10(void);
extern void ScaledShrAnd_0048bb40(void);
extern void DualEntryBitFlagDispatch_0048e820(void);
extern void SlotPhaseResetInstallChain_0048e0e0(void);
extern void RoundEndDifferenceFsmCluster_004572d0(void);
extern void ClampNegPair_0049a170(void);
extern void Vec2SumMul10ChainCompute_0049bc60(void);
extern void GuardedSeq_0049a650(void);
extern void AtanDualDeltaThreshold_0049c870(void);
extern void Set43DualCallJmp_0049a620(void);
extern unsigned int g_data_00541e68;
extern unsigned int g_load_0052ab04;
extern unsigned int g_load_0052ab08;
extern unsigned int g_load_0052ab10;
extern unsigned int g_state_00537f48;
extern unsigned int g_state_005380e0;
extern unsigned int g_state_00535cfc;
extern unsigned int g_state_0053a1d0;
void Helper_TickInit(unsigned int base) {
    g_state_00ab4d9c = base;
    g_state_00ab4da0 = base + 0x200;
    g_state_00ab4da4 = base + 0x400;
    g_state_00ab4da8 = base + 0x580;
    g_state_00ab4dac = base + 0x680;
    g_state_00ab4db0 = base + 0x720;
    g_state_00ab4db4 = base + 0x780;
    g_state_00ab4db8 = base + 0x7c0;
}

extern void PendingMatch_0045e640(void);
extern void Thunk_004344a0(void);
extern void FlagInitTableSelector_00434560(void);
extern void InstallSelfChainSetB333_00437b60(void);
extern void TriBranchJmp_00434530(void);

/*
 * @addr 0x004344b0 (114b game) - 3-stage gated chain with two
 *   sub-decision branches: push 0x4e4a00 + call _0043a950; gate
 *   pause; call _0045e640; gate pause; if bit 0 clear jmp Thunk;
 *   else gate flag for 2; if matches, set walk=0x96, AudioVolume;
 *   gate pause; if bit 0 set jmp _00437b60 else jmp TriBranch.
 */
void TriStageChainGate_004344b0(void) {
    unsigned int v;
    ((void (*)(int))QuadBlockArgInstallChain_0043a950)(0x004e4a00);
    if (g_framePauseFlag != 0) return;
    PendingMatch_0045e640();
    if (g_framePauseFlag != 0) return;
    if ((g_state_0054208c & 1) == 0) {
        Thunk_004344a0();
        return;
    }
    v = g_x_0052aac4;
    g_walkCallback = (void (*)(void))v;
    if (v == 2) {
        FlagInitTableSelector_00434560();
        return;
    }
    g_walkCallback = (void (*)(void))0x96;
    AudioVolumeRescale_004ab690();
    if (g_framePauseFlag != 0) return;
    if ((g_state_0054208c & 1) == 0) {
        InstallSelfChainSetB333_00437b60();
        return;
    }
    TriBranchJmp_00434530();
}

extern void Phase4FourHelperChain_00413760(void);
extern void Vec2SumMul10ChainCompute_0049bc60(void);
extern void ScaledIndirectJmp_0049c850(void);
extern void Phase4FivePackedDispatch_0040fe40(void);
extern void PendingMatch_00498eb0(void);

/* @addr 0x00498df0 (180b game) - triple-entry 3-block dispatcher with Mul10Tail and pause-gated paths. */
extern unsigned int g_data_004d57ac_arr;
extern unsigned int g_data_004f3608;
extern unsigned int g_data_0052ab40;
extern unsigned int g_data_0052d750;
extern unsigned int g_data_0052d754;
extern unsigned int g_data_0052d758;
extern unsigned int g_data_00535e48;
extern unsigned int g_data_00537f04;
extern unsigned int g_data_0053a514;
extern unsigned int g_data_00542094;
extern unsigned int g_pause_00541e6c;
extern unsigned int g_x_00542048;
extern unsigned int g_x_0054204c;
extern unsigned int g_x_00542050;
extern unsigned int g_x_00542054;
extern unsigned int g_x_0054205c;
extern unsigned int g_x_0054206c;
extern unsigned int g_x_00542070;
extern unsigned int g_x_00542074;
extern unsigned int g_x_00542084;
extern unsigned int g_x_00543550;
extern void ArgSar_Set0_Jmp_0049c6f0(void);
extern void CallPauseDirtyMStackPushFn_0046e2a0(void);
extern void ChainListVecAdd_0049d200(void);
extern void ChainUnlinkPushFree_0049d150(void);
extern void ComboScriptDispatchCluster_00470530(void);
extern void DirtyTestScaledCmpJmp_0046ea70(void);
extern void DispatcherComplex197_0045be40(void);
extern void DispatcherComplex197_0045bf10(void);
extern void DualBlockInstallSelfWithSibling_00484c90(void);
extern void DualEntryRecursiveInstall_00471710(void);
extern void DualPushSetCallDualPop_00404b10(void);
extern void Eleven404b90_404c00_004266d0(void);
extern void EsiInstallDecCallChain_004294a0(void);
extern void FiveThunkMStackDispatcher_0046eac0(void);
extern void FourCallBitGateChain_004334d0(void);
extern void FramePauseScaledStore_00406c10(void);
extern void FsmPoseDualEntry_00472560(void);
extern void GuardedPackedSlotInit_00428760(void);
extern void GuardedSeq_00471670(void);
extern void InstallSelfBitGated_00428eb0(void);
extern void InstallSelfDualCountdown_00429050(void);
extern void InstallSelfIndexWalk_00450de0(void);
extern void InstallSelfMidPush_0045bd80(void);
extern void IterStepScaledStore_0048e600(void);
extern void MStackBracketedStoreTwoCall_004714e0(void);
extern void MStackCall_004062f0(void);
extern void MStackPushSet0008_004901a0(void);
extern void MoveListCursorCluster_0045b420(void);
extern void PauseTestCmp2CallStore_0045bfe0(void);
extern void PhaseDispatchListAdvance_004709e0(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void SaveCallRestoreOrXor_00404a00(void);
extern void ScaledAddrInit_004677c0(void);
extern void ScaledAddrInit_004677e0(void);
extern void ScaledAndAlfe_00490390(void);
extern void ScaledArrStore_00429960(void);
extern void ScaledChainJmp_00429470(void);
extern void ScaledClearJmp_00428d40(void);
extern void ScaledClearJmp_00428e90(void);
extern void ScaledLoadJmp_00428d20(void);
extern void ScaledMove74to70_0046eaa0(void);
extern void ScaledOrStore_004677a0(void);
extern void ScaledSaveCallRestoreJmp_00472f80(void);
extern void SlotEvent3EntryChain_0046fdf0(void);
extern void SwapOrPassSet_0048fbf0(void);
extern void Ten404c40_404bd0_00426780(void);
extern void TripleCallBitJmp_00471690(void);
extern void TripleCallPauseJmp_00470500(void);
extern void ZeroAndDirty4_00405430(void);

extern unsigned int g_const_0044d820;
extern unsigned int g_data_004d5300;
extern unsigned int g_data_004d5304;
extern unsigned int g_data_004d5308;
extern unsigned int g_data_004d530c;
extern unsigned int g_data_004d531c;
extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004e2868;
extern unsigned int g_data_004e51f8;
extern unsigned int g_data_004e6208;
extern unsigned int g_data_004e6218;
extern unsigned int g_data_004e6230;
extern unsigned int g_data_004e6408;
extern unsigned int g_data_004e6580;
extern unsigned int g_data_004e6590;
extern unsigned int g_data_004e65a0;
extern unsigned int g_data_004e65b8;
extern unsigned int g_data_004e65c8;
extern unsigned int g_data_004e6f50;
extern unsigned int g_data_004e6f60;
extern unsigned int g_data_004e6f68;
extern unsigned int g_data_004e6f80;
extern unsigned int g_data_004e7e48;
extern unsigned int g_data_004e7e58;
extern unsigned int g_data_004e7e80;
extern unsigned int g_data_004e7e90;
extern unsigned int g_data_004e7f40;
extern unsigned int g_data_004e7f50;
extern unsigned int g_data_004e7f60;
extern unsigned int g_data_004e7f70;
extern unsigned int g_data_004e8190;
extern unsigned int g_data_004eb1c8;
extern unsigned int g_data_004eb938;
extern unsigned int g_data_004eb958;
extern unsigned int g_data_004eb998;
extern unsigned int g_data_004eb9b0;
extern unsigned int g_data_004eba10;
extern unsigned int g_data_004ebbf8;
extern unsigned int g_data_004ebc38;
extern unsigned int g_data_004ec040;
extern unsigned int g_data_004ec050;
extern unsigned int g_data_004ec060;
extern unsigned int g_data_004ec078;
extern unsigned int g_data_004ec950;
extern unsigned int g_data_004ecc38;
extern unsigned int g_data_004ecf80;
extern unsigned int g_data_004ed2c8;
extern unsigned int g_data_004ed2f0;
extern unsigned int g_data_004ed2f8;
extern unsigned int g_data_004ed308;
extern unsigned int g_data_004ed3d0;
extern unsigned int g_data_004f29c0;
extern unsigned int g_data_005007c4;
extern unsigned int g_data_0050104c;
extern unsigned int g_data_00501070;
extern unsigned int g_data_00501088;
extern unsigned int g_data_005010c4;
extern unsigned int g_data_005010d0;
extern unsigned int g_data_0050122c;
extern unsigned int g_data_00501250;
extern unsigned int g_data_0050b604;
extern unsigned int g_data_005117c4;
extern unsigned int g_data_0052aac4;
extern unsigned int g_data_0052ab10;
extern unsigned int g_data_0052d724;
extern unsigned int g_data_00535d58;
extern unsigned int g_data_00535d60;
extern unsigned int g_data_00535d68;
extern unsigned int g_data_00535db0;
extern unsigned int g_data_00535e44;
extern unsigned int g_data_00535e4c;
extern unsigned int g_data_00535e6c;
extern unsigned int g_data_00537e88;
extern unsigned int g_data_00537e94;
extern unsigned int g_data_00537eec;
extern unsigned int g_data_00537ef0;
extern unsigned int g_data_00537f2c;
extern unsigned int g_data_00537f30;
extern unsigned int g_data_00537f48;
extern unsigned int g_data_00537f94;
extern unsigned int g_data_00538038;
extern unsigned int g_data_0053803c;
extern unsigned int g_data_005380e0;
extern unsigned int g_data_00538148;
extern unsigned int g_data_00538158;
extern unsigned int g_data_0053815c;
extern unsigned int g_data_00538160;
extern unsigned int g_data_00538164;
extern unsigned int g_data_0053a178;
extern unsigned int g_data_0053a1ac;
extern unsigned int g_data_0053a250;
extern unsigned int g_data_0053a2d0;
extern unsigned int g_data_0053a324;
extern unsigned int g_data_0053a328;
extern unsigned int g_data_0053a3c0;
extern unsigned int g_data_0053a408;
extern unsigned int g_data_0053a430;
extern unsigned int g_data_0053a464;
extern unsigned int g_data_0053a468;
extern unsigned int g_data_0053a51c;
extern unsigned int g_data_0053a6dc;
extern unsigned int g_data_0053a730;
extern unsigned int g_data_0053a7a0;
extern unsigned int g_data_0053a7a8;
extern unsigned int g_data_0053a7b4;
extern unsigned int g_data_0053e348;
extern unsigned int g_data_00541d68;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00541f98;
extern unsigned int g_data_00541fb0;
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542048;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_00542050;
extern unsigned int g_data_00542054;
extern unsigned int g_data_00542058;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_00542070;
extern unsigned int g_data_00542074;
extern unsigned int g_data_00542078;
extern unsigned int g_data_0054207c;
extern unsigned int g_data_00542080;
extern unsigned int g_data_00542084;
extern unsigned int g_data_00542088;
extern unsigned int g_data_0054208c;
extern unsigned int g_data_00542188;
extern unsigned int g_data_00542a58;
extern unsigned int g_data_00542b68;
extern unsigned int g_data_005433e8;
extern unsigned int g_data_005433ec;
extern unsigned int g_data_0054356c;
extern unsigned int g_data_00543590;
extern unsigned int g_data_00543714;
extern unsigned int g_data_0054371c;
extern unsigned int g_data_00543728;
extern unsigned int g_data_0054388c;
extern unsigned int g_data_00543890;
extern unsigned int g_state_004d57ac;
extern void AiAngleDistComputation_00431920(void);
extern void AmbientMonitorCluster_0049e3c0(void);
extern void AndStorePushCallZero_0048a220(void);
extern void ArgSarStoreJmp_004594f0(void);
extern void AudioInstallSelfStatePush_004aa8a0(void);
extern void AudioMixerStep_004ab700(void);
extern void AudioVolumeRescale_004ab690(void);
extern void BootChainBidirRecurseWalk_00405ca0(void);
extern void BootFrameSetup_00408190(void);
extern void BootInitGuardedCallChain_004265d0(void);
extern void BootMStackBracket3SubdispatchPair_00407920(void);
extern void CallDirty4DualJmp_00470f30(void);
extern void CallDualStoreXorBit_004285e0(void);
extern void CallPauseClear3CallTriple_00428030(void);
extern void CallPauseDirtyPushCall_00488ba0(void);
extern void CallPauseScaledByteSet_0043c350(void);
extern void CallPauseScaledStoreCopyJmp_00461220(void);
extern void CallPauseTripleScaledJmp_0046c520(void);
extern void CallSetPause_0041f830(void);
extern void CameraAimSplineDriver_00430e60(void);
extern void CameraZoomFsmCluster_00440aa0(void);
extern void Cascade3ChainInit_0048fa50(void);
extern void Chain2AxisDiffStoreTailJmp_0044cad0(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void ChainGatedNegAccum_0048b740(void);
extern void ChainWalkPushPop_00405a40(void);
extern void CjFieldCopyCascade_0044c430(void);
extern void CjInstallSelfRouter_00470480(void);
extern void ClearBit2x34_00490130(void);
extern void Cmp9DirtyToggle_00464320(void);
extern void ComboMoveSelectFsmCluster_0045a2c0(void);
extern void CondPlayerLookup_004ac120(void);
extern void CopyGlobal_004ac1f0(void);
extern void CopyJmp_00406ba0(void);
extern void CopyJmp_00445ec0(void);
extern void CopyJmp_0048ef90(void);
extern void CopyLoadInstallJmp_00445ed0(void);
extern void CopyScaledTriple_00446120(void);
extern void CopyThreeFields_00404df0(void);
extern void DirtyDoubleDeref_00408cb0(void);
extern void DirtyToggleByGate_0048f350(void);
extern void DispatchOrInitFightGroup_0042f850(void);
extern void DispatcherComplex138_00476060(void);
extern void DispatcherComplex260_00407030(void);
extern void DoubleCallChainInit_0043d780(void);
extern void DoublePushScaledInitJmp_00444db0(void);
extern void DoubleScaledCrossStore_00475750(void);
extern void DualBitGateInitCall_0048a1c0(void);
extern void DualBlockChainInitBody_0043cc10(void);
extern void DualCmpSwapStore_0049c5a0(void);
extern void DualEntryInitDispatch_00431360(void);
extern void DualPushAddCallDualPopJmp_0044cc50(void);
extern void DualPushSet7bCallPop_00474310(void);
extern void DualScaledLoadStoreJmp_00475790(void);
extern void DualScaledStore_00452740(void);
extern void DualSlotCopyChain_004756f0(void);
extern void DualSlotPropagateCall_004683e0(void);
extern void DualTestDirtyToggle_00427ea0(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void DualWalkRange_00468440(void);
extern void EntryThunkBodyStateMachine_00457bb0(void);
extern void EsiEdiAliasDualMul10_004906b0(void);
extern void EsiInstallChainCmpDualCall_00429300(void);
extern void EsiInstallSetCbChainExtend_0048a970(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void FourConstCallLitCallJmp_0047ff20(void);
extern void FourFieldCopyCallSet_00446040(void);
extern void GDispatch4_004089c0(void);
extern void GameInstall2BodyMul10ScaledInit_00475590(void);
extern void GateDispatch6c_00494580(void);
extern void GatedWordPushCall_00489f90(void);
extern void GuardedBitMaskFlagOrClear_0048c510(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void GuardedCmpDualToggle_0049e360(void);
extern void GuardedDirtyXformFromTable_0048f6d0(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void GuardedDualScaledChainCopy_0044dd00(void);
extern void GuardedScaled_00475000(void);
extern void GuardedScaled_00475060(void);
extern void GuardedScaled_00475090(void);
extern void GuardedSeq_00472820(void);
extern void GuardedSeq_00472840(void);
extern void GuardedSeq_00473f10(void);
extern void GuardedSeq_00473f50(void);
extern void GuardedSeq_00476de0(void);
extern void GuardedSeq_00476f10(void);
extern void GuardedTripleSetTailJmp8_0044a500(void);
extern void Helper_TickAlt(void);
extern void HitReactionDispatcher_0045f650(void);
extern void Init0AndMax_00401370(void);
extern void Init6Struct_00404e20(void);
extern void InitStateDualCall48ac70_0048ac70(void);
extern void InitZeroSixFields_00445f40(void);
extern void InstallSelf3WayChainCmp_00428d80(void);
extern void InstallSelfAccumOverflow_00428b20(void);
extern void InstallSelfBootInit_00462980(void);
extern void InstallSelfChainAccumPath_004752b0(void);
extern void InstallSelfCmpJlJmp_00480b20(void);
extern void InstallSelfDispatch_00407620(void);
extern void InstallSelfIndirectJmp_0048f3f0(void);
extern void InstallSelfMStackPush_0041aaf0(void);
extern void InstallSelfMultiThunkDispatch_0046c3d0(void);
extern void InstallSelfPackedTailJmp_004751f0(void);
extern void IntroFsmCluster_0044d580(void);
extern void IntroInitCluster_0044d280(void);
extern void IntroSequencePipeline_0044cd50(void);
extern void LoadSetFpJmp_004093a0(void);
extern void MStackBracket5_FieldClear_StateAdvance_00405630(void);
extern void MStackBracket6_DualGate_004788e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackCall_00406340(void);
extern void MStackCall_00406390(void);
extern void MStackCall_00406600(void);
extern void MStackCall_00406740(void);
extern void MStackDirtyArgsBit0_0049fa50(void);
extern void MStackPop8_004ab860(void);
extern void MStackPush1MagicMod2_004244d0(void);
extern void MStackPush2BiasResolveChain_0048cca0(void);
extern void MStackPush2BitLoop_00476670(void);
extern void MStackPush2ChainPrepend_00409970(void);
extern void MStackPush2GlobalSwap_00477400(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void MStackPush3SideStore_0044cb80(void);
extern void MStackPush4LLWalkPop4_004090e0(void);
extern void MStackPush8_004ab790(void);
extern void MStackPushDispatchBitGate_00407330(void);
extern void MStackPushSet0001_00490260(void);
extern void MStackPushSet0004_00490230(void);
extern void MStackPushSet0020_004901d0(void);
extern void MStackPushSet0040_00490200(void);
extern void MStackPushSet0200_00490140(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void MStackVecSetupScopedRun_004749a0(void);
extern void ModuloMagic_0042afc0(void);
extern void Mul10SumStoreNegCommit_00490970(void);
extern void Mul10Tail_00404af0(void);
extern void NetEntityScanAndPunish_00474b50(void);
extern void PendingMatch_00420300(void);
extern void PendingMatch_00429ef0(void);
extern void PendingMatch_0042d240(void);
extern void PendingMatch_00432110(void);
extern void PendingMatch_004326a0(void);
extern void PendingMatch_0043c400(void);
extern void PendingMatch_0043d830(void);
extern void PendingMatch_004411d0(void);
extern void PendingMatch_00443320(void);
extern void PendingMatch_00443d20(void);
extern void PendingMatch_00444ef0(void);
extern void PendingMatch_00447000(void);
extern void PendingMatch_00447a90(void);
extern void PendingMatch_004492f0(void);
extern void PendingMatch_0044a7f0(void);
extern void PendingMatch_0044c530(void);
extern void PendingMatch_0044d7a0(void);
extern void PendingMatch_0044dd80(void);
extern void PendingMatch_0044f8d0(void);
extern void PendingMatch_0044fe90(void);
extern void PendingMatch_00452770(void);
extern void PendingMatch_00453e70(void);
extern void PendingMatch_00454510(void);
extern void PendingMatch_00455bd0(void);
extern void PendingMatch_004568b0(void);
extern void PendingMatch_00459510(void);
extern void PendingMatch_0045a5c0(void);
extern void PendingMatch_0045c8e0(void);
extern void PendingMatch_00461ca0(void);
extern void PendingMatch_00462a90(void);
extern void PendingMatch_004668b0(void);
extern void PendingMatch_004685d0(void);
extern void PendingMatch_004694b0(void);
extern void PendingMatch_00469b40(void);
extern void PendingMatch_0046a6e0(void);
extern void PendingMatch_0046ad20(void);
extern void PendingMatch_0046b670(void);
extern void PendingMatch_00473640(void);
extern void PendingMatch_00478da0(void);
extern void PendingMatch_0047cf60(void);
extern void PendingMatch_00484da0(void);
extern void PendingMatch_0048c570(void);
extern void PendingMatch_0048d7b0(void);
extern void PendingMatch_0049a670(void);
extern void Phase4TrampolineThreePacked_0040fa20(void);
extern void PhaseClampInstallSlot_0049e1c0(void);
extern void PoseChainAdvanceCluster_0044ef50(void);
extern void PoseFsmTriHelpers_00431650(void);
extern void Push16Call_00489f50(void);
extern void PushBitFieldMergePop_0048bae0(void);
extern void PushCallPauseSetMaxThenCallPauseJmp_0048e380(void);
extern void PushCallPopScaledJmpIndirect_0048ce00(void);
extern void PushClampZeroOneCallPop_00478d00(void);
extern void PushImmCallSetCallAdjustCall_00446bf0(void);
extern void PushPopCurrentSetFFFFFFFF_00473070(void);
extern void PushPopScaled1cDoubleCall_00408510(void);
extern void PushPopScaledInit343c_004aa940(void);
extern void PushSetCallCleanup_00408580(void);
extern void QuadCallPhase2_004be800(void);
extern void QuadMul10TailFpuChain_00431120(void);
extern void RoundCleanupCluster_00427690(void);
extern void RoundEndFsm_0042b2f0(void);
extern void ScaledAndAh_004902d0(void);
extern void ScaledAndAl7f_004902f0(void);
extern void ScaledAndAlbf_00490350(void);
extern void ScaledArrStore_00429980(void);
extern void ScaledChain3c74_0048f910(void);
extern void ScaledChainAndF000DirtyToggle_0048e740(void);
extern void ScaledChainCmpDispatch_0048e4f0(void);
extern void ScaledChainTwoStores_00480d20(void);
extern void ScaledClearJmp_00428d60(void);
extern void ScaledDecBranch_00466770(void);
extern void ScaledIdxLoadCallTailThunk_00472db0(void);
extern void ScaledIndexConditionalAdd_0048e400(void);
extern void ScaledInitPauseDirtyStore_00445f00(void);
extern void ScaledInitWithCounterAndType_004314f0(void);
extern void ScaledInit_0048d430(void);
extern void ScaledInit_0048f720(void);
extern void ScaledIterStep_0045c020(void);
extern void ScaledLitLoadCall_00480fe0(void);
extern void ScaledLitLoadCall_00481020(void);
extern void ScaledLoadCmp0fJmp_004930e0(void);
extern void ScaledLoadIncJmp_00428d00(void);
extern void ScaledLoadJmp_00429390(void);
extern void ScaledMove48to58_00490720(void);
extern void ScaledOrAh8CallPauseJmp_0048d0c0(void);
extern void ScaledShrAnd_0048bb40(void);
extern void ScaledStackCallPause_0049c360(void);
extern void ScaledStoreOrFlagXor_00428560(void);
extern void ScaledStoreThree_00409260(void);
extern void ScaledTestPauseStore_00408860(void);
extern void ScaledXorStore_004903b0(void);
extern void ScaledZero44_00491500(void);
extern void ScaledZeroFour_00490740(void);
extern void ScenegraphWalk_0041f7d0(void);
extern void Set2CallIncJmp_00472860(void);
extern void SetJmp_00405420(void);
extern void SetJmp_00429950(void);
extern void SetJmp_004753a0(void);
extern void SetWalk0xaCrossStore_00445fb0(void);
extern void SetWalkCurCallPauseDirty_00404c70(void);
extern void SevenThunks_0047cc50(void);
extern void SlideAttackEventCluster_00498900(void);
extern void SlotPhaseResetInstallChain_0048e0e0(void);
extern void SpecialInitDirtyJmp_00446000(void);
extern void StackPopDispatchTagged_0041f780(void);
extern void StoreDoubleNegPauseSubStore_004ab750(void);
extern void StoreLoadJmp_00404ef0(void);
extern void StorePauseImulShr16_004ab630(void);
extern void StoreTwoCall_0049cb40(void);
extern void TableHitOrSchedule_004be7a0(void);
extern void TableLookupCall_00489ff0(void);
extern void TableLookupCall_0048a130(void);
extern void TableWalkBoundedCmp_004bd890(void);
extern void TagDispatchPairedPacked_004667f0(void);
extern void TaggedSceneDispatch_004be690(void);
extern void ThreeCallChainCopy_004409e0(void);
extern void ThreeChanPackClamp_00404cc0(void);
extern void ThrowAnimTriggerCluster_0049efa0(void);
extern void Thunk_0049cbc0(void);
extern void Thunk_0049cc00(void);
extern void TriCmpOrFinal_0043c390(void);
extern void TripleBranchInstall_004283b0(void);
extern void TripleSetCallPauseDirtyJmp_00446150(void);
extern void TripleSubVec3_004250f0(void);
extern void TwinLoopSlotFinder_00429a40(void);
extern void TwinMStackPushScaledChain_00422110(void);
extern void TwoCallJmp_00478120(void);
extern void TwoPhaseInstallScaledPackedPtr_00480d50(void);
extern void Vec2ChainComputeStores_00480b80(void);
extern void WorldCellSetupCluster_0042b000(void);
extern void Wrapper_00484d90(void);

__declspec(naked) void TripleEntry3Block_00498df0(void) {
    __asm {
        mov     ecx, dword ptr [g_x_00542084]
        mov     eax, dword ptr [g_scaledInit_00542044]
        push    esi
        push    ecx
        push    0x00003333
        lea     esi, [eax*4 + 0]
        call    Mul10Tail_00404af0
        mov     edx, dword ptr [g_state_00542088]
        add     esp, 8
        mov     dword ptr [g_x_00542084], eax
        push    edx
        push    0x00003333
        call    Mul10Tail_00404af0
        mov     dword ptr [g_state_00542088], eax
        mov     eax, dword ptr [g_x_00542084]
        mov     dword ptr [esi + 0x6c], eax
        mov     ecx, dword ptr [g_state_00542088]
        add     esp, 8
        mov     dword ptr [esi + 0x74], ecx
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_x_0054205c], edx
        pop     esi
        ret
        _emit   90h
        _emit   90h
        mov     eax, dword ptr [g_data_0053a498]
        test    al, 1
        mov     dword ptr [g_x_0054206c], eax
        _emit   75h
        _emit   0eh
        call    Phase4FourHelperChain_00413760
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   22h
        call    Vec2SumMul10ChainCompute_0049bc60
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   14h
        mov     eax, dword ptr [g_x_00542070]
        mov     ecx, dword ptr [g_x_00542074]
        cmp     eax, ecx
        _emit   7eh
        _emit   05h
        jmp     ScaledIndirectJmp_0049c850
        ret
        _emit   90h
        call    Phase4FivePackedDispatch_0040fe40
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     PendingMatch_00498eb0
        ret
    }
}


/* @addr 0x0043a550 (194b game) - jump table with multi-entry chain for switch.
 *   A: eax = (arg0>>2 + g_x_0054206c); scaledInit = eax; eax = [eax*4 + 0];
 *     scaledInit = eax; jmp eax (indirect call to handler).
 *   B/C/D/E/F (+0x30/+0x50/+0x70/+0x90/+0xb0): set scaledInit = (table_addr_n>>2); jmp PendingMatch_0048d7b0.
 */
__declspec(naked) void JumpTableDispatch_0043a550(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, dword ptr [g_x_0054206c]
        sar     eax, 2
        add     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     eax
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     eax, 0x00542ea8
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     PendingMatch_0048d7b0
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     eax, 0x00542ef8
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     PendingMatch_0048d7b0
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     eax, 0x00542e48
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     PendingMatch_0048d7b0
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     eax, 0x00542d00
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     PendingMatch_0048d7b0
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     eax, 0x00542db8
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     PendingMatch_0048d7b0
    }
}


/* @addr 0x00444e00 (226b game) - mstack-push g_scaledInit + g_x_00542074; 3-stage AudioVolumeRescale
 *   cascade with bit-0 tests selecting different shifted-pointer values for tail-jmp to PendingMatch_00444ef0.
 *   Values: 0x004e5df8/0x004e5dc8/0x004e5d90/0x004e5d58 (all >>2 to g_x_0054206c).
 */
__declspec(naked) void MStackPush2VolumeCascade_00444e00(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + g_data_004d57ac_arr], ecx
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [g_x_00542074]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + g_data_004d57ac_arr], edx
        mov     dword ptr [g_x_0054206c], 0x64
        call    AudioVolumeRescale_004ab690
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   95h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_state_0054208c], 1
        _emit   75h
        _emit   12h
        mov     eax, 0x004e5df8
        shr     eax, 2
        mov     dword ptr [g_x_0054206c], eax
        jmp     PendingMatch_00444ef0
        mov     dword ptr [g_x_0054206c], 0x0000015e
        call    AudioVolumeRescale_004ab690
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   62h
        test    byte ptr [g_state_0054208c], 1
        _emit   75h
        _emit   47h
        mov     dword ptr [g_x_0054206c], 0x00000200
        call    AudioVolumeRescale_004ab690
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   41h
        test    byte ptr [g_state_0054208c], 1
        _emit   75h
        _emit   13h
        mov     ecx, 0x004e5dc8
        shr     ecx, 2
        mov     dword ptr [g_x_0054206c], ecx
        jmp     PendingMatch_00444ef0
        mov     edx, 0x004e5d90
        shr     edx, 2
        mov     dword ptr [g_x_0054206c], edx
        jmp     PendingMatch_00444ef0
        mov     eax, 0x004e5d58
        shr     eax, 2
        mov     dword ptr [g_x_0054206c], eax
        jmp     PendingMatch_00444ef0
        ret
    }
}


/* @addr 0x00462470 (230b game) - install-self with full chain init.
 *   chain[+0x84]!=0 path: call StackPopDispatchTagged; pop+ret.
 *   chain[+0x84]==0 path: chain[*4+0x30]=0x8c, chain[*4+0x34]=0; chain at [esi+0x38..0x48] populated from
 *   g_load_0052ab10 fields (+0x60, 0, +0x68); install-self at +0x08=0x00462470 with scaledInit-chain push;
 *   call PendingMatch_00432110; g_pause=1; pop+ret.
 */
__declspec(naked) void InstallSelfFullChainInit_00462470(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        xor     esi, esi
        lea     ecx, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [ecx + 0x84], esi
        cmp     eax, esi
        _emit   74h
        _emit   07h
        call    StackPopDispatchTagged_0041f780
        pop     esi
        ret
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [edx*4 + 0x30], 0x0000008c
        push    edi
        lea     eax, [edx*4 + 0]
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [edx*4 + 0x34], esi
        mov     edx, 0xfff5cccd
        mov     dword ptr [eax + 0x38], 0xfffe0000
        mov     dword ptr [g_x_0054206c], edx
        mov     dword ptr [eax + 0x3c], edx
        mov     edx, dword ptr [g_load_0052ab10]
        mov     dword ptr [g_x_0054205c], edx
        shl     edx, 2
        mov     edi, dword ptr [edx + 0x60]
        mov     dword ptr [eax + 0x40], edi
        mov     dword ptr [g_x_0054206c], esi
        mov     dword ptr [eax + 0x44], esi
        mov     edx, dword ptr [edx + 0x68]
        mov     dword ptr [g_x_0054206c], edx
        mov     dword ptr [eax + 0x48], edx
        mov     dword ptr [ecx + 0x08], 0x00462470
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     edi, 1
        mov     edx, 0x00462470
        mov     dword ptr [eax*4 + 0x84], edi
        mov     eax, dword ptr [ecx + 4]
        add     edx, 0x01000000
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     eax, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [ecx + 4], eax
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x84], esi
        call    PendingMatch_00432110
        mov     dword ptr [g_pause_00541e6c], edi
        pop     edi
        pop     esi
        ret
    }
}


extern void DrainQueueCallEach_004a1ec0(void);
/* @addr 0x004265d0 (249b game) - boot-style init sequence then guarded call chain.
 *   8 setup calls (DrainQueueCallEach_004a1ec0, PendingMatch_0045c8e0, Init0AndMax_00401370,
 *     g_x_0054206c=0, CopyGlobal_004ac1f0, Init6Struct_00404e20, ScenegraphWalk_0041f7d0,
 *     CallPauseClear3CallTriple_00428030). If pause? ret.
 *   mstack-push 3 (0, g_x_00542070, g_x_00542074); clear g_state_0053a7b0;
 *   call SlideAttackEventCluster_00498900; if pause? ret. call AndStorePushCallZero_0048a220; if pause? ret.
 *   mstack-pop 3 into g_x_00542074, g_x_00542070, g_x_0054206c.
 *   set g_x_00543550 = 0x100; ret.
 */
void BootInitGuardedCallChain_004265d0(void) {
    __asm {
        call    DrainQueueCallEach_004a1ec0
        call    PendingMatch_0045c8e0
        call    Init0AndMax_00401370
        mov     dword ptr [g_x_0054206c], 0
        call    CopyGlobal_004ac1f0
        call    Init6Struct_00404e20
        call    ScenegraphWalk_0041f7d0
        call    CallPauseClear3CallTriple_00428030
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0beh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     dword ptr [g_x_0054206c], 0
        inc     eax
        mov     dword ptr [g_state_0053a7b0], 0
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], 0
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_x_00542070]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [g_x_00542074]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + 0], edx
        call    SlideAttackEventCluster_00498900
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   56h
        call    AndStorePushCallZero_0048a220
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   48h
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_x_00542074], ecx
        mov     dword ptr [g_state_004d57ac], eax
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_x_00542070], edx
        mov     dword ptr [g_state_004d57ac], eax
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_x_0054206c], ecx
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [g_x_00543550], 0x100
        }
}


/* @addr 0x00484b70 (284b game) - 5 adjacent dispatch blocks.
 *   B1 (0..0x24, +11 NOPs): mstack-push 0x00470480 with g_x_0054206c=2; tail-jmp
 *     MstackPopScaledChainPlusThunks_00471250.
 *   B2 (0x30..0x4b, +4 NOPs): call ScaledAndAl7f_004902f0; if !pause: push 0x004ee8f8,
 *     tail-call ArgSarStoreJmp.
 *   B3 (0x50..0xa4, +11 NOPs): g_x_00542048 = 0x00500698>>2; 4-call chain
 *     (BootFrameSetup_00408190, GuardedChainCmpDualBitXor, ScaledXorStore, GateDispatch6c);
 *     if all !pause: tail-jmp CallPauseDirtyPushCall_00488ba0.
 *   B4 (0xb0..0xe7, +8 NOPs): call GateDispatch6c; if !pause: call CopyJmp_0048ef90;
 *     if !pause and bit0 of state set: tail-jmp PendingMatch_00484da0; else: push 0x004ee920,
 *     tail-call ArgSarStoreJmp.
 *   B5 (0xf0..0x11b): call DirtyToggleByGate; if !pause and bit2 of state clear:
 *     tail-jmp Wrapper_00484d90; else g_state_00542080=0xd and tail-jmp
 *     DualBlockInstallSelfWithSibling_00484c90.
 */
__declspec(naked) void FiveBlockDispatchChain_00484b70(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     dword ptr [g_x_0054206c], 2
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        _emit   0c7h
        _emit   04h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   80h
        _emit   04h
        _emit   47h
        _emit   00h
        jmp     MstackPopScaledChainPlusThunks_00471250
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
        call    ScaledAndAl7f_004902f0
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004ee8f8
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        ret
        nop
        nop
        nop
        nop
        mov     eax, 0x00500698
        mov     dword ptr [g_x_0054206c], 0
        shr     eax, 2
        mov     dword ptr [g_x_00542048], eax
        call    BootFrameSetup_00408190
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   2fh
        call    GuardedChainCmpDualBitXor_004299a0
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   21h
        call    ScaledXorStore_004903b0
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    GateDispatch6c_00494580
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     CallPauseDirtyPushCall_00488ba0
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
        call    GateDispatch6c_00494580
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   29h
        call    CopyJmp_0048ef90
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   1bh
        test    byte ptr [g_state_0054208c], 1
        _emit   74h
        _emit   05h
        jmp     PendingMatch_00484da0
        push    0x004ee920
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        call    DirtyToggleByGate_0048f350
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   1dh
        test    byte ptr [g_state_0054208c], 4
        _emit   75h
        _emit   05h
        jmp     Wrapper_00484d90
        mov     dword ptr [g_state_00542080], 0x0d
        jmp     DualBlockInstallSelfWithSibling_00484c90
        ret
    }
}


/* @addr 0x0043a830 (286b game) - scaled-step + threshold cmp + install-self.
 *   Load idx=g_baseSel_00542060; entry=ecx=*idx*4; state=[idx*4+0x84]; clear state.
 *   state==0: clear-and-init path; copy [idx*4+0x58], [g_acc_00542078]; fall to install.
 *   state!=0: bump [g_x_00542054*4 + 0x70] by 0x3d7; compare with [g_baseSel*4 + 0x5c].
 *     if eax<edx: jump to install (state stays 1).
 *     else: clear scaledInit fields; tail-call StackPopDispatchTagged_0041f780.
 *   install: state=1; [ecx+8]=self; g_x_0054204c=1; g_pause=1; ret.
 */
__declspec(naked) void InstallSelfScaledAdv3d7Cmp_0043a830(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     ecx, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [ecx + 0x84], 0
        test    eax, eax
        je      case0
        mov     edx, dword ptr [g_x_00542054]
        mov     eax, dword ptr [edx*4 + 0x70]
        add     eax, 0x3d7
        mov     dword ptr [g_x_0054206c], eax
        mov     dword ptr [edx*4 + 0x70], eax
        mov     esi, dword ptr [g_x_00542054]
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [esi*4 + 0x58]
        mov     dword ptr [g_x_0054206c], eax
        mov     edx, dword ptr [edx*4 + 0x5c]
        cmp     eax, edx
        mov     dword ptr [g_data_00542070], edx
        jl      install
        mov     dword ptr [g_x_0054206c], 0
        mov     dword ptr [esi*4 + 0x6c], 0
        mov     ecx, dword ptr [g_x_00542054]
        mov     eax, dword ptr [g_x_0054206c]
        mov     dword ptr [ecx*4 + 0x70], eax
        mov     eax, dword ptr [g_x_00542054]
        mov     edx, dword ptr [g_x_0054206c]
        mov     dword ptr [eax*4 + 0x74], edx
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     edx, dword ptr [g_x_00542054]
        mov     eax, dword ptr [ecx*4 + 0x5c]
        mov     dword ptr [g_x_0054206c], eax
        mov     dword ptr [edx*4 + 0x58], eax
        call    StackPopDispatchTagged_0041f780
        pop     esi
        ret
    case0:
        mov     eax, dword ptr [g_x_00542054]
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_x_0054206c], eax
        mov     dword ptr [edx*4 + 0x5c], eax
        mov     eax, dword ptr [g_x_00542054]
        mov     edx, dword ptr [g_acc_00542078]
        mov     dword ptr [eax*4 + 0x70], edx
    install:
        mov     eax, 1
        mov     dword ptr [ecx + 8], offset InstallSelfScaledAdv3d7Cmp_0043a830
        mov     dword ptr [ecx + 0x84], eax
        mov     dword ptr [g_x_0054204c], eax
        mov     dword ptr [g_pause_00541e6c], eax
        pop     esi
        ret
    }
}


/* @addr 0x0049a4e0 (312b game) - dual-block: install-self entry + sibling-tail with Mul10 chain.
 *   Entry (0..0x96): load state; clear. state!=0: tail-jmp FiveCallGuardSetTail.
 *     state==0: g_x_0054206c=0x1016; chain[baseSel*4+0x74]=0x1016; install-self at entry+0x01000000.
 *     state=1; call ScaledLoadJmp; pause=1; pop esi/edi; ret.
 *   Tail (+0xa0): call PendingMatch_0049a670; if pause ret.
 *     Mul10Tail(0x3333, g_x_00542084)->[g_x_00542084 + scaledInit chain offset +0x6c].
 *     Mul10Tail(0x3333, g_state_00542088)->chain[+0x74].
 *     g_cj=scaledInit; push 0x23fb23; call ThreeChanPackClamp; push g_cj; call CopyThreeFields;
 *     push 0x004f2410; call ArgSar_Set0_Jmp; pop+ret.
 */
__declspec(naked) void DualBlockInstallMul10Tail_0049a4e0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        xor     edx, edx
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   74h
        _emit   05h
        jmp     FiveCallGuardSetTail_0046f6b0
        push    edi
        push    esi
        mov     esi, dword ptr [g_baseSel_00542060]
        mov     ecx, 0x1016
        mov     dword ptr [g_x_0054206c], ecx
        mov     edi, offset DualBlockInstallMul10Tail_0049a4e0
        mov     dword ptr [esi*4 + 0x74], ecx
        mov     dword ptr [eax + 8], offset DualBlockInstallMul10Tail_0049a4e0
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     esi, 1
        add     edi, 0x01000000
        mov     dword ptr [ecx*4 + 0x84], esi
        mov     ecx, dword ptr [eax + 4]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [ecx*4 + 0], edi
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x84], edx
        call    ScaledLoadJmp_00428d20
        mov     dword ptr [g_pause_00541e6c], esi
        pop     esi
        pop     edi
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    PendingMatch_0049a670
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_x_00542084]
        mov     eax, dword ptr [g_scaledInit_00542044]
        push    esi
        push    ecx
        push    0x3333
        lea     esi, [eax*4 + 0]
        call    Mul10Tail_00404af0
        mov     edx, dword ptr [g_state_00542088]
        add     esp, 8
        mov     dword ptr [g_x_00542084], eax
        push    edx
        push    0x3333
        call    Mul10Tail_00404af0
        mov     dword ptr [g_state_00542088], eax
        mov     eax, dword ptr [g_x_00542084]
        mov     dword ptr [esi + 0x6c], eax
        mov     ecx, dword ptr [g_state_00542088]
        add     esp, 8
        mov     dword ptr [esi + 0x74], ecx
        mov     edx, dword ptr [g_scaledInit_00542044]
        push    0x23fb23
        mov     dword ptr [g_cj_0054205c], edx
        call    ThreeChanPackClamp_00404cc0
        mov     eax, dword ptr [g_cj_0054205c]
        add     esp, 4
        push    eax
        call    CopyThreeFields_00404df0
        add     esp, 4
        push    0x004f2410
        call    ArgSar_Set0_Jmp_0049c6f0
        add     esp, 4
        pop     esi
        ret
    }
}


/* @addr 0x0045a180 (313b game) - dual-entry: mstack-push prefix + state-machine body.
 *   Prefix (0..0x1f): mstack-push body addr (0x0045a1a0); tail-jmp ComboMoveSelectFsmCluster_0045a2c0.
 *   Body (+0x20): load state. state==0: tail block; state!=0: dual-call sequence:
 *     Call ScaledStoreOrFlagXor; if pause ret. If bit2(0054208c): tail-call PendingMatch_00459510, ret.
 *     Dec g_state_00542080; if 0: tail-call PendingMatch_00459510, ret.
 *     Call ScaledStoreOrFlagXor again; if pause ret. Same bit2 + counter sequence.
 *     Then recursive tail-call self (prefix entry); ret.
 *   Tail block (state==0): g_data_00542070=g_x_0054206c+1; cmp with chain[scaledInit*4+4].
 *     If equal: mstack-push PendingMatch_00459510 addr; tail-call ComboMoveSelectFsmCluster_0045a2c0; ret.
 *     Else: g_x_00542054=[g_cj*4+0x24]; g_x_0054206c=0x8000; call MStackPushZeroCallPop;
 *       if pause ret. Install-self at body; state=1; g_x_0054204c=1; pause=1; ret.
 */
__declspec(naked) void DualEntryStateMachine_0045a180(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     [eax*4 + g_data_004d57ac_arr], offset body_1a0
        jmp     ComboMoveSelectFsmCluster_0045a2c0
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
    body_1a0:
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   73h
        call    ScaledStoreOrFlagXor_00428560
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0e3h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_state_0054208c], 4
        _emit   74h
        _emit   07h
        call    PendingMatch_00459510
        pop     esi
        ret
        mov     eax, dword ptr [g_state_00542080]
        dec     eax
        mov     dword ptr [g_state_00542080], eax
        _emit   75h
        _emit   07h
        call    PendingMatch_00459510
        pop     esi
        ret
        call    ScaledStoreOrFlagXor_00428560
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0adh
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_state_0054208c], 4
        _emit   74h
        _emit   07h
        call    PendingMatch_00459510
        pop     esi
        ret
        mov     eax, dword ptr [g_state_00542080]
        dec     eax
        mov     dword ptr [g_state_00542080], eax
        _emit   75h
        _emit   07h
        call    PendingMatch_00459510
        pop     esi
        ret
        call    DualEntryStateMachine_0045a180
        pop     esi
        ret
        mov     ecx, dword ptr [g_x_0054206c]
        mov     edx, dword ptr [g_scaledInit_00542044]
        lea     eax, [ecx + 1]
        mov     dword ptr [g_data_00542070], eax
        mov     ecx, dword ptr [edx*4 + 4]
        cmp     eax, ecx
        _emit   75h
        _emit   1dh
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     [eax*4 + g_data_004d57ac_arr], offset PendingMatch_00459510
        call    ComboMoveSelectFsmCluster_0045a2c0
        pop     esi
        ret
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_x_0054206c], 0x8000
        mov     dword ptr [g_x_00542054], ecx
        call    MStackPushZeroCallPop_00407d00
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   1ch
        mov     eax, 1
        mov     dword ptr [esi + 8], offset body_1a0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_x_0054204c], eax
        mov     dword ptr [g_pause_00541e6c], eax
        pop     esi
        ret
    }
}

extern int  GuardedCallStoreSlotsCmp_00440990(void);

/* @addr 0x004431e0 (316b game) - mstack-push + 3-call chain + bit2-gate + nested mstack-push + last-call sequence.
 *   Push g_x_00542054 onto mstack. g_cj=g_x_00542054. Load chain[g_x_00542050*4]->g_x_0054206c.
 *   Call GuardedCallStoreSlotsCmp; if pause ret. If bit2(0054208c): jmp set_bit2_pop.
 *   Call GDispatch4; if pause ret. Same bit2 check.
 *   Call ThreeCallChainCopy; if pause ret. g_data_00542070=0.
 *   If [g_scaledInit*4+0x18]==0: set bit2, restore g_x_00542054 from [stack-1+4], pop mstack; ret.
 *   Else: push g_x_00542074. Call CameraZoomFsmCluster_00440aa0; if pause ret. Pop g_x_00542074 and g_x_00542054 from mstack.
 *   Call PendingMatch_00443320; if pause ret. Clear bit2: g_x_0054206c=1; and al, 0xfb. ret.
 */
void MStackPush3CallChainBit2_004431e0(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_x_00542054]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     [eax*4 + g_data_004d57ac_arr], ecx
        mov     edx, dword ptr [g_x_00542054]
        mov     eax, dword ptr [g_x_00542050]
        mov     dword ptr [g_cj_0054205c], edx
        mov     ecx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_x_0054206c], ecx
        call    GuardedCallStoreSlotsCmp_00440990
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0f3h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_state_0054208c], 4
        _emit   75h
        _emit   4dh
        call    GDispatch4_004089c0
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d8h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_state_0054208c], 4
        _emit   75h
        _emit   32h
        call    ThreeCallChainCopy_004409e0
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0bdh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_data_00542070], 0
        mov     eax, dword ptr [edx*4 + 0x18]
        test    eax, eax
        mov     dword ptr [g_x_0054206c], eax
        _emit   75h
        _emit   28h
        mov     edx, dword ptr [g_state_0054208c]
        mov     eax, dword ptr [g_state_004d57ac]
        or      edx, 4
        dec     eax
        mov     dword ptr [g_state_0054208c], edx
        mov     ecx, dword ptr [eax*4 + 4]
        mov     dword ptr [g_x_00542054], ecx
        mov     dword ptr [g_state_004d57ac], eax
        ret
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [g_x_00542074]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     [eax*4 + g_data_004d57ac_arr], edx
        call    CameraZoomFsmCluster_00440aa0
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   4fh
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, [eax*4 + g_data_004d57ac_arr]
        dec     eax
        mov     dword ptr [g_x_00542074], ecx
        mov     dword ptr [g_state_004d57ac], eax
        mov     edx, [eax*4 + g_data_004d57ac_arr]
        dec     eax
        mov     dword ptr [g_x_00542054], edx
        mov     dword ptr [g_state_004d57ac], eax
        call    PendingMatch_00443320
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   16h
        mov     eax, dword ptr [g_state_0054208c]
        mov     dword ptr [g_x_0054206c], 1
        and     al, 0xfb
        mov     dword ptr [g_state_0054208c], eax
        }
}


/* @addr 0x0043d620 (338b game) - state-machine + dual ModuloMagic + 3-state install.
 *   state>=2: jne to second dual-call block.
 *   state<2: compute (g_cj[+0x64]-g_x_00542084) -> push -> ModuloMagic; if result <= 0: install state=1.
 *   Second block: same compute again; if result > 0: install state=2.
 *   Else: g_x_0054206c=0xa; call GuardedSeq; if pause ret.
 *     g_x_0054206c=0x91, g_data_00542070=-1; call Thunk_0049cc00; if pause ret.
 *     Push 0x91, push (PendingMatch_0043d830 + 0x340); call StoreTwoCall; pop. Push 0x004e5130; call ArgSarStoreJmp; pop; ret.
 *   Tail (+0x130, 10-NOP pad): g_x_0054206c=0; chain[g_cj*4+0x7c]=0; push 0x004e5140; call ArgSarStoreJmp; pop; ret.
 */
__declspec(naked) void StateMachineDualModuloInstall_0043d620(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        _emit   83h
        _emit   0e8h
        _emit   00h
        _emit   74h
        _emit   03h
        dec     eax
        _emit   75h
        _emit   30h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [g_x_00542084]
        mov     eax, dword ptr [ecx*4 + 0x64]
        sub     eax, edx
        push    eax
        mov     dword ptr [g_x_0054206c], eax
        call    ModuloMagic_0042afc0
        add     esp, 4
        mov     dword ptr [g_x_0054206c], eax
        test    eax, eax
        _emit   0fh
        _emit   8eh
        _emit   0b2h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     edx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [edx*4 + 0x64]
        mov     edx, dword ptr [g_x_00542084]
        sub     eax, edx
        push    eax
        mov     dword ptr [g_x_0054206c], eax
        call    ModuloMagic_0042afc0
        add     esp, 4
        mov     dword ptr [g_x_0054206c], eax
        test    eax, eax
        _emit   7fh
        _emit   64h
        mov     dword ptr [g_x_0054206c], 0xa
        call    GuardedSeq_00472820
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   86h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     dword ptr [g_x_0054206c], 0x91
        mov     dword ptr [g_data_00542070], 0xffffffff
        call    Thunk_0049cc00
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   75h
        _emit   64h
        push    0x91
        push    offset PendingMatch_0043d830 + 0x340
        call    StoreTwoCall_0049cb40
        add     esp, 8
        push    0x004e5130
        call    ArgSarStoreJmp_004594f0
        mov     eax, dword ptr [g_pause_00541e6c]
        add     esp, 4
        pop     esi
        ret
        mov     eax, 1
        mov     dword ptr [esi + 8], offset StateMachineDualModuloInstall_0043d620
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_x_0054204c], eax
        mov     dword ptr [g_pause_00541e6c], eax
        pop     esi
        ret
        mov     eax, 1
        mov     dword ptr [esi + 8], offset StateMachineDualModuloInstall_0043d620
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_x_0054204c], eax
        mov     dword ptr [g_pause_00541e6c], eax
        pop     esi
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     ecx, dword ptr [g_cj_0054205c]
        xor     eax, eax
        mov     dword ptr [g_x_0054206c], eax
        push    0x004e5140
        mov     dword ptr [ecx*4 + 0x7c], eax
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        ret
    }
}


/* @addr 0x00469340 (364b game) - cdecl chain with stream-flag swap +
 *   packed_ptr select. Sets g_data_0054206c=0x52, calls
 *   TableLookupCall_00489ff0; on no-error sets 0x54206c=0xa, calls
 *   ScaledIndexConditionalAdd_0048e400. Then dispatches on
 *   g_data_00542060:
 *     - matches g_data_00538038: if g_data_0054388c is set, picks
 *       &g_data_004ec050>>2 (state 1) or &g_data_004ec040>>2 (other)
 *       into g_data_00542050, clears g_data_0054388c, jumps to next.
 *     - matches g_data_0053803c: mirror with g_data_00543890.
 *     - default: both g_data_00542050 and 0x54204c set to the two
 *       packed_ptrs, zeroes g_data_00542080, calls
 *       GuardedDualConst2AndToggle_0048eba0. If bit 0 of 0x54208c set,
 *       sets g_data_00542080=1 and copies 0x54204c into 0x542050; else
 *       keeps 0x542050.
 *   Tail: copies chosen base into 0x542044, calls Mul10SumStoreNegCommit_00490970, pushes
 *   0x542a58 and calls GuardedPackedSlotInit_00428760, then
 *   MStackPush3CmpCall_0048eec0. If bit 0 of 0x54208c set, calls
 *   PendingMatch_004694b0. Then tail-jmp ScaledChainJmp_00429470 or
 *   ScaledClearJmp_00428d60 depending on g_data_00542080.
 */
__declspec(naked) void StreamFlagPackedSelectChain_00469340(void) {
    __asm {
        mov     dword ptr [g_data_0054206c], 0x52
        call    TableLookupCall_00489ff0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sfp_done
        mov     dword ptr [g_data_0054206c], 0xa
        call    ScaledIndexConditionalAdd_0048e400
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sfp_done
        mov     ecx, dword ptr [g_data_00542060]
        mov     eax, dword ptr [g_data_00538038]
        cmp     ecx, eax
        jne     short L_sfp_check2
        mov     eax, dword ptr [g_data_0054388c]
        test    eax, eax
        je      short L_sfp_check2
        cmp     eax, 1
        mov     eax, offset g_data_004ec050
        je      short L_sfp_useEax1
        mov     eax, offset g_data_004ec040
    L_sfp_useEax1:
        shr     eax, 2
        mov     dword ptr [g_data_00542050], eax
        mov     dword ptr [g_data_0054388c], 0
        jmp     L_sfp_callBlock
    L_sfp_check2:
        cmp     ecx, dword ptr [g_data_0053803c]
        jne     short L_sfp_defaultPath
        mov     eax, dword ptr [g_data_00543890]
        test    eax, eax
        je      short L_sfp_defaultPath
        cmp     eax, 1
        mov     eax, offset g_data_004ec050
        je      short L_sfp_useEax2
        mov     eax, offset g_data_004ec040
    L_sfp_useEax2:
        shr     eax, 2
        mov     dword ptr [g_data_00542050], eax
        mov     dword ptr [g_data_00543890], 0
        jmp     short L_sfp_callBlock
    L_sfp_defaultPath:
        mov     eax, offset g_data_004ec040
        mov     ecx, offset g_data_004ec050
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_data_0054204c], eax
        mov     dword ptr [g_data_00542050], ecx
        mov     dword ptr [g_data_00542080], 0
        call    GuardedDualConst2AndToggle_0048eba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sfp_done
        mov     eax, dword ptr [g_data_0054208c]
        and     eax, 1
        je      short L_sfp_useSecond
        mov     dword ptr [g_data_00542080], 1
    L_sfp_useSecond:
        test    eax, eax
        je      short L_sfp_useStored
        mov     eax, dword ptr [g_data_0054204c]
        mov     dword ptr [g_data_00542050], eax
        jmp     short L_sfp_callBlock
    L_sfp_useStored:
        mov     eax, dword ptr [g_data_00542050]
    L_sfp_callBlock:
        mov     dword ptr [g_data_00542044], eax
        call    Mul10SumStoreNegCommit_00490970
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sfp_done
        push    offset g_data_00542a58
        call    GuardedPackedSlotInit_00428760
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     short L_sfp_done
        call    MStackPush3CmpCall_0048eec0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sfp_done
        test    byte ptr [g_data_0054208c], 1
        je      short L_sfp_skipCallb0
        call    PendingMatch_004694b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sfp_done
    L_sfp_skipCallb0:
        mov     eax, dword ptr [g_data_00542080]
        test    eax, eax
        jne     short L_sfp_tailClear
        jmp     ScaledChainJmp_00429470
    L_sfp_tailClear:
        jmp     ScaledClearJmp_00428d60
    L_sfp_done:
        ret
    }
}


/* @addr 0x00421380 (378b game) - 2-entry packed phase install + 6-call chain.
 *   Entry 1 (offset 0, 277b): phase-state install.
 *     Phase 1+: SwapOrPassSet_0048fbf0; on no-error compares
 *       g_data_0054206c with g_data_004f3608. If equal, tail-call
 *       PendingMatch_0042d240. Else bumps g_data_00537f30 by 1, calls
 *       CallPauseClear3CallTriple_00428030, then chains
 *       ScenegraphWalk_0041f7d0 + PendingMatch_00420300.
 *     Phase 0: g_data_0052d724=1, reads g_data_0052ab40 and tests
 *       bit 3; if clear calls TwinMStackPushScaledChain_00422110. Either way installs Self
 *       at body with slot[+0x84]=1, packs (Self + 0x01000000) at the
 *       bumped scaled slot, calls RoundEndFsm_0042b2f0, arms 0x541e6c=1.
 *   11b NOP align pad.
 *   Entry 2 (offset 0x120, 90b): 6-call chain (ScaledInit_0048f720,
 *     CopyJmp_00406ba0, ScaledZero44_00491500, ScaledZeroFour_00490740,
 *     MStackPushSet0001_00490260, MStackPushSet0004_00490230), each
 *     gated by 0x541e6c. On full success, tail-jmps
 *     ScaledInitWithCounterAndType_004314f0.
 */
__declspec(naked) void Phase3InstallSelfChain_00421380(void) {
    __asm {
        mov     eax, dword ptr [g_data_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_pis2_phase0
        call    SwapOrPassSet_0048fbf0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pis2_done
        mov     ecx, dword ptr [g_data_0054206c]
        mov     eax, dword ptr [g_data_004f3608]
        cmp     ecx, eax
        jne     short L_pis2_advance
        call    PendingMatch_0042d240
        pop     esi
        ret
    L_pis2_advance:
        mov     edx, dword ptr [g_data_00537f30]
        lea     eax, [edx + 1]
        mov     dword ptr [g_data_0054206c], eax
        mov     dword ptr [g_data_00537f30], eax
        call    CallPauseClear3CallTriple_00428030
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pis2_done
        call    ScenegraphWalk_0041f7d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pis2_done
        call    PendingMatch_00420300
        pop     esi
        ret
    L_pis2_phase0:
        mov     eax, dword ptr [g_data_0052ab40]
        mov     dword ptr [g_data_0052d724], 1
        mov     dword ptr [g_data_0054206c], eax
        and     eax, 8
        mov     dword ptr [g_data_00542094], eax
        jne     short L_pis2_skipCall
        call    TwinMStackPushScaledChain_00422110
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_done
    L_pis2_skipCall:
        mov     dword ptr [esi + 8], offset Phase3InstallSelfChain_00421380
        mov     eax, dword ptr [g_data_00542060]
        mov     ecx, offset Phase3InstallSelfChain_00421380
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x01000000
        mov     dword ptr [g_data_00542044], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_data_00542044]
        inc     eax
        mov     dword ptr [g_data_00542044], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_data_00542060]
        mov     dword ptr [edx*4 + 0x84], 0
        call    RoundEndFsm_0042b2f0
        mov     dword ptr [g_framePauseFlag], 1
    L_pis2_done:
        pop     esi
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
        /* entry 2 (offset 0x120) */
    L_pis2_entry2:
        call    ScaledInit_0048f720
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    CopyJmp_00406ba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    ScaledZero44_00491500
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    ScaledZeroFour_00490740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    MStackPushSet0001_00490260
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    MStackPushSet0004_00490230
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        jmp     ScaledInitWithCounterAndType_004314f0
    L_pis2_e2End:
        ret
    }
}




void DualWalkRange_00468440(void) {
    __asm {
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_data_00542084]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [g_data_00542088]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4], edx
        call    PendingMatch_004685d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dwr_ret
        mov     eax, dword ptr [g_data_00542058]
        mov     ecx, dword ptr [g_data_00542084]
        mov     dword ptr [eax*4 + 0x54], ecx
        mov     eax, dword ptr [g_data_00542058]
        mov     edx, dword ptr [g_data_00542088]
        mov     dword ptr [eax*4 + 0x5c], edx
        mov     dword ptr [g_data_00542078], 3
        call    PendingMatch_004685d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_dwr_ret
    L_dwr_fwd:
        mov     eax, dword ptr [g_data_00542084]
        mov     ecx, dword ptr [g_data_0054207c]
        mov     edx, dword ptr [g_data_00542088]
        add     eax, ecx
        mov     ecx, dword ptr [g_data_00542080]
        mov     dword ptr [g_data_00542084], eax
        add     edx, ecx
        mov     dword ptr [g_data_00542088], edx
        mov     edx, dword ptr [g_data_00542058]
        mov     dword ptr [edx*4 + 0x54], eax
        mov     ecx, dword ptr [g_data_00542058]
        mov     eax, dword ptr [g_data_00542088]
        mov     dword ptr [ecx*4 + 0x5c], eax
        mov     eax, dword ptr [g_data_00542078]
        dec     eax
        mov     dword ptr [g_data_00542078], eax
        je      short L_dwr_fwd_done
        call    PendingMatch_004685d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      short L_dwr_fwd
        ret
    L_dwr_fwd_done:
        mov     eax, dword ptr [g_state_004d57ac]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_data_00542088], edx
        mov     dword ptr [g_state_004d57ac], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_data_00542084], ecx
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [g_data_00542078], 3
        call    PendingMatch_004685d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_dwr_ret
    L_dwr_rev:
        mov     eax, dword ptr [g_data_00542084]
        mov     edx, dword ptr [g_data_0054207c]
        mov     ecx, dword ptr [g_data_00542088]
        sub     eax, edx
        mov     edx, dword ptr [g_data_00542080]
        mov     dword ptr [g_data_00542084], eax
        sub     ecx, edx
        mov     dword ptr [g_data_00542088], ecx
        mov     ecx, dword ptr [g_data_00542058]
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     eax, dword ptr [g_data_00542058]
        mov     edx, dword ptr [g_data_00542088]
        mov     dword ptr [eax*4 + 0x5c], edx
        mov     eax, dword ptr [g_data_00542078]
        dec     eax
        mov     dword ptr [g_data_00542078], eax
        je      short L_dwr_ret
        call    PendingMatch_004685d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      short L_dwr_rev
    L_dwr_ret:
        }
}


__declspec(naked) void SizeGateInstallSelfThenSubMul10_00473480(void)
{
    __asm
    {
        mov     eax, dword ptr [g_data_00542044]
        mov     edx, dword ptr [g_data_00542078]
        push    esi
        xor     esi, esi
        mov     ecx, dword ptr [eax*4 + 0x1c]
        cmp     ecx, edx
        mov     dword ptr [g_data_0054206c], ecx
        jl      L_sgis_lateTail
        mov     ecx, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_data_00542048], ecx
        mov     eax, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_data_0054206c], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        mov     eax, dword ptr [g_data_00542044]
        mov     eax, dword ptr [eax*4 + 0x40]
        cmp     eax, esi
        mov     dword ptr [g_data_0054206c], eax
        je      short L_sgis_after40
        push    eax
        push    0x1999
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_data_00542048]
        mov     dword ptr [g_data_0054206c], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     eax, dword ptr [g_data_00542048]
        or      dword ptr [eax*4], 8
    L_sgis_after40:
        mov     dword ptr [g_data_0054206c], 0x10000
        call    StoreDoubleNegPauseSubStore_004ab750
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_sgis_ret
        mov     eax, dword ptr [g_data_00542048]
        mov     edx, dword ptr [g_data_0054206c]
        mov     dword ptr [eax*4 + 0x18], edx
        mov     dword ptr [g_data_0054206c], 0xccc
        call    AudioMixerStep_004ab700
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_sgis_ret
        mov     ecx, dword ptr [g_data_0054206c]
        mov     edx, dword ptr [g_data_00542048]
        add     ecx, 0xccc
        mov     dword ptr [edx*4 + 0x1c], ecx
        mov     eax, dword ptr [g_data_00542044]
        shl     eax, 2
        mov     ecx, offset g_data_004ecc38
        shr     ecx, 2
        mov     dword ptr [eax + 0x3c], esi
        mov     dword ptr [eax + 0x40], esi
        mov     dword ptr [eax + 0x44], esi
        mov     dword ptr [g_data_0054206c], ecx
        call    ScaledStoreThree_00409260
        cmp     dword ptr [g_framePauseFlag], esi
        jne     short L_sgis_ret
        mov     edx, dword ptr [g_data_00542048]
        mov     eax, offset g_data_004ec950
        shr     eax, 2
        mov     dword ptr [edx*4 + 0x10], esi
        mov     ecx, dword ptr [g_data_00542048]
        mov     dword ptr [g_data_0054206c], eax
        mov     dword ptr [ecx*4 + 0x14], eax
        mov     eax, dword ptr [g_data_00542044]
    L_sgis_lateTail:
        mov     eax, dword ptr [eax*4 + 0xc]
        cmp     eax, esi
        mov     dword ptr [g_data_0054206c], eax
        je      short L_sgis_clear
        mov     dword ptr [g_data_0054206c], offset SizeGateInstallSelfThenSubMul10_00473480
        call    Helper_TickAlt
        cmp     dword ptr [g_framePauseFlag], esi
        jne     short L_sgis_ret
    L_sgis_clear:
        mov     eax, dword ptr [g_data_0054208c]
        and     al, 0xfe
        mov     dword ptr [g_data_0054208c], eax
    L_sgis_ret:
        pop     esi
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
    L_sgis_sub2:
        mov     eax, dword ptr [g_data_00542048]
        mov     eax, dword ptr [eax*4 + 0x48]
        push    eax
        push    0x13f35
        mov     dword ptr [g_data_0054206c], eax
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_data_00542048]
        mov     dword ptr [g_data_0054206c], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x48], eax
        jmp     PendingMatch_00473640
    }
}


__declspec(naked) void FourPackedSubInitCmpDispatch_004665b0(void)
{
    __asm
    {
        mov     eax, dword ptr [g_data_00542060]
        mov     ecx, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_data_0054204c], ecx
        mov     edx, dword ptr [eax*4 + 0x34]
        mov     dword ptr [g_data_00542054], edx
        mov     ecx, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_data_00542058], ecx
        mov     edx, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_data_0054205c], edx
        mov     dword ptr [g_data_00542074], 0x26b
        mov     dword ptr [g_data_0054204c], 0x4678b0
        call    AllocNode
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fpsicd_ret1
        mov     eax, dword ptr [g_data_00542054]
        mov     dword ptr [g_data_0054206c], 3
        mov     dword ptr [g_data_0054205c], eax
        call    GuardedSeq_00476f10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fpsicd_ret1
        call    TagDispatchPairedPacked_004667f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fpsicd_ret1
        push    0x4eaa10
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
    L_fpsicd_ret1:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_fpsicd_sub2:
        push    0x4eaa28
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
        ret
        nop
        nop
    L_fpsicd_sub3:
        mov     eax, dword ptr [g_data_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_fpsicd_sub3_phase0
        call    ScaledDecBranch_00466770
        pop     esi
        ret
    L_fpsicd_sub3_phase0:
        mov     ecx, dword ptr [g_data_00542060]
        mov     eax, dword ptr [ecx*4 + 0x30]
        cmp     eax, 1
        mov     dword ptr [g_data_0054206c], eax
        jne     short L_fpsicd_sub3_nonOne
        call    PendingMatch_004668b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fpsicd_sub3_ret
        push    0x4eaa38
        call    ArgSarStoreJmp_004594f0
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        pop     esi
        ret
    L_fpsicd_sub3_nonOne:
        call    PendingMatch_004668b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fpsicd_sub3_ret
        mov     dword ptr [esi + 8], offset L_fpsicd_sub3
        mov     dword ptr [esi + 0x84], 1
        mov     dword ptr [g_data_0054204c], 0xf
        mov     dword ptr [g_framePauseFlag], 1
    L_fpsicd_sub3_ret:
        pop     esi
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
    L_fpsicd_sub4:
        mov     eax, dword ptr [g_data_00542060]
        mov     ecx, dword ptr [eax*4 + 0x38]
        mov     dword ptr [g_data_00542058], ecx
        mov     edx, dword ptr [eax*4 + 0x3c]
        mov     dword ptr [g_data_0054205c], edx
        mov     dword ptr [g_data_00542074], 0x26b
        mov     dword ptr [g_data_0054204c], 0x4678b0
        call    AllocNode
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fpsicd_sub4_ret
        call    TagDispatchPairedPacked_004667f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fpsicd_sub4_ret
        mov     eax, dword ptr [g_data_00542060]
        push    0x4eaa48
        mov     ecx, dword ptr [eax*4 + 0x34]
        mov     dword ptr [g_data_0054205c], ecx
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
    L_fpsicd_sub4_ret:
        ret
    }
}


__declspec(naked) void StageEventExitCluster_0047cd50(void)
{
    __asm {
        /* H1: stage-exit sound */
        push     OFFSET g_data_004ed3d0
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret
        nop
        nop
        /* H2 (L_cd60): 4-state FSM */
    L_cd60:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_ceb1
        dec      eax
        je       L_ce13
        dec      eax
        je       short L_cdb4
        mov      dword ptr [g_data_0054206c], 4
        call     ScaledIndexConditionalAdd_0048e400
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cf58
        call     CjInstallSelfRouter_00470480
        pop      esi
        ret
    L_cdb4:
        mov      eax, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [eax*4 + 0x58]
        mov      dword ptr [g_data_0054206c], ecx
        mov      eax, dword ptr [eax*4 + 0x48]
        cmp      ecx, eax
        mov      dword ptr [g_data_00542070], eax
        jg       short L_ce8f
        call     ScaledMove48to58_00490720
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cf58
        mov      dword ptr [esi + 8], OFFSET L_cd60
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], 4
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_ce13:
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [ecx*4 + 0x58]
        cmp      eax, 0x10000
        mov      dword ptr [g_data_0054206c], eax
        jl       L_cf3c
        call     ScaledChainTwoStores_00480d20
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf58
        call     Vec2ChainComputeStores_00480b80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf58
        call     DualCallPauseDirtyJmp_00490c30
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf58
        call     MStackPushSet0008_004901a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf58
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, 0xffffbae2
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x70], eax
    L_ce8f:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_cd60
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_ceb1:
        call     DirtyToggleByGate_0048f350
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf58
        test     byte ptr [g_data_0054208c], 4
        je       short L_ceda
        call     PendingMatch_0047cf60
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf58
    L_ceda:
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x20c
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        call     CallPauseScaledStoreCopyJmp_00461220
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf58
        call     SetJmp_00429950
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf58
        mov      dword ptr [g_data_0054206c], 0x30
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf58
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, 0x4ccc
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x70], eax
    L_cf3c:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_cd60
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_cf58:
        pop      esi
        ret
    }
}


__declspec(naked) void IntroFsmCluster_0044d580(void)
{
    __asm {
    L_d580:
        /* H1 */
        push     OFFSET g_data_004e65b8
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret
        nop
        nop
        /* H2 */
        mov      eax, dword ptr [g_data_00542054]
        dec      eax
        mov      dword ptr [g_data_00542054], eax
        js       short L_d5a2
        /* orig uses near jmp form here (e9 rel32) even though
         * short would fit; force the 5-byte encoding. */
        _emit    0xe9
        _emit    0xde
        _emit    0xff
        _emit    0xff
        _emit    0xff
    L_d5a2:
        call     ScaledZeroFour_00490740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d5b5
        jmp      Thunk_0049cbc0
    L_d5b5:
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
        /* H3 (L_d5c0): 4-state FSM */
    L_d5c0:
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        sub      ecx, 0
        je       L_d6f0
        dec      ecx
        je       short L_d68d
        dec      ecx
        je       short L_d61c
        call     DoubleScaledCrossStore_00475750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d738
        mov      ecx, dword ptr [g_data_00542054]
        push     OFFSET g_data_004e65c8
        mov      dword ptr [g_data_0054205c], ecx
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret
    L_d61c:
        mov      edx, OFFSET g_data_00501088
        shr      edx, 2
        mov      dword ptr [g_data_00542054], edx
        mov      dword ptr [eax + 8], OFFSET L_d5c0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, OFFSET L_d5c0
        add      edx, 0x3000000
        mov      dword ptr [ecx*4 + 0x84], 3
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     SetJmp_004753a0
        mov      dword ptr [g_framePauseFlag], 1
        ret
    L_d68d:
        mov      dword ptr [eax + 8], OFFSET L_d5c0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, OFFSET L_d5c0
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x2000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfPackedTailJmp_004751f0
        mov      dword ptr [g_framePauseFlag], 1
        ret
    L_d6f0:
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542054]
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542058]
        mov      dword ptr [ecx*4 + 0x68], edx
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_d5c0
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_data_0054204c], 0xb
        mov      dword ptr [g_framePauseFlag], ecx
    L_d738:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* H4 */
        mov      eax, dword ptr [g_data_00542060]
        push     OFFSET g_const_0044d820
        mov      ecx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_data_00542054], ecx
        mov      edx, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_data_00542058], edx
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        mov      dword ptr [g_data_0054206c], 0x2b
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d793
        mov      dword ptr [g_data_00542054], 1
        jmp      PendingMatch_0044d7a0
    L_d793:
        ret
    }
}

/* ------------------------------------------------------------------ */
/* Versus-screen FSM cluster (599b game, 4 packed helpers)             */
/* ------------------------------------------------------------------ */
extern void func_0044fa70(void);
extern void func_00450520(void);
extern void func_004505d0(void);

__declspec(naked) void VersusScreenFsmCluster_0044f670(void)
{
    __asm {
        /* === Helper 1 (0x44f670): tiny event 004e6f50 forwarder === */
    L_f670:
        push     OFFSET g_data_004e6f50
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret
        nop
        nop
        /* === Helper 2 (0x44f680): counter-driven step + 0x44f680 self === */
    L_f680:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_f6b6
        push     OFFSET g_data_004e6f68
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_f6b6:
        mov      eax, dword ptr [g_data_00542054]
        dec      eax
        mov      dword ptr [g_data_00542054], eax
        js       short L_f6ca
        call     L_f670
        pop      esi
        ret
    L_f6ca:
        push     OFFSET g_data_004e6f60
        call     ScaledIdxLoadCallTailThunk_00472db0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_f74e
        mov      ecx, OFFSET g_data_005007c4
        shr      ecx, 2
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [esi + 8], OFFSET L_f680
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_f680
        add      ecx, 0x1000000
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfChainAccumPath_004752b0
        mov      dword ptr [g_framePauseFlag], 1
    L_f74e:
        pop      esi
        ret
        /* === Helper 3 (0x44f750): 3-state dispatch === */
    L_f750:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       short L_f828
        dec      eax
        je       short L_f7cb
        push     OFFSET func_004505d0
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     PendingMatch_0044f8d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_f864
        call     PendingMatch_00452770
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_f864
        push     OFFSET L_f870
        call     StoreLoadJmp_00404ef0
        mov      ecx, dword ptr [g_data_00542058]
        add      esp, 4
        mov      dword ptr [g_data_0054205c], ecx
        call     Thunk_0049cbc0
        pop      esi
        ret
    L_f7cb:
        push     OFFSET func_00450520
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     PendingMatch_0044f8d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f864
        call     PendingMatch_00452770
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f864
        push     OFFSET L_f870
        call     StoreLoadJmp_00404ef0
        mov      dword ptr [esi + 8], OFFSET L_f750
        mov      dword ptr [esi + 0x84], 2
        add      esp, 4
        mov      dword ptr [g_data_0054204c], 0x2d
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_f828:
        call     PendingMatch_00452770
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f864
        push     OFFSET L_f870
        call     StoreLoadJmp_00404ef0
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_f750
        mov      dword ptr [esi + 0x84], eax
        add      esp, 4
        mov      dword ptr [g_data_0054204c], 0x28
        mov      dword ptr [g_framePauseFlag], eax
    L_f864:
        pop      esi
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
        /* === Helper 4 (0x44f870): event 0x29 + 004e6f80 tail === */
    L_f870:
        call     DualScaledStore_00452740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f8c6
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_0054206c], 0x29
        mov      dword ptr [g_data_0054205c], eax
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f8c6
        push     OFFSET func_0044fa70
        call     StoreLoadJmp_00404ef0
        mov      ecx, dword ptr [g_data_00542058]
        add      esp, 4
        mov      dword ptr [g_data_0054205c], ecx
        push     OFFSET g_data_004e6f80
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_f8c6:
        ret
    }
}

/* ------------------------------------------------------------------ */
/* Versus-screen FSM cluster (599b game, 4 packed helpers)             */
/* ------------------------------------------------------------------ */
extern void func_0044fa70(void);
extern void func_00450520(void);
extern void func_004505d0(void);


/* ------------------------------------------------------------------ */
/* Round-cleanup cluster (687b game, 5 packed helpers + jmp table)     */
/* ------------------------------------------------------------------ */
extern void func_004569f0(void);

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
        mov      dword ptr [g_data_0054206c], eax
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

/* ------------------------------------------------------------------ */
/* Scene-node post-init sequencer (691b game): pause-guarded chain of */
/* 11 sub-init calls (transient setup + scaleInit + 4 sub-flag dispatches  */
/* + matrix + walker), each gated by g_pause_00541e6c.                */
/* ------------------------------------------------------------------ */
/* extern void AllocNode(void); -- defined elsewhere with diff sig */

void ScenePostInitSequencer_00429b70(void) {
    __asm {
        call     MStackPush8_004ab790
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        call     TwinLoopSlotFinder_00429a40
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_data_00542058]
        mov      eax, dword ptr [eax*4 + 0x3c]
        test     eax, eax
        mov      dword ptr [g_data_0054204c], eax
        je       short L_9bf5
        mov      dword ptr [g_data_0054207c], 1
        mov      dword ptr [g_data_00542074], 0x10
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      dword ptr [g_data_0054207c], 2
        mov      dword ptr [g_data_00542074], 0x10
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
    L_9bf5:
        mov      ecx, dword ptr [g_data_00542058]
        mov      edx, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_data_0054206c], edx
        call     CopyGlobal_004ac1f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [eax*4 + 0x1c]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_004d5308], ecx
        mov      ecx, dword ptr [eax*4 + 0x20]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_004d530c], ecx
        mov      ecx, dword ptr [eax*4 + 0x24]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_004d5300], ecx
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_004d5304], eax
        call     PendingMatch_00429ef0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_data_00535e6c]
        mov      ecx, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_00542044], eax
        mov      ecx, dword ptr [ecx*4 + 0x2c]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      edx, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [edx*4 + 0x30]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [edx*4 + 0x38]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      edx, dword ptr [g_data_00542058]
        mov      eax, dword ptr [edx*4 + 0xc]
        mov      dword ptr [g_data_00542048], eax
        call     MStackPushDispatchBitGate_00407330
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0053a7a8], eax
        mov      dword ptr [eax*4 + 0x30], 0xb
        mov      eax, dword ptr [g_data_00535e6c]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      edx, dword ptr [g_data_00542058]
        mov      eax, dword ptr [edx*4 + 0x14]
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        je       short L_9d79
        mov      dword ptr [g_data_00542048], eax
        call     MStackPush4LLWalkPop4_004090e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
    L_9d79:
        mov      eax, dword ptr [g_data_00542058]
        mov      eax, dword ptr [eax*4 + 0x10]
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        je       short L_9dc3
        mov      edx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542048], eax
        mov      ecx, dword ptr [eax*4]
        sar      ecx, 2
        mov      dword ptr [g_data_00542048], ecx
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_data_00542044], eax
        call     InstallSelfDispatch_00407620
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
    L_9dc3:
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542044], ecx
        call     MStackCall_00406390
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
        mov      edx, dword ptr [g_data_00542058]
        mov      eax, dword ptr [edx*4 + 8]
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        je       short L_9df5
        call     eax
    L_9df5:
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], eax
        call     MStackPop8_004ab860
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [g_data_0054205c], ecx
    L_9e22:
        }
}

/* ------------------------------------------------------------------ */
/* Pose-FSM 3-helper cluster (720b game):                             */
/*  h1 (0x431650): table-index wrapper, tail-jmp to AiAngleDistComputation_00431920.    */
/*  h2 (0x431680): pause-guarded 31360→31920→326a0 chain ending in    */
/*                 tail-jmp to ScaledInitWithCounterAndType_004314f0.                         */
/*  h3 (0x431710): 3-case pose dispatch (state 0: 31360 chain;        */
/*                 state 1: 30e60 install; state 2: scaleInit copy).  */
/* ------------------------------------------------------------------ */

__declspec(naked) void PoseFsmTriHelpers_00431650(void)
{
    __asm {
        /* === h1 (0x431650): table-index wrapper, tail-jmp 31920 === */
        mov      ecx, dword ptr [g_data_00542080]
        mov      eax, OFFSET g_data_00542188
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_data_00542044], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_data_00542044], eax
        jmp      AiAngleDistComputation_00431920
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
        /* === h2 (0x431680): pause-guarded chain → 4314f0 tail-jmp === */
        call     DualEntryInitDispatch_00431360
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        mov      eax, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_00542088], 0x10000
        mov      eax, dword ptr [eax*4 + 0x34]
        mov      dword ptr [g_data_0054206c], eax
        and      eax, 1
        mov      dword ptr [g_data_00542094], eax
        je       short L_16bd
        mov      dword ptr [g_data_00542088], 0xffff0000
    L_16bd:
        mov      ecx, dword ptr [g_data_00542080]
        mov      eax, OFFSET g_data_00542188
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_data_00542044], eax
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_data_00542044], ecx
        call     AiAngleDistComputation_00431920
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        call     PendingMatch_004326a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        jmp      ScaledInitWithCounterAndType_004314f0
    L_1700:
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
        /* === h3 (0x431710): 3-case pose-fn dispatcher === */
    L_1710:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_1853
        dec      eax
        je       L_1823
        dec      eax
        je       short L_1747
        call     DispatchOrInitFightGroup_0042f850
        pop      edi
        pop      esi
        ret
    L_1747:
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_0052ab10]
        mov      dword ptr [g_data_0054205c], ecx
        mov      dword ptr [g_data_0054206c], edi
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x40], edi
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x48], ecx
        call     CameraAimSplineDriver_00430e60
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_191d
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [edx*4 + 0x44], ecx
        lea      eax, [edx*4]
        mov      edx, dword ptr [g_data_0054207c]
        mov      dword ptr [eax + 0x34], edx
        mov      ecx, dword ptr [g_data_00542080]
        mov      dword ptr [eax + 0x3c], ecx
        mov      ecx, 0x28
        mov      dword ptr [eax + 0x38], 0xfffe8000
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax + 0x30], ecx
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_1710
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
        call     PendingMatch_00432110
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_1823:
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x78]
        mov      dword ptr [g_data_0054204c], ecx
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_1853:
        call     DualEntryInitDispatch_00431360
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_191d
        mov      edx, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_00542088], 0x10000
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [g_data_0054206c], eax
        and      eax, 1
        mov      dword ptr [g_data_00542094], eax
        je       short L_1894
        mov      dword ptr [g_data_00542088], 0xffff0000
    L_1894:
        mov      ecx, dword ptr [g_data_00542080]
        mov      eax, OFFSET g_data_00542188
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_data_00542044], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_data_00542044], eax
        call     AiAngleDistComputation_00431920
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_191d
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, OFFSET L_1710
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     PendingMatch_00432110
        mov      dword ptr [g_framePauseFlag], 1
    L_191d:
        pop      edi
        pop      esi
        ret
    }
}

/* ------------------------------------------------------------------ */
/* Match-end fade FSM cluster (732b game, 2 helpers + 4-case jmp tbl):*/
/*  h1 (0x449010): pre-fade pause-guarded chain (4089e0→408c10→       */
/*                 4b8fa0) → tail-jmp GuardedSeq_00473f50.                  */
/*  h2 (0x4490a0): pose-fn FSM with 4-case dispatch at 0x4492dc.      */
/* ------------------------------------------------------------------ */

__declspec(naked) void MatchEndFadeFsmCluster_00449010(void)
{
    __asm {
        /* === h1 (0x449010): pre-fade init → tail-jmp 473f50 === */
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_data_0054205c], ecx
        call     MStackPush2RunCountdown_004089e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_909c
        mov      dword ptr [g_data_0054206c], 2
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_909c
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [eax*4]
        or       ecx, 4
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_data_00542048]
        mov      eax, 0xa0000
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x34], eax
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_909c
        mov      dword ptr [g_data_0054206c], 2
        mov      dword ptr [g_data_00542078], 4
        jmp      GuardedSeq_00473f50
    L_909c:
        ret
        nop
        nop
        nop
        /* === h2 (0x4490a0): pose-fn 4-case FSM === */
    L_90a0:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 3
        ja       L_92d3
        jmp      dword ptr [eax*4 + L_jmptbl_92dc]
    L_90ce:
        /* case 1: install state 2 */
        mov      dword ptr [g_data_00542070], 0xfffeb334
        mov      dword ptr [esi + 8], OFFSET L_90a0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, OFFSET L_90a0
        add      edx, 0x2000000
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     PendingMatch_004492f0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_9139:
        /* case 2: install state 3 (no work) */
        mov      dword ptr [esi + 8], OFFSET L_90a0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], 0x28
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_9160:
        /* case 3: store fade params, call 44cc50, install state 4 */
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [g_data_00542074], 0xfffee667
        mov      edx, dword ptr [ecx*4 + 0x68]
        mov      dword ptr [g_data_00542058], edx
        call     DualPushAddCallDualPopJmp_0044cc50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_92d8
        mov      eax, dword ptr [g_data_00542070]
        mov      ecx, dword ptr [g_data_00542074]
        mov      dword ptr [g_data_00542084], eax
        mov      dword ptr [g_data_00542088], ecx
        mov      dword ptr [g_data_00542070], 0xfffed99a
        mov      dword ptr [esi + 8], OFFSET L_90a0
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_90a0
        add      ecx, 0x4000000
        mov      dword ptr [edx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     PendingMatch_004492f0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_9211:
        /* case 0: full init - call 4493e0 helper via push/call, then chain */
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542054]
        push     0x4493e0
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [edx*4 + 0x68], eax
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     Chain2AxisDiffStoreTailJmp_0044cad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_92d8
        mov      dword ptr [g_data_00542074], 0xb333
        mov      dword ptr [g_data_0054206c], 0xfffec000
        call     MStackPush3SideStore_0044cb80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_92d8
        mov      dword ptr [g_data_00542074], 0x1999
        call     DualPushAddCallDualPopJmp_0044cc50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_92d8
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_00542070]
        mov      edx, dword ptr [g_data_00542074]
        mov      dword ptr [g_data_0054205c], eax
        mov      eax, 1
        mov      dword ptr [g_data_00542084], ecx
        mov      dword ptr [g_data_00542088], edx
        mov      dword ptr [esi + 8], OFFSET L_90a0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0xc8
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret
    L_92d3:
        call     Thunk_0049cbc0
    L_92d8:
        pop      esi
        ret
        /* 2-byte nop pad: 8b ff (mov edi, edi) */
        _emit    0x8b
        _emit    0xff
    L_jmptbl_92dc:
        /* 4-entry jump table */
        _emit    0x11  /* case 0 -> 0x449211 */
        _emit    0x92
        _emit    0x44
        _emit    0x00
        _emit    0xce  /* case 1 -> 0x4490ce */
        _emit    0x90
        _emit    0x44
        _emit    0x00
        _emit    0x39  /* case 2 -> 0x449139 */
        _emit    0x91
        _emit    0x44
        _emit    0x00
        _emit    0x60  /* case 3 -> 0x449160 */
        _emit    0x91
        _emit    0x44
        _emit    0x00
    }
}

/* ------------------------------------------------------------------ */
/* Combo/move-select FSM cluster (759b game, 6 packed helpers):       */
/*  h1 (0x45a2c0): wait + indirect [0x542054] call OR install state 1.*/
/*  h2 (0x45a390): pose-fn install state 1 w/ 4294a0.                 */
/*  h3 (0x45a440): pose-fn install state 1 w/ 4283b0 + 45c020 prep.   */
/*  h4 (0x45a4f0): byte-mask + add to [esi+0x28] → tail 459510.       */
/*  h5 (0x45a530): byte-mask + 429980 → tail 459510.                  */
/*  h6 (0x45a570): byte-mask + 45c020 → tail 45a5c0.                  */
/* ------------------------------------------------------------------ */

__declspec(naked) void ComboMoveSelectFsmCluster_0045a2c0(void)
{
    __asm {
        /* === h1 (0x45a2c0): wait + indirect call OR install state 1 === */
    L_a2c0:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_a33e
        mov      eax, dword ptr [g_data_00542080]
        dec      eax
        mov      dword ptr [g_data_00542080], eax
        jne      short L_a2f6
        call     PendingMatch_00459510
        pop      esi
        ret
    L_a2f6:
        mov      eax, dword ptr [g_data_0054205c]
        mov      esi, dword ptr [g_data_0054208c]
        mov      edx, 4
        mov      ecx, dword ptr [eax*4 + 0x28]
        or       esi, edx
        mov      dword ptr [g_data_0054206c], ecx
        mov      eax, dword ptr [eax*4 + 0x24]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [g_data_0054208c], esi
        cmp      dword ptr [eax*4 + 4], ecx
        je       short L_a336
        xor      dword ptr [g_data_0054208c], edx
    L_a336:
        call     dword ptr [g_data_00542054]
        pop      esi
        ret
    L_a33e:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [g_data_004d57ac], eax
        call     CallDualStoreXorBit_004285e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_a380
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_a2c0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_a380:
        pop      esi
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
        /* === h2 (0x45a390): pose-fn install state 1 w/ 4294a0 === */
    L_a390:
        mov      eax, dword ptr [g_data_00542060]
        xor      edx, edx
        shl      eax, 2
        push     edi
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       short L_a3b2
        call     PendingMatch_00459510
        pop      edi
        ret
    L_a3b2:
        mov      edi, dword ptr [g_data_00542070]
        mov      ecx, dword ptr [g_framePauseFlag]
        and      edi, 0xff
        cmp      ecx, edx
        mov      dword ptr [g_data_00542070], edi
        jne      short L_a434
        mov      ecx, edi
        mov      edi, OFFSET L_a390
        mov      dword ptr [g_data_00542080], ecx
        mov      dword ptr [eax + 8], OFFSET L_a390
        mov      ecx, dword ptr [g_data_00542060]
        add      edi, 0x1000000
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     EsiInstallDecCallChain_004294a0
        mov      dword ptr [g_framePauseFlag], 1
    L_a434:
        pop      edi
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
        /* === h3 (0x45a440): pose-fn install state 1 w/ 45c020 + 4283b0 === */
    L_a440:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_a469
        call     PendingMatch_00459510
        pop      esi
        ret
    L_a469:
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_a4ee
        mov      eax, dword ptr [g_data_0054206c]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542058], eax
        mov      dword ptr [ecx*4 + 0x24], eax
        mov      dword ptr [esi + 8], OFFSET L_a440
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_a440
        add      ecx, 0x1000000
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     TripleBranchInstall_004283b0
        mov      dword ptr [g_framePauseFlag], 1
    L_a4ee:
        pop      esi
        ret
        /* === h4 (0x45a4f0): byte-mask add → tail 459510 === */
        mov      eax, dword ptr [g_data_00542070]
        mov      ecx, dword ptr [g_framePauseFlag]
        and      eax, 0xff
        test     ecx, ecx
        mov      dword ptr [g_data_00542070], eax
        jne      short L_a527
        mov      ecx, dword ptr [g_data_0054205c]
        add      eax, dword ptr [ecx*4 + 0x28]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x28], eax
        jmp      PendingMatch_00459510
    L_a527:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h5 (0x45a530): byte-mask + 429980 → tail 459510 === */
        mov      ecx, dword ptr [g_data_00542070]
        mov      eax, dword ptr [g_framePauseFlag]
        and      ecx, 0xff
        test     eax, eax
        mov      dword ptr [g_data_00542070], ecx
        jne      short L_a565
        mov      eax, ecx
        mov      dword ptr [g_data_00542080], eax
        call     ScaledArrStore_00429980
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_a565
        jmp      PendingMatch_00459510
    L_a565:
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
        /* === h6 (0x45a570): byte-mask + 45c020 → tail 45a5c0 === */
        mov      ecx, dword ptr [g_data_00542070]
        mov      eax, dword ptr [g_framePauseFlag]
        and      ecx, 0xff
        test     eax, eax
        mov      dword ptr [g_data_00542070], ecx
        jne      short L_a5b6
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [eax*4 + 0x28], ecx
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_a5b6
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [g_data_00542058], edx
        jmp      PendingMatch_0045a5c0
    L_a5b6:
        ret
    }
}

/* ------------------------------------------------------------------ */
/* Intro/menu init cluster (767b game, 5 packed helpers):             */
/*  h1 (0x44d280): mstack-bracketed flag handler w/ bit-4 dispatch.   */
/*  h2 (0x44d3a0): pose-fn 2-state intro w/ 44dd00 + 489f90 + 43d830  */
/*    + 4752b0 install. Has push 0x44d5c0 (intro params), push 0x44f1e0 */
/*    (another intro fn entry).                                       */
/*  h3 (0x44d500): event 004e6590 forwarder w/ status init.           */
/*  h4 (0x44d540): event 004e65a0 forwarder w/ 0xfffffbc7 wait.       */
/*  h5 (0x44d570): set state 9 → tail-jmp IntroFsmCluster_0044d580.   */
/* ------------------------------------------------------------------ */

__declspec(naked) void IntroInitCluster_0044d280(void)
{
    __asm {
        /* === h1 (0x44d280): mstack-bracketed flag handler === */
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542048]
        inc      eax
        push     ebx
        push     esi
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     GuardedScaled_00475060
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      L_d395
        mov      al, byte ptr [g_data_0054208c]
        mov      ebx, 4
        test     al, bl
        je       short L_d2d7
        call     MStackBracket5_FieldClear_StateAdvance_00405630
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_d395
        test     byte ptr [g_data_0054208c], bl
        je       short L_d327
        jmp      short L_d2fe
    L_d2d7:
        mov      edx, OFFSET g_data_005117c4
        shr      edx, 2
        mov      dword ptr [g_data_00542048], edx
        call     FramePauseScaledStore_00406c10
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_d395
        test     byte ptr [g_data_0054208c], bl
        je       short L_d327
    L_d2fe:
        mov      edx, dword ptr [g_data_0054208c]
        mov      eax, dword ptr [g_data_004d57ac]
        or       edx, ebx
        dec      eax
        mov      dword ptr [g_data_0054208c], edx
        mov      ecx, dword ptr [eax*4 + 4]
        mov      dword ptr [g_data_00542048], ecx
        mov      dword ptr [g_data_004d57ac], eax
        pop      esi
        pop      ebx
        ret
    L_d327:
        mov      edx, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_0054206c], esi
        mov      dword ptr [edx*4 + 0x30], esi
        mov      ecx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [g_data_0054206c]
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_data_00542044]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 0x38], edx
        mov      ecx, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_0054206c], esi
        mov      dword ptr [ecx*4 + 0x1c], esi
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      eax, dword ptr [g_data_0054208c]
        and      al, 0xfb
        mov      dword ptr [g_data_00542048], edx
        mov      dword ptr [g_data_0054208c], eax
    L_d395:
        pop      esi
        pop      ebx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x44d3a0): pose-fn 2-state intro === */
    L_d3a0:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_d48e
        dec      eax
        je       short L_d3de
        push     OFFSET g_data_004e6580
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_d3de:
        call     GuardedDualScaledChainCopy_0044dd00
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d4f9
        mov      dword ptr [g_data_0054206c], 0x30
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d4f9
        call     PendingMatch_0043d830
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d4f9
        mov      ecx, OFFSET g_data_00501070
        shr      ecx, 2
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [esi + 8], OFFSET L_d3a0
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_d3a0
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfChainAccumPath_004752b0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_d48e:
        push     OFFSET IntroFsmCluster_0044d580 + 0x40
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     OFFSET PoseChainAdvanceCluster_0044ef50 + 0x290
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     DoubleCallChainInit_0043d780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d4f9
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_00542084], 0x12666
        mov      dword ptr [g_data_0054205c], eax
        call     GameInstall2BodyMul10ScaledInit_00475590
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d4f9
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_d3a0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0x10
        mov      dword ptr [g_framePauseFlag], eax
    L_d4f9:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        /* === h3 (0x44d500): event 004e6590 forwarder === */
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [eax*4 + 0x28], 0x35
        mov      dword ptr [g_data_0054206c], 0x27
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d535
        push     OFFSET g_data_004e6590
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_d535:
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
        /* === h4 (0x44d540): event 004e65a0 forwarder === */
        mov      dword ptr [g_data_0054206c], 0xfffffbc7
        call     PendingMatch_0044dd80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d565
        push     OFFSET g_data_004e65a0
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_d565:
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
        /* === h5 (0x44d570): set state 9 → tail-jmp 44d580 === */
        mov      dword ptr [g_data_00542054], 9
        jmp      IntroFsmCluster_0044d580
    }
}

/* ------------------------------------------------------------------ */
/* Char-select setup cluster (770b game, 3 packed helpers):           */
/*  h1 (0x4565a0): main init - scaledMove → 406600 → 0042b000 +0x4b65f */
/*    → 408860 → 409260 → tail-jmp 408600.                            */
/*  h2 (0x456690): pose-fn 4-state w/ different status codes per state.*/
/*  h3 (0x4567b0): counter walk loop w/ 476060 polling, install state-1*/
/*    when bit-4 set in 0x0054208c.                                   */
/* ------------------------------------------------------------------ */

__declspec(naked) void CharSelectSetupCluster_004565a0(void)
{
    __asm {
        /* === h1 (0x4565a0): main init chain → tail 408600 === */
        mov      eax, OFFSET g_data_0050b604
        shr      eax, 2
        mov      dword ptr [g_data_00542048], eax
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6688
        test     byte ptr [g_data_0054208c], 4
        jne      L_6688
        call     MStackCall_00406600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6688
        mov      ecx, dword ptr [g_data_00542054]
        mov      eax, dword ptr [ecx*4 + 0x64]
        add      eax, 0x4b65f
        push     eax
        mov      dword ptr [g_data_0054206c], eax
        call     WorldCellSetupCluster_0042b000
        mov      edx, dword ptr [g_data_00542044]
        add      esp, 4
        mov      dword ptr [edx*4 + 0x64], eax
        mov      eax, dword ptr [g_data_00542044]
        mov      dword ptr [eax*4 + 0x30], 0x93
        mov      ecx, dword ptr [g_data_00542044]
        mov      eax, 0xfffff852
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      eax, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_00542058], eax
        mov      dword ptr [g_data_0054205c], eax
        mov      edx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_data_00542044], edx
        call     ScaledTestPauseStore_00408860
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6688
        mov      eax, OFFSET g_data_004e8190
        shr      eax, 2
        mov      dword ptr [g_data_0054206c], eax
        call     ScaledStoreThree_00409260
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6688
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542044], ecx
        jmp      MStackBracket4_ListInsertZeroFill_00408600
    L_6688:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x456690): pose-fn 4-state status FSM === */
    L_6690:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_676f
        dec      eax
        je       short L_6730
        dec      eax
        je       short L_66ed
        mov      dword ptr [g_data_0054206c], 0x4b
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_67a8
        push     0x154f
        call     TableHitOrSchedule_004be7a0
        add      esp, 4
        call     Thunk_0049cbc0
        pop      esi
        ret
    L_66ed:
        mov      dword ptr [g_data_0054206c], 0x4a
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_67a8
        mov      dword ptr [esi + 8], OFFSET L_6690
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], 0xbd
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_6730:
        mov      dword ptr [g_data_0054206c], 0x4a
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_67a8
        mov      dword ptr [esi + 8], OFFSET L_6690
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 0xbd
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_676f:
        mov      dword ptr [g_data_0054206c], 0x49
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_67a8
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_6690
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0x7d
        mov      dword ptr [g_framePauseFlag], eax
    L_67a8:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h3 (0x4567b0): counter walk loop + 476060 polling === */
    L_67b0:
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_67ea
        mov      eax, dword ptr [g_data_00542054]
        dec      eax
        mov      dword ptr [g_data_00542054], eax
        jns      short L_6806
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_67ea:
        call     DualScaledStore_00452740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_689e
        mov      dword ptr [g_data_00542054], 0x1f4
    L_6806:
        call     PendingMatch_004568b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_689e
        mov      edi, 0x93
        mov      dword ptr [g_data_00542044], 0
        mov      dword ptr [g_data_0054206c], edi
        call     DispatcherComplex138_00476060
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_689e
        mov      bl, 4
    L_683d:
        test     byte ptr [g_data_0054208c], bl
        jne      short L_6882
        mov      ecx, dword ptr [g_data_00542044]
        mov      edx, dword ptr [g_data_00542070]
        mov      dword ptr [ecx*4 + 0x54], edx
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_00542074]
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      dword ptr [g_data_0054206c], edi
        call     DispatcherComplex138_00476060
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       short L_683d
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_6882:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_67b0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_689e:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}

/* ------------------------------------------------------------------ */
/* Endurance state init + walk (830b game, 2 packed helpers):         */
/*  h1 (0x4785a0): 16-iteration linked-list copy from 004ecf80 table  */
/*    then init globals + push 0x221/0x478670 timer.                  */
/*  h2 (0x478670): pose-fn 2-state - state 0: 4x clamp/copy entries   */
/*    from 00542b68 table w/ 478d00 + 4788e0 + ratio mul; install     */
/*    state 1; state 1: bit-2 audio.                                  */
/* ------------------------------------------------------------------ */

__declspec(naked) void EnduranceStateInitWalk_004785a0(void)
{
    __asm {
        /* === h1 (0x4785a0): 16-iter list copy + timer install === */
        mov      eax, OFFSET g_data_004ecf80
        mov      dword ptr [g_data_0053a1ac], 0xf
        shr      eax, 2
        mov      dword ptr [g_data_0054204c], eax
        jmp      short L_85be
    L_85b9:
        mov      eax, dword ptr [g_data_0054204c]
    L_85be:
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [g_data_0054204c], eax
        mov      edx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_data_00542048], edx
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [ecx*4], edx
        mov      eax, dword ptr [g_data_0053a1ac]
        dec      eax
        mov      dword ptr [g_data_0053a1ac], eax
        jns      short L_85b9
        call     PendingMatch_00478da0
        mov      ecx, dword ptr [g_framePauseFlag]
        xor      eax, eax
        cmp      ecx, eax
        jne      short L_8665
        mov      edx, dword ptr [g_data_00543714]
        mov      dword ptr [g_data_00535d58], eax
        cmp      edx, eax
        mov      dword ptr [g_data_0053a324], eax
        mov      dword ptr [g_data_00535e4c], eax
        mov      dword ptr [g_data_00537ef0], eax
        mov      ecx, 0x10000
        jne      short L_8638
        mov      dword ptr [g_data_0053a6dc], ecx
        mov      dword ptr [g_data_00537f2c], ecx
    L_8638:
        push     0x221
        push     OFFSET L_8670
        mov      dword ptr [g_data_0053a328], ecx
        mov      dword ptr [g_data_0053e348], ecx
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_0053a2d0], eax
        mov      dword ptr [g_data_00535db0], eax
        call     SetWalkCurCallPauseDirty_00404c70
        add      esp, 8
    L_8665:
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
        /* === h2 (0x478670): pose-fn 2-state w/ clamp/copy walk === */
    L_8670:
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     ebp
        push     esi
        lea      ebx, [eax*4]
        xor      esi, esi
        push     edi
        mov      eax, dword ptr [ebx + 0x84]
        mov      dword ptr [ebx + 0x84], esi
        cmp      eax, esi
        je       short L_86af
        push     0x27
        call     SaveCallRestoreOrXor_00404a00
        mov      al, byte ptr [g_data_0054208c]
        add      esp, 4
        test     al, 4
        je       short L_86af
        call     CallSetPause_0041f830
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_86af:
        mov      eax, 3
        mov      edi, OFFSET g_data_00542b68
        mov      dword ptr [g_data_0053a1ac], eax
        shr      edi, 2
    L_86c1:
        mov      ecx, edi
        mov      dword ptr [g_data_00535e48], eax
        mov      dword ptr [g_data_00542044], ecx
        add      ecx, eax
        mov      ecx, dword ptr [ecx*4]
        mov      dword ptr [g_data_00542048], ecx
        call     PushClampZeroOneCallPop_00478d00
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_88d9
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_data_00542044], ecx
        mov      ecx, dword ptr [ecx*4]
        mov      dword ptr [g_data_0054206c], ecx
        mov      edx, dword ptr [eax*4 + 4]
        mov      dword ptr [g_data_00542044], edx
        mov      edx, dword ptr [edx*4]
        cmp      ecx, edx
        je       L_88ac
        jl       short L_8775
        mov      eax, dword ptr [eax*4 + 0x20]
        sub      ecx, eax
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [g_data_0054206c], ecx
        call     MStackBracket6_DualGate_004788e0
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_88d9
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [eax*4 + 4]
        mov      dword ptr [g_data_00542044], ecx
        mov      edx, dword ptr [ecx*4]
        mov      ecx, dword ptr [g_data_0054206c]
        cmp      ecx, edx
        jge      short L_87c6
        jmp      short L_87a2
    L_8775:
        mov      edx, dword ptr [eax*4 + 0x20]
        add      ecx, edx
        mov      dword ptr [g_data_00542070], edx
        mov      dword ptr [g_data_0054206c], ecx
        mov      edx, dword ptr [eax*4 + 4]
        mov      dword ptr [g_data_00542044], edx
        mov      edx, dword ptr [edx*4]
        cmp      ecx, edx
        jle      short L_87c6
    L_87a2:
        mov      dword ptr [g_data_0054206c], edx
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_0054206c]
    L_87c6:
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542048]
        mov      edx, dword ptr [g_data_0054206c]
        mov      ecx, dword ptr [eax*4 + 0x18]
        push     edx
        push     ecx
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_00542048]
        mov      dword ptr [g_data_0054206c], eax
        sar      eax, 0x10
        mov      dword ptr [g_data_00542070], eax
        mov      edx, dword ptr [ecx*4 + 0x10]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [g_data_00542074], esi
        mov      ebp, dword ptr [ecx*4 + 0x24]
        add      esp, 8
        cmp      ebp, esi
        jne      short L_882a
        add      edx, eax
        jmp      short L_882c
    L_882a:
        sub      edx, eax
    L_882c:
        mov      dword ptr [g_data_0054206c], edx
        mov      ecx, dword ptr [ecx*4 + 8]
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edx
        mov      eax, dword ptr [g_data_00542048]
        mov      edx, dword ptr [g_data_00542070]
        mov      ecx, dword ptr [eax*4 + 0x1c]
        cmp      edx, ecx
        mov      dword ptr [g_data_0054206c], ecx
        jb       short L_886f
        mov      edx, dword ptr [eax*4 + 0x1c]
        mov      dword ptr [g_data_00542070], edx
    L_886f:
        mov      ecx, dword ptr [eax*4 + 0x14]
        mov      dword ptr [g_data_00542074], esi
        mov      dword ptr [g_data_0054206c], ecx
        mov      ebp, dword ptr [eax*4 + 0x24]
        cmp      ebp, esi
        jne      short L_8891
        add      ecx, edx
        jmp      short L_8893
    L_8891:
        sub      ecx, edx
    L_8893:
        mov      dword ptr [g_data_0054206c], ecx
        mov      eax, dword ptr [eax*4 + 0xc]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
    L_88ac:
        mov      eax, dword ptr [g_data_0053a1ac]
        dec      eax
        mov      dword ptr [g_data_0053a1ac], eax
        jns      L_86c1
        mov      eax, 1
        mov      dword ptr [ebx + 8], OFFSET L_8670
        mov      dword ptr [ebx + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_88d9:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}

/* ------------------------------------------------------------------ */
/* Aerial-hit dispatcher (845b game, 7 packed helpers):               */
/*  h1 (0x47c290): pose-fn install state 1 (callback for fall).       */
/*  h2 (0x47c300): if pose[+0x70]>=0 OR pose[+0x58]>=0xfffdcccd jmp h1;*/
/*    else 48d4b0+490c30+0x5a+0x481020+48fa50+event 004ed2c8.          */
/*  h3 (0x47c3c0): chained event 004ed2f0 → 004ed2f8 forwarder.        */
/*  h4 (0x47c3f0): pose-fn 2-state: state 0 setup [+0x58]=0xfffc0000 + */
/*    push 0x47c510 to mstack -> tail-jmp 48f3f0; state 1 install.    */
/*  h5 (0x47c510): set 0x1c28 status + 48dee0 → tail-jmp 46ad20.       */
/*  h6 (0x47c530): swap-side pose [+0x70] add 0x51e on both sides.    */
/*  h7 (0x47c570): event 004ed308 via 4902d0+490c30+48e740 → tail 47cc50.*/
/* ------------------------------------------------------------------ */

__declspec(naked) void AerialHitDispatcher_0047c290(void)
{
    __asm {
        /* === h1 (0x47c290): pose-fn install state 1 === */
    L_c290:
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        mov      ebx, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_c2d6
        call     CopyJmp_0048ef90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_c2ef
        test     byte ptr [g_data_0054208c], bl
        jne      short L_c2d6
        call     FiveCallGuardSetTail_0046f6b0
        pop      esi
        pop      ebx
        ret
    L_c2d6:
        mov      dword ptr [esi + 8], OFFSET L_c290
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_data_0054204c], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_c2ef:
        pop      esi
        pop      ebx
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
        /* === h2 (0x47c300): threshold check + chain via 48d4b0 === */
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [ecx*4 + 0x70]
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        jl       short L_c31b
        jmp      L_c290
    L_c31b:
        mov      ecx, dword ptr [ecx*4 + 0x58]
        cmp      ecx, 0xfffdcccd
        mov      dword ptr [g_data_0054206c], ecx
        jge      short L_c335
        jmp      L_c290
    L_c335:
        mov      dword ptr [g_data_0054206c], 0xe
        call     CmpEqInitCallElseJmp_0048d4b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_c3b9
        mov      cl, byte ptr [g_data_0054208c]
        mov      eax, 1
        test     cl, al
        jne      short L_c361
        jmp      L_c290
    L_c361:
        cmp      dword ptr [g_data_00542088], eax
        jne      short L_c36e
        jmp      FourConstCallLitCallJmp_0047ff20
    L_c36e:
        call     DualCallPauseDirtyJmp_00490c30
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_c3b9
        mov      dword ptr [g_data_00537e94], 0x5a
        mov      dword ptr [g_data_0054206c], 8
        call     ScaledLitLoadCall_00481020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_c3b9
        call     Cascade3ChainInit_0048fa50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_c3b9
        push     OFFSET g_data_004ed2c8
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_c3b9:
        ret
    }
}


__declspec(naked) void SceneEvalFsm_0049dea0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        xor      ebx, ebx
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], ebx
        cmp      eax, 3
        ja       L_e198
        jmp      dword ptr [eax*4 + L_jmptbl]
        push     0x251
        push     OFFSET AmbientMonitorCluster_0049e3c0 + 0xd0
        call     StoreTwoCall_0049cb40
        add      esp, 8
        mov      ecx, OFFSET g_data_004f29c0
        shr      ecx, 2
        push     0x262
        push     OFFSET RoundCleanupCluster_00427690 + 0xf0
        mov      dword ptr [g_data_0054205c], ecx
        call     StoreTwoCall_0049cb40
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm_0049dea0
        mov      dword ptr [esi + 0x84], 2
        add      esp, 8
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        pop      ebx
        ret      
        mov      dword ptr [g_data_00542074], 0x47
        call     Push16Call_00489f50
        cmp      dword ptr [g_framePauseFlag], ebx
        je       L_df68
        pop      esi
        pop      ebx
        ret      
        push     0x251
        push     OFFSET AmbientMonitorCluster_0049e3c0 + 0xd0
        call     SetWalkCurCallPauseDirty_00404c70
        add      esp, 8
        call     MStackDirtyArgsBit0_0049fa50
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        test     byte ptr [g_data_0054208c], 1
        jne      L_df8b
    L_df68:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm_0049dea0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        pop      ebx
        ret      
    L_df8b:
        call     DualTestDirtyToggle_004282c0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        test     byte ptr [g_data_0054208c], 1
        je       L_e05e
        jmp      L_e198
        push     6
        mov      byte ptr [g_data_00543728], bl
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     2
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     4
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2_004be800
        add      esp, 0x10
        call     DualTestDirtyToggle_00427ea0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        test     byte ptr [g_data_0054208c], 1
        jne      L_e010
        mov      dword ptr [g_data_0054206c], 1
        mov      dword ptr [g_data_0053a408], 1
    L_e010:
        call     AmbientMonitorCluster_0049e3c0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        call     GuardedCmpDualToggle_0049e360
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        cmp      dword ptr [g_data_0053a3c0], ebx
        je       L_e0fc
        cmp      dword ptr [g_data_0053a408], 2
        je       L_e0fc
        mov      eax, dword ptr [g_data_00537e88]
        cmp      eax, 2
        mov      dword ptr [g_data_0054206c], eax
        je       L_e0fc
    L_e05e:
        cmp      dword ptr [g_data_00543714], ebx
        je       L_e09d
        cmp      dword ptr [g_data_0054356c], ebx
        je       L_e09d
        cmp      dword ptr [g_data_005433ec], ebx
        je       L_e09d
        mov      al, byte ptr [g_data_00543590]
        mov      dword ptr [g_data_0053a3c0], ebx
        cmp      al, 1
        mov      dword ptr [g_data_00541fb0], 4
        jne      L_e097
        mov      dword ptr [g_data_005380e0], ebx
        jmp      L_e09d
    L_e097:
        mov      dword ptr [g_data_00537f48], ebx
    L_e09d:
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm_0049dea0
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, OFFSET SceneEvalFsm_0049dea0
        mov      dword ptr [edx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x4000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], ebx
        call     PendingMatch_00461ca0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
    L_e0fc:
        mov      ax, word ptr [g_data_004e2868]
        mov      dword ptr [g_data_0052aac4], 3
        push     eax
        mov      dword ptr [g_data_00537eec], ebx
        mov      dword ptr [g_data_0053a468], ebx
        mov      dword ptr [g_data_0054206c], ebx
        mov      dword ptr [g_data_00535e44], ebx
        call     TaggedSceneDispatch_004be690
        add      esp, 4
        call     ThrowAnimTriggerCluster_0049efa0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm_0049dea0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, OFFSET SceneEvalFsm_0049dea0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], ebx
        call     PhaseClampInstallSlot_0049e1c0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
    L_e198:
        call     BootInitGuardedCallChain_004265d0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        call     StackPopDispatchTagged_0041f780
    L_e1aa:
        pop      esi
        pop      ebx
        ret
        _emit 0x8d
        _emit 0x49
        _emit 0x00
    L_jmptbl:
        _emit 0xae
        _emit 0xdf
        _emit 0x49
        _emit 0x00
        _emit 0xcd
        _emit 0xde
        _emit 0x49
        _emit 0x00
        _emit 0x22
        _emit 0xdf
        _emit 0x49
        _emit 0x00
        _emit 0x3c
        _emit 0xdf
        _emit 0x49
        _emit 0x00
    }
}


__declspec(naked) void BossPunchCluster_00446c50(void)
{
    __asm {
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_0054205c]
        inc      eax
        push     esi
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     ChainWalkPushPop_00405a40
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6d5c
        mov      dword ptr [g_data_0054206c], 0x12c
        call     AudioVolumeRescale_004ab690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6d5c
        test     byte ptr [g_data_0054208c], 1
        je       L_6cb2
        call     DoublePushScaledInitJmp_00444db0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6d5c
    L_6cb2:
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 0x6c]
        lea      esi, [edx*4]
        mov      dword ptr [g_data_00542070], eax
        call     PushImmCallSetCallAdjustCall_00446bf0
        mov      ecx, dword ptr [g_data_00542070]
        mov      edx, dword ptr [esi + 0x70]
        mov      dword ptr [esi + 0x6c], ecx
        mov      dword ptr [g_data_00542070], edx
        call     PushImmCallSetCallAdjustCall_00446bf0
        mov      eax, dword ptr [g_data_00542070]
        mov      ecx, dword ptr [esi + 0x74]
        mov      dword ptr [esi + 0x70], eax
        mov      dword ptr [g_data_00542070], ecx
        call     PushImmCallSetCallAdjustCall_00446bf0
        mov      edx, dword ptr [g_data_00542070]
        mov      dword ptr [esi + 0x74], edx
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [ecx*4 + 0x58]
        cmp      eax, 0xffffd99a
        mov      dword ptr [g_data_0054206c], eax
        jl       L_6d44
        mov      dword ptr [ecx*4 + 0x58], 0xffffd99a
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], 0
        mov      dword ptr [eax*4 + 0x70], 0
    L_6d44:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_0054205c], ecx
        mov      dword ptr [g_data_004d57ac], eax
    L_6d5c:
        pop      esi
        ret
        nop
        nop
    L_6d60:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 4
        ja       L_6fac
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_6d8e:
        mov      dword ptr [g_data_0054206c], 0x2f
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6fc5
        call     PendingMatch_0043d830
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6fc5
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4 + 0x64]
        mov      dword ptr [g_data_00542054], edx
        call     GuardedScaled_00475000
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6fc5
        test     byte ptr [g_data_0054208c], 4
        je       L_6ea9
        mov      eax, OFFSET g_data_005010d0
        mov      edx, OFFSET L_6d60
        shr      eax, 2
        mov      dword ptr [g_data_00542054], eax
        mov      dword ptr [esi + 8], OFFSET L_6d60
        mov      ecx, dword ptr [g_data_00542060]
        add      edx, 0x2000000
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfChainAccumPath_004752b0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_6e5c:
        mov      dword ptr [esi + 8], OFFSET L_6d60
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], 0xf
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_6e83:
        mov      ecx, dword ptr [g_data_00542058]
        push     OFFSET g_data_004e6208
        mov      dword ptr [g_data_0054205c], ecx
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_6fc5
    L_6ea9:
        mov      edx, OFFSET g_data_005010c4
        mov      ecx, OFFSET L_6d60
        shr      edx, 2
        mov      dword ptr [g_data_00542054], edx
        mov      dword ptr [esi + 8], OFFSET L_6d60
        mov      eax, dword ptr [g_data_00542060]
        add      ecx, 0x4000000
        mov      dword ptr [eax*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfChainAccumPath_004752b0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_6f18:
        mov      dword ptr [esi + 8], OFFSET L_6d60
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_data_0054204c], 0xf
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_6f3f:
        push     OFFSET PendingMatch_00447a90 + 0x320
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     OFFSET PendingMatch_00447000 + 0x1b0
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     DoubleCallChainInit_0043d780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6fc5
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_00542084], 0x10000
        mov      dword ptr [g_data_0054205c], eax
        call     GameInstall2BodyMul10ScaledInit_00475590
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6fc5
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_6d60
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0x10
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_6fac:
        mov      ecx, dword ptr [g_data_00542058]
        push     OFFSET g_data_004e6218
        mov      dword ptr [g_data_0054205c], ecx
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_6fc5:
        pop      esi
        ret
        nop
    L_jmptbl:
        _emit 0x3f
        _emit 0x6f
        _emit 0x44
        _emit 0x00
        _emit 0x8e
        _emit 0x6d
        _emit 0x44
        _emit 0x00
        _emit 0x5c
        _emit 0x6e
        _emit 0x44
        _emit 0x00
        _emit 0x83
        _emit 0x6e
        _emit 0x44
        _emit 0x00
        _emit 0x18
        _emit 0x6f
        _emit 0x44
        _emit 0x00
        nop
        nop
        nop
        nop
        call     PendingMatch_00447000
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6ffb
        push     OFFSET g_data_004e6230
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_6ffb:
        ret
    }
}




__declspec(naked) void BackdashSetupCluster_00440dc0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_0054205c], eax
        call     MStackPush2RunCountdown_004089e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1012
        mov      dword ptr [g_data_0054206c], 5
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1012
        mov      ecx, dword ptr [g_data_00542048]
        mov      dword ptr [g_data_0054206c], 6
        add      ecx, 0xc
        mov      dword ptr [g_data_00542050], ecx
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1012
        mov      edx, dword ptr [g_data_00542048]
        mov      dword ptr [g_data_0054206c], 3
        add      edx, 0xc
        mov      dword ptr [g_data_00542054], edx
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1012
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [eax*4]
        or       ecx, 4
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542048]
        mov      dword ptr [eax*4 + 0x34], 0xa3d
        mov      ecx, dword ptr [g_data_00542048]
        mov      dword ptr [g_data_0054206c], 0
        mov      dword ptr [ecx*4 + 0x30], 0
        mov      eax, dword ptr [g_data_00542048]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 0x38], edx
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1012
        mov      dword ptr [g_data_0054206c], 3
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1012
        mov      ecx, dword ptr [g_data_00542048]
        mov      edx, dword ptr [g_data_00542050]
        mov      eax, dword ptr [ecx*4 + 0x3c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4], eax
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_00542050]
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 4], eax
        mov      edx, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_00542050]
        mov      eax, dword ptr [edx*4 + 0x44]
        mov      dword ptr [ecx*4 + 8], eax
        mov      edx, dword ptr [g_data_00542048]
        mov      eax, 0xffff0000
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x34], eax
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1012
        mov      dword ptr [g_data_0054206c], 3
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1012
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_00542054]
        mov      eax, dword ptr [eax*4 + 0x3c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4], eax
        mov      edx, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_00542054]
        mov      eax, dword ptr [edx*4 + 0x40]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 4], eax
        mov      edx, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_00542054]
        mov      eax, dword ptr [edx*4 + 0x44]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 8], eax
        mov      edx, dword ptr [g_data_00541f98]
        mov      eax, dword ptr [g_data_00542054]
        mov      ecx, dword ptr [g_data_00542050]
        mov      dword ptr [g_data_00542044], edx
        mov      dword ptr [g_data_00542048], eax
        mov      dword ptr [g_data_0054204c], ecx
        call     TripleSubVec3_004250f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1012
        mov      edx, dword ptr [g_data_00542050]
        mov      eax, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_00542058], edx
        mov      dword ptr [g_data_0054204c], eax
        jmp      DualPushSet7bCallPop_00474310
    L_1012:
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
    L_1020:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_1126
        dec      eax
        je       L_10a5
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_data_00542054], ecx
        mov      eax, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_data_00542058], eax
        mov      dword ptr [g_data_0054205c], eax
        call     MStackPush2RunCountdown_004089e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1196
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1196
        push     OFFSET g_data_004e51f8
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret      
    L_10a5:
        call     PendingMatch_0043d830
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1196
        mov      edx, OFFSET g_data_0050104c
        mov      ecx, OFFSET L_1020
        shr      edx, 2
        mov      dword ptr [g_data_00542054], edx
        mov      dword ptr [esi + 8], OFFSET L_1020
        mov      eax, dword ptr [g_data_00542060]
        add      ecx, 0x2000000
        mov      dword ptr [eax*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfChainAccumPath_004752b0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_1126:
        push     0x91
        push     OFFSET PendingMatch_00443320 + 0x160
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     OFFSET PendingMatch_004411d0 + 0x370
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     DoubleCallChainInit_0043d780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1196
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_00542084], 0x15999
        mov      dword ptr [g_data_0054205c], eax
        call     GameInstall2BodyMul10ScaledInit_00475590
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1196
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_1020
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0x10
        mov      dword ptr [g_framePauseFlag], eax
    L_1196:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        push     0x92
        push     OFFSET PendingMatch_004411d0 + 0x4f0
        call     StoreTwoCall_0049cb40
        add      esp, 8
        mov      dword ptr [g_data_00542054], 0x1f
        jmp      PendingMatch_004411d0
    }
}


__declspec(naked) void ScaledRunCountdownCluster_0044a090(void)
{
    __asm {
    L_a090:
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x4c]
        mov      dword ptr [g_data_0054205c], ecx
        call     MStackPush2RunCountdown_004089e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a0d7
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a0d7
        mov      dword ptr [g_data_0054206c], 3
        mov      dword ptr [g_data_00542078], 4
        jmp      GuardedSeq_00473f10
    L_a0d7:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_0054206c], 6
        mov      dword ptr [g_data_0054205c], ecx
        call     GuardedSeq_00476de0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        mov      dword ptr [g_data_0054206c], 6
        call     DirtyDoubleDeref_00408cb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        mov      edx, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_00542048], edx
        call     IntroInitCluster_0044d280
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        call     PushPopScaled1cDoubleCall_00408510
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        call     PendingMatch_0044a7f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        mov      eax, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 0x58]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 0x5c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_00542054]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542054], eax
        call     DualSlotCopyChain_004756f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [g_data_004d57ac], eax
        call     MStackCall_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        mov      eax, dword ptr [g_data_00542060]
        push     OFFSET L_a290
        mov      edx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_data_00542054], edx
        mov      eax, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_data_00542058], eax
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     OFFSET g_data_004e6408
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_a274:
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
        jmp      Thunk_0049cbc0
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
    L_a290:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_a45f
        dec      eax
        je       L_a3df
        dec      eax
        mov      eax, dword ptr [g_data_00542058]
        je       L_a329
        dec      eax
        mov      dword ptr [g_data_00542058], eax
        jns      L_a38f
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4 + 0x64]
        mov      dword ptr [g_data_0054206c], 8
        mov      dword ptr [g_data_0054205c], edx
        call     GuardedSeq_00476f10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        mov      dword ptr [g_data_0054206c], 6
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        call     DualScaledLoadStoreJmp_00475790
        call     Thunk_0049cbc0
        pop      esi
        ret      
    L_a329:
        dec      eax
        mov      dword ptr [g_data_00542058], eax
        jns      L_a4a0
        call     GuardedScaled_00475090
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        mov      cl, byte ptr [g_data_0054208c]
        mov      eax, 4
        test     cl, al
        jne      L_a385
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4 + 0x4c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_0054205c], edx
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        call     DualScaledLoadStoreJmp_00475790
    L_a385:
        mov      dword ptr [g_data_00542058], 0x29
    L_a38f:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542058]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     GuardedTripleSetTailJmp8_0044a500
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542058], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [esi + 8], OFFSET L_a290
        mov      eax, 3
        jmp      L_a448
    L_a3df:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542058]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     GuardedScaled_00475090
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        test     byte ptr [g_data_0054208c], 4
        jne      L_a424
        call     L_a090
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
    L_a424:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542058], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [esi + 8], OFFSET L_a290
        mov      eax, 2
    L_a448:
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_a45f:
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_0054205c]
        mov      dword ptr [ecx*4 + 0x4c], edx
        mov      dword ptr [g_data_00542058], 0x29
    L_a4a0:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542058]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        call     GuardedTripleSetTailJmp8_0044a500
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      eax, 1
        mov      dword ptr [g_data_00542058], edx
        mov      dword ptr [esi + 8], OFFSET L_a290
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_a4fa:
        pop      esi
        ret      
    }
}


__declspec(naked) void JuggleSetupCluster_004539d0(void)
{
    __asm {
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     EsiInstallSetCbChainExtend_0048a970
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
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
    L_3a10:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_3ad0
        dec      eax
        je       L_3a4e
        push     OFFSET g_data_004e7e48
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret      
    L_3a4e:
        call     PendingMatch_0043d830
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b3b
        mov      ecx, OFFSET g_data_0050122c
        shr      ecx, 2
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [esi + 8], OFFSET L_3a10
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_3a10
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfChainAccumPath_004752b0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_3ad0:
        push     OFFSET PendingMatch_00453e70 + 0x190
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     OFFSET PendingMatch_00454510 + 0x550
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     DoubleCallChainInit_0043d780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b3b
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_00542084], 0x18000
        mov      dword ptr [g_data_0054205c], eax
        call     GameInstall2BodyMul10ScaledInit_00475590
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b3b
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_3a10
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0x1f
        mov      dword ptr [g_framePauseFlag], eax
    L_3b3b:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        mov      dword ptr [g_data_0054206c], 4
        call     GuardedSeq_00472820
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3b7c
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, 0xb
        mov      dword ptr [g_data_0054206c], eax
        push     OFFSET g_data_004e7e58
        mov      dword ptr [ecx*4 + 0x28], eax
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_3b7c:
        ret      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [eax*4 + 0x28], 0xa9
        mov      dword ptr [g_data_0054206c], 4
        call     GuardedSeq_00472820
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3bf6
        mov      dword ptr [g_data_0054206c], 0xc
        call     GuardedSeq_00472840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3bf6
        call     PendingMatch_00452770
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3bf6
        push     OFFSET L_3c50
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     MStackPush2GlobalSwap_00477400
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3bf6
        push     OFFSET g_data_004e7e80
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_3bf6:
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
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, 0x126
        mov      dword ptr [g_data_0054206c], eax
        push     OFFSET g_data_004e7e90
        mov      dword ptr [ecx*4 + 0x28], eax
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
        mov      dword ptr [g_data_0054206c], 0x48
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3c4d
        jmp      Thunk_0049cbc0
    L_3c4d:
        ret
        nop
        nop
    L_3c50:
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_3d7f
        dec      eax
        je       L_3d4a
        dec      eax
        je       L_3c95
        mov      eax, dword ptr [g_data_00542054]
        dec      eax
        mov      dword ptr [g_data_00542054], eax
        js       L_3da6
        jmp      L_3c9f
    L_3c95:
        mov      dword ptr [g_data_00542054], 0x10
    L_3c9f:
        mov      dword ptr [g_data_0054206c], 0x2bc
        call     AudioVolumeRescale_004ab690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
        mov      al, byte ptr [g_data_0054208c]
        mov      ebx, 1
        test     al, bl
        je       L_3d2a
        call     MStackPush2RunCountdown_004089e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
        mov      dword ptr [g_data_0054206c], 0xa
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
        mov      ecx, dword ptr [g_data_00542048]
        add      ecx, 0xf
        mov      dword ptr [g_data_00542058], ecx
        call     MStackVecSetupScopedRun_004749a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
    L_3d2a:
        mov      dword ptr [esi + 8], OFFSET L_3c50
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret      
    L_3d4a:
        mov      eax, dword ptr [g_data_00542054]
        dec      eax
        mov      dword ptr [g_data_00542054], eax
        jns      L_3dc5
        mov      dword ptr [esi + 8], OFFSET L_3c50
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 0x14
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
    L_3d7f:
        mov      edx, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_0054205c], edx
        call     PendingMatch_00453e70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
        test     byte ptr [g_data_0054208c], 4
        je       L_3dae
    L_3da6:
        call     Thunk_0049cbc0
        pop      esi
        pop      ebx
        ret      
    L_3dae:
        push     OFFSET NetEntityScanAndPunish_00474b50
        mov      dword ptr [g_data_00542054], 0x32
        call     StoreLoadJmp_00404ef0
        add      esp, 4
    L_3dc5:
        mov      dword ptr [g_data_0054206c], 0xfa
        call     AudioVolumeRescale_004ab690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
        mov      al, byte ptr [g_data_0054208c]
        mov      ebx, 1
        test     al, bl
        je       L_3e54
        call     MStackPush2RunCountdown_004089e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
        mov      eax, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [eax*4 + 0x1c]
        mov      dword ptr [g_data_00542044], eax
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_data_0054206c], ecx
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
        mov      edx, dword ptr [g_data_00542048]
        add      edx, 0xf
        mov      dword ptr [g_data_00542058], edx
        call     MStackVecSetupScopedRun_004749a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3e6d
    L_3e54:
        mov      dword ptr [esi + 8], OFFSET L_3c50
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_data_0054204c], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_3e6d:
        pop      esi
        pop      ebx
        ret      
    }
}




__declspec(naked) void StoryCharIntroFsmCluster_00467ed0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_7f81
        dec      eax
        je       L_7f20
        call     LoadSetFpJmp_004093a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8019
        push     OFFSET g_data_004eb938
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_7f20:
        mov      dword ptr [esi + 8], OFFSET StoryCharIntroFsmCluster_00467ed0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, OFFSET StoryCharIntroFsmCluster_00467ed0
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x2000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     PendingMatch_0046b670
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_7f81:
        mov      al, byte ptr [g_data_00543590]
        mov      ecx, dword ptr [g_data_00537f94]
        cmp      al, 1
        jne      L_7f9b
        cmp      ecx, 1
        jne      L_7f9b
        inc      dword ptr [g_data_005433e8]
    L_7f9b:
        cmp      al, 2
        jne      L_7faa
        cmp      ecx, 2
        jne      L_7faa
        inc      dword ptr [g_data_005433e8]
    L_7faa:
        call     GateDispatch6c_00494580
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8019
        mov      eax, 0x20
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_0053a430], eax
        call     PushCallPauseSetMaxThenCallPauseJmp_0048e380
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8019
        cmp      dword ptr [g_data_0052aac4], 2
        jne      L_7fe5
        mov      byte ptr [g_data_00538148], 1
    L_7fe5:
        push     0
        push     OFFSET L_8200
        call     StoreTwoCall_0049cb40
        mov      dword ptr [esi + 8], OFFSET StoryCharIntroFsmCluster_00467ed0
        mov      dword ptr [esi + 0x84], 1
        add      esp, 8
        mov      dword ptr [g_data_0054204c], 0x1e
        mov      dword ptr [g_framePauseFlag], 1
    L_8019:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
    L_8020:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        mov      ecx, 3
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, ecx
        ja       L_81cb
        jmp      dword ptr [eax*4 + L_81ec_jmptbl]
    L_8050:
        mov      dword ptr [g_data_00542080], 8
        mov      dword ptr [esi + 8], OFFSET L_8020
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, OFFSET L_8020
        add      edx, 0x2000000
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelf3WayChainCmp_00428d80
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_80b8:
        mov      eax, dword ptr [g_data_0054207c]
        dec      eax
        mov      dword ptr [g_data_0054207c], eax
        jne      L_8163
        mov      dword ptr [esi + 8], OFFSET L_8020
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], ecx
        mov      eax, dword ptr [esi + 4]
        mov      ecx, OFFSET L_8020
        mov      dword ptr [g_data_00542044], eax
        add      ecx, 0x3000000
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     ScaledLoadJmp_00428d20
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_8124:
        call     CallPauseScaledStoreCopyJmp_00461220
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_81e7
        mov      dword ptr [esi + 8], OFFSET L_8020
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_data_0054204c], 0x1e
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_815d:
        mov      dword ptr [g_data_0054207c], ecx
    L_8163:
        mov      dword ptr [g_data_00542080], 6
        mov      dword ptr [esi + 8], OFFSET L_8020
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_8020
        add      ecx, 0x1000000
        mov      dword ptr [eax*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     EsiInstallChainCmpDualCall_00429300
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_81cb:
        mov      dword ptr [g_data_00542074], 0x3d
        call     Push16Call_00489f50
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_81e7
        call     ScaledInitWithCounterAndType_004314f0
    L_81e7:
        pop      edi
        pop      esi
        ret
        /* 2-byte alignment nop before jump table: 8b ff (mov edi, edi) */
        _emit    0x8b
        _emit    0xff
    L_81ec_jmptbl:
        /* 4-entry jump table */
        _emit    0x5d  /* case 0 -> 0x46815d */
        _emit    0x81
        _emit    0x46
        _emit    0x00
        _emit    0x50  /* case 1 -> 0x468050 */
        _emit    0x80
        _emit    0x46
        _emit    0x00
        _emit    0xb8  /* case 2 -> 0x4680b8 */
        _emit    0x80
        _emit    0x46
        _emit    0x00
        _emit    0x24  /* case 3 -> 0x468124 */
        _emit    0x81
        _emit    0x46
        _emit    0x00
        nop
        nop
        nop
        nop
    L_8200:
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542088], 0x10000
        mov      dword ptr [g_data_00542054], eax
        push     esi
        mov      eax, dword ptr [eax*4 + 0x34]
        mov      dword ptr [g_data_0054206c], eax
        and      eax, 1
        mov      dword ptr [g_data_00542094], eax
        je       L_8235
        mov      dword ptr [g_data_00542088], 0xffff0000
    L_8235:
        mov      dword ptr [g_data_00542080], 0x28
        call     PoseFsmTriHelpers_00431650
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_83d1
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x44]
        mov      dword ptr [g_data_00542074], ecx
        call     MStackPush1MagicMod2_004244d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_83d1
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [g_data_00542074], 0x60000
        push     edx
        push     0x60000
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_00542074]
        add      esp, 8
        mov      dword ptr [g_data_00542084], eax
        mov      eax, dword ptr [g_data_00542070]
        push     eax
        push     ecx
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_data_0054206c]
        add      esp, 8
        mov      dword ptr [g_data_00542088], eax
        push     edx
        push     0x11999
        call     Mul10Tail_00404af0
        add      esp, 8
        mov      dword ptr [g_data_0054206c], eax
        mov      eax, dword ptr [g_data_00542070]
        push     eax
        push     0x11999
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_0054206c]
        mov      esi, dword ptr [g_data_00542084]
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [g_data_00542080], ecx
        neg      eax
        mov      dword ptr [g_data_0054207c], eax
        mov      eax, dword ptr [g_data_00542060]
        add      esp, 8
        mov      edx, dword ptr [eax*4 + 0x34]
        add      esi, edx
        mov      edx, dword ptr [g_data_00542088]
        mov      dword ptr [g_data_00542084], esi
        mov      eax, dword ptr [eax*4 + 0x3c]
        add      edx, eax
        push     ecx
        push     0x14ccc
        mov      dword ptr [g_data_00542088], edx
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_00542070]
        add      esp, 8
        mov      dword ptr [g_data_0054206c], eax
        push     ecx
        push     0x14ccc
        call     Mul10Tail_00404af0
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [g_data_00542070], eax
        mov      eax, dword ptr [g_data_0054206c]
        add      esp, 8
        mov      dword ptr [edx*4 + 0x30], eax
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542070]
        mov      dword ptr [ecx*4 + 0x34], edx
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542084]
        mov      dword ptr [eax*4 + 0x38], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542088]
        mov      dword ptr [eax*4 + 0x3c], edx
        call     DualWalkRange_00468440
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_83d1
        call     DualSlotPropagateCall_004683e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_83d1
        call     DualSlotPropagateCall_004683e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_83d1
        push     OFFSET g_data_004eb958
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_83d1:
        pop      esi
        ret
    }
}


__declspec(naked) void IntroSettingsFsmCluster_0046bea0(void)
{
    __asm {
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x108
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [edx*4 + 0x34]
        cmp      ecx, 0x10
        mov      dword ptr [g_data_0054206c], ecx
        jne      L_beda
        mov      ecx, 2
        mov      dword ptr [g_data_0054206c], ecx
    L_beda:
        cmp      ecx, 0x11
        jne      L_beea
        mov      ecx, 4
        mov      dword ptr [g_data_0054206c], ecx
    L_beea:
        mov      eax, 0x4ebbf8
        shr      eax, 2
        add      eax, ecx
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542044], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [ecx*4 + 0x24], eax
        mov      edx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], 0
        mov      dword ptr [edx*4 + 0x28], 0
        call     ScaledChainAndF000DirtyToggle_0048e740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bf6b
        test     byte ptr [g_data_0054208c], 1
        jne      L_bf5e
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], 4
        mov      dword ptr [eax*4 + 0x28], 4
    L_bf5e:
        push     0x4eb1c8
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_bf6b:
        ret      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 5
        ja       L_c202
        jmp      dword ptr [eax*4 + L_c20c_jmptbl]
        mov      eax, 2
        mov      dword ptr [esi + 8], 0x46bf70
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        call     DirtyToggleByGate_0048f350
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c207
        test     byte ptr [g_data_0054208c], 4
        je       L_bfe5
        call     PendingMatch_0046a6e0
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_bfe5:
        mov      dword ptr [esi + 8], 0x46bf70
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], 6
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      dword ptr [esi + 8], 0x46bf70
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_data_0054204c], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, 8
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x28], eax
        mov      dword ptr [esi + 8], 0x46bf70
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, 0x46bf70
        add      ecx, 0x6000000
        mov      dword ptr [edx*4 + 0x84], 6
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     ScaledLoadJmp_00429390
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        call     ScaledChain3c74_0048f910
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c207
        mov      eax, dword ptr [g_data_0054206c]
        mov      ebx, 1
        cmp      eax, 0x2001
        je       L_c101
        cmp      eax, 0x106
        je       L_c101
        cmp      eax, 0x107
        je       L_c101
        mov      dword ptr [g_data_0054206c], 0x10
        call     ScaledInit_0048d430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c207
        test     byte ptr [g_data_0054208c], bl
        jne      L_c177
    L_c101:
        mov      dword ptr [g_data_0054206c], 0x6f
        call     TableLookupCall_00489ff0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c207
        mov      dword ptr [esi + 8], 0x46bf70
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, 0x46bf70
        mov      dword ptr [eax*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x4000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     ScaledLoadIncJmp_00428d00
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_c177:
        mov      eax, 0x4ec060
        shr      eax, 2
        mov      dword ptr [g_data_00542044], eax
        call     GuardedDirtyXformFromTable_0048f6d0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c207
        call     MStackPushSet0200_00490140
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c207
        call     CallDirty4DualJmp_00470f30
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c207
        mov      dword ptr [esi + 8], 0x46bf70
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x46bf70
        mov      dword ptr [ecx*4 + 0x84], ebx
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     ScaledLoadIncJmp_00428d00
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_c202:
        call     FiveCallGuardSetTail_0046f6b0
    L_c207:
        pop      edi
        pop      esi
        pop      ebx
        ret      
        /* 1-byte nop alignment before jump table */
        nop
    L_c20c_jmptbl:
        /* 6-entry jump table */
        _emit    0xae  /* case 0 -> 0x46c0ae */
        _emit    0xc0
        _emit    0x46
        _emit    0x00
        _emit    0x9d  /* case 1 -> 0x46bf9d */
        _emit    0xbf
        _emit    0x46
        _emit    0x00
        _emit    0xc2  /* case 2 -> 0x46bfc2 */
        _emit    0xbf
        _emit    0x46
        _emit    0x00
        _emit    0x37  /* case 3 -> 0x46c037 */
        _emit    0xc0
        _emit    0x46
        _emit    0x00
        _emit    0x0e  /* case 4 -> 0x46c00e */
        _emit    0xc0
        _emit    0x46
        _emit    0x00
        _emit    0x37  /* case 5 -> 0x46c037 */
        _emit    0xc0
        _emit    0x46
        _emit    0x00
        /* 12 nops padding */
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
        mov      dword ptr [g_data_0054207c], 0x80002
        jmp      HitReactionDispatcher_0045f650
        nop      
        mov      dword ptr [g_data_0054207c], 0x80003
        jmp      HitReactionDispatcher_0045f650
        nop      
        mov      dword ptr [g_data_0054207c], 0x80000
        jmp      HitReactionDispatcher_0045f650
        nop      
        mov      dword ptr [g_data_0054207c], 0x80001
        jmp      HitReactionDispatcher_0045f650
        nop      
        call     ScaledMove48to58_00490720
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c2e3
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [ecx*4 + 0x30]
        test     eax, eax
        mov      dword ptr [g_data_0054207c], eax
        je       L_c299
        jmp      CallPauseTripleScaledJmp_0046c520
    L_c299:
        mov      ecx, dword ptr [ecx*4 + 0x34]
        cmp      ecx, 0x10
        mov      dword ptr [g_data_0054206c], ecx
        jne      L_c2b6
        mov      ecx, 2
        mov      dword ptr [g_data_0054206c], ecx
    L_c2b6:
        cmp      ecx, 0x11
        jne      L_c2c6
        mov      ecx, 4
        mov      dword ptr [g_data_0054206c], ecx
    L_c2c6:
        mov      eax, 0x4ebc38
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_data_00542044], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_data_00542044], eax
        jmp      eax
    L_c2e3:
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
        push     0x4eb998
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret      
        nop      
        nop      
        push     0x4eb9b0
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret      
        nop      
        nop      
        push     0x4eba10
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_c349
        call     InstallSelfMultiThunkDispatch_0046c3d0
        pop      esi
        ret      
    L_c349:
        mov      dword ptr [g_data_0054206c], 0x10
        call     ScaledInit_0048d430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c3ce
        test     byte ptr [g_data_0054208c], 1
        jne      L_c371
        call     InstallSelfMultiThunkDispatch_0046c3d0
        pop      esi
        ret      
    L_c371:
        mov      ecx, 0x4ec078
        shr      ecx, 2
        mov      dword ptr [g_data_00542044], ecx
        call     GuardedDirtyXformFromTable_0048f6d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c3ce
        call     MStackPushSet0200_00490140
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c3ce
        call     CallDirty4DualJmp_00470f30
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c3ce
        mov      dword ptr [esi + 8], 0x46c320
        mov      dword ptr [esi + 0x84], 1
        mov      dword ptr [g_data_0054204c], 3
        mov      dword ptr [g_framePauseFlag], 1
    L_c3ce:
        pop      esi
        ret      
    }
}


__declspec(naked) void PendingMatch_0043bdd0(void)
{
    __asm {
        mov      al, byte ptr [g_data_00543590]
        mov      ecx, dword ptr [g_data_00537f94]
        cmp      al, 1
        jne      L_bdea
        cmp      ecx, 1
        jne      L_bdea
        inc      dword ptr [g_data_005433e8]
    L_bdea:
        cmp      al, 2
        jne      L_bdf9
        cmp      ecx, 2
        jne      L_bdf9
        inc      dword ptr [g_data_005433e8]
    L_bdf9:
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [ecx*4 + 0x34]
        cmp      eax, 0x10
        mov      dword ptr [g_data_0054206c], eax
        jne      L_be1a
        mov      eax, 2
        mov      dword ptr [g_data_0054206c], eax
    L_be1a:
        cmp      eax, 0x11
        jne      L_be29
        mov      eax, 7
        mov      dword ptr [g_data_0054206c], eax
    L_be29:
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_data_0054206c]
        add      eax, 0x10
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_0053a430], eax
        call     CallPauseScaledStoreCopyJmp_00461220
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_be8d
        cmp      dword ptr [g_data_0052aac4], 2
        jne      L_be60
        mov      byte ptr [g_data_00538148], 1
    L_be60:
        mov      eax, dword ptr [g_data_0053803c]
        mov      dword ptr [g_data_0053a464], eax
        mov      eax, dword ptr [g_data_00537f94]
        cmp      eax, 1
        je       L_be80
        mov      ecx, dword ptr [g_data_00538038]
        mov      dword ptr [g_data_0053a464], ecx
    L_be80:
        push     0x4e4e78
        call     ScaledChainCmpDispatch_0048e4f0
        add      esp, 4
    L_be8d:
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        mov      eax, dword ptr [eax*4 + 0x3c]
        mov      dword ptr [g_data_00542044], eax
        mov      ecx, dword ptr [eax*4 + 0x34]
        cmp      ecx, 0x10
        mov      dword ptr [g_data_0054206c], ecx
        jne      L_bebe
        mov      ecx, 2
        mov      dword ptr [g_data_0054206c], ecx
    L_bebe:
        cmp      ecx, 0x11
        jne      L_bece
        mov      ecx, 7
        mov      dword ptr [g_data_0054206c], ecx
    L_bece:
        cmp      ecx, 8
        jne      L_bed8
        jmp      DualBlockChainInitBody_0043cc10
    L_bed8:
        mov      eax, 0x4e4e78
        sar      eax, 2
        add      eax, ecx
        mov      dword ptr [g_data_00542048], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_data_00542048], eax
        jmp      eax
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
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_bf3d
        call     CallPauseScaledStoreCopyJmp_00461220
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bf9f
        push     0x4e4eb8
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret      
    L_bf3d:
        mov      dword ptr [eax + 8], 0x43bf00
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x43bf00
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfMStackPush_0041aaf0
        mov      dword ptr [g_framePauseFlag], 1
    L_bf9f:
        ret      
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_bfcf
        push     0x4e4ef0
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret      
    L_bfcf:
        mov      dword ptr [eax + 8], 0x43bfa0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x43bfa0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfMStackPush_0041aaf0
        mov      dword ptr [g_framePauseFlag], 1
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
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        shl      eax, 2
        xor      esi, esi
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], esi
        cmp      ecx, esi
        je       L_c139
        call     CallPauseScaledByteSet_0043c350
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_c197
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_0054206c], esi
        mov      dword ptr [ecx*4 + 0x5c], esi
        mov      eax, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 0x5c], edx
        mov      edx, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [edx*4 + 0x54], ecx
        mov      eax, dword ptr [g_data_00542054]
        mov      ecx, dword ptr [g_data_00542080]
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      eax, dword ptr [g_data_0054206c]
        mov      dword ptr [g_data_0053a7b4], eax
        mov      dword ptr [g_data_00535d68], eax
        mov      eax, 0xffff0000
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_00541d68], eax
        mov      dword ptr [g_data_00535d60], eax
        call     PendingMatch_0043c400
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_c197
        call     TriCmpOrFinal_0043c390
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_c197
        mov      eax, dword ptr [g_data_00542080]
        mov      edx, dword ptr [g_data_00542054]
        push     0x4e4f70
        lea      eax, [eax + eax*4]
        mov      dword ptr [g_data_00542080], eax
        mov      dword ptr [edx*4 + 0x54], eax
        mov      dword ptr [g_data_0054206c], esi
        mov      dword ptr [g_data_0053a730], esi
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret      
    L_c139:
        mov      dword ptr [eax + 8], 0x43c040
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x43c040
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], esi
        call     InstallSelfMStackPush_0041aaf0
        mov      dword ptr [g_framePauseFlag], 1
    L_c197:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_c25c
        dec      eax
        je       L_c1de
        call     MStackCall_00406740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_c291
        pop      esi
        ret      
    L_c1de:
        mov      ecx, dword ptr [g_data_00542054]
        mov      edx, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [ecx*4 + 0x54]
        mov      dword ptr [g_data_0054206c], ecx
        mov      eax, dword ptr [edx*4 + 0x54]
        sub      eax, ecx
        mov      dword ptr [g_data_00542070], eax
        jns      L_c20e
        neg      eax
        mov      dword ptr [g_data_00542070], eax
    L_c20e:
        cmp      eax, 0x14ccc
        jg       L_c329
        mov      dword ptr [g_data_0054206c], 0xb2
        call     ScaledLitLoadCall_00480fe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c345
        mov      dword ptr [esi + 8], 0x43c1a0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 0xf
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_c25c:
        call     DualCmpSwapStore_0049c5a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c345
        push     0x4e4fd0
        call     ScaledStackCallPause_0049c360
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_c345
        test     byte ptr [g_data_0054208c], 4
        je       L_c298
    L_c291:
        call     Thunk_0049cbc0
        pop      esi
        ret      
    L_c298:
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, 0x5e147
        mov      dword ptr [g_data_0054205c], eax
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax*4 + 0x68], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      eax, dword ptr [eax*4 + 0x38]
        mov      dword ptr [g_data_00542054], eax
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_data_0054207c], ecx
        mov      edx, dword ptr [eax*4 + 0x5c]
        mov      dword ptr [g_data_00542080], edx
        call     QuadMul10TailFpuChain_00431120
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c345
        mov      eax, dword ptr [g_data_0054207c]
        push     eax
        push     0x4ccc
        call     Mul10Tail_00404af0
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054207c], eax
        add      esp, 8
        mov      dword ptr [ecx*4 + 0x6c], eax
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, 0x147a
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x70], eax
    L_c329:
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x43c1a0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_c345:
        pop      esi
        ret      
    }
}



__declspec(naked) void PendingMatch_0044f8d0(void)
{
    __asm {
        mov      eax, 0x4e6fa0
        push     ebx
        shr      eax, 2
        mov      dword ptr [g_data_00542054], eax
        push     esi
        mov      ecx, dword ptr [eax*4]
        inc      eax
        test     ecx, ecx
        push     edi
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_00542054], eax
        je       L_f925
    L_f8f7:
        call     MStackPush2BitLoop_00476670
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fa00
        mov      eax, dword ptr [g_data_00542054]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        test     ecx, ecx
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_00542054], eax
        jne      L_f8f7
    L_f925:
        mov      eax, 0x4e6fd8
        shr      eax, 2
        mov      dword ptr [g_data_00542054], eax
        mov      ecx, dword ptr [eax*4]
        inc      eax
        test     ecx, ecx
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_00542054], eax
        je       L_f977
    L_f949:
        call     PushPopCurrentSetFFFFFFFF_00473070
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fa00
        mov      eax, dword ptr [g_data_00542054]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        test     ecx, ecx
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_00542054], eax
        jne      L_f949
    L_f977:
        mov      edi, 0x93
        mov      dword ptr [g_data_00542044], 0
        mov      dword ptr [g_data_0054206c], edi
        call     DispatcherComplex138_00476060
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fa00
        mov      bl, 4
        mov      esi, 0xfffffffb
    L_f9a1:
        test     byte ptr [g_data_0054208c], bl
        jne      L_f9d6
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [eax*4 + 0x34]
        and      ecx, esi
        mov      dword ptr [eax*4 + 0x34], ecx
        mov      dword ptr [g_data_0054206c], edi
        call     DispatcherComplex138_00476060
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_f9a1
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_f9d6:
        mov      eax, dword ptr [g_data_00542060]
        push     0x91
        push     0x44fe90
        mov      eax, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_data_0054205c], eax
        and      dword ptr [eax*4 + 0x34], esi
        call     StoreTwoCall_0049cb40
        add      esp, 8
    L_fa00:
        pop      edi
        pop      esi
        pop      ebx
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
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        jne      L_fa40
        call     ScaledLoadCmp0fJmp_004930e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fa61
    L_fa40:
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x44fa10
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0x3c
        mov      dword ptr [g_framePauseFlag], eax
    L_fa61:
        pop      esi
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
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        je       L_fbdb
        mov      dword ptr [g_data_0054206c], 1
        call     GuardedSeq_00472840
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        call     MStackCall_00406740
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        mov      dword ptr [g_data_0054206c], 0x43
        call     TableLookupCall_00489ff0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        call     PendingMatch_00452770
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        mov      ecx, dword ptr [g_data_00542054]
        push     0x92
        push     0x44dec0
        mov      dword ptr [g_data_0054205c], ecx
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     0x92
        push     0x44e0f0
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     0x92
        push     0x44e280
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     0x92
        push     0x44e1c0
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     0x92
        push     0x44ea20
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     0x92
        push     0x44eb60
        call     StoreTwoCall_0049cb40
        add      esp, 8
        mov      dword ptr [g_data_0054206c], 0x91
        call     PushPopCurrentSetFFFFFFFF_00473070
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        mov      esi, 0x93
        mov      dword ptr [g_data_00542044], edi
        mov      dword ptr [g_data_0054206c], esi
        call     DispatcherComplex138_00476060
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        mov      ebx, 4
    L_fba7:
        test     byte ptr [g_data_0054208c], bl
        jne      L_fc14
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [eax*4 + 0x34]
        or       ecx, ebx
        mov      dword ptr [eax*4 + 0x34], ecx
        mov      dword ptr [g_data_0054206c], esi
        call     DispatcherComplex138_00476060
        cmp      dword ptr [g_framePauseFlag], edi
        je       L_fba7
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_fbdb:
        call     DualScaledStore_00452740
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        mov      edx, 0x50be38
        shr      edx, 2
        mov      dword ptr [g_data_00542048], edx
        call     DispatcherComplex260_00407030
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        test     byte ptr [g_data_0054208c], 4
        je       L_fc1d
    L_fc14:
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_fc1d:
        call     MStackCall_00406600
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        mov      eax, dword ptr [g_data_00542058]
        mov      edx, dword ptr [g_data_00542044]
        mov      ebx, 1
        mov      ecx, dword ptr [eax*4 + 0x34]
        mov      dword ptr [g_data_00542070], ecx
        mov      eax, dword ptr [edx*4 + 0x34]
        and      ecx, ebx
        and      al, 0xfe
        or       eax, ecx
        mov      dword ptr [g_data_00542070], ecx
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x34], eax
        mov      ecx, dword ptr [g_data_00542058]
        mov      eax, dword ptr [ecx*4 + 0x64]
        mov      ecx, dword ptr [g_data_004d531c]
        add      eax, ecx
        push     eax
        mov      dword ptr [g_data_0054206c], eax
        call     WorldCellSetupCluster_0042b000
        mov      edx, dword ptr [g_data_00542044]
        mov      dword ptr [edx*4 + 0x64], eax
        mov      eax, 0x10000
        mov      dword ptr [edx*4 + 0x60], edi
        lea      ecx, [edx*4]
        mov      dword ptr [g_data_0054206c], eax
        add      esp, 4
        mov      dword ptr [ecx + 0x68], eax
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_0054205c], eax
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [g_data_00542078], 0xccc
        mov      dword ptr [g_data_0054207c], edi
        call     ChainGatedNegAccum_0048b740
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [g_data_00542078]
        mov      dword ptr [edx*4 + 0x54], eax
        mov      ecx, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [g_data_0054207c]
        mov      eax, 0xfffe8000
        mov      dword ptr [ecx*4 + 0x5c], edx
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      dword ptr [g_data_00542078], edi
        mov      dword ptr [g_data_0054207c], edi
        call     ChainGatedNegAccum_0048b740
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_0054207c]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542078]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_data_00542078], 0x3333
        mov      dword ptr [g_data_0054207c], edi
        call     ChainGatedNegAccum_0048b740
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_fe34
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_00542078]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        sub      edx, ecx
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [g_data_00542078], edx
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      eax, dword ptr [g_data_0054207c]
        sub      eax, ecx
        mov      dword ptr [g_data_0054207c], eax
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [eax*4 + 0x6c], edx
        mov      ecx, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [g_data_0054207c]
        mov      eax, 0xffffd1ec
        mov      dword ptr [ecx*4 + 0x74], edx
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      edx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542044], edx
        mov      dword ptr [esi + 8], 0x44fa70
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_data_0054204c], 0xa
        mov      dword ptr [g_framePauseFlag], ebx
    L_fe34:
        pop      edi
        pop      esi
        pop      ebx
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_fe61
        jmp      PendingMatch_0044fe90
    L_fe61:
        mov      ecx, 1
        mov      dword ptr [eax + 8], 0x44fe40
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_data_0054204c], 0x19
        mov      dword ptr [g_framePauseFlag], ecx
        ret      
    }
}

__declspec(naked) void PendingMatch_00432ed0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542084]
        cmp      eax, 0x10000
        jg       L_2ee0
        test     eax, eax
        jg       L_2eed
    L_2ee0:
        mov      eax, dword ptr [g_data_0054208c]
        and      al, 0xfe
        mov      dword ptr [g_data_0054208c], eax
        ret      
    L_2eed:
        mov      eax, dword ptr [g_data_0054208c]
        or       al, 1
        mov      dword ptr [g_data_0054208c], eax
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 6
        ja       L_3311
        mov      ebx, 1
        jmp      dword ptr [eax*4 + L_338c_jmptbl]
        call     Ten404c40_404bd0_00426780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      edx, dword ptr [g_data_00542050]
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [edx*4 + 0x6c], ecx
        mov      ecx, dword ptr [g_data_00542054]
        mov      eax, dword ptr [g_data_0054206c]
        mov      dword ptr [ecx*4 + 0x6c], eax
        call     Eleven404b90_404c00_004266d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      edx, dword ptr [g_data_00542058]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [esi + 8], 0x432f00
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        call     Ten404c40_404bd0_00426780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_0054204c]
        inc      eax
        push     0x22e
        mov      dword ptr [g_data_004d57ac], eax
        push     0x4333b0
        mov      dword ptr [eax*4], ecx
        call     StoreTwoCall_0049cb40
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542048]
        add      esp, 8
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      eax, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_0054204c], edx
        mov      dword ptr [eax*4 + 0x30], ecx
        mov      edx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [g_data_0054204c]
        mov      dword ptr [edx*4 + 0x34], eax
        call     Eleven404b90_404c00_004266d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      ecx, dword ptr [g_data_00542058]
        mov      edx, dword ptr [ecx*4 + 0x14]
        mov      dword ptr [g_data_0054204c], edx
        mov      dword ptr [esi + 8], 0x432f00
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        call     Ten404c40_404bd0_00426780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_0054204c]
        inc      eax
        push     0x22e
        mov      dword ptr [g_data_004d57ac], eax
        push     0x4333b0
        mov      dword ptr [eax*4], ecx
        call     StoreTwoCall_0049cb40
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542050]
        add      esp, 8
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      eax, dword ptr [g_data_00542044]
        mov      dword ptr [g_data_0054204c], edx
        mov      dword ptr [eax*4 + 0x30], ecx
        mov      edx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [g_data_00542054]
        mov      dword ptr [edx*4 + 0x34], eax
        jmp      L_310a
        call     Ten404c40_404bd0_00426780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        push     0x22e
        call     DualPushSetCallDualPop_00404b10
        mov      al, byte ptr [g_data_0054208c]
        add      esp, 4
        test     al, bl
        je       L_313c
    L_310a:
        call     Eleven404b90_404c00_004266d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      dword ptr [esi + 8], 0x432f00
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_data_0054204c], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret      
    L_313c:
        call     Eleven404b90_404c00_004266d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      dword ptr [esi + 8], 0x432f00
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_data_0054204c], 0x2d
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret      
        call     Ten404c40_404bd0_00426780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      ecx, dword ptr [g_data_00542058]
        mov      edx, dword ptr [g_data_00542048]
        mov      eax, dword ptr [ecx*4 + 0x20]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x6c], eax
        mov      ecx, dword ptr [g_data_0054204c]
        mov      eax, dword ptr [g_data_0054206c]
        mov      dword ptr [ecx*4 + 0x6c], eax
        call     Eleven404b90_404c00_004266d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      dword ptr [esi + 8], 0x432f00
        mov      dword ptr [esi + 0x84], 6
        mov      dword ptr [g_data_0054204c], 0xf
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        call     Ten404c40_404bd0_00426780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      eax, dword ptr [g_data_00542050]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 0x6c], edx
        mov      edx, dword ptr [g_data_00542054]
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [edx*4 + 0x6c], ecx
        call     Eleven404b90_404c00_004266d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      dword ptr [esi + 8], 0x432f00
        mov      dword ptr [esi + 0x84], 7
        mov      dword ptr [g_data_0054204c], 0x28
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
        mov      ecx, dword ptr [g_data_00542058]
        mov      eax, 0x5422d8
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_data_00542044], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_data_00542058], eax
        mov      dword ptr [g_data_0054205c], eax
        call     FourCallBitGateChain_004334d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        test     byte ptr [g_data_0054208c], 4
        jne      L_331f
        mov      eax, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_00542048]
        mov      eax, dword ptr [eax*4 + 0x10]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x6c], eax
        mov      eax, dword ptr [g_data_0054204c]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 0x6c], edx
        call     Eleven404b90_404c00_004266d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      ecx, dword ptr [g_data_00542058]
        mov      ebx, 1
        mov      edx, dword ptr [ecx*4 + 0x14]
        mov      dword ptr [g_data_0054204c], edx
        mov      dword ptr [esi + 8], 0x432f00
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret      
    L_3311:
        call     Ten404c40_404bd0_00426780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
    L_331f:
        mov      eax, dword ptr [g_data_00542048]
        mov      dword ptr [g_data_00542044], eax
        call     MStackPush2ChainLLInsert_00406790
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      ecx, dword ptr [g_data_0054204c]
        mov      dword ptr [g_data_00542044], ecx
        call     MStackPush2ChainLLInsert_00406790
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      edx, dword ptr [g_data_00542050]
        mov      dword ptr [g_data_00542044], edx
        call     MStackPush2ChainLLInsert_00406790
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        mov      eax, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_00542044], eax
        call     MStackPush2ChainLLInsert_00406790
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3388
        call     CallSetPause_0041f830
    L_3388:
        pop      esi
        pop      ebx
        ret      
        nop      
    L_338c_jmptbl:
        /* 7-entry jump table */
        _emit    0x60
        _emit    0x32
        _emit    0x43
        _emit    0x00
        _emit    0x34
        _emit    0x2f
        _emit    0x43
        _emit    0x00
        _emit    0xad
        _emit    0x2f
        _emit    0x43
        _emit    0x00
        _emit    0x68
        _emit    0x30
        _emit    0x43
        _emit    0x00
        _emit    0xe2
        _emit    0x30
        _emit    0x43
        _emit    0x00
        _emit    0x72
        _emit    0x31
        _emit    0x43
        _emit    0x00
        _emit    0xef
        _emit    0x31
        _emit    0x43
        _emit    0x00
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      ecx, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [ecx + 0x84], edi
        cmp      eax, edi
        je       L_3461
        mov      edx, dword ptr [g_data_00542060]
        mov      esi, dword ptr [g_data_00542054]
        mov      edx, dword ptr [edx*4 + 0x30]
        mov      dword ptr [g_data_00542070], edx
        mov      eax, dword ptr [esi*4 + 0x6c]
        sub      eax, edx
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [esi*4 + 0x6c], eax
        mov      eax, dword ptr [g_data_00542058]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 0x6c], edx
        mov      eax, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [eax*4 + 0x24]
        mov      dword ptr [g_data_00542074], eax
        cmp      eax, edi
        mov      eax, dword ptr [g_data_0054206c]
        jne      L_3435
        cmp      eax, edi
        jle      L_3439
        jmp      L_3495
    L_3435:
        cmp      eax, edi
        jl       L_3495
    L_3439:
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [ecx*4 + 0x6c], edi
        mov      edx, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_0054206c], edi
        mov      dword ptr [edx*4 + 0x6c], edi
        call     CallSetPause_0041f830
        pop      edi
        pop      esi
        ret      
    L_3461:
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_0054205c], eax
        mov      eax, dword ptr [eax*4 + 0x1c]
        mov      dword ptr [g_data_00542070], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      edx, dword ptr [eax*4 + 0x30]
        mov      dword ptr [g_data_00542054], edx
        mov      eax, dword ptr [eax*4 + 0x34]
        mov      dword ptr [g_data_00542058], eax
    L_3495:
        mov      eax, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542070]
        pop      edi
        pop      esi
        mov      dword ptr [eax*4 + 0x30], edx
        mov      eax, 1
        mov      dword ptr [ecx + 8], 0x4333b0
        mov      dword ptr [ecx + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        ret      
    }
}


__declspec(naked) void PendingMatch_004694b0(void)
{
    __asm {
        mov      dword ptr [g_data_0054206c], 0x4ccc
        jmp      EsiEdiAliasDualMul10_004906b0
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_9832
        dec      eax
        je       L_9654
        dec      eax
        je       L_95f6
        mov      ecx, dword ptr [g_data_00538038]
        mov      edx, dword ptr [g_data_0053803c]
        mov      eax, dword ptr [ecx*4 + 0x34]
        mov      ecx, dword ptr [edx*4 + 0x34]
        cmp      eax, 6
        je       L_9527
        cmp      ecx, 6
        je       L_9527
        mov      edx, dword ptr [g_data_0053a51c]
        push     0x1d
        add      edx, 0x12
        push     edx
        push     ecx
        push     eax
        jmp      L_9540
    L_9527:
        mov      eax, dword ptr [g_data_0053a51c]
        mov      ecx, dword ptr [g_data_005380e0]
        mov      edx, dword ptr [g_data_00537f48]
        add      eax, 0x12
        push     0x1d
        push     eax
        push     ecx
        push     edx
    L_9540:
        call     QuadCallPhase2_004be800
        add      esp, 0x10
        call     PushPopScaledInit343c_004aa940
        mov      dword ptr [g_data_00542074], 0x1b58
        call     Push16Call_00489f50
        mov      dword ptr [g_data_00542074], 0xd2
        call     Push16Call_00489f50
        mov      dword ptr [g_data_00542074], 0xb9
        call     Push16Call_00489f50
        call     DualBitGateInitCall_0048a1c0
        mov      eax, dword ptr [g_data_00542060]
        mov      eax, dword ptr [eax*4 + 0x34]
        cmp      eax, 0xf
        mov      dword ptr [g_data_0054206c], eax
        je       L_95b8
        cmp      eax, 0x10
        je       L_95b8
        cmp      eax, 0x11
        je       L_95b8
        add      eax, 0x26
        mov      dword ptr [g_data_0054206c], eax
        call     TableLookupCall_0048a130
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_986a
    L_95b8:
        call     ClearBit2x34_00490130
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_986a
        call     ScaledAndAlbf_00490350
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_986a
        mov      dword ptr [g_data_0054206c], 0x24d
        mov      dword ptr [g_data_00542070], 0x28f
        call     TwoPhaseInstallScaledPackedPtr_00480d50
        pop      edi
        pop      esi
        ret      
    L_95f6:
        mov      dword ptr [esi + 8], 0x4694c0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x4694c0
        mov      dword ptr [ecx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x3000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     AudioInstallSelfStatePush_004aa8a0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret      
    L_9654:
        mov      ecx, dword ptr [g_data_00542058]
        mov      eax, dword ptr [g_data_00538160]
        cmp      ecx, eax
        mov      dword ptr [g_data_0054205c], ecx
        jne      L_96c1
        mov      edx, dword ptr [g_data_00538158]
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [g_data_00542050], edx
        mov      edx, dword ptr [g_data_0053803c]
        mov      dword ptr [g_data_00538158], ecx
        mov      ecx, dword ptr [g_data_0053a178]
        mov      dword ptr [g_data_00542044], edx
        mov      edx, dword ptr [g_data_0053815c]
        mov      dword ptr [g_data_0053a2d0], edi
        mov      dword ptr [g_data_00538038], eax
        mov      dword ptr [g_data_00538160], edi
        mov      dword ptr [g_data_00542070], ecx
        mov      dword ptr [g_data_00537f48], ecx
        mov      dword ptr [g_data_0054206c], 1
        jmp      L_9715
    L_96c1:
        mov      eax, dword ptr [g_data_0053815c]
        mov      edx, dword ptr [g_data_00538038]
        mov      dword ptr [g_data_00542050], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [g_data_0053815c], ecx
        mov      ecx, dword ptr [g_data_0053a250]
        mov      dword ptr [g_data_00542044], edx
        mov      edx, dword ptr [g_data_00538158]
        mov      dword ptr [g_data_00535db0], edi
        mov      dword ptr [g_data_0053803c], eax
        mov      dword ptr [g_data_00538164], edi
        mov      dword ptr [g_data_00542070], ecx
        mov      dword ptr [g_data_005380e0], ecx
        mov      dword ptr [g_data_0054206c], 2
    L_9715:
        mov      dword ptr [g_data_00542048], edx
        mov      dword ptr [eax*4 + 0x34], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542044]
        mov      dword ptr [eax*4 + 0x3c], ecx
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_data_00542048]
        mov      dword ptr [edx*4 + 0x38], eax
        mov      ecx, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [ecx*4 + 0x30], edx
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [eax*4 + 0x38], ecx
        mov      eax, dword ptr [g_data_00542044]
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x3c], edx
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x5c]
        mov      dword ptr [g_data_0054206c], ecx
        mov      edx, dword ptr [eax*4 + 0x60]
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542070], edx
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      ecx, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [g_data_00542070]
        mov      eax, 0xfffc8000
        mov      dword ptr [ecx*4 + 0x5c], edx
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        call     TwoCallJmp_00478120
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_986a
        call     SlotPhaseResetInstallChain_0048e0e0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_986a
        call     FiveCallScaledChainTailJmp_0045f8d0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_986a
        call     MStackPushSet0040_00490200
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_986a
        mov      dword ptr [esi + 8], 0x4694c0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 0x28
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret      
    L_9832:
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [g_data_0054206c], edi
        mov      dword ptr [edx*4 + 0x30], edi
        mov      dword ptr [esi + 8], 0x4694c0
        mov      dword ptr [esi + 0x84], 1
        mov      dword ptr [g_data_0054204c], 4
        mov      dword ptr [g_framePauseFlag], 1
    L_986a:
        pop      edi
        pop      esi
        ret      
        nop      
        nop      
        nop      
        call     MStackPushSet0020_004901d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_98f3
        call     MStackPushSet0040_00490200
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_98f3
        call     ScaledZeroFour_00490740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_98f3
        mov      dword ptr [g_data_0054207c], 6
        call     EntryThunkBodyStateMachine_00457bb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_98f3
        mov      dword ptr [g_data_0054206c], 0x19
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_98f3
        push     0x86
        push     0x41a370
        call     StoreTwoCall_0049cb40
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_0054205c]
        add      esp, 8
        mov      dword ptr [eax*4 + 0x2c], ecx
        jmp      ScaledInitWithCounterAndType_004314f0
    L_98f3:
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
        push     0x4eab98
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_99be
        dec      eax
        je       L_9941
        call     CjInstallSelfRouter_00470480
        pop      esi
        ret      
    L_9941:
        mov      ecx, dword ptr [g_data_0054205c]
        mov      edx, 0x469910
        add      edx, 0x2000000
        mov      eax, dword ptr [ecx*4 + 0x34]
        xor      eax, 4
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      dword ptr [esi + 8], 0x469910
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     ScaledLoadIncJmp_00428d00
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_99be:
        push     0x8000
        call     ThreeChanPackClamp_00404cc0
        mov      ecx, dword ptr [g_data_0054205c]
        add      esp, 4
        push     ecx
        call     CopyThreeFields_00404df0
        add      esp, 4
        call     Phase4TrampolineThreePacked_0040fa20
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9a52
        mov      dword ptr [g_data_00542080], 0x28
        mov      dword ptr [esi + 8], 0x469910
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, 0x469910
        add      ecx, 0x1000000
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelf3WayChainCmp_00428d80
        mov      dword ptr [g_framePauseFlag], 1
    L_9a52:
        pop      esi
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
        mov      dword ptr [g_data_0054206c], 0
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 1
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 2
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 3
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 4
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 5
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 7
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 0xc
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 8
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 9
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 0xa
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 0xd
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 0xe
        jmp      PendingMatch_00469b40
        nop      
        mov      dword ptr [g_data_0054206c], 0xb
        jmp      PendingMatch_00469b40
    }
}


__declspec(naked) void PendingMatch_0048c570(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        mov      ebx, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_c5a5
        dec      eax
        je       L_c687
        jmp      L_c6de
    L_c5a5:
        call     CondPlayerLookup_004ac120
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542044]
        mov      dword ptr [ecx*4 + 0x30], edx
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [eax*4 + 0x34], ecx
        call     ScaledShrAnd_0048bb40
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      eax, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 0x3c], edx
        mov      eax, dword ptr [g_data_0054206c]
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_00542054]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      ecx, 0x537f40
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_0054207c]
        shr      ecx, 2
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_00542054], ecx
        mov      byte ptr [g_data_0054371c], bl
        call     DownloadPlayerChar
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      ecx, dword ptr [g_data_004d57ac]
        mov      byte ptr [g_data_0054371c], 0
        mov      eax, dword ptr [ecx*4]
        dec      ecx
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_004d57ac], ecx
        jg       L_ca7f
    L_c687:
        call     ScaledOrAh8CallPauseJmp_0048d0c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, 0x53a510
        shr      eax, 2
        mov      edx, 0x537f48
        mov      dword ptr [g_data_00542054], eax
        mov      eax, dword ptr [g_data_00538158]
        shr      edx, 2
        cmp      ecx, eax
        mov      dword ptr [g_data_00542058], edx
        je       L_c6de
        mov      edx, 0x5380e0
        mov      eax, 0x52aafc
        shr      edx, 2
        shr      eax, 2
        mov      dword ptr [g_data_00542058], edx
        mov      dword ptr [g_data_00542054], eax
    L_c6de:
        call     GuardedBitMaskFlagOrClear_0048c510
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        test     byte ptr [g_data_0054208c], 4
        jne      L_ca5f
        mov      ecx, dword ptr [g_data_00542058]
        mov      eax, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4]
        mov      dword ptr [eax*4 + 0x38], edx
        mov      edx, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_0054207c]
        mov      dword ptr [edx*4], ecx
        mov      eax, dword ptr [g_data_0054207c]
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_0054206c], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4]
        mov      dword ptr [g_data_00542074], edx
        mov      ecx, dword ptr [eax*4 + 0x3c]
        mov      dword ptr [g_data_00542070], ecx
        call     MStackPush2BiasResolveChain_0048cca0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      al, byte ptr [g_data_0054208c]
        mov      edx, dword ptr [g_data_00542060]
        test     al, 4
        jne      L_ca46
        mov      eax, dword ptr [edx*4 + 0x40]
        mov      dword ptr [g_data_0054206c], eax
        call     PushBitFieldMergePop_0048bae0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542058]
        mov      esi, 4
        mov      eax, dword ptr [ecx*4 + 0x30]
        mov      dword ptr [g_data_00542044], eax
        mov      ecx, dword ptr [edx*4]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax*4 + 0x34], ecx
        mov      eax, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_data_00542044], ecx
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [g_data_00542058], eax
        mov      edx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_data_00542048], edx
        mov      dword ptr [eax*4 + 0x18], ecx
        mov      ecx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [ecx*4 + 0x18], eax
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [g_data_00542048]
        mov      dword ptr [edx*4 + 0x18], eax
        mov      edx, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [edx*4 + 0x18], ecx
        mov      eax, dword ptr [g_data_00542058]
        mov      edx, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [eax*4 + 0x1c]
        mov      dword ptr [g_data_0054206c], ecx
        mov      ecx, dword ptr [edx*4 + 0x1c]
        mov      dword ptr [g_data_00542070], ecx
        mov      dword ptr [eax*4 + 0x1c], ecx
        mov      eax, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 0x1c], ecx
        mov      edx, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [g_data_00542058]
        mov      eax, dword ptr [edx*4 + 0x58]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      eax, dword ptr [g_data_00542058]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 0x48], edx
        mov      ecx, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [g_data_0054208c]
        mov      eax, dword ptr [ecx*4 + 0x1c]
        or       edx, esi
        mov      dword ptr [g_data_00542044], eax
        mov      eax, dword ptr [eax*4 + 4]
        mov      dword ptr [g_data_0054208c], edx
        test     eax, eax
        mov      dword ptr [g_data_00542044], eax
        je       L_c8fa
        mov      ecx, edx
        xor      ecx, esi
        test     eax, eax
        mov      dword ptr [g_data_0054208c], ecx
        jle      L_c8fa
        call     BootChainBidirRecurseWalk_00405ca0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
    L_c8fa:
        call     MStackCall_00406740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      ebx, dword ptr [g_data_0054208c]
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_00542058]
        or       ebx, esi
        test     eax, eax
        mov      dword ptr [g_data_0054205c], ecx
        mov      dword ptr [g_data_0054208c], ebx
        je       L_c9d5
        mov      edx, ebx
        xor      edx, esi
        test     eax, eax
        mov      dword ptr [g_data_0054208c], edx
        jle      L_c9d5
        mov      ecx, dword ptr [g_data_004d57ac]
        inc      ecx
        mov      dword ptr [g_data_004d57ac], ecx
        mov      dword ptr [ecx*4], eax
        mov      dword ptr [g_data_0054206c], 0xa
        call     DirtyDoubleDeref_00408cb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      edx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [g_data_004d57ac]
        mov      dword ptr [g_data_00542048], edx
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [g_data_004d57ac], eax
        call     MStackPush2ChainPrepend_00409970
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 0x1c]
        mov      dword ptr [g_data_00542048], eax
        call     PushSetCallCleanup_00408580
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      ecx, dword ptr [g_data_0054205c]
    L_c9d5:
        mov      edx, dword ptr [ecx*4 + 0x34]
        and      dh, 0xf7
        mov      dword ptr [ecx*4 + 0x34], edx
        call     BootMStackBracket3SubdispatchPair_00407920
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        mov      ecx, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [g_data_0054207c]
        mov      eax, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [g_data_0054206c], edx
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_data_00542074], ecx
        call     PushCallPopScaledJmpIndirect_0048ce00
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        call     TwoCallJmp_00478120
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ca97
        call     StackPopDispatchTagged_0041f780
        pop      esi
        pop      ebx
        ret      
    L_ca46:
        mov      eax, dword ptr [edx*4 + 0x38]
        mov      ecx, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4], eax
    L_ca5f:
        mov      dword ptr [esi + 8], 0x48c570
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret      
    L_ca7f:
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [esi + 8], 0x48c570
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_ca97:
        pop      esi
        pop      ebx
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        mov      ebx, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_cb78
        dec      eax
        je       L_cb9c
    L_cad4:
        mov      eax, dword ptr [g_data_0053a430]
        test     eax, eax
        je       L_cae5
        call     CallSetPause_0041f830
        pop      esi
        pop      ebx
        ret      
    L_cae5:
        mov      dword ptr [g_data_0054206c], 0xf
        call     StorePauseImulShr16_004ab630
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb75
        mov      eax, dword ptr [g_data_0054206c]
        mov      ecx, dword ptr [g_data_00538158]
        mov      dword ptr [g_data_0054207c], eax
        mov      dword ptr [g_data_0054205c], ecx
        mov      dword ptr [g_data_00542054], 0x12c
        mov      dword ptr [esi + 8], 0x48caa0
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, 0x48caa0
        add      ecx, 0x1000000
        mov      dword ptr [edx*4 + 0x84], ebx
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
    L_cb44:
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     PendingMatch_0048c570
        mov      dword ptr [g_framePauseFlag], ebx
    L_cb75:
        pop      esi
        pop      ebx
        ret      
    L_cb78:
        mov      dword ptr [g_data_0054206c], 0x1f4
        call     AudioVolumeRescale_004ab690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb75
        test     byte ptr [g_data_0054208c], bl
        je       L_cad4
    L_cb9c:
        mov      eax, dword ptr [g_data_0053a430]
        test     eax, eax
        je       L_cbad
        call     CallSetPause_0041f830
        pop      esi
        pop      ebx
        ret      
    L_cbad:
        mov      dword ptr [g_data_0054206c], 0xf
        call     StorePauseImulShr16_004ab630
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cb75
        mov      ecx, dword ptr [g_data_0054206c]
        mov      edx, dword ptr [g_data_0053815c]
        mov      dword ptr [g_data_0054207c], ecx
        mov      dword ptr [g_data_0054205c], edx
        mov      dword ptr [g_data_00542054], 0x12c
        mov      dword ptr [esi + 8], 0x48caa0
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, 0x48caa0
        add      ecx, 0x2000000
        mov      dword ptr [eax*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        jmp      L_cb44
    }
}

__declspec(naked) void PendingMatch_0046e2e0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_e2ff
        jmp      FiveCallGuardSetTail_0046f6b0
    L_e2ff:
        mov      dword ptr [eax + 8], 0x46e2e0
        mov      ecx, dword ptr [g_data_00542060]
        push     edi
        mov      edi, 0x46e2e0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain_0046fdf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret      
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_00542048]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542048]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [g_data_00542048], 0x46e2a0
        call     Thunk_0049cbd0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e3dd
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542048], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542044], edx
        mov      dword ptr [g_data_004d57ac], eax
    L_e3dd:
        ret      
        nop      
        nop      
        call     ScaledAndAlfe_00490390
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e420
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x602
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        call     TripleCallPauseJmp_00470500
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e420
        push     0x4eb4e8
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_e420:
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
        mov      eax, 0x4eb540
        sar      eax, 2
        mov      dword ptr [g_data_00542054], eax
        jmp      PhaseDispatchListAdvance_004709e0
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
        test     byte ptr [g_data_0054208c], 1
        je       L_e45e
        jmp      CallPauseDirtyMStackPushFn_0046e2a0
    L_e45e:
        call     ScaledAndAlfe_00490390
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e47e
        mov      eax, 0x4eb550
        sar      eax, 2
        mov      dword ptr [g_data_00542054], eax
        jmp      ComboScriptDispatchCluster_00470530
    L_e47e:
        ret      
        nop      
        push     0x4eb568
        call     IterStepScaledStore_0048e600
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_e4a3
        push     0x4eb570
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_e4a3:
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
        mov      eax, dword ptr [g_data_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_e4cf
        jmp      FiveCallGuardSetTail_0046f6b0
    L_e4cf:
        mov      dword ptr [eax + 8], 0x46e4b0
        mov      ecx, dword ptr [g_data_00542060]
        push     edi
        mov      edi, 0x46e4b0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain_0046fdf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret      
        mov      eax, 0x4eb588
        sar      eax, 2
        mov      dword ptr [g_data_00542054], eax
        jmp      PhaseDispatchListAdvance_004709e0
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
        test     byte ptr [g_data_0054208c], 1
        je       L_e55e
        jmp      CallPauseDirtyMStackPushFn_0046e2a0
    L_e55e:
        mov      eax, 0x4eb598
        sar      eax, 2
        mov      dword ptr [g_data_00542054], eax
        jmp      ComboScriptDispatchCluster_00470530
        push     0x4eb5b0
        call     IterStepScaledStore_0048e600
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_e593
        push     0x4eb5b8
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_e593:
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
        mov      eax, dword ptr [g_data_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_e5bf
        jmp      FiveCallGuardSetTail_0046f6b0
    L_e5bf:
        mov      dword ptr [eax + 8], 0x46e5a0
        mov      ecx, dword ptr [g_data_00542060]
        push     edi
        mov      edi, 0x46e5a0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain_0046fdf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret      
        mov      eax, 0x4eb5d0
        sar      eax, 2
        mov      dword ptr [g_data_00542054], eax
        jmp      PhaseDispatchListAdvance_004709e0
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
        test     byte ptr [g_data_0054208c], 1
        je       L_e64e
        jmp      CallPauseDirtyMStackPushFn_0046e2a0
    L_e64e:
        mov      eax, 0x4eb5e0
        sar      eax, 2
        mov      dword ptr [g_data_00542054], eax
        jmp      ComboScriptDispatchCluster_00470530
        push     0x4eb5f8
        call     IterStepScaledStore_0048e600
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_e683
        push     0x4eb600
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_e683:
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
        mov      eax, dword ptr [g_data_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_e6af
        jmp      FiveCallGuardSetTail_0046f6b0
    L_e6af:
        mov      dword ptr [eax + 8], 0x46e690
        mov      ecx, dword ptr [g_data_00542060]
        push     edi
        mov      edi, 0x46e690
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain_0046fdf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret      
        push     0x4eb618
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret      
        nop      
        nop      
        call     ScaledMove74to70_0046eaa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e789
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x603
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [edx*4 + 0x30]
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        je       L_e760
        jmp      FiveThunkMStackDispatcher_0046eac0
    L_e760:
        call     ScaledAndAlfe_00490390
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e789
        call     TripleCallPauseJmp_00470500
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e789
        push     0x4eb640
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_e789:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, 0x4eb658
        sar      eax, 2
        mov      dword ptr [g_data_00542054], eax
        jmp      PhaseDispatchListAdvance_004709e0
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
        test     byte ptr [g_data_0054208c], 1
        je       L_e7be
        jmp      CallPauseDirtyMStackPushFn_0046e2a0
    L_e7be:
        mov      dword ptr [g_data_0054206c], 9
        call     ScaledArrStore_00429960
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e7e8
        mov      eax, 0x4eb668
        sar      eax, 2
        mov      dword ptr [g_data_00542054], eax
        jmp      ComboScriptDispatchCluster_00470530
    L_e7e8:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        push     0x4eb680
        call     IterStepScaledStore_0048e600
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_e813
        push     0x4eb688
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_e813:
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
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_e891
        dec      eax
        je       L_e85c
        push     0x4eb6a0
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        pop      ebx
        ret      
    L_e85c:
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, 0x28f
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      eax, dword ptr [g_data_004d57ac]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], 0x46e2a0
        call     InstallSelfIndirectJmp_0048f3f0
        pop      esi
        pop      ebx
        ret      
    L_e891:
        call     DirtyTestScaledCmpJmp_0046ea70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e998
        call     ScaledZeroFour_00490740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e998
        call     CopyJmp_0048ee80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e998
        mov      eax, dword ptr [g_data_0054206c]
        mov      ebx, 1
        cmp      eax, 0xcccc
        jg       L_e8f2
        call     MStackPush3CmpCall_0048eec0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e998
        test     byte ptr [g_data_0054208c], bl
        je       L_e944
    L_e8f2:
        call     ScaledAndAlfe_00490390
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e998
        mov      edx, 0x4ebec8
        shr      edx, 2
        mov      dword ptr [g_data_00542044], edx
        call     GuardedDirtyXformFromTable_0048f6d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e998
        mov      dword ptr [esi + 8], 0x46e820
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 0xc
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret      
    L_e944:
        call     ScaledMove48to58_00490720
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e998
        call     MStackPushSet0200_00490140
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e998
        mov      eax, 0x4ec0a8
        shr      eax, 2
        mov      dword ptr [g_data_00542044], eax
        call     GuardedDirtyXformFromTable_0048f6d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e998
        mov      dword ptr [esi + 8], 0x46e820
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_data_0054204c], 0xc
        mov      dword ptr [g_framePauseFlag], ebx
    L_e998:
        pop      esi
        pop      ebx
        ret      
    }
}

__declspec(naked) void PendingMatch_004506c0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542054]
        push     ebx
        push     esi
        mov      esi, 0x93
        mov      ecx, dword ptr [eax*4 + 0x58]
        mov      dword ptr [g_data_0054206c], ecx
        mov      edx, dword ptr [eax*4 + 0x48]
        sub      ecx, edx
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_0052d754], ecx
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_0052d750], ecx
        mov      eax, dword ptr [eax*4 + 0x5c]
        mov      dword ptr [g_data_00542044], 0
        mov      dword ptr [g_data_0052d758], eax
        mov      dword ptr [g_data_0054206c], esi
        call     DispatcherComplex138_00476060
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0780
        mov      bl, 4
    L_072d:
        test     byte ptr [g_data_0054208c], bl
        jne      L_0780
        mov      ecx, dword ptr [g_data_00542044]
        mov      edx, dword ptr [g_data_0052d750]
        mov      dword ptr [ecx*4 + 0x54], edx
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_0052d754]
        mov      dword ptr [eax*4 + 0x58], ecx
        mov      eax, dword ptr [g_data_00542044]
        mov      edx, dword ptr [g_data_0052d758]
        mov      dword ptr [eax*4 + 0x5c], edx
        mov      dword ptr [g_data_0054206c], esi
        call     DispatcherComplex138_00476060
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       L_072d
    L_0780:
        pop      esi
        pop      ebx
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
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_07c1
        mov      eax, dword ptr [g_data_00542058]
        dec      eax
        mov      dword ptr [g_data_00542058], eax
        js       L_083b
        jmp      L_07e2
    L_07c1:
        mov      eax, 0x4e7210
        shr      eax, 2
        mov      dword ptr [g_data_00542054], eax
        mov      ecx, dword ptr [eax*4]
        inc      eax
        dec      ecx
        mov      dword ptr [g_data_00542054], eax
        mov      dword ptr [g_data_00542058], ecx
    L_07e2:
        mov      dword ptr [g_data_0054206c], 6
        call     StorePauseImulShr16_004ab630
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0989
        mov      ecx, dword ptr [g_data_0054206c]
        mov      eax, 0x5423f0
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_data_00542044], eax
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_data_0054206c], ecx
        call     PushSetXfmMaskCallPop_00407140
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0989
        test     byte ptr [g_data_0054208c], 4
        je       L_0842
    L_083b:
        call     Thunk_0049cbc0
        pop      esi
        ret      
    L_0842:
        call     MStackCall_00406600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0989
        mov      edx, dword ptr [g_data_00542044]
        mov      eax, 0x93
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x30], eax
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_00542054]
        mov      eax, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_data_00542048], eax
        mov      ecx, dword ptr [ecx*4]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax*4 + 0x30], ecx
        mov      eax, dword ptr [g_data_00542054]
        mov      edx, dword ptr [g_data_00542048]
        inc      eax
        mov      dword ptr [g_data_00542054], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x38], eax
        mov      eax, dword ptr [g_data_00542054]
        mov      ecx, dword ptr [g_data_00542048]
        inc      eax
        mov      dword ptr [g_data_00542054], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      ecx, dword ptr [g_data_00542054]
        mov      edx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [g_data_0052d750]
        inc      ecx
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [edx*4 + 0x54], eax
        mov      ecx, dword ptr [g_data_00542044]
        mov      edx, dword ptr [g_data_0052d754]
        mov      dword ptr [ecx*4 + 0x58], edx
        mov      eax, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_0052d758]
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      dword ptr [g_data_0054206c], 0x51e
        call     AudioMixerStep_004ab700
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0989
        mov      eax, dword ptr [g_data_0054206c]
        mov      edx, dword ptr [g_data_00542044]
        add      eax, 0x51e
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x7c], eax
        mov      ecx, dword ptr [g_data_00542048]
        mov      eax, dword ptr [ecx*4 + 0x20]
        or       ah, 0x10
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x20], eax
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x450790
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_0989:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 4
        ja       L_0ca6
        jmp      dword ptr [eax*4 + L_0d28_jmptbl]
        call     PendingMatch_0043d830
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_0d23
        mov      dword ptr [esi + 8], 0x450990
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 0x55
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret      
        mov      ecx, 0x50d274
        shr      ecx, 2
        mov      dword ptr [g_data_00542048], ecx
        call     MStackPushDispatchBitGate_00407330
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_0d23
        test     byte ptr [g_data_0054208c], 4
        je       L_0a26
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        ret      
    L_0a26:
        call     MStackPushTwoEntryChainCall_004058c0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_0d23
        mov      edx, dword ptr [g_data_00542044]
        push     0x450dc0
        mov      dword ptr [g_data_0054205c], edx
        call     StoreLoadJmp_00404ef0
        mov      ecx, dword ptr [g_data_00542058]
        mov      eax, dword ptr [g_data_0054205c]
        shl      ecx, 2
        shl      eax, 2
        mov      edx, dword ptr [ecx + 0x54]
        add      esp, 4
        mov      dword ptr [eax + 0x54], edx
        mov      edx, 0xfffed3b7
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x58], edx
        mov      edx, dword ptr [ecx + 0x5c]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x5c], edx
        mov      edx, dword ptr [ecx + 0x60]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x60], edx
        mov      edx, dword ptr [ecx + 0x64]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x64], edx
        mov      edx, dword ptr [ecx + 0x68]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x68], edx
        mov      edx, dword ptr [ecx + 0x3c]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x3c], edx
        mov      edx, dword ptr [ecx + 0x3c]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x3c], edx
        mov      ecx, dword ptr [ecx + 0x34]
        mov      dword ptr [g_data_00542070], ecx
        mov      eax, dword ptr [eax + 0x34]
        and      ecx, 1
        and      al, 0xfe
        mov      dword ptr [g_data_00542070], ecx
        or       eax, ecx
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      dword ptr [g_data_0054206c], 0x24
        call     GatedWordPushCall_00489f90
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_0d23
        mov      dword ptr [esi + 8], 0x450990
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], 0x14
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret      
        mov      dword ptr [g_data_0054206c], 0x2e
        call     GatedWordPushCall_00489f90
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_0d23
        push     0x450d40
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     MStackCall_004062f0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_0d23
        mov      dword ptr [g_data_0054206c], 0x10
        call     PushPopCurrentSetFFFFFFFF_00473070
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_0d23
        call     ScaledSaveCallRestoreJmp_00472f80
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_0d23
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, 0x501184
        shr      eax, 2
        mov      dword ptr [edx*4 + 0x28], edi
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x24], eax
        mov      dword ptr [g_data_00542080], 0x9f
        mov      dword ptr [esi + 8], 0x450990
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, 0x450990
        mov      dword ptr [edx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        add      ecx, 0x4000000
        jmp      L_0cf2
        mov      eax, dword ptr [g_data_00542060]
        push     0x451360
        mov      ecx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_data_00542054], ecx
        mov      edx, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_data_00542058], edx
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     0x451ba0
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        mov      eax, 0xa0
        jmp      L_0cab
        push     0x4511f0
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     0x452060
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     DoubleCallChainInit_0043d780
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_0d23
        mov      edx, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_00542084], 0x20ccc
        mov      dword ptr [g_data_0054205c], edx
        call     GameInstall2BodyMul10ScaledInit_00475590
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_0d23
        mov      dword ptr [esi + 8], 0x450990
        mov      dword ptr [esi + 0x84], 1
        mov      dword ptr [g_data_0054204c], 0x10
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret      
    L_0ca6:
        mov      eax, 0x1be
    L_0cab:
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x28], eax
        mov      dword ptr [g_data_00542080], 0x206
        mov      dword ptr [esi + 8], 0x450990
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, 0x450990
        mov      dword ptr [edx*4 + 0x84], 5
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        add      ecx, 0x5000000
    L_0cf2:
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     InstallSelf3WayChainCmp_00428d80
        mov      dword ptr [g_framePauseFlag], 1
    L_0d23:
        pop      edi
        pop      esi
        ret      
        mov      edi, edi
    L_0d28_jmptbl:
        /* 5-entry jump table */
        _emit    0x2c
        _emit    0x0c
        _emit    0x45
        _emit    0x00
        _emit    0xbd
        _emit    0x09
        _emit    0x45
        _emit    0x00
        _emit    0xf6
        _emit    0x09
        _emit    0x45
        _emit    0x00
        _emit    0x26
        _emit    0x0b
        _emit    0x45
        _emit    0x00
        _emit    0xec
        _emit    0x0b
        _emit    0x45
        _emit    0x00
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_0d79
        mov      dword ptr [g_data_0054206c], 0x41
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0d9b
        jmp      Thunk_0049cbc0
    L_0d79:
        mov      ecx, 1
        mov      dword ptr [eax + 8], 0x450d40
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_data_0054204c], 0x89
        mov      dword ptr [g_framePauseFlag], ecx
    L_0d9b:
        ret      
        nop      
        nop      
        nop      
        nop      
        mov      eax, 0x4e7518
        shr      eax, 2
        mov      dword ptr [g_data_00542080], eax
        jmp      InstallSelfIndexWalk_00450de0
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
        mov      eax, 0x4e7508
        shr      eax, 2
        mov      dword ptr [g_data_00542080], eax
        jmp      InstallSelfIndexWalk_00450de0
    }
}

__declspec(naked) void PendingMatch_00471e00(void)
{
    __asm {
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_0054207c]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_00542058]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      ecx, 0x4ec310
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_0054205c]
        shr      ecx, 2
        mov      dword ptr [g_data_00542054], eax
        mov      dword ptr [g_data_00542058], ecx
        mov      dword ptr [g_data_0054206c], 0xc000
        call     ZeroAndDirty4_00405430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        test     byte ptr [g_data_0054208c], 4
        jne      L_1ea9
        mov      edx, 0x4ec360
        mov      dword ptr [g_data_0054206c], 0xd999
        shr      edx, 2
        mov      dword ptr [g_data_00542058], edx
        call     ZeroAndDirty4_00405430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        test     byte ptr [g_data_0054208c], 4
        jne      L_1ea9
        mov      eax, 0x4ec3b0
        shr      eax, 2
        mov      dword ptr [g_data_00542058], eax
    L_1ea9:
        push     0xc0
        push     0x49db40
        mov      dword ptr [g_data_0054207c], 0xc1
        call     StoreTwoCall_0049cb40
        mov      eax, dword ptr [g_data_004d57ac]
        add      esp, 8
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542058], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_0054207c], edx
        mov      dword ptr [g_data_004d57ac], eax
    L_1ef0:
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
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        lea      ebx, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [ebx + 0x84], 0
        sub      eax, 0
        je       L_2118
        dec      eax
        je       L_2062
        mov      ecx, dword ptr [g_data_0054205c]
        mov      esi, dword ptr [g_data_0054208c]
        mov      eax, dword ptr [ecx*4 + 0x18]
        mov      ecx, 4
        or       esi, ecx
        mov      dword ptr [g_data_00542044], eax
        test     eax, eax
        mov      dword ptr [g_data_0054208c], esi
        je       L_205a
        mov      edx, esi
        xor      edx, ecx
        test     eax, eax
        mov      dword ptr [g_data_0054208c], edx
        jne      L_1f72
        call     GuardedSeq_00471670
        pop      esi
        pop      ebx
        ret      
    L_1f72:
        mov      eax, dword ptr [eax*4 + 0x2c]
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        je       L_2045
        mov      esi, 0x28f
    L_1f8b:
        mov      dword ptr [g_data_00542048], eax
        mov      ecx, dword ptr [eax*4 + 0x14]
        lea      eax, [eax*4 + 0x14]
        add      ecx, esi
        mov      dword ptr [g_data_0054206c], esi
        mov      dword ptr [g_data_00542070], ecx
        mov      dword ptr [eax], ecx
        mov      edx, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 8]
        mov      dword ptr [g_data_0054206c], eax
        mov      edx, dword ptr [ecx*4 + 0x58]
        add      eax, edx
        mov      edx, dword ptr [g_data_0054204c]
        mov      dword ptr [g_data_0054206c], eax
        mov      eax, dword ptr [g_data_004d57ac]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [eax*4]
        mov      eax, dword ptr [g_data_0054206c]
        test     eax, eax
        mov      dword ptr [g_data_0054204c], ecx
        jl       L_2019
        call     ChainUnlinkPushFree_0049d150
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2174
    L_2019:
        mov      eax, dword ptr [g_data_0054204c]
        mov      ecx, dword ptr [g_data_004d57ac]
        mov      dword ptr [g_data_0054206c], eax
        mov      edx, dword ptr [ecx*4]
        dec      ecx
        test     eax, eax
        mov      dword ptr [g_data_0054204c], edx
        mov      dword ptr [g_data_004d57ac], ecx
        jne      L_1f8b
    L_2045:
        mov      eax, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [eax*4 + 0x18]
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        jne      L_20cf
    L_205a:
        call     GuardedSeq_00471670
        pop      esi
        pop      ebx
        ret      
    L_2062:
        mov      dword ptr [g_data_00542070], 0x10000
        mov      dword ptr [g_data_00542074], 0xb333
        call     DualEntryRecursiveInstall_00471710
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2174
        mov      ecx, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_data_00542044], ecx
        mov      eax, dword ptr [ecx*4 + 0x20]
        or       al, 0x40
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x20], eax
        mov      edx, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_00542070]
        mov      eax, dword ptr [edx*4 + 0x28]
        mov      dword ptr [g_data_00542048], eax
        mov      dword ptr [eax*4 + 0x2c], ecx
    L_20cf:
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_data_00542044], eax
        call     ChainListVecAdd_0049d200
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2174
        mov      esi, 1
        mov      dword ptr [ebx + 8], 0x471f00
        mov      dword ptr [ebx + 0x84], 2
        mov      dword ptr [g_data_0054204c], esi
        mov      dword ptr [g_framePauseFlag], esi
        pop      esi
        pop      ebx
        ret      
    L_2118:
        mov      dword ptr [ebx + 8], 0x471f00
        mov      ecx, dword ptr [g_data_00542060]
        mov      esi, 1
        mov      edx, 0x471f00
        mov      dword ptr [ecx*4 + 0x84], esi
        mov      eax, dword ptr [ebx + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [ebx + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     TripleCallBitJmp_00471690
        mov      dword ptr [g_framePauseFlag], esi
    L_2174:
        pop      esi
        pop      ebx
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
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        lea      ebx, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [ebx + 0x84], 0
        sub      eax, 0
        je       L_2398
        dec      eax
        je       L_22e2
        mov      ecx, dword ptr [g_data_0054205c]
        mov      esi, dword ptr [g_data_0054208c]
        mov      eax, dword ptr [ecx*4 + 0x18]
        mov      ecx, 4
        or       esi, ecx
        mov      dword ptr [g_data_00542044], eax
        test     eax, eax
        mov      dword ptr [g_data_0054208c], esi
        je       L_22da
        mov      edx, esi
        xor      edx, ecx
        test     eax, eax
        mov      dword ptr [g_data_0054208c], edx
        jne      L_21f2
        call     GuardedSeq_00471670
        pop      esi
        pop      ebx
        ret      
    L_21f2:
        mov      eax, dword ptr [eax*4 + 0x2c]
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        je       L_22c5
        mov      esi, 0x147
    L_220b:
        mov      dword ptr [g_data_00542048], eax
        mov      ecx, dword ptr [eax*4 + 0x14]
        lea      eax, [eax*4 + 0x14]
        add      ecx, esi
        mov      dword ptr [g_data_0054206c], esi
        mov      dword ptr [g_data_00542070], ecx
        mov      dword ptr [eax], ecx
        mov      edx, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 8]
        mov      dword ptr [g_data_0054206c], eax
        mov      edx, dword ptr [ecx*4 + 0x58]
        add      eax, edx
        mov      edx, dword ptr [g_data_0054204c]
        mov      dword ptr [g_data_0054206c], eax
        mov      eax, dword ptr [g_data_004d57ac]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [eax*4]
        mov      eax, dword ptr [g_data_0054206c]
        test     eax, eax
        mov      dword ptr [g_data_0054204c], ecx
        jl       L_2299
        call     ChainUnlinkPushFree_0049d150
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23f4
    L_2299:
        mov      eax, dword ptr [g_data_0054204c]
        mov      ecx, dword ptr [g_data_004d57ac]
        mov      dword ptr [g_data_0054206c], eax
        mov      edx, dword ptr [ecx*4]
        dec      ecx
        test     eax, eax
        mov      dword ptr [g_data_0054204c], edx
        mov      dword ptr [g_data_004d57ac], ecx
        jne      L_220b
    L_22c5:
        mov      eax, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [eax*4 + 0x18]
        test     eax, eax
        mov      dword ptr [g_data_0054206c], eax
        jne      L_234f
    L_22da:
        call     GuardedSeq_00471670
        pop      esi
        pop      ebx
        ret      
    L_22e2:
        mov      dword ptr [g_data_00542070], 0x10000
        mov      dword ptr [g_data_00542074], 0xb333
        call     DualEntryRecursiveInstall_00471710
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23f4
        mov      ecx, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_data_00542044], ecx
        mov      eax, dword ptr [ecx*4 + 0x20]
        or       al, 0x40
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x20], eax
        mov      edx, dword ptr [g_data_00542044]
        mov      ecx, dword ptr [g_data_00542070]
        mov      eax, dword ptr [edx*4 + 0x28]
        mov      dword ptr [g_data_00542048], eax
        mov      dword ptr [eax*4 + 0x2c], ecx
    L_234f:
        mov      edx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_data_00542044], eax
        call     ChainListVecAdd_0049d200
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_23f4
        mov      esi, 1
        mov      dword ptr [ebx + 8], 0x472180
        mov      dword ptr [ebx + 0x84], 2
        mov      dword ptr [g_data_0054204c], esi
        mov      dword ptr [g_framePauseFlag], esi
        pop      esi
        pop      ebx
        ret      
    L_2398:
        mov      dword ptr [ebx + 8], 0x472180
        mov      ecx, dword ptr [g_data_00542060]
        mov      esi, 1
        mov      edx, 0x472180
        mov      dword ptr [ecx*4 + 0x84], esi
        mov      eax, dword ptr [ebx + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [ebx + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     TripleCallBitJmp_00471690
        mov      dword ptr [g_framePauseFlag], esi
    L_23f4:
        pop      esi
        pop      ebx
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
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_2443
        mov      dword ptr [g_data_00542070], 0x10000
        mov      dword ptr [g_data_00542074], 0x9999
        call     DualEntryRecursiveInstall_00471710
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_24a5
        jmp      FsmPoseDualEntry_00472560
    L_2443:
        mov      dword ptr [eax + 8], 0x472400
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x472400
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     TripleCallBitJmp_00471690
        mov      dword ptr [g_framePauseFlag], 1
    L_24a5:
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
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_24f3
        mov      dword ptr [g_data_00542070], 0
        mov      dword ptr [g_data_00542074], 0x2666
        call     DualEntryRecursiveInstall_00471710
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2555
        jmp      FsmPoseDualEntry_00472560
    L_24f3:
        mov      dword ptr [eax + 8], 0x4724b0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x4724b0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     TripleCallBitJmp_00471690
        mov      dword ptr [g_framePauseFlag], 1
    L_2555:
        ret      
    }
}

__declspec(naked) void PendingMatch_00466fc0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        xor      esi, esi
        lea      ebx, [eax*4]
        push     edi
        mov      eax, dword ptr [ebx + 0x84]
        mov      dword ptr [ebx + 0x84], esi
        cmp      eax, esi
        jne      L_6ff8
        mov      ecx, 0x28f
        mov      dword ptr [g_data_00542054], 3
        mov      dword ptr [g_data_00542084], ecx
        jmp      L_6ffe
    L_6ff8:
        mov      ecx, dword ptr [g_data_00542084]
    L_6ffe:
        mov      eax, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [eax*4 + 0x58]
        cmp      edx, 0xfffff334
        mov      dword ptr [g_data_0054206c], edx
        jle      L_70a6
        mov      edx, 0xfffff0a4
        mov      edi, 0xffffee15
    L_7026:
        shl      eax, 2
        mov      dword ptr [eax + 0x70], esi
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x58], edx
        mov      eax, dword ptr [eax + 0x78]
        cmp      eax, esi
        je       L_705a
        jle      L_704c
        sub      eax, 0x3333
        cmp      eax, 0xccc
        jg       L_705a
        jmp      L_7058
    L_704c:
        add      eax, 0x3333
        cmp      eax, 0xfffff334
        jl       L_705a
    L_7058:
        xor      eax, eax
    L_705a:
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [ecx*4 + 0x78], eax
        mov      eax, dword ptr [g_data_00542054]
        dec      eax
        mov      dword ptr [g_data_00542054], eax
        je       L_70da
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], edi
        mov      dword ptr [eax*4 + 0x70], edi
        mov      eax, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [eax*4 + 0x58]
        cmp      ecx, 0xfffff334
        mov      dword ptr [g_data_0054206c], ecx
        jg       L_7026
        mov      ecx, dword ptr [g_data_00542084]
    L_70a6:
        add      ecx, dword ptr [eax*4 + 0x70]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax*4 + 0x70], ecx
        mov      eax, 1
        mov      dword ptr [ebx + 8], 0x466fc0
        mov      dword ptr [ebx + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_70da:
        mov      ecx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_0054206c], esi
        mov      dword ptr [ecx*4 + 0x6c], esi
        call     StackPopDispatchTagged_0041f780
        pop      edi
        pop      esi
        pop      ebx
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
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     ebp
        push     esi
        push     edi
        lea      edi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [edi + 0x84], 0
        sub      eax, 0
        je       L_7415
        dec      eax
        mov      ebp, 1
        mov      ebx, 4
        je       L_7155
        mov      eax, dword ptr [g_data_0054207c]
        inc      eax
        cmp      eax, 0x78
        mov      dword ptr [g_data_0054207c], eax
        jbe      L_7311
        mov      eax, 0x78
        jmp      L_730c
    L_7155:
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4 + 0x48]
        mov      dword ptr [g_data_0054206c], ebp
        mov      dword ptr [g_data_0054205c], edx
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [g_data_0054204c], eax
        mov      edx, dword ptr [ecx*4 + 0x50]
        mov      dword ptr [g_data_0054206c], ebp
        mov      dword ptr [g_data_0054205c], edx
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      ecx, dword ptr [g_data_00542048]
        mov      eax, 0x4e5700
        sar      eax, 2
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 4], eax
        mov      eax, dword ptr [g_data_00542048]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 8], edx
        mov      ecx, dword ptr [g_data_0054204c]
        mov      eax, 0x4e5718
        sar      eax, 2
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 4], eax
        mov      eax, dword ptr [g_data_0054204c]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 8], edx
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4 + 0x4c]
        mov      dword ptr [g_data_0054206c], ebp
        mov      dword ptr [g_data_0054205c], edx
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [g_data_0054204c], eax
        mov      edx, dword ptr [ecx*4 + 0x3c]
        mov      dword ptr [g_data_0054206c], ebp
        mov      dword ptr [g_data_0054205c], edx
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      ecx, dword ptr [g_data_00542048]
        mov      eax, 0x4e5760
        sar      eax, 2
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 4], eax
        mov      eax, dword ptr [g_data_00542048]
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 8], edx
        mov      ecx, dword ptr [g_data_0054204c]
        mov      eax, 0x4e5778
        sar      eax, 2
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 4], eax
        mov      edx, dword ptr [g_data_0054204c]
        mov      eax, dword ptr [g_data_0054206c]
        mov      dword ptr [edx*4 + 8], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_data_00542054], ecx
        mov      edx, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_data_00542058], edx
        mov      dword ptr [g_data_00542074], 0x26e
        mov      dword ptr [g_data_0054204c], 0x467600
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      eax, ebx
    L_730c:
        mov      dword ptr [g_data_0054207c], eax
    L_7311:
        shr      eax, 2
        mov      dword ptr [g_data_00542080], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x40]
        add      ecx, 0xf
        mov      dword ptr [g_data_00542048], ecx
        call     SetJmp_00405420
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        test     byte ptr [g_data_0054208c], bl
        je       L_7368
        mov      edx, 0x4ec1a0
        sar      edx, 2
        mov      dword ptr [g_data_00542070], edx
        call     MStackBracketedStoreTwoCall_004714e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
    L_7368:
        mov      esi, 0x4ec120
        sar      esi, 2
        mov      dword ptr [g_data_00542070], esi
        call     MStackBracketedStoreTwoCall_004714e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      eax, dword ptr [g_data_00542060]
        mov      edx, 0x4ec1a0
        sar      edx, 2
        mov      ecx, dword ptr [eax*4 + 0x44]
        mov      dword ptr [g_data_00542070], edx
        add      ecx, 0xf
        mov      dword ptr [g_data_00542048], ecx
        call     MStackBracketedStoreTwoCall_004714e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        call     SetJmp_00405420
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        test     byte ptr [g_data_0054208c], bl
        je       L_73ef
        mov      dword ptr [g_data_00542070], esi
        call     MStackBracketedStoreTwoCall_004714e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
    L_73ef:
        mov      dword ptr [edi + 8], 0x467100
        mov      dword ptr [edi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 3
        mov      dword ptr [g_framePauseFlag], ebp
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_7415:
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_0054205c], ecx
        call     MStackPush2RunCountdown_004089e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      dword ptr [g_data_0054206c], 3
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_data_00542048]
        mov      ebx, 4
        mov      dword ptr [edx*4 + 0x40], eax
        mov      dword ptr [g_data_0054206c], ebx
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542048]
        mov      dword ptr [ecx*4 + 0x44], edx
        call     ScaledAddrInit_004677e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        test     byte ptr [g_data_0054208c], bl
        je       L_74eb
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_74eb:
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542044]
        mov      dword ptr [eax*4 + 0x48], ecx
        call     ScaledAddrInit_004677c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        test     byte ptr [g_data_0054208c], bl
        je       L_7521
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_7521:
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_data_00542044]
        mov      dword ptr [edx*4 + 0x4c], eax
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [ecx*4 + 0x40]
        mov      dword ptr [g_data_00542048], edx
        call     ScaledAddrInit_004677e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        test     byte ptr [g_data_0054208c], bl
        je       L_756a
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_756a:
        call     ScaledOrStore_004677a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542044]
        mov      dword ptr [eax*4 + 0x50], ecx
        call     ScaledAddrInit_004677c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        test     byte ptr [g_data_0054208c], bl
        je       L_75aa
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_75aa:
        call     ScaledOrStore_004677a0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_75ec
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_data_00542044]
        mov      ebp, 1
        mov      dword ptr [edx*4 + 0x3c], eax
        mov      dword ptr [edi + 8], 0x467100
        mov      dword ptr [edi + 0x84], ebp
        mov      dword ptr [g_data_0054204c], 5
        mov      dword ptr [g_framePauseFlag], ebp
    L_75ec:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
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
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_7667
        dec      eax
        mov      dword ptr [g_data_0054206c], 0x1e
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_770b
        mov      dword ptr [esi + 8], 0x467600
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 0x2f
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_7667:
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542054]
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542058]
        mov      dword ptr [eax*4 + 0x68], ecx
        mov      dword ptr [g_data_0054206c], 0xc
        call     GuardedSeq_00472840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_770b
        mov      dword ptr [g_data_00542074], 0x26f
        mov      dword ptr [g_data_0054204c], 0x467710
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_770b
        mov      dword ptr [g_data_0054206c], 0x2c
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_770b
        mov      edx, dword ptr [g_data_0053a770]
        mov      eax, 1
        mov      dword ptr [g_data_0053a514], edx
        mov      dword ptr [esi + 8], 0x467600
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0xd3
        mov      dword ptr [g_framePauseFlag], eax
    L_770b:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        mov      dword ptr [eax*4 + 0x84], 0
        mov      dword ptr [g_data_0054206c], 3
        lea      esi, [eax*4]
        call     StorePauseImulShr16_004ab630
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7796
        add      dword ptr [g_data_0054206c], 0x1f
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7796
        mov      dword ptr [g_data_0054206c], 0xf
        call     StorePauseImulShr16_004ab630
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7796
        mov      eax, dword ptr [g_data_0054206c]
        add      eax, 0xf
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x467710
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_7796:
        pop      esi
        ret      
    }
}

__declspec(naked) void PendingMatch_00448750(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_879d
        call     DoubleScaledCrossStore_00475750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_880d
        mov      ecx, dword ptr [g_data_00542054]
        push     0x4e62b8
        mov      dword ptr [g_data_0054205c], ecx
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret      
    L_879d:
        mov      edx, 0x501130
        shr      edx, 2
        mov      dword ptr [g_data_00542054], edx
        mov      dword ptr [eax + 8], 0x448750
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x448750
        add      edx, 0x1000000
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     SetJmp_004753a0
        mov      dword ptr [g_framePauseFlag], 1
    L_880d:
        ret      
    }
}


__declspec(naked) void PendingMatch_0044baa0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_data_0054205c], ecx
        call     MStackPush2RunCountdown_004089e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bb27
        mov      dword ptr [g_data_0054206c], 2
        call     ChainDirtyBitWalker_00408c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bb27
        mov      eax, dword ptr [g_data_00542048]
        mov      ecx, dword ptr [eax*4]
        or       ecx, 4
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_data_00542048]
        mov      eax, 0xa0000
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x34], eax
        call     MStackBracket7_DispatchAndChain_004b8fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bb27
        mov      dword ptr [g_data_0054206c], 2
        mov      dword ptr [g_data_00542078], 3
    L_bb27:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_bbcc
        dec      eax
        je       L_bb6a
        mov      eax, dword ptr [g_data_00542054]
        dec      eax
        mov      dword ptr [g_data_00542054], eax
        jns      L_bb82
        call     Thunk_0049cbc0
        pop      esi
        ret      
    L_bb6a:
        mov      ecx, dword ptr [g_data_0053a7a0]
        mov      dword ptr [g_data_00542054], 0x23
        mov      dword ptr [g_data_0054205c], ecx
        jmp      L_bb88
    L_bb82:
        mov      ecx, dword ptr [g_data_0054205c]
    L_bb88:
        mov      eax, dword ptr [ecx*4 + 0x58]
        mov      dword ptr [g_data_00542070], 0x1eb
        add      eax, 0x1eb
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x44bb30
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_bbcc:
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542054]
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542058]
        mov      dword ptr [eax*4 + 0x68], ecx
        call     Chain2AxisDiffStoreTailJmp_0044cad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bc42
        mov      dword ptr [g_data_00542074], 0
        mov      dword ptr [g_data_0054206c], 0xfffe8000
        call     MStackPush3SideStore_0044cb80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bc42
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x44bb30
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0x118
        mov      dword ptr [g_framePauseFlag], eax
    L_bc42:
        pop      esi
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
        mov      eax, dword ptr [g_data_00542060]
        xor      edx, edx
        shl      eax, 2
        push     esi
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        sub      ecx, edx
        je       L_bd03
        dec      ecx
        je       L_bc79
        call     Thunk_0049cbc0
        pop      esi
        ret      
    L_bc79:
        mov      ecx, 0x4e6998
        mov      dword ptr [g_data_0054207c], edx
        shr      ecx, 2
        mov      dword ptr [g_data_00542058], ecx
        mov      ecx, dword ptr [g_data_0053a7a0]
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [g_data_00542088], 0x7ae
        mov      dword ptr [eax + 8], 0x44bc50
        mov      ecx, dword ptr [g_data_00542060]
        mov      esi, 0x44bc50
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      ecx, dword ptr [eax + 4]
        add      esi, 0x2000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], esi
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     EsiInstallSetCbChainExtend_0048a970
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_bd03:
        mov      ecx, 1
        mov      dword ptr [eax + 8], 0x44bc50
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_data_0054204c], 0x1e
        mov      dword ptr [g_framePauseFlag], ecx
        pop      esi
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
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_bdfb
        dec      eax
        je       L_bd7a
        mov      ecx, dword ptr [g_data_00542058]
        push     0x4e64e0
        mov      dword ptr [g_data_0054205c], ecx
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret      
    L_bd7a:
        call     PendingMatch_0043d830
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_be66
        mov      edx, 0x50119c
        mov      ecx, 0x44bd30
        shr      edx, 2
        mov      dword ptr [g_data_00542054], edx
        mov      dword ptr [esi + 8], 0x44bd30
        mov      eax, dword ptr [g_data_00542060]
        add      ecx, 0x2000000
        mov      dword ptr [eax*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfChainAccumPath_004752b0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_bdfb:
        push     0x44bfc0
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     0x44c760
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     DoubleCallChainInit_0043d780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_be66
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [g_data_00542084], 0x11999
        mov      dword ptr [g_data_0054205c], eax
        call     GameInstall2BodyMul10ScaledInit_00475590
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_be66
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x44bd30
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0x10
        mov      dword ptr [g_framePauseFlag], eax
    L_be66:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      dword ptr [g_data_0054206c], 5
        call     GuardedSeq_00472840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_be95
        push     0x4e64f0
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_be95:
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
        push     0x44c150
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     0x4e6500
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        call     Set2CallIncJmp_00472860
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bf0b
        mov      dword ptr [g_data_0054207c], 5
        call     EntryThunkBodyStateMachine_00457bb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bf0b
        mov      dword ptr [g_data_0054206c], 3
        call     GuardedSeq_00472840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bf0b
        push     0x4e6510
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_bf0b:
        ret      
        nop      
        nop      
        nop      
        nop      
        call     Set2CallIncJmp_00472860
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bf5b
        mov      dword ptr [g_data_0054207c], 7
        call     EntryThunkBodyStateMachine_00457bb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bf5b
        mov      dword ptr [g_data_0054206c], 3
        call     GuardedSeq_00472840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bf5b
        push     0x4e6520
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_bf5b:
        ret      
        nop      
        nop      
        nop      
        nop      
        push     0x4e6530
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret      
        nop      
        nop      
        call     Set2CallIncJmp_00472860
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bfbb
        mov      dword ptr [g_data_0054207c], 7
        call     EntryThunkBodyStateMachine_00457bb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bfbb
        mov      dword ptr [g_data_0054206c], 3
        call     GuardedSeq_00472840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bfbb
        push     0x4e6540
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_bfbb:
        ret      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        sub      ecx, 0
        je       L_c0fc
        dec      ecx
        je       L_c08d
        dec      ecx
        je       L_c01c
        call     DoubleScaledCrossStore_00475750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c144
        mov      ecx, dword ptr [g_data_00542054]
        push     0x4e6550
        mov      dword ptr [g_data_0054205c], ecx
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret      
    L_c01c:
        mov      edx, 0x5011cc
        shr      edx, 2
        mov      dword ptr [g_data_00542054], edx
        mov      dword ptr [eax + 8], 0x44bfc0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x44bfc0
        add      edx, 0x3000000
        mov      dword ptr [ecx*4 + 0x84], 3
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     SetJmp_004753a0
        mov      dword ptr [g_framePauseFlag], 1
        ret      
    L_c08d:
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_0054205c], ecx
        mov      dword ptr [eax + 8], 0x44bfc0
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 2
        mov      ecx, dword ptr [eax + 4]
        mov      edx, 0x44bfc0
        mov      dword ptr [g_data_00542044], ecx
        add      edx, 0x2000000
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfPackedTailJmp_004751f0
        mov      dword ptr [g_framePauseFlag], 1
        ret      
    L_c0fc:
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542054]
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542058]
        mov      dword ptr [ecx*4 + 0x68], edx
        mov      ecx, 1
        mov      dword ptr [eax + 8], 0x44bfc0
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_data_0054204c], 0xb
        mov      dword ptr [g_framePauseFlag], ecx
    L_c144:
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
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_data_00542058]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      dword ptr [g_data_0054206c], 0
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c2d1
        mov      dword ptr [g_data_0054206c], 8
        call     GuardedSeq_00472840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c2d1
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [g_data_0054206c], 0xc
        mov      dword ptr [g_data_0054205c], ecx
        call     GuardedSeq_00476de0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c2d1
        call     IntroSequencePipeline_0044cd50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c2d1
        mov      edx, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 0x54]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 0x58]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_data_00542058]
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [edx*4 + 0x5c]
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_00542054]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542054], eax
        call     DualSlotCopyChain_004756f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c2d1
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [g_data_004d57ac], eax
        call     MStackCall_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c2d1
        mov      eax, dword ptr [g_data_00542060]
        push     0x44c2e0
        mov      edx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_data_00542054], edx
        mov      eax, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_data_00542058], eax
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     0x4e6568
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_c2d1:
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
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_c35d
        dec      eax
        jne      L_c3ae
        call     SetJmp_00405420
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c41f
        test     byte ptr [g_data_0054208c], 4
        je       L_c338
        call     CjFieldCopyCascade_0044c430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c41f
    L_c338:
        mov      ebx, 1
        mov      dword ptr [esi + 8], 0x44c2e0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret      
    L_c35d:
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542054]
        push     0x4745e0
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542058]
        mov      dword ptr [eax*4 + 0x68], ecx
        mov      edx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [g_data_0054205c]
        mov      dword ptr [edx*4 + 0x4c], eax
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     0x44c5b0
        call     StoreLoadJmp_00404ef0
        add      esp, 4
    L_c3ae:
        call     SetJmp_00405420
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c41f
        mov      al, byte ptr [g_data_0054208c]
        mov      ebx, 1
        test     al, 4
        jne      L_c3ea
        mov      dword ptr [g_data_0054206c], 0x12c
        call     AudioVolumeRescale_004ab690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c41f
        test     byte ptr [g_data_0054208c], bl
        je       L_c406
    L_c3ea:
        call     CjFieldCopyCascade_0044c430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c41f
        call     PendingMatch_0044c530
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c41f
    L_c406:
        mov      dword ptr [esi + 8], 0x44c2e0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_data_0054204c], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_c41f:
        pop      esi
        pop      ebx
        ret      
    }
}



__declspec(naked) void PendingMatch_00443320(void)
{
    __asm {
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542048]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_data_00542058]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542070]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      ecx, dword ptr [g_data_00542054]
        mov      edx, dword ptr [g_data_00542044]
        shl      ecx, 2
        lea      eax, [edx*4]
        mov      edx, dword ptr [ecx + 0x60]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x60], edx
        mov      edx, dword ptr [ecx + 0x64]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x64], edx
        mov      edx, dword ptr [ecx + 0x68]
        xor      ecx, ecx
        mov      dword ptr [eax + 0x68], edx
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax + 0x78], ecx
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x7c], ecx
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x80], edx
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x6c], ecx
        mov      edx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x70], edx
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax + 0x74], ecx
        mov      eax, dword ptr [eax + 0x18]
        mov      edx, dword ptr [g_data_00542050]
        mov      dword ptr [g_data_00542048], eax
        mov      ecx, dword ptr [eax*4 + 0x20]
        mov      dword ptr [g_data_00542070], 0xa000000
        and      ecx, 0xfaffffff
        or       ecx, 0xa000000
        shl      eax, 2
        shl      edx, 2
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax + 0x20], ecx
        mov      ecx, dword ptr [edx + 0x14]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax + 0x3c], ecx
        mov      ecx, dword ptr [edx + 0x18]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [eax + 0x40], ecx
        mov      edx, dword ptr [edx + 0x1c]
        mov      dword ptr [g_data_0054206c], edx
        mov      dword ptr [eax + 0x44], edx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542070], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542058], edx
        mov      dword ptr [g_data_004d57ac], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_00542048], ecx
        mov      dword ptr [g_data_004d57ac], eax
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
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        je       L_34a9
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        ret      
    L_34a9:
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542054]
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542058]
        mov      dword ptr [eax*4 + 0x68], ecx
        call     Chain2AxisDiffStoreTailJmp_0044cad0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3583
        mov      dword ptr [g_data_00542074], edi
        mov      dword ptr [g_data_0054206c], 0xfffe4000
        call     MStackPush3SideStore_0044cb80
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3583
        mov      eax, dword ptr [g_data_0053a7a0]
        mov      edx, 0x4e5a48
        shr      edx, 2
        mov      dword ptr [g_data_00542058], edx
        mov      dword ptr [g_data_00542054], eax
        mov      dword ptr [g_data_0054207c], edi
        mov      dword ptr [g_data_00542088], 0x28f
        mov      dword ptr [esi + 8], 0x443480
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x443480
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     EsiInstallSetCbChainExtend_0048a970
        mov      dword ptr [g_framePauseFlag], 1
    L_3583:
        pop      edi
        pop      esi
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
        mov      eax, dword ptr [g_data_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_35af
        jmp      Thunk_0049cbc0
    L_35af:
        mov      ecx, dword ptr [g_data_00542060]
        push     edi
        push     esi
        mov      esi, dword ptr [g_data_00542054]
        mov      dword ptr [ecx*4 + 0x64], esi
        mov      esi, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542058]
        mov      edi, 0x443590
        mov      dword ptr [esi*4 + 0x68], ecx
        mov      ecx, 0x4e5ab0
        shr      ecx, 2
        mov      dword ptr [g_data_00542058], ecx
        mov      ecx, dword ptr [g_data_0053a7a0]
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [g_data_00542084], 0x40000
        mov      dword ptr [eax + 8], 0x443590
        mov      ecx, dword ptr [g_data_00542060]
        mov      esi, 1
        add      edi, 0x1000000
        mov      dword ptr [ecx*4 + 0x84], esi
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     InitStateDualCall48ac70_0048ac70
        mov      dword ptr [g_framePauseFlag], esi
        pop      esi
        pop      edi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_3754
        dec      eax
        je       L_372c
        dec      eax
        je       L_3697
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        ret      
    L_3697:
        push     0x443800
        call     StoreLoadJmp_00404ef0
        mov      edx, dword ptr [g_data_0053a7a0]
        mov      ecx, 0x4e5b80
        shr      ecx, 2
        mov      dword ptr [g_data_00542058], ecx
        mov      dword ptr [g_data_00542054], edx
        mov      dword ptr [g_data_0054207c], edi
        mov      dword ptr [g_data_00542088], 0xf5c
        mov      dword ptr [esi + 8], 0x443660
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, 0x443660
        add      esp, 4
        mov      dword ptr [eax*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x3000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     EsiInstallSetCbChainExtend_0048a970
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret      
    L_372c:
        mov      dword ptr [esi + 8], 0x443660
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], 0x8c
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret      
    L_3754:
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542054]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542058]
        mov      ecx, 0x4e5b18
        mov      dword ptr [eax*4 + 0x68], edx
        mov      edx, dword ptr [g_data_0053a7a0]
        shr      ecx, 2
        mov      dword ptr [g_data_00542058], ecx
        mov      dword ptr [g_data_00542054], edx
        mov      dword ptr [g_data_00542084], 0x40000
        mov      dword ptr [esi + 8], 0x443660
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, 0x443660
        add      ecx, 0x1000000
        mov      dword ptr [eax*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     InitStateDualCall48ac70_0048ac70
        pop      edi
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        jne      L_382a
        mov      edx, dword ptr [g_data_0053a7a0]
        mov      dword ptr [g_data_00542054], edx
        jmp      L_3830
    L_382a:
        mov      edx, dword ptr [g_data_00542054]
    L_3830:
        mov      ecx, dword ptr [edx*4 + 0x58]
        mov      dword ptr [g_data_00542070], 0x147
        add      ecx, 0x147
        cmp      ecx, 0xffff0000
        mov      dword ptr [g_data_0054206c], ecx
        jl       L_386b
        mov      eax, 0xfffecccd
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x58], eax
        jmp      Thunk_0049cbc0
    L_386b:
        mov      dword ptr [edx*4 + 0x58], ecx
        mov      ecx, 1
        mov      dword ptr [eax + 8], 0x443800
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_data_0054204c], ecx
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
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_38e8
        call     PendingMatch_0043d830
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3989
        push     0x4e5260
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret      
    L_38e8:
        push     0x445040
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     0x443f30
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        call     DoubleCallChainInit_0043d780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3989
        mov      ecx, dword ptr [g_data_00542058]
        mov      edx, 0x501034
        shr      edx, 2
        mov      dword ptr [g_data_0054205c], ecx
        mov      dword ptr [g_data_00542054], edx
        mov      dword ptr [esi + 8], 0x4438a0
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, 0x4438a0
        mov      dword ptr [eax*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x1000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfChainAccumPath_004752b0
        mov      dword ptr [g_framePauseFlag], 1
    L_3989:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      dword ptr [g_data_0054206c], 0xe
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        mov      dword ptr [g_data_0054206c], 0x2e
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        call     CopyJmp_00445ec0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        call     CopyLoadInstallJmp_00445ed0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        call     ScaledInitPauseDirtyStore_00445f00
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        test     byte ptr [g_data_0054208c], 4
        je       L_3a0c
        jmp      PendingMatch_00443d20
    L_3a0c:
        call     InitZeroSixFields_00445f40
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        call     SetWalk0xaCrossStore_00445fb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        call     SpecialInitDirtyJmp_00446000
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        test     byte ptr [g_data_0054208c], 4
        je       L_3a44
        jmp      PendingMatch_00443d20
    L_3a44:
        call     FourFieldCopyCallSet_00446040
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        call     CopyScaledTriple_00446120
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        call     TripleSetCallPauseDirtyJmp_00446150
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3a88
        push     0x443d30
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     0x4e5270
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_3a88:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      dword ptr [g_data_0054206c], 0xf
        call     GatedWordPushCall_00489f90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3ac2
        push     0x444580
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     0x4e5280
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_3ac2:
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
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_3aff
        push     0x4e5290
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret      
    L_3aff:
        mov      ecx, 0x501034
        mov      dword ptr [g_data_00542080], 0x69
        shr      ecx, 2
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [g_data_00542084], 0x1958
        mov      dword ptr [g_data_00542088], 0x1999
        mov      dword ptr [g_data_00542058], 0
        mov      dword ptr [eax + 8], 0x443ad0
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      edx, 0x443ad0
        mov      dword ptr [g_data_00542044], ecx
        add      edx, 0x1000000
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfAccumOverflow_00428b20
        mov      dword ptr [g_framePauseFlag], 1
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_3bcf
        push     0x4e52a0
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret      
    L_3bcf:
        mov      ecx, 0x501034
        mov      dword ptr [g_data_00542080], 0x69
        shr      ecx, 2
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [g_data_00542084], 0x1332
        mov      dword ptr [g_data_00542088], 0x1333
        mov      dword ptr [g_data_00542058], 0
        mov      dword ptr [eax + 8], 0x443ba0
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      edx, 0x443ba0
        mov      dword ptr [g_data_00542044], ecx
        add      edx, 0x1000000
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfAccumOverflow_00428b20
        mov      dword ptr [g_framePauseFlag], 1
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_3c9f
        push     0x4e52b8
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret      
    L_3c9f:
        mov      ecx, 0x500350
        shr      ecx, 2
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [eax + 8], 0x443c70
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      edx, 0x443c70
        mov      dword ptr [g_data_00542044], ecx
        add      edx, 0x1000000
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfChainAccumPath_004752b0
        mov      dword ptr [g_framePauseFlag], 1
        ret      
        jmp      Thunk_0049cbc0
    }
}

__declspec(naked) void PendingMatch_0045b620(void)
{
    __asm {
    L_b620:
        test     byte ptr [g_data_0054208c], 1
        je       L_b62e
        jmp      MoveListCursorCluster_0045b420
    L_b62e:
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b641
        jmp      PendingMatch_00459510
    L_b641:
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
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b678
        mov      eax, dword ptr [g_data_0054206c]
        mov      dword ptr [g_data_00542044], eax
        call     eax
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b678
        _emit    0xe9
        _emit    0xa8
        _emit    0xff
        _emit    0xff
        _emit    0xff
    L_b678:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        call     GuardedDualConst2AndToggle_0048eba0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b6af
        test     byte ptr [g_data_0054208c], 1
        je       L_b69c
        _emit    0xe9
        _emit    0x84
        _emit    0xff
        _emit    0xff
        _emit    0xff
    L_b69c:
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b6af
        jmp      PendingMatch_00459510
    L_b6af:
        ret      
        call     MStackPush3CmpCall_0048eec0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b729
        test     byte ptr [g_data_0054208c], 1
        jne      L_b6e9
        mov      eax, dword ptr [g_data_0054205c]
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_data_0054206c], eax
        and      eax, 0x200
        mov      dword ptr [g_data_00542094], eax
        je       L_b716
        jmp      MoveListCursorCluster_0045b420
    L_b6e9:
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [ecx*4 + 0x38]
        mov      dword ptr [g_data_00542044], eax
        mov      eax, dword ptr [eax*4 + 0x40]
        mov      dword ptr [g_data_00542070], eax
        and      eax, 4
        mov      dword ptr [g_data_00542094], eax
        je       L_b716
        jmp      MoveListCursorCluster_0045b420
    L_b716:
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b729
        jmp      PendingMatch_00459510
    L_b729:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_b74f
        jmp      PendingMatch_00459510
    L_b74f:
        mov      dword ptr [eax + 8], 0x45b730
        mov      ecx, dword ptr [g_data_00542060]
        push     edi
        mov      edi, 0x45b730
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     InstallSelfBitGated_00428eb0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_b7d9
        call     PendingMatch_00459510
        pop      esi
        ret      
    L_b7d9:
        call     PauseTestCmp2CallStore_0045bfe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b85a
        mov      eax, dword ptr [g_data_00542070]
        mov      edx, 0x45b7b0
        and      eax, 0xff
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [g_data_00542080], eax
        mov      dword ptr [esi + 8], 0x45b7b0
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     ScaledClearJmp_00428e90
        mov      dword ptr [g_framePauseFlag], 1
    L_b85a:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_b889
        call     PendingMatch_00459510
        pop      esi
        ret      
    L_b889:
        call     PauseTestCmp2CallStore_0045bfe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b90a
        mov      eax, dword ptr [g_data_00542070]
        mov      edx, 0x45b860
        and      eax, 0xff
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [g_data_00542080], eax
        mov      dword ptr [esi + 8], 0x45b860
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfDualCountdown_00429050
        mov      dword ptr [g_framePauseFlag], 1
    L_b90a:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_b939
        call     PendingMatch_00459510
        pop      esi
        ret      
    L_b939:
        call     PauseTestCmp2CallStore_0045bfe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b9ba
        mov      eax, dword ptr [g_data_00542070]
        mov      edx, 0x45b910
        and      eax, 0xff
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [g_data_00542080], eax
        mov      dword ptr [esi + 8], 0x45b910
        mov      ecx, dword ptr [g_data_00542060]
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     ScaledClearJmp_00428d40
        mov      dword ptr [g_framePauseFlag], 1
    L_b9ba:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_b9e9
        call     PendingMatch_00459510
        pop      esi
        ret      
    L_b9e9:
        call     PauseTestCmp2CallStore_0045bfe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ba56
        mov      dword ptr [esi + 8], 0x45b9c0
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, 0x45b9c0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     ScaledClearJmp_00428d60
        mov      dword ptr [g_framePauseFlag], 1
    L_ba56:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        call     PauseTestCmp2CallStore_0045bfe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ba95
        mov      eax, dword ptr [g_data_00542070]
        and      eax, 0xff
        mov      dword ptr [g_data_00542070], eax
        mov      dword ptr [g_data_00542080], eax
        call     ScaledArrStore_00429980
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_ba95
        jmp      PendingMatch_00459510
    L_ba95:
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
        mov      eax, dword ptr [g_data_00542060]
        xor      edx, edx
        shl      eax, 2
        push     edi
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_bac2
        call     PendingMatch_00459510
        pop      edi
        ret      
    L_bac2:
        mov      edi, dword ptr [g_data_00542070]
        mov      ecx, dword ptr [g_framePauseFlag]
        and      edi, 0xff
        cmp      ecx, edx
        mov      dword ptr [g_data_00542070], edi
        jne      L_bb44
        mov      ecx, edi
        mov      edi, 0x45baa0
        mov      dword ptr [g_data_00542080], ecx
        mov      dword ptr [eax + 8], 0x45baa0
        mov      ecx, dword ptr [g_data_00542060]
        add      edi, 0x1000000
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_data_00542044]
        inc      ecx
        mov      dword ptr [g_data_00542044], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     EsiInstallChainCmpDualCall_00429300
        mov      dword ptr [g_framePauseFlag], 1
    L_bb44:
        pop      edi
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
        mov      eax, 1
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_00537f04], eax
        jmp      PendingMatch_00459510
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
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_bb9d
        dec      eax
        je       L_bbbe
        call     PendingMatch_00459510
        pop      esi
        ret      
    L_bb9d:
        mov      ecx, dword ptr [g_data_00542070]
        mov      eax, dword ptr [g_framePauseFlag]
        and      ecx, 0xff
        test     eax, eax
        mov      dword ptr [g_data_00542070], ecx
        jne      L_bc12
        mov      dword ptr [g_data_00542080], ecx
    L_bbbe:
        call     DispatcherComplex197_0045be40
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bc12
        mov      edx, dword ptr [g_data_0054206c]
        mov      eax, dword ptr [g_data_00542080]
        cmp      edx, eax
        mov      dword ptr [esi + 8], 0x45bb70
        jl       L_bbfd
        mov      eax, 1
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_bbfd:
        mov      eax, 1
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_bc12:
        pop      esi
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
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_bc4d
        dec      eax
        je       L_bc6e
        call     PendingMatch_00459510
        pop      esi
        ret      
    L_bc4d:
        mov      ecx, dword ptr [g_data_00542070]
        mov      eax, dword ptr [g_framePauseFlag]
        and      ecx, 0xff
        test     eax, eax
        mov      dword ptr [g_data_00542070], ecx
        jne      L_bcc2
        mov      dword ptr [g_data_00542080], ecx
    L_bc6e:
        call     DispatcherComplex197_0045bf10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bcc2
        mov      edx, dword ptr [g_data_0054206c]
        mov      eax, dword ptr [g_data_00542080]
        cmp      edx, eax
        mov      dword ptr [esi + 8], 0x45bc20
        jg       L_bcad
        mov      eax, 1
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_bcad:
        mov      eax, 1
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_bcc2:
        pop      esi
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
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_bcf9
        call     PendingMatch_00459510
        pop      esi
        ret      
    L_bcf9:
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bd73
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [g_data_00542054], ecx
        mov      dword ptr [esi + 8], 0x45bcd0
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, 0x45bcd0
        add      ecx, 0x1000000
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfMidPush_0045bd80
        mov      dword ptr [g_framePauseFlag], 1
    L_bd73:
        pop      esi
        ret      
    }
}
