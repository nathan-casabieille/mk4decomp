/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/ghidra_types.h"   /* MK4_NODE_AT / MK4_ResolveCode (NON_MATCHING) */

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

/* @addr 0x00450de0 (229b game) - install-self with index-walk loop.
 *   snapshot+clear chain[+0x84]. If was nonzero -> recompute eax = 0x004e7528>>2 + 5
 *     (jmp at +0xa7 back to +0x63) then resume search.
 *   If was zero: call DualScaledStore; if pause? ret.
 *   else: copy g_cj_0054205c to baseSel[+0x4c] and g_eventQueueIdx; compute
 *   eax = 0x004e7528>>2 -> g_eventQueueEnd -> [eax*4]; if <0: call Thunk_ScaledNeg1SetPause, ret.
 *   else: add g_eventQueueChild; load scaledInit; indirect call. If pause? ret.
 *   else: refetch [g_eventQueueEnd*4+0x10]; if zero: add 5 to eax, jmp back to scaledInit
 *   walk. If non-zero: install-self at [esi+8]=0x00450de0, chain[+0x84]=1, pause=1; ret.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave946;
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
#define g_dispatchSave946 (*(unsigned int *)MK4_VA(unsigned int, 0x4e7528u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueChild (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_eventQueueEnd (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_eventQueueIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
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
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void DualScaledStore(void);
extern void Thunk_ScaledNeg1SetPause(void);

#ifdef NON_MATCHING
/* Portable twin (verify_coexec + native trampoline). Install-self index walk:
 * if node[baseSel].0x84 == 0, init then walk the dispatch table at
 * g_dispatchSave946 (VA 0x4e7528, packed base VA>>2, 5-dword stride): each entry
 * gives a callback index (signed; <0 -> Thunk_ScaledNeg1SetPause + return), call
 * it (indirect -> MK4_ResolveCode), and on a non-zero +0x10 field install self
 * (store &InstallSelfIndexWalk into node.+8) and pause. Else resume the walk at
 * g_eventQueueEnd+5. */
void InstallSelfIndexWalk(void)
{
    unsigned int base = g_baseSel;
    unsigned int self = (unsigned int)(unsigned long)InstallSelfIndexWalk;
    unsigned int v, e, c;

    v = MK4_NODE_AT(unsigned int, base, 0x84);
    MK4_NODE_AT(unsigned int, base, 0x84) = 0;
    if (v == 0) {
        DualScaledStore();
        if (g_framePauseFlag) return;
        MK4_NODE_AT(unsigned int, base, 0x4c) = g_cj_0054205c;
        g_eventQueueIdx = g_cj_0054205c;
        e = 0x4e7528u >> 2;                 /* OFFSET g_dispatchSave946 >> 2 */
    } else {
        e = g_eventQueueEnd + 5;            /* resume2 */
    }
    for (;;) {
        g_eventQueueEnd = e;
        v = MK4_NODE_AT(unsigned int, e, 0);
        g_walkCallback = v;
        if ((int)v < 0) {                   /* jge after_thunk; else thunk + ret */
            Thunk_ScaledNeg1SetPause();
            return;
        }
        v = v + g_eventQueueChild;
        g_currentNodeIdx = v;
        v = MK4_NODE_AT(unsigned int, v, 0);
        g_currentNodeIdx = v;
        ((void (*)(void))MK4_ResolveCode(v))();    /* call eax (indirect) */
        if (g_framePauseFlag) return;
        e = g_eventQueueEnd;
        c = MK4_NODE_AT(unsigned int, e, 0x10);
        g_walkCallback = c;
        if (c != 0) {                       /* install self + pause */
            g_pendingNodeType = c;
            MK4_NODE_AT(unsigned int, base, 8) = self;
            MK4_NODE_AT(unsigned int, base, 0x84) = 1;
            g_framePauseFlag = 1;
            return;
        }
        e = e + 5;
    }
}
#else
__declspec(naked) void InstallSelfIndexWalk(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        push    edi
        mov     edi, OFFSET InstallSelfIndexWalk
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        jne     L_isw_resume2
        call    DualScaledStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_isw_pop_ret
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     dword ptr [edx*4 + 0x4c], ecx
        mov     eax, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_eventQueueIdx], eax
        mov     eax, OFFSET g_dispatchSave946
        shr     eax, 2
L_isw_walk:
        mov     dword ptr [g_eventQueueEnd], eax
        mov     eax, dword ptr [eax*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jge     short L_isw_after_thunk
        call    Thunk_ScaledNeg1SetPause
        pop     edi
        pop     esi
        ret
L_isw_after_thunk:
        mov     ecx, dword ptr [g_eventQueueChild]
        add     eax, ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_currentNodeIdx], eax
        call    eax
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_isw_pop_ret
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [eax*4 + 0x10]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        jne     short L_isw_install
        add     eax, 5
        jmp     short L_isw_walk
L_isw_resume2:
        mov     eax, dword ptr [g_eventQueueEnd]
        add     eax, 5
        jmp     short L_isw_walk
L_isw_install:
        mov     eax, 1
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [esi + 8], edi
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_framePauseFlag], eax
L_isw_pop_ret:
        pop     edi
        pop     esi
        ret
    }
}
#endif
