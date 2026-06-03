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

extern void PushCallPauseSetMaxThenCallPauseJmp(void);
extern void HandWalkCluster(void);
extern void MoveCommitPackedDispatcher(void);
extern void PushPopCurrentSetFFFFFFFF(void);
extern void TripleStringPauseChain(void);
extern void PoseStateInitNode(void);

/* @addr 0x0043cc10 (326b game) - dual-block: state-0 chain-init + state-1 body.
 *   state==0: if g_tickFlagF==2: set byte g_byte_00538148=1. g_audioStreamState=g_walkCallback.
 *     Call CallPauseScaledStoreCopyJmp; if pause ret. Call PushCallPauseSetMaxThenCallPauseJmp; if pause ret.
 *     g_eventQueueIdx=g_cj; push 0x90, push body addr; g_eventQueueEnd=[baseSel*4+0x38]; call StoreTwoCall.
 *     Install-self at entry; state=1; g_pendingNodeType=0x64; pause=1; pop+ret. 15-NOP pad.
 *   Body (+0xc0): chain[baseSel*4+0x64]=g_eventQueueEnd; chain[baseSel*4+0x68]=g_eventQueueIdx.
 *     Call HandWalkCluster; if pause ret. Call MoveCommitPackedDispatcher; if pause ret.
 *     g_cj=g_eventQueueEnd. Call MoveCommitPackedDispatcher; if pause ret.
 *     g_walkCallback=0x80. Call PushPopCurrentSetFFFFFFFF; if pause ret.
 *     Call TripleStringPauseChain; if pause ret. Tail-jmp PoseStateInitNode.
 */
extern unsigned int g_tickFlagF;
extern unsigned int g_byte_00538148;
extern unsigned int g_audioStreamState;
extern void CallPauseScaledStoreCopyJmp(void);

__declspec(naked) void DualBlockChainInitBody(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   75h
        _emit   68h
        cmp     dword ptr [g_tickFlagF], 2
        _emit   75h
        _emit   07h
        mov     byte ptr [g_byte_00538148], 1
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [g_audioStreamState], ecx
        call    CallPauseScaledStoreCopyJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   63h
        call    PushCallPauseSetMaxThenCallPauseJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   55h
        mov     edx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [g_eventQueueIdx], edx
        push    0x90
        mov     ecx, dword ptr [eax*4 + 0x38]
        push    offset body_cd0
        mov     dword ptr [g_eventQueueEnd], ecx
        call    StoreTwoCall
        add     esp, 8
        mov     dword ptr [esi + 8], offset DualBlockChainInitBody
        mov     dword ptr [esi + 0x84], 1
        mov     dword ptr [g_pendingNodeType], 0x64
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
    body_cd0:
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [eax*4 + 0x64], ecx
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     dword ptr [edx*4 + 0x68], eax
        call    HandWalkCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   53h
        call    MoveCommitPackedDispatcher
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   45h
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_cj_0054205c], ecx
        call    MoveCommitPackedDispatcher
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2bh
        mov     dword ptr [g_walkCallback], 0x80
        call    PushPopCurrentSetFFFFFFFF
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    TripleStringPauseChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     PoseStateInitNode
        ret
    }
}
