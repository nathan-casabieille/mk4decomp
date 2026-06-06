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

extern unsigned int g_orphanConst_0049db40;
extern unsigned int g_dispatchSave986;
extern unsigned int g_dispatchSave987;
extern unsigned int g_dispatchSave988;
extern void StoreDoubleNegPauseSubStore(void);
extern void ZeroAndDirty4(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void SpawnImpactExplosion(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_eventQueueNotMask;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_cj_00542058;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
  g_cj_00542054 = g_cj_0054205c;
  g_cj_00542058 = 0x13b088;
  g_walkCallback = 0xc000;
  ZeroAndDirty4();
  if (g_framePauseFlag != 0) {
    return;
  }
  if (((byte)g_xformDirtyFlags & 4) == 0) {
    g_walkCallback = 0xd999;
    g_cj_00542058 = 0x13b09c;
    ZeroAndDirty4();
    if (g_framePauseFlag != 0) {
      return;
    }
    if (((byte)g_xformDirtyFlags & 4) == 0) {
      g_cj_00542058 = 0x13b0b0;
    }
  }
  g_eventQueueNotMask = 0xc1;
  StoreTwoCall(&g_orphanConst_0049db40,0xc0);
  if (((byte)g_xformDirtyFlags & 1) == 0) {
    g_eventQueueCurrent = 0;
    g_walkCallback = 0xc28f;
    StoreDoubleNegPauseSubStore();
    if (g_framePauseFlag != 0) {
      return;
    }
    *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x38) = g_eventQueueCurrent + g_walkCallback;
    g_eventQueueCurrent = -0x20000;
    g_walkCallback = 0xdc28;
    StoreDoubleNegPauseSubStore();
    if (g_framePauseFlag != 0) {
      return;
    }
    *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x3c) = g_eventQueueCurrent + g_walkCallback;
    g_eventQueueCurrent = 0xc4000;
    g_walkCallback = 0x5c28;
    StoreDoubleNegPauseSubStore();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_eventQueueCurrent = g_eventQueueCurrent + g_walkCallback;
    *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x40) = g_eventQueueCurrent;
    *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x44) = 0;
    *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x48) = 0;
    g_walkCallback = 0;
    *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x4c) = 0;
  }
  g_eventQueueNotMask = *(undefined4 *)((int)(g_matrixStackTop + -2) * 4);
  g_cj_00542058 = *(undefined4 *)((int)(g_matrixStackTop + -1) * 4);
  (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(undefined4 *)((int)g_matrixStackTop * 4);
  g_matrixStackTop = g_matrixStackTop + -3;
  return;
}
#else
__declspec(naked) void SpawnImpactExplosion(void)
{
    __asm {
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        inc      eax
        push     esi
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, OFFSET g_dispatchSave986
        mov      dword ptr [g_eventQueueEnd], edx
        shr      eax, 2
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [g_walkCallback], 0xc000
        call     ZeroAndDirty4
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      L_1dfa
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_1ca9
        mov      ecx, OFFSET g_dispatchSave987
        mov      dword ptr [g_walkCallback], 0xd999
        shr      ecx, 2
        mov      dword ptr [g_eventQueueIdx], ecx
        call     ZeroAndDirty4
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1dfa
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_1ca9
        mov      edx, OFFSET g_dispatchSave988
        shr      edx, 2
        mov      dword ptr [g_eventQueueIdx], edx
    L_1ca9:
        push     0xc0
        push     OFFSET g_orphanConst_0049db40
        mov      dword ptr [g_eventQueueNotMask], 0xc1
        call     StoreTwoCall
        mov      al, byte ptr [g_xformDirtyFlags]
        add      esp, 8
        test     al, 1
        jne      L_1dbc
        mov      dword ptr [g_eventQueueCurrent], esi
        mov      dword ptr [g_walkCallback], 0xc28f
        call     StoreDoubleNegPauseSubStore
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_1dfa
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      edx, dword ptr [g_currentNodeIdx]
        add      ecx, eax
        mov      dword ptr [edx*4 + 0x38], ecx
        mov      dword ptr [g_eventQueueCurrent], 0xfffe0000
        mov      dword ptr [g_walkCallback], 0xdc28
        call     StoreDoubleNegPauseSubStore
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_1dfa
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      edx, dword ptr [g_currentNodeIdx]
        add      ecx, eax
        mov      dword ptr [edx*4 + 0x3c], ecx
        mov      dword ptr [g_eventQueueCurrent], 0xc4000
        mov      dword ptr [g_walkCallback], 0x5c28
        call     StoreDoubleNegPauseSubStore
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_1dfa
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      ecx, dword ptr [g_walkCallback]
        add      eax, ecx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x44], esi
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x48], esi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [ecx*4 + 0x4c], esi
    L_1dbc:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueNotMask], edx
        mov      dword ptr [g_matrixStackTop], eax
    L_1dfa:
        pop      esi
        ret
    }
}
#endif
