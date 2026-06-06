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

/* @addr 0x00457830 (164b game) - search-with-counter through scaled array, find slot by value, return chain[+8].
 *   Save g_eventQueueCurrent to [esp+0xc]. ebp = g_pendingNodeType (offset).
 *   eax = chain[ebp]; edx = &chain[ebp]; ecx=0; edi=0; esi=0.
 *   if (chain[ebp] == 0) skip-loop.
 *   else: ebx = g_walkCallback (target value).
 *     loop_outer: ecx = chain[edx+4]; edx += 4; esi++.
 *       if (ebx < eax || ebx > ecx) { edx += 4; ecx -= eax; esi++; eax = [edx];
 *         edi += ecx + 1; g_eventQueueCurrent = eax;
 *         if (eax != 0): loop_outer.
 *         else: ecx=0; edi=0; jmp skip-loop.
 *       } else: ebx -= eax; edi += ebx; ecx=0; esi++; fall to skip-loop.
 *   skip-loop: edx = esi + ebp; g_chainAccumCur = ecx;
 *     while (chain[edx] != ecx): esi++; edx = esi + ebp;
 *     esi += edi + ebp; g_xformEntityIdx = chain[esi*4 + 8];
 *     restore: g_eventQueueCurrent = saved; g_scaledInit = [g_scaledInit] (no-op).
 */

extern unsigned int g_matrixStack_arr;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void ScaledSearchSum(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = MK4_NODE_AT(int, g_dualC, 0);
  piVar3 = (int *)(g_dualC * 4);
  iVar6 = 0;
  iVar4 = 0;
  while( true ) {
    if (iVar2 == 0) {
      iVar6 = 0;
      for (iVar5 = iVar4; g_chainAccumCur = 0, *(int *)((iVar5 + g_dualC) * 4) != 0;
          iVar5 = iVar5 + 1) {
LAB_00457897:
      }
      g_eventQueuePending = *(undefined4 *)((iVar5 + iVar6 + g_dualC) * 4 + 8);
      return;
    }
    piVar1 = piVar3 + 1;
    iVar5 = iVar4 + 1;
    if ((iVar2 <= g_walkCallback) && (g_walkCallback <= *piVar1)) break;
    piVar3 = piVar3 + 2;
    iVar5 = *piVar1 - iVar2;
    iVar4 = iVar4 + 2;
    iVar2 = *piVar3;
    iVar6 = iVar6 + 1 + iVar5;
  }
  iVar6 = iVar6 + (g_walkCallback - iVar2);
  goto LAB_00457897;
}
#else
__declspec(naked) void ScaledSearchSum(void) {
    __asm {
        push    ecx
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    ebx
        push    ebp
        mov     ebp, dword ptr [g_pendingNodeType]
        push    esi
        mov     [esp + 0x0c], eax
        mov     eax, [ebp*4 + g_matrixStack_arr]
        lea     edx, [ebp*4 + g_matrixStack_arr]
        push    edi
        xor     ecx, ecx
        xor     edi, edi
        xor     esi, esi
        cmp     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   74h
        _emit   2ch
        mov     ebx, dword ptr [g_walkCallback]
        mov     ecx, [edx + 4]
        add     edx, 4
        inc     esi
        cmp     ebx, eax
        _emit   7ch
        _emit   04h
        cmp     ebx, ecx
        _emit   7eh
        _emit   1bh
        add     edx, 4
        sub     ecx, eax
        inc     esi
        mov     eax, [edx]
        lea     edi, [edi + ecx + 1]
        test    eax, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   75h
        _emit   0dch
        xor     ecx, ecx
        xor     edi, edi
        _emit   0ebh
        _emit   07h
        sub     ebx, eax
        add     edi, ebx
        xor     ecx, ecx
        inc     esi
        lea     edx, [esi + ebp]
        mov     dword ptr [g_chainAccumCur], ecx
        cmp     [edx*4 + g_matrixStack_arr], ecx
        _emit   75h
        _emit   0edh
        add     esi, edi
        mov     ecx, [esp + 0x10]
        add     esi, ebp
        pop     edi
        mov     eax, [esi*4 + 8]
        pop     esi
        mov     dword ptr [g_xformEntityIdx], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        pop     ebp
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        pop     ebx
        pop     ecx
        ret
    }
}
#endif
