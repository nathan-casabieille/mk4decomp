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

/* @addr 0x0043cb00 (262b game) - guarded cascade then 4-field cj copy with bit-OR.
 *   g_xformEntityIdx = 0x0050d434>>2; call MStackPushDispatchBitGate; if pause? final-ret.
 *   if bit2 of g_xformDirtyFlags set: tail-jmp ScaledInitWithCounterAndType_004314f0.
 *   g_cj_0054205c = g_scaledInit_00542044. call MStackPushTwoEntryChainCall; if pause? final-ret.
 *   call MStackCall_00406340; if pause? final-ret.
 *   Clear cj[+0x5c] and g_eventQueueNotMask. cj[+0x64] = g_eventQueueIdx[+0x64].
 *   cj[+0x34] = (cj[+0x34] & 0xfe) | (g_eventQueueIdx[+0x34] & 1) | 0x81000.
 *   cj[+0x3c] = g_particleEmitterNode. cj[+0x54] = g_eventQueueEnd[+0x54].
 */
extern unsigned int g_particleEmitterNode;
extern void MStackCall_00406340(void);
extern void MStackPushDispatchBitGate(void);
extern void MStackPushTwoEntryChainCall(void);
extern void ScaledInitWithCounterAndType_004314f0(void);

__declspec(naked) void GuardedCascadeCjCopyFieldsBitOr(void) {
    __asm {
        mov     eax, 0x0050d434
        sar     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    MStackPushDispatchBitGate
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0e6h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   05h
        jmp     ScaledInitWithCounterAndType_004314f0
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_cj_0054205c], ecx
        call    MStackPushTwoEntryChainCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0bah
        _emit   00h
        _emit   00h
        _emit   00h
        call    MStackCall_00406340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0a8h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     edx, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_eventQueueNotMask], 0
        mov     dword ptr [edx*4 + 0x5c], 0
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [eax*4 + 0x64]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x64], eax
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [edx*4 + 0x34]
        mov     edx, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_eventQueueCurrent], ecx
        and     ecx, 1
        mov     eax, dword ptr [edx*4 + 0x34]
        mov     dword ptr [g_eventQueueCurrent], ecx
        and     al, 0xfe
        or      eax, ecx
        or      eax, 0x00081000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x34], eax
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [g_particleEmitterNode]
        mov     dword ptr [eax*4 + 0x3c], ecx
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [edx*4 + 0x54]
        mov     dword ptr [g_acc_00542078], eax
        mov     dword ptr [ecx*4 + 0x54], eax
        ret
    }
}
