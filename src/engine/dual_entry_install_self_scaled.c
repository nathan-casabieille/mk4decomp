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

/* @addr 0x00461b70 (296b game) - dual entry: thunk + install-self with scaled init.
 *   Entry (0..0x35): if g_walkStateIndex!=0: dec; push 0x26, push body addr; call StoreTwoCall;
 *     pop; chain[scaledInit*4+0x14]=g_eventQueueNotMask; ret.
 *   Body (+0x40): load state at [base*4+0x84]; clear state.
 *   state!=0: call MStackCall; if pause ret. Tail-call CallSetPause; pop esi; ret.
 *   state==0: load eax=offset g_installScaledArrBase>>2 + g_eventQueueNotMask -> g_scaledInit.
 *     Init multiple globals; call Push70CallScaleArith; if pause ret.
 *     Set chain[+0x5c]=0x1b333; g_cj=scaledInit; install-self at body; state=1;
 *     g_pendingNodeType=0xb4; pause=1; ret.
 *   Tail (+0x120): set g_tickByteFlag=1; ret.
 */
extern unsigned int g_installScaledArrBase;
extern void CallSetPause(void);
extern void MStackCall_00406740(void);

__declspec(naked) void DualEntryInstallSelfScaled(void) {
    __asm {
        mov     eax, dword ptr [g_walkStateIndex]
        test    eax, eax
        mov     dword ptr [g_eventQueueNotMask], eax
        _emit   74h
        _emit   27h
        dec     eax
        push    0x26
        push    offset body_bb0
        mov     dword ptr [g_eventQueueNotMask], eax
        call    StoreTwoCall
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [g_eventQueueNotMask]
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x14], eax
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
    body_bb0:
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   19h
        call    MStackCall_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0a1h
        _emit   00h
        _emit   00h
        _emit   00h
        call    CallSetPause
        pop     esi
        ret
        mov     ecx, dword ptr [g_eventQueueNotMask]
        mov     eax, offset g_installScaledArrBase
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_walkCallback], 0x5f
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_eventQueueCurrent], 4
        mov     dword ptr [g_acc_00542078], 0
        mov     dword ptr [g_eventQueueNotMask], 0xc80000
        call    Push70CallScaleArith
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   42h
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     eax, 0x1b333
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x5c], eax
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_cj_0054205c], eax
        mov     eax, 1
        mov     dword ptr [esi + 8], offset body_bb0
        mov     dword ptr [esi + 0x84], eax
        mov     dword ptr [g_pendingNodeType], 0xb4
        mov     dword ptr [g_framePauseFlag], eax
        pop     esi
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        mov     byte ptr [g_tickByteFlag], 1
        ret
    }
}
