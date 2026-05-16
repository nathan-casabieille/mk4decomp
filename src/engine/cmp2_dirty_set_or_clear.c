/**
 * 2 "compare-2 + dirty-flag set or clear" helpers (36 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_state]
 *   mov     [g_walkCallback], eax
 *   cmp     eax, 2
 *   mov     eax, [g_xformDirtyFlags]
 *   jne     .clear
 *   or      al, 1                    ; set bit 0
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 * .clear:
 *   and     al, 0xfe                 ; clear bit 0
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *
 * Mirrors a state slot into the global walk callback, then sets bit 0
 * of the xform-dirty flag iff the state equals 2 (else clears it).
 */
#include "engine/scenegraph.h"

extern unsigned int g_active_0053a408;
extern unsigned int g_active_00537e88;

/* @addr 0x0049fb10 */
void Cmp2DirtySetOrClear_0049fb10(void) {
    unsigned int state = g_active_0053a408;
    g_walkCallback = (void(*)(void))state;
    if (state == 2) {
        g_xformDirtyFlags = g_xformDirtyFlags | 1;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}

/* @addr 0x0049fb40 */
void Cmp2DirtySetOrClear_0049fb40(void) {
    unsigned int state = g_active_00537e88;
    g_walkCallback = (void(*)(void))state;
    if (state == 2) {
        g_xformDirtyFlags = g_xformDirtyFlags | 1;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
