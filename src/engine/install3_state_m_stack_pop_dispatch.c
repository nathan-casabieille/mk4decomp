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

/* @addr 0x0046f560 (325b game) - 3-state install-self with state-1 mstack-pop dispatch. */
extern void CallPauseScaledStoreCopyJmp(void);
extern void CjInstallSelfRouter(void);
extern void FiveCallGuardSetTail(void);
extern void PushPopWalkSet1006(void);
extern void ScaledLoadJmp_00428d20(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Install3StateMStackPopDispatch(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_baseSel * 4;
  iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
  *(undefined4 *)(iVar1 + 0x84) = 0;
  if (iVar2 == 0) {
    PushPopWalkSet1006();
    if (g_framePauseFlag == 0) {
      (g_currentNodeIdx) = MK4_NODE_AT(int, g_baseSel, 4);
      iVar2 = g_baseSel * 4;
      *MK4_NODE(int, (g_currentNodeIdx)) = g_xformScratch2088;
      *(int *)(iVar2 + 4) = (g_currentNodeIdx) + 1;
      *(code **)(iVar1 + 8) = Install3StateMStackPopDispatch;
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 1;
      (g_currentNodeIdx) = *(int *)(iVar1 + 4);
      *MK4_NODE(undefined4, (g_currentNodeIdx)) = 0x146f560;
      (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
      *(int *)(iVar1 + 4) = (g_currentNodeIdx);
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
      ScaledLoadJmp_00428d20();
      g_framePauseFlag = 1;
    }
  }
  else {
    if (iVar2 != 1) {
      CjInstallSelfRouter();
      return;
    }
    (g_currentNodeIdx) = MK4_NODE_AT(int, g_baseSel, 4) + -1;
    g_xformScratch2088 = *MK4_NODE(int, (g_currentNodeIdx));
    MK4_NODE_AT(int, g_baseSel, 4) = (g_currentNodeIdx);
    if (g_xformScratch2088 < 2) {
      FiveCallGuardSetTail();
      return;
    }
    CallPauseScaledStoreCopyJmp();
    if (g_framePauseFlag == 0) {
      *(code **)(iVar1 + 8) = Install3StateMStackPopDispatch;
      *(undefined4 *)(iVar1 + 0x84) = 2;
      g_dualC = 0x1c;
      g_framePauseFlag = 1;
      return;
    }
  }
  return;
}
#else
__declspec(naked) void Install3StateMStackPopDispatch(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        _emit   83h
        _emit   0e8h
        _emit   00h
        _emit   74h
        _emit   7ah
        dec     eax
        _emit   74h
        _emit   07h
        call    CjInstallSelfRouter
        pop     esi
        ret
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_xformScratch2088], edx
        mov     dword ptr [ecx*4 + 4], eax
        cmp     dword ptr [g_xformScratch2088], 1
        _emit   7fh
        _emit   07h
        call    FiveCallGuardSetTail
        pop     esi
        ret
        call    CallPauseScaledStoreCopyJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0cdh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     dword ptr [esi + 8], offset Install3StateMStackPopDispatch
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 0x1c
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
        call    PushPopWalkSet1006
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   94h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_xformScratch2088]
        mov     ecx, dword ptr [eax*4 + 4]
        lea     eax, [eax*4 + 4]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [ecx*4 + 0], edx
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax], ecx
        mov     dword ptr [esi + 8], offset Install3StateMStackPopDispatch
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, offset Install3StateMStackPopDispatch
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    ScaledLoadJmp_00428d20
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    }
}
#endif
