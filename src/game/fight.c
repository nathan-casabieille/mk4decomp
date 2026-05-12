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

/*
 * @addr 0x0045c5c0
 */
void FightFrameStep(void)
{
    g_currentNodeIdx  = (u32)&g_fightGroupHeads[0] >> 2;
    g_xformEntityIdx  = (u32)&g_fightGroupHeads[1] >> 2;
    g_pendingNodeType = (u32)&g_fightTableA0 >> 2;
    g_eventQueueTotal = (u32)&g_fightTableB0 >> 2;
    g_fightGroupHead  = (u32)&g_fightTableC0 >> 2;
    FightFrameStep_Inner();
    if (g_framePauseFlag != 0) return;

    g_currentNodeIdx  = (u32)&g_fightGroupHeads[2] >> 2;
    g_xformEntityIdx  = (u32)&g_fightGroupHeads[3] >> 2;
    g_pendingNodeType = (u32)&g_fightTableA1 >> 2;
    g_eventQueueTotal = (u32)&g_fightTableB1 >> 2;
    g_fightGroupHead  = (u32)&g_fightTableC1 >> 2;
    FightFrameStep_Inner();
    if (g_framePauseFlag != 0) return;

    g_currentNodeIdx  = (u32)&g_fightGroupHeads[4] >> 2;
    g_xformEntityIdx  = (u32)&g_fightGroupHeads[5] >> 2;
    g_pendingNodeType = (u32)&g_fightTableA2 >> 2;
    g_eventQueueTotal = (u32)&g_fightTableB2 >> 2;
    g_fightGroupHead  = (u32)&g_fightTableC2 >> 2;
    FightFrameStep_Inner();
}
