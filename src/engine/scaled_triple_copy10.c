/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0049d340 (52b): same shape, offsets shift to 0x10/0x14/0x18 */
void ScaledTripleCopy10(void) {
    unsigned int *src = (unsigned int *)(g_xformEntityIdx * 4);
    unsigned int *dst = (unsigned int *)(g_currentNodeIdx * 4);
    unsigned int v;
    v = src[0]; g_walkCallback = (void(*)(void))v; dst[4] = v;
    v = src[1]; g_walkCallback = (void(*)(void))v; dst[5] = v;
    v = src[2]; g_walkCallback = (void(*)(void))v; dst[6] = v;
}
