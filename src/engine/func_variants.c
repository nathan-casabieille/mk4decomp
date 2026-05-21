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
