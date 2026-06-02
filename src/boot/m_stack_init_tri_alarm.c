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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

extern void ScaledArrStore_004298c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

/* @addr 0x0040e190 (369b boot) - 3-entry packed mstack-scoped init + alarms.
 *   Entry 1 (offset 0, 180b): MStackPush8, then on no-error
 *     mstack-pushes g_eventQueueNotMask, caches g_fightGroupHead into 0x542054,
 *     sets g_walkCallback = &g_phaseChainArr2_004d62e8>>2 (stored also in 0x5381 3c),
 *     g_eventQueueIdx = &g_dispatchSave522_004d61d8>>2, g_eventQueueNotMask = 0xc1.
 *     Pushes 0x49db40, 0xc0 onto StoreTwoCall. If bit 0 of
 *     0x54208c clear, calls StackPushAdd15CallPop +
 *     ZeroThreeFields_0040a8b0. Pops the snapshot back and tail-jmps
 *     MStackPop8.
 *   12b NOP align pad.
 *   Entry 2 (offset 0xc0, 83b): sets 0x54207c=0x2666, 0x54206c=0x170a;
 *     calls StoreDoubleNegPauseSubStore; on no-error computes
 *     g_walkCallback += 0x10000, multiplies via Mul10Tail
 *     (push twice with the cur cj), negates, and tail-jmps PendingMatch_0040e310.
 *   13b NOP align pad.
 *   Entry 3 (offset 0x120, 81b): mirror of entry 2 with 0x3333 / 0x7ae
 *     constants; no negation before final store; tail-jmps PendingMatch_0040e310.
 */
extern unsigned int g_dispatchSave522_004d61d8;
extern unsigned int g_phaseChainArr2_004d62e8;
extern unsigned int g_alarmTriState;
extern unsigned int g_table_004d57b0;
extern void MStackPop8(void);
extern void MStackPush8(void);
extern void PendingMatch_0040e310(void);
extern void StackPushAdd15CallPop(void);
extern void StoreDoubleNegPauseSubStore(void);
extern void ZeroThreeFields_0040a8b0(void);

__declspec(naked) void MStackInitTriAlarm(void) {
    __asm {
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_msi_e1Ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        inc     eax
        push    0xc0
        mov     dword ptr [g_matrixStackTop], eax
        push    0x49db40
        mov     dword ptr [eax*4 + g_table_004d57b0], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, offset g_phaseChainArr2_004d62e8
        mov     dword ptr [g_eventQueueEnd], edx
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_alarmTriState], eax
        mov     eax, offset g_dispatchSave522_004d61d8
        mov     dword ptr [g_eventQueueNotMask], 0xc1
        shr     eax, 2
        mov     dword ptr [g_eventQueueIdx], eax
        call    StoreTwoCall
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 8
        test    al, 1
        jne     short L_msi_skipAlarm
        call    StackPushAdd15CallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e1Ret
        call    ZeroThreeFields_0040a8b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e1Ret
    L_msi_skipAlarm:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_matrixStackTop], eax
        jmp     MStackPop8
    L_msi_e1Ret:
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
        /* entry 2 (offset 0xc0) */
    L_msi_entry2:
        mov     dword ptr [g_eventQueueNotMask], 0x2666
        mov     dword ptr [g_walkCallback], 0x170a
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e2End
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueNotMask], eax
        neg     eax
        mov     dword ptr [g_walkCallback], eax
        jmp     PendingMatch_0040e310
    L_msi_e2End:
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
        /* entry 3 (offset 0x120) */
    L_msi_entry3:
        mov     dword ptr [g_eventQueueNotMask], 0x3333
        mov     dword ptr [g_walkCallback], 0x7ae
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_msi_e3End
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        add     eax, 0x10000
        push    ecx
        push    eax
        mov     dword ptr [g_walkCallback], eax
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     dword ptr [g_walkCallback], eax
        jmp     PendingMatch_0040e310
    L_msi_e3End:
        ret
    }
}
