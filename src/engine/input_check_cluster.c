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

/* ------------------------------------------------------------------ */
/* Scripted-event packet decoder (582b game)                           */
/* Consumes a (op,arg)-stream from [g_currentNodeIdx] and dispatches    */
/* event-IDs 0xdd, 0xaa plus collision/state-flag checks.              */
/* ------------------------------------------------------------------ */
extern void ConditionalAcc4or3(void);
extern void ConditionalAcc3or4(void);
extern void Event_InvokeHandler(void);
extern void IncJmp(void);
extern void EventGateCluster(void);


__declspec(naked) void EventPacketDecoder(void)
{
    __asm {
        push     ebx
        push     esi
        push     edi
        mov      edi, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [edi*4]
        inc      edi
        test     edx, edx
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [g_currentNodeIdx], edi
        je       L_e084
        mov      eax, dword ptr [edi*4]
        inc      edi
        cmp      edx, -1
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_currentNodeIdx], edi
        je       L_dfc9
        mov      eax, edx
        xor      ecx, ecx
        shr      eax, 8
        mov      dword ptr [g_eventQueueWorkType], eax
        je       short L_deba
    L_deaf:
        inc      ecx
        shr      eax, 8
        jne      short L_deaf
        mov      dword ptr [g_eventQueueWorkType], eax
    L_deba:
        mov      esi, dword ptr [g_eventQueueTotal]
        mov      eax, dword ptr [g_eventQueueEnd]
        add      esi, ecx
        dec      eax
        mov      dword ptr [g_eventQueueTotal], esi
        mov      dword ptr [g_eventQueueEnd], eax
    L_ded3:
        mov      edi, dword ptr [g_eventQueueEnd]
        mov      eax, edx
        and      eax, 0xff
        inc      edi
        cmp      eax, 0xdd
        mov      dword ptr [g_eventQueueEnd], edi
        mov      dword ptr [g_acc_00542078], eax
        jne      short L_df10
        call     ConditionalAcc4or3
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e0a2
        mov      edx, dword ptr [g_walkCallback]
        mov      eax, dword ptr [g_acc_00542078]
    L_df10:
        cmp      eax, 0xaa
        jne      short L_df34
        call     ConditionalAcc3or4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e0a2
        mov      edx, dword ptr [g_walkCallback]
        mov      eax, dword ptr [g_acc_00542078]
    L_df34:
        mov      esi, dword ptr [g_eventQueueTotal]
        mov      ecx, dword ptr [esi*4]
        dec      esi
        cmp      eax, ecx
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      dword ptr [g_eventQueueTotal], esi
        jne      short L_dfc0
        shr      edx, 8
        mov      dword ptr [g_walkCallback], edx
        jne      L_ded3
        mov      edi, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edi*4]
        shr      eax, 0x10
        mov      dword ptr [g_eventQueueCurrent], eax
        and      eax, 0x40
        mov      dword ptr [g_xformScratch94], eax
        jne      short L_dfc9
        mov      esi, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [g_player1NodeIdx]
        mov      ecx, 0x20
        cmp      esi, eax
        mov      dword ptr [g_eventQueueCurrent], ecx
        je       short L_dfa5
        mov      ecx, 0x2000
        mov      dword ptr [g_eventQueueCurrent], ecx
    L_dfa5:
        mov      eax, dword ptr [g_fightTableC0]
        not      eax
        and      eax, 0xffff
        and      ecx, eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_xformScratch94], ecx
        je       short L_dfcf
    L_dfc0:
        call     IncJmp
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_dfc9:
        mov      esi, dword ptr [g_fightGroupHead]
    L_dfcf:
        mov      ebx, dword ptr [edi*4]
        xor      ecx, ecx
        mov      cl, bh
        inc      edi
        test     ecx, ecx
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_currentNodeIdx], edi
        mov      dword ptr [g_eventQueueCurrent], ecx
        je       short L_e014
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [g_gtFightTickCounter]
        mov      edx, dword ptr [edx*4]
        sub      eax, edx
        mov      dword ptr [g_eventQueueWorkType], edx
        cmp      eax, ecx
        mov      dword ptr [g_acc_00542078], eax
        jg       short L_e084
    L_e014:
        mov      eax, ebx
        shr      eax, 0x10
        and      eax, 0x10
        mov      dword ptr [g_eventQueueCurrent], eax
        jne      short L_e061
        mov      eax, dword ptr [esi*4 + 0x40]
        mov      dword ptr [g_eventQueueWorkType], eax
        and      eax, 0x200
        mov      dword ptr [g_xformScratch94], eax
        jne      short L_e061
        mov      eax, dword ptr [esi*4 + 0x48]
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      ecx, dword ptr [esi*4 + 0x58]
        cmp      ecx, eax
        mov      dword ptr [g_acc_00542078], ecx
        je       short L_e061
        call     EventGateCluster
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_e061:
        mov      eax, dword ptr [esi*4 + 0x40]
        mov      ecx, eax
        mov      dword ptr [g_eventQueueWorkType], eax
        and      ecx, 1
        mov      dword ptr [g_xformScratch94], ecx
        jne      short L_e084
        and      eax, 4
        mov      dword ptr [g_xformScratch94], eax
        je       short L_e092
    L_e084:
        mov      dword ptr [g_walkCallback], 0
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_e092:
        shr      ebx, 0x18
        mov      dword ptr [g_eventQueueCurrent], ebx
        je       short L_e0a2
        call     Event_InvokeHandler
    L_e0a2:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
