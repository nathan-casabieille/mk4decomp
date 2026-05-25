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

/* ------------------------------------------------------------------ */
/* Per-tick main chain (750b game, 2 packed helpers):                 */
/*  h1 (0x481070): 14-stage pause-guarded chain (490130 → 494580 →    */
/*                 48f720 → 4903xx series → 486530 → 481360 → 470310 →*/
/*                 0040eb80 → 00427b60 → 0048e2f0 → 49cb40 timer install). */
/*  h2 (0x481340): wait + tail-jmp CallSetPause_0041f830.                     */
/* ------------------------------------------------------------------ */
extern void PendingMatch_0040eb80(void);
extern void PoseChainInstallCluster_00427b60(void);
extern void ScaledChainNegStore_00470310(void);
extern void CallPauseConstStoreJmp_00481360(void);
extern void ScaledLoadCmp1003JmpDispatch_00486530(void);
extern void PushCallPauseScaledJmpInd_0048e2f0(void);
extern void ScaledInit_0048f720(void);
extern void ClearBit2x34_00490130(void);
extern void MStackPushSet0004_00490230(void);
extern void ScaledAndAl7f_004902f0(void);
extern void ScaledAndAldf_00490330(void);
extern void ScaledAndAlbf_00490350(void);
extern void ScaledAndAlfe_00490390(void);
extern unsigned int g_data_0052ab40;
extern unsigned int g_data_00543888;

extern unsigned int g_data_00537f48;
extern unsigned int g_data_005380e0;
extern unsigned int g_data_00538158;
extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_00542048;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542060;
extern unsigned int g_data_00542094;
extern void CallSetPause_0041f830(void);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void GateDispatch6c_00494580(void);
extern void ScaledAndAlf7_00490310(void);
extern void ScaledLitLoadCall_00480fe0(void);

__declspec(naked) void MainTickChain_00481070(void)
{
    __asm {
        push     esi
        call     ClearBit2x34_00490130
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      L_1336
        mov      eax, dword ptr [g_data_00542060]
        mov      eax, dword ptr [eax*4 + 0x30]
        cmp      eax, esi
        mov      dword ptr [g_data_00542044], eax
        je       short L_10bc
        mov      eax, dword ptr [eax*4]
        cmp      eax, 0x6c
        mov      dword ptr [g_walkCallback], eax
        jne      short L_10bc
        call     GateDispatch6c_00494580
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_10bc:
        call     ScaledInit_0048f720
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAldf_00490330
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAlbf_00490350
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAl7f_004902f0
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAlfe_00490390
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     ScaledAndAlf7_00490310
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        call     MStackPushSet0004_00490230
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        cmp      dword ptr [g_data_00543888], esi
        jne      short L_114c
        call     DualCallPauseDirtyJmp_00490c30
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_114c:
        mov      dword ptr [g_data_00543888], esi
        call     ScaledLoadCmp1003JmpDispatch_00486530
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [ecx*4 + 0x34]
        cmp      eax, 0x10
        mov      dword ptr [g_walkCallback], eax
        jne      short L_1184
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_1184:
        cmp      eax, 0x11
        jne      short L_1193
        mov      eax, 7
        mov      dword ptr [g_walkCallback], eax
    L_1193:
        cmp      eax, esi
        jne      short L_11a8
        call     CallPauseConstStoreJmp_00481360
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_11a8:
        mov      edx, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [edx*4 + 0x74]
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x60], ecx
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [eax + 0x5c], esi
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x74], edx
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x4c], ecx
        mov      edx, dword ptr [g_data_0054205c]
        mov      dword ptr [edx*4 + 0x44], esi
        mov      dword ptr [g_walkCallback], esi
        lea      eax, [edx*4]
        mov      dword ptr [eax + 0x78], esi
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x80], ecx
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x60], edx
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x68], ecx
        call     ScaledChainNegStore_00470310
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        mov      edx, dword ptr [g_data_0054205c]
        mov      ecx, dword ptr [g_data_00538158]
        mov      eax, dword ptr [g_data_00537f48]
        cmp      edx, ecx
        mov      dword ptr [g_walkCallback], eax
        je       short L_124a
        mov      eax, dword ptr [g_data_005380e0]
        mov      dword ptr [g_walkCallback], eax
    L_124a:
        cmp      eax, 0xa
        jne      short L_1260
        call     PendingMatch_0040eb80
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
    L_1260:
        mov      eax, dword ptr [g_data_0052ab40]
        mov      dword ptr [g_walkCallback], eax
        and      eax, 0x2000
        mov      dword ptr [g_data_00542094], eax
        jne      L_1336
        mov      eax, dword ptr [g_data_00542060]
        mov      eax, dword ptr [eax*4 + 0x80]
        cmp      eax, 0x6666
        mov      dword ptr [g_walkCallback], eax
        jle      L_1336
        call     PoseChainInstallCluster_00427b60
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1336
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, dword ptr [ecx*4 + 0x7c]
        cmp      eax, 3
        mov      dword ptr [g_walkCallback], eax
        jl       short L_12cb
        call     PushCallPauseScaledJmpInd_0048e2f0
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_1336
    L_12cb:
        mov      edx, dword ptr [g_data_00542060]
        push     0x31
        push     OFFSET L_1340
        mov      dword ptr [edx*4 + 0x80], esi
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [eax*4 + 0x7c], esi
        call     StoreTwoCall_0049cb40
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, dword ptr [g_data_00542044]
        add      esp, 8
        mov      eax, dword ptr [ecx*4 + 0x3c]
        mov      dword ptr [g_data_00542048], eax
        mov      dword ptr [edx*4 + 0x3c], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      ecx, dword ptr [g_data_00542044]
        mov      eax, dword ptr [eax*4 + 0x38]
        mov      dword ptr [g_data_00542048], eax
        mov      dword ptr [ecx*4 + 0x38], eax
    L_1336:
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
        /* === h2 (0x481340): wait+tail-jmp 0041f830 === */
    L_1340:
        mov      dword ptr [g_walkCallback], 0x2e
        call     ScaledLitLoadCall_00480fe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_135d
        jmp      CallSetPause_0041f830
    L_135d:
        ret
    }
}
