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

/* @addr 0x00462980 (265b game) - install-self dual path with init / state setup.
 *   snapshot+clear chain[+0x84].
 *   If was nonzero: call BootInitGuardedCallChain; if pause? ret.
 *     baseSel[+0x0c]=0x1000; tail-call InstallSelfTableWalk; ret.
 *   If was zero: clear scaledInit[0]=0; g_scaledChainLoop_00537f74=1; g_walkCallback=2;
 *     g_active_0053a408=2; g_active_00537e88=2; g_eventQueueWorkType=4.
 *     call Push16Call; if pause? ret.
 *     call ScenegraphWalk; g_eventQueueCurrent=0xc; install-self at
 *     [esi+8]=0x00462980; chain[+0x84]=1; scaledInit-chain push 0x00462980+0x01000000.
 *     Call InstallSelfPackedF80; pause=1; ret.
 */
extern unsigned int g_scaledChainLoop_00537f74;
extern void BootInitGuardedCallChain(void);
extern void InstallSelfPackedF80(void);
extern void InstallSelfTableWalk(void);
extern void ScenegraphWalk(void);

__declspec(naked) void InstallSelfBootInit(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   30h
        call    BootInitGuardedCallChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d3h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, 0x1000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x0c], eax
        call    InstallSelfTableWalk
        pop     esi
        ret
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     eax, 2
        mov     dword ptr [edx*4 + 0], 0
        mov     dword ptr [g_scaledChainLoop_00537f74], 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_active_0053a408], eax
        mov     dword ptr [g_active_00537e88], eax
        mov     dword ptr [g_eventQueueWorkType], 4
        call    Push16Call
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   6eh
        call    ScenegraphWalk
        mov     dword ptr [g_eventQueueCurrent], 0x0c
        mov     dword ptr [esi + 8], 0x00462980
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, 0x00462980
        add     ecx, 0x01000000
        mov     dword ptr [eax*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    InstallSelfPackedF80
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    }
}
