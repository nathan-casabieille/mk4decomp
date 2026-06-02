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

extern unsigned int g_bootChainPair0_00541e80;
extern void GuardedChainPushSetCallPop(void);
extern void ScaledLoadGuardedJmp_004066d0(void);
extern void PvsMergeDriver_00425db0(void);
extern void MStackBracket2_TreeWalkRecursive(void);
extern void LinkedListInsert_004ab440(void);

/* @addr 0x00406790 (377b boot) - mstack-push-2 scope + 2-call chain + LL insert.
 *   Sets bit 2 of g_xformDirtyFlags. If g_currentNodeIdx is zero, takes the
 *   short path: clears bit 2 again and returns. Otherwise pushes
 *   g_xformEntityIdx / g_fightGroupHead onto mstack, calls
 *   GuardedChainPushSetCallPop + ScaledLoadGuardedJmp_004066d0.
 *   Sets g_fightGroupHead = old g_currentNodeIdx, reads [scaled+0x1c]; if
 *   non-zero, toggles bit 2 off and calls PvsMergeDriver_00425db0. Zeroes
 *   g_walkCallback and [scaled+0x1c]. Reads [scaled+0x18]; if non-zero,
 *   toggles bit 2 off and calls MStackBracket2_TreeWalkRecursive. Then writes g_bootChainPair0_00541e80
 *   into g_xformEntityIdx and calls LinkedListInsert_004ab440. Pops the 2
 *   mstack entries back and clears bit 0 of g_xformDirtyFlags via and 0xfe.
 */
extern unsigned int g_table_004d57b0;

__declspec(naked) void MStackPush2ChainLLInsert(void) {
    __asm {
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [g_currentNodeIdx]
        push    edi
        mov     edi, 4
        or      edx, edi
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        je      L_mpl_finalAndFE
        mov     ecx, edx
        xor     ecx, edi
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      L_mpl_finalAndFE
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], edx
        call    GuardedChainPushSetCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mpl_doneNoFE
        call    ScaledLoadGuardedJmp_004066d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mpl_doneNoFE
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_fightGroupHead], eax
        or      edx, edi
        mov     eax, dword ptr [eax*4 + 0x1c]
        mov     dword ptr [g_xformDirtyFlags], edx
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        je      short L_mpl_skipCall1
        mov     ecx, edx
        xor     ecx, edi
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      short L_mpl_skipCall1
        call    PvsMergeDriver_00425db0
    L_mpl_skipCall1:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax*4 + 0x1c], 0
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [ecx*4 + 0x18]
        or      edx, edi
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformDirtyFlags], edx
        je      short L_mpl_skipCall2
        mov     ecx, edx
        xor     ecx, edi
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      short L_mpl_skipCall2
        call    MStackBracket2_TreeWalkRecursive
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mpl_doneNoFE
    L_mpl_skipCall2:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_bootChainPair0_00541e80]
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_xformEntityIdx], eax
        call    LinkedListInsert_004ab440
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mpl_doneNoFE
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_fightGroupHead], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_mpl_finalAndFE:
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
    L_mpl_doneNoFE:
        pop     edi
        ret
    }
}
