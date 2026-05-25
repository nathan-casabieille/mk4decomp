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

extern unsigned int g_data_00522470;
extern unsigned int g_data_00522484;
extern unsigned int g_data_0052248c;

__declspec(naked) void FpExceptionFilter_004ca080(void)
{
    __asm {
    /* Entry A: single-operand */
        cmp      byte ptr [edx + 0xe], 5
        jne      short L_a097
        mov      bx, word ptr [ebp - 0xa4]
        or       bh, 2
        and      bh, 0xfe
        mov      bl, 0x3f
        jmp      short L_a09b
    L_a097:
        mov      bx, 0x133f
    L_a09b:
        mov      word ptr [ebp - 0xa2], bx
        fldcw    word ptr [ebp - 0xa2]
        mov      ebx, OFFSET g_data_0052248c
        fxam
        mov      dword ptr [ebp - 0x94], edx
        wait
        fnstsw   word ptr [ebp - 0xa0]
        mov      byte ptr [ebp - 0x90], 0
        wait
        mov      cl, byte ptr [ebp - 0x9f]
        shl      cl, 1
        sar      cl, 1
        rol      cl, 1
        mov      al, cl
        and      al, 0xf
        xlatb
        movsx    eax, al
        and      ecx, 0x404
        mov      ebx, edx
        add      ebx, eax
        add      ebx, 0x10
        jmp      dword ptr [ebx]
    /* Entry B: dual-operand */
        cmp      byte ptr [edx + 0xe], 5
        jne      short L_a0fe
        mov      bx, word ptr [ebp - 0xa4]
        or       bh, 2
        and      bh, 0xfe
        mov      bl, 0x3f
        jmp      short L_a102
    L_a0fe:
        mov      bx, 0x133f
    L_a102:
        mov      word ptr [ebp - 0xa2], bx
        fldcw    word ptr [ebp - 0xa2]
        mov      ebx, OFFSET g_data_0052248c
        fxam
        mov      dword ptr [ebp - 0x94], edx
        wait
        fnstsw   word ptr [ebp - 0xa0]
        mov      byte ptr [ebp - 0x90], 0
        fxch     st(1)
        mov      cl, byte ptr [ebp - 0x9f]
        fxam
        wait
        fnstsw   word ptr [ebp - 0xa0]
        fxch     st(1)
        mov      ch, byte ptr [ebp - 0x9f]
        shl      ch, 1
        sar      ch, 1
        rol      ch, 1
        mov      al, ch
        and      al, 0xf
        xlatb
        mov      ah, al
        shl      cl, 1
        sar      cl, 1
        rol      cl, 1
        mov      al, cl
        and      al, 0xf
        xlatb
        shl      ah, 1
        shl      ah, 1
        or       al, ah
        movsx    eax, al
        and      ecx, 0x404
        mov      ebx, edx
        add      ebx, eax
        add      ebx, 0x10
        jmp      dword ptr [ebx]
    /* Sub-handlers (each its own dispatch target). */
        call     L_a239
        fxch     st(1)
    L_a17a:
        fstp     st(0)
        ret
        call     L_a239
        jmp      short L_a17a
        fstp     st(0)
        fstp     st(0)
        fldz
        ret
        fstp     st(0)
        fstp     st(0)
        fld1
        ret
        fstp     tbyte ptr [ebp - 0x9e]
        fld      tbyte ptr [ebp - 0x9e]
        test     byte ptr [ebp - 0x97], 0x40
        je       short L_a1af
        mov      byte ptr [ebp - 0x90], 7
        ret
    L_a1af:
        mov      byte ptr [ebp - 0x90], 1
        fadd     qword ptr [g_data_00522484]
        ret
        fxch     st(1)
        fstp     tbyte ptr [ebp - 0x9e]
        fld      tbyte ptr [ebp - 0x9e]
        test     byte ptr [ebp - 0x97], 0x40
        je       short L_a1dd
        mov      byte ptr [ebp - 0x90], 7
        jmp      short L_a1e4
    L_a1dd:
        mov      byte ptr [ebp - 0x90], 1
    L_a1e4:
        faddp    st(1), st
        ret
        fstp     tbyte ptr [ebp - 0x9e]
        fld      tbyte ptr [ebp - 0x9e]
        test     byte ptr [ebp - 0x97], 0x40
        je       short L_a21c
        fxch     st(1)
        fstp     tbyte ptr [ebp - 0x9e]
        fld      tbyte ptr [ebp - 0x9e]
        test     byte ptr [ebp - 0x97], 0x40
        je       short L_a21c
        mov      byte ptr [ebp - 0x90], 7
        jmp      short L_a223
    L_a21c:
        mov      byte ptr [ebp - 0x90], 1
    L_a223:
        faddp    st(1), st
        ret
        fstp     st(0)
        fstp     st(0)
        fld      tbyte ptr [g_data_00522470]
        cmp      byte ptr [ebp - 0x90], 0
        jg       short L_a240
    L_a239:
        mov      byte ptr [ebp - 0x90], 1
    L_a240:
        or       cl, cl
        ret
        or       cl, cl
        je       short L_a249
        fchs
    L_a249:
        ret
        int      3
        int      3
        int      3
        int      3
        int      3
        int      3
    }
}
