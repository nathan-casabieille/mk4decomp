/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x00405a00 (59b)
 *   mov     eax, [g_currentNodeIdx]
 *   mov     edx, [eax*4 + 0x20]
 *   and     dl, 0x7f
 *   mov     [eax*4 + 0x20], edx
 *   mov     eax, [g_currentNodeIdx]
 *   mov     [g_walkCallback], 0x00405a00
 *   mov     eax, [eax*4 + 0]
 *   test    eax, eax
 *   mov     [g_eventQueueCurrent], eax
 *   je      +5
 *   jmp     +0xb5456
 *   ret
 */
extern void Helper_TickAlt(void);
extern void ScaledAndMaskInitJmp(void);
void ScaledAndMaskInitJmp(void) {
    unsigned int v;
    ((ScenegraphNode *)(g_currentNodeIdx * 4))->flags &= 0xffffff7fu;
    g_walkCallback = (void (*)(void))&ScaledAndMaskInitJmp;
    v = *(unsigned int *)(g_currentNodeIdx * 4);
    g_eventQueueCurrent = v;
    if (v == 0) return;
    Helper_TickAlt();
}
