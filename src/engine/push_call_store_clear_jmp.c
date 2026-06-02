/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00460420 (68b)
 *   push OFFSET g_dispatchSave300; call helper; if pause → ret;
 *   else store g_xformEntityIdx into g_fightGroupHead[+0x24],
 *   clear walk and g_fightGroupHead[+0x28], jmp T.
 */
extern unsigned int g_dispatchSave300;
extern void ArgScaledTestStore(void);
extern void ScaledLoadOrSetJmp(void);
void PushCallStoreClearJmp(void) {
    ArgScaledTestStore((int)&g_dispatchSave300);
    if (g_framePauseFlag != 0) {
        return;
    }
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = g_xformEntityIdx;
    g_walkCallback = (void (*)(void))0;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = 0;
    ScaledLoadOrSetJmp();
}
