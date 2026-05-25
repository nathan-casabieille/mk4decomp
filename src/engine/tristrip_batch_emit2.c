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

extern unsigned int g_pendingNodeType;
extern unsigned int g_data_007af92c;
extern unsigned int g_data_007af958;
extern unsigned int g_data_007af95a;
extern unsigned int g_data_007af95c;
extern unsigned int g_data_007af95e;
extern unsigned int g_data_007af960;
extern unsigned int g_data_007af962;
extern unsigned int g_data_007af964;
extern unsigned int g_data_007af966;
extern unsigned int g_data_007af968;
extern unsigned int g_data_007af984;
extern unsigned int g_data_007af988;
extern unsigned int g_data_007af98c;
extern unsigned int g_data_007af9b0;
extern unsigned int g_data_007af9b4;
extern unsigned int g_data_007af9b6;
extern unsigned int g_data_007af9b8;
extern unsigned int g_data_007af9ba;
extern unsigned int g_data_007af9bc;
extern unsigned int g_data_007af9be;
extern unsigned int g_data_00ab4d9c;
extern unsigned int g_data_00ab4e60;
extern void AdvanceTriStripRing(void);
extern void Helper_DrawCursor(void);
extern void MaxOfThree_004b3d90(void);
extern void ProjectTwoVertices(void);
extern void ProjectVertex(void);

__declspec(naked) void TristripBatchEmit2_004bb930(void)
{
    __asm {
        mov      eax, dword ptr [g_data_007af92c]
        sub      esp, 0xc
        test     eax, eax
        push     ebx
        push     ebp
        push     esi
        push     edi
        jne      L_bb6a
        mov      edi, dword ptr [esp + 0x20]
        mov      eax, dword ptr [edi + 4]
        test     eax, eax
        je       L_bb6a
        mov      ecx, dword ptr [edi + 8]
        mov      edx, dword ptr [g_pendingNodeType]
        lea      ecx, [ecx + edi + 8]
        lea      edi, [edi + eax + 4]
        mov      eax, dword ptr [g_data_00ab4e60]
        lea      esi, [edx + 4]
        cmp      eax, 0x10
        jl       L_b97d
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_b97f
    L_b97d:
        xor      eax, eax
    L_b97f:
        mov      edx, eax
        shl      edx, 5
        or       edx, eax
        shl      edx, 5
        or       eax, edx
        mov      dword ptr [esp + 0x14], eax
    L_b98f:
        mov      bp, word ptr [ecx]
        add      ecx, 2
        mov      eax, ebp
        and      ebp, 1
        shr      eax, 8
        and      al, 1
        mov      byte ptr [esp + 0x20], al
        mov      eax, dword ptr [esp + 0x24]
        test     eax, eax
        je       L_b9b5
        xor      eax, eax
        test     bp, bp
        sete     al
        mov      ebp, eax
    L_b9b5:
        movsx    ebx, word ptr [ecx]
        xor      eax, eax
        add      ecx, 2
        cmp      ebx, eax
        mov      dword ptr [esp + 0x18], ecx
        jl       L_bb6a
        mov      word ptr [g_data_007af958], ax
        mov      word ptr [g_data_007af95e], ax
        mov      word ptr [g_data_007af964], ax
        mov      cx, word ptr [edi]
        mov      word ptr [g_data_007af95a], cx
        mov      dx, word ptr [edi + 2]
        mov      word ptr [g_data_007af960], dx
        mov      ax, word ptr [edi + 4]
        mov      word ptr [g_data_007af966], ax
        mov      cx, word ptr [edi + 0xc]
        mov      word ptr [g_data_007af95c], cx
        mov      dx, word ptr [edi + 0xe]
        mov      word ptr [g_data_007af962], dx
        mov      ax, word ptr [edi + 0x10]
        mov      word ptr [g_data_007af968], ax
        call     ProjectTwoVertices
        add      edi, 0x18
        inc      ebx
        mov      dword ptr [esp + 0x10], ebx
    L_ba27:
        mov      cx, word ptr [edi + 4]
        mov      dx, word ptr [edi + 2]
        mov      ax, word ptr [edi]
        push     ecx
        push     edx
        push     eax
        call     AdvanceTriStripRing
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_data_007af9b4]
        movsx    ecx, word ptr [g_data_007af9b6]
        movsx    edx, word ptr [g_data_007af9be]
        movsx    ebx, word ptr [g_data_007af9b8]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_data_007af9ba]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_data_007af9bc]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        sub      edx, ebx
        test     edx, edx
        setle    al
        xor      edx, edx
        mov      dword ptr [g_data_007af9b0], eax
        test     eax, eax
        movsx    eax, bp
        sete     dl
        cmp      eax, edx
        je       L_bb42
        mov      eax, dword ptr [g_data_007af984]
        test     eax, eax
        jle      L_bb42
        mov      eax, dword ptr [g_data_007af988]
        test     eax, eax
        jle      L_bb42
        mov      eax, dword ptr [g_data_007af98c]
        test     eax, eax
        jle      L_bb42
        mov      ecx, dword ptr [g_data_007af9b4]
        mov      dword ptr [esi], ecx
        mov      edx, dword ptr [g_data_007af9b8]
        mov      cx, word ptr [esi + 0x1a]
        mov      dword ptr [esi + 4], edx
        mov      eax, dword ptr [g_data_007af9bc]
        and      ecx, 0xfbff
        mov      dword ptr [esi + 8], eax
        mov      dl, byte ptr [g_data_007af9b0]
        and      edx, 1
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [esi + 0x1a], cx
        call     MaxOfThree_004b3d90
        add      eax, 0x7d0
        mov      dx, word ptr [esi + 0x1a]
        mov      word ptr [esi + 0x12], ax
        mov      ecx, dword ptr [g_data_00ab4d9c]
        shl      ecx, 5
        add      ecx, eax
        mov      al, byte ptr [esp + 0x20]
        and      al, 3
        mov      word ptr [esi + 0x12], cx
        movsx    cx, al
        and      edx, 0xfe6f
        push     esi
        shl      ecx, 7
        or       edx, ecx
        mov      word ptr [esi + 0x1a], dx
        mov      dx, word ptr [esp + 0x18]
        mov      word ptr [esi + 0x14], dx
        call     Helper_DrawCursor
        add      esp, 4
    L_bb42:
        add      edi, 0xc
        xor      eax, eax
        test     bp, bp
        sete     al
        mov      ebp, eax
        mov      eax, dword ptr [esp + 0x10]
        add      esi, 0x1c
        dec      eax
        mov      dword ptr [esp + 0x10], eax
        jne      L_ba27
        mov      ecx, dword ptr [esp + 0x18]
        jmp      L_b98f
    L_bb6a:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    }
}
