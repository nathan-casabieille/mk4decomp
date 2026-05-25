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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* ------------------------------------------------------------------ */
/* CRT pow() helper cluster (544b boot/crt)                            */
/* ------------------------------------------------------------------ */
extern void TwinEntryFpHelper_004ca250(void);
extern void FloatTransientHelpers_004ca2b0(void);
extern void func_004ca2c5(void);
extern void func_004ca2f5(void);
extern void func_004ca34e(void);
extern void func_004ca399(void);
extern void CrtPowSpecialCases_004ca440(void);
extern unsigned int g_data_0051fff0;
extern unsigned int g_data_0051fff8;
extern unsigned int g_data_00522410;
extern unsigned int g_data_00522470;
extern unsigned int g_data_00f9f7f8;

__declspec(naked) void CrtPowCluster_004c6540(void)
{
    __asm {
        sub      esp, 0x10
        fxch     st(1)
        fstp     qword ptr [esp]
        fst      qword ptr [esp + 8]
        mov      eax, dword ptr [esp + 0xc]
        call     L_6562
        add      esp, 0x10
        ret
        lea      edx, [esp + 0xc]
        call     func_004ca2f5
    L_6562:
        mov      ecx, eax
        push     eax
        wait
        fnstcw   word ptr [esp]
        cmp      word ptr [esp], 0x27f
        je       short L_6576
        call     func_004ca2c5
    L_6576:
        and      ecx, 0x7ff00000
        lea      edx, [esp + 8]
        cmp      ecx, 0x7ff00000
        je       L_6629
        call     func_004ca2f5
        je       L_6625
        test     eax, 0x7ff00000
        je       L_6698
    L_65a2:
        mov      cl, byte ptr [esp + 0xf]
        and      cl, 0x80
        jne      L_6710
    L_65af:
        fyl2x
        call     FloatTransientHelpers_004ca2b0
        cmp      cl, 1
        jne      short L_65bd
        fchs
    L_65bd:
        cmp      dword ptr [g_data_00f9f7f8], 0
        jne      func_004ca34e
        lea      ecx, [g_data_0051fff8]
        mov      edx, 0x1d
        jmp      func_004ca399
    L_65da:
        cmp      dword ptr [g_data_00f9f7f8], 0
        jne      func_004ca34e
        lea      ecx, [g_data_0051fff8]
        mov      edx, 0x1d
        call     TwinEntryFpHelper_004ca250
        pop      edx
        ret
    L_65f9:
        lea      edx, [esp + 8]
        call     func_004ca2f5
        test     byte ptr [esp + 0x16], 8
        jne      short L_660c
        inc      ecx
        jmp      short L_663f
    L_660c:
        faddp    st(1), st
        mov      eax, 1
        jmp      L_65da
    L_6615:
        test     byte ptr [esp + 0xe], 8
        jne      short L_660c
    L_661c:
        faddp    st(1), st
        mov      eax, 7
        jmp      L_65da
    L_6625:
        xor      ecx, ecx
        jmp      short L_663f
    L_6629:
        xor      ecx, ecx
        and      eax, 0xfffff
        or       eax, dword ptr [esp + 0x10]
        jne      short L_65f9
        lea      edx, [esp + 8]
        call     func_004ca2f5
    L_663f:
        mov      eax, dword ptr [esp + 0xc]
        mov      edx, eax
        and      eax, 0x7ff00000
        and      edx, 0xfffff
        cmp      eax, 0x7ff00000
        jne      short L_665d
        or       edx, dword ptr [esp + 8]
        jne      short L_6615
    L_665d:
        test     ecx, ecx
        jne      short L_661c
        sub      esp, 0x74
        mov      ecx, esp
        push     ecx
        sub      esp, 0x10
        fstp     qword ptr [esp]
        fstp     qword ptr [esp + 8]
        wait
        fnsave   dword ptr [ecx + 8]
        call     CrtPowSpecialCases_004ca440
        add      esp, 0x10
        pop      ecx
        frstor   dword ptr [ecx + 8]
        fld      qword ptr [ecx]
        add      esp, 0x74
        test     eax, eax
        je       func_004ca34e
        mov      eax, 1
        jmp      L_65da
    L_6698:
        mov      eax, dword ptr [esp + 0xc]
        and      eax, 0xfffff
        or       eax, dword ptr [esp + 8]
        jne      L_65a2
        fstp     st(0)
        mov      eax, dword ptr [esp + 0x14]
        test     eax, 0x7ff00000
        je       short L_66f5
        call     L_6735
        mov      ch, byte ptr [esp + 0xf]
        shr      ch, 7
        test     dword ptr [esp + 0x17], 0x80
        je       short L_66e4
        fld      tbyte ptr [g_data_00522410]
        test     cl, ch
        je       short L_66da
        fchs
    L_66da:
        mov      eax, 2
        jmp      L_65da
    L_66e4:
        fldz
        test     cl, ch
        je       func_004ca34e
        fchs
        jmp      func_004ca34e
    L_66f5:
        fstp     st(0)
        and      eax, 0xfffff
        or       eax, dword ptr [esp + 0x10]
        jne      short L_6709
        fld1
        jmp      func_004ca34e
    L_6709:
        fldz
        jmp      func_004ca34e
    L_6710:
        fld      st(1)
        call     L_6735
        fchs
        test     cl, cl
        jne      L_65af
        fstp     st(0)
        fstp     st(0)
        fld      tbyte ptr [g_data_00522470]
        mov      eax, 1
        jmp      L_65da
    L_6735:
        fld      st(0)
        frndint
        fcomp    st(1)
        mov      cl, 0
        wait
        fnstsw   ax
        sahf
        jne      short L_675a
        fmul     qword ptr [g_data_0051fff0]
        inc      cl
        fld      st(0)
        frndint
        fcompp
        wait
        fnstsw   ax
        sahf
        jne      short L_6759
        inc      cl
    L_6759:
        ret
    L_675a:
        fstp     st(0)
        ret
        _emit    0xcc
        _emit    0xcc
        _emit    0xcc
    }
}
