/**
 * Host shims for the handful of Win32 API functions the converted engine
 * still calls by name (TARGET=sdl). These are the small, clean cases the
 * engine uses directly (not through a COM/IAT object); the larger Glide /
 * DirectSound / DirectDraw surface routes through the PAL instead.
 *
 * Backed by SDL where there is a real equivalent, stubbed where the native
 * port does not (yet) reproduce the behaviour (MCI = the original's CD/MIDI
 * media control). Compiled only for TARGET=sdl.
 *
 * Signatures are kept loose on purpose: the converted call sites compile
 * against the engine's own Win32 declarations (or, in the port-in-progress
 * build, implicit declarations); these definitions just satisfy the linker
 * with host-correct behaviour.
 */
#include <SDL2/SDL.h>

/* timeGetTime / Sleep: the engine's millisecond clock + frame pacing. */
unsigned timeGetTime(void)        { return (unsigned)SDL_GetTicks(); }
void     Sleep(unsigned long ms)  { SDL_Delay((Uint32)ms); }

/* mciSendCommandA: Media Control Interface (CD-audio / MIDI in the original).
 * No native equivalent wired yet - return 0 (= MMSYSERR_NOERROR, "success")
 * so the engine's media calls are harmless no-ops. Music/CD audio is a later
 * PAL-audio task. */
unsigned long mciSendCommandA(unsigned int dev, unsigned int msg,
                              unsigned long flags, unsigned long param)
{
    (void)dev; (void)msg; (void)flags; (void)param;
    return 0;
}
