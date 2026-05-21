/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0042ae10 (36b)
 *   mov     eax, 0x00020000
 *   mov     [0x004d5308], eax
 *   mov     [0x004d530c], eax
 *   mov     eax, 0x00010000
 *   mov     [0x004d5300], eax
 *   mov     [g_walkCallback], eax
 *   mov     [0x004d5304], eax
 *   ret
 */
extern unsigned int g_state_004d5308;
extern unsigned int g_state_004d530c;
extern unsigned int g_state_004d5300;
extern unsigned int g_state_004d5304;
void Init4Globals_0042ae10(void) {
    g_state_004d5308 = 0x00020000;
    g_state_004d530c = 0x00020000;
    g_state_004d5300 = 0x00010000;
    g_walkCallback   = (void(*)(void))0x00010000;
    g_state_004d5304 = 0x00010000;
}
