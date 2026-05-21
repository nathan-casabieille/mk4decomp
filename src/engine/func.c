/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00461350 (15b) walk=2 entry */
void func_00461350(void) {
    g_walkCallback = (void (*)(void))2;
    func_0048e4af();
}
