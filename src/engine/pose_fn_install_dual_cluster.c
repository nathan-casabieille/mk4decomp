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
extern void CallSetPause(void);
extern void MStackChainCountdownLoop(void);
extern void PendingMatch_ThreeMul10Stores(void);
extern void FixedDiv16(void);
extern void SaveCallRestoreOrXor(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PoseFnInstallDualCluster(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_baseSel * 4;
  iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
  *(undefined4 *)(iVar1 + 0x84) = 0;
  if (iVar2 != 0) {
    StackPopDispatchTagged();
    return;
  }
  MK4_NODE_AT(undefined4, g_baseSel, 0x30) = g_cj_00542058;
  g_walkCallback = g_cj_00542054;
  MStackChainCountdownLoop();
  if (g_framePauseFlag == 0) {
    MK4_NODE_AT(undefined4, g_baseSel, 0x34) = g_eventQueueCurrent;
    g_walkCallback = 27000;
    g_eventQueueCurrent = 0x20000;
    FixedDiv16();
    if (g_framePauseFlag == 0) {
      g_eventQueueWorkType = g_eventQueueWorkType - g_walkCallback;
      MK4_NODE_AT(int, g_baseSel, 0x38) = g_eventQueueWorkType;
      g_walkCallback = 0;
      MStackChainCountdownLoop();
      if (g_framePauseFlag == 0) {
        g_chainAccumCur = g_chainAccumCur + -0x20000;
        MK4_NODE_AT(int, g_baseSel, 0x3c) = g_chainAccumCur;
        g_cj_0054205c = g_eventQueueSeed;
        MK4_NODE_AT(undefined4, g_baseSel, 0x40) = MK4_NODE_AT(undefined4, g_eventQueueSeed, 0x60);
        MK4_NODE_AT(undefined4, g_baseSel, 0x44) = 0;
        g_walkCallback = MK4_NODE_AT(int, g_cj_0054205c, 0x68);
        MK4_NODE_AT(int, g_baseSel, 0x48) = g_walkCallback;
        *(code **)(iVar1 + 8) = PoseFnInstallDualCluster;
        MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 1;
        (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)(iVar1 + 4);
        *MK4_NODE(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044))) = 0x1463090;
        (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) + 1;
        *(int *)(iVar1 + 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
        MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
        PendingMatch_ThreeMul10Stores();
        g_framePauseFlag = 1;
      }
    }
  }
  return;
}
#else
__declspec(naked) void PoseFnInstallDualCluster(void)
{
    __asm {
        /* === h1 (0x463090): pose-fn 1-state install w/ 463fb0 + 432110 === */
    L_3090:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        je       short L_30b9
        call     StackPopDispatchTagged
        pop      edi
        pop      esi
        ret
    L_30b9:
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [ecx*4 + 0x30], edx
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_walkCallback], eax
        call     MStackChainCountdownLoop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_321c
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [edx*4 + 0x34], ecx
        mov      dword ptr [g_walkCallback], 0x6978
        mov      dword ptr [g_eventQueueCurrent], 0x20000
        call     FixedDiv16
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_321c
        mov      eax, dword ptr [g_eventQueueWorkType]
        mov      ecx, dword ptr [g_walkCallback]
        sub      eax, ecx
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [ecx*4 + 0x38], eax
        mov      dword ptr [g_walkCallback], edi
        call     MStackChainCountdownLoop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_321c
        mov      eax, dword ptr [g_chainAccumCur]
        mov      edx, dword ptr [g_baseSel]
        sub      eax, 0x20000
        mov      dword ptr [g_chainAccumCur], eax
        mov      dword ptr [edx*4 + 0x3c], eax
        mov      eax, dword ptr [g_eventQueueSeed]
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_fightGroupHead], eax
        mov      eax, dword ptr [eax*4 + 0x60]
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [edx*4 + 0x44], edi
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x48], eax
        mov      dword ptr [esi + 8], OFFSET L_3090
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_3090
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     PendingMatch_ThreeMul10Stores
        mov      dword ptr [g_framePauseFlag], 1
    L_321c:
        pop      edi
        pop      esi
        ret
        nop
        /* === h2 (0x463220): pose-fn 1-state install w/ bit-4 abort === */
    L_3220:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        jne      short L_326a
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueIdx]
        push     0x26d
        mov      dword ptr [ecx*4 + 0x30], edx
        call     SaveCallRestoreOrXor
        mov      al, byte ptr [g_xformDirtyFlags]
        add      esp, 4
        test     al, 4
        je       short L_3272
    L_326a:
        call     CallSetPause
        pop      edi
        pop      esi
        ret
    L_3272:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_fightGroupHead], eax
        mov      dword ptr [g_walkCallback], ecx
        call     MStackChainCountdownLoop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3388
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      edx, dword ptr [g_baseSel]
        sub      eax, 0x3d70
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [edx*4 + 0x34], eax
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [eax*4 + 0x38], ecx
        mov      eax, dword ptr [g_chainAccumCur]
        mov      edx, dword ptr [g_baseSel]
        sub      eax, 0x51e
        mov      dword ptr [g_chainAccumCur], eax
        mov      dword ptr [edx*4 + 0x3c], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x60]
        mov      dword ptr [edx*4 + 0x40], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [eax*4 + 0x44], edi
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [ecx*4 + 0x68]
        mov      ecx, OFFSET L_3220
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x48], eax
        mov      dword ptr [esi + 8], OFFSET L_3220
        mov      eax, dword ptr [g_baseSel]
        add      ecx, 0x1000000
        mov      dword ptr [eax*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     PendingMatch_ThreeMul10Stores
        mov      dword ptr [g_framePauseFlag], 1
    L_3388:
        pop      edi
        pop      esi
        ret
    }
}
#endif
