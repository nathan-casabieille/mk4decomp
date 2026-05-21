/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00439190 (20b): call F1; if pause, ret; else tail-jmp T1.
 *   Originally a 52-byte slot covering this 20-byte entry plus a 12-byte
 *   nop gap and a twin 20-byte entry at +0x20 (func_004391b0). Split into
 *   two pure-C functions; the gap is filled by the synth via 0x90-fill. */
extern void func_00423c10(void);
extern void func_00423bf0(void);
extern void func_00477670(void);
extern void func_0046f680(void);
void DualCallPauseJmpDual_00439190(void) {
    func_00423c10();
    if (g_framePauseFlag != 0) return;
    func_00477670();
}
