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

/* @addr 0x0040e190 (369b boot) - 3-entry packed mstack-scoped init + alarms.
 *   Entry 1 (offset 0, 180b): MStackPush8_004ab790, then on no-error
 *     mstack-pushes g_eventQueueNotMask, caches g_fightGroupHead into 0x542054,
 *     sets g_walkCallback = &g_data_004d62e8>>2 (stored also in 0x5381 3c),
 *     g_eventQueueIdx = &g_data_004d61d8>>2, g_eventQueueNotMask = 0xc1.
 *     Pushes 0x49db40, 0xc0 onto StoreTwoCall_0049cb40. If bit 0 of
 *     0x54208c clear, calls StackPushAdd15CallPop_0040a7e0 +
 *     ZeroThreeFields_0040a8b0. Pops the snapshot back and tail-jmps
 *     MStackPop8_004ab860.
 *   12b NOP align pad.
 *   Entry 2 (offset 0xc0, 83b): sets 0x54207c=0x2666, 0x54206c=0x170a;
 *     calls StoreDoubleNegPauseSubStore_004ab750; on no-error computes
 *     g_walkCallback += 0x10000, multiplies via Mul10Tail_00404af0
 *     (push twice with the cur cj), negates, and tail-jmps PendingMatch_0040e310.
 *   13b NOP align pad.
 *   Entry 3 (offset 0x120, 81b): mirror of entry 2 with 0x3333 / 0x7ae
 *     constants; no negation before final store; tail-jmps PendingMatch_0040e310.
 */
extern unsigned int g_data_004d61d8;
extern unsigned int g_data_004d62e8;
extern unsigned int g_data_0053813c;
extern unsigned int g_framePauseFlag;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_table_004d57b0;
extern void MStackPop8_004ab860(void);
extern void MStackPush8_004ab790(void);
extern void PendingMatch_0040e310(void);
extern void StackPushAdd15CallPop_0040a7e0(void);
extern void StoreDoubleNegPauseSubStore_004ab750(void);
extern void ZeroThreeFields_0040a8b0(void);

__declspec(naked) void MStackInitTriAlarm_0040e190(void) {
    __asm {
        call    MStackPush8_004ab790
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_msi_e1Ret
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        inc     eax
        push    0xc0
        mov     dword ptr [g_state_004d57ac], eax
        push    0x49db40
        mov     dword ptr [eax*4 + g_table_004d57b0], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, offset g_data_004d62e8
        mov     dword ptr [g_eventQueueEnd], edx
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_data_0053813c], eax
        mov     eax, offset g_data_004d61d8
        mov     dword ptr [g_eventQueueNotMask], 0xc1
        shr     eax, 2
        mov     dword ptr [g_eventQueueIdx], eax
        call    StoreTwoCall_0049cb40
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 8
        test    al, 1
        jne     short L_msi_skipAlarm
        call    StackPushAdd15CallPop_0040a7e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e1Ret
        call    ZeroThreeFields_0040a8b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e1Ret
    L_msi_skipAlarm:
        mov     eax, dword ptr [g_state_004d57ac]
        mov     ecx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_state_004d57ac], eax
        jmp     MStackPop8_004ab860
    L_msi_e1Ret:
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
        /* entry 2 (offset 0xc0) */
    L_msi_entry2:
        mov     dword ptr [g_eventQueueNotMask], 0x2666
        mov     dword ptr [g_walkCallback], 0x170a
        call    StoreDoubleNegPauseSubStore_004ab750
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e2End
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_eventQueueNotMask], eax
        neg     eax
        mov     dword ptr [g_walkCallback], eax
        jmp     PendingMatch_0040e310
    L_msi_e2End:
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
        nop
        /* entry 3 (offset 0x120) */
    L_msi_entry3:
        mov     dword ptr [g_eventQueueNotMask], 0x3333
        mov     dword ptr [g_walkCallback], 0x7ae
        call    StoreDoubleNegPauseSubStore_004ab750
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e3End
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail_00404af0
        add     esp, 8
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     dword ptr [g_walkCallback], eax
        jmp     PendingMatch_0040e310
    L_msi_e3End:
        ret
    }
}
