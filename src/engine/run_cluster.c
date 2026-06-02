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

extern unsigned int g_phaseTimer;
extern void CallDualStoreXorBit(void);
extern void DualHelperCallStoreCjFields(void);
extern void DualMul10AccCj(void);
extern void EsiEdiAliasDualMul10(void);
extern void FiveCallGuardSetTail(void);
extern void GuardedSeq_0047d980(void);
extern void MoveSelectorCluster(void);
extern void ScaledLitLoadCall_00480fe0(void);
extern void ScaledZero44(void);
extern void TableLookupCall_00489ff0(void);
extern void TwoPhaseInstallScaledPackedPtr(void);

__declspec(naked) void RunCluster(void)
{
    __asm {
        /* === Helper 1 (0x47d6e0): ramp+blend driver === */
    L_d6e0:
        mov      dword ptr [g_walkCallback], 0x4000
        call     EsiEdiAliasDualMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d73b
        call     ScaledZero44
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d73b
        call     CopyJmp_0048ef90
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d73b
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [g_walkCallback], 0x28f
        test     al, 1
        mov      dword ptr [g_eventQueueCurrent], 0
        je       short L_d736
        jmp      TwoPhaseInstallScaledPackedPtr
    L_d736:
        jmp      FiveCallGuardSetTail
    L_d73b:
        ret
        nop
        nop
        nop
        nop
        /* === Helper 2 (0x47d740): ev0x14 trigger === */
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_phaseTimer], eax
        call     CallDualStoreXorBit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d77d
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_d77d
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0x14
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x28], eax
    L_d77d:
        ret
        nop
        nop
        /* === Helper 3 (0x47d780): distance-test caller === */
        mov      eax, dword ptr [g_fightGroupHead]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_walkCallback], eax
        mov      ecx, dword ptr [esi + 0x5c]
        push     eax
        push     eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        mov      eax, dword ptr [g_eventQueueCurrent]
        push     eax
        push     eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_walkCallback]
        add      esp, 8
        add      ecx, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        cmp      ecx, 0x640000
        mov      dword ptr [g_walkCallback], ecx
        jl       short L_d841
        mov      ecx, dword ptr [esi + 0x6c]
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      edx, dword ptr [esi + 0x74]
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      eax, dword ptr [esi + 0x54]
        mov      dword ptr [g_acc_00542078], eax
        mov      esi, dword ptr [esi + 0x5c]
        add      eax, ecx
        add      esi, edx
        push     eax
        push     eax
        mov      dword ptr [g_acc_00542078], eax
        mov      dword ptr [g_eventQueueNotMask], esi
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_acc_00542078], eax
        mov      eax, dword ptr [g_eventQueueNotMask]
        push     eax
        push     eax
        call     Mul10Tail
        mov      edx, dword ptr [g_acc_00542078]
        mov      ecx, dword ptr [g_walkCallback]
        add      eax, edx
        add      esp, 8
        cmp      eax, ecx
        mov      dword ptr [g_eventQueueNotMask], eax
        jl       short L_d841
        call     L_d6e0
    L_d841:
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
        /* === Helper 4 (0x47d850): stride-FSM === */
    L_d850:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        mov      edi, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_d88b
        mov      eax, dword ptr [g_eventQueueChild]
        dec      eax
        mov      dword ptr [g_eventQueueChild], eax
        je       L_d91c
        jmp      short L_d8c1
    L_d88b:
        cmp      dword ptr [g_xformScratch2088], edi
        jne      short L_d89b
        call     MoveSelectorCluster
        pop      edi
        pop      esi
        ret
    L_d89b:
        mov      dword ptr [g_walkCallback], 0xd
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d97c
        mov      dword ptr [g_eventQueueChild], 0x32
    L_d8c1:
        mov      dword ptr [g_walkCallback], 0x18000
        mov      dword ptr [g_eventQueueCurrent], 0xffffe667
        call     DualHelperCallStoreCjFields
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d97c
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [ecx*4 + 0x38]
        mov      dword ptr [g_currentNodeIdx], edx
        call     DualMul10AccCj
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d97c
        mov      eax, dword ptr [g_rangeSqLimit]
        mov      ecx, dword ptr [g_walkCallback]
        cmp      ecx, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        jle      short L_d954
    L_d91c:
        mov      dword ptr [g_walkCallback], 0x53
        call     ScaledLitLoadCall_00480fe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d97c
        mov      dword ptr [g_walkCallback], 0xc
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d97c
        call     GuardedSeq_0047d980
        pop      edi
        pop      esi
        ret
    L_d954:
        mov      eax, 3
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_phaseTimer], eax
        mov      dword ptr [esi + 8], OFFSET L_d850
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_pendingNodeType], edi
        mov      dword ptr [g_framePauseFlag], edi
    L_d97c:
        pop      edi
        pop      esi
        ret
    }
}
