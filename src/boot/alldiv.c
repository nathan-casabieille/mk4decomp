/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

/* @addr 0x004c5690 (176b boot) - __alldiv: MSVC CRT 64-bit signed integer divide.
 *   Stack: ret addr, dvdnd_lo, dvdnd_hi, dvr_lo, dvr_hi.
 *   Absolutize both operands tracking sign in edi, divide via div/shift,
 *   conditionally negate result. Returns edx:eax (quotient), ret 0x10.
 */
__declspec(naked) void Alldiv(void) {
    __asm {
        push    edi
        push    esi
        push    ebx
        xor     edi, edi
        mov     eax, [esp + 0x14]
        or      eax, eax
        jge     short L_div_a_pos
        inc     edi
        mov     edx, [esp + 0x10]
        neg     eax
        neg     edx
        sbb     eax, 0
        mov     [esp + 0x14], eax
        mov     [esp + 0x10], edx
    L_div_a_pos:
        mov     eax, [esp + 0x1c]
        or      eax, eax
        jge     short L_div_b_pos
        inc     edi
        mov     edx, [esp + 0x18]
        neg     eax
        neg     edx
        sbb     eax, 0
        mov     [esp + 0x1c], eax
        mov     [esp + 0x18], edx
    L_div_b_pos:
        or      eax, eax
        jne     short L_div_big
        mov     ecx, [esp + 0x18]
        mov     eax, [esp + 0x14]
        xor     edx, edx
        div     ecx
        mov     ebx, eax
        mov     eax, [esp + 0x10]
        div     ecx
        mov     edx, ebx
        jmp     short L_div_sign
    L_div_big:
        mov     ebx, eax
        mov     ecx, [esp + 0x18]
        mov     edx, [esp + 0x14]
        mov     eax, [esp + 0x10]
    L_div_shift:
        shr     ebx, 1
        rcr     ecx, 1
        shr     edx, 1
        rcr     eax, 1
        or      ebx, ebx
        jne     short L_div_shift
        div     ecx
        mov     esi, eax
        mul     dword ptr [esp + 0x1c]
        mov     ecx, eax
        mov     eax, [esp + 0x18]
        mul     esi
        add     edx, ecx
        jb      short L_div_dec
        cmp     edx, [esp + 0x14]
        ja      short L_div_dec
        jb      short L_div_done
        cmp     eax, [esp + 0x10]
        jbe     short L_div_done
    L_div_dec:
        dec     esi
    L_div_done:
        xor     edx, edx
        mov     eax, esi
    L_div_sign:
        dec     edi
        jne     short L_div_ret
        neg     edx
        neg     eax
        sbb     edx, 0
    L_div_ret:
        pop     ebx
        pop     esi
        pop     edi
        ret     0x10
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
    }
}
