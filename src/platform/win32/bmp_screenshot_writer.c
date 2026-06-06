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

extern unsigned int g_dispatchSave830;
extern void Helper_FClose(void);
extern void Helper_FOpen(void);
extern void WrapThreeDispatch(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BmpScreenshotWriter(int param_1,byte *param_2,int param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int local_c3c;
  undefined2 local_c38;
  int local_c36;
  undefined2 local_c32;
  undefined2 local_c30;
  undefined4 local_c2e;
  undefined4 local_c28;
  int local_c24;
  int local_c20;
  undefined2 local_c1c;
  undefined2 local_c1a;
  undefined4 local_c18;
  int local_c14;
  undefined4 local_c10;
  undefined4 local_c0c;
  undefined4 local_c08;
  undefined4 local_c04;
  undefined1 local_c00;
  byte local_bff [3071];
  
  local_c38 = 0x4d42;
  local_c2e = 0x36;
  local_c28 = 0x28;
  local_c14 = param_5 * param_4 * 3;
  local_c24 = param_4;
  local_c36 = (param_5 * param_4 + 0x12) * 3;
  local_c20 = param_5;
  local_c32 = 0;
  local_c30 = 0;
  local_c1c = 1;
  local_c1a = 0x18;
  local_c18 = 0;
  local_c10 = 0;
  local_c0c = 0;
  local_c08 = 0;
  local_c04 = 0;
  if ((((param_1 != 0) && (param_2 != (byte *)0x0)) && (0 < param_3)) &&
     (((param_4 < 0x401 && (0 < param_5)) &&
      (iVar2 = Helper_FOpen(param_1,&g_dispatchSave830), iVar2 != 0)))) {
    WrapThreeDispatch(&local_c38,0xe,1,iVar2);
    WrapThreeDispatch(&local_c28,0x28,1,iVar2);
    iVar3 = param_3 / 2;
    param_2 = (byte *)((int)param_2 + (param_5 + -1) * iVar3 * 2);
    if (0 < param_5) {
      local_c3c = param_5;
      do {
        if (param_6 == 0) {
          if (0 < param_4) {
            pbVar4 = local_bff;
            iVar5 = param_4;
            pbVar6 = param_2;
            do {
              param_3 = CONCAT22((short)((uint)param_3 >> 0x10),*(undefined2 *)pbVar6);
              pbVar4[1] = -((param_3 >> 10 & 1U) != 0) & 7U | (char)(param_3 >> 10) << 3;
              bVar1 = *pbVar6;
              *pbVar4 = -((param_3 >> 5 & 1U) != 0) & 7U | (char)(param_3 >> 5) << 3;
              pbVar6 = pbVar6 + 2;
              iVar5 = iVar5 + -1;
              pbVar4[-1] = -((bVar1 & 1) != 0) & 7U | bVar1 << 3;
              pbVar4 = pbVar4 + 3;
            } while (iVar5 != 0);
          }
        }
        else if (0 < param_4) {
          pbVar4 = local_bff;
          iVar5 = param_4;
          pbVar6 = param_2;
          do {
            param_3 = CONCAT22((short)((uint)param_3 >> 0x10),*(undefined2 *)pbVar6);
            pbVar4[1] = -((param_3 >> 0xb & 1U) != 0) & 7U | (char)(param_3 >> 0xb) << 3;
            bVar1 = *pbVar6;
            *pbVar4 = -((param_3 >> 5 & 1U) != 0) & 3U | (char)(param_3 >> 5) << 2;
            pbVar6 = pbVar6 + 2;
            iVar5 = iVar5 + -1;
            pbVar4[-1] = -((bVar1 & 1) != 0) & 7U | bVar1 << 3;
            pbVar4 = pbVar4 + 3;
          } while (iVar5 != 0);
        }
        WrapThreeDispatch(&local_c00,param_4 * 3,1,iVar2);
        param_2 = param_2 + iVar3 * -2;
        local_c3c = local_c3c + -1;
      } while (local_c3c != 0);
    }
    Helper_FClose(iVar2);
  }
  return;
}
#else
__declspec(naked) void BmpScreenshotWriter(void)
{
    __asm {
        sub      esp, 0xc40
        push     ebx
        mov      ebx, dword ptr [esp + 0xc54]
        push     ebp
        push     esi
        mov      esi, dword ptr [esp + 0xc60]
        push     edi
        mov      eax, esi
        mov      word ptr [esp + 0x18], 0x4d42
        imul     eax, ebx
        mov      dword ptr [esp + 0x22], 0x36
        mov      dword ptr [esp + 0x28], 0x28
        lea      ecx, [eax + 0x12]
        lea      edx, [eax + eax*2]
        mov      eax, dword ptr [esp + 0xc54]
        mov      dword ptr [esp + 0x2c], ebx
        lea      ecx, [ecx + ecx*2]
        mov      dword ptr [esp + 0x30], esi
        mov      dword ptr [esp + 0x1a], ecx
        xor      ecx, ecx
        cmp      eax, ecx
        mov      word ptr [esp + 0x1e], cx
        mov      word ptr [esp + 0x20], cx
        mov      word ptr [esp + 0x34], 1
        mov      word ptr [esp + 0x36], 0x18
        mov      dword ptr [esp + 0x38], ecx
        mov      dword ptr [esp + 0x3c], edx
        mov      dword ptr [esp + 0x40], ecx
        mov      dword ptr [esp + 0x44], ecx
        mov      dword ptr [esp + 0x48], ecx
        mov      dword ptr [esp + 0x4c], ecx
        je       L_485e
        mov      ebp, dword ptr [esp + 0xc58]
        cmp      ebp, ecx
        je       L_485e
        mov      edi, dword ptr [esp + 0xc5c]
        cmp      edi, 1
        jl       L_485e
        cmp      ebx, 0x400
        jg       L_485e
        cmp      esi, 1
        jl       L_485e
        push     OFFSET g_dispatchSave830
        push     eax
        call     Helper_FOpen
        add      esp, 8
        mov      dword ptr [esp + 0x10], eax
        test     eax, eax
        je       L_485e
        push     eax
        push     1
        lea      eax, [esp + 0x20]
        push     0xe
        push     eax
        call     WrapThreeDispatch
        mov      ecx, dword ptr [esp + 0x20]
        add      esp, 0x10
        lea      edx, [esp + 0x28]
        push     ecx
        push     1
        push     0x28
        push     edx
        call     WrapThreeDispatch
        mov      eax, edi
        lea      ecx, [esi - 1]
        cdq
        sub      eax, edx
        add      esp, 0x10
        sar      eax, 1
        imul     ecx, eax
        test     esi, esi
        lea      edx, [ebp + ecx*2]
        mov      dword ptr [esp + 0xc5c], eax
        mov      dword ptr [esp + 0xc58], edx
        jle      L_4851
        mov      dword ptr [esp + 0x14], esi
    L_472b:
        mov      eax, dword ptr [esp + 0xc68]
        test     eax, eax
        je       short L_47a6
        test     ebx, ebx
        jle      L_4810
        mov      esi, dword ptr [esp + 0xc58]
        lea      ecx, [esp + 0x51]
        mov      ebp, ebx
    L_474b:
        mov      di, word ptr [esi]
        mov      eax, edi
        sar      eax, 0xb
        and      al, 0x1f
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        and      edx, 7
        shl      al, 3
        or       dl, al
        mov      eax, edi
        sar      eax, 5
        and      al, 0x3f
        mov      byte ptr [ecx + 1], dl
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        and      edx, 3
        shl      al, 2
        or       dl, al
        mov      al, byte ptr [esi]
        and      al, 0x1f
        mov      byte ptr [ecx], dl
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        add      esi, 2
        and      edx, 7
        add      ecx, 3
        shl      al, 3
        or       dl, al
        dec      ebp
        mov      byte ptr [ecx - 4], dl
        jne      L_474b
        jmp      short L_4810
    L_47a6:
        test     ebx, ebx
        jle      short L_4810
        mov      esi, dword ptr [esp + 0xc58]
        lea      ecx, [esp + 0x51]
        mov      ebp, ebx
    L_47b7:
        mov      di, word ptr [esi]
        mov      eax, edi
        sar      eax, 0xa
        and      al, 0x1f
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        and      edx, 7
        shl      al, 3
        or       dl, al
        mov      eax, edi
        sar      eax, 5
        and      al, 0x1f
        mov      byte ptr [ecx + 1], dl
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        and      edx, 7
        shl      al, 3
        or       dl, al
        mov      al, byte ptr [esi]
        and      al, 0x1f
        mov      byte ptr [ecx], dl
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        add      esi, 2
        and      edx, 7
        add      ecx, 3
        shl      al, 3
        or       dl, al
        dec      ebp
        mov      byte ptr [ecx - 4], dl
        jne      short L_47b7
    L_4810:
        mov      eax, dword ptr [esp + 0x10]
        lea      ecx, [ebx + ebx*2]
        push     eax
        push     1
        lea      edx, [esp + 0x58]
        push     ecx
        push     edx
        call     WrapThreeDispatch
        mov      eax, dword ptr [esp + 0xc6c]
        mov      ecx, dword ptr [esp + 0xc68]
        neg      eax
        add      esp, 0x10
        lea      edx, [ecx + eax*2]
        mov      eax, dword ptr [esp + 0x14]
        dec      eax
        mov      dword ptr [esp + 0xc58], edx
        mov      dword ptr [esp + 0x14], eax
        jne      L_472b
    L_4851:
        mov      eax, dword ptr [esp + 0x10]
        push     eax
        call     Helper_FClose
        add      esp, 4
    L_485e:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc40
        ret
    }
}
#endif
