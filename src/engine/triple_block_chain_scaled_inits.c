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

/* @addr 0x00450f10 (324b game) - 3-block: chain-init + ScaledInit dual thunks. */
extern void ChainGatedNegAccum(void);
extern void MStackCall_MStackPush2ChainPrepend_00406600(void);
extern void PushSetXfmMaskCallPop(void);
extern void RosterSetupFsmCluster(void);
extern void ScaledInit_TripleBlockChainScaledInits_g_walkCallback_00450ed0(void);
extern void ScaledInit_TripleBlockChainScaledInits_g_walkCallback_00450ef0(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void TripleBlockChainScaledInits(void)

{
  PushSetXfmMaskCallPop();
  if ((g_framePauseFlag == 0) && ((g_xformDirtyFlags & 4) == 0)) {
    MStackCall_MStackPush2ChainPrepend_00406600();
    if (g_framePauseFlag == 0) {
      g_cj_0054205c = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_cj_00542058;
      g_chainAccumCur = MK4_NODE_AT(undefined4, g_cj_00542054, 4);
      g_eventQueueNotMask = MK4_NODE_AT(undefined4, g_cj_00542054, 8);
      ChainGatedNegAccum();
      if (g_framePauseFlag == 0) {
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x54) = g_chainAccumCur;
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x5c) = g_eventQueueNotMask;
        g_walkCallback = MK4_NODE_AT(undefined4, g_cj_00542054, 0xc);
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x58) = g_walkCallback;
        g_eventQueueWorkType = 0x1999;
        (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_cj_0054205c + 0x15;
        TripleVecAccCallStore();
        if (g_framePauseFlag == 0) {
          g_xformDirtyFlags = g_xformDirtyFlags | 4;
          if ((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) != 0) {
            g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
          }
        }
      }
    }
  }
  return;
}
#else
__declspec(naked) void TripleBlockChainScaledInits(void) {
    __asm {
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0f2h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   0fh
        _emit   85h
        _emit   0e5h
        _emit   00h
        _emit   00h
        _emit   00h
        call    MStackCall_MStackPush2ChainPrepend_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d3h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_cj_0054205c], eax
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     edx, dword ptr [eax*4 + 4]
        mov     dword ptr [g_chainAccumCur], edx
        mov     eax, dword ptr [eax*4 + 8]
        mov     dword ptr [g_eventQueueNotMask], eax
        call    ChainGatedNegAccum
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   8dh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [g_chainAccumCur]
        mov     dword ptr [ecx*4 + 0x54], edx
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        mov     dword ptr [eax*4 + 0x5c], ecx
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [edx*4 + 0xc]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        mov     edx, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_eventQueueWorkType], 0x1999
        add     edx, 0x15
        mov     dword ptr [g_currentNodeIdx], edx
        call    TripleVecAccCallStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   22h
        mov     ecx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [g_currentNodeIdx]
        or      ecx, 4
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        _emit   74h
        _emit   0ah
        mov     eax, ecx
        xor     eax, 4
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    ScaledInit_TripleBlockChainScaledInits_g_walkCallback_00450ed0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     RosterSetupFsmCluster
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    ScaledInit_TripleBlockChainScaledInits_g_walkCallback_00450ef0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     RosterSetupFsmCluster
        ret
    }
}
#endif
