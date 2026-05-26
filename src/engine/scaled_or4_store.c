/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x00490110 (28b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      al, 4
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   ret
 */
void ScaledOr4Store_00490110(void) {
    ScenegraphNode *n = (ScenegraphNode *)(g_fightGroupHead * 4);
    unsigned int v = n->state_mask | 4;
    g_walkCallback = (void (*)(void))v;
    n->state_mask = v;
}
