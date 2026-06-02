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

extern void SfxAttenuateAndApply(void);
extern void ScaledIndexConditionalAdd(void);
extern void InstallSelfCascadingCalls_004806c0(void);
extern void DispatcherComplex131_00431530(void);
extern void TableLookupCall_00489ff0(void);

/* @addr 0x00480570 (333b game) - 3-state install-self with chain init + long state-0 sequence.
 *   state>=2: tail-call FiveCallGuardSetTail; pop+ret.
 *   state==1 (dec,je): chain[baseSel*4+0x74]=0; g_walkCallback=0x1eb8; call SfxAttenuateAndApply; if pause ret.
 *     g_walkCallback=8; call ScaledIndexConditionalAdd; if pause ret.
 *     Install-self at entry; state=2; g_pendingNodeType=0xe; pause=1; pop+ret.
 *   state==0: call MStackChainBit2Cascade_0048e8f0; if pause ret.
 *     If bit0(0054208c): tail-call InstallSelfCascadingCalls; pop+ret.
 *     Else: call ScaledZeroFour; if pause ret. g_walkCallback=5; call DispatcherComplex131_00431530; if pause ret.
 *     chain[baseSel*4+0x74]=0x1000; g_walkCallback=0x62; call ScaledLitLoadCall_00480fe0; if pause ret.
 *     g_walkCallback=0x3e; call TableLookupCall_00489ff0; if pause ret.
 *     Install-self at entry; state=1; g_pendingNodeType=0x33; pause=1; pop+ret.
 */
extern void FiveCallGuardSetTail(void);
extern void MStackChainBit2Cascade_0048e8f0(void);
extern void ScaledLitLoadCall_00480fe0(void);

__declspec(naked) void Install3StateLongSeq_00480570(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        lea     esi, [eax*4 + 0]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        _emit   83h
        _emit   0e8h
        _emit   00h
        _emit   74h
        _emit   7ah
        dec     eax
        _emit   74h
        _emit   07h
        call    FiveCallGuardSetTail
        pop     esi
        ret
        mov     ecx, dword ptr [g_baseSel]
        mov     dword ptr [ecx*4 + 0x74], 0
        mov     dword ptr [g_walkCallback], 0x1eb8
        call    SfxAttenuateAndApply
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0f1h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     dword ptr [g_walkCallback], 8
        call    ScaledIndexConditionalAdd
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d5h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     dword ptr [esi + 8], offset Install3StateLongSeq_00480570
        mov     dword ptr [esi + 0x84], 2
        mov     dword ptr [g_pendingNodeType], 0xe
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
        call    MStackChainBit2Cascade_0048e8f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   9ch
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   07h
        call    InstallSelfCascadingCalls_004806c0
        pop     esi
        ret
        call    ScaledZeroFour
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   7eh
        mov     dword ptr [g_walkCallback], 5
        call    DispatcherComplex131_00431530
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   66h
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x74], 0x1000
        mov     dword ptr [g_walkCallback], 0x62
        call    ScaledLitLoadCall_00480fe0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   3dh
        mov     dword ptr [g_walkCallback], 0x3e
        call    TableLookupCall_00489ff0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   25h
        mov     dword ptr [esi + 8], offset Install3StateLongSeq_00480570
        mov     dword ptr [esi + 0x84], 1
        mov     dword ptr [g_pendingNodeType], 0x33
        mov     dword ptr [g_framePauseFlag], 1
        pop     esi
        ret
    }
}
