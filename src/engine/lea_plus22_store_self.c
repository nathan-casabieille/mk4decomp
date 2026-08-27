/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x0048e4d0 (22b)
 *   mov     eax, [g_baseSel]
 *   lea     ecx, [eax + 0x22]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 4], ecx
 *   ret
 */
void LeaPlus22StoreSelf(void) {
    u32 base = g_baseSel;
    u32 v = base + 0x22;
    g_walkCallback = (NodeHandlerFn)MK4_PTR(v);
    *(u32 *)MK4_PTR((base * 4 + 4)) = v;
}
