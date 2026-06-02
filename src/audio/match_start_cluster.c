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

extern unsigned int g_dataArr_00535cfc;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern unsigned int g_player1State;
extern unsigned int g_counter_0053a51c;
extern unsigned int g_player2State;
extern u32 g_dlMode;
extern unsigned int g_audioTriEntryFlag;
extern unsigned int g_matchStartClr;
extern unsigned int g_audioMatchStartFlag;
extern u8 g_dlEnabledFlag;
extern void AudioInstallSelfStatePush(void);
extern void ClearTwoCallSetStore(void);
extern void DownloadPlayerChar(void);
extern void DualScaledStoreConst(void);
extern void IncOrZero9(void);
extern void InstallSelfTableWalk(void);
extern void ScaledClearTripleCallJmp(void);
extern void SixCallSeqPushImm(void);
extern void TablePushAccumTailJmp(void);
extern void TableWalkBoundedCmp(void);
extern void TestCmpZeroFour(void);

__declspec(naked) void MatchStartCluster(void)
{
    __asm {
        /* === Helper 1 (0x4a23c0): match init === */
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      eax, OFFSET g_active_0053a408
        mov      ecx, OFFSET g_player1State
        and      edx, 0xfffffffe
        shr      eax, 2
        shr      ecx, 2
        mov      dword ptr [g_xformDirtyFlags], edx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DualScaledStoreConst
        mov      edx, OFFSET g_active_00537e88
        mov      eax, OFFSET g_player2State
        shr      edx, 2
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_xformEntityIdx], eax
        call     DualScaledStoreConst
        call     ClearTwoCallSetStore
        mov      dword ptr [g_dlMode], 0
        call     SixCallSeqPushImm
        mov      dword ptr [g_eventQueueWorkType], 0
        call     Push16Call
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2440
        jmp      InstallSelfTableWalk
    L_2440:
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
        /* === Helper 2 (0x4a2450): round-start FSM step === */
    L_2450:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        je       L_2527
        mov      dword ptr [g_eventQueueWorkType], edi
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_260c
        mov      ecx, dword ptr [g_counter_0053a51c]
        mov      dword ptr [g_walkCallback], ecx
        call     TablePushAccumTailJmp
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_260c
        call     TestCmpZeroFour
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_260c
        mov      eax, dword ptr [g_dlNalt1]
        mov      edx, OFFSET g_dataArr_00535cfc
        shr      edx, 2
        mov      ebx, 1
        mov      dword ptr [g_eventQueueEnd], edx
        mov      byte ptr [g_dlEnabledFlag], bl
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], edi
        call     DownloadPlayerChar
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_260c
        mov      ecx, dword ptr [g_dlNalt2]
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_walkCallback], ecx
        call     DownloadPlayerChar
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_260c
        mov      byte ptr [g_dlEnabledFlag], 0
        call     ScaledClearTripleCallJmp
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_2527:
        mov      ebx, dword ptr [g_xformDirtyFlags]
        push     6
        and      ebx, 0xfffffffe
        mov      dword ptr [g_xformDirtyFlags], ebx
        call     TableWalkBoundedCmp
        mov      edx, OFFSET g_active_0053a408
        mov      eax, OFFSET g_player1State
        mov      ebx, 1
        add      esp, 4
        shr      edx, 2
        shr      eax, 2
        mov      dword ptr [g_audioMatchStartFlag], ebx
        mov      dword ptr [g_audioTriEntryFlag], ebx
        mov      dword ptr [g_matchStartClr], ebx
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_xformEntityIdx], eax
        call     DualScaledStoreConst
        mov      ecx, OFFSET g_active_00537e88
        mov      edx, OFFSET g_player2State
        shr      ecx, 2
        shr      edx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_xformEntityIdx], edx
        call     DualScaledStoreConst
        call     ClearTwoCallSetStore
        mov      dword ptr [g_dlMode], edi
        mov      dword ptr [g_dlNalt1], edi
        mov      dword ptr [g_dlNalt2], edi
        call     IncOrZero9
        call     SixCallSeqPushImm
        mov      dword ptr [esi + 8], OFFSET L_2450
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_2450
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
        call     AudioInstallSelfStatePush
        mov      dword ptr [g_framePauseFlag], ebx
    L_260c:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
