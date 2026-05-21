/**
 * Auto-split from misc_matches4.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041f830 (16b)
 *   call    F
 *   mov     [g_framePauseFlag], 1
 *   ret
 */
extern void ScaledNeg1SetPause_0041f840(void);
void CallSetPause_0041f830(void) {
    ScaledNeg1SetPause_0041f840();
    g_framePauseFlag = 1;
}
