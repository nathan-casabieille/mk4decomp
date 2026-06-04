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

/* ------------------------------------------------------------------ */
/* Pose-tree blend walker (596b game): traverse skeleton list,         */
/* per-node compute pos = parent_pos + bone_offset * scale.            */
/* ------------------------------------------------------------------ */
extern void BootMod6487eClampAndChainMul10(void);
extern void Mul10HeavyTransform(void);
extern void MStackPush8(void);
extern void MStackPop8(void);
extern unsigned int g_dispatchSave6;
extern unsigned int g_savedNode;
extern unsigned int g_mul10TransformVar;

extern void QuadInterpolator(void);
extern void StoreDoubleNegPauseSubStore(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PoseTreeBlendWalker(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  MStackPush8();
  iVar1 = g_eventQueuePending;
  iVar4 = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
  iVar5 = g_savedNode;
  iVar6 = g_mul10TransformVar;
  if (g_framePauseFlag == 0) {
    while (g_dualD = iVar6, g_dualC = iVar5, g_cj_00542054 = iVar4, g_cj_00542058 = iVar1,
          g_cj_00542054 != 0) {
      iVar1 = g_cj_00542058 * 4;
      piVar2 = (int *)(g_dualC * 4);
      piVar3 = (int *)(g_dualD * 4);
      g_walkCallback = *(int *)(iVar1 + 0x3c);
      if ((g_walkCallback != 0) && (StoreDoubleNegPauseSubStore(), g_framePauseFlag != 0)) {
        return;
      }
      *piVar2 = g_walkCallback + *(int *)(iVar1 + 0x30);
      g_walkCallback = *(int *)(iVar1 + 0x40);
      if ((g_walkCallback != 0) && (StoreDoubleNegPauseSubStore(), g_framePauseFlag != 0)) {
        return;
      }
      piVar2[1] = g_walkCallback + *(int *)(iVar1 + 0x34);
      g_walkCallback = *(int *)(iVar1 + 0x44);
      if ((g_walkCallback != 0) && (StoreDoubleNegPauseSubStore(), g_framePauseFlag != 0)) {
        return;
      }
      piVar2[2] = g_walkCallback + *(int *)(iVar1 + 0x38);
      g_walkCallback = *(int *)(iVar1 + 0x24);
      if ((g_walkCallback != 0) && (StoreDoubleNegPauseSubStore(), g_framePauseFlag != 0)) {
        return;
      }
      g_walkCallback = g_walkCallback + *(int *)(iVar1 + 0x18);
      BootMod6487eClampAndChainMul10();
      if (g_framePauseFlag != 0) {
        return;
      }
      *piVar3 = g_walkCallback;
      g_walkCallback = *(int *)(iVar1 + 0x28);
      if ((g_walkCallback != 0) && (StoreDoubleNegPauseSubStore(), g_framePauseFlag != 0)) {
        return;
      }
      g_walkCallback = g_walkCallback + *(int *)(iVar1 + 0x1c);
      BootMod6487eClampAndChainMul10();
      if (g_framePauseFlag != 0) {
        return;
      }
      piVar3[1] = g_walkCallback;
      g_walkCallback = *(int *)(iVar1 + 0x2c);
      if ((g_walkCallback != 0) && (StoreDoubleNegPauseSubStore(), g_framePauseFlag != 0)) {
        return;
      }
      g_walkCallback = g_walkCallback + *(int *)(iVar1 + 0x20);
      BootMod6487eClampAndChainMul10();
      if (g_framePauseFlag != 0) {
        return;
      }
      piVar3[2] = g_walkCallback;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_dispatchSave6;
      g_eventQueuePending = g_dualD;
      Mul10HeavyTransform();
      if (g_framePauseFlag != 0) {
        return;
      }
      g_eventQueuePending = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_cj_00542054 + 4;
      QuadInterpolator();
      if (g_framePauseFlag != 0) {
        return;
      }
      g_framePauseFlag = 0;
      iVar1 = g_cj_00542058;
      iVar5 = g_dualC;
      iVar6 = g_dualD;
      iVar4 = MK4_NODE_AT(int, g_cj_00542054, 0);
    }
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_cj_00542054;
    g_eventQueuePending = g_cj_00542058;
    g_walkCallback = g_cj_00542054;
    MStackPop8();
  }
  return;
}
#else
__declspec(naked) void PoseTreeBlendWalker(void)
{
    __asm {
        push     ebx
        push     esi
        push     edi
        call     MStackPush8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_savedNode]
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      ecx, dword ptr [g_mul10TransformVar]
        mov      dword ptr [g_eventQueueEnd], eax
        test     eax, eax
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [g_eventQueueTotal], ecx
        mov      dword ptr [g_walkCallback], eax
        je       L_d8ba
    L_d6d0:
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [g_eventQueueTotal]
        lea      esi, [edx*4]
        lea      edi, [eax*4]
        lea      ebx, [ecx*4]
        mov      eax, dword ptr [esi + 0x3c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d719
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d719:
        add      eax, dword ptr [esi + 0x30]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edi], eax
        mov      eax, dword ptr [esi + 0x40]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d746
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d746:
        add      eax, dword ptr [esi + 0x34]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edi + 4], eax
        mov      eax, dword ptr [esi + 0x44]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d774
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d774:
        add      eax, dword ptr [esi + 0x38]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edi + 8], eax
        mov      eax, dword ptr [esi + 0x24]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d7a2
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d7a2:
        add      eax, dword ptr [esi + 0x18]
        mov      dword ptr [g_walkCallback], eax
        call     BootMod6487eClampAndChainMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ebx], edx
        mov      eax, dword ptr [esi + 0x28]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d7e7
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d7e7:
        add      eax, dword ptr [esi + 0x1c]
        mov      dword ptr [g_walkCallback], eax
        call     BootMod6487eClampAndChainMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d0
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ebx + 4], eax
        mov      eax, dword ptr [esi + 0x2c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d82c
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d82c:
        add      eax, dword ptr [esi + 0x20]
        mov      dword ptr [g_walkCallback], eax
        call     BootMod6487eClampAndChainMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d0
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [ebx + 8], ecx
        mov      edx, dword ptr [g_dispatchSave6]
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_xformEntityIdx], eax
        call     Mul10HeavyTransform
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d0
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      edx, 4
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_currentNodeIdx], edx
        call     QuadInterpolator
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d0
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [eax*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueEnd], eax
        jne      L_d6d0
    L_d8ba:
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     MStackPop8
    L_d8d0:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
#endif
