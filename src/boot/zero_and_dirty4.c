/**
 * Auto-split from misc_matches2.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x00405430 (23b)
 *   mov     eax, [g_xformDirtyFlags]
 *   mov     [g_walkCallback], 0
 *   or      al, 4
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void ZeroAndDirty4_00405430(void) {
    unsigned int v = g_xformDirtyFlags;
    g_walkCallback = 0;
    g_xformDirtyFlags = v | 4;
}
