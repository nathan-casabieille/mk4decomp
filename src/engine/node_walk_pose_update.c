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

/* ------------------------------------------------------------------ */
/* Pre-fight install cluster (660b game, 2 packed helpers)             */
/* Helper 1: 0x96-fighter-id-vs-default branch + mat-copy.             */
/* Helper 2: simple dispatcher → func_004745e0 callback.               */
/* ------------------------------------------------------------------ */
extern void NodeWalkPoseUpdate_00474630(void);
extern void MStackPushVec3Mul10(void);
extern void TripleVecAccCallStore(void);
extern void DoublePushAddCallDoublePop_00476930(void);
extern unsigned int g_dispatchSave731_004eca50;
extern unsigned int g_dispatchSave136_0050b268;

extern void AudioMixerStep(void);
extern void MStackCall_00406340(void);
extern void PushSetXfmMaskCallPop(void);
extern void StoreDoubleNegPauseSubStore(void);
extern void func_004745e0(void);

__declspec(naked) void PreFightInstallCluster(void)
{
    __asm {
        /* === Helper 1 (0x474390): pre-fight slot install w/ char branch === */
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      eax
        push     esi
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_pendingNodeType]
        cmp      eax, 0x96
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_walkCallback], 0x7ae
        je       short L_441c
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_45d4
        mov      eax, dword ptr [g_walkCallback]
        add      eax, 0x23d7
        mov      dword ptr [g_eventQueueWorkType], eax
        call     MStackPushVec3Mul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_45d4
        mov      ecx, OFFSET g_dispatchSave136_0050b268
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        je       short L_4478
        pop      esi
        ret
    L_441c:
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_45d4
        mov      eax, dword ptr [g_walkCallback]
        add      eax, 0x23d7
        mov      dword ptr [g_eventQueueWorkType], eax
        call     MStackPushVec3Mul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_45d4
        mov      ecx, OFFSET g_dispatchSave731_004eca50
        shr      ecx, 2
        mov      dword ptr [g_walkCallback], ecx
        call     PushSetXfmMaskCallPop
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_45d4
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_449b
    L_4478:
        test     byte ptr [g_xformDirtyFlags], 4
        je       short L_44c9
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        pop      esi
        ret
    L_449b:
        mov      dword ptr [g_walkCallback], 0x6147
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_45d4
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x80], ecx
    L_44c9:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [edx*4 + 0x30], ecx
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      edx, dword ptr [g_pendingNodeType]
        mov      esi, dword ptr [eax*4]
        lea      ecx, [eax*4]
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], esi
        shl      eax, 2
        shl      edx, 2
        mov      dword ptr [eax + 0x54], esi
        mov      esi, dword ptr [ecx + 4]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [eax + 0x58], esi
        mov      ecx, dword ptr [ecx + 8]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x5c], ecx
        mov      ecx, dword ptr [edx]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x6c], ecx
        mov      ecx, dword ptr [edx + 4]
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [eax + 0x70], ecx
        mov      edx, dword ptr [edx + 8]
        mov      dword ptr [g_walkCallback], edx
        mov      dword ptr [eax + 0x74], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueWorkType], 0x7ae
        add      ecx, 0x1b
        mov      dword ptr [g_currentNodeIdx], ecx
        call     TripleVecAccCallStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_45d4
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_pendingNodeType]
        sub      eax, 0x1b
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_fightGroupHead], eax
        mov      eax, dword ptr [eax*4 + 0x30]
        cmp      eax, 0x96
        mov      dword ptr [g_walkCallback], eax
        je       short L_45bc
        call     DoublePushAddCallDoublePop_00476930
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_45d4
    L_45bc:
        call     MStackCall_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_45d4
        mov      dword ptr [g_walkCallback], 1
    L_45d4:
        pop      esi
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
        /* === Helper 2 (0x4745e0): post-install dispatcher === */
        mov      eax, dword ptr [g_baseSel]
        push     esi
        mov      dword ptr [eax*4 + 0x84], 0
        lea      esi, [eax*4]
        call     NodeWalkPoseUpdate_00474630
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_4622
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET func_004745e0
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_4622:
        pop      esi
        ret
    }
}
