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

extern void EntryThunkBodyStateMachine(void);
extern void AerialPunchCluster(void);
extern void EsiInstallDecCallChain_004294a0(void);

/* @addr 0x0047baf0 (305b game) - state-machine: 4-arm dispatcher with shared common-tail call.
 *   Load state; clear. If state!=0: scaledInit=[baseSel*4+0x3c]; inc [scaledInit*4+0x7c] -> g_walkCallback.
 *     g_eventQueueNotMask=0; call EntryThunkBodyStateMachine; if pause ret.
 *     g_walkCallback=0x5f; call ScaledLitLoadCall; if pause ret. Tail-call AerialPunchCluster; pop+ret.
 *   state==0: g_eventQueueNotMask=0; call EntryThunkBodyStateMachine; if pause ret.
 *     If g_xformScratch2088==1: tail-call AerialPunchCluster; pop+ret.
 *     Else: call MStackPush3CmpCall; if pause ret.
 *     If bit0(0054208c) set: tail-call AerialPunchCluster; pop+ret.
 *     Else: g_eventQueueChild=6; install-self at entry+0x01000000; call EsiInstallDecCallChain;
 *     pause=1; pop edi/esi/ebx; ret.
 */
extern void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void);

__declspec(naked) void StateMachineSharedTail(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        push    edi
        lea     esi, [eax*4 + 0]
        xor     edi, edi
        mov     eax, dword ptr [esi + 0x84]
        mov     dword ptr [esi + 0x84], edi
        cmp     eax, edi
        _emit   74h
        _emit   62h
        mov     ecx, dword ptr [g_baseSel]
        mov     ecx, dword ptr [ecx*4 + 0x3c]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     eax, dword ptr [ecx*4 + 0x7c]
        inc     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x7c], eax
        mov     dword ptr [g_eventQueueNotMask], edi
        call    EntryThunkBodyStateMachine
        cmp     dword ptr [g_framePauseFlag], edi
        _emit   0fh
        _emit   85h
        _emit   0ceh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     dword ptr [g_walkCallback], 0x5f
        call    ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0
        cmp     dword ptr [g_framePauseFlag], edi
        _emit   0fh
        _emit   85h
        _emit   0b3h
        _emit   00h
        _emit   00h
        _emit   00h
        call    AerialPunchCluster
        pop     edi
        pop     esi
        pop     ebx
        ret
        mov     dword ptr [g_eventQueueNotMask], edi
        call    EntryThunkBodyStateMachine
        cmp     dword ptr [g_framePauseFlag], edi
        _emit   0fh
        _emit   85h
        _emit   93h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_xformScratch2088]
        mov     ebx, 1
        cmp     eax, ebx
        _emit   75h
        _emit   09h
        call    AerialPunchCluster
        pop     edi
        pop     esi
        pop     ebx
        ret
        call    MStackPush3CmpCall
        cmp     dword ptr [g_framePauseFlag], edi
        _emit   75h
        _emit   6fh
        _emit   84h
        _emit   1dh
        _emit   8ch
        _emit   20h
        _emit   54h
        _emit   00h
        _emit   74h
        _emit   09h
        call    AerialPunchCluster
        pop     edi
        pop     esi
        pop     ebx
        ret
        mov     dword ptr [g_eventQueueChild], 6
        mov     dword ptr [esi + 8], offset StateMachineSharedTail
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, offset StateMachineSharedTail
        add     ecx, 0x01000000
        mov     dword ptr [edx*4 + 0x84], ebx
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], edi
        call    EsiInstallDecCallChain_004294a0
        mov     dword ptr [g_framePauseFlag], ebx
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
