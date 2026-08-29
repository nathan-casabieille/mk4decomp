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
extern unsigned int g_walkBoundsLimit;
extern unsigned int g_walkBoundsSlot;
extern unsigned int g_pendingClear;
extern unsigned int g_xformEntityIdxSrc;
extern unsigned int g_eventQueueSeed;
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
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueSeed (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_pendingClear (*(unsigned int *)MK4_VA(unsigned int, 0x53a3ccu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkBoundsLimit (*(unsigned int *)MK4_VA(unsigned int, 0x535d60u))
#define g_walkBoundsSlot (*(unsigned int *)MK4_VA(unsigned int, 0x535d68u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformEntityIdxSrc (*(unsigned int *)MK4_VA(unsigned int, 0x541facu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


/* @addr 0x00431260 (256b game) - 5-field copy from indexed table to chain.
 *   eax = g_eventQueueSeed (chain base); ecx = g_xformEntityIdxSrc (table idx).
 *   g_currentNodeIdx = eax; g_xformEntityIdx = ecx.
 *   Initial: chain[+0x54] = table[+0]. Then 4 more iterations:
 *     idx++; chain[+0x58/+0x5c/+0x60/+0x64] = table[+idx]; g_walkCallback=value.
 *   Then idx++; chain[+0x68] = table[+idx] (no g_walkCallback set).
 *   Then idx++ (final increment).
 *   Set g_pendingClear=0, g_walkBoundsSlot=0, g_walkCallback=0xffff0000,
 *   g_walkBoundsLimit=0xffff0000; ret.
 */
#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* @addr 0x00431260 (256b) - NATIVE twin; the matching build keeps the
 * body below.
 *
 * Copies six sequential words from the source cursor into the seed node's
 * +0x54..+0x68 fields, advancing the cursor as it goes, then clears the
 * two walk-bounds slots and arms the limit at 0xffff0000. This is the
 * per-match transfer of the staged fight parameters into the live node. */
void FiveFieldChainCopyTableWalk(void)
{
    unsigned int node, w;

    g_currentNodeIdx = *MK4_VA(unsigned int, 0x52ab10u);
    g_xformEntityIdx = *MK4_VA(unsigned int, 0x541facu);
    node = g_currentNodeIdx;

    w = *MK4_NODE(unsigned int, g_xformEntityIdx);
    g_walkCallback = w;
    MK4_NODE_AT(unsigned int, node, 0x54) = w;
    g_xformEntityIdx++;
    w = *MK4_NODE(unsigned int, g_xformEntityIdx);
    g_walkCallback = w;
    MK4_NODE_AT(unsigned int, node, 0x58) = w;
    g_xformEntityIdx++;
    w = *MK4_NODE(unsigned int, g_xformEntityIdx);
    g_walkCallback = w;
    MK4_NODE_AT(unsigned int, node, 0x5c) = w;
    g_xformEntityIdx++;
    w = *MK4_NODE(unsigned int, g_xformEntityIdx);
    g_walkCallback = w;
    MK4_NODE_AT(unsigned int, node, 0x60) = w;
    g_xformEntityIdx++;
    w = *MK4_NODE(unsigned int, g_xformEntityIdx);
    g_walkCallback = w;
    MK4_NODE_AT(unsigned int, node, 0x64) = w;
    g_xformEntityIdx++;
    w = *MK4_NODE(unsigned int, g_xformEntityIdx);
    MK4_NODE_AT(unsigned int, node, 0x68) = w;
    g_xformEntityIdx++;

    *MK4_VA(unsigned int, 0x53a3ccu) = 0;
    *MK4_VA(unsigned int, 0x535d68u) = 0;
    g_walkCallback = 0xffff0000u;
    *MK4_VA(unsigned int, 0x535d60u) = 0xffff0000u;
}
#else
void FiveFieldChainCopyTableWalk(void) {
    g_currentNodeIdx = g_eventQueueSeed;
    g_xformEntityIdx = g_xformEntityIdxSrc;
    g_walkCallback = *(unsigned int *)(g_xformEntityIdx * 4);
    ((ScenegraphNode *)(g_currentNodeIdx * 4))->position_x = g_walkCallback;
    g_xformEntityIdx++;
    g_walkCallback = *(unsigned int *)(g_xformEntityIdx * 4);
    ((ScenegraphNode *)(g_currentNodeIdx * 4))->position_y = g_walkCallback;
    g_xformEntityIdx++;
    g_walkCallback = *(unsigned int *)(g_xformEntityIdx * 4);
    ((ScenegraphNode *)(g_currentNodeIdx * 4))->position_z = g_walkCallback;
    g_xformEntityIdx++;
    g_walkCallback = *(unsigned int *)(g_xformEntityIdx * 4);
    *(unsigned int *)(g_currentNodeIdx * 4 + 0x60) = g_walkCallback;
    g_xformEntityIdx++;
    g_walkCallback = *(unsigned int *)(g_xformEntityIdx * 4);
    *(unsigned int *)(g_currentNodeIdx * 4 + 0x64) = g_walkCallback;
    g_xformEntityIdx++;
    *(unsigned int *)(g_currentNodeIdx * 4 + 0x68) = *(unsigned int *)(g_xformEntityIdx * 4);
    g_xformEntityIdx++;
    g_pendingClear = 0;
    g_walkBoundsSlot = 0;
    g_walkCallback = 0xffff0000;
    g_walkBoundsLimit = 0xffff0000;
}
#endif
