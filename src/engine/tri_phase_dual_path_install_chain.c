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
extern unsigned int g_state_00537f94;
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
extern unsigned int g_state_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004ed590;
extern unsigned int g_data_004ed5a8;
extern void MStackPushSet0008_004901a0(void);
extern void MStackPushSet0020_004901d0(void);
extern void CmpEqInitCallElseJmp_0048d4b0(void);
extern void TriPhaseDualPathInstallChain_0047e420(void);
extern void TailJmpInstallSelfPair_0047e690(void);
extern void ScaledAndAldf_00490330(void);
extern void EsiEdiAliasDualMul10_004906b0(void);
extern void InstallSelfThresholdDispatch_0047e310(void);

/* @addr 0x0047e1a0 (355b game) - 3-entry packed phase chain w/ alarms.
 *   Entry 1 (offset 0, 51b): writes 0x1012 into [g_baseSel_00542060*4+0x74]
 *     (mirrored 0x54206c), calls MStackPushSet0008_004901a0, on no-error
 *     pushes 0x4ed590 (alarm string) and calls ArgSarStoreJmp_004594f0.
 *   13b NOP align pad.
 *   Entry 2 (offset 0x40, 67b): same shape but writes [scaled+0x68]=0x402,
 *     [scaled+0x74]=0x201 first, calls MStackPushSet0020_004901d0, then
 *     conditionally pushes 0x4ed5a8.
 *   13b NOP align pad.
 *   Entry 3 / body (offset 0x90, 211b): phase-state install. Phase 0 →
 *     install Self body at [esi+8], slot[+0x84]=1, arms 0x541e6c. Phase 1 →
 *     CmpEqInitCallElseJmp_0048d4b0, on no-error: if bit 0 of 0x54208c set
 *     tail-call TriPhaseDualPathInstallChain_0047e420; else call TailJmpInstallSelfPair_0047e690.
 *     If g_walkCallback < 0x26666 (threshold) tail-installs Self.
 *     Else chains ScaledAndAldf_00490330 → EsiEdiAliasDualMul10_004906b0,
 *     writes 0x28f into [g_fightGroupHead*4+0x4c], calls
 *     InstallSelfThresholdDispatch_0047e310.
 */
extern unsigned int g_framePauseFlag;
extern unsigned int g_pendingNodeType;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_xformDirtyFlags;
extern void ArgSarStoreJmp_004594f0(void);

__declspec(naked) void Alarm3EntryPhaseChain_0047e1a0(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x1012
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    MStackPushSet0008_004901a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a3e_e1End
        push    offset g_data_004ed590
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
    L_a3e_e1End:
        ret
        /* 13b NOP pad */
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
        nop
        /* entry 2 (offset 0x40) */
    L_a3e_entry2:
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x68], 0x402
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x201
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    MStackPushSet0020_004901d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a3e_e2End
        push    offset g_data_004ed5a8
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
    L_a3e_e2End:
        ret
        /* 13b NOP pad */
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
        nop
        /* entry 3 / body (offset 0x90) */
    L_a3e_body:
        mov     eax, dword ptr [g_baseSel_00542060]
        push    ebx
        push    esi
        mov     ebx, 1
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_a3e_installPhase0
        mov     dword ptr [g_walkCallback], 2
        call    CmpEqInitCallElseJmp_0048d4b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_a3e_doneNoPop
        test    byte ptr [g_xformDirtyFlags], bl
        je      short L_a3e_e3InitChain
        call    TriPhaseDualPathInstallChain_0047e420
        pop     esi
        pop     ebx
        ret
    L_a3e_e3InitChain:
        call    TailJmpInstallSelfPair_0047e690
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a3e_doneNoPop
        cmp     dword ptr [g_walkCallback], 0x26666
        jl      short L_a3e_installPhase0
        call    ScaledAndAldf_00490330
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a3e_doneNoPop
        mov     dword ptr [g_walkCallback], 0x4ccc
        call    EsiEdiAliasDualMul10_004906b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a3e_doneNoPop
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0x28f
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x4c], eax
        call    InstallSelfThresholdDispatch_0047e310
        pop     esi
        pop     ebx
        ret
    L_a3e_installPhase0:
        mov     dword ptr [esi + 8], offset L_a3e_body
        mov     dword ptr [esi + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], ebx
        mov     dword ptr [g_framePauseFlag], ebx
    L_a3e_doneNoPop:
        pop     esi
        pop     ebx
        ret
    }
}
