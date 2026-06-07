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
 * AudioChainStateInitSequence - 294b audio multi-stage chain init.
 *   g_xformEntityIdx = (0x0050f1bc >> 2); call FramePauseScaledStore. If paused: ret.
 *   If g_xformDirtyFlags & 4: tail-jmp TestEqJmpInitFightGroup.
 *   Else: chain[g_currentNodeIdx + 0x1c] = g_pendingNodeType; g_xformEntityIdx = g_eventQueueTotal;
 *     call MStackPush2ChainPrepend. If paused: ret.
 *   chain[+0x30] = g_walkCallback = 0x80000; chain[+0x34] = g_walkCallback;
 *   chain[+0x38] = g_walkCallback = 0x83; g_currentNodeIdx = g_fightGroupHead; call MStackBracket4_ListInsertZeroFill.
 *   If paused: ret. If g_xformDirtyFlags & 4: jmp 0x004a173f.
 *   Else call MStackPush3LinkedListWalk. If paused: ret.
 *   If g_xformDirtyFlags & 4: tail-jmp TestEqJmpInitFightGroup.
 *   Else g_walkCallback = g_pendingNodeType; call ChainDirtyBitWalker. If paused: ret.
 *   chain[g_xformEntityIdx*4 + 0x14] = 0x80; chain[+0x10] = g_walkCallback = 0x004ba0e0;
 *   tail-jmp TestEqJmpInitFightGroup.
 */
extern unsigned int g_dispatchSave126;
extern void FramePauseScaledStore(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackPush2ChainPrepend(void);
extern void MStackPush3LinkedListWalk(void);
extern void TestEqJmpInitFightGroup(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void AudioChainStateInitSequence(void)

{
  int iVar1;
  int iVar2;
  
  g_eventQueuePending = 0x143c6f;
  FramePauseScaledStore();
  if (g_framePauseFlag == 0) {
    if (((byte)g_xformDirtyFlags & 4) != 0) {
LAB_004a1740:
      if (g_cj_00542054 == 0) {
        g_eventQueueWorkType = 0xfef20000;
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x30) = 0x25a;
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x6c) = 0x50000;
      }
      else {
        g_eventQueueWorkType = 0x1020000;
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x30) = 0x25b;
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x6c) = 0xfffb0000;
      }
      iVar1 = g_baseSel * 4;
      iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
      *(undefined4 *)(iVar1 + 0x84) = 0;
      if (iVar2 != 0) {
        if (iVar2 == 1) {
          g_walkCallback = g_cj_00542054;
          if (g_cj_00542054 != 0) {
            InstallSelfChainAddSigned();
            return;
          }
        }
        else {
          g_walkCallback = MK4_NODE_AT(int, g_cj_0054205c, 0x6c) + -0x4000;
          MK4_NODE_AT(int, g_cj_0054205c, 0x6c) = g_walkCallback;
          if (g_walkCallback < 1) {
            ScaledInitOrSelfPtrSetType14();
            return;
          }
        }
        *(undefined4 *)(iVar1 + 8) = 0x4a17d0;
        *(undefined4 *)(iVar1 + 0x84) = 2;
        g_dualC = 1;
        g_framePauseFlag = 1;
        return;
      }
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x54) = g_eventQueueWorkType;
      g_walkCallback = 0;
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x58) = 0;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_cj_0054205c;
      MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430();
      if (g_framePauseFlag == 0) {
        *(undefined4 *)(iVar1 + 8) = 0x4a17d0;
        *(undefined4 *)(iVar1 + 0x84) = 1;
        g_dualC = 0x1c;
        g_framePauseFlag = 1;
      }
      return;
    }
    *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x1c) = g_dualC;
    g_eventQueuePending = g_dualD;
    MStackPush2ChainPrepend();
    if (g_framePauseFlag == 0) {
      g_walkCallback = 0x80000;
      *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x30) = 0x80000;
      *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x34) = g_walkCallback;
      g_walkCallback = 0x83;
      *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x38) = 0x83;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_cj_0054205c;
      MStackBracket4_ListInsertZeroFill();
      if (g_framePauseFlag == 0) {
        if (((byte)g_xformDirtyFlags & 4) == 0) {
          MStackPush3LinkedListWalk();
          if (g_framePauseFlag != 0) {
            return;
          }
          if (((byte)g_xformDirtyFlags & 4) == 0) {
            g_walkCallback = g_dualC;
            ChainDirtyBitWalker();
            if (g_framePauseFlag != 0) {
              return;
            }
            MK4_NODE_AT(undefined4, g_eventQueuePending, 0x14) = 0x80;
            *(code **)(g_eventQueuePending * 4 + 0x10) = ClampMulShiftStore;
          }
        }
        goto LAB_004a1740;
      }
    }
  }
  return;
}
#else
__declspec(naked) void AudioChainStateInitSequence(void)
{
    __asm
    {
        mov     eax, offset g_dispatchSave126
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    FramePauseScaledStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_a16_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_a16_continue
        jmp     TestEqJmpInitFightGroup
    L_a16_continue:
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_pendingNodeType]
        mov     dword ptr [ecx*4 + 0x1c], edx
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     dword ptr [g_xformEntityIdx], eax
        call    MStackPush2ChainPrepend
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_a16_ret
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, 0x80000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x34], edx
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, 0x83
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x38], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackBracket4_ListInsertZeroFill
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a16_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_a16_callPush3
        jmp     TestEqJmpInitFightGroup
    L_a16_callPush3:
        call    MStackPush3LinkedListWalk
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a16_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_a16_callDirty
        jmp     TestEqJmpInitFightGroup
    L_a16_callDirty:
        mov     eax, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_walkCallback], eax
        call    ChainDirtyBitWalker
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a16_ret
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x004ba0e0
        mov     dword ptr [ecx*4 + 0x14], 0x80
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x10], eax
        jmp     TestEqJmpInitFightGroup
    L_a16_ret:
        ret
    }
}
#endif
