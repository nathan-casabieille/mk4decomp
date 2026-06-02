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
/* Hit-reaction state cluster (682b game, 2 packed helpers)            */
/* Helper 1: hit-launch dispatcher → 433640 callback.                  */
/* Helper 2: hit-reaction FSM w/ 4-bucket hit-amount picker.           */
/* ------------------------------------------------------------------ */
extern void GuardedPushCall_004338a0(void);
extern void GuardedPushCall_004338c0(void);
extern void Cmp3JmpOrPushCall(void);
extern void ScaledLoadInstallOrCall_00433990(void);
extern void GameDispatchValidateState(void);
extern void ThreeStageGateCascade(void);
extern void CmpJmpConstStoreJmp(void);
extern void PackedAdvanceCallTailJmp(void);
extern void MultiBranchStateFilter(void);
extern void GDispatch1_00439c40(void);
extern void TieredCmpDispatch(void);
extern void InstallSelfCountdownCascade(void);
extern void RoundReadyFsmCluster(void);
extern void QuadBlockArgInstallChain(void);
extern void LeaPlus22StoreSelf(void);
extern void DualGatedStateYield(void);
extern void CallPauseInc(void);
extern void AudioVolumeRescale(void);
extern unsigned int g_dispatchSave680_004e4460;
extern unsigned int g_dispatchSave681_004e49fc;
extern unsigned int g_dispatchState;

extern void ScaledMove48to58(void);

__declspec(naked) void HitReactionStateCluster(void)
{
    __asm {
        /* === Helper 1 (0x4335f0): hit-launch dispatcher === */
        call     LeaPlus22StoreSelf
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3630
        call     ScaledMove48to58
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_3630
        call     DualGatedStateYield
        test     eax, eax
        jne      short L_3630
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET L_3640
        jmp      GameDispatchValidateState
    L_3630:
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
        /* === Helper 2 (0x433640): hit-reaction FSM === */
    L_3640:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_377d
        dec      eax
        jne      short L_3695
        cmp      dword ptr [g_stateCountdown], 2
        jg       short L_3695
        mov      dword ptr [g_walkCallback], 0x1f4
        call     AudioVolumeRescale
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3897
        test     byte ptr [g_xformDirtyFlags], 1
        jne      short L_36f2
    L_3695:
        mov      eax, dword ptr [g_table_00535ddc]
        cmp      eax, 0x10000
        mov      dword ptr [g_walkCallback], eax
        jge      short L_36ae
        call     Cmp3JmpOrPushCall
        pop      edi
        pop      esi
        ret
    L_36ae:
        cmp      eax, 0x20000
        jge      short L_36bd
        call     GuardedPushCall_004338c0
        pop      edi
        pop      esi
        ret
    L_36bd:
        cmp      eax, 0x30000
        jge      short L_36cc
        call     GuardedPushCall_004338a0
        pop      edi
        pop      esi
        ret
    L_36cc:
        call     ScaledLoadInstallOrCall_00433990
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3897
        push     OFFSET g_dispatchSave680_004e4460
        call     PackedAdvanceCallTailJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      edi
        pop      esi
        ret
    L_36f2:
        mov      dword ptr [g_walkCallback], 0xb4
        call     CallPauseInc
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3897
        mov      eax, dword ptr [g_walkCallback]
        mov      edx, OFFSET L_3640
        add      eax, 0x3c
        add      edx, 0x2000000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueChild], eax
        mov      dword ptr [esi + 8], OFFSET L_3640
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     CmpJmpConstStoreJmp
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_377d:
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], edi
        push     OFFSET g_dispatchSave681_004e49fc
        mov      dword ptr [ecx*4 + 0x74], edi
        call     QuadBlockArgInstallChain
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        cmp      eax, edi
        jne      L_3897
        mov      dword ptr [g_dispatchState], edi
        call     InstallSelfCountdownCascade
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3897
        cmp      dword ptr [g_dispatchState], edi
        jne      L_3897
        mov      dword ptr [g_dispatchState], edi
        call     MultiBranchStateFilter
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3897
        cmp      dword ptr [g_dispatchState], edi
        jne      L_3897
        mov      dword ptr [g_dispatchState], edi
        call     RoundReadyFsmCluster
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_3897
        cmp      dword ptr [g_dispatchState], edi
        jne      short L_3897
        call     GDispatch1_00439c40
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_3897
        mov      dword ptr [g_dispatchState], edi
        call     TieredCmpDispatch
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_3897
        cmp      dword ptr [g_dispatchState], edi
        jne      short L_3897
        mov      dword ptr [esi + 8], OFFSET L_3640
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_3640
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     ThreeStageGateCascade
        mov      dword ptr [g_framePauseFlag], 1
    L_3897:
        pop      edi
        pop      esi
        ret
    }
}
