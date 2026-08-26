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
#define g_eventQueueTotal (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_player1NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x0048e590 (69b)
 *   eax = arg0 >> 2 → g_eventQueueTotal; ecx = [eax*4+0] → scaled;
 *   if g_fightGroupHead != [0x538158]: ecx = [eax*4+4] → scaled;
 *   eax = [ecx*4+0]; store → walk; ret.
 */
void ScaledIndexCondCopy(int arg) {
    unsigned int packed = (unsigned int)(arg >> 2);
    unsigned int v;
    g_eventQueueTotal = packed;
    v = *(unsigned int *)(packed * 4 + 0);
    g_currentNodeIdx = v;
    if (g_fightGroupHead != g_player1NodeIdx) {
        v = *(unsigned int *)(packed * 4 + 4);
        g_currentNodeIdx = v;
    }
    g_walkCallback = (void (*)(void))(*(unsigned int *)(v * 4 + 0));
}
