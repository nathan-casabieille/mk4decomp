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

/* @addr 0x00433c60 (197b game) - branch packed_ptr select, then load 6 fields.
 *   eax = packed_ptr(0x541d98); ecx = packed_ptr(0x535d18);
 *   g_scaledInit = eax; g_xformEntityIdx = ecx;
 *   if (g_fightGroupHead != [0x538158]) g_scaledInit = ecx;
 *   Walk g_scaledInit forward, storing 6 values into:
 *     g_eventQueueNotMask, 80, 84, 88, 54, 58 (using edx/ecx alternating).
 *   Then: g_scaledInit = chain[g_baseSel + 0x3c];
 *   g_walkCallback = chain[g_scaledInit + 0x74].
 */

extern unsigned int g_matrixStack_arr;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PackedSelectLoad6(void)

{
  int iVar1;
  
  g_eventQueuePending = 0x14d746;
  iVar1 = 0x150766;
  if (g_cj_0054205c != g_player1NodeIdx) {
    iVar1 = 0x14d746;
  }
  g_eventQueueNotMask = MK4_NODE_AT(undefined4, iVar1, 0);
  g_eventQueueChild = *MK4_NODE(undefined4, (iVar1 + 1));
  g_currentNodeFlags = *MK4_NODE(undefined4, (iVar1 + 2));
  g_xformScratch2088 = *MK4_NODE(undefined4, (iVar1 + 3));
  g_cj_00542054 = *MK4_NODE(undefined4, (iVar1 + 4));
  g_cj_00542058 = *MK4_NODE(undefined4, (iVar1 + 5));
  (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = MK4_NODE_AT(int, g_baseSel, 0x3c);
  g_walkCallback = MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x74);
  return;
}
#else
__declspec(naked) void PackedSelectLoad6(void) {
    __asm {
        mov     edx, dword ptr [g_fightGroupHead]
        push    esi
        mov     esi, dword ptr [g_player1NodeIdx]
        mov     eax, 0x00541d98
        mov     ecx, 0x00535d18
        shr     eax, 2
        shr     ecx, 2
        cmp     edx, esi
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        _emit   74h
        _emit   07h
        mov     eax, ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, [eax*4 + g_matrixStack_arr]
        inc     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     edx, [eax*4 + g_matrixStack_arr]
        inc     eax
        mov     dword ptr [g_eventQueueChild], edx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, [eax*4 + g_matrixStack_arr]
        inc     eax
        mov     dword ptr [g_currentNodeFlags], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     edx, [eax*4 + g_matrixStack_arr]
        inc     eax
        mov     dword ptr [g_xformScratch2088], edx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, [eax*4 + g_matrixStack_arr]
        inc     eax
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     edx, [eax*4 + g_matrixStack_arr]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [g_eventQueueIdx], edx
        pop     esi
        mov     eax, [eax*4 + 0x3c]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, [eax*4 + 0x74]
        mov     dword ptr [g_walkCallback], ecx
        ret
    }
}
#endif
