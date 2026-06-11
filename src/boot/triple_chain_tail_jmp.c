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

/*
 * @addr 0x00419900 (118b boot) - 3-stage chain then tail-jmp:
 *   call MStackPush2RunCountdown; gate; call MStackBracket7_DispatchAndChain; gate; set up
 *   g_eventQueueWorkType=3 and g_pendingNodeType=0x004d7afe; call SlotInitAndChainLink;
 *   gate; if state-bit 2 clear, set walk=0x11999 into wt[+0x48] and
 *   bump g_eventQueueEnd by 0x15, then tail-jmp BootFlagChainAudioPause.
 */
extern void BootFlagChainAudioPause(void);
extern void SlotInitAndChainLink(void);

/*
 * NON-COAXABLE: MSVC /O2 assigns xform to eax (a1, 5b) and val to ecx (b9, 5b),
 * forcing g_walkCallback store to 89 0d (6b) and state to a1+a3 (10b).
 * Orig has xform in ecx (8b 0d, 6b) and val in eax (b8), giving a3 (5b) and
 * 8b15+8915 (12b). MSVC's choice is more optimal; register layout not coaxable.
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void TripleChainTailJmp(void)

{
  MStackPush2RunCountdown();
  if (g_framePauseFlag == 0) {
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag == 0) {
      g_eventQueueWorkType = 3;
      g_dualC = 0x135ebe;
      SlotInitAndChainLink();
      if ((g_framePauseFlag == 0) && (((byte)g_xformDirtyFlags & 4) == 0)) {
        g_walkCallback = 0x11999;
        MK4_NODE_AT(undefined4, g_eventQueuePending, 0x48) = 0x11999;
        (g_currentNodeIdx) = g_cj_00542054 + 0x15;
        BootFlagChainAudioPause();
        return;
      }
    }
  }
  return;
}
#else
__declspec(naked) void TripleChainTailJmp(void) {
    __asm {
        call    MStackPush2RunCountdown
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     done
        call    MStackBracket7_DispatchAndChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     done
        mov     eax, 0x004d7af8
        mov     dword ptr [g_eventQueueWorkType], 3
        shr     eax, 2
        mov     dword ptr [g_pendingNodeType], eax
        call    SlotInitAndChainLink
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     done
        test    byte ptr [g_xformDirtyFlags], 4
        jne     done
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x011999
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        add     edx, 0x15
        mov     dword ptr [g_currentNodeIdx], edx
        jmp     BootFlagChainAudioPause
done:
        ret
    }
}
#endif
