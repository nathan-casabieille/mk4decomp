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

extern void SelfInstallPhaseDispatch_00428990(void);

/* @addr 0x004753b0 (221b game) - install-self with chain[+0x84] dispatch.
 *   chain[+0x84]==0 path: install-self at +0x08=0x004753b0; g_currentNodeFlags=0x32f1, g_xformScratch2088=0x3333,
 *   g_eventQueueChild=0; scaledInit-chain push 0x004753b0|0x01000000; call SelfInstallPhaseDispatch_00428990; pause=1; pop+ret.
 *   chain[+0x84]!=0 path: set [g_fightGroupHead*4+0x24]=g_cj_00542054, [g_fightGroupHead*4+0x28]=0, g_walkCallback=0,
 *   g_cj_00542054=baseSel[*4+0x64], g_cj_00542058=baseSel[*4+0x68]; jmp StackPopDispatchTagged.
 */
extern unsigned int g_data_004ea058;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_pause_00541e6c;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_fightGroupHead;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_eventQueueChild;
extern unsigned int g_currentNodeFlags;
extern void CallPauseMStackPushSet9Jmp_0045ffc0(void);
extern void CjInstallSelfRouter_00470480(void);
extern void CjMaskedFlagProbe_0048ecf0(void);
extern void DualGatedStateYield_0048fc80(void);
extern void GuardedDirtyXformFromTable_0048f6d0(void);
extern void GuardedDualAndFlagToggle_0048f020(void);
extern void InstallSelfChainCascade_0045feb0(void);
extern void MStackPushSet0001_00490260(void);
extern void MstackPopScaledChainPlusThunks_00471250(void);
extern void MultiThunkDispatcher_00460470(void);
extern void ScaledAndAlfe_00490390(void);
extern void TableLookupCall_00489ff0(void);

extern unsigned int g_data_004f1a20;
extern void ArgScaledTestStore_00494140(void);
extern void ScaledChainJmp_00429470(void);
extern void ScaledClearJmp_00428d60(void);
extern void ScaledZeroFour_00490740(void);
extern void SelfInstallPhaseDispatch_00460000(void);
extern void SelfInstallPhaseDispatch_004943f0(void);

__declspec(naked) void InstallSelfChainEsi_004753b0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        xor     edx, edx
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   74h
        _emit   48h
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_cj_00542054]
        mov     dword ptr [ecx*4 + 0x24], eax
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx*4 + 0x28], edx
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     edx, dword ptr [eax*4 + 0x64]
        mov     dword ptr [g_cj_00542054], edx
        mov     eax, dword ptr [eax*4 + 0x68]
        mov     dword ptr [g_cj_00542058], eax
        jmp     StackPopDispatchTagged_0041f780
        mov     dword ptr [g_currentNodeFlags], 0x000032f1
        mov     dword ptr [g_xformScratch2088], 0x00003333
        mov     dword ptr [g_eventQueueChild], edx
        mov     dword ptr [eax + 0x08], 0x004753b0
        mov     ecx, dword ptr [g_baseSel_00542060]
        push    edi
        mov     edi, 0x004753b0
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     ecx, dword ptr [eax + 4]
        add     edi, 0x01000000
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [ecx*4 + 0], edi
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x84], edx
        call    SelfInstallPhaseDispatch_00428990
        mov     dword ptr [g_pause_00541e6c], 1
        pop     edi
        ret
    }
}


/* @addr 0x00486ff0 (298b game) - 3-state install-self with dual entry-point.
 *   state==0: push 0x00542bc8; call ArgScaledTestStore; pop. If pause ret.
 *     [cj*4+0x24]=g_xformEntityIdx. Install-self at func entry +0x01000000.
 *     state=1; chain[+0x84]=0; call ScaledClearJmp; pause=1; ret.
 *   state==1: install-self at func entry +0x02000000. State=2; call ScaledChainJmp; pause=1; ret.
 *   state>=2: call ScaledZeroFour_00490740; if pause ret. Tail-call SelfInstallPhaseDispatch_00460000; ret.
 */
__declspec(naked) void InstallSelf3StateDualEntry_00486ff0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        _emit   83h
        _emit   0e8h
        _emit   00h
        _emit   74h
        _emit   7dh
        dec     eax
        _emit   74h
        _emit   19h
        call    ScaledZeroFour_00490740
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0f0h
        _emit   00h
        _emit   00h
        _emit   00h
        call    SelfInstallPhaseDispatch_00460000
        pop     esi
        ret
        mov     dword ptr [esi + 8], offset InstallSelf3StateDualEntry_00486ff0
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     edx, offset InstallSelf3StateDualEntry_00486ff0
        mov     dword ptr [ecx*4 + 0x84], 2
        mov     eax, dword ptr [esi + 4]
        add     edx, 0x02000000
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     eax, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x84], 0
        call    ScaledChainJmp_00429470
        mov     dword ptr [g_pause_00541e6c], 1
        pop     esi
        ret
        push    0x00542bc8
        call    ArgScaledTestStore_00494140
        mov     eax, dword ptr [g_pause_00541e6c]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   72h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [ecx*4 + 0x24], edx
        mov     dword ptr [esi + 8], offset InstallSelf3StateDualEntry_00486ff0
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, offset InstallSelf3StateDualEntry_00486ff0
        add     ecx, 0x01000000
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [edx*4 + 0x84], 0
        call    ScaledClearJmp_00428d60
        mov     dword ptr [g_pause_00541e6c], 1
        pop     esi
        ret
    }
}


/* @addr 0x00494290 (343b game) - install-self with cmd-stream interpreter.
 *   state!=0: load eax = (0x004f1a20>>2) + ([cj*4+0x30] - 0x60); call indirect via TableLookupCall.
 *     If pause ret.
 *   state==0 (or after table call): iterate g_eventQueueEnd stream:
 *     read ecx; if == 0xffff0000: tail-call StackPopDispatchTagged.
 *     if != 0xfffe0000: install-self at entry+0x01000000; state=1; call SelfInstallPhaseDispatch_004943f0; pause=1; ret.
 *     Else (0xfffe0000): load function ptr from next stream slot; indirect call; if pause ret.
 *     Read next; if == 0xffff0000: tail-call StackPopDispatchTagged. Else loop.
 */
__declspec(naked) void InstallSelfCmdStreamInterp_00494290(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   44h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, offset g_data_004f1a20
        shr     eax, 2
        mov     ecx, dword ptr [ecx*4 + 0x30]
        sub     ecx, 0x60
        add     eax, ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_walkCallback], edx
        call    TableLookupCall_00489ff0
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0efh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        cmp     ecx, 0xffff0000
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_eventQueueEnd], eax
        _emit   74h
        _emit   4ah
        cmp     ecx, 0xfffe0000
        mov     ecx, dword ptr [eax*4 + 0]
        _emit   75h
        _emit   42h
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_eventQueueEnd], eax
        call    ecx
        mov     eax, dword ptr [g_pause_00541e6c]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0a5h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        cmp     ecx, 0xffff0000
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_eventQueueEnd], eax
        _emit   75h
        _emit   0b6h
        call    StackPopDispatchTagged_0041f780
        pop     esi
        ret
        inc     eax
        mov     dword ptr [g_acc_00542078], ecx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     ecx, offset InstallSelfCmdStreamInterp_00494290
        mov     edx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_xformScratch2088], edx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [esi + 8], offset InstallSelfCmdStreamInterp_00494290
        mov     eax, dword ptr [g_baseSel_00542060]
        add     ecx, 0x01000000
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [edx*4 + 0x84], 0
        call    SelfInstallPhaseDispatch_004943f0
        mov     dword ptr [g_pause_00541e6c], 1
        pop     esi
        ret
    }
}

__declspec(naked) void SelfInstallPhaseDispatch_0045fd30(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    ebx
        push    esi
        mov     ebx, 1
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_sipd2_phase0
        dec     eax
        jne     L_sipd2_phase2
        call    DualGatedStateYield_0048fc80
        test    eax, eax
        jne     L_sipd2_retCommon
        call    CjMaskedFlagProbe_0048ecf0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sipd2_retCommon
        test    byte ptr [g_xformDirtyFlags], bl
        je      short L_sipd2_continue
        call    CallPauseMStackPushSet9Jmp_0045ffc0
        pop     esi
        pop     ebx
        ret
    L_sipd2_continue:
        call    GuardedDualAndFlagToggle_0048f020
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sipd2_retCommon
        test    byte ptr [g_xformDirtyFlags], bl
        jne     short L_sipd2_phase2
        mov     dword ptr [esi + 8], offset SelfInstallPhaseDispatch_0045fd30
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     edx, offset SelfInstallPhaseDispatch_0045fd30
        mov     dword ptr [ecx*4 + 0x84], 2
        mov     eax, dword ptr [esi + 4]
        add     edx, 0x2000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x84], 0
        call    InstallSelfChainCascade_0045feb0
        mov     dword ptr [g_framePauseFlag], ebx
        pop     esi
        pop     ebx
        ret
    L_sipd2_phase2:
        call    GuardedDualConst2AndToggle_0048eba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_sipd2_retCommon
        test    byte ptr [g_xformDirtyFlags], bl
        jne     short L_sipd2_finishInstall
        call    MStackPushSet0001_00490260
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sipd2_retCommon
        mov     eax, dword ptr [g_state_004d57ac]
        mov     dword ptr [g_walkCallback], ebx
        inc     eax
        mov     dword ptr [g_state_004d57ac], eax
        mov     dword ptr [eax*4], offset CjInstallSelfRouter_00470480
        call    MstackPopScaledChainPlusThunks_00471250
        pop     esi
        pop     ebx
        ret
    L_sipd2_phase0:
        call    ScaledAndAlfe_00490390
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sipd2_retCommon
        mov     ecx, offset g_data_004ea058
        shr     ecx, 2
        mov     dword ptr [g_currentNodeIdx], ecx
        call    GuardedDirtyXformFromTable_0048f6d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sipd2_retCommon
        call    MultiThunkDispatcher_00460470
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_sipd2_retCommon
    L_sipd2_finishInstall:
        mov     dword ptr [esi + 8], offset SelfInstallPhaseDispatch_0045fd30
        mov     dword ptr [esi + 0x84], ebx
        mov     dword ptr [g_pendingNodeType], ebx
        mov     dword ptr [g_framePauseFlag], ebx
    L_sipd2_retCommon:
        pop     esi
        pop     ebx
        ret
    }
}
