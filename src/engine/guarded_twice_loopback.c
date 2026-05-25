/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00459fc0 (27b): mstack-push func_00459fe0 onto stack[idx*4], tail-jmp
 * Phase3IndirectInstallChain_0045a010. Entry A of the original 73-byte packed
 * block; entry B (loop body) lives in func_00459fe0. */
extern void Phase3IndirectInstallChain_0045a010(void);
extern void PendingMatch_00459510(void);
extern void func_00459fe0(void);
void GuardedTwiceLoopback_00459fc0(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = (unsigned int)&func_00459fe0;
    Phase3IndirectInstallChain_0045a010();
}
