/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x0042c790 (46b): loop-head wrapper - stores walk into baseSel[+0x5c]
 * as counter, calls Cascade3ChainInit, then if !pause tail-calls
 * ArgSarStoreJmp_004594f0(0x4e37d0). Entry A of the original 79-byte packed
 * block; entry B (loop body) lives in func_0042c7c0. */
extern unsigned int g_data_004e37d0;
extern void Cascade3ChainInit_0048fa50(void);
extern void TripleEntryStateCascade_0042c7e0(void);
void LoopGuardedDecJmp_0042c790(void) {
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x5c) = (unsigned int)g_walkCallback;
    Cascade3ChainInit_0048fa50();
    if (g_framePauseFlag != 0) return;
    ArgSarStoreJmp_004594f0(&g_data_004e37d0);
}
