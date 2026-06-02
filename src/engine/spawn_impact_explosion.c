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

extern unsigned int g_const_0049db40;
extern unsigned int g_dispatchSave986;
extern unsigned int g_dispatchSave987;
extern unsigned int g_dispatchSave988;
extern void StoreDoubleNegPauseSubStore(void);
extern void ZeroAndDirty4(void);

__declspec(naked) void SpawnImpactExplosion(void)
{
    __asm {
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        inc      eax
        push     esi
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, OFFSET g_dispatchSave986
        mov      dword ptr [g_eventQueueEnd], edx
        shr      eax, 2
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [g_walkCallback], 0xc000
        call     ZeroAndDirty4
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      L_1dfa
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_1ca9
        mov      ecx, OFFSET g_dispatchSave987
        mov      dword ptr [g_walkCallback], 0xd999
        shr      ecx, 2
        mov      dword ptr [g_eventQueueIdx], ecx
        call     ZeroAndDirty4
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_1dfa
        test     byte ptr [g_xformDirtyFlags], 4
        jne      short L_1ca9
        mov      edx, OFFSET g_dispatchSave988
        shr      edx, 2
        mov      dword ptr [g_eventQueueIdx], edx
    L_1ca9:
        push     0xc0
        push     OFFSET g_const_0049db40
        mov      dword ptr [g_eventQueueNotMask], 0xc1
        call     StoreTwoCall
        mov      al, byte ptr [g_xformDirtyFlags]
        add      esp, 8
        test     al, 1
        jne      L_1dbc
        mov      dword ptr [g_eventQueueCurrent], esi
        mov      dword ptr [g_walkCallback], 0xc28f
        call     StoreDoubleNegPauseSubStore
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_1dfa
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      edx, dword ptr [g_currentNodeIdx]
        add      ecx, eax
        mov      dword ptr [edx*4 + 0x38], ecx
        mov      dword ptr [g_eventQueueCurrent], 0xfffe0000
        mov      dword ptr [g_walkCallback], 0xdc28
        call     StoreDoubleNegPauseSubStore
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_1dfa
        mov      eax, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      edx, dword ptr [g_currentNodeIdx]
        add      ecx, eax
        mov      dword ptr [edx*4 + 0x3c], ecx
        mov      dword ptr [g_eventQueueCurrent], 0xc4000
        mov      dword ptr [g_walkCallback], 0x5c28
        call     StoreDoubleNegPauseSubStore
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_1dfa
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      ecx, dword ptr [g_walkCallback]
        add      eax, ecx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x44], esi
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x48], esi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [ecx*4 + 0x4c], esi
    L_1dbc:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueNotMask], edx
        mov      dword ptr [g_matrixStackTop], eax
    L_1dfa:
        pop      esi
        ret
    }
}
