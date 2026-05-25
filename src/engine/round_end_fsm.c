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
extern unsigned int g_state_00542094;
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
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern unsigned int g_data_00537f30;
extern unsigned int g_data_0052d724;
extern void PendingMatch_0042d240(void);
extern void ScenegraphWalk_0041f7d0(void);
extern void PendingMatch_00420300(void);
extern void TwinMStackPushScaledChain_00422110(void);
extern void RoundEndFsm_0042b2f0(void);
extern void CallPauseClear3CallTriple_00428030(void);
extern void ScaledInit_0048f720(void);
extern void CopyJmp_00406ba0(void);
extern void ScaledZero44_00491500(void);
extern void MStackPushSet0001_00490260(void);
extern void MStackPushSet0004_00490230(void);
extern void ScaledInitWithCounterAndType_004314f0(void);

/* @addr 0x00421380 (378b game) - 2-entry packed phase install + 6-call chain.
 *   Entry 1 (offset 0, 277b): phase-state install.
 *     Phase 1+: SwapOrPassSet_0048fbf0; on no-error compares
 *       g_walkCallback with g_data_004f3608. If equal, tail-call
 *       PendingMatch_0042d240. Else bumps g_data_00537f30 by 1, calls
 *       CallPauseClear3CallTriple_00428030, then chains
 *       ScenegraphWalk_0041f7d0 + PendingMatch_00420300.
 *     Phase 0: g_data_0052d724=1, reads g_data_0052ab40 and tests
 *       bit 3; if clear calls TwinMStackPushScaledChain_00422110. Either way installs Self
 *       at body with slot[+0x84]=1, packs (Self + 0x01000000) at the
 *       bumped scaled slot, calls RoundEndFsm_0042b2f0, arms 0x541e6c=1.
 *   11b NOP align pad.
 *   Entry 2 (offset 0x120, 90b): 6-call chain (ScaledInit_0048f720,
 *     CopyJmp_00406ba0, ScaledZero44_00491500, ScaledZeroFour_00490740,
 *     MStackPushSet0001_00490260, MStackPushSet0004_00490230), each
 *     gated by 0x541e6c. On full success, tail-jmps
 *     ScaledInitWithCounterAndType_004314f0.
 */
extern unsigned int g_data_004f3608;
extern unsigned int g_data_0052ab40;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_data_00542094;
extern void SwapOrPassSet_0048fbf0(void);

__declspec(naked) void Phase3InstallSelfChain_00421380(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_pis2_phase0
        call    SwapOrPassSet_0048fbf0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pis2_done
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, dword ptr [g_data_004f3608]
        cmp     ecx, eax
        jne     short L_pis2_advance
        call    PendingMatch_0042d240
        pop     esi
        ret
    L_pis2_advance:
        mov     edx, dword ptr [g_data_00537f30]
        lea     eax, [edx + 1]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_data_00537f30], eax
        call    CallPauseClear3CallTriple_00428030
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pis2_done
        call    ScenegraphWalk_0041f7d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pis2_done
        call    PendingMatch_00420300
        pop     esi
        ret
    L_pis2_phase0:
        mov     eax, dword ptr [g_data_0052ab40]
        mov     dword ptr [g_data_0052d724], 1
        mov     dword ptr [g_walkCallback], eax
        and     eax, 8
        mov     dword ptr [g_data_00542094], eax
        jne     short L_pis2_skipCall
        call    TwinMStackPushScaledChain_00422110
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_done
    L_pis2_skipCall:
        mov     dword ptr [esi + 8], offset Phase3InstallSelfChain_00421380
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, offset Phase3InstallSelfChain_00421380
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [edx*4 + 0x84], 0
        call    RoundEndFsm_0042b2f0
        mov     dword ptr [g_framePauseFlag], 1
    L_pis2_done:
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 2 (offset 0x120) */
    L_pis2_entry2:
        call    ScaledInit_0048f720
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    CopyJmp_00406ba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    ScaledZero44_00491500
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    ScaledZeroFour_00490740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    MStackPushSet0001_00490260
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        call    MStackPushSet0004_00490230
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_pis2_e2End
        jmp     ScaledInitWithCounterAndType_004314f0
    L_pis2_e2End:
        ret
    }
}
