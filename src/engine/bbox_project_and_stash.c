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
extern unsigned int g_dispatchSave722;
extern unsigned int g_dispatchSave571;
extern unsigned int g_dispatchSave570;
extern unsigned int g_dispatchSave726;
extern unsigned int g_dispatchSave727;
extern unsigned int g_dispatchSave728;
#endif
#ifdef NON_MATCHING
/* a WORD at 0x007af958 - the original stores it as `mov word ptr [...], 0` */
#define g_dispatchSave1626 (*(short *)MK4_VA(short, 0x007af958u))

/* The working 3x3's elements are SIGNED WORDS - every read of them here is a
 * `movsx eax, word ptr [...]`. Declared `unsigned int` they would each pull a
 * dword spanning two neighbouring elements, unsigned, and the projection came
 * out thousands of units off. */
#define g_mat3x3_007af992 (*(short *)MK4_VA(short, 0x007af992u))
#define g_mat3x3_007af994 (*(short *)MK4_VA(short, 0x007af994u))
#define g_mat3x3_007af998 (*(short *)MK4_VA(short, 0x007af998u))
#define g_mat3x3_007af99a (*(short *)MK4_VA(short, 0x007af99au))
#define g_mat3x3_007af99e (*(short *)MK4_VA(short, 0x007af99eu))
#define g_mat3x3_007af9a0 (*(short *)MK4_VA(short, 0x007af9a0u))
#else
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1626[];
#endif
#endif
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn2_y;
extern s32 g_vtxOut1_x;
extern s32 g_vtxOut1_y;
extern unsigned int g_triStripRingB;
#endif
#ifndef NON_MATCHING   /* the native twin defines these as signed words above */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_mat3x3_007af992;
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99a;
extern unsigned int g_mat3x3_007af99e;
extern unsigned int g_mat3x3_007af9a0;
#endif
#endif
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern unsigned int g_dispatchSave1513;
extern unsigned int g_dispatchSave1514;
extern unsigned int g_dispatchSave1515;
extern unsigned int g_dispatchSave1516;
extern unsigned int g_dispatchSave1517;
extern unsigned int g_dispatchSave1518;
extern unsigned int g_dispatchSave1580;
#endif

/* Seven globals are deliberately absent from this block - they are defined
 * above at their real ACCESS WIDTH (signed words), which the generic pass
 * would overwrite with the 32-bit spelling.
 *
 * --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
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
#define g_dispatchSave1513 (*(unsigned int *)MK4_VA(unsigned int, 0xab44f8u))
#define g_dispatchSave1514 (*(unsigned int *)MK4_VA(unsigned int, 0xab44fau))
#define g_dispatchSave1515 (*(unsigned int *)MK4_VA(unsigned int, 0xab44fcu))
#define g_dispatchSave1516 (*(unsigned int *)MK4_VA(unsigned int, 0xab44feu))
#define g_dispatchSave1517 (*(unsigned int *)MK4_VA(unsigned int, 0xab4500u))
#define g_dispatchSave1518 (*(unsigned int *)MK4_VA(unsigned int, 0xab4502u))
#define g_dispatchSave1580 (*(unsigned int *)MK4_VA(unsigned int, 0xab51f8u))
#define g_dispatchSave570 (*(unsigned int *)MK4_VA(unsigned int, 0x4f63eau))
#define g_dispatchSave571 (*(unsigned int *)MK4_VA(unsigned int, 0x4f63e8u))
#define g_dispatchSave722 (*(unsigned int *)MK4_VA(unsigned int, 0x4f6264u))
#define g_dispatchSave726 (*(unsigned int *)MK4_VA(unsigned int, 0x4f63ecu))
#define g_dispatchSave727 (*(unsigned int *)MK4_VA(unsigned int, 0x4f63eeu))
#define g_dispatchSave728 (*(unsigned int *)MK4_VA(unsigned int, 0x4f63f0u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_min_007af984 (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_tickCurConfig (*(unsigned int *)MK4_VA(unsigned int, 0xab4e2cu))
#define g_tickX2 (*(unsigned int *)MK4_VA(unsigned int, 0xab51f4u))
#define g_triStripRingB (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_vtxIn1_y (*(short *)MK4_VA(short, 0x7af95eu))
#define g_vtxIn2_y (*(short *)MK4_VA(short, 0x7af964u))
#define g_vtxOut1_x (*(int *)MK4_VA(int, 0x7af96cu))
#define g_vtxOut1_y (*(int *)MK4_VA(int, 0x7af978u))
#define g_vtxTransX (*(int *)MK4_VA(int, 0x7af9a4u))
#define g_vtxTransY (*(int *)MK4_VA(int, 0x7af9a8u))
#define g_vtxTransZ (*(int *)MK4_VA(int, 0x7af9acu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void BboxProjectAndStash(void)

{
  undefined2 uVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  
  iVar2 = g_tickX2;
  g_walkCallback = MK4_NODE_AT(int, g_eventQueuePending, 0x1c);
  if (((0 < (int)g_walkCallback) && (g_walkCallback < 0x11)) &&
     (iVar11 = g_walkCallback * 0x10, *(unsigned char *)MK4_VA(unsigned char, 0x004f63e8u + iVar11) == 0)) {
    if (g_tickCurConfig == 0x004f6264u) {
      if (g_dispatchSave1580 != 0) {
        return;
      }
    }
    else {
      g_dispatchSave1580 = 0;
      if (*(char *)MK4_PTR(g_tickCurConfig) != 1) {
        g_dispatchSave1580 = 0;
        return;
      }
    }
    iVar8 = (int)*(short *)MK4_VA(short, 0x004f63eau + iVar11);
    iVar4 = (int)*(short *)MK4_VA(short, 0x004f63eeu + iVar11);
    g_dispatchSave1626 = 0;
    iVar5 = (int)g_mat3x3_007af998;
    iVar10 = (int)g_mat3x3_007af99a;
    iVar6 = (int)g_mat3x3_007af99e;
    (*(unsigned short *)((char *)&g_eventQueuePending + 0)) = (short)(iVar5 * iVar8 + iVar10 * iVar4 >> 0xc) + (short)g_vtxTransY;
    iVar7 = (int)g_mat3x3_007af9a0;
    sVar3 = (short)g_vtxTransZ;
    *(short *)MK4_VA(short, 0x00ab44f8u + g_tickX2 * 6u + 0) =
         (short)(iVar8 * g_mat3x3_007af992 + iVar4 * g_mat3x3_007af994 >> 0xc) + (short)g_vtxTransX;
    *(short *)MK4_VA(short, 0x00ab44f8u + iVar2 * 6u + 2) = (short)g_eventQueuePending;
    *(short *)MK4_VA(short, 0x00ab44f8u + iVar2 * 6u + 4) = (short)(iVar7 * iVar4 + iVar6 * iVar8 >> 0xc) + sVar3;
    g_vtxIn1_y = *(short *)MK4_VA(short, 0x004f63ecu + iVar11);
    g_vtxIn2_y = *(short *)MK4_VA(short, 0x004f63f0u + iVar11);
    iVar11 = (int)g_vtxIn1_y;
    iVar4 = (int)g_vtxIn2_y;
    sVar9 = (short)(iVar11 * g_mat3x3_007af992 + iVar4 * g_mat3x3_007af994 >> 0xc) + (short)g_vtxTransX;
    sVar3 = (short)(iVar5 * iVar11 + iVar10 * iVar4 >> 0xc) + (short)g_vtxTransY;
    (g_currentNodeIdx) = (int)sVar9;
    g_eventQueuePending = (int)sVar3;
    g_eventQueueCurrent = (int)(short)((short)(iVar7 * iVar4 + iVar6 * iVar11 >> 0xc) + (short)g_vtxTransZ
                               );
    g_vtxOut1_x = (g_currentNodeIdx);
    g_vtxOut1_y = g_eventQueuePending;
    g_min_007af984 = g_eventQueueCurrent;
    *(short *)MK4_VA(short, 0x00ab44f8u + iVar2 * 6u + 6) = sVar9;
    uVar1 = (undefined2)g_min_007af984;
    *(short *)MK4_VA(short, 0x00ab44f8u + iVar2 * 6u + 8) = sVar3;
    *(short *)MK4_VA(short, 0x00ab44f8u + iVar2 * 6u + 10) = uVar1;
    g_tickX2 = g_tickX2 + 2;
  }
  return;
}
#else
__declspec(naked) void BboxProjectAndStash(void)
{
    __asm {
        mov      eax, dword ptr [g_xformEntityIdx]
        sub      esp, 0xc
        push     ebx
        push     ebp
        push     esi
        push     edi
        mov      edi, dword ptr [eax*4 + 0x1c]
        test     edi, edi
        mov      dword ptr [g_walkCallback], edi
        jle      L_c7d1
        cmp      edi, 0x10
        jg       L_c7d1
        shl      edi, 4
        mov      al, byte ptr [edi + g_dispatchSave571]
        test     al, al
        jne      L_c7d1
        mov      eax, dword ptr [g_tickCurConfig]
        cmp      eax, OFFSET g_dispatchSave722
        jne      L_c5f6
        mov      eax, dword ptr [g_dispatchSave1580]
        test     eax, eax
        jne      L_c7d1
        jmp      L_c60b
    L_c5f6:
        mov      dword ptr [g_dispatchSave1580], 0
        mov      cl, byte ptr [eax]
        cmp      cl, 1
        jne      L_c7d1
    L_c60b:
        mov      cx, word ptr [edi + g_dispatchSave570]
        mov      dx, word ptr [edi + g_dispatchSave727]
        movsx    eax, word ptr [g_mat3x3_007af992]
        movsx    ebp, word ptr [g_mat3x3_007af994]
        movsx    ebx, cx
        movsx    ecx, dx
        mov      dword ptr [esp + 0x10], ebx
        mov      dword ptr [esp + 0x14], ecx
        imul     ebx, eax
        mov      eax, dword ptr [esp + 0x14]
        mov      word ptr [g_dispatchSave1626], 0
        imul     eax, ebp
        movsx    ecx, word ptr [g_mat3x3_007af998]
        movsx    esi, word ptr [g_mat3x3_007af99a]
        add      ebx, eax
        mov      eax, dword ptr [g_vtxTransX]
        sar      ebx, 0xc
        add      ebx, eax
        mov      ebp, esi
        movsx    eax, bx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [esp + 0x14]
        mov      ebx, ecx
        imul     ebp, eax
        imul     ebx, dword ptr [esp + 0x10]
        movsx    edx, word ptr [g_mat3x3_007af99e]
        add      ebx, ebp
        mov      ebp, dword ptr [g_vtxTransY]
        sar      ebx, 0xc
        add      ebx, ebp
        mov      dword ptr [esp + 0x18], edx
        movsx    edx, word ptr [g_mat3x3_007af9a0]
        movsx    ebx, bx
        mov      dword ptr [g_xformEntityIdx], ebx
        mov      ebx, edx
        imul     ebx, eax
        mov      eax, dword ptr [esp + 0x18]
        mov      bp, word ptr [g_currentNodeIdx]
        imul     eax, dword ptr [esp + 0x10]
        add      ebx, eax
        mov      eax, dword ptr [g_vtxTransZ]
        sar      ebx, 0xc
        add      ebx, eax
        mov      eax, dword ptr [g_tickX2]
        movsx    ebx, bx
        lea      eax, [eax + eax*2]
        shl      eax, 1
        mov      word ptr [eax + g_dispatchSave1513], bp
        mov      bp, word ptr [g_xformEntityIdx]
        mov      word ptr [eax + g_dispatchSave1514], bp
        mov      word ptr [eax + g_dispatchSave1515], bx
        mov      bx, word ptr [edi + g_dispatchSave726]
        mov      di, word ptr [edi + g_dispatchSave728]
        mov      word ptr [g_vtxIn1_y], bx
        mov      word ptr [g_vtxIn2_y], di
        movsx    ebx, bx
        mov      dword ptr [esp + 0x10], ebx
        mov      ebp, ebx
        movsx    ebx, word ptr [g_mat3x3_007af992]
        movsx    edi, di
        imul     ebp, ebx
        mov      dword ptr [esp + 0x14], edi
        mov      ebx, edi
        movsx    edi, word ptr [g_mat3x3_007af994]
        imul     ebx, edi
        mov      edi, dword ptr [g_vtxTransX]
        add      ebp, ebx
        mov      ebx, dword ptr [esp + 0x14]
        sar      ebp, 0xc
        imul     esi, ebx
        add      ebp, edi
        mov      edi, dword ptr [esp + 0x10]
        imul     ecx, edi
        add      ecx, esi
        mov      esi, dword ptr [g_vtxTransY]
        sar      ecx, 0xc
        add      ecx, esi
        movsx    ebp, bp
        movsx    esi, cx
        mov      dword ptr [g_vtxOut1_x], ebp
        mov      dword ptr [g_vtxOut1_y], esi
        mov      ecx, dword ptr [esp + 0x18]
        imul     edx, ebx
        imul     ecx, edi
        add      edx, ecx
        mov      ecx, dword ptr [g_vtxTransZ]
        sar      edx, 0xc
        add      edx, ecx
        mov      dword ptr [g_currentNodeIdx], ebp
        movsx    ecx, dx
        mov      dx, word ptr [g_vtxOut1_y]
        mov      dword ptr [g_triStripRingB], ecx
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      cx, word ptr [g_vtxOut1_x]
        mov      word ptr [eax + g_dispatchSave1516], cx
        mov      cx, word ptr [g_triStripRingB]
        mov      word ptr [eax + g_dispatchSave1517], dx
        mov      word ptr [eax + g_dispatchSave1518], cx
        mov      eax, dword ptr [g_tickX2]
        mov      dword ptr [g_xformEntityIdx], esi
        add      eax, 2
        mov      dword ptr [g_tickX2], eax
    L_c7d1:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    }
}
#endif
