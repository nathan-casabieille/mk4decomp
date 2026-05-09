/**
 * End-of-frame finalize step.
 *
 * Called after the per-frame logic + render passes. Ticks all
 * entities one last time and bumps the logic frame counter,
 * unless the pause flag is set (e.g. menu paused or VSync stall).
 */
#include "game/tick.h"
#include "engine/scenegraph.h"

/*
 * Wrap up the current frame: run TickAllEntities, then advance
 * the logic counter when not paused.
 *
 * @addr 0x00405400
 */
void FrameFinalize(void)
{
    TickAllEntities();
    if (g_framePauseFlag == 0) {
        g_logicFrameCounter++;
    }
}
