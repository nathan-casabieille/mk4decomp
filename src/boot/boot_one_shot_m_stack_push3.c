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
extern unsigned int g_dispatchVar42_004d5ed0;
extern void ThreeChanPackClamp_00404cc0(void);
extern void CopyThreeFields_00404df0(void);

/* @addr 0x0040c100 (337b boot) - boot one-shot setup w/ MStack-push-3.
 *   Pushes 0x806000 onto ThreeChanPackClamp_00404cc0 (audio volume?),
 *   passes g_fightGroupHead to CopyThreeFields_00404df0, then calls
 *   SetJmp_00405420. On no-error AND bit 2 of g_xformDirtyFlags set:
 *   mstack-pushes g_xformEntityIdx/00542054/0054205c (3 entries). Caches
 *   g_fightGroupHead into g_eventQueueEnd, sets g_walkCallback =
 *   &g_dispatchVar42_004d5ed0>>2, calls PushSetXfmMaskCallPop_00407140.
 *   On no-error AND bit 2 NOT set: calls ScaledChainOr8_00404e50,
 *   writes 0x18000 into [g_xformEntityIdx*4 + 0x48], calls
 *   ScaledTripleCopy54_004ac040. On no-error sets g_currentNodeIdx =
 *   g_fightGroupHead, g_walkCallback=0xff, calls
 *   PushSetDualDeref_00406650 → MStackCall_00406600. Pops the 3
 *   mstack entries back into 0054205c/00542054/00542048 in reverse.
 */
void BootOneShotMStackPush3_0040c100(void) {
    ((void (*)(int))ThreeChanPackClamp_00404cc0)(0x806000);
    ((void (*)(unsigned int))CopyThreeFields_00404df0)(g_fightGroupHead);
    SetJmp_00405420();
    if (g_framePauseFlag != 0) return;
    if (!(g_xformDirtyFlags & 4)) return;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_xformEntityIdx;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueEnd;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_fightGroupHead;
    g_eventQueueEnd = g_fightGroupHead;
    g_walkCallback = (unsigned int)&g_dispatchVar42_004d5ed0 >> 2;
    PushSetXfmMaskCallPop_00407140();
    if (g_framePauseFlag != 0) return;
    if (!(g_xformDirtyFlags & 4)) {
        ScaledChainOr8_00404e50();
        g_walkCallback = 0x18000;
        *(unsigned int *)(g_xformEntityIdx * 4 + 0x48) = 0x18000;
        ScaledTripleCopy54_004ac040();
        if (g_framePauseFlag != 0) return;
        g_walkCallback = 0xff;
        g_currentNodeIdx = g_fightGroupHead;
        PushSetDualDeref_00406650();
        if (g_framePauseFlag != 0) return;
        MStackCall_00406600();
        if (g_framePauseFlag != 0) return;
    }
    g_fightGroupHead = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
    g_eventQueueEnd = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
    g_xformEntityIdx = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}
