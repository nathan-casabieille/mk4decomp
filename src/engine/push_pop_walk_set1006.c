/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x00470ee0 (72b)
 *   PushPopWalk save/restore around setting walk = 0x1006 and
 *   storing it into g_baseSel[+0x74]. Symmetric stack frame.
 */
void PushPopWalkSet1006_00470ee0(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = (unsigned int)g_walkCallback;
    g_walkCallback = (void (*)(void))0x1006;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x74) = 0x1006;
    g_walkCallback = *(void (**)(void))(g_matrixStackTop * 4);
    g_matrixStackTop--;
}
