/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
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

/*
 * @addr 0x004bd4a0 (110b engine.geo) - chain walker with cleanup:
 *   if walk[+0x48] non-null call Helper_TickAlt on it; load
 *   walk[+0] into walk; if null exit; load walk[+0x0c], if == 1
 *   indirect-chain to walk[+0] and tail-recurse; else install self,
 *   call CleanupCallTwice, then return value of g_framePauseFlag.
 *   NON-COAXABLE: MSVC /O2 TCO loop-heuristic puts jmp path before
 *   ret path; orig has else-block before tailRecurse.
 */
#ifdef NON_MATCHING
extern void CleanupCallTwice(unsigned int *slot);
extern void Helper_TickAlt(void);
#else
extern void CleanupCallTwice(void);
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
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"
#include "portable/code_va.h"

/* Portable twin. Walks the sibling chain from g_currentNodeIdx, releasing each
 * node's +0x48 handle, and stops at the first node whose link is null.
 *
 * The walk is not a plain loop: a node whose +0xc field is not 1 yields to
 * Helper_TickAlt after PARKING ITS OWN ADDRESS in g_walkCallback, so the tick
 * resumes the walk where it left off. That slot holds a code VA, hence
 * MK4_CODE_VA; the other two things written to it are a node link and a field
 * value, which is why it cannot be typed as a pointer.
 *
 * CleanupCallTwice dereferences its argument, so the +0x48 slot goes in as a
 * host pointer even though the original computes it with `lea ecx, [eax*4 +
 * 0x48]`.
 *
 * Returns eax, which the original leaves as the node index on the null-link
 * exit and as the pause flag on the yield. */
int ChainWalkCleanup(void)
{
    for (;;) {
        unsigned int idx = g_currentNodeIdx;
        unsigned int next;

        if (MK4_NODE_AT(unsigned int, idx, 0x48) != 0) {
            CleanupCallTwice(&MK4_NODE_AT(unsigned int, idx, 0x48));
            idx = g_currentNodeIdx;
        }

        next = MK4_NODE_AT(unsigned int, idx, 0);
        g_walkCallback = next;
        if (next == 0)
            return (int)idx;

        g_walkCallback = MK4_NODE_AT(unsigned int, idx, 0xc);
        if (g_walkCallback != 1) {
            g_walkCallback = MK4_CODE_VA(ChainWalkCleanup);
            Helper_TickAlt();
            return (int)g_framePauseFlag;
        }
        g_currentNodeIdx = MK4_NODE_AT(unsigned int, idx, 0);
    }
}
#else
__declspec(naked) void ChainWalkCleanup(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     edx, dword ptr [eax*4 + 0x48]
        lea     ecx, [eax*4 + 0x48]
        test    edx, edx
        je      noCleanup
        push    ecx
        call    Helper_TickAlt
        mov     eax, dword ptr [g_walkCallback]
        add     esp, 4
noCleanup:
        mov     ecx, dword ptr [eax*4 + 0]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        je      done
        mov     ecx, dword ptr [eax*4 + 0x0c]
        cmp     ecx, 1
        mov     dword ptr [g_walkCallback], ecx
        je      tailRecurse
        mov     dword ptr [g_walkCallback], 0x004bd4a0
        call    CleanupCallTwice
        mov     eax, dword ptr [g_framePauseFlag]
done:
        ret
tailRecurse:
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_walkCallback], eax
        jmp     ChainWalkCleanup
    }
}
#endif
