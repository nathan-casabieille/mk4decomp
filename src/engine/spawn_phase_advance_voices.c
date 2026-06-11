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
extern unsigned int g_phaseThunkVar4;
extern unsigned int g_dispatchVar7;
extern unsigned int g_imageBaseHi;
extern void MStackPush2ChainLLInsert(void);
extern void MStackPushTableMatch(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void SpawnPhaseAdvanceVoices(void)

{
  int iVar1;
  undefined *puVar2;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = g_walkCallback;
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = g_eventQueueCurrent;
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = (g_currentNodeIdx);
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = g_eventQueuePending;
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = g_dualC;
  g_eventQueuePending = MK4_NODE_AT(int, g_dispatchVar7, 0);
  g_dualC = g_eventQueueSeed;
  puVar2 = g_matrixStackTop;
  (g_currentNodeIdx) = g_dispatchVar7;
  do {
    if (g_eventQueuePending == 0) {
      g_eventQueueCurrent = *MK4_NODE(undefined4, (int)(puVar2 + -3));
      g_walkCallback = *MK4_NODE(undefined4, (int)(puVar2 + -4));
      g_dualC = *MK4_NODE(undefined4, (int)puVar2);
      g_eventQueuePending = *MK4_NODE(undefined4, (int)(puVar2 + -1));
      (g_currentNodeIdx) = *MK4_NODE(undefined4, (int)(puVar2 + -2));
      g_matrixStackTop = puVar2 + -5;
      return;
    }
    (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
    iVar1 = MK4_NODE_AT(int, g_eventQueuePending, 0x5c);
    g_eventQueueCurrent = iVar1 + 0xa0000;
    if (g_eventQueueCurrent <= MK4_NODE_AT(int, g_dualC, 0x5c)) {
      if (g_phaseThunkVar4 == 0) {
        *(undefined **)(g_eventQueuePending * 4 + 0x5c) = &(*(unsigned int *)MK4_VA(unsigned int, 0x640000)) + iVar1;
        puVar2 = g_matrixStackTop;
      }
      else {
        g_matrixStackTop = puVar2 + 1;
        g_walkCallback = g_phaseThunkVar4;
        *MK4_NODE(int, (int)g_matrixStackTop) = (g_currentNodeIdx);
        (g_currentNodeIdx) = g_eventQueuePending;
        MStackPushTableMatch();
        if (g_framePauseFlag != 0) {
          return;
        }
        MStackPush2ChainLLInsert();
        if (g_framePauseFlag != 0) {
          return;
        }
        (g_currentNodeIdx) = *MK4_NODE(int, (int)g_matrixStackTop);
        puVar2 = g_matrixStackTop + -1;
        g_matrixStackTop = puVar2;
      }
    }
    g_eventQueuePending = *MK4_NODE(int, (g_currentNodeIdx));
  } while( true );
}
#else
__declspec(naked) void SpawnPhaseAdvanceVoices(void)
{
    __asm {
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_walkCallback]
        inc      eax
        push     ebx
        mov      dword ptr [g_matrixStackTop], eax
        push     esi
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueCurrent]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        push     edi
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
        mov      ecx, dword ptr [g_pendingNodeType]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_eventQueueSeed]
        mov      eax, dword ptr [g_dispatchVar7]
        mov      esi, dword ptr [g_matrixStackTop]
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4]
        lea      edx, [eax + 1]
        test     ecx, ecx
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_currentNodeIdx], edx
        je       short L_e40c
    L_e345:
        mov      eax, dword ptr [ecx*4 + 0x5c]
        mov      edi, dword ptr [g_pendingNodeType]
        add      eax, 0xa0000
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      ebx, dword ptr [edi*4 + 0x5c]
        cmp      eax, ebx
        jg       short L_e3f0
        mov      edi, dword ptr [g_phaseThunkVar4]
        test     edi, edi
        mov      dword ptr [g_walkCallback], edi
        jne      short L_e39a
        add      eax, OFFSET g_imageBaseHi
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      esi, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_currentNodeIdx]
        jmp      short L_e3f0
    L_e39a:
        inc      esi
        mov      dword ptr [g_matrixStackTop], esi
        mov      dword ptr [esi*4], edx
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackPushTableMatch
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_e46f
        call     MStackPush2ChainLLInsert
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_e46f
        mov      esi, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [esi*4]
        dec      esi
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_matrixStackTop], esi
    L_e3f0:
        mov      ecx, dword ptr [edx*4]
        inc      edx
        test     ecx, ecx
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_currentNodeIdx], edx
        jne      short L_e345
    L_e40c:
        mov      ecx, dword ptr [esi*4]
        dec      esi
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_matrixStackTop], esi
        mov      edx, dword ptr [esi*4]
        dec      esi
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_matrixStackTop], esi
        mov      eax, dword ptr [esi*4]
        dec      esi
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_matrixStackTop], esi
        mov      ecx, dword ptr [esi*4]
        dec      esi
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_matrixStackTop], esi
        mov      edx, dword ptr [esi*4]
        dec      esi
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_matrixStackTop], esi
    L_e46f:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
#endif
