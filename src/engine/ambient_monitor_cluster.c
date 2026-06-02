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

extern void SetWalkCurCallPauseDirty(void);
extern void StackPopDispatchTagged(void);
extern void BootInitGuardedCallChain(void);
extern void DualTestDirtyToggle_00427ea0(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void PendingMatch_00461ca0(void);
extern void Push16Call(void);
extern void StoreTwoCall(void);
extern void PhaseClampInstallSlot(void);
extern void GuardedCmpDualToggle(void);
extern void AmbientMonitorCluster(void);
extern void ThrowAnimTriggerCluster(void);
extern void MStackDirtyArgsBit0(void);
extern void TableWalkBoundedCmp(int);
extern void TaggedSceneDispatch(void);
extern void QuadCallPhase2(void);
extern void RoundCleanupCluster_00427690(void);
extern unsigned int g_dispatchSave669;
extern unsigned int g_dispatchSave637;
extern unsigned int g_tickFlagF;
extern unsigned int g_dispatchSave49;
extern unsigned int g_audioInstall2Slot;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern unsigned int g_phaseThunkSlot5;
extern unsigned int g_phaseCounter;
extern unsigned int g_audioTriEntryFlag;
extern unsigned int g_audioMatchStartFlag;
extern unsigned int g_audioStateRemapByte;

__declspec(naked) void SceneEvalFsm(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        xor      ebx, ebx
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], ebx
        cmp      eax, 3
        ja       L_e198
        jmp      dword ptr [eax*4 + L_jmptbl]
        push     0x251
        push     OFFSET AmbientMonitorCluster + 0xd0
        call     StoreTwoCall
        add      esp, 8
        mov      ecx, OFFSET g_dispatchSave637
        shr      ecx, 2
        push     0x262
        push     OFFSET RoundCleanupCluster_00427690 + 0xf0
        mov      dword ptr [g_fightGroupHead], ecx
        call     StoreTwoCall
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm
        mov      dword ptr [esi + 0x84], 2
        add      esp, 8
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        pop      ebx
        ret      
        mov      dword ptr [g_eventQueueWorkType], 0x47
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], ebx
        je       L_df68
        pop      esi
        pop      ebx
        ret      
        push     0x251
        push     OFFSET AmbientMonitorCluster + 0xd0
        call     SetWalkCurCallPauseDirty
        add      esp, 8
        call     MStackDirtyArgsBit0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        test     byte ptr [g_xformDirtyFlags], 1
        jne      L_df8b
    L_df68:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        pop      ebx
        ret      
    L_df8b:
        call     DualTestDirtyToggle_004282c0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        test     byte ptr [g_xformDirtyFlags], 1
        je       L_e05e
        jmp      L_e198
        push     6
        mov      byte ptr [g_audioStateRemapByte], bl
        call     TableWalkBoundedCmp
        add      esp, 4
        push     2
        call     TableWalkBoundedCmp
        add      esp, 4
        push     4
        call     TableWalkBoundedCmp
        add      esp, 4
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2
        add      esp, 0x10
        call     DualTestDirtyToggle_00427ea0
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        test     byte ptr [g_xformDirtyFlags], 1
        jne      L_e010
        mov      dword ptr [g_walkCallback], 1
        mov      dword ptr [g_active_0053a408], 1
    L_e010:
        call     AmbientMonitorCluster
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        call     GuardedCmpDualToggle
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        cmp      dword ptr [g_stateCountdown], ebx
        je       L_e0fc
        cmp      dword ptr [g_active_0053a408], 2
        je       L_e0fc
        mov      eax, dword ptr [g_active_00537e88]
        cmp      eax, 2
        mov      dword ptr [g_walkCallback], eax
        je       L_e0fc
    L_e05e:
        cmp      dword ptr [g_audioMatchStartFlag], ebx
        je       L_e09d
        cmp      dword ptr [g_gtOtherFlag], ebx
        je       L_e09d
        cmp      dword ptr [g_audioTriEntryFlag], ebx
        je       L_e09d
        mov      al, byte ptr [g_gtModeFlag]
        mov      dword ptr [g_stateCountdown], ebx
        cmp      al, 1
        mov      dword ptr [g_phaseCounter], 4
        jne      L_e097
        mov      dword ptr [g_dlNalt2], ebx
        jmp      L_e09d
    L_e097:
        mov      dword ptr [g_dlNalt1], ebx
    L_e09d:
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET SceneEvalFsm
        mov      dword ptr [edx*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x4000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], ebx
        call     PendingMatch_00461ca0
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
    L_e0fc:
        mov      ax, word ptr [g_dispatchSave669]
        mov      dword ptr [g_tickFlagF], 3
        push     eax
        mov      dword ptr [g_audioInstall2Slot], ebx
        mov      dword ptr [g_phaseThunkSlot5], ebx
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_dispatchSave49], ebx
        call     TaggedSceneDispatch
        add      esp, 4
        call     ThrowAnimTriggerCluster
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        mov      dword ptr [esi + 8], OFFSET SceneEvalFsm
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET SceneEvalFsm
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
        mov      dword ptr [eax*4 + 0x84], ebx
        call     PhaseClampInstallSlot
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
    L_e198:
        call     BootInitGuardedCallChain
        cmp      dword ptr [g_framePauseFlag], ebx
        jne      L_e1aa
        call     StackPopDispatchTagged
    L_e1aa:
        pop      esi
        pop      ebx
        ret
        _emit 0x8d
        _emit 0x49
        _emit 0x00
    L_jmptbl:
        _emit 0xae
        _emit 0xdf
        _emit 0x49
        _emit 0x00
        _emit 0xcd
        _emit 0xde
        _emit 0x49
        _emit 0x00
        _emit 0x22
        _emit 0xdf
        _emit 0x49
        _emit 0x00
        _emit 0x3c
        _emit 0xdf
        _emit 0x49
        _emit 0x00
    }
}
