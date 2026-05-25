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

extern unsigned int g_acc_00542078;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_data_0053815c;
extern void Distance2DSaturationClamp_004300a0(void);
extern void ChainFieldTest2Branch_0042fbc0(void);
extern void LoadSetCallPauseStoreJmp_0042fea0(void);
extern void MStackPush4DualCallAbsPop4_00430d30(void);
extern void WalkTowardTargetFsm_004301e0(void);
extern void DualMul10ChainAcc7C_00430020(void);
extern void EsiInstallChainCallCmpThreshold_0042fad0(void);
extern void GuardedSeq_0042fba0(void);
extern void Mul10Triple0xd999Interp_0042fa10(void);
extern void SubCmpCallPauseJmp_0042fc40(void);
extern void GuardedSeq_0042fb80(void);

/* @addr 0x0042f8a0 (355b game) - install-self phase dispatcher with 2D
 *   interpolation tails. Phase 0: installs Self at [eax+8] with slot[+0x84]=1
 *   and arms g_framePauseFlag.
 *   Phase 1+ path: chains Distance2DSaturationClamp_004300a0 → load
 *   g_data_00538158 → ChainFieldTest2Branch_0042fbc0 → load g_data_0053815c
 *   → ChainFieldTest2Branch_0042fbc0 → LoadSetCallPauseStoreJmp_0042fea0 →
 *   MStackPush4DualCallAbsPop4_00430d30. After the chain:
 *     - if g_acc_00542078 > 0xa3d, tail-call WalkTowardTargetFsm_004301e0.
 *     - else call DualMul10ChainAcc7C_00430020, then if g_eventQueueNotMask <
 *       0x300000 tail-call EsiInstallChainCallCmpThreshold_0042fad0.
 *     - else (>= 0x370000): compute eax = g_eventQueueWorkType - 0x1999,
 *       store into g_acc_00542078, compare 0x54206c/0x542070 against it
 *       and select one of three tails:
 *         - if 0x54206c <  threshold: GuardedSeq_0042fba0
 *         - else if 0x542070 < threshold: GuardedSeq_0042fba0
 *         - else if 0x54206c < 0x542074: pick Mul10Triple0xd999Interp_0042fa10
 *           or SubCmpCallPauseJmp_0042fc40 (after stashing 0x5381cc into
 *           g_currentNodeIdx)
 *         - else (>= 0x542074): GuardedSeq_0042fb80 or SubCmpCallPauseJmp.
 */
extern unsigned int g_data_00538158;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;

__declspec(naked) void PhaseInstall2DInterpDispatch_0042f8a0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        test    ecx, ecx
        je      L_pii_phase0
        call    Distance2DSaturationClamp_004300a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        mov     ecx, dword ptr [g_data_00538158]
        mov     dword ptr [g_currentNodeIdx], ecx
        call    ChainFieldTest2Branch_0042fbc0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        mov     edx, dword ptr [g_data_0053815c]
        mov     dword ptr [g_currentNodeIdx], edx
        call    ChainFieldTest2Branch_0042fbc0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        call    LoadSetCallPauseStoreJmp_0042fea0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        call    MStackPush4DualCallAbsPop4_00430d30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        cmp     dword ptr [g_acc_00542078], 0xa3d
        jle     short L_pii_check2
        call    WalkTowardTargetFsm_004301e0
        pop     esi
        ret
    L_pii_check2:
        call    DualMul10ChainAcc7C_00430020
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_pii_done
        mov     eax, dword ptr [g_eventQueueNotMask]
        cmp     eax, 0x300000
        jge     short L_pii_check3
        call    EsiInstallChainCallCmpThreshold_0042fad0
        pop     esi
        ret
    L_pii_check3:
        mov     ecx, dword ptr [g_eventQueueWorkType]
        mov     esi, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_eventQueueCurrent]
        cmp     eax, 0x370000
        jl      short L_pii_sample
        lea     eax, [ecx - 0x1999]
        cmp     esi, eax
        mov     dword ptr [g_acc_00542078], eax
        jge     short L_pii_eaxOk
        call    GuardedSeq_0042fba0
        pop     esi
        ret
    L_pii_eaxOk:
        cmp     edx, eax
        jge     short L_pii_sample
        call    GuardedSeq_0042fba0
        pop     esi
        ret
    L_pii_sample:
        cmp     esi, ecx
        jge     short L_pii_storeEdx
        cmp     edx, ecx
        jge     short L_pii_storeEsi
        call    Mul10Triple0xd999Interp_0042fa10
        pop     esi
        ret
    L_pii_storeEsi:
        mov     eax, dword ptr [g_data_0053815c]
        mov     dword ptr [g_acc_00542078], esi
        mov     dword ptr [g_currentNodeIdx], eax
        call    SubCmpCallPauseJmp_0042fc40
        pop     esi
        ret
    L_pii_storeEdx:
        cmp     edx, ecx
        jle     short L_pii_writeEdx
        call    GuardedSeq_0042fb80
        pop     esi
        ret
    L_pii_writeEdx:
        mov     dword ptr [g_acc_00542078], edx
        call    SubCmpCallPauseJmp_0042fc40
        pop     esi
        ret
    L_pii_phase0:
        mov     ecx, 1
        mov     dword ptr [eax + 8], offset PhaseInstall2DInterpDispatch_0042f8a0
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
    L_pii_done:
        pop     esi
        ret
    }
}
