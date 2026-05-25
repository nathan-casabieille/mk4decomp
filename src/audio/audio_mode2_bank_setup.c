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
extern unsigned int g_state_0053a3c0;
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

extern void AudioMode2BankSetup_004a6080(void);
extern unsigned char g_byte_00543840;
extern unsigned char g_byte_0054383c;
extern unsigned char g_byte_005435a0;
extern unsigned char g_byte_005435b8;
extern unsigned int g_data_00543838;
extern unsigned int g_data_0054355c;
extern unsigned int g_table_00543848;

/*
 * AudioByteCounterChain_004a9820 - 204b audio counter+state machine.
 *   chain = g_baseSel_00542060<<2; saved = chain->state; chain->state = 0.
 *   If was 0: dispatch on g_audioBankSel_00537f94 == 1/2 to increment indexed slots in g_table_00543848;
 *     call BootInitGuardedCallChain; if paused: ret.
 *     Call FiveTableWalkInit; if paused: ret.
 *     Inc g_byte_00543840; g_data_0054355c=1; g_data_00543838=1;
 *     if hit 0xf: inc g_byte_0054383c; if also equal to (post-inc) al: zero it.
 *     Stash to g_byte_005435a0; push (&g_byte_005435b8, &g_byte_005435a0);
 *     g_byte_005435b8 = g_byte_0054383c; zero g_byte_005435a3 / g_byte_005435bb;
 *     call AudioMode2BankSetup_004a6080; call TwoStageAudioInit.
 */
extern unsigned int g_framePauseFlag;
extern unsigned int g_state_00537f48;
extern unsigned int g_state_005380e0;
extern void BootInitGuardedCallChain_004265d0(void);
extern void FiveTableWalkInit_00403c90(void);
extern void TwoStageAudioInit_004a6180(void);

__declspec(naked) void AudioByteCounterChain_004a9820(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel_00542060]
        push    ebx
        xor     ebx, ebx
        mov     ecx, dword ptr [eax*4 + 0x84]
        mov     dword ptr [eax*4 + 0x84], ebx
        cmp     ecx, ebx
        jne     short L_skipInit
        mov     eax, dword ptr [g_audioBankSel_00537f94]
        cmp     eax, 1
        jne     short L_check2
        mov     ecx, dword ptr [g_state_00537f48]
        inc     dword ptr [ecx*4 + g_table_00543848]
    L_check2:
        cmp     eax, 2
        jne     short L_skipInit
        mov     eax, dword ptr [g_state_005380e0]
        inc     dword ptr [eax*4 + g_table_00543848]
    L_skipInit:
        call    BootInitGuardedCallChain_004265d0
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_end
        call    FiveTableWalkInit_00403c90
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_end
        mov     al, byte ptr [g_byte_00543840]
        mov     dword ptr [g_data_0054355c], 1
        inc     al
        mov     dword ptr [g_data_00543838], 1
        cmp     al, 0xf
        mov     byte ptr [g_byte_00543840], al
        jne     short L_finalize
        mov     cl, byte ptr [g_byte_0054383c]
        inc     cl
        cmp     cl, al
        mov     byte ptr [g_byte_0054383c], cl
        jne     short L_finalize
        mov     byte ptr [g_byte_0054383c], bl
    L_finalize:
        mov     byte ptr [g_byte_005435a0], al
        mov     al, byte ptr [g_byte_0054383c]
        push    offset g_byte_005435b8
        push    offset g_byte_005435a0
        mov     byte ptr [g_byte_005435b8], al
        mov     byte ptr [g_byte_005435a0 + 3], bl
        mov     byte ptr [g_byte_005435b8 + 3], bl
        call    AudioMode2BankSetup_004a6080
        add     esp, 8
        call    TwoStageAudioInit_004a6180
    L_end:
        pop     ebx
        ret
    }
}
