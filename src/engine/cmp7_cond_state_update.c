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
 * @addr 0x0042ed90 (125b game) - cmp7-check then conditional state update:
 *   call Cmp7DirtyToggle; on pause clear, if state-bit 0 set and
 *   0x537f8c is null and slot[walk]==1 and g_eventMusicSlot2==g_eventQueueCurrent,
 *   update slot[walk]=2 and 0x537f8c=g_eventMusicSlot2; then tail-call
 *   CallSetPause.
 */
extern unsigned int g_dispatchSave_00537f8c;
extern unsigned int g_eventMusicSlot2;
extern void CallSetPause(void);
extern void Cmp7DirtyToggle(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Cmp7CondStateUpdate(void)

{
  Cmp7DirtyToggle();
  if (g_framePauseFlag == 0) {
    if ((((byte)g_xformDirtyFlags & 1) != 0) && (g_walkCallback = (*(unsigned int *)MK4_VA(unsigned int, 0x537f8c)), (*(unsigned int *)MK4_VA(unsigned int, 0x537f8c)) == 0)) {
      g_walkCallback = 1;
      if ((*MK4_NODE(int, (g_currentNodeIdx)) == 1) &&
         (g_walkCallback = g_eventMusicSlot2, g_eventMusicSlot2 != g_eventQueueCurrent)) {
        g_eventQueueCurrent = 2;
        *MK4_NODE(undefined4, (g_currentNodeIdx)) = 2;
        g_walkCallback = 1;
        (*(unsigned int *)MK4_VA(unsigned int, 0x537f8c)) = 1;
      }
    }
    CallSetPause();
  }
  return;
}
#else
__declspec(naked) void Cmp7CondStateUpdate(void) {
    __asm {
        call    Cmp7DirtyToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     done
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ecx, 1
        test    al, cl
        push    esi
        je      tailCall
        mov     eax, dword ptr [g_dispatchSave_00537f8c]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     tailCall
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], ecx
        cmp     dword ptr [eax*4 + 0], ecx
        jne     tailCall
        mov     edx, dword ptr [g_eventMusicSlot2]
        mov     esi, dword ptr [g_eventQueueCurrent]
        cmp     edx, esi
        mov     dword ptr [g_walkCallback], edx
        je      tailCall
        mov     dword ptr [g_eventQueueCurrent], 2
        mov     dword ptr [eax*4 + 0], 2
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_dispatchSave_00537f8c], ecx
tailCall:
        call    CallSetPause
        pop     esi
done:
        ret
    }
}
#endif
