/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


/* @addr 0x00475790 (36b)
 *   mov     eax, [g_xformEntityIdx]
 *   mov     ecx, [eax*4 + 0x3c]
 *   mov     [g_walkCallback], ecx
 *   mov     edx, [eax*4 + 0x44]
 *   mov     [g_eventQueueCurrent], edx
 *   jmp     +0x0c
 */
extern void MStackBracket3PackedSlotInit(void);
void DualScaledLoadStoreJmp(void) {
    unsigned int idx = g_xformEntityIdx;
    g_walkCallback = (void (*)(void))((ScenegraphNode *)(idx * 4))->child_a;
    g_eventQueueCurrent = ((ScenegraphNode *)(idx * 4))->child_c;
    MStackBracket3PackedSlotInit();
}
