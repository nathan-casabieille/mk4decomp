/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00439680 (54b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x38]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0x70]
 *   mov     [g_walkCallback], eax
 *   test    eax, eax
 *   mov     eax, [g_xformDirtyFlags]
 *   jge     +8
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void ScaledChainSignDirtyToggle_00439680(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x38);
    g_scaledInit_00542044 = v;
    v = *(unsigned int *)(v * 4 + 0x70);
    g_walkCallback = (void (*)(void))v;
    if ((int)v < 0) {
        g_xformDirtyFlags = g_xformDirtyFlags | 1;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
