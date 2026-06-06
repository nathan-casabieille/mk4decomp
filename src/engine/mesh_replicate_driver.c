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

extern unsigned int g_dispatchSave732;
extern unsigned int g_dispatchSave122;
extern void DirtyDoubleDeref(void);
extern void MStackBracket1_TreeWalkRecursive2(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackPush3LinkedListWalk(void);
extern void PushPopScaled1cDoubleCall(void);
extern void ScaledLoadDirtyOrSetJmp(void);
extern void StoreLoadJmp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MeshReplicateDriver(void)

{
  StoreLoadJmp(&(*(unsigned int *)MK4_VA(unsigned int, 0x4738a0)));
  StoreLoadJmp(&(*(unsigned int *)MK4_VA(unsigned int, 0x473a80)));
  g_eventQueueWorkType = *(int *)(MK4_NODE_AT(int, g_cj_0054205c, 0x1c) * 4) + 1;
  g_dualC = 0x13b2d6;
  g_chainAccumCur = g_eventQueueWorkType;
  g_walkCallback = g_dispatchSave732;
  while( true ) {
    if (g_walkCallback == 0) {
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_cj_0054205c;
      MStackBracket4_ListInsertZeroFill();
      if ((((g_framePauseFlag == 0) && (((byte)g_xformDirtyFlags & 4) == 0)) &&
          (MStackPush3LinkedListWalk(), g_framePauseFlag == 0)) && (((byte)g_xformDirtyFlags & 4) == 0)) {
        ScaledLoadDirtyOrSetJmp();
      }
      return;
    }
    DirtyDoubleDeref();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_dualD = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    g_eventQueuePending = 0x145254;
    MStackBracket1_TreeWalkRecursive2();
    if (g_framePauseFlag != 0) {
      return;
    }
    if (((byte)g_xformDirtyFlags & 4) != 0) break;
    *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x3c) = MK4_NODE_AT(undefined4, g_dualC, 0);
    g_dualC = g_dualC + 1;
    *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x40) = MK4_NODE_AT(undefined4, g_dualC, 0);
    g_dualC = g_dualC + 1;
    *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x30) = MK4_NODE_AT(int, g_dualD, 0x30) >> 1;
    *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x34) = MK4_NODE_AT(int, g_dualD, 0x34) >> 1;
    *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x38) = MK4_NODE_AT(int, g_dualD, 0x38) >> 1;
    g_walkCallback = *(uint *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x20) & 0xfaffffff | 0xa001000;
    *(uint *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x20) = g_walkCallback;
    g_eventQueuePending = MK4_NODE_AT(undefined4, g_dualD, 0x14);
    PushPopScaled1cDoubleCall();
    if (g_framePauseFlag != 0) {
      return;
    }
    *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x1c) = g_eventQueueWorkType;
    g_eventQueueWorkType = g_eventQueueWorkType + 1;
    g_walkCallback = MK4_NODE_AT(int, g_dualC, 0);
  }
  return;
}
#else
__declspec(naked) void MeshReplicateDriver(void)
{
    __asm {
        push     ebx
        push     esi
        push     0x4738a0
        call     StoreLoadJmp
        add      esp, 4
        push     0x473a80
        call     StoreLoadJmp
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, OFFSET g_dispatchSave732
        add      esp, 4
        mov      bl, 4
        mov      eax, dword ptr [eax*4 + 0x1c]
        mov      dword ptr [g_pendingNodeType], eax
        mov      eax, dword ptr [eax*4]
        inc      eax
        shr      ecx, 2
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_chainAccumCur], eax
        mov      ecx, dword ptr [ecx*4]
        test     ecx, ecx
        mov      dword ptr [g_walkCallback], ecx
        je       L_3403
        mov      esi, 0xa001000
    L_3289:
        call     DirtyDoubleDeref
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3440
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, OFFSET g_dispatchSave122
        shr      edx, 2
        mov      dword ptr [g_eventQueueTotal], ecx
        mov      dword ptr [g_xformEntityIdx], edx
        call     MStackBracket1_TreeWalkRecursive2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3440
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_3440
        mov      eax, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      eax, dword ptr [g_pendingNodeType]
        mov      edx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x40], eax
        mov      edx, dword ptr [g_pendingNodeType]
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      edx
        mov      dword ptr [g_pendingNodeType], edx
        mov      eax, dword ptr [eax*4 + 0x30]
        sar      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x34]
        sar      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x38]
        sar      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x38], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x20]
        mov      dword ptr [g_xformEntityIdx], esi
        and      eax, 0xfaffffff
        or       eax, esi
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x20], eax
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      eax, dword ptr [edx*4 + 0x14]
        mov      dword ptr [g_xformEntityIdx], eax
        call     PushPopScaled1cDoubleCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3440
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [edx*4 + 0x1c], ecx
        mov      edx, dword ptr [g_eventQueueWorkType]
        mov      eax, dword ptr [g_pendingNodeType]
        inc      edx
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      eax, dword ptr [eax*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      L_3289
    L_3403:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackBracket4_ListInsertZeroFill
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3440
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_3440
        call     MStackPush3LinkedListWalk
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3440
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_3440
        call     ScaledLoadDirtyOrSetJmp
    L_3440:
        pop      esi
        pop      ebx
        ret
    }
}
#endif
