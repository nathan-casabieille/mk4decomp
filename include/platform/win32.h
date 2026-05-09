/**
 * Win32 platform interface.
 *
 * The matching build links against KERNEL32, USER32, GDI32, ADVAPI32,
 * WINMM, DDRAW, DSOUND. For the portable build, this header swaps to
 * SDL/Metal shims via #ifdefs (later).
 */
#ifndef MK4_PLATFORM_WIN32_H
#define MK4_PLATFORM_WIN32_H

#include "../types.h"

#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>
#include <ddraw.h>
#include <dsound.h>
#else
/* IDE-only shim - these typedefs let clang/IntelliSense parse the
 * source on non-Windows hosts. The matching build uses MSVC 5.0
 * under Wine where _WIN32 is defined and the real Win32 SDK headers
 * supply these types. */
typedef void *HINSTANCE;
typedef void *HWND;
typedef void *HANDLE;
typedef void *HDC;
typedef void *HBRUSH;
typedef void *HCURSOR;
typedef void *HICON;
typedef void *HMENU;
typedef void *HMODULE;
typedef void *LPVOID;
typedef const char *LPCSTR;
typedef char *LPSTR;
typedef u32 DWORD;
typedef u32 *LPDWORD;
typedef long LRESULT;
typedef u32 UINT;
typedef u32 WPARAM;
typedef long LPARAM;
typedef u32 ATOM;
typedef long BOOL;
typedef u32 HKEY;
typedef long LSTATUS;
typedef void *HRESULT;
#endif

/* Global Win32 application state - set by WinMain. */
extern HINSTANCE g_hInstance;       /* DAT_00f9f7c4 */
extern HWND      g_hMainWindow;     /* DAT_00f9f7c0 */
extern int       g_nCmdShow;        /* DAT_00f9f7cc */
extern HANDLE    g_hAppMutex;       /* DAT_00f9f7d0 - single-instance handle, CloseHandle'd on exit */

/* === API ==================================================== */

/* Tear-down of subsystems (renderer/audio/input/etc). Called from
 * ExitGame and from WM_DESTROY. */
void AppShutdown(void);                                  /* 0x004b2690 */

/* Best-effort shutdown: notifies the main window, releases the
 * single-instance handle, and exits the process. */
void ExitGame(void);                                     /* 0x004c4870 */

/* Initialise the high-resolution wall-clock timer. Reads the QPC
 * frequency, stashes "ticks per microsecond" into g_qpcUsPerTick,
 * and primes g_qpcStart with the current QPC value. Skipped (no-op)
 * when g_timerInitedSkip is set. */
void Timer_Init(void);                                   /* 0x004c4470 */

/* Returns wall-clock microseconds since Timer_Init, using QPC if it
 * was successfully initialised, otherwise falling back to
 * timeGetTime() * 1000. Result is a 32-bit unsigned int. */
u32 QueryMicroTimer(void);                               /* 0x004c4510 */

/* Pop up an error MessageBox-and-exit. Used by subsystem init paths
 * that can't recover. */
void ShowErrorMessage(const char *msg);                  /* 0x004c48c0 */

extern s32 g_timerInitedSkip;       /* 0x00f9f008 - non-zero = skip init */

#ifdef _WIN32
extern double         g_qpcUsPerTick;   /* 0x00f9f010 - QPC freq / 1e6 */
extern LARGE_INTEGER  g_qpcStart;        /* 0x00f9f018 - prime QPC reading */
#endif

#endif /* MK4_PLATFORM_WIN32_H */
