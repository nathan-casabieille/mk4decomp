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

/* @addr 0x0042f760 (221b game) - gated chain init. */
extern unsigned int g_bootGatedByte360c;
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void PushSetXfmMaskCallPop(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void GatedChainInit(void)

{
  int iVar1;
  
  if (g_bootGatedByte360c != '\0') {
    g_walkCallback = 0x138e26;
    PushSetXfmMaskCallPop();
    if ((g_framePauseFlag == 0) && (((byte)g_xformDirtyFlags & 4) == 0)) {
      MStackCall_MStackPush2ChainPrepend_00406340();
      if (g_framePauseFlag == 0) {
        iVar1 = (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4;
        *(undefined4 *)(iVar1 + 0x54) = 0;
        *(undefined4 *)(iVar1 + 0x58) = 0;
        *(undefined4 *)(iVar1 + 0x5c) = 0x3333;
        *(undefined4 *)(iVar1 + 0x60) = 0xca3d;
        g_walkCallback = 0x138e26;
        PushSetXfmMaskCallPop();
        if ((g_framePauseFlag == 0) && (((byte)g_xformDirtyFlags & 4) == 0)) {
          MStackCall_MStackPush2ChainPrepend_00406340();
          iVar1 = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
          if (g_framePauseFlag == 0) {
            MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) = 0xb333;
            MK4_NODE_AT(undefined4, iVar1, 0x58) = 0x3333;
            MK4_NODE_AT(undefined4, iVar1, 0x5c) = 0x3333;
            g_walkCallback = 0xca3d;
            MK4_NODE_AT(undefined4, iVar1, 0x60) = 0xca3d;
          }
        }
      }
    }
  }
  return;
}
#else
__declspec(naked) void GatedChainInit(void) {
    __asm {
        mov     al, byte ptr [g_bootGatedByte360c]
        push    esi
        test    al, al
        _emit   0fh
        _emit   84h
        _emit   0cdh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     esi, 0x004e3898
        shr     esi, 2
        mov     dword ptr [g_walkCallback], esi
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0adh
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   0fh
        _emit   85h
        _emit   0a0h
        _emit   00h
        _emit   00h
        _emit   00h
        call    MStackCall_MStackPush2ChainPrepend_00406340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   8eh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_currentNodeIdx]
        shl     eax, 2
        mov     dword ptr [eax + 0x54], 0
        mov     dword ptr [eax + 0x58], 0
        mov     dword ptr [eax + 0x5c], 0x00003333
        mov     dword ptr [eax + 0x60], 0x0000ca3d
        mov     dword ptr [g_walkCallback], esi
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   56h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   4dh
        call    MStackCall_MStackPush2ChainPrepend_00406340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3fh
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [ecx*4 + 0x54], 0x0000b333
        mov     dword ptr [ecx*4 + 0x58], 0x00003333
        mov     dword ptr [ecx*4 + 0x5c], 0x00003333
        lea     eax, [ecx*4 + 0]
        mov     dword ptr [g_walkCallback], 0x0000ca3d
        mov     dword ptr [eax + 0x60], 0x0000ca3d
        pop     esi
        ret
    }
}
#endif
