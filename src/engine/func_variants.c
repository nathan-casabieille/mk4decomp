/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00428390 (19b naked): Block B - reached only via external
 * jmp from a different call site. Uses _emit jne for the back-jump
 * into Block A and a forward tail-jmp. */
extern unsigned int g_dispatchSave505;
extern unsigned int g_dispatchSave796;
extern unsigned int g_acc_00542078;
extern unsigned int g_table_00535ddc;
extern unsigned int g_dispatchSave1308;
extern unsigned int g_dispatchSave795;
extern unsigned int g_dispatchSave797;
extern unsigned int g_dispatchSave798;
extern unsigned int g_dispatchSave714;
extern unsigned int g_dispatchSave715;
extern unsigned int g_dispatchSave716;
extern unsigned int g_dispatchSave747;
extern unsigned int g_dispatchSave748;
extern unsigned int g_dispatchSave749;
extern unsigned int g_dispatchSave750;
extern unsigned int g_dispatchSave751;
extern unsigned int g_dispatchSave752;
extern unsigned int g_dispatchSave753;
extern unsigned int g_dispatchSave754;
extern unsigned int g_dispatchSave755;
extern unsigned int g_dispatchSave756;
extern unsigned int g_dispatchSave757;
extern unsigned int g_dispatchSave758;
extern unsigned int g_dispatchSave759;
extern unsigned int g_dispatchSave935;
extern unsigned int g_dispatchSave936;
extern unsigned int g_dispatchSave937;
extern unsigned int g_dispatchSave938;
extern unsigned int g_dispatchSave939;
extern unsigned int g_dispatchSave940;
extern unsigned int g_dispatchSave941;
extern void HitReactionStateCluster(void);
extern void DualCallPauseJmpDual(void);
extern void AllocSlotPushTripleGlobals(void);
extern void ArgSarStoreJmp(void);
extern void ArgSar_Set0_Jmp(void);
extern void AudioVolumeRescale(void);
extern void CallSetPause(void);
extern void ConstStoreCallJmp_00448fa0(void);
extern void DirtyOrFlagDispatch(void);
extern void DispatcherComplex181_00426310(void);
extern void DispatcherComplex181_00426490(void);
extern void DispatcherComplex260_00407030(void);
extern void DualCmpSwapStore(void);
extern void DualPushSetCallDualPop(void);
extern void EntryThunkBodyStateMachine(void);
extern void FiveCallGuardSetTail(void);
extern void GatedWordPushCall(void);
extern void GuardedDispatch4_00489080(void);
extern void GuardedSeq_00472840(void);
extern void GuardedSeq_00476de0(void);
extern void GuardedSeq_00476f10(void);
extern void InitZeroChainLookupJmp(void);
extern void InstallSelf3WayChainCmp(void);
extern void InstallSelfCmpJlJmp(void);
extern void InstallSelfIndirectJmp(void);
extern void InstallSelfWithDispatch(void);
extern void LoadStoreDoubleCallSet(void);
extern void LoopGuardedDecJmp(void);
extern void MStackCall_00406340(void);
extern void MStackCall_00406740(void);
extern void MStackChainSwapTraversal(void);
extern void MStackPop4Rewrite(void);
extern void MatchEndFadeFsmCluster(void);
extern void Mul10Tail(void);
extern void PendingMatch_00432ed0(void);
extern void Phase3DispatchScaleInstallSelf(void);
extern void Push70CallScaleArith2(void);
extern void RoundCleanupCluster_00427690(void);
extern void ScaledZero44(void);
extern void Set2CallIncJmp(void);
extern void SlideAttackEventCluster(void);
extern void StoreIncrMStackPush6(void);
extern void StoreLoadJmp(void);
extern void StoreTwoCall(void);
extern void StreamChainStringInstall(void);
extern void TableLookupCall_00489ff0(void);
extern void Thunk_ScaledNeg1SetPause(void);
extern void TripleEntryStateCascade(void);
extern void TripleMStackPushChainStores(void);
extern void MStackPushDualJmp(void);
extern void StackPopDispatchTagged(void);

extern void DualCallPauseDirtyJmp_00490c30(void);
extern void EsiInstallChainCallIndirect(void);
extern void IterStepDualStore(void);
extern void PendingMatch_00459510(void);
extern void Phase3IndirectInstallChain(void);
extern void PushChainAddCallPop(void);

__declspec(naked) void func_00428390(void) {
    __asm {
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     MStackPushDualJmp
        jmp     StackPopDispatchTagged
    }
}

/* @addr 0x004391b0 (20b): twin of DualCallPauseJmpDual at +0x20 in
 * the original packed slot. Reached via OFFSET func_004391b0 references
 * (e.g. from misc_matchesF.c). */
void func_004391b0(void) {
    DualScaledInitClear();
    if (g_framePauseFlag != 0) return;
    FiveCallGuardSetTail();
}

/* @addr 0x00497b30 (15b): set g_eventQueueChild = 1; tail-jmp PunchDispatcher. */
void func_00497b30(void) {
    g_eventQueueChild = 1;
    PunchDispatcherCluster();
}

/* @addr 0x00497b40 (15b): set g_eventQueueChild = 0; tail-jmp PunchDispatcher. */
void func_00497b40(void) {
    g_eventQueueChild = 0;
    PunchDispatcherCluster();
}

/* @addr 0x00436270 (47b): call Cmp2CallDirtyCall; if non-zero ret;
 * else mstack-push HitReactionStateCluster, set walkCallback=2,
 * tail-jmp MstackPopScaledChainPlusThunks. Orphan sub-entry. */
void func_00436270(void) {
    if (Cmp2CallDirtyCall() != 0) return;
    g_walkCallback = (void (*)(void))2;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) =
        (unsigned int)&HitReactionStateCluster;
    MstackPopScaledChainPlusThunks();
}

/* @addr 0x004362a0 (5b): orphan tail-jmp into Cmp30000And18000. */
void func_004362a0(void) {
    Cmp30000And18000();
}

/* @addr 0x00437100 (52b): call LeaPlus22StoreSelf; if !pause set walk=3,
 * mstack-push OFFSET DualCallPauseJmpDual, tail-jmp MstackPopScaledChainPlusThunks.
 * Orphan sub-entry of the original packed block. */
void func_00437100(void) {
    LeaPlus22StoreSelf();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))3;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) =
        (unsigned int)&DualCallPauseJmpDual;
    MstackPopScaledChainPlusThunks();
}

/* @addr 0x0048e3c0 (20b): call DualEntryInitDispatch; if !pause tail-jmp
 * ScaledInitWithCounterAndType_004314f0. Orphan sub-entry of the original packed block. */
void func_0048e3c0(void) {
    DualEntryInitDispatch();
    if (g_framePauseFlag != 0) return;
    ScaledInitWithCounterAndType_004314f0();
}

/* @addr 0x004bf080 (5b) tail-jmp wrapper to LoadStoreRetNopJmp
 * (resolved via the LoadStoreRetNopJmp alias in extras_map). */
void func_004bf080(void) {
    LoadStoreRetNopJmp();
}

/* @addr 0x004bf0a0 (5b) tail-jmp wrapper to AddStore
 * (resolved via the AddStore alias in extras_map). */
void func_004bf0a0(void) {
    AddStore();
}

/* @addr 0x004284a0 (27b): mstack-push the chain callback at +0x20 (func_004284c0)
 * and tail-jmp into the indirect-call dispatcher. Entry A of the original
 * 69-byte packed block; the 5-byte nop gap to entry B is filled by 0x90-fill. */
extern void func_0041f780_pp(void);
extern void func_004284c0(void);
void GuardedLoopWithCallback(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = (unsigned int)&func_004284c0;
    EsiInstallChainCallIndirect();
}

/* @addr 0x004667e0 (5b) tail-jmp wrapper. */
void func_004667e0(void) {
    CallSetPause();
}

/* @addr 0x00482700 (56b): triple call chain with pause-gates; final
 * push+call+pause gate then tail-jmp LiteralPushCallEntZero. */
void func_00482700(void) {
    GateDispatch6c();
    if (g_framePauseFlag != 0) return;
    ScaledChainCmp61();
    if (g_framePauseFlag != 0) return;
    ArgSarStoreJmp(&g_dispatchSave1308);
    if (g_framePauseFlag != 0) return;
    LiteralPushCallEntZero();
}

/* @addr 0x00459fc0 (27b): mstack-push func_00459fe0 onto stack[idx*4], tail-jmp
 * Phase3IndirectInstallChain. Entry A of the original 73-byte packed
 * block; entry B (loop body) lives in func_00459fe0. */
extern void func_00459fe0(void);
void GuardedTwiceLoopback(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = (unsigned int)&func_00459fe0;
    Phase3IndirectInstallChain();
}

/* @addr 0x0042c7c0 (31b): loop body - reload counter from baseSel[+0x5c],
 * decrement, store as new walkCallback; if counter hit zero tail-jmp
 * TripleEntryStateCascade, else loop back to LoopGuardedDecJmp
 * (e9 b6 ff ff ff = rel32 -0x4a). The 2-byte nop gap before this entry is
 * filled by 0x90-fill. */
__declspec(naked) void func_0042c7c0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, dword ptr [eax*4 + 0x5c]
        dec     ecx
        mov     dword ptr [g_walkCallback], ecx
        je      short L_lgdj_done
        jmp     LoopGuardedDecJmp
L_lgdj_done:
        jmp     TripleEntryStateCascade
    }
}

/* @addr 0x00461370 (15b) walk=8 entry */
void func_00461370(void) {
    g_walkCallback = (void (*)(void))8;
    OrDualStore_0048e4b0();
}

/* @addr 0x00461380 (15b) walk=0x10 entry */
void func_00461380(void) {
    g_walkCallback = (void (*)(void))0x10;
    OrDualStore_0048e4b0();
}

/* @addr 0x00461390 (15b) walk=0x20 entry */
void func_00461390(void) {
    g_walkCallback = (void (*)(void))0x20;
    OrDualStore_0048e4b0();
}

/* @addr 0x004613a0 (15b) walk=0x80 entry */
void func_004613a0(void) {
    g_walkCallback = (void (*)(void))0x80;
    OrDualStore_0048e4b0();
}

/* @addr 0x0042ce70 (20b): call GuardedTriple + pause-gated tail-jmp
 * CjInstallSelfRouter. Orphan TCO wrapper. */
void func_0042ce70(void) {
    GuardedTripleCallSwapJmp();
    if (g_framePauseFlag != 0) return;
    CjInstallSelfRouter();
}

/* @addr 0x0042ce90 (34b): double call/pause chain - GuardedTriple,
 * then SetJmp, then tail-jmp CjInstallSelfRouter. Orphan sub-entry. */
void func_0042ce90(void) {
    GuardedTripleCallSwapJmp();
    if (g_framePauseFlag != 0) return;
    SetJmp_Distance3DMul10Chain_0042d080();
    if (g_framePauseFlag != 0) return;
    CjInstallSelfRouter();
}

/* @addr 0x00439fa0 (35b): cmp state_ddc with 0x13333, store at g_walkCallback;
 * if < clear bit 0 of state_208c and ret; if >= tail-jmp IdCascadeBitSet.
 * Orphan sub-entry of the original packed block. */
void func_00439fa0(void) {
    unsigned int v = g_table_00535ddc;
    g_walkCallback = v;
    if ((int)v < 0x13333) {
        g_xformDirtyFlags &= 0xfffffffeu;
        return;
    }
    IdCascadeBitSet();
}

/* h2 @ 0x00498730 (64b): threshold check + tail-jmp
 * ScaledIndirectJmp_0049c850. */
void func_00498730(void) {
    PushChainAddCallPop();
    if (g_framePauseFlag) return;
    Vec2SumMul10ChainCompute();
    if (g_framePauseFlag) return;
    if ((int)g_eventQueueCurrent <= (int)g_eventQueueWorkType) return;
    ScaledIndirectJmp_0049c850();
}

/* h3 @ 0x00498770 (32b): MStackCall + tail-jmp CallSetPause.
 * Standard TCO wrapper. */
void func_00498770(void) {
    MStackCall_00406740();
    if (g_framePauseFlag) return;
    CallSetPause();
}

/* h4 @ 0x00498790 (357b naked): pose-fn state machine. Keep naked:
 * self-ref via `mov [esi+8], offset L_qsv_main` (DIR32 reloc to
 * internal label) + callee-saved ebx/esi register caching. */
__declspec(naked) void func_00498790(void)
{
    __asm
    {
    L_qsv_main:
        mov     eax, dword ptr [g_baseSel]
        push    ebx
        push    esi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x84]
        mov     dword ptr [esi + 0x84], 0
        sub     eax, 0
        je      short L_qsv_phase0
        dec     eax
        call    MStackChainSwapTraversal
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_qsv_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x30]
        cmp     eax, 0x62
        mov     dword ptr [g_walkCallback], eax
        jne     short L_qsv_callPause
        call    SlideAttackEventCluster
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_qsv_ret
    L_qsv_callPause:
        call    CallSetPause
        pop     esi
        pop     ebx
        ret
    L_qsv_phase0:
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ebx, 1
        mov     dword ptr [g_eventQueueEnd], eax
        mov     eax, dword ptr [eax*4 + 0x30]
        cmp     eax, 0x6c
        mov     dword ptr [g_walkCallback], eax
        je      short L_qsv_install1
        mov     dword ptr [g_walkCallback], 0x12c
        call    AudioVolumeRescale
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_qsv_ret
        test    byte ptr [g_xformDirtyFlags], bl
        jne     short L_qsv_install2
    L_qsv_install1:
        mov     dword ptr [esi + 8], offset L_qsv_main
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, offset L_qsv_main
        mov     dword ptr [edx*4 + 0x84], 2
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x2000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    InitZeroChainLookupJmp
        mov     dword ptr [g_framePauseFlag], ebx
        pop     esi
        pop     ebx
        ret
    L_qsv_install2:
        mov     dword ptr [esi + 8], offset L_qsv_main
        mov     eax, dword ptr [g_baseSel]
        mov     ecx, offset L_qsv_main
        mov     dword ptr [eax*4 + 0x84], ebx
        mov     eax, dword ptr [esi + 4]
        add     ecx, 0x1000000
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [esi + 4], eax
        mov     edx, dword ptr [g_baseSel]
        mov     dword ptr [edx*4 + 0x84], 0
        call    Phase3DispatchScaleInstallSelf
        mov     dword ptr [g_framePauseFlag], ebx
    L_qsv_ret:
        pop     esi
        pop     ebx
        ret
    }
}

/* h2 @ 0x00498930 (80b): event 004f21d0 forwarder w/ 0x30b status.
 * Sister of h7 (different imm and event addr). */
void func_00498930(void) {
    unsigned int v;
    g_walkCallback = 7;
    ScaledIndexConditionalAdd();
    if (g_framePauseFlag) return;
    CondPickDualStore();
    if (g_framePauseFlag) return;
    v = 0x30b;
    g_walkCallback = v;
    ((ScenegraphNode *)(g_baseSel * 4))->fsm_state = v;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave795);
}

/* h3 @ 0x00498980 (368b naked): pose copy + 0x23d7 ratio + event
 * 004f2240. Keep naked: 13+ intermediate `mov [g_walkCallback], reg`
 * stores that pure C dead-store-eliminates; callee-saved esi for
 * cross-call value retention; reload-via-global pattern. */
__declspec(naked) void func_00498980(void)
{
    __asm {
        /* === h3 (0x498980): pose copy + 0x23d7 ratio + 004f2240 === */
        mov      dword ptr [g_walkCallback], 0x47
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8ae4
        call     DualCmpSwapStore
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8ae4
        mov      eax, OFFSET g_dispatchSave505
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        call     DispatcherComplex260_00407030
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8ae4
        call     MStackCall_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8ae4
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x43
        mov      dword ptr [g_walkCallback], eax
        push     esi
        mov      dword ptr [ecx*4 + 0x30], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        lea      eax, [edx*4]
        mov      edx, dword ptr [ecx*4 + 0x54]
        mov      dword ptr [g_walkCallback], edx
        mov      esi, dword ptr [ecx*4 + 0x58]
        mov      dword ptr [g_eventQueueCurrent], esi
        mov      ecx, dword ptr [ecx*4 + 0x5c]
        mov      dword ptr [g_eventQueueWorkType], ecx
        mov      dword ptr [eax + 0x54], edx
        mov      edx, dword ptr [g_eventQueueCurrent]
        mov      dword ptr [eax + 0x58], edx
        mov      ecx, dword ptr [g_eventQueueWorkType]
        mov      dword ptr [eax + 0x5c], ecx
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x34]
        and      eax, 1
        mov      dword ptr [g_walkCallback], eax
        mov      edx, dword ptr [ecx*4 + 0x34]
        or       eax, edx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x34], eax
        mov      eax, dword ptr [g_currentNodeFlags]
        push     eax
        push     0x23d7
        call     Mul10Tail
        mov      ecx, dword ptr [g_xformScratch2088]
        add      esp, 8
        mov      dword ptr [g_currentNodeFlags], eax
        push     ecx
        push     0x23d7
        call     Mul10Tail
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_xformScratch2088], eax
        mov      eax, dword ptr [g_currentNodeFlags]
        add      esp, 8
        mov      dword ptr [edx*4 + 0x6c], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_xformScratch2088]
        push     OFFSET g_dispatchSave796
        mov      dword ptr [ecx*4 + 0x74], edx
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      dword ptr [g_fightGroupHead], eax
        call     ArgSar_Set0_Jmp
        add      esp, 4
        pop      esi
    L_8ae4:
        ret
    }
}

/* h4 @ 0x00498af0 (48b): Vec2SumMul10ChainCompute + threshold check
 * (signed cmp [70] vs [74]) -> tail-jmp ScaledIndirectJmp. */
void func_00498af0(void) {
    Vec2SumMul10ChainCompute();
    if (g_framePauseFlag) return;
    if ((int)g_eventQueueCurrent <= (int)g_eventQueueWorkType) return;
    ScaledIndirectJmp_0049c850();
}

/* h5 @ 0x00498b20 (144b naked): pose-fn 2-state. Keep naked: the
 * `mov [esi+8], OFFSET L_8b20` installs the function's own internal
 * label as a callback (DIR32 reloc to mid-function address - not
 * expressible in pure C). */
__declspec(naked) void func_00498b20(void)
{
    __asm {
        /* === h5 (0x498b20): pose-fn 2-state w/ 489ff0 + 406740 === */
    L_8b20:
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        test     eax, eax
        je       short L_8b61
        mov      dword ptr [g_walkCallback], 0x49
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8ba8
        call     CallSetPause
        pop      esi
        ret
    L_8b61:
        call     MStackCall_00406740
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8ba8
        mov      dword ptr [g_walkCallback], 0x48
        call     TableLookupCall_00489ff0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      short L_8ba8
        mov      eax, 1
        mov      dword ptr [esi + 8], OFFSET L_8b20
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], 0xa
        mov      dword ptr [g_framePauseFlag], eax
    L_8ba8:
        pop      esi
        ret
    }
}

/* h6 @ 0x00498bb0 (32b): MStackCall + pause-test -> tail-jmp
 * CallSetPause. Standard TCO wrapper. */
void func_00498bb0(void) {
    MStackCall_00406740();
    if (g_framePauseFlag) return;
    CallSetPause();
}

/* h7 @ 0x00498bd0 (64b): event 004f2250 forwarder w/ 0x309 status.
 * Sister of h2 with different imm and event addr. */
void func_00498bd0(void) {
    unsigned int v;
    CondPickDualStore();
    if (g_framePauseFlag) return;
    v = 0x309;
    g_walkCallback = v;
    ((ScenegraphNode *)(g_baseSel * 4))->fsm_state = v;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave797);
}

/* h8 @ 0x00498c10 (42b): chained DualCmpSwapStore +
 * MstackPushPackChainInit + ArgSar_Set0_Jmp w/ event 004f2298. */
void func_00498c10(void) {
    DualCmpSwapStore();
    if (g_framePauseFlag) return;
    MstackPushPackChainInit();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSar_Set0_Jmp)(&g_dispatchSave798);
}

/* h3 @ 0x0047c3c0 (48b): chained event 004ed2f0 -> 004ed2f8 forwarder. */
void func_0047c3c0(void) {
    ((void (*)(void *))IterStepDualStore)(&g_dispatchSave714);
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave715);
}

/* h4 @ 0x0047c3f0 (288b naked): pose-fn 2-state. Keep naked: self-ref
 * via OFFSET L_c3f0 + cross-ref to func_0047c510 via OFFSET. */
extern void func_0047c510(void);
__declspec(naked) void func_0047c3f0(void)
{
    __asm {
        /* === h4 (0x47c3f0): pose-fn 2-state w/ 0xfffc0000 + 48f3f0 === */
    L_c3f0:
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_c4a2
        call     ScaledZero44
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_c50e
        mov      ecx, dword ptr [g_baseSel]
        mov      eax, 0xfffc0000
        mov      edx, dword ptr [ecx*4 + 0x38]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [eax*4 + 0x58], edx
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      eax, 0x51e
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x4c], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_walkCallback]
        mov      dword ptr [edx*4 + 0x4c], eax
        mov      eax, dword ptr [g_matrixStackTop]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], OFFSET func_0047c510
        jmp      InstallSelfIndirectJmp
    L_c4a2:
        mov      dword ptr [g_eventQueueNotMask], 0x30000
        mov      dword ptr [eax + 8], OFFSET L_c3f0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, OFFSET L_c3f0
        add      edx, 0x1000000
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfCmpJlJmp
        mov      dword ptr [g_framePauseFlag], 1
    L_c50e:
        ret
    }
}


/* h6 @ 0x0047c530 (64b naked): swap-side pose [+0x70] add 0x51e on
 * both sides. Keep naked: redundant `mov [g_walkCallback], reg`
 * stores before final indexed-store. */
__declspec(naked) void func_0047c530(void)
{
    __asm {
        /* === h6 (0x47c530): swap-side pose [+0x70] add 0x51e === */
        mov      eax, dword ptr [g_player2NodeIdx]
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [g_player1NodeIdx]
        cmp      ecx, eax
        je       short L_c54e
        mov      dword ptr [g_currentNodeIdx], eax
    L_c54e:
        mov      eax, dword ptr [ecx*4 + 0x70]
        add      eax, 0x51e
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x70], eax
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_walkCallback]
        mov      dword ptr [ecx*4 + 0x70], edx
        ret
    }
}

/* h7 @ 0x0047c580 (93b): event 004ed308 via 3-call chain w/ 0x200d
 * store + bit-1 fail-first dispatch to SevenThunks.
 * (Source comment had stale "0x47c570" address - real is 0x47c580.) */
void func_0047c580(void) {
    unsigned int v;
    ScaledAndAh();
    if (g_framePauseFlag) return;
    DualCallPauseDirtyJmp_00490c30();
    if (g_framePauseFlag) return;
    v = 0x200d;
    g_walkCallback = v;
    ((ScenegraphNode *)(g_baseSel * 4))->fsm_state = v;
    ScaledChainAndF000DirtyToggle();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        SevenThunks();
        return;
    }
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave716);
}

/* h2 @ 0x00482200 (32b): event 004edb98 forwarder. */
void func_00482200(void) {
    GateDispatch6c();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave747);
}

/* h3 @ 0x00482220 (32b): event 004edba8 forwarder. */
void func_00482220(void) {
    GateDispatch6c();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave748);
}

/* h4 @ 0x00482240 (80b): 0x1b333 + ScaledMove48to58 + event 004edbf0. */
void func_00482240(void) {
    GateDispatch6c();
    if (g_framePauseFlag) return;
    g_walkCallback = 0x1b333;
    g_eventQueueCurrent = 0;
    Wrapper_IterLoad_0048fd30_004f12ac();
    if (g_framePauseFlag) return;
    ScaledMove48to58();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave749);
}

/* h5 @ 0x00482290 (48b): 488f00 + 494580 + event 004edc18. */
void func_00482290(void) {
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    GateDispatch6c();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave750);
}

/* h6 @ 0x004822c0 (16b): bare event 004edc60 forwarder. */
void func_004822c0(void) {
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave751);
}

/* h7 @ 0x004822d0 (16b): bare event 004edc80 forwarder. */
void func_004822d0(void) {
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave752);
}

/* h8 @ 0x004822e0 (128b naked): pose-fn install state 1.
 * Keep naked: self-ref `mov [eax+8], OFFSET L_22e0` + `mov edi,
 * OFFSET L_22e0` (DIR32 reloc to function's own entry label). */
__declspec(naked) void func_004822e0(void)
{
    __asm {
        /* === h8 (0x4822e0): pose-fn install state 1 w/ 00489080 === */
    L_22e0:
        mov      eax, dword ptr [g_baseSel]
        xor      edx, edx
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], edx
        cmp      ecx, edx
        je       short L_22ff
        jmp      FiveCallGuardSetTail
    L_22ff:
        mov      dword ptr [eax + 8], OFFSET L_22e0
        mov      ecx, dword ptr [g_baseSel]
        push     edi
        mov      edi, OFFSET L_22e0
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        add      edi, 0x1000000
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edi
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], edx
        call     GuardedDispatch4_00489080
        mov      dword ptr [g_framePauseFlag], 1
        pop      edi
        ret
    }
}

/* h9 @ 0x00482360 (80b): 0x8000 + CmpP1DualInitStore + chain + event
 * 004edca8. (Comment said 0x482350 but real addr is 0x482360.) */
void func_00482360(void) {
    g_walkCallback = 0x8000;
    CmpP1DualInitStore_00482ab0();
    if (g_framePauseFlag) return;
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    GateDispatch6c();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave753);
}

/* h10 @ 0x004823b0 (48b): 488f00 + 494580 + event 004edcf0. */
void func_004823b0(void) {
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    GateDispatch6c();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave754);
}

/* h11 @ 0x004823e0 (64b): event 004edd20 + tail-jmp Wrapper_Cascade5StageInit_004ef208. */
void func_004823e0(void) {
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    GateDispatch6c();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave755);
    if (g_framePauseFlag) return;
    Wrapper_Cascade5StageInit_004ef208();
}

/* h12 @ 0x00482420 (80b): 0x8000 + CmpP1DualInitStore + chain +
 * event 004edd58 + tail-jmp Wrapper_Cascade5StageInit_004ef208. */
void func_00482420(void) {
    g_walkCallback = 0x8000;
    CmpP1DualInitStore_00482ab0();
    if (g_framePauseFlag) return;
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    GateDispatch6c();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave756);
    if (g_framePauseFlag) return;
    Wrapper_Cascade5StageInit_004ef208();
}

/* h12b @ 0x00482470 (16b): bare event 004edd90 forwarder. */
void func_00482470(void) {
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave757);
}

/* h13 @ 0x00482480 (48b): 488f00 + 494580 + event 004eddb8. */
void func_00482480(void) {
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    GateDispatch6c();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave758);
}

/* h14 @ 0x004824b0 (48b): 488f00 + 494580 + event 004ede00. */
void func_004824b0(void) {
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    GateDispatch6c();
    if (g_framePauseFlag) return;
    ((void (*)(void *))ArgSarStoreJmp)(&g_dispatchSave759);
}

/* h15 @ 0x004824e0 (30b): wait 6 + EntryThunkBodyStateMachine -> tail
 * EightEntryAlarmDispatch. */
void func_004824e0(void) {
    g_eventQueueNotMask = 6;
    EntryThunkBodyStateMachine();
    if (g_framePauseFlag) return;
    EightEntryAlarmDispatch();
}

/* Part 2 @ 0x00431c70 (5b): 1-line tail-jmp wrapper to
 * InstallSelfState88. Packed as a trailing sub-entry of
 * the 853-byte AiAngleDistComputation symbol (11-byte nop
 * pad between Part 1's ret and this entry, filled via synth 0x90). */
void func_00431c70(void) {
    InstallSelfState88();
}

/* @addr 0x0044f3d0 (28b) */
void func_0044f3d0(void) {
    unsigned int v = (unsigned int)&g_dispatchSave935;
    g_xformScratch2088 = 0x2666;
    v >>= 2;
    g_eventQueueIdx = v;
    DualSubInstallChain();
}

/* @addr 0x0044f3f0 (28b) */
void func_0044f3f0(void) {
    unsigned int v = (unsigned int)&g_dispatchSave936;
    g_xformScratch2088 = 0x4ccc;
    v >>= 2;
    g_eventQueueIdx = v;
    DualSubInstallChain();
}

/* @addr 0x0044f410 (28b) */
void func_0044f410(void) {
    unsigned int v = (unsigned int)&g_dispatchSave937;
    g_xformScratch2088 = 0x4ccc;
    v >>= 2;
    g_eventQueueIdx = v;
    DualSubInstallChain();
}

/* @addr 0x0044f430 (28b) */
void func_0044f430(void) {
    unsigned int v = (unsigned int)&g_dispatchSave938;
    g_xformScratch2088 = 0x4ccc;
    v >>= 2;
    g_eventQueueIdx = v;
    DualSubInstallChain();
}

/* @addr 0x0044f450 (28b) */
void func_0044f450(void) {
    unsigned int v = (unsigned int)&g_dispatchSave939;
    g_xformScratch2088 = 0x4ccc;
    v >>= 2;
    g_eventQueueIdx = v;
    DualSubInstallChain();
}

/* @addr 0x0044f470 (28b) */
void func_0044f470(void) {
    unsigned int v = (unsigned int)&g_dispatchSave940;
    g_xformScratch2088 = 0x4ccc;
    v >>= 2;
    g_eventQueueIdx = v;
    DualSubInstallChain();
}

/* @addr 0x0044f490 (28b) */
void func_0044f490(void) {
    unsigned int v = (unsigned int)&g_dispatchSave941;
    g_xformScratch2088 = 0x1999;
    v >>= 2;
    g_eventQueueIdx = v;
    DualSubInstallChain();
}

/* @addr 0x00432710 (1973b): entries B+C of the original packed slot.
 * Hand-rolled prologues (push interleaved with body code) and constant
 * register caching (ebx=4, esi=0xff*0000) are non-coaxable in pure C.
 * Internal data-table reference at 0x00432a70 (entry C label) preserved. */
__declspec(naked) void func_00432710(void) {
    __asm {
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeFlags]
        inc      eax
        push     ebx
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_pendingNodeType]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        call     PendingMatch_00432ed0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        test     byte ptr [g_xformDirtyFlags], 1
        je       L_2a19
        push     0x228
        call     DualPushSetCallDualPop
        mov      al, byte ptr [g_xformDirtyFlags]
        add      esp, 4
        test     al, 1
        jne      L_2a19
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      eax, 0x4e4458
        shr      eax, 2
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        add      ecx, eax
        mov      dword ptr [g_currentNodeFlags], ecx
        call     StoreIncrMStackPush6
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        mov      ebx, 4
        mov      dword ptr [g_eventQueueWorkType], 0x23e
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_acc_00542078], 0xfe9d0000
        mov      dword ptr [g_eventQueueNotMask], 0xff9c0000
        mov      dword ptr [g_currentNodeFlags], 1
        call     DispatcherComplex181_00426490
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        call     RoundCleanupCluster_00427690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2a19
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x18000
        mov      dword ptr [g_eventQueueChild], eax
        mov      dword ptr [ecx*4 + 0x5c], eax
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        mov      edx, 0x4d55a8
        mov      dword ptr [g_walkCallback], 0x23f
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_acc_00542078], 0xfecf0000
        mov      dword ptr [g_eventQueueNotMask], 0xff9c0000
        call     Push70CallScaleArith2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2a19
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      eax, dword ptr [g_currentNodeFlags]
        lea      eax, [eax + eax*4]
        lea      eax, [eax + eax*4]
        shl      eax, 2
        mov      dword ptr [g_currentNodeFlags], eax
        sar      eax, 0x10
        mov      dword ptr [g_walkCallback], eax
        call     StoreIncrMStackPush6
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_eventQueueWorkType], 0x240
        mov      dword ptr [g_acc_00542078], 0xfe540000
        mov      dword ptr [g_eventQueueNotMask], 0xffb00000
        mov      dword ptr [g_currentNodeFlags], 1
        call     DispatcherComplex181_00426490
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        call     RoundCleanupCluster_00427690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2a19
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueChild]
        mov      dword ptr [edx*4 + 0x5c], eax
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        mov      ecx, 0x4d55b0
        mov      dword ptr [g_walkCallback], 0x241
        shr      ecx, 2
        mov      dword ptr [g_xformEntityIdx], ecx
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_acc_00542078], 0xfecf0000
        mov      dword ptr [g_eventQueueNotMask], 0xffb00000
        call     Push70CallScaleArith2
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2a6a
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2a19
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [g_eventQueueChild]
        push     0x228
        push     0x432f00
        mov      dword ptr [edx*4 + 0x5c], eax
        mov      dword ptr [g_eventQueueIdx], 0
        call     StoreTwoCall
        add      esp, 8
    L_2a19:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_pendingNodeType], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeFlags], edx
        mov      dword ptr [g_matrixStackTop], eax
    L_2a6a:
        pop      ebx
        ret      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_currentNodeFlags]
        inc      eax
        push     ebx
        mov      dword ptr [g_matrixStackTop], eax
        push     esi
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_pendingNodeType]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [g_eventQueueIdx]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], edx
        call     PendingMatch_00432ed0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        test     byte ptr [g_xformDirtyFlags], 1
        je       L_2e71
        push     0x229
        call     DualPushSetCallDualPop
        mov      al, byte ptr [g_xformDirtyFlags]
        add      esp, 4
        test     al, 1
        jne      L_2e71
        mov      ecx, dword ptr [g_currentNodeFlags]
        mov      eax, 0x4e4458
        shr      eax, 2
        mov      dword ptr [g_eventQueueChild], 0x18000
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [eax*4]
        add      ecx, eax
        mov      dword ptr [g_currentNodeFlags], ecx
        call     StoreIncrMStackPush6
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        mov      ebx, 4
        mov      esi, 0xffa00000
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_eventQueueWorkType], 0x242
        mov      dword ptr [g_acc_00542078], 0x1310000
        mov      dword ptr [g_eventQueueNotMask], esi
        mov      dword ptr [g_currentNodeFlags], 1
        call     DispatcherComplex181_00426310
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        call     RoundCleanupCluster_00427690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2e71
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_eventQueueChild]
        mov      dword ptr [ecx*4 + 0x5c], edx
        mov      eax, dword ptr [g_walkCallback]
        cmp      eax, 0xa
        jb       L_2c3b
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        mov      eax, 0x4d55a8
        mov      dword ptr [g_walkCallback], 0x243
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_acc_00542078], 0x14d0000
        mov      dword ptr [g_eventQueueNotMask], esi
        call     StreamChainStringInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2e71
        jmp      L_2caa
    L_2c3b:
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        mov      eax, 0x4d55a8
        mov      dword ptr [g_walkCallback], 0x243
        shr      eax, 2
        mov      dword ptr [g_xformEntityIdx], eax
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_acc_00542078], 0x1430000
        mov      dword ptr [g_eventQueueNotMask], esi
        call     StreamChainStringInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2e71
    L_2caa:
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      edx, dword ptr [g_eventQueueChild]
        mov      dword ptr [ecx*4 + 0x5c], edx
        mov      eax, dword ptr [g_currentNodeFlags]
        lea      eax, [eax + eax*4]
        lea      eax, [eax + eax*4]
        shl      eax, 2
        mov      dword ptr [g_currentNodeFlags], eax
        sar      eax, 0x10
        mov      dword ptr [g_walkCallback], eax
        call     StoreIncrMStackPush6
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        mov      esi, 0xffb40000
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_eventQueueWorkType], 0x244
        mov      dword ptr [g_acc_00542078], 0x1310000
        mov      dword ptr [g_eventQueueNotMask], esi
        mov      dword ptr [g_currentNodeFlags], 1
        call     DispatcherComplex181_00426310
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        call     RoundCleanupCluster_00427690
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2e71
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueChild]
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      eax, dword ptr [g_walkCallback]
        cmp      eax, 0xa
        jb       L_2dd7
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        mov      edx, 0x4d55b0
        mov      dword ptr [g_walkCallback], 0x245
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_acc_00542078], 0x14a0000
        mov      dword ptr [g_eventQueueNotMask], esi
        call     StreamChainStringInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2e71
        jmp      L_2e43
    L_2dd7:
        call     AllocSlotPushTripleGlobals
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        mov      edx, 0x4d55b0
        mov      dword ptr [g_walkCallback], 0x245
        shr      edx, 2
        mov      dword ptr [g_xformEntityIdx], edx
        mov      dword ptr [g_eventQueueCurrent], ebx
        mov      dword ptr [g_acc_00542078], 0x1400000
        mov      dword ptr [g_eventQueueNotMask], esi
        call     StreamChainStringInstall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        call     MStackPop4Rewrite
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_2ec2
        test     byte ptr [g_xformDirtyFlags], bl
        jne      L_2e71
    L_2e43:
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_eventQueueChild]
        push     0x229
        push     0x432f00
        mov      dword ptr [eax*4 + 0x5c], ecx
        mov      dword ptr [g_eventQueueIdx], 1
        call     StoreTwoCall
        add      esp, 8
    L_2e71:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_eventQueueIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_pendingNodeType], ecx
        mov      dword ptr [g_matrixStackTop], eax
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeIdx], edx
        mov      dword ptr [g_matrixStackTop], eax
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_currentNodeFlags], ecx
        mov      dword ptr [g_matrixStackTop], eax
    L_2ec2:
        pop      esi
        pop      ebx
        ret      
    }
}

void func_00448810(void) {
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0x3b;
    g_walkCallback = 0x1c;
    GatedWordPushCall();
    if (g_framePauseFlag != 0) return;
    ((void (*)(int))ArgSarStoreJmp)(0x4e62c8);
}

void func_00448850(void) {
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0x83;
    g_walkCallback = 0x29;
    GatedWordPushCall();
    if (g_framePauseFlag != 0) return;
    ((void (*)(int))ArgSarStoreJmp)(0x4e62d8);
}

void func_00448890(void) {
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0x94;
    g_walkCallback = 0x1b;
    GatedWordPushCall();
    if (g_framePauseFlag != 0) return;
    ((void (*)(int))ArgSarStoreJmp)(0x4e62e8);
}

void func_004488d0(void) {
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0xa6;
    g_walkCallback = 0x2a;
    GatedWordPushCall();
    if (g_framePauseFlag != 0) return;
    ((void (*)(int))ArgSarStoreJmp)(0x4e62f8);
}

void func_00448910(void) {
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0xb9;
    g_walkCallback = 0x1b;
    GatedWordPushCall();
    if (g_framePauseFlag != 0) return;
    ((void (*)(int))ArgSarStoreJmp)(0x4e6308);
}

void func_00448950(void) {
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0xce;
    g_walkCallback = 0x2b;
    GatedWordPushCall();
    if (g_framePauseFlag != 0) return;
    ((void (*)(int))ArgSarStoreJmp)(0x4e6318);
}

/* @addr 0x00448990 (1543b): entry H+ of the original packed block. Multiple
 * install-self states reachable via internal pointers (0x448990, 0x448ce0,
 * 0x448e10, etc.); hand-rolled prologues, push esi interleaved with body
 * setup, and constant register caching make pure-C conversion impractical. */
__declspec(naked) void func_00448990(void) {
    __asm {
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_8a7f
        dec      eax
        je       L_89fc
        call     Set2CallIncJmp
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8b40
        mov      dword ptr [g_eventQueueNotMask], 5
        call     EntryThunkBodyStateMachine
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8b40
        push     0x4e6328
        call     ArgSarStoreJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        pop      esi
        ret      
    L_89fc:
        mov      ecx, dword ptr [g_fightGroupHead]
        mov      dword ptr [ecx*4 + 0x28], 0x116
        mov      dword ptr [g_walkCallback], 0x12
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8b40
        mov      dword ptr [g_eventQueueNotMask], 5
        call     EntryThunkBodyStateMachine
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8b40
        mov      dword ptr [g_eventQueueChild], 0x133
        mov      dword ptr [esi + 8], 0x448990
        mov      edx, dword ptr [g_baseSel]
        mov      ecx, 0x448990
        add      ecx, 0x2000000
        mov      dword ptr [edx*4 + 0x84], 2
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
        jmp      L_8b0b
    L_8a7f:
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [eax*4 + 0x28], 0xe1
        mov      dword ptr [g_walkCallback], 3
        call     GuardedSeq_00476f10
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8b40
        mov      eax, dword ptr [g_baseSel]
        push     0x448b50
        mov      ecx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      edx, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_eventQueueIdx], edx
        call     StoreLoadJmp
        mov      dword ptr [g_eventQueueChild], 0x115
        mov      dword ptr [esi + 8], 0x448990
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, 0x448990
        add      esp, 4
        add      ecx, 0x1000000
        mov      dword ptr [eax*4 + 0x84], 1
        mov      eax, dword ptr [esi + 4]
        mov      dword ptr [g_currentNodeIdx], eax
    L_8b0b:
        mov      dword ptr [eax*4], ecx
        mov      eax, dword ptr [g_currentNodeIdx]
        inc      eax
        mov      dword ptr [g_currentNodeIdx], eax
        mov      dword ptr [esi + 4], eax
        mov      edx, dword ptr [g_baseSel]
        mov      dword ptr [edx*4 + 0x84], 0
        call     InstallSelf3WayChainCmp
        mov      dword ptr [g_framePauseFlag], 1
    L_8b40:
        pop      esi
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      dword ptr [g_walkCallback], 0xc
        call     GuardedSeq_00472840
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8cd2
        mov      dword ptr [g_walkCallback], 0x16
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8cd2
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [g_fightGroupHead], ecx
        call     TripleMStackPushChainStores
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8cd2
        test     byte ptr [g_xformDirtyFlags], 4
        je       L_8bd8
        jmp      Thunk_ScaledNeg1SetPause
    L_8bd8:
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x58]
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [ecx*4 + 0x58], eax
        mov      edx, dword ptr [g_fightGroupHead]
        mov      ecx, dword ptr [g_currentNodeIdx]
        mov      eax, dword ptr [edx*4 + 0x3c]
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      edx, dword ptr [g_currentNodeIdx]
        mov      eax, 0x7e
        mov      dword ptr [g_walkCallback], eax
        mov      dword ptr [edx*4 + 0x30], eax
        call     MStackCall_00406340
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8cd2
        mov      eax, dword ptr [g_currentNodeIdx]
        push     0x4745e0
        mov      dword ptr [g_fightGroupHead], eax
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [eax*4 + 0x64]
        mov      dword ptr [g_eventQueueEnd], ecx
        mov      edx, dword ptr [eax*4 + 0x68]
        mov      dword ptr [g_eventQueueIdx], edx
        call     StoreLoadJmp
        add      esp, 4
        push     0x448e10
        call     StoreLoadJmp
        add      esp, 4
        mov      dword ptr [g_walkCallback], 0xb
        call     GuardedSeq_00476de0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8cd2
        mov      dword ptr [g_walkCallback], 0xc
        call     GuardedSeq_00476de0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8cd2
        mov      dword ptr [g_walkCallback], 4
        call     DirtyOrFlagDispatch
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8cd2
        push     0x4e6338
        call     ArgSarStoreJmp
        add      esp, 4
    L_8cd2:
        ret      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        shl      eax, 2
        mov      ecx, dword ptr [eax + 0x84]
        mov      dword ptr [eax + 0x84], 0
        test     ecx, ecx
        je       L_8d0f
        push     0x4e6348
        call     ArgSarStoreJmp
        mov      eax, dword ptr [g_framePauseFlag]
        add      esp, 4
        ret      
    L_8d0f:
        mov      dword ptr [g_eventQueueChild], 0x6d
        mov      dword ptr [eax + 8], 0x448ce0
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, 0x448ce0
        add      edx, 0x1000000
        mov      dword ptr [ecx*4 + 0x84], 1
        mov      ecx, dword ptr [eax + 4]
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [ecx*4], edx
        mov      ecx, dword ptr [g_currentNodeIdx]
        inc      ecx
        mov      dword ptr [g_currentNodeIdx], ecx
        mov      dword ptr [eax + 4], ecx
        mov      eax, dword ptr [g_baseSel]
        mov      dword ptr [eax*4 + 0x84], 0
        call     InstallSelfWithDispatch
        mov      dword ptr [g_framePauseFlag], 1
        ret      
        nop      
        nop      
        nop      
        nop      
        mov      eax, dword ptr [g_fightGroupHead]
        mov      dword ptr [eax*4 + 0x28], 0x7b
        mov      dword ptr [g_walkCallback], 0x17
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8dcd
        mov      dword ptr [g_eventQueueNotMask], 9
        call     EntryThunkBodyStateMachine
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8dcd
        push     0x4e6358
        call     ArgSarStoreJmp
        add      esp, 4
    L_8dcd:
        ret      
        nop      
        nop      
        mov      dword ptr [g_walkCallback], 0x17
        call     GatedWordPushCall
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8e0d
        mov      dword ptr [g_eventQueueNotMask], 9
        call     EntryThunkBodyStateMachine
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8e0d
        push     0x4e6368
        call     ArgSarStoreJmp
        add      esp, 4
    L_8e0d:
        ret      
        nop      
        nop      
        mov      eax, dword ptr [g_baseSel]
        push     esi
        lea      esi, [eax*4]
        mov      eax, dword ptr [eax*4 + 0x84]
        mov      dword ptr [esi + 0x84], 0
        sub      eax, 0
        je       L_8eec
        dec      eax
        mov      eax, dword ptr [g_eventQueueEnd]
        je       L_8e60
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        jns      L_8e88
        call     ConstStoreCallJmp_00448fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8f95
        call     Thunk_ScaledNeg1SetPause
        pop      esi
        ret      
    L_8e60:
        dec      eax
        mov      dword ptr [g_eventQueueEnd], eax
        jns      L_8f2d
        call     ConstStoreCallJmp_00448fa0
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8f95
        mov      dword ptr [g_eventQueueEnd], 0x5f
    L_8e88:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueEnd]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     LoadStoreDoubleCallSet
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8f95
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [g_eventQueueEnd], edx
        mov      eax, 1
        mov      dword ptr [esi + 8], 0x448e10
        mov      dword ptr [esi + 0x84], 2
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
        pop      esi
        ret      
    L_8eec:
        mov      eax, dword ptr [g_baseSel]
        mov      ecx, dword ptr [g_eventQueueEnd]
        mov      dword ptr [eax*4 + 0x64], ecx
        mov      edx, dword ptr [g_baseSel]
        mov      eax, dword ptr [g_eventQueueIdx]
        mov      dword ptr [edx*4 + 0x68], eax
        mov      ecx, dword ptr [g_baseSel]
        mov      edx, dword ptr [g_fightGroupHead]
        mov      dword ptr [ecx*4 + 0x4c], edx
        mov      dword ptr [g_eventQueueEnd], 0x64
    L_8f2d:
        mov      eax, dword ptr [g_matrixStackTop]
        mov      ecx, dword ptr [g_eventQueueEnd]
        inc      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      dword ptr [eax*4], ecx
        call     LoadStoreDoubleCallSet
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8f95
        call     MatchEndFadeFsmCluster
        mov      eax, dword ptr [g_framePauseFlag]
        test     eax, eax
        jne      L_8f95
        mov      eax, dword ptr [g_matrixStackTop]
        mov      edx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_matrixStackTop], eax
        mov      eax, 1
        mov      dword ptr [g_eventQueueEnd], edx
        mov      dword ptr [esi + 8], 0x448e10
        mov      dword ptr [esi + 0x84], eax
        mov      dword ptr [g_pendingNodeType], eax
        mov      dword ptr [g_framePauseFlag], eax
    L_8f95:
        pop      esi
        ret      
    }
}
