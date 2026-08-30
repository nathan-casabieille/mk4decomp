/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00404e50 (52b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x18]
 *   mov     [g_currentNodeIdx], eax
 *   mov     ecx, [eax*4 + 0x28]
 *   mov     [g_xformEntityIdx], ecx
 *   mov     eax, [ecx*4 + 0]
 *   or      al, 8
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0], eax
 *   ret
 */
#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* arena-safe: the auto-split lift dereferenced raw VAs as host pointers -
 * the (code **) family - and was first LINKED (and first EXERCISED, by the
 * Phase4 walk-in) in 2026-08-30's build. */
void ScaledChainOr8(void) {
    unsigned int s, e, v;

    s = MK4_NODE_AT(unsigned int, (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu)), 0x18);
    *(unsigned int *)MK4_VA(unsigned int, 0x542044u) = s;
    e = MK4_NODE_AT(unsigned int, s, 0x28);
    *(unsigned int *)MK4_VA(unsigned int, 0x542048u) = e;
    v = *(unsigned int *)MK4_PTR(e * 4u) | 8u;
    *(unsigned int *)MK4_VA(unsigned int, 0x54206cu) = v;
    *(unsigned int *)MK4_PTR(e * 4u) = v;
}
#else
void ScaledChainOr8(void) {
    unsigned int s;
    unsigned int e;
    unsigned int v;
    s = ((ScenegraphNode *)(g_fightGroupHead * 4))->child_chain;
    g_currentNodeIdx = s;
    e = ((ScenegraphNode *)(s * 4))->queue_idx;
    g_xformEntityIdx = e;
    v = *(unsigned int *)(e * 4) | 8;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(e * 4) = v;
}
#endif
