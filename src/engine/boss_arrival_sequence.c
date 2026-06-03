/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
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

extern void CjDispatchCommit(void);
extern void BossArrivalSequence(void);
extern void SwapTwoGlobals(void);
extern void TableHitOrSchedule(void);
extern unsigned int g_dispatchSave540;
extern unsigned int g_dispatchSave539;
extern unsigned int g_bossArrivalState;
extern unsigned int g_const_00481a10;
extern unsigned int g_const_00481a80;

extern unsigned int g_load_0052ab10;
extern void ArgSarStoreJmp(void);
extern void ScaledInitWithCounterAndType_004314f0(void);

__declspec(naked) void BlockedCounterCluster(void)
{
    __asm {
    L_16d0:
        /* H1: counter update */
        mov      eax, dword ptr [g_fightGroupHead]
        and      dword ptr [eax*4 + 0x34], 0xfffffffe
        call     SwapTwoGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1707
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_fightGroupHead]
        sub      eax, 0x191eb
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x64], eax
    L_1707:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* H2: trigger ground impact */
        call     L_16d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1749
        push     0x26
        push     OFFSET g_const_00481a10
        call     StoreTwoCall
        add      esp, 8
        push     0x26
        push     OFFSET g_const_00481a80
        call     StoreTwoCall
        add      esp, 8
        push     OFFSET g_dispatchSave539
        call     ArgSarStoreJmp
        add      esp, 4
    L_1749:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* H3 (L_1750): per-entity FSM init */
    L_1750:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_1791
        call     CjDispatchCommit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1813
        push     OFFSET g_dispatchSave540
        call     ArgSarStoreJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret
    L_1791:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [ecx*4 + 0x6c]
        mov      dword ptr [g_currentNodeFlags], edx
        mov      ecx, dword ptr [ecx*4 + 0x74]
        mov      dword ptr [g_xformScratch2088], ecx
        mov      dword ptr [eax + 8], OFFSET L_1750
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      edx, OFFSET L_1750
        mov      dword ptr [g_currentNodeIdx], ecx
        add      edx, 0x1000000
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     BossArrivalSequence
        mov      dword ptr [g_framePauseFlag], 1
    L_1813:
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
        /* H4 (L_1820): per-entity tick */
    L_1820:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_1874
        push     0x1392
        call     TableHitOrSchedule
        mov      eax, dword ptr [g_load_0052ab10]
        mov      ecx, 0xfffffd71
        add      esp, 4
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax*4 + 0x70], ecx
        call     ScaledInitWithCounterAndType_004314f0
        pop      edi
        pop      esi
        ret
    L_1874:
        mov      edi, 1
        mov      dword ptr [g_eventQueueWorkType], 0x3d
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [g_bossArrivalState], edi
        call     Push16Call
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_18d8
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x58]
        sub      eax, 0x147a
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      dword ptr [esi + 8], OFFSET L_1820
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], edi
    L_18d8:
        pop      edi
        pop      esi
        ret
    }
}
