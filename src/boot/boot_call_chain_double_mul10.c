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
extern unsigned int g_dispatchSave907;

/*
 * BootCallChainDoubleMul10 - 217b boot init via StoreTwoCall + dual Mul10.
 *   Snapshot g_fightGroupHead → g_eventQueueEnd; g_cj_00542058 = (0x004d6478 >> 2);
 *   g_eventQueueNotMask = 0xc1; push 0xc0, 0x0049db40; call StoreTwoCall.
 *   If g_xformDirtyFlags & 1: ret. Call StackPushAdd15CallPop; if paused: ret.
 *   g_eventQueueCurrent = 0x3333; load g_fightGroupHead[+0x6c] → eax → g_walkCallback;
 *   push (eax,0x3333); call Mul10Tail; chain[+0x44] = result.
 *   g_walkCallback = 0; chain[+0x48] = 0;
 *   load g_fightGroupHead[+0x74] → eax → g_walkCallback; push (eax, g_eventQueueCurrent);
 *   call Mul10Tail; chain[+0x4c] = result; ret.
 */
void BootCallChainDoubleMul10(void) {
    unsigned int v;
    g_eventQueueEnd = g_fightGroupHead;
    g_cj_00542058 = (unsigned int)&g_dispatchSave907 >> 2;
    g_eventQueueNotMask = 0xc1;
    ((void (*)(int, int))StoreTwoCall)(0x0049db40, 0xc0);
    if (g_xformDirtyFlags & 1) return;
    StackPushAdd15CallPop();
    if (g_framePauseFlag != 0) return;
    g_eventQueueCurrent = 0x3333;
    v = *(unsigned int *)(g_fightGroupHead * 4 + 0x6c);
    g_walkCallback = v;
    v = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(0x3333, v);
    ((ScenegraphNode *)(g_currentNodeIdx * 4))->child_c = v;
    g_walkCallback = 0;
    *(unsigned int *)(g_currentNodeIdx * 4 + 0x48) = 0;
    v = ((ScenegraphNode *)(g_fightGroupHead * 4))->fsm_state;
    g_walkCallback = v;
    v = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_eventQueueCurrent, v);
    g_walkCallback = v;
    *(unsigned int *)(g_currentNodeIdx * 4 + 0x4c) = v;
}
