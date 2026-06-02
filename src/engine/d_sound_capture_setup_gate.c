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

/* @addr 0x004ad4a0 (234b engine.install) - DSound capture buffer setup gate.
 *   Frame: sub esp, 0x6c; push ebx/ebp/esi/edi.
 *   Validate: g_renderer2_active!=0, arg1!=0, arg2!=0, arg3!=0, g_renderer2_paused==0; else fail.
 *   Zero local 108-byte struct ([esp+0x10]); set struct[0]=0x6c (size).
 *   Depending on arg0 (esi): if esi!=0 use [0x58c7b4]; else use [0x58c7b0].
 *   vtbl call ([ecx+0x64]: object_ptr, 0, struct_ptr, flag, 0) and store result
 *   in g_renderer2_present_rc.
 *   If [esp+0x34] (returned blob) != 0 and [esp+0x20] >= 0x280:
 *     *arg1 = blob; *arg2 = field; *arg3 = [0x004f4788]; g_renderer2_paused = (esi?2:1).
 *     Return 1. Else return 0.
 */
extern unsigned int g_dispatchSave501;
extern unsigned int g_comptr_0058c7b0;
extern unsigned int g_comptr_0058c7b4;
extern int g_renderer2_present_rc;
extern int g_renderer2_active;
extern int g_renderer2_paused;

__declspec(naked) void DSoundCaptureSetupGate(void) {
    __asm {
        mov     eax, dword ptr [g_renderer2_active]
        sub     esp, 0x6c
        test    eax, eax
        push    ebx
        push    ebp
        push    esi
        push    edi
        jz      L_dcg_fail
        mov     eax, [esp + 0x84]
        test    eax, eax
        jz      L_dcg_fail
        mov     ebp, [esp + 0x88]
        test    ebp, ebp
        jz      L_dcg_fail
        mov     ebx, [esp + 0x8c]
        test    ebx, ebx
        jz      L_dcg_fail
        mov     eax, dword ptr [g_renderer2_paused]
        test    eax, eax
        jne     L_dcg_fail
        mov     esi, [esp + 0x80]
        mov     ecx, 0x1b
        xor     eax, eax
        lea     edi, [esp + 0x10]
        rep     stosd
        test    esi, esi
        mov     dword ptr [esp + 0x10], 0x6c
        jz      short L_dcg_pickB
        mov     eax, dword ptr [g_comptr_0058c7b4]
        test    eax, eax
        jz      short L_dcg_skipCall
        mov     ecx, [eax]
        push    0
        push    0x21
        jmp     short L_dcg_doCall
    L_dcg_pickB:
        mov     eax, dword ptr [g_comptr_0058c7b0]
        test    eax, eax
        jz      short L_dcg_skipCall
        mov     ecx, [eax]
        push    0
        push    0x11
    L_dcg_doCall:
        lea     edx, [esp + 0x18]
        push    edx
        push    0
        push    eax
        call    dword ptr [ecx + 0x64]
        mov     dword ptr [g_renderer2_present_rc], eax
    L_dcg_skipCall:
        mov     eax, [esp + 0x34]
        test    eax, eax
        jz      short L_dcg_fail
        mov     ecx, [esp + 0x20]
        cmp     ecx, 0x280
        jl      short L_dcg_fail
        mov     edx, [esp + 0x84]
        mov     [edx], eax
        mov     [ebp], ecx
        mov     eax, dword ptr [g_dispatchSave501]
        xor     ecx, ecx
        test    esi, esi
        setne   cl
        inc     ecx
        mov     [ebx], eax
        mov     dword ptr [g_renderer2_paused], ecx
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x6c
        ret
    L_dcg_fail:
        pop     edi
        pop     esi
        pop     ebp
        xor     eax, eax
        pop     ebx
        add     esp, 0x6c
        ret
    }
}
