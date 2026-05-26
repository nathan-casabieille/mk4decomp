/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00409320 (40b)
 *   mov     ecx, [g_scaledInit_00542044]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      al, 4
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
void ScaledOr4DirtyClear_00409320(void) {
    ScenegraphNode *n = (ScenegraphNode *)(g_scaledInit_00542044 * 4);
    unsigned int v = n->state_mask | 4;
    g_walkCallback = (void (*)(void))v;
    n->state_mask = v;
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
