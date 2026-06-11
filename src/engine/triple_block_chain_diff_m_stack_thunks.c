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

/* @addr 0x0049ca10 (302b game) - 3-block: chain-diff mstack-push + push-call thunks.
 *   Block A (0..0x6c): mstack-push g_eventQueueChild. Compute diffs between [baseSel*4+0x38] and g_cj fields.
 *     g_eventQueueWorkType = [scaledInit*4+0x54] - [cj*4+0x54]; g_acc = [scaledInit*4+0x5c] - [cj*4+0x5c].
 *     Call Atan2QuadrantLookup; if pause skip. Call BootMod6487eClampAndChainMul10; if pause skip.
 *     chain[baseSel*4+0x70] = g_walkCallback. Mstack-pop into g_eventQueueChild. Pop esi; ret.
 *   Block B (+0xc0): call CondPickDualStore; if pause ret. Push 0x004f2778; call ArgSarStoreJmp; pop; ret.
 *   Block C (+0xe0): call DualCmpSwapStore; if pause ret. Push 0x004f27b8; call ScaledStackCallPause; pop; if pause ret.
 *     If bit2(0054208c): jmp CallSetPause. Else call DualMul10AndDispatchChain; if pause ret.
 *     Push 0x004f27c8; call ArgSar_Set1_Jmp; pop; ret.
 */
extern void ArgSarStoreJmp(void);
extern void ArgSar_Set1_Jmp(void);
extern void Atan2QuadrantLookup(void);
extern void CallSetPause(void);
extern void CondPickDualStore(void);
extern void DualCmpSwapStore(void);
extern void DualMul10AndDispatchChain(void);
extern void ScaledStackCallPause(void);

extern unsigned int g_matrixStack_arr;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void TripleBlockChainDiffMStackThunks(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_eventQueueChild;
  (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = MK4_NODE_AT(int, g_baseSel, 0x38);
  g_walkCallback = MK4_NODE_AT(int, g_cj_0054205c, 0x54);
  g_eventQueueCurrent = MK4_NODE_AT(int, g_cj_0054205c, 0x5c);
  g_eventQueueWorkType = MK4_NODE_AT(int, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) - g_walkCallback;
  g_chainAccumCur = MK4_NODE_AT(int, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) - g_eventQueueCurrent;
  Atan2QuadrantLookup();
  if (g_framePauseFlag == 0) {
    BootMod6487eClampAndChainMul10();
    if (g_framePauseFlag == 0) {
      MK4_NODE_AT(int, g_baseSel, 0x70) = g_walkCallback;
      g_eventQueueChild = *MK4_NODE(undefined4, (int)g_matrixStackTop);
      g_matrixStackTop = g_matrixStackTop + -1;
    }
  }
  return;
}
#else
__declspec(naked) void TripleBlockChainDiffMStackThunks(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueChild]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], ecx
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [edx*4 + 0x38]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     edx, dword ptr [ecx*4 + 0x54]
        mov     dword ptr [g_walkCallback], edx
        mov     ecx, dword ptr [ecx*4 + 0x5c]
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     esi, dword ptr [eax*4 + 0x54]
        mov     dword ptr [g_eventQueueWorkType], esi
        mov     eax, dword ptr [eax*4 + 0x5c]
        sub     esi, edx
        sub     eax, ecx
        mov     dword ptr [g_eventQueueWorkType], esi
        mov     dword ptr [g_chainAccumCur], eax
        call    Atan2QuadrantLookup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   38h
        call    BootMod6487eClampAndChainMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2ah
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x70], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_eventQueueChild], edx
        mov     dword ptr [g_matrixStackTop], eax
        pop     esi
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
        call    CondPickDualStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004f2778
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    DualCmpSwapStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3fh
        push    0x004f27b8
        call    ScaledStackCallPause
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   05h
        jmp     CallSetPause
        call    DualMul10AndDispatchChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004f27c8
        call    ArgSar_Set1_Jmp
        add     esp, 4
        ret
    }
}
#endif
