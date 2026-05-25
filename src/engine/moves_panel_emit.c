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

extern unsigned int g_data_004ed000;
extern unsigned int g_data_004ed020;
extern unsigned int g_data_004ed040;
extern unsigned int g_data_004ed060;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_data_00543550;
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
extern unsigned int g_data_00ab48b8;
extern unsigned int g_data_00ab48bc;
extern unsigned int g_data_00ab48c0;
extern unsigned int g_data_00ab48c4;
extern unsigned int g_data_00ab48c5;
extern unsigned int g_data_00ab48c6;
extern unsigned int g_data_00ab48c7;
extern unsigned int g_data_00ab48c8;
extern unsigned int g_data_00ab48c9;
extern unsigned int g_data_00ab48ca;
extern unsigned int g_data_00ab48cc;
extern unsigned int g_data_00ab48d2;
extern unsigned int g_data_00ab4e20;
extern void GamepadSeqRecord_004bcc70(void);
extern void Helper_DrawCursor(void);
extern void ProjectTwoVertices(void);
extern void SunbeamSpriteEmit_004bd270(void);

__declspec(naked) void MovesPanelEmit_004bcf60(void)
{
    __asm {
        mov      eax, dword ptr [g_eventQueueTotal]
        push     ebx
        push     esi
        push     edi
        mov      ecx, dword ptr [eax*4 + 0x18]
        cmp      ecx, 8
        mov      dword ptr [g_xformEntityIdx], ecx
        jge      L_cf83
        call     SunbeamSpriteEmit_004bd270
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_cf83:
        mov      edx, dword ptr [g_data_007af92c]
        xor      edi, edi
        cmp      edx, edi
        jne      L_d260
        shl      eax, 2
        cmp      eax, OFFSET g_data_004ed060
        je       L_cfb6
        cmp      eax, OFFSET g_data_004ed040
        je       L_cfb6
        cmp      eax, OFFSET g_data_004ed020
        je       L_cfb6
        cmp      eax, OFFSET g_data_004ed000
        jne      L_d260
    L_cfb6:
        mov      eax, dword ptr [g_data_00543550]
        cmp      eax, 0x10
        jl       L_cfcc
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_cfce
    L_cfcc:
        xor      eax, eax
    L_cfce:
        mov      edx, dword ptr [ecx*4]
        lea      esi, [ecx*4]
        xor      ecx, ecx
        cmp      edx, 0xa000
        sete     cl
        neg      cl
        sbb      ecx, ecx
        mov      dx, word ptr [g_data_00ab4e20]
        and      ecx, 0xfffffff4
        mov      word ptr [g_data_00ab48ca], dx
        add      ecx, 0x16
        mov      word ptr [g_data_00ab48d2], 0xf
        mov      byte ptr [g_data_00ab48c6], cl
        mov      byte ptr [g_data_00ab48c8], cl
        mov      byte ptr [g_data_00ab48c4], cl
        mov      cl, 0x64
        mov      byte ptr [g_data_00ab48c7], cl
        mov      byte ptr [g_data_00ab48c9], cl
        mov      byte ptr [g_data_00ab48c5], cl
        mov      ecx, eax
        shl      ecx, 5
        or       ecx, eax
        shl      ecx, 5
        or       ecx, eax
        mov      word ptr [g_data_00ab48cc], cx
        mov      eax, dword ptr [esi + 4]
        mov      ecx, eax
        mov      word ptr [g_data_007af964], di
        shl      ecx, 0x10
        sar      ecx, 0x13
        sar      eax, 0x13
        mov      word ptr [g_data_007af958], cx
        mov      word ptr [g_data_007af95e], ax
        mov      eax, dword ptr [esi + 0xc]
        mov      word ptr [g_data_007af966], di
        mov      ecx, eax
        shl      ecx, 0x10
        sar      ecx, 0x13
        sar      eax, 0x13
        mov      word ptr [g_data_007af95a], cx
        mov      word ptr [g_data_007af960], ax
        mov      eax, dword ptr [esi + 0x14]
        mov      word ptr [g_data_007af968], di
        mov      ecx, eax
        shl      ecx, 0x10
        sar      ecx, 0x13
        sar      eax, 0x13
        mov      word ptr [g_data_007af95c], cx
        mov      word ptr [g_data_007af962], ax
        call     ProjectTwoVertices
        movsx    eax, word ptr [g_data_007af9b4]
        movsx    ecx, word ptr [g_data_007af9b6]
        movsx    edx, word ptr [g_data_007af9be]
        movsx    ebx, word ptr [g_data_007af9b8]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_data_007af9ba]
        sub      ebx, ecx
        push     edi
        movsx    ecx, word ptr [g_data_007af9bc]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_data_007af9b4]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_data_007af9b8]
        mov      dword ptr [g_data_00ab48b8], ecx
        mov      cx, word ptr [g_data_00ab48d2]
        mov      dword ptr [g_data_00ab48bc], edx
        setle    al
        mov      dword ptr [g_data_007af9b0], eax
        mov      dl, byte ptr [g_data_007af9b0]
        mov      eax, dword ptr [g_data_007af9bc]
        and      edx, 1
        and      ecx, 0xfbff
        mov      dword ptr [g_data_00ab48c0], eax
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [g_data_00ab48d2], cx
        mov      eax, dword ptr [g_eventQueueTotal]
        lea      ecx, [eax*4]
        push     ecx
        call     GamepadSeqRecord_004bcc70
        mov      eax, dword ptr [g_data_007af984]
        add      esp, 8
        cmp      eax, edi
        jle      L_d172
        cmp      dword ptr [g_data_007af988], edi
        jle      L_d172
        cmp      dword ptr [g_data_007af98c], edi
        jle      L_d172
        push     OFFSET g_data_00ab48b8
        call     Helper_DrawCursor
        add      esp, 4
    L_d172:
        mov      esi, dword ptr [esi + 0x1c]
        mov      word ptr [g_data_007af966], di
        mov      eax, esi
        shl      eax, 0x10
        sar      eax, 0x13
        sar      esi, 0x13
        mov      word ptr [g_data_007af95a], ax
        mov      word ptr [g_data_007af960], si
        call     ProjectTwoVertices
        movsx    eax, word ptr [g_data_007af9b4]
        movsx    ecx, word ptr [g_data_007af9b6]
        movsx    edx, word ptr [g_data_007af9be]
        movsx    esi, word ptr [g_data_007af9b8]
        sub      edx, ecx
        sub      esi, eax
        imul     edx, esi
        movsx    esi, word ptr [g_data_007af9ba]
        sub      esi, ecx
        push     1
        movsx    ecx, word ptr [g_data_007af9bc]
        sub      ecx, eax
        xor      eax, eax
        imul     esi, ecx
        mov      ecx, dword ptr [g_data_007af9b4]
        sub      edx, esi
        test     edx, edx
        mov      edx, dword ptr [g_data_007af9b8]
        mov      dword ptr [g_data_00ab48b8], ecx
        mov      cx, word ptr [g_data_00ab48d2]
        mov      dword ptr [g_data_00ab48bc], edx
        setle    al
        mov      dword ptr [g_data_007af9b0], eax
        mov      dl, byte ptr [g_data_007af9b0]
        mov      eax, dword ptr [g_data_007af9bc]
        and      edx, 1
        and      ecx, 0xfbff
        mov      dword ptr [g_data_00ab48c0], eax
        mov      eax, dword ptr [g_eventQueueTotal]
        shl      edx, 0xa
        or       ecx, edx
        mov      word ptr [g_data_00ab48d2], cx
        lea      ecx, [eax*4]
        push     ecx
        call     GamepadSeqRecord_004bcc70
        mov      eax, dword ptr [g_data_007af984]
        add      esp, 8
        cmp      eax, edi
        jle      L_d260
        cmp      dword ptr [g_data_007af988], edi
        jle      L_d260
        cmp      dword ptr [g_data_007af98c], edi
        jle      L_d260
        push     OFFSET g_data_00ab48b8
        call     Helper_DrawCursor
        add      esp, 4
    L_d260:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
