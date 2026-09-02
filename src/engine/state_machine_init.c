/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
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

/* @addr 0x00493000 (216b game) - state-machine init with cascading calls. */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_particleEmitterNode;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
/* g_matrixStackTop is a REAL host symbol (src/data.c defines it), so a file
 * that does not alias it here pushes and pops a word in __DATA while the 97
 * files that DO alias it - including the boot helper that sets the packed
 * base 0x14e05a, and RecordListIterMStack, this file's own caller - use the
 * arena slot at 0x4d57ac. Two storages for one stack pointer. */
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
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
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_lit16_00542074 (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_particleEmitterNode (*(unsigned int *)MK4_VA(unsigned int, 0x535e6cu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch2088 (*(unsigned int *)MK4_VA(unsigned int, 0x542088u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void MStackCall_MStackPush2ChainPrepend_004062f0(void);
extern void MStackPushDispatchBitGate(void);
extern void MStackPushTableWalk(void);
extern void PushSetCallTailJmp(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"
extern void MStackPushDispatchBitGate(void);
extern void MStackPushTableWalk(void);
extern void PushSetCallTailJmp(void);
extern void MStackCall_MStackPush2ChainPrepend_004062f0(void);

/* @addr 0x00493000 (216b) - NATIVE twin; the matching build keeps the
 * body below.
 *
 * Creates ONE renderable scene node from a record: the walk value becomes
 * the type literal, the bit-gate dispatcher builds the node (leaving it in
 * the fight group slot), the type is stamped at +0x30, the table walk
 * runs, the record's flags and scratch land at +0x54 and +0x5c, the
 * set-call pass runs, the particle emitter is linked at +0x3c, and the
 * node is PREPENDED under the fight group's parent. The tail re-signals
 * not-found only when nothing was built. */

#ifdef TARGET_SDL
/* MK4_TRACE_MSTACK - finding who clears the matrix-stack top.
 *
 * g_matrixStackTop (0x4d57ac) is a PACKED index based at 0x538168, so a live
 * value is 0x14e05a and never small. On the long tower path it intermittently
 * reads 0 by the time MStackPushTableWalk pushes, and that push then writes
 * through index 1 - arena + 4. The caller's own pushes just above succeed, so
 * the clear happens inside this function.
 *
 * Sampled at four points rather than one: the first point that reports low is
 * the statement that did it. getenv is cached in a static because calling it
 * per sample perturbed the timing enough to hide the fault.
 *
 * The earlier version of this probe range-checked g_fightGroupHead for being
 * OUTSIDE the packed band and could never fire: the handles that make this
 * function's four stores land ON 0x4d57ac are 0x1355d4, 0x1355d6, 0x1355dc
 * and 0x1355df, all comfortably INSIDE the band. An in-band handle is exactly
 * what a stray-store bug looks like, so the check is now against the aliasing
 * window, not the band. */
static void SmiMstackSample(int point)
{
    extern void SDL_Log(const char *, ...);
    extern char *getenv(const char *);
    static int tr = -1;
    static unsigned n;
    static const char *where[4] = { "entry", "after MStackPushDispatchBitGate",
                                    "after head+0x30 store", "before walk" };
    unsigned int top, head;
    if (tr < 0) tr = getenv("MK4_TRACE_MSTACK") != 0;
    if (!tr || n >= 12) return;
    top = (unsigned int)g_matrixStackTop;
    head = (unsigned int)g_fightGroupHead;
    /* a head anywhere in this window aliases 0x4d57ac through one of the
     * four stores; report it even when the top still looks healthy */
    if (head >= 0x1355d0u && head <= 0x1355e4u) { n++;
        SDL_Log("SMI head 0x%06x ALIASES the mstack top (at %s)", head,
                where[point]); }
    if (top < 0x100000u) { n++;
        if (point == 0) {
            /* who called us matters more than the value: the top is already
             * clear on entry, so the writer is upstream of this function */
            extern int dladdr(const void *, void *);
            struct { const char *fn; void *fb; const char *sn; void *sa; } di;
            void *ra = __builtin_return_address(0);
            if (dladdr(ra, (void *)&di) && di.sn)
                SDL_Log("SMI mstack top low (%08x) at entry; head=%08x;"
                        " called from %s", top, head, di.sn);
            else
                SDL_Log("SMI mstack top low (%08x) at entry; head=%08x;"
                        " called from %p", top, head, ra);
        } else
            SDL_Log("SMI mstack top low (%08x) at %s; head=%08x", top,
                    where[point], head); }
}
#define SMI_SAMPLE(p) SmiMstackSample(p)
#else
#define SMI_SAMPLE(p) ((void)0)
#endif

void StateMachineInit(void)
{
    SMI_SAMPLE(0);
    g_lit16_00542074 = g_walkCallback;
    MStackPushDispatchBitGate();
    SMI_SAMPLE(1);
    if (g_framePauseFlag != 0) return;
    if (g_xformDirtyFlags & 4u) return;

    g_walkCallback = g_lit16_00542074;
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x30) = g_lit16_00542074;
    SMI_SAMPLE(2);
    SMI_SAMPLE(3);
    MStackPushTableWalk();
    if (g_framePauseFlag != 0) return;

    g_pendingNodeType = g_xformEntityIdx;
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x54) = g_currentNodeFlags;
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x5c) = g_xformScratch2088;
    PushSetCallTailJmp();
    if (g_framePauseFlag != 0) return;

    g_walkCallback = *MK4_VA(unsigned int, 0x535e6cu);
    MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x3c) = g_walkCallback;
    MStackCall_MStackPush2ChainPrepend_004062f0();
    if (g_framePauseFlag != 0) return;

    g_xformDirtyFlags |= 4;
    if (g_fightGroupHead != 0) g_xformDirtyFlags ^= 4;
}
#else
void StateMachineInit(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [g_eventQueueWorkType], eax
        call    MStackPushDispatchBitGate
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0bbh
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   0fh
        _emit   85h
        _emit   0aeh
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_eventQueueWorkType]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x30], eax
        call    MStackPushTableWalk
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [eax*4 + 0x54], ecx
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_xformScratch2088]
        mov     dword ptr [edx*4 + 0x5c], eax
        call    PushSetCallTailJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   47h
        mov     eax, dword ptr [g_particleEmitterNode]
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x3c], eax
        call    MStackCall_MStackPush2ChainPrepend_004062f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   22h
        mov     ecx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [g_fightGroupHead]
        or      ecx, 4
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        _emit   74h
        _emit   0ah
        mov     eax, ecx
        xor     eax, 4
        mov     dword ptr [g_xformDirtyFlags], eax
        }
}
#endif

