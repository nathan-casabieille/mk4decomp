/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0049d2d0 (52b)
 *   triple copy from a[0..8] into b[4..0xc] with each pass
 *   echoing through g_walkCallback.
 */
void ScaledTripleCopy4_0049d2d0(void) {
    unsigned int *src = (unsigned int *)(g_xformEntityIdx * 4);
    unsigned int *dst = (unsigned int *)(g_scaledInit_00542044 * 4);
    unsigned int v;
    v = src[0]; g_walkCallback = (void(*)(void))v; dst[1] = v;
    v = src[1]; g_walkCallback = (void(*)(void))v; dst[2] = v;
    v = src[2]; g_walkCallback = (void(*)(void))v; dst[3] = v;
}
