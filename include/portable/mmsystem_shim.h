/**
 * Portable <mmsystem.h> shim.
 *
 * The matching build (MSVC, _WIN32) needs the real <mmsystem.h> for timeGetTime
 * et al. The native port (NON_MATCHING + a non-Windows toolchain under
 * -ffreestanding) has no such header; the few symbols the engine actually uses
 * are provided by the host shims (src/platform/sdl/host_win32.c). Including this
 * header instead of <mmsystem.h> keeps the matching preprocessing identical
 * (it just includes <mmsystem.h>) while letting the native build compile.
 */
#ifndef MK4_PORTABLE_MMSYSTEM_SHIM_H
#define MK4_PORTABLE_MMSYSTEM_SHIM_H

#if defined(NON_MATCHING) && (!defined(_WIN32) || defined(MK4_WIN32_SHIM))
/* Native: just the multimedia-timer entry the engine calls (host_win32.c). */
extern unsigned int timeGetTime(void);
#else
#include <mmsystem.h>
#endif

#endif /* MK4_PORTABLE_MMSYSTEM_SHIM_H */
