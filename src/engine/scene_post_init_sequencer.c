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
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern s32 g_dlNalt3;
extern s32 g_dlNalt4;
extern unsigned int g_counter_0053a51c;
extern unsigned int g_rangeBase;
extern unsigned char g_dispatchSave623;
#endif
extern void TablePushAccumTailJmp(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave658;
extern unsigned int g_dispatchSave659;
extern unsigned int g_dispatchSave656;
extern unsigned int g_dispatchSave657;
extern unsigned int g_particleEmitterNode;
extern unsigned int g_pendingMatchAudio2;
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
#define g_counter_0053a51c (*(unsigned int *)MK4_VA(unsigned int, 0x53a51cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave623 (*(unsigned char *)MK4_VA(unsigned char, 0x4dfd48u))
#define g_dispatchSave656 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5300u))
#define g_dispatchSave657 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5304u))
#define g_dispatchSave658 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5308u))
#define g_dispatchSave659 (*(unsigned int *)MK4_VA(unsigned int, 0x4d530cu))
#define g_dlNalt1 (*(int *)MK4_VA(int, 0x537f48u))
#define g_dlNalt2 (*(int *)MK4_VA(int, 0x5380e0u))
#define g_dlNalt3 (*(int *)MK4_VA(int, 0x53a178u))
#define g_dlNalt4 (*(int *)MK4_VA(int, 0x53a250u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_iatPtr_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_particleEmitterNode (*(unsigned int *)MK4_VA(unsigned int, 0x535e6cu))
#define g_pendingMatchAudio2 (*(unsigned int *)MK4_VA(unsigned int, 0x53a7a8u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void MStackPush8(void);
extern void TwinLoopSlotFinder(void);
extern void *AllocNode(void);
extern void CopyGlobal(void);
extern void PendingMatch_BootStateTriple(void);
extern void MStackPushDispatchBitGate(void);
extern void MStackPush4LLWalkPop4(void);
extern void InstallSelfDispatch(void);
extern void MStackCall_MStackPush2ChainPrepend_00406390(void);
extern void MStackPop8(void);

/* @addr 0x00429b70 (691b game) */
#ifdef NON_MATCHING
#include "portable/mem_model.h"
extern void MStackPush8(void);
extern void TwinLoopSlotFinder(void);
extern void CopyGlobal(void);
extern void PendingMatch_BootStateTriple(void);
extern void MStackPushDispatchBitGate(void);
extern void MStackPush4LLWalkPop4(void);
extern void InstallSelfDispatch(void);
extern void MStackCall_MStackPush2ChainPrepend_00406390(void);
extern void MStackPop8(void);

/* @addr 0x00429b70 (691b) - NATIVE ONLY; the matching build synthesizes it.
 *
 * The scene post-init. This is the function that gets a fight's scene
 * BUILT: everything above it in the chain only decides which record to
 * build from, and everything below it (the bit-gate dispatcher, the tree
 * walk, the list installer, the allocator) was already converted.
 *
 * It brackets eight slots, finds a twin loop slot, and - when the source
 * record's +0x3c is set - allocates two work nodes. It then copies six
 * fields out of that record into the particle-emitter node and the
 * dispatch save block, runs the state triple, and hands the record's +0xc
 * to MStackPushDispatchBitGate, which is where the scene nodes are
 * actually allocated and chained. What comes back in g_fightGroupHead is
 * stamped as state 0xb, linked to the emitter, optionally walked (+0x14)
 * and installed (+0x10), prepended to the chain, and finally handed to the
 * record's own +8 callback if it has one. */
void ScenePostInitSequencer(void)
{
    unsigned int rec, v, node;

    MStackPush8();
    if (g_framePauseFlag != 0) return;
    TwinLoopSlotFinder();
    if (g_framePauseFlag != 0) return;

    rec = g_iatPtr_00542058;
    v = MK4_NODE_AT(unsigned int, rec, 0x3c);
    g_pendingNodeType = v;
    if (v != 0) {
        g_eventQueueNotMask = 1;
        g_eventQueueWorkType = 0x10;
        AllocNode();
        if (g_framePauseFlag != 0) return;
        g_eventQueueNotMask = 2;
        g_eventQueueWorkType = 0x10;
        AllocNode();
        if (g_framePauseFlag != 0) return;
    }

    g_walkCallback = MK4_NODE_AT(unsigned int, g_iatPtr_00542058, 0x18);
    CopyGlobal();
    if (g_framePauseFlag != 0) return;

    rec = g_iatPtr_00542058;
    g_walkCallback = MK4_NODE_AT(unsigned int, rec, 0x1c);
    *MK4_VA(unsigned int, 0x4d5308u) = g_walkCallback;
    g_walkCallback = MK4_NODE_AT(unsigned int, rec, 0x20);
    *MK4_VA(unsigned int, 0x4d530cu) = g_walkCallback;
    g_walkCallback = MK4_NODE_AT(unsigned int, rec, 0x24);
    *MK4_VA(unsigned int, 0x4d5300u) = g_walkCallback;
    g_walkCallback = MK4_NODE_AT(unsigned int, rec, 0x28);
    *MK4_VA(unsigned int, 0x4d5304u) = g_walkCallback;

    PendingMatch_BootStateTriple();
    if (g_framePauseFlag != 0) return;

    node = *MK4_VA(unsigned int, 0x535e6cu);      /* particle emitter node */
    g_currentNodeIdx = node;
    g_walkCallback = MK4_NODE_AT(unsigned int, g_iatPtr_00542058, 0x2c);
    MK4_NODE_AT(unsigned int, node, 0x54) = g_walkCallback;
    g_walkCallback = MK4_NODE_AT(unsigned int, g_iatPtr_00542058, 0x30);
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x58) = g_walkCallback;
    g_walkCallback = MK4_NODE_AT(unsigned int, g_iatPtr_00542058, 0x34);
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x5c) = g_walkCallback;
    g_walkCallback = MK4_NODE_AT(unsigned int, g_iatPtr_00542058, 0x38);
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x3c) = g_walkCallback;

    g_xformEntityIdx = MK4_NODE_AT(unsigned int, g_iatPtr_00542058, 0xc);
    MStackPushDispatchBitGate();                  /* <- builds the scene */
    if (g_framePauseFlag != 0) return;

    *MK4_VA(unsigned int, 0x53a7a8u) = g_fightGroupHead;
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x30) = 0xb;
    g_walkCallback = *MK4_VA(unsigned int, 0x535e6cu);
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x3c) = g_walkCallback;

    v = MK4_NODE_AT(unsigned int, g_iatPtr_00542058, 0x14);
    g_walkCallback = v;
    if (v != 0) {
        g_xformEntityIdx = v;
        MStackPush4LLWalkPop4();
        if (g_framePauseFlag != 0) return;
    }

    v = MK4_NODE_AT(unsigned int, g_iatPtr_00542058, 0x10);
    g_walkCallback = v;
    if (v != 0) {
        g_xformEntityIdx = v;
        g_xformEntityIdx = (unsigned int)((int)*MK4_NODE(unsigned int, v) >> 2);
        g_currentNodeIdx = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x18);
        InstallSelfDispatch();
        if (g_framePauseFlag != 0) return;
    }

    g_currentNodeIdx = g_fightGroupHead;
    MStackCall_MStackPush2ChainPrepend_00406390();
    if (g_framePauseFlag != 0) return;

    v = MK4_NODE_AT(unsigned int, g_iatPtr_00542058, 8);
    g_walkCallback = v;
    if (v != 0)
        ((void (*)(void))MK4_ResolveCode(v))();
    if (g_framePauseFlag != 0) return;

    g_walkCallback = g_fightGroupHead;
    MStackPop8();
    if (g_framePauseFlag != 0) return;
    g_fightGroupHead = g_walkCallback;
}
#else
void ScenePostInitSequencer(void) {
    __asm {
        call     MStackPush8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        call     TwinLoopSlotFinder
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_cj_00542058]
        mov      eax, dword ptr [eax*4 + 0x3c]
        test     eax, eax
        mov      dword ptr [g_pendingNodeType], eax
        je       short L_9bf5
        mov      dword ptr [g_eventQueueNotMask], 1
        mov      dword ptr [g_eventQueueWorkType], 0x10
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_eventQueueWorkType], 0x10
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
    L_9bf5:
        mov      ecx, dword ptr [g_cj_00542058]
        mov      edx, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_walkCallback], edx
        call     CopyGlobal
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_cj_00542058]
        mov      ecx, dword ptr [eax*4 + 0x1c]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_dispatchSave658], ecx
        mov      ecx, dword ptr [eax*4 + 0x20]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_dispatchSave659], ecx
        mov      ecx, dword ptr [eax*4 + 0x24]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_dispatchSave656], ecx
        mov      eax, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_dispatchSave657], eax
        call     PendingMatch_BootStateTriple
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_particleEmitterNode]
        mov      ecx, dword ptr [g_cj_00542058]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [ecx*4 + 0x2c]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      edx, dword ptr [g_cj_00542058]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x30]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_cj_00542058]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_cj_00542058]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x38]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      edx, dword ptr [g_cj_00542058]
        mov      eax, dword ptr [edx*4 + 0xc]
        mov      dword ptr [g_xformEntityIdx], eax
        call     MStackPushDispatchBitGate
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
        mov      eax, dword ptr [g_cj_0054205c]
        mov      dword ptr [g_pendingMatchAudio2], eax
        mov      dword ptr [eax*4 + 0x30], 0xb
        mov      eax, dword ptr [g_particleEmitterNode]
        mov      ecx, dword ptr [g_cj_0054205c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      edx, dword ptr [g_cj_00542058]
        mov      eax, dword ptr [edx*4 + 0x14]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_9d79
        mov      dword ptr [g_xformEntityIdx], eax
        call     MStackPush4LLWalkPop4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_9e22
    L_9d79:
        mov      eax, dword ptr [g_cj_00542058]
        mov      eax, dword ptr [eax*4 + 0x10]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_9dc3
        mov      edx, dword ptr [g_cj_0054205c]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      ecx, dword ptr [eax*4]
        sar      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], eax
        call     InstallSelfDispatch
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
    L_9dc3:
        mov      ecx, dword ptr [g_cj_0054205c]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackCall_MStackPush2ChainPrepend_00406390
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
        mov      edx, dword ptr [g_cj_00542058]
        mov      eax, dword ptr [edx*4 + 8]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_9df5
        call     eax
    L_9df5:
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
        mov      eax, dword ptr [g_cj_0054205c]
        mov      dword ptr [g_walkCallback], eax
        call     MStackPop8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9e22
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [g_cj_0054205c], ecx
    L_9e22:
        }
}
#endif
