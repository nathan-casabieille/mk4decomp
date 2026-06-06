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

extern unsigned int g_dispatchSave901;
extern unsigned int g_quadEntryGate;
extern unsigned int g_clamp_00537f2c;
extern unsigned int g_clamp_0053a6dc;
extern void Cmp2DirtyToggle(void);
extern void DualAddSar(void);
extern void SaveCallRestore(void);
extern void TableLookupCall_g_eventTbl_112(void);
extern void func_004214a0(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MkIntroFsm(void)

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
      g_walkCallback = 1;
      g_quadEntryGate = 1;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_dualB_00538038;
      g_eventQueuePending = 0x4214a0;
      thunk_ChainNodeInit();
      if (g_framePauseFlag == 0) {
        g_eventQueuePending = 0x4214a0;
        (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_dualB_0053803c;
        thunk_ChainNodeInit();
        if (g_framePauseFlag == 0) {
          g_walkCallback = 0x24b;
          g_eventQueueCurrent = 4;
          g_chainAccumCur = 0;
          g_eventQueueNotMask = 0xffc90000;
          g_eventQueuePending = 0x1355b6;
          Push70CallScaleArith();
          if (g_framePauseFlag == 0) {
            g_eventQueueWorkType = 0x48;
            Push16Call();
            if (g_framePauseFlag == 0) {
              *(code **)(iVar1 + 8) = MkIntroFsm;
              *(undefined4 *)(iVar1 + 0x84) = 1;
              g_dualC = 0x10;
              g_framePauseFlag = 1;
            }
          }
        }
      }
    }
    return;
  }
  if (iVar2 == 1) {
    g_walkCallback = 0x2d;
    TableLookupCall_g_eventTbl_112();
    if (g_framePauseFlag != 0) {
      return;
    }
    *(code **)(iVar1 + 8) = MkIntroFsm;
    *(undefined4 *)(iVar1 + 0x84) = 2;
    g_dualC = 0x90;
    g_framePauseFlag = 1;
    return;
  }
  if (iVar2 == 2) {
    SaveCallRestore(0x24b);
    *(code **)(iVar1 + 8) = MkIntroFsm;
    *(undefined4 *)(iVar1 + 0x84) = 3;
    g_dualC = 8;
    g_framePauseFlag = 1;
    return;
  }
  Cmp2DirtyToggle();
  if (g_framePauseFlag != 0) {
    return;
  }
  if (((byte)g_xformDirtyFlags & 1) == 0) {
LAB_00421aa8:
    g_walkCallback = g_clamp_0053a6dc;
    g_eventQueueCurrent = g_clamp_00537f2c;
    if (g_clamp_00537f2c < (int)g_clamp_0053a6dc) {
LAB_00421ae4:
      g_walkCallback = 1;
      g_audioBankSel = 1;
      StackPopDispatchTagged();
      return;
    }
    if (g_clamp_00537f2c <= (int)g_clamp_0053a6dc) {
      if (g_clamp_0053a6dc == 0x10000) goto LAB_0042192f;
      DualAddSar();
      if ((g_walkCallback & 1) == 0) goto LAB_00421ae4;
    }
  }
  else {
    if (g_player3NodeIdx != 0) {
      if (g_player4NodeIdx == 0) goto LAB_00421ae4;
      goto LAB_00421aa8;
    }
    if (g_player4NodeIdx == 0) goto LAB_00421aa8;
  }
  g_walkCallback = 2;
  g_audioBankSel = 2;
LAB_0042192f:
  StackPopDispatchTagged();
  return;
}
#else
__declspec(naked) void MkIntroFsm(void)
{
    __asm {
    L_18b0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_19b0
        dec      eax
        je       L_196c
        dec      eax
        je       short L_1937
        call     Cmp2DirtyToggle
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1aa1
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        test     al, bl
        je       L_1aa8
        mov      eax, dword ptr [g_player3NodeIdx]
        test     eax, eax
        mov      eax, dword ptr [g_player4NodeIdx]
        jne      L_1aa4
        test     eax, eax
        je       L_1aa8
    L_1920:
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_audioBankSel], eax
    L_192f:
        call     StackPopDispatchTagged
        pop      esi
        pop      ebx
        ret
    L_1937:
        push     0x24b
        call     SaveCallRestore
        mov      dword ptr [esi + 8], OFFSET L_18b0
        mov      dword ptr [esi + 0x84], 3
        add      esp, 4
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret
    L_196c:
        mov      dword ptr [g_walkCallback], 0x2d
        call     TableLookupCall_g_eventTbl_112
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1aa1
        mov      dword ptr [esi + 8], OFFSET L_18b0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x90
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret
    L_19b0:
        mov      dword ptr [g_eventQueueWorkType], 0
        call     Push16Call
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1aa1
        mov      ecx, dword ptr [g_gtPlayerProbe2]
        mov      ebx, 1
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_quadEntryGate], ebx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_xformEntityIdx], OFFSET func_004214a0
        call     Thunk_ChainNodeInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1aa1
        mov      edx, dword ptr [g_gtPlayerProbe1]
        mov      dword ptr [g_xformEntityIdx], OFFSET func_004214a0
        mov      dword ptr [g_currentNodeIdx], edx
        call     Thunk_ChainNodeInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1aa1
        mov      eax, OFFSET g_dispatchSave901
        mov      dword ptr [g_walkCallback], 0x24b
        shr      eax, 2
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [g_chainAccumCur], 0
        mov      dword ptr [g_eventQueueNotMask], 0xffc90000
        mov      dword ptr [g_xformEntityIdx], eax
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1aa1
        mov      dword ptr [g_eventQueueWorkType], 0x48
        call     Push16Call
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1aa1
        mov      dword ptr [esi + 8], OFFSET L_18b0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 0x10
        mov      dword ptr [g_framePauseFlag], ebx
    L_1aa1:
        pop      esi
        pop      ebx
        ret
    L_1aa4:
        test     eax, eax
        je       short L_1ae4
    L_1aa8:
        mov      eax, dword ptr [g_clamp_0053a6dc]
        mov      ecx, dword ptr [g_clamp_00537f2c]
        cmp      eax, ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        jg       short L_1ae4
        jl       L_1920
        cmp      eax, 0x10000
        je       L_192f
        call     DualAddSar
        test     byte ptr [g_walkCallback], bl
        jne      L_1920
    L_1ae4:
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_audioBankSel], ebx
        call     StackPopDispatchTagged
        pop      esi
        pop      ebx
        ret
    }
}
#endif
