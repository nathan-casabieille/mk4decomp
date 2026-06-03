/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
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
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
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

/* @addr 0x0045a010 (360b game) - 4-entry packed phase-state with indirect.
 *   Entry 1 (offset 0, 187b): phase from [scaled g_baseSel+0x84].
 *     phase 2: tail-call PendingMatch_00459510.
 *     phase 1: indirect-call [g_eventQueueEnd].
 *     phase 0: pop mstack into g_eventQueueEnd (saving the prior
 *       function-ptr), call CallDualStoreXorBit; on no-error AND
 *       bit 2 of 0x54208c clear, call ScaledArrStore_CallDualStoreXorBit. Tail
 *       installs Self with slot[+0x84] = 2 (bit-2 path) or 1 (clean path).
 *   5b NOP pad.
 *   Entry 2 (offset 0xc0, 70b): ScaledIterStep_0045c020; on no-error writes
 *     g_walkCallback into [g_fightGroupHead*4+0x24], zeroes +0x28, sets
 *     g_eventQueueChild=0xc8, tail-jmp DualEntryStateMachine.
 *   10b NOP pad.
 *   Entry 3 (offset 0x110, 40b): mask g_eventQueueCurrent with 0xff; on
 *     no-error set g_eventQueueChild = that and tail-jmp ScaledIterStep.
 *   8b NOP pad.
 *   Entry 4 (offset 0x140, 40b): same shape as entry 3 but tail-jmp
 *     DualEntryStateMachine.
 */
extern unsigned int g_table_004d57b0;
extern void CallDualStoreXorBit(void);
extern void DualEntryStateMachine(void);
extern void PendingMatch_00459510(void);
extern void ScaledArrStore_CallDualStoreXorBit(void);
extern void ScaledIterStep_0045c020(void);

__declspec(naked) void Phase3IndirectInstallChain(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      short L_p3i_phase0
        dec     eax
        je      short L_p3i_phase1
        call    PendingMatch_00459510
        pop     esi
        ret
    L_p3i_phase1:
        call    dword ptr [g_eventQueueEnd]
        pop     esi
        ret
    L_p3i_phase0:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_matrixStackTop], eax
        call    CallDualStoreXorBit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_p3i_done
        test    byte ptr [g_xformDirtyFlags], 4
        jne     short L_p3i_bit2Set
        call    ScaledArrStore_CallDualStoreXorBit
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_p3i_done
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_p3i_clean
    L_p3i_bit2Set:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset Phase3IndirectInstallChain
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    L_p3i_clean:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset Phase3IndirectInstallChain
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p3i_done:
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
        /* entry 2 (offset 0xc0) */
    L_p3i_entry2:
        call    ScaledIterStep_0045c020
        mov     ecx, dword ptr [g_framePauseFlag]
        xor     eax, eax
        cmp     ecx, eax
        jne     short L_p3i_e2End
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x24], ecx
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x28], eax
        mov     dword ptr [g_eventQueueChild], 0xc8
        jmp     DualEntryStateMachine
    L_p3i_e2End:
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
        /* entry 3 (offset 0x110) */
    L_p3i_entry3:
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     eax, dword ptr [g_framePauseFlag]
        and     ecx, 0xff
        test    eax, eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        jne     short L_p3i_e3End
        mov     eax, ecx
        mov     dword ptr [g_eventQueueChild], eax
        jmp     ScaledIterStep_0045c020
    L_p3i_e3End:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 4 (offset 0x140) */
    L_p3i_entry4:
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     eax, dword ptr [g_framePauseFlag]
        and     ecx, 0xff
        test    eax, eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        jne     short L_p3i_e4End
        mov     eax, ecx
        mov     dword ptr [g_eventQueueChild], eax
        jmp     DualEntryStateMachine
    L_p3i_e4End:
        ret
    }
}
