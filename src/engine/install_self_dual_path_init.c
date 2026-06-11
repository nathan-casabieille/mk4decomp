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

/* @addr 0x0049a2f0 (280b game) - install-self with dual-path tail.
 *   state nonzero (init path): push 0x47, 0x0049a580; call StoreTwoCall;
 *     push 0x004f2770; tail-call ArgSarStoreJmp; eax=g_pause; ret.
 *   state zero: call RunBlockFsmCluster; if !pause: push 0x0054331c, call
 *     GuardedPackedSlotInit; if !pause: g_eventQueueChild=4; install-self;
 *     chain[+0x84]=1; scaledInit-chain push 0x0049a2f0+0x01000000;
 *     call ScaledClearJmp_InstallSelf3WayChainCmp; pause=1; ret.
 *   After 12 NOPs (alignment-only): tail block for another entry/sibling that
 *     calls CondPickDualStore; if !pause: RunBlockFsmCluster; if !pause:
 *     push 0x00543318, GuardedPackedSlotInit; if !pause: tail-jmp InstallSelfStoreTwoCall; ret.
 */
extern void ArgSarStoreJmp(void);
extern void CondPickDualStore(void);
extern void GuardedPackedSlotInit(void);
extern void InstallSelfStoreTwoCall(void);
extern void RunBlockFsmCluster(void);
extern void ScaledClearJmp_InstallSelf3WayChainCmp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int InstallSelfDualPathInit(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_baseSel * 4;
  iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
  *(undefined4 *)(iVar1 + 0x84) = 0;
  if (iVar2 != 0) {
    StoreTwoCall(&(*(unsigned int *)MK4_VA(unsigned int, 0x49a580)),0x47);
    ArgSarStoreJmp(&(*(unsigned int *)MK4_VA(unsigned int, 0x4f2770)));
    return g_framePauseFlag;
  }
  RunBlockFsmCluster();
  iVar2 = g_framePauseFlag;
  if (g_framePauseFlag == 0) {
    GuardedPackedSlotInit(&(*(unsigned int *)MK4_VA(unsigned int, 0x54331c)));
    iVar2 = g_framePauseFlag;
    if (g_framePauseFlag == 0) {
      g_eventQueueChild = 4;
      *(code **)(iVar1 + 8) = InstallSelfDualPathInit;
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 1;
      (g_currentNodeIdx) = *(int *)(iVar1 + 4);
      *MK4_NODE(undefined4, (g_currentNodeIdx)) = 0x149a2f0;
      (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
      *(int *)(iVar1 + 4) = (g_currentNodeIdx);
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
      iVar2 = ScaledClearJmp_InstallSelf3WayChainCmp();
      g_framePauseFlag = 1;
    }
  }
  return iVar2;
}
#else
__declspec(naked) void InstallSelfDualPathInit(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   23h
        push    0x47
        push    0x0049a580
        call    StoreTwoCall
        add     esp, 8
        push    0x004f2770
        call    ArgSarStoreJmp
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        pop     esi
        ret
        call    RunBlockFsmCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   7fh
        push    0x0054331c
        call    GuardedPackedSlotInit
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   69h
        mov     dword ptr [g_eventQueueChild], 4
        mov     dword ptr [esi + 8], 0x0049a2f0
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, 0x0049a2f0
        add     edx, 0x01000000
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], 0
        call    ScaledClearJmp_InstallSelf3WayChainCmp
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
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
        call    CondPickDualStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        call    RunBlockFsmCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        push    0x00543318
        call    GuardedPackedSlotInit
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     InstallSelfStoreTwoCall
        ret
    }
}
#endif
