/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueWorkType;
extern u32 g_pendingNodeType;

/* @addr 0x00497b10 (20b): MStackCall + pause-gated tail-jmp to CallSetPause.
 * Entry A of the original 63-byte packed block; entries B (set child=1) and
 * C (set child=0) live in func_00497b30 / func_00497b40. The 12-byte nop gap
 * before entry B is filled by 0x90-fill. */
extern void MStackCall_00406740(void);
extern void CallSetPause_0041f830(void);
extern void PunchDispatcherCluster_00497b50(void);
void CallPauseJmpThenSetChild_00497b10(void) {
    MStackCall_00406740();
    if (g_framePauseFlag != 0) return;
    CallSetPause_0041f830();
}
