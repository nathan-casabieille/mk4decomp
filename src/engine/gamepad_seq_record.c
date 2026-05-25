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
extern unsigned int g_data_00ab48b8;
extern unsigned int g_data_00ab48ba;
extern unsigned int g_data_00ab48bc;
extern unsigned int g_data_00ab48be;
extern unsigned int g_data_00ab48c0;
extern unsigned int g_data_00ab48c2;

__declspec(naked) void GamepadSeqRecord_004bcc70(void)
{
    __asm {
        push     esi
        call     Renderer_GetMode
        mov      esi, 2
        cmp      eax, esi
        je       L_cd96
        call     Renderer_GetMode
        cmp      eax, 1
        je       L_cd96
        mov      eax, dword ptr [esp + 0xc]
        test     eax, eax
        mov      eax, dword ptr [esp + 8]
        jne      L_cd11
        cmp      eax, OFFSET g_data_004ed040
        jne      L_ccbe
        inc      word ptr [g_data_00ab48b8]
        mov      ecx, 3
        add      word ptr [g_data_00ab48bc], cx
        add      word ptr [g_data_00ab48c0], cx
    L_ccbe:
        cmp      eax, OFFSET g_data_004ed060
        jne      L_ccd3
        add      word ptr [g_data_00ab48bc], si
        add      word ptr [g_data_00ab48c0], si
    L_ccd3:
        cmp      eax, OFFSET g_data_004ed000
        jne      L_ccf6
        inc      word ptr [g_data_00ab48b8]
        inc      word ptr [g_data_00ab48bc]
        inc      word ptr [g_data_00ab48c0]
        inc      word ptr [g_data_00ab48c2]
    L_ccf6:
        cmp      eax, OFFSET g_data_004ed020
        jne      L_cf5c
        inc      word ptr [g_data_00ab48b8]
        add      word ptr [g_data_00ab48bc], si
        jmp      L_cd7f
    L_cd11:
        cmp      eax, OFFSET g_data_004ed040
        jne      L_cd2e
        inc      word ptr [g_data_00ab48b8]
        inc      word ptr [g_data_00ab48bc]
        add      word ptr [g_data_00ab48c0], 3
    L_cd2e:
        cmp      eax, OFFSET g_data_004ed060
        jne      L_cd3c
        add      word ptr [g_data_00ab48c0], si
    L_cd3c:
        cmp      eax, OFFSET g_data_004ed000
        jne      L_cd66
        inc      word ptr [g_data_00ab48b8]
        inc      word ptr [g_data_00ab48bc]
        inc      word ptr [g_data_00ab48be]
        inc      word ptr [g_data_00ab48c0]
        inc      word ptr [g_data_00ab48c2]
    L_cd66:
        cmp      eax, OFFSET g_data_004ed020
        jne      L_cf5c
        inc      word ptr [g_data_00ab48b8]
        inc      word ptr [g_data_00ab48bc]
    L_cd7f:
        inc      word ptr [g_data_00ab48be]
        add      word ptr [g_data_00ab48c0], si
        inc      word ptr [g_data_00ab48c2]
        pop      esi
        ret
    L_cd96:
        mov      eax, dword ptr [esp + 0xc]
        mov      edx, 0xfffffffe
        test     eax, eax
        mov      eax, dword ptr [esp + 8]
        jne      L_ce8c
        cmp      eax, OFFSET g_data_004ed040
        jne      L_cde8
        mov      cx, word ptr [g_data_00ab48c0]
        inc      word ptr [g_data_00ab48b8]
        add      word ptr [g_data_00ab48ba], dx
        add      word ptr [g_data_00ab48bc], si
        add      word ptr [g_data_00ab48be], dx
        add      cx, si
        dec      word ptr [g_data_00ab48c2]
        mov      word ptr [g_data_00ab48c0], cx
        jmp      L_cdef
    L_cde8:
        mov      cx, word ptr [g_data_00ab48c0]
    L_cdef:
        cmp      eax, OFFSET g_data_004ed060
        jne      L_ce1c
        add      word ptr [g_data_00ab48ba], dx
        add      word ptr [g_data_00ab48bc], si
        add      word ptr [g_data_00ab48be], dx
        add      cx, si
        dec      word ptr [g_data_00ab48c2]
        mov      word ptr [g_data_00ab48c0], cx
    L_ce1c:
        cmp      eax, OFFSET g_data_004ed000
        jne      L_ce3a
        inc      word ptr [g_data_00ab48b8]
        inc      word ptr [g_data_00ab48bc]
        inc      cx
        mov      word ptr [g_data_00ab48c0], cx
    L_ce3a:
        cmp      eax, OFFSET g_data_004ed020
        jne      L_cf5c
        mov      dx, word ptr [g_data_00ab48b8]
        add      cx, si
        dec      dx
        add      word ptr [g_data_00ab48bc], si
        mov      word ptr [g_data_00ab48b8], dx
        mov      word ptr [g_data_00ab48c0], cx
        movsx    eax, cx
        movsx    edx, dx
        sub      eax, edx
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 3
        jg       L_cf5c
        mov      word ptr [g_data_00ab48bc], cx
        mov      word ptr [g_data_00ab48b8], cx
        pop      esi
        ret
    L_ce8c:
        cmp      eax, OFFSET g_data_004ed040
        jne      L_cec9
        mov      cx, word ptr [g_data_00ab48c0]
        inc      word ptr [g_data_00ab48b8]
        add      word ptr [g_data_00ab48ba], dx
        inc      word ptr [g_data_00ab48bc]
        dec      word ptr [g_data_00ab48be]
        add      cx, si
        dec      word ptr [g_data_00ab48c2]
        mov      word ptr [g_data_00ab48c0], cx
        jmp      L_ced0
    L_cec9:
        mov      cx, word ptr [g_data_00ab48c0]
    L_ced0:
        cmp      eax, OFFSET g_data_004ed060
        jne      L_cef6
        add      word ptr [g_data_00ab48ba], dx
        dec      word ptr [g_data_00ab48be]
        add      cx, si
        dec      word ptr [g_data_00ab48c2]
        mov      word ptr [g_data_00ab48c0], cx
    L_cef6:
        cmp      eax, OFFSET g_data_004ed000
        jne      L_cf14
        inc      word ptr [g_data_00ab48b8]
        inc      word ptr [g_data_00ab48bc]
        inc      cx
        mov      word ptr [g_data_00ab48c0], cx
    L_cf14:
        cmp      eax, OFFSET g_data_004ed020
        jne      L_cf5c
        mov      dx, word ptr [g_data_00ab48b8]
        add      cx, si
        dec      dx
        dec      word ptr [g_data_00ab48bc]
        mov      word ptr [g_data_00ab48b8], dx
        mov      word ptr [g_data_00ab48c0], cx
        movsx    eax, cx
        movsx    edx, dx
        sub      eax, edx
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 3
        jg       L_cf5c
        mov      word ptr [g_data_00ab48bc], cx
        mov      word ptr [g_data_00ab48b8], cx
    L_cf5c:
        pop      esi
        ret
    }
}
