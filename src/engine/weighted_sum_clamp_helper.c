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
extern void GuardedDispatch_InstallSelfDualEsi(void);
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

/*
 * @addr 0x00439920 (129b game) - weighted-sum + cap + helper:
 *   computes walk = clamp(0x53a3c0 * 0x4f381c + 0x4f3814 + 0x54355c_dispatch
 *   + 0x541fb0*0x4f3818 + 0x53a1f0*0x4f3820, max 0x3cf); cj-dependent
 *   pick of multiplier (0x5433f0 if baseSel==0x538038, else 0x543444);
 *   call StorePauseImulShr16.
 */
extern unsigned int g_dispatchSave1319;
extern unsigned int g_dispatchSave1320;
extern unsigned int g_dispatchSave1321;
extern unsigned int g_dispatchSave1322;
extern unsigned int g_audioRestoreSlot3;
extern unsigned int g_phaseCounter;
extern unsigned int g_audioInstallSlot2;
extern unsigned int g_phaseThunkSave2;
extern unsigned int g_audioPathFlag;
extern void AudioVolumeRescale(void);

/*
 * NON-COAXABLE: orig keeps d (g_dispatchSave1320) in ecx (volatile) across the entire
 * dispatch branch, and reuses esi as scratch for two different short-lived values
 * (ref in dispatch branch, then f intermediate after noScale). MSVC /O2 instead
 * promotes d to edi (extra callee-saved push), giving two-register prologue
 * (push esi/edi) vs orig's single push esi. The volatile-register-survives-
 * branch + register-reuse pattern is not coaxable from pure C.
 */
__declspec(naked) void WeightedSumClampHelper(void) {
    __asm {
        mov     eax, dword ptr [g_stateCountdown]
        mov     edx, dword ptr [g_dispatchSave1319]
        imul    eax, dword ptr [g_dispatchSave1321]
        mov     ecx, dword ptr [g_audioPathFlag]
        add     eax, edx
        test    ecx, ecx
        mov     ecx, dword ptr [g_dispatchSave1320]
        push    esi
        je      noScale
        mov     edx, dword ptr [g_baseSel]
        mov     esi, dword ptr [g_gtPlayerProbe2]
        cmp     edx, esi
        mov     edx, ecx
        jne     useB
        imul    edx, dword ptr [g_audioInstallSlot2]
        jmp     after
useB:
        imul    edx, dword ptr [g_phaseThunkSave2]
after:
        add     eax, edx
noScale:
        mov     esi, dword ptr [g_phaseCounter]
        mov     edx, dword ptr [g_audioRestoreSlot3]
        imul    edx, dword ptr [g_dispatchSave1322]
        imul    esi, ecx
        add     esi, eax
        lea     eax, [esi + edx]
        cmp     eax, 0x3cf
        mov     dword ptr [g_walkCallback], eax
        jle     callTail
        mov     dword ptr [g_walkCallback], 0x3cf
callTail:
        call    AudioVolumeRescale
        pop     esi
        ret
    }
}
