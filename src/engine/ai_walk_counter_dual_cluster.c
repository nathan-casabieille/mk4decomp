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

extern unsigned int g_loaded;
extern unsigned int g_dispatchClr0;
extern unsigned int g_player1State;
extern unsigned int g_player2State;
extern void CallSetPause(void);
extern void DualPushSetCallDualPop(void);
extern void MStackPush2ChainLLInsert(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void MultiGateDispatchCallJmp(void);
extern void SaveCallRestoreOrXor(void);
extern void ScaledLoadGuardedJmp(void);
extern void SwapOrPassSet(void);

__declspec(naked) void AiWalkCounterDualCluster(void)
{
    __asm {
        /* === h1 (0x477e20): mstack lookup + counter inc === */
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     SwapOrPassSet
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7eda
        mov      edx, dword ptr [g_walkCallback]
        mov      eax, dword ptr [g_loaded]
        cmp      edx, eax
        jne      short L_7ec2
        mov      eax, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [g_player1NodeIdx]
        cmp      eax, ecx
        jne      short L_7e7d
        mov      eax, dword ptr [g_active_0053a408]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_7ec2
        mov      ecx, OFFSET g_player1State
        jmp      short L_7e90
    L_7e7d:
        mov      eax, dword ptr [g_active_00537e88]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_7ec2
        mov      ecx, OFFSET g_player2State
    L_7e90:
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      eax, dword ptr [ecx*4]
        inc      eax
        cmp      eax, 0x3e7
        mov      dword ptr [g_walkCallback], eax
        jae      short L_7ec2
        mov      dword ptr [ecx*4], eax
        call     MultiGateDispatchCallJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7eda
    L_7ec2:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_7eda:
        ret
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x477ee0): pose-fn 2-state dispatch === */
    L_7ee0:
        mov      eax, dword ptr [g_baseSel]
        push     ebp
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_80c4
        dec      eax
        mov      eax, dword ptr [g_dispatchClr0]
        mov      dword ptr [g_walkCallback], eax
        je       L_8005
        cmp      eax, edi
        jne      L_7fee
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      ebp, 4
        mov      dword ptr [g_currentNodeIdx], eax
        or       edx, ebp
        cmp      eax, edi
        mov      dword ptr [g_xformDirtyFlags], edx
        je       short L_7f5e
        mov      ecx, edx
        xor      ecx, ebp
        cmp      eax, edi
        mov      dword ptr [g_xformDirtyFlags], ecx
        je       short L_7f5e
        call     MStackPushComplexCallPop_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_8119
    L_7f5e:
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      eax, dword ptr [g_eventQueueIdx]
        or       edx, ebp
        cmp      eax, edi
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       L_80c4
        mov      ecx, edx
        xor      ecx, ebp
        cmp      eax, edi
        mov      dword ptr [g_xformDirtyFlags], ecx
        je       L_80c4
        call     MStackPushComplexCallPop_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_8119
        push     0x90
        call     DualPushSetCallDualPop
        mov      al, byte ptr [g_xformDirtyFlags]
        add      esp, 4
        test     al, 1
        je       L_80c4
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackPush2ChainLLInsert
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_8119
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_currentNodeIdx], edx
        call     MStackPush2ChainLLInsert
        jmp      L_80b3
    L_7fee:
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [eax*4 + 0xc], edi
        jmp      L_80ae
    L_8005:
        cmp      eax, edi
        jne      L_809b
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      ebp, 4
        mov      dword ptr [g_currentNodeIdx], eax
        or       edx, ebp
        cmp      eax, edi
        mov      dword ptr [g_xformDirtyFlags], edx
        je       short L_804d
        mov      ecx, edx
        xor      ecx, ebp
        cmp      eax, edi
        mov      dword ptr [g_xformDirtyFlags], ecx
        je       short L_804d
        call     ScaledLoadGuardedJmp
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_8119
    L_804d:
        mov      edx, dword ptr [g_xformDirtyFlags]
        mov      eax, dword ptr [g_eventQueueIdx]
        or       edx, ebp
        cmp      eax, edi
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformDirtyFlags], edx
        je       short L_8088
        mov      ecx, edx
        xor      ecx, ebp
        cmp      eax, edi
        mov      dword ptr [g_xformDirtyFlags], ecx
        je       short L_8088
        call     ScaledLoadGuardedJmp
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_8119
    L_8088:
        mov      dword ptr [esi + 8], OFFSET L_7ee0
        mov      dword ptr [esi + 0x84], 2
        jmp      short L_8105
    L_809b:
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], edi
        mov      dword ptr [ecx*4 + 0xc], edi
    L_80ae:
        call     MultiGateDispatchCallJmp
    L_80b3:
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_8119
        call     CallSetPause
        pop      edi
        pop      esi
        pop      ebp
        ret
    L_80c4:
        push     0x232
        call     SaveCallRestoreOrXor
        mov      edx, dword ptr [g_currentNodeIdx]
        add      esp, 4
        mov      dword ptr [g_eventQueueEnd], edx
        push     0x233
        call     SaveCallRestoreOrXor
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 4
        mov      dword ptr [g_eventQueueIdx], eax
        mov      dword ptr [esi + 8], OFFSET L_7ee0
        mov      dword ptr [esi + 0x84], 1
    L_8105:
        mov      dword ptr [g_pendingNodeType], 0xa
        mov      dword ptr [g_framePauseFlag], 1
    L_8119:
        pop      edi
        pop      esi
        pop      ebp
        ret
    }
}
