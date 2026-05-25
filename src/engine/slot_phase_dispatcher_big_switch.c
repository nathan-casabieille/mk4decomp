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

extern unsigned int g_data_00538094;
extern unsigned int g_framePauseFlag;
extern unsigned int g_pendingNodeType;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch94;
extern void CallPauseCallTestStackPushJmp_00460c60(void);
extern void CallPauseMStackPushSet0Jmp_0045fcf0(void);
extern void CallPauseTriCmpJmp_00460910(void);
extern void CjInstallSelfRouter_00470480(void);
extern void CjMaskedFlagProbe_0048ecf0(void);
extern void DualGatedStateYield_0048fc80(void);
extern void GuardedDispatch_00460ca0(void);
extern void GuardedDispatch_00460cd0(void);
extern void GuardedDoubleCallSetJmp_00460260(void);
extern void NotShrCmp1Store_00460d80(void);
extern void PerSlotPhaseRouter_004605d0(void);
extern void PerSlotPhaseRouter_00460770(void);
extern void UnlinkChainInstall_00460dd0(void);

__declspec(naked) void SlotPhaseDispatcherBigSwitch_0045fac0(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    ebx
        push    esi
        push    edi
        lea     esi, [eax*4]
        xor     edi, edi
        mov     eax, dword ptr [esi + 0x84]
        mov     dword ptr [esi + 0x84], edi
        cmp     eax, edi
        je      L_spdbs_phase0
        mov     ebx, 4
    L_spdbs_loop:
        call    DirtyToggleByGate_0048f350
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_spdbs_ret
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_spdbs_b4
        call    CjMaskedFlagProbe_0048ecf0
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_spdbs_ret
        test    byte ptr [g_xformDirtyFlags], 1
        jne     L_spdbs_b1
        call    NotShrCmp1Store_00460d80
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_spdbs_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, eax
        and     ecx, 9
        cmp     ecx, 9
        mov     dword ptr [g_eventQueueCurrent], ecx
        je      L_spdbs_b9
        mov     ecx, eax
        and     ecx, 5
        cmp     ecx, 5
        mov     dword ptr [g_eventQueueCurrent], ecx
        je      L_spdbs_b5
        mov     ecx, eax
        and     ecx, 1
        cmp     ecx, 1
        mov     dword ptr [g_eventQueueCurrent], ecx
        je      L_spdbs_b1a
        mov     ecx, eax
        and     ecx, 8
        cmp     ecx, 8
        mov     dword ptr [g_eventQueueCurrent], ecx
        je      L_spdbs_b8
        mov     ecx, eax
        and     ecx, ebx
        cmp     ecx, ebx
        mov     dword ptr [g_eventQueueCurrent], ecx
        je      L_spdbs_b4a
        and     eax, 2
        mov     dword ptr [g_xformScratch94], eax
        jne     L_spdbs_b2
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], edi
        mov     dword ptr [ecx*4 + 0x6c], edi
        mov     eax, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x70], edx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4 + 0x74], ecx
        call    CallPauseTriCmpJmp_00460910
        cmp     dword ptr [g_framePauseFlag], edi
        jne     short L_spdbs_ret
        mov     eax, dword ptr [g_baseSel_00542060]
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], edi
        cmp     eax, edi
        jne     L_spdbs_loop
    L_spdbs_phase0:
        call    DualGatedStateYield_0048fc80
        test    eax, eax
        jne     short L_spdbs_ret
        mov     eax, dword ptr [g_data_00538094]
        cmp     eax, edi
        mov     dword ptr [g_eventQueueCurrent], eax
        je      short L_spdbs_install
        call    UnlinkChainInstall_00460dd0
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_install:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset SlotPhaseDispatcherBigSwitch_0045fac0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_spdbs_ret:
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b4:
        call    CjInstallSelfRouter_00470480
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b1:
        call    GuardedDoubleCallSetJmp_00460260
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b9:
        call    GuardedDispatch_00460ca0
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b5:
        call    GuardedDispatch_00460cd0
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b1a:
        call    CallPauseCallTestStackPushJmp_00460c60
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b8:
        call    PerSlotPhaseRouter_004605d0
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b4a:
        call    PerSlotPhaseRouter_00460770
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_spdbs_b2:
        call    CallPauseMStackPushSet0Jmp_0045fcf0
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
