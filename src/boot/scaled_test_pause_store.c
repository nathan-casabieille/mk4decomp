/**
 * Auto-split from misc_matchesHH.c
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
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


/* @addr 0x00408860 (68b)
 *   load scaled+0x28 into walk; if non-zero clear dirty bit 4 and ret;
 *   else call F; pause → ret; load g_scaledInit and g_xformEntityIdx;
 *   store xformEntityIdx into [scaledInit*4 + 0x28]; ret.
 */
extern void MStackPush2Burst6Init(void);
#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* NATIVE twin: same body through the node seam. The node's +0x28 slot is
 * the "already has a queue entry" cache - non-zero clears the dirty bit and
 * returns, zero runs the burst init and stamps the current entity there. */
void ScaledTestPauseStore(void)
{
    unsigned int v = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x28);

    g_walkCallback = v;
    if (v) {
        g_xformDirtyFlags &= 0xfffffffbu;
        return;
    }
    MStackPush2Burst6Init();
    if (g_framePauseFlag) return;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x28) = g_xformEntityIdx;
}
#else
void ScaledTestPauseStore(void) {
    unsigned int v = ((ScenegraphNode *)(g_currentNodeIdx * 4))->queue_idx;
    g_walkCallback = (void(*)(void))v;
    if (v) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFBu;
        return;
    }
    MStackPush2Burst6Init();
    if (g_framePauseFlag) return;
    ((ScenegraphNode *)(g_currentNodeIdx * 4))->queue_idx = g_xformEntityIdx;
}
#endif
