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

extern unsigned int g_dispatchVar42;
extern unsigned int g_dispatchSave615;
extern unsigned int g_eventQueueSeed;
extern void CallSetPause(void);
extern void ClampMulShiftStore(void);
extern void MStackCall_MStackPush2ChainInsert_004062a0(void);
extern void MStackCall_MStackPush2ChainPrepend_00406600(void);
extern void MStackPushZeroCallPop(void);
extern void PushSetDualDeref(void);
extern void PushSetXfmMaskCallPop(void);
extern void QuadMul10TailFpuChain(void);
extern void ScaledChainOr8(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Phase4TrampolineThreePacked(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = (*(unsigned int *)MK4_VA(unsigned int, 0x542044));
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_dualC;
  StoreTwoCall(0x40fa90,0x84);
  g_dualC = *(undefined4 *)((int)g_matrixStackTop * 4);
  (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = *(undefined4 *)((int)(g_matrixStackTop + -1) * 4);
  g_matrixStackTop = g_matrixStackTop + -2;
  return;
}
#else
__declspec(naked) void Phase4TrampolineThreePacked(void)
{
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        push    0x84
        mov     dword ptr [g_matrixStackTop], eax
        push    0x0040FA90
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_pendingNodeType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        call    StoreTwoCall
        mov     eax, dword ptr [g_matrixStackTop]
        add     esp, 8
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
        ret
        nop
        nop
    L_p4ttp_B:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      L_p4ttp_B_phase0
        dec     eax
        je      L_p4ttp_B_phase1
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], ecx
        call    MStackPushZeroCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4ttp_B_exit
        mov     eax, dword ptr [g_eventQueueIdx]
        dec     eax
        mov     dword ptr [g_eventQueueIdx], eax
        jns     L_p4ttp_B_install
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackCall_MStackPush2ChainPrepend_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        je      L_p4ttp_B_tailjmp_0041f830
        pop     esi
        ret
    L_p4ttp_B_phase1:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackPushZeroCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4ttp_B_exit
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], ecx
        call    MStackCall_MStackPush2ChainInsert_004062a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4ttp_B_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0040FA90
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    L_p4ttp_B_phase0:
        mov     eax, dword ptr [g_eventQueueSeed]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_eventQueueEnd], edx
        mov     ecx, dword ptr [eax*4 + 0x54]
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     edx, dword ptr [eax*4 + 0x5C]
        mov     dword ptr [g_eventQueueChild], edx
        call    QuadMul10TailFpuChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4ttp_B_exit
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     edx, dword ptr [g_eventQueueNotMask]
        mov     ecx, dword ptr [eax*4 + 0x54]
        add     edx, ecx
        mov     dword ptr [g_eventQueueNotMask], edx
        mov     edx, dword ptr [eax*4 + 0x5C]
        mov     eax, dword ptr [g_eventQueueChild]
        add     eax, edx
        mov     dword ptr [g_eventQueueChild], eax
        mov     eax, offset g_dispatchVar42
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4ttp_B_exit
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4ttp_B_tailjmp_0041f830
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_eventQueueNotMask]
        mov     dword ptr [ecx*4 + 0x54], edx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueChild]
        mov     dword ptr [eax*4 + 0x5C], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [edx*4 + 0x58], 0xFFFFB334
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], 0x46
        mov     dword ptr [eax*4 + 0x30], 0x46
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4]
        or      ecx, 8
        mov     dword ptr [eax*4], ecx
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [edx*4 + 0x48], 0x1999
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [eax*4 + 0x14], 0xFF
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x0040FDE0
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x10], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackCall_MStackPush2ChainPrepend_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4ttp_B_exit
        mov     eax, offset g_dispatchSave615
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4ttp_B_exit
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4ttp_B_continue
    L_p4ttp_B_tailjmp_0041f830:
        call    CallSetPause
        pop     esi
        ret
    L_p4ttp_B_continue:
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [ecx*4 + 0x30], 0x46
        mov     dword ptr [g_walkCallback], 0xC0
        call    PushSetDualDeref
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4ttp_B_exit
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_eventQueueNotMask]
        mov     dword ptr [edx*4 + 0x54], eax
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_eventQueueChild]
        mov     dword ptr [ecx*4 + 0x5C], edx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax*4 + 0x58], 0x18000
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0xFFFFEE98
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x70], eax
        call    ScaledChainOr8
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x16666
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x48], eax
        mov     dword ptr [g_eventQueueIdx], 0x0D
    L_p4ttp_B_install:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], eax
        call    MStackCall_MStackPush2ChainPrepend_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4ttp_B_exit
        mov     eax, 1
        mov     dword ptr [esi + 8], 0x0040FA90
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
    L_p4ttp_B_exit:
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4ttp_C:
        call    ClampMulShiftStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4ttp_C_ret
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4ttp_C_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0x48]
        add     ecx, 0x11EB
        mov     dword ptr [eax*4 + 0x48], ecx
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [ecx*4 + 0x14]
        sub     eax, 0x10
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x14], eax
    L_p4ttp_C_ret:
        ret
    }
}
#endif
