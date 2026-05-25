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
extern unsigned int g_player1NodeIdx;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

/* ------------------------------------------------------------------ */
/* Pose-copy + idle-decision cluster (560b game, falls through into  */
/* sibling 0x4539d0)                                                  */
/* ------------------------------------------------------------------ */
extern void MStackCall_004062f0(void);
extern void Chain2AxisDiffStoreTailJmp_0044cad0(void);
extern void MStackPush3SideStore_0044cb80(void);
extern void DualScaledStore_00452740(void);
extern void JuggleSetupCluster_004539d0(void);
extern void func_00453a01(void);
extern void Thunk_0049cbc0(void);
extern unsigned int g_data_004e7fd0;
extern unsigned int g_data_004e8020;
extern unsigned int g_data_0053a7a0;
extern unsigned int g_eventQueueEnd;
extern unsigned int g_eventQueueIdx;
extern unsigned int g_xformScratch2088;

extern unsigned int g_framePauseFlag;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_fightGroupHead;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_eventQueueWorkType;
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_xformDirtyFlags;

__declspec(naked) void PoseCopyIdleCluster_004537a0(void)
{
    __asm {
        /* === Helper 1: pose-copy from slot ECX to slot EAX === */
        call     MStackCall_004062f0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_38a4
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_fightGroupHead]
        shl      ecx, 2
        shl      eax, 2
        mov      edx, dword ptr [ecx + 0x54]
        mov      dword ptr [eax + 0x54], edx
        mov      edx, 0xfffed3b7
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x58], edx
        mov      edx, dword ptr [ecx + 0x5c]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x5c], edx
        mov      edx, dword ptr [ecx + 0x60]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x60], edx
        mov      edx, dword ptr [ecx + 0x64]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x64], edx
        mov      edx, dword ptr [ecx + 0x68]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x68], edx
        mov      ecx, dword ptr [ecx + 0x34]
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      eax, dword ptr [eax + 0x34]
        and      ecx, 1
        and      al, 0xfe
        mov      dword ptr [g_eventQueueCurrent], ecx
        or       eax, ecx
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4 + 0x30], 0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x38], edx
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 4
        or       edx, eax
        test     ecx, ecx
        mov      dword ptr [g_xformDirtyFlags], edx
        je       short L_38a4
        mov      ecx, edx
        xor      ecx, eax
        mov      dword ptr [g_xformDirtyFlags], ecx
    L_38a4:
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
        /* === Helper 2 (0x4538b0): idle/standup dispatcher === */
    L_38b0:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       short L_3935
        dec      eax
        je       short L_38dc
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        ret
    L_38dc:
        mov      edx, dword ptr [g_data_0053a7a0]
        mov      ecx, OFFSET g_data_004e8020
        shr      ecx, 2
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [g_eventQueueNotMask], edi
        mov      dword ptr [g_xformScratch2088], 0x20c
        mov      dword ptr [esi + 8], OFFSET L_38b0
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET L_38b0
        mov      dword ptr [eax*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      ecx, 0x2000000
        jmp      JuggleSetupCluster_004539d0
    L_3935:
        call     DualScaledStore_00452740
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_00453a01
        call     Chain2AxisDiffStoreTailJmp_0044cad0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_00453a01
        mov      dword ptr [g_eventQueueWorkType], 0xe666
        mov      dword ptr [g_walkCallback], 0xfffef334
        call     MStackPush3SideStore_0044cb80
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_00453a01
        mov      ecx, dword ptr [g_data_0053a7a0]
        mov      eax, OFFSET g_data_004e7fd0
        shr      eax, 2
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      dword ptr [g_eventQueueNotMask], edi
        mov      dword ptr [g_xformScratch2088], 0x666
        mov      dword ptr [esi + 8], OFFSET L_38b0
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      ecx, OFFSET L_38b0
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      ecx, 0x1000000
        /* Fall-through to JuggleSetupCluster_004539d0 (sibling immediately after). */
    }
}
