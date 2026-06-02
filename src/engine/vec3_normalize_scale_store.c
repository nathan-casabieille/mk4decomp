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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

/* @addr 0x004b3130 (161b engine.app) - 3-vec normalize + scale + store:
 *   len2 = a^2 + b^2 + c^2; if (sqrt(len2) <= const1): write 0/0/0.
 *   else: factor = const2 / sqrt(len2);
 *   For each component: result = DoubleToInt64(component * factor).
 *   Store esi/edi/ecx (each int result) to 6 slots at 0x7af9c0/c4/c8/d8/dc/e0
 *   indexed by 12*idx0.
 */
extern unsigned int g_arr_007af9c0;
extern unsigned int g_arr_007af9c4;
extern unsigned int g_arr_007af9c8;
extern unsigned int g_arr_007af9d8;
extern unsigned int g_arr_007af9dc;
extern unsigned int g_arr_007af9e0;
extern unsigned int g_fp_004d29b8;
extern unsigned int g_fp_004d29c0;
extern void DoubleToInt64(void);

__declspec(naked) void Vec3NormalizeScaleStore_004b3130(void) {
    __asm {
        push    ecx
        push    esi
        mov     esi, dword ptr [esp + 0x10]
        push    edi
        mov     edi, dword ptr [esp + 0x18]
        mov     eax, esi
        mov     ecx, edi
        imul    eax, esi
        imul    ecx, edi
        add     eax, ecx
        mov     ecx, dword ptr [esp + 0x1c]
        mov     edx, ecx
        imul    edx, ecx
        add     eax, edx
        mov     dword ptr [esp + 8], eax
        fild    dword ptr [esp + 8]
        fsqrt
        fcom    qword ptr [g_fp_004d29b8]
        fnstsw  ax
        test    ah, 0x40
        _emit   75h
        _emit   34h
        fdivr   qword ptr [g_fp_004d29c0]
        fild    dword ptr [esp + 0x14]
        fmul    st(0), st(1)
        call    DoubleToInt64
        fild    dword ptr [esp + 0x18]
        movsx   esi, ax
        fmul    st(0), st(1)
        call    DoubleToInt64
        fild    dword ptr [esp + 0x1c]
        movsx   edi, ax
        fmul    st(0), st(1)
        call    DoubleToInt64
        fstp    st(0)
        movsx   ecx, ax
        _emit   0ebh
        _emit   02h
        fstp    st(0)
        mov     eax, dword ptr [esp + 0x10]
        lea     eax, [eax + eax*2]
        shl     eax, 2
        mov     dword ptr [eax + g_arr_007af9c0], esi
        mov     dword ptr [eax + g_arr_007af9d8], esi
        mov     dword ptr [eax + g_arr_007af9c4], edi
        mov     dword ptr [eax + g_arr_007af9dc], edi
        mov     dword ptr [eax + g_arr_007af9c8], ecx
        pop     edi
        mov     dword ptr [eax + g_arr_007af9e0], ecx
        pop     esi
        pop     ecx
        ret
    }
}
