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

/* @addr 0x0046b360 (374b game) - 3-entry packed: state-remap + install +
 *   state-remap-call.
 *   Entry 1 (offset 0, 80b): sets g_xformEntityIdx = &g_dispatchTableArr7>>2,
 *     reads [g_baseSel*4 + 0x34] as state code; if 0x10 → 2, if
 *     0x11 → 7. If != 0xf, pushes 0x542a70 → ArgScaledTestStore.
 *   Entry 2 (offset 0x50, 219b): phase-state install. Phase != 0 tail-jmps
 *     StackPopDispatchTagged. Phase 0: writes [scaled+0x74]=0x2002,
 *     ScaledAndAlfe → push 0x542a78 → ArgScaledTestStore. On
 *     no-error writes g_xformEntityIdx → [0x54205c*4 + 0x24], installs Self
 *     entry 1 (0x46b3b0) with packed_ptr (Self + 0x01000000), calls
 *     ScaledClearJmp_EsiInstallBitCallChain.
 *   5b NOP align pad.
 *   Entry 3 (offset 0x130, 70b): FiveCallScaledChainTailJmp;
 *     on no-error reads [scaled+0x34] as state code; if 0x11 → 7. If
 *     != 0xf, tail-call Install3StateRouterTail; else pushes
 *     0x4eaee0 → ArgSarStoreJmp.
 */
extern unsigned int g_dispatchSave967;
extern unsigned int g_dispatchTableArr7;
extern unsigned int g_dispatchSave64;
extern unsigned int g_dispatchSave65;
extern void ArgSarStoreJmp(void);
extern void ArgScaledTestStore(void);
extern void Install3StateRouterTail(void);
extern void ScaledAndAlfe(void);
extern void ScaledClearJmp_EsiInstallBitCallChain(void);

__declspec(naked) void StateRemapPackedInstall(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, offset g_dispatchTableArr7
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        mov     eax, dword ptr [ecx*4 + 0x34]
        cmp     eax, 0x10
        mov     dword ptr [g_walkCallback], eax
        jne     short L_srp_check11
        mov     eax, 2
        mov     dword ptr [g_walkCallback], eax
    L_srp_check11:
        cmp     eax, 0x11
        jne     short L_srp_check15
        mov     eax, 7
        mov     dword ptr [g_walkCallback], eax
    L_srp_check15:
        cmp     eax, 0xf
        je      short L_srp_e1End
        push    offset g_dispatchSave64
        call    ArgScaledTestStore
        add     esp, 4
    L_srp_e1End:
        ret
    L_srp_entry2:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      short L_srp_e2phase0
        call    StackPopDispatchTagged
        pop     esi
        ret
    L_srp_e2phase0:
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x2002
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    ScaledAndAlfe
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_srp_e2End
        push    offset g_dispatchSave65
        call    ArgScaledTestStore
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     short L_srp_e2End
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [edx*4 + 0x24], eax
        mov     dword ptr [esi + 8], offset L_srp_entry2
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, offset L_srp_entry2
        add     edx, 0x01000000
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], 0
        call    ScaledClearJmp_EsiInstallBitCallChain
        mov     dword ptr [g_framePauseFlag], 1
    L_srp_e2End:
        pop     esi
        ret
        nop
        nop
        nop
        nop
        nop
        /* entry 3 (offset 0x130) */
    L_srp_entry3:
        call    FiveCallScaledChainTailJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_srp_e3End
        mov     eax, dword ptr [g_baseSel]
        mov     eax, dword ptr [eax*4 + 0x34]
        cmp     eax, 0x11
        mov     dword ptr [g_walkCallback], eax
        jne     short L_srp_e3check15
        mov     eax, 7
        mov     dword ptr [g_walkCallback], eax
    L_srp_e3check15:
        cmp     eax, 0xf
        jne     short L_srp_e3pushAlarm
        jmp     Install3StateRouterTail
    L_srp_e3pushAlarm:
        push    offset g_dispatchSave967
        call    ArgSarStoreJmp
        add     esp, 4
    L_srp_e3End:
        ret
    }
}
