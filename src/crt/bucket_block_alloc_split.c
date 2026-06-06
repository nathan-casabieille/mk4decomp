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

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int BucketBlockAllocSplit(int *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar2 = (byte *)*param_1;
  if (param_3 <= (uint)param_1[1]) {
    *pbVar2 = (byte)param_3;
    if (pbVar2 + param_3 < param_1 + 0x3e) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    return (int)(pbVar2 + 8) * 0x10 + (int)param_1 * -0xf;
  }
  pbVar6 = pbVar2;
  if (pbVar2[param_1[1]] != 0) {
    pbVar6 = pbVar2 + param_1[1];
  }
  if (pbVar6 + param_3 < param_1 + 0x3e) {
    do {
      if (*pbVar6 == 0) {
        pbVar3 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = pbVar6[1];
        while (bVar1 == 0) {
          pbVar3 = pbVar3 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar3;
        }
        if (param_3 <= uVar5) {
          if (param_1 + 0x3e <= pbVar6 + param_3) {
            *param_1 = (int)(param_1 + 2);
            goto LAB_004c77bf;
          }
          *param_1 = (int)(pbVar6 + param_3);
          param_1[1] = uVar5 - param_3;
          goto LAB_004c77c6;
        }
        if (pbVar6 == pbVar2) {
          param_1[1] = uVar5;
        }
        else {
          param_2 = param_2 - uVar5;
          if (param_2 < param_3) {
            return 0;
          }
        }
      }
      else {
        pbVar3 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar3;
    } while (pbVar3 + param_3 < param_1 + 0x3e);
  }
  pbVar3 = (byte *)(param_1 + 2);
  pbVar6 = pbVar3;
  if (pbVar3 < pbVar2) {
    while (pbVar6 + param_3 < param_1 + 0x3e) {
      if (*pbVar6 == 0) {
        pbVar4 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = pbVar6[1];
        while (bVar1 == 0) {
          pbVar4 = pbVar4 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar4;
        }
        if (param_3 <= uVar5) {
          if (pbVar6 + param_3 < param_1 + 0x3e) {
            *param_1 = (int)(pbVar6 + param_3);
            param_1[1] = uVar5 - param_3;
          }
          else {
            *param_1 = (int)pbVar3;
LAB_004c77bf:
            param_1[1] = 0;
          }
LAB_004c77c6:
          *pbVar6 = (byte)param_3;
          return (int)(pbVar6 + 8) * 0x10 + (int)param_1 * -0xf;
        }
        param_2 = param_2 - uVar5;
        if (param_2 < param_3) {
          return 0;
        }
      }
      else {
        pbVar4 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar4;
      if (pbVar2 <= pbVar4) {
        return 0;
      }
    }
  }
  return 0;
}
#else
__declspec(naked) void BucketBlockAllocSplit(void)
{
    __asm {
        mov      edx, dword ptr [esp + 0xc]
        push     ebx
        push     ebp
        push     esi
        push     edi
        mov      edi, dword ptr [esp + 0x14]
        mov      eax, dword ptr [edi + 4]
        mov      ecx, dword ptr [edi]
        cmp      eax, edx
        mov      dword ptr [esp + 0x14], ecx
        mov      esi, ecx
        lea      ebx, [edi + 0xf8]
        jb       short L_76cb
        lea      eax, [ecx + edx]
        mov      byte ptr [ecx], dl
        cmp      eax, ebx
        jae      short L_76aa
        mov      esi, dword ptr [edi]
        mov      eax, dword ptr [edi + 4]
        add      esi, edx
        sub      eax, edx
        mov      dword ptr [edi], esi
        mov      dword ptr [edi + 4], eax
        jmp      short L_76b6
    L_76aa:
        lea      edx, [edi + 8]
        mov      dword ptr [edi + 4], 0
        mov      dword ptr [edi], edx
    L_76b6:
        lea      eax, [edi + edi*2]
        lea      eax, [eax + eax*4]
        mov      edx, eax
        lea      eax, [ecx + 8]
        shl      eax, 4
        sub      eax, edx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_76cb:
        add      eax, ecx
        cmp      byte ptr [eax], 0
        je       short L_76d4
        mov      esi, eax
    L_76d4:
        lea      eax, [esi + edx]
        cmp      eax, ebx
        mov      ebx, dword ptr [esp + 0x18]
        jae      short L_7754
    L_76df:
        mov      al, byte ptr [esi]
        test     al, al
        jne      short L_7721
        cmp      byte ptr [esi + 1], 0
        lea      eax, [esi + 1]
        mov      ecx, 1
        jne      short L_76fa
    L_76f3:
        inc      eax
        inc      ecx
        cmp      byte ptr [eax], 0
        je       short L_76f3
    L_76fa:
        cmp      ecx, edx
        jae      short L_7737
        mov      ebp, dword ptr [esp + 0x14]
        cmp      esi, ebp
        jne      short L_770f
        mov      dword ptr [edi + 4], ecx
        mov      esi, eax
        mov      ecx, ebp
        jmp      short L_7728
    L_770f:
        sub      ebx, ecx
        cmp      ebx, edx
        jb       L_77db
        mov      ecx, dword ptr [esp + 0x14]
        mov      esi, eax
        jmp      short L_7728
    L_7721:
        and      eax, 0xff
        add      esi, eax
    L_7728:
        lea      ebp, [esi + edx]
        lea      eax, [edi + 0xf8]
        cmp      ebp, eax
        jb       short L_76df
        jmp      short L_7754
    L_7737:
        lea      eax, [esi + edx]
        lea      ebx, [edi + 0xf8]
        cmp      eax, ebx
        jae      short L_774d
        sub      ecx, edx
        mov      dword ptr [edi], eax
        mov      dword ptr [edi + 4], ecx
        jmp      short L_77c6
    L_774d:
        lea      ecx, [edi + 8]
        mov      dword ptr [edi], ecx
        jmp      short L_77bf
    L_7754:
        lea      ebp, [edi + 8]
        mov      esi, ebp
        cmp      esi, ecx
        jae      short L_77db
    L_775d:
        lea      ecx, [esi + edx]
        lea      eax, [edi + 0xf8]
        cmp      ecx, eax
        jae      short L_77db
        mov      al, byte ptr [esi]
        test     al, al
        jne      short L_7793
        cmp      byte ptr [esi + 1], 0
        lea      eax, [esi + 1]
        mov      ecx, 1
        jne      short L_7785
    L_777e:
        inc      eax
        inc      ecx
        cmp      byte ptr [eax], 0
        je       short L_777e
    L_7785:
        cmp      ecx, edx
        jae      short L_77a7
        sub      ebx, ecx
        cmp      ebx, edx
        jb       short L_77db
        mov      esi, eax
        jmp      short L_779a
    L_7793:
        and      eax, 0xff
        add      esi, eax
    L_779a:
        cmp      esi, dword ptr [esp + 0x14]
        jb       short L_775d
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_77a7:
        lea      eax, [esi + edx]
        lea      ebx, [edi + 0xf8]
        cmp      eax, ebx
        jae      short L_77bd
        sub      ecx, edx
        mov      dword ptr [edi], eax
        mov      dword ptr [edi + 4], ecx
        jmp      short L_77c6
    L_77bd:
        mov      dword ptr [edi], ebp
    L_77bf:
        mov      dword ptr [edi + 4], 0
    L_77c6:
        lea      eax, [edi + edi*2]
        mov      byte ptr [esi], dl
        lea      edx, [eax + eax*4]
        lea      eax, [esi + 8]
        shl      eax, 4
        sub      eax, edx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_77db:
        pop      edi
        pop      esi
        pop      ebp
        xor      eax, eax
        pop      ebx
        ret
    }
}
#endif
