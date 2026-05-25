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
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern unsigned int g_data_0049db40;
extern unsigned int g_data_004d62a8;
extern unsigned int g_data_004d62e8;
extern unsigned int g_data_0053813c;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueNotMask;
extern void CallSetPause_0041f830(void);
extern void LinkedListFieldAdd_0049d450(void);
extern void MStackCall_00406600(void);
extern void MStackCall_00406740(void);
extern void MStackPop8_004ab860(void);
extern void MStackPush8_004ab790(void);
extern void MStackPushNegMul10Var_0040a730(void);
extern void MStackPushZeroCallPop_004066f0(void);
extern void StackPushAdd15CallPop_0040a7e0(void);
extern void StoreDoubleNegPauseSubStore_004ab750(void);
extern void ZeroThreeFields_0040a8b0(void);

__declspec(naked) void Phase4InitWithChainCallback_0040e860(void)
{
    __asm {
        call    MStackPush8_004ab790
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_A_ret
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        inc     eax
        push    0xC0
        mov     dword ptr [g_state_004d57ac], eax
        push    offset g_data_0049db40
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, offset g_data_004d62e8
        mov     dword ptr [g_eventQueueEnd], edx
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_data_0053813c], eax
        mov     eax, offset g_data_004d62a8
        mov     dword ptr [g_eventQueueNotMask], 0xC1
        shr     eax, 2
        mov     dword ptr [g_eventQueueIdx], eax
        call    StoreTwoCall_0049cb40
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 8
        test    al, 1
        jne     L_p4iwcc_A_pop_tail
        call    StackPushAdd15CallPop_0040a7e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_A_ret
        call    ZeroThreeFields_0040a8b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_A_ret
    L_p4iwcc_A_pop_tail:
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_state_004d57ac], eax
        jmp     MStackPop8_004ab860
    L_p4iwcc_A_ret:
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
        nop
    L_p4iwcc_B:
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_p4iwcc_B_phase0
        call    MStackCall_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        call    CallSetPause_0041f830
        pop     esi
        ret
    L_p4iwcc_B_phase0:
        mov     ecx, dword ptr [g_data_0053813c]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0x5C
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x30], eax
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackPushZeroCallPop_004066f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        call    MStackCall_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        mov     dword ptr [g_eventQueueNotMask], 0x2E14
        mov     dword ptr [g_walkCallback], 0x4CCC
        call    StoreDoubleNegPauseSubStore_004ab750
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail_00404af0
        mov     edx, dword ptr [g_xformEntityIdx]
        add     esp, 8
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     ecx, dword ptr [edx*4]
        push    ecx
        push    eax
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_fightGroupHead]
        add     esp, 8
        inc     ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [edx*4 + 0x70], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_eventQueueNotMask]
        mov     ecx, dword ptr [eax*4]
        push    ecx
        push    edx
        call    Mul10Tail_00404af0
        mov     ecx, dword ptr [g_xformEntityIdx]
        add     esp, 8
        inc     ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        call    MStackPushNegMul10Var_0040a730
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x6C], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [edx*4 + 0x74], eax
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [ecx*4 + 0x18]
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_currentNodeIdx], edx
        mov     eax, dword ptr [ecx*4]
        neg     eax
        inc     ecx
        add     eax, 0x4B5C2
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_data_0053813c], ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x44], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4]
        or      ecx, 8
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [eax*4 + 0x48], 0x4000
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x0040E840
        mov     dword ptr [ecx*4 + 0x14], 0xFF
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x10], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x2C]
        add     edx, 0x1B
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_xformEntityIdx], edx
        call    LinkedListFieldAdd_0049d450
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4iwcc_B_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0040E920
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 0x19
        mov     dword ptr [g_framePauseFlag], eax
    L_p4iwcc_B_exit:
        pop     esi
        ret
    }
}
