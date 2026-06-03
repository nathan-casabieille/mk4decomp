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

/* @addr 0x0045f310 (303b game) - arg-table indexed setup with conditional double-init + bitmask result.
 *   Init: eax=[esp+4]>>2; g_eventQueueTotal=eax. Load 4 from [eax*4+0]: g_eventQueueWorkType, g_acc, g_eventQueueNotMask, g_eventQueueChild.
 *   Load g_player1NodeIdx into g_scaledInit. If g_cj_0054205c==ecx (538158): skip second-init, jmp call.
 *   Else load 4 more from [eax*4+0] into same globals. Call NotMaskStorePair.
 *   If pause: ret. Compute (g_walkCallback & g_eventQueueNotMask) and (g_eventQueueCurrent & g_eventQueueChild).
 *   If g_dispatchVar != 0: jmp set-bit branch (or al,1).
 *   Else: cmp g_eventQueueWorkType with eax (g_walkCallback & 7c).
 *     If equal: cmp g_acc with ecx. If equal: set bit. Else clear bit. Ret.
 *     If first not equal: clear bit, ret.
 */
extern unsigned int g_dispatchVar;
extern void NotMaskStorePair(void);

void ArgIndexedBitmaskInit(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        sar     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     edx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_acc_00542078], edx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     ecx, dword ptr [g_player1NodeIdx]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_eventQueueChild], edx
        mov     edx, dword ptr [g_cj_0054205c]
        inc     eax
        cmp     edx, ecx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [g_currentNodeIdx], ecx
        _emit   74h
        _emit   4ch
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     edx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_acc_00542078], edx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     edx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_eventQueueChild], edx
        mov     dword ptr [g_eventQueueTotal], eax
        call    NotMaskStorePair
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   66h
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_eventQueueNotMask]
        mov     edx, dword ptr [g_eventQueueChild]
        and     eax, ecx
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [g_walkCallback], eax
        and     ecx, edx
        mov     edx, dword ptr [g_dispatchVar]
        test    edx, edx
        mov     dword ptr [g_eventQueueCurrent], ecx
        _emit   75h
        _emit   2ah
        cmp     dword ptr [g_eventQueueWorkType], eax
        _emit   74h
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        cmp     dword ptr [g_acc_00542078], ecx
        _emit   74h
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        }
}

