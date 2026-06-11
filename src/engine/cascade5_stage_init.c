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

/* @addr 0x00491520 (205b game) - 5-stage cascade init.
 *   call ScaledMove48to58; if !pause: scaledInit=(arg0>>2); call GDispatch1; if !pause: call DirtyToggleByGate;
 *   if !pause: bit-2 check; if not set call GuardedDualConst2AndToggle; if !pause: bit-0 check;
 *   if set jmp InstallSelfScaledChain; baseSel[*4+0x74]=0x200e; eax=[g_cj_00542054*4 + 0]; g_walkCallback=eax;
 *   call MStackFrameCdeclDouble; if !pause: g_xformEntityIdx = [g_cj_00542054*4 + 4],
 *   store to [g_fightGroupHead*4 + 0x24], clear g_walkCallback; jmp StoreGuardedBitInstallJmp. ret.
 */
extern void GDispatch1_DualCondMatchSet_then_ScaledInitWithCounterAndType(void);
extern void InstallSelfScaledChain(void);
extern void ScaledMove48to58(void);
extern void StoreGuardedBitInstallJmp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Cascade5StageInit(int param_1)

{
  int iVar1;
  int iVar2;
  
  ScaledMove48to58();
  if (g_framePauseFlag == 0) {
    g_cj_00542054 = param_1 >> 2;
    GDispatch1_DualCondMatchSet_then_ScaledInitWithCounterAndType();
    if ((g_framePauseFlag == 0) && (DirtyToggleByGate(), g_framePauseFlag == 0)) {
      if (((byte)g_xformDirtyFlags & 4) == 0) {
        GuardedDualConst2AndToggle();
        if (g_framePauseFlag != 0) {
          return;
        }
        if (((byte)g_xformDirtyFlags & 1) != 0) {
          iVar1 = g_baseSel * 4;
          iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
          *(undefined4 *)(iVar1 + 0x84) = 0;
          if (iVar2 == 0) {
            g_walkCallback = MK4_NODE_AT(undefined4, g_cj_00542054, 8);
            MStackFrameCdeclDouble();
            if (g_framePauseFlag == 0) {
              g_eventQueuePending = MK4_NODE_AT(undefined4, g_cj_00542054, 0xc);
              MK4_NODE_AT(undefined4, g_cj_0054205c, 0x24) = g_eventQueuePending;
              *(undefined4 *)(iVar1 + 8) = 0x4916f0;
              MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 1;
              (g_currentNodeIdx) = *(int *)(iVar1 + 4);
              *MK4_NODE(undefined4, (g_currentNodeIdx)) = 0x14916f0;
              (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
              *(int *)(iVar1 + 4) = (g_currentNodeIdx);
              MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
              ScaledClearJmp_EsiInstallBitCallChain();
              g_framePauseFlag = 1;
            }
          }
          else {
            SlotPhaseResetInstallChain();
            if ((g_framePauseFlag == 0) && (ScaledZeroFour(), g_framePauseFlag == 0)) {
              CallPauseScaledStorePushCall();
              return;
            }
          }
          return;
        }
      }
      MK4_NODE_AT(undefined4, g_baseSel, 0x74) = 0x200e;
      g_walkCallback = MK4_NODE_AT(undefined4, g_cj_00542054, 0);
      MStackFrameCdeclDouble();
      if (g_framePauseFlag == 0) {
        g_eventQueuePending = MK4_NODE_AT(undefined4, g_cj_00542054, 4);
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x24) = g_eventQueuePending;
        g_walkCallback = 0;
        while( true ) {
          MK4_NODE_AT(int, g_cj_0054205c, 0x28) = g_walkCallback;
          GuardedChainCmpDualBitXor();
          if ((g_framePauseFlag != 0) || (DirtyToggleByGate(), g_framePauseFlag != 0)) {
            return;
          }
          if (((byte)g_xformDirtyFlags & 4) != 0) {
            g_matrixStackTop = g_matrixStackTop + 1;
            *MK4_NODE(undefined4, (int)g_matrixStackTop) = 0x491660;
            GameDispatchValidateState();
            return;
          }
          GuardedScaledChainJmpIndirect(&(*(unsigned int *)MK4_VA(unsigned int, 0x4f12b8)));
          if (g_framePauseFlag != 0) break;
          iVar2 = g_baseSel * 4;
          iVar1 = *(int *)(iVar2 + 0x84);
          *(undefined4 *)(iVar2 + 0x84) = 0;
          if (iVar1 == 0) {
            *(undefined4 *)(iVar2 + 8) = 0x491660;
            *(undefined4 *)(iVar2 + 0x84) = 1;
            g_framePauseFlag = 1;
            g_dualC = 1;
            return;
          }
          (g_currentNodeIdx) = MK4_NODE_AT(int, g_cj_0054205c, 0x24);
          g_walkCallback = MK4_NODE_AT(int, g_cj_0054205c, 0x28) + 1;
          if (MK4_NODE_AT(int, (g_currentNodeIdx), 4) <= g_walkCallback) {
            SlotPhaseResetInstallChain();
            if ((g_framePauseFlag == 0) && (ScaledZeroFour(), g_framePauseFlag == 0)) {
              CjInstallSelfRouter();
              return;
            }
            return;
          }
        }
        return;
      }
    }
  }
  return;
}
#else
__declspec(naked) void Cascade5StageInit(void) {
    __asm {
        call    ScaledMove48to58
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0bah
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_cj_00542054], eax
        call    GDispatch1_DualCondMatchSet_then_ScaledInitWithCounterAndType
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   9ch
        _emit   00h
        _emit   00h
        _emit   00h
        call    DirtyToggleByGate
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   8ah
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   1ch
        call    GuardedDualConst2AndToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   73h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     InstallSelfScaledChain
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x0000200e
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        mov     edx, dword ptr [g_cj_00542054]
        mov     eax, dword ptr [edx*4 + 0]
        mov     dword ptr [g_walkCallback], eax
        call    MStackFrameCdeclDouble
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2eh
        mov     ecx, dword ptr [g_cj_00542054]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 4]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [edx*4 + 0x24], eax
        mov     dword ptr [g_walkCallback], 0
        jmp     StoreGuardedBitInstallJmp
        ret
    }
}
#endif
