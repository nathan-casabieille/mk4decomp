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

extern unsigned int g_dispatchSave713_004ed0b8;
extern void ArgSarStoreJmp(void);
extern void CmpEqInitCallElseJmp_0048d4b0(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void InstallSelf3StateDualChain_0047a1c0(void);
extern void InstallSelf3StateFieldSet_0047a090(void);
extern void MStackPushSet0020_004901d0(void);
extern void Push8e_Push413690_00413560(void);
extern void ScaledArrStore_00429980(void);
extern void ScaledChainJmp_00429470(void);
extern void ScoreAiStatusFsmCluster_00479b50(void);

__declspec(naked) void ThrowTakedownStepCluster_00479e40(void)
{
    __asm {
        /* === Helper 1 (0x479e40): trigger dispatcher === */
    L_9e40:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       short L_9ece
        dec      eax
        je       short L_9e6d
        call     FiveCallGuardSetTail_0046f6b0
        pop      esi
        ret
    L_9e6d:
        mov      dword ptr [esi + 8], OFFSET L_9e40
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_9e40
        mov      dword ptr [ecx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        add      edx, 0x2000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     ScaledChainJmp_00429470
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret
    L_9ece:
        call     ScaledZeroFour
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9f15
        mov      dword ptr [g_eventQueueChild], 0x18
        call     ScaledArrStore_00429980
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9f15
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_9e40
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0xa
        mov      dword ptr [g_framePauseFlag], eax
    L_9f15:
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
        /* === Helper 2: 0x219 event === */
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0x219
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x74], eax
        call     ScoreAiStatusFsmCluster_00479b50
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_9f52
        push     OFFSET g_dispatchSave713_004ed0b8
        call     ArgSarStoreJmp
        add      esp, 4
    L_9f52:
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
        /* === Helper 3 (0x479f60): take-step / hold loop === */
    L_9f60:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_9fb1
        mov      eax, dword ptr [g_eventQueueChild]
        dec      eax
        mov      dword ptr [g_eventQueueChild], eax
        jne      L_a019
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0x28f
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x4c], eax
        call     InstallSelf3StateDualChain_0047a1c0
        pop      esi
        ret
    L_9fb1:
        call     Push8e_Push413690_00413560
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a08e
        call     MStackPushSet0020_004901d0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_a08e
        mov      edx, dword ptr [g_fightGroupHead]
        push     0xfffffd71
        push     0x1999
        mov      dword ptr [edx*4 + 0x70], 0xffffe148
        mov      dword ptr [g_walkCallback], 0xfffffd71
        call     Mul10Tail
        mov      ecx, dword ptr [g_fightGroupHead]
        add      esp, 8
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      dword ptr [g_eventQueueChild], 6
    L_a019:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueChild]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      dword ptr [g_walkCallback], 0x1a
        call     CmpEqInitCallElseJmp_0048d4b0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_a08e
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueChild], ecx
        mov      cl, byte ptr [g_xformDirtyFlags]
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, 1
        test     cl, al
        je       short L_a077
        call     InstallSelf3StateFieldSet_0047a090
        pop      esi
        ret
    L_a077:
        mov      dword ptr [esi + 8], OFFSET L_9f60
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_a08e:
        pop      esi
        ret
    }
}
