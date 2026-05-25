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

extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_00543724;
extern unsigned int g_data_0054372c;
extern unsigned int g_data_00543730;
extern unsigned int g_data_005437f4;
extern void AudioBindEntry_004a1e40(void);
extern void AudioInitArgs3_004a1f20(void);
extern void AudioState50b4BitDispatcher_004a32c0(void);
extern void FiveTableWalkInit_00403c90(void);
extern void InstallSelfPackedF80_00426000(void);
extern void PendingMatch_004a2a80(void);
extern void RetZero_004a1c40(void);
extern void ScaledByteIdxDualCopy_004a3260(void);
extern void TripleCallByteCheck_004a1bf0(void);
extern void TripleCallSetCopy_004a4880(void);
extern void VoicePoolTickDispatch_004a4c10(void);

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
        mov     byte ptr [g_data_00543724], bl
        mov     byte ptr [g_data_0054372c], bl
        mov     byte ptr [g_data_00543730], bl
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
