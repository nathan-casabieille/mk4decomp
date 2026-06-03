/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0049fa00 (29b)
 *   mov     eax, [g_phaseThunkVar3]
 *   cmp     eax, 8
 *   mov     [g_walkCallback], eax
 *   ja      .reset
 *   add     eax, 5
 *   mov     [g_walkCallback], eax
 *   mov     [g_phaseThunkVar3], eax
 *   ret
 */
extern unsigned int g_phaseThunkVar3;
void StateAdd5Capped(void) {
    unsigned int v = g_phaseThunkVar3;
    g_walkCallback = (void (*)(void))v;
    if (v > 8) {
        return;
    }
    v += 5;
    g_walkCallback = (void (*)(void))v;
    g_phaseThunkVar3 = v;
}
