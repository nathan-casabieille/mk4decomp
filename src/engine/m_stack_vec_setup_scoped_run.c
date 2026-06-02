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

/* @addr 0x004749a0 (360b game) - mstack snapshot + vec setup + scoped run.
 *   Sets g_xformEntityIdx = &g_vecSetupArrBase_0051204c>>2 (packed_ptr), calls
 *   DispatcherComplex260_00407030. On no-error AND bit 2 of 0x54208c clear:
 *   pushes g_currentNodeIdx, walks one level of [scaled+0x18] indirection,
 *   OR's bit 9 into [resolved+0x20]. Pops the snapshot back into 0x542044,
 *   writes 0x95 into [snapshot+0x30], copies the 3-component vec at
 *   [g_eventQueueIdx *4 + 0/4/8] into [snapshot+0x54/+0x58/+0x5c]. Calls
 *   AudioMixerStep. On no-error reads g_walkCallback, adds
 *   0xa3d, writes into [snapshot+0x70], sets g_eventQueueWorkType=0xc4, advances
 *   g_currentNodeIdx by 0x1b, calls TripleVecAccCallStore.
 *   On no-error subtracts 0x1b back from 0x542044, calls MStackCall_00406340,
 *   sets g_walkCallback=1 on success.
 */
extern unsigned int g_vecSetupArrBase_0051204c;
extern unsigned int g_table_004d57b0;
extern void AudioMixerStep(void);
extern void MStackCall_00406340(void);

void MStackVecSetupScopedRun_004749a0(void) {
    __asm {
        mov     eax, offset g_vecSetupArrBase_0051204c
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    DispatcherComplex260_00407030
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mvss_done
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_mvss_done
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [edx*4 + 0x18]
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     eax, dword ptr [ecx*4 + 0x20]
        or      ah, 6
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     eax, 0x95
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [eax*4]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 4]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x58], eax
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [edx*4 + 8]
        mov     dword ptr [ecx*4 + 0x5c], eax
        mov     dword ptr [g_walkCallback], 0x28f
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mvss_done
        mov     eax, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_currentNodeIdx]
        add     eax, 0xa3d
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x70], eax
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_eventQueueWorkType], 0xc4
        add     ecx, 0x1b
        mov     dword ptr [g_currentNodeIdx], ecx
        call    TripleVecAccCallStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mvss_done
        sub     dword ptr [g_currentNodeIdx], 0x1b
        call    MStackCall_00406340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mvss_done
        mov     dword ptr [g_walkCallback], 1
    L_mvss_done:
        }
}

