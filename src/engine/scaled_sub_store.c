/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/ghidra_types.h"   /* MK4_NODE_AT (NON_MATCHING-only) */

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


/* @addr 0x0048ee90 (39b)
 *   mov     eax, [g_currentNodeIdx]
 *   mov     ecx, [eax*4 + 0x48]
 *   mov     [g_walkCallback], ecx
 *   mov     eax, [eax*4 + 0x58]
 *   sub     ecx, eax
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [g_walkCallback], ecx
 *   ret
 */

#ifdef NON_MATCHING
/* Portable twin (verified via verify_coexec). Reads node[g_currentNodeIdx]
 * fields +0x48 and +0x58, stores +0x58 to g_eventQueueCurrent and their
 * difference (f48 - f58) to g_walkCallback. */
void ScaledSubStore(void) {
    unsigned int idx = g_currentNodeIdx;
    unsigned int f48 = MK4_NODE_AT(unsigned int, idx, 0x48);
    unsigned int f58 = MK4_NODE_AT(unsigned int, idx, 0x58);
    g_walkCallback = f48;
    g_eventQueueCurrent = f58;
    g_walkCallback = f48 - f58;
}
#else
void ScaledSubStore(void) {
    __asm {
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [eax*4 + 0x48]
        mov     dword ptr [g_walkCallback], ecx
        mov     eax, dword ptr [eax*4 + 0x58]
        sub     ecx, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_walkCallback], ecx
        }
}
#endif

