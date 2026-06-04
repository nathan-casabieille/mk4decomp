/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

extern void AudioMixerStep(void);
extern void EsiTripleMul10Vec(void);
extern void GatedWordPushCall(void);
extern void ScaledAddStore(void);
extern void SetJmp_AudioBridgeMStackChainCopy_00440720(void);
extern void StoreDoubleNegPauseSubStore(void);

__declspec(naked) void CameraBounceUpdate(void)
{
    __asm {
        push     esi
        call     ScaledAddStore
        mov      eax, dword ptr [g_framePauseFlag]
        xor      esi, esi
        cmp      eax, esi
        jne      L_0657
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [ecx*4 + 0x58]
        cmp      eax, esi
        mov      dword ptr [g_walkCallback], eax
        jge      short L_0472
        cmp      eax, 0xfffff334
        jge      L_0527
        call     SetJmp_AudioBridgeMStackChainCopy_00440720
        mov      eax, dword ptr [g_framePauseFlag]
        pop      esi
        ret
    L_0472:
        je       L_0657
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [ecx*4 + 0x58], esi
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x70]
        push     eax
        push     0xffff999a
        mov      dword ptr [g_eventQueueCurrent], eax
        call     Mul10Tail
        add      esp, 8
        cmp      eax, 0xfffffd71
        mov      dword ptr [g_eventQueueCurrent], eax
        jle      short L_052e
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], esi
        mov      dword ptr [ecx*4 + 0x6c], esi
        mov      edx, dword ptr [g_walkCallback]
        lea      eax, [ecx*4]
        mov      dword ptr [eax + 0x70], edx
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x74], ecx
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x78], edx
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x7c], ecx
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x80], edx
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [eax + 0x4c], ecx
        mov      ecx, 0xfffffae2
        mov      dword ptr [g_walkCallback], ecx
        mov      edx, dword ptr [eax + 0x54]
        mov      dword ptr [eax + 0x58], ecx
        mov      dword ptr [g_walkCallback], edx
        mov      eax, dword ptr [eax + 0x5c]
        mov      dword ptr [g_eventQueueCurrent], eax
        call     MStackBracketed3StoreCall
    L_0527:
        mov      eax, dword ptr [g_framePauseFlag]
        pop      esi
        ret
    L_052e:
        mov      dword ptr [g_walkCallback], 0x19
        call     GatedWordPushCall
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_0657
        mov      dword ptr [g_walkCallback], 0x20c
        call     StoreDoubleNegPauseSubStore
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_0657
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      edx, dword ptr [g_walkCallback]
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      eax, edx
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x6c]
        push     eax
        push     0x6666
        mov      dword ptr [g_eventQueueCurrent], eax
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_walkCallback], 0x20000
        call     AudioMixerStep
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_0657
        mov      eax, dword ptr [g_eventQueueCurrent]
        mov      ecx, dword ptr [g_walkCallback]
        push     eax
        push     ecx
        call     Mul10Tail
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_eventQueueCurrent], eax
        add      esp, 8
        mov      dword ptr [edx*4 + 0x6c], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [eax*4 + 0x74]
        push     eax
        push     0x6666
        mov      dword ptr [g_eventQueueCurrent], eax
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_walkCallback], 0x30000
        call     AudioMixerStep
        cmp      dword ptr [g_framePauseFlag], esi
        jne      short L_0657
        mov      ecx, dword ptr [g_eventQueueCurrent]
        mov      edx, dword ptr [g_walkCallback]
        push     ecx
        push     edx
        call     Mul10Tail
        mov      ecx, dword ptr [g_currentNodeIdx]
        add      esp, 8
        mov      dword ptr [ecx*4 + 0x74], eax
        mov      dword ptr [g_eventQueueCurrent], 0xffff0ccd
        call     EsiTripleMul10Vec
    L_0657:
        pop      esi
        ret
    }
}
