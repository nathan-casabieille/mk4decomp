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
extern void CopyJmp_0048ef90(void);
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
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
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

extern unsigned int g_dispatchSave745_004ed818;
extern void ArgSarStoreJmp(void);
extern void EsiEdiAliasDualMul10(void);
extern void FiveCallGuardSetTail(void);
extern void Install3StateLongSeq(void);
extern void MStackPushSet0008(void);
extern void NotMaskStorePair(void);
extern void PunchAnimCluster(void);
extern void PushCallScaledStore(void);
extern void ScaledChainJmp_004298e0(void);
extern void ScaledIndexConditionalAdd(void);
extern void ScaledZero44(void);
extern void TripleEntryChainGate(void);

__declspec(naked) void HitContactDispatcherCluster(void)
{
    __asm {
        /* === h1 (0x480240): velocity/angle update === */
        mov      eax, dword ptr [g_eventQueueNotMask]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        push     esi
        push     eax
        push     ecx
        call     Mul10Tail
        mov      edx, dword ptr [g_eventQueueChild]
        add      esp, 8
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      eax, dword ptr [g_eventQueueCurrent]
        push     edx
        push     eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_eventQueueChild], eax
        mov      esi, dword ptr [g_eventQueueNotMask]
        add      esp, 8
        mov      edx, dword ptr [ecx*4 + 0x38]
        mov      dword ptr [g_currentNodeIdx], edx
        mov      ecx, dword ptr [edx*4 + 0x54]
        mov      dword ptr [g_walkCallback], ecx
        mov      edx, dword ptr [edx*4 + 0x5c]
        add      edx, eax
        add      ecx, esi
        mov      dword ptr [g_eventQueueCurrent], edx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [edx*4 + 0x54], ecx
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      eax, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_eventQueueCurrent]
        push     eax
        push     eax
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      dword ptr [g_acc_00542078], edx
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      eax, dword ptr [g_acc_00542078]
        push     eax
        push     eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueWorkType]
        add      esp, 8
        add      eax, ecx
        mov      ecx, dword ptr [g_rangeSqLimit]
        cmp      eax, ecx
        mov      dword ptr [g_acc_00542078], eax
        mov      dword ptr [g_eventQueueWorkType], ecx
        jle      short L_036c
        mov      eax, dword ptr [g_baseSel]
        mov      eax, dword ptr [eax*4 + 0x38]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_walkCallback], ecx
        mov      edx, dword ptr [eax*4 + 0x5c]
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_eventQueueCurrent], edx
        mov      dword ptr [eax*4 + 0x54], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [edx*4 + 0x5c], ecx
    L_036c:
        call     ScaledChainJmp_004298e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_03af
        mov      dword ptr [g_walkCallback], 0xffffd99a
        call     MStackFrameCdeclDouble
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_03af
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_baseSel], ecx
        mov      dword ptr [g_matrixStackTop], eax
        call     ScaledZero44
    L_03af:
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
        nop
        nop
        /* === h2 (0x4803c0): event 004ed818 forwarder w/ 0x20a === */
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x20a
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        call     PushCallScaledStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_03f2
        push     OFFSET g_dispatchSave745_004ed818
        call     ArgSarStoreJmp
        add      esp, 4
    L_03f2:
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
        /* === h3 (0x480400): pose-fn 2-state hit-contact === */
    L_0400:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        mov      edi, 1
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_0537
        dec      eax
        je       short L_0454
        mov      dword ptr [g_walkCallback], 8
        call     ScaledIndexConditionalAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0567
        call     FiveCallGuardSetTail
        pop      edi
        pop      esi
        ret
    L_0454:
        mov      eax, dword ptr [g_table_00535ddc]
        cmp      eax, 0x10000
        mov      dword ptr [g_walkCallback], eax
        jge      short L_046d
        call     Install3StateLongSeq
        pop      edi
        pop      esi
        ret
    L_046d:
        call     TripleEntryChainGate
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0567
        mov      dword ptr [g_walkCallback], 0x9999
        call     EsiEdiAliasDualMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0567
        mov      dword ptr [g_xformScratch2088], 0x10000
        call     PunchAnimCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0567
        call     NotMaskStorePair
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_0567
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      edx, dword ptr [g_player1NodeIdx]
        mov      eax, edi
        cmp      ecx, edx
        mov      dword ptr [g_eventQueueWorkType], eax
        je       short L_04ea
        mov      eax, 0x10
        mov      dword ptr [g_eventQueueWorkType], eax
    L_04ea:
        and      eax, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [g_xformScratch94], eax
        jne      short L_054e
        call     ScaledZeroFour
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_0567
        call     MStackPushSet0008
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_0567
        mov      dword ptr [esi + 8], OFFSET L_0400
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0xc
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        ret
    L_0537:
        mov      edx, dword ptr [g_baseSel]
        mov      eax, 0x28
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x68], eax
    L_054e:
        mov      dword ptr [esi + 8], OFFSET L_0400
        mov      dword ptr [esi + 0x84], edi
        mov      dword ptr [g_pendingNodeType], edi
        mov      dword ptr [g_framePauseFlag], edi
    L_0567:
        pop      edi
        pop      esi
        ret
    }
}
