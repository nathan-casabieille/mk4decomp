/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_tickFrameTailVar;
extern unsigned int g_dispatchSave894;
extern unsigned int g_tickFrameTailVar2;
extern unsigned int g_bootChainState3;
extern unsigned int g_bootChainScaled4;
extern unsigned int g_bootChainScaled1;
extern unsigned int g_bootChainPair1;
extern unsigned int g_bootChainScaled2;
extern unsigned int g_lit_00541e90;
extern unsigned int g_lit_00541e94;
extern unsigned int g_bootChainScaled3;

void Helper_TickFrameTail(void)
{
    g_scaledInit_00542044 = g_bootChainState3;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_bootChainScaled4;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_bootChainScaled1;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_bootChainPair1;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_bootChainScaled2;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_lit_00541e90;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_lit_00541e94;
    g_walkCallback = g_tickFrameTailVar;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_bootChainScaled3;
    g_walkCallback = g_dispatchSave894;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_bootChainState3;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_bootChainPair1;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_bootChainScaled1;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_bootChainScaled2;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_lit_00541e90;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = g_lit_00541e94;
    g_walkCallback = g_tickFrameTailVar2;
    Helper_TickAlt();
}

