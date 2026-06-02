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

extern unsigned int g_dispatchSave645_004eefd8;
extern unsigned int g_dispatchSave644_004ef010;
extern unsigned int g_dispatchTableArr6_00500710;
extern void ArgSarStoreJmp(void);
extern void CinematicCFsmCluster_004884a0(void);
extern void FlagThunk4EntryDispatcher(void);
extern void IncThunkPlusCjDispatch_00483b80(void);
extern void InstallSelfIndirectJmpNeg(void);
extern void InstallSelfIndirectJmp(void);
extern void InstallSelfOrCmpJmp_0048f570(void);
extern void TableLookupCall_00489ff0(void);

__declspec(naked) void BossRoarCluster_00488210(void)
{
    __asm {
        /* === Helper 1 (0x488210): set 0x83 + push 488250 continuation === */
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0x83
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET L_8250
        jmp      InstallSelfIndirectJmpNeg
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
        /* === Helper 2 (0x488250): 3-state FSM === */
    L_8250:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       short L_8340
        dec      eax
        je       short L_82ab
        dec      eax
        je       short L_8284
        call     StackPopDispatchTagged
        pop      esi
        ret
    L_8284:
        mov      dword ptr [esi + 8], OFFSET L_8250
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_82ab:
        mov      dword ptr [g_walkCallback], 0x40
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8361
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0xffffff7d
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      dword ptr [esi + 8], OFFSET L_8250
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_8250
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelfOrCmpJmp_0048f570
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_8340:
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_8250
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], eax
    L_8361:
        pop      esi
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
        /* === Helper 3 (0x488370): callback continuation === */
    L_8370:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_83be
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0xf5c
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET L_8410
        jmp      InstallSelfIndirectJmp
    L_83be:
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, 0xffffee15
        mov      dword ptr [edx*4 + 0x74], 0x1002
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [edx*4 + 0x4c], ecx
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_8370
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 4
        mov      dword ptr [g_framePauseFlag], ecx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 4 (0x488410): event 004eefd8 forwarder === */
    L_8410:
        mov      eax, OFFSET g_dispatchTableArr6_00500710
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        call     ScaledArrStore_004298c0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8446
        call     IncThunkPlusCjDispatch_00483b80
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8446
        push     OFFSET g_dispatchSave645_004eefd8
        call     ArgSarStoreJmp
        add      esp, 4
    L_8446:
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
        /* === Helper 5: event 004ef010 forwarder === */
        push     OFFSET g_dispatchSave644_004ef010
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        nop
        nop
        /* === Helper 6: 0xf event + jmp 004884a0 === */
        mov      dword ptr [g_walkCallback], 0xf
        call     FlagThunk4EntryDispatcher
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_847d
        jmp      CinematicCFsmCluster_004884a0
    L_847d:
        ret
        nop
        nop
        /* === Helper 7: 9 event + jmp 004884a0 === */
        mov      dword ptr [g_walkCallback], 9
        call     FlagThunk4EntryDispatcher
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_849d
        jmp      CinematicCFsmCluster_004884a0
    L_849d:
        ret
    }
}
