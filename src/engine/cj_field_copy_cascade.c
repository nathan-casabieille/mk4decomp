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

/* @addr 0x0044c430 (241b game) - 4-field copy from scaledInit chain to chain via cj alias.
 *   Set cj = baseSel[+0x4c]; call MStackPush2RunCountdown; if pause? ret.
 *   g_walkCallback=2; call BootStateTriple; if pause? ret.
 *   Then for k in {0, 0x30, 0x34, 0x38}: copy scaledInit[k] to g_xformEntityIdx[k]
 *     (first iteration also OR's al with 4).
 *   Then call MStackBracket7_DispatchAndChain; if !pause: g_walkCallback=3, g_chainAccumCur=2, tail-jmp GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7b; ret.
 */
extern void BootStateTriple(void);
extern void GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7b(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void CjFieldCopyCascade(void)

{
  g_cj_0054205c = MK4_NODE_AT(int, g_baseSel, 0x4c);
  MStackPush2RunCountdown();
  if (g_framePauseFlag == 0) {
    g_walkCallback = 2;
    BootStateTriple();
    if (g_framePauseFlag == 0) {
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4);
      MK4_NODE_AT(uint, g_eventQueuePending, 0) = MK4_NODE_AT(uint, g_eventQueuePending, 0) | 4;
      MK4_NODE_AT(undefined4, g_eventQueuePending, 0x30) = *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x30);
      MK4_NODE_AT(undefined4, g_eventQueuePending, 0x34) = *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x34);
      g_walkCallback = *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x38);
      MK4_NODE_AT(int, g_eventQueuePending, 0x38) = g_walkCallback;
      MStackBracket7_DispatchAndChain();
      if (g_framePauseFlag == 0) {
        g_walkCallback = 3;
        g_chainAccumCur = 2;
        DualSetShiftCall();
        if (g_framePauseFlag == 0) {
          g_matrixStackTop = g_matrixStackTop + 1;
          *(int *)((int)g_matrixStackTop * 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
          g_matrixStackTop = g_matrixStackTop + 1;
          *(int *)((int)g_matrixStackTop * 4) = g_cj_0054205c;
          (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = 0x7b;
          PreFightInstallCluster();
          if (g_framePauseFlag == 0) {
            if (((byte)g_xformDirtyFlags & 4) == 0) {
              MK4_NODE_AT(int, g_cj_0054205c, 0x6c) = MK4_NODE_AT(int, g_cj_0054205c, 0x6c) >> 1;
              MK4_NODE_AT(int, g_cj_0054205c, 0x70) = MK4_NODE_AT(int, g_cj_0054205c, 0x70) >> 1;
              g_walkCallback = MK4_NODE_AT(int, g_cj_0054205c, 0x74) >> 1;
              MK4_NODE_AT(int, g_cj_0054205c, 0x74) = g_walkCallback;
            }
            g_cj_0054205c = *(int *)((int)g_matrixStackTop * 4);
            (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(undefined4 *)((int)(g_matrixStackTop + -1) * 4);
            g_matrixStackTop = g_matrixStackTop + -2;
          }
          return;
        }
        return;
      }
    }
  }
  return;
}
#else
__declspec(naked) void CjFieldCopyCascade(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, dword ptr [eax*4 + 0x4c]
        mov     dword ptr [g_cj_0054205c], ecx
        call    MStackPush2RunCountdown
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0cch
        _emit   00h
        _emit   00h
        _emit   00h
        mov     dword ptr [g_walkCallback], 2
        call    BootStateTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0b0h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [edx*4 + 0]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [ecx*4 + 0]
        or      al, 4
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0], eax
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x30]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x30], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [eax*4 + 0x34]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [edx*4 + 0x38]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x38], eax
        call    MStackBracket7_DispatchAndChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   19h
        mov     dword ptr [g_walkCallback], 3
        mov     dword ptr [g_chainAccumCur], 2
        jmp     GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7b
        ret
    }
}
#endif
