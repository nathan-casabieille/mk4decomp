/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00409280 (22b)
 *   mov     eax, [g_walkCallback]
 *   and     eax, 0xf
 *   shl     eax, 0x14
 *   mov     [g_walkCallback], eax
 *   mov     [g_X], eax
 *   ret
 */
extern unsigned int g_dest_0053a6e4;
void AndShlStore_00409280(void) {
    unsigned int v = ((unsigned int)g_walkCallback & 0xf) << 0x14;
    g_walkCallback  = (void(*)(void))v;
    g_dest_0053a6e4 = v;
}
