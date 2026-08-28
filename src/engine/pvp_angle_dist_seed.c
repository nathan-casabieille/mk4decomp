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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern s32 g_dlNalt1;
extern unsigned int g_dispatchSave99;
extern unsigned int g_dispatchSave98;
extern s32 g_dlNalt2;
extern s32 g_dlNalt3;
extern s32 g_dlNalt4;
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
#define g_dispatchSave98 (*(unsigned int *)MK4_VA(unsigned int, 0x538044u))
#define g_dispatchSave99 (*(unsigned int *)MK4_VA(unsigned int, 0x538040u))
#define g_dlNalt1 (*(int *)MK4_VA(int, 0x537f48u))
#define g_dlNalt2 (*(int *)MK4_VA(int, 0x5380e0u))
#define g_dlNalt3 (*(int *)MK4_VA(int, 0x53a178u))
#define g_dlNalt4 (*(int *)MK4_VA(int, 0x53a250u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueChild (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
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
#define g_player1NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_player2NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x53815cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void CallPauseLoadAndDispatch(void);
extern void InstallSelfPause2(void);
extern void FixedDiv16(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"
extern void CallPauseLoadAndDispatch(void);

/* @addr 0x004233f0 and 0x00423470 - the two per-player fight handlers,
 * packed inside this symbol with no names of their own. MatchInitMonsterChain
 * schedules them (work types 1 and 2) and parks their node indices in the
 * two player probes; from then on the scheduled-node walk calls them every
 * frame, so they are registered in config/codeptr_extras.yaml.
 *
 * Each one points the fight group at ITS player and fills the scheduled
 * node's four fight fields: this player's character index at +0x34, the
 * OTHER player's node at +0x38, the other player's probe at +0x3c, and the
 * two axis records at +0x40 / +0x44 (packed) - X and Y for player 1, the
 * negated pair for player 2. g_currentNodeIdx is left on the second axis
 * record, which is what the shared tail loads from. */
void FightHandler_Player1_004233f0(void)
{
    unsigned int base = g_baseSel;

    g_fightGroupHead = *MK4_VA(unsigned int, 0x538158u);      /* p1 node */
    g_walkCallback = g_dlNalt1;
    MK4_NODE_AT(unsigned int, base, 0x34) = g_dlNalt1;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x38) =
        *MK4_VA(unsigned int, 0x53815cu);                    /* p2 node */
    MK4_NODE_AT(unsigned int, g_baseSel, 0x3c) =
        *MK4_VA(unsigned int, 0x53803cu);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x40) = 0x535e78u >> 2;
    g_currentNodeIdx = 0x535e7cu >> 2;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x44) = 0x535e7cu >> 2;
    CallPauseLoadAndDispatch();          /* tail-jmp in the original */
}

void FightHandler_Player2_00423470(void)
{
    unsigned int base = g_baseSel;

    g_fightGroupHead = *MK4_VA(unsigned int, 0x53815cu);      /* p2 node */
    g_walkCallback = g_dlNalt2;
    MK4_NODE_AT(unsigned int, base, 0x34) = g_dlNalt2;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x38) =
        *MK4_VA(unsigned int, 0x538158u);                    /* p1 node */
    MK4_NODE_AT(unsigned int, g_baseSel, 0x3c) =
        *MK4_VA(unsigned int, 0x538038u);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x40) = 0x535e70u >> 2;
    g_currentNodeIdx = 0x535e74u >> 2;
    MK4_NODE_AT(unsigned int, g_baseSel, 0x44) = 0x535e74u >> 2;
    CallPauseLoadAndDispatch();          /* tail-jmp in the original */
}
#endif

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PvpAngleDistSeed(void)

{
  int iVar1;
  
  (g_currentNodeIdx) = g_player1NodeIdx;
  g_eventQueuePending = g_player2NodeIdx;
  g_chainAccumCur = MK4_NODE_AT(int, g_player1NodeIdx, 0x54);
  g_eventQueueCurrent = MK4_NODE_AT(int, g_player1NodeIdx, 0x5c);
  g_eventQueueWorkType = MK4_NODE_AT(int, g_player2NodeIdx, 0x54) - g_chainAccumCur;
  g_walkCallback = MK4_NODE_AT(int, g_player2NodeIdx, 0x5c) - g_eventQueueCurrent;
  g_eventQueueNotMask = g_eventQueueWorkType;
  g_eventQueueChild = g_walkCallback;
  g_eventQueueWorkType = ((int (*)(int, int))Mul10Tail)(
      (int)g_eventQueueWorkType, (int)g_eventQueueWorkType);
  g_walkCallback = ((int (*)(int, int))Mul10Tail)(
      (int)g_walkCallback, (int)g_walkCallback);
  g_eventQueueWorkType = g_eventQueueWorkType + g_walkCallback;
  FpuSqrtMul();
  iVar1 = g_walkCallback;
  if (g_framePauseFlag == 0) {
    g_currentNodeFlags = g_walkCallback;
    g_walkCallback = g_eventQueueNotMask;
    g_eventQueueCurrent = iVar1;
    FixedDiv16();
    if (g_framePauseFlag == 0) {
      g_eventQueueNotMask = g_walkCallback;
      g_walkCallback = g_eventQueueChild;
      g_eventQueueCurrent = g_currentNodeFlags;
      FixedDiv16();
      if (g_framePauseFlag == 0) {
        g_eventQueueChild = g_walkCallback;
      }
    }
  }
  return;
}
#else
__declspec(naked) void PvpAngleDistSeed(void)
{
    __asm {
        /* === h1 (0x4232e0): main diff/ratio + angle install === */
        mov      ecx, dword ptr [g_player1NodeIdx]
        mov      edx, dword ptr [g_player2NodeIdx]
        push     esi
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_xformEntityIdx], edx
        mov      esi, dword ptr [ecx*4 + 0x54]
        mov      dword ptr [g_chainAccumCur], esi
        mov      eax, dword ptr [edx*4 + 0x54]
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      ecx, dword ptr [ecx*4 + 0x5c]
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      edx, dword ptr [edx*4 + 0x5c]
        sub      eax, esi
        sub      edx, ecx
        push     eax
        push     eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      dword ptr [g_eventQueueChild], edx
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      eax, dword ptr [g_walkCallback]
        push     eax
        push     eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueWorkType]
        add      esp, 8
        add      ecx, eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueWorkType], ecx
        call     FpuSqrtMul
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_33e4
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [g_currentNodeFlags], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueCurrent], eax
        call     FixedDiv16
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_33e4
        mov      edx, dword ptr [g_walkCallback]
        mov      eax, dword ptr [g_eventQueueChild]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_eventQueueNotMask], edx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        call     FixedDiv16
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_33e4
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [g_eventQueueChild], edx
    L_33e4:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x4233f0): p1→p2 seed → 4235f0 === */
        mov      eax, dword ptr [g_player1NodeIdx]
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_fightGroupHead], eax
        mov      eax, dword ptr [g_dlNalt1]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_player2NodeIdx]
        mov      dword ptr [edx*4 + 0x38], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_gtPlayerProbe1]
        mov      eax, OFFSET g_fightAxisPosX
        mov      dword ptr [ecx*4 + 0x3c], edx
        mov      ecx, dword ptr [g_baseSel]
        shr      eax, 2
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      edx, dword ptr [g_baseSel]
        mov      eax, OFFSET g_fightAxisPosY
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edx*4 + 0x44], eax
        jmp      CallPauseLoadAndDispatch
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h3 (0x423470): p2→p1 seed → 4235f0 === */
        mov      eax, dword ptr [g_player2NodeIdx]
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_fightGroupHead], eax
        mov      eax, dword ptr [g_dlNalt2]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_player1NodeIdx]
        mov      dword ptr [edx*4 + 0x38], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_gtPlayerProbe2]
        mov      eax, OFFSET g_fightAxisNegX
        mov      dword ptr [ecx*4 + 0x3c], edx
        mov      ecx, dword ptr [g_baseSel]
        shr      eax, 2
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      edx, dword ptr [g_baseSel]
        mov      eax, OFFSET g_fightAxisNegY
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edx*4 + 0x44], eax
        jmp      CallPauseLoadAndDispatch
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h4 (0x4234f0): p3→p4 seed → 423630 === */
        mov      eax, dword ptr [g_player3NodeIdx]
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_fightGroupHead], eax
        mov      eax, dword ptr [g_dlNalt3]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_player4NodeIdx]
        mov      dword ptr [edx*4 + 0x38], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_dispatchSave98]
        mov      eax, OFFSET g_fightAxisPosX
        mov      dword ptr [ecx*4 + 0x3c], edx
        mov      ecx, dword ptr [g_baseSel]
        shr      eax, 2
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      edx, dword ptr [g_baseSel]
        mov      eax, OFFSET g_fightAxisPosY
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edx*4 + 0x44], eax
        jmp      InstallSelfPause2
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h5 (0x423570): p4→p3 seed → 423630 === */
        mov      eax, dword ptr [g_player4NodeIdx]
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_fightGroupHead], eax
        mov      eax, dword ptr [g_dlNalt4]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_player3NodeIdx]
        mov      dword ptr [edx*4 + 0x38], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_dispatchSave99]
        mov      eax, OFFSET g_fightAxisNegX
        mov      dword ptr [ecx*4 + 0x3c], edx
        mov      ecx, dword ptr [g_baseSel]
        shr      eax, 2
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      edx, dword ptr [g_baseSel]
        mov      eax, OFFSET g_fightAxisNegY
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edx*4 + 0x44], eax
        jmp      InstallSelfPause2
    }
}
#endif
