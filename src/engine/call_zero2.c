/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004be610 (18b)
 *   call    F
 *   xor     eax, eax
 *   mov     [g_X1], eax
 *   mov     [g_X2], eax
 *   ret
 */
extern void Loop16Init(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_armedReloadB;
extern unsigned int g_armedReloadA;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#endif

void CallZero2(void) {
    Loop16Init();
    g_armedReloadB = 0;
    g_armedReloadA = 0;
}
