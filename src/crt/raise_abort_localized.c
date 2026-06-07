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

extern unsigned int g_crtMsg_Microsoft;
extern unsigned int g_crtMsg_LineBreak;
extern unsigned int g_crtMsg_Runtime;
extern unsigned int g_crtMsg_Ellipsis;
extern unsigned int g_crtMsg_ProgramTag;
extern unsigned int g_crtFdCloseSlot;
extern unsigned int g_crtAbortBase;
extern unsigned int g_crtFpuSlot1;
extern unsigned int g_crtCType;
extern unsigned int g_crtCleanupFlag;
extern unsigned int g_crtHandleTable;
extern unsigned int g_iat_GetModuleFileNameA;
extern unsigned int g_iat_WriteFile;
extern unsigned int g_iat_GetStdHandle;
extern void LazyLoadInvoke(void);
extern void Strncpy(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void RaiseAbortLocalized(undefined *param_1)

{
  char cVar1;
  undefined **ppuVar2;
  DWORD DVar3;
  HANDLE hFile;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  CHAR *pCVar10;
  char *pcVar11;
  DWORD local_1a8;
  char local_1a4 [100];
  char acStack_140 [60];
  CHAR local_104 [260];
  
  ppuVar2 = (undefined **)&g_crtAbortBase;
  iVar8 = 0;
  do {
    if (param_1 == *ppuVar2) break;
    ppuVar2 = ppuVar2 + 2;
    iVar8 = iVar8 + 1;
  } while (ppuVar2 < &g_crtCType);
  if (param_1 == (undefined *)(&g_crtAbortBase)[iVar8 * 2]) {
    if ((g_crtCleanupFlag == 1) || ((g_crtCleanupFlag == 0 && (g_crtFdCloseSlot == 1)))) {
      if ((g_crtHandleTable == 0) ||
         (hFile = *(HANDLE *)(g_crtHandleTable + 0x48), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar7 = *(char **)(iVar8 * 8 + 0x52290c);
      uVar5 = 0xffffffff;
      pcVar9 = pcVar7;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      WriteFile(hFile,pcVar7,~uVar5 - 1,&local_1a8,(LPOVERLAPPED)0x0);
    }
    else if (param_1 != (undefined *)0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_104,0x104);
      if (DVar3 == 0) {
        pcVar7 = "<program name unknown>";
        pCVar10 = local_104;
        for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined4 *)pCVar10 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pCVar10 = pCVar10 + 4;
        }
        *(undefined2 *)pCVar10 = *(undefined2 *)pcVar7;
        pCVar10[2] = pcVar7[2];
      }
      uVar5 = 0xffffffff;
      pcVar7 = local_104;
      pcVar9 = local_104;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (0x3c < ~uVar5) {
        uVar5 = 0xffffffff;
        pcVar7 = local_104;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        pcVar7 = acStack_140 + ~uVar5;
        _strncpy(pcVar7,"...",3);
      }
      pcVar9 = "Runtime Error!\n\nProgram: ";
      pcVar11 = local_1a4;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar11 = pcVar11 + 4;
      }
      *(undefined2 *)pcVar11 = *(undefined2 *)pcVar9;
      uVar5 = 0xffffffff;
      do {
        pcVar9 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar4 = -1;
      pcVar7 = local_1a4;
      do {
        pcVar11 = pcVar7;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar11 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar11;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar5;
      pcVar9 = pcVar11 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar5 = 0xffffffff;
      pcVar7 = "\n\n";
      do {
        pcVar9 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar4 = -1;
      pcVar7 = local_1a4;
      do {
        pcVar11 = pcVar7;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar11 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar11;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar5;
      pcVar9 = pcVar11 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar5 = 0xffffffff;
      pcVar7 = *(char **)(iVar8 * 8 + 0x52290c);
      do {
        pcVar9 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar8 = -1;
      pcVar7 = local_1a4;
      do {
        pcVar11 = pcVar7;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar11 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar11;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar5;
      pcVar9 = pcVar11 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      LazyLoadInvoke(local_1a4,"Microsoft Visual C++ Runtime Library");
      return;
    }
  }
  return;
}
#else
__declspec(naked) void RaiseAbortLocalized(void)
{
    __asm {
        mov      ecx, dword ptr [esp + 4]
        sub      esp, 0x1a8
        mov      eax, OFFSET g_crtAbortBase
        push     ebx
        push     ebp
        push     esi
        push     edi
        xor      ebp, ebp
    L_c085:
        cmp      ecx, dword ptr [eax]
        je       short L_c094
        add      eax, 8
        inc      ebp
        cmp      eax, OFFSET g_crtCType
        jb       short L_c085
    L_c094:
        cmp      ecx, dword ptr [ebp*8 + g_crtAbortBase]
        jne      L_c23b
        mov      eax, dword ptr [g_crtCleanupFlag]
        cmp      eax, 1
        je       L_c1fd
        test     eax, eax
        jne      short L_c0c0
        cmp      dword ptr [g_crtFdCloseSlot], 1
        je       L_c1fd
    L_c0c0:
        cmp      ecx, 0xfc
        je       L_c23b
        lea      eax, [esp + 0xb4]
        push     0x104
        push     eax
        push     0
        call     dword ptr [g_iat_GetModuleFileNameA]
        test     eax, eax
        jne      short L_c0fb
        mov      ecx, 5
        mov      esi, OFFSET g_crtMsg_ProgramTag
        lea      edi, [esp + 0xb4]
        rep movsd
        movsw
        movsb
    L_c0fb:
        lea      edi, [esp + 0xb4]
        or       ecx, 0xffffffff
        xor      eax, eax
        lea      ebx, [esp + 0xb4]
        repne scasb
        not      ecx
        cmp      ecx, 0x3c
        jbe      short L_c144
        lea      edi, [esp + 0xb4]
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        dec      ecx
        push     3
        mov      ebx, ecx
        lea      ecx, [esp + 0xb8]
        sub      ecx, 0x3b
        push     OFFSET g_crtMsg_Ellipsis
        add      ebx, ecx
        push     ebx
        call     Strncpy
        add      esp, 0xc
    L_c144:
        mov      ecx, 6
        mov      esi, OFFSET g_crtMsg_Runtime
        lea      edi, [esp + 0x14]
        xor      eax, eax
        rep movsd
        movsw
        or       ecx, 0xffffffff
        mov      edi, ebx
        repne scasb
        not      ecx
        sub      edi, ecx
        lea      edx, [esp + 0x14]
        mov      ebx, ecx
        mov      esi, edi
        or       ecx, 0xffffffff
        mov      edi, edx
        repne scasb
        mov      ecx, ebx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, ebx
        lea      edx, [esp + 0x14]
        and      ecx, 3
        push     0x12010
        rep movsb
        mov      edi, OFFSET g_crtMsg_LineBreak
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        sub      edi, ecx
        push     OFFSET g_crtMsg_Microsoft
        mov      esi, edi
        mov      ebx, ecx
        mov      edi, edx
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, ebx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, ebx
        lea      edx, [esp + 0x1c]
        and      ecx, 3
        rep movsb
        mov      edi, dword ptr [ebp*8 + g_crtFpuSlot1]
        or       ecx, 0xffffffff
        repne scasb
        not      ecx
        sub      edi, ecx
        mov      esi, edi
        mov      ebx, ecx
        mov      edi, edx
        or       ecx, 0xffffffff
        repne scasb
        mov      ecx, ebx
        dec      edi
        shr      ecx, 2
        rep movsd
        mov      ecx, ebx
        lea      eax, [esp + 0x1c]
        and      ecx, 3
        push     eax
        rep movsb
        call     LazyLoadInvoke
        add      esp, 0xc
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x1a8
        ret
    L_c1fd:
        mov      eax, dword ptr [g_crtHandleTable]
        test     eax, eax
        je       short L_c20e
        mov      esi, dword ptr [eax + 0x48]
        cmp      esi, -1
        jne      short L_c218
    L_c20e:
        push     -0xc
        call     dword ptr [g_iat_GetStdHandle]
        mov      esi, eax
    L_c218:
        mov      edx, dword ptr [ebp*8 + g_crtFpuSlot1]
        lea      ecx, [esp + 0x10]
        push     0
        push     ecx
        mov      edi, edx
        or       ecx, 0xffffffff
        xor      eax, eax
        repne scasb
        not      ecx
        dec      ecx
        push     ecx
        push     edx
        push     esi
        call     dword ptr [g_iat_WriteFile]
    L_c23b:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x1a8
        ret
    }
}
#endif
