/**
 * Auto-split from misc_matchesNN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1940 (85b)
 *   ScaledInitOrSelfPtrSetType variant with extra side-effect:
 *     also clears [fightGroupHead*4 + 0x6c] before recursing.
 */
extern void func_0041f780_nn(void);
void ScaledInitOrSelfPtrSetType14_004a1940(void) {
    unsigned int *base = (unsigned int *)(g_baseSel_00542060 * 4);
    unsigned int prev = base[0x84 / 4];
    base[0x84 / 4] = 0;
    if (prev != 0) {
        func_0041f780_nn();
        return;
    }
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x6c) = 0;
    base[8 / 4] = 0x004a1940;
    base[0x84 / 4] = 1;
    g_pendingNodeType = 0x14;
    g_framePauseFlag = 1;
}
