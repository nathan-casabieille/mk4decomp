/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

void ZeroNDwords(int *p, int n) {
    if (n <= 0) return;
    memset(p, 0, n * 4);
}
