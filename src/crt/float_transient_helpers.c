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

extern unsigned int g_const_004d2ba0;
extern unsigned int g_const_004d2bb4;
extern unsigned int g_const_004d2bbc;
extern unsigned int g_const_004d2bc4;
extern unsigned int g_const_004d2bcc;
extern unsigned int g_const_004d2bd4;
extern unsigned int g_const_004d2bdc;
extern void TwinEntryFpHelper_004ca250(void);
extern void func_004ca267(void);

__declspec(naked) void FloatTransientHelpers_004ca2b0(void)
{
    __asm {
        /* H1: __2_to_x */
        fld      st(0)
        frndint
        fsubr    st(1), st(0)
        fxch     st(1)
        fchs
        f2xm1
        fld1
        faddp    st(1), st
        fscale
        fstp     st(1)
        ret
        /* H2: __set_fpcw_precision */
        mov      edx, dword ptr [esp + 4]
        and      edx, 0x300
        or       edx, 0x7f
        mov      word ptr [esp + 6], dx
        fldcw    word ptr [esp + 6]
        ret
        /* H3: denormal-input classifier */
        test     eax, 0x80000
        je       short L_a2e9
        mov      eax, 7
        ret
    L_a2e9:
        fadd     qword ptr [g_const_004d2ba0]
        mov      eax, 1
        ret
        /* H4: __extract_unbiased_exp_xword */
        mov      eax, dword ptr [edx + 4]
        and      eax, 0x7ff00000
        cmp      eax, 0x7ff00000
        je       short L_a307
        fld      qword ptr [edx]
        ret
    L_a307:
        mov      eax, dword ptr [edx + 4]
        sub      esp, 0xa
        or       eax, 0x7fff0000
        mov      dword ptr [esp + 6], eax
        mov      eax, dword ptr [edx + 4]
        mov      ecx, dword ptr [edx]
        shld     eax, ecx, 0xb
        shl      ecx, 0xb
        mov      dword ptr [esp + 4], eax
        mov      dword ptr [esp], ecx
        fld      tbyte ptr [esp]
        add      esp, 0xa
        test     eax, 0
        mov      eax, dword ptr [edx + 4]
        ret
        /* H5: nan-passthrough probe */
        mov      eax, dword ptr [esp + 8]
        and      eax, 0x7ff00000
        cmp      eax, 0x7ff00000
        je       short L_a349
        ret
    L_a349:
        mov      eax, dword ptr [esp + 8]
        ret
        /* H6: conditional fldcw restore */
        cmp      word ptr [esp], 0x27f
        je       short L_a359
        fldcw    word ptr [esp]
    L_a359:
        pop      edx
        ret
        /* H7: fldcw + status check */
        mov      ax, word ptr [esp]
        cmp      ax, 0x27f
        je       short L_a383
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        je       short L_a380
        wait
        fnstsw   ax
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        je       short L_a380
        mov      eax, 8
        call     func_004ca267
        pop      edx
        ret
    L_a380:
        fldcw    word ptr [esp]
    L_a383:
        pop      edx
        ret
        /* H8: inf/nan check path A */
        sub      esp, 8
        fst      qword ptr [esp]
        mov      eax, dword ptr [esp + 4]
        add      esp, 8
        and      eax, 0x7ff00000
        jmp      short L_a3ad
        /* H9: inf/nan check path B + recovery */
        sub      esp, 8
        fst      qword ptr [esp]
        mov      eax, dword ptr [esp + 4]
        add      esp, 8
        and      eax, 0x7ff00000
        je       short L_a3ea
    L_a3ad:
        cmp      eax, 0x7ff00000
        je       short L_a413
        mov      ax, word ptr [esp]
        cmp      ax, 0x27f
        je       short L_a3e8
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        jne      short L_a3e5
        wait
        fnstsw   ax
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        je       short L_a3e5
        mov      eax, 8
    L_a3d2:
        cmp      edx, 0x1d
        je       short L_a3de
        call     func_004ca267
        pop      edx
        ret
    L_a3de:
        call     TwinEntryFpHelper_004ca250
        pop      edx
        ret
    L_a3e5:
        fldcw    word ptr [esp]
    L_a3e8:
        pop      edx
        ret
    L_a3ea:
        fld      qword ptr [g_const_004d2bcc]
        fxch     st(1)
        fscale
        fstp     st(1)
        fld      st(0)
        fabs
        fcomp    qword ptr [g_const_004d2bbc]
        wait
        fnstsw   ax
        sahf
        mov      eax, 4
        jae      short L_a3d2
        fmul     qword ptr [g_const_004d2bdc]
        jmp      short L_a3d2
    L_a413:
        fld      qword ptr [g_const_004d2bc4]
        fxch     st(1)
        fscale
        fstp     st(1)
        fld      st(0)
        fabs
        fcomp    qword ptr [g_const_004d2bb4]
        wait
        fnstsw   ax
        sahf
        mov      eax, 3
        jbe      short L_a3d2
        fmul     qword ptr [g_const_004d2bd4]
        jmp      short L_a3d2
        int      3
        int      3
        int      3
        int      3
    }
}
