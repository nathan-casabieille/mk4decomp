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

extern unsigned int g_const_004d2a20;
extern unsigned int g_const_004d2a28;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_fightGroupHead;
extern unsigned int g_data_00543550;
extern unsigned int g_data_007af990;
extern unsigned int g_data_007af994;
extern unsigned int g_data_007af998;
extern unsigned int g_data_007af99c;
extern unsigned int g_data_007af9a0;
extern unsigned int g_data_00ab44d8;
extern unsigned int g_data_00ab44da;
extern unsigned int g_data_00ab44dc;
extern unsigned int g_data_00ab44de;
extern unsigned int g_data_00ab44e0;
extern unsigned int g_data_00ab44e2;
extern unsigned int g_data_00ab44e4;
extern unsigned int g_data_00ab44e6;
extern unsigned int g_data_00ab44e8;
extern unsigned int g_data_00ab47f8;
extern unsigned int g_data_00ab47fa;
extern unsigned int g_data_00ab47fc;
extern unsigned int g_data_00ab47fe;
extern unsigned int g_data_00ab4800;
extern unsigned int g_data_00ab4802;
extern unsigned int g_data_00ab4804;
extern unsigned int g_data_00ab4806;
extern unsigned int g_data_00ab4808;
extern unsigned int g_data_00ab4838;
extern unsigned int g_data_00ab483c;
extern unsigned int g_data_00ab4840;
extern unsigned int g_data_00ab4cd8;
extern unsigned int g_data_00ab4d58;
extern unsigned int g_data_00ab4d5c;
extern unsigned int g_data_00ab4d60;
extern unsigned int g_data_00ab4d64;
extern unsigned int g_data_00ab4d68;
extern unsigned int g_data_00ab4dc4;
extern unsigned int g_data_00ab4e3c;
extern unsigned int g_data_00ab4e40;
extern unsigned int g_data_00ab4e44;
extern unsigned int g_data_00ab4e48;
extern unsigned int g_data_00ab4e4c;
extern unsigned int g_data_00ab4e50;
extern unsigned int g_data_00ab4e54;
extern unsigned int g_data_00ab4e58;
extern unsigned int g_data_00ab4e5c;
extern unsigned int g_data_00ab4e60;
extern unsigned int g_data_00ab4e68;
extern unsigned int g_data_00ab4e6c;
extern void AltCamMatrixProject_004b9840(void);
extern void Color15BitPacker_004b3030(void);
extern void DoubleToInt64_004c57d0(void);
extern void Mat3x3VecMul6Bit_004b3590(void);
extern void PackColor_004b30c0(void);
extern void Vec3NormalizeScaleStore_004b3130(void);

__declspec(naked) void CameraSetupAndCullFan_004b99b0(void)
{
    __asm {
        sub      esp, 0x18
        mov      eax, dword ptr [g_pendingNodeType]
        push     ebx
        mov      dword ptr [esp + 0x18], eax
        mov      eax, dword ptr [g_data_00ab4e68]
        push     ebp
        push     esi
        lea      eax, [eax + eax*2]
        mov      edx, dword ptr [g_currentNodeIdx]
        shl      eax, 5
        shr      eax, 8
        push     edi
        mov      edi, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_data_00ab4e5c], eax
        mov      eax, dword ptr [g_data_00543550]
        mov      dword ptr [esp + 0x20], edx
        mov      dword ptr [g_data_00ab4e60], eax
        mov      ecx, dword ptr [edi*4 + 0x3c]
        sar      ecx, 8
        cmp      ecx, 0x60
        mov      dword ptr [g_walkCallback], ecx
        jge      L_9a0e
        mov      ecx, 0x60
        jmp      L_9a1b
    L_9a0e:
        cmp      ecx, 0xa0
        jle      L_9a21
        mov      ecx, 0xa0
    L_9a1b:
        mov      dword ptr [g_walkCallback], ecx
    L_9a21:
        mov      esi, eax
        imul     esi, ecx
        shl      esi, 3
        sar      esi, 8
        cmp      ecx, 0x100
        jle      L_9a3f
        mov      ecx, 0x100
        mov      dword ptr [g_walkCallback], ecx
    L_9a3f:
        imul     eax, ecx
        sar      eax, 8
        mov      word ptr [g_data_00ab44d8], si
        mov      word ptr [g_data_00ab44de], si
        mov      word ptr [g_data_00ab44e4], si
        mov      dword ptr [g_data_00ab4e6c], eax
        sar      esi, 1
        mov      eax, esi
        lea      ecx, [edx + 0x15]
        neg      eax
        mov      word ptr [g_data_00ab44da], ax
        mov      word ptr [g_data_00ab44e0], ax
        mov      word ptr [g_data_00ab44e6], ax
        lea      eax, [edi + 0x15]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      edx, dword ptr [ecx*4]
        mov      edi, dword ptr [eax*4]
        sub      edx, edi
        push     OFFSET g_data_00ab4838
        sar      edx, 8
        mov      dword ptr [g_data_00ab4838], edx
        mov      edx, dword ptr [ecx*4 + 4]
        mov      ebx, dword ptr [eax*4 + 4]
        push     OFFSET g_data_00ab4838
        sub      edx, ebx
        sar      edx, 8
        mov      dword ptr [g_data_00ab483c], edx
        mov      ecx, dword ptr [ecx*4 + 8]
        mov      edx, dword ptr [eax*4 + 8]
        mov      eax, dword ptr [g_data_00ab4d5c]
        sub      ecx, edx
        mov      edx, dword ptr [g_data_00ab4d58]
        sar      ecx, 8
        mov      dword ptr [g_data_00ab4840], ecx
        mov      ecx, dword ptr [g_data_00ab4d60]
        mov      dword ptr [g_data_007af990], edx
        mov      edx, dword ptr [g_data_00ab4d64]
        mov      dword ptr [g_data_007af994], eax
        mov      ax, word ptr [g_data_00ab4d68]
        mov      dword ptr [g_data_007af998], ecx
        mov      dword ptr [g_data_007af99c], edx
        mov      word ptr [g_data_007af9a0], ax
        call     Mat3x3VecMul6Bit_004b3590
        mov      edi, dword ptr [g_data_00ab4838]
        mov      ecx, dword ptr [g_data_00ab483c]
        mov      ebx, dword ptr [g_data_00ab4840]
        mov      word ptr [g_data_00ab4800], cx
        movsx    eax, di
        movsx    ecx, cx
        mov      ebp, eax
        mov      dword ptr [esp + 0x18], eax
        movsx    edx, bx
        imul     ebp, eax
        mov      eax, ecx
        mov      dword ptr [esp + 0x1c], ecx
        imul     eax, ecx
        mov      ecx, edx
        add      ebp, eax
        imul     ecx, edx
        add      ebp, ecx
        add      esp, 8
        mov      dword ptr [esp + 0x1c], ebp
        mov      word ptr [g_data_00ab47fe], di
        fild     dword ptr [esp + 0x1c]
        mov      word ptr [g_data_00ab4802], bx
        mov      dword ptr [esp + 0x18], edx
        fsqrt
        fcom     qword ptr [g_const_004d2a20]
        fnstsw   ax
        test     ah, 0x40
        jne      L_9bca
        fdivr    qword ptr [g_const_004d2a28]
        fild     dword ptr [esp + 0x10]
        fmul     st, st(1)
        call     DoubleToInt64_004c57d0
        fild     dword ptr [esp + 0x14]
        mov      di, ax
        mov      word ptr [g_data_00ab47fe], di
        fmul     st, st(1)
        call     DoubleToInt64_004c57d0
        fild     dword ptr [esp + 0x18]
        mov      word ptr [g_data_00ab4800], ax
        fmul     st, st(1)
        call     DoubleToInt64_004c57d0
        mov      bx, ax
        fstp     st(0)
        mov      word ptr [g_data_00ab4802], bx
        jmp      L_9bcc
    L_9bca:
        fstp     st(0)
    L_9bcc:
        mov      eax, dword ptr [g_data_00ab4800]
        mov      dx, di
        neg      dx
        mov      word ptr [g_data_00ab47f8], dx
        mov      cx, bx
        neg      eax
        movsx    edx, bx
        neg      cx
        mov      word ptr [g_data_00ab47fa], ax
        mov      word ptr [g_data_00ab47fc], cx
        movsx    eax, word ptr [g_data_00ab4800]
        neg      edx
        movsx    ecx, di
        push     edx
        push     eax
        push     ecx
        push     0
        call     Vec3NormalizeScaleStore_004b3130
        add      esp, 0x10
        push     0x50
        push     0x50
        push     0x50
        call     Color15BitPacker_004b3030
        add      esp, 0xc
        push     esi
        push     esi
        push     esi
        push     0
        call     PackColor_004b30c0
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_data_00ab4e50]
        mov      esi, dword ptr [g_data_00ab4e54]
        add      esp, 0x10
        mov      edi, dword ptr [eax*4]
        sub      ecx, edi
        mov      edi, dword ptr [g_data_00ab4e58]
        sar      ecx, 8
        mov      dword ptr [g_data_00ab4838], ecx
        mov      edx, dword ptr [eax*4 + 4]
        sub      esi, edx
        sar      esi, 8
        mov      dword ptr [g_data_00ab483c], esi
        mov      ebx, dword ptr [eax*4 + 8]
        sub      edi, ebx
        mov      edx, esi
        sar      edi, 8
        imul     edx, esi
        mov      ebx, edi
        mov      eax, ecx
        imul     ebx, edi
        imul     eax, ecx
        sar      ebx, 0xc
        sar      edx, 0xc
        add      ebx, edx
        mov      dword ptr [g_data_00ab4840], edi
        sar      eax, 0xc
        add      ebx, eax
        je       L_9df0
        mov      eax, 0x180000
        mov      bp, cx
        cdq
        idiv     ebx
        mov      word ptr [g_data_00ab4808], di
        mov      word ptr [g_data_00ab4804], bp
        movsx    edx, di
        mov      word ptr [g_data_00ab4806], si
        mov      dword ptr [esp + 0x18], edx
        mov      ebx, eax
        movsx    eax, cx
        movsx    ecx, si
        mov      edi, eax
        mov      dword ptr [esp + 0x10], eax
        imul     edi, eax
        mov      eax, ecx
        mov      dword ptr [esp + 0x14], ecx
        imul     eax, ecx
        mov      ecx, edx
        add      edi, eax
        imul     ecx, edx
        add      edi, ecx
        mov      dword ptr [esp + 0x1c], edi
        fild     dword ptr [esp + 0x1c]
        sar      ebx, 8
        fsqrt
        fcom     qword ptr [g_const_004d2a20]
        fnstsw   ax
        test     ah, 0x40
        jne      L_9d42
        fdivr    qword ptr [g_const_004d2a28]
        fild     dword ptr [esp + 0x10]
        fmul     st, st(1)
        call     DoubleToInt64_004c57d0
        fild     dword ptr [esp + 0x14]
        mov      bp, ax
        mov      word ptr [g_data_00ab4804], bp
        fmul     st, st(1)
        call     DoubleToInt64_004c57d0
        fild     dword ptr [esp + 0x18]
        mov      si, ax
        mov      word ptr [g_data_00ab4806], si
        fmul     st, st(1)
        call     DoubleToInt64_004c57d0
        fstp     st(0)
        mov      word ptr [g_data_00ab4808], ax
        jmp      L_9d44
    L_9d42:
        fstp     st(0)
    L_9d44:
        cmp      ebx, 0x100
        jle      L_9d51
        mov      ebx, 0x100
    L_9d51:
        imul     ebx, dword ptr [g_data_00ab4e68]
        mov      edx, dword ptr [g_data_00ab4e44]
        mov      eax, dword ptr [g_data_00ab4e48]
        mov      ecx, dword ptr [g_data_00ab4e4c]
        and      edx, 0xffff
        and      eax, 0xffff
        sub      edx, 0x8000
        and      ecx, 0xffff
        sub      eax, 0x8000
        shr      ebx, 8
        sar      edx, 8
        sub      ecx, 0x8000
        imul     edx, ebx
        sar      eax, 8
        sar      ecx, 8
        imul     eax, ebx
        imul     ecx, ebx
        mov      word ptr [g_data_00ab44dc], dx
        mov      word ptr [g_data_00ab44e2], ax
        movsx    edx, word ptr [g_data_00ab4808]
        mov      word ptr [g_data_00ab44e8], cx
        push     edx
        movsx    eax, si
        movsx    ecx, bp
        push     eax
        push     ecx
        push     1
        call     Vec3NormalizeScaleStore_004b3130
        movsx    edx, word ptr [g_data_00ab44e8]
        movsx    eax, word ptr [g_data_00ab44e2]
        movsx    ecx, word ptr [g_data_00ab44dc]
        add      esp, 0x10
        push     edx
        push     eax
        push     ecx
        push     1
        call     PackColor_004b30c0
        add      esp, 0x10
    L_9df0:
        mov      eax, dword ptr [g_fightGroupHead]
        test     eax, 0x180000
        je       L_9e10
        mov      ecx, dword ptr [g_data_00ab4e40]
        test     ecx, ecx
        je       L_9e10
        add      dword ptr [g_data_00ab4dc4], 0x2b85
    L_9e10:
        test     ah, 0x10
        je       L_9e2d
        mov      eax, dword ptr [g_data_00ab4e3c]
        test     eax, eax
        jl       L_9e2d
        push     0
        push     OFFSET g_data_00ab4cd8
        call     AltCamMatrixProject_004b9840
        add      esp, 8
    L_9e2d:
        mov      edx, dword ptr [esp + 0x20]
        mov      eax, dword ptr [esp + 0x24]
        pop      edi
        pop      esi
        pop      ebp
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_pendingNodeType], eax
        pop      ebx
        add      esp, 0x18
        ret
    }
}
