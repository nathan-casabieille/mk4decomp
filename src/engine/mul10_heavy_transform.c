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

/* ------------------------------------------------------------------ */
/* Pose-tree blend walker (596b game): traverse skeleton list,         */
/* per-node compute pos = parent_pos + bone_offset * scale.            */
/* ------------------------------------------------------------------ */
extern void BootMod6487eClampAndChainMul10(void);
extern void Mul10HeavyTransform_00424bf0(void);
extern void MStackPush8_004ab790(void);
extern void MStackPop8_004ab860(void);
extern unsigned int g_dispatchSave6_00541f94;
extern unsigned int g_savedNode;
extern unsigned int g_mul10TransformVar_00541f9c;

extern void QuadInterpolator_00425380(void);
extern void StoreDoubleNegPauseSubStore_004ab750(void);

__declspec(naked) void PoseTreeBlendWalker_0049d680(void)
{
    __asm {
        push     ebx
        push     esi
        push     edi
        call     MStackPush8_004ab790
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_savedNode]
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      ecx, dword ptr [g_mul10TransformVar_00541f9c]
        mov      dword ptr [g_eventQueueEnd], eax
        test     eax, eax
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [g_eventQueueTotal], ecx
        mov      dword ptr [g_walkCallback], eax
        je       L_d8ba
    L_d6d0:
        mov      edx, dword ptr [g_eventQueueIdx]
        mov      eax, dword ptr [g_pendingNodeType]
        mov      ecx, dword ptr [g_eventQueueTotal]
        lea      esi, [edx*4]
        lea      edi, [eax*4]
        lea      ebx, [ecx*4]
        mov      eax, dword ptr [esi + 0x3c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d719
        call     StoreDoubleNegPauseSubStore_004ab750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d719:
        add      eax, dword ptr [esi + 0x30]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edi], eax
        mov      eax, dword ptr [esi + 0x40]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d746
        call     StoreDoubleNegPauseSubStore_004ab750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d746:
        add      eax, dword ptr [esi + 0x34]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edi + 4], eax
        mov      eax, dword ptr [esi + 0x44]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d774
        call     StoreDoubleNegPauseSubStore_004ab750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d774:
        add      eax, dword ptr [esi + 0x38]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edi + 8], eax
        mov      eax, dword ptr [esi + 0x24]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d7a2
        call     StoreDoubleNegPauseSubStore_004ab750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d7a2:
        add      eax, dword ptr [esi + 0x18]
        mov      dword ptr [g_walkCallback], eax
        call     BootMod6487eClampAndChainMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ebx], edx
        mov      eax, dword ptr [esi + 0x28]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d7e7
        call     StoreDoubleNegPauseSubStore_004ab750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d7e7:
        add      eax, dword ptr [esi + 0x1c]
        mov      dword ptr [g_walkCallback], eax
        call     BootMod6487eClampAndChainMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d0
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [ebx + 4], eax
        mov      eax, dword ptr [esi + 0x2c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       short L_d82c
        call     StoreDoubleNegPauseSubStore_004ab750
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d0
        mov      eax, dword ptr [g_walkCallback]
    L_d82c:
        add      eax, dword ptr [esi + 0x20]
        mov      dword ptr [g_walkCallback], eax
        call     BootMod6487eClampAndChainMul10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d0
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [ebx + 8], ecx
        mov      edx, dword ptr [g_dispatchSave6_00541f94]
        mov      eax, dword ptr [g_eventQueueTotal]
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_xformEntityIdx], eax
        call     Mul10HeavyTransform_00424bf0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d0
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      edx, 4
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_currentNodeIdx], edx
        call     QuadInterpolator_00425380
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_d8d0
        mov      eax, dword ptr [g_eventQueueEnd]
        mov      eax, dword ptr [eax*4]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueEnd], eax
        jne      L_d6d0
    L_d8ba:
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [g_xformEntityIdx], ecx
        call     MStackPop8_004ab860
    L_d8d0:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
