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

extern unsigned int g_pendingMatchVar_004d5324;
extern unsigned int g_data_004d7878;
extern unsigned int g_data_004d78b8;
extern unsigned int g_savedNode_00541f98;
extern void AudioMixerStep_004ab700(void);
extern void CallSetPause_0041f830(void);
extern void ChainListVecAdd_0049d200(void);
extern void ClampMulShiftStore_004ba0e0(void);
extern void CmpDivJmp_0049d080(void);
extern void LoopUnrolledTripleMul10_0049d550(void);
extern void MStackCall_004065b0(void);
extern void MStackPush1MagicMod2_004244d0(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void ScaledTripleCopy10_0049d340(void);
extern void SetJmp_00405420(void);
extern void SetJmp_00408d20(void);

__declspec(naked) void Phase4TrampolineMainHelper_00415180(void)
{
    __asm {
        push    0xB3
        push    0x004151C0
        call    StoreTwoCall_0049cb40
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_currentNodeIdx]
        shl     ecx, 2
        shl     eax, 2
        mov     edx, dword ptr [ecx + 0x54]
        add     esp, 8
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x30], edx
        mov     ecx, dword ptr [ecx + 0x5C]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x34], ecx
        ret
        nop
        nop
        nop
        nop
    L_p4tmh_M:
        mov     eax, offset g_data_004d7878
        push    esi
        shr     eax, 2
        push    edi
        mov     dword ptr [g_walkCallback], eax
        call    PushSetXfmMaskCallPop_00407140
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4tmh_M_tailjmp
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0xA2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        call    SetJmp_00408d20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     esi, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [g_xformEntityIdx]
        lea     ecx, [edx*4]
        mov     edx, dword ptr [g_fightGroupHead]
        lea     edi, [esi*4]
        mov     esi, dword ptr [ecx + 0x20]
        or      esi, 0x00004000
        shl     eax, 2
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [ecx + 0x20], esi
        mov     esi, dword ptr [eax]
        mov     dword ptr [eax + 0x48], 0x4CCC
        or      esi, 0x0A
        mov     dword ptr [eax + 0x14], 0xFF
        mov     dword ptr [eax], esi
        mov     esi, 0x9999
        mov     dword ptr [eax + 0x30], 0x12
        mov     dword ptr [eax + 0x10], 0x00415440
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [eax + 0x2C], esi
        mov     eax, dword ptr [edi + 0x30]
        shl     edx, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx + 0x54], eax
        mov     eax, dword ptr [edi + 0x34]
        mov     dword ptr [edx + 0x5C], eax
        mov     dword ptr [edx + 0x58], 0
        mov     eax, 0x0F
        mov     dword ptr [ecx + 0x3C], 0xC000
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], eax
        call    CmpDivJmp_0049d080
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4tmh_M_call_4065b0
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_savedNode_00541f98]
        mov     eax, dword ptr [g_pendingMatchVar_004d5324]
        dec     ecx
        mov     dword ptr [g_xformLoopCounter], ecx
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_walkCallback], eax
        call    AudioMixerStep_004ab700
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        mov     eax, dword ptr [g_xformLoopCounter]
        mov     ecx, dword ptr [g_walkCallback]
        test    eax, eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        jl      L_p4tmh_M_call_4065b0
        mov     esi, 0x2666
    L_p4tmh_M_loop_top:
        mov     dword ptr [g_walkCallback], esi
        call    AudioMixerStep_004ab700
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueWorkType]
        add     eax, esi
        add     ecx, 0x10000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_acc_00542078], eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        call    MStackPush1MagicMod2_004244d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        mov     edx, dword ptr [g_walkCallback]
        mov     eax, dword ptr [g_acc_00542078]
        push    edx
        push    eax
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [ecx*4], eax
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     eax, dword ptr [g_acc_00542078]
        push    edx
        push    eax
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_eventQueueCurrent], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 8], eax
        mov     edx, dword ptr [g_acc_00542078]
        push    edx
        push    0xFFFFFAE2
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_xformEntityIdx]
        add     esp, 8
        mov     dword ptr [g_acc_00542078], eax
        mov     dword ptr [ecx*4 + 4], eax
        call    ScaledTripleCopy10_0049d340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [g_xformLoopCounter]
        dec     eax
        mov     dword ptr [g_xformLoopCounter], eax
        jns     L_p4tmh_M_loop_top
    L_p4tmh_M_call_4065b0:
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], ecx
        call    MStackCall_004065b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_M_ret
    L_p4tmh_M_tailjmp:
        call    CallSetPause_0041f830
    L_p4tmh_M_ret:
        pop     edi
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4tmh_H:
        call    ClampMulShiftStore_004ba0e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_H_ret
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4tmh_H_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [eax*4 + 0x2C]
        push    eax
        push    0xE666
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x2C], eax
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x30]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     L_p4tmh_H_dec
        mov     eax, dword ptr [ecx*4 + 0x14]
        sub     eax, 0x0C
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x14], eax
        call    SetJmp_00405420
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_H_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4tmh_H_after
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], 0x28F
        mov     eax, dword ptr [ecx*4 + 0x48]
        add     eax, 0x28F
        cmp     eax, 0x7333
        mov     dword ptr [g_walkCallback], eax
        jle     L_p4tmh_H_no_cap
        mov     eax, 0x7333
        mov     dword ptr [g_walkCallback], eax
    L_p4tmh_H_no_cap:
        mov     dword ptr [ecx*4 + 0x48], eax
        jmp     L_p4tmh_H_after
    L_p4tmh_H_dec:
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
    L_p4tmh_H_after:
        call    ChainListVecAdd_0049d200
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_H_ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, offset g_data_004d78b8
        mov     eax, dword ptr [edx*4 + 0x2C]
        shr     ecx, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        call    LoopUnrolledTripleMul10_0049d550
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4tmh_H_ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
    L_p4tmh_H_ret:
        ret
    }
}
