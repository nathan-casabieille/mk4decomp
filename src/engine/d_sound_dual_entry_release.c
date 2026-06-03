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
extern unsigned int g_fightStateProgress;
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

extern unsigned int g_comptr_0058c7ac;
extern int g_renderer2_present_rc;
extern int g_renderer2_active;
extern int g_renderer2_initOk;
extern void Renderer2_EndScene_D3D(void);
extern void VtRelease_Modal(void);
extern void ReleaseVtableSlots(int);
extern void ComRelease_g_comptr_0058c7b8(void);
extern void DSoundDualEntryRelease(void);
extern void DualVtable8Call(void);
extern void ComRelease_g_comptr_0058c7c0(void);
extern void ComReleasePair_004af440(void);
extern void DSoundBufferInit146_a40(int);
extern void ComRelease_g_comptr_0058c7bc(void);
extern void ComReleaseCapture_004aeee0(void);
extern void DSoundBufferInit146_004aea40_alt(void);
extern void R2_Init4(void);

/* @addr 0x004ad7c0 (141b engine.install) - shutdown sequence:
 *   Renderer2_EndScene_D3D, VtRelease_Modal, ReleaseVtableSlot 0..15;
 *   ComRelease 4x, DSoundBufferInit146(0), 3 more releases; if g_renderer2_initOk:
 *   SetEvent via IAT@4d2210; clear g_renderer2_initOk; ret.
 */
extern unsigned int g_iat_InvalidateRect;

__declspec(naked) void R2_Cleanup(void) {
    __asm {
        push    esi
        call    Renderer2_EndScene_D3D
        call    VtRelease_Modal
        mov     eax, dword ptr [g_comptr_0058c7ac]
        test    eax, eax
        _emit   74h
        _emit   0bh
        mov     ecx, dword ptr [eax]
        push    eax
        call    dword ptr [ecx + 0x28]
        mov     dword ptr [g_renderer2_present_rc], eax
        xor     esi, esi
loop4ad7c0:
        push    esi
        call    ReleaseVtableSlots
        add     esp, 4
        inc     esi
        cmp     esi, 0x10
        _emit   7ch
        _emit   0f1h
        call    ComRelease_g_comptr_0058c7b8
        call    DSoundDualEntryRelease
        call    DualVtable8Call
        call    ComRelease_g_comptr_0058c7c0
        call    ComReleasePair_004af440
        push    0
        call    R2_Init4
        add     esp, 4
        call    ComRelease_g_comptr_0058c7bc
        call    ComReleaseCapture_004aeee0
        call    DSoundBufferInit146_a40
        mov     eax, dword ptr [g_renderer2_initOk]
        mov     dword ptr [g_renderer2_active], 0
        test    eax, eax
        _emit   74h
        _emit   0ch
        push    1
        push    0
        push    0
        call    dword ptr [g_iat_InvalidateRect]
        mov     dword ptr [g_renderer2_initOk], 0
        pop     esi
        ret
    }
}
