/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

/* @addr 0x004b3130 (161b engine.app) - 3-vec normalize + scale + store:
 *   len2 = a^2 + b^2 + c^2; if (sqrt(len2) <= const1): write 0/0/0.
 *   else: factor = const2 / sqrt(len2);
 *   For each component: result = DoubleToInt64(component * factor).
 *   Store esi/edi/ecx (each int result) to 6 slots at 0x7af9c0/c4/c8/d8/dc/e0
 *   indexed by 12*idx0.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_lightMat00;
extern unsigned int g_lightMat01;
extern unsigned int g_lightMat02;
extern unsigned int g_lightMat20;
extern unsigned int g_lightMat21;
extern unsigned int g_lightMat22;
extern unsigned int g_fpNormalizeZero;
extern unsigned int g_fpNormalizeScale4096;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_fpNormalizeScale4096 (*(unsigned int *)MK4_VA(unsigned int, 0x4d29c0u))
#define g_fpNormalizeZero (*(unsigned int *)MK4_VA(unsigned int, 0x4d29b8u))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_lightMat00 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9c0u))
#define g_lightMat01 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9c4u))
#define g_lightMat02 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9c8u))
#define g_lightMat20 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9d8u))
#define g_lightMat21 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9dcu))
#define g_lightMat22 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9e0u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void DoubleToInt64(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin, written from the disassembly. Normalizes the vector to
 * length 4096 (Q12) - unless it is exactly zero-length, in which case the RAW
 * components go through - and stores it into BOTH light matrices at a stride
 * of 12: row `which` of the 3x3 at 0x007af9c0 and of its mirror at 0x007af9d8.
 *
 * The scaled components are truncated to s16 (`movsx esi, ax` after the CRT
 * helper) before the store widens them again - so a component that overflows
 * 16 bits wraps, and the twin keeps that.
 *
 * __builtin_sqrt lowers to fsqrt under -fno-math-errno (the fpu_sqrt_mul.c
 * precedent); the two doubles are the engine's own constants, read from their
 * VAs rather than spelled as literals - a literal would sit in .rodata, which
 * the co-exec blob does not relocate. */
void Vec3NormalizeScaleStore(int which, int x, int y, int z)
{
    unsigned int row = (unsigned int)which * 12u;
    double len = __builtin_sqrt((double)(x * x + y * y + z * z));

    if (!(len == *MK4_VA(double, 0x4d29b8u))) {
        double scale = *MK4_VA(double, 0x4d29c0u) / len;

        x = (int)(short)(int)((double)x * scale);
        y = (int)(short)(int)((double)y * scale);
        z = (int)(short)(int)((double)z * scale);
    }

    *MK4_VA(int, 0x7af9c0u + row) = x;
    *MK4_VA(int, 0x7af9d8u + row) = x;
    *MK4_VA(int, 0x7af9c4u + row) = y;
    *MK4_VA(int, 0x7af9dcu + row) = y;
    *MK4_VA(int, 0x7af9c8u + row) = z;
    *MK4_VA(int, 0x7af9e0u + row) = z;
}
#else
__declspec(naked) void Vec3NormalizeScaleStore(void) {
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
        fcom    qword ptr [g_fpNormalizeZero]
        fnstsw  ax
        test    ah, 0x40
        _emit   75h
        _emit   34h
        fdivr   qword ptr [g_fpNormalizeScale4096]
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
        mov     dword ptr [eax + g_lightMat00], esi
        mov     dword ptr [eax + g_lightMat20], esi
        mov     dword ptr [eax + g_lightMat01], edi
        mov     dword ptr [eax + g_lightMat21], edi
        mov     dword ptr [eax + g_lightMat02], ecx
        pop     edi
        mov     dword ptr [eax + g_lightMat22], ecx
        pop     esi
        pop     ecx
        ret
    }
}
#endif
