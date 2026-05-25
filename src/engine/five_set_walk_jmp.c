/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00461360 (15b) walk=4 entry */
void FiveSetWalkJmp_00461360(void) {
    g_walkCallback = (void (*)(void))4;
    OrDualStore_0048e4b0();
}
