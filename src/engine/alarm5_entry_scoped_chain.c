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

/* @addr 0x0049be10 (370b game) - 5-entry packed alarm + scoped chain.
 *   Entry 1 (offset 0, 20b): MStackCall_00406740; on no-error tail-jmps
 *     CallSetPause_0041f830.
 *   12b NOP pad.
 *   Entry 2 (offset 0x20, 51b): writes 0x305 into [scaled+0x74], calls
 *     CondPickDualStore_0049c670; on no-error pushes 0x4f25d8 and
 *     ArgSarStoreJmp_004594f0.
 *   13b NOP pad.
 *   Entry 3 (offset 0x60, 190b): DualCmpSwapStore_0049c5a0 → push
 *     0x4f2640 → ScaledStackCallPause_0049c360. If bit 2 of 0x54208c
 *     set, tail-call CallSetPause_0041f830. Else does two Mul10Tail
 *     calls multiplying g_currentNodeFlags / 00542088 by 0x3333 (interp
 *     factor) then stores results back. Writes them into [esi+0x6c]
 *     and [esi+0x74], writes g_currentNodeIdx → g_fightGroupHead, sets
 *     [g_baseSel_00542060*4+0x5c]=0x30, pushes 0x4f2650 → ArgSar_Set0_Jmp_0049c6f0.
 *   2b NOP pad.
 *   Entry 4 (offset 0xf0, 40b): Vec2SumMul10ChainCompute_0049bc60 → on no-error compare
 *     g_eventQueueCurrent vs g_eventQueueWorkType: if le tail-jmp Phase1ChainSetupCallScale6_0040ca70,
 *     else tail-jmp ScaledIndirectJmp_0049c850.
 *   8b NOP pad.
 *   Entry 5 (offset 0x150, 34b): Phase1ContextSetupHelper_0040c260 + BootCallChainDoubleMul10_0040b890;
 *     on no-error tail-jmps Triple3PathDispatch_0049bf90.
 */
extern unsigned int g_data_004f25d8;
extern unsigned int g_data_004f2640;
extern unsigned int g_data_004f2650;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformDirtyFlags;
extern void ArgSarStoreJmp_004594f0(void);
extern void ArgSar_Set0_Jmp_0049c6f0(void);
extern void BootCallChainDoubleMul10_0040b890(void);
extern void CallSetPause_0041f830(void);
extern void CondPickDualStore_0049c670(void);
extern void DualCmpSwapStore_0049c5a0(void);
extern void MStackCall_00406740(void);
extern void Phase1ChainSetupCallScale6_0040ca70(void);
extern void Phase1ContextSetupHelper_0040c260(void);
extern void ScaledIndirectJmp_0049c850(void);
extern void ScaledStackCallPause_0049c360(void);
extern void Triple3PathDispatch_0049bf90(void);
extern void Vec2SumMul10ChainCompute_0049bc60(void);

__declspec(naked) void Alarm5EntryScopedChain_0049be10(void) {
    __asm {
        call    MStackCall_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a5e_e1End
        jmp     CallSetPause_0041f830
    L_a5e_e1End:
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
        nop
        nop
        /* entry 2 (offset 0x20) */
    L_a5e_entry2:
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x305
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    CondPickDualStore_0049c670
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a5e_e2End
        push    offset g_data_004f25d8
        call    ArgSarStoreJmp_004594f0
        add     esp, 4
    L_a5e_e2End:
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
        nop
        nop
        nop
        /* entry 3 (offset 0x60) */
    L_a5e_entry3:
        push    esi
        call    DualCmpSwapStore_0049c5a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_a5e_e3End
        push    offset g_data_004f2640
        call    ScaledStackCallPause_0049c360
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     L_a5e_e3End
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_a5e_doInterp
        call    CallSetPause_0041f830
        pop     esi
        ret
    L_a5e_doInterp:
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     eax, dword ptr [g_currentNodeIdx]
        push    ecx
        push    0x3333
        lea     esi, [eax*4]
        call    Mul10Tail_00404af0
        mov     edx, dword ptr [g_xformScratch2088]
        add     esp, 8
        mov     dword ptr [g_currentNodeFlags], eax
        push    edx
        push    0x3333
        call    Mul10Tail_00404af0
        mov     dword ptr [g_xformScratch2088], eax
        mov     eax, dword ptr [g_currentNodeFlags]
        mov     dword ptr [esi + 0x6c], eax
        mov     ecx, dword ptr [g_xformScratch2088]
        add     esp, 8
        mov     dword ptr [esi + 0x74], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, 0x30
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_walkCallback], eax
        push    offset g_data_004f2650
        mov     dword ptr [ecx*4 + 0x5c], eax
        call    ArgSar_Set0_Jmp_0049c6f0
        add     esp, 4
    L_a5e_e3End:
        pop     esi
        ret
        nop
        nop
        /* entry 4 (offset 0xf0) */
    L_a5e_entry4:
        call    Vec2SumMul10ChainCompute_0049bc60
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a5e_e4End
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_eventQueueWorkType]
        cmp     eax, ecx
        jle     short L_a5e_e4tail2
        jmp     ScaledIndirectJmp_0049c850
    L_a5e_e4tail2:
        jmp     Phase1ChainSetupCallScale6_0040ca70
    L_a5e_e4End:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 5 (offset 0x150) */
    L_a5e_entry5:
        call    Phase1ContextSetupHelper_0040c260
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a5e_e5End
        call    BootCallChainDoubleMul10_0040b890
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a5e_e5End
        jmp     Triple3PathDispatch_0049bf90
    L_a5e_e5End:
        ret
    }
}
