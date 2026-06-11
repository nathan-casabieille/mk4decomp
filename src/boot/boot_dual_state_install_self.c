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
 * BootDualStateInstallSelf - 246b 3-state install-self.
 *   chain = g_baseSel<<2; saved = chain->state; chain->state=0.
 *   sub eax, 0 → flags. If state == 0: g_eventQueueWorkType=0; Push16Call; install-self with chain->state=1
 *     and g_pendingNodeType=1, pause=1; pop+ret.
 *   If state == 1: call FiveTableWalkInit; if paused: pop+ret. Else tail StackPopDispatchTagged; pop+ret.
 *   Otherwise: call TwinMStackPushScaledChain; if paused: pop+ret. g_eventQueueCurrent=5; install-self;
 *     chain->state=2; mstack-push (entry+0x02000000); g_currentNodeIdx++; clear g_baseSel*4+0x84;
 *     call InstallSelfPackedF80; g_framePauseFlag=1; pop+ret.
 */
extern void FiveTableWalkInit(void);
extern void InstallSelfPackedF80(void);
extern void TwinMStackPushScaledChain(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BootDualStateInstallSelf(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_baseSel * 4;
  iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
  *(undefined4 *)(iVar1 + 0x84) = 0;
  if (iVar2 == 0) {
    g_eventQueueWorkType = 0;
    Push16Call();
    if (g_framePauseFlag == 0) {
      *(code **)(iVar1 + 8) = BootDualStateInstallSelf;
      *(undefined4 *)(iVar1 + 0x84) = 1;
      g_dualC = 1;
      g_framePauseFlag = 1;
    }
  }
  else if (iVar2 == 1) {
    TwinMStackPushScaledChain();
    if (g_framePauseFlag == 0) {
      g_eventQueueCurrent = 5;
      *(code **)(iVar1 + 8) = BootDualStateInstallSelf;
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 2;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)(iVar1 + 4);
      *MK4_NODE(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044))) = 0x2403070;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
      *(int *)(iVar1 + 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
      InstallSelfPackedF80();
      g_framePauseFlag = 1;
      return;
    }
  }
  else {
    FiveTableWalkInit();
    if (g_framePauseFlag == 0) {
      StackPopDispatchTagged();
      return;
    }
  }
  return;
}
#else
__declspec(naked) void BootDualStateInstallSelf(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_state0
        dec     eax
        je      short L_state2
        call    FiveTableWalkInit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ret
        call    StackPopDispatchTagged
        pop     esi
        ret
    L_state2:
        call    TwinMStackPushScaledChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ret
        mov     dword ptr [g_eventQueueCurrent], 5
        mov     dword ptr [esi + 8], offset BootDualStateInstallSelf
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, offset BootDualStateInstallSelf
        add     edx, 0x02000000
        mov     dword ptr [ecx*4 + 0x84], 2
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], 0
        call    InstallSelfPackedF80
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_state0:
        mov     dword ptr [g_eventQueueWorkType], 0
        call    Push16Call
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_ret
        mov     eax, 1
        mov     dword ptr [esi + 8], offset BootDualStateInstallSelf
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_ret:
        pop     esi
        ret
    }
}
#endif
