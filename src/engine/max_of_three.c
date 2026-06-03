/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern int g_min_007af984;
extern int g_min_007af988;
extern int g_min_007af98c;

/* @addr 0x004b3d90 (30b): max-of-three (jle instead of jge) */
int MaxOfThree(void) {
    int a = g_min_007af984;
    int b = g_min_007af988;
    if (b > a) a = b;
    b = g_min_007af98c;
    if (b > a) a = b;
    return a;
}
