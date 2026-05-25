/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_state_0053a718;
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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_const_004d2b88;
extern unsigned int g_data_004d2b60;
extern unsigned int g_data_004d2b7c;
extern unsigned int g_data_00522998;
extern unsigned int g_data_00522bb0;
extern unsigned int g_byte_00522bb4;
extern unsigned int g_iat_004d2058;
extern unsigned int g_iat_004d212c;
extern void FPUPrecisionCheck_004c8400(void);
extern void IsCType_004cc650(void);
extern void SevenArgThenTwoArg_004ccd20(void);
extern void SevenArgThenTwoArg_004ccd60(void);
extern void TolowerLocale_004cc6f0(void);

__declspec(naked) void LocaleNumericHelpers_004c8450(void)
{
    __asm {
        /* Helper 1: __setusermatherr early-init guard. */
        push     OFFSET g_data_004d2b7c
        call     dword ptr [g_iat_004d212c]
        test     eax, eax
        je       short L_8474
        push     OFFSET g_data_004d2b60
        push     eax
        call     dword ptr [g_iat_004d2058]
        test     eax, eax
        je       short L_8474
        push     0
        call     eax
        ret
    L_8474:
        jmp      FPUPrecisionCheck_004c8400
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* Helper 2: scan-and-swap. */
        push     esi
        mov      esi, dword ptr [esp + 8]
        movsx    eax, byte ptr [esi]
        push     eax
        call     TolowerLocale_004cc6f0
        add      esp, 4
        cmp      eax, 0x65
        je       short L_84c3
    L_8496:
        mov      eax, dword ptr [g_data_00522bb0]
        inc      esi
        cmp      eax, 1
        jle      short L_84b1
        movsx    ecx, byte ptr [esi]
        push     4
        push     ecx
        call     IsCType_004cc650
        add      esp, 8
        jmp      short L_84bf
    L_84b1:
        movsx    edx, byte ptr [esi]
        mov      eax, dword ptr [g_data_00522998]
        mov      al, byte ptr [eax + edx*2]
        and      eax, 4
    L_84bf:
        test     eax, eax
        jne      short L_8496
    L_84c3:
        mov      cl, byte ptr [g_byte_00522bb4]
        mov      al, byte ptr [esi]
        mov      byte ptr [esi], cl
        inc      esi
    L_84ce:
        mov      cl, byte ptr [esi]
        mov      byte ptr [esi], al
        mov      dl, byte ptr [esi]
        inc      esi
        test     dl, dl
        mov      al, cl
        jne      short L_84ce
        pop      esi
        ret
        nop
        nop
        nop
        /* Helper 3: strip_locale_decimal_zeros. */
        mov      eax, dword ptr [esp + 4]
        push     ebx
        mov      bl, byte ptr [g_byte_00522bb4]
        mov      cl, byte ptr [eax]
        test     cl, cl
        je       short L_84fd
    L_84f1:
        cmp      cl, bl
        je       short L_84fd
        mov      cl, byte ptr [eax + 1]
        inc      eax
        test     cl, cl
        jne      short L_84f1
    L_84fd:
        mov      cl, byte ptr [eax]
        inc      eax
        test     cl, cl
        je       short L_8549
        mov      cl, byte ptr [eax]
        test     cl, cl
        je       short L_851c
    L_850a:
        cmp      cl, 0x65
        je       short L_851c
        cmp      cl, 0x45
        je       short L_851c
        mov      cl, byte ptr [eax + 1]
        inc      eax
        test     cl, cl
        jne      short L_850a
    L_851c:
        mov      cl, byte ptr [eax - 1]
        mov      edx, eax
        dec      eax
        cmp      cl, 0x30
        jne      short L_8530
    L_8527:
        mov      cl, byte ptr [eax - 1]
        dec      eax
        cmp      cl, 0x30
        je       short L_8527
    L_8530:
        cmp      byte ptr [eax], bl
        jne      short L_8535
        dec      eax
    L_8535:
        mov      cl, byte ptr [edx]
        inc      eax
        inc      edx
        test     cl, cl
        mov      byte ptr [eax], cl
        je       short L_8549
    L_853f:
        mov      cl, byte ptr [edx]
        inc      eax
        inc      edx
        test     cl, cl
        mov      byte ptr [eax], cl
        jne      short L_853f
    L_8549:
        pop      ebx
        ret
        nop
        nop
        nop
        nop
        nop
        /* Helper 4: __isnan-ish double-vs-0 check. */
        mov      eax, dword ptr [esp + 4]
        fld      qword ptr [eax]
        fcomp    qword ptr [g_const_004d2b88]
        fnstsw   ax
        test     ah, 1
        jne      short L_8569
        mov      eax, 1
        ret
    L_8569:
        xor      eax, eax
        ret
        nop
        nop
        nop
        nop
        /* Helper 5: 2-dword writeback via SevenArgThenTwoArg_004ccd20. */
        mov      eax, dword ptr [esp + 4]
        sub      esp, 8
        test     eax, eax
        je       short L_85a2
        mov      eax, dword ptr [esp + 0x14]
        /* MASM emits 3-byte `8d 0c 24` for lea ecx, [esp]; orig uses
         * the 4-byte disp8=0 form `8d 4c 24 00` here. */
        _emit    0x8d
        _emit    0x4c
        _emit    0x24
        _emit    0x00
        push     eax
        push     ecx
        call     SevenArgThenTwoArg_004ccd20
        mov      eax, dword ptr [esp + 0x18]
        mov      edx, dword ptr [esp + 8]
        mov      ecx, dword ptr [esp + 0xc]
        add      esp, 8
        mov      dword ptr [eax], edx
        mov      dword ptr [eax + 4], ecx
        add      esp, 8
        ret
        /* Helper 6: 1-dword writeback via SevenArgThenTwoArg_004ccd60. */
    L_85a2:
        mov      edx, dword ptr [esp + 0x14]
        lea      eax, [esp + 0x14]
        push     edx
        push     eax
        call     SevenArgThenTwoArg_004ccd60
        mov      ecx, dword ptr [esp + 0x18]
        mov      edx, dword ptr [esp + 0x1c]
        add      esp, 8
        mov      dword ptr [ecx], edx
        add      esp, 8
        ret
    }
}
