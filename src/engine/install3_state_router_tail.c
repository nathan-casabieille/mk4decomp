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

/* @addr 0x0046b4e0 (325b game) - 3-state install-self + dispatch state-1 (router) + tail thunk.
 *   state==0: call StateDispatchTable; if pause ret.
 *     g_eventQueueEnd=g_walkCallback; g_currentNodeFlags=0x1999; g_eventQueueNotMask=0.
 *     Install-self at entry+0x01000000; state=1; call EsiInstallClampAddCall; pause=1; ret.
 *   state==1 (dec,je): tail-call CallPauseScaledStoreCopyJmp; if pause ret.
 *     Install-self at entry; state=2; g_pendingNodeType=1; pause=1; ret.
 *   state>=2 (fall): cmp g_tickFlagF with 2: if neq tail-call CjInstallSelfRouter; pop+ret.
 *     Else: g_walkCallback=g_smState4Way; if zero jmp state=2 install; else tail-call CjInstallSelfRouter; pop+ret.
 *   Tail (+0x120, 2-NOP pad): chain[baseSel*4+0x74]=0x104; push 0x004eb008; call ArgSarStoreJmp; pop; ret.
 */
extern unsigned int g_smState4Way;
extern unsigned int g_tickFlagF;
extern void ArgSarStoreJmp(void);
extern void CallPauseScaledStoreCopyJmp(void);
extern void CjInstallSelfRouter(void);
extern void EsiInstallClampAddCall(void);
extern void StateDispatchTable(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Install3StateRouterTail(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_baseSel * 4;
  iVar2 = MK4_NODE_AT(int, g_baseSel, 0x84);
  *(undefined4 *)(iVar1 + 0x84) = 0;
  if (iVar2 == 0) {
    StateDispatchTable();
    if (g_framePauseFlag == 0) {
      g_currentNodeFlags = 0x1999;
      g_cj_00542054 = g_walkCallback;
      g_eventQueueNotMask = 0;
      *(code **)(iVar1 + 8) = Install3StateRouterTail;
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 1;
      (g_currentNodeIdx) = *(int *)(iVar1 + 4);
      *MK4_NODE(undefined4, (g_currentNodeIdx)) = 0x146b4e0;
      (g_currentNodeIdx) = (g_currentNodeIdx) + 1;
      *(int *)(iVar1 + 4) = (g_currentNodeIdx);
      MK4_NODE_AT(undefined4, g_baseSel, 0x84) = 0;
      EsiInstallClampAddCall();
      g_framePauseFlag = 1;
    }
    return;
  }
  if (iVar2 == 1) {
    CallPauseScaledStoreCopyJmp();
    if (g_framePauseFlag != 0) {
      return;
    }
  }
  else {
    g_walkCallback = g_tickFlagF;
    if (g_tickFlagF == 2) {
      CjInstallSelfRouter();
      return;
    }
    g_walkCallback = g_smState4Way;
    if (g_smState4Way != 0) {
      CjInstallSelfRouter();
      return;
    }
  }
  *(code **)(iVar1 + 8) = Install3StateRouterTail;
  *(undefined4 *)(iVar1 + 0x84) = 2;
  g_dualC = 1;
  g_framePauseFlag = 1;
  return;
}
#else
__declspec(naked) void Install3StateRouterTail(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        _emit   83h
        _emit   0e8h
        _emit   00h
        _emit   74h
        _emit   67h
        dec     eax
        _emit   74h
        _emit   2bh
        mov     eax, dword ptr [g_tickFlagF]
        cmp     eax, 2
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   07h
        call    CjInstallSelfRouter
        pop     esi
        ret
        mov     eax, dword ptr [g_smState4Way]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   19h
        call    CjInstallSelfRouter
        pop     esi
        ret
        call    CallPauseScaledStoreCopyJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0b9h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     dword ptr [esi + 8], offset Install3StateRouterTail
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 1
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
        call    StateDispatchTable
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   80h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [g_currentNodeFlags], 0x1999
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_eventQueueNotMask], 0
        mov     dword ptr [esi + 8], offset Install3StateRouterTail
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, offset Install3StateRouterTail
        mov     dword ptr [edx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    EsiInstallClampAddCall
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
        _emit   90h
        _emit   90h
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x104
        mov     dword ptr [g_walkCallback], eax
        push    0x004eb008
        mov     dword ptr [ecx*4 + 0x74], eax
        call    ArgSarStoreJmp
        add     esp, 4
        ret
    }
}
#endif
