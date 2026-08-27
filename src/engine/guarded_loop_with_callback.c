/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#include "portable/code_va.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#endif


/* @addr 0x004284a0 (27b): mstack-push the chain callback at +0x20 (GuardedLoopWithCallback_Callback_004284c0)
 * and tail-jmp into the indirect-call dispatcher. Entry A of the original
 * 69-byte packed block; the 5-byte nop gap to entry B is filled by 0x90-fill. */
extern void EsiInstallChainCallIndirect(void);
extern void func_0041f780_pp(void);
extern void GuardedLoopWithCallback_Callback_004284c0(void);
void GuardedLoopWithCallback(void) {
    g_matrixStackTop++;
    *(unsigned int *)MK4_PTR((g_matrixStackTop * 4)) = MK4_CODE_VA(GuardedLoopWithCallback_Callback_004284c0);
    EsiInstallChainCallIndirect();
}
