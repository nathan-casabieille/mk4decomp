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

extern unsigned int g_data_004f1610;
extern unsigned int g_data_004f1628;
extern unsigned int g_data_004f163c;
extern unsigned int g_data_00538158;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054206c;
extern unsigned int g_data_00542074;
extern unsigned int g_data_00542080;
extern unsigned int g_data_00542088;
extern unsigned int g_data_00542094;
extern unsigned int g_data_005431b8;
extern void ArgSarStoreJmp_004594f0(void);
extern void DualGatedStateYield_0048fc80(void);
extern void EsiEdiAliasDualMul10_004906b0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void GuardedPackedSlotInit_00428760(void);
extern void IterStepNegStore_00490b10(void);
extern void NotMaskStorePair_0045f440(void);
extern void PunchAnimCluster_00496d80(void);
extern void PushPopWalkSet1006_00470ee0(void);
extern void ScaledChain3c7c_0048f930(void);
extern void ScaledClearJmp_00428d40(void);
extern void ScaledInit_0048d490(void);
extern void ScaledLoadJmp_00428d20(void);
extern void ScaledLoadJmp_24_00429790(void);
extern void ScaledLookupGuardJmpIndirect_004949f0(void);
extern void TableLookupCall_00489ff0(void);
extern void TournamentMenuFsmCluster_004960e0(void);

__declspec(naked) void ComboFinisherEventCluster_00495dc0(void)
{
    __asm {
        /* === h1 (0x495dc0): event 004f1610 forwarder === */
        push     OFFSET g_data_004f1610
        call     ScaledLookupGuardJmpIndirect_004949f0
        add      esp, 4
        ret
        nop
        nop
        /* === h2 (0x495dd0): event 004f1628 forwarder === */
        mov      eax, dword ptr [g_data_00542060]
        push     OFFSET g_data_004f1628
        mov      dword ptr [eax*4 + 0x74], 0x404
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x314
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x68], eax
        call     ArgSarStoreJmp_004594f0
        add      esp, 4
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
        /* === h3 (0x495e10): pose-fn 3-state combo handler === */
    L_5e10:
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      ebx, 1
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_5fc5
        dec      eax
        je       L_5f26
        dec      eax
        jne      L_6067
        mov      dword ptr [g_data_0054206c], 0x14
        call     ScaledInit_0048d490
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        mov      eax, dword ptr [g_data_00542088]
        cmp      eax, ebx
        je       L_5fe8
        jl       short L_5e90
        call     ScaledChain3c7c_0048f930
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        cmp      dword ptr [g_data_0054206c], 3
        jge      L_5fe8
    L_5e90:
        mov      dword ptr [g_data_0054206c], 0xe666
        call     EsiEdiAliasDualMul10_004906b0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        mov      dword ptr [g_data_00542088], 0x10000
        call     PunchAnimCluster_00496d80
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        call     NotMaskStorePair_0045f440
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        mov      ecx, dword ptr [g_data_0054205c]
        mov      edx, dword ptr [g_data_00538158]
        mov      eax, 0x10
        cmp      ecx, edx
        mov      dword ptr [g_data_00542074], eax
        je       short L_5efb
        mov      eax, 0x1000
        mov      dword ptr [g_data_00542074], eax
    L_5efb:
        and      eax, dword ptr [g_data_0054206c]
        mov      dword ptr [g_data_00542094], eax
        jne      L_6067
        call     PushPopWalkSet1006_00470ee0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        call     FiveCallGuardSetTail_0046f6b0
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_5f26:
        mov      dword ptr [g_data_0054206c], 0x1f
        call     TableLookupCall_00489ff0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        push     OFFSET g_data_005431b8
        call     GuardedPackedSlotInit_00428760
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        cmp      eax, edi
        jne      L_60d0
        mov      dword ptr [g_data_00542080], 6
        mov      dword ptr [esi + 8], OFFSET L_5e10
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_5e10
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     ScaledClearJmp_00428d40
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_5fc5:
        mov      dword ptr [g_data_0054206c], 0x14
        call     ScaledInit_0048d490
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        cmp      dword ptr [g_data_00542088], ebx
        jne      short L_6067
    L_5fe8:
        push     OFFSET g_data_004f163c
        call     IterStepNegStore_00490b10
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        cmp      eax, edi
        jne      L_60d0
        mov      dword ptr [g_data_00542080], 8
        mov      dword ptr [esi + 8], OFFSET L_5e10
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_5e10
        add      ecx, 0x3000000
        mov      dword ptr [eax*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     TournamentMenuFsmCluster_004960e0
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_6067:
        call     DualGatedStateYield_0048fc80
        test     eax, eax
        jne      short L_60d0
        call     ScaledLoadJmp_24_00429790
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_60d0
        mov      dword ptr [esi + 8], OFFSET L_5e10
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, OFFSET L_5e10
        mov      dword ptr [eax*4 + 0x84], ebx
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x1000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_data_00542060]
        mov      dword ptr [edx*4 + 0x84], edi
        call     ScaledLoadJmp_00428d20
        mov      dword ptr [g_framePauseFlag], ebx
    L_60d0:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
