/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x0048e710 (40b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [0x0052aac4]
 *   sar     eax, 2
 *   add     eax, ecx
 *   mov     [g_walkCallback], ecx
 *   mov     [g_currentNodeIdx], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_currentNodeIdx], eax
 *   jmp     eax
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_tickFlagF;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_tickFlagF (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* The argument is a descriptor VA; `sar eax, 2` packs it, and the sum indexes
 * a base-0 table whose entry is the state's code VA - so the deref goes
 * through MK4_NODE and the tail jump through MK4_ResolveCode.
 *
 * g_walkCallback is a plain u32 slot under the arena aliases: the engine also
 * puts node links and field values in it, so it cannot be typed as a pointer. */
void ArgSarAddDerefJmp(int arg) {
    unsigned int c = g_tickFlagF;
    unsigned int v = (unsigned int)(arg >> 2) + c;
    g_walkCallback = c;
    g_currentNodeIdx = v;
    v = *MK4_NODE(unsigned int, v);
    g_currentNodeIdx = v;
    ((void (*)(void))MK4_ResolveCode(v))();
}
#else
void ArgSarAddDerefJmp(int arg) {
    unsigned int c = g_tickFlagF;
    unsigned int v = (unsigned int)(arg >> 2) + c;
    g_walkCallback = (void (*)(void))c;
    g_currentNodeIdx = v;
    v = *(unsigned int *)(v * 4);
    g_currentNodeIdx = v;
    ((void (*)(void))MK4_ResolveCode(v))();
}
#endif
