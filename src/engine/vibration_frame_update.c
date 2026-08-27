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

/* @addr 0x004b9640 (301b engine.render) - vibration/feedback frame update.
 *   Reads g_fightGroupHead & 0x180000; if both bits 0, skip. Else loads
 *   [esp+0x14] as `i`; if [i*4+0x1c]==-20, set i=2. Validate i in [1,0x18].
 *   Lookup pattern entry at [i*4 + g_dispatchSave554]; bail if 0x10000.
 *   If i==2: load FP, fadd to g_fpuConst, fcomp 0x004d2a00; if FP overflow,
 *     re-init constants to 0x3fec_cccccccd / 0x3f90_624d_d2f1_a9fc.
 *   Else: check fcomp 0x004d2a10; if outside range, re-init to 0x3ff1_9999_9999_999a
 *     / 0xbf78_9374_bc6a_7efa.
 *   Convert via DoubleToInt64, write to g_walkCallback, shift right by 4,
 *   call Transform9Words(esi, &local); OR bit 0x30 of high byte of g_xformDirtyFlags.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave887;
extern unsigned int g_dispatchSave888;
extern unsigned int g_dispatchSave554;
extern unsigned int g_fpuConst;
extern unsigned int g_dispatchSave553;
extern unsigned int g_dispatchSave502;
extern unsigned int g_dispatchSave552;
#endif
extern void DoubleToInt64(void);
#ifdef NON_MATCHING
extern void Transform9Words(short *dst, int *src);
#else
extern void Transform9Words(void);
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
#define g_dispatchSave502 (*(unsigned int *)MK4_VA(unsigned int, 0x4f6578u))
#define g_dispatchSave552 (*(unsigned int *)MK4_VA(unsigned int, 0x4f657cu))
#define g_dispatchSave553 (*(unsigned int *)MK4_VA(unsigned int, 0x4f6574u))
#define g_dispatchSave554 (*(unsigned int *)MK4_VA(unsigned int, 0x4f6508u))
#define g_dispatchSave887 (*(unsigned int *)MK4_VA(unsigned int, 0x4d2a00u))
#define g_dispatchSave888 (*(unsigned int *)MK4_VA(unsigned int, 0x4d2a10u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_fpuConst (*(unsigned int *)MK4_VA(unsigned int, 0x4f6570u))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin, rewritten from the disassembly rather than patched: the lift
 * had the FPU block as a bare `__ftol()` with no argument, and every double
 * here was declared `unsigned int`.
 *
 * Only mode 2 runs the oscillator. It steps g_fpuConst by a signed increment
 * and FLIPS that increment's sign whenever the value leaves [0.9, 1.1], so the
 * scale ping-pongs between the two bounds. The increment's two halves are
 * written as raw dwords, as the original does - they are exact bit patterns,
 * not decimals. Every other mode skips straight to the broadcast.
 *
 * The scale is applied as `(int)((double)(int)g_walkCallback * g_fpuConst)`:
 * `fild` reads the slot SIGNED, and the CRT's helper truncates toward zero,
 * which is what a C cast does. */
void VibrationFrameUpdate(int node)
{
    int mode, t;
    int v[3];

    if ((g_cj_0054205c & 0x180000) == 0)
        return;

    mode = MK4_NODE_AT(int, node, 0x1c);
    if (mode == -0x14)
        mode = 2;
    if (mode <= 0 || mode > 0x18)
        return;

    g_walkCallback = *(unsigned int *)MK4_VA(unsigned int,
                                             0x004f6508u + (unsigned)mode * 4u);
    if (g_walkCallback == 0x10000)
        return;

    if (mode == 2) {
        /* VOLATILE, and that is load-bearing. The clamps below rewrite these
         * two doubles through an `unsigned int` lens - the exact-dword form
         * the original uses - and at -O2 strict aliasing lets the compiler
         * keep the pre-clamp value in a register. The twin then multiplied by
         * the UNCLAMPED scale: 64 * 1.5 instead of 64 * 1.1. */
        volatile double *k    = MK4_VA(volatile double, 0x004f6570u);
        volatile double *step = MK4_VA(volatile double, 0x004f6578u);

        *k += *step;
        /* All four constants go in as their exact dwords, the way the
         * original writes them. A decimal literal would be right to the bit
         * but would live in .rodata, which the co-exec harness does not
         * relocate - the twin then multiplied by zero and only the clamped
         * cases showed it. */
        if (*k < *MK4_VA(double, 0x004d2a00u)) {
            *(unsigned int *)MK4_VA(unsigned int, 0x004f6570u) = 0xcccccccdu;
            *(unsigned int *)MK4_VA(unsigned int, 0x004f6574u) = 0x3fecccccu;
            *(unsigned int *)MK4_VA(unsigned int, 0x004f6578u) = 0xd2f1a9fcu;
            *(unsigned int *)MK4_VA(unsigned int, 0x004f657cu) = 0x3f90624du;
        }
        if (*k > *MK4_VA(double, 0x004d2a10u)) {
            *(unsigned int *)MK4_VA(unsigned int, 0x004f6570u) = 0x9999999au;
            *(unsigned int *)MK4_VA(unsigned int, 0x004f6574u) = 0x3ff19999u;
            *(unsigned int *)MK4_VA(unsigned int, 0x004f6578u) = 0xbc6a7efau;
            *(unsigned int *)MK4_VA(unsigned int, 0x004f657cu) = 0xbf789374u;
        }
        g_walkCallback = (unsigned int)(int)((double)(int)g_walkCallback * *k);
    }

    t = (int)g_walkCallback >> 4;
    v[2] = t;
    v[1] = t;
    v[0] = t;
    Transform9Words(MK4_NODE(short, g_dualC), v);
    g_xformDirtyFlags |= 0x30;
}
#else
__declspec(naked) void VibrationFrameUpdate(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        sub     esp, 0x0c
        test    eax, 0x180000
        push    esi
        jz      L_vfu_done
        mov     eax, [esp + 0x14]
        mov     ecx, dword ptr [eax*4 + 0x1c]
        cmp     ecx, -0x14
        jne     short L_vfu_chk
        mov     ecx, 2
    L_vfu_chk:
        test    ecx, ecx
        jle     L_vfu_done
        cmp     ecx, 0x18
        jg      L_vfu_done
        mov     eax, dword ptr [ecx*4 + g_dispatchSave554]
        cmp     eax, 0x10000
        mov     dword ptr [g_walkCallback], eax
        jz      L_vfu_done
        mov     edx, dword ptr [g_pendingNodeType]
        cmp     ecx, 2
        lea     esi, [edx*4]
        jne     L_vfu_pathB_sar
        fld     qword ptr [g_dispatchSave502]
        fadd    qword ptr [g_fpuConst]
        fst     qword ptr [g_fpuConst]
        fcomp   qword ptr [g_dispatchSave887]
        fnstsw  ax
        test    ah, 1
        jz      short L_vfu_skipReinitA
        mov     dword ptr [g_fpuConst], 0xcccccccd
        mov     dword ptr [g_dispatchSave553], 0x3feccccc
        mov     dword ptr [g_dispatchSave502], 0xd2f1a9fc
        mov     dword ptr [g_dispatchSave552], 0x3f90624d
    L_vfu_skipReinitA:
        fld     qword ptr [g_fpuConst]
        fcomp   qword ptr [g_dispatchSave888]
        fnstsw  ax
        test    ah, 0x41
        jne     short L_vfu_doConv
        mov     dword ptr [g_fpuConst], 0x9999999a
        mov     dword ptr [g_dispatchSave553], 0x3ff19999
        mov     dword ptr [g_dispatchSave502], 0xbc6a7efa
        mov     dword ptr [g_dispatchSave552], 0xbf789374
    L_vfu_doConv:
        fild    dword ptr [g_walkCallback]
        fmul    qword ptr [g_fpuConst]
        call    DoubleToInt64
        mov     dword ptr [g_walkCallback], eax
    L_vfu_pathB_sar:
        sar     eax, 4
        mov     [esp + 0x0c], eax
        mov     [esp + 0x08], eax
        mov     [esp + 0x04], eax
        lea     eax, [esp + 4]
        push    eax
        push    esi
        call    Transform9Words
        mov     eax, dword ptr [g_xformDirtyFlags]
        add     esp, 8
        or      al, 0x30
        mov     dword ptr [g_xformDirtyFlags], eax
    L_vfu_pathB:
    L_vfu_done:
        pop     esi
        add     esp, 0x0c
        ret
    }
}
#endif
