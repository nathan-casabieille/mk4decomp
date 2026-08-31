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
extern unsigned int g_bootChainState3;
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
#define g_bootChainState3 (*(unsigned int *)MK4_VA(unsigned int, 0x541e98u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_chainInsertSlot (*(unsigned int *)MK4_VA(unsigned int, 0x53a168u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
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
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void MStackPush2ChainPrepend(void);

/*
 * @addr 0x00406530 (118b boot) - push-set-call-pop: push wt onto
 *   state stack, OR walk[+0x34] |= 0xc2, set walk[+0x5c]=0x10000,
 *   load g_bootChainState3 into wt and call MStackPush2ChainPrepend; on pause clear
 *   pop wt back from state stack.
 */

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* @addr 0x00409970 (296b) - NATIVE ONLY; the matching build synthesizes it.
 *
 * LinkedListInsert's sibling with the link direction reversed: PREPENDS the
 * current node to the relative list at g_xformEntityIdx, under the same
 * two-value bracket (g_chainInsertSlot, g_pendingNodeType). The new node's
 * back slot (at node + head[+8]) takes the head, its forward link is zeroed,
 * and the OLD first element - head[+4] - gets the node written either into
 * its own slot at +8-offset (list non-empty) or into the head's [0] (empty).
 * head[+4] then points at the node and the element count at +0xc is bumped.
 * g_walkCallback ends the call holding the old first element. */
void MStackPush2ChainPrepend(void)
{
    unsigned int node, head, slot, old;

    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_chainInsertSlot;
    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_pendingNodeType;

    node = g_currentNodeIdx;
    head = g_xformEntityIdx;
    g_pendingNodeType = node;
    slot = MK4_NODE_AT(unsigned int, head, 8) + node;
    g_pendingNodeType = slot;
    MK4_NODE_AT(unsigned int, slot, 4) = head;

    g_walkCallback = 0;
    *MK4_NODE(unsigned int, g_pendingNodeType) = 0;

    old = MK4_NODE_AT(unsigned int, head, 4);
    g_walkCallback = old;
    MK4_NODE_AT(unsigned int, g_pendingNodeType, 8) = old;

    if (MK4_NODE_AT(unsigned int, head, 4) == 0) {
        *MK4_NODE(unsigned int, head) = g_currentNodeIdx;
    } else {
        g_pendingNodeType = g_walkCallback;
        g_pendingNodeType = MK4_NODE_AT(unsigned int, head, 8) + g_walkCallback;
        *MK4_NODE(unsigned int, g_pendingNodeType) = g_currentNodeIdx;
    }

    MK4_NODE_AT(unsigned int, head, 4) = g_currentNodeIdx;
    MK4_NODE_AT(unsigned int, head, 0xc) += 1;

    g_pendingNodeType = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
    g_chainInsertSlot = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
}
/* @addr 0x00406530 (118b) - NATIVE ONLY; the matching build synthesizes it.
 *
 * The mode-select screen's state 3 calls this twice, once per title record,
 * to hand the freshly placed node to the chain-prepend under a save of the
 * relative head. It marks the node 0xc2 (visible + the two walk bits) and
 * plants +0x5c = 0x10000. The pause exit skips the pop, as the original
 * does. */
void PushSetCallPop(void)
{
    unsigned int top, node;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_xformEntityIdx;

    node = g_currentNodeIdx;
    MK4_NODE_AT(unsigned int, node, 0x34) |= 0xc2u;
    g_walkCallback = 0x10000;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = 0x10000;

    g_xformEntityIdx = g_bootChainState3;
    MStackPush2ChainPrepend();
    if (g_framePauseFlag != 0)
        return;

    top = g_matrixStackTop;
    g_xformEntityIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}
#else
/* no matching-side C - the synthesizer provides 0x00409970; the empty branch
 * exists because the co-exec extractor recognises a twin only as an
 * ifdef/else pair. */
#endif

#ifndef NON_MATCHING   /* naked body - matched, kept for the synthesizer */
void PushSetCallPop(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [eax*4 + 0x34]
        or      cl, 0xc2
        mov     dword ptr [eax*4 + 0x34], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, 0x00010000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x5c], eax
        mov     eax, dword ptr [g_bootChainState3]
        mov     dword ptr [g_xformEntityIdx], eax
        call    MStackPush2ChainPrepend
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     done
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
done:
        }
}
#endif

