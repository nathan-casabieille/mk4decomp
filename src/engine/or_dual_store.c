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

extern unsigned int g_dualBitGate_0053a7b0;     /* 0x004d57b0 (mirrors back) */
extern unsigned int g_or_0052ab40;     /* 0x0052ab40 */

/* @addr 0x0048a190 */
void OrDualStore_0048a190(void) {
    unsigned int v = g_dualBitGate_0053a7b0 | (unsigned int)g_walkCallback;
    g_eventQueueCurrent = v;
    g_dualBitGate_0053a7b0       = v;
}

/* @addr 0x0048e4b0 */
void OrDualStore_0048e4b0(void) {
    unsigned int v = g_or_0052ab40 | (unsigned int)g_walkCallback;
    g_eventQueueCurrent = v;
    g_or_0052ab40       = v;
}
