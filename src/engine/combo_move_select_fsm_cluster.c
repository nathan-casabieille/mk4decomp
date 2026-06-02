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

extern void ComboMoveSelectFsmCluster(void);
extern void ScaledStoreOrFlagXor(void);
extern void PendingMatch_00459510(void);
extern void MStackPushZeroCallPop_00407d00(void);

/* @addr 0x0045a180 (313b game) - dual-entry: mstack-push prefix + state-machine body.
 *   Prefix (0..0x1f): mstack-push body addr (0x0045a1a0); tail-jmp ComboMoveSelectFsmCluster.
 *   Body (+0x20): load state. state==0: tail block; state!=0: dual-call sequence:
 *     Call ScaledStoreOrFlagXor; if pause ret. If bit2(0054208c): tail-call PendingMatch_00459510, ret.
 *     Dec g_eventQueueChild; if 0: tail-call PendingMatch_00459510, ret.
 *     Call ScaledStoreOrFlagXor again; if pause ret. Same bit2 + counter sequence.
 *     Then recursive tail-call self (prefix entry); ret.
 *   Tail block (state==0): g_eventQueueCurrent=g_walkCallback+1; cmp with chain[scaledInit*4+4].
 *     If equal: mstack-push PendingMatch_00459510 addr; tail-call ComboMoveSelectFsmCluster; ret.
 *     Else: g_eventQueueEnd=[g_cj*4+0x24]; g_walkCallback=0x8000; call MStackPushZeroCallPop;
 *       if pause ret. Install-self at body; state=1; g_pendingNodeType=1; pause=1; ret.
 */

extern unsigned int g_matrixStack_arr;

__declspec(naked) void DualEntryStateMachine(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], offset body_1a0
        jmp     ComboMoveSelectFsmCluster
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
    body_1a0:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   73h
        call    ScaledStoreOrFlagXor
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0e3h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   07h
        call    PendingMatch_00459510
        pop     esi
        ret
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        _emit   75h
        _emit   07h
        call    PendingMatch_00459510
        pop     esi
        ret
        call    ScaledStoreOrFlagXor
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0adh
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   07h
        call    PendingMatch_00459510
        pop     esi
        ret
        mov     eax, dword ptr [g_eventQueueChild]
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        _emit   75h
        _emit   07h
        call    PendingMatch_00459510
        pop     esi
        ret
        call    DualEntryStateMachine
        pop     esi
        ret
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_scaledInit_00542044]
        lea     eax, [ecx + 1]
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     ecx, dword ptr [edx*4 + 4]
        cmp     eax, ecx
        _emit   75h
        _emit   1dh
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], offset PendingMatch_00459510
        call    ComboMoveSelectFsmCluster
        pop     esi
        ret
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_walkCallback], 0x8000
        mov     dword ptr [g_eventQueueEnd], ecx
        call    MStackPushZeroCallPop_00407d00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1ch
        mov     eax, 1
        mov     dword ptr [esi + 8], offset body_1a0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
    }
}
