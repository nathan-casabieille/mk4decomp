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

extern unsigned int g_eventMusicSlot2;
extern unsigned int g_dispatchVar3;
extern unsigned int g_eventMusicSlot;
extern void Helper_Sprintf(void);
extern void PushPopPendingTwoCalls(void);
extern void ScaledStoreCallEpilogue(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MultiPlayerWinStringFormat(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  
  PushPopPendingTwoCalls();
  iVar2 = g_eventMusicSlot;
  iVar4 = g_dispatchVar3;
  if (g_framePauseFlag != 0) {
    return;
  }
  g_walkCallback = g_eventMusicSlot2;
  g_currentNodeFlags = 0x14000;
  if (g_eventMusicSlot2 == 1) {
    if ((g_active_0053a408 == 0) && (g_active_00537e88 == 1)) {
      g_dispatchVar3 = g_dispatchVar3 + -1;
      if ((int)g_dispatchVar3 < 0) {
        g_walkCallback = g_eventMusicSlot2;
        g_currentNodeFlags = 0x14000;
        return;
      }
      Helper_Sprintf(MK4_VA(unsigned int, 0x543450),&g_dispatchSave1178,iVar4);
      pcVar6 = MK4_VA(char, 0x004d56e8);
      if (g_dispatchVar3 < 1) {
        pcVar6 = MK4_VA(char, 0x004d56f8);
      }
      uVar3 = 0xffffffff;
      do {
        pcVar8 = pcVar6;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      pcVar6 = (char *)MK4_VA(unsigned int, 0x543450);
      do {
        pcVar7 = pcVar6;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      pcVar6 = pcVar8 + -uVar3;
      pcVar8 = pcVar7 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar8 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      }
      uVar3 = 0xffffffff;
      pcVar6 = MK4_VA(char, 0x004d5708);
      do {
        pcVar8 = pcVar6;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      pcVar6 = (char *)MK4_VA(unsigned int, 0x543450);
      do {
        pcVar7 = pcVar6;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      pcVar6 = pcVar8 + -uVar3;
      pcVar8 = pcVar7 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar8 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      }
      AllocSlotPushTripleGlobals();
      if (g_framePauseFlag != 0) {
        return;
      }
      g_eventQueuePending = 0x150d14;
      g_walkCallback = 0x238;
      g_eventQueueCurrent = 4;
      g_chainAccumCur = &g_imageBaseHi;
      g_eventQueueNotMask = (undefined *)0x370000;
      Push70CallScaleArith();
      if (g_framePauseFlag != 0) {
        return;
      }
      MStackPop4Rewrite();
      if (g_framePauseFlag != 0) {
        return;
      }
      MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x5c) = g_currentNodeFlags;
    }
    AllocSlotPushTripleGlobals();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_walkCallback = 0x238;
    g_eventQueuePending = 0x13555e;
    g_eventQueueCurrent = 4;
    g_chainAccumCur = &g_imageBaseHi;
    g_eventQueueNotMask = MK4_VA(unsigned int, 0x500000);
    Push70CallScaleArith();
    if (g_framePauseFlag != 0) {
      return;
    }
    MStackPop4Rewrite();
    if (g_framePauseFlag != 0) {
      return;
    }
    MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x5c) = g_currentNodeFlags;
    AllocSlotPushTripleGlobals();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_eventQueuePending = 0x135562;
    g_walkCallback = 0x238;
    g_eventQueueCurrent = 4;
    g_chainAccumCur = MK4_VA(unsigned int, 0x610000);
    g_eventQueueNotMask = MK4_VA(unsigned int, 0x640000);
    Push70CallScaleArith();
    if (g_framePauseFlag != 0) {
      return;
    }
    MStackPop4Rewrite();
    if (g_framePauseFlag != 0) {
      return;
    }
    MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x5c) = g_currentNodeFlags;
    AllocSlotPushTripleGlobals();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_walkCallback = 0x238;
    g_eventQueuePending = 0x13558a;
    g_eventQueueCurrent = 4;
    g_chainAccumCur = MK4_VA(unsigned int, 0x610000);
    g_eventQueueNotMask = (undefined *)0x780000;
    Push70CallScaleArith();
    if (g_framePauseFlag != 0) {
      return;
    }
    MStackPop4Rewrite();
  }
  else {
    if ((g_active_0053a408 == 1) && (g_active_00537e88 == 0)) {
      g_eventMusicSlot = g_eventMusicSlot + -1;
      if ((int)g_eventMusicSlot < 0) {
        g_walkCallback = g_eventMusicSlot2;
        g_currentNodeFlags = 0x14000;
        return;
      }
      Helper_Sprintf(MK4_VA(unsigned int, 0x543450),&g_dispatchSave1178,iVar2);
      pcVar6 = MK4_VA(char, 0x004d56e8);
      if (g_eventMusicSlot < 1) {
        pcVar6 = MK4_VA(char, 0x004d56f8);
      }
      uVar3 = 0xffffffff;
      do {
        pcVar8 = pcVar6;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      pcVar6 = (char *)MK4_VA(unsigned int, 0x543450);
      do {
        pcVar7 = pcVar6;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      pcVar6 = pcVar8 + -uVar3;
      pcVar8 = pcVar7 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar8 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      }
      uVar3 = 0xffffffff;
      pcVar6 = MK4_VA(char, 0x004d5708);
      do {
        pcVar8 = pcVar6;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      pcVar6 = (char *)MK4_VA(unsigned int, 0x543450);
      do {
        pcVar7 = pcVar6;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      pcVar6 = pcVar8 + -uVar3;
      pcVar8 = pcVar7 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar8 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      }
      AllocSlotPushTripleGlobals();
      if (g_framePauseFlag != 0) {
        return;
      }
      g_eventQueuePending = 0x150d14;
      g_walkCallback = 0x238;
      g_eventQueueCurrent = 4;
      g_chainAccumCur = (undefined *)0xffa60000;
      g_eventQueueNotMask = (undefined *)0x370000;
      Push70CallScaleArith();
      if (g_framePauseFlag != 0) {
        return;
      }
      MStackPop4Rewrite();
      if (g_framePauseFlag != 0) {
        return;
      }
      MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x5c) = g_currentNodeFlags;
    }
    AllocSlotPushTripleGlobals();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_walkCallback = 0x238;
    g_eventQueuePending = 0x13555a;
    g_eventQueueCurrent = 4;
    g_chainAccumCur = (undefined *)0xffa60000;
    g_eventQueueNotMask = MK4_VA(unsigned int, 0x500000);
    Push70CallScaleArith();
    if (g_framePauseFlag != 0) {
      return;
    }
    MStackPop4Rewrite();
    if (g_framePauseFlag != 0) {
      return;
    }
    MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x5c) = g_currentNodeFlags;
    AllocSlotPushTripleGlobals();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_eventQueuePending = 0x135562;
    g_walkCallback = 0x238;
    g_eventQueueCurrent = 4;
    g_chainAccumCur = (undefined *)0xff9f0000;
    g_eventQueueNotMask = MK4_VA(unsigned int, 0x640000);
    Push70CallScaleArith();
    if (g_framePauseFlag != 0) {
      return;
    }
    MStackPop4Rewrite();
    if (g_framePauseFlag != 0) {
      return;
    }
    MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x5c) = g_currentNodeFlags;
    AllocSlotPushTripleGlobals();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_walkCallback = 0x238;
    g_eventQueuePending = 0x13558a;
    g_eventQueueCurrent = 4;
    g_chainAccumCur = (undefined *)0xff9f0000;
    g_eventQueueNotMask = (undefined *)0x780000;
    Push70CallScaleArith();
    if (g_framePauseFlag != 0) {
      return;
    }
    MStackPop4Rewrite();
  }
  if (g_framePauseFlag == 0) {
    MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x5c) = g_currentNodeFlags;
    Event23bMusicCluster();
  }
  return;
}
#else
__declspec(naked) void MultiPlayerWinStringFormat(void)
{
    __asm {
        push     ebp
        push     esi
        push     edi
        call     PushPopPendingTwoCalls
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x13
        _emit    0x05
        _emit    0x00
        _emit    0x00
        mov      eax, dword ptr [g_eventMusicSlot2]
        mov      esi, 1
        mov      dword ptr [g_walkCallback], eax
        cmp      eax, esi
        mov      eax, dword ptr [g_active_0053a408]
        mov      dword ptr [g_currentNodeFlags], 0x14000
        mov      ebp, 4
        jne      L_f272
        test     eax, eax
        jne      L_f11c
        cmp      dword ptr [g_active_00537e88], esi
        jne      L_f11c
        mov      eax, dword ptr [g_dispatchVar3]
        dec      eax
        mov      dword ptr [g_dispatchVar3], eax
        /* js 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x88
        _emit    0xc3
        _emit    0x04
        _emit    0x00
        _emit    0x00
        inc      eax
        push     eax
        push     0x4d56d0
        push     0x543450
        call     Helper_Sprintf
        mov      eax, dword ptr [g_dispatchVar3]
        add      esp, 0xc
        cmp      eax, esi
        mov      edi, 0x4d56e8
        jge      L_f04c
        mov      edi, 0x4d56f8
    L_f04c:
        or       ecx, 0xffffffff
        xor      eax, eax
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      edx, ecx
        mov      edi, 0x543450
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, edx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, edx
        and      ecx, 3
        rep movsb
        mov      edi, 0x4d5708
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      edx, ecx
        mov      edi, 0x543450
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, edx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, edx
        and      ecx, 3
        rep movsb
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x37
        _emit    0x04
        _emit    0x00
        _emit    0x00
        mov      eax, 0x543450
        mov      edi, 0x238
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_chainAccumCur], 0x5a0000
        mov      dword ptr [g_eventQueueNotMask], 0x370000
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xf3
        _emit    0x03
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xe1
        _emit    0x03
        _emit    0x00
        _emit    0x00
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        jmp      L_f121
    L_f11c:
        mov      edi, 0x238
    L_f121:
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xb5
        _emit    0x03
        _emit    0x00
        _emit    0x00
        mov      eax, 0x4d5578
        mov      dword ptr [g_walkCallback], edi
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_chainAccumCur], 0x5a0000
        mov      dword ptr [g_eventQueueNotMask], 0x500000
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x76
        _emit    0x03
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x64
        _emit    0x03
        _emit    0x00
        _emit    0x00
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x3f
        _emit    0x03
        _emit    0x00
        _emit    0x00
        mov      eax, 0x4d5588
        mov      esi, 0x610000
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_chainAccumCur], esi
        mov      dword ptr [g_eventQueueNotMask], 0x640000
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xff
        _emit    0x02
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xed
        _emit    0x02
        _emit    0x00
        _emit    0x00
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xc8
        _emit    0x02
        _emit    0x00
        _emit    0x00
        mov      eax, 0x4d5628
        mov      dword ptr [g_walkCallback], edi
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_chainAccumCur], esi
        mov      dword ptr [g_eventQueueNotMask], 0x780000
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x8d
        _emit    0x02
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x7b
        _emit    0x02
        _emit    0x00
        _emit    0x00
        jmp      ScaledStoreCallEpilogue
    L_f272:
        cmp      eax, esi
        jne      L_f38f
        mov      eax, dword ptr [g_active_00537e88]
        test     eax, eax
        jne      L_f38f
        mov      eax, dword ptr [g_eventMusicSlot]
        dec      eax
        mov      dword ptr [g_eventMusicSlot], eax
        /* js 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x88
        _emit    0x50
        _emit    0x02
        _emit    0x00
        _emit    0x00
        inc      eax
        push     eax
        push     0x4d56d0
        push     0x543450
        call     Helper_Sprintf
        mov      eax, dword ptr [g_eventMusicSlot]
        add      esp, 0xc
        cmp      eax, esi
        mov      edi, 0x4d56e8
        jge      L_f2bf
        mov      edi, 0x4d56f8
    L_f2bf:
        or       ecx, 0xffffffff
        xor      eax, eax
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      edx, ecx
        mov      edi, 0x543450
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, edx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, edx
        and      ecx, 3
        rep movsb
        mov      edi, 0x4d5708
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      edx, ecx
        mov      edi, 0x543450
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, edx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, edx
        and      ecx, 3
        rep movsb
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xc4
        _emit    0x01
        _emit    0x00
        _emit    0x00
        mov      eax, 0x543450
        mov      edi, 0x238
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_chainAccumCur], 0xffa60000
        mov      dword ptr [g_eventQueueNotMask], 0x370000
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x80
        _emit    0x01
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x6e
        _emit    0x01
        _emit    0x00
        _emit    0x00
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        jmp      L_f394
    L_f38f:
        mov      edi, 0x238
    L_f394:
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x42
        _emit    0x01
        _emit    0x00
        _emit    0x00
        mov      eax, 0x4d5568
        mov      dword ptr [g_walkCallback], edi
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_chainAccumCur], 0xffa60000
        mov      dword ptr [g_eventQueueNotMask], 0x500000
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x03
        _emit    0x01
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xf1
        _emit    0x00
        _emit    0x00
        _emit    0x00
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xcc
        _emit    0x00
        _emit    0x00
        _emit    0x00
        mov      eax, 0x4d5588
        mov      esi, 0xff9f0000
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_chainAccumCur], esi
        mov      dword ptr [g_eventQueueNotMask], 0x640000
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x8c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x75
        _emit    0x7e
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x75
        _emit    0x5d
        mov      eax, 0x4d5628
        mov      dword ptr [g_walkCallback], edi
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_chainAccumCur], esi
        mov      dword ptr [g_eventQueueNotMask], 0x780000
        call     Push70CallScaleArith
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x75
        _emit    0x26
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x75
        _emit    0x18
    }
}
#endif
