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
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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

extern void Wrapper_0041fcf0(void);
extern void DualBlockChainInitBody_0043cc10(void);
extern void ScaledLitLoadCall_00480fe0(void);
extern void CallPauseScaledStoreCopyJmp_00461220(void);

/* @addr 0x00467d40 (280b game) - 3-state install-self with state-dependent dispatch.
 *   state 1: call CopyJmp_00406ba0; if !pause:
 *     baseSel[+0x34] mapped: 0x10 -> 2, 0x11 -> 7, else unchanged.
 *     g_walkCallback=mapped++. Fall through to common tail.
 *   state >= 2: skip to common tail.
 *   Common tail: call Wrapper_0041fcf0; tail-call DualBlockChainInitBody_0043cc10.
 *   state 0: dual-equal byte tests (g_gtModeFlag vs g_audioBankSel for 1 and 2)
 *     increment g_installSelfCounter_005433e8 on each match. g_walkCallback=0xac. 4-call chain
 *     ending with install-self at [esi+8]=0x00467d40, chain[+0x84]=1,
 *     g_pendingNodeType=8, pause=1; ret.
 */
extern unsigned int g_installSelfCounter_005433e8;
extern void CopyJmp_00406ba0(void);
extern void GateDispatch6c_00494580(void);
extern void ScaledMove48to58_00490720(void);

__declspec(naked) void InstallSelfStateCounter_00467d40(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        _emit   74h
        _emit   63h
        dec     eax
        _emit   75h
        _emit   54h
        call    CopyJmp_00406ba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0deh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x34]
        cmp     eax, 0x10
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0ah
        mov     eax, 2
        mov     dword ptr [g_walkCallback], eax
        cmp     eax, 0x11
        _emit   75h
        _emit   0ah
        mov     eax, 7
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     eax, dword ptr [g_walkCallback]
        inc     eax
        mov     dword ptr [g_walkCallback], eax
        call    Wrapper_0041fcf0
        call    DualBlockChainInitBody_0043cc10
        pop     esi
        ret
        mov     al, byte ptr [g_gtModeFlag]
        mov     ecx, dword ptr [g_audioBankSel]
        cmp     al, 1
        _emit   75h
        _emit   0bh
        cmp     ecx, 1
        _emit   75h
        _emit   06h
        inc     dword ptr [g_installSelfCounter_005433e8]
        cmp     al, 2
        _emit   75h
        _emit   0bh
        cmp     ecx, 2
        _emit   75h
        _emit   06h
        inc     dword ptr [g_installSelfCounter_005433e8]
        mov     dword ptr [g_walkCallback], 0xac
        call    ScaledLitLoadCall_00480fe0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   4fh
        call    GateDispatch6c_00494580
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   41h
        call    ScaledMove48to58_00490720
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   33h
        call    CallPauseScaledStoreCopyJmp_00461220
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   25h
        mov     dword ptr [esi + 8], 0x00467d40
        mov     dword ptr [esi + 0x84], 1
        mov     dword ptr [g_pendingNodeType], 8
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    }
}
