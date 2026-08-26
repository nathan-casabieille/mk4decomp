/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x0048e780 (35b)
 *   mov     eax, [g_baseSel]
 *   mov     eax, [eax*4 + 0x3c]
 *   mov     [g_currentNodeIdx], eax
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   jmp     +0x2d
 */
extern void WalkCallbackSetClearDirty(void);
void ScaledChain3c74Jmp(void) {
    unsigned int v = ((ScenegraphNode *)(g_baseSel * 4))->child_a;
    g_currentNodeIdx = v;
    g_walkCallback = (void (*)(void))((ScenegraphNode *)(v * 4))->fsm_state;
    WalkCallbackSetClearDirty();
}
