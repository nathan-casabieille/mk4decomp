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

/* @addr 0x004a8310 (377b audio) - phase-state install w/ vol-up/down on input.
 *   Phase 0: sets [0x52aac4]=2, [0x53a50c]=0xe, installs Self with
 *     slot[+0x84]=1, g_pendingNodeType=1, arms 0x541e6c=1.
 *   Phase 1+: AudioSwap2ChainBank3State; reads slot[+0x30]:
 *     if 4 → reads vol byte at [g_byte_005435a0 + 0x542070*0x18],
 *     if 3 → similar with g_counter_0054359c stride. Then
 *     DualListInit + [g_gtModeFlag]==1 ? DebugStub_NoOp_A :
 *     DebugStub_NoOp_B. Tests [g_byte_004d50b4] al/ah bit 2 / 3 for
 *     vol-down / vol-up (via dec/inc cl on the 0x18-stride byte table),
 *     wrapping at 0/0xe. Final call TripleCallByteCheck; on
 *     zero, calls AudioMicroEntries with the current vol byte
 *     and tail-jmps StackPopDispatchTagged. Else: stores
 *     g_eventQueueEnd into 0x542044, vol byte into 0x54206c, calls
 *     ScaledChainStore24 and falls through to install tail.
 */
extern unsigned int g_byte_004d50b4;
extern unsigned int g_tickFlagF;
extern unsigned int g_phaseIdx;
extern unsigned int g_counter_005433c8;
extern unsigned int g_counter_0054359c;
extern unsigned int g_byte_005435a0;
extern void AudioMicroEntries(void);
extern void AudioSwap2ChainBank3State(void);
extern void DebugStub_NoOp_A(void);
extern void DebugStub_NoOp_B(void);
extern void DualListInit(void);
extern void ScaledChainStore24(void);
extern void SetJmp_Push16Call_004a1ad0(void);
extern void TripleCallByteCheck(void);

__declspec(naked) void Phase3InstallVolToggle(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_p3v_phase0
        call    AudioSwap2ChainBank3State
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x30]
        sub     eax, 3
        je      short L_p3v_phase3
        dec     eax
        jne     short L_p3v_afterSnap
        mov     eax, dword ptr [g_counter_005433c8]
        add     ecx, eax
        add     eax, 5
        mov     edx, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_eventQueueEnd], edx
        jmp     short L_p3v_storeVol
    L_p3v_phase3:
        mov     eax, dword ptr [g_counter_0054359c]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4 + 0x34]
        mov     dword ptr [g_eventQueueEnd], edx
    L_p3v_storeVol:
        mov     dword ptr [g_eventQueueCurrent], eax
    L_p3v_afterSnap:
        call    DualListInit
        cmp     byte ptr [g_gtModeFlag], 1
        jne     short L_p3v_useStubB
        call    DebugStub_NoOp_A
        jmp     short L_p3v_postStub
    L_p3v_useStubB:
        call    DebugStub_NoOp_B
    L_p3v_postStub:
        mov     eax, dword ptr [g_byte_004d50b4]
        test    al, 4
        jne     short L_p3v_doDown
        test    ah, 4
        je      short L_p3v_checkUp
    L_p3v_doDown:
        call    SetJmp_Push16Call_004a1ad0
        mov     eax, dword ptr [g_eventQueueCurrent]
        lea     eax, [eax + eax*2]
        mov     cl, byte ptr [eax*8 + g_byte_005435a0]
        dec     cl
        mov     byte ptr [eax*8 + g_byte_005435a0], cl
        jns     short L_p3v_okDown
        mov     byte ptr [eax*8 + g_byte_005435a0], 0xe
    L_p3v_okDown:
        mov     eax, dword ptr [g_byte_004d50b4]
    L_p3v_checkUp:
        test    al, 8
        jne     short L_p3v_doUp
        test    ah, 8
        je      short L_p3v_postUp
    L_p3v_doUp:
        call    SetJmp_Push16Call_004a1ad0
        mov     eax, dword ptr [g_eventQueueCurrent]
        lea     eax, [eax + eax*2]
        mov     dl, byte ptr [eax*8 + g_byte_005435a0]
        inc     dl
        mov     cl, dl
        mov     byte ptr [eax*8 + g_byte_005435a0], dl
        cmp     cl, 0xf
        jne     short L_p3v_postUp
        mov     byte ptr [eax*8 + g_byte_005435a0], 0
    L_p3v_postUp:
        call    TripleCallByteCheck
        test    eax, eax
        mov     eax, dword ptr [g_eventQueueCurrent]
        je      short L_p3v_storeAndCall
        lea     eax, [eax + eax*2]
        movsx   ecx, byte ptr [eax*8 + g_byte_005435a0]
        push    ecx
        call    AudioMicroEntries
        add     esp, 4
        call    StackPopDispatchTagged
        pop     esi
        ret
    L_p3v_storeAndCall:
        mov     ecx, dword ptr [g_eventQueueEnd]
        lea     edx, [eax + eax*2]
        mov     dword ptr [g_currentNodeIdx], ecx
        movsx   eax, byte ptr [edx*8 + g_byte_005435a0]
        mov     dword ptr [g_walkCallback], eax
        call    ScaledChainStore24
        jmp     short L_p3v_installTail
    L_p3v_phase0:
        mov     dword ptr [g_tickFlagF], 2
        mov     dword ptr [g_phaseIdx], 0xe
    L_p3v_installTail:
        mov     eax, 1
        mov     dword ptr [esi + 8], offset Phase3InstallVolToggle
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}
