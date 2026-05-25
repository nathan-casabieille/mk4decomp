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
extern unsigned int g_dualBitGate_0053a7b0;
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

extern unsigned int g_data_004d5d38;
extern unsigned int g_data_004d6748;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_data_00543800;
extern void AudioMixerStep_004ab700(void);
extern void CallSetPause_0041f830(void);
extern void ChainListVecAdd_0049d200(void);
extern void ClampMulShiftStore_004ba0e0(void);
extern void CmpDivJmp_0049d080(void);
extern void MStackPushSet9Jmp_00413040(void);
extern void PoseTreeBlendWalker_0049d680(void);
extern void PushStackCallPauseSet0xa_00413070(void);
extern void ScaledStoreThree_00409260(void);
extern void ZeroAndDirty4_00405430(void);

__declspec(naked) void Phase4FivePackedHelpers_00412cb0(void)
{
    __asm {
        push    0x8B
        push    0x00412CD0
        call    StoreTwoCall_0049cb40
        add     esp, 8
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
    L_p4fph_B:
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_p4fph_B_phase0
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4fph_B_call
        call    CallSetPause_0041f830
        pop     esi
        ret
    L_p4fph_B_phase0:
        mov     dword ptr [g_eventQueueIdx], 0x22
    L_p4fph_B_call:
        mov     dword ptr [g_walkCallback], 0x3333
        call    AudioMixerStep_004ab700
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_B_exit
        add     dword ptr [g_walkCallback], 0xD999
        call    ZeroAndDirty4_00405430
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_B_exit
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4fph_B_skip_call
        call    PushStackCallPauseSet0xa_00413070
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_B_exit
    L_p4fph_B_skip_call:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412CD0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p4fph_B_exit:
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
        nop
        nop
    L_p4fph_C:
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4fph_C_phase0
        dec     eax
        je      L_p4fph_C_phase1
        dec     eax
        mov     eax, dword ptr [g_eventQueueIdx]
        je      L_p4fph_C_phase2
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4fph_C_phase3_call
        call    CallSetPause_0041f830
        pop     esi
        ret
    L_p4fph_C_phase2:
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4fph_C_phase2_dec
        mov     dword ptr [g_eventQueueIdx], 0x28
    L_p4fph_C_phase3_call:
        call    PushStackCallPauseSet0xa_00413070
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        call    MStackPushSet9Jmp_00413040
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412D80
        mov     dword ptr [esi + 0x84], 3
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    L_p4fph_C_phase1:
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4fph_C_phase1_call
        mov     dword ptr [g_eventQueueIdx], 6
    L_p4fph_C_phase2_dec:
        call    PushStackCallPauseSet0xa_00413070
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        call    MStackPushSet9Jmp_00413040
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        mov     eax, 2
        mov     dword ptr [esi + 8], 0x00412D80
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_p4fph_C_phase0:
        mov     dword ptr [g_eventQueueIdx], 5
    L_p4fph_C_phase1_call:
        call    PushStackCallPauseSet0xa_00413070
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        call    MStackPushSet9Jmp_00413040
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_C_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412D80
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 3
        mov     dword ptr [g_framePauseFlag], eax
    L_p4fph_C_exit:
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
    L_p4fph_D:
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_p4fph_D_phase0
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4fph_D_call
        call    CallSetPause_0041f830
        pop     esi
        ret
    L_p4fph_D_phase0:
        mov     dword ptr [g_eventQueueIdx], 3
    L_p4fph_D_call:
        call    PushStackCallPauseSet0xa_00413070
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_D_exit
        mov     eax, dword ptr [g_currentNodeIdx]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      L_p4fph_D_install_self
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, offset g_data_004d6748
        shr     eax, 2
        mov     dword ptr [ecx*4 + 0x48], 0x4CCC
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [edx*4 + 0x10], 0x00412FF0
        mov     dword ptr [g_walkCallback], eax
        call    ScaledStoreThree_00409260
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_D_exit
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [ecx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x20]
        or      ecx, 0x40
        mov     dword ptr [eax*4 + 0x20], ecx
        mov     dword ptr [g_walkCallback], 0x64
        call    CmpDivJmp_0049d080
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_D_exit
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4fph_D_install_self
        mov     edx, offset g_data_004d5d38
        shr     edx, 2
        mov     dword ptr [g_xformEntityIdx], edx
        call    PoseTreeBlendWalker_0049d680
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_D_exit
    L_p4fph_D_install_self:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00412EC0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 4
        mov     dword ptr [g_framePauseFlag], eax
    L_p4fph_D_exit:
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
    L_p4fph_E:
        mov     eax, dword ptr [g_data_00543800]
        test    eax, eax
        jne     L_p4fph_E_tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], 0xFFFFFDB3
        mov     eax, dword ptr [ecx*4 + 0x48]
        sub     eax, 0x24D
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        call    ChainListVecAdd_0049d200
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4fph_E_ret
    L_p4fph_E_tail:
        jmp     ClampMulShiftStore_004ba0e0
    L_p4fph_E_ret:
        ret
    }
}
