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

extern void MStackSignedMod(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PoseBlendDriver(void)

{
  MStackSignedMod();
  if (g_framePauseFlag == 0) {
    g_matrixStackTop = g_matrixStackTop + 1;
    *MK4_NODE(int, (int)g_matrixStackTop) = g_walkCallback;
    g_eventQueueNotMask = MK4_NODE_AT(undefined4, g_cj_0054205c, 0x54);
    g_eventQueueChild = MK4_NODE_AT(undefined4, g_cj_0054205c, 0x5c);
    g_walkCallback = g_fightAxisPosX;
    g_eventQueueCurrent = g_fightAxisPosY;
    g_walkCallback = Mul10Tail(0x1999,g_fightAxisPosX);
    g_eventQueueCurrent = Mul10Tail(0x1999,g_eventQueueCurrent);
    g_eventQueueWorkType = MK4_NODE_AT(int, g_cj_0054205c, 0x54) + g_walkCallback;
    g_chainAccumCur = MK4_NODE_AT(int, g_cj_0054205c, 0x5c) + g_eventQueueCurrent;
    MK4_NODE_AT(int, g_cj_0054205c, 0x54) = g_eventQueueWorkType;
    MK4_NODE_AT(int, g_cj_0054205c, 0x5c) = g_chainAccumCur;
    MStackSignedMod();
    if (g_framePauseFlag == 0) {
      g_eventQueueCurrent = *MK4_NODE(int, (int)g_matrixStackTop);
      g_matrixStackTop = g_matrixStackTop + -1;
      g_eventQueueWorkType = ((g_eventQueueCurrent < g_walkCallback) - 1 & 0x20000) - 0x10000;
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x54) = g_eventQueueNotMask;
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x5c) = g_eventQueueChild;
      g_chainAccumCur = g_walkCallback + -0x4ccc;
      if (g_chainAccumCur < 0) {
        g_chainAccumCur = -g_chainAccumCur;
      }
      g_chainAccumCur = Mul10Tail(0x44924,g_chainAccumCur);
      if (g_chainAccumCur < 0x7ae) {
        g_chainAccumCur = 0x7ae;
      }
      g_eventQueueNotMask = g_fightAxisPosX;
      g_eventQueueChild = g_fightAxisPosY;
      g_eventQueueNotMask = Mul10Tail(g_chainAccumCur,g_fightAxisPosX);
      g_eventQueueChild = Mul10Tail(g_chainAccumCur,g_eventQueueChild);
      g_eventQueueNotMask = Mul10Tail(g_eventQueueWorkType,g_eventQueueNotMask);
      g_eventQueueChild = Mul10Tail(g_eventQueueWorkType,g_eventQueueChild);
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x6c) = g_eventQueueNotMask;
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x74) = g_eventQueueChild;
    }
  }
  return;
}
#else
__declspec(naked) void PoseBlendDriver(void)
{
    __asm {
        push     esi
        push     edi
        call     MStackSignedMod
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fe9d
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_walkCallback]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_fightAxisPosY]
        mov      edx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_eventQueueNotMask], edx
        mov      eax, dword ptr [eax*4 + 0x5c]
        mov      dword ptr [g_eventQueueChild], eax
        mov      eax, dword ptr [g_fightAxisPosX]
        push     eax
        push     0x1999
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        call     Mul10Tail
        mov      edx, dword ptr [g_eventQueueCurrent]
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        push     edx
        push     0x1999
        call     Mul10Tail
        mov      edx, dword ptr [g_fightGroupHead]
        mov      edi, dword ptr [g_walkCallback]
        mov      dword ptr [g_eventQueueCurrent], eax
        add      esp, 8
        mov      ecx, dword ptr [edx*4 + 0x54]
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      esi, dword ptr [edx*4 + 0x5c]
        add      ecx, edi
        add      esi, eax
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      dword ptr [g_chainAccumCur], esi
        mov      dword ptr [edx*4 + 0x54], ecx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_chainAccumCur]
        mov      dword ptr [eax*4 + 0x5c], ecx
        call     MStackSignedMod
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fe9d
        mov      eax, dword ptr [g_matrixStackTop]
        mov      esi, dword ptr [g_walkCallback]
        xor      edx, edx
        mov      ecx, dword ptr [eax*4]
        dec      eax
        cmp      esi, ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      ecx, dword ptr [g_eventQueueNotMask]
        setg     dl
        dec      edx
        and      edx, 0x20000
        add      edx, 0xffff0000
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_eventQueueChild]
        mov      dword ptr [edx*4 + 0x5c], eax
        mov      ecx, dword ptr [g_walkCallback]
        lea      eax, [ecx - 0x4ccc]
        test     eax, eax
        mov      dword ptr [g_chainAccumCur], eax
        jge      short L_fddf
        neg      eax
        mov      dword ptr [g_chainAccumCur], eax
    L_fddf:
        push     eax
        push     0x44924
        call     Mul10Tail
        add      esp, 8
        cmp      eax, 0x7ae
        mov      dword ptr [g_chainAccumCur], eax
        jge      short L_fe03
        mov      eax, 0x7ae
        mov      dword ptr [g_chainAccumCur], eax
    L_fe03:
        mov      ecx, dword ptr [g_fightAxisPosX]
        mov      edx, dword ptr [g_fightAxisPosY]
        push     ecx
        push     eax
        mov      dword ptr [g_eventQueueNotMask], ecx
        mov      dword ptr [g_eventQueueChild], edx
        call     Mul10Tail
        mov      ecx, dword ptr [g_chainAccumCur]
        add      esp, 8
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      eax, dword ptr [g_eventQueueChild]
        push     eax
        push     ecx
        call     Mul10Tail
        mov      edx, dword ptr [g_eventQueueNotMask]
        add      esp, 8
        mov      dword ptr [g_eventQueueChild], eax
        mov      eax, dword ptr [g_eventQueueWorkType]
        push     edx
        push     eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      edx, dword ptr [g_eventQueueWorkType]
        add      esp, 8
        mov      dword ptr [g_eventQueueNotMask], eax
        push     ecx
        push     edx
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [g_eventQueueChild], eax
        mov      eax, dword ptr [g_fightGroupHead]
        add      esp, 8
        mov      dword ptr [eax*4 + 0x6c], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_eventQueueChild]
        mov      dword ptr [edx*4 + 0x74], eax
    L_fe9d:
        pop      edi
        pop      esi
        ret
    }
}
#endif
