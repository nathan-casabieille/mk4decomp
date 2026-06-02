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

extern unsigned int g_primary_0052d74c;
extern unsigned int g_secondary_00535d04;
extern unsigned int g_secondary_00538068;
extern unsigned int g_primary_0053a774;
extern unsigned int g_dispatchVar20_0054200c;
extern void PositionClampCluster_00489a30(void);

__declspec(naked) void GeoTransformDispatchAndApply_00489840(void)
{
    __asm {
        /* H1 */
        mov      ecx, dword ptr [g_secondary_00535d04]
        mov      eax, dword ptr [g_primary_0053a774]
        mov      dword ptr [g_currentNodeFlags], ecx
        mov      ecx, dword ptr [g_primary_0052d74c]
        mov      dword ptr [g_eventQueueChild], eax
        xor      eax, eax
        test     ecx, ecx
        mov      dword ptr [g_walkCallback], eax
        jle      short L_9871
        mov      eax, 2
        mov      dword ptr [g_walkCallback], eax
    L_9871:
        mov      ecx, dword ptr [g_secondary_00538068]
        test     ecx, ecx
        mov      dword ptr [g_eventQueueCurrent], ecx
        je       short L_9889
        jl       short L_9889
        inc      eax
        mov      dword ptr [g_walkCallback], eax
    L_9889:
        mov      edx, dword ptr [g_dispatchVar20_0054200c]
        add      eax, edx
        mov      dword ptr [g_pendingNodeType], eax
        mov      eax, dword ptr [eax*4]
        mov      dword ptr [g_pendingNodeType], eax
        jmp      eax
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
        /* H1 case body */
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueWorkType], 0xccc
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      eax, dword ptr [g_fightAxisNegX]
        push     eax
        push     0xccc
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueCurrent], eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_currentNodeIdx]
        add      ecx, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [edx*4 + 0x54], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_eventQueueWorkType]
        add      esp, 8
        mov      ecx, dword ptr [eax*4 + 0x5c]
        mov      eax, dword ptr [g_fightAxisNegY]
        push     eax
        push     edx
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueCurrent], eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [g_eventQueueCurrent], eax
        add      ecx, eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], ecx
        add      esp, 8
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      eax, dword ptr [g_fightAxisPosX]
        mov      edx, dword ptr [ecx*4 + 0x54]
        mov      dword ptr [g_eventQueueCurrent], eax
        push     eax
        mov      eax, dword ptr [g_eventQueueWorkType]
        push     eax
        mov      dword ptr [g_walkCallback], edx
        call     Mul10Tail
        mov      ecx, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_xformEntityIdx]
        add      ecx, eax
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [edx*4 + 0x54], ecx
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      edx, dword ptr [g_eventQueueWorkType]
        add      esp, 8
        mov      ecx, dword ptr [eax*4 + 0x5c]
        mov      eax, dword ptr [g_fightAxisPosY]
        push     eax
        push     edx
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_eventQueueCurrent], eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [g_eventQueueCurrent], eax
        add      ecx, eax
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      dword ptr [g_walkCallback], ecx
        add      esp, 8
        mov      dword ptr [eax*4 + 0x5c], ecx
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
        /* H2: swap + tail-jmp */
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_xformEntityIdx]
        mov      edx, dword ptr [g_currentNodeFlags]
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_xformEntityIdx], eax
        mov      eax, dword ptr [g_eventQueueChild]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueChild], edx
        mov      dword ptr [g_currentNodeFlags], eax
        jmp      PositionClampCluster_00489a30
    }
}
