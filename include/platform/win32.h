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
extern LPSTR     g_cmdLine;         /* DAT_00f9f7c8 */
extern int       g_nCmdShow;        /* DAT_00f9f7cc */
extern HANDLE    g_hAppMutex;       /* DAT_00f9f7d0 - single-instance handle, CloseHandle'd on exit */

/* === API ==================================================== */

/* Tear-down of subsystems (renderer/audio/input/etc). Called from
 * ExitGame and from WM_DESTROY. */
void AppShutdown(void);                                  /* 0x004b2690 */

/* Boot-time engine startup (CreateMainWindow, parse cmdline, ...). */
void Boot(void);                                         /* 0x004c5070 */

extern u32 g_wndClassStyle;     /* 0x00f9f790 - WNDCLASS::style */
extern u32 g_wndClassWndProc;   /* 0x00f9f794 - WNDCLASS::lpfnWndProc */
extern HWND g_wndClassHInst;    /* 0x00f9f7a0 - WNDCLASS::hInstance */
extern u32 g_wndClassHIcon;     /* 0x00f9f7a4 - WNDCLASS::hIcon */
extern u32 g_wndClassHCursor;   /* 0x00f9f7a8 - WNDCLASS::hCursor */
extern u32 g_wndClassHbrBkgnd;  /* 0x00f9f7ac - WNDCLASS::hbrBackground */
extern u32 g_wndClassName;      /* 0x00f9f7b4 - WNDCLASS::lpszClassName */
extern s32 g_clientWidth;       /* 0x00f9f7b8 */
extern s32 g_clientHeight;      /* 0x00f9f7bc */

extern long __stdcall WndProc(HWND, UINT, WPARAM, LPARAM); /* 0x004c49b0 */

/* Post-window-create helper (sets up DDraw / palette related
 * state, returns the value stored in g_mode4PauseGate). */
u32  Helper_PostCreateWindow(void);                      /* 0x004c4950 */

/* High-level app init invoked by WinMain after Boot. */
void AppInit(HWND hwnd);                                 /* 0x004b2500 */

/* Sub-helpers called by AppInit (mostly anonymous - their internal
 * structure isn't reverse-engineered yet, but the matching diff
 * just needs REL32 relocations to point at named symbols). */
void AppInit_PostJoy(void);                              /* 0x004b5a10 */
void AppInit_PreInstall(void);                           /* 0x004b1cf0 */
void AuxAudio_SetMasterVol(s32 vol);                     /* 0x004ac9c0 */
void AppInit_AudioPostInit(s32 flag);                    /* 0x004c3eb0 */
void AppInit_PostDSound(void);                           /* 0x004b21b0 */
void AppInit_Misc1(void);                                /* 0x004b6180 */
void AppInit_Misc2(void);                                /* 0x004b5a80 */
void AppInit_Misc3(void);                                /* 0x004b2ac0 */
void AppInit_Misc4(void);                                /* 0x004bd960 */
void AppInit_Misc5(void);                                /* 0x004054c0 */
void AppInit_Misc6(void);                                /* 0x00418f10 */
void AppInit_Misc7(void);                                /* 0x00464830 */
void AppInit_Misc8(void);                                /* 0x004c51f0 */
s32  AppInit_Probe(void);                                /* 0x004ac060 */
void Crt_srand(u32 seed);                                /* 0x004c6500 */
s32  Crt_rand(void);                                     /* 0x004c6510 */

extern HWND g_appInitHwnd;       /* 0x007af924 */
extern u32  g_appInitFlag1;      /* 0x007af920 */
extern u32  g_appInitFlag2;      /* 0x007af91c */
extern u8   g_audioMasterVol;    /* 0x00543a88 */
extern u8   g_audioPostFlag;     /* 0x00543a90 */
extern u32  g_demoModeFlag;      /* 0x004ffd7c */

/* Per-frame engine step (60 Hz). */
void MainLoopStep(void);                                 /* 0x004b2750 */

extern u8  g_appFlags;            /* 0x00f9f714 - bit 0 = first-frame done */
extern u32 g_lastFrameTime;       /* 0x00f9f708 - QueryMicroTimer baseline */
extern u32 g_loopCounter;         /* 0x00f9f70c - per-step counter */
extern u32 g_sleepBudgetMs;       /* 0x00f9f710 - cumulative Sleep ms */
extern u32 g_inLoopStep;          /* 0x00f9f72c - 1 while inside the body */

/* Drain pending Win32 messages. */
void PumpMessages(void);                                 /* 0x004c52a0 */

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

extern u8 g_inErrorHandler;     /* 0x00f9f7f4 - set while ShowErrorMessage runs */

extern s32 g_timerInitedSkip;       /* 0x00f9f008 - non-zero = skip init */

#ifdef _WIN32
extern double         g_qpcUsPerTick;   /* 0x00f9f010 - QPC freq / 1e6 */
extern LARGE_INTEGER  g_qpcStart;        /* 0x00f9f018 - prime QPC reading */
#endif

/* === CRT entry / startup ==================================== */

/* MSVC 5.0 CRT entry-point. SEH-wrapped: builds an
 * _except_handler3 frame, calls _heap_init / _ioinit / _setargv /
 * _setenvp, parses argv[0] (handling quoted+space-separated forms),
 * fetches the startup-info nShowCmd, then calls WinMain via a
 * standard cdecl push of (hInstance, hPrevInstance, lpCmdLine,
 * nShowCmd) and _exit() with WinMain's return value. */
void entry(void);                                        /* 0x004c6cb0 */

/* SEH scope table and the canonical _except_handler3 - referenced
 * by the SEH frame the entry function pushes. */
extern u32 g_seh_scope_table[];                          /* 0x004d2ad0 */
void _except_handler3(void);                             /* 0x004c6bd8 */

/* IAT slots for kernel32 imports the entry function calls.  The
 * 6-byte `ff 15 + reloc` indirect-call form addresses these. */
extern void *g_iat_GetVersion;                           /* 0x004d2164 */
extern void *g_iat_GetCommandLineA;                      /* 0x004d2160 */
extern void *g_iat_GetStartupInfoA;                      /* 0x004d2138 */
extern void *g_iat_GetModuleHandleA;                     /* 0x004d212c */

/* Decomposed Win-version cache populated from GetVersion(). */
extern u32 g_winverMajor;                                /* 0x00f9f810 */
extern u32 g_winverMinor;                                /* 0x00f9f80c */
extern u32 g_winverCombined;                             /* 0x00f9f808 */
extern u32 g_winverBuild;                                /* 0x00f9f804 */

/* Cached results: lpCmdLine + the value returned by the early
 * one-arg setup helper. */
extern char *g_cmdline;                                  /* 0x00fa0ee8 */
extern u32   g_initRet;                                  /* 0x00f9f844 */

/* CRT private helpers invoked by entry. */
s32  _heap_init(void);                                   /* 0x004c6ee0 */
s32  _ioinit(void);                                      /* 0x004c9d70 */
void _amsg_exit(s32 code);                               /* 0x004c6e90 */
void _setargv(void);                                     /* 0x004c8bc0 */
void _setenvp(void);                                     /* 0x004c9a20 */
s32  _crt_startup_check(void);                           /* 0x004cbed0 */
void _exit(s32 status);                                  /* 0x004c6820 */
void _exit_post(s32 status);                             /* 0x004c6840 */
void _cinit(void);                                       /* 0x004cbc20 */
void _init_main(void);                                   /* 0x004cbb30 */
void _init_premain(void);                                /* 0x004c67f0 */
s32  _isspace_crt(s32 ch);                               /* 0x004cbad0 */
s32  _XcptFilter(s32 ex_code, void *ex_info);            /* 0x004cb880 */

#endif /* MK4_PLATFORM_WIN32_H */
