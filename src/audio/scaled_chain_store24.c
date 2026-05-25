/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a7d40 (80b)
 *   Scaled-base table walk: ecx = walk + (0x50a0f0>>2); load
 *   [ecx*4+0]; mask to 24-bit, store as g_xformEntityIdx;
 *   chase pointer ([eax]); shr 2; mask 22-bit; store again;
 *   load g_scaledInit's [+0x18] → g_fightGroupHead;
 *   store eax → [g_fightGroupHead*4+0x24]; ret.
 */
extern unsigned int g_data_0050a0f0;
void ScaledChainStore24_004a7d40(void) {
    unsigned int p;
    unsigned int sc;
    int v;
    p = (unsigned int)g_walkCallback;
    p += (unsigned int)&g_data_0050a0f0 >> 2;
    g_xformEntityIdx = (unsigned int)&g_data_0050a0f0 >> 2;
    sc = g_scaledInit_00542044;
    v = *(int *)(p * 4) & 0xffffff;
    g_xformEntityIdx = (unsigned int)v;
    v = *(int *)v;
    v = (v >> 2) & 0x3fffff;
    g_xformEntityIdx = (unsigned int)v;
    {
        unsigned int chain = *(unsigned int *)(sc * 4 + 0x18);
        g_fightGroupHead = chain;
        *(int *)(chain * 4 + 0x24) = v;
    }
}
