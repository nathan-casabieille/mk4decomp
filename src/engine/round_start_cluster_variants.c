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

extern void RoundStartCluster_CjInstallSelfRouter(void);
extern void ScaledLoadIncJmp_set_g_walkCallback_then_ScaledArrStore_GuardedChainCmpDualBitXor(void);
extern void StateMachineSharedTail(void);
extern void AerialPunchCluster(void);
extern void CmpEqInitCallElseJmp(void);
extern void EsiInstallClampAddCall(void);
extern void MStackPushSet0008(void);
extern void ScaledZeroFour(void);
extern unsigned int g_dispatchSave598;

extern unsigned int g_dispatchSave125;
extern unsigned int g_dispatchWalkVar;
extern unsigned int g_dispatchTab70;
extern void ArgSarStoreJmp(void);
extern void AudioInstallSelfStatePush(void);
extern void BootInitGuardedCallChain(void);
extern void CallSetPause(void);
extern void CjInstallSelfRouter(void);
extern void DualSectionInit(void);
extern void Eleven404b90_404c00(void);
extern void GuardedSetupTailMStackJmp(void);
extern void MStackPushChainDispatchInit5(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void);
extern void RemapWalkAndJmp_00491e70(void);
extern void RemapWalkAndJmp_00491ec0(void);
extern void ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain(void);
extern void StateDispatchTable(void);
extern void Ten404c40_404bd0(void);
extern void UpperBodyComboFsmCluster(void);
extern void ZeroTripleJmp(void);

__declspec(naked) void RoundStartCluster_CjInstallSelfRouter(void)
{
    __asm {
        /* H1: 3-state FSM */
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       short L_b9cd
        dec      eax
        je       short L_b930
        call     CjInstallSelfRouter
        pop      edi
        pop      esi
        ret
    L_b930:
        call     ScaledZeroFour
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_ba4d
        call     StateDispatchTable
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_ba4d
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [g_eventQueueNotMask], edi
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      dword ptr [g_currentNodeFlags], 0xccc
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_CjInstallSelfRouter
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET RoundStartCluster_CjInstallSelfRouter
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x2000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     EsiInstallClampAddCall
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_b9cd:
        call     MStackPushSet0008
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_ba4d
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x100e
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_CjInstallSelfRouter
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET RoundStartCluster_CjInstallSelfRouter
        add      ecx, 0x1000000
        mov      dword ptr [edx*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain
        mov      dword ptr [g_framePauseFlag], 1
    L_ba4d:
        pop      edi
        pop      esi
        ret
        /* H2: chime trigger */
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x211
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_dispatchSave598
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ArgSarStoreJmp
        add      esp, 4
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
        /* H3: scenario picker */
        call     ScaledLoadIncJmp_set_g_walkCallback_then_ScaledArrStore_GuardedChainCmpDualBitXor
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_baed
        mov      dword ptr [g_walkCallback], 0x11
        call     CmpEqInitCallElseJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_baed
        test     byte ptr [g_xformDirtyFlags], 1
        je       short L_bab4
        jmp      StateMachineSharedTail
    L_bab4:
        call     ScaledLoadIncJmp_set_g_walkCallback_then_ScaledArrStore_GuardedChainCmpDualBitXor
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_baed
        mov      dword ptr [g_walkCallback], 0x11
        call     CmpEqInitCallElseJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_baed
        test     byte ptr [g_xformDirtyFlags], 1
        jne      short L_bae8
        jmp      AerialPunchCluster
    L_bae8:
        jmp      StateMachineSharedTail
    L_baed:
        ret
    }
}

__declspec(naked) void RoundStartCluster_RemapWalkAndJmp(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 3
        ja       L_1bf6
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_19ed:
        call     RemapWalkAndJmp_00491e70
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_eventQueueEnd], ecx
        call     RemapWalkAndJmp_00491ec0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_eventQueueIdx], edx
        call     GuardedSetupTailMStackJmp
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        call     MStackLoopFieldInit
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        call     MStackPushChainDispatchInit5
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        push     0x1a
        push     OFFSET UpperBodyComboFsmCluster + 0xc0
        call     StoreTwoCall
        add      esp, 8
        push     0x1a
        push     OFFSET UpperBodyComboFsmCluster + 0x230
        call     StoreTwoCall
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], 0x48
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [eax*4 + 0x6c], 0x62e97
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      eax, 0xfff9d169
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x6c], eax
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_RemapWalkAndJmp
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x25
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_1ae3:
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [edx*4 + 0x6c], edi
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [eax*4 + 0x6c], edi
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_RemapWalkAndJmp
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x8c
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_1b2b:
        mov      ebx, 1
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_dispatchWalkVar], ebx
        call     UpperBodyComboFsmCluster
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_RemapWalkAndJmp
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET RoundStartCluster_RemapWalkAndJmp
        mov      dword ptr [ecx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x4000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edi
        call     AudioInstallSelfStatePush
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_1ba8:
        call     ZeroTripleJmp
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        call     DualSectionInit
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        push     0x25f
        push     OFFSET L_1c20
        call     StoreTwoCall
        mov      ebx, 1
        mov      dword ptr [esi + 8], OFFSET RoundStartCluster_RemapWalkAndJmp
        mov      dword ptr [esi + 0x84], ebx
        add      esp, 8
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_1bf6:
        call     BootInitGuardedCallChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1c08
        call     StackPopDispatchTagged
    L_1c08:
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_jmptbl:
        _emit 0xa8
        _emit 0x1b
        _emit 0x49
        _emit 0x00
        _emit 0xed
        _emit 0x19
        _emit 0x49
        _emit 0x00
        _emit 0xe3
        _emit 0x1a
        _emit 0x49
        _emit 0x00
        _emit 0x2b
        _emit 0x1b
        _emit 0x49
        _emit 0x00
        nop
        nop
        nop
        nop
    L_1c20:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, edi
        je       L_1ccc
        call     Ten404c40_404bd0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [ecx*4]
        inc      ecx
        cmp      eax, edi
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueEnd], ecx
        jne      L_1ca8
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      eax, OFFSET g_dispatchSave125
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [ecx*4 + 0x24], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x24], edx
        call     CallSetPause
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_1ca8:
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [ecx*4 + 0x24], eax
        mov      eax, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [eax*4 + 0x24], edx
        jmp      L_1e11
    L_1ccc:
        mov      eax, OFFSET g_dispatchTab70
        shr      eax, 2
        mov      dword ptr [g_eventQueueEnd], eax
        mov      ecx, dword ptr [eax*4]
        inc      eax
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_eventQueueEnd], eax
        call     DispatcherComplex260_FramePauseScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        test     byte ptr [g_xformDirtyFlags], 4
        je       L_1d0f
        call     CallSetPause
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_1d0f:
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueIdx], edx
        call     DispatcherComplex260_FramePauseScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_fightGroupHead], eax
        mov      dword ptr [ecx*4 + 0x54], edi
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x58], edi
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [eax*4 + 0x54], edi
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0x21
        mov      dword ptr [ecx*4 + 0x58], edi
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x30], eax
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_currentNodeIdx], edx
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      ebx, 0x14000
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [eax*4 + 0x5c], ebx
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [edx*4 + 0x5c], ebx
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      eax, dword ptr [edx*4 + 0x18]
        mov      dword ptr [g_fightGroupHead], eax
    L_1e11:
        call     Eleven404b90_404c00
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_1e3f
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_1c20
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 5
        mov      dword ptr [g_framePauseFlag], eax
    L_1e3f:
        pop      edi
        pop      esi
        pop      ebx
        ret      
    }
}
