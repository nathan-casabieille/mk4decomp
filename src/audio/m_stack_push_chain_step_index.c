/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
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
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
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
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
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
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
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

/*
 * MStackPushChainStepIndex - 240b audio chain-step with mstack push2.
 *   ecx = g_currentNodeIdx[0]; g_walkCallback = ecx; g_xformDirtyFlags |= 4.
 *   If ecx == 0: g_currentNodeIdx = 0; ret. Else: g_xformDirtyFlags ^= 4.
 *   If ecx == 0 (still): g_currentNodeIdx = 0; ret. Else: mstack-push ecx, then g_xformEntityIdx;
 *   ecx = g_currentNodeIdx; eax = chain[ecx*4 + 4] + g_walkCallback → g_xformEntityIdx; chain[0] = chain[eax*4];
 *   chain[g_xformEntityIdx*4 + 4] = 0; chain[g_xformEntityIdx*4] = g_walkCallback; pop2 mstack into
 *   g_xformEntityIdx and g_walkCallback; g_currentNodeIdx = (last popped); ret.
 */
void MStackPushChainStepIndex(void)
{
    unsigned int chain;
    unsigned int idx;
    unsigned int new_idx;
    chain = *(unsigned int *)(g_currentNodeIdx * 4);
    g_walkCallback = chain;
    g_xformDirtyFlags |= 4;
    if (chain == 0) {
        g_currentNodeIdx = chain;
        return;
    }
    g_xformDirtyFlags ^= 4;
    if (chain == 0) {
        g_currentNodeIdx = chain;
        return;
    }
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = chain;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_xformEntityIdx;
    idx = g_currentNodeIdx;
    new_idx = *(unsigned int *)(idx * 4 + 4) + g_walkCallback;
    g_xformEntityIdx = new_idx;
    *(unsigned int *)(idx * 4) = *(unsigned int *)(new_idx * 4);
    g_walkCallback = 0;
    *(unsigned int *)(new_idx * 4 + 4) = 0;
    *(unsigned int *)(new_idx * 4) = 0;
    g_xformEntityIdx = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
    chain = *(unsigned int *)(g_matrixStackTop * 4);
    g_walkCallback = chain;
    g_matrixStackTop--;
    g_currentNodeIdx = chain;
}
