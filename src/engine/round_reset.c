/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

extern unsigned int g_tickFlagF;
extern u32 g_dlSomeFlag2;
extern unsigned int g_quadEntryGate;
extern unsigned int g_phaseTimer;
extern unsigned int g_dst_00537ea4;
extern unsigned int g_dispatchSave_00537ef4;
extern unsigned int g_dispatchVar11;
extern unsigned int g_hitPhase;
extern unsigned int g_audioBank2State;
extern unsigned int g_fightTickSavedSlot;
extern unsigned int g_roundResetSlot;
extern unsigned int g_phaseInstallSlot;
extern unsigned int g_audioStreamState;
extern unsigned int g_phaseThunkArr;
extern u32 g_dlSomeFlag1;
extern unsigned int g_dst_0053a6e0;
extern unsigned int g_phaseThunkSlot4;
extern unsigned int g_phaseThunkState;
extern unsigned int g_dispatchSave39;
extern unsigned int g_dispatchClr1;
extern unsigned int g_installCountdownSlot2;
extern unsigned int g_smState4Way;
extern unsigned int g_titleDemoState;
extern unsigned int g_titleDemoState2;
extern u32 g_dlState;
extern u32 g_dlAux;
extern unsigned int g_dispatchSave37;
extern unsigned int g_clusterArr541f60_n6;
extern unsigned int g_clusterArr541f60_n5;
extern unsigned int g_clusterArr541f60_n4;
extern unsigned int g_clusterArr541f60_n3;
extern unsigned int g_clusterArr541f60_n2;
extern unsigned int g_clusterArr541f60_n1;
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
extern unsigned int g_tripleEntryFlag;
extern void Cmp2DirtyToggle(void);
extern void TestCmpZeroFour(void);
extern void TriBranchFlagWrite(void);
extern void TwoStateCopyDup(void);

__declspec(naked) void RoundReset(void)
{
    __asm {
        push     ebx
        call     Cmp2DirtyToggle
        mov      eax, dword ptr [g_framePauseFlag]
        xor      ebx, ebx
        cmp      eax, ebx
        jne      L_25e9
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_240f
        call     TwoStateCopyDup
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_25e9
    L_240f:
        mov      eax, dword ptr [g_tickFlagF]
        cmp      eax, 2
        mov      dword ptr [g_walkCallback], eax
        jne      short L_242f
        call     TestCmpZeroFour
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_25e9
    L_242f:
        mov      eax, 0x10000
        mov      dword ptr [g_roundResetSlot], eax
        mov      dword ptr [g_phaseThunkArr], eax
        mov      eax, dword ptr [g_hitPhase]
        cmp      eax, 1
        mov      dword ptr [g_walkCallback], eax
        jne      short L_2459
        mov      dword ptr [g_dst_0053a6e0], ebx
        mov      dword ptr [g_dst_00537ea4], ebx
    L_2459:
        mov      dword ptr [g_titleDemoState], ebx
        mov      dword ptr [g_titleDemoState2], ebx
        mov      byte ptr [g_tripleEntryFlag], bl
        mov      dword ptr [g_phaseThunkSlot4], ebx
        mov      dword ptr [g_dispatchSave39], ebx
        mov      dword ptr [g_dispatchClr1], ebx
        mov      dword ptr [g_smState4Way], ebx
        mov      dword ptr [g_phaseTimer], ebx
        mov      dword ptr [g_phaseInstallSlot], ebx
        mov      dword ptr [g_dispatchSave_00537ef4], ebx
        mov      dword ptr [g_audioBankSel], ebx
        mov      dword ptr [g_quadEntryGate], ebx
        mov      dword ptr [g_audioBank2State], ebx
        mov      dword ptr [g_phaseThunkState], ebx
        mov      dword ptr [g_installCountdownSlot2], ebx
        mov      dword ptr [g_audioStreamState], ebx
        mov      dword ptr [g_dispatchVar11], ebx
        mov      dword ptr [g_dlSomeFlag1], ebx
        mov      dword ptr [g_dlSomeFlag2], ebx
        mov      dword ptr [g_dlState], ebx
        mov      dword ptr [g_dlAux], ebx
        mov      dword ptr [g_fightTickSavedSlot], ebx
        mov      dword ptr [g_clusterArr541f60_n6], ebx
        mov      dword ptr [g_dispatchSave37], ebx
        mov      dword ptr [g_clusterArr541f60_n4], ebx
        mov      dword ptr [g_clusterArr541f60_n5], ebx
        mov      dword ptr [g_clusterArr541f60_n2], ebx
        mov      dword ptr [g_clusterArr541f60_n3], ebx
        mov      dword ptr [g_clusterArr541f60_10], ebx
        mov      dword ptr [g_clusterArr541f60_n1], ebx
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
        call     TriBranchFlagWrite
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      short L_25e9
        mov      eax, dword ptr [g_gtFightTickCounter]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_fightTickSavedSlot], eax
    L_25e9:
        pop      ebx
        ret
    }
}
