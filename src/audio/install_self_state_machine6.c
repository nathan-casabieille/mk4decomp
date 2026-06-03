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

extern unsigned int g_dispatchSave814;
extern unsigned int g_tickFlagF;
extern unsigned int g_phaseIdx;
extern unsigned int g_audioSavedGlobal0;
extern unsigned int g_audioSavedGlobal1;
extern unsigned int g_audioSavedGlobal2;
extern unsigned int g_audioSavedGlobal3;
extern void AudioInstallSelfStatePush(void);
extern void BootInitGuardedCallChain(void);
extern void FiveTableWalkInit(void);
extern void MStackPush2ChainLLInsert(void);
extern void MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430(void);
extern void PushPopScaledInit343c(void);
extern void SceneFrameStepWithInputs(void);

__declspec(naked) void InstallSelfStateMachine6(void)
{
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        xor      edi, edi
        mov      ebx, 1
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, 5
        ja       L_4b51
        jmp      dword ptr [eax*4 + L_4b6c_jmptbl]
        mov      ecx, dword ptr [g_eventQueueIdx]
        mov      dword ptr [g_currentNodeIdx], ecx
        call     MStackPush2ChainLLInsert
        mov      dword ptr [g_tickW1], 0x100
        call     PushPopScaledInit343c
        mov      dword ptr [esi + 8], 0x4a48e0
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, 0x4a48e0
        mov      dword ptr [edx*4 + 0x84], 3
        mov      eax, dword ptr [esi + 4]
        add      ecx, 0x3000000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     AudioInstallSelfStatePush
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        pop      esi
        pop      ebx
        ret      
        push     ebx
        push     ebx
        call     SceneFrameStepWithInputs
        add      esp, 8
        cmp      eax, 9
        je       L_4a51
        call     PushPopScaledInit343c
        mov      dword ptr [esi + 8], 0x4a48e0
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, 0x4a48e0
        mov      dword ptr [eax*4 + 0x84], 4
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      ecx, 0x4000000
        jmp      L_4a15
        push     ebx
        push     2
        call     SceneFrameStepWithInputs
        add      esp, 8
        cmp      eax, 9
        je       L_4a51
        call     PushPopScaledInit343c
        mov      dword ptr [esi + 8], 0x4a48e0
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, 0x4a48e0
        mov      dword ptr [eax*4 + 0x84], 5
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        add      ecx, 0x5000000
    L_4a15:
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], edi
        call     AudioInstallSelfStatePush
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
        push     ebx
        push     0x23
        call     SceneFrameStepWithInputs
        add      esp, 8
    L_4a51:
        call     FiveTableWalkInit
        cmp      dword ptr [g_framePauseFlag], edi
        je       L_4b51
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [g_tickFlagF], 2
        mov      dword ptr [g_phaseIdx], 0x10
        mov      dword ptr [eax*4 + 0x30], edi
        call     BootInitGuardedCallChain
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_4b66
        mov      ecx, 0x506c44
        shr      ecx, 2
        mov      dword ptr [g_currentNodeIdx], ecx
        call     LoadGeoAsset_Default
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_4b66
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [edx*4 + 0x30]
        mov      ecx, dword ptr [eax*4 + g_dispatchSave814]
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        call     DispatcherComplex260_FramePauseScaledStore
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_4b66
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x1f
        mov      dword ptr [edx*4 + 0x54], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        call     MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430
        cmp      dword ptr [g_framePauseFlag], edi
        jne      L_4b66
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ebx, 1
        mov      dword ptr [g_eventQueueIdx], edx
        mov      dword ptr [g_tickW1], 0x100
        mov      dword ptr [esi + 8], 0x4a48e0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], 0xf0
        mov      dword ptr [g_framePauseFlag], ebx
        pop      edi
        pop      esi
        pop      ebx
        ret      
    L_4b51:
        mov      dword ptr [g_tickFlagF], 2
        mov      dword ptr [g_phaseIdx], ebx
        call     StackPopDispatchTagged
    L_4b66:
        pop      edi
        pop      esi
        pop      ebx
        ret      
        mov      edi, edi
    L_4b6c_jmptbl:
        /* 6-entry jump table */
        _emit    0x66
        _emit    0x4a
        _emit    0x4a
        _emit    0x00
        _emit    0x12
        _emit    0x49
        _emit    0x4a
        _emit    0x00
        _emit    0x12
        _emit    0x49
        _emit    0x4a
        _emit    0x00
        _emit    0x92
        _emit    0x49
        _emit    0x4a
        _emit    0x00
        _emit    0xd6
        _emit    0x49
        _emit    0x4a
        _emit    0x00
        _emit    0x46
        _emit    0x4a
        _emit    0x4a
        _emit    0x00
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
        mov      ecx, dword ptr [g_audioSavedGlobal0]
        xor      eax, eax
        test     ecx, ecx
        sete     al
        mov      dword ptr [g_audioSavedGlobal0], eax
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
        mov      ecx, dword ptr [g_audioSavedGlobal1]
        xor      eax, eax
        test     ecx, ecx
        sete     al
        mov      dword ptr [g_audioSavedGlobal1], eax
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
        mov      ecx, dword ptr [g_audioSavedGlobal2]
        xor      eax, eax
        test     ecx, ecx
        sete     al
        mov      dword ptr [g_audioSavedGlobal2], eax
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
        mov      ecx, dword ptr [g_audioSavedGlobal3]
        xor      eax, eax
        test     ecx, ecx
        sete     al
        mov      dword ptr [g_audioSavedGlobal3], eax
        ret      
    }
}
