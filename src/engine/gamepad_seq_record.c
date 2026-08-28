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
extern unsigned int g_installCountdownEnd;
extern unsigned int g_dispatchCmpEnd2;
extern unsigned int g_movesPanelEnd;
extern unsigned int g_dispatchCmpEnd;
extern unsigned int g_dispatchSave1534;
extern unsigned int g_dispatchSave1535;
extern unsigned int g_dispatchSave1536;
extern unsigned int g_dispatchSave1537;
extern unsigned int g_dispatchSave1538;
extern unsigned int g_dispatchSave1539;
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
#define g_dispatchCmpEnd (*(unsigned int *)MK4_VA(unsigned int, 0x4ed060u))
#define g_dispatchCmpEnd2 (*(unsigned int *)MK4_VA(unsigned int, 0x4ed020u))
#define g_dispatchSave1534 (*(unsigned int *)MK4_VA(unsigned int, 0xab48b8u))
#define g_dispatchSave1535 (*(unsigned int *)MK4_VA(unsigned int, 0xab48bau))
#define g_dispatchSave1536 (*(unsigned int *)MK4_VA(unsigned int, 0xab48bcu))
#define g_dispatchSave1537 (*(unsigned int *)MK4_VA(unsigned int, 0xab48beu))
#define g_dispatchSave1538 (*(unsigned int *)MK4_VA(unsigned int, 0xab48c0u))
#define g_dispatchSave1539 (*(unsigned int *)MK4_VA(unsigned int, 0xab48c2u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installCountdownEnd (*(unsigned int *)MK4_VA(unsigned int, 0x4ed000u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_movesPanelEnd (*(unsigned int *)MK4_VA(unsigned int, 0x4ed040u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* The record's six screen words at 0x00ab48b8..c2 - v0/v1/v2 x,y pairs. The
 * generic externs make them dwords; every access in the original is a word
 * (`inc word ptr`, `add word ptr`), and as dwords each nudge would carry into
 * its neighbour. */
#define g_dispatchSave1534 (*(short *)MK4_VA(short, 0xab48b8u))
#define g_dispatchSave1535 (*(short *)MK4_VA(short, 0xab48bau))
#define g_dispatchSave1536 (*(short *)MK4_VA(short, 0xab48bcu))
#define g_dispatchSave1537 (*(short *)MK4_VA(short, 0xab48beu))
#define g_dispatchSave1538 (*(short *)MK4_VA(short, 0xab48c0u))
#define g_dispatchSave1539 (*(short *)MK4_VA(short, 0xab48c2u))

/* Ghidra-decompiled twin. The first argument is the PANEL's VA - the original
 * compares it against the four sentinel records directly, so the compares stay
 * VA literals rather than host pointers. */
void GamepadSeqRecord(unsigned int panel_va, int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = Renderer_GetMode();
  if ((iVar1 == 2) || (iVar1 = Renderer_GetMode(), iVar1 == 1)) {
    if (param_2 == 0) {
      if (panel_va == 0x4ed040u) {
        g_dispatchSave1534 = g_dispatchSave1534 + 1;
        g_dispatchSave1535 = g_dispatchSave1535 + -2;
        g_dispatchSave1536 = g_dispatchSave1536 + 2;
        g_dispatchSave1537 = g_dispatchSave1537 + -2;
        g_dispatchSave1538 = g_dispatchSave1538 + 2;
        g_dispatchSave1539 = g_dispatchSave1539 + -1;
      }
      if (panel_va == 0x4ed060u) {
        g_dispatchSave1535 = g_dispatchSave1535 + -2;
        g_dispatchSave1536 = g_dispatchSave1536 + 2;
        g_dispatchSave1537 = g_dispatchSave1537 + -2;
        g_dispatchSave1538 = g_dispatchSave1538 + 2;
        g_dispatchSave1539 = g_dispatchSave1539 + -1;
      }
      if (panel_va == 0x4ed000u) {
        g_dispatchSave1534 = g_dispatchSave1534 + 1;
        g_dispatchSave1536 = g_dispatchSave1536 + 1;
        g_dispatchSave1538 = g_dispatchSave1538 + 1;
      }
      if (panel_va == 0x4ed020u) {
        g_dispatchSave1538 = g_dispatchSave1538 + 2;
        g_dispatchSave1536 = g_dispatchSave1536 + 2;
        uVar2 = (int)g_dispatchSave1538 - (int)(short)(g_dispatchSave1534 + -1);
        uVar3 = (int)uVar2 >> 0x1f;
        g_dispatchSave1534 = g_dispatchSave1534 + -1;
        if ((int)((uVar2 ^ uVar3) - uVar3) < 4) {
          g_dispatchSave1536 = g_dispatchSave1538;
          g_dispatchSave1534 = g_dispatchSave1538;
          return;
        }
      }
    }
    else {
      if (panel_va == 0x4ed040u) {
        g_dispatchSave1534 = g_dispatchSave1534 + 1;
        g_dispatchSave1535 = g_dispatchSave1535 + -2;
        g_dispatchSave1536 = g_dispatchSave1536 + 1;
        g_dispatchSave1537 = g_dispatchSave1537 + -1;
        g_dispatchSave1538 = g_dispatchSave1538 + 2;
        g_dispatchSave1539 = g_dispatchSave1539 + -1;
      }
      if (panel_va == 0x4ed060u) {
        g_dispatchSave1535 = g_dispatchSave1535 + -2;
        g_dispatchSave1537 = g_dispatchSave1537 + -1;
        g_dispatchSave1538 = g_dispatchSave1538 + 2;
        g_dispatchSave1539 = g_dispatchSave1539 + -1;
      }
      if (panel_va == 0x4ed000u) {
        g_dispatchSave1534 = g_dispatchSave1534 + 1;
        g_dispatchSave1536 = g_dispatchSave1536 + 1;
        g_dispatchSave1538 = g_dispatchSave1538 + 1;
      }
      if (panel_va == 0x4ed020u) {
        g_dispatchSave1538 = g_dispatchSave1538 + 2;
        g_dispatchSave1536 = g_dispatchSave1536 + -1;
        uVar2 = (int)g_dispatchSave1538 - (int)(short)(g_dispatchSave1534 + -1);
        uVar3 = (int)uVar2 >> 0x1f;
        g_dispatchSave1534 = g_dispatchSave1534 + -1;
        if ((int)((uVar2 ^ uVar3) - uVar3) < 4) {
          g_dispatchSave1534 = g_dispatchSave1538;
          g_dispatchSave1536 = g_dispatchSave1538;
        }
      }
    }
  }
  else if (param_2 == 0) {
    if (panel_va == 0x4ed040u) {
      g_dispatchSave1534 = g_dispatchSave1534 + 1;
      g_dispatchSave1536 = g_dispatchSave1536 + 3;
      g_dispatchSave1538 = g_dispatchSave1538 + 3;
    }
    if (panel_va == 0x4ed060u) {
      g_dispatchSave1536 = g_dispatchSave1536 + 2;
      g_dispatchSave1538 = g_dispatchSave1538 + 2;
    }
    if (panel_va == 0x4ed000u) {
      g_dispatchSave1534 = g_dispatchSave1534 + 1;
      g_dispatchSave1536 = g_dispatchSave1536 + 1;
      g_dispatchSave1538 = g_dispatchSave1538 + 1;
      g_dispatchSave1539 = g_dispatchSave1539 + 1;
    }
    if (panel_va == 0x4ed020u) {
      g_dispatchSave1536 = g_dispatchSave1536 + 2;
LAB_004bcd7f:
      g_dispatchSave1534 = g_dispatchSave1534 + 1;
      g_dispatchSave1537 = g_dispatchSave1537 + 1;
      g_dispatchSave1538 = g_dispatchSave1538 + 2;
      g_dispatchSave1539 = g_dispatchSave1539 + 1;
      return;
    }
  }
  else {
    if (panel_va == 0x4ed040u) {
      g_dispatchSave1534 = g_dispatchSave1534 + 1;
      g_dispatchSave1536 = g_dispatchSave1536 + 1;
      g_dispatchSave1538 = g_dispatchSave1538 + 3;
    }
    if (panel_va == 0x4ed060u) {
      g_dispatchSave1538 = g_dispatchSave1538 + 2;
    }
    if (panel_va == 0x4ed000u) {
      g_dispatchSave1534 = g_dispatchSave1534 + 1;
      g_dispatchSave1536 = g_dispatchSave1536 + 1;
      g_dispatchSave1537 = g_dispatchSave1537 + 1;
      g_dispatchSave1538 = g_dispatchSave1538 + 1;
      g_dispatchSave1539 = g_dispatchSave1539 + 1;
    }
    if (panel_va == 0x4ed020u) {
      g_dispatchSave1536 = g_dispatchSave1536 + 1;
      goto LAB_004bcd7f;
    }
  }
  return;
}
#else
__declspec(naked) void GamepadSeqRecord(void)
{
    __asm {
        push     esi
        call     Renderer_GetMode
        mov      esi, 2
        cmp      eax, esi
        je       L_cd96
        call     Renderer_GetMode
        cmp      eax, 1
        je       L_cd96
        mov      eax, dword ptr [esp + 0xc]
        test     eax, eax
        mov      eax, dword ptr [esp + 8]
        jne      L_cd11
        cmp      eax, OFFSET g_movesPanelEnd
        jne      L_ccbe
        inc      word ptr [g_dispatchSave1534]
        mov      ecx, 3
        add      word ptr [g_dispatchSave1536], cx
        add      word ptr [g_dispatchSave1538], cx
    L_ccbe:
        cmp      eax, OFFSET g_dispatchCmpEnd
        jne      L_ccd3
        add      word ptr [g_dispatchSave1536], si
        add      word ptr [g_dispatchSave1538], si
    L_ccd3:
        cmp      eax, OFFSET g_installCountdownEnd
        jne      L_ccf6
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
        inc      word ptr [g_dispatchSave1538]
        inc      word ptr [g_dispatchSave1539]
    L_ccf6:
        cmp      eax, OFFSET g_dispatchCmpEnd2
        jne      L_cf5c
        inc      word ptr [g_dispatchSave1534]
        add      word ptr [g_dispatchSave1536], si
        jmp      L_cd7f
    L_cd11:
        cmp      eax, OFFSET g_movesPanelEnd
        jne      L_cd2e
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
        add      word ptr [g_dispatchSave1538], 3
    L_cd2e:
        cmp      eax, OFFSET g_dispatchCmpEnd
        jne      L_cd3c
        add      word ptr [g_dispatchSave1538], si
    L_cd3c:
        cmp      eax, OFFSET g_installCountdownEnd
        jne      L_cd66
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
        inc      word ptr [g_dispatchSave1537]
        inc      word ptr [g_dispatchSave1538]
        inc      word ptr [g_dispatchSave1539]
    L_cd66:
        cmp      eax, OFFSET g_dispatchCmpEnd2
        jne      L_cf5c
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
    L_cd7f:
        inc      word ptr [g_dispatchSave1537]
        add      word ptr [g_dispatchSave1538], si
        inc      word ptr [g_dispatchSave1539]
        pop      esi
        ret
    L_cd96:
        mov      eax, dword ptr [esp + 0xc]
        mov      edx, 0xfffffffe
        test     eax, eax
        mov      eax, dword ptr [esp + 8]
        jne      L_ce8c
        cmp      eax, OFFSET g_movesPanelEnd
        jne      L_cde8
        mov      cx, word ptr [g_dispatchSave1538]
        inc      word ptr [g_dispatchSave1534]
        add      word ptr [g_dispatchSave1535], dx
        add      word ptr [g_dispatchSave1536], si
        add      word ptr [g_dispatchSave1537], dx
        add      cx, si
        dec      word ptr [g_dispatchSave1539]
        mov      word ptr [g_dispatchSave1538], cx
        jmp      L_cdef
    L_cde8:
        mov      cx, word ptr [g_dispatchSave1538]
    L_cdef:
        cmp      eax, OFFSET g_dispatchCmpEnd
        jne      L_ce1c
        add      word ptr [g_dispatchSave1535], dx
        add      word ptr [g_dispatchSave1536], si
        add      word ptr [g_dispatchSave1537], dx
        add      cx, si
        dec      word ptr [g_dispatchSave1539]
        mov      word ptr [g_dispatchSave1538], cx
    L_ce1c:
        cmp      eax, OFFSET g_installCountdownEnd
        jne      L_ce3a
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
        inc      cx
        mov      word ptr [g_dispatchSave1538], cx
    L_ce3a:
        cmp      eax, OFFSET g_dispatchCmpEnd2
        jne      L_cf5c
        mov      dx, word ptr [g_dispatchSave1534]
        add      cx, si
        dec      dx
        add      word ptr [g_dispatchSave1536], si
        mov      word ptr [g_dispatchSave1534], dx
        mov      word ptr [g_dispatchSave1538], cx
        movsx    eax, cx
        movsx    edx, dx
        sub      eax, edx
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 3
        jg       L_cf5c
        mov      word ptr [g_dispatchSave1536], cx
        mov      word ptr [g_dispatchSave1534], cx
        pop      esi
        ret
    L_ce8c:
        cmp      eax, OFFSET g_movesPanelEnd
        jne      L_cec9
        mov      cx, word ptr [g_dispatchSave1538]
        inc      word ptr [g_dispatchSave1534]
        add      word ptr [g_dispatchSave1535], dx
        inc      word ptr [g_dispatchSave1536]
        dec      word ptr [g_dispatchSave1537]
        add      cx, si
        dec      word ptr [g_dispatchSave1539]
        mov      word ptr [g_dispatchSave1538], cx
        jmp      L_ced0
    L_cec9:
        mov      cx, word ptr [g_dispatchSave1538]
    L_ced0:
        cmp      eax, OFFSET g_dispatchCmpEnd
        jne      L_cef6
        add      word ptr [g_dispatchSave1535], dx
        dec      word ptr [g_dispatchSave1537]
        add      cx, si
        dec      word ptr [g_dispatchSave1539]
        mov      word ptr [g_dispatchSave1538], cx
    L_cef6:
        cmp      eax, OFFSET g_installCountdownEnd
        jne      L_cf14
        inc      word ptr [g_dispatchSave1534]
        inc      word ptr [g_dispatchSave1536]
        inc      cx
        mov      word ptr [g_dispatchSave1538], cx
    L_cf14:
        cmp      eax, OFFSET g_dispatchCmpEnd2
        jne      L_cf5c
        mov      dx, word ptr [g_dispatchSave1534]
        add      cx, si
        dec      dx
        dec      word ptr [g_dispatchSave1536]
        mov      word ptr [g_dispatchSave1534], dx
        mov      word ptr [g_dispatchSave1538], cx
        movsx    eax, cx
        movsx    edx, dx
        sub      eax, edx
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 3
        jg       L_cf5c
        mov      word ptr [g_dispatchSave1536], cx
        mov      word ptr [g_dispatchSave1534], cx
    L_cf5c:
        pop      esi
        ret
    }
}
#endif
