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

extern unsigned int g_particleEmitterNode;
extern unsigned int g_bootHeavyState;
extern unsigned int g_particleInitState;
extern void BootPhaseGateBracketedInit(void);
extern void InstallSelf5CallVecChain(void);
extern void MStackCall_MStackPush2ChainPrepend_004063e0(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void StageParticleEmitterInit(void)

{
  g_walkCallback = g_bootHeavyState;
  if (g_bootHeavyState == 0) {
    BootPhaseGateBracketedInit();
    if (g_framePauseFlag != 0) {
      return;
    }
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x3c) = 0xe666;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x30) = 0x11;
    g_bootHeavyState = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) = 0xffffb0a4;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x58) = 0xfffe0000;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) = 0xffffae15;
    g_walkCallback = MK4_NODE_AT(uint, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x34) | 8;
    MK4_NODE_AT(uint, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x34) = g_walkCallback;
    MStackCall_MStackPush2ChainPrepend_004063e0();
    if (g_framePauseFlag != 0) {
      return;
    }
  }
  g_walkCallback = g_particleInitState;
  if (g_particleInitState == 0) {
    BootPhaseGateBracketedInit();
    if (g_framePauseFlag != 0) {
      return;
    }
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x3c) = 0xe666;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x30) = 0x12;
    g_particleInitState = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) = 0x4f5c;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x58) = 0xfffe0000;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) = 0xffffae15;
    g_walkCallback = MK4_NODE_AT(uint, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x34) | 8;
    MK4_NODE_AT(uint, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x34) = g_walkCallback;
    MStackCall_MStackPush2ChainPrepend_004063e0();
    if (g_framePauseFlag != 0) {
      return;
    }
  }
  g_walkCallback = g_particleEmitterNode;
  if ((g_particleEmitterNode == 0) && (BootPhaseGateBracketedInit(), g_framePauseFlag == 0)) {
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x3c) = 0xf333;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x30) = 0x13;
    g_particleEmitterNode = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) = 0xffe80000;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x58) = 0xffd00000;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) = 0;
    g_walkCallback = MK4_NODE_AT(uint, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x34) | 8;
    MK4_NODE_AT(uint, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x34) = g_walkCallback;
    MStackCall_MStackPush2ChainPrepend_004063e0();
  }
  return;
}
#else
__declspec(naked) void StageParticleEmitterInit(void)
{
    __asm {
        /* === h1 (0x464350): 3-stage particle spawn === */
        mov      eax, dword ptr [g_bootHeavyState]
        push     esi
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        mov      esi, 0xffffae15
        jne      L_4400
        call     BootPhaseGateBracketedInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4551
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x3c], 0xe666
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x30], 0x11
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_bootHeavyState], eax
        mov      dword ptr [eax*4 + 0x54], 0xffffb0a4
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x58], 0xfffe0000
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [eax*4 + 0x5c], esi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       al, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        call     MStackCall_MStackPush2ChainPrepend_004063e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4551
    L_4400:
        mov      eax, dword ptr [g_particleInitState]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      L_44ab
        call     BootPhaseGateBracketedInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4551
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x3c], 0xe666
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x30], 0x12
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_particleInitState], eax
        mov      dword ptr [eax*4 + 0x54], 0x4f5c
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x58], 0xfffe0000
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [ecx*4 + 0x5c], esi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       al, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        call     MStackCall_MStackPush2ChainPrepend_004063e0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4551
    L_44ab:
        mov      eax, dword ptr [g_particleEmitterNode]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        jne      L_4551
        call     BootPhaseGateBracketedInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_4551
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x3c], 0xf333
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x30], 0x13
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_particleEmitterNode], eax
        mov      dword ptr [eax*4 + 0x54], 0xffe80000
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], 0xffd00000
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], 0
        mov      dword ptr [edx*4 + 0x5c], 0
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x34]
        or       al, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        call     MStackCall_MStackPush2ChainPrepend_004063e0
    L_4551:
        pop      esi
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
        /* === h2 (0x464560): bullet seed #1 → tail-jmp 464660 === */
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x30], 0x8000
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0xffffd1ec
        mov      dword ptr [ecx*4 + 0x34], 0xffff6667
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], eax
        mov      ecx, OFFSET g_bootHeavyState
        mov      dword ptr [edx*4 + 0x38], eax
        mov      eax, OFFSET g_player1NodeIdx
        shr      eax, 2
        mov      dword ptr [g_eventQueueEnd], eax
        mov      eax, dword ptr [g_eventQueueNotMask]
        shr      ecx, 2
        cmp      eax, 1
        mov      dword ptr [g_eventQueueIdx], ecx
        je       short L_45d8
        mov      edx, OFFSET g_player2NodeIdx
        mov      eax, OFFSET g_particleInitState
        shr      edx, 2
        shr      eax, 2
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [g_eventQueueIdx], eax
    L_45d8:
        jmp      InstallSelf5CallVecChain
        nop
        nop
        nop
        /* === h3 (0x4645e0): bullet seed #2 → tail-jmp 464660 === */
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x30], 0xffff6e15
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0xffffd99a
        mov      dword ptr [ecx*4 + 0x34], 0x12b85
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [g_walkCallback], eax
        mov      ecx, OFFSET g_bootHeavyState
        mov      dword ptr [edx*4 + 0x38], eax
        mov      eax, OFFSET g_player1NodeIdx
        shr      eax, 2
        mov      dword ptr [g_eventQueueEnd], eax
        mov      eax, dword ptr [g_eventQueueNotMask]
        shr      ecx, 2
        cmp      eax, 1
        mov      dword ptr [g_eventQueueIdx], ecx
        je       short L_4658
        mov      edx, OFFSET g_player2NodeIdx
        mov      eax, OFFSET g_particleInitState
        shr      edx, 2
        shr      eax, 2
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [g_eventQueueIdx], eax
    L_4658:
        jmp      InstallSelf5CallVecChain
    }
}
#endif
