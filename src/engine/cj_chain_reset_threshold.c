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

/* @addr 0x00490cc0 (315b game) - cj-chain validate + indirect callback + threshold check + chain reset.
 *   If g_cj==0: ret. If [cj*4+0x44]!=0: indirect call; if pause ret. If [cj*4+0x4c]!=0: add to [cj*4+0x70].
 *   If negative: ret. Validate threshold via scaledInit chain.
 *   Zero out chain entries 0x6c/0x70/0x74/0x78/0x7c/0x80/0x4c; sync. Select 538038/53803c.
 *   Call ScaledLoadJmpIfNonzero; pop edi/esi; ret.
 */
extern void ScaledLoadJmpIfNonzero(void);

__declspec(naked) void CjChainResetThreshold(void) {
    __asm {
        mov     ecx, dword ptr [g_cj_0054205c]
        push    esi
        xor     esi, esi
        push    edi
        cmp     ecx, esi
        _emit   0fh
        _emit   84h
        _emit   26h
        _emit   01h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [ecx*4 + 0x44]
        cmp     eax, esi
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   19h
        mov     dword ptr [g_scaledInit_00542044], eax
        call    eax
        cmp     dword ptr [g_framePauseFlag], esi
        _emit   0fh
        _emit   85h
        _emit   03h
        _emit   01h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [ecx*4 + 0x4c]
        cmp     eax, esi
        mov     dword ptr [g_eventQueueCurrent], eax
        _emit   0fh
        _emit   84h
        _emit   0e9h
        _emit   00h
        _emit   00h
        _emit   00h
        add     eax, dword ptr [ecx*4 + 0x70]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x70], eax
        _emit   0fh
        _emit   88h
        _emit   0d0h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_cj_0054205c]
        mov     eax, dword ptr [ecx*4 + 0x18]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [eax*4 + 0x34]
        mov     dword ptr [g_acc_00542078], edx
        mov     edi, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_eventQueueCurrent], edi
        mov     eax, dword ptr [ecx*4 + 0x58]
        add     eax, edx
        mov     edx, dword ptr [g_walkCallback]
        add     eax, edx
        cmp     eax, edi
        mov     dword ptr [g_eventQueueWorkType], eax
        _emit   0fh
        _emit   8ch
        _emit   86h
        _emit   00h
        _emit   00h
        _emit   00h
        lea     eax, [ecx*4 + 0]
        mov     ecx, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [eax + 0x6c], esi
        mov     dword ptr [eax + 0x70], esi
        mov     dword ptr [eax + 0x74], esi
        mov     dword ptr [eax + 0x78], esi
        mov     dword ptr [eax + 0x7c], esi
        mov     dword ptr [eax + 0x80], esi
        mov     dword ptr [eax + 0x4c], esi
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x58], ecx
        mov     eax, dword ptr [g_cj_0054205c]
        mov     dword ptr [g_eventQueueCurrent], esi
        mov     eax, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0x34]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0x34], esi
        mov     eax, dword ptr [g_cj_0054205c]
        mov     ecx, dword ptr [g_player1NodeIdx]
        mov     edx, dword ptr [g_gtPlayerProbe2]
        cmp     eax, ecx
        mov     dword ptr [g_xformEntityIdx], edx
        _emit   74h
        _emit   0ch
        mov     ecx, dword ptr [g_gtPlayerProbe1]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    ScaledLoadJmpIfNonzero
        pop     edi
        pop     esi
        ret
    }
}
