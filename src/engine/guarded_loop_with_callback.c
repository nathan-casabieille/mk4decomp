/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004284a0 (27b): mstack-push the chain callback at +0x20 (func_004284c0)
 * and tail-jmp into the indirect-call dispatcher. Entry A of the original
 * 69-byte packed block; the 5-byte nop gap to entry B is filled by 0x90-fill. */
extern void EsiInstallChainCallIndirect_00428680(void);
extern void func_0041f780_pp(void);
extern void func_004284c0(void);
void GuardedLoopWithCallback_004284a0(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = (unsigned int)&func_004284c0;
    EsiInstallChainCallIndirect_00428680();
}
