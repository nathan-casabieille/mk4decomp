/**
 * Auto-split from misc_matches8.c
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
#endif


/* @addr 0x004bd510 (22b)
 *   mov     eax, [g_currentNodeIdx]
 *   lea     ecx, [eax*4 + 0x48]
 *   push    ecx
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int CleanupCallTwice(void *);
void LeaScaledCall(void) {
    CleanupCallTwice((void *)(g_currentNodeIdx * 4 + 0x48));
}
