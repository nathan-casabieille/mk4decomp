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

extern unsigned int g_pendingMatchVar;
extern unsigned int g_dispatchSave730;
extern unsigned int g_particleEmitterNode;
extern void AudioMixerStep(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void PushSetXfmMaskCallPop(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MStackBracket3PackedSlotInit(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *(int *)((int)g_matrixStackTop * 4) = g_cj_0054205c;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_walkCallback;
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_eventQueueCurrent;
  g_walkCallback = 0x13b226;
  PushSetXfmMaskCallPop();
  if (g_framePauseFlag == 0) {
    if (((byte)g_xformDirtyFlags & 4) != 0) {
      g_eventQueueCurrent = *(undefined4 *)((int)g_matrixStackTop * 4);
      g_walkCallback = *(undefined4 *)((int)(g_matrixStackTop + -1) * 4);
      g_cj_0054205c = *(undefined4 *)((int)(g_matrixStackTop + -2) * 4);
      g_matrixStackTop = g_matrixStackTop + -3;
      return;
    }
    MK4_NODE_AT(undefined4, g_cj_0054205c, 0x3c) = g_particleEmitterNode;
    g_walkCallback = 0x7f;
    *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x30) = 0x7f;
    MStackCall_MStackPush2ChainPrepend_00406340();
    if (g_framePauseFlag == 0) {
      g_matrixStackTop = g_matrixStackTop + 1;
      iVar1 = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4;
      *(undefined4 *)((int)g_matrixStackTop * 4) = g_eventQueuePending;
      *(uint *)(*(int *)(iVar1 + 0x18) * 4 + 0x20) =
           *(uint *)(*(int *)(iVar1 + 0x18) * 4 + 0x20) & 0xfffff9ff;
      g_eventQueuePending = *(undefined4 *)((int)g_matrixStackTop * 4);
      g_matrixStackTop = g_matrixStackTop + -1;
      *(undefined4 *)(iVar1 + 0x60) = 0x1921f;
      g_walkCallback = g_pendingMatchVar;
      AudioMixerStep();
      if (g_framePauseFlag == 0) {
        *(undefined4 *)(iVar1 + 100) = g_walkCallback;
        *(undefined4 *)(iVar1 + 0x58) = 0xfffffae2;
        puVar2 = (undefined4 *)((int)g_matrixStackTop * 4);
        g_matrixStackTop = g_matrixStackTop + -1;
        *(undefined4 *)(iVar1 + 0x5c) = *puVar2;
        g_walkCallback = *(undefined4 *)((int)g_matrixStackTop * 4);
        g_matrixStackTop = g_matrixStackTop + -1;
        *(undefined4 *)(iVar1 + 0x54) = g_walkCallback;
        g_cj_0054205c = *(int *)((int)g_matrixStackTop * 4);
        g_matrixStackTop = g_matrixStackTop + -1;
      }
    }
  }
  return;
}
#else
__declspec(naked) void MStackBracket3PackedSlotInit(void)
{
    __asm
    {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_walkCallback]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        inc     eax
        mov     edx, offset g_dispatchSave730
        mov     dword ptr [g_matrixStackTop], eax
        shr     edx, 2
        mov     dword ptr [eax*4], ecx
        mov     dword ptr [g_walkCallback], edx
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mb3p_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_mb3p_doBody
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_fightGroupHead], ecx
        mov     dword ptr [g_matrixStackTop], eax
        pop     esi
        ret
    L_mb3p_doBody:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_particleEmitterNode]
        mov     dword ptr [edx*4 + 0x3c], eax
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, 0x7f
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        call    MStackCall_MStackPush2ChainPrepend_00406340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mb3p_ret
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        lea     esi, [edx*4]
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     ecx, dword ptr [esi + 0x18]
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     eax, dword ptr [ecx*4 + 0x20]
        and     ah, 0xf9
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [esi + 0x60], 0x1921f
        mov     eax, dword ptr [g_pendingMatchVar]
        mov     dword ptr [g_walkCallback], eax
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mb3p_ret
        mov     ecx, dword ptr [g_walkCallback]
        mov     eax, 0xfffffae2
        mov     dword ptr [esi + 0x64], ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [esi + 0x58], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [esi + 0x5c], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [esi + 0x54], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_mb3p_ret:
        pop     esi
        ret
    }
}
#endif
