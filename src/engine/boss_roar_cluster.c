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
extern unsigned int g_dualBitGate_0053a7b0;
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
extern unsigned int g_stateCountdown_0053a3c0;
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

extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004eefd8;
extern unsigned int g_data_004ef010;
extern unsigned int g_data_00500710;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern void ArgSarStoreJmp_004594f0(void);
extern void CinematicCFsmCluster_004884a0(void);
extern void FlagThunk4EntryDispatcher_0040a470(void);
extern void IncThunkPlusCjDispatch_00483b80(void);
extern void InstallSelfIndirectJmpNeg_0048f4f0(void);
extern void InstallSelfIndirectJmp_0048f3f0(void);
extern void InstallSelfOrCmpJmp_0048f570(void);
extern void TableLookupCall_00489ff0(void);

__declspec(naked) void BossRoarCluster_00488210(void)
{
    __asm {
        /* === Helper 1 (0x488210): set 0x83 + push 488250 continuation === */
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0x83
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      eax, dword ptr [g_data_004d57ac]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], OFFSET L_8250
        jmp      InstallSelfIndirectJmpNeg_0048f4f0
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
        /* === Helper 2 (0x488250): 3-state FSM === */
    L_8250:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       short L_8340
        dec      eax
        je       short L_82ab
        dec      eax
        je       short L_8284
        call     StackPopDispatchTagged_0041f780
        pop      esi
        ret
    L_8284:
        mov      dword ptr [esi + 8], OFFSET L_8250
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_82ab:
        mov      dword ptr [g_walkCallback], 0x40
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8361
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0xffffff7d
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      dword ptr [esi + 8], OFFSET L_8250
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET L_8250
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfOrCmpJmp_0048f570
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_8340:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_8250
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], eax
    L_8361:
        pop      esi
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
        /* === Helper 3 (0x488370): callback continuation === */
    L_8370:
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_83be
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0xf5c
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      eax, dword ptr [g_data_004d57ac]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], OFFSET L_8410
        jmp      InstallSelfIndirectJmp_0048f3f0
    L_83be:
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, 0xffffee15
        mov      dword ptr [edx*4 + 0x74], 0x1002
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [edx*4 + 0x4c], ecx
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_8370
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 4
        mov      dword ptr [g_framePauseFlag], ecx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 4 (0x488410): event 004eefd8 forwarder === */
    L_8410:
        mov      eax, OFFSET g_data_00500710
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        call     ScaledArrStore_004298c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8446
        call     IncThunkPlusCjDispatch_00483b80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8446
        push     OFFSET g_data_004eefd8
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_8446:
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
        /* === Helper 5: event 004ef010 forwarder === */
        push     OFFSET g_data_004ef010
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
        ret
        nop
        nop
        /* === Helper 6: 0xf event + jmp 004884a0 === */
        mov      dword ptr [g_walkCallback], 0xf
        call     FlagThunk4EntryDispatcher_0040a470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_847d
        jmp      CinematicCFsmCluster_004884a0
    L_847d:
        ret
        nop
        nop
        /* === Helper 7: 9 event + jmp 004884a0 === */
        mov      dword ptr [g_walkCallback], 9
        call     FlagThunk4EntryDispatcher_0040a470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_849d
        jmp      CinematicCFsmCluster_004884a0
    L_849d:
        ret
    }
}
