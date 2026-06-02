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
extern void GuardedDispatch_InstallSelfDualEsi(void);
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

extern void DualScaledStore(void);
extern void EntryThunkBodyStateMachine(void);
extern void GatedWordPushCall(void);
extern void GuardedSeq_DualPushCmp12Dispatch_then_ByteWordTableTaggedDispatch(void);
extern void GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7d(void);
extern void MStackPush4ChainCopyPop4(void);
extern void ScaledLoadTwoCallLit_MStackPush2RunCountdown_then_MStackBracket7_DispatchAndChain_then_StunDownCluster_00451f70(void);
extern void Set2CallIncJmp(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void JuggleFsmCluster(void)
{
    __asm {
        mov      dword ptr [g_acc_00542078], 0xb
        jmp      GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7d
        nop
    L_1ba0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        cmp      eax, 8
        ja       L_1ed3
        jmp      dword ptr [eax*4 + L_jmptbl]
    L_1bce:
        mov      dword ptr [g_walkCallback], 0x35
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [g_walkCallback], 0x2b
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x12
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1c2d:
        mov      dword ptr [g_walkCallback], 0x36
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x12
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1c70:
        mov      dword ptr [g_walkCallback], 0x37
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [g_walkCallback], 0x2a
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], 0x11
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1ccf:
        mov      dword ptr [g_walkCallback], 0x36
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 5
        mov      dword ptr [g_pendingNodeType], 0x5f
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1d12:
        mov      dword ptr [g_walkCallback], 8
        call     GuardedSeq_DualPushCmp12Dispatch_then_ByteWordTableTaggedDispatch
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 6
        mov      dword ptr [g_pendingNodeType], 0xf
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1d55:
        mov      dword ptr [g_walkCallback], 0x37
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 7
        mov      dword ptr [g_pendingNodeType], 4
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1d98:
        call     MStackPush4ChainCopyPop4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        call     Set2CallIncJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        call     ScaledLoadTwoCallLit_MStackPush2RunCountdown_then_MStackBracket7_DispatchAndChain_then_StunDownCluster_00451f70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [g_eventQueueNotMask], 5
        call     EntryThunkBodyStateMachine
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 8
        mov      dword ptr [g_pendingNodeType], 0x1b
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1e11:
        call     MStackPush4ChainCopyPop4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        call     Set2CallIncJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        call     ScaledLoadTwoCallLit_MStackPush2RunCountdown_then_MStackBracket7_DispatchAndChain_then_StunDownCluster_00451f70
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [g_eventQueueNotMask], 7
        call     EntryThunkBodyStateMachine
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], 9
        mov      dword ptr [g_pendingNodeType], 7
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_1e8a:
        call     DualScaledStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      dword ptr [g_eventQueueNotMask], 6
        call     EntryThunkBodyStateMachine
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_1ba0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x55
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_1ed3:
        mov      dword ptr [g_walkCallback], 0x12
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_1ef0
        call     Thunk_ScaledNeg1SetPause
    L_1ef0:
        pop      esi
        ret
        _emit 0x8b
        _emit 0xff
    L_jmptbl:
        _emit 0x8a
        _emit 0x1e
        _emit 0x45
        _emit 0x00
        _emit 0xce
        _emit 0x1b
        _emit 0x45
        _emit 0x00
        _emit 0x2d
        _emit 0x1c
        _emit 0x45
        _emit 0x00
        _emit 0x70
        _emit 0x1c
        _emit 0x45
        _emit 0x00
        _emit 0xcf
        _emit 0x1c
        _emit 0x45
        _emit 0x00
        _emit 0x12
        _emit 0x1d
        _emit 0x45
        _emit 0x00
        _emit 0x55
        _emit 0x1d
        _emit 0x45
        _emit 0x00
        _emit 0x98
        _emit 0x1d
        _emit 0x45
        _emit 0x00
        _emit 0x11
        _emit 0x1e
        _emit 0x45
        _emit 0x00
    }
}
