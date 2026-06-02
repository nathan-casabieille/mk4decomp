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

extern unsigned int g_dispatchSave650_004a0370;
extern unsigned int g_poseGridGenVar;
extern void Ten404c40_404bd0(void);
extern void PushCallPauseStorePushDispatch(void);
extern void TripleStageRollback(void);
extern void RoundWinTransition(void);
extern void StoreTwoCall(void);
extern void TaggedSceneDispatch(void);
extern void InstallSelf3WaySubDec(void);
extern void LinkedListIndirectDirtyToggle(void);
extern void IncWrap0fJmp(void);
extern void Eleven404b90_404c00(void);
extern void PoseGridGenerator(void);

__declspec(naked) void AudioPhaseDispatch(void)
{
    __asm
    {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        je      L_apd_phase0
        call    Ten404c40_404bd0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_apd_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0x1c]
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_eventQueueIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_eventQueueEnd]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jne     short L_apd_subPath
        call    PushCallPauseStorePushDispatch
        pop     esi
        pop     ebx
        ret
    L_apd_subPath:
        push    0x230
        call    TripleStageRollback
        add     esp, 4
        call    RoundWinTransition
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_apd_ret
        push    0x16
        push    offset g_dispatchSave650_004a0370
        call    StoreTwoCall
        mov     cx, word ptr [g_poseGridGenVar]
        add     esp, 8
        push    ecx
        call    TaggedSceneDispatch
        add     esp, 4
        call    InstallSelf3WaySubDec
        pop     esi
        pop     ebx
        ret
    L_apd_phase0:
        call    LinkedListIndirectDirtyToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_apd_ret
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 1
        test    al, bl
        je      short L_apd_continue
        call    IncWrap0fJmp
        pop     esi
        pop     ebx
        ret
    L_apd_continue:
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4], edx
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], ebx
        mov     eax, dword ptr [ecx*4 + 0x14]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ebx
        call    Eleven404b90_404c00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_apd_ret
        mov     dword ptr [esi + 8], offset AudioPhaseDispatch
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, offset AudioPhaseDispatch
        mov     dword ptr [edx*4 + 0x84], ebx
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x1000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    PoseGridGenerator
        mov     dword ptr [g_framePauseFlag], ebx
    L_apd_ret:
        pop     esi
        pop     ebx
        ret
    }
}
