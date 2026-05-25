/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ab630 (53b)
 *   load g_walkCallback; store to g_dispatchSave_00538150;
 *   call F; pause-test → ret;
 *   load walk; and 0xffff; imul g_dispatchSave_00538150; shr 16; store walk.
 */
extern unsigned int g_dispatchSave_00538150;
extern void DualAddSar_004ab600(void);
void StorePauseImulShr16_004ab630(void) {
    g_dispatchSave_00538150 = (unsigned int)g_walkCallback;
    DualAddSar_004ab600();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_walkCallback = (void (*)(void))((((unsigned int)g_walkCallback & 0xffff) * g_dispatchSave_00538150) >> 16);
}
