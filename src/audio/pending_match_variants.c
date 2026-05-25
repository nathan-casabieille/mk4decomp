/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
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
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

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
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern void PendingMatch_004a3400(void);
extern void Thunk_004c48b0(void);

/*
 * AudioFlagPair3EntryDeinit_004a2720 - 149b audio deinit variant of AudioModeInit_004a2610.
 *   Main (0x004a2720): if g_gtModeFlag == 1 → store (0x53a408,0x53a3e0)>>2 to
 *     (g_currentNodeIdx,g_xformEntityIdx); else (0x537e88,0x53a700)>>2; call
 *     DualScaledStoreConst, ClearTwoCallSetStore; g_dlMode=0; call
 *     SixCallSeqPushImm; g_eventQueueWorkType=0; call Push16Call; if !paused
 *     tail-jmp PendingMatch_004a3400; ret.
 *   Pad-aligned bare-ret entry (0x004a27a0).
 *   Pad-aligned tail-jmp Thunk_004c48b0 (0x004a27b0).
 */
extern unsigned int g_byte_004d50b4;
extern unsigned int g_data_004f31cc;
extern unsigned int g_data_004f31d0;
extern unsigned int g_data_004f3220;
extern unsigned int g_data_004f3a30;
extern unsigned int g_data_004f3a38;
extern unsigned int g_table_004f3ac8;
extern unsigned int g_tickFlagF;
extern unsigned int g_load_0052ab10;
extern unsigned int g_bootInitState_00535de4;
extern unsigned int g_particleEmitterNode_00535e6c;
extern s32 g_dlNalt1;
extern unsigned int g_data_00538088;
extern s32 g_dlNalt2;
extern unsigned int g_phaseIdx_0053a50c;
extern unsigned int g_counter_0053a51c;
extern unsigned int g_data_0053a7a8;
extern unsigned int g_audioCrewState_00541d8c;
extern unsigned int g_savedNode_00541f98;
extern unsigned int g_phaseCounter_00541fb0;
extern u32 g_dlMode;
extern unsigned int g_audioPathFlag_0054355c;
extern u8 g_dlEnabledFlag;
extern unsigned int g_data_005437f8;
extern unsigned int g_data_005437fc;
extern unsigned int g_x_004f3ae4;
extern unsigned int g_x_004f3ae8;
extern unsigned int g_counter_005433c8;
extern void Audio11SlotInitLoop_004a5540(void);
extern void AudioStoreXfer3SelfInstall_004a2060(void);
extern void CallDualStoreXorBit_004285e0(void);
extern void ChainInitDoublePushCall_004a47c0(void);
extern void ClearTwoCallSetStore_004a2270(void);
extern void CopyGlobal_004ac1f0(void);
extern void DoublePushCallDualPopJmp_00423270(void);
extern void DownloadPlayerChar(void);
extern void DualAddSar_004ab600(void);
extern void DualScaledStoreConst_004a22c0(void);
extern void GuardedSetupCallTailJmp_004a1fa0(void);
extern void InstallChainInitTailJmp_004a7030(void);
extern void KonquestPortalCluster_004a5290(void);
extern void MStackBracket3_FieldSequentialCopy_00411d80(void);
extern void MStackPush2ChainLLInsert_00406790(void);
extern void MStackPushComplexCallPop_004064b0(void);
extern void PendingMatch_00401b70(void);
extern void Phase1ChainAdvanceCallScale_00418f80(void);
extern void ScaledAnd4InvDirtyClear_00409350(void);
extern void ScaledArrStore_004285c0(void);
extern void ScaledClearTripleCallJmp_004202c0(void);
extern void ScaledOr4DirtyClear_00409320(void);
extern void ScaledSet1OnNonZero_0048c190(void);
extern void SetJmp_004a1ac0(void);
extern void SetJmp_004a1ad0(void);
extern void SixCallSeqPushImm_004a1d80(void);
extern void TablePushAccumTailJmp_00429e30(void);
extern void TestCmpZeroFour_004238b0(void);
extern void VoiceBankTickDispatch_004a3120(void);

extern unsigned int g_byte_005435a1;
extern unsigned int g_byte_005435a2;
extern unsigned int g_byte_00543619;
extern unsigned int g_byte_0054361a;
extern unsigned int g_data_004f3a58;
extern unsigned int g_data_004f3a70;
extern unsigned int g_data_004f3a98;
extern unsigned int g_data_004f3aa8;
extern unsigned int g_data_0050b118;
extern unsigned int g_data_0050f114;
extern unsigned int g_count_005433b8;
extern unsigned int g_data_005433bc;
extern unsigned int g_audioBankPick_005433c0;
extern unsigned int g_data_005433cc;
extern unsigned int g_audioMicroEntry_005433f4;
extern unsigned int g_data_005433f8;
extern unsigned int g_counter_0054359c;
extern unsigned int g_byte_005435a0;
extern unsigned int g_data_005435a3;
extern unsigned int g_data_005435a4;
extern unsigned int g_byte_005435b8;
extern unsigned int g_byte_00543724;
extern unsigned int g_byte_0054372c;
extern unsigned int g_byte_00543730;
extern unsigned int g_data_005437f4;
extern unsigned int g_audioPreloadState_00543830;
extern void AudioBindEntry_004a1e40(void);
extern void AudioInitArgs3_004a1f20(void);
extern void AudioInstallSelfStateMachine2_004a85c0(void);
extern void AudioInstallSelfStatePush_004aa8a0(void);
extern void AudioPreloadStreamingTrack_004a6e70(void);
extern void AudioState50b4BitDispatcher_004a32c0(void);
extern void BootInitGuardedCallChain_004265d0(void);
extern void CallSetPause_0041f830(void);
extern void CmpByteJmp_004a4180(void);
extern void DispatcherComplex260_00407400(void);
extern void DrainQueueCallEach_004a1ec0(void);
extern void DualCallSetByte_004a1cb0(void);
extern void FiveTableWalkInit_00403c90(void);
extern void IncCapped3e7_00491920(void);
extern void InstallSelfPackedF80_00426000(void);
extern void IsNonzeroBoolFlagged_004a1d00(void);
extern void LoadGeoAsset_Default(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void MemcpyByteN_004a5680(void);
extern void Memset18Step_004a56a0(void);
extern void PendingMatch_004a2a80(void);
extern void PendingMatch_004a56c0(void);
extern void PendingMatch_004a62b0(void);
extern void PendingMatch_004a8ca0(void);
extern void PendingMatch_004a93c0(void);
extern void PendingMatch_004aa9f0(void);
extern void Push16Call_00489f50(void);
extern void QuadCallPhase2_004be800(void);
extern void ScaledByteIdxDualCopy_004a3260(void);
extern void SnapshotDirtyMark_004a1dc0(void);
extern void TableWalkBoundedCmp_004bd890(void);
extern void TableWalkChainCall_004a30f0(void);
extern void TestByteOrAndCheck_004a1ae0(void);
extern void TripleCallByteCheck_004a1bf0(void);
extern void TripleCallSetCopy_004a4880(void);
extern void VoicePoolTickDispatch_004a4c10(void);

__declspec(naked) void AudioFlagPair3EntryDeinit_004a2720(void)
{
    __asm
    {
        cmp     byte ptr [g_gtModeFlag], 1
        jne     short L_modeB
        mov     eax, 0x0053a408
        mov     ecx, 0x0053a3e0
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        jmp     short L_common
    L_modeB:
        mov     edx, 0x00537e88
        mov     eax, 0x0053a700
        shr     edx, 2
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_xformEntityIdx], eax
    L_common:
        call    DualScaledStoreConst_004a22c0
        call    ClearTwoCallSetStore_004a2270
        mov     dword ptr [g_dlMode], 0
        call    SixCallSeqPushImm_004a1d80
        mov     dword ptr [g_eventQueueWorkType], 0
        call    Push16Call_00489f50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_main_ret
        jmp     PendingMatch_004a3400
    L_main_ret:
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        jmp     Thunk_004c48b0
    }
}


/*
 * AudioInitLoopTriple_004a7840 - 237b audio 2-entry init + triple-loop body.
 *   Entry 0x004a7840: g_xformEntityIdx = (0x0050f114 >> 2); call DispatcherComplex260;
 *     if paused: ret. push 0x13333; SnapshotDirtyMark; MStackPushComplexCallPop;
 *     if paused: ret. chain[g_currentNodeIdx*4 + 0x5c] = 0x00100000; ret.
 *   16b-aligned body 0x004a7890: g_eventQueueWorkType = 0x32a; Push16Call.
 *     Loop1 (esi: byte-table at 0x004f3b48 to 0x004f3c20 step 0x24): chain[(g_baseSel+byte)*4],
 *       call MStackPush2ChainLLInsert_00406790. Loop2 (esi 0..5): chain[(g_baseSel+esi)*4 + 0x34], call.
 *     Loop3 (esi 0..5): chain[(g_baseSel+esi)*4 + 0x48], call. DrainQueueCallEach.
 *     if [0x005433f4] == 2: tail-call PendingMatch_004a8ca0 else AudioInstallSelfStateMachine2_004a85c0.
 */
__declspec(naked) void AudioInitLoopTriple_004a7840(void)
{
    __asm
    {
        mov     eax, offset g_data_0050f114
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    DispatcherComplex260_00407400
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_e0_ret
        push    0x13333
        call    SnapshotDirtyMark_004a1dc0
        add     esp, 4
        call    MStackPushComplexCallPop_00406430
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_e0_ret
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [ecx*4 + 0x5c], 0x00100000
    L_e0_ret:
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        push    esi
        mov     dword ptr [g_eventQueueWorkType], 0x32a
        call    Push16Call_00489f50
        mov     esi, 0x004f3b48
    L_loop1:
        movsx   eax, byte ptr [esi]
        mov     ecx, dword ptr [g_baseSel_00542060]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert_00406790
        add     esi, 0x24
        cmp     esi, 0x004f3c20
        jb      short L_loop1
        xor     esi, esi
    L_loop2:
        mov     eax, dword ptr [g_baseSel_00542060]
        lea     ecx, [esi + eax]
        mov     edx, dword ptr [ecx*4 + 0x34]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert_00406790
        inc     esi
        cmp     esi, 5
        jl      short L_loop2
        xor     esi, esi
    L_loop3:
        mov     eax, dword ptr [g_baseSel_00542060]
        lea     ecx, [esi + eax]
        mov     edx, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert_00406790
        inc     esi
        cmp     esi, 5
        jl      short L_loop3
        call    DrainQueueCallEach_004a1ec0
        cmp     dword ptr [g_audioMicroEntry_005433f4], 2
        jne     short L_tail85c0
        call    PendingMatch_004a8ca0
        pop     esi
        ret
    L_tail85c0:
        call    AudioInstallSelfStateMachine2_004a85c0
        pop     esi
        ret
    }
}

extern void func_004a2080(void);

/*
 * AudioBank2StatePickerWalk_004a9270 - 324b audio 2-bank state picker and roundrobin walk.
 *   g_walkCallback=0; CopyGlobal_004ac1f0; func_004a2080.
 *   eax = g_audioBankSel_00537f94; edx = g_counter_0054359c; edi = g_counter_005433c8.
 *   If eax == 1: chain low table [edi*24 + 0x0054361a/19] += 1.
 *   Else: chain high table [edx*24 + 0x005435a2/a1] += 1.
 *   ++g_bootInitState_00535de4. esi=1. ecx=g_x_004f3ae4; walk g_byte_005435a2[i*24] for i in [0,ecx);
 *     if any !=0: keep esi=1; else esi=0. If esi: g_audioBankPick_005433c0=2; tail to cleanup.
 *   Else: ebp=g_x_004f3ae8; esi=1. Walk g_byte_0054361a[i*24] for i in [0,ebp). If esi: g_audioBankPick_005433c0=1;
 *     cleanup: zero g_counter_0054359c, g_counter_005433c8; call PendingMatch_004a93c0; pop+ret.
 *   Else (both banks have something nonzero): eax = g_audioBankSel_00537f94 again.
 *     If eax==2: roundrobin edx through ecx slots looking for g_byte_005435a2[edx*24]!=0; store to g_counter_0054359c.
 *     If eax==1: roundrobin edi through ebp slots looking for g_byte_0054361a[edi*24]!=0; store to g_counter_005433c8.
 *     call PendingMatch_004a93c0; pop+ret.
 */
__declspec(naked) void AudioBank2StatePickerWalk_004a9270(void)
{
    __asm
    {
        push    ebp
        push    esi
        push    edi
        mov     dword ptr [g_walkCallback], 0
        call    CopyGlobal_004ac1f0
        call    func_004a2080
        mov     eax, dword ptr [g_audioBankSel_00537f94]
        mov     edx, dword ptr [g_counter_0054359c]
        mov     edi, dword ptr [g_counter_005433c8]
        cmp     eax, 1
        jne     short L_a92_highBank
        lea     eax, [edi + edi*2]
        shl     eax, 3
        mov     byte ptr [eax + g_byte_0054361a], 1
        mov     cl, byte ptr [eax + g_byte_00543619]
        inc     cl
        mov     byte ptr [eax + g_byte_00543619], cl
        jmp     short L_a92_afterStore
    L_a92_highBank:
        lea     eax, [edx + edx*2]
        shl     eax, 3
        mov     byte ptr [eax + g_byte_005435a2], 1
        mov     cl, byte ptr [eax + g_byte_005435a1]
        inc     cl
        mov     byte ptr [eax + g_byte_005435a1], cl
    L_a92_afterStore:
        mov     ecx, dword ptr [g_bootInitState_00535de4]
        mov     esi, 1
        inc     ecx
        mov     dword ptr [g_bootInitState_00535de4], ecx
        mov     ecx, dword ptr [g_x_004f3ae4]
        test    ecx, ecx
        jle     short L_a92_checkLow
        mov     eax, offset g_byte_005435a2
    L_a92_walkHigh:
        cmp     byte ptr [eax], 0
        jne     short L_a92_walkHighCont
        xor     esi, esi
    L_a92_walkHighCont:
        add     eax, 0x18
        dec     ecx
        jne     short L_a92_walkHigh
    L_a92_checkLow:
        test    esi, esi
        je      short L_a92_lowBankCheck
        mov     dword ptr [g_audioBankPick_005433c0], 2
        jmp     short L_a92_cleanup
    L_a92_lowBankCheck:
        mov     ebp, dword ptr [g_x_004f3ae8]
        mov     esi, 1
        test    ebp, ebp
        jle     short L_a92_decideSet
        mov     eax, offset g_byte_0054361a
        mov     ecx, ebp
    L_a92_walkLow:
        cmp     byte ptr [eax], 0
        jne     short L_a92_walkLowCont
        xor     esi, esi
    L_a92_walkLowCont:
        add     eax, 0x18
        dec     ecx
        jne     short L_a92_walkLow
    L_a92_decideSet:
        test    esi, esi
        je      short L_a92_walkPicks
        mov     dword ptr [g_audioBankPick_005433c0], 1
    L_a92_cleanup:
        mov     dword ptr [g_counter_0054359c], 0
        mov     dword ptr [g_counter_005433c8], 0
        call    PendingMatch_004a93c0
        pop     edi
        pop     esi
        pop     ebp
        ret
    L_a92_walkPicks:
        mov     eax, dword ptr [g_audioBankSel_00537f94]
        cmp     eax, 2
        jne     short L_a92_checkLowPick
    L_a92_rrHigh:
        mov     ecx, dword ptr [g_x_004f3ae4]
        inc     edx
        cmp     edx, ecx
        jne     short L_a92_rrHighSkip
        xor     edx, edx
    L_a92_rrHighSkip:
        lea     ecx, [edx + edx*2]
        cmp     byte ptr [ecx*8 + g_byte_005435a2], 0
        jne     short L_a92_rrHigh
        mov     dword ptr [g_counter_0054359c], edx
    L_a92_checkLowPick:
        cmp     eax, 1
        jne     short L_a92_callEnd
    L_a92_rrLow:
        inc     edi
        cmp     edi, ebp
        jne     short L_a92_rrLowSkip
        xor     edi, edi
    L_a92_rrLowSkip:
        lea     edx, [edi + edi*2]
        mov     al, byte ptr [edx*8 + g_byte_0054361a]
        test    al, al
        jne     short L_a92_rrLow
        mov     dword ptr [g_counter_005433c8], edi
    L_a92_callEnd:
        call    PendingMatch_004a93c0
        pop     edi
        pop     esi
        pop     ebp
        ret
    }
}

extern int RetZero_004a1c40(void);

__declspec(naked) void AudioStateInitMultiInstall_004a4d20(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    ebx
        push    esi
        push    edi
        lea     edi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [edi + 0x84], 0
        sub     eax, 0
        je      L_asimi_phase0
        dec     eax
        je      short L_asimi_phase1
        mov     dword ptr [g_data_005437f4], 1
        call    PendingMatch_004a2a80
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_asimi_phase1:
        call    VoicePoolTickDispatch_004a4c10
        push    0x4f3830
        call    ScaledByteIdxDualCopy_004a3260
        add     esp, 4
        push    0x4f3830
        call    AudioState50b4BitDispatcher_004a32c0
        add     esp, 4
        call    TripleCallByteCheck_004a1bf0
        test    eax, eax
        mov     ebx, 1
        je      short L_asimi_skipDispatch
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 0x30]
        lea     edx, [eax + eax*8]
        mov     eax, dword ptr [edx*4 + 0x4f383c]
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        je      short L_asimi_checkFlag
        call    eax
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_asimi_ret
    L_asimi_checkFlag:
        test    byte ptr [g_xformDirtyFlags], bl
        jne     short L_asimi_skipRetZero
    L_asimi_skipDispatch:
        call    RetZero_004a1c40
        test    eax, eax
        je      L_asimi_install2
    L_asimi_skipRetZero:
        mov     dword ptr [g_eventQueueWorkType], 0x32f
        call    Push16Call_00489f50
        call    VoicePoolTickDispatch_004a4c10
        mov     dword ptr [g_eventQueueCurrent], 0x20
        mov     dword ptr [edi + 8], offset AudioStateInitMultiInstall_004a4d20
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, offset AudioStateInitMultiInstall_004a4d20
        add     ecx, 0x2000000
        mov     dword ptr [eax*4 + 0x84], 2
        mov     eax, dword ptr [edi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [edi + 4], eax
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [edx*4 + 0x84], 0
        call    InstallSelfPackedF80_00426000
        mov     dword ptr [g_framePauseFlag], ebx
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_asimi_phase0:
        mov     ebx, 1
        mov     byte ptr [g_byte_00543724], bl
        mov     byte ptr [g_byte_0054372c], bl
        mov     byte ptr [g_byte_00543730], bl
        call    FiveTableWalkInit_00403c90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_asimi_ret
        call    TripleCallSetCopy_004a4880
        mov     esi, 0x4f384c
    L_asimi_loop:
        mov     ecx, dword ptr [esi]
        mov     eax, dword ptr [esi + 4]
        sub     ecx, 0x50000
        push    eax
        push    ecx
        push    0
        push    0x5159b8
        call    AudioInitArgs3_004a1f20
        movsx   edx, byte ptr [esi - 0xc]
        mov     eax, dword ptr [g_baseSel_00542060]
        add     esi, 0x24
        add     edx, eax
        add     esp, 0x10
        cmp     esi, 0x4f3924
        mov     dword ptr [edx*4], 0
        jb      short L_asimi_loop
        push    0x4f6358
        call    AudioBindEntry_004a1e40
        mov     eax, dword ptr [g_baseSel_00542060]
        add     esp, 4
        mov     dword ptr [eax*4 + 0x30], 5
    L_asimi_install2:
        mov     dword ptr [edi + 8], offset AudioStateInitMultiInstall_004a4d20
        mov     dword ptr [edi + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], ebx
        mov     dword ptr [g_framePauseFlag], ebx
    L_asimi_ret:
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}

/* extern void AllocNode(void); -- defined elsewhere with diff sig */

__declspec(naked) void AudioPreloadStreamingTrack_004a6e70(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_6fc9
        push     8
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        push     7
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        call     BootInitGuardedCallChain_004265d0
        call     IncCapped3e7_00491920
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2_004be800
        add      esp, 0x10
        call     FiveTableWalkInit_00403c90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_702b
        mov      ecx, OFFSET g_data_0050b118
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_702b
        call     TripleCallSetCopy_004a4880
        mov      eax, dword ptr [g_count_005433b8]
        cmp      eax, 4
        mov      eax, dword ptr [g_audioBankSel_00537f94]
        jne      short L_6f3d
        mov      edx, dword ptr [g_audioPreloadState_00543830]
        cmp      eax, 1
        lea      eax, [edx*4]
        mov      ecx, dword ptr [eax + g_data_004f3a58]
        lea      ecx, [ecx + ecx*2]
        jne      short L_6f2e
        mov      eax, dword ptr [eax + g_data_004f3a98]
        lea      ecx, [ecx*8 + g_byte_005435a0]
        jmp      short L_6f7f
    L_6f2e:
        mov      eax, dword ptr [eax + g_data_004f3a98]
        lea      ecx, [ecx*8 + g_byte_005435b8]
        jmp      short L_6f7f
    L_6f3d:
        cmp      eax, 1
        jne      short L_6f5c
        mov      eax, dword ptr [g_audioPreloadState_00543830]
        shl      eax, 2
        mov      ecx, dword ptr [eax + g_data_004f3a70]
        lea      ecx, [ecx + ecx*2]
        lea      ecx, [ecx*8 + g_byte_005435a0]
        jmp      short L_6f79
    L_6f5c:
        mov      edx, dword ptr [g_audioPreloadState_00543830]
        lea      eax, [edx*4]
        mov      ecx, dword ptr [eax + g_data_004f3a70]
        lea      ecx, [ecx + ecx*2]
        lea      ecx, [ecx*8 + g_byte_005435b8]
    L_6f79:
        mov      eax, dword ptr [eax + g_data_004f3aa8]
    L_6f7f:
        lea      edx, [eax + eax*2]
        push     0x18
        push     ecx
        lea      eax, [edx*8 + g_byte_005435a0]
        push     eax
        call     MemcpyByteN_004a5680
        mov      ecx, dword ptr [g_audioPreloadState_00543830]
        add      esp, 0xc
        inc      ecx
        mov      dword ptr [g_pendingNodeType], OFFSET PendingMatch_004a62b0
        mov      dword ptr [g_audioPreloadState_00543830], ecx
        mov      dword ptr [g_eventQueueWorkType], 0x1000
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_702b
        jmp      CallSetPause_0041f830
    L_6fc9:
        mov      dword ptr [eax + 8], OFFSET AudioPreloadStreamingTrack_004a6e70
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, OFFSET AudioPreloadStreamingTrack_004a6e70
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     AudioInstallSelfStatePush_004aa8a0
        mov      dword ptr [g_framePauseFlag], 1
    L_702b:
        ret
    }
}

__declspec(naked) void PendingMatch_004a70f0(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebp
        push     esi
        push     edi
        lea      ebp, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [ebp + 0x84]
        mov      dword ptr [ebp + 0x84], edi
        cmp      eax, edi
        je       L_72fd
        mov      ecx, dword ptr [g_data_00538088]
        mov      dword ptr [g_fightGroupHead], ecx
        call     CallDualStoreXorBit_004285e0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        test     byte ptr [g_xformDirtyFlags], 4
        je       L_714c
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [edx*4 + 0x28], 0x2a
    L_714c:
        call     DualAddSar_004ab600
        test     byte ptr [g_walkCallback], 0xf
        jne      L_724e
        call     MStackPush2RunCountdown_004089e0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        call     MStackBracket7_DispatchAndChain_004b8fa0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      dword ptr [g_walkCallback], 9
        call     ChainDirtyBitWalker_00408c10
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_724e
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_savedNode_00541f98]
        add      ecx, 0xf
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [eax*4], edi
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 8], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 4], 0x28f
        call     MStackBracket3_FieldSequentialCopy_00411d80
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      eax, dword ptr [g_currentNodeIdx]
        cmp      eax, edi
        je       L_724e
        mov      eax, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      ecx, dword ptr [eax*4 + 0x28]
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      eax, dword ptr [ecx*4]
        or       al, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [edx*4 + 0x48], 0x8000
        mov      eax, dword ptr [g_currentNodeIdx]
        add      dword ptr [eax*4 + 0x58], 0x1999
    L_724e:
        mov      esi, dword ptr [g_load_0052ab10]
        mov      dword ptr [g_fightGroupHead], esi
        mov      ecx, dword ptr [esi*4 + 0x58]
        lea      eax, [ecx + 0x1a666]
        cdq      
        and      edx, 0x1f
        add      eax, edx
        sar      eax, 5
        neg      eax
        add      ecx, eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [esi*4 + 0x58], ecx
        mov      esi, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [esi*4 + 0x5c]
        lea      eax, [ecx + 0x60000]
        cdq      
        and      edx, 0x1f
        add      eax, edx
        sar      eax, 5
        neg      eax
        add      ecx, eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [esi*4 + 0x5c], ecx
        call     TripleCallByteCheck_004a1bf0
        test     eax, eax
        je       L_75df
        mov      dword ptr [g_eventQueueWorkType], 0x325
        call     Push16Call_00489f50
        call     BootInitGuardedCallChain_004265d0
        mov      dword ptr [g_pendingNodeType], 0x401b70
        mov      dword ptr [g_eventQueueWorkType], 0x1000
        call     AllocNode
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        call     CallSetPause_0041f830
        pop      edi
        pop      esi
        pop      ebp
        ret      
    L_72fd:
        mov      dword ptr [g_tickFlagF], 2
        mov      dword ptr [g_phaseIdx_0053a50c], 1
        call     BootInitGuardedCallChain_004265d0
        call     FiveTableWalkInit_00403c90
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        push     6
        call     TableWalkBoundedCmp_004bd890
        mov      eax, 0x50b10c
        add      esp, 4
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      ecx, 0x5032f0
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      edx, 0x505b8c
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_00407030
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_data_0053a7a8], eax
        call     ChainInitDoublePushCall_004a47c0
        mov      ecx, dword ptr [g_data_0053a7a8]
        mov      edx, 0x5063dc
        shr      edx, 2
        mov      dword ptr [ecx*4 + 0x58], 0xfffe8000
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_00407400
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      esi, 0xff800000
        shl      eax, 2
        mov      dword ptr [eax + 0x54], 0xff010000
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [eax + 0x58], esi
        call     PushSetCallPop_00406530
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      ecx, 0x5063f8
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DispatcherComplex260_00407400
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x54], edi
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [edx*4 + 0x58], esi
        lea      eax, [edx*4]
        call     PushSetCallPop_00406530
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        cmp      dword ptr [g_count_005433b8], 4
        jne      L_746c
        mov      eax, dword ptr [g_audioPreloadState_00543830]
        mov      eax, dword ptr [eax*4 + g_data_004f3a58]
        lea      ecx, [eax + eax*2]
        lea      esi, [ecx*8 + g_byte_005435a0]
        jmp      L_7483
    L_746c:
        mov      edx, dword ptr [g_audioPreloadState_00543830]
        mov      eax, dword ptr [edx*4 + g_data_004f3a70]
        lea      eax, [eax + eax*2]
        lea      esi, [eax*8 + g_byte_005435a0]
    L_7483:
        push     0x280000
        push     0x4d25a8
        call     GuardedSetupCallTailJmp_004a1fa0
        add      esp, 8
        push     0x5a0000
        push     0x4d25b8
        call     GuardedSetupCallTailJmp_004a1fa0
        add      esp, 8
        push     0xa50000
        push     0x4d25d0
        call     GuardedSetupCallTailJmp_004a1fa0
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      dword ptr [ecx*4 + 0x5c], 0x18000
        push     0x410000
        movsx    edx, byte ptr [esi + 1]
        mov      eax, dword ptr [edx*4 + g_data_004f3a38]
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp_004a1fa0
        mov      eax, dword ptr [g_load_0052ab10]
        add      esp, 8
        mov      dword ptr [g_fightGroupHead], eax
        push     0x4f3ad8
        push     eax
        call     AudioStoreXfer3SelfInstall_004a2060
        mov      dword ptr [g_eventQueueWorkType], edi
        add      esp, 8
        movsx    eax, byte ptr [esi]
        mov      dword ptr [g_eventQueueCurrent], edi
        movsx    eax, byte ptr [eax + g_table_004f3ac8]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_dlNalt1], eax
        call     DoublePushCallDualPopJmp_00423270
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_data_00538088], eax
        mov      dword ptr [eax*4 + 0x5c], 0xfffe8000
        mov      eax, dword ptr [g_particleEmitterNode_00535e6c]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [eax*4 + 0x34]
        or       edx, 0x80000
        mov      dword ptr [eax*4 + 0x34], edx
        mov      edx, 0x500320
        shr      edx, 2
        mov      dword ptr [g_eventQueueIdx], edx
        call     ScaledArrStore_004285c0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      eax, 0x506c5c
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        mov      ecx, 0x50b238
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        call     ScaledSet1OnNonZero_0048c190
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_75fb
        call     Phase1ChainAdvanceCallScale_00418f80
        call     InstallChainInitTailJmp_004a7030
        mov      dword ptr [g_eventQueueWorkType], 9
        call     Push16Call_00489f50
    L_75df:
        mov      eax, 1
        mov      dword ptr [ebp + 8], 0x4a70f0
        mov      dword ptr [ebp + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_75fb:
        pop      edi
        pop      esi
        pop      ebp
        ret      
    }
}


__declspec(naked) void PendingMatch_004a3400(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     ebp
        push     esi
        push     edi
        lea      edi, [eax*4]
        mov      ebp, 4
        xor      ebx, ebx
        mov      eax, dword ptr [edi + 0x84]
        mov      dword ptr [edi + 0x84], ebx
        cmp      eax, ebp
        ja       L_381d
        jmp      dword ptr [eax*4 + L_38b8_jmptbl]
        mov      al, byte ptr [g_fightTableC0]
        mov      esi, 3
        test     al, 0x20
        jne      L_34a1
        test     byte ptr [g_fightTableC1], 2
        jne      L_34a1
        mov      ecx, dword ptr [g_baseSel_00542060]
        cmp      dword ptr [ecx*4 + 0x30], esi
        jne      L_349b
        mov      eax, dword ptr [g_data_005433bc]
        inc      eax
        cmp      eax, 0x258
        mov      dword ptr [g_data_005433bc], eax
        jle      L_3483
        mov      dword ptr [g_eventQueueWorkType], 0xcc6
        call     Push16Call_00489f50
        call     AudioStateInitMultiInstall_004a4d20
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_3483:
        cmp      eax, 0x12c
        jne      L_34a1
        mov      dword ptr [g_eventQueueWorkType], 0x18bf
        call     Push16Call_00489f50
        jmp      L_34a1
    L_349b:
        mov      dword ptr [g_data_005433bc], ebx
    L_34a1:
        call     CmpByteJmp_004a4180
        call     VoiceBankTickDispatch_004a3120
        push     0x4f3250
        call     ScaledByteIdxDualCopy_004a3260
        add      esp, 4
        push     0x4f3250
        call     AudioState50b4BitDispatcher_004a32c0
        add      esp, 4
        call     TripleCallByteCheck_004a1bf0
        test     eax, eax
        je       L_358b
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [edx*4 + 0x30]
        cmp      eax, 7
        jne      L_352d
        mov      dword ptr [g_eventQueueWorkType], 0x32a
        call     Push16Call_00489f50
        call     VoiceBankTickDispatch_004a3120
        mov      dword ptr [g_eventQueueCurrent], 0x20
        mov      dword ptr [edi + 8], 0x4a3400
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, 0x4a3400
        add      ecx, 0x4000000
        mov      dword ptr [eax*4 + 0x84], ebp
        mov      eax, dword ptr [edi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      L_35dc
    L_352d:
        cmp      eax, 8
        jne      L_353c
        call     PendingMatch_004aa9f0
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_353c:
        cmp      eax, 9
        jne      L_358b
        mov      dword ptr [g_eventQueueWorkType], 0x32f
        call     Push16Call_00489f50
        call     VoiceBankTickDispatch_004a3120
        mov      dword ptr [g_eventQueueCurrent], 0x20
        mov      dword ptr [edi + 8], 0x4a3400
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, 0x4a3400
        add      ecx, 0x2000000
        mov      dword ptr [eax*4 + 0x84], 2
        mov      eax, dword ptr [edi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      L_35dc
    L_358b:
        call     RetZero_004a1c40
        test     eax, eax
        je       L_37fa
        mov      dword ptr [g_eventQueueWorkType], 0x32f
        call     Push16Call_00489f50
        call     VoiceBankTickDispatch_004a3120
        mov      dword ptr [g_eventQueueCurrent], 0x20
        mov      dword ptr [edi + 8], 0x4a3400
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, 0x4a3400
        add      ecx, 0x3000000
        mov      dword ptr [eax*4 + 0x84], esi
        mov      eax, dword ptr [edi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
    L_35dc:
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], ebx
        call     InstallSelfPackedF80_00426000
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        call     BootInitGuardedCallChain_004265d0
        mov      dword ptr [g_data_005437f4], 1
        call     PendingMatch_00401b70
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        call     PendingMatch_004a2a80
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        call     TableWalkChainCall_004a30f0
        call     FiveTableWalkInit_00403c90
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_38b1
        mov      al, byte ptr [g_data_005433f8]
        mov      ecx, dword ptr [g_data_004f31cc]
        mov      byte ptr [g_gtModeFlag], al
        mov      eax, dword ptr [g_data_005437f8]
        mov      edx, dword ptr [g_data_004f31d0]
        mov      dword ptr [g_counter_0053a51c], eax
        mov      eax, dword ptr [g_data_005437fc]
        mov      esi, 1
        mov      dword ptr [g_stateCountdown_0053a3c0], eax
        mov      dword ptr [g_phaseCounter_00541fb0], eax
        mov      eax, dword ptr [g_gtConfig4f]
        mov      dword ptr [g_dlNalt1], ecx
        cmp      eax, esi
        mov      dword ptr [g_dlNalt2], edx
        je       L_36e5
        cmp      dword ptr [g_active_00537e88], ebx
        jne      L_36bd
        mov      ecx, 0x537e88
        mov      edx, 0x53a700
        shr      ecx, 2
        shr      edx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_xformEntityIdx], edx
        call     DualScaledStoreConst_004a22c0
    L_36bd:
        cmp      dword ptr [g_active_0053a408], ebx
        jne      L_36e5
        mov      eax, 0x53a408
        mov      ecx, 0x53a3e0
        shr      eax, 2
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DualScaledStoreConst_004a22c0
    L_36e5:
        push     6
        call     TableWalkBoundedCmp_004bd890
        add      esp, 4
        call     SixCallSeqPushImm_004a1d80
        mov      dword ptr [edi + 8], 0x4a3400
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, 0x4a3400
        mov      dword ptr [edx*4 + 0x84], 5
        mov      eax, dword ptr [edi + 4]
        add      ecx, 0x5000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], ebx
        call     AudioInstallSelfStatePush_004aa8a0
        mov      dword ptr [g_framePauseFlag], esi
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        movsx    eax, byte ptr [g_gtModeFlag]
        mov      ebp, 1
        mov      dword ptr [g_gtState438], ebx
        mov      dword ptr [g_tickFlagF], 2
        mov      dword ptr [g_phaseIdx_0053a50c], ebp
        mov      dword ptr [g_data_005433f8], eax
        call     TripleCallSetCopy_004a4880
        mov      dword ptr [g_eventQueueWorkType], 9
        call     Push16Call_00489f50
        mov      dword ptr [g_eventQueueChild], 0x1c20
        mov      esi, 0x4f326c
    L_379b:
        mov      edx, dword ptr [esi]
        mov      ecx, dword ptr [esi + 4]
        sub      edx, 0x50000
        push     ecx
        push     edx
        push     ebx
        push     0x5159b8
        call     AudioInitArgs3_004a1f20
        movsx    eax, byte ptr [esi - 0xc]
        mov      edx, dword ptr [g_baseSel_00542060]
        add      esi, 0x24
        add      eax, edx
        add      esp, 0x10
        cmp      esi, 0x4f33d4
        mov      dword ptr [eax*4], ebx
        jb       L_379b
        push     0x4f6358
        call     AudioBindEntry_004a1e40
        mov      ecx, dword ptr [g_baseSel_00542060]
        add      esp, 4
        mov      dword ptr [ecx*4 + 0x30], 7
        mov      dword ptr [g_data_005433bc], ebx
        jmp      L_37ff
    L_37fa:
        mov      ebp, 1
    L_37ff:
        mov      dword ptr [edi + 8], 0x4a3400
        mov      dword ptr [edi + 0x84], ebp
        mov      dword ptr [g_pendingNodeType], ebp
        mov      dword ptr [g_framePauseFlag], ebp
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
    L_381d:
        mov      edx, dword ptr [g_counter_0053a51c]
        mov      dword ptr [g_walkCallback], edx
        call     TablePushAccumTailJmp_00429e30
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_38b1
        call     TestCmpZeroFour_004238b0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_38b1
        mov      ecx, dword ptr [g_dlNalt1]
        mov      eax, 0x535cfc
        shr      eax, 2
        mov      dword ptr [g_eventQueueEnd], eax
        mov      byte ptr [g_dlEnabledFlag], 1
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueCurrent], ebx
        call     DownloadPlayerChar
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_38b1
        mov      edx, dword ptr [g_dlNalt2]
        mov      esi, 1
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_eventQueueCurrent], esi
        call     DownloadPlayerChar
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_38b1
        mov      byte ptr [g_dlEnabledFlag], bl
        mov      dword ptr [g_tickFlagF], ebp
        mov      dword ptr [g_gtState438], esi
        call     ScaledClearTripleCallJmp_004202c0
    L_38b1:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret      
        mov      edi, edi
    L_38b8_jmptbl:
        /* 5-entry jump table */
        _emit    0x51
        _emit    0x37
        _emit    0x4a
        _emit    0x00
        _emit    0x32
        _emit    0x34
        _emit    0x4a
        _emit    0x00
        _emit    0x12
        _emit    0x36
        _emit    0x4a
        _emit    0x00
        _emit    0x2b
        _emit    0x36
        _emit    0x4a
        _emit    0x00
        _emit    0x35
        _emit    0x36
        _emit    0x4a
        _emit    0x00
    }
}


__declspec(naked) void PendingMatch_004a56c0(void)
{
    __asm {
        push     ebx
        push     esi
        push     edi
        mov      esi, 0x5435ac
        mov      ebx, 0xf
        xor      edi, edi
    L_56cf:
        mov      eax, dword ptr [esi - 4]
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackPush2ChainLLInsert_00406790
        mov      ecx, dword ptr [esi]
        mov      dword ptr [esi - 4], edi
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackPush2ChainLLInsert_00406790
        mov      edx, dword ptr [esi + 4]
        mov      dword ptr [esi], edi
        mov      dword ptr [g_currentNodeIdx], edx
        call     MStackPush2ChainLLInsert_00406790
        mov      eax, dword ptr [esi + 8]
        mov      dword ptr [esi + 4], edi
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackPush2ChainLLInsert_00406790
        mov      dword ptr [esi + 8], edi
        add      esi, 0x18
        dec      ebx
        jne      L_56cf
        pop      edi
        pop      esi
        pop      ebx
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        sub      esp, 0xc
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     ebp
        push     esi
        lea      ebx, [eax*4]
        push     edi
        xor      edi, edi
        mov      dword ptr [esp + 0x14], ebx
        mov      eax, dword ptr [ebx + 0x84]
        mov      dword ptr [ebx + 0x84], edi
        cmp      eax, edi
        je       L_5d35
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [ecx*4 + 0x34]
        cmp      eax, 0x8000
        jl       L_5773
        add      eax, 0xffff8000
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      ecx, dword ptr [g_baseSel_00542060]
    L_5773:
        mov      esi, dword ptr [ecx*4 + 0x38]
        mov      eax, dword ptr [ecx*4 + 0x3c]
        sub      eax, esi
        xor      ebp, ebp
        cdq      
        and      edx, 3
        add      eax, edx
        sar      eax, 2
        add      eax, esi
        mov      dword ptr [ecx*4 + 0x38], eax
        mov      eax, dword ptr [g_count_005433b8]
        cmp      eax, ebp
        jle      L_5ada
        mov      eax, 0x50a0f0
        mov      dword ptr [esp + 0x10], ebp
        shr      eax, 2
        mov      dword ptr [esp + 0x18], eax
        mov      ebp, 0x4f3a38
        mov      esi, 0x5435a8
        mov      ebx, 0xffc40000
    L_57c3:
        mov      ecx, dword ptr [esi]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackPush2ChainLLInsert_00406790
        mov      edx, dword ptr [esi + 8]
        mov      dword ptr [g_currentNodeIdx], edx
        call     MStackPush2ChainLLInsert_00406790
        mov      eax, dword ptr [esi + 0xc]
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackPush2ChainLLInsert_00406790
        movsx    ecx, byte ptr [esi - 8]
        mov      eax, dword ptr [esp + 0x18]
        add      ecx, eax
        mov      dword ptr [g_xformEntityIdx], eax
        mov      eax, dword ptr [ecx*4]
        and      eax, 0xffffff
        mov      dword ptr [g_xformEntityIdx], eax
        mov      edx, dword ptr [eax]
        sar      edx, 2
        and      edx, 0x3fffff
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_00407400
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5e93
        call     MStackPushComplexCallPop_00406430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5e93
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      edx, dword ptr [esp + 0x10]
        mov      ecx, dword ptr [eax*4 + 0x38]
        lea      eax, [ecx + edx - 0x1000000]
        mov      dword ptr [g_audioCrewState_00541d8c], eax
        mov      al, byte ptr [g_xformDirtyFlags]
        test     al, 4
        jne      L_58b1
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x54], 0xf9200000
        mov      edx, dword ptr [g_audioCrewState_00541d8c]
        mov      ecx, dword ptr [g_currentNodeIdx]
        lea      eax, [edx*4]
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      edx, dword ptr [g_currentNodeIdx]
        lea      ecx, [eax*4 + 0xc0000]
        mov      dword ptr [edx*4 + 0x5c], ecx
    L_58b1:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [esi], eax
        mov      ecx, eax
        mov      eax, 0x55555556
        mov      dword ptr [g_eventQueueEnd], ecx
        imul     dword ptr [g_audioCrewState_00541d8c]
        mov      eax, edx
        shr      eax, 0x1f
        lea      edx, [edx + eax - 0x100000]
        mov      eax, dword ptr [g_data_005433cc]
        mov      dword ptr [g_audioCrewState_00541d8c], edx
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [g_currentNodeIdx], eax
        cmp      edi, dword ptr [edx*4 + 0x30]
        jne      L_5938
        mov      ecx, dword ptr [ecx*4 + 0x54]
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x58]
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x5c]
        mov      dword ptr [ecx*4 + 0x5c], eax
    L_5938:
        test     byte ptr [g_gtFightTickCounter], 8
        je       L_5948
        call     ScaledOr4DirtyClear_00409320
        jmp      L_594d
    L_5948:
        call     ScaledAnd4InvDirtyClear_00409350
    L_594d:
        mov      eax, dword ptr [esi + 4]
        test     eax, eax
        mov      dword ptr [g_currentNodeIdx], eax
        jne      L_598e
        mov      edx, dword ptr [g_audioCrewState_00541d8c]
        mov      eax, dword ptr [ebp]
        push     edx
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp_004a1fa0
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      ecx, dword ptr [eax*4 + 0x54]
        add      ecx, ebx
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [esi + 4], eax
    L_598e:
        mov      ecx, dword ptr [g_audioCrewState_00541d8c]
        mov      dword ptr [eax*4 + 0x58], ecx
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      eax, 0x55555556
        mov      ecx, dword ptr [edx*4 + 0x34]
        imul     ecx
        mov      eax, edx
        shr      eax, 0x1f
        lea      ecx, [edx + eax + 0x10000]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x5c], ecx
        mov      ecx, dword ptr [g_audioCrewState_00541d8c]
        movsx    eax, byte ptr [esi - 5]
        add      ecx, 0x140000
        mov      eax, dword ptr [eax*4 + g_data_004f3a30]
        push     ecx
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp_004a1fa0
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      edx, dword ptr [eax*4 + 0x54]
        add      edx, ebx
        mov      dword ptr [eax*4 + 0x54], edx
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      eax, 0x55555556
        mov      ecx, dword ptr [edx*4 + 0x34]
        imul     ecx
        mov      eax, edx
        shr      eax, 0x1f
        lea      ecx, [edx + eax + 0x10000]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x5c], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_audioCrewState_00541d8c]
        mov      dword ptr [esi + 8], eax
        movsx    ecx, byte ptr [esi - 4]
        add      edx, 0x280000
        mov      eax, dword ptr [ecx*4 + g_data_004f3220]
        push     edx
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp_004a1fa0
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      ecx, dword ptr [eax*4 + 0x54]
        add      ecx, ebx
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [eax*4 + 0x34]
        mov      eax, 0x55555556
        imul     ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, edx
        shr      ecx, 0x1f
        lea      edx, [edx + ecx + 0x10000]
        mov      dword ptr [eax*4 + 0x5c], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [esi + 0xc], ecx
        mov      al, byte ptr [esi - 5]
        test     al, al
        je       L_5ab3
        call     ScaledOr4DirtyClear_00409320
    L_5ab3:
        mov      eax, dword ptr [esp + 0x10]
        inc      edi
        add      eax, 0xb80000
        add      ebp, 4
        mov      dword ptr [esp + 0x10], eax
        mov      eax, dword ptr [g_count_005433b8]
        add      esi, 0x18
        cmp      edi, eax
        jl       L_57c3
        mov      ebx, dword ptr [esp + 0x14]
        xor      ebp, ebp
    L_5ada:
        mov      ecx, dword ptr [g_byte_004d50b4]
        test     cl, 1
        jne      L_5aea
        test     ch, 1
        je       L_5b55
    L_5aea:
        mov      eax, dword ptr [g_baseSel_00542060]
        cmp      dword ptr [eax*4 + 0x30], ebp
        jle      L_5b5a
        call     SetJmp_004a1ad0
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [eax*4 + 0x30]
        dec      ecx
        mov      dword ptr [eax*4 + 0x30], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [eax*4 + 0x30]
        mov      edx, dword ptr [eax*4 + 0x3c]
        lea      esi, [ecx + ecx*2]
        shl      esi, 3
        sub      esi, ecx
        shl      esi, 0x13
        add      esi, edx
        jns      L_5b4d
        add      edx, 0xb80000
        mov      dword ptr [eax*4 + 0x3c], edx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [g_byte_004d50b4]
        jmp      L_5b5a
    L_5b4d:
        mov      ecx, dword ptr [g_byte_004d50b4]
        jmp      L_5b5a
    L_5b55:
        mov      eax, dword ptr [g_baseSel_00542060]
    L_5b5a:
        test     cl, 2
        jne      L_5b64
        test     ch, 2
        je       L_5be3
    L_5b64:
        mov      edx, dword ptr [g_count_005433b8]
        mov      ecx, dword ptr [eax*4 + 0x30]
        dec      edx
        cmp      ecx, edx
        jge      L_5be3
        call     SetJmp_004a1ad0
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [eax*4 + 0x30]
        inc      ecx
        mov      dword ptr [eax*4 + 0x30], ecx
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [ecx*4 + 0x30]
        mov      edx, dword ptr [ecx*4 + 0x3c]
        lea      esi, [eax + eax*2]
        shl      esi, 3
        sub      esi, eax
        shl      esi, 0x13
        add      esi, edx
        cmp      esi, 0x2e00000
        jge      L_5bcb
        add      edx, 0xb80000
        mov      dword ptr [ecx*4 + 0x3c], edx
        mov      ecx, dword ptr [g_baseSel_00542060]
    L_5bcb:
        mov      eax, dword ptr [ecx*4 + 0x3c]
        add      eax, 0xff480000
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      eax, dword ptr [g_baseSel_00542060]
    L_5be3:
        mov      esi, dword ptr [eax*4 + 0x30]
        call     TestByteOrAndCheck_004a1ae0
        test     eax, eax
        je       L_5c1a
        lea      eax, [esi + esi*2]
        mov      dl, byte ptr [eax*8 + g_data_005435a4]
        inc      dl
        mov      cl, dl
        mov      byte ptr [eax*8 + g_data_005435a4], dl
        cmp      cl, 4
        jle      L_5c15
        mov      byte ptr [eax*8 + g_data_005435a4], 0
    L_5c15:
        call     SetJmp_004a1ac0
    L_5c1a:
        mov      eax, dword ptr [g_byte_004d50b4]
        test     al, 4
        jne      L_5c28
        test     ah, 4
        je       L_5c4f
    L_5c28:
        lea      eax, [esi + esi*2]
        mov      cl, byte ptr [eax*8 + g_byte_005435a0]
        dec      cl
        mov      byte ptr [eax*8 + g_byte_005435a0], cl
        jns      L_5c45
        mov      byte ptr [eax*8 + g_byte_005435a0], 0xe
    L_5c45:
        call     SetJmp_004a1ac0
        mov      eax, dword ptr [g_byte_004d50b4]
    L_5c4f:
        test     al, 8
        jne      L_5c58
        test     ah, 8
        je       L_5c7f
    L_5c58:
        lea      eax, [esi + esi*2]
        mov      dl, byte ptr [eax*8 + g_byte_005435a0]
        inc      dl
        mov      cl, dl
        mov      byte ptr [eax*8 + g_byte_005435a0], dl
        cmp      cl, 0xe
        jle      L_5c7a
        mov      byte ptr [eax*8 + g_byte_005435a0], 0
    L_5c7a:
        call     SetJmp_004a1ac0
    L_5c7f:
        call     IsNonzeroBoolFlagged_004a1d00
        test     eax, eax
        je       L_5ce6
        mov      dword ptr [g_eventQueueWorkType], 0x32a
        call     Push16Call_00489f50
        mov      eax, dword ptr [g_data_005433cc]
        mov      dword ptr [g_currentNodeIdx], eax
        call     MStackPush2ChainLLInsert_00406790
        mov      dword ptr [g_data_005433cc], ebp
        mov      esi, 0x543408
    L_5cb1:
        mov      ecx, dword ptr [esi]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackPush2ChainLLInsert_00406790
        add      esi, 4
        cmp      esi, 0x543434
        jl       L_5cb1
        call     PendingMatch_004a56c0
        mov      dword ptr [g_audioPreloadState_00543830], ebp
        call     Memset18Step_004a56a0
        call     PendingMatch_004a62b0
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret      
    L_5ce6:
        call     DualCallSetByte_004a1cb0
        test     eax, eax
        je       L_5d0c
        lea      eax, [esi + esi*2]
        xor      edx, edx
        mov      cl, byte ptr [eax*8 + g_data_005435a3]
        test     cl, cl
        sete     dl
        mov      byte ptr [eax*8 + g_data_005435a3], dl
        call     SetJmp_004a1ac0
    L_5d0c:
        call     RetZero_004a1c40
        test     eax, eax
        je       L_5e75
        mov      dword ptr [g_eventQueueWorkType], 0x32f
        call     Push16Call_00489f50
        call     KonquestPortalCluster_004a5290
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret      
    L_5d35:
        mov      ebp, 1
        mov      dword ptr [g_tickFlagF], 2
        mov      dword ptr [g_phaseIdx_0053a50c], 0xd
        mov      dword ptr [g_audioPathFlag_0054355c], ebp
        call     DrainQueueCallEach_004a1ec0
        call     Audio11SlotInitLoop_004a5540
        mov      esi, 0x4f3940
    L_5d63:
        movsx    eax, byte ptr [esi]
        add      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackPush2ChainLLInsert_00406790
        add      esi, 0x24
        cmp      esi, 0x4f3a3c
        jb       L_5d63
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_currentNodeIdx], edx
        call     MStackPush2ChainLLInsert_00406790
        mov      ecx, 0x5a
        xor      eax, eax
        mov      edi, 0x5435a0
        xor      ebx, ebx
        rep stosd
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x34], 0xa0000
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [ecx*4 + 0x38], ebx
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x3c], ebx
        mov      eax, dword ptr [g_count_005433b8]
        test     eax, eax
        jle      L_5e25
        mov      esi, 0x5435a4
    L_5de2:
        mov      byte ptr [esi - 2], 0
        call     DualAddSar_004ab600
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, 0xf
        and      eax, 0xffff
        mov      byte ptr [esi], 0
        cdq      
        idiv     ecx
        cmp      esi, 0x5435d4
        mov      byte ptr [esi - 4], dl
        mov      byte ptr [esi - 3], bl
        jge      L_5e14
        mov      byte ptr [esi - 1], 1
        jmp      L_5e18
    L_5e14:
        mov      byte ptr [esi - 1], 0
    L_5e18:
        mov      eax, dword ptr [g_count_005433b8]
        inc      ebx
        add      esi, 0x18
        cmp      ebx, eax
        jl       L_5de2
    L_5e25:
        mov      edx, 0x50c960
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5e93
        call     MStackPushComplexCallPop_004064b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5e93
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_data_005433cc], eax
        call     ScaledOr4DirtyClear_00409320
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      ebx, dword ptr [esp + 0x14]
        mov      dword ptr [ecx*4 + 0x30], 0
        jmp      L_5e7a
    L_5e75:
        mov      ebp, 1
    L_5e7a:
        mov      dword ptr [ebx + 8], 0x4a5720
        mov      dword ptr [ebx + 0x84], ebp
        mov      dword ptr [g_pendingNodeType], ebp
        mov      dword ptr [g_framePauseFlag], ebp
    L_5e93:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret      
    }
}

__declspec(naked) void PendingMatch_004a42d0(void)
{
    __asm {
        _emit    0xc7
        _emit    0x05
        _emit    0x24
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe9
        _emit    0x31
        _emit    0xa3
        _emit    0x01
        _emit    0x00
        _emit    0x90
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x53
        _emit    0x55
        _emit    0x56
        _emit    0x8d
        _emit    0x34
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x33
        _emit    0xdb
        _emit    0x57
        _emit    0xbd
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x86
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x9e
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x2b
        _emit    0xc3
        _emit    0x0f
        _emit    0x84
        _emit    0xbb
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x48
        _emit    0x0f
        _emit    0x84
        _emit    0xb4
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x48
        _emit    0x0f
        _emit    0x84
        _emit    0x1d
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x38
        _emit    0x80
        _emit    0x53
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x3c
        _emit    0x80
        _emit    0x53
        _emit    0x00
        _emit    0x8b
        _emit    0x04
        _emit    0x8d
        _emit    0x34
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0c
        _emit    0x95
        _emit    0x34
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xf8
        _emit    0x06
        _emit    0x74
        _emit    0x15
        _emit    0x83
        _emit    0xf9
        _emit    0x06
        _emit    0x74
        _emit    0x10
        _emit    0x8b
        _emit    0x15
        _emit    0x1c
        _emit    0xa5
        _emit    0x53
        _emit    0x00
        _emit    0x6a
        _emit    0x1d
        _emit    0x83
        _emit    0xc2
        _emit    0x12
        _emit    0x52
        _emit    0x51
        _emit    0x50
        _emit    0xeb
        _emit    0x19
        _emit    0xa1
        _emit    0x1c
        _emit    0xa5
        _emit    0x53
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0xe0
        _emit    0x80
        _emit    0x53
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x48
        _emit    0x7f
        _emit    0x53
        _emit    0x00
        _emit    0x83
        _emit    0xc0
        _emit    0x12
        _emit    0x6a
        _emit    0x1d
        _emit    0x50
        _emit    0x51
        _emit    0x52
        _emit    0xe8
        _emit    0x95
        _emit    0xa4
        _emit    0x01
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x10
        _emit    0xe8
        _emit    0xcd
        _emit    0x65
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0xc8
        _emit    0x65
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x2c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0xa9
        _emit    0x5d
        _emit    0xfe
        _emit    0xff
        _emit    0x39
        _emit    0x1d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x75
        _emit    0x32
        _emit    0x88
        _emit    0x1d
        _emit    0x9c
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x39
        _emit    0x1d
        _emit    0x34
        _emit    0x43
        _emit    0xab
        _emit    0x00
        _emit    0x75
        _emit    0x0b
        _emit    0xe8
        _emit    0x0e
        _emit    0xff
        _emit    0xff
        _emit    0xff
        _emit    0x89
        _emit    0x1d
        _emit    0x00
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0xc7
        _emit    0x46
        _emit    0x08
        _emit    0xe0
        _emit    0x42
        _emit    0x4a
        _emit    0x00
        _emit    0x89
        _emit    0xae
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0xa1
        _emit    0x1c
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0x20
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x3b
        _emit    0xc3
        _emit    0x75
        _emit    0x35
        _emit    0xa1
        _emit    0xc0
        _emit    0x50
        _emit    0x4d
        _emit    0x00
        _emit    0x8b
        _emit    0x3d
        _emit    0x08
        _emit    0xa4
        _emit    0x53
        _emit    0x00
        _emit    0x8b
        _emit    0xc8
        _emit    0x83
        _emit    0xe1
        _emit    0x04
        _emit    0x74
        _emit    0x04
        _emit    0x3b
        _emit    0xfb
        _emit    0x75
        _emit    0x1f
        _emit    0x8b
        _emit    0x15
        _emit    0x88
        _emit    0x7e
        _emit    0x53
        _emit    0x00
        _emit    0x83
        _emit    0xe0
        _emit    0x20
        _emit    0x74
        _emit    0x04
        _emit    0x3b
        _emit    0xd3
        _emit    0x75
        _emit    0x10
        _emit    0x3b
        _emit    0xcb
        _emit    0x75
        _emit    0x04
        _emit    0x3b
        _emit    0xc3
        _emit    0x74
        _emit    0x29
        _emit    0x3b
        _emit    0xfb
        _emit    0x75
        _emit    0x25
        _emit    0x3b
        _emit    0xd3
        _emit    0x75
        _emit    0x21
        _emit    0xa0
        _emit    0x0c
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x1d
        _emit    0x1c
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x3a
        _emit    0xc3
        _emit    0x75
        _emit    0x12
        _emit    0x39
        _emit    0x1d
        _emit    0x30
        _emit    0xa4
        _emit    0x53
        _emit    0x00
        _emit    0x75
        _emit    0x0a
        _emit    0x6a
        _emit    0x03
        _emit    0xe8
        _emit    0x18
        _emit    0x1f
        _emit    0x01
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x04
        _emit    0x39
        _emit    0x1d
        _emit    0x34
        _emit    0x43
        _emit    0xab
        _emit    0x00
        _emit    0x74
        _emit    0x0f
        _emit    0xe8
        _emit    0x98
        _emit    0xfe
        _emit    0xff
        _emit    0xff
        _emit    0xc7
        _emit    0x05
        _emit    0x00
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0xe0
        _emit    0x42
        _emit    0x4a
        _emit    0x00
        _emit    0x39
        _emit    0x1d
        _emit    0x10
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x4b
        _emit    0x89
        _emit    0x1d
        _emit    0x10
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x6b
        _emit    0xd6
        _emit    0xff
        _emit    0xff
        _emit    0x89
        _emit    0x1d
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x90
        _emit    0x7d
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x6b
        _emit    0x21
        _emit    0xf8
        _emit    0xff
        _emit    0xe8
        _emit    0xd6
        _emit    0x64
        _emit    0x00
        _emit    0x00
        _emit    0x68
        _emit    0x00
        _emit    0x00
        _emit    0x64
        _emit    0x00
        _emit    0x68
        _emit    0x50
        _emit    0x22
        _emit    0x4d
        _emit    0x00
        _emit    0xe8
        _emit    0x27
        _emit    0xdb
        _emit    0xff
        _emit    0xff
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0xa3
        _emit    0x3c
        _emit    0x34
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0xd5
        _emit    0xfd
        _emit    0xff
        _emit    0xff
        _emit    0xe8
        _emit    0xa0
        _emit    0xb3
        _emit    0xf7
        _emit    0xff
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0x39
        _emit    0x1d
        _emit    0x14
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x25
        _emit    0x89
        _emit    0x1d
        _emit    0x14
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x18
        _emit    0xd6
        _emit    0xff
        _emit    0xff
        _emit    0x89
        _emit    0x1d
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x3d
        _emit    0x7d
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0xe8
        _emit    0xfc
        _emit    0xff
        _emit    0xff
        _emit    0xe8
        _emit    0x73
        _emit    0xb3
        _emit    0xf7
        _emit    0xff
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0x39
        _emit    0x1d
        _emit    0x18
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x6c
        _emit    0x89
        _emit    0x1d
        _emit    0x18
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x00
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0xd0
        _emit    0x38
        _emit    0x4a
        _emit    0x00
        _emit    0xc7
        _emit    0x46
        _emit    0x08
        _emit    0xe0
        _emit    0x42
        _emit    0x4a
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xba
        _emit    0xe0
        _emit    0x42
        _emit    0x4a
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x8d
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x46
        _emit    0x04
        _emit    0x81
        _emit    0xc2
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x02
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x14
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x40
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x46
        _emit    0x04
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x1c
        _emit    0x85
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0xa5
        _emit    0xf3
        _emit    0xff
        _emit    0xff
        _emit    0x89
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0x38
        _emit    0x1d
        _emit    0x9c
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x84
        _emit    0x53
        _emit    0xfe
        _emit    0xff
        _emit    0xff
        _emit    0xc7
        _emit    0x46
        _emit    0x08
        _emit    0xe0
        _emit    0x42
        _emit    0x4a
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xba
        _emit    0xe0
        _emit    0x42
        _emit    0x4a
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x8d
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x46
        _emit    0x04
        _emit    0x81
        _emit    0xc2
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x03
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x14
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x40
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x46
        _emit    0x04
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x1c
        _emit    0x85
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x0d
        _emit    0x63
        _emit    0x00
        _emit    0x00
        _emit    0x5f
        _emit    0x89
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0xa1
        _emit    0xf0
        _emit    0xa1
        _emit    0x53
        _emit    0x00
        _emit    0x85
        _emit    0xc0
        _emit    0x7e
        _emit    0x07
        _emit    0x48
        _emit    0xa3
        _emit    0xf0
        _emit    0xa1
        _emit    0x53
        _emit    0x00
        _emit    0xc3
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0c
        _emit    0x01
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0xa1
        _emit    0xf0
        _emit    0xa1
        _emit    0x53
        _emit    0x00
        _emit    0x83
        _emit    0xf8
        _emit    0x05
        _emit    0x7d
        _emit    0x07
        _emit    0x40
        _emit    0xa3
        _emit    0xf0
        _emit    0xa1
        _emit    0x53
        _emit    0x00
        _emit    0xc3
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0c
        _emit    0x01
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0xa1
        _emit    0x08
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0x83
        _emit    0xf8
        _emit    0x02
        _emit    0x7e
        _emit    0x07
        _emit    0x48
        _emit    0xa3
        _emit    0x08
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0xc3
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0c
        _emit    0x01
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0xa1
        _emit    0x08
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0x83
        _emit    0xf8
        _emit    0x09
        _emit    0x7d
        _emit    0x07
        _emit    0x40
        _emit    0xa3
        _emit    0x08
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0xc3
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0c
        _emit    0x01
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0x8b
        _emit    0x0d
        _emit    0x04
        _emit    0x34
        _emit    0x4f
        _emit    0x00
        _emit    0x33
        _emit    0xc0
        _emit    0x85
        _emit    0xc9
        _emit    0x0f
        _emit    0x94
        _emit    0xc0
        _emit    0xa3
        _emit    0x04
        _emit    0x34
        _emit    0x4f
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x8a
        _emit    0x0d
        _emit    0x28
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0x33
        _emit    0xc0
        _emit    0x84
        _emit    0xc9
        _emit    0x0f
        _emit    0x94
        _emit    0xc0
        _emit    0xa2
        _emit    0x28
        _emit    0x38
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x8a
        _emit    0x0d
        _emit    0x0c
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0x33
        _emit    0xc0
        _emit    0x84
        _emit    0xc9
        _emit    0x0f
        _emit    0x94
        _emit    0xc0
        _emit    0xa2
        _emit    0x0c
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0xc7
        _emit    0x05
        _emit    0x74
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x2a
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0xc1
        _emit    0x58
        _emit    0xfe
        _emit    0xff
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x85
        _emit    0x80
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0xc4
        _emit    0xaa
        _emit    0x52
        _emit    0x00
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x0c
        _emit    0xa5
        _emit    0x53
        _emit    0x00
        _emit    0x0f
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0xc7
        _emit    0x05
        _emit    0x74
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x2a
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x81
        _emit    0x58
        _emit    0xfe
        _emit    0xff
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xb8
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x04
        _emit    0x8d
        _emit    0x80
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa3
        _emit    0xc4
        _emit    0xaa
        _emit    0x52
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x0c
        _emit    0xa5
        _emit    0x53
        _emit    0x00
        _emit    0x0f
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0xa1
        _emit    0x1c
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0x85
        _emit    0xc0
        _emit    0x7e
        _emit    0x07
        _emit    0x48
        _emit    0xa3
        _emit    0x1c
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0xc3
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0c
        _emit    0x01
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0xa1
        _emit    0x1c
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0x83
        _emit    0xf8
        _emit    0x09
        _emit    0x7d
        _emit    0x07
        _emit    0x40
        _emit    0xa3
        _emit    0x1c
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0xc3
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0c
        _emit    0x01
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0xa0
        _emit    0x14
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0x84
        _emit    0xc0
        _emit    0x76
        _emit    0x08
        _emit    0xfe
        _emit    0xc8
        _emit    0xa2
        _emit    0x14
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0xc3
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0c
        _emit    0x01
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0xa0
        _emit    0x14
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0x3c
        _emit    0x0a
        _emit    0x73
        _emit    0x08
        _emit    0xfe
        _emit    0xc0
        _emit    0xa2
        _emit    0x14
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0xc3
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0c
        _emit    0x01
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0xa0
        _emit    0x18
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0x84
        _emit    0xc0
        _emit    0x76
        _emit    0x08
        _emit    0xfe
        _emit    0xc8
        _emit    0xa2
        _emit    0x18
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0xc3
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0c
        _emit    0x01
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0xa0
        _emit    0x18
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0x3c
        _emit    0x0a
        _emit    0x73
        _emit    0x08
        _emit    0xfe
        _emit    0xc0
        _emit    0xa2
        _emit    0x18
        _emit    0x36
        _emit    0x4f
        _emit    0x00
        _emit    0xc3
        _emit    0xa1
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0c
        _emit    0x01
        _emit    0xa3
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc3
    }
}

__declspec(naked) void PendingMatch_004a9940(void)
{
    __asm {
        _emit    0x56
        _emit    0xbe
        _emit    0x3c
        _emit    0x3e
        _emit    0x4f
        _emit    0x00
        _emit    0x0f
        _emit    0xbe
        _emit    0x46
        _emit    0xfc
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x03
        _emit    0xc8
        _emit    0x8b
        _emit    0x14
        _emit    0x8d
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x2c
        _emit    0xce
        _emit    0xf5
        _emit    0xff
        _emit    0x8b
        _emit    0x46
        _emit    0x08
        _emit    0x8b
        _emit    0x0e
        _emit    0x50
        _emit    0x51
        _emit    0xa3
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x25
        _emit    0x86
        _emit    0xff
        _emit    0xff
        _emit    0x8b
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x46
        _emit    0x0c
        _emit    0x83
        _emit    0xc6
        _emit    0x24
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0x89
        _emit    0x04
        _emit    0x8d
        _emit    0x5c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x14
        _emit    0x85
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x56
        _emit    0xe0
        _emit    0x8b
        _emit    0x15
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0xbe
        _emit    0x4e
        _emit    0xd8
        _emit    0x89
        _emit    0x0d
        _emit    0x70
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x03
        _emit    0xca
        _emit    0x81
        _emit    0xfe
        _emit    0xf0
        _emit    0x3e
        _emit    0x4f
        _emit    0x00
        _emit    0x89
        _emit    0x04
        _emit    0x8d
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x72
        _emit    0x85
        _emit    0x5e
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x53
        _emit    0x56
        _emit    0x57
        _emit    0x8d
        _emit    0x3c
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xbb
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x87
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x87
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xe8
        _emit    0x00
        _emit    0x74
        _emit    0x2a
        _emit    0x48
        _emit    0x0f
        _emit    0x84
        _emit    0xc4
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x48
        _emit    0x74
        _emit    0x09
        _emit    0xe8
        _emit    0x78
        _emit    0x90
        _emit    0xff
        _emit    0xff
        _emit    0x5f
        _emit    0x5e
        _emit    0x5b
        _emit    0xc3
        _emit    0xff
        _emit    0x15
        _emit    0x58
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa1
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x85
        _emit    0xc0
        _emit    0x0f
        _emit    0x84
        _emit    0x35
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5b
        _emit    0xc3
        _emit    0xc7
        _emit    0x05
        _emit    0xc4
        _emit    0xaa
        _emit    0x52
        _emit    0x00
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x1d
        _emit    0x0c
        _emit    0xa5
        _emit    0x53
        _emit    0x00
        _emit    0xe8
        _emit    0x58
        _emit    0xa2
        _emit    0xf5
        _emit    0xff
        _emit    0xa1
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x85
        _emit    0xc0
        _emit    0x0f
        _emit    0x85
        _emit    0xb6
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x36
        _emit    0xae
        _emit    0xff
        _emit    0xff
        _emit    0xc7
        _emit    0x05
        _emit    0x74
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x09
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0xf7
        _emit    0x04
        _emit    0xfe
        _emit    0xff
        _emit    0xc7
        _emit    0x05
        _emit    0x80
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x20
        _emit    0x1c
        _emit    0x00
        _emit    0x00
        _emit    0xbe
        _emit    0x44
        _emit    0x3e
        _emit    0x4f
        _emit    0x00
        _emit    0x8b
        _emit    0x16
        _emit    0x8b
        _emit    0x4e
        _emit    0x04
        _emit    0x81
        _emit    0xea
        _emit    0x00
        _emit    0x00
        _emit    0x05
        _emit    0x00
        _emit    0x51
        _emit    0x52
        _emit    0x6a
        _emit    0x00
        _emit    0x68
        _emit    0xb8
        _emit    0x59
        _emit    0x51
        _emit    0x00
        _emit    0xe8
        _emit    0x9f
        _emit    0x84
        _emit    0xff
        _emit    0xff
        _emit    0x0f
        _emit    0xbe
        _emit    0x46
        _emit    0xf4
        _emit    0x8b
        _emit    0x15
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc6
        _emit    0x24
        _emit    0x03
        _emit    0xc2
        _emit    0x83
        _emit    0xc4
        _emit    0x10
        _emit    0x81
        _emit    0xfe
        _emit    0xf8
        _emit    0x3e
        _emit    0x4f
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x72
        _emit    0xc2
        _emit    0x68
        _emit    0x58
        _emit    0x63
        _emit    0x4f
        _emit    0x00
        _emit    0xe8
        _emit    0x90
        _emit    0x83
        _emit    0xff
        _emit    0xff
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x04
        _emit    0xc7
        _emit    0x04
        _emit    0x8d
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x04
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x77
        _emit    0xfe
        _emit    0xff
        _emit    0xff
        _emit    0x68
        _emit    0x28
        _emit    0x3e
        _emit    0x4f
        _emit    0x00
        _emit    0xe8
        _emit    0x8d
        _emit    0x97
        _emit    0xff
        _emit    0xff
        _emit    0x83
        _emit    0xc4
        _emit    0x04
        _emit    0x68
        _emit    0x28
        _emit    0x3e
        _emit    0x4f
        _emit    0x00
        _emit    0xe8
        _emit    0xe0
        _emit    0x97
        _emit    0xff
        _emit    0xff
        _emit    0x83
        _emit    0xc4
        _emit    0x04
        _emit    0xe8
        _emit    0x08
        _emit    0x81
        _emit    0xff
        _emit    0xff
        _emit    0x85
        _emit    0xc0
        _emit    0x74
        _emit    0x70
        _emit    0x8b
        _emit    0x15
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x04
        _emit    0x95
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8d
        _emit    0x04
        _emit    0xc0
        _emit    0x8b
        _emit    0x04
        _emit    0x85
        _emit    0x34
        _emit    0x3e
        _emit    0x4f
        _emit    0x00
        _emit    0x85
        _emit    0xc0
        _emit    0xa3
        _emit    0x58
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x48
        _emit    0x3d
        _emit    0x80
        _emit    0x2f
        _emit    0x4a
        _emit    0x00
        _emit    0x74
        _emit    0x52
        _emit    0xe8
        _emit    0xa8
        _emit    0x7f
        _emit    0xff
        _emit    0xff
        _emit    0xe8
        _emit    0x23
        _emit    0xfe
        _emit    0xff
        _emit    0xff
        _emit    0xc7
        _emit    0x05
        _emit    0x70
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x20
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x47
        _emit    0x08
        _emit    0xd0
        _emit    0x99
        _emit    0x4a
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xba
        _emit    0xd0
        _emit    0x99
        _emit    0x4a
        _emit    0x00
        _emit    0x81
        _emit    0xc2
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x02
        _emit    0xc7
        _emit    0x04
        _emit    0x8d
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x47
        _emit    0x04
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xeb
        _emit    0x5a
        _emit    0x84
        _emit    0x1d
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x75
        _emit    0x09
        _emit    0xe8
        _emit    0xdf
        _emit    0x80
        _emit    0xff
        _emit    0xff
        _emit    0x85
        _emit    0xc0
        _emit    0x74
        _emit    0x7d
        _emit    0xc7
        _emit    0x05
        _emit    0x74
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x2f
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0xdc
        _emit    0x03
        _emit    0xfe
        _emit    0xff
        _emit    0xe8
        _emit    0xc7
        _emit    0xfd
        _emit    0xff
        _emit    0xff
        _emit    0xc7
        _emit    0x05
        _emit    0x70
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x20
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x47
        _emit    0x08
        _emit    0xd0
        _emit    0x99
        _emit    0x4a
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xba
        _emit    0xd0
        _emit    0x99
        _emit    0x4a
        _emit    0x00
        _emit    0x81
        _emit    0xc2
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x03
        _emit    0xc7
        _emit    0x04
        _emit    0x8d
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x47
        _emit    0x04
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x14
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x40
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x47
        _emit    0x04
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x85
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x28
        _emit    0xc4
        _emit    0xf7
        _emit    0xff
        _emit    0x89
        _emit    0x1d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5b
        _emit    0xc3
        _emit    0xc7
        _emit    0x47
        _emit    0x08
        _emit    0xd0
        _emit    0x99
        _emit    0x4a
        _emit    0x00
        _emit    0x89
        _emit    0x9f
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x1d
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x1d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5b
        _emit    0xc3
        _emit    0x90
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc1
        _emit    0xe0
        _emit    0x02
        _emit    0x8b
        _emit    0x88
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x80
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x83
        _emit    0xe9
        _emit    0x00
        _emit    0x74
        _emit    0x44
        _emit    0x49
        _emit    0x75
        _emit    0x54
        _emit    0x8b
        _emit    0x15
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xb9
        _emit    0x04
        _emit    0xd2
        _emit    0x50
        _emit    0x00
        _emit    0xc1
        _emit    0xe9
        _emit    0x02
        _emit    0x89
        _emit    0x0d
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0c
        _emit    0x95
        _emit    0x24
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x40
        _emit    0x08
        _emit    0x00
        _emit    0x9c
        _emit    0x4a
        _emit    0x00
        _emit    0xc7
        _emit    0x80
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x08
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc3
        _emit    0x8b
        _emit    0x0d
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x14
        _emit    0x8d
        _emit    0x18
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xb9
        _emit    0xe8
        _emit    0xd1
        _emit    0x50
        _emit    0x00
        _emit    0xc1
        _emit    0xe9
        _emit    0x02
        _emit    0x89
        _emit    0x0d
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0c
        _emit    0x95
        _emit    0x24
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xb9
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x40
        _emit    0x08
        _emit    0x00
        _emit    0x9c
        _emit    0x4a
        _emit    0x00
        _emit    0x89
        _emit    0x88
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x08
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0xc3
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0x90
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x53
        _emit    0x55
        _emit    0x56
        _emit    0x57
        _emit    0x8d
        _emit    0x3c
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x33
        _emit    0xed
        _emit    0x8b
        _emit    0x87
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0xaf
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x2b
        _emit    0xc5
        _emit    0x0f
        _emit    0x84
        _emit    0x04
        _emit    0x04
        _emit    0x00
        _emit    0x00
        _emit    0x48
        _emit    0x0f
        _emit    0x84
        _emit    0x97
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0x48
        _emit    0x0f
        _emit    0x84
        _emit    0x86
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x14
        _emit    0x8d
        _emit    0x34
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x84
        _emit    0xca
        _emit    0xf5
        _emit    0xff
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x0c
        _emit    0x85
        _emit    0x38
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x6d
        _emit    0xca
        _emit    0xf5
        _emit    0xff
        _emit    0xa1
        _emit    0xd0
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x68
        _emit    0x00
        _emit    0x00
        _emit    0x96
        _emit    0x00
        _emit    0x3b
        _emit    0xc5
        _emit    0x74
        _emit    0x21
        _emit    0x68
        _emit    0x10
        _emit    0x56
        _emit    0x4d
        _emit    0x00
        _emit    0xe8
        _emit    0x65
        _emit    0x82
        _emit    0xff
        _emit    0xff
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xbe
        _emit    0x00
        _emit    0x40
        _emit    0x01
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0x89
        _emit    0x34
        _emit    0x95
        _emit    0x5c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xeb
        _emit    0x1e
        _emit    0x68
        _emit    0x08
        _emit    0x56
        _emit    0x4d
        _emit    0x00
        _emit    0xe8
        _emit    0x44
        _emit    0x82
        _emit    0xff
        _emit    0xff
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xbe
        _emit    0x00
        _emit    0x40
        _emit    0x01
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0x89
        _emit    0x34
        _emit    0x85
        _emit    0x5c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x68
        _emit    0x00
        _emit    0x00
        _emit    0x96
        _emit    0x00
        _emit    0x8b
        _emit    0x0c
        _emit    0x85
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x81
        _emit    0xc1
        _emit    0x00
        _emit    0x00
        _emit    0x7e
        _emit    0xff
        _emit    0x89
        _emit    0x0c
        _emit    0x85
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x14
        _emit    0x8d
        _emit    0x34
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x08
        _emit    0x37
        _emit    0x54
        _emit    0x00
        _emit    0x3b
        _emit    0xc5
        _emit    0x74
        _emit    0x1b
        _emit    0x68
        _emit    0x10
        _emit    0x56
        _emit    0x4d
        _emit    0x00
        _emit    0xe8
        _emit    0xec
        _emit    0x81
        _emit    0xff
        _emit    0xff
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0x89
        _emit    0x34
        _emit    0x85
        _emit    0x5c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xeb
        _emit    0x1a
        _emit    0x68
        _emit    0x08
        _emit    0x56
        _emit    0x4d
        _emit    0x00
        _emit    0xe8
        _emit    0xd1
        _emit    0x81
        _emit    0xff
        _emit    0xff
        _emit    0x8b
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0x89
        _emit    0x34
        _emit    0x8d
        _emit    0x5c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x0c
        _emit    0x85
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x81
        _emit    0xc1
        _emit    0x00
        _emit    0x00
        _emit    0x82
        _emit    0x00
        _emit    0x89
        _emit    0x0c
        _emit    0x85
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x04
        _emit    0x95
        _emit    0x38
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0xd0
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x3b
        _emit    0xc5
        _emit    0x75
        _emit    0x05
        _emit    0xe8
        _emit    0x28
        _emit    0xa3
        _emit    0xff
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x08
        _emit    0x37
        _emit    0x54
        _emit    0x00
        _emit    0x75
        _emit    0x05
        _emit    0xe8
        _emit    0x3b
        _emit    0xa3
        _emit    0xff
        _emit    0xff
        _emit    0x8b
        _emit    0x0d
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x3b
        _emit    0xcd
        _emit    0x0f
        _emit    0x84
        _emit    0xe0
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x04
        _emit    0x95
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x2b
        _emit    0xc5
        _emit    0x74
        _emit    0x0a
        _emit    0x48
        _emit    0x75
        _emit    0x18
        _emit    0xb8
        _emit    0xeb
        _emit    0x51
        _emit    0x00
        _emit    0x00
        _emit    0xeb
        _emit    0x05
        _emit    0xb8
        _emit    0xcd
        _emit    0xac
        _emit    0xff
        _emit    0xff
        _emit    0xa3
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x04
        _emit    0x8d
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0xa4
        _emit    0x50
        _emit    0x4d
        _emit    0x00
        _emit    0xa8
        _emit    0x04
        _emit    0x74
        _emit    0x3b
        _emit    0xf6
        _emit    0xc4
        _emit    0x04
        _emit    0x74
        _emit    0x36
        _emit    0xa8
        _emit    0x08
        _emit    0x74
        _emit    0x05
        _emit    0xf6
        _emit    0xc4
        _emit    0x08
        _emit    0x75
        _emit    0x53
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xbb
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x39
        _emit    0x1c
        _emit    0x85
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x74
        _emit    0x12
        _emit    0xe8
        _emit    0x42
        _emit    0x7c
        _emit    0xff
        _emit    0xff
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x1c
        _emit    0x8d
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0xfc
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0xeb
        _emit    0x2b
        _emit    0x8b
        _emit    0x15
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x39
        _emit    0x2c
        _emit    0x95
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x74
        _emit    0x11
        _emit    0xe8
        _emit    0x19
        _emit    0x7c
        _emit    0xff
        _emit    0xff
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2c
        _emit    0x85
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0xfc
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0xbb
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x2d
        _emit    0x7c
        _emit    0xff
        _emit    0xff
        _emit    0x85
        _emit    0xc0
        _emit    0xbe
        _emit    0x2a
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0x75
        _emit    0x1a
        _emit    0xe8
        _emit    0xff
        _emit    0x7d
        _emit    0xff
        _emit    0xff
        _emit    0x85
        _emit    0xc0
        _emit    0x75
        _emit    0x11
        _emit    0x39
        _emit    0x2d
        _emit    0xd0
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x54
        _emit    0xe8
        _emit    0xae
        _emit    0x7c
        _emit    0xff
        _emit    0xff
        _emit    0x85
        _emit    0xc0
        _emit    0x74
        _emit    0x4b
        _emit    0xa1
        _emit    0xd0
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0xfc
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x3b
        _emit    0xc5
        _emit    0x74
        _emit    0x31
        _emit    0x8b
        _emit    0x0d
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x7a
        _emit    0xc8
        _emit    0xf5
        _emit    0xff
        _emit    0x89
        _emit    0x2d
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x35
        _emit    0x74
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x29
        _emit    0x00
        _emit    0xfe
        _emit    0xff
        _emit    0x68
        _emit    0x35
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x1f
        _emit    0xab
        _emit    0xf5
        _emit    0xff
        _emit    0x83
        _emit    0xc4
        _emit    0x04
        _emit    0xeb
        _emit    0x0b
        _emit    0x89
        _emit    0x1d
        _emit    0xd0
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x7f
        _emit    0x7b
        _emit    0xff
        _emit    0xff
        _emit    0xe8
        _emit    0x0a
        _emit    0x7c
        _emit    0xff
        _emit    0xff
        _emit    0x85
        _emit    0xc0
        _emit    0x75
        _emit    0x1a
        _emit    0xe8
        _emit    0xa1
        _emit    0x7d
        _emit    0xff
        _emit    0xff
        _emit    0x85
        _emit    0xc0
        _emit    0x75
        _emit    0x11
        _emit    0x39
        _emit    0x2d
        _emit    0x08
        _emit    0x37
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x54
        _emit    0xe8
        _emit    0x40
        _emit    0x7c
        _emit    0xff
        _emit    0xff
        _emit    0x85
        _emit    0xc0
        _emit    0x74
        _emit    0x4b
        _emit    0xa1
        _emit    0x08
        _emit    0x37
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0xfc
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x3b
        _emit    0xc5
        _emit    0x74
        _emit    0x31
        _emit    0x8b
        _emit    0x15
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x0c
        _emit    0xc8
        _emit    0xf5
        _emit    0xff
        _emit    0x89
        _emit    0x2d
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x35
        _emit    0x74
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0xbb
        _emit    0xff
        _emit    0xfd
        _emit    0xff
        _emit    0x68
        _emit    0x35
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0xb1
        _emit    0xaa
        _emit    0xf5
        _emit    0xff
        _emit    0x83
        _emit    0xc4
        _emit    0x04
        _emit    0xeb
        _emit    0x0b
        _emit    0x89
        _emit    0x1d
        _emit    0x08
        _emit    0x37
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x11
        _emit    0x7b
        _emit    0xff
        _emit    0xff
        _emit    0xa1
        _emit    0xfc
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x40
        _emit    0x3d
        _emit    0x08
        _emit    0x07
        _emit    0x00
        _emit    0x00
        _emit    0xa3
        _emit    0xfc
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x7f
        _emit    0x57
        _emit    0xe8
        _emit    0x7a
        _emit    0x7c
        _emit    0xff
        _emit    0xff
        _emit    0x85
        _emit    0xc0
        _emit    0x0f
        _emit    0x84
        _emit    0x00
        _emit    0x04
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x74
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x2f
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x73
        _emit    0xff
        _emit    0xfd
        _emit    0xff
        _emit    0xc7
        _emit    0x05
        _emit    0x70
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x20
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x47
        _emit    0x08
        _emit    0xc0
        _emit    0x9c
        _emit    0x4a
        _emit    0x00
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xb9
        _emit    0xc0
        _emit    0x9c
        _emit    0x4a
        _emit    0x00
        _emit    0x81
        _emit    0xc1
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x02
        _emit    0xc7
        _emit    0x04
        _emit    0x85
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x47
        _emit    0x04
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xeb
        _emit    0x35
        _emit    0xbb
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x70
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x20
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x47
        _emit    0x08
        _emit    0xc0
        _emit    0x9c
        _emit    0x4a
        _emit    0x00
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xb9
        _emit    0xc0
        _emit    0x9c
        _emit    0x4a
        _emit    0x00
        _emit    0x81
        _emit    0xc1
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x01
        _emit    0x89
        _emit    0x1c
        _emit    0x85
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x47
        _emit    0x04
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0c
        _emit    0x85
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x40
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x47
        _emit    0x04
        _emit    0x8b
        _emit    0x15
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2c
        _emit    0x95
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x91
        _emit    0xbf
        _emit    0xf7
        _emit    0xff
        _emit    0x89
        _emit    0x1d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0xe8
        _emit    0x01
        _emit    0x8a
        _emit    0xff
        _emit    0xff
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0xe8
        _emit    0x07
        _emit    0x9c
        _emit    0xf5
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x56
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0x39
        _emit    0x2d
        _emit    0xd0
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x2a
        _emit    0x39
        _emit    0x2d
        _emit    0x08
        _emit    0x37
        _emit    0x54
        _emit    0x00
        _emit    0x74
        _emit    0x22
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x39
        _emit    0x2c
        _emit    0x85
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x75
        _emit    0x0a
        _emit    0xe8
        _emit    0x08
        _emit    0x83
        _emit    0xff
        _emit    0xff
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0xe8
        _emit    0xce
        _emit    0x85
        _emit    0xff
        _emit    0xff
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x39
        _emit    0x2c
        _emit    0x8d
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x75
        _emit    0x0a
        _emit    0xe8
        _emit    0x15
        _emit    0x82
        _emit    0xff
        _emit    0xff
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0xe8
        _emit    0x2b
        _emit    0x85
        _emit    0xff
        _emit    0xff
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
        _emit    0xa0
        _emit    0x90
        _emit    0x35
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0xfc
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x3c
        _emit    0x01
        _emit    0x89
        _emit    0x2d
        _emit    0x08
        _emit    0x37
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0xd0
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x75
        _emit    0x0c
        _emit    0xc7
        _emit    0x05
        _emit    0xd0
        _emit    0x33
        _emit    0x54
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xeb
        _emit    0x0a
        _emit    0xc7
        _emit    0x05
        _emit    0x08
        _emit    0x37
        _emit    0x54
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0xc4
        _emit    0xaa
        _emit    0x52
        _emit    0x00
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x0c
        _emit    0xa5
        _emit    0x53
        _emit    0x00
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x5c
        _emit    0x9b
        _emit    0xf5
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0xab
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xba
        _emit    0x08
        _emit    0xb2
        _emit    0x50
        _emit    0x00
        _emit    0xc1
        _emit    0xea
        _emit    0x02
        _emit    0x89
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x5d
        _emit    0x34
        _emit    0x01
        _emit    0x00
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x8c
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x05
        _emit    0x74
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x51
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0xe2
        _emit    0xfd
        _emit    0xfd
        _emit    0xff
        _emit    0xb8
        _emit    0x94
        _emit    0xfb
        _emit    0x50
        _emit    0x00
        _emit    0xc1
        _emit    0xe8
        _emit    0x02
        _emit    0xa3
        _emit    0x48
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0xb0
        _emit    0xce
        _emit    0xf5
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x5f
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xa0
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xb3
        _emit    0x04
        _emit    0x84
        _emit    0xc3
        _emit    0x0f
        _emit    0x85
        _emit    0xa6
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xbe
        _emit    0x1f
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x8d
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x9d
        _emit    0xff
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x35
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x34
        _emit    0x95
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x67
        _emit    0xc3
        _emit    0xf5
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x16
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xb8
        _emit    0xb0
        _emit    0xfb
        _emit    0x50
        _emit    0x00
        _emit    0xc1
        _emit    0xe8
        _emit    0x02
        _emit    0xa3
        _emit    0x48
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0x49
        _emit    0xce
        _emit    0xf5
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0xf8
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x84
        _emit    0x1d
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x42
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x8d
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x64
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x35
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x34
        _emit    0x95
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x08
        _emit    0xc3
        _emit    0xf5
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0xb7
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0xb8
        _emit    0xe8
        _emit    0xd1
        _emit    0x50
        _emit    0x00
        _emit    0xc1
        _emit    0xe8
        _emit    0x02
        _emit    0xa3
        _emit    0x48
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xe8
        _emit    0xea
        _emit    0xcd
        _emit    0xf5
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x99
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x84
        _emit    0x1d
        _emit    0x8c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0xe3
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x8d
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x4e
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0xcc
        _emit    0xc0
        _emit    0xf5
        _emit    0xff
        _emit    0x39
        _emit    0x2d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x0f
        _emit    0x85
        _emit    0x6b
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x68
        _emit    0x35
        _emit    0x02
        _emit    0x00
        _emit    0x00
        _emit    0x68
        _emit    0x00
        _emit    0x9c
        _emit    0x4a
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x95
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xcd
        _emit    0xac
        _emit    0xff
        _emit    0xff
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x85
        _emit    0x58
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x93
        _emit    0x18
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x8d
        _emit    0x5c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xcd
        _emit    0xcc
        _emit    0xfc
        _emit    0xff
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa1
        _emit    0x10
        _emit    0xab
        _emit    0x52
        _emit    0x00
        _emit    0x89
        _emit    0x15
        _emit    0x5c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa3
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2d
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2c
        _emit    0x85
        _emit    0x60
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xa1
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x04
        _emit    0x8d
        _emit    0x64
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x14
        _emit    0x85
        _emit    0x68
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0c
        _emit    0x95
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x6c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x0c
        _emit    0x85
        _emit    0x58
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xc7
        _emit    0x04
        _emit    0x95
        _emit    0x5c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xfb
        _emit    0xff
        _emit    0xe8
        _emit    0x02
        _emit    0x28
        _emit    0xff
        _emit    0xff
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0xa1
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x68
        _emit    0x00
        _emit    0x00
        _emit    0x82
        _emit    0x00
        _emit    0x68
        _emit    0xe8
        _emit    0x55
        _emit    0x4d
        _emit    0x00
        _emit    0x89
        _emit    0x2c
        _emit    0x85
        _emit    0x30
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x0d
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2c
        _emit    0x8d
        _emit    0x34
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x8b
        _emit    0x15
        _emit    0x60
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x2c
        _emit    0x95
        _emit    0x38
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xe8
        _emit    0x2a
        _emit    0x7c
        _emit    0xff
        _emit    0xff
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0xbe
        _emit    0x00
        _emit    0x40
        _emit    0x01
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0x89
        _emit    0x34
        _emit    0x85
        _emit    0x5c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x68
        _emit    0x00
        _emit    0x00
        _emit    0x82
        _emit    0x00
        _emit    0x68
        _emit    0xf8
        _emit    0x55
        _emit    0x4d
        _emit    0x00
        _emit    0x81
        _emit    0x04
        _emit    0x85
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x7e
        _emit    0xff
        _emit    0xe8
        _emit    0xf7
        _emit    0x7b
        _emit    0xff
        _emit    0xff
        _emit    0x8b
        _emit    0x0d
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x83
        _emit    0xc4
        _emit    0x08
        _emit    0xbb
        _emit    0x01
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x34
        _emit    0x8d
        _emit    0x5c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0xa1
        _emit    0x44
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x81
        _emit    0x04
        _emit    0x85
        _emit    0x54
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x82
        _emit    0x00
        _emit    0xc7
        _emit    0x47
        _emit    0x08
        _emit    0xc0
        _emit    0x9c
        _emit    0x4a
        _emit    0x00
        _emit    0xc7
        _emit    0x87
        _emit    0x84
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x03
        _emit    0x00
        _emit    0x00
        _emit    0x00
        _emit    0x89
        _emit    0x1d
        _emit    0x4c
        _emit    0x20
        _emit    0x54
        _emit    0x00
        _emit    0x89
        _emit    0x1d
        _emit    0x6c
        _emit    0x1e
        _emit    0x54
        _emit    0x00
        _emit    0x5f
        _emit    0x5e
        _emit    0x5d
        _emit    0x5b
        _emit    0xc3
    }
}
