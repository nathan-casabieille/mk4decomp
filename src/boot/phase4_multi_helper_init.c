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

extern unsigned int g_dispatchSave613;
extern unsigned int g_dispatchSave612;
extern unsigned int g_dispatchSave611;
extern unsigned int g_dispatchSave95;
extern unsigned int g_phase4HelperSlot;
extern void BootSetupWithMStackBody(void);
extern void CallSetPause(void);
extern void ClampMulShiftStore(void);
extern void Helper_MenuStub_8EB0(void);
extern void MStackCall_MStackPush2ChainPrepend_004062f0(void);
extern void MStackCall_MStackPush2ChainPrepend_00406600(void);
extern void MStackPop8(void);
extern void MStackPush8(void);
extern void PushSetXfmMaskCallPop(void);
extern void ScaledTripleCopy54(void);
extern void SetJmp_BootStateTriple(void);
extern void TableWalkBoundedCmp(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Phase4MultiHelperInit(void)

{
  int iVar1;
  
  MStackPush8();
  if (g_framePauseFlag == 0) {
    g_cj_00542054 = g_cj_0054205c;
    g_walkCallback = 0x135d68;
    PushSetXfmMaskCallPop();
    if (g_framePauseFlag == 0) {
      if (((byte)g_xformDirtyFlags & 4) != 0) {
LAB_00418bd4:
        MStackPop8();
        return;
      }
      SetJmp_BootStateTriple();
      iVar1 = g_eventQueuePending;
      if (g_framePauseFlag == 0) {
        MK4_NODE_AT(undefined4, g_eventQueuePending, 0x48) = 0x3333;
        MK4_NODE_AT(undefined4, iVar1, 0x14) = 0xff;
        MK4_NODE_AT(uint, iVar1, 0) = MK4_NODE_AT(uint, iVar1, 0) | 8;
        g_walkCallback = 0x418be0;
        ((uint *)(iVar1 * 4))[4] = 0x418be0;
        ScaledTripleCopy54();
        if (g_framePauseFlag == 0) {
          MK4_NODE_AT(int, g_cj_0054205c, 0x58) = MK4_NODE_AT(int, g_cj_0054205c, 0x58) + -0x1c000;
          g_walkCallback = MK4_NODE_AT(undefined4, g_cj_0054205c, 0x58);
          (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = g_cj_0054205c;
          MStackCall_MStackPush2ChainPrepend_00406600();
          if (g_framePauseFlag == 0) goto LAB_00418bd4;
        }
      }
    }
  }
  return;
}
#else
__declspec(naked) void Phase4MultiHelperInit(void)
{
    __asm {
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_A_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, offset g_dispatchSave612
        shr     ecx, 2
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [g_walkCallback], ecx
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_A_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4mh_A_tailjmp
        call    SetJmp_BootStateTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_A_ret
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [edx*4 + 0x48], 0x3333
        mov     dword ptr [edx*4 + 0x14], 0xFF
        mov     ecx, dword ptr [edx*4]
        lea     eax, [edx*4]
        or      ecx, 8
        mov     dword ptr [eax], ecx
        mov     ecx, 0x00418BE0
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x10], ecx
        call    ScaledTripleCopy54
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_A_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x58]
        add     ecx, 0xFFFE4000
        mov     dword ptr [eax*4 + 0x58], ecx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x58]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_walkCallback], ecx
        call    MStackCall_MStackPush2ChainPrepend_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_A_ret
    L_p4mh_A_tailjmp:
        jmp     MStackPop8
    L_p4mh_A_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4mh_helperB:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4mh_B_tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        sub     eax, dword ptr [ecx*4 + 0x48]
        push    eax
        push    0x1999
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        add     eax, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x48], eax
    L_p4mh_B_tail:
        jmp     ClampMulShiftStore
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
    L_p4mh_mainC:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4mh_C_phase0
        dec     eax
        je      L_p4mh_C_phase1
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [eax*4]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        jne     L_p4mh_C_have_target
        call    CallSetPause
        pop     esi
        ret
    L_p4mh_C_phase1:
        mov     eax, dword ptr [g_phase4HelperSlot]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        je      L_p4mh_C_set_install
        mov     ecx, offset g_dispatchSave611
        shr     ecx, 2
        mov     dword ptr [g_walkCallback], ecx
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_C_exit
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4mh_C_after_init
        call    ScaledTripleCopy54
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_C_exit
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, 0xFFFFE667
        mov     dword ptr [edx*4 + 0x58], 0x00190000
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x80], eax
        call    MStackCall_MStackPush2ChainPrepend_004062f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_C_exit
    L_p4mh_C_after_init:
        mov     dword ptr [g_eventQueueTotal], 6
        mov     dword ptr [g_eventQueueNotMask], 0x003C0000
        call    BootSetupWithMStackBody
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4mh_C_exit
    L_p4mh_C_loop:
        mov     ecx, dword ptr [g_eventQueueNotMask]
        mov     eax, dword ptr [g_eventQueueTotal]
        sub     ecx, 0x0009FD70
        dec     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        js      L_p4mh_C_loop_done
        call    BootSetupWithMStackBody
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      L_p4mh_C_loop
        pop     esi
        ret
    L_p4mh_C_loop_done:
        mov     eax, offset g_dispatchSave613
        shr     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
    L_p4mh_C_have_target:
        mov     ecx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_dispatchSave95], ecx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     edx, dword ptr [eax*4]
        inc     eax
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_eventQueueEnd], eax
        mov     dword ptr [esi + 8], 0x00418C40
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    L_p4mh_C_phase0:
        mov     byte ptr [g_gtPlayerEnabled], 0
        call    Helper_MenuStub_8EB0
        push    7
        call    TableWalkBoundedCmp
        add     esp, 4
        push    8
        call    TableWalkBoundedCmp
        add     esp, 4
    L_p4mh_C_set_install:
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x00418C40
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p4mh_C_exit:
        pop     esi
        ret
    }
}
#endif
