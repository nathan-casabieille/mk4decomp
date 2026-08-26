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

/* @addr 0x00425a80 (155b game) - 3-element clamp loop:
 *   neg = -g_walkCallback; for i in {0,1,2}:
 *     v = arr_src[g_xformEntityIdx++];
 *     if (v < 0): if (v < neg) v = neg; else: if (v > g_walkCallback) v = walkCallback;
 *     arr_dst[g_scaledInit++] = v.
 *   Then: g_xformLoopCounter = 2 (the iter sentinel), rollback g_scaledInit/g_xformEntityIdx by 3.
 */

extern unsigned int g_arr_425a80_dst;
extern unsigned int g_arr_425a80_src;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void ThreeClampLoop(void)

{
  int iVar1;
  int iVar2;
  
  g_xformLoopCounter = 2;
  g_eventQueueCurrent = -g_walkCallback;
  iVar2 = 3;
  iVar1 = (g_currentNodeIdx);
  do {
    (g_currentNodeIdx) = iVar1;
    g_eventQueueWorkType = MK4_NODE_AT(int, g_eventQueuePending, 0);
    g_eventQueuePending = g_eventQueuePending + 1;
    if ((int)g_eventQueueWorkType < 0) {
      iVar1 = g_eventQueueCurrent;
      if (g_eventQueueWorkType < g_eventQueueCurrent) {
LAB_00425ad6:
        g_eventQueueWorkType = iVar1;
      }
    }
    else {
      iVar1 = g_walkCallback;
      if (g_walkCallback < g_eventQueueWorkType) goto LAB_00425ad6;
    }
    *MK4_NODE(int, (g_currentNodeIdx)) = g_eventQueueWorkType;
    g_xformLoopCounter = g_xformLoopCounter + -1;
    iVar2 = iVar2 + -1;
    iVar1 = (g_currentNodeIdx) + 1;
    if (iVar2 == 0) {
      (g_currentNodeIdx) = (g_currentNodeIdx) + -2;
      g_eventQueuePending = g_eventQueuePending + -3;
      return;
    }
  } while( true );
}
#else
__declspec(naked) void ThreeClampLoop(void) {
    __asm {
        push    ebx
        push    esi
        mov     esi, dword ptr [g_walkCallback]
        push    edi
        mov     edx, esi
        mov     edi, 2
        neg     edx
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     ebx, 3
        _emit   0ebh
        _emit   0ch
loop425a80:
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     esi, dword ptr [g_walkCallback]
afterReload:
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, [ecx*4 + g_arr_425a80_src]
        inc     ecx
        test    eax, eax
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        _emit   7dh
        _emit   08h
        cmp     eax, edx
        _emit   7dh
        _emit   0fh
        mov     eax, edx
        _emit   0ebh
        _emit   06h
        cmp     eax, esi
        _emit   7eh
        _emit   07h
        mov     eax, esi
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     [ecx*4 + g_arr_425a80_dst], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        inc     edx
        dec     edi
        dec     ebx
        mov     dword ptr [g_currentNodeIdx], edx
        _emit   75h
        _emit   0a6h
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, edx
        mov     dword ptr [g_xformLoopCounter], edi
        sub     ecx, 3
        sub     eax, 3
        pop     edi
        pop     esi
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_xformEntityIdx], eax
        pop     ebx
        ret
    }
}
#endif
