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

extern void func_00477ee0(void);
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

extern unsigned int g_dispatchTableArr4;
extern unsigned int g_dispatchTableArr3;
extern unsigned int g_dispatchClr0;
extern unsigned int g_player2State;
extern void BootMstackInit(void);
extern void DispatcherComplex181_StreamChainStringInstall(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void);
extern void RoundCleanupCluster_00427690(void);
extern void SaveCallRestoreOrXor(void);
extern void SaveCallRestore(void);
extern void StoreIncrMStackPush6(void);

void YRiseSpawnerCluster(void) {
    __asm {
        mov      eax, dword ptr [g_active_00537e88]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       L_7d70
        push     0x24
        call     SaveCallRestore
        add      esp, 4
        push     0x26
        call     SaveCallRestore
        mov      eax, OFFSET g_dispatchTableArr4
        add      esp, 4
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        call     DispatcherComplex260_FramePauseScaledStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7e12
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_7e12
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x54], 0x870000
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x58], 0xff910000
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], 0x24
        mov      dword ptr [eax*4 + 0x30], 0x24
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7e12
        mov      eax, dword ptr [g_player2State]
        cmp      eax, 0x63
        mov      dword ptr [g_walkCallback], eax
        ja       short L_7ce0
        call     StoreIncrMStackPush6
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7e12
        mov      dword ptr [g_eventQueueCurrent], 3
        mov      dword ptr [g_eventQueueWorkType], 0x26
        mov      dword ptr [g_acc_00542078], 0xa00000
        mov      dword ptr [g_eventQueueNotMask], 0xff970000
        mov      dword ptr [g_currentNodeFlags], 2
        call     DispatcherComplex181_StreamChainStringInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7e12
        call     RoundCleanupCluster_00427690
        mov      eax, dword ptr [g_framePauseFlag]
        ret
    L_7ce0:
        push     0x24
        call     SaveCallRestoreOrXor
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 4
        mov      ecx, dword ptr [eax*4 + 0x54]
        add      ecx, 0xfff70000
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      ecx, dword ptr [g_player2State]
        mov      dword ptr [g_walkCallback], ecx
        call     StoreIncrMStackPush6
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7e12
        mov      dword ptr [g_eventQueueCurrent], 3
        mov      dword ptr [g_eventQueueWorkType], 0x26
        mov      dword ptr [g_acc_00542078], 0x970000
        mov      dword ptr [g_eventQueueNotMask], 0xff970000
        mov      dword ptr [g_currentNodeFlags], 2
        call     DispatcherComplex181_StreamChainStringInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7e12
        call     RoundCleanupCluster_00427690
        mov      eax, dword ptr [g_framePauseFlag]
        ret
    L_7d70:
        push     0x233
        call     SaveCallRestore
        mov      edx, OFFSET g_dispatchTableArr3
        add      esp, 4
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_FramePauseScaledStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7e12
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_7e12
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], 0x870000
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], 0xff910000
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], 0x233
        mov      dword ptr [edx*4 + 0x30], 0x233
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7e12
        push     0x25b
        push     OFFSET func_00477ee0
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [g_dispatchClr0], 0
        call     BootMstackInit
        add      esp, 8
    L_7e12:
        }
}
extern void func_00477ee0(void);

