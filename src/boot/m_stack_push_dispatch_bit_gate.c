/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

/* @addr 0x004b8ec0 (92b)
 *   eax = arg0; g_dispatchSave1559 = eax;
 *   ecx = eax + 0x200; edx = eax + 0x400;
 *   g_dispatchSave1560 = ecx; g_dispatchSave1561 = edx;
 *   ecx = eax + 0x580; edx = eax + 0x680;
 *   g_dispatchSave1562 = ecx; g_dispatchSave1563 = edx;
 *   ecx = eax + 0x720; edx = eax + 0x780;
 *   eax += 0x7c0; g_dispatchSave1564=ecx; g_dispatchSave1565=edx;
 *   g_dispatchSave1566=eax; ret.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1559;
extern unsigned int g_dispatchSave1560;
extern unsigned int g_dispatchSave1561;
extern unsigned int g_dispatchSave1562;
extern unsigned int g_dispatchSave1563;
extern unsigned int g_dispatchSave1564;
extern unsigned int g_dispatchSave1565;
extern unsigned int g_dispatchSave1566;
#endif
extern void MStackBracket5_LinkedListUnlink(void);
extern void CountdownClampWalk(void);
extern void DownloadPlayerChar(void);
extern void DualWalkRange(void);
extern void BootDispatchSlotInit(void);
extern void CjInstallSelfRouter(void);
extern void ScaledChainCallPauseSetJmp(void);
extern void MStackBracket2_TreeWalkRecursive(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void CallPauseScaledStoreCopyJmp(void);
extern void ScaledArrStore_GuardedChainCmpDualBitXor_00429980(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_counter_0053a51c;
extern unsigned int g_tickFlagF;
extern unsigned int g_hitPhase;
#endif
extern void StreamChainStringInstall(void);
extern void StorePauseImulShr16(void);
extern void Mul10TailPairMidChain(void);
extern void NotShrCmp1Store(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
extern void FpuSqrtMul(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dualB_00538038;
extern unsigned int g_dualB_0053803c;
extern unsigned int g_bootInitSaveSlot;
#endif
extern void TripleSubVec3(void);
extern void Mul10SumSqrt(void);
extern void MStackPushTableWalk(void);
extern void LoadCmpAddrJmp(void);
extern void ScaledInitOrSelfPtrSetType_0046a5e0(void);
extern void ScaledStoreCSet58Jmp(void);
extern void CjTableThresholdDispatch(void);
extern void GateDispatch6c(void);
extern void TwoEntryWrapperGuarded(void);
extern void DualGatedStateYield(void);
extern void DualScaledInitCmp_0046dbd0(void);
extern void FlagCascadeStateSet(void);
extern void MoveDispatch4StateFsm(void);
extern void IdCascadeBitSet(void);
extern void Scaled3StorePushCallJmp(void);
extern void Thunk_InstallSelfChainSet2011(void);
extern void StateDispatchYield(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchState;
extern unsigned int g_stateFlag;
#endif
extern void PushPopState70Mask(void);
extern void Thunk_LinkedListBitMaskSearch(void);
extern void CopyJmp_ScaledSubStore_g_currentNodeIdx(void);
extern void ScaledChain3c74(void);
extern void ScaledChain3c7c(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void PendingMatch_0046cd30(void);
extern void Phase3InstallPackedSelf(void);
extern void ZeroSlotsGatedDispatch(void);
extern void GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void);
extern void ScaledInitOrSelfPtr_CallPauseDirty1JmpDirty4StackPush(void);
extern void MStackPush2ChainSwap(void);
extern void CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx(void);
extern void DivLongPushCall(void);
extern void ScaledDecPop_00404c40(void);
extern void ScaledDecPop_00404bd0(void);
extern void TripleMul10VecJmpFpu(void);
extern void DownloadPlayerChar_Variant(void);
extern void TripleStateSwapCall(void);
extern void Atan2QuadrantLookup(void);
extern void InstallSelfChainSet2011(void);
extern void GuardedChainPushSetCallPop(void);
extern void MStackPushSet0001(void);
extern void ScaledInit_GuardedDirtyXformFromTable_g_scaledInit(void);
extern void ScaledZero44(void);
extern void ScaledChainNegStore(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void CallPauseScaledDecJmp(void);
extern void PushPop84TripleCall(void);
extern void Vec3DeltaDualMul10(void);
extern void FiveCallGuardSetTail(void);
extern void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void);
extern void Thunk_InstallSelfChainSetB333v2(void);
extern void HitReactionDispatcher(void);
extern void Cmp2DirtyToggle(void);
extern void ScaledClear1cTestWalkCall(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackPush3LinkedListWalk(void);
extern void MStackScopedSlotSetupPair(void);
extern void ChainSetupBitToggle(void);
extern void MstackPopScaledChainPlusThunks(void);
extern void InstallSelfCmdStreamInterp(void);
extern void DirtyDoubleDeref(void);
extern void DispatchSwitchWalkCmp(void);
extern void Wrapper_CmpDualPatchScaledRangeJmp_004e4850(void);
extern void ScaledAndCheckJmp(void);
extern void AudioVolumeRescale(void);
extern void CallPauseConstStoreJmp_MultiThunkDispatcher_then_InstallSelfPair(void);
extern void InstallSelfPair(void);
extern void MStackPushSet6Jmp(void);
extern void MStackPushSet0Jmp(void);
extern void GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7b(void);
extern void GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7d(void);
extern void Push70CallScaleArith(void);
extern void StateGateMStackOverlap(void);
extern void ChainDecCondStoreCallJmp(void);
extern void ScaledAddDeref(void);
extern void MStackPush2ChainLLInsert(void);
extern void ScaledLitAddJmp(void);
extern void MStackPushDispatchBitGate(void);
extern void PushDualDerefClearPop(void);
extern void MStackPushTwoEntryChainCall(void);
extern void PushPopScaled18(void);
extern void PushCallSet2147Jmp(void);
extern void TableLookupCall_g_eventTbl_112(void);
extern void CmpEqInitCallElseJmp(void);
extern void MStackAngleRatioSubchain(void);
extern void PushStackAllocCall(void);
extern void DualScaledInitClear(void);
extern void ScaledShrAnd(void);
extern void DualEntryBitFlagDispatch(void);
extern void SlotPhaseResetInstallChain(void);
extern void RoundEndDifferenceFsmCluster(void);
extern void ClampNegPair(void);
extern void Vec2SumMul10ChainCompute(void);
extern void GuardedSeq_MStackCall_then_CallSetPause_0049a650(void);
extern void AtanDualDeltaThreshold(void);
extern void Set43DualCallJmp(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_scaledArgChain;
extern unsigned int g_distRefX;
extern unsigned int g_distRefZ;
extern unsigned int g_eventQueueSeed;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_bootInitSaveSlot (*(unsigned int *)MK4_VA(unsigned int, 0x541dc4u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_counter_0053a51c (*(unsigned int *)MK4_VA(unsigned int, 0x53a51cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1559 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d9cu))
#define g_dispatchSave1560 (*(unsigned int *)MK4_VA(unsigned int, 0xab4da0u))
#define g_dispatchSave1561 (*(unsigned int *)MK4_VA(unsigned int, 0xab4da4u))
#define g_dispatchSave1562 (*(unsigned int *)MK4_VA(unsigned int, 0xab4da8u))
#define g_dispatchSave1563 (*(unsigned int *)MK4_VA(unsigned int, 0xab4dacu))
#define g_dispatchSave1564 (*(unsigned int *)MK4_VA(unsigned int, 0xab4db0u))
#define g_dispatchSave1565 (*(unsigned int *)MK4_VA(unsigned int, 0xab4db4u))
#define g_dispatchSave1566 (*(unsigned int *)MK4_VA(unsigned int, 0xab4db8u))
#define g_dispatchState (*(unsigned int *)MK4_VA(unsigned int, 0x53a478u))
#define g_distRefX (*(unsigned int *)MK4_VA(unsigned int, 0x52ab04u))
#define g_distRefZ (*(unsigned int *)MK4_VA(unsigned int, 0x52ab08u))
#define g_dlNalt1 (*(int *)MK4_VA(int, 0x537f48u))
#define g_dlNalt2 (*(int *)MK4_VA(int, 0x5380e0u))
#define g_dualB_00538038 (*(unsigned int *)MK4_VA(unsigned int, 0x538038u))
#define g_dualB_0053803c (*(unsigned int *)MK4_VA(unsigned int, 0x53803cu))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueSeed (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_hitPhase (*(unsigned int *)MK4_VA(unsigned int, 0x537f30u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_scaledArgChain (*(unsigned int *)MK4_VA(unsigned int, 0x541e68u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_stateFlag (*(unsigned int *)MK4_VA(unsigned int, 0x537e98u))
#define g_tickFlagF (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern unsigned int g_dataArr_00535cfc;
extern unsigned int g_dataArr_0053a1d0;
#ifdef NON_MATCHING
#include "portable/mem_model.h"
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackPush3LinkedListWalk(void);
extern void MStackPush2ChainLLInsert(void);

/* @addr 0x00407330 (205b) - NATIVE ONLY; the matching build synthesizes it.
 *
 * The scene-build entry. Brackets the entity, runs the DC260 tree walk to
 * BUILD the node, and if that found one: installs its element list, walks
 * that list, and - only if the walk came back not-found - falls back to the
 * chain insert, publishing null afterwards. The built node is parked in
 * g_fightGroupHead the whole way, which is what the callers read. The tail
 * signals not-found when nothing was built. This is the function that
 * actually allocates scene nodes; everything below it was already
 * converted. */
void MStackPushDispatchBitGate(void)
{
    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_xformEntityIdx;

    DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
    if (g_framePauseFlag != 0) return;          /* bracket leaked */

#ifdef TARGET_SDL
    /* MK4_TRACE_FREEPOP family: what the scene build RETURNS as the
     * built node - the value the caller's write-back will adopt. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int f = -1; static int n;
      if (f < 0) f = getenv("MK4_TRACE_FREEPOP") != 0;
      if (f && n < 40) { n++;
          SDL_Log("BUILT n44=%x dirty=%x tmpl=%x", g_currentNodeIdx,
                  g_xformDirtyFlags, *MK4_VA(unsigned int, 0x542048u)); } }
#endif
    g_fightGroupHead = g_currentNodeIdx;
    if ((g_xformDirtyFlags & 4u) == 0) {
        MStackBracket4_ListInsertZeroFill();
        if (g_framePauseFlag != 0) return;
#ifdef TARGET_SDL
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      static int f2 = -1; static int n2;
      if (f2 < 0) f2 = getenv("MK4_TRACE_FREEPOP") != 0;
      if (f2 && n2 < 40) { n2++;
          SDL_Log("BUILT2 n44=%x g5c=%x dirty=%x", g_currentNodeIdx,
                  g_fightGroupHead, g_xformDirtyFlags); } }
#endif
        if ((g_xformDirtyFlags & 4u) == 0) {
            MStackPush3LinkedListWalk();
            if (g_framePauseFlag != 0) return;
        }
        if (g_xformDirtyFlags & 4u) {
            MStackPush2ChainLLInsert();
            if (g_framePauseFlag != 0) return;
            g_currentNodeIdx = 0;
            g_fightGroupHead = 0;
        }
    }

    g_xformEntityIdx = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
    g_xformDirtyFlags |= 4;
    if (g_currentNodeIdx != 0) g_xformDirtyFlags ^= 4;
}
#else
/* no matching-side C - the synthesizer provides 0x00407330. */
#endif

#ifndef NON_MATCHING /* stale QQ-split copy; canonical: countdown_clamp_walk.c */
void Helper_TickInit(unsigned int base) {
    g_dispatchSave1559 = base;
    g_dispatchSave1560 = base + 0x200;
    g_dispatchSave1561 = base + 0x400;
    g_dispatchSave1562 = base + 0x580;
    g_dispatchSave1563 = base + 0x680;
    g_dispatchSave1564 = base + 0x720;
    g_dispatchSave1565 = base + 0x780;
    g_dispatchSave1566 = base + 0x7c0;
}
#endif
