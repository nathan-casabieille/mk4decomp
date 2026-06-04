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

/* @addr 0x0041f9c0 (138b) - linked-list search by (g_walkCallback, g_cj):
 *   curr = chain[g_scaledInit]; while (curr != NULL) {
 *     if (curr[0xd8] != 0 && arr1[curr>>2] == g_walkCallback &&
 *         arr2[curr>>2] == g_cj_0054205c): set bit 0, clear bit 2; return.
 *     curr = curr[0xe4]; }
 *   g_scaledInit = 0; clear bit 0, set bit 2 of g_xformDirtyFlags.
 */

extern unsigned int g_chain_arr_41f9c0;
extern unsigned int g_chain_disp_0c_41f9c0;
extern unsigned int g_chain_disp_2c_41f9c0;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void ChainSearch(void)

{
  int iVar1;
  
  iVar1 = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4;
  do {
    if (iVar1 == 0) {
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = 0;
      g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffe | 4;
      return;
    }
    if (*(int *)(iVar1 + 0xd8) != 0) {
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = iVar1 >> 2;
      g_eventQueueWorkType = *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0xc);
      if ((g_eventQueueWorkType == g_walkCallback) && (*(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x2c) == g_cj_0054205c))
      {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffb | 1;
        return;
      }
    }
    iVar1 = *(int *)(iVar1 + 0xe4);
  } while( true );
}
#else
__declspec(naked) void ChainSearch(void) {
    __asm {
        mov     eax, dword ptr [g_currentNodeIdx]
        push    esi
        push    edi
        lea     ecx, [eax*4 + g_chain_arr_41f9c0]
        test    ecx, ecx
        _emit   74h
        _emit   44h
        mov     esi, dword ptr [g_walkCallback]
        mov     edi, dword ptr [g_cj_0054205c]
loop41f9c0:
        mov     eax, dword ptr [ecx + 0xd8]
        test    eax, eax
        _emit   74h
        _emit   24h
        mov     eax, ecx
        sar     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     edx, [eax*4 + g_chain_disp_0c_41f9c0]
        cmp     edx, esi
        mov     dword ptr [g_eventQueueWorkType], edx
        _emit   75h
        _emit   09h
        cmp     [eax*4 + g_chain_disp_2c_41f9c0], edi
        _emit   74h
        _emit   29h
        mov     ecx, dword ptr [ecx + 0xe4]
        test    ecx, ecx
        _emit   75h
        _emit   0c8h
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_currentNodeIdx], 0
        and     edx, 0xfffffffe
        or      edx, 4
        mov     dword ptr [g_xformDirtyFlags], edx
        pop     edi
        pop     esi
        ret
        mov     ecx, dword ptr [g_xformDirtyFlags]
        pop     edi
        and     ecx, 0xfffffffb
        pop     esi
        or      ecx, 1
        mov     dword ptr [g_xformDirtyFlags], ecx
        ret
    }
}
#endif
