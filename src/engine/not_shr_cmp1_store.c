/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer;

/* @addr 0x00460d80 (65b)
 *   load g_phaseThunkState2; if non-zero zero g_walkCallback and ret.
 *   else load g_fightTableC0, g_fightGroupHead; not eax; store walk
 *   load [ecx*4 + 0x30]; cmp 1; store g_eventQueueCurrent
 *   if equal ret, else shr eax,8; store walk; ret.
 */
extern unsigned int g_phaseThunkState2;
void NotShrCmp1Store(void) {
    unsigned int e;
    unsigned int chain;
    if (g_phaseThunkState2 != 0) {
        g_walkCallback = 0;
        return;
    }
    e = ~g_fightTableC0;
    g_walkCallback = (void(*)(void))e;
    chain = ((FightGroupNode *)(g_fightGroupHead * 4))->tag;
    g_eventQueueCurrent = chain;
    if (chain == 1) return;
    g_walkCallback = (void(*)(void))(e >> 8);
}
