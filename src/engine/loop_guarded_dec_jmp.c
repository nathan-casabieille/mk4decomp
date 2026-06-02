/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;

/* @addr 0x0042c790 (46b): loop-head wrapper - stores walk into baseSel[+0x5c]
 * as counter, calls Cascade3ChainInit, then if !pause tail-calls
 * ArgSarStoreJmp(0x4e37d0). Entry A of the original 79-byte packed
 * block; entry B (loop body) lives in func_0042c7c0. */
extern unsigned int g_dispatchSave1219_004e37d0;
extern void Cascade3ChainInit(void);
extern void TripleEntryStateCascade(void);
void LoopGuardedDecJmp(void) {
    ((ScenegraphNode *)(g_baseSel * 4))->position_z = (unsigned int)g_walkCallback;
    Cascade3ChainInit();
    if (g_framePauseFlag != 0) return;
    ArgSarStoreJmp(&g_dispatchSave1219_004e37d0);
}
