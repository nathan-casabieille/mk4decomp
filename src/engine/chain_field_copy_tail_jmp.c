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

/* @addr 0x00466e70 (325b game) - quad-call chain + chain-field copy (g_eventQueueEnd -> g_cj_0054205c) + tail-jmp.
 *   g_walkCallback=2; call DirtyDoubleDeref. If pause ret.
 *   g_xformEntityIdx = [scaledInit*4 + 0x24]. Call MStackPushDispatchBitGate. If pause ret.
 *   If bit2(0054208c) ret. Call MStackPushTwoEntryChainCall. If pause ret. Call MStackCall_MStackPush2ChainPrepend_004062f0. If pause ret.
 *   Copy chain entries from [g_eventQueueEnd*4]+offset to [g_cj_0054205c*4]+offset:
 *     +0x54 (raw), +0x58 (subtract 0x9999), +0x5c, +0x60, +0x64, +0x68 (raw).
 *   chain[+0x34] ^= 1; copy chain[+0x3c]. Load chain[+0x18] into g_scaledInit.
 *   Zero chain[scaledInit*4 + 0x30/+0x34/+0x38]. Tail-jmp SetupVecFsmCluster. ret.
 */
extern void DirtyDoubleDeref(void);
extern void MStackCall_MStackPush2ChainPrepend_004062f0(void);
extern void MStackPushDispatchBitGate(void);
extern void MStackPushTwoEntryChainCall(void);
extern void SetupVecFsmCluster(void);

__declspec(naked) void ChainFieldCopyTailJmp(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 2
        call    DirtyDoubleDeref
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   28h
        _emit   01h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    MStackPushDispatchBitGate
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   04h
        _emit   01h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   0fh
        _emit   85h
        _emit   0f7h
        _emit   00h
        _emit   00h
        _emit   00h
        call    MStackPushTwoEntryChainCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0e5h
        _emit   00h
        _emit   00h
        _emit   00h
        call    MStackCall_MStackPush2ChainPrepend_004062f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d3h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     edx, dword ptr [g_cj_0054205c]
        shl     ecx, 2
        lea     eax, [edx*4 + 0]
        mov     edx, dword ptr [ecx + 0x54]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x54], edx
        mov     edx, dword ptr [ecx + 0x58]
        sub     edx, 0x9999
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x58], edx
        mov     edx, dword ptr [ecx + 0x5c]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x5c], edx
        mov     edx, dword ptr [ecx + 0x60]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x60], edx
        mov     edx, dword ptr [ecx + 0x64]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x64], edx
        mov     edx, dword ptr [ecx + 0x68]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x68], edx
        mov     ecx, dword ptr [ecx + 0x34]
        xor     ecx, 1
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x34], ecx
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [edx*4 + 0x3c]
        mov     edx, dword ptr [g_cj_0054205c]
        mov     dword ptr [edx*4 + 0x3c], ecx
        mov     eax, dword ptr [eax + 0x18]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax*4 + 0x30], 0
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x34], eax
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x38], edx
        jmp     SetupVecFsmCluster
        ret
    }
}
