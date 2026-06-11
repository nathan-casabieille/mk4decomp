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

extern unsigned int g_audioVoiceTrioBase;
extern unsigned int g_dispatchSave134;
extern unsigned int g_dispatchArg;
extern unsigned int g_particleEmitterNode;
extern unsigned int g_state2_00537ea8;
extern unsigned int g_state2_00541d88;
extern void CallSetPause(void);
extern void GameStateTick(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void MStackPush3LinkedListWalk(void);
extern void MStackPush4LLWalkPop4(void);
extern void RoundWinTransition(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void ThrowAnimTriggerCluster(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_eventQueuePending;
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_cj_0054205c;
  g_eventQueuePending = 0x14302f;
  DispatcherComplex260_MStackBracket1_TreeWalkRecursive2();
  if (g_framePauseFlag != 0) {
    return;
  }
  if (((byte)g_xformDirtyFlags & 4) == 0) {
    MStackBracket4_ListInsertZeroFill();
    if (g_framePauseFlag != 0) {
      return;
    }
    MStackPush3LinkedListWalk();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_eventQueuePending = 0x14283c;
    MStackPush4LLWalkPop4();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_walkCallback = 0;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) = 0;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x58) = g_walkCallback;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) = g_walkCallback;
    g_walkCallback = 6;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x30) = 6;
    MStackCall_MStackPush2ChainPrepend_00406340();
    if (g_framePauseFlag != 0) {
      return;
    }
    g_eventQueueCurrent = 0x10000;
    MK4_NODE_AT(uint, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x34) = MK4_NODE_AT(uint, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x34) | 0x10000;
    g_dualC = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_particleEmitterNode;
    MK4_NODE_AT(undefined4, g_particleEmitterNode, 0x54) = 0x10000;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x58) = 0;
    g_walkCallback = 0xffff8000;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) = 0xffff8000;
    MK4_NODE_AT(int, g_dualC, 0x3c) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    RoundWinTransition();
    if (g_framePauseFlag != 0) {
      return;
    }
  }
  g_cj_0054205c = *MK4_NODE(undefined4, (int)g_matrixStackTop);
  g_eventQueuePending = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -1));
  (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -2));
  g_matrixStackTop = g_matrixStackTop + -3;
  return;
}
#else
__declspec(naked) void ThrowAnimTriggerCluster(void)
{
    __asm {
        /* === Helper 1 (0x49efa0): throw setup with mstack save === */
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
        mov      ecx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      edx, OFFSET g_dispatchSave134
        mov      dword ptr [g_matrixStackTop], eax
        shr      edx, 2
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_MStackBracket1_TreeWalkRecursive2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_f183
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_f145
        call     MStackBracket4_ListInsertZeroFill
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_f183
        call     MStackPush3LinkedListWalk
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_f183
        mov      eax, OFFSET g_audioVoiceTrioBase
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        call     MStackPush4LLWalkPop4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f183
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [ecx*4 + 0x54], 0
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x58], edx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_walkCallback]
        mov      eax, 6
        mov      dword ptr [edx*4 + 0x5c], ecx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        call     MStackCall_MStackPush2ChainPrepend_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f183
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, 0x10000
        mov      eax, dword ptr [ecx*4 + 0x34]
        mov      dword ptr [g_eventQueueCurrent], edx
        or       eax, edx
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_pendingNodeType], eax
        mov      eax, dword ptr [g_particleEmitterNode]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4 + 0x54], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xffff8000
        mov      dword ptr [ecx*4 + 0x58], 0
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x5c], eax
        mov      ecx, dword ptr [g_pendingNodeType]
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x3c], eax
        call     RoundWinTransition
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f183
    L_f145:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
    L_f183:
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
        nop
        /* === Helper 2: flag-gated 535e48=0 trampoline === */
        mov      eax, dword ptr [g_state2_00541d88]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_f1a3
        jmp      CallSetPause
    L_f1a3:
        mov      dword ptr [g_dispatchArg], 0
        jmp      GameStateTick
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
        nop
        nop
        nop
        /* === Helper 3: flag-gated 535e48=1 trampoline === */
        mov      eax, dword ptr [g_state2_00537ea8]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_f1d3
        jmp      CallSetPause
    L_f1d3:
        mov      dword ptr [g_dispatchArg], 1
        jmp      GameStateTick
    }
}
#endif
