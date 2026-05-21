/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueWorkType;
extern u32 g_pendingNodeType;

/* @addr 0x00404680 (71b)
 *   zero a bunch of state globals, with one extra-conditional zero on
 *   g_state_00535de4 if g_state_0054355c == 0 && g_state_00543710 == 0.
 */
extern unsigned int g_state_0054355c_hh;
extern unsigned int g_state_0053a3c0;
extern unsigned int g_state_00537f10;
extern unsigned int g_state_00543710_hh;
extern unsigned int g_state_00535de4;
extern unsigned int g_state_0052ab00;
extern unsigned int g_state_00537f8c;
extern unsigned int g_state_00541d90;
extern unsigned int g_state_0053a3e0;
extern unsigned int g_state_0053a700;
extern unsigned int g_state_00535e44;
void ZeroMultiGlobalsCmp_00404680(void) {
    g_walkCallback = 0;
    g_state_0053a3c0 = 0;
    g_state_00537f10 = 0;
    if (g_state_0054355c_hh == 0 && g_state_00543710_hh == 0) {
        g_state_00535de4 = 0;
    }
    g_state_0052ab00 = 0;
    g_state_00537f8c = 0;
    g_state_00541d90 = 0;
    g_state_0053a3e0 = 0;
    g_state_0053a700 = 0;
    g_state_00535e44 = 0;
}
