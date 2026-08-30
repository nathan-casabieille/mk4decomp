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
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
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
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


/* @addr 0x00429530 (109b)
 *   eax = g_baseSel; push esi; esi = &[eax*4];
 *   eax = [eax*4+0x84]; [esi+0x84] = 0;
 *   if eax!=0: skip; call CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx; if pause: ret;
 *   skip: call GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp; if pause: ret;
 *   cl = byte [g_xformDirtyFlags]; eax=1; test al,cl;
 *   if zero: install;
 *     call ScaledInitOrSelfPtr_StackPopDispatchTagged; pop esi; ret;
 *   install: [esi+8]=0x429530; [esi+0x84]=1;
 *            g_pendingNodeType=1; g_framePauseFlag=1; pop esi; ret.
 */
extern void CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx(void);
extern void GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void);
extern void GuardedDoubleIncCmpJmp(void);
extern void CallPauseScaledDecJmp(void);
extern void ScaledInitOrSelfPtr_StackPopDispatchTagged(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429530(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_baseSel * 4;
  iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
  *(undefined4 *)MK4_PTR((iVar1 + 0x84)) = 0;
  if ((iVar2 == 0) && (CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx(), g_framePauseFlag != 0)) {
    return;
  }
  GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp();
  if (g_framePauseFlag == 0) {
    if (((byte)g_xformDirtyFlags & 1) != 0) {
      ScaledInitOrSelfPtr_StackPopDispatchTagged();
      return;
    }
    /* the original stores the VA for the pump to resolve; the lift wrote a
     * HOST function pointer through an UNTRANSLATED address - first exercised
     * when the fight-script VM started reaching this state. */
    *(unsigned int *)MK4_PTR((unsigned int)(iVar1 + 8)) = 0x429530u;
    *(undefined4 *)MK4_PTR((iVar1 + 0x84)) = 1;
    g_dualC = 1;
    g_framePauseFlag = 1;
  }
  return;
}
#else
__declspec(naked) void EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429530(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   75h
        _emit   0eh
        call    CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3bh
        call    GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2dh
        mov     cl, byte ptr [g_xformDirtyFlags]
        mov     eax, 1
        _emit   84h
        _emit   0c8h
        _emit   74h
        _emit   07h
        call    ScaledInitOrSelfPtr_StackPopDispatchTagged
        pop     esi
        ret
        mov     dword ptr [esi + 8], 0x00429530
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}
#endif

/* @addr 0x004295a0 (109b) - twin of 0x00429530 with self-addr 0x4295a0. */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_004295a0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_baseSel * 4;
  iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
  *(undefined4 *)MK4_PTR((iVar1 + 0x84)) = 0;
  if ((iVar2 == 0) && (CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx(), g_framePauseFlag != 0)) {
    return;
  }
  GuardedDoubleIncCmpJmp();
  if (g_framePauseFlag == 0) {
    if (((byte)g_xformDirtyFlags & 1) != 0) {
      ScaledInitOrSelfPtr_StackPopDispatchTagged();
      return;
    }
    /* the original stores the VA for the pump to resolve; the lift wrote a
     * HOST function pointer through an UNTRANSLATED address - first exercised
     * when the fight-script VM started reaching this state. */
    *(unsigned int *)MK4_PTR((unsigned int)(iVar1 + 8)) = 0x4295a0u;
    *(undefined4 *)MK4_PTR((iVar1 + 0x84)) = 1;
    g_dualC = 1;
    g_framePauseFlag = 1;
  }
  return;
}
#else
__declspec(naked) void EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_004295a0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   75h
        _emit   0eh
        call    CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3bh
        call    GuardedDoubleIncCmpJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2dh
        mov     cl, byte ptr [g_xformDirtyFlags]
        mov     eax, 1
        _emit   84h
        _emit   0c8h
        _emit   74h
        _emit   07h
        call    ScaledInitOrSelfPtr_StackPopDispatchTagged
        pop     esi
        ret
        mov     dword ptr [esi + 8], 0x004295a0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}
#endif

/* @addr 0x00429610 (109b) - twin of 0x00429530 with self-addr 0x429610. */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429610(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_baseSel * 4;
  iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
  *(undefined4 *)MK4_PTR((iVar1 + 0x84)) = 0;
  if ((iVar2 == 0) && (CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx(), g_framePauseFlag != 0)) {
    return;
  }
  CallPauseScaledDecJmp();
  if (g_framePauseFlag == 0) {
    if (((byte)g_xformDirtyFlags & 1) != 0) {
      ScaledInitOrSelfPtr_StackPopDispatchTagged();
      return;
    }
    /* the original stores the VA for the pump to resolve; the lift wrote a
     * HOST function pointer through an UNTRANSLATED address - first exercised
     * when the fight-script VM started reaching this state. */
    *(unsigned int *)MK4_PTR((unsigned int)(iVar1 + 8)) = 0x429610u;
    *(undefined4 *)MK4_PTR((iVar1 + 0x84)) = 1;
    g_dualC = 1;
    g_framePauseFlag = 1;
  }
  return;
}
#else
__declspec(naked) void EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429610(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   75h
        _emit   0eh
        call    CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3bh
        call    CallPauseScaledDecJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2dh
        mov     cl, byte ptr [g_xformDirtyFlags]
        mov     eax, 1
        _emit   84h
        _emit   0c8h
        _emit   74h
        _emit   07h
        call    ScaledInitOrSelfPtr_StackPopDispatchTagged
        pop     esi
        ret
        mov     dword ptr [esi + 8], 0x00429610
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}
#endif
