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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_bootChainPair0;
#endif
extern void GuardedChainPushSetCallPop(void);
extern void ScaledLoadGuardedJmp(void);
extern void PvsMergeDriver(void);
extern void MStackBracket2_TreeWalkRecursive(void);
extern void LinkedListInsert(void);

/* @addr 0x00406790 (377b boot) - mstack-push-2 scope + 2-call chain + LL insert.
 *   Sets bit 2 of g_xformDirtyFlags. If g_currentNodeIdx is zero, takes the
 *   short path: clears bit 2 again and returns. Otherwise pushes
 *   g_xformEntityIdx / g_fightGroupHead onto mstack, calls
 *   GuardedChainPushSetCallPop + ScaledLoadGuardedJmp.
 *   Sets g_fightGroupHead = old g_currentNodeIdx, reads [scaled+0x1c]; if
 *   non-zero, toggles bit 2 off and calls PvsMergeDriver. Zeroes
 *   g_walkCallback and [scaled+0x1c]. Reads [scaled+0x18]; if non-zero,
 *   toggles bit 2 off and calls MStackBracket2_TreeWalkRecursive. Then writes g_bootChainPair0
 *   into g_xformEntityIdx and calls LinkedListInsert. Pops the 2
 *   mstack entries back and clears bit 0 of g_xformDirtyFlags via and 0xfe.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_phaseChainTbl;
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
#define g_bootChainPair0 (*(unsigned int *)MK4_VA(unsigned int, 0x541e80u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_phaseChainTbl (*(unsigned int *)MK4_VA(unsigned int, 0x0u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void MStackBracket5_LinkedListUnlink(void);
extern void Helper_TickAlt(void);
extern void MStackPush2ChainInsert(void);
/* the PVS list head - an ARENA alias, not a C variable: a plain extern would
 * bind to the weak autostub global, separate storage the engine never sees */
#define g_vertexInitFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e74u))

/* The two continuations Helper_TickAlt calls back during PvsMergeDriver's
 * walks. Both live INSIDE PvsMergeDriver's own symbol in the original
 * (0x425f90 / 0x425fd0), so they have no symbols.yaml entry and are registered
 * through config/codeptr_extras.yaml - NATIVE ONLY, the matching build carries
 * them inside the blob.
 *
 * Each is a match predicate: clear the walk's found bit, then set it if the
 * walked node - by its END (node + count + 4) for the first, by itself for
 * the second - is the merge target. */
void PvsMerge_MatchEnd_00425f90(void)
{
    unsigned int end;

    g_walkCallback = g_currentNodeIdx;
    end = g_currentNodeIdx + MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0xc) + 4;
    g_xformDirtyFlags &= 0xfffffffeu;
    g_walkCallback = end;
    if (end == g_pendingNodeType)
        g_xformDirtyFlags |= 1;
}

void PvsMerge_MatchNode_00425fd0(void)
{
    g_xformDirtyFlags &= 0xfffffffeu;
    if (g_currentNodeIdx == g_pendingNodeType)
        g_xformDirtyFlags |= 1;
}

/* @addr 0x00425db0 (584b) - NATIVE ONLY; the matching build synthesizes it.
 *
 * Merges the freed node into the PVS free list: unlink the node four slots
 * back, walk the list for the region whose END touches it (callback
 * 0x425f90), and if the walk found one (bit 0 - the `dirty & 4` test reads
 * the walk's OWN not-found bit) unlink that region too and fold both counts
 * into one (`count = a + b + 4`). Then the same again in the other direction
 * with the by-node predicate, and the merged region is re-inserted. The
 * bracket saves g_xformEntityIdx and g_pendingNodeType; every paused exit
 * leaks it, as all the mstack brackets here do.
 *
 * The callback slots take the CONTINUATION VAs as literals, exactly as the
 * original stores them - identity under co-exec, resolved through the
 * trampoline by Helper_TickAlt's own MK4_ResolveCode on the native build. */
void PvsMergeDriver(void)
{
    unsigned int c;

    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_xformEntityIdx;
    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_pendingNodeType;

    g_currentNodeIdx -= 4;
    g_xformEntityIdx = 0;
    MStackBracket5_LinkedListUnlink();
    if (g_framePauseFlag != 0)
        return;

    g_pendingNodeType = g_currentNodeIdx;
    g_currentNodeIdx = g_vertexInitFlag;
    g_walkCallback = 0x425f90u;
    Helper_TickAlt();
    if (g_framePauseFlag != 0)
        return;

    if ((g_xformDirtyFlags & 4u) == 0) {
        g_xformEntityIdx = 0;
        MStackBracket5_LinkedListUnlink();
        if (g_framePauseFlag != 0)
            return;

        c = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0xc);
        g_walkCallback = c;
        c += MK4_NODE_AT(unsigned int, g_pendingNodeType, 0xc) + 4;
        g_walkCallback = c;
        MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0xc) = c;
        g_pendingNodeType = g_currentNodeIdx;
    }
    g_xformEntityIdx = g_pendingNodeType;

    c = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0xc);
    g_walkCallback = 0x425fd0u;
    g_pendingNodeType = g_xformEntityIdx + c + 4;
    g_currentNodeIdx = g_vertexInitFlag;
    Helper_TickAlt();
    if (g_framePauseFlag != 0)
        return;

    g_pendingNodeType = g_xformEntityIdx;
    if ((g_xformDirtyFlags & 4u) == 0) {
        g_xformEntityIdx = 0;
        MStackBracket5_LinkedListUnlink();
        if (g_framePauseFlag != 0)
            return;

        c = MK4_NODE_AT(unsigned int, g_pendingNodeType, 0xc);
        g_walkCallback = c;
        c += MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0xc) + 4;
        g_walkCallback = c;
        MK4_NODE_AT(unsigned int, g_pendingNodeType, 0xc) = c;
    }

    g_currentNodeIdx = g_pendingNodeType;
    g_xformEntityIdx = g_vertexInitFlag;
    MStackPush2ChainInsert();
    if (g_framePauseFlag != 0)
        return;

    g_pendingNodeType = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
    g_xformEntityIdx = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
}

#include "portable/mem_model.h"

extern void GuardedChainPushSetCallPop(void);
extern void ScaledLoadGuardedJmp(void);
extern void PvsMergeDriver(void);
extern void MStackBracket2_TreeWalkRecursive(void);
extern void LinkedListInsert(void);

/* Portable twin. Walks one node's two child chains under an mstack bracket,
 * then links the node into the boot chain.
 *
 * Every child descent is the same three-step shape: set bit 2 of the dirty
 * flags, load the child, and clear the bit again before recursing - so the bit
 * is only observably set across the load, and the second test the original
 * makes against the SAME unreloaded register is dead. It is kept because that
 * is what the code does.
 *
 * The two saved values are pushed and popped through the matrix stack rather
 * than the C stack, and the pops are SKIPPED on every paused exit - the
 * original leaks them deliberately, so an aborted frame leaves the stack deep
 * and the tail `and al, 0xfe` unrun. */
void MStackPush2ChainLLInsert(void)
{
#ifdef TARGET_SDL
  /* MK4_TRACE_FREEPOP family: one line per node DESTRUCTION - detach +
   * merge + push back on the [0x541e80] pool. A live node here is the
   * bad free the pop probe measures. NOTE: this file is the LINKED copy
   * (five_block_dispatch_variants.c holds a dead twin of this symbol). */
  { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
    static int f = -1; static int n;
    if (f < 0) f = getenv("MK4_TRACE_FREEPOP") != 0;
    if (f && n < 220) { n++;
      { unsigned int v_ = *MK4_VA(unsigned int, 0x542044u);
        SDL_Log("FREEKILL node=%x n18=%x n1c=%x l0=%x l4=%x l8=%x l10=%x l14=%x",
              v_,
              v_ ? MK4_NODE_AT(unsigned int, v_, 0x18) : 0u,
              v_ ? MK4_NODE_AT(unsigned int, v_, 0x1c) : 0u,
              v_ ? MK4_NODE_AT(unsigned int, v_, 0) : 0u,
              v_ ? MK4_NODE_AT(unsigned int, v_, 4) : 0u,
              v_ ? MK4_NODE_AT(unsigned int, v_, 8) : 0u,
              v_ ? MK4_NODE_AT(unsigned int, v_, 0x10) : 0u,
              v_ ? MK4_NODE_AT(unsigned int, v_, 0x14) : 0u); } } }
#endif

    unsigned int node = g_currentNodeIdx;
    unsigned int next;

    g_xformDirtyFlags |= 4;
    if (node != 0) {
        g_xformDirtyFlags ^= 4;

        g_matrixStackTop++;
        *MK4_NODE(unsigned int, g_matrixStackTop) = g_xformEntityIdx;
        g_matrixStackTop++;
        *MK4_NODE(unsigned int, g_matrixStackTop) = g_fightGroupHead;

        GuardedChainPushSetCallPop();
        if (g_framePauseFlag != 0)
            return;
        ScaledLoadGuardedJmp();
        if (g_framePauseFlag != 0)
            return;

        g_fightGroupHead = g_currentNodeIdx;
        g_xformDirtyFlags |= 4;
        next = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x1c);
        g_currentNodeIdx = next;
        if (next != 0) {
            g_xformDirtyFlags ^= 4;
            PvsMergeDriver();
        }

        g_walkCallback = 0;
        MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x1c) = 0;
        next = MK4_NODE_AT(unsigned int, g_fightGroupHead, 0x18);
        g_xformDirtyFlags |= 4;
        g_currentNodeIdx = next;
        if (next != 0) {
            g_xformDirtyFlags ^= 4;
            MStackBracket2_TreeWalkRecursive();
            if (g_framePauseFlag != 0)
                return;
        }

        g_currentNodeIdx = g_fightGroupHead;
        g_xformEntityIdx = g_bootChainPair0;
        LinkedListInsert();
        if (g_framePauseFlag != 0)
            return;

        g_fightGroupHead = *MK4_NODE(unsigned int, g_matrixStackTop);
        g_matrixStackTop--;
        g_xformEntityIdx = *MK4_NODE(unsigned int, g_matrixStackTop);
        g_matrixStackTop--;
    }
    g_xformDirtyFlags &= 0xfffffffeu;
}
#else
__declspec(naked) void MStackPush2ChainLLInsert(void) {
    __asm {
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [g_currentNodeIdx]
        push    edi
        mov     edi, 4
        or      edx, edi
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        je      L_mpl_finalAndFE
        mov     ecx, edx
        xor     ecx, edi
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      L_mpl_finalAndFE
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_xformEntityIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_phaseChainTbl], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_phaseChainTbl], edx
        call    GuardedChainPushSetCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mpl_doneNoFE
        call    ScaledLoadGuardedJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_mpl_doneNoFE
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_fightGroupHead], eax
        or      edx, edi
        mov     eax, dword ptr [eax*4 + 0x1c]
        mov     dword ptr [g_xformDirtyFlags], edx
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        je      short L_mpl_skipCall1
        mov     ecx, edx
        xor     ecx, edi
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      short L_mpl_skipCall1
        call    PvsMergeDriver
    L_mpl_skipCall1:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax*4 + 0x1c], 0
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [ecx*4 + 0x18]
        or      edx, edi
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformDirtyFlags], edx
        je      short L_mpl_skipCall2
        mov     ecx, edx
        xor     ecx, edi
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        je      short L_mpl_skipCall2
        call    MStackBracket2_TreeWalkRecursive
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mpl_doneNoFE
    L_mpl_skipCall2:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_bootChainPair0]
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_xformEntityIdx], eax
        call    LinkedListInsert
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mpl_doneNoFE
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + g_phaseChainTbl]
        dec     eax
        mov     dword ptr [g_fightGroupHead], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4 + g_phaseChainTbl]
        dec     eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_mpl_finalAndFE:
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
    L_mpl_doneNoFE:
        pop     edi
        ret
    }
}
#endif
