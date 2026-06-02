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

/* @addr 0x00446680 (272b game) - load baseSel triple + call cascade with bit2 gate.
 *   Load baseSel[+0x30/+0x60/+0x4c] -> scaledInit/g_xformEntityIdx/g_cj_0054205c.
 *   Call PushPopScaled1cDoubleCall; if pause? ret.
 *   mstack-push g_cj_0054205c; g_cj_0054205c = g_eventQueueIdx.
 *   Call DispatchSetDirtyToggle.
 *   If bit2 of state set: g_xformEntityIdx = 0x0051962c >> 2. Else: 0x00519ae0 >> 2.
 *   mstack-pop g_cj_0054205c. Call MStackBracket1_TreeWalkRecursive2; if pause/bit2? ret.
 *   g_xformEntityIdx = baseSel[+0x30]. Call Thunk_MStackPush2ChainPrepend; if pause? ret.
 *   Call SetupVecFsmCluster; if pause? ret. Else: state |= 4; if scaledInit was 0 ret;
 *   else: state ^= 4 (clear bit2); ret.
 */
extern void DispatchSetDirtyToggle(void);
extern void MStackBracket1_TreeWalkRecursive2(void);
extern void Thunk_MStackPush2ChainPrepend(void);
extern void PushPopScaled1cDoubleCall(void);
extern void SetupVecFsmCluster(void);

__declspec(naked) void GuardedCascadeBaseSelBit(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        mov     ecx, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     edx, dword ptr [eax*4 + 0x60]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     eax, dword ptr [eax*4 + 0x4c]
        mov     dword ptr [g_cj_0054205c], eax
        call    PushPopScaled1cDoubleCall
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0d0h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_cj_0054205c]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_cj_0054205c], edx
        call    DispatchSetDirtyToggle
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 4
        _emit   84h
        _emit   0c3h
        _emit   74h
        _emit   0fh
        mov     eax, 0x0051962c
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        _emit   0ebh
        _emit   0eh
        mov     ecx, 0x00519ae0
        shr     ecx, 2
        mov     dword ptr [g_xformEntityIdx], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_cj_0054205c], edx
        mov     dword ptr [g_matrixStackTop], eax
        call    MStackBracket1_TreeWalkRecursive2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   56h
        test    byte ptr [g_xformDirtyFlags], bl
        _emit   75h
        _emit   4eh
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_xformEntityIdx], ecx
        call    Thunk_MStackPush2ChainPrepend
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   2eh
        call    SetupVecFsmCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   20h
        mov     ecx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [g_scaledInit_00542044]
        or      ecx, ebx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        _emit   74h
        _emit   09h
        mov     eax, ecx
        xor     eax, ebx
        mov     dword ptr [g_xformDirtyFlags], eax
        pop     ebx
        ret
    }
}
