/**
 * Auto-split from misc_matches2.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x00487120 (24b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, 0x2005
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x74], eax
 *   ret
 */
void Const0x2005Store_00487120(void) {
    g_walkCallback = (void(*)(void))0x2005;
    ((ScenegraphNode *)(g_baseSel_00542060 * 4))->fsm_state = 0x2005;
}
