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


/* @addr 0x004b5ae0 (29b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [esp+8]
 *   and     ecx, 0x3f
 *   mov     edx, [eax-0xc]
 *   shl     ecx, 0x18
 *   and     edx, 0xc0ffffff
 *   or      ecx, edx
 *   mov     [eax-0xc], ecx
 *   ret
 */
void SetHi6(unsigned int *p, unsigned int v) {
    p[-3] = (p[-3] & 0xc0ffffffu) | ((v & 0x3fu) << 24);
}
