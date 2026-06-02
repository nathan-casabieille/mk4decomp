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

/* @addr 0x0049cc30 (267b game) - mstack-push + bit-gated loop with 3 helper calls. */
extern void AndStoreJmp(void);
extern void Thunk_0049cb80(void);

__declspec(naked) void MStackBitLoopTripleCall(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        push    ebx
        mov     dword ptr [g_matrixStackTop], eax
        push    esi
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [g_eventQueueWorkType], edx
        call    SetJmp_0049cb90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d0h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ebx, 4
        or      esi, 0xffffffff
        test    byte ptr [g_xformDirtyFlags], bl
        _emit   0fh
        _emit   85h
        _emit   0a4h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_cj_0054205c]
        cmp     ecx, dword ptr [eax*4 + 0x2c]
        _emit   74h
        _emit   5ch
        mov     edx, dword ptr [g_xformDirtyFlags]
        or      edx, ebx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   7eh
        mov     ecx, edx
        xor     ecx, ebx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        _emit   74h
        _emit   70h
        mov     edx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [g_eventQueueCurrent], esi
        mov     dword ptr [g_walkCallback], edx
        call    AndStoreJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   68h
        test    byte ptr [g_xformDirtyFlags], bl
        _emit   75h
        _emit   48h
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_cj_0054205c]
        cmp     ecx, dword ptr [eax*4 + 0x2c]
        _emit   75h
        _emit   0a4h
        mov     dword ptr [g_pendingNodeType], eax
        call    Thunk_0049cb80
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   39h
        mov     edx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [g_walkCallback], edx
        call    SetJmp_0049cb90
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   84h
        _emit   53h
        _emit   0ffh
        _emit   0ffh
        _emit   0ffh
        pop     esi
        pop     ebx
        ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_matrixStackTop], eax
        pop     esi
        pop     ebx
        ret
    }
}
