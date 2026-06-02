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
extern void GuardedDispatch_InstallSelfDualEsi(void);
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

/* @addr 0x004251f0 (207b game) - 3-iter loop computing |a-b| diffs then clamping
 * to thresholds in [004d5320..0x4d5328], storing to scaledInit table.
 *   esi=2, edi=3; loop iterates 3 times (jne after dec edi).
 *   per iter: a=arr1[i], b=arr2[j], diff=a-b; |diff|<=thr ? 1 : 0; clamp uses 004d5328;
 *   advance indices, write diff to scaledInit[k]*4, k++.
 *   end: store esi (=-1) to [0x0053a1ac]; rewind 3 indices.
 */
extern unsigned int g_dispatchSave895;
extern unsigned int g_pendingMatchVar;
extern unsigned int g_pendingMatchVar3;
extern unsigned int g_eq;

__declspec(naked) void TripleArrayDiffClamp(void) {
    __asm {
        push    ebx
        push    esi
        push    edi
        mov     esi, 2
        mov     edi, 3
loop_004251fd:
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_pendingNodeType]
        mov     eax, dword ptr [ecx*4 + 0]
        mov     ebx, dword ptr [edx*4 + 0]
        sub     eax, ebx
        inc     edx
        inc     ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_pendingNodeType], edx
        test    eax, eax
        mov     ecx, eax
        _emit   7dh
        _emit   02h
        neg     ecx
        mov     ebx, dword ptr [g_pendingMatchVar3]
        xor     edx, edx
        cmp     ecx, ebx
        mov     ecx, dword ptr [g_pendingMatchVar]
        setle   dl
        test    eax, eax
        mov     dword ptr [g_eq], edx
        mov     dword ptr [g_walkCallback], ecx
        _emit   7ch
        _emit   0ch
        mov     ecx, dword ptr [g_dispatchSave895]
        mov     dword ptr [g_walkCallback], ecx
        test    edx, edx
        _emit   75h
        _emit   07h
        add     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [ecx*4 + 0], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        inc     edx
        dec     esi
        dec     edi
        mov     dword ptr [g_scaledInit_00542044], edx
        jne     loop_004251fd
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_xformLoopCounter], esi
        sub     edx, 3
        sub     ecx, 3
        sub     eax, 3
        pop     edi
        pop     esi
        mov     dword ptr [g_scaledInit_00542044], edx
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_pendingNodeType], eax
        pop     ebx
        ret
    }
}
