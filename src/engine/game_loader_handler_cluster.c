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
extern unsigned int g_data_00542050;
extern unsigned int g_data_00542070;
extern unsigned int g_data_00542084;
extern unsigned int g_state_0054208c;
extern unsigned int g_state_00542088;
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_state_00542080;
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
extern unsigned int g_state_0054207c;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_state_00541fa4;
extern unsigned int g_state_00541fa8;
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

extern unsigned int g_data_00541dc4;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_00542054;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_0054207c;
extern unsigned int g_data_00542bd4;
extern void CjInstallSelfRouter_00470480(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void FlagThunk4EntryDispatcher_0040a470(void);
extern void GateDispatch6c_00494580(void);
extern void GuardedPackedSlotInit_00428760(void);
extern void InstallSelfMStackIndirect_00487920(void);
extern void ScaledAndAlfb_00490370(void);
extern void ScaledAndAlfe_00490390(void);
extern void ScaledLoadOrSetJmp_00406b20(void);
extern void StateDispatchTable_00490fc0(void);
extern void TableLookupCall_0048a160(void);
extern void TripleEntryBitsetMStack_00487890(void);

__declspec(naked) void GameLoaderHandlerCluster_004876f0(void)
{
    __asm {
        /* Helper 1: simple guard over ScaledAndAlfb_00490370/ScaledAndAlfe_00490390. */
        call     ScaledAndAlfb_00490370
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7703
        jmp      ScaledAndAlfe_00490390
    L_7703:
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
        /* Helper 2 (L_7710): per-entity state-clear. */
    L_7710:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_7739
        call     CjInstallSelfRouter_00470480
        pop      esi
        ret
        /* Helper 3 (L_7739): advance-to-state-1. */
    L_7739:
        call     StateDispatchTable_00490fc0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_77a7
        mov      edx, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [edx*4 + 0x24], ecx
        mov      eax, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [g_data_0054206c]
        mov      dword ptr [eax*4 + 0x28], ecx
        mov      edx, dword ptr [g_data_0054205c]
        mov      dword ptr [g_data_00542044], edx
        call     ScaledLoadOrSetJmp_00406b20
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_77a7
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_7710
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], 0x28
        mov      dword ptr [g_framePauseFlag], eax
    L_77a7:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* Helper 4 (L_77b0): advance-to-state-2 + tail-jmp InstallSelfMStackIndirect_00487920. */
        call     GateDispatch6c_00494580
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7812
        call     DualCallPauseDirtyJmp_00490c30
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7812
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 1
        mov      dword ptr [g_data_0054206c], eax
        push     OFFSET g_data_00542bd4
        mov      dword ptr [ecx*4 + 0x5c], eax
        call     GuardedPackedSlotInit_00428760
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_7812
        mov      dword ptr [g_data_0054207c], 0x201
        mov      dword ptr [g_data_00542054], OFFSET L_7820
        jmp      InstallSelfMStackIndirect_00487920
    L_7812:
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
        /* Helper 5 (L_7820): periodic ticker with wrap+dispatch. */
    L_7820:
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [ecx*4 + 0x5c]
        dec      eax
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [g_data_00541dc4], eax
        jne      short L_7844
        mov      eax, 8
        mov      dword ptr [g_data_0054206c], eax
    L_7844:
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_data_00541dc4]
        test     eax, eax
        je       short L_7859
        jmp      TripleEntryBitsetMStack_00487890
    L_7859:
        mov      dword ptr [g_data_0054206c], 0xf
        call     FlagThunk4EntryDispatcher_0040a470
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_788e
        mov      dword ptr [g_data_0054206c], 5
        call     TableLookupCall_0048a160
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_788e
        jmp      TripleEntryBitsetMStack_00487890
    L_788e:
        ret
    }
}
