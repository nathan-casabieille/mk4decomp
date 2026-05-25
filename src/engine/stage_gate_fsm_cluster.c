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
/* Round-FSM cluster (708b game, 3 packed helpers + 6-case dispatch): */
/*  h1 (0x47aff0): pre-pose pause/check, set bit 0x17.                */
/*  h2 (0x47b040): event 004ed160 forwarder (sets [0x542060]+0x74=0x20d). */
/*  h3 (0x47b070): pose-fn FSM dispatching on g_data_..._84 (0..5),  */
/*                 jump table @0x47b29c, each case installs next state.*/
/* ------------------------------------------------------------------ */
extern void ScaledLoadIncJmp_00428d00(void);
extern void EsiInstallChainCmpDualCall_00429300(void);
extern void ScaledLoadJmp_00429390(void);
extern void GuardedSeq_004297b0(void);
extern void StageGateFsmCluster_0047b2c0(void);
extern void EsiEdiAliasDualMul10_004906b0(void);
extern unsigned int g_data_004ed160;

extern unsigned int g_framePauseFlag;
extern unsigned int g_data_00542044;
extern unsigned int g_data_0054204c;
extern unsigned int g_data_0054205c;
extern unsigned int g_data_00542060;
extern unsigned int g_data_0054207c;
extern unsigned int g_data_00542080;
extern unsigned int g_data_0054208c;
extern void ArgSarStoreJmp_004594f0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);

__declspec(naked) void RoundFsmCluster_0047aff0(void)
{
    __asm {
        /* === h1 (0x47aff0): pre-pose pause/check w/ bit 0x17 set === */
        mov      dword ptr [g_walkCallback], 0xe666
        call     EsiEdiAliasDualMul10_004906b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b036
        call     GuardedSeq_004297b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b036
        test     byte ptr [g_data_0054208c], 1
        je       short L_b036
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, 0x17
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x28], eax
    L_b036:
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
        /* === h2 (0x47b040): event 004ed160 forwarder w/ 0x20d store === */
        mov      ecx, dword ptr [g_data_00542060]
        mov      eax, 0x20d
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_data_004ed160
        mov      dword ptr [ecx*4 + 0x74], eax
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
        /* === h3 (0x47b070): pose-fn 6-case FSM === */
    L_b070:
        mov      eax, dword ptr [g_data_00542060]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 5
        ja       L_b292
        jmp      dword ptr [eax*4 + L_jmptbl_b29c]
    L_b09d:
        /* case 1: bit 0x13, call 0047b2c0, install state 2 */
        mov      dword ptr [g_data_00542080], 0x13
        call     StageGateFsmCluster_0047b2c0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_b297
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret
    L_b0db:
        /* case 2: bit 0x12, call 0047b2c0, install state 3 */
        mov      dword ptr [g_data_00542080], 0x12
        call     StageGateFsmCluster_0047b2c0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_b297
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret
    L_b119:
        /* case 3: wait counter = 6, fall into L_b19a (install state 4) */
        mov      dword ptr [g_data_0054207c], 6
        jmp      short L_b19a
    L_b125:
        /* case 4: install state 5 via EsiInstallChainCmpDualCall_00429300 */
        mov      dword ptr [g_data_00542080], 0x13
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, OFFSET L_b070
        add      edx, 0x5000000
        mov      dword ptr [ecx*4 + 0x84], 5
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     EsiInstallChainCmpDualCall_00429300
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b18d:
        /* case 5: dec wait counter; if 0 jump to L_b1f8 (state 6), else fall to L_b19a */
        mov      eax, dword ptr [g_data_0054207c]
        dec      eax
        mov      dword ptr [g_data_0054207c], eax
        je       short L_b1f8
    L_b19a:
        /* install state 4 via ScaledLoadIncJmp_00428d00 */
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, OFFSET L_b070
        mov      dword ptr [ecx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x4000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     ScaledLoadIncJmp_00428d00
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b1f8:
        /* install state 6 via ScaledLoadJmp_00429390 */
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      ecx, dword ptr [g_data_00542060]
        mov      edx, OFFSET L_b070
        mov      dword ptr [ecx*4 + 0x84], 6
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x6000000
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_data_00542044]
        inc      eax
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_data_00542060]
        mov      dword ptr [eax*4 + 0x84], edi
        call     ScaledLoadJmp_00429390
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b256:
        /* case 0: clear wait, bit 0x12, call 0047b2c0, install state 1 */
        mov      dword ptr [g_data_0054207c], edi
        mov      dword ptr [g_data_00542080], 0x12
        call     StageGateFsmCluster_0047b2c0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_b297
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_data_0054204c], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret
    L_b292:
        call     FiveCallGuardSetTail_0046f6b0
    L_b297:
        pop      edi
        pop      esi
        ret
        /* 2-byte nop padding before jump table: 8b ff (mov edi, edi) */
        _emit    0x8b
        _emit    0xff
    L_jmptbl_b29c:
        /* 6-entry jump table: 0, 1, 2, 3, 4, 5 */
        _emit    0x56  /* case 0 -> 0x47b256 */
        _emit    0xb2
        _emit    0x47
        _emit    0x00
        _emit    0x9d  /* case 1 -> 0x47b09d */
        _emit    0xb0
        _emit    0x47
        _emit    0x00
        _emit    0xdb  /* case 2 -> 0x47b0db */
        _emit    0xb0
        _emit    0x47
        _emit    0x00
        _emit    0x19  /* case 3 -> 0x47b119 */
        _emit    0xb1
        _emit    0x47
        _emit    0x00
        _emit    0x25  /* case 4 -> 0x47b125 */
        _emit    0xb1
        _emit    0x47
        _emit    0x00
        _emit    0x8d  /* case 5 -> 0x47b18d */
        _emit    0xb1
        _emit    0x47
        _emit    0x00
    }
}
