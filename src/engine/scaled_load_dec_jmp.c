/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#endif


/* @addr 0x00429710 (24b)
 *   mov     eax, [g_currentNodeIdx]
 *   mov     ecx, [eax*4 + 4]
 *   dec     ecx
 *   mov     [g_eventQueueCurrent], ecx
 *   jmp     +8
 */
extern void ScaledStoreCurDirtyOr1(void);
void ScaledLoadDecJmp(void) {
    g_eventQueueCurrent = *(unsigned int*)MK4_PTR((g_currentNodeIdx * 4 + 4)) - 1;
    ScaledStoreCurDirtyOr1();
}
