/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueEnd;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueWorkType;
extern u32 g_pendingNodeType;
extern u32 g_eventQueueNotMask;

/* @addr 0x0048e330 (70b)
 *   load g_fightGroupHead, g_player1NodeIdx; cmp; load g_state_00537f48;
 *   jne skip; load g_state_005380e0 → walk;
 *   load dirty | 4; cmp eax,6; if eq: dirty stays; else: dirty ^= 4;
 *   ret.
 */
extern unsigned int g_state_00538158_ll;
extern unsigned int g_state_00537f48;
extern unsigned int g_state_005380e0;
void LoadCmpStateOrDirtyToggle_0048e330(void) {
    unsigned int v = g_state_00537f48;
    g_walkCallback = (void (*)(void))v;
    if (g_fightGroupHead != g_state_00538158_ll) {
        v = g_state_005380e0;
        g_walkCallback = (void (*)(void))v;
    }
    g_xformDirtyFlags |= 4;
    if (v != 6) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
}
