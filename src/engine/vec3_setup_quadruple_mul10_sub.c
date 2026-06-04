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
extern void AudioMixerStep(void);
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void MStackPush1MagicMod2(void);
extern void StoreDoubleNegPauseSubStore(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Vec3SetupQuadrupleMul10Sub(void)

{
  int iVar1;
  
  MStackCall_MStackPush2ChainPrepend_00406340();
  if (g_framePauseFlag == 0) {
    MK4_NODE_AT(undefined4, g_currentNodeIdx, 0x30) = 0x7e;
    MK4_NODE_AT(undefined4, g_currentNodeIdx, 0x54) = MK4_NODE_AT(undefined4, g_cj_00542054, 0x3c);
    MK4_NODE_AT(undefined4, g_currentNodeIdx, 0x58) = MK4_NODE_AT(undefined4, g_cj_00542054, 0x40);
    MK4_NODE_AT(undefined4, g_currentNodeIdx, 0x5c) = MK4_NODE_AT(undefined4, g_cj_00542054, 0x44);
    MK4_NODE_AT(undefined4, g_currentNodeIdx, 0x70) = 0xffffe148;
    MK4_NODE_AT(undefined4, g_currentNodeIdx, 0x4c) = 0x3d7;
    g_walkCallback = g_pendingMatchVar;
    AudioMixerStep();
    if (g_framePauseFlag == 0) {
      g_eventQueueWorkType = g_walkCallback;
      MStackPush1MagicMod2();
      if (g_framePauseFlag == 0) {
        g_eventQueueCurrent = Mul10Tail(0x1c28,g_eventQueueCurrent);
        g_walkCallback = Mul10Tail(0x1c28,g_walkCallback);
        iVar1 = g_currentNodeIdx * 4;
        *(undefined4 *)(iVar1 + 0x6c) = g_eventQueueCurrent;
        *(undefined4 *)(iVar1 + 0x74) = g_walkCallback;
        g_walkCallback = 0x1999;
        StoreDoubleNegPauseSubStore();
        if (g_framePauseFlag == 0) {
          *(undefined4 *)(iVar1 + 0x78) = g_walkCallback;
          g_walkCallback = 0x1999;
          StoreDoubleNegPauseSubStore();
          if (g_framePauseFlag == 0) {
            *(undefined4 *)(iVar1 + 0x7c) = g_walkCallback;
            g_walkCallback = 0x1999;
            StoreDoubleNegPauseSubStore();
            if (g_framePauseFlag == 0) {
              *(undefined4 *)(iVar1 + 0x80) = g_walkCallback;
              g_eventQueueWorkType = 0x7ae;
              g_currentNodeIdx = g_currentNodeIdx + 0x1b;
              TripleVecAccCallStore();
              if (g_framePauseFlag == 0) {
                g_currentNodeIdx = g_currentNodeIdx + -0x1b;
              }
            }
          }
        }
      }
    }
  }
  return;
}
#else
__declspec(naked) void Vec3SetupQuadrupleMul10Sub(void)
{
    __asm
    {
        push    esi
        call    MStackCall_MStackPush2ChainPrepend_00406340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_v3sqs_ret
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, 0x7e
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x3c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x40]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x44]
        mov     dword ptr [ecx*4 + 0x5c], eax
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [edx*4 + 0x70], 0xffffe148
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [eax*4 + 0x4c], 0x3d7
        mov     ecx, dword ptr [g_pendingMatchVar]
        mov     dword ptr [g_walkCallback], ecx
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_v3sqs_ret
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [g_eventQueueWorkType], edx
        call    MStackPush1MagicMod2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_v3sqs_ret
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    eax
        push    0x1c28
        call    Mul10Tail
        mov     ecx, dword ptr [g_walkCallback]
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        push    ecx
        push    0x1c28
        call    Mul10Tail
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_eventQueueCurrent]
        add     esp, 8
        lea     esi, [edx*4]
        mov     dword ptr [esi + 0x6c], eax
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 0x74], ecx
        mov     dword ptr [g_walkCallback], 0x1999
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_v3sqs_ret
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 0x78], edx
        mov     dword ptr [g_walkCallback], 0x1999
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_v3sqs_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 0x7c], eax
        mov     dword ptr [g_walkCallback], 0x1999
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_v3sqs_ret
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 0x80], ecx
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     esi, 0x1b
        mov     dword ptr [g_eventQueueWorkType], 0x7ae
        add     ecx, esi
        mov     dword ptr [g_currentNodeIdx], ecx
        call    TripleVecAccCallStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_v3sqs_ret
        sub     dword ptr [g_currentNodeIdx], esi
    L_v3sqs_ret:
        pop     esi
        ret
    }
}
#endif
