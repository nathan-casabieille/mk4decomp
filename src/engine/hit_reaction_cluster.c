/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

extern unsigned int g_dispatchSave923;
extern unsigned int g_dispatchArg;
extern unsigned int g_hitPhase;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern void CallSetPause(void);
extern void DispatcherComplex181_StreamChainStringInstall(void);
extern void DualAddSar(void);
extern void GuardedRangeCmpFpuJmp(void);
extern void GuardedScaledCall(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void);
extern void PendingMatch_00459510(void);
extern void RoundCleanupCluster_Ten404c40_404bd0(void);
extern void SaveCallRestore(void);
extern void StoreIncrMStackPush6(void);
extern void TableLookupCall_g_eventTbl_65(void);

__declspec(naked) void HitReactionCluster(void)
{
    __asm {
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      ecx, eax
        shr      eax, 0xc
        and      ecx, 0xfff
        and      eax, 0xfff
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueCurrent], eax
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
        mov      dword ptr [g_eventQueueWorkType], 0x20000
        call     GuardedRangeCmpFpuJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c0cd
        jmp      PendingMatch_00459510
    L_c0cd:
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_walkCallback]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        call     DualAddSar
        mov      al, byte ptr [g_walkCallback]
        mov      dword ptr [g_eventQueueWorkType], 0x64a
        test     al, 1
        je       L_c122
        mov      dword ptr [g_eventQueueWorkType], 0x66d
    L_c122:
        call     Push16Call
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      dword ptr [g_matrixStackTop], eax
        jmp      PendingMatch_00459510
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_eventQueueWorkType], 0x627
        call     Push16Call
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueWorkType], edx
        mov      dword ptr [g_matrixStackTop], eax
        jmp      PendingMatch_00459510
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
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_player1NodeIdx]
        cmp      eax, ecx
        jne      L_c1ea
        cmp      dword ptr [g_dlNalt1], 9
        jne      L_c1e5
        mov      dword ptr [g_walkCallback], 0x1a
        call     TableLookupCall_g_eventTbl_65
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c21d
        jmp      PendingMatch_00459510
    L_c1e5:
        jmp      PendingMatch_00459510
    L_c1ea:
        cmp      eax, dword ptr [g_player2NodeIdx]
        jne      L_c21d
        cmp      dword ptr [g_dlNalt2], 9
        jne      L_c218
        mov      dword ptr [g_walkCallback], 0x1a
        call     TableLookupCall_g_eventTbl_65
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c21d
        jmp      PendingMatch_00459510
    L_c218:
        jmp      PendingMatch_00459510
    L_c21d:
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_player1NodeIdx]
        cmp      eax, ecx
        jne      L_c25a
        cmp      dword ptr [g_dlNalt1], 9
        jne      L_c255
        mov      dword ptr [g_walkCallback], 0x1c
        call     TableLookupCall_g_eventTbl_65
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c28d
        jmp      PendingMatch_00459510
    L_c255:
        jmp      PendingMatch_00459510
    L_c25a:
        cmp      eax, dword ptr [g_player2NodeIdx]
        jne      L_c28d
        cmp      dword ptr [g_dlNalt2], 9
        jne      L_c288
        mov      dword ptr [g_walkCallback], 0x1c
        call     TableLookupCall_g_eventTbl_65
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c28d
        jmp      PendingMatch_00459510
    L_c288:
        jmp      PendingMatch_00459510
    L_c28d:
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      ebx, 4
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, ebx
        ja       L_c591
        jmp      dword ptr [eax*4 + L_c5a4_jmptbl]
        mov      ecx, 0x50d8b0
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DispatcherComplex260_FramePauseScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_c59b
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x30], 0x2f
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xffc40000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xffffc667
        mov      dword ptr [edx*4 + 0x5c], 0xa0000
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_fightGroupHead], edx
        mov      dword ptr [esi + 8], 0x45c290
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x14
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        push     0x30
        call     SaveCallRestore
        add      esp, 4
        push     0x30
        call     SaveCallRestore
        mov      dword ptr [esi + 8], 0x45c290
        mov      dword ptr [esi + 0x84], 3
        add      esp, 4
        mov      dword ptr [g_pendingNodeType], 0x14
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      ax, word ptr [g_dispatchSave923]
        push     eax
        call     TaggedSceneDispatch
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], edi
        add      esp, 4
        mov      dword ptr [ecx*4 + 0x74], edi
        mov      dword ptr [esi + 8], 0x45c290
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 0x14
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, 0x3999
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x74], eax
        mov      dword ptr [esi + 8], 0x45c290
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], 0x28
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        call     AllocSlotPushTripleGlobals
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        mov      eax, 0x4d5550
        mov      dword ptr [g_walkCallback], 0x30
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_chainAccumCur], 0xfff60000
        mov      dword ptr [g_eventQueueNotMask], 0xffd20000
        call     Push70CallScaleArith
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        call     MStackPop4Rewrite
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_c59b
        mov      ecx, dword ptr [g_hitPhase]
        mov      dword ptr [g_walkCallback], ecx
        call     StoreIncrMStackPush6
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      ebx, 1
        mov      dword ptr [g_eventQueueWorkType], 0x30
        mov      dword ptr [g_chainAccumCur], 0x230000
        mov      dword ptr [g_eventQueueNotMask], 0xffd20000
        mov      dword ptr [g_currentNodeFlags], ebx
        call     DispatcherComplex181_StreamChainStringInstall
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        call     RoundCleanupCluster_Ten404c40_404bd0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
        cmp      dword ptr [g_walkCallback], edi
        je       L_c59b
        mov      edx, dword ptr [g_hitPhase]
        mov      eax, 0x5424b0
        shr      eax, 2
        lea      ecx, [edx - 1]
        mov      dword ptr [g_currentNodeIdx], eax
        cmp      ecx, 2
        mov      dword ptr [g_dispatchArg], ecx
        jg       L_c570
        add      eax, ecx
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_walkCallback], eax
        call     GuardedScaledCall
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_c5a0
    L_c570:
        mov      dword ptr [esi + 8], 0x45c290
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_c591:
        push     0x2f
        call     SaveCallRestore
        add      esp, 4
    L_c59b:
        call     CallSetPause
    L_c5a0:
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_c5a4_jmptbl:
        /* 5-entry jump table */
        _emit    0x52  /* case 0 -> 0x45c452 */
        _emit    0xc4
        _emit    0x45
        _emit    0x00
        _emit    0xc1  /* case 1 -> 0x45c2c1 */
        _emit    0xc2
        _emit    0x45
        _emit    0x00
        _emit    0x8e  /* case 2 -> 0x45c38e */
        _emit    0xc3
        _emit    0x45
        _emit    0x00
        _emit    0xcb  /* case 3 -> 0x45c3cb */
        _emit    0xc3
        _emit    0x45
        _emit    0x00
        _emit    0x12  /* case 4 -> 0x45c412 */
        _emit    0xc4
        _emit    0x45
        _emit    0x00
    }
}
