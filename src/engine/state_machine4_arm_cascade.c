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

extern void StateMachine4ArmCascade(void);

/* @addr 0x0043aed0 (282b game) - dual block: thunk + 3-state install-self.
 *   B1 (0..0x1f): call FiveCallScaledChainTailJmp; if !pause: push 0x004e4b28,
 *     tail-call ArgSarStoreJmp; ret.
 *   B2 (0x20..0x119, 3-state install-self):
 *     state >=2: tail-call StateMachine4ArmCascade.
 *     state 1: install-self [eax+8]=0x0043aef0, chain[+0x84]=2, scaledInit-chain push
 *       0x0043aef0+0x02000000; call ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain; pause=1; ret.
 *     state 0: g_eventQueueNotMask=0xa, g_eventQueueChild=0x1f, install-self at
 *       [eax+8]=0x0043aef0; chain[+0x84]=1; scaledInit-chain push 0x0043aef0+0x01000000;
 *       call InstallSelfDoubleMStack; pause=1; ret.
 */
extern void ArgSarStoreJmp(void);
extern void InstallSelfDoubleMStack(void);
extern void ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain(void);

__declspec(naked) void DualBlockThunkPlus3State(void) {
    __asm {
        call    FiveCallScaledChainTailJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0dh
        push    0x004e4b28
        call    ArgSarStoreJmp
        add     esp, 4
        ret
        nop
        nop
        nop
        nop
        mov     eax, dword ptr [g_baseSel]
        xor     edx, edx
        shl     eax, 2
        push    esi
        push    edi
        mov     ecx, dword ptr [eax + 0x84]
        mov     dword ptr [eax + 0x84], edx
        sub     ecx, edx
        _emit   74h
        _emit   6ch
        dec     ecx
        _emit   74h
        _emit   08h
        call    StateMachine4ArmCascade
        pop     edi
        pop     esi
        ret
        mov     dword ptr [eax + 8], 0x0043aef0
        mov     ecx, dword ptr [g_baseSel]
        mov     esi, 0x0043aef0
        mov     dword ptr [ecx*4 + 0x84], 2
        mov     ecx, dword ptr [eax + 4]
        add     esi, 0x02000000
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [ecx*4 + 0], esi
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edx
        call    ScaledLoadIncJmp_set_g_eventQueueCurrent_then_ScaledArrStore_EsiInstallBitCallChain
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        pop     esi
        ret
        mov     dword ptr [g_eventQueueNotMask], 0x0a
        mov     dword ptr [g_eventQueueChild], 0x1f
        mov     dword ptr [eax + 8], 0x0043aef0
        mov     ecx, dword ptr [g_baseSel]
        mov     esi, 1
        mov     edi, 0x0043aef0
        mov     dword ptr [ecx*4 + 0x84], esi
        mov     ecx, dword ptr [eax + 4]
        add     edi, 0x01000000
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [ecx*4 + 0], edi
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [eax + 4], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edx
        call    InstallSelfDoubleMStack
        mov     dword ptr [g_framePauseFlag], esi
        pop     edi
        pop     esi
        ret
    }
}
