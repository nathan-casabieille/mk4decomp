/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b2ac0 (17b): zero a buffer using rep stosd
 *   push    edi
 *   mov     ecx, 0x2a
 *   xor     eax, eax
 *   mov     edi, 0x007af958
 *   rep     stosd
 *   pop     edi
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1626[];
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_dispatchSave1626 ((unsigned int *)MK4_VA(unsigned int, 0x7af958u))
#endif







extern void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
void AppInit_Misc3(void) {
    memset(g_dispatchSave1626, 0, 0x2a * 4);
}

