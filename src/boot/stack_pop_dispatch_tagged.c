/**
 * Auto-split from misc_matchesPP.c
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


/* @addr 0x0041f780 (77b)
 *   eax = [g_baseSel*4+4] - 1 → g_scaledInit; edx = [eax*4+0]
 *   → g_walkCallback; [g_baseSel*4+4] = eax (decrement);
 *   eax = walk; eax >>= 24; → [g_baseSel*4+0x84];
 *   eax = walk & 0xffffff → walk; jmp eax.
 *   Hand-rolled tail-dispatch: pops a 24-bit "next" + 8-bit "tag"
 *   from a stack-of-callbacks, invokes the next.
 */
void StackPopDispatchTagged(void) {
    unsigned int base = g_baseSel;
    unsigned int top = *(unsigned int *)(base * 4 + 4) - 1;
    unsigned int walk;
    g_currentNodeIdx = top;
    g_walkCallback = (void (*)(void))*(unsigned int *)(top * 4);
    *(unsigned int *)(base * 4 + 4) = top;
    ((ScenegraphNode *)(g_baseSel * 4))->install_flag = (unsigned int)((int)g_walkCallback >> 24);
    walk = (unsigned int)g_walkCallback & 0xffffff;
    g_walkCallback = (void (*)(void))walk;
    ((void (*)(void))walk)();
}
