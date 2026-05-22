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
extern unsigned int g_data_00542050;
extern unsigned int g_data_00542070;
extern unsigned int g_data_00542084;
extern unsigned int g_state_0054208c;
extern unsigned int g_state_00542088;
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_state_00542080;
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
extern unsigned int g_state_0054207c;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_state_00541fa4;
extern unsigned int g_state_00541fa8;
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

extern unsigned int g_data_005420c8;
extern unsigned int g_data_00541f98;
extern void VoicePicker_00401000(void);
extern unsigned int g_data_00542094;
extern void ChainNodeAdvanceCallback_00408e70(void);
/* extern void AuxCapsBitFlagAggregate_004b5380(void); -- defined elsewhere with diff sig */
extern void Helper_AudioStartMusic(void);
extern unsigned int g_data_00543b68;
extern unsigned int g_data_00543b6c;
extern unsigned int g_data_00ab4338;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054207c;
extern void GuardedSeq_00471670(void);
extern void ChainListVecAdd_0049d200(void);
extern void Filbuf_004c8ed0(void);
extern void Thunk_0049cb70(void);
extern void Thunk_0049cb80(void);
extern unsigned int g_data_00542074;
extern void Transform9Words_004b3a90(void);
extern void CrtGetLocaleInfo_004d0bc0(void);
extern void StringDigitConvert_004d03c0(void);
extern unsigned short g_data_00f9fc94;
extern unsigned int g_data_00522154;
extern unsigned int g_data_00fa0ee4;
extern unsigned int g_data_00f9f850;
extern void IndirectCall_004c6ec0(void);
extern void Helper_MemMalloc_Post(void);
extern void *g_iat_004d2150;
extern void DosMapErr_004c8b20(void);
extern void Thunk_004ca77b_helper(void);
extern void Thunk_004ca701_helper(void);
extern void FmodHelper_004ccb7d(void);
extern unsigned int g_data_00f9f7fc;
extern unsigned int g_data_00523ae4;
extern unsigned int g_data_00523ae0;
extern unsigned int g_data_00523b1c;
extern unsigned int g_data_00523b20;
extern unsigned int g_data_00523b24;
extern unsigned char g_data_00523b18;
extern void PendingMatch_004013a0(void);
extern void StoreTwoCall_0049cb40(void);
extern void DispatcherComplex260_00407400(void);
extern unsigned int g_data_00542058;
extern void CopyGlobal_004ac1f0(void);
extern void Test4StatesAny_004a1d20(void);
extern void BootInitGuardedCallChain_004265d0(void);
extern void Push16Call_00489f50(void);
extern void InstallSelfPackedF80_00426000(void);
extern void ScenegraphWalk_0041f7d0(void);
extern void CallSetPause_0041f830(void);

extern void Audio_TimerTeardown_004ac5f0(void);
extern unsigned int g_data_005438f8;
extern unsigned int g_data_005438ec;
extern unsigned int g_data_005438f0;
extern unsigned int g_data_005438f4;
extern unsigned int g_data_005438fc;
extern unsigned int g_data_0054390c;
extern unsigned int g_data_00543904;

/* @addr 0x004ac650 (290b audio) - MIDI MCI playback position setter.
 *   Calls Audio_TimerTeardown. Saves 4 args into globals (5438f8/ec/f0/f4).
 *   If 0x54390c non-zero or PostInit fails or already-init flag 0x543904 set:
 *     skip to timeGetTime tail. Else build MCI packet with mciSendCommandA
 *     (cmd 0x80d MCI_SET, 0x806 MCI_PLAY); convert esi/edi via /60 divmod
 *     using 0x88888889 reciprocal-mul to TMSF (mins:secs:frames) format.
 *     Set flag 0x543904 on success. Tail-call timeGetTime via IAT[0x4d2240];
 *     save in 0x5438fc.
 */
extern unsigned int g_iat_004d2240;
extern unsigned int g_iat_004d2244;
extern unsigned int g_x_005438e8;
extern void Helper_AuxAudio_PostInit(void);

__declspec(naked) void Audio_TimerSet(void) {
    __asm {
        sub     esp, 0x18
        push    ebx
        push    esi
        push    edi
        call    Audio_TimerTeardown_004ac5f0
        mov     eax, [esp + 0x34]
        mov     ebx, [esp + 0x28]
        mov     esi, [esp + 0x2c]
        mov     edi, [esp + 0x30]
        mov     dword ptr [g_data_005438f8], eax
        mov     eax, dword ptr [g_data_0054390c]
        test    eax, eax
        mov     dword ptr [g_data_005438ec], ebx
        mov     dword ptr [g_data_005438f0], esi
        mov     dword ptr [g_data_005438f4], edi
        jne     L_mp_tailCall
        call    Helper_AuxAudio_PostInit
        test    eax, eax
        jz      L_mp_tailCall
        mov     eax, dword ptr [g_data_00543904]
        test    eax, eax
        jne     L_mp_tailCall
        mov     edx, dword ptr [g_x_005438e8]
        lea     ecx, [esp + 0x18]
        push    ebp
        mov     ebp, dword ptr [g_iat_004d2244]
        push    ecx
        push    0x400
        push    0x80d
        push    edx
        mov     dword ptr [esp + 0x30], 0x0a
        call    ebp
        mov     eax, 0x88888889
        mov     ecx, ebx
        imul    esi
        add     edx, esi
        and     ecx, 0xff
        sar     edx, 5
        mov     eax, edx
        shr     eax, 31
        add     edx, eax
        mov     eax, esi
        mov     ebx, edx
        mov     esi, 60
        cdq
        idiv    esi
        xor     eax, eax
        and     ebx, 0xffff
        mov     ah, dl
        or      ebx, eax
        mov     eax, 0x88888889
        imul    edi
        add     edx, edi
        sar     edx, 5
        mov     eax, edx
        shr     eax, 31
        add     edx, eax
        mov     eax, edi
        mov     esi, edx
        mov     edi, 60
        cdq
        idiv    edi
        xor     eax, eax
        and     esi, 0xffff
        shl     ebx, 8
        or      ebx, ecx
        mov     [esp + 0x14], ebx
        mov     ah, dl
        mov     edx, dword ptr [g_x_005438e8]
        or      esi, eax
        shl     esi, 8
        or      esi, ecx
        lea     ecx, [esp + 0x10]
        push    ecx
        push    0xc
        push    0x806
        push    edx
        mov     [esp + 0x28], esi
        call    ebp
        neg     eax
        sbb     eax, eax
        pop     ebp
        inc     eax
        mov     dword ptr [g_data_00543904], eax
    L_mp_tailCall:
        call    dword ptr [g_iat_004d2240]
        pop     edi
        pop     esi
        mov     dword ptr [g_data_005438fc], eax
        pop     ebx
        add     esp, 0x18
        ret
    }
}
