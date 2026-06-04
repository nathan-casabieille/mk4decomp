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

/* @addr 0x00404d50 (146b boot) - scaled 3-channel pack:
 *   Multiply 3 byte channels (from arg1 hi byte / mid / low) by g_walkCallback,
 *   add corresponding word at 0xab4e44/48/4c, clamp each to <=0xfe00, store back.
 *   Clear 3 dword globals.
 */
extern unsigned int g_pointColorR;
extern unsigned int g_pointColorG;
extern unsigned int g_pointColorB;
extern unsigned int g_pointPosX;
extern unsigned int g_pointPosY;
extern unsigned int g_pointPosZ;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void ScaledThreeChanPack(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = ((int)param_1 >> 0x10) * g_walkCallback + (uint)g_gtAxisX;
  uVar3 = (param_1 >> 8 & 0xff) * g_walkCallback + (uint)g_gtAxisY;
  uVar1 = (param_1 & 0xff) * g_walkCallback + (uint)g_gtAxisZ;
  if (0xfe00 < uVar2) {
    uVar2 = 0xfe00;
  }
  if (0xfe00 < uVar3) {
    uVar3 = 0xfe00;
  }
  if (0xfe00 < uVar1) {
    uVar1 = 0xfe00;
  }
  g_gtAxisZ = (short)uVar1;
  g_gtAxisX = (short)uVar2;
  g_gtAxisY = (short)uVar3;
  g_pointPosZ = 0;
  g_pointPosY = 0;
  g_pointPosX = 0;
  return;
}
#else
__declspec(naked) void ScaledThreeChanPack(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        mov     esi, dword ptr [g_walkCallback]
        mov     ecx, eax
        sar     ecx, 16
        imul    ecx, esi
        xor     edx, edx
        push    edi
        mov     dx, word ptr [g_pointColorR]
        xor     edi, edi
        add     ecx, edx
        xor     edx, edx
        mov     dl, ah
        and     eax, 0xff
        imul    edx, esi
        imul    eax, esi
        mov     di, word ptr [g_pointColorG]
        xor     esi, esi
        mov     si, word ptr [g_pointColorB]
        add     edx, edi
        add     eax, esi
        cmp     ecx, 0xfe00
        _emit   76h
        _emit   05h
        mov     ecx, 0xfe00
        cmp     edx, 0xfe00
        _emit   76h
        _emit   05h
        mov     edx, 0xfe00
        cmp     eax, 0xfe00
        _emit   76h
        _emit   05h
        mov     eax, 0xfe00
        mov     word ptr [g_pointColorB], ax
        xor     eax, eax
        pop     edi
        mov     word ptr [g_pointColorR], cx
        mov     word ptr [g_pointColorG], dx
        mov     dword ptr [g_pointPosZ], eax
        mov     dword ptr [g_pointPosY], eax
        mov     dword ptr [g_pointPosX], eax
        pop     esi
        ret
    }
}
#endif
