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
