/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00497b10 (20b): MStackCall + pause-gated tail-jmp to CallSetPause.
 * Entry A of the original 63-byte packed block; entries B (set child=1) and
 * C (set child=0) live in func_set_g_eventQueueChild_then_PunchDispatcherCluster_00497b30 / func_set_g_eventQueueChild_then_PunchDispatcherCluster_00497b40. The 12-byte nop gap
 * before entry B is filled by 0x90-fill. */
extern void MStackCall_MStackPush2ChainLLInsert(void);
extern void CallSetPause(void);
extern void PunchDispatcherCluster(void);
void CallPauseJmpThenSetChild(void) {
    MStackCall_MStackPush2ChainLLInsert();
    if (g_framePauseFlag != 0) return;
    CallSetPause();
}
