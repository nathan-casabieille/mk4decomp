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

/* @addr 0x0042d090 (304b game) - 3D-distance mul10 + scaled chain advance.
 *   Load eax/ecx/edx from globals 0053a1a8/0053a1a4/g_cj. esi = [cj*4+0x54].
 *   Compute diffs: eax -= esi; ecx -= edx[cj*4+0x5c].
 *   Mul10Tail(eax,eax)->g_eventQueueWorkType. Mul10Tail(ecx,ecx)->g_chainAccumCur; add for g_eventQueueWorkType.
 *   Call FpuSqrtMul; if pause ret.
 *   Mul10Tail(g_currentNodeFlags, g_walkCallback)->g_eventQueueChild.
 *   Mul10Tail(eax, g_eventQueueScratch)->g_eventQueueWorkType. Mul10Tail(ecx, g_eventQueueChildSrc)->g_acc.
 *   Sum: g_walkCallback = g_dual_0053a1a8 + g_eventQueueWorkType; g_eventQueueCurrent = g_dual_0053a1a4 + g_acc.
 *   Store both into [g_cj*4+0x54] and [+0x5c]. Tail-call DualCallPauseDirtyJmp; pop esi; ret.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dual_0053a1a4;
extern unsigned int g_dual_0053a1a8;
extern unsigned int g_eventQueueChildSrc;
extern unsigned int g_eventQueueScratch;
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
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_dual_0053a1a4 (*(unsigned int *)MK4_VA(unsigned int, 0x53a1a4u))
#define g_dual_0053a1a8 (*(unsigned int *)MK4_VA(unsigned int, 0x53a1a8u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueChild (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_eventQueueChildSrc (*(unsigned int *)MK4_VA(unsigned int, 0x53a3dcu))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueScratch (*(unsigned int *)MK4_VA(unsigned int, 0x53a41cu))
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
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void DualCallPauseDirtyJmp_00490c30(void);

#ifdef NON_MATCHING
/* Portable twin - VERIFIED via verify_coexec. Mul10Tail returns eax (declared
 * void on the matching side); cast to a returning fn-ptr to capture it. */
void Distance3DMul10Chain(void)

{
  g_walkCallback = MK4_NODE_AT(int, g_cj_0054205c, 0x54);
  g_eventQueueCurrent = MK4_NODE_AT(int, g_cj_0054205c, 0x5c);
  g_eventQueueWorkType = g_dual_0053a1a8 - g_walkCallback;
  g_chainAccumCur = g_dual_0053a1a4 - g_eventQueueCurrent;
  g_eventQueueWorkType = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_eventQueueWorkType,g_eventQueueWorkType);
  g_chainAccumCur = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_chainAccumCur,g_chainAccumCur);
  g_eventQueueWorkType = g_eventQueueWorkType + g_chainAccumCur;
  FpuSqrtMul();
  if (g_framePauseFlag == 0) {
    g_eventQueueChild = g_walkCallback;
    g_eventQueueChild = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_currentNodeFlags,g_walkCallback);
    g_eventQueueWorkType = g_eventQueueScratch;
    g_chainAccumCur = g_eventQueueChildSrc;
    g_eventQueueWorkType = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_eventQueueChild,g_eventQueueScratch);
    g_chainAccumCur = ((unsigned int (*)(unsigned int, unsigned int))Mul10Tail)(g_eventQueueChild,g_chainAccumCur);
    g_walkCallback = g_dual_0053a1a8 + g_eventQueueWorkType;
    g_eventQueueCurrent = g_dual_0053a1a4 + g_chainAccumCur;
    MK4_NODE_AT(int, g_cj_0054205c, 0x54) = g_walkCallback;
    MK4_NODE_AT(int, g_cj_0054205c, 0x5c) = g_eventQueueCurrent;
    DualCallPauseDirtyJmp_00490c30();
  }
  return;
}
#else
__declspec(naked) void Distance3DMul10Chain(void) {
    __asm {
        mov     eax, dword ptr [g_dual_0053a1a8]
        mov     ecx, dword ptr [g_dual_0053a1a4]
        mov     edx, dword ptr [g_cj_0054205c]
        push    esi
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_chainAccumCur], ecx
        mov     esi, dword ptr [edx*4 + 0x54]
        mov     dword ptr [g_walkCallback], esi
        mov     edx, dword ptr [edx*4 + 0x5c]
        sub     eax, esi
        sub     ecx, edx
        push    eax
        push    eax
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_chainAccumCur], ecx
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     eax, dword ptr [g_chainAccumCur]
        push    eax
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_eventQueueWorkType]
        add     esp, 8
        add     ecx, eax
        mov     dword ptr [g_chainAccumCur], eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        call    FpuSqrtMul
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0a5h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_eventQueueChild], eax
        push    eax
        mov     eax, dword ptr [g_currentNodeFlags]
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_eventQueueScratch]
        mov     edx, dword ptr [g_eventQueueChildSrc]
        add     esp, 8
        mov     dword ptr [g_eventQueueChild], eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_chainAccumCur], edx
        push    ecx
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_eventQueueChild]
        add     esp, 8
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     eax, dword ptr [g_chainAccumCur]
        push    eax
        push    ecx
        call    Mul10Tail
        mov     edx, dword ptr [g_eventQueueWorkType]
        mov     ecx, dword ptr [g_dual_0053a1a8]
        add     ecx, edx
        mov     edx, dword ptr [g_dual_0053a1a4]
        mov     dword ptr [g_chainAccumCur], eax
        add     edx, eax
        mov     eax, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        add     esp, 8
        mov     dword ptr [eax*4 + 0x54], ecx
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [ecx*4 + 0x5c], edx
        call    DualCallPauseDirtyJmp_00490c30
        pop     esi
        ret
    }
}
#endif
