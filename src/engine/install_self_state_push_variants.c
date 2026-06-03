/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
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
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
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

/* @addr 0x00434990 (148b) - install-self variant of 0x4348f0:
 *   Same shape as InstallSelfStatePush_InstallSelf3StateDualBody_004348f0, but writes 0x10041 instead
 *   of 0x10042 to g_eventQueueNotMask and installs self at 0x00434990.
 */
extern unsigned int g_dispatchSave1580;
extern void CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp(void);
extern void HitReactionDispatcher(void);
extern void InstallSelf3StateDualBody(void);
extern void Wrapper_CmpDualPatchScaledRangeJmp_004e4990(void);

extern unsigned int g_chain_arr_4348f0;
extern void FiveCallGuardSetTail(void);

__declspec(naked) void InstallSelfStatePush_InstallSelf3StateDualBody_00434990(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [g_dispatchSave1580], 1
        shl     eax, 2
        xor     edx, edx
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   74h
        _emit   0fh
        mov     dword ptr [g_eventQueueNotMask], 0x10041
        jmp     HitReactionDispatcher
        mov     dword ptr [eax + 8], offset InstallSelfStatePush_InstallSelf3StateDualBody_00434990
        mov     ecx, dword ptr [g_baseSel]
        push    edi
        mov     edi, offset InstallSelfStatePush_InstallSelf3StateDualBody_00434990
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     ecx, dword ptr [eax + 4]
        add     edi, 0x01000000
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     [ecx*4 + g_chain_arr_4348f0], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     [eax*4 + 0x84], edx
        call    InstallSelf3StateDualBody
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        ret
    }
}

/* @addr 0x00435d40 (148b game) - install-self twin (0x1cccc/0x3c). */
__declspec(naked) void InstallSelfStatePush_CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp_00435d40(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        xor     edx, edx
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   74h
        _emit   05h
        jmp     Wrapper_CmpDualPatchScaledRangeJmp_004e4990
        mov     dword ptr [g_currentNodeFlags], 0x1cccc
        mov     dword ptr [g_eventQueueChild], 0x3c
        mov     dword ptr [eax + 8], offset InstallSelfStatePush_CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp_00435d40
        mov     ecx, dword ptr [g_baseSel]
        push    edi
        mov     edi, offset InstallSelfStatePush_CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp_00435d40
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     ecx, dword ptr [eax + 4]
        add     edi, 0x01000000
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     [ecx*4 + g_chain_arr_4348f0], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     [eax*4 + 0x84], edx
        call    CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        ret
    }
}

/* @addr 0x00435b00 (148b game) - install-self twin (0x34ccc/0x3c):
 *   Same shape as InstallSelfStatePush variants, but sets g_currentNodeFlags
 *   = 0x34ccc, g_eventQueueChild = 0x3c, calls CallPauseConstStoreJmp at tail.
 */
__declspec(naked) void InstallSelfStatePush_CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp_00435b00(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        xor     edx, edx
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   74h
        _emit   05h
        jmp     Wrapper_CmpDualPatchScaledRangeJmp_004e4990
        mov     dword ptr [g_currentNodeFlags], 0x34ccc
        mov     dword ptr [g_eventQueueChild], 0x3c
        mov     dword ptr [eax + 8], offset InstallSelfStatePush_CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp_00435b00
        mov     ecx, dword ptr [g_baseSel]
        push    edi
        mov     edi, offset InstallSelfStatePush_CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp_00435b00
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     ecx, dword ptr [eax + 4]
        add     edi, 0x01000000
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     [ecx*4 + g_chain_arr_4348f0], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     [eax*4 + 0x84], edx
        call    CallPauseConstStoreJmp_Push80SetWalkNegDualCallPop_then_InstallSelfWaitCmp
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        ret
    }
}

/* @addr 0x004348f0 (148b) - install-self with state push:
 *   g_dispatchSave1580 = 1; if chain[sel].slot84 != 0: g_eventQueueNotMask = 0x10042; jmp F.
 *   Else: install self at chain[sel]+8, slot84=1, slot4=newIdx; push 0x14348f0
 *   into mstack-like arr at scaledInit; clear chain[sel].slot84 in g_x array;
 *   call F2; g_framePauseFlag = 1; ret.
 */
__declspec(naked) void InstallSelfStatePush_InstallSelf3StateDualBody_004348f0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [g_dispatchSave1580], 1
        shl     eax, 2
        xor     edx, edx
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        cmp     ecx, edx
        _emit   74h
        _emit   0fh
        mov     dword ptr [g_eventQueueNotMask], 0x10042
        jmp     HitReactionDispatcher
        mov     dword ptr [eax + 8], offset InstallSelfStatePush_InstallSelf3StateDualBody_004348f0
        mov     ecx, dword ptr [g_baseSel]
        push    edi
        mov     edi, offset InstallSelfStatePush_InstallSelf3StateDualBody_004348f0
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     ecx, dword ptr [eax + 4]
        add     edi, 0x01000000
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     [ecx*4 + g_chain_arr_4348f0], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     [eax*4 + 0x84], edx
        call    InstallSelf3StateDualBody
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        ret
    }
}
