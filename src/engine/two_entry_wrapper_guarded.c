/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004826f0 (14b): mini-wrapper - push lit + call + cleanup + ret.
 * Entry A of the original 72-byte packed block; entry B (the main 56-byte
 * body at +0x10) lives in func_GateDispatch6c_then_ScaledChainCmp61_then_ArgSarStoreJmp_then_LiteralPushCallEntZero. The 2-byte nop gap is filled
 * by 0x90-fill. */
extern unsigned int g_dispatchSave1307;
extern unsigned int g_dispatchSave1308;
extern void GateDispatch6c(void);
extern void ScaledChainCmp61(void);
extern void LiteralPushCallEntZero(void);
void TwoEntryWrapperGuarded(void) {
    ArgSarStoreJmp(&g_dispatchSave1307);
}
