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

/*
 * AudioInitLoopTriple - 237b audio 2-entry init + triple-loop body.
 *   Entry 0x004a7840: g_xformEntityIdx = (0x0050f114 >> 2); call DispatcherComplex260;
 *     if paused: ret. push 0x13333; SnapshotDirtyMark; MStackPushComplexCallPop;
 *     if paused: ret. chain[g_currentNodeIdx*4 + 0x5c] = 0x00100000; ret.
 *   16b-aligned body 0x004a7890: g_eventQueueWorkType = 0x32a; Push16Call.
 *     Loop1 (esi: byte-table at 0x004f3b48 to 0x004f3c20 step 0x24): chain[(g_baseSel+byte)*4],
 *       call MStackPush2ChainLLInsert. Loop2 (esi 0..5): chain[(g_baseSel+esi)*4 + 0x34], call.
 *     Loop3 (esi 0..5): chain[(g_baseSel+esi)*4 + 0x48], call. DrainQueueCallEach.
 *     if [0x005433f4] == 2: tail-call PendingMatch_004a8ca0 else AudioInstallSelfStateMachine2.
 */
extern unsigned int g_audioInstallArr;
extern unsigned int g_audioMicroEntry;
extern void AudioInstallSelfStateMachine2(void);
extern void DrainQueueCallEach(void);
extern void MStackPush2ChainLLInsert(void);
extern void MStackPushComplexCallPop_00406430(void);
extern void PendingMatch_004a8ca0(void);
extern void SnapshotDirtyMark(void);

__declspec(naked) void AudioInitLoopTriple(void)
{
    __asm
    {
        mov     eax, offset g_audioInstallArr
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    DispatcherComplex260_00407400
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_e0_ret
        push    0x13333
        call    SnapshotDirtyMark
        add     esp, 4
        call    MStackPushComplexCallPop_00406430
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_e0_ret
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [ecx*4 + 0x5c], 0x00100000
    L_e0_ret:
        ret
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        _emit   90h
        push    esi
        mov     dword ptr [g_eventQueueWorkType], 0x32a
        call    Push16Call
        mov     esi, 0x004f3b48
    L_loop1:
        movsx   eax, byte ptr [esi]
        mov     ecx, dword ptr [g_baseSel]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert
        add     esi, 0x24
        cmp     esi, 0x004f3c20
        jb      short L_loop1
        xor     esi, esi
    L_loop2:
        mov     eax, dword ptr [g_baseSel]
        lea     ecx, [esi + eax]
        mov     edx, dword ptr [ecx*4 + 0x34]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert
        inc     esi
        cmp     esi, 5
        jl      short L_loop2
        xor     esi, esi
    L_loop3:
        mov     eax, dword ptr [g_baseSel]
        lea     ecx, [esi + eax]
        mov     edx, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert
        inc     esi
        cmp     esi, 5
        jl      short L_loop3
        call    DrainQueueCallEach
        cmp     dword ptr [g_audioMicroEntry], 2
        jne     short L_tail85c0
        call    PendingMatch_004a8ca0
        pop     esi
        ret
    L_tail85c0:
        call    AudioInstallSelfStateMachine2
        pop     esi
        ret
    }
}
