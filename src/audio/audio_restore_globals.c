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

extern unsigned int g_voiceBankTickByte;
extern unsigned int g_bootGatedByte360c;
extern unsigned int g_audioRestoreByte10;
extern unsigned int g_audioStateWalk6;
extern unsigned int g_audioStateWalk7;
extern unsigned int g_audioStateByte730;
extern unsigned int g_audioRestoreCount;
extern unsigned int g_audioRestoreByte3c;
extern unsigned int g_audioRestoreByte3d;
extern unsigned int g_audioRestoreByte3e;
extern unsigned int g_menuPageTailByte;
extern unsigned int g_audioStateMachineVar6;
extern unsigned int g_audioStateMachineVar5;
extern unsigned int g_audioStateMachineVar3;
extern unsigned int g_loaded;
extern unsigned int g_dispatchSave813;
extern unsigned int g_dispatchSave577;
extern unsigned int g_dispatchSave576;
extern unsigned int g_dispatchSave575;
extern unsigned int g_dispatchSave574;
extern unsigned int g_or;
extern unsigned int g_audioRestoreSlot3;
extern unsigned int g_audioSavedGlobal0;
extern unsigned int g_audioSavedGlobal1;
extern unsigned int g_audioSavedGlobal2;
extern unsigned int g_audioSavedGlobal3;
extern unsigned int g_audioSavedGlobal4;
extern unsigned int g_audioSavedGlobal5;
extern u32 g_gsmFlag;
extern unsigned int g_audioSavedReg_00543a28;
extern unsigned int g_audioSavedReg_00543a2c;
extern unsigned int g_audioSavedReg_00543a30;
extern unsigned int g_audioSavedReg_00543a34;
extern unsigned int g_audioSavedReg_00543a38;
extern unsigned int g_audioSavedReg_00543a40;
extern unsigned int g_audioSavedReg_00543a44;
extern unsigned int g_audioSavedReg_00543a48;
extern unsigned int g_audioSavedReg_00543a4c;
extern unsigned int g_audioSavedReg_00543a50;
extern unsigned int g_audioSavedReg_00543a54;
extern unsigned int g_audioSavedReg_00543a58;
extern unsigned int g_audioSavedReg_00543a5c;
extern unsigned int g_audioSavedReg_00543a60;
extern unsigned int g_audioSavedReg_00543a64;
extern unsigned int g_audioRestoreSlot2;
extern unsigned int g_menuRestoreD;
extern unsigned int g_menuRestoreA;
extern unsigned int g_menuRestoreB;
extern unsigned int g_menuRestoreC;
extern unsigned int g_configInitGate;
extern unsigned int g_audioSlotMarks;
extern unsigned int g_audioRestoreBuf;
extern unsigned int g_audioStateGlobals;
extern unsigned int g_audioStateGlobalsSnap;
extern unsigned int g_audioStateMachine0;
extern unsigned int g_audioStateMachine1;
extern void Config_SnapshotGlobals(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Config_RestoreGlobals(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  if ((g_gsmFlag == 0) || (g_configInitGate == 0)) {
    bVar4 = g_gsmFlag == 0;
    g_gsmFlag = 1;
    g_configInitGate = 1;
    if (bVar4) {
      Config_SnapshotGlobals();
    }
    g_voiceBankTickByte = g_audioRestoreCount;
    puVar2 = &g_audioStateGlobals;
    puVar3 = &g_audioRestoreBuf;
    for (iVar1 = 0x3c; g_audioStateMachineVar5 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a2c)), iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &g_audioStateGlobalsSnap;
    puVar3 = &g_audioSlotMarks;
    for (iVar1 = 5; g_or = g_audioRestoreSlot2, g_audioStateMachine1 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a64)), iVar1 != 0;
        iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    g_audioStateMachineVar6 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a28));
    g_audioSavedGlobal4 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a30));
    g_audioSavedGlobal5 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a34));
    g_gtConfig4f = (*(unsigned int *)MK4_VA(unsigned int, 0x543a38));
    g_audioStateWalk6 = g_audioRestoreByte3c;
    g_audioStateWalk7 = g_audioRestoreByte3d;
    g_audioStateByte730 = g_audioRestoreByte3e;
    g_audioSavedGlobal0 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a40));
    g_audioSavedGlobal1 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a44));
    g_audioSavedGlobal2 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a48));
    g_audioSavedGlobal3 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a4c));
    g_dispatchSave1319 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a50));
    g_dispatchSave1320 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a54));
    g_dispatchSave1321 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a58));
    g_dispatchSave1322 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a5c));
    g_audioStateMachine0 = (*(unsigned int *)MK4_VA(unsigned int, 0x543a60));
    *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
  }
  g_bootGatedByte360c = (undefined1)g_menuPageTailByte;
  g_audioRestoreByte10 = (undefined1)g_menuPageTailByte;
  g_loaded = g_menuRestoreC;
  g_audioStateMachineVar3 = g_menuRestoreB;
  g_audioRestoreSlot3 = g_menuRestoreD;
  g_dispatchSave813 = g_menuRestoreA;
  return;
}
#else
__declspec(naked) void Config_RestoreGlobals(void)
{
    __asm {
        mov     eax, dword ptr [g_gsmFlag]
        push    esi
        test    eax, eax
        push    edi
        je      L_arg_setboth
        mov     ecx, dword ptr [g_configInitGate]
        test    ecx, ecx
        jne     L_arg_tail
    L_arg_setboth:
        mov     ecx, 1
        test    eax, eax
        mov     dword ptr [g_gsmFlag], ecx
        mov     dword ptr [g_configInitGate], ecx
        jne     L_arg_main
        call    Config_SnapshotGlobals
    L_arg_main:
        mov     ecx, 0x3C
        mov     esi, offset g_audioStateGlobals
        mov     edi, offset g_audioRestoreBuf
        mov     al, byte ptr [g_audioRestoreCount]
        rep     movsd
        mov     edx, dword ptr [g_audioSavedReg_00543a2c]
        mov     ecx, 5
        mov     esi, offset g_audioStateGlobalsSnap
        mov     edi, offset g_audioSlotMarks
        rep     movsd
        mov     ecx, dword ptr [g_audioSavedReg_00543a28]
        mov     byte ptr [g_voiceBankTickByte], al
        mov     eax, dword ptr [g_audioSavedReg_00543a30]
        mov     dword ptr [g_audioStateMachineVar6], ecx
        mov     ecx, dword ptr [g_audioSavedReg_00543a34]
        mov     dword ptr [g_audioStateMachineVar5], edx
        mov     edx, dword ptr [g_audioSavedReg_00543a38]
        mov     dword ptr [g_audioSavedGlobal4], eax
        mov     al, byte ptr [g_audioRestoreByte3c]
        mov     dword ptr [g_audioSavedGlobal5], ecx
        mov     cl, byte ptr [g_audioRestoreByte3d]
        mov     dword ptr [g_gtConfig4f], edx
        mov     dl, byte ptr [g_audioRestoreByte3e]
        mov     byte ptr [g_audioStateWalk6], al
        mov     eax, dword ptr [g_audioSavedReg_00543a40]
        mov     byte ptr [g_audioStateWalk7], cl
        mov     ecx, dword ptr [g_audioSavedReg_00543a44]
        mov     byte ptr [g_audioStateByte730], dl
        mov     edx, dword ptr [g_audioSavedReg_00543a48]
        mov     dword ptr [g_audioSavedGlobal0], eax
        mov     eax, dword ptr [g_audioSavedReg_00543a4c]
        mov     dword ptr [g_audioSavedGlobal1], ecx
        mov     ecx, dword ptr [g_audioSavedReg_00543a50]
        mov     dword ptr [g_audioSavedGlobal2], edx
        mov     edx, dword ptr [g_audioSavedReg_00543a54]
        mov     dword ptr [g_audioSavedGlobal3], eax
        mov     eax, dword ptr [g_audioSavedReg_00543a58]
        mov     dword ptr [g_dispatchSave577], ecx
        mov     ecx, dword ptr [g_audioSavedReg_00543a5c]
        mov     dword ptr [g_dispatchSave576], edx
        mov     edx, dword ptr [g_audioSavedReg_00543a60]
        mov     dword ptr [g_dispatchSave575], eax
        mov     eax, dword ptr [g_audioSavedReg_00543a64]
        mov     dword ptr [g_dispatchSave574], ecx
        mov     ecx, dword ptr [g_audioRestoreSlot2]
        mov     dword ptr [g_audioStateMachine0], edx
        movsb
        mov     dword ptr [g_audioStateMachine1], eax
        mov     dword ptr [g_or], ecx
    L_arg_tail:
        mov     al, byte ptr [g_menuPageTailByte]
        mov     edx, dword ptr [g_menuRestoreC]
        mov     ecx, dword ptr [g_menuRestoreD]
        mov     byte ptr [g_bootGatedByte360c], al
        mov     byte ptr [g_audioRestoreByte10], al
        mov     eax, dword ptr [g_menuRestoreB]
        mov     dword ptr [g_loaded], edx
        mov     edx, dword ptr [g_menuRestoreA]
        pop     edi
        mov     dword ptr [g_audioStateMachineVar3], eax
        mov     dword ptr [g_audioRestoreSlot3], ecx
        mov     dword ptr [g_dispatchSave813], edx
        pop     esi
        ret
    }
}
#endif
