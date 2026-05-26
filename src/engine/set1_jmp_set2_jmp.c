/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00461340 (15b) walk=1 entry */
void Set1JmpSet2Jmp_00461340(void) {
    g_walkCallback = (void (*)(void))1;
    OrDualStore_0048e4b0();
}
