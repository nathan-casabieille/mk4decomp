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

extern unsigned int g_dispatchSave958;
extern unsigned int g_tickFlagF;
extern unsigned int g_audioPathFlag;
extern unsigned int g_matchStartClr;
extern unsigned int g_audioMatchStartFlag;
extern void ArgSarAddDerefJmp(void);
extern void AudioInstallSelfStatePush(void);
extern void BootInitGuardedCallChain(void);
extern void CallSetPause(void);
extern void DispatcherComplex115_Cmp3DirtyToggle_0049f900(void);
extern void DispatcherComplex115_Cmp3DirtyToggle_0049f980(void);
extern void InstallSelfPackedF80(void);
extern void InstallSelfTableWalk(void);
extern void ScenegraphWalk(void);
extern void SixCallSeqPushImm(void);
extern void TripleStageRollback(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void RoundEndFsmCluster(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_baseSel * 4;
  iVar2 = *(int *)(iVar1 + 0x84);
  *(undefined4 *)(iVar1 + 0x84) = 0;
  if (iVar2 == 0) {
    TripleStageRollback(0x4000);
    g_tickFlagF = 0;
    *MK4_NODE(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044))) = 0;
    g_walkCallback = 0;
    g_active_0053a408 = 0;
    g_active_00537e88 = 0;
    ScenegraphWalk();
    g_eventQueueWorkType = 4;
    Push16Call();
    if (g_framePauseFlag == 0) {
      g_eventQueueCurrent = 10;
      *(code **)(iVar1 + 8) = RoundEndFsmCluster;
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 1;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)(iVar1 + 4);
      *MK4_NODE(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044))) = 0x145d680;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
      *(int *)(iVar1 + 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
      InstallSelfPackedF80();
      g_framePauseFlag = 1;
    }
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        *(code **)(iVar1 + 8) = RoundEndFsmCluster;
        *(undefined4 *)(iVar1 + 0x84) = 3;
        g_dualC = 8;
        g_framePauseFlag = 1;
        return;
      }
      SixCallSeqPushImm();
      g_walkCallback = 0x1000;
      MK4_NODE_AT(undefined4, g_baseSel, 0xc) = 0x1000;
      InstallSelfTableWalk();
      return;
    }
    g_walkCallback = 2;
    g_active_0053a408 = 2;
    g_active_00537e88 = 2;
    BootInitGuardedCallChain();
    if (g_framePauseFlag == 0) {
      *(code **)(iVar1 + 8) = RoundEndFsmCluster;
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 2;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)(iVar1 + 4);
      *MK4_NODE(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044))) = 0x245d680;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
      *(int *)(iVar1 + 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
      AudioInstallSelfStatePush();
      g_framePauseFlag = 1;
      return;
    }
  }
  return;
}
#else
__declspec(naked) void RoundEndFsmCluster(void)
{
    __asm {
        /* === Helper 1 (0x45d680): round-end FSM === */
    L_d680:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_d77d
        dec      eax
        je       short L_d6f9
        dec      eax
        je       short L_d6d4
        mov      dword ptr [esi + 8], OFFSET L_d680
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_d6d4:
        call     SixCallSeqPushImm
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x1000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0xc], eax
        call     InstallSelfTableWalk
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_d6f9:
        mov      ebx, 2
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_active_0053a408], ebx
        mov      dword ptr [g_active_00537e88], ebx
        call     BootInitGuardedCallChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_d82c
        mov      dword ptr [esi + 8], OFFSET L_d680
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_d680
        mov      dword ptr [edx*4 + 0x84], ebx
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x2000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     AudioInstallSelfStatePush
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_d77d:
        push     0x4000
        call     TripleStageRollback
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_tickFlagF], edi
        add      esp, 4
        mov      dword ptr [eax*4], edi
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_active_0053a408], edi
        mov      dword ptr [g_active_00537e88], edi
        call     ScenegraphWalk
        mov      dword ptr [g_eventQueueWorkType], 4
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_d82c
        mov      dword ptr [g_eventQueueCurrent], 0xa
        mov      dword ptr [esi + 8], OFFSET L_d680
        mov      ecx, dword ptr [g_baseSel]
        mov      ebx, 1
        mov      edx, OFFSET L_d680
        mov      dword ptr [ecx*4 + 0x84], ebx
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelfPackedF80
        mov      dword ptr [g_framePauseFlag], ebx
    L_d82c:
        pop      edi
        pop      esi
        pop      ebx
        ret
        /* === Helper 2: jmp 0041f830 === */
        jmp      CallSetPause
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
        nop
        /* === Helper 3: call 0049f900 + jmp 0041f830 === */
        call     DispatcherComplex115_Cmp3DirtyToggle_0049f900
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d853
        jmp      CallSetPause
    L_d853:
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
        nop
        nop
        /* === Helper 4: jmp 0041f830 === */
        jmp      CallSetPause
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
        nop
        /* === Helper 5: flag-gated dispatch w/ 4e9068 fallback === */
        mov      eax, dword ptr [g_audioMatchStartFlag]
        test     eax, eax
        je       short L_d890
        mov      eax, dword ptr [g_matchStartClr]
        test     eax, eax
        jne      short L_d890
        cmp      byte ptr [g_gtModeFlag], 1
        jne      short L_d890
        jmp      CallSetPause
    L_d890:
        mov      eax, dword ptr [g_audioPathFlag]
        test     eax, eax
        je       short L_d89e
        jmp      CallSetPause
    L_d89e:
        push     OFFSET g_dispatchSave958
        call     ArgSarAddDerefJmp
        add      esp, 4
        ret
        nop
        nop
        nop
        nop
        /* === Helper 6: jmp 0041f830 === */
        jmp      CallSetPause
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
        nop
        /* === Helper 7: call 0049f980 + jmp 0041f830 === */
        call     DispatcherComplex115_Cmp3DirtyToggle_0049f980
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d3
        jmp      CallSetPause
    L_d8d3:
        ret
    }
}
#endif
