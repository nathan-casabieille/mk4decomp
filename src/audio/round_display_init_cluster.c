/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
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
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
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
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
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
extern void PendingMatch_StoreTwoCall_0042b930(void);
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
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
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

extern void AudioStreamFsm5Way(void);
extern void TwoCallsTwoBranchTail(void);
extern void RoundDisplayInitCluster(void);
extern void CopyGlobal(void);
extern unsigned int g_audioStreamState;

extern void AudioInitInstallerPair(void);
extern void BootInitGuardedCallChain(void);
extern void GuardedSetupCallTailJmp(void);

__declspec(naked) void AudioStreamFsm5Way(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     esi
        push     edi
        xor      edi, edi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 4
        ja       L_4115
        jmp      dword ptr [eax*4 + L_f50_jmptbl]
    L_3f7d:
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [ecx*4 + 0x30]
        mov      dword ptr [edx*4 + 0x74], edi
        mov      eax, dword ptr [g_audioStreamState]
        cmp      eax, edi
        jne      short L_3fd3
        call     TwoCallsTwoBranchTail
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_411a
        mov      dword ptr [esi + 8], OFFSET AudioStreamFsm5Way
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3fd3:
        mov      dword ptr [esi + 8], OFFSET AudioStreamFsm5Way
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_3ffb:
        mov      dword ptr [esi + 8], OFFSET AudioStreamFsm5Way
        mov      dword ptr [esi + 0x84], 4
        mov      dword ptr [g_pendingNodeType], 0xf0
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_4023:
        mov      dword ptr [g_walkCallback], edi
        call     CopyGlobal
        call     BootInitGuardedCallChain
        cmp      dword ptr [g_gtOtherFlag], edi
        je       short L_4115
        mov      dword ptr [esi + 8], OFFSET AudioStreamFsm5Way
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, OFFSET AudioStreamFsm5Way
        mov      dword ptr [eax*4 + 0x84], 5
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x5000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     RoundDisplayInitCluster
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        ret
    L_409d:
        push     0xffec0000
        push     0x4d2320
        call     GuardedSetupCallTailJmp
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      dword ptr [eax*4 + 0x30], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [edx*4 + 0x30]
        mov      dword ptr [eax*4 + 0x5c], 0xa0000
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 1
        mov      edx, dword ptr [ecx*4 + 0x30]
        mov      dword ptr [edx*4 + 0x74], 0xffffc000
        mov      dword ptr [esi + 8], OFFSET AudioStreamFsm5Way
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0x24
        mov      dword ptr [g_framePauseFlag], eax
        pop      edi
        pop      esi
        ret
    L_4115:
        call     AudioInitInstallerPair
    L_411a:
        pop      edi
        pop      esi
        ret
        /* 3-byte align nop `lea ecx, [ecx]` (8d 49 00). */
        _emit    0x8d
        _emit    0x49
        _emit    0x00
    L_f50_jmptbl:
        _emit    0x9d
        _emit    0x40
        _emit    0x4a
        _emit    0x00
        _emit    0x7d
        _emit    0x3f
        _emit    0x4a
        _emit    0x00
        _emit    0xd3
        _emit    0x3f
        _emit    0x4a
        _emit    0x00
        _emit    0xfb
        _emit    0x3f
        _emit    0x4a
        _emit    0x00
        _emit    0x23
        _emit    0x40
        _emit    0x4a
        _emit    0x00
    }
}
