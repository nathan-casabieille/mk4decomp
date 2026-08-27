/**
 * 2 "scaled-load + xor 1 + dual-store" helpers (29 bytes each).
 *
 * Pattern:
 *   mov     ecx, [g_baseSelector]
 *   mov     eax, [ecx*4 + 0x34]
 *   xor     eax, 1
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   ret
 *
 * Toggles bit 0 of the per-base entry at offset 0x34, mirrors the
 * new value into the global walk callback slot. Variant of
 * ScaledOrStore (uses xor instead of or).
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x004900f0 */
void ScaledXorStore_004900f0(void) {
    ScenegraphNode *n = (ScenegraphNode *)MK4_PTR((g_currentNodeIdx * 4));
    unsigned int v = n->state_mask ^ 1;
    g_walkCallback = (void (*)(void))v;
    n->state_mask = v;
}

/* @addr 0x004903b0 */
void ScaledXorStore_004903b0(void) {
    ScenegraphNode *n = (ScenegraphNode *)MK4_PTR((g_fightGroupHead * 4));
    unsigned int v = n->state_mask ^ 1;
    g_walkCallback = (void (*)(void))v;
    n->state_mask = v;
}
