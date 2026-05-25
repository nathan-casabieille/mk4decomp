/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
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
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

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
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern void CjDispatchCommit_004818e0(void);
extern void BossArrivalSequence_00481950(void);
extern void SwapTwoGlobals_004911c0(void);
extern void TableHitOrSchedule_004be7a0(void);
extern unsigned int g_data_004ef290;
extern unsigned int g_data_004ef2c0;
extern unsigned int g_data_00538124;
extern unsigned int g_const_00481a10;
extern unsigned int g_const_00481a80;

extern unsigned int g_load_0052ab10;
extern void ArgSarStoreJmp_004594f0(void);
extern void ScaledInitWithCounterAndType_004314f0(void);

__declspec(naked) void BlockedCounterCluster_004816d0(void)
{
    __asm {
    L_16d0:
        /* H1: counter update */
        mov      eax, dword ptr [g_fightGroupHead]
        and      dword ptr [eax*4 + 0x34], 0xfffffffe
        call     SwapTwoGlobals_004911c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1707
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_fightGroupHead]
        sub      eax, 0x191eb
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x64], eax
    L_1707:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* H2: trigger ground impact */
        call     L_16d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1749
        push     0x26
        push     OFFSET g_const_00481a10
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     0x26
        push     OFFSET g_const_00481a80
        call     StoreTwoCall_0049cb40
        add      esp, 8
        push     OFFSET g_data_004ef2c0
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
    L_1749:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* H3 (L_1750): per-entity FSM init */
    L_1750:
        mov      eax, dword ptr [g_baseSel_00542060]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_1791
        call     CjDispatchCommit_004818e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1813
        push     OFFSET g_data_004ef290
        call     ArgSarStoreJmp_004594f0
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret
    L_1791:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [ecx*4 + 0x6c]
        mov      dword ptr [g_currentNodeFlags], edx
        mov      ecx, dword ptr [ecx*4 + 0x74]
        mov      dword ptr [g_xformScratch2088], ecx
        mov      dword ptr [eax + 8], OFFSET L_1750
        mov      edx, dword ptr [g_baseSel_00542060]
        mov      dword ptr [edx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      edx, OFFSET L_1750
        mov      dword ptr [g_currentNodeIdx], ecx
        add      edx, 0x1000000
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel_00542060]
        mov      dword ptr [eax*4 + 0x84], 0
        call     BossArrivalSequence_00481950
        mov      dword ptr [g_framePauseFlag], 1
    L_1813:
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
        /* H4 (L_1820): per-entity tick */
    L_1820:
        mov      eax, dword ptr [g_baseSel_00542060]
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_1874
        push     0x1392
        call     TableHitOrSchedule_004be7a0
        mov      eax, dword ptr [g_load_0052ab10]
        mov      ecx, 0xfffffd71
        add      esp, 4
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x70], ecx
        call     ScaledInitWithCounterAndType_004314f0
        pop      edi
        pop      esi
        ret
    L_1874:
        mov      edi, 1
        mov      dword ptr [g_eventQueueWorkType], 0x3d
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_data_00538124], edi
        call     Push16Call_00489f50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_18d8
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x58]
        sub      eax, 0x147a
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      dword ptr [esi + 8], OFFSET L_1820
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], edi
    L_18d8:
        pop      edi
        pop      esi
        ret
    }
}
