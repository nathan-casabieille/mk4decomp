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

/* @addr 0x0042e1d0 (188b game) - install-self counted-decrement with chain accumulator.
 *   eax = base*4; flag = [eax+0x84]; clear.
 *   if (flag != 0): g_eventQueueEnd--; if (!= 0) install-with-snapshot;
 *     else call StackPopDispatchTagged; pop edi/esi; ret.
 *   if (flag == 0): esi = [0x52ab10]; edx = packed_ptr(0x4e38d0);
 *     g_fightGroupHead = esi; g_eventQueueIdx = edx; g_eventQueueEnd = 0xf; jmp install-with-snapshot.
 *   install-with-snapshot: esi = g_fightGroupHead; edx = g_eventQueueIdx;
 *     ecx = chain[esi+0x5c]; edi = chain[(edx+1)*4 - 4]; ecx += edi;
 *     g_walkCallback = ecx; g_eventQueueCurrent = edi; g_eventQueueIdx = edx+1;
 *     chain[esi+0x5c] = ecx. install self: [eax+8]=0x42e1d0, [eax+0x84]=1.
 *     g_pendingNodeType = 2; pause = 1.
 */
extern unsigned int g_eventQueueSeed;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void InstallSelfCountedAccum(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = g_baseSel * 4;
  iVar1 = *(int *)(iVar2 + 0x84);
  *(undefined4 *)(iVar2 + 0x84) = 0;
  if (iVar1 == 0) {
    g_cj_00542058 = 0x138e34;
    g_cj_0054205c = g_eventQueueSeed;
    g_cj_00542054 = 0xf;
  }
  else {
    g_cj_00542054 = g_cj_00542054 + -1;
    if (g_cj_00542054 == 0) {
      StackPopDispatchTagged();
      return;
    }
  }
  g_cj_00542058 = g_cj_00542058 + 1;
  g_eventQueueCurrent = *(int *)(g_cj_00542058 * 4 + -4);
  g_walkCallback = MK4_NODE_AT(int, g_cj_0054205c, 0x5c) + g_eventQueueCurrent;
  MK4_NODE_AT(int, g_cj_0054205c, 0x5c) = g_walkCallback;
  *(code **)(iVar2 + 8) = InstallSelfCountedAccum;
  *(undefined4 *)(iVar2 + 0x84) = 1;
  g_dualC = 2;
  g_framePauseFlag = 1;
  return;
}
#else
__declspec(naked) void InstallSelfCountedAccum(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        shl     eax, 2
        push    edi
        mov     ecx, [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   17h
        mov     ecx, dword ptr [g_eventQueueEnd]
        dec     ecx
        mov     dword ptr [g_eventQueueEnd], ecx
        _emit   75h
        _emit   2eh
        call    StackPopDispatchTagged
        pop     edi
        pop     esi
        ret
        mov     esi, dword ptr [g_eventQueueSeed]
        mov     edx, 0x004e38d0
        shr     edx, 2
        mov     dword ptr [g_fightGroupHead], esi
        mov     dword ptr [g_eventQueueIdx], edx
        mov     dword ptr [g_eventQueueEnd], 0x0f
        _emit   0ebh
        _emit   0ch
        mov     esi, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     ecx, [esi*4 + 0x5c]
        inc     edx
        mov     dword ptr [g_walkCallback], ecx
        mov     edi, [edx*4 - 4]
        add     ecx, edi
        mov     dword ptr [g_eventQueueCurrent], edi
        mov     dword ptr [g_eventQueueIdx], edx
        mov     dword ptr [g_walkCallback], ecx
        mov     [esi*4 + 0x5c], ecx
        mov     ecx, 1
        mov     dword ptr [eax + 8], 0x0042e1d0
        mov     dword ptr [eax + 0x84], ecx
        pop     edi
        mov     dword ptr [g_pendingNodeType], 2
        mov     dword ptr [g_framePauseFlag], ecx
        pop     esi
        ret
    }
}
#endif
