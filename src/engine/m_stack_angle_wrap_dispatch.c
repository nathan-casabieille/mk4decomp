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

extern void RandSarMod0xFFFSub400(void);
extern void RandSarMod0xFFF(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MStackAngleWrapDispatch(int param_1)

{
  int iVar1;
  uint uVar2;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_eventQueueCurrent;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_eventQueueChild;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_currentNodeFlags;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_xformScratch2088;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_eventQueuePending;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_chainAccumCur;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_eventQueueNotMask;
  if ((int)g_eventQueueWorkType < 0) {
    g_eventQueueWorkType = g_eventQueueWorkType + ((0x6487d - g_eventQueueWorkType) / 0x6487e) * 0x6487e;
  }
  if (0x6487d < (int)g_eventQueueWorkType) {
    uVar2 = g_eventQueueWorkType / 0x6487e;
    do {
      g_eventQueueWorkType = g_eventQueueWorkType - 0x6487e;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  g_matrixStackTop = g_matrixStackTop + 1;
  *(uint *)((int)g_matrixStackTop * 4) = g_eventQueueWorkType;
  RandSarMod0xFFF();
  if (g_framePauseFlag == 0) {
    g_eventQueueWorkType = *(uint *)((int)g_matrixStackTop * 4);
    *(undefined4 *)((int)g_matrixStackTop * 4) = g_walkCallback;
    RandSarMod0xFFFSub400();
    if (g_framePauseFlag == 0) {
      g_eventQueueCurrent = *(undefined4 *)((int)g_matrixStackTop * 4);
      g_eventQueueNotMask = *(undefined4 *)((int)(g_matrixStackTop + -1) * 4);
      g_chainAccumCur = *(undefined4 *)((int)(g_matrixStackTop + -2) * 4);
      g_eventQueuePending = *(undefined4 *)((int)(g_matrixStackTop + -3) * 4);
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(undefined4 *)((int)(g_matrixStackTop + -4) * 4);
      g_matrixStackTop = g_matrixStackTop + -5;
      g_eventQueueChild = Mul10Tail(g_chainAccumCur,g_eventQueueCurrent);
      g_currentNodeFlags = Mul10Tail(g_eventQueueNotMask,g_walkCallback);
      iVar1 = g_currentNodeFlags;
      if (param_1 == 0) {
        iVar1 = -g_currentNodeFlags;
      }
      g_xformScratch2088 = iVar1 + g_eventQueueChild;
      g_eventQueueChild = Mul10Tail(g_eventQueueNotMask,g_eventQueueCurrent);
      iVar1 = Mul10Tail(g_chainAccumCur,g_walkCallback);
      g_eventQueueNotMask = g_eventQueueChild - iVar1;
      g_chainAccumCur = g_xformScratch2088;
      g_xformScratch2088 = *(undefined4 *)((int)g_matrixStackTop * 4);
      g_currentNodeFlags = *(undefined4 *)((int)(g_matrixStackTop + -1) * 4);
      g_eventQueueChild = *(undefined4 *)((int)(g_matrixStackTop + -2) * 4);
      g_eventQueueCurrent = *(undefined4 *)((int)(g_matrixStackTop + -3) * 4);
      g_matrixStackTop = g_matrixStackTop + -4;
    }
  }
  return;
}
#else
__declspec(naked) void MStackAngleWrapDispatch(void)
{
    __asm {
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        inc      eax
        push     esi
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueChild]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeFlags]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_xformScratch2088]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_xformEntityIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_chainAccumCur]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueNotMask]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      ecx, dword ptr [g_eventQueueWorkType]
        test     ecx, ecx
        jge      short L_b8ea
        mov      edx, 0x6487d
        mov      eax, 0xa2f99905
        sub      edx, ecx
        mul      edx
        shr      edx, 0x12
        imul     edx, edx, 0x6487e
        add      ecx, edx
        mov      dword ptr [g_eventQueueWorkType], ecx
    L_b8ea:
        cmp      ecx, 0x6487e
        jl       short L_b90b
        mov      eax, 0xa2f99905
        mul      ecx
        shr      edx, 0x12
    L_b8fc:
        sub      ecx, 0x6487e
        dec      edx
        jne      short L_b8fc
        mov      dword ptr [g_eventQueueWorkType], ecx
    L_b90b:
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     RandSarMod0xFFF
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bab2
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      dword ptr [eax*4], edx
        call     RandSarMod0xFFFSub400
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_bab2
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueNotMask], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_chainAccumCur], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      esi, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_xformEntityIdx], esi
        mov      dword ptr [g_matrixStackTop], eax
        mov      esi, dword ptr [eax*4]
        dec      eax
        push     ecx
        push     edx
        mov      dword ptr [g_currentNodeIdx], esi
        mov      dword ptr [g_matrixStackTop], eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueNotMask]
        add      esp, 8
        mov      dword ptr [g_eventQueueChild], eax
        mov      eax, dword ptr [g_walkCallback]
        push     eax
        push     ecx
        call     Mul10Tail
        mov      ecx, dword ptr [esp + 0x10]
        add      esp, 8
        test     ecx, ecx
        mov      dword ptr [g_currentNodeFlags], eax
        je       short L_ba09
        mov      edx, dword ptr [g_eventQueueChild]
        add      eax, edx
        mov      dword ptr [g_xformScratch2088], eax
        jmp      short L_ba17
    L_ba09:
        mov      ecx, dword ptr [g_eventQueueChild]
        sub      ecx, eax
        mov      dword ptr [g_xformScratch2088], ecx
    L_ba17:
        mov      edx, dword ptr [g_eventQueueCurrent]
        mov      eax, dword ptr [g_eventQueueNotMask]
        push     edx
        push     eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_chainAccumCur]
        add      esp, 8
        mov      dword ptr [g_eventQueueChild], eax
        push     ecx
        push     edx
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      edx, dword ptr [g_xformScratch2088]
        sub      ecx, eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      dword ptr [g_eventQueueNotMask], ecx
        mov      dword ptr [g_chainAccumCur], edx
        mov      ecx, dword ptr [eax*4]
        add      esp, 8
        dec      eax
        mov      dword ptr [g_xformScratch2088], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeFlags], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueChild], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], edx
        mov      dword ptr [g_matrixStackTop], eax
    L_bab2:
        pop      esi
        ret
    }
}
#endif
