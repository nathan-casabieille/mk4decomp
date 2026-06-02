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
extern void CopyJmp_0048ef90(void);
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

extern void ScaledArrStore_004298c0(void);
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

/* @addr 0x00432000 (264b game) - 4-field setup + 2-iter Mul10Tail loop.
 *   diff = g_walkCallback - [g_pendingNodeType*4]; -= [g_eventQueueTotal*4]; shl 16;
 *   += [g_pendingNodeType*4 +4]; += [g_eventQueueTotal*4 +4].
 *   call DivLongPushCall; if pause? final-ret.
 *   Init g_xformLoopCounter = 2. Loop while g_xformLoopCounter >= 0:
 *     Mul10Tail([g_xformEntityIdx*4], g_walkCallback), store to scaledInit++, ++g_xformEntityIdx, --g_xformLoopCounter.
 *   At end: scaledInit -= 3, g_xformEntityIdx -= 4 (rewind to start), pop esi, ret.
 */
extern void DivLongPushCall(void);

__declspec(naked) void DiffMul10Loop(void) {
    __asm {
        mov     ecx, dword ptr [g_pendingNodeType]
        mov     eax, dword ptr [g_walkCallback]
        push    esi
        mov     edx, dword ptr [ecx*4 + 0]
        sub     eax, edx
        mov     edx, dword ptr [g_eventQueueTotal]
        mov     dword ptr [g_walkCallback], eax
        sub     eax, dword ptr [edx*4 + 0]
        shl     eax, 0x10
        mov     dword ptr [g_walkCallback], eax
        mov     esi, dword ptr [ecx*4 + 4]
        add     eax, esi
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [edx*4 + 4]
        add     eax, ecx
        mov     dword ptr [g_walkCallback], eax
        call    DivLongPushCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0a9h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [eax*4 + 0]
        push    ecx
        push    edx
        call    Mul10Tail
        mov     ecx, dword ptr [g_xformEntityIdx]
        add     esp, 8
        inc     ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     dword ptr [g_xformLoopCounter], 2
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [ecx*4 + 0], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [g_walkCallback]
        inc     edx
        mov     dword ptr [g_scaledInit_00542044], edx
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [edx*4 + 0]
        push    eax
        push    ecx
        call    Mul10Tail
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [g_xformLoopCounter]
        add     esp, 8
        inc     edx
        dec     ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_xformLoopCounter], ecx
        _emit   79h
        _emit   0a8h
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, edx
        sub     ecx, 3
        sub     eax, 4
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_xformEntityIdx], eax
        pop     esi
        ret
    }
}
