/**
 * Fight subsystem outer dispatcher.
 *
 * Three iterations of (set up entity-queue head pair + extra
 * scratch pointers, call FightFrameStep_Inner, check pause flag).
 * Pairs come from a 6-entry array; extras come from three triples
 * of unrelated tables.
 */
#include "game/tick.h"
#include "engine/scenegraph.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueTotal (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_fightGroupHeads ((unsigned int *)MK4_VA(unsigned int, 0x53a4a0u))
#define g_fightTableA0 (*(unsigned int *)MK4_VA(unsigned int, 0x4e9250u))
#define g_fightTableA1 (*(unsigned int *)MK4_VA(unsigned int, 0x4e92c8u))
#define g_fightTableA2 (*(unsigned int *)MK4_VA(unsigned int, 0x4e9318u))
#define g_fightTableB0 (*(unsigned int *)MK4_VA(unsigned int, 0x542948u))
#define g_fightTableB1 (*(unsigned int *)MK4_VA(unsigned int, 0x4e9300u))
#define g_fightTableB2 (*(unsigned int *)MK4_VA(unsigned int, 0x54294cu))
#define g_fightTableC0 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50a4u))
#define g_fightTableC1 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50a8u))
#define g_fightTableC2 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50b0u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


/*
 * @addr 0x0045c5c0
 */
void FightFrameStep(void)
{
    g_currentNodeIdx  = (u32)MK4_UNPTR(&g_fightGroupHeads[0]) >> 2;
    g_xformEntityIdx  = (u32)MK4_UNPTR(&g_fightGroupHeads[1]) >> 2;
    g_pendingNodeType = (u32)MK4_UNPTR(&g_fightTableA0) >> 2;
    g_eventQueueTotal = (u32)MK4_UNPTR(&g_fightTableB0) >> 2;
    g_fightGroupHead  = (u32)MK4_UNPTR(&g_fightTableC0) >> 2;
    FightFrameStep_Inner();
    if (g_framePauseFlag != 0) return;

    g_currentNodeIdx  = (u32)MK4_UNPTR(&g_fightGroupHeads[2]) >> 2;
    g_xformEntityIdx  = (u32)MK4_UNPTR(&g_fightGroupHeads[3]) >> 2;
    g_pendingNodeType = (u32)MK4_UNPTR(&g_fightTableA1) >> 2;
    g_eventQueueTotal = (u32)MK4_UNPTR(&g_fightTableB1) >> 2;
    g_fightGroupHead  = (u32)MK4_UNPTR(&g_fightTableC1) >> 2;
    FightFrameStep_Inner();
    if (g_framePauseFlag != 0) return;

    g_currentNodeIdx  = (u32)MK4_UNPTR(&g_fightGroupHeads[4]) >> 2;
    g_xformEntityIdx  = (u32)MK4_UNPTR(&g_fightGroupHeads[5]) >> 2;
    g_pendingNodeType = (u32)MK4_UNPTR(&g_fightTableA2) >> 2;
    g_eventQueueTotal = (u32)MK4_UNPTR(&g_fightTableB2) >> 2;
    g_fightGroupHead  = (u32)MK4_UNPTR(&g_fightTableC2) >> 2;
    FightFrameStep_Inner();
}
