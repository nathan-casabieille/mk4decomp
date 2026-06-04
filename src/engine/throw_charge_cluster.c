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

extern unsigned int g_pendingMatchVar;
extern void AudioMixerStep(void);
extern void DispatcherComplex138_004760f0(void);
extern void MStackPush1MagicMod2(void);
extern void MStackPush2ChainLLInsert(void);
extern void SetupVecFsmCluster(void);
extern void StoreDoubleNegPauseSubStore(void);
extern void StoreLoadJmp(void);
extern void ThrowFsmCluster_MStackPush2RunCountdown(void);
extern void Thunk_ScaledNeg1SetPause(void);

__declspec(naked) void ThrowChargeCluster(void)
{
    __asm {
        mov      eax, dword ptr [g_currentNodeIdx]
        push     esi
        mov      dword ptr [eax*4 + 0x30], 0x75
        mov      dword ptr [g_walkCallback], 0x2147
        lea      esi, [eax*4]
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      ecx, dword ptr [g_walkCallback]
        mov      dword ptr [esi + 0x78], ecx
        mov      dword ptr [g_walkCallback], 0x2147
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [esi + 0x7c], edx
        mov      dword ptr [g_walkCallback], 0x2147
        call     StoreDoubleNegPauseSubStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [esi + 0x80], eax
        mov      ecx, dword ptr [g_pendingMatchVar]
        mov      dword ptr [g_walkCallback], ecx
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [g_eventQueueWorkType], edx
        call     MStackPush1MagicMod2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      eax, dword ptr [g_walkCallback]
        push     eax
        push     0x2b85
        call     Mul10Tail
        mov      ecx, dword ptr [g_eventQueueCurrent]
        add      esp, 8
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_eventQueueWorkType], eax
        push     ecx
        push     0x2b85
        call     Mul10Tail
        add      esp, 8
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [g_walkCallback], 0xb333
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      eax, dword ptr [g_walkCallback]
        mov      edx, dword ptr [g_eventQueueWorkType]
        add      eax, 0x4ccc
        push     edx
        push     eax
        mov      dword ptr [g_walkCallback], eax
        call     Mul10Tail
        mov      ecx, dword ptr [g_walkCallback]
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], eax
        mov      eax, dword ptr [g_eventQueueCurrent]
        push     eax
        push     ecx
        call     Mul10Tail
        mov      edx, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [g_eventQueueCurrent], eax
        mov      dword ptr [esi + 0x6c], edx
        mov      eax, dword ptr [g_eventQueueCurrent]
        add      esp, 8
        mov      dword ptr [esi + 0x74], eax
        mov      dword ptr [g_walkCallback], 0x11eb
        call     AudioMixerStep
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_e8df
        mov      ecx, dword ptr [g_walkCallback]
        mov      eax, 0xffffe3d8
        sub      eax, ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [esi + 0x70], eax
    L_e8df:
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
        nop
        nop
        nop
        nop
        nop
    L_e8f0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     ebp
        push     esi
        lea      ebp, [eax*4]
        xor      esi, esi
        push     edi
        mov      eax, dword ptr [ebp + 0x84]
        mov      dword ptr [ebp + 0x84], esi
        cmp      eax, esi
        jne      L_e91f
        push     OFFSET SetupVecFsmCluster + 0x2c0
        call     StoreLoadJmp
        add      esp, 4
    L_e91f:
        mov      edi, 0x75
        mov      bl, 4
    L_e926:
        mov      dword ptr [g_currentNodeIdx], esi
    L_e92c:
        mov      dword ptr [g_walkCallback], edi
        call     DispatcherComplex138_004760f0
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_ea0f
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_e9f3
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [eax*4 + 0x58]
        cmp      ecx, esi
        mov      dword ptr [g_walkCallback], ecx
        jl       L_e92c
        mov      ecx, dword ptr [eax*4 + 0x54]
        mov      dword ptr [g_walkCallback], ecx
        mov      edx, dword ptr [eax*4 + 0x5c]
        mov      eax, dword ptr [g_matrixStackTop]
        mov      dword ptr [g_eventQueueCurrent], edx
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueCurrent]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     MStackPush2ChainLLInsert
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_ea0f
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueCurrent], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_matrixStackTop], eax
        call     MStackBracketed3StoreCall
        cmp      dword ptr [g_framePauseFlag], esi
        jne      L_ea0f
        jmp      L_e926
    L_e9f3:
        mov      eax, 1
        mov      dword ptr [ebp + 8], OFFSET L_e8f0
        mov      dword ptr [ebp + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_ea0f:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
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
    L_ea20:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_ea94
        dec      eax
        je       L_ea5f
        call     ThrowFsmCluster_MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_eae8
        call     Thunk_ScaledNeg1SetPause
        pop      esi
        ret      
    L_ea5f:
        call     ThrowFsmCluster_MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_eae8
        mov      dword ptr [esi + 8], OFFSET L_ea20
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], 0xf
        mov      dword ptr [g_framePauseFlag], 1
        pop      esi
        ret      
    L_ea94:
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [ecx*4 + 0x64], edx
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [eax*4 + 0x68], ecx
        call     ThrowFsmCluster_MStackPush2RunCountdown
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_eae8
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_ea20
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0xf
        mov      dword ptr [g_framePauseFlag], eax
    L_eae8:
        pop      esi
        ret      
    }
}
