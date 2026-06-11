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

extern unsigned int g_dispatchSave909;
extern void CallSetPause(void);
extern void ChainListVecAdd(void);
extern void ClampMulShiftStore(void);
extern void CopyThreeFields(void);
extern void MStackCall_MStackPush2ChainPrepend_00406600(void);
extern void MStackPushNegMul10(void);
extern void MStackPushZeroCallPop(void);
extern void PushSetXfmMaskCallPop(void);
extern void ThreeChanPackClamp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Phase4StateInit4Helpers(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  ChainDirtyBitWalker();
  if (g_framePauseFlag == 0) {
    if (((byte)g_xformDirtyFlags & 4) == 0) {
      g_dualC = g_eventQueuePending;
      g_walkCallback = 0x1359d6;
      PushSetXfmMaskCallPop();
      if (g_framePauseFlag != 0) {
        return;
      }
      if (((byte)g_xformDirtyFlags & 4) == 0) {
        iVar3 = g_dualC * 4;
        iVar1 = g_cj_0054205c * 4;
        *(undefined4 *)(iVar1 + 0x30) = 0x98;
        *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar3 + 0x3c);
        *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar3 + 0x40);
        g_walkCallback = *(undefined4 *)(iVar3 + 0x44);
        (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(int *)(iVar1 + 0x18);
        *(undefined4 *)(iVar1 + 0x5c) = g_walkCallback;
        ThreeChanPackClamp(0x100020);
        CopyThreeFields(g_cj_0054205c);
        g_eventQueuePending = MK4_NODE_AT(int, (*(unsigned int *)MK4_VA(unsigned int, 0x542044)), 0x28);
        puVar2 = (uint *)(g_eventQueuePending * 4);
        puVar2[0x12] = 0xa666;
        puVar2[5] = 0xff;
        *puVar2 = *puVar2 | 8;
        g_walkCallback = 0x4131f0;
        puVar2[4] = 0x4131f0;
        (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_cj_0054205c;
        MStackCall_MStackPush2ChainPrepend_00406600();
        if (g_framePauseFlag != 0) {
          return;
        }
      }
    }
    g_cj_0054205c = *MK4_NODE(int, (int)g_matrixStackTop);
    g_matrixStackTop = g_matrixStackTop + -1;
  }
  return;
}
#else
__declspec(naked) void Phase4StateInit4Helpers(void)
{
    __asm {
        call    ChainDirtyBitWalker
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p44_pop1
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, offset g_dispatchSave909
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_walkCallback], ecx
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p44_pop1
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_pendingNodeType]
        shl     ecx, 2
        lea     eax, [edx*4]
        mov     edx, 0x98
        mov     dword ptr [g_walkCallback], edx
        push    0x100020
        mov     dword ptr [eax + 0x30], edx
        mov     edx, dword ptr [ecx + 0x3C]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x54], edx
        mov     edx, dword ptr [ecx + 0x40]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x58], edx
        mov     ecx, dword ptr [ecx + 0x44]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax + 0x18]
        mov     dword ptr [eax + 0x5C], ecx
        mov     dword ptr [g_currentNodeIdx], edx
        call    ThreeChanPackClamp
        mov     eax, dword ptr [g_fightGroupHead]
        add     esp, 4
        push    eax
        call    CopyThreeFields
        mov     ecx, dword ptr [g_currentNodeIdx]
        add     esp, 4
        mov     eax, dword ptr [ecx*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        shl     eax, 2
        mov     ecx, dword ptr [eax]
        mov     dword ptr [eax + 0x48], 0xA666
        or      ecx, 8
        mov     dword ptr [eax + 0x14], 0xFF
        mov     dword ptr [eax], ecx
        mov     ecx, 0x004131F0
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x10], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackCall_MStackPush2ChainPrepend_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_ret
    L_p44_pop1:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_fightGroupHead], ecx
        mov     dword ptr [g_matrixStackTop], eax
    L_p44_ret:
        ret
        nop
        nop
        nop
    L_p44_helperA:
        call    ClampMulShiftStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_helperA_ret
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p44_helperA_ret
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x14]
        sub     eax, 0x16
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x14], eax
    L_p44_helperA_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_p44_helperB:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackPushZeroCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_helperB_ret
        call    MStackCall_MStackPush2ChainPrepend_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_helperB_ret
        mov     dword ptr [g_walkCallback], 0xCCC
        call    MStackPushNegMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_helperB_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x6C], edx
        lea     eax, [ecx*4]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax + 0x74], ecx
        mov     eax, dword ptr [eax + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0x20]
        or      ecx, 0x40
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x20], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        shl     eax, 2
        mov     ecx, dword ptr [eax]
        mov     dword ptr [eax + 0x48], 0x3333
        or      ecx, 0x0A
        mov     dword ptr [eax + 0x2C], 0x26666
        mov     dword ptr [eax], ecx
        mov     ecx, 0x00413310
        mov     dword ptr [eax + 0x14], 0xFF
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x10], ecx
        jmp     CallSetPause
    L_p44_helperB_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_p44_helperC:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p44_helperC_tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], 0xFFFFFEB9
        mov     eax, dword ptr [ecx*4 + 0x48]
        sub     eax, 0x147
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        call    ChainListVecAdd
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p44_helperC_ret
    L_p44_helperC_tail:
        jmp     ClampMulShiftStore
    L_p44_helperC_ret:
        ret
    }
}
#endif
