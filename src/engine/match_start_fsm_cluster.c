/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_state_0053a718;
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
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_00542a54;
extern void CjInstallSelfRouter_00470480(void);
extern void EntryThunkBodyStateMachine_00457bb0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void GuardedPackedSlotInit_00428760(void);
extern void InstallSelf3WayChainCmp_00428d80(void);
extern void InstallSelfPair3Branch_00429240(void);
extern void Phase4DualHelperTrampoline_00412900(void);
extern void Phase4FivePackedHelpers_00412cb0(void);
extern void ScaledArrStore_00429980(void);
extern void ScaledLitLoadCall_00480fe0(void);
extern void ScaledLoadJmp_00428d20(void);
extern void ScaledLoadJmp_00429390(void);
extern void SfxAttenuateAndApply_0048dee0(void);
extern void StreamFlagPackedSelectChain_00469340(void);
extern void TableLookupCall_00489ff0(void);

__declspec(naked) void MatchStartFsmCluster_00468eb0(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel_00542060]
        xor      edx, edx
        shl      eax, 2
        push     esi
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        sub      ecx, edx
        je       L_8f35
        dec      ecx
        je       L_8ed5
        call     FiveCallGuardSetTail_0046f6b0
        pop      esi
        ret      
    L_8ed5:
        mov      dword ptr [eax + 8], OFFSET MatchStartFsmCluster_00468eb0
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      esi, OFFSET MatchStartFsmCluster_00468eb0
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      ecx, dword ptr [eax + 4]
        add      esi, 0x2000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], esi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     ScaledLoadJmp_00429390
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_8f35:
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET MatchStartFsmCluster_00468eb0
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0x14
        mov      dword ptr [g_framePauseFlag], ecx
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_8f60:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 5
        ja       L_9283
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_8f8d:
        call     Phase4FivePackedHelpers_00412cb0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [g_eventQueueChild], 0x23
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, OFFSET L_8f60
        add      edx, 0x2000000
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelf3WayChainCmp_00428d80
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_9007:
        call     Phase4DualHelperTrampoline_00412900
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [g_walkCallback], 0x50
        call     TableLookupCall_00489ff0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [g_eventQueueNotMask], 3
        call     EntryThunkBodyStateMachine_00457bb0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        call     MStackPush3CmpCall_0048eec0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        test     al, bl
        jne      L_90a3
        mov      dword ptr [g_walkCallback], 0x23d7
        call     SfxAttenuateAndApply_0048dee0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [g_walkCallback], 0x88
        call     ScaledLitLoadCall_00480fe0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
    L_90a3:
        mov      dword ptr [g_eventQueueChild], 0x26
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, OFFSET L_8f60
        add      edx, 0x3000000
        mov      dword ptr [ecx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     InstallSelf3WayChainCmp_00428d80
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_9108:
        mov      dword ptr [g_eventQueueNotMask], 0xa
        jmp      L_914f
    L_9114:
        mov      dword ptr [g_eventQueueChild], 0x26
        call     ScaledArrStore_00429980
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      dword ptr [esi + 0x84], 5
        jmp      L_917b
    L_9142:
        mov      eax, dword ptr [g_eventQueueNotMask]
        dec      eax
        mov      dword ptr [g_eventQueueNotMask], eax
        je       L_9190
    L_914f:
        mov      dword ptr [g_eventQueueChild], 0x25
        call     ScaledArrStore_00429980
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_9288
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      dword ptr [esi + 0x84], 4
    L_917b:
        mov      ebx, 1
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_9190:
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      edx, OFFSET L_8f60
        mov      dword ptr [ecx*4 + 0x84], 6
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x6000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     ScaledLoadJmp_00428d20
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_91ef:
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, 0x101
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_data_00542a54
        mov      dword ptr [ecx*4 + 0x74], eax
        call     GuardedPackedSlotInit_00428760
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        cmp      eax, edi
        jne      L_9288
        mov      dword ptr [g_eventQueueChild], 0xf
        mov      dword ptr [esi + 8], OFFSET L_8f60
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ebx, 1
        mov      ecx, OFFSET L_8f60
        mov      dword ptr [edx*4 + 0x84], ebx
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     InstallSelfPair3Branch_00429240
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_9283:
        call     FiveCallGuardSetTail_0046f6b0
    L_9288:
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_jmptbl:
        _emit 0xef
        _emit 0x91
        _emit 0x46
        _emit 0x00
        _emit 0x8d
        _emit 0x8f
        _emit 0x46
        _emit 0x00
        _emit 0x07
        _emit 0x90
        _emit 0x46
        _emit 0x00
        _emit 0x08
        _emit 0x91
        _emit 0x46
        _emit 0x00
        _emit 0x14
        _emit 0x91
        _emit 0x46
        _emit 0x00
        _emit 0x42
        _emit 0x91
        _emit 0x46
        _emit 0x00
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
    L_92b0:
        mov      eax, dword ptr [g_baseSel_00542060]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       L_92cf
        jmp      CjInstallSelfRouter_00470480
    L_92cf:
        mov      dword ptr [eax + 8], OFFSET L_92b0
        mov      ecx, dword ptr [g_baseSel_00542060]
        push     edi
        mov      edi, OFFSET L_92b0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], edx
        call     StreamFlagPackedSelectChain_00469340
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret      
        jmp      StreamFlagPackedSelectChain_00469340
    }
}
