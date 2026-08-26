/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x00489e90 (70b)
 *   copy g_scaledInit → g_pendingNodeType; load g_primary_0052d74c;
 *   if non-neg call F1; pause → ret; load g_secondary_00538068 → g_xformEntityIdx;
 *   if signed: jmp T1.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_primary_0052d74c;
extern unsigned int g_secondary_00538068;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_primary_0052d74c (*(unsigned int *)MK4_VA(unsigned int, 0x52d74cu))
#define g_secondary_00538068 (*(unsigned int *)MK4_VA(unsigned int, 0x538068u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif

extern void DualSubFromField(void);
extern void DualSubFromField(void);
void ScaledStateNegCallPauseLoad(void) {
    int v;
    g_pendingNodeType = g_currentNodeIdx;
    v = (int)g_primary_0052d74c;
    g_walkCallback = (void (*)(void))v;
    if (v < 0) {
        DualSubFromField();
        if (g_framePauseFlag != 0) return;
    }
    v = (int)g_secondary_00538068;
    g_pendingNodeType = g_xformEntityIdx;
    g_walkCallback = (void (*)(void))v;
    if (v < 0) {
        DualSubFromField();
    }
}
