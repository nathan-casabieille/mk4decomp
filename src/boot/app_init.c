/**
 * High-level engine init (called from WinMain).
 *
 * Bring up the timer, joystick, install validator, gfx pipeline,
 * audio (Aux + DSound), various sub-systems, then run the
 * renderer auto-fallback ladder (mode 1 -> 2 -> 3 -> 5) calling
 * TryInitRenderer until one succeeds. Tail does demo-mode init
 * and a small RNG dice-roll for the random seed.
 */
#include "platform/win32.h"
#include "engine/render.h"
#include "game/statemachine.h"
#include "audio/sound.h"
#include "game/tick.h"

extern void UpdateWindowTitle(void);
extern s32  ValidateInstall(void);
extern void Joystick_Init(void);
extern u32  g_pumpFlagD8, g_pumpFlagDC, g_pumpFlagE0, g_pumpFlagE4;

/*
 * @addr 0x004b2500
 */
void AppInit(HWND hwnd)
{
    g_appInitHwnd = hwnd;
    Timer_Init();
    Joystick_Init();
    ValidateInstall();
    AppInit_PostJoy();
    AppInit_PreInstall();
    Gfx_Init(g_appInitHwnd);
    AuxAudio_Init(g_appInitHwnd);
    AuxAudio_SetMasterVol(*(int *)&g_audioMasterVol & 0xff);
    DSound_Init(g_appInitHwnd);
    AppInit_AudioPostInit(g_audioPostFlag);
    AppInit_PostDSound();
    AppInit_Misc1();
    AppInit_Misc2();
    AppInit_Misc3();

    g_pumpFlagE4 = 1;
    g_pumpFlagE0 = 1;
    g_pumpFlagDC = 1;
    g_pumpFlagD8 = 1;
    Helper_GSM_PlayMusic(1);
    if (TryInitRenderer() < 0) {
        g_pumpFlagD8 = 0;
        Helper_GSM_PlayMusic(2);
        if (TryInitRenderer() < 0) {
            g_pumpFlagDC = 0;
            Helper_GSM_PlayMusic(3);
            if (TryInitRenderer() < 0) {
                g_pumpFlagE0 = 0;
                Helper_GSM_PlayMusic(5);
                if (TryInitRenderer() < 0) {
                    g_pumpFlagE4 = 0;
                }
            }
        }
    }

    UpdateWindowTitle();
    AppInit_Misc4();
    AppInit_Misc5();
    AppInit_Misc6();
    AppInit_Misc7();
    AppInit_Misc8();

    if (g_demoModeFlag == 0) {
        GameStateMachine(7);
    }

    g_appInitFlag1 = 0;
    g_appInitFlag2 = 0;
    if (AppInit_Probe()) {
        /* MK4_SEED=<n>: seed the RNG from the environment instead of the
         * wall clock, so a run is REPRODUCIBLE. The original seeds from
         * timeGetTime, and two lines below the seed decides which of two
         * init paths the app takes - so every launch is a different run, and
         * on this port some of those paths reach code that is not converted
         * yet and fault. That is what made MK4_BOOT_MATCH read 10/10 one
         * hour and 0/8 the next on identical binaries, and what invalidated
         * a string of A/B measurements in the process. Off by default: the
         * clock still seeds it unless the variable is set. */
        { extern char *getenv(const char *); extern int atoi(const char *);
          const char *seed = getenv("MK4_SEED");
          Crt_srand(seed ? atoi(seed) : (int)timeGetTime()); }
        if (Crt_rand() & 3) {
            g_appInitFlag1 = 1;
        } else {
            g_appInitFlag2 = Crt_rand() | 0x1881;
        }
    }
}
