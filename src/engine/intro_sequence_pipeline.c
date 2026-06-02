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

extern void GDispatch4(void);
extern void MStackBracket5_FieldClear_StateAdvance(void);
extern void MStackCall_0044d230(void);
extern void MStackPush2GuardedFieldClear(void);
extern void MStackPushTyped_0044cf50(void);
extern void MStackPushTyped_0044cf80(void);
extern void MStackPushTyped_0044cfb0(void);
extern void PushPopXformEntityCall(void);
extern void PushSetXfmCallStoreCopy(void);

__declspec(naked) void IntroSequencePipeline(void)
{
    __asm {
        push     ebx
        call     PushSetXfmCallStoreCopy
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cf48
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      bl, 4
        test     al, bl
        jne      L_cf48
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      ecx, 1
        mov      eax, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4 + 0x1c], ecx
        call     MStackPushTyped_0044cf50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cf48
        mov      dword ptr [g_walkCallback], 0x10
        call     MStackPush2GuardedFieldClear
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cf48
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_cf48
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 3
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x1c], eax
        call     MStackPushTyped_0044cf80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_cf48
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_xformEntityIdx], eax
        call     MStackCall_0044d230
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf48
        mov      ecx, dword ptr [g_eventQueueTotal]
        mov      eax, dword ptr [g_pendingNodeType]
        mov      edx, dword ptr [ecx*4 + 0x18]
        mov      dword ptr [g_walkCallback], 0xe
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_eventQueueEnd], eax
        call     MStackPush2GuardedFieldClear
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf48
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_cf48
        call     PushPopXformEntityCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf48
        call     MStackCall_0044d230
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf48
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_xformEntityIdx], ecx
        call     MStackBracket5_FieldClear_StateAdvance
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf48
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_cf48
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x1c], eax
        call     MStackPushTyped_0044cfb0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf48
        call     MStackCall_0044d230
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf48
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_pendingNodeType]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_walkCallback], 0xc
        mov      dword ptr [g_eventQueueEnd], ecx
        call     MStackPush2GuardedFieldClear
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf48
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_cf48
        call     PushPopXformEntityCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf48
        call     MStackCall_0044d230
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_cf48
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_fightGroupHead], eax
        call     GDispatch4
    L_cf48:
        pop      ebx
        ret
    }
}
