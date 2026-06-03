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

extern void Phase1ChainExtendedInitLoop(void);
extern void ScaledIndirectJmp_0049c850(void);
extern void BootOneShotSetup(void);
extern void PendingMatch_MStackPush8_0040a8d0(void);
extern void GuardedSeq_MStackCall_then_CallSetPause_0049c340(void);

/* @addr 0x0049c220 (274b game) - three adjacent blocks.
 *   B1 (0..0x7f): 2x Mul10Tail with 0x3333 mod for g_currentNodeFlags/g_xformScratch2088;
 *     store results to scaledInit[+0x6c/+0x74]; g_cj_0054205c = scaledInit;
 *     baseSel[+0x5c]=0x30; baseSel[+0x74]=1; ret.
 *   B2 (0x80..0xe3, +12 NOPs): dec baseSel[+0x74] (clamp to 3 if was 0); if
 *     orig was 0: call Phase1ChainExtendedInitLoop. If !pause: dec baseSel[+0x5c]; if was 0:
 *     tail-jmp ScaledIndirectJmp_0049c850. ret.
 *   B3 (0xf0..0x111): call BootOneShotSetup; if !pause: call PendingMatch_MStackPush8_0040a8d0;
 *     if !pause: tail-jmp GuardedSeq_MStackCall_then_CallSetPause_0049c340; ret.
 */
extern unsigned int g_bootInitSaveSlot;

__declspec(naked) void DualMul10AndDispatchChain(void) {
    __asm {
        mov     edx, dword ptr [g_currentNodeFlags]
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_baseSel]
        push    esi
        push    edi
        push    edx
        push    0x3333
        lea     esi, [eax*4 + 0]
        lea     edi, [ecx*4 + 0]
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_currentNodeFlags], eax
        mov     eax, dword ptr [g_xformScratch2088]
        push    eax
        push    0x3333
        call    Mul10Tail
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [g_xformScratch2088], eax
        mov     dword ptr [esi + 0x6c], ecx
        mov     edx, dword ptr [g_xformScratch2088]
        mov     dword ptr [esi + 0x74], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_cj_0054205c], eax
        mov     eax, 1
        add     esp, 8
        mov     dword ptr [edi + 0x5c], 0x30
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edi + 0x74], eax
        pop     edi
        pop     esi
        ret
        nop
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x74]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_bootInitSaveSlot], eax
        _emit   75h
        _emit   0ah
        mov     eax, 3
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x74], eax
        mov     eax, dword ptr [g_bootInitSaveSlot]
        test    eax, eax
        _emit   75h
        _emit   0eh
        call    Phase1ChainExtendedInitLoop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   21h
        mov     ecx, dword ptr [g_baseSel]
        mov     eax, dword ptr [ecx*4 + 0x5c]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x5c], eax
        _emit   75h
        _emit   05h
        jmp     ScaledIndirectJmp_0049c850
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
        call    BootOneShotSetup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    PendingMatch_MStackPush8_0040a8d0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     GuardedSeq_MStackCall_then_CallSetPause_0049c340
        ret
    }
}
