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
extern void CopyJmp_0048ef90(void);
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
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
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
extern void GuardedDispatch_0042b6c0(void);
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
extern void DispatcherComplex260_00407400(void);
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
/* Special-move chain cluster (812b game, 4 packed helpers):          */
/*  h1 (0x43f9c0): 7-stage 76670 + 73070 chain w/ status sequence     */
/*    (0x76, 0x7b, 0x77, 0xc1×2, 0xc0, 0x93, 0x74, 0x75) + event 4e51c8.*/
/*  h2 (0x43fb90): mstack pop helper.                                 */
/*  h3 (0x43fbb0): pose-fn install state 1 w/ 0043fcf0 (476de0 chain).*/
/*  h4 (0x43fc50): pose-fn install state 1 w/ 0043fcf0 (476f10 chain).*/
/* ------------------------------------------------------------------ */
extern void TwoCallScaledOr1600(void);
extern void EntitySetupCountdownFsm(void);
extern void ComboLoopCluster(void);
extern void PushPopCurrentSetFFFFFFFF(void);
extern void MStackPush2BitLoop(void);
extern void GuardedSeq_00476de0(void);
extern void GuardedSeq_00476f10(void);
extern void GuardedSeq_00476fc0(void);
extern unsigned int g_dispatchSave603_004e51c8;

extern void ArgSarStoreJmp(void);

__declspec(naked) void SpecialMoveChainCluster(void)
{
    __asm {
        /* === h1 (0x43f9c0): 7-stage status sequence + event 4e51c8 === */
        mov      dword ptr [g_walkCallback], 0x76
        call     MStackPush2BitLoop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      dword ptr [g_walkCallback], 0x7b
        call     MStackPush2BitLoop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      dword ptr [g_walkCallback], 0x77
        call     MStackPush2BitLoop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      dword ptr [g_walkCallback], 0xc1
        call     MStackPush2BitLoop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      dword ptr [g_walkCallback], 0xc1
        call     PushPopCurrentSetFFFFFFFF
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      dword ptr [g_walkCallback], 0xc0
        call     PushPopCurrentSetFFFFFFFF
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        call     TwoCallScaledOr1600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_fb81
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_fightGroupHead]
        shl      ecx, 2
        lea      eax, [edx*4]
        mov      edx, dword ptr [ecx + 0x3c]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x54], edx
        mov      edx, dword ptr [ecx + 0x40]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x58], edx
        mov      edx, dword ptr [ecx + 0x44]
        mov      dword ptr [eax + 0x5c], edx
        mov      dword ptr [g_walkCallback], 0x93
        call     PushPopCurrentSetFFFFFFFF
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fb81
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x64]
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      edx, dword ptr [eax + 0x30]
        shl      ecx, 2
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [ecx + 0x54], edx
        mov      edx, dword ptr [eax + 0x34]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [ecx + 0x58], edx
        mov      edx, dword ptr [eax + 0x38]
        mov      dword ptr [ecx + 0x5c], edx
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_fightGroupHead], eax
        mov      dword ptr [g_walkCallback], 3
        call     GuardedSeq_00476fc0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fb81
        mov      dword ptr [g_walkCallback], 0x74
        call     MStackPush2BitLoop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fb81
        mov      dword ptr [g_walkCallback], 0x75
        call     MStackPush2BitLoop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fb81
        call     ScaledZeroFour
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fb81
        push     OFFSET g_dispatchSave603_004e51c8
        call     ArgSarStoreJmp
        add      esp, 4
    L_fb81:
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
        /* === h2 (0x43fb90): mstack pop helper === */
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_matrixStackTop], eax
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h3 (0x43fbb0): pose-fn install state 1 w/ 476de0 === */
    L_fbb0:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_fbe9
        mov      dword ptr [g_walkCallback], 3
        call     GuardedSeq_00476de0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fc4b
        jmp      ComboLoopCluster
    L_fbe9:
        mov      dword ptr [eax + 8], OFFSET L_fbb0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_fbb0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     EntitySetupCountdownFsm
        mov      dword ptr [g_framePauseFlag], 1
    L_fc4b:
        ret
        nop
        nop
        nop
        nop
        /* === h4 (0x43fc50): pose-fn install state 1 w/ 476f10 === */
    L_fc50:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_fc89
        mov      dword ptr [g_walkCallback], 3
        call     GuardedSeq_00476f10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_fceb
        jmp      ComboLoopCluster
    L_fc89:
        mov      dword ptr [eax + 8], OFFSET L_fc50
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_fc50
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     EntitySetupCountdownFsm
        mov      dword ptr [g_framePauseFlag], 1
    L_fceb:
        ret
    }
}
