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

extern unsigned int g_or;
extern unsigned int g_audioStreamState;
extern s32 g_dlChar13;
extern s32 g_dlChar24;
extern unsigned int g_dispatchTab68;
extern unsigned int g_dispatchTab67;
extern unsigned int g_dispatchTab66;
extern void DirtyDoubleDeref(void);
extern void MStackBracket1_TreeWalkRecursive2(void);
extern void MStackChainDecodeCall(void);
extern void MStackPush2ChainPrepend(void);
extern void MStackPushCallCallPop_00405e20(void);
extern void PushSetCallCleanup(void);
extern void ScaledAddDeref(void);
extern void ScaledLoadJmp30_set_g_walkCallback_then_LoadCmpAddrJmp(void);
extern void ScaledTestPauseStore(void);
extern void TestStoreConstJmp(void);

void StrikeAnim4Picker(void) {
    __asm {
        mov      eax, dword ptr [g_or]
        mov      dword ptr [g_eventQueueCurrent], eax
        and      eax, 0x20
        mov      dword ptr [g_xformScratch94], eax
        je       short L_3126
        call     TestStoreConstJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_33a1
    L_3126:
        mov      eax, dword ptr [g_audioStreamState]
        mov      edx, dword ptr [g_baseSel]
        test     eax, eax
        jne      short L_314d
        cmp      edx, dword ptr [g_gtPlayerProbe2]
        jne      short L_3145
        mov      ecx, dword ptr [g_dlChar13]
        jmp      short L_314f
    L_3145:
        mov      ecx, dword ptr [g_dlChar24]
        jmp      short L_314f
    L_314d:
        xor      ecx, ecx
    L_314f:
        test     ecx, ecx
        je       short L_3158
        cmp      ecx, 1
        jne      short L_3162
    L_3158:
        mov      eax, OFFSET g_dispatchTab68
        shr      eax, 2
        jmp      short L_3167
    L_3162:
        mov      eax, dword ptr [g_currentNodeIdx]
    L_3167:
        cmp      ecx, 2
        jne      short L_3174
        mov      eax, OFFSET g_dispatchTab67
        shr      eax, 2
    L_3174:
        cmp      ecx, 3
        jne      short L_3181
        mov      eax, OFFSET g_dispatchTab66
        shr      eax, 2
    L_3181:
        add      eax, dword ptr [g_walkCallback]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [edx*4 + 0x30], eax
        mov      dword ptr [g_walkCallback], 1
        call     ScaledAddDeref
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_33a1
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], 2
        mov      dword ptr [g_xformEntityIdx], eax
        call     ScaledAddDeref
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_33a1
        mov      ecx, dword ptr [g_matrixStackTop]
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_matrixStackTop], ecx
        mov      dword ptr [ecx*4], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_xformEntityIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_pendingNodeType]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueTotal]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     MStackBracket1_TreeWalkRecursive2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_33a1
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_3350
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueTotal], edx
        call     ScaledTestPauseStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_33a1
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_3342
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x1c]
        mov      dword ptr [g_xformEntityIdx], ecx
        call     PushSetCallCleanup
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_33a1
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      dword ptr [g_currentNodeIdx], edx
        call     MStackChainDecodeCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_33a1
        mov      dword ptr [g_walkCallback], 0xa
        call     DirtyDoubleDeref
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_33a1
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueTotal]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackPush2ChainPrepend
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_33a1
        call     ScaledLoadJmp30_set_g_walkCallback_then_LoadCmpAddrJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_33a1
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4 + 0x40]
        or       al, 2
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [ecx*4 + 0x40], eax
        jmp      short L_3350
    L_3342:
        call     MStackPushCallCallPop_00405e20
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_33a1
    L_3350:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueTotal], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_33a1:
        }
}

