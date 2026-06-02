/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
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
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
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
extern void DispatcherComplex260_00407030(void);
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
extern void PendingMatch_0042b930(void);
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
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
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

/* @addr 0x0046a230 (367b game) - 3-entry packed install chain w/ countdown.
 *   Entry 1 (offset 0, 15b): sets g_eventQueueNotMask = 0x20012 and tail-jmps
 *     HitReactionDispatcher.
 *   1b NOP align pad.
 *   Entry 2 / body1 (offset 0x10, 159b): phase-state install. Phase 0:
 *     calls State6Latch, then reads g_or → 0x54206c,
 *     AND with 0x10 → g_xformScratch94; if bit-4 set goes to phase-1 body.
 *     Otherwise chain ClearBit2x34 → ScaledZeroFour →
 *     sets byte 0x54380c = 1 → tail-call Wrapper_ArgSarStoreJmp_004eba28.
 *   Phase non-0: chain CallPauseScaledStoreCopyJmp, install Self
 *     at body1 with slot[+0x84] = 1 and g_pendingNodeType = 0x78, arm
 *     g_framePauseFlag = 1.
 *   1b NOP align pad.
 *   Entry 3 / body2 (offset 0xb0, 191b): phase-state install with
 *     countdown via g_eventQueueChild. Phase 0: sets g_fightGroupHead*4+0x4c
 *     = 0xfffffd71, install Self at body2 with slot[+0x84] = 1, arm
 *     g_framePauseFlag = 1. Phase 1: counts down g_eventQueueChild from 0xa;
 *     when reaches 0, tail-jmps state-tail at +0x100 (≈0x46a3a0). Else
 *     installs Self with slot[+0x84] = 2 and re-arms 0x541e6c.
 *     Phase 2: increments [g_fightGroupHead*4 + 0x4c] by 0x41, sets
 *     g_eventQueueCurrent = 0x41, then continues into the phase-1 countdown.
 */
extern unsigned int g_or;
extern unsigned int g_tripleEntryFlag;
extern void CallPauseScaledStoreCopyJmp(void);
extern void ClearBit2x34(void);
extern void HitReactionDispatcher(void);
extern void MStackInstallBodyChain(void);
extern void State6Latch(void);
extern void Wrapper_ArgSarStoreJmp_004eba28(void);

__declspec(naked) void TripleEntryCountdownInstall(void) {
    __asm {
        mov     dword ptr [g_eventQueueNotMask], 0x20012
        jmp     HitReactionDispatcher
        nop
    L_tec_body1:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        jne     short L_tec_b1install
        call    State6Latch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tec_b1done
        mov     eax, dword ptr [g_or]
        mov     dword ptr [g_walkCallback], eax
        and     eax, 0x10
        mov     dword ptr [g_xformScratch94], eax
        jne     short L_tec_b1nonzero
    L_tec_b1install:
        call    ClearBit2x34
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tec_b1done
        call    ScaledZeroFour
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tec_b1done
        mov     byte ptr [g_tripleEntryFlag], 1
        call    Wrapper_ArgSarStoreJmp_004eba28
        pop     esi
        ret
    L_tec_b1nonzero:
        call    CallPauseScaledStoreCopyJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_tec_b1done
        mov     eax, 1
        mov     dword ptr [esi + 8], offset L_tec_body1
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 0x78
        mov     dword ptr [g_framePauseFlag], eax
    L_tec_b1done:
        pop     esi
        ret
        nop
    L_tec_body2:
        mov     eax, dword ptr [g_baseSel]
        shl     eax, 2
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], 0
        sub     ecx, 0
        je      short L_tec_b2phase0
        dec     ecx
        je      short L_tec_b2phase1
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [edx*4 + 0x4c]
        mov     dword ptr [g_eventQueueCurrent], 0x41
        add     ecx, 0x41
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [edx*4 + 0x4c], ecx
        mov     ecx, dword ptr [g_eventQueueChild]
        dec     ecx
        mov     dword ptr [g_eventQueueChild], ecx
        jne     short L_tec_b2install2
        jmp     MStackInstallBodyChain
    L_tec_b2phase1:
        mov     dword ptr [g_eventQueueChild], 0xa
    L_tec_b2install2:
        mov     ecx, 1
        mov     dword ptr [eax + 8], offset L_tec_body2
        mov     dword ptr [eax + 0x84], 2
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    L_tec_b2phase0:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     ecx, 0xfffffd71
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [edx*4 + 0x4c], ecx
        mov     ecx, 1
        mov     dword ptr [eax + 8], offset L_tec_body2
        mov     dword ptr [eax + 0x84], ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_framePauseFlag], ecx
        ret
    }
}
