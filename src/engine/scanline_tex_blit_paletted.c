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

extern unsigned int g_viewportW;
extern unsigned int g_viewportH;
extern unsigned int g_dispatchSave1707;
extern unsigned int g_dispatchSave1708;
extern unsigned int g_dispatchSave1340;
extern unsigned int g_dispatchSave1345;
extern unsigned int g_dispatchSave1346;
extern unsigned int g_dispatchSave1357;
extern unsigned int g_dispatchSave1358;
extern s32 g_clipMinScratch;
extern unsigned int g_dispatchSave1367;
extern unsigned int g_dispatchSave1371;
extern unsigned int g_dispatchSave1373;
extern unsigned int g_dispatchSave1374;
extern unsigned int g_dispatchSave1375;
extern unsigned int g_dispatchSave1377;
extern unsigned int g_dispatchSave1378;
extern unsigned int g_dispatchSave1380;
extern unsigned int g_dispatchSave1381;
extern unsigned int g_dispatchSave1383;
extern unsigned int g_dispatchSave1387;
extern unsigned int g_dispatchSave1388;
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void ScanlineTexBlitPaletted(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if ((((g_viewportX != 0) && (g_dispatchSave1378 < g_viewportW)) && (g_dispatchSave1381 < g_viewportH)) &&
     ((-1 < g_dispatchSave1380 && (-1 < g_dispatchSave1383)))) {
    g_dispatchSave1708 = g_dispatchSave1380 - g_dispatchSave1378;
    g_dispatchSave1707 = g_dispatchSave1383 - g_dispatchSave1381;
    if ((0 < g_dispatchSave1708) && (0 < g_dispatchSave1707)) {
      uVar2 = g_dispatchSave1374 * 0x10000;
      g_dispatchSave1373 = g_dispatchSave1373 * 0x10000;
      uVar5 = g_dispatchSave1371 * 0x10000;
      g_dispatchSave1357 = (int)(g_dispatchSave1373 + g_dispatchSave1371 * -0x10000) / g_dispatchSave1708;
      g_dispatchSave1377 = g_dispatchSave1377 * 0x10000;
      iVar3 = (int)(g_dispatchSave1377 + g_dispatchSave1374 * -0x10000) / g_dispatchSave1707;
      g_dispatchSave1371 = uVar5;
      if (g_dispatchSave1378 < 0) {
        g_dispatchSave1371 = uVar5 - g_dispatchSave1357 * g_dispatchSave1378;
        g_dispatchSave1708 = g_dispatchSave1708 + g_dispatchSave1378;
        g_dispatchSave1378 = 0;
      }
      g_dispatchSave1374 = uVar2;
      if (g_dispatchSave1381 < 0) {
        g_dispatchSave1374 = uVar2 - iVar3 * g_dispatchSave1381;
        g_dispatchSave1707 = g_dispatchSave1707 + g_dispatchSave1381;
        g_dispatchSave1381 = 0;
      }
      if (g_viewportW <= g_dispatchSave1380) {
        g_dispatchSave1708 = g_viewportW - g_dispatchSave1378;
      }
      if (g_viewportH <= g_dispatchSave1383) {
        g_dispatchSave1707 = g_viewportH - g_dispatchSave1381;
      }
      g_dispatchSave1346 = (undefined2 *)(g_viewportX + g_viewportY * g_dispatchSave1381 + g_dispatchSave1378 * 2);
      iVar4 = (g_dispatchSave1367 & 0xf0) * 0x2000 + g_dispatchSave1340;
      uVar2 = (g_dispatchSave1403 & 0xf) << 0x10;
      g_dispatchSave1358 = iVar3;
      g_dispatchSave1403 = uVar2;
      iVar6 = g_dispatchSave1708;
      while (0 < g_dispatchSave1707) {
        g_dispatchSave1404 = g_dispatchSave1400 + ((g_dispatchSave1374 >> 0x10 & 0xff) * 0x100 + uVar2) * 2;
        g_dispatchSave1345 = g_dispatchSave1346;
        iVar7 = g_dispatchSave1707;
        g_dispatchSave1387 = g_dispatchSave1371;
        for (g_clipMinScratch = iVar6; 0 < g_clipMinScratch; g_clipMinScratch = g_clipMinScratch + -1) {
          uVar1 = *(ushort *)(g_dispatchSave1404 + (g_dispatchSave1387 >> 0x10 & 0xff) * 2);
          if (uVar1 != 0) {
            *g_dispatchSave1345 = *(undefined2 *)(iVar4 + (uint)uVar1 * 2);
            iVar6 = g_dispatchSave1708;
            iVar7 = g_dispatchSave1707;
          }
          g_dispatchSave1387 = g_dispatchSave1387 + g_dispatchSave1357;
          g_dispatchSave1345 = g_dispatchSave1345 + 1;
          iVar3 = g_dispatchSave1358;
          uVar2 = g_dispatchSave1403;
        }
        g_dispatchSave1374 = g_dispatchSave1374 + iVar3;
        g_dispatchSave1346 = (undefined2 *)((int)g_dispatchSave1346 + g_viewportY);
        g_dispatchSave1707 = iVar7 + -1;
      }
    }
  }
  return;
}
#else
__declspec(naked) void ScanlineTexBlitPaletted(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     ebp
        push     esi
        test     eax, eax
        push     edi
        je       L_05d4
        mov      ecx, dword ptr [g_dispatchSave1378]
        mov      eax, dword ptr [g_viewportW]
        cmp      ecx, eax
        jge      L_05d4
        mov      ebx, dword ptr [g_dispatchSave1381]
        mov      eax, dword ptr [g_viewportH]
        cmp      ebx, eax
        jge      L_05d4
        mov      esi, dword ptr [g_dispatchSave1380]
        test     esi, esi
        jl       L_05d4
        mov      edi, dword ptr [g_dispatchSave1383]
        test     edi, edi
        jl       L_05d4
        sub      esi, ecx
        sub      edi, ebx
        cmp      esi, 1
        mov      dword ptr [g_dispatchSave1708], esi
        mov      dword ptr [g_dispatchSave1707], edi
        jl       L_05d4
        cmp      edi, 1
        jl       L_05d4
        mov      eax, dword ptr [g_dispatchSave1374]
        mov      edx, dword ptr [g_dispatchSave1371]
        shl      eax, 0x10
        mov      dword ptr [g_dispatchSave1374], eax
        mov      eax, dword ptr [g_dispatchSave1373]
        shl      eax, 0x10
        shl      edx, 0x10
        mov      dword ptr [g_dispatchSave1373], eax
        sub      eax, edx
        mov      dword ptr [g_dispatchSave1371], edx
        mov      ebp, dword ptr [g_dispatchSave1377]
        cdq
        idiv     esi
        mov      edx, dword ptr [g_dispatchSave1374]
        shl      ebp, 0x10
        mov      dword ptr [g_dispatchSave1377], ebp
        mov      dword ptr [g_dispatchSave1357], eax
        mov      eax, ebp
        sub      eax, edx
        cdq
        idiv     edi
        test     ecx, ecx
        mov      ebp, eax
        mov      dword ptr [g_dispatchSave1358], ebp
        jge      L_0456
        mov      eax, dword ptr [g_dispatchSave1357]
        mov      edx, dword ptr [g_dispatchSave1371]
        imul     eax, ecx
        sub      edx, eax
        add      esi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1371], edx
        mov      dword ptr [g_dispatchSave1708], esi
        mov      dword ptr [g_dispatchSave1378], ecx
    L_0456:
        test     ebx, ebx
        jge      L_047b
        mov      edx, ebp
        mov      eax, dword ptr [g_dispatchSave1374]
        imul     edx, ebx
        sub      eax, edx
        add      edi, ebx
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374], eax
        mov      dword ptr [g_dispatchSave1707], edi
        mov      dword ptr [g_dispatchSave1381], ebx
    L_047b:
        mov      eax, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380]
        cmp      edx, eax
        jl       L_0494
        sub      eax, ecx
        mov      esi, eax
        mov      dword ptr [g_dispatchSave1708], esi
    L_0494:
        mov      eax, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383]
        cmp      edx, eax
        jl       L_04ad
        sub      eax, ebx
        mov      edi, eax
        mov      dword ptr [g_dispatchSave1707], edi
    L_04ad:
        mov      edx, dword ptr [g_viewportY]
        mov      eax, dword ptr [g_viewportX]
        imul     edx, ebx
        add      eax, edx
        mov      ebx, dword ptr [g_dispatchSave1340]
        lea      eax, [eax + ecx*2]
        mov      ecx, dword ptr [g_dispatchSave1367]
        and      ecx, 0xff
        mov      dword ptr [g_dispatchSave1346], eax
        mov      eax, dword ptr [g_dispatchSave1403]
        and      ecx, 0xfffffff0
        shl      ecx, 0xd
        and      eax, 0xf
        add      ecx, ebx
        shl      eax, 0x10
        test     edi, edi
        mov      dword ptr [g_dispatchSave1403], eax
        jle      L_05d4
    L_04f7:
        mov      edx, dword ptr [g_dispatchSave1371]
        mov      ebx, dword ptr [g_dispatchSave1400]
        mov      dword ptr [g_dispatchSave1387], edx
        xor      edx, edx
        mov      dh, byte ptr [g_dispatchSave1375]
        mov      dword ptr [g_clipMinScratch], esi
        add      edx, eax
        test     esi, esi
        lea      edx, [ebx + edx*2]
        mov      dword ptr [g_dispatchSave1404], edx
        mov      edx, dword ptr [g_dispatchSave1346]
        mov      dword ptr [g_dispatchSave1345], edx
        jle      L_05a3
    L_0532:
        mov      edx, dword ptr [g_dispatchSave1404]
        xor      eax, eax
        mov      al, byte ptr [g_dispatchSave1388]
        mov      ax, word ptr [edx + eax*2]
        test     ax, ax
        je       L_0566
        mov      edx, dword ptr [g_dispatchSave1345]
        and      eax, 0xffff
        mov      ax, word ptr [ecx + eax*2]
        mov      word ptr [edx], ax
        mov      esi, dword ptr [g_dispatchSave1708]
        mov      edi, dword ptr [g_dispatchSave1707]
    L_0566:
        mov      eax, dword ptr [g_clipMinScratch]
        mov      edx, dword ptr [g_dispatchSave1357]
        mov      ebp, dword ptr [g_dispatchSave1387]
        mov      ebx, dword ptr [g_dispatchSave1345]
        dec      eax
        add      ebp, edx
        add      ebx, 2
        mov      dword ptr [g_clipMinScratch], eax
        test     eax, eax
        mov      dword ptr [g_dispatchSave1387], ebp
        mov      dword ptr [g_dispatchSave1345], ebx
        jg       L_0532
        mov      eax, dword ptr [g_dispatchSave1403]
        mov      ebp, dword ptr [g_dispatchSave1358]
    L_05a3:
        mov      edx, dword ptr [g_dispatchSave1374]
        mov      ebx, dword ptr [g_dispatchSave1346]
        add      edx, ebp
        dec      edi
        mov      dword ptr [g_dispatchSave1374], edx
        mov      edx, dword ptr [g_viewportY]
        add      ebx, edx
        mov      dword ptr [g_dispatchSave1707], edi
        test     edi, edi
        mov      dword ptr [g_dispatchSave1346], ebx
        jg       L_04f7
    L_05d4:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
#endif
