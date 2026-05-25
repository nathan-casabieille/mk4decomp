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
extern unsigned int g_data_0053a180;
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
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern unsigned int g_data_004d77b0;
extern unsigned int g_data_0052aac4;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_baseSel_00542060;
extern void CallPauseInc_004ab670(void);
extern void CallSetPause_0041f830(void);
extern void ChainNodeAdvanceCallback_00408e70(void);
extern void DirtyDoubleDeref_00408cb0(void);
extern void FramePauseScaledStore_00406c10(void);
extern void GuardedSelfRefSet_0048d070(void);
extern void MStackPushCallCallPop_00405e20(void);
extern void PushPopScaled1cDoubleCall_00408510(void);
extern void ScaledStoreThree_00409260(void);
extern void ScaledTestPauseStore_00408860(void);
extern void SetJmp_00405420(void);
extern void StoreDoubleNegPauseSubStore_004ab750(void);
extern void StorePauseImulShr16_004ab630(void);
extern void Wrapper_0048a260(void);

__declspec(naked) void Phase4TrampolineMainHelpers_00414b90(void)
{
    __asm {
        push    0xB1
        push    0x00414BB0
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
    L_p4tmh2_M:
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4tmh2_M_phase0
        dec     eax
        je      L_p4tmh2_M_phase1_alt
        call    SetJmp_00405420
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_M_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4tmh2_M_call_4ab670
        push    0xB2
        push    0x00414CF0
        call    StoreTwoCall_0049cb40
        mov     eax, dword ptr [g_eventQueueEnd]
        add     esp, 8
        dec     eax
        mov     dword ptr [g_eventQueueEnd], eax
        jns     L_p4tmh2_M_call_4ab670
    L_p4tmh2_M_phase1_alt:
        cmp     dword ptr [g_data_0052aac4], 4
        jne     L_p4tmh2_M_set_54_4
        call    Wrapper_0048a260
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_M_ret
    L_p4tmh2_M_set_54_4:
        mov     dword ptr [g_eventQueueEnd], 4
    L_p4tmh2_M_call_4ab670:
        mov     dword ptr [g_walkCallback], 0x0C
        call    CallPauseInc_004ab670
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_M_ret
        mov     eax, dword ptr [g_walkCallback]
        add     eax, 6
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [esi + 8], 0x00414BB0
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_p4tmh2_M_phase0:
        mov     dword ptr [esi + 8], 0x00414BB0
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     edx, 0x00414BB0
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     edx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x84], 0
        call    GuardedSelfRefSet_0048d070
        mov     dword ptr [g_framePauseFlag], 1
    L_p4tmh2_M_ret:
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
    L_p4tmh2_H:
        mov     eax, dword ptr [g_baseSel_00542060]
        push    edi
        lea     edi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [edi + 0x84], 0
        test    eax, eax
        je      L_p4tmh2_H_phase0
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    ChainNodeAdvanceCallback_00408e70
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_H_pop_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      L_p4tmh2_H_tailjmp
        jmp     L_p4tmh2_H_install
    L_p4tmh2_H_phase0:
        mov     dword ptr [g_walkCallback], 0x0A
        call    StorePauseImulShr16_004ab630
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_H_pop_ret
        mov     eax, dword ptr [g_walkCallback]
        lea     ecx, [eax + eax*4]
        mov     eax, offset g_data_004d77b0
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [eax*4]
        sar     edx, 2
        and     edx, 0x003FFFFF
        mov     dword ptr [g_xformEntityIdx], edx
        call    FramePauseScaledStore_00406c10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_H_pop_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4tmh2_H_tailjmp
        call    ScaledTestPauseStore_00408860
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_H_pop_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4tmh2_H_call_5e20
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     ecx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        call    ScaledStoreThree_00409260
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_H_pop_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [edx*4 + 0x1C], 0
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     eax, dword ptr [g_eventQueueTotal]
        inc     eax
        mov     dword ptr [g_eventQueueTotal], eax
        mov     edx, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], edx
        call    StoreDoubleNegPauseSubStore_004ab750
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_H_pop_ret
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x30], eax
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     edx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_eventQueueTotal], eax
        call    StoreDoubleNegPauseSubStore_004ab750
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_H_pop_ret
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x38], eax
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x004BA0E0
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x10], eax
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x48]
        or      al, 8
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4]
        mov     eax, 0xFF
        mov     dword ptr [edx*4 + 0x48], ecx
        mov     edx, dword ptr [g_eventQueueTotal]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     edx
        mov     dword ptr [g_eventQueueTotal], edx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x14], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_eventQueueTotal]
        mov     dword ptr [g_eventQueueIdx], edx
        mov     ecx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        call    DirtyDoubleDeref_00408cb0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_H_pop_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_currentNodeIdx], eax
        call    PushPopScaled1cDoubleCall_00408510
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_H_pop_ret
    L_p4tmh2_H_install:
        mov     eax, 1
        mov     dword ptr [edi + 8], 0x00414CF0
        mov     dword ptr [edi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     edi
        ret
    L_p4tmh2_H_call_5e20:
        call    MStackPushCallCallPop_00405e20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_H_pop_ret
    L_p4tmh2_H_tailjmp:
        call    CallSetPause_0041f830
    L_p4tmh2_H_pop_ret:
        pop     edi
        ret
        nop
        nop
    L_p4tmh2_S:
        call    MStackPushCallCallPop_00405e20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh2_S_ret
        mov     dword ptr [g_currentNodeIdx], 0
    L_p4tmh2_S_ret:
        ret
    }
}
