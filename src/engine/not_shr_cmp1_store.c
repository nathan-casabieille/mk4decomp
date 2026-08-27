/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_phaseTimer;
#endif

/* @addr 0x00460d80 (65b)
 *   load g_phaseThunkState2; if non-zero zero g_walkCallback and ret.
 *   else load g_fightTableC0, g_fightGroupHead; not eax; store walk
 *   load [ecx*4 + 0x30]; cmp 1; store g_eventQueueCurrent
 *   if equal ret, else shr eax,8; store walk; ret.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_phaseThunkState2;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_fightTableC0 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50a4u))
#define g_phaseThunkState2 (*(unsigned int *)MK4_VA(unsigned int, 0x538094u))
#define g_phaseTimer (*(unsigned int *)MK4_VA(unsigned int, 0x537e94u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

void NotShrCmp1Store(void) {
    unsigned int e;
    unsigned int chain;
    if (g_phaseThunkState2 != 0) {
        g_walkCallback = 0;
        return;
    }
    e = ~g_fightTableC0;
    g_walkCallback = (void(*)(void))e;
    chain = ((FightGroupNode *)MK4_PTR((g_fightGroupHead * 4)))->tag;
    g_eventQueueCurrent = chain;
    if (chain == 1) return;
    g_walkCallback = (void(*)(void))(e >> 8);
}
