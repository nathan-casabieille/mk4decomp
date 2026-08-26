/**
 * Auto-split from misc_matchesPP.c
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
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x004392c0 (78b)
 *   Tail-dispatch on packed table. eax = arg0>>2 → g_scaledInit;
 *   ecx = [eax*4+0] → walk; advance idx; call F; pause → ret;
 *   eax = (g_scaledInit + walk) → g_scaledInit; eax = [g_scaledInit*4];
 *   walk = eax; jmp eax.
 */
extern void StorePauseImulShr16(void);
void PackedAdvanceCallTailJmp(packed_ptr arg) {
    g_currentNodeIdx = (unsigned int)((int)arg >> 2);
    g_walkCallback = *(void (**)(void))(g_currentNodeIdx * 4);
    g_currentNodeIdx++;
    StorePauseImulShr16();
    if (g_framePauseFlag) return;
    g_currentNodeIdx += (unsigned int)g_walkCallback;
    g_currentNodeIdx = *(unsigned int *)(g_currentNodeIdx * 4);
    ((void (*)(void))g_currentNodeIdx)();
}
