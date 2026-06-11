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

extern unsigned int g_audioStateMachine0;
extern unsigned int g_audioStateMachine1;
extern unsigned int g_audioCrewState;
extern unsigned int g_audioBank2Byte2;
extern unsigned int g_audioPendByte61a;
extern unsigned int g_dispatchSave1701;
extern unsigned int g_glideFnTable;
extern unsigned int g_dispatchSave1710;
extern void AudioChainInit(void);
extern void AudioInitLoopTriple(void);
extern void ScaledChainStore24(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void SpawnLeftRightAudioCrew(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  g_audioCrewState = g_audioStateMachine0 * 0x600000 + -0x600000;
  iVar3 = 0;
  if (0 < g_audioStateMachine0) {
    iVar1 = 0;
    pcVar2 = &g_audioBank2Byte2;
    do {
      g_walkCallback = 0x10;
      AudioChainInit();
      MK4_NODE_AT(int, (iVar3 + g_baseSel), 0x34) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
      MK4_NODE_AT(int, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) = (iVar1 - g_audioCrewState) * 4;
      MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x58) = 0xfde40000;
      MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 100) = 0;
      MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) = 0xc0000;
      g_walkCallback = (int)pcVar2[-2];
      ScaledChainStore24();
      if (*pcVar2 != '\0') {
        AudioInitLoopTriple();
        MK4_NODE_AT(int, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) = iVar1 - g_audioCrewState;
        MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x58) = 0xff890000;
        MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) = 0x30000;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 0x18;
      iVar1 = iVar1 + 0xc00000;
    } while (iVar3 < g_audioStateMachine0);
  }
  iVar3 = 0;
  g_audioCrewState = g_audioStateMachine1 * 0x600000 + -0x600000;
  if (0 < g_audioStateMachine1) {
    iVar1 = 0;
    pcVar2 = &g_audioPendByte61a;
    do {
      g_walkCallback = 0x10;
      AudioChainInit();
      MK4_NODE_AT(int, (iVar3 + g_baseSel), 0x48) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
      MK4_NODE_AT(int, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) = (iVar1 - g_audioCrewState) * 4;
      MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x58) = 0x12c0000;
      MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 100) = 0;
      MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) = 0xc0000;
      g_walkCallback = (int)pcVar2[-2];
      ScaledChainStore24();
      if (*pcVar2 != '\0') {
        AudioInitLoopTriple();
        MK4_NODE_AT(int, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) = iVar1 - g_audioCrewState;
        *(undefined4 **)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x58) = &g_glideFnTable;
        MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) = 0x30000;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 0x18;
      iVar1 = iVar1 + 0xc00000;
    } while (iVar3 < g_audioStateMachine1);
  }
  return;
}
#else
__declspec(naked) void SpawnLeftRightAudioCrew(void)
{
    __asm {
        mov      eax, dword ptr [g_audioStateMachine0]
        push     ebx
        push     ebp
        push     esi
        lea      ecx, [eax + eax*2]
        push     edi
        shl      ecx, 0x15
        sub      ecx, OFFSET g_dispatchSave1701
        xor      edi, edi
        test     eax, eax
        mov      dword ptr [g_audioCrewState], ecx
        jle      L_8183
        xor      ebp, ebp
        mov      esi, OFFSET g_audioBank2Byte2
        mov      ebx, 0xfde40000
    L_80b1:
        mov      dword ptr [g_walkCallback], 0x10
        call     AudioChainInit
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_currentNodeIdx]
        lea      eax, [edi + edx]
        mov      edx, ebp
        mov      dword ptr [eax*4 + 0x34], ecx
        mov      eax, dword ptr [g_audioCrewState]
        sub      edx, eax
        mov      eax, dword ptr [g_currentNodeIdx]
        shl      edx, 2
        mov      dword ptr [eax*4 + 0x54], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], ebx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x64], 0
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x5c], 0xc0000
        movsx    ecx, byte ptr [esi - 2]
        mov      dword ptr [g_walkCallback], ecx
        call     ScaledChainStore24
        cmp      byte ptr [esi], 0
        je       short L_816c
        call     AudioInitLoopTriple
        mov      eax, dword ptr [g_audioCrewState]
        mov      edx, ebp
        sub      edx, eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], 0xff890000
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x5c], 0x30000
    L_816c:
        mov      eax, dword ptr [g_audioStateMachine0]
        inc      edi
        add      esi, 0x18
        add      ebp, OFFSET g_dispatchSave1710
        cmp      edi, eax
        jl       L_80b1
    L_8183:
        mov      eax, dword ptr [g_audioStateMachine1]
        xor      edi, edi
        lea      ecx, [eax + eax*2]
        shl      ecx, 0x15
        sub      ecx, OFFSET g_dispatchSave1701
        test     eax, eax
        mov      dword ptr [g_audioCrewState], ecx
        jle      short L_8282
        xor      ebp, ebp
        mov      esi, OFFSET g_audioPendByte61a
        mov      ebx, 0x12c0000
    L_81b0:
        mov      dword ptr [g_walkCallback], 0x10
        call     AudioChainInit
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_currentNodeIdx]
        lea      eax, [edi + edx]
        mov      edx, ebp
        mov      dword ptr [eax*4 + 0x48], ecx
        mov      eax, dword ptr [g_audioCrewState]
        sub      edx, eax
        mov      eax, dword ptr [g_currentNodeIdx]
        shl      edx, 2
        mov      dword ptr [eax*4 + 0x54], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], ebx
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x64], 0
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x5c], 0xc0000
        movsx    ecx, byte ptr [esi - 2]
        mov      dword ptr [g_walkCallback], ecx
        call     ScaledChainStore24
        cmp      byte ptr [esi], 0
        je       short L_826b
        call     AudioInitLoopTriple
        mov      eax, dword ptr [g_audioCrewState]
        mov      edx, ebp
        sub      edx, eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [ecx*4 + 0x58], OFFSET g_glideFnTable
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [edx*4 + 0x5c], 0x30000
    L_826b:
        mov      eax, dword ptr [g_audioStateMachine1]
        inc      edi
        add      esi, 0x18
        add      ebp, OFFSET g_dispatchSave1710
        cmp      edi, eax
        jl       L_81b0
    L_8282:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
#endif
