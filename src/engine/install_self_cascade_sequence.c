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

/* @addr 0x00434350 (325b game) - install-self + cascade-call sequence + tail jmp.
 *   state!=0: tail-call MStackPushPtr1Jmp; pop+ret.
 *   state==0: call Cmp2CallDirtyCall; if !=0 ret.
 *   Call StoreCallPauseDirtyStoreJmp; if pause ret.
 *   If !bit0(0054208c): tail-call GuardedSeq; pop+ret.
 *   g_currentNodeFlags=0x78000; install-self at entry+0x01000000; state=1; call EsiInstallTwoCallCmpInstall; pause=1; ret.
 *   Tail (+0xc0, 1-NOP pad): set g_dispatchState=0; call InstallSelfCountdownCascade; if pause ret.
 *     If [0053a478]!=0 ret; call Cmp2CallDirtyCall; if !=0 ret.
 *     If [baseSel*4+0x34]!=0: jmp InstallSelfThreeStateLeaPlus22.
 *     Else: g_walkCallback=0x1f4; call AudioVolumeRescale; if pause ret.
 *       If bit0(0054208c): jmp InstallSelfChainSetB333v3 (0x00437fb0).
 *       Else: g_eventQueueNotMask=0x10028; jmp HitReactionDispatcher.
 *   Tail (+0x140 after 6-NOP pad): jmp InstallSelfChainSetB333v2.
 */
extern unsigned int g_dispatchState;
extern void AudioVolumeRescale(void);
extern void EsiInstallTwoCallCmpInstall(void);
extern void GuardedSeq_PackedSelectLoad6_then_GuardedSeq(void);
extern void HitReactionDispatcher(void);
extern void InstallSelfChainSetB333v2(void);
extern void InstallSelfChainSetB333v3(void);
extern void InstallSelfCountdownCascade(void);
extern void InstallSelfThreeStateLeaPlus22(void);
extern void MStackPushPtr1Jmp_00438e70(void);
extern void StoreCallPauseDirtyStoreJmp(void);

__declspec(naked) void InstallSelfCascadeSequence(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        test    eax, eax
        _emit   74h
        _emit   07h
        call    MStackPushPtr1Jmp_00438e70
        pop     esi
        ret
        call    Cmp2CallDirtyCall
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   87h
        _emit   00h
        _emit   00h
        _emit   00h
        call    StoreCallPauseDirtyStoreJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   79h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   75h
        _emit   07h
        call    GuardedSeq_PackedSelectLoad6_then_GuardedSeq
        pop     esi
        ret
        mov     dword ptr [g_currentNodeFlags], 0x78000
        mov     dword ptr [esi + 8], offset InstallSelfCascadeSequence
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, offset InstallSelfCascadeSequence
        add     edx, 0x01000000
        mov     dword ptr [ecx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [eax*4 + 0], edx
        mov     eax, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], 0
        call    EsiInstallTwoCallCmpInstall
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
        _emit   90h
        mov     dword ptr [g_dispatchState], 0
        call    InstallSelfCountdownCascade
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   61h
        mov     eax, dword ptr [g_dispatchState]
        test    eax, eax
        _emit   75h
        _emit   58h
        call    Cmp2CallDirtyCall
        test    eax, eax
        _emit   75h
        _emit   4fh
        mov     eax, dword ptr [g_baseSel]
        mov     eax, dword ptr [eax*4 + 0x34]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   05h
        jmp     InstallSelfThreeStateLeaPlus22
        mov     dword ptr [g_walkCallback], 0x1f4
        call    AudioVolumeRescale
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1dh
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     InstallSelfChainSetB333v3
        mov     dword ptr [g_eventQueueNotMask], 0x10028
        jmp     HitReactionDispatcher
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        jmp     InstallSelfChainSetB333v2
    }
}
