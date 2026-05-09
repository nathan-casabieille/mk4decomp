/**
 * Audio timer tick.
 *
 * Re-fires Audio_TimerSet once enough wall-clock time has elapsed
 * since the previous tick. The threshold is encoded as
 * (g_timerEndSec - g_timerStartSec) seconds, expanded to ms via the
 * 5*5*5*8 = 1000 lea/shl chain that MSVC pattern-matches on.
 */
#include "audio/sound.h"
#include "platform/win32.h"
#include <mmsystem.h>

/*
 * @addr 0x004ac4b0
 */
void Audio_TimerTick(void)
{
    if (g_timerActive == 0) return;
    if (timeGetTime() - g_timerLastNow <
        (g_timerEndSec - g_timerStartSec) * 1000) return;
    g_timerFlag = 0;
    Audio_TimerSet(g_timerActive, g_timerHandle,
                   g_timerEndSec, g_timerHandle);
}
