/**
 * Auto-split from misc_matchesD.c
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
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


/* @addr 0x00409260 (32b)
 *   mov     eax, [g_xformEntityIdx]
 *   mov     ecx, [g_walkCallback]
 *   shl     eax, 2
 *   mov     [eax + 4], ecx
 *   xor     ecx, ecx
 *   mov     [eax + 8], ecx
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x0c], ecx
 *   ret
 */
#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Same body; the raw packed-index deref and the fn-ptr-typed store are the
 * two spellings that do not carry to the arena. */
void ScaledStoreThree_00409260(void) {
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 4) = g_walkCallback;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 8) = 0;
    g_walkCallback = 0;
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0xc) = 0;
}
#else
void ScaledStoreThree_00409260(void) {
    unsigned int *base = (unsigned int *)(g_xformEntityIdx * 4);
    base[1] = (unsigned int)g_walkCallback;
    base[2] = 0;
    g_walkCallback = (void (*)(void))0;
    base[3] = 0;
}
#endif
