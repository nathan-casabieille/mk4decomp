/**
 * 2 "or with global + dual store" helpers (24 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [g_walkCallback]
 *   or      eax, ecx                  ; eax |= g_walkCallback
 *   mov     [g_B], eax
 *   mov     [g_A], eax
 *   ret
 *
 * Combines per-helper global with the walk callback bitfield, then
 * mirrors the result into both an output slot and back into g_A.
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dualBitGate;     /* 0x004d57b0 (mirrors back) */
extern unsigned int g_or;     /* 0x0052ab40 */
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_or (*(unsigned int *)MK4_VA(unsigned int, 0x52ab40u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x0048a190 */
void OrDualStore_0048a190(void) {
    unsigned int v = g_dualBitGate | (unsigned int)g_walkCallback;
    g_eventQueueCurrent = v;
    g_dualBitGate       = v;
}

/* @addr 0x0048e4b0 */
void OrDualStore_0048e4b0(void) {
    unsigned int v = g_or | (unsigned int)g_walkCallback;
    g_eventQueueCurrent = v;
    g_or       = v;
}
