/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404680 (71b)
 *   zero a bunch of state globals, with one extra-conditional zero on
 *   g_bootInitState if g_audioPathFlag == 0 && g_audioPathFlag2 == 0.
 */
extern unsigned int g_audioPathFlag;
extern unsigned int g_stateCountdown;
extern unsigned int g_dispatchSave402;
extern unsigned int g_audioPathFlag2;
extern unsigned int g_bootInitState;
extern unsigned int g_dispatchSave266;
extern unsigned int g_dispatchSave_00537f8c;
extern unsigned int g_installSelfCounter2;
extern unsigned int g_player1State;
extern unsigned int g_player2State;
extern unsigned int g_dispatchSave49;
void ZeroMultiGlobalsCmp(void) {
    g_walkCallback = 0;
    g_stateCountdown = 0;
    g_dispatchSave402 = 0;
    if (g_audioPathFlag == 0 && g_audioPathFlag2 == 0) {
        g_bootInitState = 0;
    }
    g_dispatchSave266 = 0;
    g_dispatchSave_00537f8c = 0;
    g_installSelfCounter2 = 0;
    g_player1State = 0;
    g_player2State = 0;
    g_dispatchSave49 = 0;
}
