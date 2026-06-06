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

/* @addr 0x004388f0 (190b game) - install-self with multi-stage cascade.
 *   chain[+0x84]!=0 path: call DecOrZeroDirty4; if !pause and !bit-2 ret; else call GuardedSeq_ScaledZeroFour_then_StackPopDispatchTagged; ret.
 *     Continuing: esi=g_eventQueueChild; call Push84CallTestInstallJmp; if !pause:
 *     call DecJneSetCallSetJmp; if !pause: mstack-push 0x00438990; jmp GameDispatchValidateState; ret.
 *   chain[+0x84]==0 path: install-self at +0x08=0x004388f0, g_pendingNodeType=1, pause=1; pop+ret.
 *   Block B (+0xa0): cmp g_fightStateProgress vs g_currentNodeFlags; if le jmp self; else jmp GuardedSeq_ScaledZeroFour_then_StackPopDispatchTagged.
 */
extern unsigned int g_matrixStack_arr;
extern void DecJneSetCallSetJmp(void);
extern void DecOrZeroDirty4(void);
extern void GuardedSeq_ScaledZeroFour_then_StackPopDispatchTagged(void);
extern void Push84CallTestInstallJmp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void InstallSelfMultiCascade(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = g_baseSel * 4;
  iVar1 = *(int *)(iVar3 + 0x84);
  *(undefined4 *)(iVar3 + 0x84) = 0;
  if (iVar1 == 0) {
    *(code **)(iVar3 + 8) = InstallSelfMultiCascade;
    *(undefined4 *)(iVar3 + 0x84) = 1;
    g_dualC = 1;
    g_framePauseFlag = 1;
  }
  else {
    DecOrZeroDirty4();
    uVar2 = g_eventQueueChild;
    if (g_framePauseFlag == 0) {
      if (((byte)g_xformDirtyFlags & 4) != 0) {
        GuardedSeq_ScaledZeroFour_then_StackPopDispatchTagged();
        return;
      }
      Push84CallTestInstallJmp();
      if (g_framePauseFlag == 0) {
        DecJneSetCallSetJmp();
        if (g_framePauseFlag == 0) {
          g_matrixStackTop = g_matrixStackTop + 1;
          g_eventQueueChild = uVar2;
          *(undefined1 **)((int)g_matrixStackTop * 4) = &(*(unsigned int *)MK4_VA(unsigned int, 0x438990));
          GameDispatchValidateState();
          return;
        }
      }
    }
  }
  return;
}
#else
__declspec(naked) void InstallSelfMultiCascade(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        _emit   74h
        _emit   63h
        call    DecOrZeroDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   73h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   07h
        call    GuardedSeq_ScaledZeroFour_then_StackPopDispatchTagged
        pop     esi
        ret
        mov     esi, dword ptr [g_eventQueueChild]
        call    Push84CallTestInstallJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   4fh
        call    DecJneSetCallSetJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   41h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_eventQueueChild], esi
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_matrixStack_arr], 0x00438990
        call    GameDispatchValidateState
        pop     esi
        ret
        mov     ecx, 1
        mov     dword ptr [eax + 0x08], 0x004388f0
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        pop     esi
        ret
        mov     eax, dword ptr [g_fightStateProgress]
        mov     ecx, dword ptr [g_currentNodeFlags]
        cmp     eax, ecx
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   05h
        jmp     InstallSelfMultiCascade
        jmp     GuardedSeq_ScaledZeroFour_then_StackPopDispatchTagged
    }
}
#endif
