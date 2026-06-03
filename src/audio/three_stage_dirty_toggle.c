/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;


/* @addr 0x004ac1a0 (80b)
 *   Three-step XOR toggle of dirty&4 across cmp checks. Each
 *   stage compares walk against a different global (538158, 538158
 *   again, 53815c) and either keeps or removes the bit-4 flag.
 */
void ThreeStageDirtyToggle(void) {
    unsigned int dirty;
    g_xformDirtyFlags |= 4;
    if (g_walkCallback == g_player1NodeIdx) return;
    dirty = g_xformDirtyFlags ^ 4;
    g_xformDirtyFlags = dirty;
    if (g_walkCallback == g_player1NodeIdx) return;
    dirty |= 4;
    g_xformDirtyFlags = dirty;
    if (g_player2NodeIdx == (unsigned int)g_walkCallback) return;
    dirty ^= 4;
    g_xformDirtyFlags = dirty;
}
