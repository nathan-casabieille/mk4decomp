/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
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
extern unsigned int g_dispatchSave1171;
extern unsigned int g_dispatchSave1172;
extern unsigned int g_dispatchSave1169;
extern unsigned int g_dispatchSave1170;
void Init4Globals(void) {
    g_dispatchSave1171 = 0x00020000;
    g_dispatchSave1172 = 0x00020000;
    g_dispatchSave1169 = 0x00010000;
    g_walkCallback   = (void(*)(void))0x00010000;
    g_dispatchSave1170 = 0x00010000;
}
