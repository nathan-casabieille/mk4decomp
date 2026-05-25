/**
 * Game event queue.
 */
#include "game/tick.h"
#include "engine/scenegraph.h"

/* Base of the 20-entry packed-ptr ring buffer (0x0053a4b8..0x0053a508). */
extern unsigned int g_eventQueueDrainBase_0053a4b8;

/* Drain loop lives in src/engine/misc_matchesQQ.c at 0x0045c840. The
 * linker pads the gap between this function's tail jmp and the loop
 * entry to 16-byte alignment, producing the orig's `jmp +3; 90 90 90`
 * pattern. */
extern void EventQueueDrainLoop_0045c840(void);

/*
 * Snapshot the active event-queue cursor (g_eventQueueActive) into the
 * working slot (g_xformEntityIdx), pin the buffer-end packed pointer
 * (&g_eventQueueDrainBase_0053a4b8 + 80 == 0x0053a508 >> 2) in g_eventQueueTotal,
 * then tail-call into EventQueueDrainLoop_0045c840 to walk the queue.
 *
 * The shr survives const-folding because (&g_data + 80) carries a
 * DIR32 link-time reloc; MSVC SP3 /O2 emits the runtime
 * `mov reg, OFFSET sym+0x50; shr reg, 2` sequence. The trailing void
 * call tail-call-optimizes to a 5-byte `jmp`.
 *
 * @addr 0x0045c820
 */
void DispatchEventQueue(void)
{
    unsigned int total = ((unsigned int)&g_eventQueueDrainBase_0053a4b8 + 80) >> 2;
    g_xformEntityIdx = g_eventQueueActive;
    g_eventQueueTotal = total;
    EventQueueDrainLoop_0045c840();
}

/*
 * Promote the pending event-queue snapshot into the active slot.
 * Called at the end of each fight frame after DispatchEventQueue
 * has finished filling Pending.
 *
 * @addr 0x0045c8d0
 */
void DispatchEventQueue_Commit(void)
{
    g_eventQueueActive = g_eventQueuePending;
}
