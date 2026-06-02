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

/* ------------------------------------------------------------------ */
/* Throw-grab pose-copy cluster (592b game, 2 packed helpers)          */
/* ------------------------------------------------------------------ */
extern void MStackPushTwoEntryChainCall(void);
extern void MStackPush2ChainLLInsert(void);
extern void func_0047ef70(void);
extern void AerialBlockFsmCluster(void);
extern void func_0047fa30(void);
/* extern void AllocNode(void); -- defined elsewhere with diff sig */
extern unsigned int g_dispatchSave744;
extern unsigned int g_dispatchSave135;

extern unsigned int g_load_0052ab10;
extern void EntryThunkBodyStateMachine(void);
extern void InstallSelfIndirectJmp(void);
extern void MStackPushDispatchBitGate(void);
extern void ScaledIndexConditionalAdd(void);
extern void TripleScaledChainStore(void);

__declspec(naked) void ThrowGrabPoseCopyCluster(void)
{
    __asm {
        /* === Helper 1 (0x47f4e0): grab finalize event === */
        mov      dword ptr [g_eventQueueNotMask], 0
        call     EntryThunkBodyStateMachine
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f529
        push     OFFSET g_dispatchSave744
        call     TripleScaledChainStore
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        test     eax, eax
        jne      short L_f529
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET func_0047ef70
        jmp      InstallSelfIndirectJmp
    L_f529:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2: 0x405 anim w/ source-pose copy === */
        mov      dword ptr [g_walkCallback], 6
        call     ScaledIndexConditionalAdd
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_f72f
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x74], 0x406
        mov      eax, dword ptr [g_table_00535ddc]
        cmp      eax, 0x10000
        mov      dword ptr [g_walkCallback], eax
        jge      short L_f572
        jmp      AerialBlockFsmCluster
    L_f572:
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x405
        mov      dword ptr [g_walkCallback], eax
        mov      edx, OFFSET g_dispatchSave135
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_fightGroupHead]
        shr      edx, 2
        inc      eax
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     MStackPushDispatchBitGate
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_f72f
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      al, byte ptr [g_xformDirtyFlags]
        test     al, 4
        mov      dword ptr [g_fightGroupHead], edx
        je       short L_f5e7
        jmp      AerialBlockFsmCluster
    L_f5e7:
        call     MStackPushTwoEntryChainCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_f72f
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        shl      eax, 2
        shl      ecx, 2
        mov      edx, dword ptr [eax + 0x1c]
        mov      dword ptr [g_xformEntityIdx], edx
        mov      edx, dword ptr [edx*4 + 0x10]
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [edx*4 + 0x34], 0
        mov      edx, 0x73
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x30], edx
        mov      edx, dword ptr [ecx + 0x54]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x54], edx
        mov      edx, dword ptr [ecx + 0x58]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x58], edx
        mov      edx, dword ptr [ecx + 0x5c]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x5c], edx
        mov      edx, dword ptr [ecx + 0x60]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x60], edx
        mov      edx, dword ptr [ecx + 0x64]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x64], edx
        mov      edx, dword ptr [ecx + 0x68]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x68], edx
        mov      edx, dword ptr [ecx + 0x34]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x34], edx
        mov      edx, dword ptr [ecx + 0x24]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x24], edx
        mov      edx, dword ptr [ecx + 0x28]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x28], edx
        mov      edx, dword ptr [ecx + 0x3c]
        mov      dword ptr [eax + 0x3c], edx
        mov      ecx, dword ptr [g_load_0052ab10]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x3c], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_baseSel]
        mov      dword ptr [g_eventQueueEnd], eax
        mov      dword ptr [g_eventQueueWorkType], 0x45
        mov      eax, dword ptr [ecx*4 + 0xc]
        cmp      eax, 1
        mov      dword ptr [g_walkCallback], eax
        je       short L_f6ef
        mov      dword ptr [g_eventQueueWorkType], 0x46
    L_f6ef:
        mov      dword ptr [g_pendingNodeType], OFFSET func_0047fa30
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f72f
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      edx, dword ptr [g_eventQueueEnd]
        test     al, 1
        mov      dword ptr [g_currentNodeIdx], edx
        je       short L_f72a
        call     MStackPush2ChainLLInsert
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_f72f
    L_f72a:
        jmp      AerialBlockFsmCluster
    L_f72f:
        ret
    }
}
