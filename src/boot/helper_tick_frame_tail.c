/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

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

