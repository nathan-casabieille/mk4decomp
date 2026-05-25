/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004826f0 (14b): mini-wrapper - push lit + call + cleanup + ret.
 * Entry A of the original 72-byte packed block; entry B (the main 56-byte
 * body at +0x10) lives in func_00482700. The 2-byte nop gap is filled
 * by 0x90-fill. */
extern unsigned int g_dispatchSave1307_004edf38;
extern unsigned int g_dispatchSave1308_004edf68;
extern void GateDispatch6c_00494580(void);
extern void ScaledChainCmp61_00482740(void);
extern void LiteralPushCallEntZero_00488c00(void);
void TwoEntryWrapperGuarded_004826f0(void) {
    ArgSarStoreJmp_004594f0(&g_dispatchSave1307_004edf38);
}
