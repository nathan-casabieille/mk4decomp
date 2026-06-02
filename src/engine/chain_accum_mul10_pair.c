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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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
extern unsigned int g_matrixStack_arr;

/* @addr 0x00490b70 (191b game) - chain[+0x58] accumulate, then 2 Mul10 calls + chain[+0x54,+0x5c] accumulate.
 *   chain[g_fightGroupHead + 0x58] += g_walkCallback; g_eventQueueWorkType = result.
 *   g_scaledInit = chain[g_baseSel + 0x40]; push packed_ptr[g_scaledInit], g_eventQueueCurrent;
 *   call Mul10Tail; g_walkCallback = result; add esp,8.
 *   g_scaledInit = chain[g_baseSel + 0x44]; eax = packed_ptr[g_scaledInit];
 *   g_eventQueueWorkType = eax; push eax, g_eventQueueCurrent; call Mul10Tail; add esp,8.
 *   g_eventQueueWorkType = result; chain[g_fightGroupHead + 0x54] += g_walkCallback; g_eventQueueCurrent = sum.
 *   chain[g_fightGroupHead + 0x5c] += g_eventQueueWorkType; g_eventQueueCurrent = sum.
 */
void ChainAccumMul10Pair_00490b70(void) {
    unsigned int v;
    v = g_walkCallback + ((ScenegraphNode *)(g_fightGroupHead * 4))->position_y;
    g_eventQueueWorkType = v;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->position_y = v;
    g_scaledInit_00542044 = ((ScenegraphNode *)(g_baseSel * 4))->child_b;
    g_walkCallback = (&g_matrixStack_arr)[g_scaledInit_00542044];
    g_walkCallback = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(
        g_eventQueueCurrent, g_walkCallback);
    g_scaledInit_00542044 = ((ScenegraphNode *)(g_baseSel * 4))->child_c;
    g_eventQueueWorkType = (&g_matrixStack_arr)[g_scaledInit_00542044];
    g_eventQueueWorkType = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(
        g_eventQueueCurrent, g_eventQueueWorkType);
    v = g_walkCallback + ((ScenegraphNode *)(g_fightGroupHead * 4))->position_x;
    g_eventQueueCurrent = v;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->position_x = v;
    v = g_eventQueueWorkType + ((ScenegraphNode *)(g_fightGroupHead * 4))->position_z;
    g_eventQueueCurrent = v;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->position_z = v;
}
