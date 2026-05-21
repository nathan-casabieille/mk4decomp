/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueEnd;

/* @addr 0x0049d340 (52b): same shape, offsets shift to 0x10/0x14/0x18 */
void ScaledTripleCopy10_0049d340(void) {
    unsigned int *src = (unsigned int *)(g_xformEntityIdx * 4);
    unsigned int *dst = (unsigned int *)(g_scaledInit_00542044 * 4);
    unsigned int v;
    v = src[0]; g_walkCallback = (void(*)(void))v; dst[4] = v;
    v = src[1]; g_walkCallback = (void(*)(void))v; dst[5] = v;
    v = src[2]; g_walkCallback = (void(*)(void))v; dst[6] = v;
}
