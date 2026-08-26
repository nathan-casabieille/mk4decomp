/**
 * End-of-frame finalize step.
 *
 * Called after the per-frame logic + render passes. Ticks all
 * entities one last time and bumps the logic frame counter,
 * unless the pause flag is set (e.g. menu paused or VSync stall).
 */
#include "game/tick.h"
#include "engine/scenegraph.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_logicFrameCounter (*(unsigned int *)MK4_VA(unsigned int, 0x53a79cu))
#endif


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
