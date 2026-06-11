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

extern unsigned int g_eventQueueSeed;
extern unsigned int g_dispatchArr;
extern void AiAngleDistComputation(void);
extern void CameraAimSplineDriver(void);
extern void DispatchOrInitFightGroup(void);
extern void DualEntryInitDispatch(void);
extern void PendingMatch_ThreeMul10Stores(void);
extern void PendingMatch_ZeroThreeFields6c_then_ZeroThreeSlots(void);
extern void ScaledInitWithCounterAndType_004314f0(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PoseFsmTriHelpers(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iStack_10;
  
  (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *MK4_NODE(int, (g_eventQueueChild + 0x150862));
  g_eventQueuePending = g_eventQueueSeed;
  iVar6 = MK4_NODE_AT(int, g_player1NodeIdx, 0x54);
  iVar7 = MK4_NODE_AT(int, g_player1NodeIdx, 0x5c);
  iVar2 = MK4_NODE_AT(int, g_player2NodeIdx, 0x5c);
  iVar5 = MK4_NODE_AT(int, g_eventQueueSeed, 0x5c);
  iVar3 = MK4_NODE_AT(int, g_player2NodeIdx, 0x54);
  iVar8 = MK4_NODE_AT(int, g_eventQueueSeed, 0x54);
  iVar4 = Mul10Tail(iVar8 - iVar6,iVar2 - iVar5);
  iVar5 = Mul10Tail(iVar3 - iVar8,iVar5 - iVar7);
  TimerWindowWrap();
  iStack_10 = g_walkCallback;
  if (g_framePauseFlag == 0) {
    g_eventQueueCurrent = *MK4_NODE(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)));
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
    g_eventQueueCurrent = Mul10Tail(g_xformScratch2088,g_eventQueueCurrent);
    g_walkCallback = g_walkCallback + g_eventQueueCurrent;
    g_currentNodeFlags = *MK4_NODE(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)));
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
    GuardedTimeBudgetDualMul10();
    if (g_framePauseFlag == 0) {
      iVar8 = MK4_NODE_AT(int, g_cj_00542054, 0x54) + g_eventQueueWorkType;
      iVar9 = MK4_NODE_AT(int, g_cj_00542054, 0x5c) + g_chainAccumCur;
      g_walkCallback = iVar8;
      g_eventQueueCurrent = iVar9;
      if (g_audioStreamState == 0) {
        iVar6 = Mul10Tail(iVar8 - iVar6,iVar2 - iVar9);
        iVar7 = Mul10Tail(iVar3 - iVar8,iVar9 - iVar7);
        if (iVar6 - iVar7 < 0 != iVar4 - iVar5 < 0) {
          iStack_10 = iStack_10 + 0x3243f;
          g_eventQueueCurrent = *MK4_NODE(undefined4, ((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + -2));
          (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + -1;
          g_walkCallback = iStack_10;
          g_eventQueueCurrent = Mul10Tail(g_xformScratch2088,g_eventQueueCurrent);
          g_walkCallback = g_walkCallback + g_eventQueueCurrent;
          g_currentNodeFlags = *MK4_NODE(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)));
          (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
          GuardedTimeBudgetDualMul10();
          if (g_framePauseFlag != 0) {
            return;
          }
          g_walkCallback = MK4_NODE_AT(int, g_cj_00542054, 0x54) + g_eventQueueWorkType;
          g_eventQueueCurrent = MK4_NODE_AT(int, g_cj_00542054, 0x5c) + g_chainAccumCur;
        }
      }
      iVar6 = g_baseSel;
      MK4_NODE_AT(int, g_baseSel, 0x34) = g_walkCallback;
      MK4_NODE_AT(int, iVar6, 0x3c) = g_eventQueueCurrent;
      puVar1 = (undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4);
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
      MK4_NODE_AT(undefined4, iVar6, 0x40) = *puVar1;
      g_walkCallback = iStack_10;
      g_eventQueueCurrent = *MK4_NODE(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)));
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
      g_eventQueueCurrent = Mul10Tail(g_xformScratch2088,g_eventQueueCurrent);
      MK4_NODE_AT(int, g_baseSel, 0x44) = g_walkCallback + g_eventQueueCurrent;
      puVar1 = (undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4);
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
      MK4_NODE_AT(undefined4, g_baseSel, 0x38) = *puVar1;
      puVar1 = (undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4);
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
      MK4_NODE_AT(undefined4, g_baseSel, 0x78) = *puVar1;
      MK4_NODE_AT(undefined4, g_baseSel, 0x48) = 0;
      g_walkCallback = 0x28;
      MK4_NODE_AT(undefined4, g_baseSel, 0x30) = 0x28;
    }
  }
  return;
}
#else
__declspec(naked) void PoseFsmTriHelpers(void)
{
    __asm {
        /* === h1 (0x431650): table-index wrapper, tail-jmp 31920 === */
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_dispatchArr
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      AiAngleDistComputation
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
        /* === h2 (0x431680): pause-guarded chain → 4314f0 tail-jmp === */
        call     DualEntryInitDispatch
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_xformScratch2088], 0x10000
        mov      eax, dword ptr [eax*4 + 0x34]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 1
        mov      dword ptr [g_xformScratch94], eax
        je       short L_16bd
        mov      dword ptr [g_xformScratch2088], 0xffff0000
    L_16bd:
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_dispatchArr
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     AiAngleDistComputation
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        call     PendingMatch_ZeroThreeFields6c_then_ZeroThreeSlots
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1700
        jmp      ScaledInitWithCounterAndType_004314f0
    L_1700:
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
        nop
        nop
        nop
        /* === h3 (0x431710): 3-case pose-fn dispatcher === */
    L_1710:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_1853
        dec      eax
        je       L_1823
        dec      eax
        je       short L_1747
        call     DispatchOrInitFightGroup
        pop      edi
        pop      esi
        ret
    L_1747:
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueSeed]
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_walkCallback], edi
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x40], edi
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x48], ecx
        call     CameraAimSplineDriver
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_191d
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 0x44], ecx
        lea      eax, [edx*4]
        mov      edx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [eax + 0x34], edx
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      dword ptr [eax + 0x3c], ecx
        mov      ecx, 0x28
        mov      dword ptr [eax + 0x38], 0xfffe8000
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x30], ecx
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_1710
        add      ecx, 0x3000000
        mov      dword ptr [edx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     PendingMatch_ThreeMul10Stores
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_1823:
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x78]
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_1853:
        call     DualEntryInitDispatch
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_191d
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_xformScratch2088], 0x10000
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 1
        mov      dword ptr [g_xformScratch94], eax
        je       short L_1894
        mov      dword ptr [g_xformScratch2088], 0xffff0000
    L_1894:
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      eax, OFFSET g_dispatchArr
        shr      eax, 2
        add      eax, ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], eax
        call     AiAngleDistComputation
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_191d
        mov      dword ptr [esi + 8], OFFSET L_1710
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_1710
        mov      dword ptr [ecx*4 + 0x84], 1
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
        call     PendingMatch_ThreeMul10Stores
        mov      dword ptr [g_framePauseFlag], 1
    L_191d:
        pop      edi
        pop      esi
        ret
    }
}
#endif
