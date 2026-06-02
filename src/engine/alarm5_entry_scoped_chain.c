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
extern void GuardedDispatch_InstallSelfDualEsi(void);
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

/* @addr 0x0049be10 (370b game) - 5-entry packed alarm + scoped chain.
 *   Entry 1 (offset 0, 20b): MStackCall_00406740; on no-error tail-jmps
 *     CallSetPause.
 *   12b NOP pad.
 *   Entry 2 (offset 0x20, 51b): writes 0x305 into [scaled+0x74], calls
 *     CondPickDualStore; on no-error pushes 0x4f25d8 and
 *     ArgSarStoreJmp.
 *   13b NOP pad.
 *   Entry 3 (offset 0x60, 190b): DualCmpSwapStore → push
 *     0x4f2640 → ScaledStackCallPause. If bit 2 of 0x54208c
 *     set, tail-call CallSetPause. Else does two Mul10Tail
 *     calls multiplying g_currentNodeFlags / 00542088 by 0x3333 (interp
 *     factor) then stores results back. Writes them into [esi+0x6c]
 *     and [esi+0x74], writes g_currentNodeIdx → g_fightGroupHead, sets
 *     [g_baseSel*4+0x5c]=0x30, pushes 0x4f2650 → ArgSar_Set0_Jmp.
 *   2b NOP pad.
 *   Entry 4 (offset 0xf0, 40b): Vec2SumMul10ChainCompute → on no-error compare
 *     g_eventQueueCurrent vs g_eventQueueWorkType: if le tail-jmp Phase1ChainSetupCallScale6,
 *     else tail-jmp ScaledIndirectJmp_0049c850.
 *   8b NOP pad.
 *   Entry 5 (offset 0x150, 34b): Phase1ContextSetupHelper + BootCallChainDoubleMul10;
 *     on no-error tail-jmps Triple3PathDispatch.
 */
extern unsigned int g_dispatchSave640;
extern unsigned int g_dispatchSave639;
extern unsigned int g_dispatchSave638;
extern void ArgSarStoreJmp(void);
extern void ArgSar_Set0_Jmp(void);
extern void BootCallChainDoubleMul10(void);
extern void CallSetPause(void);
extern void CondPickDualStore(void);
extern void DualCmpSwapStore(void);
extern void MStackCall_00406740(void);
extern void Phase1ChainSetupCallScale6(void);
extern void Phase1ContextSetupHelper(void);
extern void ScaledIndirectJmp_0049c850(void);
extern void ScaledStackCallPause(void);
extern void Triple3PathDispatch(void);
extern void Vec2SumMul10ChainCompute(void);

__declspec(naked) void Alarm5EntryScopedChain(void) {
    __asm {
        call    MStackCall_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a5e_e1End
        jmp     CallSetPause
    L_a5e_e1End:
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
        /* entry 2 (offset 0x20) */
    L_a5e_entry2:
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x305
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        call    CondPickDualStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a5e_e2End
        push    offset g_dispatchSave640
        call    ArgSarStoreJmp
        add     esp, 4
    L_a5e_e2End:
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
        /* entry 3 (offset 0x60) */
    L_a5e_entry3:
        push    esi
        call    DualCmpSwapStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_a5e_e3End
        push    offset g_dispatchSave639
        call    ScaledStackCallPause
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        jne     L_a5e_e3End
        test    byte ptr [g_xformDirtyFlags], 4
        je      short L_a5e_doInterp
        call    CallSetPause
        pop     esi
        ret
    L_a5e_doInterp:
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     eax, dword ptr [g_currentNodeIdx]
        push    ecx
        push    0x3333
        lea     esi, [eax*4]
        call    Mul10Tail
        mov     edx, dword ptr [g_xformScratch2088]
        add     esp, 8
        mov     dword ptr [g_currentNodeFlags], eax
        push    edx
        push    0x3333
        call    Mul10Tail
        mov     dword ptr [g_xformScratch2088], eax
        mov     eax, dword ptr [g_currentNodeFlags]
        mov     dword ptr [esi + 0x6c], eax
        mov     ecx, dword ptr [g_xformScratch2088]
        add     esp, 8
        mov     dword ptr [esi + 0x74], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x30
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_walkCallback], eax
        push    offset g_dispatchSave638
        mov     dword ptr [ecx*4 + 0x5c], eax
        call    ArgSar_Set0_Jmp
        add     esp, 4
    L_a5e_e3End:
        pop     esi
        ret
        nop
        nop
        /* entry 4 (offset 0xf0) */
    L_a5e_entry4:
        call    Vec2SumMul10ChainCompute
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a5e_e4End
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_eventQueueWorkType]
        cmp     eax, ecx
        jle     short L_a5e_e4tail2
        jmp     ScaledIndirectJmp_0049c850
    L_a5e_e4tail2:
        jmp     Phase1ChainSetupCallScale6
    L_a5e_e4End:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* entry 5 (offset 0x150) */
    L_a5e_entry5:
        call    Phase1ContextSetupHelper
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a5e_e5End
        call    BootCallChainDoubleMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_a5e_e5End
        jmp     Triple3PathDispatch
    L_a5e_e5End:
        ret
    }
}
