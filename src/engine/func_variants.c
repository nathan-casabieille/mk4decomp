/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00428390 (19b naked): Block B - reached only via external
 * jmp from a different call site. Uses _emit jne for the back-jump
 * into Block A and a forward tail-jmp. */
__declspec(naked) void func_00428390(void) {
    __asm {
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   75h
        _emit   05h
        jmp     func_004283b3
        jmp     func_0042976e
    }
}

/* @addr 0x004391b0 (20b): twin of DualCallPauseJmpDual_00439190 at +0x20 in
 * the original packed slot. Reached via OFFSET func_004391b0 references
 * (e.g. from misc_matchesF.c). */
void func_004391b0(void) {
    func_00423bf0();
    if (g_framePauseFlag != 0) return;
    func_0046f680();
}

/* @addr 0x00497b30 (15b): set g_eventQueueChild = 1; tail-jmp PunchDispatcher. */
void func_00497b30(void) {
    g_eventQueueChild = 1;
    PunchDispatcherCluster_00497b50();
}

/* @addr 0x00497b40 (15b): set g_eventQueueChild = 0; tail-jmp PunchDispatcher. */
void func_00497b40(void) {
    g_eventQueueChild = 0;
    PunchDispatcherCluster_00497b50();
}

/* @addr 0x00436270 (47b): call func_00439890; if non-zero ret;
 * else mstack-push HitReactionStateCluster_004335f0, set walkCallback=2,
 * tail-jmp func_00471200. Orphan sub-entry. */
void func_00436270(void) {
    if (func_00439890() != 0) return;
    g_walkCallback = (void (*)(void))2;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) =
        (unsigned int)&HitReactionStateCluster_004335f0;
    func_00471200();
}

/* @addr 0x004362a0 (5b): orphan tail-jmp into func_00436290. */
void func_004362a0(void) {
    func_00436290();
}

/* @addr 0x00437100 (52b): call LeaPlus22StoreSelf; if !pause set walk=3,
 * mstack-push OFFSET DualCallPauseJmpDual_00439190, tail-jmp func_00471270.
 * Orphan sub-entry of the original packed block. */
void func_00437100(void) {
    LeaPlus22StoreSelf_0048e4d0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))3;
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) =
        (unsigned int)&DualCallPauseJmpDual_00439190;
    func_00471270();
}

/* @addr 0x0048e3c0 (20b): call func_004312e0; if !pause tail-jmp
 * func_00431470. Orphan sub-entry of the original packed block. */
void func_0048e3c0(void) {
    func_004312e0();
    if (g_framePauseFlag != 0) return;
    func_00431470();
}

/* @addr 0x004bf080 (5b) tail-jmp wrapper to LoadStoreRetNopJmp_004bf090
 * (resolved via the func_004bf088 alias in extras_map). */
void func_004bf080(void) {
    func_004bf088();
}

/* @addr 0x004bf0a0 (5b) tail-jmp wrapper to AddStore_004bf0b0
 * (resolved via the func_004bf0a8 alias in extras_map). */
void func_004bf0a0(void) {
    func_004bf0a8();
}

/* @addr 0x004284a0 (27b): mstack-push the chain callback at +0x20 (func_004284c0)
 * and tail-jmp into the indirect-call dispatcher. Entry A of the original
 * 69-byte packed block; the 5-byte nop gap to entry B is filled by 0x90-fill. */
extern void EsiInstallChainCallIndirect_00428680(void);
extern void func_0041f780_pp(void);
extern void func_004284c0(void);
void GuardedLoopWithCallback_004284a0(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = (unsigned int)&func_004284c0;
    EsiInstallChainCallIndirect_00428680();
}

/* @addr 0x004667e0 (5b) tail-jmp wrapper. */
void func_004667e0(void) {
    CallSetPause_0041f830();
}

/* @addr 0x00482700 (56b): triple call chain with pause-gates; final
 * push+call+pause gate then tail-jmp LiteralPushCallEntZero. */
void func_00482700(void) {
    GateDispatch6c_00494580();
    if (g_framePauseFlag != 0) return;
    ScaledChainCmp61_00482740();
    if (g_framePauseFlag != 0) return;
    ArgSarStoreJmp_004594f0(&g_data_004edf68);
    if (g_framePauseFlag != 0) return;
    LiteralPushCallEntZero_00488c00();
}

/* @addr 0x00459fc0 (27b): mstack-push func_00459fe0 onto stack[idx*4], tail-jmp
 * Phase3IndirectInstallChain_0045a010. Entry A of the original 73-byte packed
 * block; entry B (loop body) lives in func_00459fe0. */
extern void Phase3IndirectInstallChain_0045a010(void);
extern void PendingMatch_00459510(void);
extern void func_00459fe0(void);
void GuardedTwiceLoopback_00459fc0(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = (unsigned int)&func_00459fe0;
    Phase3IndirectInstallChain_0045a010();
}

/* @addr 0x0042c7c0 (31b): loop body - reload counter from baseSel[+0x5c],
 * decrement, store as new walkCallback; if counter hit zero tail-jmp
 * TripleEntryStateCascade_0042c7e0, else loop back to LoopGuardedDecJmp_0042c790
 * (e9 b6 ff ff ff = rel32 -0x4a). The 2-byte nop gap before this entry is
 * filled by 0x90-fill. */
__declspec(naked) void func_0042c7c0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x5c]
        dec     ecx
        mov     dword ptr [g_walkCallback], ecx
        je      short L_lgdj_done
        jmp     LoopGuardedDecJmp_0042c790
L_lgdj_done:
        jmp     TripleEntryStateCascade_0042c7e0
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
