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

/* @addr 0x00459fc0 (27b): mstack-push func_00459fe0 onto stack[idx*4], tail-jmp
 * Phase3IndirectInstallChain_0045a010. Entry A of the original 73-byte packed
 * block; entry B (loop body) lives in func_00459fe0. */
extern void Phase3IndirectInstallChain_0045a010(void);
extern void PendingMatch_00459510(void);
extern void func_00459fe0(void);
void GuardedTwiceLoopback_00459fc0(void) {
    g_state_004d57ac++;
    *(unsigned int *)(g_state_004d57ac * 4) = (unsigned int)&func_00459fe0;
    Phase3IndirectInstallChain_0045a010();
}
