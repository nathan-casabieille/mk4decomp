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

/* @addr 0x00494670 (219b game) - 2-call cascade + state-based chain selection + indirect call.
 *   call ScaledLoadCmp0fJmp; if !pause: call MStackBitFlagDispatch; if !pause:
 *   pick chain from 0x0053a3e4>>2 or 0x0053a474>>2 based on g_fightGroupHead==g_player1NodeIdx;
 *   g_walkCallback=[chain*4+0]; scaledInit=baseSel[*4+0x3c]; g_eventQueueCurrent=[scaledInit*4+0x7c];
 *   if > 3: ecx=0x4ccc, g_walkCallback=ecx; store ecx to [chain*4+0].
 *   eax = baseSel[*4+0x30]; scaledInit=eax; ecx=[eax*4+0]; sub 0x60;
 *   eax = ecx + 0x004f1b28>>2; scaledInit=eax; eax=[eax*4+0]; scaledInit=eax; call eax. ret.
 */
extern void MStackBitFlagDispatch(void);
extern void ScaledLoadCmp0fJmp(void);

__declspec(naked) void StateChainIndirect(void) {
    __asm {
        call    ScaledLoadCmp0fJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0c8h
        _emit   00h
        _emit   00h
        _emit   00h
        call    MStackBitFlagDispatch
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0b6h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     edx, dword ptr [g_fightGroupHead]
        push    esi
        mov     esi, dword ptr [g_player1NodeIdx]
        mov     ecx, 0x0053a3e4
        mov     eax, 0x0053a474
        shr     ecx, 2
        shr     eax, 2
        cmp     edx, esi
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_xformEntityIdx], eax
        _emit   74h
        _emit   07h
        mov     eax, ecx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     ecx, dword ptr [eax*4 + 0]
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [edx*4 + 0x3c]
        mov     dword ptr [g_currentNodeIdx], edx
        mov     edx, dword ptr [edx*4 + 0x7c]
        cmp     edx, 3
        mov     dword ptr [g_eventQueueCurrent], edx
        _emit   7eh
        _emit   0bh
        mov     ecx, 0x00004ccc
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_baseSel]
        mov     eax, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_currentNodeIdx], eax
        mov     ecx, dword ptr [eax*4 + 0]
        mov     eax, 0x004f1b28
        sub     ecx, 0x60
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0]
        mov     dword ptr [g_currentNodeIdx], eax
        call    eax
        pop     esi
        ret
    }
}
