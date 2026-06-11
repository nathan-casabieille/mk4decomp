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

/* @addr 0x00427390 (204b game) - 5-step setup if [g_bootGatedByte360c] is set.
 *   call MStackPush8; pause-check. Set g_walkCallback = 0x004e2760>>2.
 *   call PushSetXfmMaskCallPop; pause-check.
 *   If bit-2 not set: setup chain[+0x30]=0x25c, [+0x54]=g_chainAccumCur, [+0x5c]=g_eventQueueNotMask,
 *     [+0x58]=0xfffffd71. Set g_walkCallback=0x18000; scaledInit = [chain*4+0x18]; chain[+0x3c]=0x18000.
 *   call MStackCall_MStackPush2ChainPrepend_004062f0; if !pause jmp MStackPop8; ret.
 */
extern unsigned int g_bootGatedByte360c;
extern void MStackCall_MStackPush2ChainPrepend_004062f0(void);
extern void MStackPop8(void);
extern void MStackPush8(void);
extern void PushSetXfmMaskCallPop(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void GatedScaledChainSetup(void)

{
  if ((g_bootGatedByte360c != '\0') && (MStackPush8(), g_framePauseFlag == 0)) {
    g_walkCallback = 0x1389d8;
    PushSetXfmMaskCallPop();
    if (g_framePauseFlag == 0) {
      if (((byte)g_xformDirtyFlags & 4) == 0) {
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x30) = 0x25c;
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x54) = g_chainAccumCur;
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x5c) = g_eventQueueNotMask;
        MK4_NODE_AT(undefined4, g_cj_0054205c, 0x58) = 0xfffffd71;
        (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = MK4_NODE_AT(int, g_cj_0054205c, 0x18);
        g_walkCallback = 0x18000;
        MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x3c) = 0x18000;
        MStackCall_MStackPush2ChainPrepend_004062f0();
        if (g_framePauseFlag != 0) {
          return;
        }
      }
      g_baseSel = *MK4_NODE(undefined4, (int)g_matrixStackTop);
      g_cj_0054205c = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -1));
      g_cj_00542058 = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -2));
      g_cj_00542054 = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -3));
      g_dualD = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -4));
      g_dualC = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -5));
      g_eventQueuePending = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -6));
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *MK4_NODE(undefined4, (int)(g_matrixStackTop + -7));
      g_matrixStackTop = g_matrixStackTop + -8;
      return;
    }
  }
  return;
}
#else
__declspec(naked) void GatedScaledChainSetup(void) {
    __asm {
        mov     al, byte ptr [g_bootGatedByte360c]
        test    al, al
        _emit   0fh
        _emit   84h
        _emit   0beh
        _emit   00h
        _emit   00h
        _emit   00h
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0ach
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, 0x004e2760
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   8dh
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   7fh
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [ecx*4 + 0x30], 0x0000025c
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_chainAccumCur]
        mov     dword ptr [edx*4 + 0x54], eax
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_eventQueueNotMask]
        mov     eax, 0xfffffd71
        mov     dword ptr [ecx*4 + 0x5c], edx
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, 0x00018000
        mov     eax, dword ptr [edx*4 + 0x18]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0x3c], ecx
        call    MStackCall_MStackPush2ChainPrepend_004062f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     MStackPop8
        ret
    }
}
#endif
