/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004be630 (91b)
 *   6× push 0, push imm; call F; add esp 8; ret. Pattern of 6 unique 2-arg calls.
 */
extern void Snd3DSourceCleanup(int, int);
void SixDoublePushCall(void) {
    Snd3DSourceCleanup(0x138, 0);
    Snd3DSourceCleanup(0x333, 0);
    Snd3DSourceCleanup(0x3ec, 0);
    Snd3DSourceCleanup(0x3f0, 0);
    Snd3DSourceCleanup(0x3f7, 0);
    Snd3DSourceCleanup(0x420, 0);
}
