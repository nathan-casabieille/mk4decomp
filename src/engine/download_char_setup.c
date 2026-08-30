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

/* @addr 0x00422ef0 (199b game) - load g_dlNalt2 + flags, call F1; pause? ret;
 *   prep two-arg state, call F2; pause? ret;
 *   chain[g_fightGroupHead +0x30]=2, +0x54=0x14ccc, +0x5c=0;
 *   chain[+0x34] |= 0x001c0001; chain[+0x3c] = g_particleInitState.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern u32 g_dlSomeFlag2;
extern s32 g_dlNalt2;
extern unsigned int g_particleInitState;
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
#define g_dlNalt2 (*(int *)MK4_VA(int, 0x5380e0u))
#define g_dlSomeFlag2 (*(unsigned int *)MK4_VA(unsigned int, 0x52aafcu))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_lit16_00542074 (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_particleInitState (*(unsigned int *)MK4_VA(unsigned int, 0x541de0u))
#define g_player2NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void DownloadPlayerChar(void);
extern void GuardedDualPushTailJmp(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"
extern void DownloadPlayerChar(void);
extern void GuardedDualPushTailJmp(void);

/* @addr 0x00422ef0 (199b) - NATIVE twin; the matching build keeps the
 * __asm body below.
 *
 * Player 2's spawn, the mirror of DownloadDualPush: character g_dlNalt2
 * as slot 1, slot number 2 at +0x30, flags 0x1c0001 (bit 0 is the
 * facing), the mirrored +0x54 value, and the particle-init state rather
 * than the boot-heavy one at +0x3c. Leaves g_player2NodeIdx. */
void DownloadCharSetup(void)
{
    unsigned int grp;

    g_eventQueueCurrent = 1;
    g_walkCallback = g_dlNalt2;
    DownloadPlayerChar();
    if (g_framePauseFlag != 0) return;

    g_walkCallback = g_dlNalt2;
    g_eventQueueCurrent = 1;
    g_lit16_00542074 = *MK4_VA(unsigned int, 0x52aafcu);
    GuardedDualPushTailJmp();
    if (g_framePauseFlag != 0) return;

    grp = g_fightGroupHead;
    *MK4_VA(unsigned int, 0x53815cu) = grp;          /* g_player2NodeIdx */
    MK4_NODE_AT(unsigned int, grp, 0x30) = 2;
    grp = g_fightGroupHead;
    MK4_NODE_AT(unsigned int, grp, 0x54) = 0x14cccu;
    grp = g_fightGroupHead;
    g_walkCallback = 0;
    MK4_NODE_AT(unsigned int, grp, 0x5c) = 0;
    grp = g_fightGroupHead;
    MK4_NODE_AT(unsigned int, grp, 0x34) =
        MK4_NODE_AT(unsigned int, grp, 0x34) | 0x1c0001u;
    g_walkCallback = *MK4_VA(unsigned int, 0x541de0u);
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x3c) = g_walkCallback;
}
#else
void DownloadCharSetup(void) {
    __asm {
        mov     eax, dword ptr [g_dlNalt2]
        mov     dword ptr [g_eventQueueCurrent], 1
        mov     dword ptr [g_walkCallback], eax
        call    DownloadPlayerChar
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0a0h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_dlNalt2]
        mov     edx, dword ptr [g_dlSomeFlag2]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueCurrent], 1
        mov     dword ptr [g_eventQueueWorkType], edx
        call    GuardedDualPushTailJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   70h
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_player2NodeIdx], eax
        mov     dword ptr [eax*4 + 0x30], 2
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax*4 + 0x54], 0x00014ccc
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [ecx*4 + 0x5c], 0
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, [eax*4 + 0x34]
        or      ecx, 0x001c0001
        mov     [eax*4 + 0x34], ecx
        mov     eax, dword ptr [g_particleInitState]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     [edx*4 + 0x3c], eax
        }
}
#endif

