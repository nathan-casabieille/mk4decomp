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

extern unsigned int g_data_004eb6f8;
extern unsigned int g_data_004eb710;
extern unsigned int g_data_004eb720;
extern unsigned int g_data_004eb738;
extern unsigned int g_data_004eb740;
extern void CallPauseDirtyMStackPushFn_0046e2a0(void);
extern void InstallSelfIndirectJmp_0048f3f0(void);
extern void ScaledMove74to70_0046eaa0(void);
extern void FiveBlockDispatchChain_0046ec20(void);
extern void TripleCallPauseJmp_00470500(void);
extern void ComboScriptDispatchCluster_00470530(void);
extern void PhaseDispatchListAdvance_004709e0(void);
extern void IterStepScaledStore_0048e600(void);

/* @addr 0x0046ee00 (356b game) - 5-entry packed install-self + alarm chain.
 *   Entry 1 (offset 0, 135b): phase from [scaled g_baseSel_00542060+0x84].
 *     phase != 0: writes 0x28f into [g_fightGroupHead*4+0x4c], pushes
 *       0x0046e2a0 (callback addr) onto mstack via g_state_004d57ac, then
 *       tail-call InstallSelfIndirectJmp_0048f3f0.
 *     phase 0: calls ScaledZeroFour_00490740; on no-error installs Self at
 *       [esi+8], slot[+0x84]=1, g_pendingNodeType=0xc, arms 0x541e6c=1.
 *   9b NOP align pad.
 *   Entry 2 (offset 0x90, 106b): ScaledMove74to70_0046eaa0; on no-error
 *     sets [g_baseSel_00542060*4+0x74]=0x604; if [scaled+0x30] != 0 tail-jmp
 *     FiveBlockDispatchChain_0046ec20; else chain ScaledAndAlfe_00490390 →
 *     TripleCallPauseJmp_00470500 → push 0x4eb6f8 →
 *     ArgSarStoreJmp_004594f0.
 *   6b NOP align pad.
 *   Entry 3 (offset 0x100, 18b): sets g_eventQueueEnd = &g_data_004eb710>>2
 *     and tail-jmp PhaseDispatchListAdvance_004709e0.
 *   14b NOP align pad.
 *   Entry 4 (offset 0x120, 32b): if bit 0 of g_xformDirtyFlags set tail-jmp
 *     CallPauseDirtyMStackPushFn_0046e2a0; else set g_eventQueueEnd =
 *     &g_data_004eb720>>2 and tail-jmp ComboScriptDispatchCluster_00470530.
 *   Entry 5 (offset 0x140, 36b): push 0x4eb738, call IterStepScaledStore_0048e600;
 *     on no-error push 0x4eb740, call ArgSarStoreJmp_004594f0.
 */
extern unsigned int g_framePauseFlag;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_table_004d57b0;
extern void ArgSarStoreJmp_004594f0(void);
extern void ScaledAndAlfe_00490390(void);

__declspec(naked) void FiveEntryAlarmInstallChain_0046ee00(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_fea_phase0
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0x28f
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x4c], eax
        mov     eax, dword ptr [g_state_004d57ac]
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], offset CallPauseDirtyMStackPushFn_0046e2a0
        call    InstallSelfIndirectJmp_0048f3f0
        pop     esi
        ret
    L_fea_phase0:
        call    ScaledZeroFour_00490740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fea_e1End
        mov     eax, 1
        mov     dword ptr [esi + 8], offset FiveEntryAlarmInstallChain_0046ee00
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 0xc
        mov     dword ptr [g_framePauseFlag], eax
    L_fea_e1End:
        pop     esi
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
        /* entry 2 (offset 0x90) */
    L_fea_entry2:
        call    ScaledMove74to70_0046eaa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fea_e2End
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x604
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [edx*4 + 0x30]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      short L_fea_skipJmp
        jmp     FiveBlockDispatchChain_0046ec20
    L_fea_skipJmp:
        call    ScaledAndAlfe_00490390
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fea_e2End
        call    TripleCallPauseJmp_00470500
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_fea_e2End
        push    offset g_data_004eb6f8
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
    L_fea_e2End:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 3 (offset 0x100) */
    L_fea_entry3:
        mov     eax, offset g_data_004eb710
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        jmp     PhaseDispatchListAdvance_004709e0
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
        nop
        /* entry 4 (offset 0x120) */
    L_fea_entry4:
        test    byte ptr [g_xformDirtyFlags], 1
        je      short L_fea_e4second
        jmp     CallPauseDirtyMStackPushFn_0046e2a0
    L_fea_e4second:
        mov     eax, offset g_data_004eb720
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        jmp     ComboScriptDispatchCluster_00470530
        /* entry 5 (offset 0x140) */
    L_fea_entry5:
        push    offset g_data_004eb738
        call    IterStepScaledStore_0048e600
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     short L_fea_e5End
        push    offset g_data_004eb740
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
    L_fea_e5End:
        ret
    }
}
