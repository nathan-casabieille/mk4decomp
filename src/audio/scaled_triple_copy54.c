/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ac040 (54b): triple cross-store at offsets 0x54/0x58/0x5c */
void ScaledTripleCopy54_004ac040(void) {
    unsigned char *dst = (unsigned char *)(g_fightGroupHead * 4);
    unsigned char *src = (unsigned char *)(g_eventQueueEnd * 4);
    unsigned int v;
    v = *(unsigned int *)(src + 0x54);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x54) = v;
    v = *(unsigned int *)(src + 0x58);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x58) = v;
    v = *(unsigned int *)(src + 0x5c);
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(dst + 0x5c) = v;
}
