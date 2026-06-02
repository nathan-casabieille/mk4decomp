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
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
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
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
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

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
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
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
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

extern unsigned int g_dispatchSave920;
extern unsigned int g_dispatchSave922;
extern unsigned int g_assetLoadStateInit;
extern unsigned int g_dispatchSave141;
extern void BootInitGuardedCallChain(void);
extern void CopyGlobal(void);
extern void InstallSelfPackedF80(void);
extern void OpcodeStreamDispatch(void);
extern void RegistryPushBindPop(void);

__declspec(naked) void ContinueScreenFsm(void)
{
    __asm {
    L_3c20:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        sub      eax, edi
        je       L_3e4e
        dec      eax
        je       L_3d8d
        dec      eax
        je       L_3d25
        call     BootInitGuardedCallChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3e8f
        mov      ecx, OFFSET g_assetLoadStateInit
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3e8f
        mov      dword ptr [g_eventQueueWorkType], 0x25
        call     Push16Call
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3e8f
        mov      dword ptr [g_walkCallback], edi
        call     CopyGlobal
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3e8f
        mov      edx, OFFSET g_dispatchSave920
        mov      dword ptr [g_walkCallback], 0xa
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [g_acc_00542078], edi
        mov      dword ptr [g_eventQueueNotMask], 0xff9c0000
        call     Push70CallScaleArith
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_3e8f
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x10000
        mov      edx, OFFSET g_dispatchSave922
        mov      dword ptr [g_walkCallback], eax
        shr      edx, 2
        mov      dword ptr [ecx*4 + 0x5c], eax
        mov      dword ptr [g_eventQueueIdx], edx
        call     OpcodeStreamDispatch
        pop      edi
        pop      esi
        ret
    L_3d25:
        mov      dword ptr [g_eventQueueCurrent], 4
        mov      dword ptr [esi + 8], OFFSET L_3c20
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET L_3c20
        add      ecx, 0x3000000
        mov      dword ptr [eax*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     InstallSelfPackedF80
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3d8d:
        mov      eax, OFFSET g_assetLoadStateInit
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_3e8f
        mov      ecx, OFFSET g_assetLoadStateInit
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_3e8f
        mov      edx, OFFSET g_dispatchSave141
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        call     DispatcherComplex260_00407400
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_3e8f
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [eax*4 + 0x54], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x1f
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        call     PushSetCallPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_3e8f
        call     RegistryPushBindPop
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_3e8f
        mov      dword ptr [esi + 8], OFFSET L_3c20
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0xf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3e4e:
        call     BootInitGuardedCallChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_3e8f
        mov      dword ptr [g_walkCallback], edi
        call     CopyGlobal
        cmp      dword ptr [g_framePauseFlag], edi
        jne      short L_3e8f
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_3c20
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 8
        mov      dword ptr [g_framePauseFlag], eax
    L_3e8f:
        pop      edi
        pop      esi
        ret
    }
}
