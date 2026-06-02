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

extern void PendingMatch_004a62b0(void);
extern void AudioPreloadStreamingTrack(void);
extern void FiveTableWalkInit(void);
extern void CallSetPause(void);
extern void BootInitGuardedCallChain(void);
extern void IncCapped3e7(void);
/* extern void AllocNode(void); -- defined elsewhere with diff sig */
extern void TripleCallSetCopy(void);
extern void MemcpyByteN(void);
extern void AudioInstallSelfStatePush(void);
extern void LoadGeoAsset_Default(void);
extern void TableWalkBoundedCmp(int);
extern void QuadCallPhase2(void);
extern unsigned int g_audioPreloadVar2;
extern unsigned int g_audioPreloadVar;
extern unsigned int g_dispatchSave519;
extern unsigned int g_dispatchSave633;
extern unsigned int g_audioPreloadBase;
extern unsigned int g_count;
extern unsigned int g_byte_005435a0;
extern unsigned int g_byte_005435b8;
extern unsigned int g_audioPreloadState;


__declspec(naked) void AudioPreloadStreamingTrack(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_6fc9
        push     8
        call     TableWalkBoundedCmp
        add      esp, 4
        push     7
        call     TableWalkBoundedCmp
        add      esp, 4
        call     BootInitGuardedCallChain
        call     IncCapped3e7
        push     -1
        push     -1
        push     -1
        push     0x1e
        call     QuadCallPhase2
        add      esp, 0x10
        call     FiveTableWalkInit
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_702b
        mov      ecx, OFFSET g_audioPreloadBase
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_702b
        call     TripleCallSetCopy
        mov      eax, dword ptr [g_count]
        cmp      eax, 4
        mov      eax, dword ptr [g_audioBankSel]
        jne      short L_6f3d
        mov      edx, dword ptr [g_audioPreloadState]
        cmp      eax, 1
        lea      eax, [edx*4]
        mov      ecx, dword ptr [eax + g_audioPreloadVar2]
        lea      ecx, [ecx + ecx*2]
        jne      short L_6f2e
        mov      eax, dword ptr [eax + g_dispatchSave519]
        lea      ecx, [ecx*8 + g_byte_005435a0]
        jmp      short L_6f7f
    L_6f2e:
        mov      eax, dword ptr [eax + g_dispatchSave519]
        lea      ecx, [ecx*8 + g_byte_005435b8]
        jmp      short L_6f7f
    L_6f3d:
        cmp      eax, 1
        jne      short L_6f5c
        mov      eax, dword ptr [g_audioPreloadState]
        shl      eax, 2
        mov      ecx, dword ptr [eax + g_audioPreloadVar]
        lea      ecx, [ecx + ecx*2]
        lea      ecx, [ecx*8 + g_byte_005435a0]
        jmp      short L_6f79
    L_6f5c:
        mov      edx, dword ptr [g_audioPreloadState]
        lea      eax, [edx*4]
        mov      ecx, dword ptr [eax + g_audioPreloadVar]
        lea      ecx, [ecx + ecx*2]
        lea      ecx, [ecx*8 + g_byte_005435b8]
    L_6f79:
        mov      eax, dword ptr [eax + g_dispatchSave633]
    L_6f7f:
        lea      edx, [eax + eax*2]
        push     0x18
        push     ecx
        lea      eax, [edx*8 + g_byte_005435a0]
        push     eax
        call     MemcpyByteN
        mov      ecx, dword ptr [g_audioPreloadState]
        add      esp, 0xc
        inc      ecx
        mov      dword ptr [g_pendingNodeType], OFFSET PendingMatch_004a62b0
        mov      dword ptr [g_audioPreloadState], ecx
        mov      dword ptr [g_eventQueueWorkType], 0x1000
        call     AllocNode
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_702b
        jmp      CallSetPause
    L_6fc9:
        mov      dword ptr [eax + 8], OFFSET AudioPreloadStreamingTrack
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET AudioPreloadStreamingTrack
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edx, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     AudioInstallSelfStatePush
        mov      dword ptr [g_framePauseFlag], 1
    L_702b:
        ret
    }
}
