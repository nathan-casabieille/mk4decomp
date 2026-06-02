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

extern void StackPopDispatchTagged(void);
extern void ArgSarStoreJmp(void);
extern void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void);
extern void RoundFinishEventGroup(void);
extern void CmpP1DualInitStore_00482ab0(void);
extern void ScaledCmpJlJmp(void);
extern void TableLookupCall_g_table_004efa00(void);
extern void TableLookupCall_g_table_004efae0(void);
extern void Wrapper_IterLoad_0048fd30_004f12a8(void);
extern void Wrapper_IterLoad_0048fd30_004f12ac(void);
extern unsigned int g_dispatchSave595;
extern unsigned int g_dispatchSave594;
extern unsigned int g_dispatchSave593;
extern unsigned int g_dispatchSave592;
extern unsigned int g_secondary_00535d04;
extern unsigned int g_primary_0053a774;

extern void GateDispatch6c(void);

__declspec(naked) void GameModeAdvanceCluster(void)
{
    __asm {
        /* H1: */
        push     OFFSET g_dispatchSave595
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        nop
        nop
        /* H2: */
        jmp      StackPopDispatchTagged
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
        /* H3: */
        mov      dword ptr [g_walkCallback], 0x9999
        call     CmpP1DualInitStore_00482ab0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_20c6
        mov      eax, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 0x7c]
        cmp      eax, 2
        mov      dword ptr [g_walkCallback], eax
        jle      short L_20ab
        mov      eax, dword ptr [g_player1NodeIdx]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_primary_0053a774]
        cmp      edx, eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_currentNodeIdx], eax
        je       short L_207e
        mov      ecx, dword ptr [g_secondary_00535d04]
        mov      dword ptr [g_walkCallback], ecx
    L_207e:
        mov      edx, dword ptr [g_rangeSqLimit]
        lea      eax, [edx - 0xa0000]
        cmp      ecx, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        jl       short L_20ab
        mov      dword ptr [g_walkCallback], 0xe
        call     ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_20c6
    L_20ab:
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_20c6
        push     OFFSET g_dispatchSave594
        call     ArgSarStoreJmp
        add      esp, 4
    L_20c6:
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
        /* H4: */
        mov      dword ptr [g_walkCallback], 0x9999
        call     CmpP1DualInitStore_00482ab0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2129
        mov      dword ptr [g_walkCallback], 2
        call     ScaledCmpJlJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2129
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2129
        call     Wrapper_IterLoad_0048fd30_004f12a8
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_2129
        push     OFFSET g_dispatchSave593
        call     ArgSarStoreJmp
        add      esp, 4
    L_2129:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* H5: */
        mov      dword ptr [g_walkCallback], 0x1b333
        mov      dword ptr [g_eventQueueCurrent], 0xffffe667
        call     Wrapper_IterLoad_0048fd30_004f12ac
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_216d
        call     GateDispatch6c
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_216d
        push     OFFSET g_dispatchSave592
        call     ArgSarStoreJmp
        add      esp, 4
    L_216d:
        ret
        nop
        nop
        /* H6: */
        mov      dword ptr [g_walkCallback], 6
        call     TableLookupCall_g_table_004efae0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_218d
        jmp      RoundFinishEventGroup
    L_218d:
        ret
        nop
        nop
        /* H7: */
        mov      dword ptr [g_walkCallback], 8
        call     TableLookupCall_g_table_004efa00
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_21ad
        jmp      RoundFinishEventGroup
    L_21ad:
        ret
    }
}
