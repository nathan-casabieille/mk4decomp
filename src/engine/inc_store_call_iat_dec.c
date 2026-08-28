/**
 * Auto-split from misc_matchesX.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueChild (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_iatPtr (*(unsigned int (**)())MK4_VA(unsigned int, 0x542058u))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#endif

extern void Mul10Tail(void);

/* @addr 0x00439520 (64b)
 *   inc g_matrixStackTop, store callback to stack[idx*4],
 *   call IAT [g_iatPtr], pause-test, restore
 */
#ifndef MK4_ARENA
extern void (*g_iatPtr)(void);
#endif
void IncStoreCallIATDec(void) {
    g_matrixStackTop++;
    *(unsigned int *)MK4_PTR((g_matrixStackTop * 4)) = g_eventQueueChild;
    g_iatPtr();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_eventQueueChild = *(unsigned int *)MK4_PTR((g_matrixStackTop * 4));
    g_matrixStackTop--;
}
