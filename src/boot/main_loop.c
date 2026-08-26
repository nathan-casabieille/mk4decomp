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

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_appFlags (*(unsigned int *)MK4_VA(unsigned int, 0x7af914u))
#define g_inLoopStep (*(unsigned int *)MK4_VA(unsigned int, 0x7af92cu))
#define g_lastFrameTime (*(unsigned int *)MK4_VA(unsigned int, 0x7af908u))
#define g_loopCounter (*(unsigned int *)MK4_VA(unsigned int, 0x7af90cu))
#define g_sleepBudgetMs (*(unsigned int *)MK4_VA(unsigned int, 0x7af910u))
#endif


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
