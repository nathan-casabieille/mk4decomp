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

extern void AudioVolumeRescale(void);
extern void DualScaledLoadStoreJmp(void);
extern void GuardedSeq_ScaledLoadTwoCallDualConst_then_GuardedSeq_00467c10(void);
extern void GuardedSeq_GuardedTripleCallSetTail_then_GuardedSeq(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void PreFightInstallCluster(void);
extern void PushSetXfmMaskCallPop(void);
extern void SetJmp_ZeroAndDirty4(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void IntroComboFsmCluster(void)
{
    __asm {
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_78a1
        test     byte ptr [g_xformDirtyFlags], 4
        jne      L_78a1
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x91
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        call     MStackCall_MStackPush2ChainPrepend_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_78a1
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x3c]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x54], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x40]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x44]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
    L_78a1:
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
    L_78b0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_797e
        dec      eax
        mov      eax, dword ptr [g_eventQueueEnd]
        je       L_78f0
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        jns      L_7906
        call     Thunk_ScaledNeg1SetPause
        pop      esi
        pop      ebx
        ret      
    L_78f0:
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        jns      L_7a0b
        mov      dword ptr [g_eventQueueEnd], 0xf
    L_7906:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueEnd]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     GuardedSeq_ScaledLoadTwoCallDualConst_then_GuardedSeq_00467c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7aac
        call     GuardedSeq_GuardedTripleCallSetTail_then_GuardedSeq
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7aac
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, 2
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [esi + 8], OFFSET L_78b0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        pop      ebx
        ret      
    L_797e:
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [ecx*4 + 0x4c], edx
        mov      dword ptr [g_eventQueueWorkType], 0
        mov      dword ptr [g_pendingNodeType], OFFSET PreFightInstallCluster + 0x250
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7aac
        mov      dword ptr [g_eventQueueWorkType], 0
        mov      dword ptr [g_pendingNodeType], OFFSET L_7ab0
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7aac
        mov      dword ptr [g_eventQueueEnd], 8
    L_7a0b:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueEnd]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     SetJmp_ZeroAndDirty4
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7aac
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        test     al, 4
        jne      L_7a5f
        mov      dword ptr [g_walkCallback], 0x190
        call     AudioVolumeRescale
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7aac
        test     byte ptr [g_xformDirtyFlags], bl
        je       L_7a7b
    L_7a5f:
        call     GuardedSeq_ScaledLoadTwoCallDualConst_then_GuardedSeq_00467c10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7aac
        call     GuardedSeq_GuardedTripleCallSetTail_then_GuardedSeq
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7aac
    L_7a7b:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [esi + 8], OFFSET L_78b0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_7aac:
        pop      esi
        pop      ebx
        ret
        nop
    L_7ab0:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_7baf
        dec      eax
        je       L_7b39
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [ecx*4 + 0x4c]
        mov      dword ptr [g_fightGroupHead], edx
        call     MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7c07
        call     MStackBracket7_DispatchAndChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7c07
        mov      dword ptr [g_walkCallback], 3
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7c07
        call     DualScaledLoadStoreJmp
        call     Thunk_ScaledNeg1SetPause
        pop      esi
        ret      
    L_7b39:
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_fightGroupHead], eax
        call     MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7c07
        call     MStackBracket7_DispatchAndChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7c07
        mov      dword ptr [g_walkCallback], 3
        call     ChainDirtyBitWalker
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7c07
        call     DualScaledLoadStoreJmp
        mov      dword ptr [esi + 8], OFFSET L_7ab0
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 4
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_7baf:
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [eax*4 + 0x68], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [edx*4 + 0x4c], eax
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_7ab0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x78
        mov      dword ptr [g_framePauseFlag], eax
    L_7c07:
        pop      esi
        ret      
    }
}
