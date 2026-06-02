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
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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

extern unsigned int g_dispatchSave600_004ed1b0;
extern unsigned int g_dispatchSave599_004ed1b8;
extern unsigned int g_audioBank2State_00537f98;
extern void ArgSarStoreJmp(void);
extern void CmpEqInitCallElseJmp_0048d4b0(void);
extern void EsiInstallDecCallChain_004294a0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void RoundStartCluster_0047b900(void);
extern void ScaledIndexConditionalAdd_0048e400(void);
extern void ScaledLoadIncJmp_00428d00(void);
extern void ScaledLoadIncJmp_00429840(void);

__declspec(naked) void RoundEndCelebrationCluster_0047b6e0(void)
{
    __asm {
        /* H1 */
        push     OFFSET g_dispatchSave600_004ed1b0
        call     ArgSarStoreJmp
        add      esp, 4
        ret
        nop
        nop
        /* H2 */
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x213
        mov      dword ptr [g_walkCallback], eax
        push     OFFSET g_dispatchSave599_004ed1b8
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ArgSarStoreJmp
        add      esp, 4
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
        /* H3 (L_b720): 2-state FSM */
    L_b720:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_b836
        dec      eax
        je       short L_b753
        call     FiveCallGuardSetTail_0046f6b0
        pop      edi
        pop      esi
        ret
    L_b753:
        call     ScaledLoadIncJmp_00429840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b8f3
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_audioBank2State_00537f98]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      dword ptr [g_walkCallback], 0x12
        call     CmpEqInitCallElseJmp_0048d4b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_b8f3
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edi, 1
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, dword ptr [g_xformScratch2088]
        cmp      eax, edi
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_audioBank2State_00537f98], ecx
        jne      short L_b7cd
        call     RoundStartCluster_0047b900
        pop      edi
        pop      esi
        ret
    L_b7cd:
        mov      dword ptr [g_walkCallback], 0x12
        mov      dword ptr [esi + 8], OFFSET L_b720
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_b720
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 0
        call     ScaledLoadIncJmp_00428d00
        mov      dword ptr [g_framePauseFlag], edi
        pop      edi
        pop      esi
        ret
    L_b836:
        mov      dword ptr [g_walkCallback], 9
        call     ScaledIndexConditionalAdd_0048e400
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b8f3
        call     ScaledLoadIncJmp_00429840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b8f3
        mov      dword ptr [g_walkCallback], 0x12
        call     CmpEqInitCallElseJmp_0048d4b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_b8f3
        mov      eax, dword ptr [g_xformScratch2088]
        mov      edi, 1
        cmp      eax, edi
        jne      short L_b892
        call     RoundStartCluster_0047b900
        pop      edi
        pop      esi
        ret
    L_b892:
        mov      dword ptr [g_eventQueueChild], 6
        mov      dword ptr [esi + 8], OFFSET L_b720
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_b720
        add      ecx, 0x1000000
        mov      dword ptr [eax*4 + 0x84], edi
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 0
        call     EsiInstallDecCallChain_004294a0
        mov      dword ptr [g_framePauseFlag], edi
    L_b8f3:
        pop      edi
        pop      esi
        ret
    }
}
