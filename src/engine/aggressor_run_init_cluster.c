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

extern unsigned int g_dispatchSave746_004ed988;
extern unsigned int g_dispatchSave774_004ef228;
extern unsigned int g_dispatchSave775_004ef258;
extern unsigned int g_dispatchSave776_004ef278;
extern unsigned int g_dispatchSave777_004ef2b8;
extern unsigned int g_load_0052ab10;
extern unsigned int g_dispatchSave_00537ef4;
extern unsigned int g_dispatchSave70_00542be8;
extern void ArgSarStoreJmp(void);
extern void BlockedCounterCluster_004816d0(void);
extern void BossArrivalSequence_00481950(void);
extern void CjDispatchCommit_004818e0(void);
extern void DualScaledStore(void);
extern void MStackDualDiffSequencer(void);
extern void PendingMatch_00455bd0(void);
extern void Push267_Push44eb60_Jmp_00489220(void);
extern void ScaledInitWithCounterAndType_004314f0(void);
extern void ScaledXorStore_004903b0(void);
extern void StoreLoadJmp(void);
extern void TripleEntryCountdownInstall_0046a230(void);

__declspec(naked) void AggressorRunInitCluster_004813b0(void)
{
    __asm {
        /* === h1 (0x4813b0): event 004ed988 forwarder === */
        push     OFFSET g_dispatchSave746_004ed988
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        nop
        nop
        /* === h2 (0x4813c0): timer + angle/dist init → tail 4314f0 === */
        call     ScaledXorStore_004903b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1475
        mov      eax, 0x258
        push     OFFSET g_dispatchSave70_00542be8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_dispatchSave_00537ef4], eax
        call     IterLoad_00491050
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_1475
        mov      ecx, dword ptr [g_load_0052ab10]
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x58]
        add      eax, 0x18000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_eventQueueCurrent], 0x3333
        add      ecx, 0x15
        mov      dword ptr [g_eventQueueWorkType], 0x41
        mov      dword ptr [g_xformEntityIdx], ecx
        call     MStackDualDiffSequencer
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1475
        mov      ecx, dword ptr [g_load_0052ab10]
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      eax, dword ptr [ecx*4 + 0x58]
        sub      eax, 0x18000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        jmp      ScaledInitWithCounterAndType_004314f0
    L_1475:
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
        /* === h3 (0x481480): pose-fn install state 1 w/ 489220 === */
    L_1480:
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       short L_149f
        jmp      ScaledInitWithCounterAndType_004314f0
    L_149f:
        mov      ecx, dword ptr [g_fightGroupHead]
        push     edi
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      ecx, dword ptr [g_baseSel]
        mov      edi, OFFSET L_1480
        mov      ecx, dword ptr [ecx*4 + 0x38]
        add      edi, 0x1000000
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      dword ptr [eax + 8], OFFSET L_1480
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     Push267_Push44eb60_Jmp_00489220
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
        nop
        /* === h4 (0x481500): event 004ef228 w/ push PendingMatch_00455bd0+0x80 === */
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueEnd], eax
        call     DualScaledStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_1561
        mov      eax, dword ptr [g_eventQueueEnd]
        push     OFFSET PendingMatch_00455bd0 + 0x80
        mov      dword ptr [g_fightGroupHead], eax
        mov      dword ptr [g_eventQueueIdx], eax
        call     StoreLoadJmp
        add      esp, 4
        push     OFFSET g_dispatchSave774_004ef228
        call     ArgSarStoreJmp
        add      esp, 4
    L_1561:
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
        /* === h5 (0x481560): timer install + event 004ef258 === */
        push     0x26
        push     OFFSET TripleEntryCountdownInstall_0046a230 + 0xb0
        call     StoreTwoCall
        add      esp, 8
        push     OFFSET g_dispatchSave775_004ef258
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        nop
        nop
        nop
        /* === h6 (0x481590): pose-fn state-1 install w/ 004816d0 + event === */
    L_1590:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_15cd
        call     BlockedCounterCluster_004816d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_15ef
        push     OFFSET g_dispatchSave776_004ef278
        call     ArgSarStoreJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret
    L_15cd:
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_1590
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0x1c
        mov      dword ptr [g_framePauseFlag], ecx
    L_15ef:
        ret
        /* === h7 (0x4815f0): pose-fn 2-state w/ 0048e1e0/004ef2b8 === */
    L_15f0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_1638
        call     CjDispatchCommit_004818e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_16c4
        push     OFFSET g_dispatchSave777_004ef2b8
        call     ArgSarStoreJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret
    L_1638:
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [eax*4 + 0x6c]
        mov      dword ptr [g_currentNodeFlags], ecx
        mov      edx, dword ptr [eax*4 + 0x74]
        mov      dword ptr [g_xformScratch2088], edx
        call     ScaledZeroFour
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_16c4
        mov      dword ptr [esi + 8], OFFSET L_15f0
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_15f0
        mov      dword ptr [eax*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 0
        call     BossArrivalSequence_00481950
        mov      dword ptr [g_framePauseFlag], 1
    L_16c4:
        pop      esi
        ret
    }
}
