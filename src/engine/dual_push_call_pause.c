/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00482eb0 (36b): push F1-arg + call + pause + push F2-arg + call.
 * Entry A of the original 53-byte packed block; the 5-byte tail-jmp
 * sub-entry at +0x30 (func_00482ee0) is split into its own symbol.
 * The 12-byte nop gap is filled by 0x90-fill. */
extern int IterStepDualStore_00490b40(void *);
extern int ArgSarStoreJmp_004594f0(void *);
extern void *g_dispatchSave1310_004ee340;
extern void *g_dispatchSave1311_004ee348;
extern void Chain3CallGuarded_00482ef0(void);
void DualPushCallPause_00482eb0(void) {
    IterStepDualStore_00490b40(&g_dispatchSave1310_004ee340);
    if (g_framePauseFlag != 0) return;
    ArgSarStoreJmp_004594f0(&g_dispatchSave1311_004ee348);
}

/* @addr 0x00482ee0 (5b): tail-jmp into Chain3CallGuarded_00482ef0 sub-entry. */
void func_00482ee0(void) {
    Chain3CallGuarded_00482ef0();
}
