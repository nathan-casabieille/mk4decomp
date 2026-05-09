/**
 * Game event queue.
 */
#include "game/tick.h"

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
