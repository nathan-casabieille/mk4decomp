/**
 * Per-frame engine loop body.
 *
 * Captures the wall-clock time, runs one BeginFrame / GameLogicStep /
 * DrawScene / PresentFrame, then catches up to the 60 Hz baseline if
 * we fell behind (up to 3 extra GameLogicStep calls), then sleeps
 * the remaining budget (clamped to 1..16 ms).
 */
#include "platform/win32.h"
#include "engine/render.h"
#include "game/tick.h"

/*
 * @addr 0x004b2750
 */
void MainLoopStep(void)
{
    int delta;
    int counter;
    int sleep_ms;

    if (!(g_appFlags & 1)) {
        g_appFlags |= 1;
        g_lastFrameTime = QueryMicroTimer();
    }
    BeginFrame(1);
    GameLogicStep();
    DrawScene();
    PresentFrame();

    g_loopCounter   = 0;
    g_sleepBudgetMs = 0;
    g_inLoopStep    = 1;

    counter = 0;
    while (1) {
        delta = (int)QueryMicroTimer() - (int)g_lastFrameTime;
        if (delta < 0x4e20) {
            break;
        }
        GameLogicStep();
        g_lastFrameTime += 0x411b;
        ++counter;
        ++g_loopCounter;
        if (counter >= 3) {
            break;
        }
    }

    sleep_ms = -1 - (delta - 16667) / 1000;
    g_inLoopStep = 0;

    if (sleep_ms > 1) {
        if (sleep_ms > 16) sleep_ms = 16;
        g_sleepBudgetMs += sleep_ms;
        Sleep(sleep_ms);
    }
    g_lastFrameTime = QueryMicroTimer();
}
