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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

extern unsigned int g_dispatchSave695_004e8190;
extern unsigned int g_dispatchSave58_0050b604;
extern void DispatcherComplex138_00476060(void);
extern void DualScaledStore(void);
extern void GatedWordPushCall(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackCall_00406600(void);
extern void PendingMatch_004568b0(void);
extern void ScaledStoreThree_00409260(void);
extern void ScaledTestPauseStore(void);
extern void TableHitOrSchedule(void);
extern void Thunk_0049cbc0(void);
extern void WorldCellSetupCluster(void);

__declspec(naked) void CharSelectSetupCluster_004565a0(void)
{
    __asm {
        /* === h1 (0x4565a0): main init chain → tail 408600 === */
        mov      eax, OFFSET g_dispatchSave58_0050b604
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6688
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_6688
        call     MStackCall_00406600
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_6688
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [ecx*4 + 0x64]
        add      eax, 0x4b65f
        push     eax
        mov      dword ptr [g_walkCallback], eax
        call     WorldCellSetupCluster
        mov      edx, dword ptr [g_currentNodeIdx]
        add      esp, 4
        mov      dword ptr [edx*4 + 0x64], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x30], 0x93
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0xfffff852
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [g_fightGroupHead], eax
        mov      edx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], edx
        call     ScaledTestPauseStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6688
        mov      eax, OFFSET g_dispatchSave695_004e8190
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        call     ScaledStoreThree_00409260
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_6688
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], ecx
        jmp      MStackBracket4_ListInsertZeroFill
    L_6688:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x456690): pose-fn 4-state status FSM === */
    L_6690:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_676f
        dec      eax
        je       short L_6730
        dec      eax
        je       short L_66ed
        mov      dword ptr [g_walkCallback], 0x4b
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_67a8
        push     0x154f
        call     TableHitOrSchedule
        add      esp, 4
        call     Thunk_0049cbc0
        pop      esi
        ret
    L_66ed:
        mov      dword ptr [g_walkCallback], 0x4a
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_67a8
        mov      dword ptr [esi + 8], OFFSET L_6690
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0xbd
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_6730:
        mov      dword ptr [g_walkCallback], 0x4a
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_67a8
        mov      dword ptr [esi + 8], OFFSET L_6690
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0xbd
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_676f:
        mov      dword ptr [g_walkCallback], 0x49
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_67a8
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_6690
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x7d
        mov      dword ptr [g_framePauseFlag], eax
    L_67a8:
        pop      esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h3 (0x4567b0): counter walk loop + 476060 polling === */
    L_67b0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_67ea
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        jns      short L_6806
        call     Thunk_0049cbc0
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_67ea:
        call     DualScaledStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_689e
        mov      dword ptr [g_eventQueueEnd], 0x1f4
    L_6806:
        call     PendingMatch_004568b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_689e
        mov      edi, 0x93
        mov      dword ptr [g_currentNodeIdx], 0
        mov      dword ptr [g_walkCallback], edi
        call     DispatcherComplex138_00476060
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_689e
        mov      bl, 4
    L_683d:
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_6882
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [ecx*4 + 0x54], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      dword ptr [g_walkCallback], edi
        call     DispatcherComplex138_00476060
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       short L_683d
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_6882:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_67b0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_689e:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
