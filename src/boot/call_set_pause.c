/**
 * Auto-split from misc_matches4.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0041f830 (16b)
 *   call    F
 *   mov     [g_framePauseFlag], 1
 *   ret
 */
extern void ScaledNeg1SetPause(void);
void CallSetPause(void) {
    ScaledNeg1SetPause();
    g_framePauseFlag = 1;
}
