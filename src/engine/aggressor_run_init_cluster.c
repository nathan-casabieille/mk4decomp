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

extern unsigned int g_data_004ed988;
extern unsigned int g_data_004ef228;
extern unsigned int g_data_004ef258;
extern unsigned int g_data_004ef278;
extern unsigned int g_data_004ef2b8;
extern unsigned int g_data_0052ab10;
extern unsigned int g_data_00537ef4;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_xformScratch2088;
extern unsigned int g_data_00542be8;
extern void ArgSarStoreJmp_004594f0(void);
extern void BlockedCounterCluster_004816d0(void);
extern void BossArrivalSequence_00481950(void);
extern void CjDispatchCommit_004818e0(void);
extern void DualScaledStore_00452740(void);
extern void MStackDualDiffSequencer_00477040(void);
extern void PendingMatch_00455bd0(void);
extern void Push267_Push44eb60_Jmp_00489220(void);
extern void ScaledInitWithCounterAndType_004314f0(void);
extern void ScaledXorStore_004903b0(void);
extern void StoreLoadJmp_00404ef0(void);
extern void TripleEntryCountdownInstall_0046a230(void);

__declspec(naked) void AggressorRunInitCluster_004813b0(void)
{
    __asm {
        /* === h1 (0x4813b0): event 004ed988 forwarder === */
        push     OFFSET g_data_004ed988
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret
        nop
        nop
        /* === h2 (0x4813c0): timer + angle/dist init → tail 4314f0 === */
        call     ScaledXorStore_004903b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1475
        mov      eax, 0x258
        push     OFFSET g_data_00542be8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_data_00537ef4], eax
        call     IterLoad_00491050
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_1475
        mov      ecx, dword ptr [g_data_0052ab10]
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x58]
        add      eax, 0x18000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_eventQueueCurrent], 0x3333
        add      ecx, 0x15
        mov      dword ptr [g_eventQueueWorkType], 0x41
        mov      dword ptr [g_xformEntityIdx], ecx
        call     MStackDualDiffSequencer_00477040
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1475
        mov      ecx, dword ptr [g_data_0052ab10]
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x58]
        sub      eax, 0x18000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        jmp      ScaledInitWithCounterAndType_004314f0
    L_1475:
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
        /* === h3 (0x481480): pose-fn install state 1 w/ 489220 === */
    L_1480:
        mov      eax, dword ptr [g_baseSel_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       short L_149f
        jmp      ScaledInitWithCounterAndType_004314f0
    L_149f:
        mov      ecx, dword ptr [g_fightGroupHead]
        push     edi
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edi, OFFSET L_1480
        mov      ecx, dword ptr [ecx*4 + 0x38]
        add      edi, 0x1000000
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      dword ptr [eax + 8], OFFSET L_1480
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     Push267_Push44eb60_Jmp_00489220
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
        nop
        /* === h4 (0x481500): event 004ef228 w/ push PendingMatch_00455bd0+0x80 === */
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueEnd], eax
        call     DualScaledStore_00452740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1561
        mov      eax, dword ptr [g_eventQueueEnd]
        push     OFFSET PendingMatch_00455bd0 + 0x80
        mov      dword ptr [g_fightGroupHead], eax
        mov      dword ptr [g_eventQueueIdx], eax
        call     StoreLoadJmp_00404ef0
        add      esp, 4
        push     OFFSET g_data_004ef228
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_1561:
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
        nop
        /* === h5 (0x481560): timer install + event 004ef258 === */
        push     0x26
        push     OFFSET TripleEntryCountdownInstall_0046a230 + 0xb0
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     OFFSET g_data_004ef258
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret
        nop
        nop
        nop
        /* === h6 (0x481590): pose-fn state-1 install w/ 004816d0 + event === */
    L_1590:
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_15cd
        call     BlockedCounterCluster_004816d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_15ef
        push     OFFSET g_data_004ef278
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret
    L_15cd:
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_1590
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0x1c
        mov      dword ptr [g_framePauseFlag], ecx
    L_15ef:
        ret
        /* === h7 (0x4815f0): pose-fn 2-state w/ 0048e1e0/004ef2b8 === */
    L_15f0:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_1638
        call     CjDispatchCommit_004818e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_16c4
        push     OFFSET g_data_004ef2b8
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_1638:
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x6c]
        mov      dword ptr [g_currentNodeFlags], ecx
        mov      edx, dword ptr [eax*4 + 0x74]
        mov      dword ptr [g_xformScratch2088], edx
        call     ScaledZeroFour_00490740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_16c4
        mov      dword ptr [esi + 8], OFFSET L_15f0
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET L_15f0
        mov      dword ptr [eax*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     BossArrivalSequence_00481950
        mov      dword ptr [g_framePauseFlag], 1
    L_16c4:
        pop      esi
        ret
    }
}
