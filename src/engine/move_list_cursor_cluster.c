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

extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_pendingNodeType;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformDirtyFlags;
extern void PendingMatch_00459510(void);
extern void ScaledIterStep_0045c020(void);

__declspec(naked) void MoveListCursorCluster_0045b420(void)
{
    __asm {
    L_b420:
        /* H1 */
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b445
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x48], ecx
        jmp      PendingMatch_00459510
    L_b445:
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
        /* H2 */
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      eax, dword ptr [g_framePauseFlag]
        and      ecx, 0xff
        test     eax, eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        jne      short L_b47c
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x78], ecx
        jmp      PendingMatch_00459510
    L_b47c:
        ret
        nop
        nop
        nop
        /* H3 */
        mov      ecx, dword ptr [g_baseSel_00542060]
        mov      eax, dword ptr [ecx*4 + 0x78]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [ecx*4 + 0x78], eax
        jne      short L_b4a1
        jmp      PendingMatch_00459510
    L_b4a1:
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [edx*4 + 0x48]
        dec      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4]
        shr      eax, 0x18
        cmp      eax, 0x3a
        mov      dword ptr [g_walkCallback], eax
        je       short L_b4e4
    L_b4c9:
        dec      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4]
        shr      eax, 0x18
        cmp      eax, 0x3a
        mov      dword ptr [g_walkCallback], eax
        jne      short L_b4c9
    L_b4e4:
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [edx*4 + 0x48], ecx
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
        /* H4 */
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, dword ptr [edx*4 + 0x48]
        mov      dword ptr [g_eventQueueTotal], ecx
        mov      eax, dword ptr [edx*4 + 0x34]
        cmp      eax, 0x10
        mov      dword ptr [g_walkCallback], eax
        jne      short L_b52e
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_b52e:
        cmp      eax, 0x11
        jne      short L_b53d
        mov      eax, 7
        mov      dword ptr [g_walkCallback], eax
    L_b53d:
        add      ecx, eax
        mov      dword ptr [g_eventQueueTotal], ecx
        mov      ecx, dword ptr [ecx*4]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [edx*4 + 0x48], ecx
        jmp      PendingMatch_00459510
        nop
        nop
        /* H5 */
        cmp      dword ptr [g_xformScratch2088], 1
        jne      short L_b56e
        jmp      L_b420
    L_b56e:
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b581
        jmp      PendingMatch_00459510
    L_b581:
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
        /* H6 (L_b590): install state 1 */
    L_b590:
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, 1
        shl      eax, 2
        mov      dword ptr [eax + 0x84], 0
        mov      dword ptr [eax + 8], OFFSET L_b590
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], ecx
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
        /* H7: combined call + dispatch */
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b614
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [g_currentNodeIdx], eax
        call     eax
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b614
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_b601
        jmp      L_b420
    L_b601:
        call     ScaledIterStep_0045c020
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b614
        jmp      PendingMatch_00459510
    L_b614:
        ret
    }
}
