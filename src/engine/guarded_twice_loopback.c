/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/code_va.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00459fc0 (27b): mstack-push GuardedTwiceLoopback_Body_00459fe0 onto stack[idx*4], tail-jmp
 * Phase3IndirectInstallChain. Entry A of the original 73-byte packed
 * block; entry B (loop body) lives in GuardedTwiceLoopback_Body_00459fe0. */
extern void Phase3IndirectInstallChain(void);
extern void PendingMatch_00459510(void);
extern void GuardedTwiceLoopback_Body_00459fe0(void);
void GuardedTwiceLoopback(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = MK4_CODE_VA(GuardedTwiceLoopback_Body_00459fe0);
    Phase3IndirectInstallChain();
}
