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

/* @addr 0x0049cc30 (267b game) - mstack-push + bit-gated loop with 3 helper calls. */
extern void AndStoreJmp(void);
extern void Thunk_LoadShlDerefCallSkip(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MStackBitLoopTripleCall(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
  g_eventQueueWorkType = g_walkCallback;
  SetJmp_Thunk_LinkedListBitMaskSearch();
  if (g_framePauseFlag == 0) {
    while ((g_xformDirtyFlags & 4) == 0) {
      if (g_cj_0054205c != *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x2c)) {
        do {
          g_xformDirtyFlags = g_xformDirtyFlags | 4;
          if (((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) == 0) || (g_xformDirtyFlags = g_xformDirtyFlags ^ 4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) == 0))
          goto LAB_0049cd20;
          g_eventQueueCurrent = 0xffffffff;
          g_walkCallback = g_eventQueueWorkType;
          AndStoreJmp();
          if (g_framePauseFlag != 0) {
            return;
          }
          if ((g_xformDirtyFlags & 4) != 0) goto LAB_0049cd20;
        } while (g_cj_0054205c != *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x2c));
      }
      g_dualC = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
      thunk_LoadShlDerefCallSkip();
      if (g_framePauseFlag != 0) {
        return;
      }
      g_walkCallback = g_eventQueueWorkType;
      SetJmp_Thunk_LinkedListBitMaskSearch();
      if (g_framePauseFlag != 0) {
        return;
      }
    }
LAB_0049cd20:
    (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)((int)g_matrixStackTop * 4);
    g_matrixStackTop = g_matrixStackTop + -1;
  }
  return;
}
#else
__declspec(naked) void MStackBitLoopTripleCall(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        push    ebx
        mov     dword ptr [g_matrixStackTop], eax
        push    esi
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [g_eventQueueWorkType], edx
        call    SetJmp_Thunk_LinkedListBitMaskSearch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d0h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ebx, 4
        or      esi, 0xffffffff
        test    byte ptr [g_xformDirtyFlags], bl
        _emit   0fh
        _emit   85h
        _emit   0a4h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_cj_0054205c]
        cmp     ecx, dword ptr [eax*4 + 0x2c]
        _emit   74h
        _emit   5ch
        mov     edx, dword ptr [g_xformDirtyFlags]
        or      edx, ebx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   7eh
        mov     ecx, edx
        xor     ecx, ebx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        _emit   74h
        _emit   70h
        mov     edx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [g_eventQueueCurrent], esi
        mov     dword ptr [g_walkCallback], edx
        call    AndStoreJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   68h
        test    byte ptr [g_xformDirtyFlags], bl
        _emit   75h
        _emit   48h
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_cj_0054205c]
        cmp     ecx, dword ptr [eax*4 + 0x2c]
        _emit   75h
        _emit   0a4h
        mov     dword ptr [g_pendingNodeType], eax
        call    Thunk_LoadShlDerefCallSkip
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   39h
        mov     edx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [g_walkCallback], edx
        call    SetJmp_Thunk_LinkedListBitMaskSearch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   84h
        _emit   53h
        _emit   0ffh
        _emit   0ffh
        _emit   0ffh
        pop     esi
        pop     ebx
        ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        pop     esi
        pop     ebx
        ret
    }
}
#endif
