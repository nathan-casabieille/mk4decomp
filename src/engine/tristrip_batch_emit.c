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
extern u32 g_inLoopStep;
#endif
extern s16 g_vtxIn_x;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP1Y;
extern s16 g_vtxScreenP2X;
extern s16 g_vtxScreenP2Y;
extern s16 g_vtxScreenX;
extern s16 g_vtxScreenY;
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
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1626 (*(short *)MK4_VA(short, 0x7af958u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_inLoopStep (*(unsigned int *)MK4_VA(unsigned int, 0x7af92cu))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_min_007af984 (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_min_007af988 (*(unsigned int *)MK4_VA(unsigned int, 0x7af988u))
#define g_min_007af98c (*(unsigned int *)MK4_VA(unsigned int, 0x7af98cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_triStripRingA (*(unsigned int *)MK4_VA(unsigned int, 0x7af9b4u))
#define g_triStripRingB (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_triStripX0 (*(short *)MK4_VA(short, 0x7af95cu))
#define g_triStripX1 (*(short *)MK4_VA(short, 0x7af962u))
#define g_triStripX2 (*(short *)MK4_VA(short, 0x7af968u))
#define g_vtxIn1_y (*(short *)MK4_VA(short, 0x7af95eu))
#define g_vtxIn1_z (*(short *)MK4_VA(short, 0x7af960u))
#define g_vtxIn2_x (*(short *)MK4_VA(short, 0x7af95au))
#define g_vtxIn2_y (*(short *)MK4_VA(short, 0x7af964u))
#define g_vtxIn2_z (*(short *)MK4_VA(short, 0x7af966u))
#define g_vtxOut2_z (*(int *)MK4_VA(int, 0x7af988u))
#define g_vtxOut_z (*(int *)MK4_VA(int, 0x7af98cu))
#define g_vtxScreenP1Y (*(short *)MK4_VA(short, 0x7af9b6u))
#define g_vtxScreenP2X (*(unsigned int *)MK4_VA(unsigned int, 0x7af9b8u))
#define g_vtxScreenP2Y (*(short *)MK4_VA(short, 0x7af9bau))
#define g_vtxScreenX (*(unsigned int *)MK4_VA(unsigned int, 0x7af9bcu))
#define g_vtxScreenY (*(short *)MK4_VA(short, 0x7af9beu))
#define g_vtxValid (*(int *)MK4_VA(int, 0x7af9b0u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void AdvanceTriStripRing(s16 v0, s16 v1, s16 v2);
extern void Helper_DrawCursor(void *entry);
extern int MaxOfThree(void);
extern int MinOfThree(void);
extern void ProjectTwoVertices(void);
extern void ProjectVertex(void);
extern void Vec3ColorShiftClamp(int entry, unsigned char shift);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void TristripBatchEmit(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  int local_8;
  
  if ((g_inLoopStep == 0) && (*(int *)MK4_PTR(param_1 + 4) != 0)) {
    puVar5 = (ushort *)MK4_PTR(*(int *)MK4_PTR(param_1 + 8) + 8 + param_1);
    puVar7 = (undefined2 *)MK4_PTR(param_1 + 4 + *(int *)MK4_PTR(param_1 + 4));
    puVar6 = (undefined4 *)MK4_PTR(g_dualC + 4);
    while( true ) {
      uVar1 = *puVar5;
      uVar3 = uVar1 & 1;
      if (param_2 != 0) {
        uVar3 = (ushort)(uVar3 == 0);
      }
      uVar2 = puVar5[1];
      puVar5 = puVar5 + 2;
      if ((short)uVar2 < 0) break;
      g_dispatchSave1626 = 0;
      g_vtxIn1_y = 0;
      g_vtxIn2_y = 0;
      g_vtxIn2_x = *puVar7;
      g_vtxIn1_z = puVar7[1];
      g_vtxIn2_z = puVar7[2];
      g_triStripX0 = puVar7[6];
      g_triStripX1 = puVar7[7];
      g_triStripX2 = puVar7[8];
      ProjectTwoVertices();
      puVar7 = puVar7 + 0xc;
      local_8 = (short)uVar2 + 1;
      do {
        AdvanceTriStripRing(*puVar7,puVar7[1],puVar7[2]);
        ProjectVertex();
        g_vtxValid =
             (uint)(((int)(*(unsigned short *)((char *)&g_vtxScreenX + 2)) - (int)(*(unsigned short *)((char *)&g_triStripRingA + 2))) *
                    ((int)(short)g_vtxScreenP2X - (int)(short)g_triStripRingA) -
                    ((int)(*(unsigned short *)((char *)&g_vtxScreenP2X + 2)) - (int)(*(unsigned short *)((char *)&g_triStripRingA + 2))) *
                    ((int)(short)g_vtxScreenX - (int)(short)g_triStripRingA) < 1);
        if ((((uVar3 != (g_vtxValid == 0)) && (0 < (int)g_min_007af984)) && (0 < (int)g_min_007af988)) &&
           (0 < (int)g_min_007af98c)) {
          *puVar6 = g_triStripRingA;
          puVar6[1] = g_vtxScreenP2X;
          puVar6[2] = g_vtxScreenX;
          *(ushort *)((char *)puVar6 + 0x1a) =
               *(ushort *)((char *)puVar6 + 0x1a) & 0xfbff | (ushort)((g_vtxValid & 1) << 10);
          if (param_3 == 0) {
            uVar4 = MinOfThree();
          }
          else {
            uVar4 = MaxOfThree();
          }
          *(undefined2 *)((char *)puVar6 + 0x12) = uVar4;
          *(ushort *)((char *)puVar6 + 0x1a) =
               *(ushort *)((char *)puVar6 + 0x1a) & 0xfe7f | (short)(char)((byte)(uVar1 >> 8) & 1) << 7
               | 0x10;
          Vec3ColorShiftClamp(MK4_UNPTR(puVar6),9);
          Helper_DrawCursor(puVar6);
        }
        puVar7 = puVar7 + 6;
        uVar3 = (ushort)(uVar3 == 0);
        puVar6 = puVar6 + 7;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
  }
  return;
}
#else
__declspec(naked) void TristripBatchEmit(void)
{
    __asm {
        mov      eax, dword ptr [g_inLoopStep]
        sub      esp, 8
        xor      edx, edx
        push     ebx
        push     ebp
        push     esi
        cmp      eax, edx
        push     edi
        jne      L_bd95
        mov      edi, dword ptr [esp + 0x1c]
        mov      eax, dword ptr [edi + 4]
        cmp      eax, edx
        je       L_bd95
        mov      ecx, dword ptr [edi + 8]
        lea      ecx, [ecx + edi + 8]
        lea      edi, [edi + eax + 4]
        mov      eax, dword ptr [g_pendingNodeType]
        lea      esi, [eax + 4]
    L_bbb8:
        mov      bp, word ptr [ecx]
        add      ecx, 2
        mov      eax, ebp
        and      ebp, 1
        shr      eax, 8
        and      al, 1
        mov      byte ptr [esp + 0x1c], al
        mov      eax, dword ptr [esp + 0x20]
        cmp      eax, edx
        je       L_bbde
        xor      eax, eax
        cmp      bp, dx
        sete     al
        mov      ebp, eax
    L_bbde:
        movsx    ebx, word ptr [ecx]
        add      ecx, 2
        cmp      ebx, edx
        mov      dword ptr [esp + 0x14], ecx
        jl       L_bd95
        mov      word ptr [g_vtxIn_x], dx
        mov      word ptr [g_vtxIn1_y], dx
        mov      word ptr [g_vtxIn2_y], dx
        mov      cx, word ptr [edi]
        mov      word ptr [g_vtxIn2_x], cx
        mov      dx, word ptr [edi + 2]
        mov      word ptr [g_vtxIn1_z], dx
        mov      ax, word ptr [edi + 4]
        mov      word ptr [g_vtxIn2_z], ax
        mov      cx, word ptr [edi + 0xc]
        mov      word ptr [g_triStripX0], cx
        mov      dx, word ptr [edi + 0xe]
        mov      word ptr [g_triStripX1], dx
        mov      ax, word ptr [edi + 0x10]
        mov      word ptr [g_triStripX2], ax
        call     ProjectTwoVertices
        add      edi, 0x18
        inc      ebx
        mov      dword ptr [esp + 0x10], ebx
    L_bc51:
        mov      cx, word ptr [edi + 4]
        mov      dx, word ptr [edi + 2]
        mov      ax, word ptr [edi]
        push     ecx
        push     edx
        push     eax
        call     AdvanceTriStripRing
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
        sub      edx, ebx
        test     edx, edx
        setle    al
        xor      edx, edx
        mov      dword ptr [g_vtxValid], eax
        test     eax, eax
        movsx    eax, bp
        sete     dl
        cmp      eax, edx
        je       L_bd6b
        mov      eax, dword ptr [g_triStripRingB]
        test     eax, eax
        jle      L_bd6b
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_bd6b
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_bd6b
        mov      ecx, dword ptr [g_triStripRingA]
        mov      dword ptr [esi], ecx
        mov      edx, dword ptr [g_vtxScreenP2X]
        mov      cx, word ptr [esi + 0x1a]
        mov      dword ptr [esi + 4], edx
        mov      eax, dword ptr [g_vtxScreenX]
        and      ecx, 0xfbff
        mov      dword ptr [esi + 8], eax
        mov      dl, byte ptr [g_vtxValid]
        mov      eax, dword ptr [esp + 0x24]
        and      edx, 1
        shl      edx, 0xa
        or       ecx, edx
        test     eax, eax
        mov      word ptr [esi + 0x1a], cx
        jne      L_bd2f
        call     MinOfThree
        jmp      L_bd34
    L_bd2f:
        call     MaxOfThree
    L_bd34:
        mov      cl, byte ptr [esp + 0x1c]
        mov      word ptr [esi + 0x12], ax
        mov      ax, word ptr [esi + 0x1a]
        and      cl, 3
        movsx    dx, cl
        and      eax, 0xfe7f
        push     9
        shl      edx, 7
        or       eax, edx
        push     esi
        or       al, 0x10
        mov      word ptr [esi + 0x1a], ax
        call     Vec3ColorShiftClamp
        add      esp, 8
        push     esi
        call     Helper_DrawCursor
        add      esp, 4
    L_bd6b:
        add      edi, 0xc
        xor      eax, eax
        test     bp, bp
        sete     al
        mov      ebp, eax
        mov      eax, dword ptr [esp + 0x10]
        add      esi, 0x1c
        dec      eax
        mov      dword ptr [esp + 0x10], eax
        jne      L_bc51
        mov      ecx, dword ptr [esp + 0x14]
        xor      edx, edx
        jmp      L_bbb8
    L_bd95:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    }
}
#endif
