/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#endif


/* @addr 0x004b5b00 (12b)
 *   mov     ecx, [esp+4]
 *   mov     eax, [esp+8]
 *   mov     [ecx-8], eax
 *   ret
 */
void StoreAtMinus8(int *p, int v) {
    p[-2] = v;
}
