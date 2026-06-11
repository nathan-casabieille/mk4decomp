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

/* @addr 0x00415010 (356b boot) - mstack-push-8 + slot-init chain + pop-8.
 *   MStackPush8 reserves 8 slots; on no-error stashes
 *   g_fightGroupHead into g_eventQueueEnd and sets g_walkCallback =
 *   &g_dispatchSave561>>2. Calls PushSetXfmMaskCallPop. On
 *   no-error AND bit 2 of g_xformDirtyFlags clear: writes 0xa1 into
 *   [g_fightGroupHead*4+0x30], copies [old_054054*4+0x34] into the new
 *   slot's +0x34, calls ScaledTripleCopy54. On no-error:
 *   copies [old+0x68] into new+0x68, sets g_walkCallback=0xfffffeb9
 *   and calls MStackPushNegMul10. On no-error: copies edx*4
 *   indirection chain through new slot's +0x6c/+0x74/+0x18, then
 *   OR's bit 3 into [scaled+0]. Writes 0xe666 into [scaled+0x48],
 *   sets &g_dispatchSave567 at +0x10, 0xff at +0x14, then calls
 *   MStackCall_MStackPush2ChainInsert_004065b0. Tail-jmp MStackPop8 on success;
 *   bit-2-set branch also tail-jmps to MStackPop8 directly.
 */
extern unsigned int g_dispatchSave567;
extern unsigned int g_dispatchSave561;
extern void MStackCall_MStackPush2ChainInsert_004065b0(void);
extern void MStackPop8(void);
extern void MStackPush8(void);
extern void MStackPushNegMul10(void);
extern void PushSetXfmMaskCallPop(void);
extern void ScaledTripleCopy54(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MStackPush8SlotInitPop8(void)

{
  int iVar1;
  
  MStackPush8();
  if (g_framePauseFlag == 0) {
    g_cj_00542054 = g_cj_0054205c;
    g_walkCallback = (code *)0x135e2a;
    PushSetXfmMaskCallPop();
    if (g_framePauseFlag == 0) {
      if (((byte)g_xformDirtyFlags & 4) != 0) {
LAB_0041516e:
        g_baseSel = *MK4_NODE(undefined4, (int)g_matrixStackTop);
        g_cj_0054205c = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -1));
        g_cj_00542058 = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -2));
        g_cj_00542054 = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -3));
        g_dualD = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -4));
        g_dualC = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -5));
        g_eventQueuePending = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -6));
        (g_currentNodeIdx) = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -7));
        g_matrixStackTop = g_matrixStackTop + -8;
        return;
      }
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x30) = 0xa1;
      g_walkCallback = *(code **)(g_cj_00542054 * 4 + 0x34);
      *(code **)(g_cj_0054205c * 4 + 0x34) = g_walkCallback;
      ScaledTripleCopy54();
      if (g_framePauseFlag == 0) {
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x68) = MK4_NODE_AT(undefined4, g_cj_00542054, 0x68);
        g_walkCallback = (code *)0xfffffeb9;
        MStackPushNegMul10();
        iVar1 = g_cj_0054205c;
        if (g_framePauseFlag == 0) {
          *(code **)(g_cj_0054205c * 4 + 0x6c) = g_walkCallback;
          MK4_NODE_AT(undefined4, iVar1, 0x74) = g_eventQueueCurrent;
          g_eventQueuePending = MK4_NODE_AT(int, MK4_NODE_AT(int, iVar1, 0x18), 0x28);
          MK4_NODE_AT(uint, g_eventQueuePending, 0) = MK4_NODE_AT(uint, g_eventQueuePending, 0) | 8;
          MK4_NODE_AT(undefined4, g_eventQueuePending, 0x48) = 0xe666;
          MK4_NODE_AT(undefined4, g_eventQueuePending, 0x14) = 0xff;
          g_walkCallback = ClampMulShiftStore;
          *(code **)(g_eventQueuePending * 4 + 0x10) = ClampMulShiftStore;
          (g_currentNodeIdx) = g_cj_0054205c;
          MStackCall_MStackPush2ChainInsert_004065b0();
          if (g_framePauseFlag == 0) goto LAB_0041516e;
        }
      }
    }
  }
  return;
}
#else
__declspec(naked) void MStackPush8SlotInitPop8(void) {
    __asm {
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp8_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, offset g_dispatchSave561
        shr     ecx, 2
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [g_walkCallback], ecx
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp8_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_mp8_tailJmp
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0xa1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x30], eax
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [eax*4 + 0x34]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        call    ScaledTripleCopy54
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp8_ret
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x68]
        mov     dword ptr [ecx*4 + 0x68], eax
        mov     dword ptr [g_walkCallback], 0xfffffeb9
        call    MStackPushNegMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mp8_ret
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x6c], ecx
        lea     eax, [edx*4]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax + 0x74], edx
        mov     eax, dword ptr [eax + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4]
        or      ecx, 8
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [eax*4 + 0x48], 0xe666
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, offset g_dispatchSave567
        mov     dword ptr [ecx*4 + 0x14], 0xff
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x10], eax
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackCall_MStackPush2ChainInsert_004065b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mp8_ret
    L_mp8_tailJmp:
        jmp     MStackPop8
    L_mp8_ret:
        ret
    }
}
#endif
