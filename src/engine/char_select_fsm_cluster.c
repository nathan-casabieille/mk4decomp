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
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
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
extern void PendingMatch_StoreTwoCall_0042b930(void);
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
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
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
/* Throw-init link cluster (815b game, 3 packed helpers):             */
/*  h1 (0x4555f0): main link/init chain - 4089e0+4b8fa0+407140 mstack */
/*    + 406600+408c10 + copy 3 angles + 4ab700 + d5324 timer.         */
/*  h2 (0x455730): pose-fn 2-state - state 0 init via 407330+4058c0+  */
/*    406340 + push 0x456510 helper-call + 48b740 + status 0x91/bit-flags */
/*    + event 004e7f28; state 1 install state 1 w/ 0x41 wait.         */
/*  h3 (0x4558f0): set wait=0x16 → tail-jmp RoundCleanupCluster_ArgSarStoreJmp.*/
/* ------------------------------------------------------------------ */
extern void MStackPushTwoEntryChainCall(void);
extern void MStackCall_00406600(void);
extern void PushSetXfmMaskCallPop(void);
extern void MStackPushDispatchBitGate(void);
extern void RoundCleanupCluster_ArgSarStoreJmp(void);
extern void CharSelectFsmCluster(void);
extern void ChainGatedNegAccum(void);
extern unsigned int g_dispatchSave951;
extern unsigned int g_dispatchSave954;
extern unsigned int g_dispatchSave129;

extern unsigned int g_pendingMatchVar;
extern unsigned int g_particleEmitterNode;
extern void ArgSarStoreJmp(void);
extern void AudioMixerStep(void);
extern void DualScaledStore(void);
extern void MStackCall_00406340(void);
extern void StoreLoadJmp(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void ThrowInitLinkCluster(void)
{
    __asm {
        /* === h1 (0x4555f0): main link/init chain === */
        call     MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5721
        call     MStackBracket7_DispatchAndChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5721
        mov      eax, OFFSET g_dispatchSave954
        mov      ecx, dword ptr [g_fightGroupHead]
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5721
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      al, byte ptr [g_xformDirtyFlags]
        test     al, 4
        mov      dword ptr [g_fightGroupHead], edx
        jne      L_5721
        call     MStackCall_00406600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5721
        mov      dword ptr [g_walkCallback], 0xa
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_5721
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x3c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x40]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x44]
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_pendingMatchVar]
        mov      dword ptr [g_walkCallback], edx
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_5721
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x68], eax
    L_5721:
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
        /* === h2 (0x455730): pose-fn 2-state w/ throw setup === */
    L_5730:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_58d0
        mov      ecx, OFFSET g_dispatchSave129
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     MStackPushDispatchBitGate
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_58ff
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_5786
        call     Thunk_ScaledNeg1SetPause
        pop      esi
        ret
    L_5786:
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_fightGroupHead], edx
        call     MStackPushTwoEntryChainCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_58ff
        call     MStackCall_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_58ff
        push     OFFSET CharSelectFsmCluster + 0x320
        call     StoreLoadJmp
        mov      eax, dword ptr [g_eventQueueIdx]
        add      esp, 4
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_acc_00542078], 0x16666
        mov      dword ptr [g_eventQueueNotMask], 0
        call     ChainGatedNegAccum
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_58ff
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_acc_00542078]
        push     OFFSET g_dispatchSave951
        mov      dword ptr [ecx*4 + 0x54], edx
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, 0x91
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x30], eax
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [eax*4 + 0x48]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [edx*4 + 0x64]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x64], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      ecx, dword ptr [edx*4 + 0x34]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueCurrent], ecx
        and      ecx, 1
        mov      eax, dword ptr [edx*4 + 0x34]
        mov      dword ptr [g_eventQueueCurrent], ecx
        and      al, 0xfe
        or       eax, ecx
        or       eax, 0x81000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x34], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_particleEmitterNode]
        mov      dword ptr [eax*4 + 0x3c], ecx
        call     ArgSarStoreJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_58d0:
        call     DualScaledStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_58ff
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_5730
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x41
        mov      dword ptr [g_framePauseFlag], eax
    L_58ff:
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
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h3 (0x4558f0): set wait=0x16 → tail-jmp 00455920 === */
        mov      dword ptr [g_eventQueueIdx], 0x16
        jmp      RoundCleanupCluster_ArgSarStoreJmp
    }
}
