/**
 * 3 "scaled-load + or 1 + dual-store" helpers (28 bytes each).
 *
 * Pattern:
 *   mov     ecx, [g_baseSelector]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      al, 1
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   ret
 *
 * Sets bit 0 of the per-base entry at offset 0x34, mirrors the new
 * value into the global walk callback slot, and writes it back.
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00441df0 */
void ScaledOrStore_00441df0(void) {
    ScenegraphNode *n = (ScenegraphNode *)(g_scaledInit_00542044 * 4);
    unsigned int v = n->state_mask | 1;
    g_walkCallback = (void (*)(void))v;
    n->state_mask = v;
}

/* @addr 0x004677a0 */
void ScaledOrStore_004677a0(void) {
    ScenegraphNode *n = (ScenegraphNode *)(g_scaledInit_00542044 * 4);
    unsigned int v = n->state_mask | 1;
    g_walkCallback = (void (*)(void))v;
    n->state_mask = v;
}

/* @addr 0x004903d0 */
void ScaledOrStore_004903d0(void) {
    ScenegraphNode *n = (ScenegraphNode *)(g_fightGroupHead * 4);
    unsigned int v = n->state_mask | 1;
    g_walkCallback = (void (*)(void))v;
    n->state_mask = v;
}
