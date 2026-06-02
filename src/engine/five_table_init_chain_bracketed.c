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

extern unsigned int g_dispatchSave87_0053a52c;
extern unsigned int g_dispatchSave86_0053a530;
extern unsigned int g_dispatchSave85_0053a654;
extern unsigned int g_dispatchSave66_00542ab8;
extern unsigned int g_dispatchSave67_00542b00;
extern void ScaledDerefStore_004774b0(void);

void FiveTableInitChainBracketed_004774f0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueWorkType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_pendingNodeType]
        inc     eax
        mov     edx, offset g_dispatchSave87_0053a52c
        mov     dword ptr [g_matrixStackTop], eax
        sar     edx, 2
        mov     dword ptr [eax*4], ecx
        mov     dword ptr [g_eventQueueWorkType], 0x64
        mov     dword ptr [g_pendingNodeType], edx
        call    ScaledDerefStore_004774b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ftic_abort
        mov     eax, offset g_dispatchSave86_0053a530
        mov     dword ptr [g_eventQueueWorkType], 0x23
        sar     eax, 2
        mov     dword ptr [g_pendingNodeType], eax
        call    ScaledDerefStore_004774b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ftic_abort
        mov     eax, offset g_dispatchSave66_00542ab8
        mov     dword ptr [g_eventQueueWorkType], 0
        sar     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4]
        inc     eax
        test    ecx, ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        je      short L_ftic_block3
    L_ftic_loop2:
        call    ScaledDerefStore_004774b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ftic_abort
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [eax*4]
        inc     eax
        test    ecx, ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        jne     short L_ftic_loop2
    L_ftic_block3:
        mov     eax, offset g_dispatchSave67_00542b00
        mov     dword ptr [g_eventQueueWorkType], 1
        sar     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4]
        inc     eax
        test    ecx, ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        je      short L_ftic_block4
    L_ftic_loop3:
        call    ScaledDerefStore_004774b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_ftic_abort
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [eax*4]
        inc     eax
        test    ecx, ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        jne     short L_ftic_loop3
    L_ftic_block4:
        mov     ecx, offset g_dispatchSave85_0053a654
        mov     dword ptr [g_eventQueueWorkType], 4
        sar     ecx, 2
        mov     dword ptr [g_pendingNodeType], ecx
        call    ScaledDerefStore_004774b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_ftic_abort
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueWorkType], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_ftic_abort:
        }
}

