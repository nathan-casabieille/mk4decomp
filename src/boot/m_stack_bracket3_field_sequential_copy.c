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
extern void CopyJmp_0048ef90(void);
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

extern void ScaledArrStore_004298c0(void);
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
extern void GuardedDispatch_0042b6c0(void);
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

extern void ModelRenderDispatch(void);
extern void TripleMul10TailIndexed(void);
extern void TripleAddVec3(void);
extern void MStackBracket3_FieldSequentialCopy(void);
extern unsigned int g_dispatchSave607_004d78d8;
extern unsigned int g_savedNode;

/*
 * BootInitTripleAddChain - 203b boot pause-gated init.
 *   Call ModelRenderDispatch; if paused: ret.
 *   Snapshot g_currentNodeIdx → g_xformEntityIdx; g_currentNodeIdx = g_savedNode; g_pendingNodeType = (0x004d78d8>>2).
 *   Call QuadInterpolator; if paused: ret.
 *   g_eventQueueCurrent = 0xcccc; g_eventQueueWorkType = 0x13333; call TripleMul10TailIndexed; if paused: ret.
 *   g_xformEntityIdx = g_fightGroupHead + 0x15; call MStackBracket3_FieldSequentialCopy; if paused or g_xformDirtyFlags & 4: ret.
 *   eax = g_currentNodeIdx; g_xformEntityIdx = eax + 0x1b; g_currentNodeIdx = eax + 0x15; g_pendingNodeType = eax + 0x15.
 *   Call TripleAddVec3; if paused: ret. Call TripleAddVec3; if paused: ret. Tail-jmp TripleAddVec3.
 */
void BootInitTripleAddChain(void)
{
    unsigned int v;
    ModelRenderDispatch();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = g_currentNodeIdx;
    g_currentNodeIdx = g_savedNode;
    g_pendingNodeType = (unsigned int)&g_dispatchSave607_004d78d8 >> 2;
    QuadInterpolator();
    if (g_framePauseFlag != 0) return;
    g_eventQueueCurrent = 0xcccc;
    g_eventQueueWorkType = 0x13333;
    TripleMul10TailIndexed();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = g_fightGroupHead + 0x15;
    MStackBracket3_FieldSequentialCopy();
    if (g_framePauseFlag != 0) return;
    if (g_xformDirtyFlags & 4) return;
    v = g_currentNodeIdx;
    g_xformEntityIdx = v + 0x1b;
    v += 0x15;
    g_currentNodeIdx = v;
    g_pendingNodeType = v;
    TripleAddVec3();
    if (g_framePauseFlag != 0) return;
    TripleAddVec3();
    if (g_framePauseFlag != 0) return;
    TripleAddVec3();
}
