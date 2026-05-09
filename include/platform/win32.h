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

#endif /* MK4_PLATFORM_WIN32_H */
