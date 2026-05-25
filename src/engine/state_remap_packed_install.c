/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;

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
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* @addr 0x0046b360 (374b game) - 3-entry packed: state-remap + install +
 *   state-remap-call.
 *   Entry 1 (offset 0, 80b): sets g_xformEntityIdx = &g_dispatchTableArr7_005019d0>>2,
 *     reads [g_baseSel_00542060*4 + 0x34] as state code; if 0x10 → 2, if
 *     0x11 → 7. If != 0xf, pushes 0x542a70 → ArgScaledTestStore_00494140.
 *   Entry 2 (offset 0x50, 219b): phase-state install. Phase != 0 tail-jmps
 *     StackPopDispatchTagged_0041f780. Phase 0: writes [scaled+0x74]=0x2002,
 *     ScaledAndAlfe_00490390 → push 0x542a78 → ArgScaledTestStore. On
 *     no-error writes g_xformEntityIdx → [0x54205c*4 + 0x24], installs Self
 *     entry 1 (0x46b3b0) with packed_ptr (Self + 0x01000000), calls
 *     ScaledClearJmp_00428d60.
 *   5b NOP align pad.
 *   Entry 3 (offset 0x130, 70b): FiveCallScaledChainTailJmp_0045f8d0;
 *     on no-error reads [scaled+0x34] as state code; if 0x11 → 7. If
 *     != 0xf, tail-call Install3StateRouterTail_0046b4e0; else pushes
 *     0x4eaee0 → ArgSarStoreJmp_004594f0.
 */
extern unsigned int g_data_004eaee0;
extern unsigned int g_dispatchTableArr7_005019d0;
extern unsigned int g_dispatchSave64_00542a70;
extern unsigned int g_dispatchSave65_00542a78;
extern void ArgSarStoreJmp_004594f0(void);
extern void ArgScaledTestStore_00494140(void);
extern void Install3StateRouterTail_0046b4e0(void);
extern void ScaledAndAlfe_00490390(void);
extern void ScaledClearJmp_00428d60(void);

__declspec(naked) void StateRemapPackedInstall_0046b360(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, offset g_dispatchTableArr7_005019d0
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        mov     eax, dword ptr [ecx*4 + 0x34]
        cmp     eax, 0x10
        mov     dword ptr [g_walkCallback], eax
        jne     short L_srp_check11
        mov     eax, 2
        mov     dword ptr [g_walkCallback], eax
    L_srp_check11:
        cmp     eax, 0x11
        jne     short L_srp_check15
        mov     eax, 7
        mov     dword ptr [g_walkCallback], eax
    L_srp_check15:
        cmp     eax, 0xf
        je      short L_srp_e1End
        push    offset g_dispatchSave64_00542a70
        call    ArgScaledTestStore_00494140
        add     esp, 4
    L_srp_e1End:
        ret
    L_srp_entry2:
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_srp_e2phase0
        call    StackPopDispatchTagged_0041f780
        pop     esi
        ret
    L_srp_e2phase0:
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x2002
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    ScaledAndAlfe_00490390
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_srp_e2End
        push    offset g_dispatchSave65_00542a78
        call    ArgScaledTestStore_00494140
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     short L_srp_e2End
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [edx*4 + 0x24], eax
        mov     dword ptr [esi + 8], offset L_srp_entry2
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     edx, offset L_srp_entry2
        add     edx, 0x01000000
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x84], 0
        call    ScaledClearJmp_00428d60
        mov     dword ptr [g_framePauseFlag], 1
    L_srp_e2End:
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
        /* entry 3 (offset 0x130) */
    L_srp_entry3:
        call    FiveCallScaledChainTailJmp_0045f8d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_srp_e3End
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [eax*4 + 0x34]
        cmp     eax, 0x11
        mov     dword ptr [g_walkCallback], eax
        jne     short L_srp_e3check15
        mov     eax, 7
        mov     dword ptr [g_walkCallback], eax
    L_srp_e3check15:
        cmp     eax, 0xf
        jne     short L_srp_e3pushAlarm
        jmp     Install3StateRouterTail_0046b4e0
    L_srp_e3pushAlarm:
        push    offset g_data_004eaee0
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
    L_srp_e3End:
        ret
    }
}
