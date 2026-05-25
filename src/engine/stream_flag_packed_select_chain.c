/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_state_0053a718;
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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* @addr 0x00469340 (364b game) - cdecl chain with stream-flag swap +
 *   packed_ptr select. Sets g_walkCallback=0x52, calls
 *   TableLookupCall_00489ff0; on no-error sets 0x54206c=0xa, calls
 *   ScaledIndexConditionalAdd_0048e400. Then dispatches on
 *   g_baseSel_00542060:
 *     - matches g_gtPlayerProbe2: if g_data_0054388c is set, picks
 *       &g_data_004ec050>>2 (state 1) or &g_data_004ec040>>2 (other)
 *       into g_eventQueueTotal, clears g_data_0054388c, jumps to next.
 *     - matches g_gtPlayerProbe1: mirror with g_data_00543890.
 *     - default: both g_eventQueueTotal and 0x54204c set to the two
 *       packed_ptrs, zeroes g_eventQueueChild, calls
 *       GuardedDualConst2AndToggle_0048eba0. If bit 0 of 0x54208c set,
 *       sets g_eventQueueChild=1 and copies 0x54204c into 0x542050; else
 *       keeps 0x542050.
 *   Tail: copies chosen base into 0x542044, calls Mul10SumStoreNegCommit_00490970, pushes
 *   0x542a58 and calls GuardedPackedSlotInit_00428760, then
 *   MStackPush3CmpCall_0048eec0. If bit 0 of 0x54208c set, calls
 *   PendingMatch_004694b0. Then tail-jmp ScaledChainJmp_00429470 or
 *   ScaledClearJmp_00428d60 depending on g_eventQueueChild.
 */
extern unsigned int g_data_004ec040;
extern unsigned int g_data_004ec050;
extern unsigned int g_data_00542a58;
extern unsigned int g_data_0054388c;
extern unsigned int g_data_00543890;
extern void GuardedPackedSlotInit_00428760(void);
extern void Mul10SumStoreNegCommit_00490970(void);
extern void PendingMatch_004694b0(void);
extern void ScaledChainJmp_00429470(void);
extern void ScaledClearJmp_00428d60(void);
extern void ScaledIndexConditionalAdd_0048e400(void);
extern void TableLookupCall_00489ff0(void);

__declspec(naked) void StreamFlagPackedSelectChain_00469340(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x52
        call    TableLookupCall_00489ff0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sfp_done
        mov     dword ptr [g_walkCallback], 0xa
        call    ScaledIndexConditionalAdd_0048e400
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sfp_done
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [g_gtPlayerProbe2]
        cmp     ecx, eax
        jne     short L_sfp_check2
        mov     eax, dword ptr [g_data_0054388c]
        test    eax, eax
        je      short L_sfp_check2
        cmp     eax, 1
        mov     eax, offset g_data_004ec050
        je      short L_sfp_useEax1
        mov     eax, offset g_data_004ec040
    L_sfp_useEax1:
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_data_0054388c], 0
        jmp     L_sfp_callBlock
    L_sfp_check2:
        cmp     ecx, dword ptr [g_gtPlayerProbe1]
        jne     short L_sfp_defaultPath
        mov     eax, dword ptr [g_data_00543890]
        test    eax, eax
        je      short L_sfp_defaultPath
        cmp     eax, 1
        mov     eax, offset g_data_004ec050
        je      short L_sfp_useEax2
        mov     eax, offset g_data_004ec040
    L_sfp_useEax2:
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_data_00543890], 0
        jmp     short L_sfp_callBlock
    L_sfp_defaultPath:
        mov     eax, offset g_data_004ec040
        mov     ecx, offset g_data_004ec050
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_eventQueueTotal], ecx
        mov     dword ptr [g_eventQueueChild], 0
        call    GuardedDualConst2AndToggle_0048eba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sfp_done
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     eax, 1
        je      short L_sfp_useSecond
        mov     dword ptr [g_eventQueueChild], 1
    L_sfp_useSecond:
        test    eax, eax
        je      short L_sfp_useStored
        mov     eax, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_eventQueueTotal], eax
        jmp     short L_sfp_callBlock
    L_sfp_useStored:
        mov     eax, dword ptr [g_eventQueueTotal]
    L_sfp_callBlock:
        mov     dword ptr [g_currentNodeIdx], eax
        call    Mul10SumStoreNegCommit_00490970
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sfp_done
        push    offset g_data_00542a58
        call    GuardedPackedSlotInit_00428760
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     short L_sfp_done
        call    MStackPush3CmpCall_0048eec0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sfp_done
        test    byte ptr [g_xformDirtyFlags], 1
        je      short L_sfp_skipCallb0
        call    PendingMatch_004694b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sfp_done
    L_sfp_skipCallb0:
        mov     eax, dword ptr [g_eventQueueChild]
        test    eax, eax
        jne     short L_sfp_tailClear
        jmp     ScaledChainJmp_00429470
    L_sfp_tailClear:
        jmp     ScaledClearJmp_00428d60
    L_sfp_done:
        ret
    }
}
