/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

extern unsigned int g_dispatchSave803;
extern unsigned int g_dispatchArg;
extern unsigned int g_audioVoiceCounter;
extern unsigned int g_audioBitField;
extern unsigned int g_audioSequencerSlot;
extern unsigned int g_dispatchTab65;
extern void AudioInitChainTag(void);
extern void Eleven404b90_404c00(void);
extern void GuardedScaledCall(void);
extern void LinkedListIndirectDirtyToggle(void);
extern void RoundWinTransition(void);
extern void StorePauseImulShr16(void);
extern void Ten404c40_404bd0(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void AudioVoiceSequencerCluster(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
  g_chainAccumCur = *(undefined4 *)((g_chainAccumCur * 5 + -5 + g_audioSequencerSlot) * 4);
  (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(undefined4 *)((int)g_matrixStackTop * 4);
  g_matrixStackTop = g_matrixStackTop + -1;
  return;
}
#else
__declspec(naked) void AudioVoiceSequencerCluster(void)
{
    __asm {
        /* === Helper 1 (0x4a0d60): sample-pick from mul-5 stride === */
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_chainAccumCur]
        mov      edx, dword ptr [g_audioSequencerSlot]
        lea      eax, [eax + eax*4 - 5]
        mov      dword ptr [g_chainAccumCur], eax
        add      eax, edx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_chainAccumCur], eax
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2 (0x4a0dc0): sequence list walker === */
    L_0dc0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     ebp
        push     esi
        push     edi
        lea      edi, [eax*4]
        xor      esi, esi
        mov      ebx, 1
        mov      eax, dword ptr [edi + 0x84]
        mov      dword ptr [edi + 0x84], esi
        cmp      eax, esi
        je       short L_0e03
        call     Ten404c40_404bd0
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_0ff9
        inc      dword ptr [g_audioVoiceCounter]
        jmp      L_0f19
    L_0e03:
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      ebp, 0xf
        mov      dword ptr [edx*4 + 0x30], ecx
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_dispatchArg], eax
        mov      dword ptr [g_walkCallback], ebp
        call     StorePauseImulShr16
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_0ff9
    L_0e3c:
        inc      dword ptr [g_walkCallback]
        call     LinkedListIndirectDirtyToggle
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_0ff9
        test     byte ptr [g_xformDirtyFlags], bl
        jne      short L_0ed1
        mov      eax, dword ptr [g_audioBitField]
        mov      edx, dword ptr [g_dispatchArg]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [g_xformEntityIdx], eax
        add      eax, edx
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_xformEntityIdx], eax
        mov      ecx, dword ptr [eax*4]
        mov      dword ptr [g_walkCallback], ebx
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      edx, dword ptr [eax*4 + 0x14]
        mov      eax, OFFSET g_dispatchTab65
        mov      dword ptr [edx*4], ebx
        mov      edx, dword ptr [g_eventQueueCurrent]
        shr      eax, 2
        add      eax, edx
        mov      dword ptr [g_audioVoiceCounter], esi
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        cmp      eax, esi
        mov      dword ptr [g_fightGroupHead], eax
        jne      short L_0eed
    L_0ed1:
        mov      dword ptr [g_walkCallback], ebp
        call     StorePauseImulShr16
        cmp      dword ptr [g_framePauseFlag], esi
        je       L_0e3c
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_0eed:
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      edx, dword ptr [g_baseSel]
        mov      eax, OFFSET g_dispatchSave803
        shr      eax, 2
        mov      dword ptr [g_eventQueueTotal], eax
        mov      eax, dword ptr [ecx*4 + 8]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x38], eax
    L_0f19:
        mov      eax, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_audioVoiceCounter]
        add      eax, ecx
        mov      eax, dword ptr [eax*4]
        cmp      eax, esi
        mov      dword ptr [g_walkCallback], eax
        jne      short L_0f40
        call     AudioInitChainTag
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_0f40:
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x34], eax
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4], eax
        call     RoundWinTransition
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_0ff9
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [edx*4 + 0x38]
        mov      dword ptr [g_walkCallback], eax
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     GuardedScaledCall
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_0ff9
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueTotal]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, dword ptr [g_audioVoiceCounter]
        add      ecx, eax
        mov      dword ptr [g_xformEntityIdx], edx
        mov      edx, dword ptr [ecx*4]
        mov      dword ptr [g_pendingNodeType], edx
        call     Eleven404b90_404c00
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_0ff9
        mov      dword ptr [edi + 8], OFFSET L_0dc0
        mov      dword ptr [edi + 0x84], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_0ff9:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
#endif
