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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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
/* MoveSelector cluster (544b game, 4 packed helpers)                  */
/* ------------------------------------------------------------------ */
extern void FiveCallGuardSetTail(void);
extern void SlotEvent3EntryChain(void);
extern void DualSetCallPair(void);
extern void ThrowTakedownCluster(void);
extern void InstallSelfCmpJmpIndirect(void);
extern void InstallSelfIndirectJmpNeg(void);
extern void Wrapper_0048ff30(void);
extern void ZeroThreeSlots_00490780(void);
extern void TripleScaledChainStore(int);
extern void DualCallPauseDirtyJmp_00490c30(void);
extern void ZeroSixStores6080(void);
extern void ScaledZero44(void);
extern unsigned int g_dispatchSave739_004ed490;
extern unsigned int g_dispatchSave740_004ed4a0;
extern unsigned int g_phaseTimer;

extern void ArgSarStoreJmp(void);

__declspec(naked) void MoveSelectorCluster(void)
{
    __asm {
        /* === Main: move-selector dispatch === */
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x1010
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ScaledZero44
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_dac7
        mov      dword ptr [g_phaseTimer], 5
        mov      dword ptr [g_walkCallback], 0x8000
        mov      dword ptr [g_eventQueueCurrent], 0
        call     Wrapper_0048ff30
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_dac7
        push     OFFSET g_dispatchSave739_004ed490
        call     TripleScaledChainStore
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_dac7
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [edx*4 + 0x34]
        cmp      eax, 0x10
        mov      dword ptr [g_walkCallback], eax
        jne      short L_da34
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_da34:
        cmp      eax, 0x11
        jne      short L_da43
        mov      eax, 7
        mov      dword ptr [g_walkCallback], eax
    L_da43:
        cmp      eax, 7
        jne      short L_da5b
        call     ThrowTakedownCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_dac7
        mov      eax, dword ptr [g_walkCallback]
    L_da5b:
        cmp      eax, 0xe
        jne      short L_da73
        call     ThrowTakedownCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_dac7
        mov      eax, dword ptr [g_walkCallback]
    L_da73:
        cmp      eax, 0xc
        jne      short L_da8b
        call     ThrowTakedownCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_dac7
        mov      eax, dword ptr [g_walkCallback]
    L_da8b:
        cmp      eax, 9
        jne      short L_da9e
        call     ThrowTakedownCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_dac7
    L_da9e:
        call     DualSetCallPair
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_dac7
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET L_dad0
        jmp      InstallSelfIndirectJmpNeg
    L_dac7:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2 (0x47dad0) === */
    L_dad0:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      dword ptr [g_currentNodeFlags], 0xfffd8000
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET L_db00
        jmp      InstallSelfCmpJmpIndirect
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
        /* === Helper 3 (0x47db00) === */
    L_db00:
        call     ZeroThreeSlots_00490780
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_db37
        call     ZeroSixStores6080
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_db37
        call     DualCallPauseDirtyJmp_00490c30
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_db37
        push     OFFSET g_dispatchSave740_004ed4a0
        call     ArgSarStoreJmp
        add      esp, 4
    L_db37:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 4 (0x47db40) === */
    L_db40:
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       short L_db5f
        jmp      FiveCallGuardSetTail
    L_db5f:
        mov      dword ptr [eax + 8], OFFSET L_db40
        mov      ecx, dword ptr [g_baseSel]
        push     edi
        mov      edi, OFFSET L_db40
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     SlotEvent3EntryChain
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
    }
}
