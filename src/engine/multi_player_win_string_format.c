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
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_active_00537e88;
extern unsigned int g_data_0053a318;
extern unsigned int g_active_0053a408;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_acc_00542078;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_data_00543564;
extern unsigned int g_data_00543594;
extern void Helper_Sprintf(void);
extern void PushPopPendingTwoCalls_0042f4f0(void);
extern void ScaledStoreCallEpilogue_0042f4d0(void);

__declspec(naked) void MultiPlayerWinStringFormat_0042efc0(void)
{
    __asm {
        push     ebp
        push     esi
        push     edi
        call     PushPopPendingTwoCalls_0042f4f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x13
        _emit    0x05
        _emit    0x00
        _emit    0x00
        mov      eax, dword ptr [g_data_0053a318]
        mov      esi, 1
        mov      dword ptr [g_walkCallback], eax
        cmp      eax, esi
        mov      eax, dword ptr [g_active_0053a408]
        mov      dword ptr [g_currentNodeFlags], 0x14000
        mov      ebp, 4
        jne      L_f272
        test     eax, eax
        jne      L_f11c
        cmp      dword ptr [g_active_00537e88], esi
        jne      L_f11c
        mov      eax, dword ptr [g_data_00543564]
        dec      eax
        mov      dword ptr [g_data_00543564], eax
        /* js 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x88
        _emit    0xc3
        _emit    0x04
        _emit    0x00
        _emit    0x00
        inc      eax
        push     eax
        push     0x4d56d0
        push     0x543450
        call     Helper_Sprintf
        mov      eax, dword ptr [g_data_00543564]
        add      esp, 0xc
        cmp      eax, esi
        mov      edi, 0x4d56e8
        jge      L_f04c
        mov      edi, 0x4d56f8
    L_f04c:
        or       ecx, 0xffffffff
        xor      eax, eax
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      edx, ecx
        mov      edi, 0x543450
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, edx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, edx
        and      ecx, 3
        rep movsb
        mov      edi, 0x4d5708
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      edx, ecx
        mov      edi, 0x543450
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, edx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, edx
        and      ecx, 3
        rep movsb
        call     AllocSlotPushTripleGlobals_00427470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x37
        _emit    0x04
        _emit    0x00
        _emit    0x00
        mov      eax, 0x543450
        mov      edi, 0x238
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_acc_00542078], 0x5a0000
        mov      dword ptr [g_eventQueueNotMask], 0x370000
        call     Push70CallScaleArith_00457ad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xf3
        _emit    0x03
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite_004274f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xe1
        _emit    0x03
        _emit    0x00
        _emit    0x00
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        jmp      L_f121
    L_f11c:
        mov      edi, 0x238
    L_f121:
        call     AllocSlotPushTripleGlobals_00427470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xb5
        _emit    0x03
        _emit    0x00
        _emit    0x00
        mov      eax, 0x4d5578
        mov      dword ptr [g_walkCallback], edi
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_acc_00542078], 0x5a0000
        mov      dword ptr [g_eventQueueNotMask], 0x500000
        call     Push70CallScaleArith_00457ad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x76
        _emit    0x03
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite_004274f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x64
        _emit    0x03
        _emit    0x00
        _emit    0x00
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        call     AllocSlotPushTripleGlobals_00427470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x3f
        _emit    0x03
        _emit    0x00
        _emit    0x00
        mov      eax, 0x4d5588
        mov      esi, 0x610000
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_acc_00542078], esi
        mov      dword ptr [g_eventQueueNotMask], 0x640000
        call     Push70CallScaleArith_00457ad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xff
        _emit    0x02
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite_004274f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xed
        _emit    0x02
        _emit    0x00
        _emit    0x00
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        call     AllocSlotPushTripleGlobals_00427470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xc8
        _emit    0x02
        _emit    0x00
        _emit    0x00
        mov      eax, 0x4d5628
        mov      dword ptr [g_walkCallback], edi
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_acc_00542078], esi
        mov      dword ptr [g_eventQueueNotMask], 0x780000
        call     Push70CallScaleArith_00457ad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x8d
        _emit    0x02
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite_004274f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x7b
        _emit    0x02
        _emit    0x00
        _emit    0x00
        jmp      ScaledStoreCallEpilogue_0042f4d0
    L_f272:
        cmp      eax, esi
        jne      L_f38f
        mov      eax, dword ptr [g_active_00537e88]
        test     eax, eax
        jne      L_f38f
        mov      eax, dword ptr [g_data_00543594]
        dec      eax
        mov      dword ptr [g_data_00543594], eax
        /* js 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x88
        _emit    0x50
        _emit    0x02
        _emit    0x00
        _emit    0x00
        inc      eax
        push     eax
        push     0x4d56d0
        push     0x543450
        call     Helper_Sprintf
        mov      eax, dword ptr [g_data_00543594]
        add      esp, 0xc
        cmp      eax, esi
        mov      edi, 0x4d56e8
        jge      L_f2bf
        mov      edi, 0x4d56f8
    L_f2bf:
        or       ecx, 0xffffffff
        xor      eax, eax
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      edx, ecx
        mov      edi, 0x543450
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, edx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, edx
        and      ecx, 3
        rep movsb
        mov      edi, 0x4d5708
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      edx, ecx
        mov      edi, 0x543450
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, edx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, edx
        and      ecx, 3
        rep movsb
        call     AllocSlotPushTripleGlobals_00427470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xc4
        _emit    0x01
        _emit    0x00
        _emit    0x00
        mov      eax, 0x543450
        mov      edi, 0x238
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_acc_00542078], 0xffa60000
        mov      dword ptr [g_eventQueueNotMask], 0x370000
        call     Push70CallScaleArith_00457ad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x80
        _emit    0x01
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite_004274f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x6e
        _emit    0x01
        _emit    0x00
        _emit    0x00
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        jmp      L_f394
    L_f38f:
        mov      edi, 0x238
    L_f394:
        call     AllocSlotPushTripleGlobals_00427470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x42
        _emit    0x01
        _emit    0x00
        _emit    0x00
        mov      eax, 0x4d5568
        mov      dword ptr [g_walkCallback], edi
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_acc_00542078], 0xffa60000
        mov      dword ptr [g_eventQueueNotMask], 0x500000
        call     Push70CallScaleArith_00457ad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x03
        _emit    0x01
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite_004274f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xf1
        _emit    0x00
        _emit    0x00
        _emit    0x00
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        call     AllocSlotPushTripleGlobals_00427470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0xcc
        _emit    0x00
        _emit    0x00
        _emit    0x00
        mov      eax, 0x4d5588
        mov      esi, 0xff9f0000
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_acc_00542078], esi
        mov      dword ptr [g_eventQueueNotMask], 0x640000
        call     Push70CallScaleArith_00457ad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x0f
        _emit    0x85
        _emit    0x8c
        _emit    0x00
        _emit    0x00
        _emit    0x00
        call     MStackPop4Rewrite_004274f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x75
        _emit    0x7e
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [edx*4 + 0x5c], ecx
        call     AllocSlotPushTripleGlobals_00427470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x75
        _emit    0x5d
        mov      eax, 0x4d5628
        mov      dword ptr [g_walkCallback], edi
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebp
        mov      dword ptr [g_acc_00542078], esi
        mov      dword ptr [g_eventQueueNotMask], 0x780000
        call     Push70CallScaleArith_00457ad0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x75
        _emit    0x26
        call     MStackPop4Rewrite_004274f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        /* jne 0x42f4e8 (external, raw bytes) */
        _emit    0x75
        _emit    0x18
    }
}
