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

extern void CallPauseScaledStoreCopyJmp(void);
extern void GameStateDispatch4Way(void);
extern void InstallSelfPlusTailThunk(void);
extern void MStackChainBit2Cascade(void);
extern void MstackPopScaledChainPlusThunks(void);
extern void ScaledInit_GameModeHandlerCluster_g_scaledInit_00495590(void);
extern void ScaledInit_GameModeHandlerCluster_g_scaledInit_004955b0(void);
extern void StateGateMStackOverlap(void);

__declspec(naked) void ThrowGrabInitCluster(void)
{
    __asm {
        /* === h1 (0x436b30): timer + tail-jmp 471250 === */
        call     LeaPlus22StoreSelf
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6b63
        mov      eax, dword ptr [g_matrixStackTop]
        mov      dword ptr [g_walkCallback], 0xa
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET InstallSelfPlusTailThunk + 0x100
        jmp      MstackPopScaledChainPlusThunks
    L_6b63:
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
        /* === h2 (0x436b70): pose-fn install state 1 w/ 0x21999 === */
    L_6b70:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_6b99
        call     ScaledInit_GameModeHandlerCluster_g_scaledInit_004955b0
        pop      esi
        ret
    L_6b99:
        call     LeaPlus22StoreSelf
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6c1a
        mov      dword ptr [g_currentNodeFlags], 0x21999
        mov      dword ptr [g_eventQueueChild], 0x1e
        mov      dword ptr [esi + 8], OFFSET L_6b70
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_6b70
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     StateGateMStackOverlap
        mov      dword ptr [g_framePauseFlag], 1
    L_6c1a:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        /* === h3 (0x436c20): pose-fn install state 1 w/ 0x16666 === */
    L_6c20:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_6c49
        call     ScaledInit_GameModeHandlerCluster_g_scaledInit_00495590
        pop      esi
        ret
    L_6c49:
        call     LeaPlus22StoreSelf
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6cca
        mov      dword ptr [g_currentNodeFlags], 0x16666
        mov      dword ptr [g_eventQueueChild], 0x1e
        mov      dword ptr [esi + 8], OFFSET L_6c20
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_6c20
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     StateGateMStackOverlap
        mov      dword ptr [g_framePauseFlag], 1
    L_6cca:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        /* === h4 (0x436cd0): pose-fn 2-state w/ wait counter === */
    L_6cd0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        mov      ebx, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_6d2b
        mov      eax, dword ptr [g_eventQueueChild]
        dec      eax
        mov      dword ptr [g_eventQueueChild], eax
        jne      short L_6d0d
        call     CallPauseTestByteJmpCalls
        pop      esi
        pop      ebx
        ret
    L_6d0d:
        call     MStackChainBit2Cascade
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6d78
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_6d5f
        call     CallPauseTestByteJmpCalls
        pop      esi
        pop      ebx
        ret
    L_6d2b:
        call     LeaPlus22StoreSelf
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6d78
        call     ScaledZeroFour
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6d78
        call     CallPauseScaledStoreCopyJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6d78
        mov      dword ptr [g_eventQueueChild], 0x3c
    L_6d5f:
        mov      dword ptr [esi + 8], OFFSET L_6cd0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_6d78:
        pop      esi
        pop      ebx
        ret
        nop
        nop
        nop
        nop
        nop
        /* === h5 (0x436d80): pose-fn state-1 install if dist>=0x20000 === */
    L_6d80:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_6da9
        call     GameStateDispatch4Way
        pop      esi
        ret
    L_6da9:
        call     LeaPlus22StoreSelf
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6e46
        mov      eax, dword ptr [g_fightStateProgress]
        cmp      eax, 0x20000
        mov      dword ptr [g_walkCallback], eax
        jge      short L_6dd3
        call     GameStateDispatch4Way
        pop      esi
        ret
    L_6dd3:
        mov      dword ptr [g_currentNodeFlags], 0x20000
        mov      dword ptr [g_eventQueueChild], 0x1e
        mov      dword ptr [esi + 8], OFFSET L_6d80
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_6d80
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     StateGateMStackOverlap
        mov      dword ptr [g_framePauseFlag], 1
    L_6e46:
        pop      esi
        ret
    }
}
