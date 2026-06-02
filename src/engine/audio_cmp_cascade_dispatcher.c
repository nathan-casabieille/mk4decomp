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

extern unsigned int g_poseGridGenVar_004e2864;
extern unsigned int g_audioInitPeriodic_00537e90;
extern unsigned int g_state2_00537ea8;
extern unsigned int g_audioInstall2State_00537f88;
extern void AudioMStackPushHandlerPair_0049ff30(void);
extern void BitSetByIndex_004a07a0(void);
extern void Cmp3DirtyToggle_0049fa20(void);
extern void DualPushSetCallDualPop(void);
extern void MStackDualPushSaveRestore_004a09c0(void);
extern void RoundWinTransition(void);
extern void SetWalkCurCallPauseDirty(void);
extern void TripleStageRollback(void);

__declspec(naked) void AudioCmpCascadeDispatcher_0049fd50(void)
{
    __asm
    {
        push    ebx
        call    Cmp3DirtyToggle_0049fa20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_acsd_ret
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 1
        test    al, bl
        je      L_acsd_ret
        mov     eax, dword ptr [g_active_00537e88]
        cmp     eax, 2
        mov     dword ptr [g_walkCallback], eax
        jne     L_acsd_ret
        mov     eax, dword ptr [g_state2_00537ea8]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     L_acsd_ret
        mov     eax, dword ptr [g_audioInitPeriodic_00537e90]
        mov     dword ptr [g_eventQueueNotMask], ebx
        cmp     eax, 0xf
        mov     dword ptr [g_acc_00542078], eax
        ja      L_acsd_cmp10
        push    0x253
        call    DualPushSetCallDualPop
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        test    al, bl
        jne     short L_acsd_skipPush
        call    MStackPush2TableNot
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_acsd_ret
        mov     eax, dword ptr [g_eventQueueWorkType]
        and     eax, 0x20
        mov     dword ptr [g_xformScratch94], eax
        jne     short L_acsd_callsub
    L_acsd_skipPush:
        push    0x16
        push    0x4a0370
        mov     dword ptr [g_walkCallback], ebx
        mov     dword ptr [g_state2_00537ea8], ebx
        call    SetWalkCurCallPauseDirty
        add     esp, 8
        call    RoundWinTransition
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_acsd_ret
        push    0x230
        call    TripleStageRollback
        mov     cx, word ptr [g_poseGridGenVar_004e2864]
        add     esp, 4
        push    ecx
        call    TaggedSceneDispatch
        add     esp, 4
        pop     ebx
        ret
    L_acsd_callsub:
        call    MStackDualPushSaveRestore_004a09c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_acsd_ret
        test    byte ptr [g_xformDirtyFlags], bl
        je      L_acsd_ret
        push    0x238
        call    DualPushSetCallDualPop
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 4
        test    al, bl
        je      short L_acsd_skipCmp
        mov     edx, dword ptr [g_acc_00542078]
        mov     eax, dword ptr [g_audioInstall2State_00537f88]
        cmp     edx, eax
        je      L_acsd_ret
    L_acsd_skipCmp:
        mov     dword ptr [g_walkCallback], ebx
        call    BitSetByIndex_004a07a0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_acsd_ret
        mov     eax, dword ptr [g_acc_00542078]
        push    0x239
        push    0x4a0b00
        mov     dword ptr [g_eventQueueChild], eax
        call    SetWalkCurCallPauseDirty
        add     esp, 8
        pop     ebx
        ret
    L_acsd_cmp10:
        cmp     eax, 0x10
        jne     short L_acsd_cmp11
        push    0x23e
        push    0x4a0dc0
        mov     dword ptr [g_eventQueueEnd], ebx
        call    SetWalkCurCallPauseDirty
        add     esp, 8
        mov     dword ptr [g_walkCallback], ebx
        mov     dword ptr [g_state2_00537ea8], ebx
        pop     ebx
        ret
    L_acsd_cmp11:
        cmp     eax, 0x11
        jne     short L_acsd_cmp12
        mov     cx, word ptr [g_poseGridGenVar_004e2864]
        mov     dword ptr [g_eventQueueEnd], ebx
        push    ecx
        call    TaggedSceneDispatch
        add     esp, 4
        push    0x243
        push    0x4a10d0
        call    SetWalkCurCallPauseDirty
        add     esp, 8
        mov     dword ptr [g_walkCallback], ebx
        mov     dword ptr [g_state2_00537ea8], ebx
        pop     ebx
        ret
    L_acsd_cmp12:
        cmp     eax, 0x12
        jne     short L_acsd_ret
        call    AudioMStackPushHandlerPair_0049ff30
    L_acsd_ret:
        pop     ebx
        ret
    }
}
