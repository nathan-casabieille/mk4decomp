/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048f3c0 (43b)
 *   mov     edx, [g_xformDirtyFlags]
 *   mov     eax, [g_state_0053a408]
 *   mov     ecx, 4
 *   mov     [g_walkCallback], eax
 *   or      edx, ecx
 *   test    eax, eax
 *   mov     [g_xformDirtyFlags], edx
 *   je      +9
 *   mov     eax, edx
 *   xor     eax, ecx
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_state_0053a408;
void DirtyFlagsManipB_0048f3c0(void) {
    unsigned int v = g_state_0053a408;
    g_walkCallback = (void (*)(void))v;
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    if (v != 0) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
}
