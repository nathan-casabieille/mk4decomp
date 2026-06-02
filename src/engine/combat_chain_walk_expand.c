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

extern unsigned int g_dispatchSave138_0050a49c;
extern unsigned int g_dispatchSave132_0050cab0;
extern unsigned int g_dispatchSave131_0050cb3c;
extern unsigned int g_dispatchSave123_005108dc;
extern unsigned int g_load_0052ab10;
extern unsigned int g_dispatchArg;
extern unsigned int g_dispatchSave32_00542a08;
extern void DirtyDoubleDeref(void);
extern void InstallSelfDispatch_00407620(void);
extern void MStackBracket4_ListInsertZeroFill(void);
extern void MStackCall_00406340(void);
extern void MStackPush3LinkedListWalk(void);
extern void MStackPush4LLWalkPop4_004090e0(void);

__declspec(naked) void CombatChainWalkExpand_00463870(void)
{
    __asm {
        mov      eax, dword ptr [g_pendingNodeType]
        mov      edx, OFFSET g_dispatchSave131_0050cb3c
        push     ebx
        push     ebp
        mov      ecx, dword ptr [eax*4 + 0xc]
        push     edi
        shr      edx, 2
        mov      dword ptr [g_eventQueueTotal], ecx
        mov      dword ptr [g_eventQueueNotMask], 0
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3c6e
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_3c6e
        mov      eax, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 4]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [edx*4 + 0x58], eax
        mov      ecx, dword ptr [g_pendingNodeType]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 8]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [edx*4 + 0x5c], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_pendingNodeType]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_load_0052ab10]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [edx*4 + 0x3c], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [edx*4 + 0x40], 0
        call     MStackCall_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3c6e
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edi, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [g_fightGroupHead], eax
        mov      eax, dword ptr [g_eventQueueTotal]
        sub      edi, 0x6978
        inc      eax
        mov      dword ptr [g_eventQueueNotMask], edi
        mov      ecx, dword ptr [eax*4 - 4]
        test     ecx, ecx
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      dword ptr [g_eventQueueTotal], eax
        je       L_3c4f
        mov      ebx, OFFSET g_dispatchSave132_0050cab0
        mov      ebp, 1
        shr      ebx, 2
        mov      edi, 0x4baf40
    L_39cd:
        mov      dword ptr [g_xformEntityIdx], ebx
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3c6e
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_3c6e
        call     MStackBracket4_ListInsertZeroFill
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3c6e
        call     MStackPush3LinkedListWalk
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3c6e
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_pendingNodeType]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_load_0052ab10]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      eax, OFFSET g_dispatchSave123_005108dc
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      edx, dword ptr [eax*4]
        mov      eax, dword ptr [g_currentNodeIdx]
        sar      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     InstallSelfDispatch_00407620
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3c6e
        mov      edx, OFFSET g_dispatchSave138_0050a49c
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        call     MStackPush4LLWalkPop4_004090e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3c6e
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [ecx*4 + 4]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [edx*4 + 0x54], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueNotMask]
        mov      dword ptr [eax*4 + 0x58], ecx
        mov      edx, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 8]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [edx*4 + 0x40], eax
        call     MStackCall_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3c6e
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [g_fightGroupHead], ecx
        mov      ecx, OFFSET g_dispatchSave32_00542a08
        shr      ecx, 2
        mov      dword ptr [g_walkCallback], ebp
        mov      dword ptr [g_eventQueueCurrent], 0xff
        mov      dword ptr [g_eventQueueEnd], ecx
        jmp      L_3b89
    L_3b83:
        mov      ecx, dword ptr [g_eventQueueEnd]
    L_3b89:
        and      eax, dword ptr [g_eventQueueCurrent]
        cmp      eax, 0x10
        mov      dword ptr [g_dispatchArg], eax
        ja       L_3c6e
        add      ecx, eax
        mov      edx, dword ptr [ecx*4]
        mov      dword ptr [g_acc_00542078], edx
        call     DirtyDoubleDeref
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_3c6e
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_acc_00542078]
        mov      dword ptr [eax*4 + 0x24], ecx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x28]
        mov      dword ptr [eax*4 + 0x10], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      edx, dword ptr [ecx*4 + 0x28]
        mov      dword ptr [edx*4 + 0x14], eax
        mov      eax, dword ptr [g_eventQueueWorkType]
        mov      ecx, dword ptr [g_walkCallback]
        sar      eax, 8
        inc      ecx
        mov      dword ptr [g_eventQueueWorkType], eax
        cmp      ecx, 4
        mov      dword ptr [g_walkCallback], ecx
        jbe      L_3b83
        mov      eax, dword ptr [g_eventQueueNotMask]
        sub      eax, 0x6978
        mov      dword ptr [g_eventQueueNotMask], eax
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      ecx, dword ptr [eax*4]
        inc      eax
        test     ecx, ecx
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      dword ptr [g_eventQueueTotal], eax
        jne      L_39cd
    L_3c4f:
        mov      ecx, dword ptr [g_pendingNodeType]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      eax, dword ptr [ecx*4]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x30], eax
    L_3c6e:
        pop      edi
        pop      ebp
        pop      ebx
        ret      
    }
}
