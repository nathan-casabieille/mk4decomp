/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

/* ------------------------------------------------------------------ */
/* Round-FSM cluster (708b game, 3 packed helpers + 6-case dispatch): */
/*  h1 (0x47aff0): pre-pose pause/check, set bit 0x17.                */
/*  h2 (0x47b040): event 004ed160 forwarder (sets [0x542060]+0x74=0x20d). */
/*  h3 (0x47b070): pose-fn FSM dispatching on g_data_..._84 (0..5),  */
/*                 jump table @0x47b29c, each case installs next state.*/
/* ------------------------------------------------------------------ */
extern void ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain(void);
extern void EsiInstallChainCmpDualCall(void);
extern void ScaledLoadJmp_00429390(void);
extern void GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void);
extern void StageGateFsmCluster(void);
extern void EsiEdiAliasDualMul10(void);
extern unsigned int g_dispatchSave737;

extern void ArgSarStoreJmp(void);
extern void FiveCallGuardSetTail(void);

__declspec(naked) void RoundFsmCluster_0047aff0(void)
{
    __asm {
        /* === h1 (0x47aff0): pre-pose pause/check w/ bit 0x17 set === */
        mov      dword ptr [g_walkCallback], 0xe666
        call     EsiEdiAliasDualMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b036
        call     GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b036
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_b036
        mov      ecx, dword ptr [g_fightGroupHead]
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
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x20d
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_dispatchSave737
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ArgSarStoreJmp
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
        mov      eax, dword ptr [g_baseSel]
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
        mov      dword ptr [g_eventQueueChild], 0x13
        call     StageGateFsmCluster
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_b297
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret
    L_b0db:
        /* case 2: bit 0x12, call 0047b2c0, install state 3 */
        mov      dword ptr [g_eventQueueChild], 0x12
        call     StageGateFsmCluster
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_b297
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret
    L_b119:
        /* case 3: wait counter = 6, fall into L_b19a (install state 4) */
        mov      dword ptr [g_eventQueueNotMask], 6
        jmp      short L_b19a
    L_b125:
        /* case 4: install state 5 via EsiInstallChainCmpDualCall */
        mov      dword ptr [g_eventQueueChild], 0x13
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_b070
        add      edx, 0x5000000
        mov      dword ptr [ecx*4 + 0x84], 5
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     EsiInstallChainCmpDualCall
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b18d:
        /* case 5: dec wait counter; if 0 jump to L_b1f8 (state 6), else fall to L_b19a */
        mov      eax, dword ptr [g_eventQueueNotMask]
        dec      eax
        mov      dword ptr [g_eventQueueNotMask], eax
        je       short L_b1f8
    L_b19a:
        /* install state 4 via ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain */
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_b070
        mov      dword ptr [ecx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x4000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b1f8:
        /* install state 6 via ScaledLoadJmp_00429390 */
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_b070
        mov      dword ptr [ecx*4 + 0x84], 6
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x6000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     ScaledLoadJmp_00429390
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b256:
        /* case 0: clear wait, bit 0x12, call 0047b2c0, install state 1 */
        mov      dword ptr [g_eventQueueNotMask], edi
        mov      dword ptr [g_eventQueueChild], 0x12
        call     StageGateFsmCluster
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_b297
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_b070
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret
    L_b292:
        call     FiveCallGuardSetTail
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
