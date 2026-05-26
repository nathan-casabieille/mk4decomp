/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004902d0 (29b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x40]
 *   and     ah, 0xfd
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [ecx*4 + 0x40], eax
 *   ret
 */
void ScaledAndAh_004902d0(void) {
    FightGroupNode *n = (FightGroupNode *)(g_fightGroupHead * 4);
    unsigned int v = n->bits & 0xFFFFFDFFu;
    g_eventQueueCurrent = v;
    n->bits = v;
}
