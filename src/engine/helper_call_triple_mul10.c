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

/* @addr 0x0043e2d0 (259b game) - mstack-push cj, then helper call + 3 Mul10Tail.
 *   mstack-push g_cj_0054205c; g_cj_0054205c = g_currentNodeIdx;
 *   g_eventQueueEnd = baseSel[+0x64]; call SetupVecFsmCluster; if pause? final-ret.
 *   esi = scaledInit*4 base. 3x Mul10Tail for fields +0x78/+0x7c/+0x80 with 0x9999 mod;
 *   then g_xformEntityIdx = g_eventQueueSeed + 0x15; g_eventQueueCurrent = 0x2b85;
 *   g_eventQueueWorkType = 0x20; call MStackDualDiffSequencer; if pause? final-ret.
 *   mstack-pop g_cj_0054205c; ret.
 */
extern unsigned int g_eventQueueSeed;
extern void MStackDualDiffSequencer(void);
extern void SetupVecFsmCluster(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void HelperCallTripleMul10(void)

{
  int iVar1;
  undefined4 uVar2;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_cj_0054205c;
  g_cj_0054205c = g_currentNodeIdx;
  g_cj_00542054 = MK4_NODE_AT(undefined4, g_baseSel, 100);
  SetupVecFsmCluster();
  if (g_framePauseFlag == 0) {
    g_walkCallback = MK4_NODE_AT(undefined4, g_currentNodeIdx, 0x78);
    iVar1 = g_currentNodeIdx * 4;
    uVar2 = Mul10Tail(0x9999,g_walkCallback);
    *(undefined4 *)(iVar1 + 0x78) = uVar2;
    g_walkCallback = *(undefined4 *)(iVar1 + 0x7c);
    uVar2 = Mul10Tail(0x9999,g_walkCallback);
    *(undefined4 *)(iVar1 + 0x7c) = uVar2;
    g_walkCallback = *(undefined4 *)(iVar1 + 0x80);
    g_walkCallback = Mul10Tail(0x9999,g_walkCallback);
    *(undefined4 *)(iVar1 + 0x80) = g_walkCallback;
    g_eventQueuePending = g_eventQueueSeed + 0x15;
    g_eventQueueCurrent = 0x2b85;
    g_eventQueueWorkType = 0x20;
    MStackDualDiffSequencer();
    if (g_framePauseFlag == 0) {
      g_cj_0054205c = *(int *)((int)g_matrixStackTop * 4);
      g_matrixStackTop = g_matrixStackTop + -1;
    }
  }
  return;
}
#else
__declspec(naked) void HelperCallTripleMul10(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_cj_0054205c]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [g_cj_0054205c], edx
        mov     ecx, dword ptr [eax*4 + 0x64]
        mov     dword ptr [g_eventQueueEnd], ecx
        call    SetupVecFsmCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0b8h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x78]
        lea     esi, [edx*4 + 0]
        push    eax
        push    0x9999
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [esi + 0x78], eax
        mov     eax, dword ptr [esi + 0x7c]
        push    eax
        push    0x9999
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [esi + 0x7c], eax
        mov     eax, dword ptr [esi + 0x80]
        push    eax
        push    0x9999
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [esi + 0x80], eax
        mov     eax, dword ptr [g_eventQueueSeed]
        add     esp, 8
        add     eax, 0x15
        mov     dword ptr [g_eventQueueCurrent], 0x2b85
        mov     dword ptr [g_xformEntityIdx], eax
        mov     dword ptr [g_eventQueueWorkType], 0x20
        call    MStackDualDiffSequencer
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   18h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_cj_0054205c], ecx
        mov     dword ptr [g_matrixStackTop], eax
        pop     esi
        ret
    }
}
#endif
