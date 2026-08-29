/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x004066d0 (27b)
 *   mov     eax, [g_currentNodeIdx]
 *   mov     eax, [eax*4 + 4]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      ret_label
 *   jmp     +6
 *   ret
 */
extern void MStackPushZeroCallPop(void);
void ScaledLoadGuardedJmp(void) {
#ifdef MK4_ARENA
    unsigned int v = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 4);
#else
    unsigned int v = *(unsigned int*)(g_currentNodeIdx * 4 + 4);
#endif
    g_walkCallback = (void(*)(void))v;
    if (v) {
        MStackPushZeroCallPop();
    }
}
