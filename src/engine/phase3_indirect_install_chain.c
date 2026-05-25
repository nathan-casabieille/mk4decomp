/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;
extern unsigned int g_eventQueueChild;
extern u32 g_pendingNodeType;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* @addr 0x0045a010 (360b game) - 4-entry packed phase-state with indirect.
 *   Entry 1 (offset 0, 187b): phase from [scaled g_baseSel_00542060+0x84].
 *     phase 2: tail-call PendingMatch_00459510.
 *     phase 1: indirect-call [g_eventQueueEnd].
 *     phase 0: pop mstack into g_eventQueueEnd (saving the prior
 *       function-ptr), call CallDualStoreXorBit_004285e0; on no-error AND
 *       bit 2 of 0x54208c clear, call ScaledArrStore_004285c0. Tail
 *       installs Self with slot[+0x84] = 2 (bit-2 path) or 1 (clean path).
 *   5b NOP pad.
 *   Entry 2 (offset 0xc0, 70b): ScaledIterStep_0045c020; on no-error writes
 *     g_walkCallback into [g_fightGroupHead*4+0x24], zeroes +0x28, sets
 *     g_eventQueueChild=0xc8, tail-jmp DualEntryStateMachine_0045a180.
 *   10b NOP pad.
 *   Entry 3 (offset 0x110, 40b): mask g_eventQueueCurrent with 0xff; on
 *     no-error set g_eventQueueChild = that and tail-jmp ScaledIterStep.
 *   8b NOP pad.
 *   Entry 4 (offset 0x140, 40b): same shape as entry 3 but tail-jmp
 *     DualEntryStateMachine_0045a180.
 */
extern unsigned int g_framePauseFlag;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueChild;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_table_004d57b0;
extern void CallDualStoreXorBit_004285e0(void);
extern void DualEntryStateMachine_0045a180(void);
extern void PendingMatch_00459510(void);
extern void ScaledArrStore_004285c0(void);
extern void ScaledIterStep_0045c020(void);

__declspec(naked) void Phase3IndirectInstallChain_0045a010(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
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
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_state_004d57ac], eax
        call    CallDualStoreXorBit_004285e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_p3i_done
        test    byte ptr [g_xformDirtyFlags], 4
        jne     short L_p3i_bit2Set
        call    ScaledArrStore_004285c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_p3i_done
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_p3i_clean
    L_p3i_bit2Set:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset Phase3IndirectInstallChain_0045a010
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    L_p3i_clean:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset Phase3IndirectInstallChain_0045a010
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
        jmp     DualEntryStateMachine_0045a180
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
        jmp     DualEntryStateMachine_0045a180
    L_p3i_e4End:
        ret
    }
}
