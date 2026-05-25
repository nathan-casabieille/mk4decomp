/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueEnd;

/* @addr 0x0048f2a0 (63b)
 *   load 3 globals; push esi (saving callee reg); cmp/conditional store dance;
 *   pop esi; ret.
 */
extern unsigned int g_player1NodeIdx;
extern unsigned int g_state_00535d04;
extern unsigned int g_state_0053a774;
void ScaledLoadCmpStoreXfm_0048f2a0(void) {
    unsigned int s1 = g_player1NodeIdx;
    unsigned int fg = g_fightGroupHead;
    unsigned int s2 = g_state_00535d04;
    unsigned int s3 = g_state_0053a774;
    g_walkCallback = (void (*)(void))s3;
    g_eventQueueCurrent = s2;
    g_scaledInit_00542044 = s1;
    if (fg != s1) {
        g_walkCallback = (void (*)(void))s2;
    }
    if (fg != s1) {
        g_eventQueueCurrent = s3;
    }
}
