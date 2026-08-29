/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave523;
extern unsigned int g_eventQueueSeed;
extern unsigned int g_particleEmitterNode;
extern unsigned int g_bootChainSlot3;
extern unsigned int g_bootHeavyState;
extern unsigned int g_phaseThunkSlot8;
extern unsigned int g_particleInitState;
extern unsigned int g_dispatchSave82;
extern unsigned int g_bootChainPair0;
extern unsigned int g_bootChainPair1;
extern unsigned int g_bootChainScaled1;
extern unsigned int g_bootChainScaled2;
extern unsigned int g_tickFrameNodeA;
extern unsigned int g_tickFrameNodeB;
extern unsigned int g_bootChainState3;
extern unsigned int g_bootChainScaled4;
extern unsigned int g_bootChainScaled3;
extern unsigned int g_dispatchSave81;
extern unsigned int g_bootChainSlot2;
extern unsigned int g_dispatchSave80;
extern unsigned int g_bootChainState4;
extern unsigned int g_audioInitScaled;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_audioInitScaled (*(unsigned int *)MK4_VA(unsigned int, 0x54343cu))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_bootChainPair0 (*(unsigned int *)MK4_VA(unsigned int, 0x541e80u))
#define g_bootChainPair1 (*(unsigned int *)MK4_VA(unsigned int, 0x541e84u))
#define g_bootChainScaled1 (*(unsigned int *)MK4_VA(unsigned int, 0x541e88u))
#define g_bootChainScaled2 (*(unsigned int *)MK4_VA(unsigned int, 0x541e8cu))
#define g_bootChainScaled3 (*(unsigned int *)MK4_VA(unsigned int, 0x541ea0u))
#define g_bootChainScaled4 (*(unsigned int *)MK4_VA(unsigned int, 0x541e9cu))
#define g_bootChainSlot2 (*(unsigned int *)MK4_VA(unsigned int, 0x541ea8u))
#define g_bootChainSlot3 (*(unsigned int *)MK4_VA(unsigned int, 0x537e8cu))
#define g_bootChainState3 (*(unsigned int *)MK4_VA(unsigned int, 0x541e98u))
#define g_bootChainState4 (*(unsigned int *)MK4_VA(unsigned int, 0x541eb0u))
#define g_bootHeavyState (*(unsigned int *)MK4_VA(unsigned int, 0x537f78u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave523 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5140u))
#define g_dispatchSave80 (*(unsigned int *)MK4_VA(unsigned int, 0x541eacu))
#define g_dispatchSave81 (*(unsigned int *)MK4_VA(unsigned int, 0x541ea4u))
#define g_dispatchSave82 (*(unsigned int *)MK4_VA(unsigned int, 0x541e7cu))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_dualD (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_eventQueueSeed (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_particleEmitterNode (*(unsigned int *)MK4_VA(unsigned int, 0x535e6cu))
#define g_particleInitState (*(unsigned int *)MK4_VA(unsigned int, 0x541de0u))
#define g_phaseThunkSlot8 (*(unsigned int *)MK4_VA(unsigned int, 0x53a520u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_tickFrameNodeA (*(unsigned int *)MK4_VA(unsigned int, 0x541e90u))
#define g_tickFrameNodeB (*(unsigned int *)MK4_VA(unsigned int, 0x541e94u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void AndShlStore(void);
extern void BootPhaseGateBracketedInit(void);
extern void Helper_GeoLoadPre(void);
extern void LinkedListBuilder(void);
extern void MStackCall_MStackPush2ChainPrepend_004063e0(void);
extern void ScaledChainAccumLoop(void);
extern void Thunk_Helper_GeoLoadPre(void);
extern void VertexSlotInitFlagWalk(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BootInitChainHeavy(void)

{
  g_audioInitScaled = 0;
  Helper_GeoLoadPre();
  if (g_framePauseFlag == 0) {
    Thunk_Helper_GeoLoadPre();
    if (g_framePauseFlag == 0) {
      (g_currentNodeIdx) = g_dispatchSave82;
      g_eventQueuePending = 0;
      g_dualC = 0x21;
      g_dualD = g_bootChainPair0;
      g_cj_00542054 = 200;
      LinkedListBuilder();
      if (g_framePauseFlag == 0) {
        g_cj_00542054 = 0;
        g_dualD = g_bootChainPair1;
        VertexSlotInitFlagWalk();
        if (g_framePauseFlag == 0) {
          g_cj_00542054 = 0;
          g_dualD = g_bootChainScaled1;
          VertexSlotInitFlagWalk();
          if (g_framePauseFlag == 0) {
            g_cj_00542054 = 0;
            g_dualD = g_bootChainScaled2;
            VertexSlotInitFlagWalk();
            if (g_framePauseFlag == 0) {
              g_cj_00542054 = 0;
              g_dualD = g_bootChainState3;
              VertexSlotInitFlagWalk();
              if (g_framePauseFlag == 0) {
                g_cj_00542054 = 0;
                g_dualD = g_tickFrameNodeA;
                VertexSlotInitFlagWalk();
                if (g_framePauseFlag == 0) {
                  g_cj_00542054 = 0;
                  g_dualD = g_tickFrameNodeB;
                  VertexSlotInitFlagWalk();
                  if (g_framePauseFlag == 0) {
                    g_cj_00542054 = 0;
                    g_dualD = g_bootChainScaled4;
                    VertexSlotInitFlagWalk();
                    if (g_framePauseFlag == 0) {
                      g_eventQueuePending = 3;
                      g_dualD = g_bootChainScaled3;
                      g_cj_00542054 = 0;
                      VertexSlotInitFlagWalk();
                      if (g_framePauseFlag == 0) {
                        (g_currentNodeIdx) = g_dispatchSave81;
                        g_eventQueuePending = 4;
                        g_dualC = 0x13;
                        g_dualD = g_bootChainSlot2;
                        g_cj_00542054 = 0x1c2;
                        LinkedListBuilder();
                        if (g_framePauseFlag == 0) {
                          (g_currentNodeIdx) = g_dispatchSave80;
                          g_eventQueuePending = 0;
                          g_dualC = 0x13;
                          g_dualD = g_bootChainState4;
                          g_cj_00542054 = 200;
                          LinkedListBuilder();
                          if (g_framePauseFlag == 0) {
                            ScaledChainAccumLoop();
                            if (g_framePauseFlag == 0) {
                              BootPhaseGateBracketedInit();
                              if (g_framePauseFlag == 0) {
                                g_walkCallback = 0xc;
                                MK4_NODE_AT(undefined4, (g_currentNodeIdx), 0x30) = 0xc;
                                g_eventQueueSeed = (g_currentNodeIdx);
                                MStackCall_MStackPush2ChainPrepend_004063e0();
                                if (g_framePauseFlag == 0) {
                                  g_phaseThunkSlot8 = 0;
                                  g_bootChainSlot3 = 0;
                                  g_bootHeavyState = 0;
                                  g_particleInitState = 0;
                                  g_particleEmitterNode = 0;
                                  g_dispatchSave523 = 0x7f000000;
                                  g_walkCallback = 0;
                                  AndShlStore();
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
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
__declspec(naked) void BootInitChainHeavy(void)
{
    __asm {
        push    esi
        xor     esi, esi
        mov     dword ptr [g_audioInitScaled], esi
        call    Helper_GeoLoadPre
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        call    Thunk_Helper_GeoLoadPre
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     eax, dword ptr [g_dispatchSave82]
        mov     ecx, dword ptr [g_bootChainPair0]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], esi
        mov     dword ptr [g_pendingNodeType], 0x21
        mov     dword ptr [g_eventQueueTotal], ecx
        mov     dword ptr [g_eventQueueEnd], 0xC8
        call    LinkedListBuilder
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     edx, dword ptr [g_bootChainPair1]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], edx
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     eax, dword ptr [g_bootChainScaled1]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], eax
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     ecx, dword ptr [g_bootChainScaled2]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], ecx
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     edx, dword ptr [g_bootChainState3]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], edx
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     eax, dword ptr [g_tickFrameNodeA]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], eax
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     ecx, dword ptr [g_tickFrameNodeB]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], ecx
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     edx, dword ptr [g_bootChainScaled4]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], edx
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     eax, dword ptr [g_bootChainScaled3]
        mov     dword ptr [g_xformEntityIdx], 3
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_eventQueueEnd], esi
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     ecx, dword ptr [g_dispatchSave81]
        mov     edx, dword ptr [g_bootChainSlot2]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_xformEntityIdx], 4
        mov     dword ptr [g_pendingNodeType], 0x13
        mov     dword ptr [g_eventQueueTotal], edx
        mov     dword ptr [g_eventQueueEnd], 0x1C2
        call    LinkedListBuilder
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     eax, dword ptr [g_dispatchSave80]
        mov     ecx, dword ptr [g_bootChainState4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], esi
        mov     dword ptr [g_pendingNodeType], 0x13
        mov     dword ptr [g_eventQueueTotal], ecx
        mov     dword ptr [g_eventQueueEnd], 0xC8
        call    LinkedListBuilder
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        call    ScaledChainAccumLoop
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        call    BootPhaseGateBracketedInit
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, 0x0C
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x30], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_eventQueueSeed], eax
        call    MStackCall_MStackPush2ChainPrepend_004063e0
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     dword ptr [g_phaseThunkSlot8], esi
        mov     dword ptr [g_bootChainSlot3], esi
        mov     dword ptr [g_bootHeavyState], esi
        mov     dword ptr [g_particleInitState], esi
        mov     dword ptr [g_particleEmitterNode], esi
        mov     dword ptr [g_dispatchSave523], 0x7F000000
        mov     dword ptr [g_walkCallback], esi
        call    AndShlStore
    L_boot_init_exit:
        pop     esi
        ret
    }
}
#endif
