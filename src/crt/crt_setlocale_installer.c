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

extern unsigned int g_dispatchSave117;
extern unsigned int g_dispatchSave116;
extern unsigned int g_crtLocaleEnvVarTbl;
extern unsigned int g_dispatchSave115;
extern unsigned int g_crtTlsSlot;
extern unsigned int g_dispatchSave1433;
extern unsigned int g_ctypeByteTable;
extern unsigned int g_dispatchSave1435;
extern unsigned int g_dispatchSave1436;
extern unsigned int g_dispatchSave1437;
extern unsigned int g_dispatchSave1438;
extern unsigned int g_dispatchSave1439;
extern unsigned int g_dispatchSave1440;
extern unsigned int g_dispatchSave1467;
extern unsigned int g_iat_GetCPInfo;
extern void BuildCharacterCaseTables(void);
extern void CRTSignalDispatch(void);
extern void InitGlobalsAndZero(void);
extern void Lock(void);
extern void TableLookupIatCall(void);
extern void TranslateMsgId(void);

extern unsigned int g_dispatchSave114;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
undefined4 CrtSetlocaleInstaller(undefined4 param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  BYTE *pBVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  _cpinfo local_14;
  
  Lock(0x19);
  CodePage = CRTSignalDispatch(param_1);
  if (CodePage == g_dispatchSave1435) {
    TableLookupIatCall(0x19);
    return 0;
  }
  if (CodePage == 0) {
    InitGlobalsAndZero();
    BuildCharacterCaseTables();
    TableLookupIatCall(0x19);
    return 0;
  }
  iVar10 = 0;
  pUVar5 = &g_dispatchSave116;
  do {
    if (*pUVar5 == CodePage) {
      puVar14 = &g_dispatchSave1433;
      for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      *(undefined1 *)puVar14 = 0;
      uVar7 = 0;
      iVar10 = iVar10 * 0x30;
      pbVar12 = (byte *)(iVar10 + 0x522320);
      do {
        bVar3 = *pbVar12;
        for (pbVar13 = pbVar12; (bVar3 != 0 && (bVar3 = pbVar13[1], bVar3 != 0));
            pbVar13 = pbVar13 + 2) {
          uVar8 = (uint)*pbVar13;
          if (uVar8 <= bVar3) {
            bVar4 = (&g_dispatchSave117)[uVar7];
            do {
              pbVar2 = (byte *)((int)&g_dispatchSave1433 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          bVar3 = pbVar13[2];
        }
        uVar7 = uVar7 + 1;
        pbVar12 = pbVar12 + 8;
      } while (uVar7 < 4);
      g_dispatchSave1467 = 1;
      g_dispatchSave1435 = CodePage;
      g_dispatchSave1436 = TranslateMsgId(CodePage);
      g_dispatchSave1437 = *(undefined4 *)(iVar10 + 0x522314);
      g_dispatchSave1438 = *(undefined4 *)(iVar10 + 0x522318);
      g_dispatchSave1439 = *(undefined4 *)(iVar10 + 0x52231c);
      goto LAB_004c9672;
    }
    pUVar5 = pUVar5 + 0xc;
    iVar10 = iVar10 + 1;
  } while (pUVar5 < &g_crtTlsSlot);
  BVar6 = g_arr_476f30_disp_34(CodePage,&local_14);
  if (BVar6 == 1) {
    puVar14 = &g_dispatchSave1433;
    for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    *(undefined1 *)puVar14 = 0;
    g_dispatchSave1436 = 0;
    if (local_14.MaxCharSize < 2) {
      g_dispatchSave1467 = 0;
      g_dispatchSave1435 = CodePage;
    }
    else {
      g_dispatchSave1435 = CodePage;
      if (local_14.LeadByte[0] != '\0') {
        pBVar11 = local_14.LeadByte + 1;
        do {
          bVar3 = *pBVar11;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar11[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            *(byte *)((int)&g_dispatchSave1433 + uVar7 + 1) =
                 *(byte *)((int)&g_dispatchSave1433 + uVar7 + 1) | 4;
          }
          pBVar1 = pBVar11 + 1;
          pBVar11 = pBVar11 + 2;
        } while (*pBVar1 != 0);
      }
      uVar7 = 1;
      do {
        *(byte *)((int)&g_dispatchSave1433 + uVar7 + 1) = *(byte *)((int)&g_dispatchSave1433 + uVar7 + 1) | 8;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 0xff);
      g_dispatchSave1436 = TranslateMsgId(CodePage);
      g_dispatchSave1467 = 1;
    }
    g_dispatchSave1437 = 0;
    g_dispatchSave1438 = 0;
    g_dispatchSave1439 = 0;
  }
  else {
    if (g_dispatchSave1440 == 0) {
      TableLookupIatCall(0x19);
      return 0xffffffff;
    }
    InitGlobalsAndZero();
  }
LAB_004c9672:
  BuildCharacterCaseTables();
  TableLookupIatCall(0x19);
  return 0;
}
#else
__declspec(naked) void CrtSetlocaleInstaller(void)
{
    __asm {
        sub      esp, 0x14
        push     ebx
        push     ebp
        push     esi
        push     edi
        push     0x19
        call     Lock
        mov      eax, dword ptr [esp + 0x2c]
        add      esp, 4
        push     eax
        call     CRTSignalDispatch
        mov      ecx, eax
        mov      eax, dword ptr [g_dispatchSave1435]
        add      esp, 4
        cmp      ecx, eax
        mov      dword ptr [esp + 0x28], ecx
        jne      short L_9561
        push     0x19
        call     TableLookupIatCall
        add      esp, 4
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x14
        ret
    L_9561:
        test     ecx, ecx
        jne      short L_9583
        call     InitGlobalsAndZero
        call     BuildCharacterCaseTables
        push     0x19
        call     TableLookupIatCall
        add      esp, 4
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x14
        ret
    L_9583:
        xor      edx, edx
        mov      eax, OFFSET g_dispatchSave116
    L_958a:
        cmp      dword ptr [eax], ecx
        je       L_96a0
        add      eax, 0x30
        inc      edx
        cmp      eax, OFFSET g_crtTlsSlot
        jb       short L_958a
        lea      edx, [esp + 0x10]
        push     edx
        push     ecx
        call     dword ptr [g_iat_GetCPInfo]
        mov      esi, 1
        cmp      eax, esi
        jne      L_9664
        mov      ecx, 0x40
        xor      eax, eax
        mov      edi, OFFSET g_dispatchSave1433
        rep stosd
        mov      ecx, dword ptr [esp + 0x10]
        stosb
        mov      edi, dword ptr [esp + 0x28]
        xor      eax, eax
        cmp      ecx, esi
        mov      dword ptr [g_dispatchSave1435], edi
        mov      dword ptr [g_dispatchSave1436], eax
        jbe      short L_964c
        mov      al, byte ptr [esp + 0x16]
        test     al, al
        je       short L_961d
        lea      edx, [esp + 0x17]
    L_95ea:
        mov      cl, byte ptr [edx]
        test     cl, cl
        je       short L_961d
        xor      eax, eax
        and      ecx, 0xff
        mov      al, byte ptr [edx - 1]
        cmp      eax, ecx
        ja       short L_9613
    L_95ff:
        mov      bl, byte ptr [eax + g_ctypeByteTable]
        or       bl, 4
        mov      byte ptr [eax + g_ctypeByteTable], bl
        inc      eax
        cmp      eax, ecx
        jbe      short L_95ff
    L_9613:
        mov      al, byte ptr [edx + 1]
        add      edx, 2
        test     al, al
        jne      short L_95ea
    L_961d:
        mov      eax, esi
    L_961f:
        mov      bl, byte ptr [eax + g_ctypeByteTable]
        or       bl, 8
        mov      byte ptr [eax + g_ctypeByteTable], bl
        inc      eax
        cmp      eax, 0xff
        jb       short L_961f
        push     edi
        call     TranslateMsgId
        add      esp, 4
        mov      dword ptr [g_dispatchSave1436], eax
        mov      dword ptr [g_dispatchSave1467], esi
        jmp      short L_9651
    L_964c:
        mov      dword ptr [g_dispatchSave1467], eax
    L_9651:
        xor      eax, eax
        mov      dword ptr [g_dispatchSave1437], eax
        mov      dword ptr [g_dispatchSave1438], eax
        mov      dword ptr [g_dispatchSave1439], eax
        jmp      short L_9672
    L_9664:
        mov      eax, dword ptr [g_dispatchSave1440]
        test     eax, eax
        je       short L_968b
        call     InitGlobalsAndZero
    L_9672:
        call     BuildCharacterCaseTables
        push     0x19
        call     TableLookupIatCall
        add      esp, 4
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x14
        ret
    L_968b:
        push     0x19
        call     TableLookupIatCall
        add      esp, 4
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x14
        ret
    L_96a0:
        mov      ecx, 0x40
        xor      eax, eax
        mov      edi, OFFSET g_dispatchSave1433
        lea      ebx, [edx + edx*2]
        rep stosd
        stosb
        xor      edi, edi
        shl      ebx, 4
        lea      ebp, [ebx + g_dispatchSave114]
    L_96bd:
        mov      al, byte ptr [ebp]
        mov      esi, ebp
        test     al, al
        je       short L_96f6
    L_96c6:
        mov      cl, byte ptr [esi + 1]
        test     cl, cl
        je       short L_96f6
        xor      eax, eax
        and      ecx, 0xff
        mov      al, byte ptr [esi]
        cmp      eax, ecx
        ja       short L_96ec
        mov      dl, byte ptr [edi + g_dispatchSave117]
    L_96e1:
        or       byte ptr [eax + g_ctypeByteTable], dl
        inc      eax
        cmp      eax, ecx
        jbe      short L_96e1
    L_96ec:
        mov      al, byte ptr [esi + 2]
        add      esi, 2
        test     al, al
        jne      short L_96c6
    L_96f6:
        inc      edi
        add      ebp, 8
        cmp      edi, 4
        jb       short L_96bd
        mov      eax, dword ptr [esp + 0x28]
        mov      dword ptr [g_dispatchSave1467], 1
        push     eax
        mov      dword ptr [g_dispatchSave1435], eax
        call     TranslateMsgId
        mov      ecx, dword ptr [ebx + g_crtLocaleEnvVarTbl]
        mov      edx, dword ptr [ebx + g_dispatchSave115]
        mov      dword ptr [g_dispatchSave1436], eax
        lea      eax, [ebx + g_crtLocaleEnvVarTbl]
        add      esp, 4
        mov      dword ptr [g_dispatchSave1437], ecx
        mov      eax, dword ptr [eax + 8]
        mov      dword ptr [g_dispatchSave1438], edx
        mov      dword ptr [g_dispatchSave1439], eax
        jmp      L_9672
    }
}
#endif
