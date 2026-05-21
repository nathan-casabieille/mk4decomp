/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;

/* @addr 0x0048e740 (62b)
 *   scaled chain 0x3c → 0x74; and 0xf000; cmp 0x4000;
 *   if eq: or al,1 → store dirty;  else and al,0xfe → store dirty.
 */
void ScaledChainAndF000DirtyToggle_0048e740(void) {
    unsigned int v;
    v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x3c);
    g_scaledInit_00542044 = v;
    v = *(unsigned int *)(v * 4 + 0x74) & 0xf000;
    g_walkCallback = (void(*)(void))v;
    if (v == 0x4000) {
        g_xformDirtyFlags = g_xformDirtyFlags | 1;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
