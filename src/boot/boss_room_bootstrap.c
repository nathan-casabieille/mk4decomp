/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
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
/* Boss-room init cluster (640b game, 3 packed helpers)                */
/* Cross-references jump table inside sibling stub BossRoomBootstrap.      */
/* ------------------------------------------------------------------ */
extern void ScaledChainOr8(void);
extern void Copy3Fields3c4044(void);
extern void PushSetXfmMaskCallPop(void);
extern void MStackPush2RunCountdown(void);
extern void BossRoomBootstrap(void);
extern void func_0041062b(void);
extern void func_00410725(void);
extern void func_0041076b(void);
extern void func_004107b4(void);
extern void MStackBracket7_DispatchAndChain(void);
extern unsigned int g_dispatchSave902;
extern unsigned int g_dispatchSave903;
extern unsigned int g_dispatchSave915;
extern unsigned int g_dispatchSave880;
extern void MStackCall_MStackPush2ChainPrepend_004062f0(void);
extern void TableLookupCall_g_eventTbl_112(void);

__declspec(naked) void BossRoomInitCluster(void)
{
    __asm {
        /* === Helper 1 (0x410340): pack-hi16 into 004d5814[0] === */
    L_0340:
        mov      edx, dword ptr [g_walkCallback]
        mov      eax, OFFSET g_dispatchSave903
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        mov      ecx, dword ptr [eax*4]
        shl      edx, 0x10
        and      ecx, 0xffff
        mov      dword ptr [g_walkCallback], edx
        or       ecx, edx
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      dword ptr [eax*4], ecx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2 (0x410370): event-0 push trampoline === */
        push     0
        push     OFFSET L_0390
        call     StoreTwoCall
        add      esp, 8
        ret
        /* === Helper 3 (0x410390): main 5-case dispatcher === */
    L_0390:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      ebx, 4
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, ebx
        ja       func_0041076b
        jmp      dword ptr [eax*4 + g_dispatchSave880]
        mov      eax, dword ptr [g_eventQueueEnd]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        jns      func_00410725
        call     MStackPush2RunCountdown
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_004107b4
        call     MStackBracket7_DispatchAndChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_004107b4
        mov      dword ptr [g_walkCallback], 0xa
        call     ChainDirtyBitWalker
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_004107b4
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_04e1
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      edx, dword ptr [g_fightGroupHead]
        inc      eax
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, OFFSET g_dispatchSave915
        shr      eax, 2
        mov      dword ptr [g_walkCallback], eax
        call     PushSetXfmMaskCallPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_004107b4
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_04ae
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0x9a
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        call     Copy3Fields3c4044
        call     ScaledChainOr8
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      eax, 0x14ccc
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x48], eax
        call     MStackCall_MStackPush2ChainPrepend_004062f0
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_004107b4
    L_04ae:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_fightGroupHead], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [g_walkCallback], 0x19
        call     TableLookupCall_g_eventTbl_112
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_004107b4
    L_04e1:
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, 0xfd70
        mov      eax, dword ptr [edx*4 + 0x3c]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueEnd], eax
        mov      dword ptr [eax*4 + 0x3c], ecx
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [eax*4 + 0x20]
        mov      dword ptr [eax*4 + 0x38], 0xffff0000
        mov      dword ptr [g_eventQueueNotMask], 3
        jmp      BossRoomBootstrap
        mov      eax, OFFSET g_dispatchSave902
        mov      dword ptr [g_walkCallback], 0x707070
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], 0x707070
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      edx, dword ptr [ecx*4]
        mov      dword ptr [g_walkCallback], edx
        call     L_0340
        cmp      dword ptr [g_framePauseFlag], edi
        jne      func_004107b4
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      eax, 0x10000
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      dword ptr [esi + 8], OFFSET L_0390
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 2
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
        mov      eax, dword ptr [g_eventQueueNotMask]
        dec      eax
        cmp      eax, edi
        mov      dword ptr [g_eventQueueNotMask], eax
        /* force short jle to in-sibling-stub target (orig: 7e 6b) */
        _emit    0x7e
        _emit    0x6b
    }
}
