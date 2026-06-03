/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
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
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
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
extern void PendingMatch_StoreTwoCall_0042b930(void);
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

extern void InstallSelfDualBranchInit(void);
extern void TableWalkBoundedCmp(int);
extern void IncOrZero9(void);
extern void DispatchPair(void);
extern void SceneEvalFsm(void);
extern unsigned int g_counter_0053a51c;
extern unsigned int g_dispatchVar9;

/* @addr 0x004200d0 (200b game) - install-self gate w/ pre-call sequence and packed_ptr store.
 *   esi = base*4; edi=0; snapshot [esi+0x84]; clear via edi.
 *   if (snap == 0): go to main path; else: call InstallSelfDualBranchInit; pop edi; pop esi; ret.
 *   Main: push 8, call TableWalk; add esp, 4; call IncOrZero9; pause? -> epilogue;
 *   g_walkCallback = [0x53a51c]; call DispatchPair; pause? -> epilogue;
 *   g_walkCallback = 0; g_dispatchVar9 = 0; install self with chain[+0x84]=1, packed ptr store,
 *   g_scaledInit++; chain[+0x84] = 0; call SceneEvalFsm; g_framePauseFlag = 1.
 */

extern unsigned int g_matrixStack_arr;

__declspec(naked) void InstallSelfTableWalk(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        push    edi
        xor     edi, edi
        lea     esi, [eax*4 + g_matrixStack_arr]
        mov     eax, [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], edi
        cmp     eax, edi
        _emit   74h
        _emit   08h
        call    InstallSelfDualBranchInit
        pop     edi
        pop     esi
        ret
        push    8
        call    TableWalkBoundedCmp
        add     esp, 4
        call    IncOrZero9
        cmp     dword ptr [g_framePauseFlag], edi
        _emit   0fh
        _emit   85h
        _emit   81h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_counter_0053a51c]
        mov     dword ptr [g_walkCallback], ecx
        call    DispatchPair
        cmp     dword ptr [g_framePauseFlag], edi
        _emit   75h
        _emit   68h
        mov     dword ptr [g_walkCallback], edi
        mov     dword ptr [g_dispatchVar9], edi
        mov     dword ptr [esi + 8], 0x004200d0
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, 0x004200d0
        mov     dword ptr [edx*4 + 0x84], 1
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x01000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     [eax*4 + g_matrixStack_arr], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     [edx*4 + 0x84], edi
        call    SceneEvalFsm
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        pop     esi
        ret
    }
}
