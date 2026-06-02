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

extern unsigned int g_dispatchSave780;
extern unsigned int g_dispatchSave781;
extern unsigned int g_dispatchSave782;
extern unsigned int g_dispatchTab69;
extern void ArgSarStoreJmp(void);
extern void DualGatedStateYield(void);
extern void EsiEdiAliasDualMul10(void);
extern void FiveCallGuardSetTail(void);
extern void GuardedPackedSlotInit(void);
extern void IterStepNegStore(void);
extern void NotMaskStorePair(void);
extern void PunchAnimCluster(void);
extern void PushPopWalkSet1006(void);
extern void ScaledChain3c7c(void);
extern void ScaledClearJmp_00428d40(void);
extern void ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d490(void);
extern void ScaledLoadJmp_00428d20(void);
extern void ScaledLoadJmp_24(void);
extern void ScaledLookupGuardJmpIndirect(void);
extern void TableLookupCall_g_table_004efa00(void);
extern void TournamentMenuFsmCluster(void);

__declspec(naked) void ComboFinisherEventCluster(void)
{
    __asm {
        /* === h1 (0x495dc0): event 004f1610 forwarder === */
        push     OFFSET g_dispatchSave780
        call     ScaledLookupGuardJmpIndirect
        add      esp, 4
        ret
        nop
        nop
        /* === h2 (0x495dd0): event 004f1628 forwarder === */
        mov      eax, dword ptr [g_baseSel]
        push     OFFSET g_dispatchSave781
        mov      dword ptr [eax*4 + 0x74], 0x404
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x314
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x68], eax
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
        /* === h3 (0x495e10): pose-fn 3-state combo handler === */
    L_5e10:
        mov      eax, dword ptr [g_baseSel]
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
        mov      dword ptr [g_walkCallback], 0x14
        call     ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d490
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        mov      eax, dword ptr [g_xformScratch2088]
        cmp      eax, ebx
        je       L_5fe8
        jl       short L_5e90
        call     ScaledChain3c7c
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        cmp      dword ptr [g_walkCallback], 3
        jge      L_5fe8
    L_5e90:
        mov      dword ptr [g_walkCallback], 0xe666
        call     EsiEdiAliasDualMul10
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        mov      dword ptr [g_xformScratch2088], 0x10000
        call     PunchAnimCluster
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        call     NotMaskStorePair
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_player1NodeIdx]
        mov      eax, 0x10
        cmp      ecx, edx
        mov      dword ptr [g_eventQueueWorkType], eax
        je       short L_5efb
        mov      eax, 0x1000
        mov      dword ptr [g_eventQueueWorkType], eax
    L_5efb:
        and      eax, dword ptr [g_walkCallback]
        mov      dword ptr [g_xformScratch94], eax
        jne      L_6067
        call     PushPopWalkSet1006
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        call     FiveCallGuardSetTail
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_5f26:
        mov      dword ptr [g_walkCallback], 0x1f
        call     TableLookupCall_g_table_004efa00
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        push     OFFSET g_dispatchTab69
        call     GuardedPackedSlotInit
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        cmp      eax, edi
        jne      L_60d0
        mov      dword ptr [g_eventQueueChild], 6
        mov      dword ptr [esi + 8], OFFSET L_5e10
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_5e10
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     ScaledClearJmp_00428d40
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_5fc5:
        mov      dword ptr [g_walkCallback], 0x14
        call     ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d490
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_60d0
        cmp      dword ptr [g_xformScratch2088], ebx
        jne      short L_6067
    L_5fe8:
        push     OFFSET g_dispatchSave782
        call     IterStepNegStore
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        cmp      eax, edi
        jne      L_60d0
        mov      dword ptr [g_eventQueueChild], 8
        mov      dword ptr [esi + 8], OFFSET L_5e10
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_5e10
        add      ecx, 0x3000000
        mov      dword ptr [eax*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     TournamentMenuFsmCluster
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_6067:
        call     DualGatedStateYield
        test     eax, eax
        jne      short L_60d0
        call     ScaledLoadJmp_24
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_60d0
        mov      dword ptr [esi + 8], OFFSET L_5e10
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_5e10
        mov      dword ptr [eax*4 + 0x84], ebx
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
        call     ScaledLoadJmp_00428d20
        mov      dword ptr [g_framePauseFlag], ebx
    L_60d0:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
