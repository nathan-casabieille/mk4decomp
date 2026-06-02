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

/* @addr 0x00422fc0 (237b game) - 4-call guarded sequence ending with cj field set.
 *   call DownloadPlayerChar with g_eventQueueCurrent=2; if pause? ret.
 *   call GuardedDualPushTailJmp; if pause? ret.
 *   mstack-push g_scaledInit_00542044, call ScaledOr4DirtyClear, mstack-pop.
 *   cj[+0x30]=3, cj[+0x34] |= 0x1c0000.
 *   call TwoStateLookupDirty; if !pause: cj[+0x3c] = g_bootHeavyState; ret.
 */
extern u32 g_dlState;
extern u32 g_dlAux;
extern unsigned int g_bootHeavyState;
extern s32 g_dlNalt3;
extern s32 g_dlNalt4;
extern unsigned int g_particleInitState;
extern void DownloadPlayerChar(void);
extern void GuardedDualPushTailJmp(void);
extern void ScaledOr4DirtyClear(void);
extern void TwoStateLookupDirty(void);

void QuadGuardedCjSet_00422fc0(void) {
    __asm {
        mov     eax, dword ptr [g_dlNalt3]
        mov     dword ptr [g_eventQueueCurrent], 2
        mov     dword ptr [g_walkCallback], eax
        call    DownloadPlayerChar
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0c6h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_dlNalt3]
        mov     edx, dword ptr [g_dlState]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueCurrent], 2
        mov     dword ptr [g_eventQueueWorkType], edx
        call    GuardedDualPushTailJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   92h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_scaledInit_00542044], edx
        call    ScaledOr4DirtyClear
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, 3
        mov     dword ptr [g_player3NodeIdx], eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x30], ecx
        mov     eax, dword ptr [g_cj_0054205c]
        _emit   81h
        _emit   0ch
        _emit   85h
        _emit   34h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   00h
        _emit   1ch
        _emit   00h
        call    TwoStateLookupDirty
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   17h
        mov     eax, dword ptr [g_bootHeavyState]
        mov     edx, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x3c], eax
        }
}

/* @addr 0x004230b0 (246b game) - 4-call guarded sequence (sibling of 0x00422fc0).
 *   Set up locals (g_eventQueueCurrent=3, g_walkCallback=g_dlNalt4); call DownloadPlayerChar.
 *   If pause? ret. Reload then call GuardedDualPushTailJmp. If pause? ret.
 *   mstack-push g_scaledInit_00542044; call ScaledOr4DirtyClear; mstack-pop;
 *   set cj[+0x30]=4 + cj[+0x34] |= 0x1c0001; call TwoStateLookupDirty;
 *   if pause? ret; else cj[+0x3c] = g_particleInitState; ret.
 */
void QuadGuardedCjSet_004230b0(void) {
    __asm {
        mov     eax, dword ptr [g_dlNalt4]
        mov     dword ptr [g_eventQueueCurrent], 3
        mov     dword ptr [g_walkCallback], eax
        call    DownloadPlayerChar
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0cfh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_dlNalt4]
        mov     edx, dword ptr [g_dlAux]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_eventQueueCurrent], 3
        mov     dword ptr [g_eventQueueWorkType], edx
        call    GuardedDualPushTailJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   9bh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_scaledInit_00542044], edx
        call    ScaledOr4DirtyClear
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, 4
        mov     dword ptr [g_player4NodeIdx], eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x30], ecx
        call    TwoStateLookupDirty
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   30h
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [eax*4 + 0x34]
        or      ecx, 0x001c0001
        mov     dword ptr [eax*4 + 0x34], ecx
        mov     eax, dword ptr [g_particleInitState]
        mov     edx, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x3c], eax
        }
}

