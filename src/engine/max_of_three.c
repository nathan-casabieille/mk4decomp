/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern int g_min_007af984;
extern int g_min_007af988;
extern int g_min_007af98c;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_min_007af984 (*(int *)MK4_VA(int, 0x7af984u))
#define g_min_007af988 (*(int *)MK4_VA(int, 0x7af988u))
#define g_min_007af98c (*(int *)MK4_VA(int, 0x7af98cu))
#endif


/* @addr 0x004b3d90 (30b): max-of-three (jle instead of jge) */
int MaxOfThree(void) {
    int a = g_min_007af984;
    int b = g_min_007af988;
    if (b > a) a = b;
    b = g_min_007af98c;
    if (b > a) a = b;
    return a;
}
