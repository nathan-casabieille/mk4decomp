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

extern unsigned int g_dispatchSave523_004d5140;
extern unsigned int g_load_0052ab10;
extern unsigned int g_particleEmitterNode;
extern unsigned int g_bootChainSlot3_00537e8c;
extern unsigned int g_bootHeavyState;
extern unsigned int g_phaseThunkSlot8_0053a520;
extern unsigned int g_particleInitState;
extern unsigned int g_dispatchSave82_00541e7c;
extern unsigned int g_bootChainPair0_00541e80;
extern unsigned int g_bootChainPair1_00541e84;
extern unsigned int g_bootChainScaled1_00541e88;
extern unsigned int g_bootChainScaled2_00541e8c;
extern unsigned int g_lit_00541e90;
extern unsigned int g_lit_00541e94;
extern unsigned int g_bootChainState3_00541e98;
extern unsigned int g_bootChainScaled4_00541e9c;
extern unsigned int g_bootChainScaled3_00541ea0;
extern unsigned int g_dispatchSave81_00541ea4;
extern unsigned int g_bootChainSlot2_00541ea8;
extern unsigned int g_dispatchSave80_00541eac;
extern unsigned int g_bootChainState4_00541eb0;
extern unsigned int g_audioInitScaled;
extern void AndShlStore(void);
extern void BootPhaseGateBracketedInit(void);
extern void Helper_GeoLoadPre(void);
extern void LinkedListBuilder(void);
extern void MStackCall_004063e0(void);
extern void ScaledChainAccumLoop(void);
extern void Thunk_004bd8d0(void);
extern void VertexSlotInitFlagWalk(void);

__declspec(naked) void BootInitChainHeavy(void)
{
    __asm {
        push    esi
        xor     esi, esi
        mov     dword ptr [g_audioInitScaled], esi
        call    Helper_GeoLoadPre
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        call    Thunk_004bd8d0
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     eax, dword ptr [g_dispatchSave82_00541e7c]
        mov     ecx, dword ptr [g_bootChainPair0_00541e80]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], esi
        mov     dword ptr [g_pendingNodeType], 0x21
        mov     dword ptr [g_eventQueueTotal], ecx
        mov     dword ptr [g_eventQueueEnd], 0xC8
        call    LinkedListBuilder
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     edx, dword ptr [g_bootChainPair1_00541e84]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], edx
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     eax, dword ptr [g_bootChainScaled1_00541e88]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], eax
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     ecx, dword ptr [g_bootChainScaled2_00541e8c]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], ecx
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     edx, dword ptr [g_bootChainState3_00541e98]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], edx
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     eax, dword ptr [g_lit_00541e90]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], eax
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     ecx, dword ptr [g_lit_00541e94]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], ecx
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     edx, dword ptr [g_bootChainScaled4_00541e9c]
        mov     dword ptr [g_eventQueueEnd], esi
        mov     dword ptr [g_eventQueueTotal], edx
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     eax, dword ptr [g_bootChainScaled3_00541ea0]
        mov     dword ptr [g_xformEntityIdx], 3
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_eventQueueEnd], esi
        call    VertexSlotInitFlagWalk
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     ecx, dword ptr [g_dispatchSave81_00541ea4]
        mov     edx, dword ptr [g_bootChainSlot2_00541ea8]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_xformEntityIdx], 4
        mov     dword ptr [g_pendingNodeType], 0x13
        mov     dword ptr [g_eventQueueTotal], edx
        mov     dword ptr [g_eventQueueEnd], 0x1C2
        call    LinkedListBuilder
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     eax, dword ptr [g_dispatchSave80_00541eac]
        mov     ecx, dword ptr [g_bootChainState4_00541eb0]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], esi
        mov     dword ptr [g_pendingNodeType], 0x13
        mov     dword ptr [g_eventQueueTotal], ecx
        mov     dword ptr [g_eventQueueEnd], 0xC8
        call    LinkedListBuilder
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        call    ScaledChainAccumLoop
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        call    BootPhaseGateBracketedInit
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, 0x0C
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x30], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_load_0052ab10], eax
        call    MStackCall_004063e0
        cmp     dword ptr [g_framePauseFlag], esi
        jne     L_boot_init_exit
        mov     dword ptr [g_phaseThunkSlot8_0053a520], esi
        mov     dword ptr [g_bootChainSlot3_00537e8c], esi
        mov     dword ptr [g_bootHeavyState], esi
        mov     dword ptr [g_particleInitState], esi
        mov     dword ptr [g_particleEmitterNode], esi
        mov     dword ptr [g_dispatchSave523_004d5140], 0x7F000000
        mov     dword ptr [g_walkCallback], esi
        call    AndShlStore
    L_boot_init_exit:
        pop     esi
        ret
    }
}
