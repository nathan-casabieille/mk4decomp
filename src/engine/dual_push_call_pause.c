/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00482eb0 (36b): push F1-arg + call + pause + push F2-arg + call.
 * Entry A of the original 53-byte packed block; the 5-byte tail-jmp
 * sub-entry at +0x30 (func_Chain3CallGuarded) is split into its own symbol.
 * The 12-byte nop gap is filled by 0x90-fill. */
extern int IterStepDualStore(void *);
extern int ArgSarStoreJmp(void *);
extern void *g_dispatchSave1310;
extern void *g_dispatchSave1311;
extern void Chain3CallGuarded(void);
void DualPushCallPause(void) {
    IterStepDualStore(&g_dispatchSave1310);
    if (g_framePauseFlag != 0) return;
    ArgSarStoreJmp(&g_dispatchSave1311);
}

/* @addr 0x00482ee0 (5b): tail-jmp into Chain3CallGuarded sub-entry. */
void func_Chain3CallGuarded(void) {
    Chain3CallGuarded();
}
