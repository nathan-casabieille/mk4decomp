/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004a4260 (75b)
 *   pendingNodeType = 0x4200b0 (a func ptr stored as data);
 *   eventQueueWorkType = 0x1000; call F; pause → ret;
 *   eax = 2; [0x543800] = -1; walk = eax; [0x52aac4] = eax;
 *   eventQueueWorkType = 0; jmp T.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_tickFlagF;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameMode (*(unsigned int *)MK4_VA(unsigned int, 0x543800u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_tickFlagF (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

extern void *AllocNode(void);
extern void Push16Call(void);
void InitDispatchersJmp(void) {
    g_pendingNodeType = 0x004200b0;
    g_eventQueueWorkType = 0x1000;
    AllocNode();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_gameMode = 0xffffffff;
    g_walkCallback = (void (*)(void))2;
    g_tickFlagF = 2;
    g_eventQueueWorkType = 0;
    Push16Call();
}
