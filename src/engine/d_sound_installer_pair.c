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

/* @addr 0x004aede0 (241b engine.install) - DSound enumeration + open helper pair.
 *   First sub-function (0x4aede0, 62b): call DSCreate(g_comptr_0058c7ac, callback=L_fn2);
 *     store result; if [0x58c7ac] still null, retry via DSEnum(0, ptr, 0); ret bool.
 *   Second sub-function (0x4aee20, 177b): DSCreate(p): allocates 0x2dc-byte caps buffer
 *     on stack, queries device caps via vtbl[+0x2c], validates total memory >= 0x32c000;
 *     on success: stores object pointer; ret 0 success / 1 fail.
 *   Both are bundled as a single symbols.yaml entry (size 241 includes 2 nop pad).
 */
extern unsigned int g_comptr_0058c7ac;
extern int g_renderer2_present_rc;
extern void DSCreateThunk_004d12d2(void);
extern void DSEnumeratorThunk_004d12cc(void);

__declspec(naked) void DSoundInstallerPair(void) {
    __asm {
        /* sub-function 1 (0x4aede0 .. 0x4aee1d, plus 90h padding) */
        push    offset g_comptr_0058c7ac
        push    offset L_dsfn2
        call    DSCreateThunk_004d12d2
        mov     dword ptr [g_renderer2_present_rc], eax
        mov     eax, dword ptr [g_comptr_0058c7ac]
        test    eax, eax
        jne     short L_dsr_done
        push    0
        push    offset g_comptr_0058c7ac
        push    0
        call    DSEnumeratorThunk_004d12cc
        mov     dword ptr [g_renderer2_present_rc], eax
    L_dsr_done:
        mov     ecx, dword ptr [g_comptr_0058c7ac]
        xor     eax, eax
        test    ecx, ecx
        setne   al
        ret
        _emit   90h
        _emit   90h
    L_dsfn2:
        /* sub-function 2 (0x4aee20 .. 0x4aeed0) */
        mov     eax, [esp + 4]
        sub     esp, 0x2dc
        test    eax, eax
        push    edi
        jz      L_ds2_fail
        lea     ecx, [esp + 4]
        push    0
        push    ecx
        push    eax
        call    DSEnumeratorThunk_004d12cc
        test    eax, eax
        jl      L_ds2_fail
        mov     ecx, 0x5b
        xor     eax, eax
        lea     edi, [esp + 8]
        mov     edx, 0x16c
        rep     stosd
        mov     ecx, 0x5b
        lea     edi, [esp + 0x174]
        rep     stosd
        mov     eax, [esp + 4]
        mov     [esp + 8], edx
        test    eax, eax
        mov     [esp + 0x174], edx
        jz      short L_ds2_skipVtbl
        mov     edx, [eax]
        lea     ecx, [esp + 0x174]
        push    ecx
        lea     ecx, [esp + 0xc]
        push    ecx
        push    eax
        call    dword ptr [edx + 0x2c]
        test    eax, eax
        mov     eax, [esp + 4]
        jl      short L_ds2_releaseFail
    L_ds2_skipVtbl:
        test    byte ptr [esp + 0xc], 1
        jz      short L_ds2_releaseChk
        cmp     dword ptr [esp + 0x44], 0x32c000
        jb      short L_ds2_releaseChk
        mov     ecx, [esp + 0x2f0]
        mov     [ecx], eax
        xor     eax, eax
        pop     edi
        add     esp, 0x2dc
        ret     0x10
    L_ds2_releaseChk:
        test    eax, eax
        jz      short L_ds2_fail
    L_ds2_releaseFail:
        mov     edx, [eax]
        push    eax
        call    dword ptr [edx + 8]
    L_ds2_fail:
        mov     eax, 1
        pop     edi
        add     esp, 0x2dc
        ret     0x10
    }
}
