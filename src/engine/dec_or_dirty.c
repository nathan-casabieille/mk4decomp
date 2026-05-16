/**
 * 2 "decrement-or-mark-dirty" helpers (29 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_counter]
 *   test    eax, eax
 *   jle     dirty
 *   dec     eax
 *   mov     [g_counter], eax
 *   ret
 * dirty:
 *   mov     eax, [g_xformDirtyFlags]
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *
 * Decrements a per-helper counter while it's positive; once it
 * reaches zero, instead sets the dirty flag bit so the next frame
 * reprocesses the affected scene entries.
 */
#include "engine/scenegraph.h"

extern int g_counter_0054359c;   /* 0x0054359c */
extern int g_counter_005433c8;   /* 0x005433c8 */

/* @addr 0x004a7d90 */
void DecOrDirty_004a7d90(void) {
    if (g_counter_0054359c > 0) {
        g_counter_0054359c--;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}

/* @addr 0x004a7de0 */
void DecOrDirty_004a7de0(void) {
    if (g_counter_005433c8 > 0) {
        g_counter_005433c8--;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}
