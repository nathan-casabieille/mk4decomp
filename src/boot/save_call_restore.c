/**
 * Auto-split from misc_matchesE.c
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
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x004049d0 (38b)
 *   mov     eax, [esp+4]
 *   push    esi
 *   mov     esi, [g_walkCallback]
 *   mov     [g_walkCallback], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], esi
 * .ret:
 *   pop     esi
 *   ret
 */
extern void MStackPush2DirtyCall(void);
void SaveCallRestore(unsigned int arg) {
    void (*saved)(void) = g_walkCallback;
    g_walkCallback = (void (*)(void))arg;
    MStackPush2DirtyCall();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = saved;
}
