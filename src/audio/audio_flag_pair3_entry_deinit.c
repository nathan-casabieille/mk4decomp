/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

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
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

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

/*
 * GameMode_EnterScene - 149b audio deinit variant of AudioModeInit.
 *   Main (0x004a2720): if g_gtModeFlag == 1 → store (0x53a408,0x53a3e0)>>2 to
 *     (g_currentNodeIdx,g_xformEntityIdx); else (0x537e88,0x53a700)>>2; call
 *     DualScaledStoreConst, ClearTwoCallSetStore; g_dlMode=0; call
 *     SixCallSeqPushImm; g_eventQueueWorkType=0; call Push16Call; if !paused
 *     tail-jmp PendingMatch_Push16Call_004a3400; ret.
 *   Pad-aligned bare-ret entry (0x004a27a0).
 *   Pad-aligned tail-jmp Thunk_ExitGame (0x004a27b0).
 */
extern u32 g_dlMode;
extern void ClearTwoCallSetStore(void);
extern void DualScaledStoreConst(void);
extern void PendingMatch_Push16Call_004a3400(void);
extern void SixCallSeqPushImm(void);
extern void Thunk_ExitGame(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void GameMode_EnterScene(void)

{
  if (g_gtModeFlag == '\x01') {
    (g_currentNodeIdx) = 0x14e902;
    g_eventQueuePending = 0x14e8f8;
  }
  else {
    (g_currentNodeIdx) = 0x14dfa2;
    g_eventQueuePending = 0x14e9c0;
  }
  DualScaledStoreConst();
  ClearTwoCallSetStore();
  g_dlMode = 0;
  SixCallSeqPushImm();
  g_eventQueueWorkType = 0;
  Push16Call();
  if (g_framePauseFlag == 0) {
    PendingMatch_Push16Call_004a3400();
    return;
  }
  return;
}
#else
__declspec(naked) void GameMode_EnterScene(void)
{
    __asm
    {
        cmp     byte ptr [g_gtModeFlag], 1
        jne     short L_modeB
        mov     eax, 0x0053a408
        mov     ecx, 0x0053a3e0
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        jmp     short L_common
    L_modeB:
        mov     edx, 0x00537e88
        mov     eax, 0x0053a700
        shr     edx, 2
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_xformEntityIdx], eax
    L_common:
        call    DualScaledStoreConst
        call    ClearTwoCallSetStore
        mov     dword ptr [g_dlMode], 0
        call    SixCallSeqPushImm
        mov     dword ptr [g_eventQueueWorkType], 0
        call    Push16Call
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_main_ret
        jmp     PendingMatch_Push16Call_004a3400
    L_main_ret:
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        jmp     Thunk_ExitGame
    }
}
#endif
