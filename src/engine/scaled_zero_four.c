/**
 * Auto-split from misc_matchesAA.c
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
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x00490740 (51b)
 *   load fightGroupHead*4 into eax; xor ecx,ecx → g_walkCallback;
 *   set [eax+0x6c]=0; reload walk into ecx; set [eax+0x70]=ecx; etc. for 0x74, 0x4c
 *   then jmp.
 */
extern void ZeroThreeSlots_00490780(void);
void ScaledZeroFour(void) {
    unsigned int *base = (unsigned int *)(g_fightGroupHead * 4);
    g_walkCallback = 0;
    base[0x6c/4] = 0;
    base[0x70/4] = (unsigned int)g_walkCallback;
    base[0x74/4] = (unsigned int)g_walkCallback;
    base[0x4c/4] = (unsigned int)g_walkCallback;
    ZeroThreeSlots_00490780();
}
