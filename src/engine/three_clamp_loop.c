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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

/* @addr 0x00425a80 (155b game) - 3-element clamp loop:
 *   neg = -g_walkCallback; for i in {0,1,2}:
 *     v = arr_src[g_xformEntityIdx++];
 *     if (v < 0): if (v < neg) v = neg; else: if (v > g_walkCallback) v = walkCallback;
 *     arr_dst[g_scaledInit++] = v.
 *   Then: g_xformLoopCounter = 2 (the iter sentinel), rollback g_scaledInit/g_xformEntityIdx by 3.
 */

extern unsigned int g_arr_425a80_dst;
extern unsigned int g_arr_425a80_src;

__declspec(naked) void ThreeClampLoop_00425a80(void) {
    __asm {
        push    ebx
        push    esi
        mov     esi, dword ptr [g_walkCallback]
        push    edi
        mov     edx, esi
        mov     edi, 2
        neg     edx
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     ebx, 3
        _emit   0ebh
        _emit   0ch
loop425a80:
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     esi, dword ptr [g_walkCallback]
afterReload:
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, [ecx*4 + g_arr_425a80_src]
        inc     ecx
        test    eax, eax
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        _emit   7dh
        _emit   08h
        cmp     eax, edx
        _emit   7dh
        _emit   0fh
        mov     eax, edx
        _emit   0ebh
        _emit   06h
        cmp     eax, esi
        _emit   7eh
        _emit   07h
        mov     eax, esi
        mov     dword ptr [g_eventQueueWorkType], eax
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     [ecx*4 + g_arr_425a80_dst], eax
        mov     edx, dword ptr [g_scaledInit_00542044]
        inc     edx
        dec     edi
        dec     ebx
        mov     dword ptr [g_scaledInit_00542044], edx
        _emit   75h
        _emit   0a6h
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, edx
        mov     dword ptr [g_xformLoopCounter], edi
        sub     ecx, 3
        sub     eax, 3
        pop     edi
        pop     esi
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [g_xformEntityIdx], eax
        pop     ebx
        ret
    }
}
