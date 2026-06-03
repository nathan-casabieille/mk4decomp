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

extern unsigned int g_dispatchSave773;
extern void GatedChainClamp(void);
extern void MStackPush3CallCascade(void);
extern void Phase2InitDispatchInstallSelf(void);
extern void ScaledChainDouble(void);

__declspec(naked) void RoundResultSlotInitTable(void)
{
    __asm {
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_walkCallback]
        inc      eax
        push     esi
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueCurrent]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueChild]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        call     ScaledChainDouble
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_69c8
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      edx, dword ptr [g_eventQueueChild]
        mov      esi, dword ptr [g_fightGroupHead]
        sar      ecx, 1
        sar      edx, 1
        mov      dword ptr [g_eventQueueNotMask], ecx
        mov      dword ptr [g_eventQueueChild], edx
        mov      eax, dword ptr [esi*4 + 0x54]
        mov      dword ptr [g_walkCallback], eax
        mov      esi, dword ptr [esi*4 + 0x5c]
        add      eax, ecx
        mov      ecx, dword ptr [g_baseSel]
        add      esi, edx
        add      ecx, 0x19
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], esi
        mov      dword ptr [g_eventQueueWorkType], 0xfffe6667
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [edx*4 + 4], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      eax, OFFSET g_dispatchSave773
        shr      eax, 2
        mov      dword ptr [edx*4 + 8], ecx
        mov      dword ptr [g_xformEntityIdx], eax
        call     Phase2InitDispatchInstallSelf
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_69c8
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueChild], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueNotMask], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_matrixStackTop], eax
    L_69c8:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x74], 0x4004
        mov      dword ptr [g_eventQueueCurrent], 1
        mov      dword ptr [g_eventQueueWorkType], 0
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0xf5c
        mov      dword ptr [g_eventQueueChild], 3
        jmp      MStackPush3CallCascade
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        xor      ecx, ecx
        mov      eax, 1
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueChild], 0x10
        jmp      MStackPush3CallCascade
        nop
        nop
        nop
        nop
        mov      dword ptr [g_eventQueueCurrent], 0
        mov      dword ptr [g_eventQueueWorkType], 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0x2e14
        mov      dword ptr [g_eventQueueChild], 0x15
        jmp      MStackPush3CallCascade
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov      eax, 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_walkCallback], 0x3333
        mov      dword ptr [g_eventQueueChild], 0x16
        jmp      MStackPush3CallCascade
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
        mov      eax, 1
        mov      dword ptr [g_eventQueueChild], 0x17
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueNotMask], 3
        mov      dword ptr [g_walkCallback], 0x4000
        jmp      MStackPush3CallCascade
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
        mov      eax, 1
        mov      dword ptr [g_eventQueueChild], 7
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueNotMask], 3
        mov      dword ptr [g_walkCallback], 0x4000
        jmp      MStackPush3CallCascade
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
        mov      eax, 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_walkCallback], 0x3333
        mov      dword ptr [g_eventQueueChild], 6
        jmp      MStackPush3CallCascade
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
        mov      dword ptr [g_eventQueueCurrent], 1
        mov      dword ptr [g_eventQueueWorkType], 0
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0x3333
        mov      dword ptr [g_eventQueueChild], 6
        jmp      MStackPush3CallCascade
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov      dword ptr [g_eventQueueCurrent], 0
        mov      dword ptr [g_eventQueueWorkType], 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0x2e14
        mov      dword ptr [g_eventQueueChild], 5
        jmp      MStackPush3CallCascade
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov      dword ptr [g_eventQueueCurrent], 0
        mov      dword ptr [g_eventQueueWorkType], 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0x2666
        mov      dword ptr [g_eventQueueChild], 4
        jmp      MStackPush3CallCascade
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x74], 0x4004
        mov      eax, 1
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], 0xf5c
        mov      dword ptr [g_eventQueueChild], 3
        jmp      MStackPush3CallCascade
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
        mov      eax, 1
        mov      dword ptr [g_eventQueueCurrent], 0
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      dword ptr [g_walkCallback], 0x3d70
        mov      dword ptr [g_eventQueueChild], eax
        jmp      MStackPush3CallCascade
        nop
        nop
        nop
        xor      eax, eax
        mov      dword ptr [g_eventQueueNotMask], 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueChild], eax
        jmp      MStackPush3CallCascade
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
        xor      eax, eax
        mov      dword ptr [g_walkCallback], 0x2147
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_eventQueueChild], 5
        jmp      MStackPush3CallCascade
        nop
        xor      eax, eax
        mov      ecx, 1
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      dword ptr [g_eventQueueNotMask], ecx
        mov      dword ptr [g_eventQueueChild], eax
        jmp      MStackPush3CallCascade
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        xor      eax, eax
        mov      dword ptr [g_eventQueueCurrent], 1
        mov      dword ptr [g_eventQueueNotMask], 2
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueChild], eax
        jmp      GatedChainClamp
    }
}
