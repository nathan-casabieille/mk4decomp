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

extern unsigned int g_dispatchSave541_004e8698;
extern unsigned int g_tickFlagF;
extern unsigned int g_stateFlag;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern unsigned int g_counter_0053a51c;
extern unsigned int g_stateChangePair_00541d6c;
extern void BootInitGuardedCallChain(void);
extern void CallSetPause(void);
extern void DualPushSetCallDualPop(void);
extern void HealthBarTickDriver(void);
extern void QuadCallPauseJmp(void);
extern void QuadCallPhase2(void);
extern void SequencedInit3CallB(void);
extern void SpawnTrioInitCluster(void);
extern void TableWalkBoundedCmp(void);
extern void TripleStageRollback(void);
extern void func_00427780(void);

__declspec(naked) void RoundEndHandlerCluster(void)
{
    __asm {
        /* H1 (L_7de0): 3-state FSM */
    L_7de0:
        mov      eax, dword ptr [g_baseSel]
        push     ebx
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_7ed2
        dec      eax
        jne      short L_7e38
        mov      eax, dword ptr [g_stateChangePair_00541d6c]
        test     eax, eax
        mov      dword ptr [g_walkCallback], eax
        je       L_7f6d
        push     0x25e
        call     DualPushSetCallDualPop
        mov      al, byte ptr [g_xformDirtyFlags]
        mov      ebx, 1
        add      esp, 4
        test     al, bl
        jne      short L_7e7d
    L_7e38:
        call     BootInitGuardedCallChain
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7f8b
        push     3
        call     TableWalkBoundedCmp
        mov      ecx, dword ptr [g_counter_0053a51c]
        mov      edx, dword ptr [g_dlNalt2]
        mov      eax, dword ptr [g_dlNalt1]
        add      esp, 4
        add      ecx, 0x12
        push     0x1d
        push     ecx
        push     edx
        push     eax
        call     QuadCallPhase2
        add      esp, 0x10
        call     StackPopDispatchTagged
        pop      esi
        pop      ebx
        ret
    L_7e7d:
        call     HealthBarTickDriver
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7f8b
        call     SpawnTrioInitCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_7f8b
        push     0x25e
        call     TripleStageRollback
        mov      dword ptr [esi + 8], OFFSET L_7de0
        mov      dword ptr [esi + 0x84], 2
        add      esp, 4
        mov      dword ptr [g_pendingNodeType], 0x3c
        mov      dword ptr [g_framePauseFlag], ebx
        pop      esi
        pop      ebx
        ret
    L_7ed2:
        push     7
        call     TableWalkBoundedCmp
        add      esp, 4
        push     -1
        push     -1
        push     -1
        push     0x1c
        call     QuadCallPhase2
        mov      ecx, dword ptr [g_eventQueueWorkType]
        mov      eax, 0xc
        add      esp, 0x10
        mov      dword ptr [g_stateFlag], ecx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [g_tickFlagF], eax
        call     SequencedInit3CallB
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7f8b
        call     QuadCallPauseJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7f8b
        push     0x25e
        push     OFFSET L_7f90
        call     StoreTwoCall
        add      esp, 8
        mov      dword ptr [g_eventQueueWorkType], 9
        call     Push16Call
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_7f8b
        mov      edx, OFFSET g_dispatchSave541_004e8698
        push     0x262
        shr      edx, 2
        push     OFFSET func_00427780
        mov      dword ptr [g_fightGroupHead], edx
        call     StoreTwoCall
        add      esp, 8
    L_7f6d:
        mov      ebx, 1
        mov      dword ptr [esi + 8], OFFSET L_7de0
        mov      dword ptr [esi + 0x84], ebx
        mov      dword ptr [g_pendingNodeType], ebx
        mov      dword ptr [g_framePauseFlag], ebx
    L_7f8b:
        pop      esi
        pop      ebx
        ret
        nop
        nop
        /* H2 (L_7f90): per-entity state-clear */
    L_7f90:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       short L_7fc2
        mov      ecx, 1
        mov      dword ptr [g_walkCallback], ecx
        mov      dword ptr [g_stateChangePair_00541d6c], ecx
        jmp      CallSetPause
    L_7fc2:
        mov      ecx, 1
        mov      dword ptr [eax + 8], OFFSET L_7f90
        mov      dword ptr [eax + 0x84], ecx
        mov      dword ptr [g_pendingNodeType], 0x708
        mov      dword ptr [g_framePauseFlag], ecx
        ret
    }
}
