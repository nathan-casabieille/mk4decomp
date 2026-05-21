/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004ac570 (116b audio) - audio re-entrant teardown:
 *   if g_audioState0C set bail; mark it 1; if g_timerFlag set,
 *   call Helper_AuxAudio_PostInit; if it returns non-null, call
 *   timeKillEvent-like IAT with (preState,0x808,2,0). If
 *   g_audioState00 set call IAT-2240 (timeGetTime), subtract
 *   prior g_audioState00 from it, add to g_timerLastNow; clear
 *   g_audioState00 and g_timerFlag.
 */
void Helper_TitleEnterStateB(void) {
    unsigned int tf;
    if (g_audioState0C != 0) return;
    tf = g_timerFlag;
    g_audioState0C = 1;
    if (tf != 0) {
        if (((int(*)(void))Helper_AuxAudio_PostInit)() != 0) {
            ((void(__stdcall *)(unsigned int, int, int, int))g_iat_004d2244)(g_audioPreState, 0x808, 2, 0);
        }
    }
    if (g_audioState00 != 0) {
        unsigned int now = ((unsigned int(__stdcall *)(void))g_iat_004d2240)();
        now -= g_audioState00;
        g_audioState00 = 0;
        g_timerLastNow += now;
    }
    g_timerFlag = 0;
}

