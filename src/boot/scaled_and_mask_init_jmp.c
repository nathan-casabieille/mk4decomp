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
    ((ScenegraphNode *)MK4_PTR((g_currentNodeIdx * 4)))->flags &= 0xffffff7fu;
    /* The original stores its OWN code VA here - `mov [0x54206c], offset
     * ScaledAndMaskInitJmp` - and Helper_TickAlt later hands that value to
     * MK4_ResolveCode. Spelled as `&ScaledAndMaskInitJmp` it was the NATIVE
     * function's address instead, which resolves to nothing and leaves the
     * walk dispatching into a no-op or worse. It is ASLR-varying, so this
     * was the second source of the MK4_BOOT_MATCH flake (a32225ffd found
     * the first); the run that named it printed
     * "unresolved code VA 0x0092941c" and a backtrace through Helper_TickAlt
     * from MatchInitMonsterChain. */
    g_walkCallback = (void (*)(void))0x00405a00u;
    v = *(unsigned int *)MK4_PTR((g_currentNodeIdx * 4));
    g_eventQueueCurrent = v;
    if (v == 0) return;
    Helper_TickAlt();
}
