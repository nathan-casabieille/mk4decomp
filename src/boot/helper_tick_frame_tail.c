/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_tickFrameTailVar;
extern unsigned int g_dispatchSave894;
extern unsigned int g_tickFrameTailVar2;
extern unsigned int g_bootChainState3;
extern unsigned int g_bootChainScaled4;
extern unsigned int g_bootChainScaled1;
extern unsigned int g_bootChainPair1;
extern unsigned int g_bootChainScaled2;
extern unsigned int g_tickFrameNodeA;
extern unsigned int g_tickFrameNodeB;
extern unsigned int g_bootChainScaled3;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_bootChainPair1 (*(unsigned int *)MK4_VA(unsigned int, 0x541e84u))
#define g_bootChainScaled1 (*(unsigned int *)MK4_VA(unsigned int, 0x541e88u))
#define g_bootChainScaled2 (*(unsigned int *)MK4_VA(unsigned int, 0x541e8cu))
#define g_bootChainScaled3 (*(unsigned int *)MK4_VA(unsigned int, 0x541ea0u))
#define g_bootChainScaled4 (*(unsigned int *)MK4_VA(unsigned int, 0x541e9cu))
#define g_bootChainState3 (*(unsigned int *)MK4_VA(unsigned int, 0x541e98u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave894 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5124u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_tickFrameNodeA (*(unsigned int *)MK4_VA(unsigned int, 0x541e90u))
#define g_tickFrameNodeB (*(unsigned int *)MK4_VA(unsigned int, 0x541e94u))
#define g_tickFrameTailVar (*(unsigned int *)MK4_VA(unsigned int, 0x4d511cu))
#define g_tickFrameTailVar2 (*(unsigned int *)MK4_VA(unsigned int, 0x4d5138u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


void Helper_TickFrameTail(void)
{
    g_currentNodeIdx = g_bootChainState3;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_bootChainScaled4;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_bootChainScaled1;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_bootChainPair1;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_bootChainScaled2;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_tickFrameNodeA;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_tickFrameNodeB;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_bootChainScaled3;
    g_walkCallback = g_dispatchSave894;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_bootChainState3;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_bootChainPair1;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_bootChainScaled1;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_bootChainScaled2;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_tickFrameNodeA;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = g_tickFrameNodeB;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
}

