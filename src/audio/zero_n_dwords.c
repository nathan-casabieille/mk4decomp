/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

void ZeroNDwords_004a5660(int *p, int n) {
    if (n <= 0) return;
    memset(p, 0, n * 4);
}
