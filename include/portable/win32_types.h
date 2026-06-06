/**
 * Portable Win32 ABI type seam for NON_MATCHING twins.
 *
 * The platform-glue functions (window/menu/timer/MCI/locale/critical-section
 * wrappers) decompile to C that names Win32 ABI types (DWORD, HWND, ...).
 * To get those functions out of x86 __asm and into legible portable C, the
 * type names must exist under a non-MSVC toolchain that has no <windows.h>.
 *
 * These are the standard fixed 32-bit Win32 ABI widths (factual interface
 * definitions, not an implementation). Defining them does NOT make the code
 * platform-independent on its own: each Win32 *API call* the body makes is
 * the PAL boundary (Phase 2, src/platform/) - this header just removes the
 * type wall so the boundary is visible C instead of inline asm.
 *
 * NON_MATCHING-only and pulled in via ghidra_types.h; the matching build
 * (real MSVC <windows.h>) never sees these.
 */
#ifndef MK4_PORTABLE_WIN32_TYPES_H
#define MK4_PORTABLE_WIN32_TYPES_H

/* Active when there is no real <windows.h>: a native non-Windows SDL
 * backend (!_WIN32), or the injector's isolation compile-gate which sets
 * MK4_WIN32_SHIM to get these types without windows.h's API prototypes. On
 * a Windows/mingw real build _WIN32 is set and types.h pulls in the
 * authoritative <windows.h>, so this stays inert there (no redefinition). */
#if defined(NON_MATCHING) && (!defined(_WIN32) || defined(MK4_WIN32_SHIM))

/* --- Scalars (Win32 LLP64-irrelevant; this engine is a 32-bit target) --- */
typedef int                BOOL;
typedef unsigned char      BYTE;
typedef char               CHAR;
typedef unsigned short     WORD;
typedef unsigned long      DWORD;
typedef unsigned int       UINT;
typedef long               LONG;
typedef unsigned long      ULONG;
typedef unsigned long      DWORD_PTR;
typedef unsigned long      LCID;
typedef unsigned long      LCTYPE;
typedef unsigned long      MCIERROR;
typedef unsigned int       MCIDEVICEID;
typedef unsigned short     ATOM;

/* --- Opaque handles: all Win32 HANDLEs are just addresses --- */
typedef void              *HANDLE;
typedef void              *HWND;
typedef void              *HMENU;
typedef void              *HDC;
typedef void              *HMODULE;
typedef void              *HINSTANCE;
typedef void              *HGDIOBJ;
typedef void              *HBITMAP;
typedef void              *HICON;
typedef void              *HCURSOR;
typedef void              *HBRUSH;
typedef void              *HKEY;
typedef int (*FARPROC)(void);

/* --- String / buffer pointers --- */
typedef char              *LPSTR;
typedef const char        *LPCSTR;
typedef unsigned short    *LPWSTR;
typedef const unsigned short *LPCWSTR;
typedef unsigned short    *LPWORD;
typedef DWORD             *LPDWORD;
typedef void              *LPVOID;
typedef const void        *LPCVOID;

/* --- Structs: Ghidra reaches their members by raw byte offset, so the
 *     layout below only needs to exist (and be at least large enough); the
 *     real field-exact layouts belong to the PAL when these are implemented.
 *     Tag names match what Ghidra emits (e.g. `_cpinfo`). --- */
typedef struct _POINT { LONG x, y; } POINT, *LPPOINT;
typedef struct _RECT  { LONG left, top, right, bottom; } RECT, *LPRECT;
typedef struct _WINDOWPLACEMENT {
    UINT length; UINT flags; UINT showCmd;
    POINT ptMinPosition, ptMaxPosition; RECT rcNormalPosition;
} WINDOWPLACEMENT;
typedef struct _cpinfo { UINT MaxCharSize; BYTE DefaultChar[2]; BYTE LeadByte[12]; } _cpinfo;
typedef struct _STARTUPINFOA { DWORD cb; char _pad[64]; } _STARTUPINFOA;
typedef struct _EXCEPTION_POINTERS { void *ExceptionRecord; void *ContextRecord; } _EXCEPTION_POINTERS;
typedef struct _OVERLAPPED { DWORD _f[5]; } OVERLAPPED, *LPOVERLAPPED;
typedef struct _CRITICAL_SECTION { void *_f[6]; } CRITICAL_SECTION, *LPCRITICAL_SECTION;

#endif /* NON_MATCHING */

#endif /* MK4_PORTABLE_WIN32_TYPES_H */
