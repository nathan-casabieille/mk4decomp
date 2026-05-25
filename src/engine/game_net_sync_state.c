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

extern unsigned int g_const_004a0060;
extern unsigned int g_const_004a0b00;
extern unsigned int g_const_004a0dc0;
extern unsigned int g_const_004a10d0;
extern unsigned int g_data_004e2860;
extern unsigned int g_data_00537e90;
extern unsigned int g_data_00537f88;
extern unsigned int g_active_0053a408;
extern unsigned int g_data_00541d88;
extern unsigned int g_framePauseFlag;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_eventQueueChild;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_data_00542094;
extern void AudioMStackPushHandlerPair_0049ff30(void);
extern void BitSetByIndex_004a07a0(void);
extern void Cmp3DirtyToggle_0049fa20(void);
extern void DualPushSetCallDualPop_00404b10(void);
extern void MStackDualPushSaveRestore_004a09c0(void);
extern void RoundWinTransition_0049e7e0(void);
extern void SetWalkCurCallPauseDirty_00404c70(void);
extern void TripleStageRollback_00404a50(void);

__declspec(naked) void GameNetSyncState_0049fb70(void)
{
    __asm {
        push     ebx
        push     esi
        call     Cmp3DirtyToggle_0049fa20
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      L_fd46
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        test     al, bl
        je       L_fd46
        mov      eax, dword ptr [g_active_0053a408]
        cmp      eax, 2
        mov      dword ptr [g_walkCallback], eax
        jne      L_fd46
        mov      eax, dword ptr [g_data_00541d88]
        cmp      eax, esi
        mov      dword ptr [g_walkCallback], eax
        jne      L_fd46
        mov      eax, dword ptr [g_data_00537f88]
        mov      dword ptr [g_eventQueueNotMask], esi
        cmp      eax, 0xf
        mov      dword ptr [g_acc_00542078], eax
        ja       L_fcd4
        push     0x252
        call     DualPushSetCallDualPop_00404b10
        mov      al, byte ptr [g_xformDirtyFlags]
        add      esp, 4
        test     al, bl
        jne      short L_fc0c
        call     MStackPush2TableNot_00426230
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_fd46
        mov      eax, dword ptr [g_eventQueueWorkType]
        and      eax, 4
        mov      dword ptr [g_data_00542094], eax
        jne      short L_fc58
    L_fc0c:
        push     0x15
        push     OFFSET g_const_004a0060
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_data_00541d88], ebx
        call     SetWalkCurCallPauseDirty_00404c70
        add      esp, 8
        call     RoundWinTransition_0049e7e0
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_fd46
        push     0x22f
        call     TripleStageRollback_00404a50
        mov      cx, word ptr [g_data_004e2860]
        add      esp, 4
        push     ecx
        call     TaggedSceneDispatch_004be690
        add      esp, 4
        pop      esi
        pop      ebx
        ret
    L_fc58:
        call     MStackDualPushSaveRestore_004a09c0
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_fd46
        test     byte ptr [g_xformDirtyFlags], bl
        je       short L_fd46
        push     0x239
        call     DualPushSetCallDualPop_00404b10
        mov      al, byte ptr [g_xformDirtyFlags]
        add      esp, 4
        test     al, bl
        je       short L_fc9e
        mov      edx, dword ptr [g_acc_00542078]
        mov      eax, dword ptr [g_data_00537e90]
        cmp      edx, eax
        je       short L_fd46
    L_fc9e:
        mov      dword ptr [g_walkCallback], esi
        call     BitSetByIndex_004a07a0
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_fd46
        mov      eax, dword ptr [g_acc_00542078]
        push     0x238
        push     OFFSET g_const_004a0b00
        mov      dword ptr [g_eventQueueChild], eax
        call     SetWalkCurCallPauseDirty_00404c70
        add      esp, 8
        pop      esi
        pop      ebx
        ret
    L_fcd4:
        cmp      eax, 0x10
        jne      short L_fd00
        push     0x23d
        push     OFFSET g_const_004a0dc0
        mov      dword ptr [g_eventQueueEnd], esi
        call     SetWalkCurCallPauseDirty_00404c70
        add      esp, 8
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_data_00541d88], ebx
        pop      esi
        pop      ebx
        ret
    L_fd00:
        cmp      eax, 0x11
        jne      short L_fd3c
        mov      cx, word ptr [g_data_004e2860]
        mov      dword ptr [g_eventQueueEnd], esi
        push     ecx
        call     TaggedSceneDispatch_004be690
        add      esp, 4
        push     0x242
        push     OFFSET g_const_004a10d0
        call     SetWalkCurCallPauseDirty_00404c70
        add      esp, 8
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_data_00541d88], ebx
        pop      esi
        pop      ebx
        ret
    L_fd3c:
        cmp      eax, 0x12
        jne      short L_fd46
        call     AudioMStackPushHandlerPair_0049ff30
    L_fd46:
        pop      esi
        pop      ebx
        ret
    }
}
