/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bea30 (16b)
 *   call    F
 *   mov     [g_target], 0
 *   ret
 */
extern void ECM_Cleanup(void);
extern unsigned int g_rendererCheckVal;
void CallZero_004bea30(void) {
    ECM_Cleanup();
    g_rendererCheckVal = 0;
}
