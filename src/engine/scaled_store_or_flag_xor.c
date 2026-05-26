/**
 * Auto-split from misc_matchesNN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00428560 (85b)
 *   inc fightGroupHead[+0x28]; load fightGroupHead[+0x24] → scaled;
 *   or dirty |= 4; cmp [scaled+4], walk; if !=, dirty ^= 4 (clear).
 */
void ScaledStoreOrFlagXor_00428560(void) {
    unsigned int v;
    unsigned int s;
    v = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx + 1;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = v;
    s = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end;
    g_scaledInit_00542044 = s;
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    if (*(unsigned int *)(s * 4 + 4) != (unsigned int)g_walkCallback) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
}
