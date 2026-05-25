/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404680 (71b)
 *   zero a bunch of state globals, with one extra-conditional zero on
 *   g_bootInitState_00535de4 if g_audioPathFlag_0054355c == 0 && g_audioPathFlag2_00543710 == 0.
 */
extern unsigned int g_audioPathFlag_0054355c;
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_dispatchSave402_00537f10;
extern unsigned int g_audioPathFlag2_00543710;
extern unsigned int g_bootInitState_00535de4;
extern unsigned int g_dispatchSave266_0052ab00;
extern unsigned int g_dispatchSave_00537f8c;
extern unsigned int g_installSelfCounter2_00541d90;
extern unsigned int g_state4_0053a3e0;
extern unsigned int g_state4_0053a700;
extern unsigned int g_dispatchSave49_00535e44;
void ZeroMultiGlobalsCmp_00404680(void) {
    g_walkCallback = 0;
    g_stateCountdown_0053a3c0 = 0;
    g_dispatchSave402_00537f10 = 0;
    if (g_audioPathFlag_0054355c == 0 && g_audioPathFlag2_00543710 == 0) {
        g_bootInitState_00535de4 = 0;
    }
    g_dispatchSave266_0052ab00 = 0;
    g_dispatchSave_00537f8c = 0;
    g_installSelfCounter2_00541d90 = 0;
    g_state4_0053a3e0 = 0;
    g_state4_0053a700 = 0;
    g_dispatchSave49_00535e44 = 0;
}
