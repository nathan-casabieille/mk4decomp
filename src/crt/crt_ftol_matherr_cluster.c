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

extern unsigned int g_const_004d2c00;
extern unsigned int g_const_004d2c08;
extern unsigned int g_const_004d2c10;
extern unsigned int g_const_004d2c18;
extern unsigned int g_const_004d2c20;
extern unsigned int g_const_004d2c28;
extern unsigned int g_crtFpuExceptionMask_00522e50;
extern unsigned int g_data_00f9f7f8;
extern void Crt_fpieee_flt_004cdd20(void);
extern void FpExceptionFilter_004ca080(void);
extern void func_004ca0e7(void);

__declspec(naked) void CrtFtolMatherrCluster_004ca700(void)
{
    __asm {
        /* === Helper 1 (0x4ca700): 2-arg matherr-trigger via fxch === */
        push     ebp
        mov      ebp, esp
        add      esp, 0xfffffd30
        push     ebx
        wait
        fnstcw   word ptr [ebp - 0xa4]
        wait
        cmp      dword ptr [g_crtFpuExceptionMask_00522e50], 0
        je       short L_a72f
    L_a71b:
        call     func_004ca0e7
        or       byte ptr [ebp - 0x2c8], 3
        call     L_a7ca
        pop      ebx
        leave
        ret
    L_a72f:
        fxch     st(1)
        fst      qword ptr [ebp - 0x86]
        fxch     st(1)
        fst      qword ptr [ebp - 0x7e]
        jmp      short L_a71b
        /* === Helper 2: 1-arg matherr === */
        push     ebp
        mov      ebp, esp
        add      esp, 0xfffffd30
        push     ebx
        wait
        fnstcw   word ptr [ebp - 0xa4]
        cmp      dword ptr [g_crtFpuExceptionMask_00522e50], 0
        je       short L_a773
    L_a758:
        call     FpExceptionFilter_004ca080
        or       byte ptr [ebp - 0x2c8], 1
        and      byte ptr [ebp - 0x2c8], 0xfd
        call     L_a7ca
        pop      ebx
        leave
        ret
    L_a773:
        fst      qword ptr [ebp - 0x86]
        jmp      short L_a758
        /* === Helper 3: 4-arg matherr === */
        push     ebp
        mov      ebp, esp
        add      esp, 0xfffffd30
        push     ebx
        push     dword ptr [ebp + 0xc]
        push     dword ptr [ebp + 8]
        call     L_a92e
        add      esp, 8
        push     dword ptr [ebp + 0x14]
        push     dword ptr [ebp + 0x10]
        call     L_a92e
        add      esp, 8
        wait
        fnstcw   word ptr [ebp - 0xa4]
        or       byte ptr [ebp - 0x2c8], 2
        mov      byte ptr [ebp - 0x8f], 1
        call     func_004ca0e7
        call     L_a7c3
        pop      ebx
        leave
        ret
    L_a7c3:
        and      byte ptr [ebp - 0x2c8], 0xfe
    L_a7ca:
        cmp      dword ptr [g_data_00f9f7f8], 0
        jne      short L_a81f
        fst      qword ptr [ebp - 0x2d0]
        mov      al, byte ptr [ebp - 0x90]
        or       al, al
        je       short L_a7fd
        cmp      al, 0xff
        je       short L_a827
        cmp      al, 0xfe
        je       short L_a827
        or       al, al
        je       short L_a81f
        movsx    eax, al
        mov      dword ptr [ebp - 0x8e], eax
        jmp      L_a899
    L_a7fd:
        mov      ax, word ptr [ebp - 0xa4]
        /* force `and ax, imm8` sign-extended form (per feedback) */
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        jne      short L_a81f
        wait
        fnstsw   ax
        _emit    0x66
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        je       short L_a81f
        mov      dword ptr [ebp - 0x8e], 8
        jmp      short L_a899
    L_a81f:
        fldcw    word ptr [ebp - 0xa4]
        wait
        ret
    L_a827:
        mov      ax, word ptr [ebp - 0x2ca]
        and      ax, 0x7ff0
        or       ax, ax
        je       short L_a83f
        cmp      ax, 0x7ff0
        je       short L_a86d
        jmp      short L_a7fd
    L_a83f:
        mov      dword ptr [ebp - 0x8e], 4
        fld      qword ptr [g_const_004d2c18]
        fxch     st(1)
        fscale
        fstp     st(1)
        fld      st(0)
        fabs
        fcomp    qword ptr [g_const_004d2c08]
        wait
        fnstsw   ax
        sahf
        jae      short L_a899
        fmul     qword ptr [g_const_004d2c28]
        jmp      short L_a899
    L_a86d:
        mov      dword ptr [ebp - 0x8e], 3
        fld      qword ptr [g_const_004d2c10]
        fxch     st(1)
        fscale
        fstp     st(1)
        fld      st(0)
        fabs
        fcomp    qword ptr [g_const_004d2c00]
        wait
        fnstsw   ax
        sahf
        jbe      short L_a899
        fmul     qword ptr [g_const_004d2c20]
    L_a899:
        push     esi
        push     edi
        mov      ebx, dword ptr [ebp - 0x94]
        inc      ebx
        mov      dword ptr [ebp - 0x8a], ebx
        test     byte ptr [ebp - 0x2c8], 1
        jne      short L_a8cb
        cld
        lea      esi, [ebp + 8]
        lea      edi, [ebp - 0x86]
        movsd
        movsd
        cmp      byte ptr [ebx + 0xc], 1
        je       short L_a8cb
        lea      esi, [ebp + 0x10]
        lea      edi, [ebp - 0x7e]
        movsd
        movsd
    L_a8cb:
        fstp     qword ptr [ebp - 0x76]
        lea      eax, [ebp - 0x8e]
        lea      ebx, [ebp - 0xa4]
        push     ebx
        push     eax
        mov      ebx, dword ptr [ebp - 0x94]
        mov      al, byte ptr [ebx + 0xe]
        movsx    eax, al
        push     eax
        call     Crt_fpieee_flt_004cdd20
        add      esp, 0xc
        pop      edi
        pop      esi
        fld      qword ptr [ebp - 0x76]
        jmp      short L_a81f
        /* === Helper 4: 2-arg matherr (no fxch) === */
        push     ebp
        mov      ebp, esp
        add      esp, 0xfffffd30
        push     ebx
        push     dword ptr [ebp + 0xc]
        push     dword ptr [ebp + 8]
        call     L_a92e
        add      esp, 8
        wait
        fnstcw   word ptr [ebp - 0xa4]
        and      byte ptr [ebp - 0x2c8], 0xfd
        call     FpExceptionFilter_004ca080
        call     L_a7c3
        pop      ebx
        leave
        ret
    L_a92e:
        /* === Helper 5: denormal-handler (shifts into tbyte) === */
        push     ebp
        mov      ebp, esp
        add      esp, -0xc
        push     ebx
        mov      ax, word ptr [ebp + 0xe]
        mov      bx, ax
        and      ax, 0x7ff0
        cmp      ax, 0x7ff0
        jne      short L_a964
        or       bx, 0x7fff
        mov      word ptr [ebp - 2], bx
        mov      eax, dword ptr [ebp + 0xc]
        mov      ebx, dword ptr [ebp + 8]
        shld     eax, ebx, 0xb
        mov      dword ptr [ebp - 6], eax
        mov      dword ptr [ebp - 0xa], ebx
        fld      tbyte ptr [ebp - 0xa]
        jmp      short L_a967
    L_a964:
        fld      qword ptr [ebp + 8]
    L_a967:
        pop      ebx
        leave
        ret
        _emit    0xcc
        _emit    0xcc
        _emit    0xcc
        _emit    0xcc
        _emit    0xcc
        _emit    0xcc
    }
}
