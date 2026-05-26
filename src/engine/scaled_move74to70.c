/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0046eaa0 (26b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x70], ecx
 *   ret
 */
extern unsigned int g_baseSel_00542060;
void ScaledMove74to70_0046eaa0(void) {
    unsigned int idx = g_baseSel_00542060;
    unsigned int v = ((ScenegraphNode *)(idx * 4))->fsm_state;
    g_walkCallback = (void(*)(void))v;
    *(unsigned int *)(idx * 4 + 0x70) = v;
}
