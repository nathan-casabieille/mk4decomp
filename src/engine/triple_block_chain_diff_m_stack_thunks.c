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

/* @addr 0x0049ca10 (302b game) - 3-block: chain-diff mstack-push + push-call thunks.
 *   Block A (0..0x6c): mstack-push g_eventQueueChild. Compute diffs between [baseSel*4+0x38] and g_cj fields.
 *     g_eventQueueWorkType = [scaledInit*4+0x54] - [cj*4+0x54]; g_acc = [scaledInit*4+0x5c] - [cj*4+0x5c].
 *     Call Atan2QuadrantLookup; if pause skip. Call BootMod6487eClampAndChainMul10; if pause skip.
 *     chain[baseSel*4+0x70] = g_walkCallback. Mstack-pop into g_eventQueueChild. Pop esi; ret.
 *   Block B (+0xc0): call CondPickDualStore; if pause ret. Push 0x004f2778; call ArgSarStoreJmp; pop; ret.
 *   Block C (+0xe0): call DualCmpSwapStore; if pause ret. Push 0x004f27b8; call ScaledStackCallPause; pop; if pause ret.
 *     If bit2(0054208c): jmp CallSetPause. Else call DualMul10AndDispatchChain; if pause ret.
 *     Push 0x004f27c8; call ArgSar_Set1_Jmp; pop; ret.
 */
extern void ArgSarStoreJmp(void);
extern void ArgSar_Set1_Jmp(void);
extern void Atan2QuadrantLookup(void);
extern void CallSetPause(void);
extern void CondPickDualStore(void);
extern void DualCmpSwapStore(void);
extern void DualMul10AndDispatchChain(void);
extern void ScaledStackCallPause(void);

extern unsigned int g_matrixStack_arr;

__declspec(naked) void TripleBlockChainDiffMStackThunks(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueChild]
        inc     eax
        push    esi
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], ecx
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [edx*4 + 0x38]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [ecx*4 + 0x54]
        mov     dword ptr [g_walkCallback], edx
        mov     ecx, dword ptr [ecx*4 + 0x5c]
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     esi, dword ptr [eax*4 + 0x54]
        mov     dword ptr [g_eventQueueWorkType], esi
        mov     eax, dword ptr [eax*4 + 0x5c]
        sub     esi, edx
        sub     eax, ecx
        mov     dword ptr [g_eventQueueWorkType], esi
        mov     dword ptr [g_acc_00542078], eax
        call    Atan2QuadrantLookup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   38h
        call    BootMod6487eClampAndChainMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2ah
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x70], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_eventQueueChild], edx
        mov     dword ptr [g_matrixStackTop], eax
        pop     esi
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    CondPickDualStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004f2778
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        call    DualCmpSwapStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3fh
        push    0x004f27b8
        call    ScaledStackCallPause
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   05h
        jmp     CallSetPause
        call    DualMul10AndDispatchChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004f27c8
        call    ArgSar_Set1_Jmp
        add     esp, 4
        ret
    }
}
