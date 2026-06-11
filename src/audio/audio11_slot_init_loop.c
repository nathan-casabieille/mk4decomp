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

/*
 * CharSelect_HelpPrompts - 278b audio: zero an 11-slot table at 0x00543408, then iterate
 *   11 times calling GuardedSetupCallTailJmp(ptr_i, val_i). After each call, chain[+0x54]=0x190000;
 *   chain[+0x5c]=0x18000; store g_currentNodeIdx to (g_charSelHelpNodeIdxArr)[i].
 *   Stack-frame: sub esp, 0x58. Holds 11 const ptrs (0x004d24bc..0x004d2578) and 11 const vals
 *   (0xff9c0000..0x00930000 step 0x190000-ish).
 */
extern unsigned int g_charSelHelpNodeIdxArr;
extern unsigned int g_charSelHelpSlotBuf;
extern void GuardedSetupCallTailJmp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void CharSelect_HelpPrompts(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *apcStack_58 [22];
  
  puVar4 = (undefined4 *)0x543408;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  apcStack_58[0xb] = " ";
  apcStack_58[0xc] = "USE UP/DOWN TO";
  apcStack_58[0xd] = "SELECT A PLAYER.";
  apcStack_58[0xe] = "LEFT/RIGHT TO";
  apcStack_58[0xf] = "CHOOSE CHARACTER.";
  apcStack_58[0x10] = "PRESS PUNCH TO TOGGLE";
  apcStack_58[0x11] = "HUMAN OR CPU.";
  apcStack_58[0x12] = "PRESS KICK TO";
  apcStack_58[0x13] = "CHANGE CPU SKILL.";
  apcStack_58[0x14] = "PRESS START WHEN";
  apcStack_58[0x15] = "FINISHED.";
  apcStack_58[0] = (char *)0xff9c0000;
  apcStack_58[1] = (char *)0xffb20000;
  apcStack_58[2] = (char *)0xffcb0000;
  apcStack_58[3] = (char *)0xffe40000;
  apcStack_58[4] = (char *)0xfffd0000;
  apcStack_58[5] = (char *)0x160000;
  apcStack_58[6] = (char *)0x2f0000;
  apcStack_58[7] = "";
  apcStack_58[8] = &(*(unsigned int *)MK4_VA(unsigned int, 0x610000));
  apcStack_58[9] = (char *)0x7a0000;
  apcStack_58[10] = (char *)0x930000;
  uVar2 = 0;
  do {
    GuardedSetupCallTailJmp(*(undefined4 *)((int)apcStack_58 + uVar2 + 0x2c),
                 *(undefined4 *)((int)apcStack_58 + uVar2));
    uVar3 = uVar2 + 4;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x54) = 0x190000;
    MK4_NODE_AT(undefined4, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x5c) = 0x18000;
    *(int *)(uVar2 + 0x543408) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
    uVar2 = uVar3;
  } while (uVar3 < 0x2c);
  return;
}
#else
__declspec(naked) void CharSelect_HelpPrompts(void)
{
    __asm
    {
        sub     esp, 0x58
        push    ebx
        push    esi
        push    edi
        mov     ecx, 0xb
        xor     eax, eax
        mov     edi, offset g_charSelHelpSlotBuf
        rep     stosd
        mov     dword ptr [esp + 0x38], 0x004d24bc
        mov     dword ptr [esp + 0x3c], 0x004d24c0
        mov     dword ptr [esp + 0x40], 0x004d24d0
        mov     dword ptr [esp + 0x44], 0x004d24e8
        mov     dword ptr [esp + 0x48], 0x004d24f8
        mov     dword ptr [esp + 0x4c], 0x004d2510
        mov     dword ptr [esp + 0x50], 0x004d2528
        mov     dword ptr [esp + 0x54], 0x004d2538
        mov     dword ptr [esp + 0x58], 0x004d2548
        mov     dword ptr [esp + 0x5c], 0x004d2560
        mov     dword ptr [esp + 0x60], 0x004d2578
        mov     dword ptr [esp + 0x0c], 0xff9c0000
        mov     dword ptr [esp + 0x10], 0xffb20000
        mov     dword ptr [esp + 0x14], 0xffcb0000
        mov     dword ptr [esp + 0x18], 0xffe40000
        mov     dword ptr [esp + 0x1c], 0xfffd0000
        mov     dword ptr [esp + 0x20], 0x00160000
        mov     dword ptr [esp + 0x24], 0x002f0000
        mov     dword ptr [esp + 0x28], 0x00480000
        mov     dword ptr [esp + 0x2c], 0x00610000
        mov     dword ptr [esp + 0x30], 0x007a0000
        mov     dword ptr [esp + 0x34], 0x00930000
        xor     esi, esi
        mov     ebx, 0x190000
        mov     edi, 0x18000
    L_a5_iter:
        mov     eax, dword ptr [esp + esi + 0x0c]
        mov     ecx, dword ptr [esp + esi + 0x38]
        push    eax
        push    ecx
        call    GuardedSetupCallTailJmp
        mov     edx, dword ptr [g_currentNodeIdx]
        add     esi, 4
        add     esp, 8
        cmp     esi, 0x2c
        mov     dword ptr [edx*4 + 0x54], ebx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [eax*4 + 0x5c], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [esi + g_charSelHelpNodeIdxArr], ecx
        jb      short L_a5_iter
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0x58
        ret
    }
}
#endif
