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

extern unsigned int g_audioStateMachineVar4;
extern unsigned int g_dispatchSave503;
extern unsigned int g_audioStateMachineVar;
extern unsigned int g_audioVoiceTrioBase;
extern unsigned int g_voiceTrioBaseB;
extern void GuardedSetupCallTailJmp3(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void);
extern void ScaledOr4DirtyClear(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void VoiceTrioBindAndKick(char *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1[2] == '\x01') {
    g_eventQueuePending = *(int *)(*(uint *)((*param_1 + 0x14283c) * 4) & 0xffffff) >> 2 & 0x3fffff;
  }
  else {
    g_eventQueuePending = 0x143186;
  }
  DispatcherComplex260_FramePauseScaledStore();
  if (g_framePauseFlag == 0) {
    MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430();
    if (g_framePauseFlag == 0) {
      if (((byte)g_xformDirtyFlags & 4) == 0) {
        if (param_1[2] == '\0') {
          MK4_NODE_AT(undefined4, (int)(g_currentNodeIdx), 100) = 0x3243f;
        }
        MK4_NODE_AT(int, (int)(g_currentNodeIdx), 0x54) = param_2 * 4;
        MK4_NODE_AT(int, (int)(g_currentNodeIdx), 0x58) = param_3 * 4;
        MK4_NODE_AT(int, (int)(g_currentNodeIdx), 0x5c) = param_4 * 4 + 0xc0000;
      }
      *(undefined **)(param_1 + 8) = (g_currentNodeIdx);
      if (param_1[2] == '\x01') {
        param_3 = param_3 / 3;
        iVar1 = param_2 / 3 + 0x300000;
        (g_currentNodeIdx) = (&g_audioStateMachineVar)[param_1[1]];
        GuardedSetupCallTailJmp3((g_currentNodeIdx),iVar1,param_3 + -0xa0000);
        iVar2 = param_4 / 3 + 0x10000;
        MK4_NODE_AT(int, (int)(g_currentNodeIdx), 0x5c) = iVar2;
        *(undefined **)(param_1 + 0xc) = (g_currentNodeIdx);
        (g_currentNodeIdx) = (&g_dispatchSave503)[param_1[3]];
        GuardedSetupCallTailJmp3((g_currentNodeIdx),iVar1,param_3 + 0xa0000);
        MK4_NODE_AT(int, (int)(g_currentNodeIdx), 0x5c) = iVar2;
        *(undefined **)(param_1 + 0x10) = (g_currentNodeIdx);
        (g_currentNodeIdx) = (&g_audioStateMachineVar4)[param_1[4]];
        GuardedSetupCallTailJmp3((g_currentNodeIdx),iVar1,param_3 + 0x1e0000);
        MK4_NODE_AT(int, (int)(g_currentNodeIdx), 0x5c) = iVar2;
        *(undefined **)(param_1 + 0x14) = (g_currentNodeIdx);
        if (param_1[3] != '\0') {
          ScaledOr4DirtyClear();
        }
      }
    }
  }
  return;
}
#else
__declspec(naked) void VoiceTrioBindAndKick(void)
{
    __asm {
        push     ebx
        push     ebp
        mov      eax, OFFSET g_audioVoiceTrioBase
        push     esi
        mov      esi, dword ptr [esp + 0x10]
        mov      bl, 1
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      cl, byte ptr [esi + 2]
        cmp      cl, bl
        push     edi
        jne      short L_5ee7
        movsx    ecx, byte ptr [esi]
        add      ecx, eax
        mov      eax, dword ptr [ecx*4]
        and      eax, 0xffffff
        mov      dword ptr [g_xformEntityIdx], eax
        mov      edx, dword ptr [eax]
        sar      edx, 2
        and      edx, 0x3fffff
        mov      dword ptr [g_xformEntityIdx], edx
        jmp      short L_5ef4
    L_5ee7:
        mov      eax, OFFSET g_voiceTrioBaseB
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
    L_5ef4:
        call     DispatcherComplex260_FramePauseScaledStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_607a
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_607a
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ecx, dword ptr [esp + 0x20]
        mov      edx, dword ptr [esp + 0x1c]
        mov      ebp, dword ptr [esp + 0x18]
        test     al, 4
        jne      short L_5f80
        mov      al, byte ptr [esi + 2]
        test     al, al
        jne      short L_5f44
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x64], 0x3243f
    L_5f44:
        mov      edi, dword ptr [g_currentNodeIdx]
        lea      eax, [ebp*4]
        mov      dword ptr [edi*4 + 0x54], eax
        mov      edi, dword ptr [g_currentNodeIdx]
        lea      eax, [edx*4]
        mov      dword ptr [edi*4 + 0x58], eax
        mov      edi, dword ptr [g_currentNodeIdx]
        lea      eax, [ecx*4 + 0xc0000]
        mov      dword ptr [edi*4 + 0x5c], eax
    L_5f80:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [esi + 8], eax
        mov      al, byte ptr [esi + 2]
        cmp      al, bl
        jne      L_607a
        mov      eax, 0x55555556
        imul     edx
        mov      eax, edx
        shr      eax, 0x1f
        add      edx, eax
        mov      eax, 0x55555556
        mov      edi, edx
        imul     ebp
        mov      eax, edx
        shr      eax, 0x1f
        lea      ebx, [edx + eax + 0x300000]
        mov      eax, 0x55555556
        imul     ecx
        mov      ecx, edx
        shr      ecx, 0x1f
        add      edx, ecx
        lea      ecx, [edi - 0xa0000]
        mov      ebp, edx
        push     ecx
        movsx    edx, byte ptr [esi + 1]
        push     ebx
        mov      eax, dword ptr [edx*4 + g_audioStateMachineVar]
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp3
        mov      edx, dword ptr [g_currentNodeIdx]
        add      ebp, 0x10000
        add      esp, 0xc
        mov      dword ptr [edx*4 + 0x5c], ebp
        mov      eax, dword ptr [g_currentNodeIdx]
        movsx    ecx, byte ptr [esi + 3]
        lea      edx, [edi + 0xa0000]
        mov      dword ptr [esi + 0xc], eax
        mov      eax, dword ptr [ecx*4 + g_dispatchSave503]
        push     edx
        push     ebx
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp3
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 0xc
        add      edi, 0x1e0000
        mov      dword ptr [eax*4 + 0x5c], ebp
        mov      ecx, dword ptr [g_currentNodeIdx]
        movsx    edx, byte ptr [esi + 4]
        mov      dword ptr [esi + 0x10], ecx
        push     edi
        mov      eax, dword ptr [edx*4 + g_audioStateMachineVar4]
        push     ebx
        push     eax
        mov      dword ptr [g_currentNodeIdx], eax
        call     GuardedSetupCallTailJmp3
        mov      eax, dword ptr [g_currentNodeIdx]
        add      esp, 0xc
        mov      dword ptr [eax*4 + 0x5c], ebp
        mov      al, byte ptr [esi + 3]
        mov      ecx, dword ptr [g_currentNodeIdx]
        test     al, al
        mov      dword ptr [esi + 0x14], ecx
        je       short L_607a
        call     ScaledOr4DirtyClear
    L_607a:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
#endif
