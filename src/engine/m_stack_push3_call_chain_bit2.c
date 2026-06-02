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

extern void MStackPush3CallChainBit2(void);
extern void MStackPush1MagicMod2(void);
extern unsigned int g_dispatchSave682;

/* @addr 0x00442740 (311b game) - field-setup with chain init + Mul10 ops + multi-field bulk store.
 *   Save [baseSel*4+0x64] to g_eventQueueEnd, [baseSel*4+0x68] to g_eventQueueIdx.
 *   g_eventQueueTotal = (0x004e5a00 >> 2). Call MStackPush3CallChainBit2; if pause ret. If bit2(0054208c) ret.
 *   chain[scaledInit*4+0x30]=0x94; eax = chain[+0x64] - 0x5b333; g_eventQueueWorkType=eax.
 *   Call MStackPush1MagicMod2; if pause ret.
 *   Mul10Tail(0x247, g_eventQueueCurrent) -> g_eventQueueCurrent.
 *   Mul10Tail(g_eventQueueWorkType, g_walkCallback) -> g_walkCallback.
 *   ecx=g_eventQueueCurrent; if (g_cj[+0x34] & 1): keep, else neg ecx.
 *   chain at [scaledInit*4]: +0x6c=ecx, +0x70=-19660, +0x74=g_walkCallback, +0x4c=0x20c,
 *     +0x60=0x1e666, +0x78=0, +0x7c=0x51e, +0x80=0x28f.
 *   g_walkCallback=0x28f. ret.
 */

void ChainInitMul10BulkStore(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, dword ptr [eax*4 + 0x64]
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     edx, dword ptr [eax*4 + 0x68]
        mov     eax, offset g_dispatchSave682
        mov     dword ptr [g_eventQueueIdx], edx
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        call    MStackPush3CallChainBit2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0f8h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   0fh
        _emit   85h
        _emit   0ebh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, 0x94
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [edx*4 + 0x64]
        sub     eax, 0x5b333
        mov     dword ptr [g_eventQueueWorkType], eax
        call    MStackPush1MagicMod2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0abh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [g_eventQueueWorkType], 0x247
        push    ecx
        push    0x247
        call    Mul10Tail
        mov     edx, dword ptr [g_walkCallback]
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     eax, dword ptr [g_eventQueueWorkType]
        push    edx
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_walkCallback], eax
        add     esp, 8
        mov     edx, dword ptr [ecx*4 + 0x34]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        and     edx, 1
        mov     dword ptr [g_eventQueueWorkType], edx
        _emit   74h
        _emit   08h
        neg     ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        shl     eax, 2
        mov     dword ptr [eax + 0x6c], ecx
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x74], ecx
        mov     ecx, 0x28f
        mov     dword ptr [eax + 0x70], 0xffffb334
        mov     dword ptr [eax + 0x4c], 0x20c
        mov     dword ptr [eax + 0x60], 0x1e666
        mov     dword ptr [eax + 0x78], 0
        mov     dword ptr [eax + 0x7c], 0x51e
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x80], ecx
        }
}

