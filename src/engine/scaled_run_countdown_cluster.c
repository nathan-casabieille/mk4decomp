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

extern unsigned int g_dispatchSave684;
extern void ArgSarStoreJmp(void);
extern void DirtyDoubleDeref(void);
extern void DualScaledLoadStoreJmp(void);
extern void DualSlotCopyChain(void);
extern void GuardedScaled_TestP1ReplaceCurrent_then_LinkedListSearch_00475090(void);
extern void GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7d(void);
extern void GuardedSeq_DirtyDoubleDeref_then_ScaledOr4Jmp(void);
extern void GuardedSeq_DirtyDoubleDeref_then_ChainSlotSetupInstallSelf(void);
extern void GuardedTripleSetTailJmp8(void);
extern void IntroInitCluster(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void PendingMatch_0044a7f0(void);
extern void PushPopScaled1cDoubleCall(void);
extern void StoreLoadJmp(void);
extern void Thunk_ScaledNeg1SetPause(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void ScaledRunCountdownCluster(void)

{
  g_cj_0054205c = MK4_NODE_AT(undefined4, g_baseSel, 0x4c);
  MStackPush2RunCountdown();
  if (g_framePauseFlag == 0) {
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag == 0) {
      g_walkCallback = 3;
      g_chainAccumCur = 4;
      DualSetShiftCall();
      if (g_framePauseFlag == 0) {
        DoubleStackPushAndJmp7d();
        return;
      }
      return;
    }
  }
  return;
}
#else
__declspec(naked) void ScaledRunCountdownCluster(void)
{
    __asm {
    L_a090:
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x4c]
        mov      dword ptr [g_fightGroupHead], ecx
        call     MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a0d7
        call     MStackBracket7_DispatchAndChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a0d7
        mov      dword ptr [g_walkCallback], 3
        mov      dword ptr [g_chainAccumCur], 4
        jmp      GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7d
    L_a0d7:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_walkCallback], 6
        mov      dword ptr [g_fightGroupHead], ecx
        call     GuardedSeq_DirtyDoubleDeref_then_ScaledOr4Jmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        mov      dword ptr [g_walkCallback], 6
        call     DirtyDoubleDeref
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_xformEntityIdx], edx
        call     IntroInitCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        call     PushPopScaled1cDoubleCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        call     PendingMatch_0044a7f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x58]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x5c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueEnd]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueEnd], eax
        call     DualSlotCopyChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      dword ptr [g_matrixStackTop], eax
        call     MStackCall_MStackPush2ChainPrepend_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a274
        mov      eax, dword ptr [g_baseSel]
        push     OFFSET L_a290
        mov      edx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_eventQueueEnd], edx
        mov      eax, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_eventQueueIdx], eax
        call     StoreLoadJmp
        add      esp, 4
        push     OFFSET g_dispatchSave684
        call     ArgSarStoreJmp
        add      esp, 4
    L_a274:
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
        jmp      Thunk_ScaledNeg1SetPause
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
    L_a290:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_a45f
        dec      eax
        je       L_a3df
        dec      eax
        mov      eax, dword ptr [g_eventQueueIdx]
        je       L_a329
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        jns      L_a38f
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [ecx*4 + 0x64]
        mov      dword ptr [g_walkCallback], 8
        mov      dword ptr [g_fightGroupHead], edx
        call     GuardedSeq_DirtyDoubleDeref_then_ChainSlotSetupInstallSelf
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        mov      dword ptr [g_walkCallback], 6
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        call     DualScaledLoadStoreJmp
        call     Thunk_ScaledNeg1SetPause
        pop      esi
        ret      
    L_a329:
        dec      eax
        mov      dword ptr [g_eventQueueIdx], eax
        jns      L_a4a0
        call     GuardedScaled_TestP1ReplaceCurrent_then_LinkedListSearch_00475090
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        mov      cl, byte ptr [g_xformDirtyFlags]
        mov      eax, 4
        test     cl, al
        jne      L_a385
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [ecx*4 + 0x4c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_fightGroupHead], edx
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        call     DualScaledLoadStoreJmp
    L_a385:
        mov      dword ptr [g_eventQueueIdx], 0x29
    L_a38f:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     GuardedTripleSetTailJmp8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [esi + 8], OFFSET L_a290
        mov      eax, 3
        jmp      L_a448
    L_a3df:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     GuardedScaled_TestP1ReplaceCurrent_then_LinkedListSearch_00475090
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_a424
        call     L_a090
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
    L_a424:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [esi + 8], OFFSET L_a290
        mov      eax, 2
    L_a448:
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_a45f:
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [ecx*4 + 0x4c], edx
        mov      dword ptr [g_eventQueueIdx], 0x29
    L_a4a0:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     GuardedTripleSetTailJmp8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a4fa
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, 1
        mov      dword ptr [g_eventQueueIdx], edx
        mov      dword ptr [esi + 8], OFFSET L_a290
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_a4fa:
        pop      esi
        ret      
    }
}
#endif
