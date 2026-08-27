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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_bootChainState4;
extern unsigned int g_chainInsertSlot;   /* 0x0053a168 */
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
#define g_bootChainState4 (*(unsigned int *)MK4_VA(unsigned int, 0x541eb0u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_chainInsertSlot (*(unsigned int *)MK4_VA(unsigned int, 0x53a168u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void LinkedListInsert(void);

/*
 * @addr 0x004055b0 (119b boot) - dirty-set + push-call-pop guard:
 *   set state bit 2; if walk is null exit; else clear bit 2 and
 *   re-test walk; if still null exit; push wt onto state stack, load
 *   g_bootChainState4 into wt, call LinkedListInsert; on pause clear pop wt.
 */
#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Written from the disassembly, and it does NOT agree with the matching-side
 * body further down. That one tests g_walkCallback (0x54206c) and brackets
 * g_eventQueueWorkType (0x542074); 0x004055b0 tests g_currentNodeIdx
 * (0x542044) and brackets g_xformEntityIdx (0x542048). The bytes settle it -
 * and the mismatch is invisible to `make matching`, which synthesizes this
 * function from the original rather than compiling that source, so nothing
 * ever checked it. The seeded co-exec run is what found it.
 *
 * The matrix stack is also addressed through the seam here: the matching
 * spelling dereferences the PACKED INDEX directly, which is right on a flat
 * 32-bit image and lands outside the arena. */
void DirtyPushCallPop(void) {
    g_xformDirtyFlags |= 4;
    if (g_currentNodeIdx == 0) return;
    g_xformDirtyFlags ^= 4;
    if (g_currentNodeIdx == 0) return;
    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_xformEntityIdx;
    g_xformEntityIdx = g_bootChainState4;
    LinkedListInsert();
    if (g_framePauseFlag) return;
    g_xformEntityIdx = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
}

/* @addr 0x004ab440 (199b) - NATIVE ONLY.
 *
 * There is no C source for this in the matching build; the synthesizer takes
 * it from the original bytes, and symbols.yaml names this file as where it
 * WOULD live. So it is written here under NON_MATCHING only, and the matching
 * build is untouched.
 *
 * Prepends the current node to a list head, brackets by pushing two globals
 * onto the matrix stack. Straight-line, no branches.
 *
 * The link field is not a plain pointer: the insertion point is
 * `head[+4] + node`, an offset ADDED to the node index, and the head's
 * element count at +8 is bumped. g_pendingNodeType is written twice - once
 * with the raw node, once with the computed slot - and both stores are kept. */
void LinkedListInsert(void)
{
    unsigned int node, head;

    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_chainInsertSlot;
    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_pendingNodeType;

    node = g_currentNodeIdx;
    head = g_xformEntityIdx;
    g_pendingNodeType = node;
    g_pendingNodeType = MK4_NODE_AT(unsigned int, head, 4) + node;
    MK4_NODE_AT(unsigned int, g_pendingNodeType, 4) = head;

    g_walkCallback = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0);
    MK4_NODE_AT(unsigned int, g_pendingNodeType, 0) = g_walkCallback;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0) = g_currentNodeIdx;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 8) += 1;

    g_pendingNodeType = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
    g_chainInsertSlot = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
}
#else
void DirtyPushCallPop(void) {
    g_xformDirtyFlags |= 4;
    if (g_walkCallback == 0) return;
    g_xformDirtyFlags ^= 4;
    if (g_walkCallback == 0) return;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueWorkType;
    g_eventQueueWorkType = g_bootChainState4;
    LinkedListInsert();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}
#endif
