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

/* @addr 0x0041f8f0 (194b boot) - linked-list search by bit-mask flag.
 *   Push g_eventQueueWorkType; ecx = [0x52ab3c]; edx = g_walkCallback & g_eventQueueCurrent; g_walkCallback = edx.
 *   if (ecx == 0): bit_set_exit.
 *   loop: if ([ecx+0xd8] != 0) {
 *     g_scaledInit = ecx >> 2; g_eventQueueWorkType = chain[g_scaledInit + 0xc];
 *     if (g_eventQueueWorkType == edx) goto bit_clear_exit;
 *   }
 *   ecx = [ecx+0xe4]; if (ecx != 0) goto loop;
 *   bit_set_exit: mstack-pop g_eventQueueWorkType; g_scaledInit = 0;
 *     g_xformDirtyFlags = (orig & ~1) | 4; ret.
 *   bit_clear_exit: mstack-pop g_eventQueueWorkType;
 *     g_xformDirtyFlags = (orig & ~4) | 1; ret.
 */

extern unsigned int g_matrixStack_arr;

void LinkedListBitMaskSearch(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_eventQueueWorkType]
        mov     ecx, dword ptr [g_nodeListTail]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     [eax*4 + g_matrixStack_arr], edx
        mov     edx, dword ptr [g_walkCallback]
        and     edx, dword ptr [g_eventQueueCurrent]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], edx
        _emit   74h
        _emit   2eh
        mov     eax, [ecx + 0xd8]
        test    eax, eax
        _emit   74h
        _emit   1ah
        mov     eax, ecx
        sar     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, [eax*4 + 0x0c]
        cmp     eax, edx
        mov     dword ptr [g_eventQueueWorkType], eax
        _emit   74h
        _emit   3fh
        mov     ecx, [ecx + 0xe4]
        test    ecx, ecx
        _emit   75h
        _emit   0d2h
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_scaledInit_00542044], 0
        and     edx, 0xfffffffe
        mov     ecx, [eax*4 + g_matrixStack_arr]
        dec     eax
        or      edx, 4
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [g_xformDirtyFlags], edx
        ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_xformDirtyFlags]
        and     edx, 0xfffffffb
        mov     ecx, [eax*4 + g_matrixStack_arr]
        dec     eax
        or      edx, 1
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [g_xformDirtyFlags], edx
        }
}

