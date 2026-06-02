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

extern unsigned int g_dispatchSave741;
extern unsigned int g_dispatchSave742;
extern unsigned int g_dispatchSave743;
extern unsigned int g_dispatchSave69;
extern void Alarm3EntryPhaseChain(void);
extern void ArgSarStoreJmp(void);
extern void Cascade3ChainInit(void);
extern void CmpEqInitCallElseJmp(void);
extern void EsiInstallDecCallChain_004294a0(void);
extern void FiveCallGuardSetTail(void);
extern void GuardedPackedSlotInit(void);
extern void GuardedRangeCmpFpuJmp(void);
extern void ScaledLoadJmp_00428d20(void);
extern void ScaledZero44(void);
extern void SetJmp_MStackPush4IndirectCall(void);
extern void StoreLitRetSet2(void);
extern void StreamInitCountdownBody(void);
extern void TableLookupCall_g_table_004efa00(void);
extern void TableLookupCall_g_table_004efd18(void);

__declspec(naked) void AggressorModeCluster(void)
{
    __asm {
        /* === Helper 1 (0x47df30): tiny event 004ed518 forwarder === */
        push     OFFSET g_dispatchSave741
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        nop
        nop
        /* === Helper 2 (0x47df40): main dispatcher === */
    L_df40:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       L_e004
        mov      dword ptr [g_walkCallback], 3
        call     CmpEqInitCallElseJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e0fd
        mov      eax, dword ptr [g_xformScratch2088]
        test     eax, eax
        jne      short L_df92
        call     Alarm3EntryPhaseChain
        pop      esi
        ret
    L_df92:
        cmp      eax, 1
        jne      short L_df9e
        call     Alarm3EntryPhaseChain
        pop      esi
        ret
    L_df9e:
        mov      dword ptr [g_eventQueueWorkType], 0x20000
        call     GuardedRangeCmpFpuJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e0fd
        call     SetJmp_MStackPush4IndirectCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e0fd
        call     Cascade3ChainInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e0fd
        call     StoreLitRetSet2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e0fd
        push     OFFSET g_dispatchSave743
        call     ArgSarStoreJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_e004:
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x203
        push     OFFSET g_dispatchSave742
        mov      dword ptr [ecx*4 + 0x68], 0x403
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x74], eax
        call     StreamInitCountdownBody
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      L_e0fd
        mov      dword ptr [g_walkCallback], 9
        call     TableLookupCall_g_table_004efa00
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e0fd
        push     OFFSET g_dispatchSave69
        call     GuardedPackedSlotInit
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_e0fd
        mov      dword ptr [g_walkCallback], 0xf
        call     TableLookupCall_g_table_004efd18
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_e0fd
        mov      dword ptr [g_eventQueueChild], 0xb
        mov      dword ptr [esi + 8], OFFSET L_df40
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_df40
        add      ecx, 0x1000000
        mov      dword ptr [eax*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 0
        call     EsiInstallDecCallChain_004294a0
        mov      dword ptr [g_framePauseFlag], 1
    L_e0fd:
        pop      esi
        ret
        nop
        /* === Helper 3 (0x47e100): post-pause continuation === */
    L_e100:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_e12f
        call     ScaledZero44
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_e191
        jmp      FiveCallGuardSetTail
    L_e12f:
        mov      dword ptr [eax + 8], OFFSET L_e100
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_e100
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
        call     ScaledLoadJmp_00428d20
        mov      dword ptr [g_framePauseFlag], 1
    L_e191:
        ret
    }
}
