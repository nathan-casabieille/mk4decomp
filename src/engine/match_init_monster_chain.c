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
extern unsigned int g_counter_0053a51c;
extern unsigned int g_dispatchSave881;
extern unsigned int g_dispatchSave509;
#endif
extern int GuardedScaledLookupCallJmp(void);
extern void AndShlStore(void);
extern void StackPopDispatchTagged(void);
extern void TableWalkBoundedCmp(int);
extern void BootInitGuardedCallChain(void);
extern void DualScaledLitInitJmp(void);
extern void TableWalkPause(void);
extern void QuadCallPhase2(void);
#ifndef NON_MATCHING
extern void StoreTwoCall(void);
#endif
extern void MatchInitMonsterChain(void);

/* @addr 0x00403170 (348b boot) - 3-state install-self phase dispatcher.
 *   Reads phase from [g_baseSel*4 + 0x84], zeroes it, then dispatches
 *   on phase = 0, 1, 2, 3.
 *     - phase 0 / 1: jump to the heavy "first-time init" path that pushes 4
 *       on TableWalkBoundedCmp, calls BootInitGuardedCallChain,
 *       DualScaledLitInitJmp, TableWalkPause, then runs
 *       QuadCallPhase2 with args (g_dlNalt1, g_dlNalt2,
 *       g_counter_0053a51c + 0x12, 0x1d). Pushes two StoreTwoCall calls
 *       with table pointers 0x004a2090 / 0x004a2180. Installs self at
 *       [esi+8]=0x403170 and sets [eax*4+0x84]=2 (with packed_ptr +
 *       0x02000000 tag), then calls MatchInitMonsterChain and asserts the error
 *       flag g_framePauseFlag = 1.
 *     - phase 2: install self at [esi+8]=0x403170, zero [esi+0x84]=3,
 *       set g_pendingNodeType=4, set g_framePauseFlag=1, return.
 *     - phase 3: call GuardedScaledLookupCallJmp, on no-error set
 *       g_walkCallback=3, call AndShlStore, call
 *       StackPopDispatchTagged, return.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern unsigned int g_smState4Way;
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
#define g_counter_0053a51c (*(unsigned int *)MK4_VA(unsigned int, 0x53a51cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave509 (*(unsigned int *)MK4_VA(unsigned int, 0x4a2180u))
#define g_dispatchSave881 (*(unsigned int *)MK4_VA(unsigned int, 0x4a2090u))
#define g_dlNalt1 (*(int *)MK4_VA(int, 0x537f48u))
#define g_dlNalt2 (*(int *)MK4_VA(int, 0x5380e0u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_iatPtr_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_or_0052ab40 (*(unsigned int *)MK4_VA(unsigned int, 0x52ab40u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_save_0053a7d8 (*(unsigned int *)MK4_VA(unsigned int, 0x53a7d8u))
#define g_smState4Way (*(unsigned int *)MK4_VA(unsigned int, 0x541dc8u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void DispatchPair(void);
extern void RoundReset(void);
extern void Cmp2DirtyToggle(void);
extern void ZeroTriple(void);
extern void StageParticleEmitterInit(void);
extern void FiveFieldChainCopyTableWalk(void);
extern void DownloadDualPush(void);
extern void DownloadCharSetup(void);
extern void QuadGuardedCjSet_00422fc0(void);
extern void QuadGuardedCjSet_004230b0(void);
extern void FourGlobalsEqualFInitTail(void);
extern void PvpAngleDistSeed(void);
extern void DualPushCallStore(void);
extern void OrDualStore_0048a190(void);
extern void DualBitGateInitCall(void);
extern void RecordListIterMStack(void);
extern void BitFlagEffectDispatch(void);
extern void DualEntryInstallSelfScaled(void);
extern void DoublePushWalkInitJmp(void);
extern void StackPopDispatchTagged(void);
extern void Thunk_StackPopDispatchTagged_004647f0(void);

/* @addr 0x004228b0 (1061b) - NATIVE ONLY; the matching build synthesizes it.
 *
 * Match init: the scheduled-node handler that turns a loaded pair of
 * characters into a live fight. On its first tick (state 0) it only
 * re-arms itself with a state-1 resume word queued, which is what gives
 * the frame back before the heavy work. State 1 runs the sequence:
 * round reset, the stage particle emitter seeded with both character
 * indices, the field-copy walk, then DownloadDualPush and
 * DownloadCharSetup - the two that build the player entities - with the
 * download-enabled byte held set across them. After that the two match
 * handlers are scheduled (0x4233f0 work 1 and 0x423470 work 2, their node
 * indices parked in the two player probes), a third at 0x430430, and the
 * arena-specific record iterators run for arena 0, 1 and 3 unless any
 * fighter is character 15 or bit 7 of the mode word is set. Every call is
 * pause-guarded and every pause returns immediately - this handler holds
 * no bracket of its own. */
void MatchInitMonsterChain(void)
{
    unsigned int state, v, mode, arena;

    state = MK4_NODE_AT(unsigned int, g_baseSel, 0x84);
    MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
    if (state == 0) {
        /* first tick: re-arm with a state-1 resume word and give the
         * frame back */
        MK4_NODE_AT(unsigned int, g_baseSel, 8) = 0x4228b0u;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 1;
        v = MK4_NODE_AT(unsigned int, g_baseSel, 4);
        g_currentNodeIdx = v;
        *MK4_NODE(unsigned int, v) = 0x4228b0u + 0x1000000u;
        g_currentNodeIdx = v + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 4) = v + 1;
        MK4_NODE_AT(unsigned int, g_baseSel, 0x84) = 0;
        Thunk_StackPopDispatchTagged_004647f0();
        g_framePauseFlag = 1;
        return;
    }

    v = g_save_0053a7d8;
    g_walkCallback = v;
    if (v != 0) {
        v--;
        g_walkCallback = v;
        g_counter_0053a51c = v;
        DispatchPair();
        if (g_framePauseFlag != 0) return;
    }
    RoundReset();
    if (g_framePauseFlag != 0) return;
    Cmp2DirtyToggle();
    if (g_framePauseFlag != 0) return;
    if (g_xformDirtyFlags & 1) {
        ZeroTriple();
        if (g_framePauseFlag != 0) return;
    }

    mode = g_or_0052ab40;
    g_walkCallback = mode;
    g_xformScratch94 = mode & 0x100u;
    if (mode & 0x100u) {
        ZeroTriple();
        if (g_framePauseFlag != 0) return;
    }

    g_walkCallback = g_dlNalt1;
    g_eventQueueCurrent = g_dlNalt2;
    StageParticleEmitterInit();
    if (g_framePauseFlag != 0) return;
    FiveFieldChainCopyTableWalk();
    if (g_framePauseFlag != 0) return;

    *MK4_VA(unsigned char, 0x54371cu) = 1;      /* downloads enabled */
    DownloadDualPush();
    if (g_framePauseFlag != 0) return;
    DownloadCharSetup();
    if (g_framePauseFlag != 0) return;
    Cmp2DirtyToggle();
    if (g_framePauseFlag != 0) return;
    if (g_xformDirtyFlags & 1) {
        QuadGuardedCjSet_00422fc0();
        if (g_framePauseFlag != 0) return;
    }
    Cmp2DirtyToggle();
    if (g_framePauseFlag != 0) return;
    if (g_xformDirtyFlags & 1) {
        QuadGuardedCjSet_004230b0();
        if (g_framePauseFlag != 0) return;
    }

    v = *MK4_VA(unsigned int, 0x535dacu);
    *MK4_VA(unsigned char, 0x54371cu) = 0;
    g_eventQueueCurrent = v;
    if (v != 0) {
        g_walkCallback = g_counter_0053a51c;
        DispatchPair();
        if (g_framePauseFlag != 0) return;
    }
    g_walkCallback = g_counter_0053a51c;
    FourGlobalsEqualFInitTail();
    if (g_framePauseFlag != 0) return;
    PvpAngleDistSeed();
    if (g_framePauseFlag != 0) return;

    StoreTwoCall(0x4233f0u, 1);
    *MK4_VA(unsigned int, 0x538038u) = g_currentNodeIdx;
    StoreTwoCall(0x423470u, 2);
    *MK4_VA(unsigned int, 0x53803cu) = g_currentNodeIdx;
    Cmp2DirtyToggle();
    if (g_framePauseFlag != 0) return;
    if (g_xformDirtyFlags & 1) {
        DualPushCallStore();
        if (g_framePauseFlag != 0) return;
    }
    StoreTwoCall(0x430430u, 0x12);
    *MK4_VA(unsigned int, 0x541df8u) = g_currentNodeIdx;

    mode = g_or_0052ab40;
    g_walkCallback = mode;
    g_xformScratch94 = mode & 0x200u;
    arena = g_counter_0053a51c;
    if ((mode & 0x200u) == 0) {
        g_walkCallback = 2;
        g_eventQueueCurrent = arena;
        if (arena == 4) {
            OrDualStore_0048a190();
            if (g_framePauseFlag != 0) return;
            DualBitGateInitCall();
            arena = g_counter_0053a51c;
            mode = g_or_0052ab40;
        }
    }

    if (g_dlNalt1 != 0xf && g_dlNalt2 != 0xf &&
        *MK4_VA(unsigned int, 0x53a178u) != 0xf &&
        *MK4_VA(unsigned int, 0x53a250u) != 0xf) {
        g_walkCallback = mode;
        g_xformScratch94 = mode & 0x80u;
        if ((mode & 0x80u) == 0) {
            g_eventQueueCurrent = arena;
            g_iatPtr_00542058 = 0x4dfc60u >> 2;
            if (arena == 0) {
                RecordListIterMStack();
                if (g_framePauseFlag != 0) return;
            }
            g_iatPtr_00542058 = 0x4dfc28u >> 2;
            if (g_eventQueueCurrent == 1) {
                RecordListIterMStack();
                if (g_framePauseFlag != 0) return;
            }
            g_iatPtr_00542058 = 0x4dfbf0u >> 2;
            if (g_eventQueueCurrent == 3) {
                RecordListIterMStack();
                if (g_framePauseFlag != 0) return;
            }
        }
    }

    BitFlagEffectDispatch();
    if (g_framePauseFlag != 0) return;
    DualEntryInstallSelfScaled();
    if (g_framePauseFlag != 0) return;
    if (*MK4_VA(unsigned int, 0x543438u) == 0 &&
        *MK4_VA(unsigned int, 0x52aac4u) != 2) {
        DoublePushWalkInitJmp();
        if (g_framePauseFlag != 0) return;
    }
    StackPopDispatchTagged();
}
#else
/* no matching-side C - the synthesizer provides 0x004228b0. */
#endif

#ifndef NON_MATCHING /* naked; no twin yet */
__declspec(naked) void Phase3InstallSelf(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        push    esi
        push    edi
        xor     edi, edi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], edi
        sub     eax, edi
        je      L_p3i_initPath
        dec     eax
        je      L_p3i_initPath
        dec     eax
        je      short L_p3i_phase2
        call    GuardedScaledLookupCallJmp
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p3i_done
        mov     dword ptr [g_walkCallback], 3
        call    AndShlStore
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p3i_done
        call    StackPopDispatchTagged
        pop     edi
        pop     esi
        ret
    L_p3i_phase2:
        mov     dword ptr [g_walkCallback], edi
        mov     dword ptr [g_smState4Way], edi
        mov     dword ptr [esi + 8], offset Phase3InstallSelf
        mov     dword ptr [esi + 0x84], 3
        mov     dword ptr [g_pendingNodeType], 4
        mov     dword ptr [g_framePauseFlag], 1
        pop     edi
        pop     esi
        ret
    L_p3i_initPath:
        push    4
        call    TableWalkBoundedCmp
        add     esp, 4
        call    BootInitGuardedCallChain
        cmp     dword ptr [g_framePauseFlag], edi
        jne     L_p3i_done
        call    DualScaledLitInitJmp
        call    TableWalkPause
        mov     ecx, dword ptr [g_counter_0053a51c]
        mov     edx, dword ptr [g_dlNalt2]
        mov     eax, dword ptr [g_dlNalt1]
        add     ecx, 0x12
        push    0x1d
        push    ecx
        push    edx
        push    eax
        call    QuadCallPhase2
        add     esp, 0x10
        call    BootInitGuardedCallChain
        cmp     dword ptr [g_framePauseFlag], edi
        jne     short L_p3i_done
        push    edi
        push    offset g_dispatchSave881
        call    StoreTwoCall
        add     esp, 8
        push    edi
        push    offset g_dispatchSave509
        call    StoreTwoCall
        mov     dword ptr [esi + 8], offset Phase3InstallSelf
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, offset Phase3InstallSelf
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x84], 2
        mov     eax, dword ptr [esi + 4]
        add     edx, 0x02000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], edx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     eax, dword ptr [g_baseSel]
        mov     dword ptr [eax*4 + 0x84], edi
        call    MatchInitMonsterChain
        mov     dword ptr [g_framePauseFlag], 1
    L_p3i_done:
        pop     edi
        pop     esi
        ret
    }
}
#endif
