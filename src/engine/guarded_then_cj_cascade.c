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

/* @addr 0x0047d560 (231b game) - two blocks (+13 NOPs padding).
 *   B1 (0..66): clear g_eventQueueNotMask; call EntryThunkBodyStateMachine; if !pause: set
 *     g_walkCallback=0x13; call TableLookupCall; push 0x004ed420; call
 *     ScaledDualPropagateJmp; if !pause: tail-jmp FiveCallGuardSetTail; ret.
 *   B2 (80..230): read cj[+0x58]; if eax<0x9999: select g_gtPlayerProbe2 or
 *     [0053803c] based on edx == g_player1NodeIdx; copy [+0x5c]/[+0x60]; clear
 *     cj[+0x58] = 0xfffc0000; set cj[+0x4c] = 0xa3d; tail-jmp ScaledZero44.
 */
extern void EntryThunkBodyStateMachine(void);
extern void FiveCallGuardSetTail(void);
extern void ScaledDualPropagateJmp(void);
extern void ScaledZero44(void);
extern void TableLookupCall_00489f60(void);

__declspec(naked) void GuardedThenCjCascade(void) {
    __asm {
        mov     dword ptr [g_eventQueueNotMask], 0
        call    EntryThunkBodyStateMachine
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2ah
        mov     dword ptr [g_walkCallback], 0x13
        call    TableLookupCall_00489f60
        push    0x004ed420
        call    ScaledDualPropagateJmp
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     FiveCallGuardSetTail
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
        mov     edx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [edx*4 + 0x58]
        cmp     eax, 0x9999
        mov     dword ptr [g_walkCallback], eax
        _emit   7ch
        _emit   7dh
        mov     ecx, dword ptr [g_player1NodeIdx]
        mov     eax, dword ptr [g_gtPlayerProbe2]
        cmp     edx, ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   74h
        _emit   0ah
        mov     eax, dword ptr [g_gtPlayerProbe1]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0x5c]
        mov     dword ptr [g_walkCallback], ecx
        mov     eax, dword ptr [eax*4 + 0x60]
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [edx*4 + 0x54], ecx
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [ecx*4 + 0x5c], edx
        mov     eax, dword ptr [g_cj_0054205c]
        _emit   0c7h
        _emit   04h
        _emit   85h
        _emit   58h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   0fch
        _emit   0ffh
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, 0xa3d
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x4c], eax
        jmp     ScaledZero44
        ret
    }
}
