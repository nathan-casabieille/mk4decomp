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

extern unsigned int g_dispatchSave955;
extern unsigned int g_dispatchArg;
extern unsigned int g_audioVoiceCounter;
extern unsigned int g_cameraProjSlot;
extern unsigned int g_installCountdownArr3;
extern void BootPhaseGateBracketedInit(void);
extern void Chain2CallMul10Accum(void);
extern void FramePauseScaledStore(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void MStackPush2ChainLLInsert(void);
extern void MStackPush2ChainPrepend(void);
extern void FixedDiv16(void);
extern void RegistryPushBindPop(void);
extern void Thunk_BootMod6487eClampAndChainMul10(void);

__declspec(naked) void CameraProjectionInitSweep(void)
{
    __asm {
        push     ebx
        push     edi
        mov      dword ptr [g_walkCallback], 0x6487e
        mov      dword ptr [g_eventQueueCurrent], 0x280000
        call     FixedDiv16
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8430
        mov      eax, dword ptr [g_walkCallback]
        mov      edi, OFFSET g_installCountdownArr3
        shr      edi, 2
        mov      dword ptr [g_currentNodeFlags], eax
        mov      dword ptr [g_pendingNodeType], edi
        call     BootPhaseGateBracketedInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8430
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      bl, 4
        test     al, bl
        jne      L_8430
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, OFFSET g_dispatchSave955
        shr      ecx, 2
        mov      dword ptr [g_eventQueueTotal], eax
        mov      dword ptr [g_cameraProjSlot], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     FramePauseScaledStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8430
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_840c
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x18], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      dword ptr [ecx*4 + 0x18], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueTotal], eax
        mov      dword ptr [g_audioVoiceCounter], 0x28
        mov      dword ptr [g_acc_00542078], 0
        mov      dword ptr [g_eventQueueNotMask], 0
        mov      dword ptr [g_xformScratch2088], 0x3243f
        mov      dword ptr [g_eventQueueChild], 0x50000
        mov      dword ptr [g_dispatchArg], 1
    L_8267:
        mov      eax, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        test     ecx, ecx
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_pendingNodeType], eax
        jne      short L_829d
        mov      eax, edi
        mov      dword ptr [g_pendingNodeType], eax
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_pendingNodeType], eax
    L_829d:
        call     FramePauseScaledStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8430
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_840c
        mov      edx, dword ptr [g_eventQueueTotal]
        mov      dword ptr [g_xformEntityIdx], edx
        call     MStackPush2ChainPrepend
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8430
        mov      eax, dword ptr [g_xformScratch2088]
        mov      dword ptr [g_eventQueueWorkType], eax
        call     Chain2CallMul10Accum
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8430
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x30], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      edx, 0x3243f
        mov      dword ptr [ecx*4 + 0x38], eax
        mov      ecx, dword ptr [g_xformScratch2088]
        sub      edx, ecx
        mov      dword ptr [g_walkCallback], edx
        call     Thunk_BootMod6487eClampAndChainMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8430
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x40], eax
        mov      eax, dword ptr [g_xformScratch2088]
        sub      eax, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_xformScratch2088], eax
        mov      dword ptr [g_walkCallback], eax
        call     Thunk_BootMod6487eClampAndChainMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8430
        mov      eax, dword ptr [g_dispatchArg]
        mov      edx, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_xformScratch2088], edx
        mov      dword ptr [g_dispatchArg], eax
        mov      dword ptr [ecx*4 + 0x1c], eax
        mov      eax, dword ptr [g_audioVoiceCounter]
        dec      eax
        mov      dword ptr [g_audioVoiceCounter], eax
        jne      L_8267
        mov      eax, dword ptr [g_cameraProjSlot]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4 + 0x30], 0x270
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x18000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x58], eax
        call     MStackCall_MStackPush2ChainPrepend_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8430
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_fightGroupHead], eax
        call     RegistryPushBindPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8430
        call     MStackBracket4_ListInsertZeroFill
        mov      eax, dword ptr [g_framePauseFlag]
        pop      edi
        pop      ebx
        ret
    L_840c:
        mov      ecx, dword ptr [g_cameraProjSlot]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackPush2ChainLLInsert
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8430
        mov      dword ptr [g_currentNodeIdx], 0
    L_8430:
        pop      edi
        pop      ebx
        ret
    }
}
