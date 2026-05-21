/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004abfc0 (27b)
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, eax
 *   and     eax, 0x00ffffff
 *   shr     ecx, 0x18
 *   mov     [g_eventQueueCurrent], ecx
 *   mov     [g_xformEntityIdx], eax
 *   ret
 */
extern packed_ptr g_xformEntityIdx;
void SplitHi8Lo24_004abfc0(void) {
    unsigned int v = g_eventQueueCurrent;
    g_eventQueueCurrent = v >> 24;
    g_xformEntityIdx = v & 0x00ffffff;
}
