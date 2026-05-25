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

extern unsigned int g_data_004d57ac;
extern unsigned int g_data_004e27cc;
extern unsigned int g_data_00535e48;
extern unsigned int g_data_00537f30;
extern unsigned int g_data_00537f48;
extern unsigned int g_data_005380e0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_player2NodeIdx;
extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_xformDirtyFlags;
extern void CallSetPause_0041f830(void);
extern void DispatcherComplex181_00426310(void);
extern void DualAddSar_004ab600(void);
extern void GuardedRangeCmpFpuJmp_0042b8d0(void);
extern void GuardedScaledCall_0048a020(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void PendingMatch_00459510(void);
extern void RoundCleanupCluster_00427690(void);
extern void SaveCallRestore_004049d0(void);
extern void StoreIncrMStackPush6_004275c0(void);
extern void TableLookupCall_0048a130(void);

__declspec(naked) void HitReactionCluster_0045c080(void)
{
    __asm {
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      ecx, eax
        shr      eax, 0xc
        and      ecx, 0xfff
        and      eax, 0xfff
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueCurrent], eax
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
        nop      
        mov      dword ptr [g_eventQueueWorkType], 0x20000
        call     GuardedRangeCmpFpuJmp_0042b8d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c0cd
        jmp      PendingMatch_00459510
    L_c0cd:
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [g_walkCallback]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        call     DualAddSar_004ab600
        mov      al, byte ptr [g_walkCallback]
        mov      dword ptr [g_eventQueueWorkType], 0x64a
        test     al, 1
        je       L_c122
        mov      dword ptr [g_eventQueueWorkType], 0x66d
    L_c122:
        call     Push16Call_00489f50
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      dword ptr [g_data_004d57ac], eax
        jmp      PendingMatch_00459510
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        inc      eax
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_eventQueueWorkType], 0x627
        call     Push16Call_00489f50
        mov      eax, dword ptr [g_data_004d57ac]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      dword ptr [g_data_004d57ac], eax
        jmp      PendingMatch_00459510
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
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_player1NodeIdx]
        cmp      eax, ecx
        jne      L_c1ea
        cmp      dword ptr [g_data_00537f48], 9
        jne      L_c1e5
        mov      dword ptr [g_walkCallback], 0x1a
        call     TableLookupCall_0048a130
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c21d
        jmp      PendingMatch_00459510
    L_c1e5:
        jmp      PendingMatch_00459510
    L_c1ea:
        cmp      eax, dword ptr [g_player2NodeIdx]
        jne      L_c21d
        cmp      dword ptr [g_data_005380e0], 9
        jne      L_c218
        mov      dword ptr [g_walkCallback], 0x1a
        call     TableLookupCall_0048a130
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c21d
        jmp      PendingMatch_00459510
    L_c218:
        jmp      PendingMatch_00459510
    L_c21d:
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_player1NodeIdx]
        cmp      eax, ecx
        jne      L_c25a
        cmp      dword ptr [g_data_00537f48], 9
        jne      L_c255
        mov      dword ptr [g_walkCallback], 0x1c
        call     TableLookupCall_0048a130
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c28d
        jmp      PendingMatch_00459510
    L_c255:
        jmp      PendingMatch_00459510
    L_c25a:
        cmp      eax, dword ptr [g_player2NodeIdx]
        jne      L_c28d
        cmp      dword ptr [g_data_005380e0], 9
        jne      L_c288
        mov      dword ptr [g_walkCallback], 0x1c
        call     TableLookupCall_0048a130
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c28d
        jmp      PendingMatch_00459510
    L_c288:
        jmp      PendingMatch_00459510
    L_c28d:
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      ebx, 4
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, ebx
        ja       L_c591
        jmp      dword ptr [eax*4 + L_c5a4_jmptbl]
        mov      ecx, 0x50d8b0
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DispatcherComplex260_00407400
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_c59b
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x30], 0x2f
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xffc40000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        call     MStackPushComplexCallPop_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xffffc667
        mov      dword ptr [edx*4 + 0x5c], 0xa0000
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [esi + 8], 0x45c290
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x14
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        push     0x30
        call     SaveCallRestore_004049d0
        add      esp, 4
        push     0x30
        call     SaveCallRestore_004049d0
        mov      dword ptr [esi + 8], 0x45c290
        mov      dword ptr [esi + 0x84], 3
        add      esp, 4
        mov      dword ptr [g_pendingNodeType], 0x14
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      ax, word ptr [g_data_004e27cc]
        push     eax
        call     TaggedSceneDispatch_004be690
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], edi
        add      esp, 4
        mov      dword ptr [ecx*4 + 0x74], edi
        mov      dword ptr [esi + 8], 0x45c290
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 0x14
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, 0x3999
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x74], eax
        mov      dword ptr [esi + 8], 0x45c290
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], 0x28
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        call     AllocSlotPushTripleGlobals_00427470
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        mov      eax, 0x4d5550
        mov      dword ptr [g_walkCallback], 0x30
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_acc_00542078], 0xfff60000
        mov      dword ptr [g_eventQueueNotMask], 0xffd20000
        call     Push70CallScaleArith_00457ad0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        call     MStackPop4Rewrite_004274f0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_c59b
        mov      ecx, dword ptr [g_data_00537f30]
        mov      dword ptr [g_walkCallback], ecx
        call     StoreIncrMStackPush6_004275c0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      ebx, 1
        mov      dword ptr [g_eventQueueWorkType], 0x30
        mov      dword ptr [g_acc_00542078], 0x230000
        mov      dword ptr [g_eventQueueNotMask], 0xffd20000
        mov      dword ptr [g_currentNodeFlags], ebx
        call     DispatcherComplex181_00426310
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        call     RoundCleanupCluster_00427690
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        cmp      dword ptr [g_walkCallback], edi
        je       L_c59b
        mov      edx, dword ptr [g_data_00537f30]
        mov      eax, 0x5424b0
        shr      eax, 2
        lea      ecx, [edx - 1]
        mov      dword ptr [g_currentNodeIdx], eax
        cmp      ecx, 2
        mov      dword ptr [g_data_00535e48], ecx
        jg       L_c570
        add      eax, ecx
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_walkCallback], eax
        call     GuardedScaledCall_0048a020
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
    L_c570:
        mov      dword ptr [esi + 8], 0x45c290
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_c591:
        push     0x2f
        call     SaveCallRestore_004049d0
        add      esp, 4
    L_c59b:
        call     CallSetPause_0041f830
    L_c5a0:
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_c5a4_jmptbl:
        /* 5-entry jump table */
        _emit    0x52  /* case 0 -> 0x45c452 */
        _emit    0xc4
        _emit    0x45
        _emit    0x00
        _emit    0xc1  /* case 1 -> 0x45c2c1 */
        _emit    0xc2
        _emit    0x45
        _emit    0x00
        _emit    0x8e  /* case 2 -> 0x45c38e */
        _emit    0xc3
        _emit    0x45
        _emit    0x00
        _emit    0xcb  /* case 3 -> 0x45c3cb */
        _emit    0xc3
        _emit    0x45
        _emit    0x00
        _emit    0x12  /* case 4 -> 0x45c412 */
        _emit    0xc4
        _emit    0x45
        _emit    0x00
    }
}
