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

#ifdef TARGET_SDL
    /* MK4_TRACE_PAD: bracket the input aggregate. It reads 1 in
     * engine_frame.c after the publish and 0 by the time the node pump runs,
     * on the same frame - this says which side of MainLoopStep loses it. */
    { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
      extern unsigned int g_mk4FrameNo;
      static int tr = -1; static unsigned n;
      if (tr < 0) tr = getenv("MK4_TRACE_PAD") != 0;
      if (tr && n < 20) { unsigned char pad = *MK4_VA(unsigned char, 0x4d50b8u);
          if (pad != 0) { n++;
              SDL_Log("PAD f=%u MainLoopStep entry pad=%02x", g_mk4FrameNo, pad); } } }
#endif
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
#ifdef TARGET_SDL
    /* MK4_FIXED_STEP=1: run exactly ONE GameLogicStep per frame.
     *
     * The catch-up loop below calls GameLogicStep up to three extra times
     * depending on QueryMicroTimer, i.e. on wall-clock and machine load, so
     * two headless runs of the same command execute a different number of
     * logic steps and can end on different frames. That is the whole source
     * of the fight scene settling on 157664 px or 155512 px at random, and it
     * silently invalidates any A/B done by diffing frames - the difference
     * between those two states is 14052 px, which is larger than most effects
     * worth measuring.
     *
     * Off by default: skipping the catch-up changes how fast the game runs,
     * which is a behaviour change, not a fix. On for measurement. */
    { extern char *getenv(const char *);
      static int fixed = -1;
      if (fixed < 0) fixed = getenv("MK4_FIXED_STEP") != 0;
      if (fixed) { g_lastFrameTime = QueryMicroTimer(); goto after_catchup; } }
#endif
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

#ifdef TARGET_SDL
after_catchup:
    delta = 0;
#endif
    sleep_ms = -1 - (delta - 16667) / 1000;
    g_inLoopStep = 0;

    if (sleep_ms > 1) {
        if (sleep_ms > 16) sleep_ms = 16;
        g_sleepBudgetMs += sleep_ms;
        Sleep(sleep_ms);
    }
    g_lastFrameTime = QueryMicroTimer();
}
