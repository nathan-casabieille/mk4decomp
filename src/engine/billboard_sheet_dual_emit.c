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

extern unsigned int g_dispatchSave531;
extern u32 g_inLoopStep;
extern unsigned int g_dispatchSave1626[];
extern s16 g_vtxIn2_x;
extern unsigned int g_triStripX0;
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn1_z;
extern unsigned int g_triStripX1;
extern s16 g_vtxIn2_y;
extern s16 g_vtxIn2_z;
extern unsigned int g_triStripX2;
extern unsigned int g_triStripRingB;
extern s32 g_vtxOut2_z;
extern s32 g_vtxOut_z;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP1Y;
extern s16 g_vtxScreenP2X;
extern s16 g_vtxScreenP2Y;
extern s16 g_vtxScreenX;
extern s16 g_vtxScreenY;
extern unsigned int g_dispatchSave1501;
extern unsigned int g_dispatchSave1502;
extern unsigned int g_dispatchSave1503;
extern unsigned int g_dispatchSave1559;
extern unsigned int g_dispatchSave1576;
extern void CopyArgs16ToGlobals(void);
extern void Helper_DrawCursor(void);
extern void MaxOfThree(void);
extern void ProjectTwoVertices(void);
extern void ProjectVertex(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BillboardSheetDualEmit(int param_1,int param_2)

{
  int iVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  ushort uVar8;
  short sVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  char local_34;
  char local_33;
  char local_32;
  char local_31;
  char local_30;
  char local_2f;
  short local_2e;
  ushort local_2c;
  uint local_26;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  char local_14;
  char local_13;
  char local_12;
  char local_11;
  char local_10;
  char local_f;
  short local_e;
  ushort local_c;
  undefined4 local_6;
  
  if (g_inLoopStep != 0) {
    return;
  }
  if (g_dispatchSave1576 < 0x10) {
    uVar10 = 0;
  }
  else {
    uVar10 = ((int)(g_dispatchSave1576 + (g_dispatchSave1576 >> 0x1f & 7U)) >> 3) - 1;
  }
  local_2c = (ushort)uVar10 | (ushort)((uVar10 << 5 | uVar10) << 5);
  g_vtxTransZ = g_dispatchSave1503 >> 7;
  if (((byte)g_cj_0054205c & 0x60) == 0) {
    g_vtxTransX = g_dispatchSave1501 >> 7;
    g_vtxTransY = g_dispatchSave1502 >> 7;
  }
  else {
    g_vtxTransX = g_dispatchSave1501 >> 0x10;
    g_vtxTransY = g_dispatchSave1502 >> 0x10;
  }
  sVar2 = *(short *)(param_1 + 10);
  iVar1 = *(int *)(*(int *)(g_eventQueuePending + 4) + 4) + 8 + *(int *)(g_eventQueuePending + 4);
  uVar7 = (short)(char)((&g_dispatchSave531)[*(byte *)(param_1 + 1) & 3] & 3) << 7;
  sVar3 = *(short *)(param_1 + 8);
  uVar16 = CONCAT22((short)((uint)iVar1 >> 0x10),sVar3);
  uVar8 = uVar7 ^ *(byte *)(iVar1 + 2 + (uint)*(byte *)(param_1 + 2) * 4) & 0xf;
  local_6 = CONCAT22((*(unsigned short *)((char *)&local_6 + 2)),uVar8);
  local_34 = *(char *)(param_1 + 0xc);
  local_26 = CONCAT22((*(unsigned short *)((char *)&local_26 + 2)),uVar7 ^ uVar8 & 0xf);
  local_33 = *(char *)(param_1 + 0xd);
  local_2f = *(char *)(param_1 + 0xf) + local_33;
  local_32 = *(char *)(param_1 + 0xe) + local_34;
  g_vtxIn2_y = 0;
  g_vtxIn2_x = sVar3 + *(short *)(param_1 + 4);
  g_vtxIn2_z = 0;
  g_triStripX0 = sVar3 + *(short *)(param_1 + 4);
  g_triStripX1 = sVar2 + *(short *)(param_1 + 6);
  g_triStripX2 = 0;
  g_dispatchSave1626 = sVar3;
  g_vtxIn1_y = sVar2;
  g_vtxIn1_z = sVar2;
  local_31 = local_33;
  local_30 = local_32;
  local_14 = local_34;
  local_13 = local_33;
  local_12 = local_32;
  local_11 = local_2f;
  local_10 = local_34;
  local_f = local_2f;
  local_c = local_2c;
  ProjectTwoVertices();
  local_2e = g_tickCurMask;
  if (g_tickCurMask == 0) {
    sVar9 = MaxOfThree();
    local_2e = sVar9 / 2 + (short)(g_dispatchSave1559 << 5);
  }
  local_e = local_2e;
  if ((g_currentNodeFlags & 0x40) == 0) {
    local_40 = g_triStripRingA;
    local_3c = g_vtxScreenP2X;
    bVar4 = ((int)(*(unsigned short *)((char *)&g_vtxScreenX + 2)) - (int)(*(unsigned short *)((char *)&g_triStripRingA + 2))) *
            ((int)(short)g_vtxScreenP2X - (int)(short)g_triStripRingA) -
            ((int)(*(unsigned short *)((char *)&g_vtxScreenP2X + 2)) - (int)(*(unsigned short *)((char *)&g_triStripRingA + 2))) *
            ((int)(short)g_vtxScreenX - (int)(short)g_triStripRingA) < 1;
    g_vtxValid = (uint)bVar4;
    local_38 = g_vtxScreenX;
    local_26 = CONCAT22((*(unsigned short *)((char *)&local_26 + 2)),(ushort)local_26 & 0xfbff | (ushort)bVar4 << 10);
    if (((0 < g_min_007af984) && (0 < g_min_007af988)) && (0 < g_min_007af98c)) {
      CopyArgs16ToGlobals(uVar16,sVar2 + *(short *)(param_1 + 6),0);
      ProjectVertex();
      local_20 = g_triStripRingA;
      local_1c = g_vtxScreenP2X;
      bVar4 = ((int)(*(unsigned short *)((char *)&g_vtxScreenX + 2)) - (int)(*(unsigned short *)((char *)&g_triStripRingA + 2))) *
              ((int)(short)g_vtxScreenP2X - (int)(short)g_triStripRingA) -
              ((int)(*(unsigned short *)((char *)&g_vtxScreenP2X + 2)) - (int)(*(unsigned short *)((char *)&g_triStripRingA + 2))) *
              ((int)(short)g_vtxScreenX - (int)(short)g_triStripRingA) < 1;
      g_vtxValid = (uint)bVar4;
      local_18 = g_vtxScreenX;
      local_6 = CONCAT22((*(unsigned short *)((char *)&local_6 + 2)),(ushort)local_6 & 0xfbff | (ushort)bVar4 << 10);
      if (((0 < g_min_007af984) && (0 < g_min_007af988)) && (0 < g_min_007af98c)) {
        if (((*(unsigned short *)((char *)&local_40 + 2)) == (*(unsigned short *)((char *)&local_3c + 2))) && ((short)local_40 == (short)g_vtxScreenX)) {
          if (((short)local_38 == (short)local_3c) && ((*(unsigned short *)((char *)&local_38 + 2)) == (*(unsigned short *)((char *)&g_vtxScreenX + 2)))) {
            local_26 = local_26 | 0x20;
            Helper_DrawCursor(&local_40);
            local_26 = local_26 & 0xffffffdf;
            goto LAB_004bc15a;
          }
        }
        Helper_DrawCursor(&local_40);
        Helper_DrawCursor(&local_20);
      }
    }
  }
LAB_004bc15a:
  iVar6 = g_vtxTransZ;
  iVar5 = g_vtxTransY;
  iVar1 = g_vtxTransX;
  for ((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x2c); (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) != 0;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4)) {
    iVar13 = *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 4) >> 7;
    iVar11 = *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 8) >> 7;
    iVar12 = *(int *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0xc) >> 7;
    iVar14 = iVar11;
    iVar15 = iVar13;
    if ((g_currentNodeFlags & 0x4000) == 0) {
      iVar15 = MK4_NODE_AT(short, param_2, 2) * iVar11 + MK4_NODE_AT(short, param_2, 0) * iVar13 +
               MK4_NODE_AT(short, param_2, 4) * iVar12 >> 0xc;
      iVar14 = MK4_NODE_AT(short, param_2, 6) * iVar13 + MK4_NODE_AT(short, param_2, 10) * iVar12 +
               MK4_NODE_AT(short, param_2, 8) * iVar11 >> 0xc;
      iVar12 = MK4_NODE_AT(short, param_2, 0xe) * iVar11 + MK4_NODE_AT(short, param_2, 0xc) * iVar13 +
               MK4_NODE_AT(short, param_2, 0x10) * iVar12 >> 0xc;
    }
    g_vtxTransX = iVar15 + iVar1;
    g_vtxTransY = iVar14 + iVar5;
    g_vtxTransZ = iVar12 + iVar6;
    g_vtxIn2_y = 0;
    g_vtxIn2_x = sVar3 + *(short *)(param_1 + 4);
    g_vtxIn2_z = 0;
    g_triStripX0 = sVar3 + *(short *)(param_1 + 4);
    g_triStripX1 = sVar2 + *(short *)(param_1 + 6);
    g_triStripX2 = 0;
    g_dispatchSave1626 = sVar3;
    g_vtxIn1_y = sVar2;
    g_vtxIn1_z = sVar2;
    ProjectTwoVertices();
    local_40 = g_triStripRingA;
    local_3c = g_vtxScreenP2X;
    bVar4 = ((int)(*(unsigned short *)((char *)&g_vtxScreenX + 2)) - (int)(*(unsigned short *)((char *)&g_triStripRingA + 2))) *
            ((int)(short)g_vtxScreenP2X - (int)(short)g_triStripRingA) -
            ((int)(*(unsigned short *)((char *)&g_vtxScreenP2X + 2)) - (int)(*(unsigned short *)((char *)&g_triStripRingA + 2))) *
            ((int)(short)g_vtxScreenX - (int)(short)g_triStripRingA) < 1;
    g_vtxValid = (uint)bVar4;
    local_38 = g_vtxScreenX;
    local_26 = CONCAT22((*(unsigned short *)((char *)&local_26 + 2)),(ushort)local_26 & 0xfbff | (ushort)bVar4 << 10);
    if (((0 < g_min_007af984) && (0 < g_min_007af988)) && (0 < g_min_007af98c)) {
      Helper_DrawCursor(&local_40);
    }
    CopyArgs16ToGlobals(uVar16,sVar2 + *(short *)(param_1 + 6),0);
    ProjectVertex();
    local_20 = g_triStripRingA;
    local_1c = g_vtxScreenP2X;
    bVar4 = ((int)(*(unsigned short *)((char *)&g_vtxScreenX + 2)) - (int)(*(unsigned short *)((char *)&g_triStripRingA + 2))) *
            ((int)(short)g_vtxScreenP2X - (int)(short)g_triStripRingA) -
            ((int)(*(unsigned short *)((char *)&g_vtxScreenP2X + 2)) - (int)(*(unsigned short *)((char *)&g_triStripRingA + 2))) *
            ((int)(short)g_vtxScreenX - (int)(short)g_triStripRingA) < 1;
    g_vtxValid = (uint)bVar4;
    local_18 = g_vtxScreenX;
    local_6 = CONCAT22((*(unsigned short *)((char *)&local_6 + 2)),(ushort)local_6 & 0xfbff | (ushort)bVar4 << 10);
    if (((0 < g_min_007af984) && (0 < g_min_007af988)) && (0 < g_min_007af98c)) {
      Helper_DrawCursor(&local_20);
    }
  }
  return;
}
#else
__declspec(naked) void BillboardSheetDualEmit(void)
{
    __asm {
        mov      eax, dword ptr [g_inLoopStep]
        sub      esp, 0x58
        test     eax, eax
        push     ebx
        push     ebp
        push     esi
        push     edi
        jne      L_c45f
        mov      eax, dword ptr [g_dispatchSave1576]
        cmp      eax, 0x10
        jl       L_bdca
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_bdcc
    L_bdca:
        xor      eax, eax
    L_bdcc:
        mov      ecx, eax
        shl      ecx, 5
        or       ecx, eax
        shl      ecx, 5
        or       eax, ecx
        mov      cl, byte ptr [g_fightGroupHead]
        test     cl, 0x60
        je       L_be12
        mov      edx, dword ptr [g_dispatchSave1501]
        mov      ecx, dword ptr [g_dispatchSave1502]
        sar      edx, 0x10
        mov      dword ptr [g_vtxTransX], edx
        mov      edx, dword ptr [g_dispatchSave1503]
        sar      ecx, 0x10
        sar      edx, 7
        mov      dword ptr [g_vtxTransY], ecx
        mov      dword ptr [g_vtxTransZ], edx
        jmp      L_be3f
    L_be12:
        mov      ecx, dword ptr [g_dispatchSave1501]
        mov      edx, dword ptr [g_dispatchSave1502]
        sar      ecx, 7
        mov      dword ptr [g_vtxTransX], ecx
        mov      ecx, dword ptr [g_dispatchSave1503]
        sar      edx, 7
        sar      ecx, 7
        mov      dword ptr [g_vtxTransY], edx
        mov      dword ptr [g_vtxTransZ], ecx
    L_be3f:
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      esi, dword ptr [esp + 0x6c]
        mov      ecx, dword ptr [ecx + 4]
        mov      bp, word ptr [esi + 0xa]
        mov      dword ptr [esp + 0x18], ebp
        mov      edx, dword ptr [ecx + 4]
        mov      word ptr [esp + 0x5c], ax
        mov      word ptr [esp + 0x3c], ax
        mov      al, byte ptr [esi + 1]
        and      eax, 3
        lea      edi, [edx + ecx + 8]
        xor      edx, edx
        mov      cl, byte ptr [eax + g_dispatchSave531]
        mov      dl, byte ptr [esi + 2]
        and      cl, 3
        movsx    ax, cl
        shl      eax, 7
        mov      word ptr [esp + 0x62], ax
        mov      ecx, dword ptr [esp + 0x62]
        mov      bl, byte ptr [esp + 0x62]
        and      ecx, 0x180
        mov      word ptr [esp + 0x42], cx
        mov      dl, byte ptr [edi + edx*4 + 2]
        xor      dl, bl
        mov      bl, byte ptr [esp + 0x42]
        and      edx, 0xf
        mov      di, word ptr [esi + 8]
        xor      ax, dx
        mov      dl, byte ptr [esi + 0xe]
        mov      word ptr [esp + 0x62], ax
        mov      al, byte ptr [esp + 0x62]
        xor      al, bl
        mov      bl, byte ptr [esi + 0xf]
        and      eax, 0xf
        xor      cx, ax
        mov      al, byte ptr [esi + 0xc]
        mov      word ptr [esp + 0x42], cx
        mov      cl, byte ptr [esi + 0xd]
        mov      byte ptr [esp + 0x35], cl
        mov      byte ptr [esp + 0x37], cl
        add      bl, cl
        mov      byte ptr [esp + 0x55], cl
        mov      cx, di
        add      dl, al
        mov      word ptr [g_dispatchSave1626], di
        mov      word ptr [g_vtxIn1_y], bp
        mov      word ptr [g_vtxIn2_y], 0
        add      cx, word ptr [esi + 4]
        mov      byte ptr [esp + 0x36], dl
        mov      byte ptr [esp + 0x38], dl
        mov      byte ptr [esp + 0x56], dl
        mov      dx, di
        mov      word ptr [g_vtxIn2_x], cx
        mov      word ptr [g_vtxIn1_z], bp
        mov      word ptr [g_vtxIn2_z], 0
        add      dx, word ptr [esi + 4]
        mov      byte ptr [esp + 0x34], al
        mov      byte ptr [esp + 0x54], al
        mov      byte ptr [esp + 0x58], al
        mov      ax, bp
        mov      word ptr [g_triStripX0], dx
        add      ax, word ptr [esi + 6]
        mov      byte ptr [esp + 0x39], bl
        mov      byte ptr [esp + 0x57], bl
        mov      byte ptr [esp + 0x59], bl
        mov      word ptr [g_triStripX1], ax
        mov      word ptr [g_triStripX2], 0
        call     ProjectTwoVertices
        mov      ax, word ptr [g_tickCurMask]
        test     ax, ax
        jne      L_bf84
        call     MaxOfThree
        mov      ecx, dword ptr [g_dispatchSave1559]
        movsx    eax, ax
        cdq
        sub      eax, edx
        sar      eax, 1
        shl      ecx, 5
        add      ax, cx
    L_bf84:
        mov      word ptr [esp + 0x3a], ax
        mov      word ptr [esp + 0x5a], ax
        test     byte ptr [g_currentNodeFlags], 0x40
        jne      L_c15a
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [esp + 0x28], ecx
        mov      ecx, dword ptr [esp + 0x42]
        mov      dword ptr [esp + 0x2c], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        mov      dword ptr [esp + 0x30], eax
        mov      eax, dword ptr [g_triStripRingB]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x42], cx
        jle      L_c15a
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_c15a
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_c15a
        mov      ax, bp
        push     0
        add      ax, word ptr [esi + 6]
        push     eax
        push     edi
        call     CopyArgs16ToGlobals
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [esp + 0x48], ecx
        mov      ecx, dword ptr [esp + 0x62]
        mov      dword ptr [esp + 0x4c], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        mov      dword ptr [esp + 0x50], eax
        mov      eax, dword ptr [g_triStripRingB]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x62], cx
        jle      L_c15a
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_c15a
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_c15a
        mov      ax, word ptr [esp + 0x2a]
        cmp      ax, word ptr [esp + 0x2e]
        jne      L_c140
        mov      cx, word ptr [esp + 0x28]
        cmp      cx, word ptr [esp + 0x50]
        jne      L_c140
        mov      dx, word ptr [esp + 0x30]
        cmp      dx, word ptr [esp + 0x2c]
        jne      L_c140
        mov      ax, word ptr [esp + 0x32]
        cmp      ax, word ptr [esp + 0x52]
        jne      L_c140
        or       byte ptr [esp + 0x42], 0x20
        lea      ecx, [esp + 0x28]
        push     ecx
        call     Helper_DrawCursor
        add      esp, 4
        /* MASM picks 6-byte 66 83 /4 sign-extended form for 0xffdf; orig uses 7-byte 66 81 /4 - force via _emit */
        _emit 0x66
        _emit 0x81
        _emit 0x64
        _emit 0x24
        _emit 0x42
        _emit 0xdf
        _emit 0xff
        jmp      L_c15a
    L_c140:
        lea      edx, [esp + 0x28]
        push     edx
        call     Helper_DrawCursor
        add      esp, 4
        lea      eax, [esp + 0x48]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_c15a:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [ecx*4 + 0x2c]
        test     ecx, ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        je       L_c45f
        mov      edx, dword ptr [g_vtxTransX]
        mov      eax, dword ptr [g_vtxTransY]
        mov      dword ptr [esp + 0x1c], edx
        mov      edx, dword ptr [g_vtxTransZ]
        mov      dword ptr [esp + 0x20], eax
        mov      dword ptr [esp + 0x24], edx
    L_c192:
        mov      edx, dword ptr [ecx*4 + 4]
        mov      eax, dword ptr [ecx*4 + 8]
        mov      ecx, dword ptr [ecx*4 + 0xc]
        mov      ebx, dword ptr [g_currentNodeFlags]
        sar      edx, 7
        sar      eax, 7
        sar      ecx, 7
        test     bh, 0x40
        jne      L_c261
        mov      ebx, dword ptr [esp + 0x70]
        mov      dword ptr [esp + 0x6c], edx
        mov      dword ptr [esp + 0x10], eax
        movsx    ebp, word ptr [ebx*4 + 2]
        movsx    ebx, word ptr [ebx*4]
        imul     ebp, eax
        imul     ebx, edx
        mov      edx, dword ptr [esp + 0x70]
        add      ebp, ebx
        movsx    ebx, word ptr [edx*4 + 4]
        imul     ebx, ecx
        add      ebp, ebx
        movsx    ebx, word ptr [edx*4 + 6]
        imul     ebx, dword ptr [esp + 0x6c]
        sar      ebp, 0xc
        mov      dword ptr [esp + 0x14], ebp
        movsx    ebp, word ptr [edx*4 + 0xa]
        imul     ebp, ecx
        add      ebx, ebp
        movsx    ebp, word ptr [edx*4 + 8]
        imul     ebp, eax
        add      ebx, ebp
        mov      ebp, dword ptr [esp + 0x18]
        sar      ebx, 0xc
        mov      eax, ebx
        movsx    ebx, word ptr [edx*4 + 0xe]
        movsx    edx, word ptr [edx*4 + 0xc]
        imul     ebx, dword ptr [esp + 0x10]
        imul     edx, dword ptr [esp + 0x6c]
        add      ebx, edx
        mov      edx, dword ptr [esp + 0x70]
        movsx    edx, word ptr [edx*4 + 0x10]
        imul     edx, ecx
        add      ebx, edx
        mov      edx, dword ptr [esp + 0x14]
        sar      ebx, 0xc
        mov      ecx, ebx
    L_c261:
        mov      ebx, dword ptr [esp + 0x1c]
        mov      word ptr [g_dispatchSave1626], di
        add      edx, ebx
        mov      word ptr [g_vtxIn1_y], bp
        mov      dword ptr [g_vtxTransX], edx
        mov      edx, dword ptr [esp + 0x20]
        add      eax, edx
        mov      dx, di
        mov      dword ptr [g_vtxTransY], eax
        mov      eax, dword ptr [esp + 0x24]
        add      ecx, eax
        xor      eax, eax
        mov      dword ptr [g_vtxTransZ], ecx
        mov      cx, di
        mov      word ptr [g_vtxIn2_y], ax
        add      cx, word ptr [esi + 4]
        mov      word ptr [g_vtxIn1_z], bp
        mov      word ptr [g_vtxIn2_z], ax
        mov      word ptr [g_vtxIn2_x], cx
        add      dx, word ptr [esi + 4]
        mov      cx, bp
        mov      word ptr [g_triStripX0], dx
        add      cx, word ptr [esi + 6]
        mov      word ptr [g_triStripX2], ax
        mov      word ptr [g_triStripX1], cx
        call     ProjectTwoVertices
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [esp + 0x28], ecx
        mov      ecx, dword ptr [esp + 0x42]
        mov      dword ptr [esp + 0x2c], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        mov      dword ptr [esp + 0x30], eax
        mov      eax, dword ptr [g_triStripRingB]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x42], cx
        jle      L_c384
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_c384
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_c384
        lea      eax, [esp + 0x28]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_c384:
        mov      cx, bp
        push     0
        add      cx, word ptr [esi + 6]
        push     ecx
        push     edi
        call     CopyArgs16ToGlobals
        add      esp, 0xc
        call     ProjectVertex
        movsx    eax, word ptr [g_triStripRingA]
        movsx    ecx, word ptr [g_vtxScreenP1Y]
        movsx    edx, word ptr [g_vtxScreenY]
        movsx    ebx, word ptr [g_vtxScreenP2X]
        sub      edx, ecx
        sub      ebx, eax
        imul     edx, ebx
        movsx    ebx, word ptr [g_vtxScreenP2Y]
        sub      ebx, ecx
        movsx    ecx, word ptr [g_vtxScreenX]
        sub      ecx, eax
        xor      eax, eax
        imul     ebx, ecx
        mov      ecx, dword ptr [g_triStripRingA]
        sub      edx, ebx
        test     edx, edx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      dword ptr [esp + 0x48], ecx
        mov      ecx, dword ptr [esp + 0x62]
        mov      dword ptr [esp + 0x4c], edx
        setle    al
        mov      dword ptr [g_vtxValid], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [g_vtxScreenX]
        and      edx, 1
        mov      dword ptr [esp + 0x50], eax
        mov      eax, dword ptr [g_triStripRingB]
        and      ecx, 0xfbff
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esp + 0x62], cx
        jle      L_c444
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_c444
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_c444
        lea      eax, [esp + 0x48]
        push     eax
        call     Helper_DrawCursor
        add      esp, 4
    L_c444:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [ecx*4]
        test     ecx, ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        jne      L_c192
    L_c45f:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x58
        ret
    }
}
#endif
