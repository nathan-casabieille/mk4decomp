/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00460420 (68b)
 *   push OFFSET g_dispatchSave300_00542978; call helper; if pause → ret;
 *   else store g_xformEntityIdx into g_fightGroupHead[+0x24],
 *   clear walk and g_fightGroupHead[+0x28], jmp T.
 */
extern unsigned int g_dispatchSave300_00542978;
extern void ArgScaledTestStore_00494140(void);
extern void ScaledLoadOrSetJmp_00406b20(void);
void PushCallStoreClearJmp_00460420(void) {
    ArgScaledTestStore_00494140((int)&g_dispatchSave300_00542978);
    if (g_framePauseFlag != 0) {
        return;
    }
    *(unsigned int *)(g_fightGroupHead * 4 + 0x24) = g_xformEntityIdx;
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0;
    ScaledLoadOrSetJmp_00406b20();
}
