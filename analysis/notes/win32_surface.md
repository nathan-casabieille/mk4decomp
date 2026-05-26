# Win32 / IAT surface

Per-subsystem deep dive for MK4's Win32 API surface. Inventories
every IAT entry the binary depends on, identifies which internal
wrapper calls each one, and groups them by use case so a porter can
see at a glance what each Windows API is used for.

The truth source is [config/iat_map.yaml](../../config/iat_map.yaml)
(135 imports across 7 DLLs) and [config/imports.yaml](../../config/imports.yaml)
(same data laid out per-DLL).


## DLL inventory

MK4.EXE imports from exactly **seven** DLLs:

| DLL          | Imports | Purpose                                         |
|--------------|---------|-------------------------------------------------|
| KERNEL32.dll | 74      | Process, threads, files, heap, env, locale     |
| USER32.dll   | 40      | Window, messages, input, cursor                |
| GDI32.dll    | 6       | DIB framebuffer + stock objects                |
| ADVAPI32.dll | 5       | Registry (install path + config)               |
| WINMM.dll    | 11      | Audio (aux/MCI) + timers + joystick            |
| DDRAW.dll    | 2       | DirectDraw create + enumerate                  |
| DSOUND.dll   | 1       | DirectSound create only                        |

Not in the IAT but loaded dynamically via `LoadLibraryA`:

- **`glide2x.dll`** - 3dfx Glide bindings; populates `g_glideFnTable`
  via `GetProcAddress` at `Renderer1_Init_Glide` (see [render.md](render.md)).


## KERNEL32 - process, threads, files, heap

### Process + version

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `GetModuleHandleA`    | CRT init (`_init_application`), `GetExeDirectory` `0x004aca60`  |
| `GetModuleFileNameA`  | `GetExeDirectory` (audio init gate)                              |
| `GetCommandLineA`     | CRT startup `__getmainargs`                                      |
| `GetVersion`          | CRT startup                                                      |
| `GetStartupInfoA`     | CRT startup                                                      |
| `ExitProcess`         | `ExitGame` -> `exit(0)` -> CRT `_doexit`                         |
| `TerminateProcess`    | CRT abort path                                                   |
| `RaiseException`      | CRT SEH translator                                               |
| `UnhandledExceptionFilter` | CRT `_except_handler3` tail                                 |
| `RtlUnwind`           | CRT SEH unwind                                                   |
| `SetUnhandledExceptionFilter` | (not imported - we use the default)                       |

### Threads

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `CreateThread`        | `ECM_Open` `0x004b06f0` - spawns `ECM_PlayThread`                |
| `TerminateThread`     | `ECM_Cleanup` `0x004b0cb0` - kills the play thread on shutdown   |
| `SuspendThread`       | `ECM_PlayThread` `0x004b0a50` - yields after each frame group    |
| `ResumeThread`        | ECM driver - wakes the play thread on demand                     |
| `GetCurrentThread`    | CRT thread-local init                                            |
| `GetCurrentThreadId`  | CRT - locks `_lock` keyed on this                                |
| `GetCurrentProcess`   | CRT heap setup                                                   |
| `GetPriorityClass` / `SetPriorityClass` | (unused at runtime - left from CRT scaffolding)        |
| `GetThreadPriority`   | (same)                                                           |
| `SetThreadPriority`   | (same)                                                           |
| `Sleep`               | `MainLoopStep` - frame throttle (capped at 16 ms)                |

ECM playback is the **only** in-game threading. Everything else is
single-threaded.

### Files (CreateFile-era)

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `CreateFileA`         | CRT `_open` -> game asset loaders                                |
| `CreateFileMappingA`  | `WinMain` - single-instance gate (`"Mortal Kombat 4"` mapping)   |
| `ReadFile`            | CRT `_read`                                                      |
| `WriteFile`           | CRT `_write`                                                     |
| `SetFilePointer`      | CRT `_lseek`                                                     |
| `FlushFileBuffers`    | CRT `_flushall`                                                  |
| `GetFileType`         | CRT FD-table init - distinguishes pipe/char/disk                 |
| `SetEndOfFile`        | CRT `_chsize`                                                    |
| `CloseHandle`         | CRT `_close` + `ExitGame` (mutex release)                        |
| `SetHandleCount`      | CRT FD-table init                                                |
| `SetStdHandle`        | CRT `_freopen`                                                   |
| `GetStdHandle`        | CRT FD-table init                                                |
| `GetFileAttributesA`  | (not used in game code; CRT path validation)                     |
| `GetLogicalDrives`    | `ValidateInstall` `0x004ad270` - bail if no fixed disk           |
| `GetDriveTypeA`       | `ValidateInstall` - require fixed disk (DRIVE_FIXED == 3)        |
| `SetCurrentDirectoryA`| `CheckInstallPath` `0x004acc50` - chdir to install dir           |

`g_hAppMutex` (`0x00f9f7d0`) holds the `CreateFileMappingA` HANDLE.
On exit, `ExitGame` `CloseHandle`s it - that's the
single-instance lock release.

### Heap + memory

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `HeapCreate`          | CRT `_heap_init`                                                 |
| `HeapDestroy`         | CRT `_heap_term`                                                 |
| `HeapAlloc`           | CRT `malloc` -> game asset loader                                |
| `HeapFree`            | CRT `free`                                                       |
| `VirtualAlloc`        | CRT large-alloc path (for the 1 MB+ palette scratch)             |
| `VirtualFree`         | CRT large-free                                                   |

The game-level allocator is CRT `malloc` - no custom pool except for
the **scenegraph node pool** (`g_nodeSlotsArea`, see [scenegraph.md](scenegraph.md))
which is a static array, not heap-allocated.

### Synchronization

| Import                       | Wrapper / call site                                       |
|------------------------------|-----------------------------------------------------------|
| `InitializeCriticalSection`  | CRT init / `_lock` lazy-init                              |
| `DeleteCriticalSection`      | CRT teardown                                              |
| `EnterCriticalSection`       | CRT `_lock`                                               |
| `LeaveCriticalSection`       | CRT `_unlock`                                             |
| `InterlockedIncrement`       | CRT `_atexit_register` (refcount)                         |
| `InterlockedDecrement`       | CRT `_atexit_deregister`                                  |

Critical sections are CRT-only. Game code never directly synchronizes
because the ECM thread communicates via a single status byte
(`g_ecmThreadStatus`) and self-suspends.

### TLS + thread-local data

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `TlsAlloc`            | CRT `_init_per_thread_data` -> `g_crtTlsSlot_00522400`           |
| `TlsGetValue`         | CRT per-thread data lookup                                       |
| `TlsSetValue`         | CRT per-thread data set                                          |

TLS is CRT-only. Game code is single-threaded.

### LoadLibrary + dynamic resolution

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `LoadLibraryA`        | `Renderer1_Init_Glide` - loads `glide2x.dll`                     |
| `FreeLibrary`         | `Renderer1_Init_Glide` teardown                                  |
| `GetProcAddress`      | `Renderer1_Init_Glide` - populates `g_glideFnTable` (`0x007b0000`)|

This is **the only dynamic-load path** in the binary. Everything else
binds statically through the IAT.

### Performance counter + timing

| Import                       | Wrapper / call site                                       |
|------------------------------|-----------------------------------------------------------|
| `QueryPerformanceCounter`    | `QueryMicroTimer` `0x004c4510` - 60 Hz frame tick base    |
| `QueryPerformanceFrequency`  | `Timer_Init` `0x004c4470` - compute ticks-per-usec        |

The frame loop uses QPC as its time source. WinMM's `timeGetTime` is
the fallback for audio scheduling - see WINMM section below.

### Locale / codepages / strings

These are all CRT-internal (`_setlocale`, `_mbslen`, etc.) - game
code does not call them directly:

| Import                | Used by                                                          |
|-----------------------|------------------------------------------------------------------|
| `GetACP`              | CRT `_get_ANSI_codepage`                                         |
| `GetOEMCP`            | CRT `_get_OEM_codepage`                                          |
| `GetCPInfo`           | CRT codepage validation                                          |
| `GetLocaleInfoA/W`    | CRT locale init                                                  |
| `GetStringTypeA/W`    | CRT `_iswctype`                                                  |
| `LCMapStringA/W`      | CRT `_wcsupr`                                                    |
| `WideCharToMultiByte` | CRT `wcstombs`                                                   |
| `MultiByteToWideChar` | CRT `mbstowcs`                                                   |

### Environment + standard streams

| Import                       | Wrapper / call site                                       |
|------------------------------|-----------------------------------------------------------|
| `GetEnvironmentStrings`      | CRT `_environ` init                                       |
| `GetEnvironmentStringsW`     | (same, wide variant)                                      |
| `FreeEnvironmentStringsA/W`  | CRT cleanup                                               |

### Last-error + reporting

| Import                | Used by                                                          |
|-----------------------|------------------------------------------------------------------|
| `GetLastError`        | `WinMain` (post-`CreateFileMappingA` check), CRT failure paths   |
| `SetLastError`        | CRT internal                                                     |


## USER32 - window, messages, input, cursor

### Window lifecycle

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `RegisterClassA`      | `Boot` `0x004c5070` - registers `"Mortal Kombat 4"` class        |
| `CreateWindowExA`     | `Boot` - creates 640x480 main window                             |
| `DefWindowProcA`      | `WndProc` `0x004c49b0` - default fallthrough                     |
| `LoadIconA`           | `Boot` - loads icon resource 0x80                                |
| `LoadCursorA`         | `Boot` - loads cursor IDC_ARROW (0x7f00)                         |
| `ShowWindow`          | `Boot` - twice (initial cmdShow + SW_NORMAL)                     |
| `UpdateWindow`        | `Boot` - first paint                                             |
| `SetWindowTextA`      | `UpdateWindowTitle` `0x004b22e0` - per-frame title bar sync      |
| `SetWindowPos`        | (window-size adjust during mode switches)                        |
| `SetWindowLongA`      | (style update on fullscreen toggle)                              |
| `GetWindowLongA`      | (style read)                                                     |
| `GetWindowPlacement`  | (windowed-mode position save/restore)                            |
| `GetWindowRect`       | (window dimensions probe)                                        |
| `GetClientRect`       | (viewport extents on resize)                                     |
| `GetActiveWindow`     | (focus probe before grab-input)                                  |
| `InvalidateRect`      | (forced repaint after mode switch)                               |

### Message pump

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `PeekMessageA`        | `PumpMessages` `0x004c52a0` - up to 20 messages per frame        |
| `GetMessageA`         | (fallback when PeekMessage queue is empty)                       |
| `TranslateMessage`    | `PumpMessages`                                                   |
| `DispatchMessageA`    | `PumpMessages`                                                   |
| `WaitMessage`         | `PumpMessages` tail - blocks when no work to do                  |
| `PostQuitMessage`     | `WndProc` WM_DESTROY handler                                     |
| `SendNotifyMessageA`  | `ExitGame` `0x004c4870` - sends WM_CLOSE to self                 |

### Paint + drawing context

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `BeginPaint`          | `WndProc` WM_PAINT handler                                       |
| `EndPaint`            | (same)                                                           |
| `GetDC`               | DDraw windowed-mode init                                         |
| `ReleaseDC`           | (same)                                                           |
| `FillRect`            | (mode-switch background clear)                                   |

### Input - keyboard, mouse, joystick

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `GetAsyncKeyState`    | Per-frame key polling (in fight tick / menu nav)                 |
| `MapVirtualKeyA`      | Key-to-scancode conversion in input config                       |
| `GetCursorPos`        | Mouse-aware menu probe                                           |
| `SetCursorPos`        | Cursor pin (during fullscreen)                                   |
| `ShowCursor`          | Hide cursor during fight, show in menus                          |
| `SetCursor`           | Set hourglass during load                                        |
| `MessageBeep`         | (UI feedback - never reached in practice)                        |

### System info

| Import                       | Wrapper / call site                                       |
|------------------------------|-----------------------------------------------------------|
| `GetSystemMetrics`           | DDraw mode-3 init - SM_CXSCREEN/SM_CYSCREEN               |
| `SystemParametersInfoA`      | `Boot` - SPI_GETWORKAREA for centered window placement    |

### Menus + dialog boxes

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `GetMenu`             | (Mode-switch menu hide path - unused in shipping build)         |
| `SetMenu`             | (same)                                                           |
| `MessageBoxA`         | `ShowErrorMessage` `0x004c48c0` - fatal error popup              |


## GDI32 - DIB framebuffer + stock objects

GDI is used **only** by the SW-Windowed renderer (mode 4) for the
final blit. No font / pen / brush usage beyond `GetStockObject`.

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `CreateDIBSection`    | Mode-4 init - creates the back-buffer DIB                        |
| `DeleteObject`        | Mode-4 cleanup - frees the DIB                                   |
| `SetDIBitsToDevice`   | (alternative blit path - unused in shipping build)               |
| `GetStockObject`      | `Boot` - BLACK_BRUSH for window background                       |
| `GetDeviceCaps`       | Mode-4 init - probes color depth + DPI                           |
| `GdiFlush`            | (Force flush after blit; usually elided)                         |

For Glide / D3D / SW-Fullscreen modes (1/2/3/5), GDI is bypassed -
the renderer owns the surface directly.


## ADVAPI32 - registry (install path + config)

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `RegOpenKeyExA`       | `CheckInstallPath` `0x004acc50` - opens `HKLM\Software\GT Interactive\Mortal Kombat 4\1.00` |
| `RegQueryValueExA`    | `CheckInstallPath` - reads `Path` value into `g_installPath[1024]` |
| `RegSetValueExA`      | (writeback path - used by Config screen)                         |
| `RegCreateKeyExA`     | (first-run path - creates the registry key if missing)           |
| `RegCloseKey`         | (both Check and Config paths)                                    |

The registry footprint is **tiny**: one key, one value (`Path`).
That's the only place MK4 looks to find its install directory.
Everything else is in the same dir (or in a sibling dir reachable by
the registered path).

For porting: replacing the registry probe with an env var lookup or
a config file is a 5-line change in `CheckInstallPath` -
[src/audio/install_path.c](../../src/audio/install_path.c).


## WINMM - audio + timers + joystick

See [audio.md](audio.md) for the audio details. Summary:

| Import                | Wrapper / call site                                              |
|-----------------------|------------------------------------------------------------------|
| `mciSendCommandA`     | `Audio_TimerSet` `0x004ac650` - MCI music playback packets       |
| `timeGetTime`         | `Audio_TimerTick`, `MainLoopStep` profiling                      |
| `timeBeginPeriod`     | `Timer_Init` - request 1 ms timer resolution                     |
| `timeEndPeriod`       | (paired with timeBeginPeriod; emitted but rarely reached)        |
| `auxGetNumDevs`       | `AuxAudio_Init` `0x004ac8f0` - enumerate aux output devices      |
| `auxGetDevCapsA`      | `AuxAudio_Init` - per-device caps                                |
| `auxGetVolume`        | `AuxAudio_Init` - snapshot initial volumes                       |
| `auxSetVolume`        | `AuxAudio_SetVolume` `0x004aca10` - broadcast master vol         |
| `joyGetDevCapsA`      | `Joystick_Init` `0x004b5230` - per-joystick caps + calibration   |
| `joyGetPos`           | `Joystick_Init` - probe + per-frame poll                         |
| `joyGetPosEx`         | (extended poll - axis + buttons in one struct)                   |

Joystick is shared between audio.h (input poll wrappers also live
under audio path) and engine geometry (`g_joyButtonState[16]`).


## DDRAW - DirectDraw create + enumerate

| Import                  | Wrapper / call site                                            |
|-------------------------|----------------------------------------------------------------|
| `DirectDrawCreate`      | `DDraw3_Create` `0x004afb30`, `DDraw5_Create` `0x004b0360`     |
| `DirectDrawEnumerateA`  | (DDraw enum callback - used by some renderer-2 init paths)     |

These are the **only two** DDraw entries in the IAT. Everything else
(surfaces, blits, flip, lock/unlock) goes through the COM vtable on
the IDirectDraw / IDirectDrawSurface objects:

- **Mode 3 / 5 surface**: vtable slot 32 (`+0x80`) called per
  `EndScene` with arg=0 - probably `IDirectDrawSurface::Flip(NULL)`.
- **Mode 4 blit**: `Renderer4_PresentFrame` calls the 12-arg
  `g_iat_004d2034` slot - that's `IDirectDrawSurface::Blt(...)`,
  with source rect (0,0,320,240) and dest at the window-client
  origin.

DirectDraw is the foundation of three of the five renderer modes
(SW_FS, SW_Win, SW_FS_Hi) AND the bottom of the D3D mode (D3D2 is
obtained via `QueryInterface(IID_IDirect3D)` on the DDraw object).
So `DDRAW.DLL` is the load-bearing graphics dependency; the rest of
the rendering happens through COM dispatch.


## DSOUND - DirectSound create only

| Import              | Wrapper / call site                                              |
|---------------------|------------------------------------------------------------------|
| `DirectSoundCreate` | `DSound_Init` `0x004c3ef0`                                       |

That's it. **One import**. Like DDraw, everything else goes through
the COM vtable on `IDirectSound` / `IDirectSoundBuffer`:

- `IDirectSound::SetCooperativeLevel` - called inside `DSound_Init`
- `IDirectSound::CreateSoundBuffer` - primary buffer + ECM secondary buffer
- `IDirectSoundBuffer::GetStatus` (vtable slot 9 / offset 0x24) -
  called by `Audio_UpdateChannels` per channel
- `IDirectSoundBuffer::Stop` / `Release` / `Lock` / `Unlock` /
  `Restore` / `Play` - all through `g_audioChannelTable[idx].vtable`


## Dynamically-loaded - Glide via LoadLibraryA

Not in the IAT, but worth a section since the function-pointer
table effectively serves as a second IAT for Glide.

`g_glideFnTable` at `0x007b0000` is a 256-entry function-pointer
array (only ~50 slots populated). Populated by `Renderer1_Init_Glide`:

```c
HMODULE hGlide = LoadLibraryA("glide2x.dll");
if (!hGlide) return 0;     // fall through to mode 2

g_glideFnTable[0]  = GetProcAddress(hGlide, "grSstQueryHardware");
g_glideFnTable[1]  = GetProcAddress(hGlide, "grSstSelect");
g_glideFnTable[2]  = GetProcAddress(hGlide, "grSstWinOpen");
... (~50 more slots)
```

All Glide calls in the renderer dispatch through this table:
`call dword ptr [g_glideFnTable + N]`. So adding a custom shim is a
matter of writing a replacement DLL exporting the same names and
arranging for `LoadLibraryA("glide2x.dll")` to find it -
dgVoodoo2 is exactly that.


## What's CRT-only vs game-logic-used

About **half** of the IAT (~70 entries) is consumed only by the MSVC
5.0 runtime. The game code never calls these directly. They are:

- All locale / codepage / string-type functions
- All TLS functions
- All Heap* and Virtual* functions (game uses `malloc`/`free` wrappers)
- All SEH machinery (RtlUnwind, RaiseException, UnhandledExceptionFilter)
- Most environment / standard-stream functions
- Most file-handle plumbing (the game uses `fopen` / `fread`)
- Critical-section + interlocked-increment

The **other half** (~70 entries) is game-visible. Among those, the
load-bearing ones are roughly:

```
Per-frame:
  QueryPerformanceCounter, timeGetTime, Sleep
  PeekMessage, TranslateMessage, DispatchMessage, WaitMessage
  GetAsyncKeyState, joyGetPos/joyGetPosEx
  IDirectDrawSurface::Blt (via IAT slot 0x4d2034)
  IDirectSoundBuffer::GetStatus (via COM vtable)

Boot:
  RegisterClassA, CreateWindowExA, ShowWindow, UpdateWindow
  RegOpenKeyExA, RegQueryValueExA
  DirectDrawCreate, DirectSoundCreate
  CreateFileMappingA (single-instance gate)
  auxGetNumDevs, auxGetDevCapsA, joyGetDevCapsA
  LoadLibraryA, GetProcAddress (for glide2x.dll)

Per-asset-load:
  CreateFileA, ReadFile, SetFilePointer, CloseHandle (via CRT)
```


## IAT slot addresses

The IAT lives at VA `0x004d2000..0x004d2280` (640 bytes, 160
4-byte slots). The slot addresses are referenced by absolute
address from inline assembly throughout the code, so renames must
be consistent.

Selected high-traffic slots:

| VA           | Import                    | Used by                                |
|--------------|---------------------------|----------------------------------------|
| `0x004d2024` | DirectDrawCreate          | DDraw3_Create, DDraw5_Create           |
| `0x004d2028` | DirectDrawEnumerateA      | Some Renderer2 init helper             |
| `0x004d2034` | (DDraw vtable slot for Blt) | Renderer4_PresentFrame              |
| `0x004d2040` | (some DDraw slot)         | Renderer4_PresentFrame                 |
| `0x004d2090` | SuspendThread             | ECM_PlayThread "yield"                 |
| `0x004d21bc` | SetWindowTextA            | UpdateWindowTitle                      |
| `0x004d2220` | timeBeginPeriod           | Timer_Init                             |
| `0x004d2224` | timeEndPeriod             | (rarely reached)                       |
| `0x004d2240` | timeGetTime               | Audio_TimerTick, MainLoopStep          |
| `0x004d2244` | mciSendCommandA           | Audio_TimerSet, Audio_TimerTeardown    |

Full mapping: see [config/iat_map.yaml](../../config/iat_map.yaml).


## What's safe to change vs not

**Safe**:
- Renaming IAT slots in `iat_map.yaml` and the corresponding extern
  symbols. The byte-match only depends on absolute IAT addresses;
  symbol names are link-time only.
- Adding new imports to a new DLL **at a higher slot address** than
  the existing ones. Adding inside the existing range shifts all
  later slots and breaks every `call dword ptr [imm32]` site.
- Replacing the registry probe with an alternative install-path
  lookup (env var, config file, sibling-binary auto-detect). The
  wrapper `CheckInstallPath` is pure C - just change the function
  body keeping the same return value semantics (1 = found, 0 = not).
- Replacing `glide2x.dll` with a wrapper (e.g. dgVoodoo2). The
  function-pointer table is populated at runtime; bytes-on-disk
  unchanged.

**Unsafe**:
- Reordering imports within a DLL. Each import's IAT slot address
  is baked into every `call dword ptr [imm32]` and `mov reg, [imm32]`
  site by absolute address.
- Removing an import. Even if the wrapper that uses it is gone, the
  IAT slot still occupies its address; removing it shifts all later
  slots.
- Adding a new DLL between existing ones. The DLL order in
  `imports.yaml` is byte-significant - it determines the order of
  the DLL descriptor table in the PE header.
- Changing how `g_hAppMutex` is created. The `CreateFileMappingA`
  call is the single-instance gate; if you switch to `CreateMutexA`,
  the bytes change and the ExitGame `CloseHandle` site needs the
  same handle type. Substituting at runtime is fine; substituting
  in source breaks the byte match.


## What's NOT used (notable absences)

For a 1998 Win32 fighting game, MK4 is **strikingly minimal** in its
API surface. Things you'd expect but that aren't used:

- **No `DirectInput`**: input is `GetAsyncKeyState` + WinMM joystick
  APIs. This is unusual - DirectInput was the recommended path even
  in 1997. Possibly Eurocom's preference for portability across
  console builds.
- **No `DirectMusic`**: music is MCI (CD-DA or .MID via the system
  MIDI sequencer). DirectMusic shipped in 1997 but wasn't widely
  adopted until 1998.
- **No `DirectShow`**: cinematics are MK4's own ECM format, not WMF
  / VfW / DirectShow.
- **No `gdi32::TextOutA` / `DrawTextA`**: all text rendering uses
  the engine's own bitmap-font system (the .geo character font asset
  drawn via the regular draw queue).
- **No `WSAStartup` / `winsock`**: no networking at all. Multiplayer
  is hot-seat (P1/P2 both on the same machine).
- **No `Imagehlp`, no `DbgHelp`, no `PSAPI`**: no symbol lookups,
  no process enumeration.
- **No `Comctl32`**: no common controls.
- **No `Shell32`**: no file dialogs, no shell APIs.
- **No `Ole32` / `OleAut32`**: COM is consumed only through DDraw /
  DSound vtables, never explicitly via `CoCreateInstance` /
  `IUnknown::QueryInterface` (the QueryInterface calls are
  inlined as vtable[0] slot indirect calls).
- **No `Crypt*` / `Bcrypt`**: integrity check is a custom hash
  (`Helper_ComputeExeHash` in `src/audio/integrity.c`), not Win32
  crypto.

This minimal surface is **good news for porting**: replacing each
of these dependencies is a single-DLL substitution.


## Where to start when porting away from Win32

1. **Replace registry with config file**: edit `CheckInstallPath` and
   `RegSetValueExA` call sites. Pure-C bodies, single-file edits.
2. **Replace WinMM joystick with SDL_GameController**: hook
   `Joystick_Init` and the per-frame `joyGetPos` poll. The
   `g_joyButtonState[16]` array is the unified view; everything
   downstream reads from it.
3. **Replace DDraw with SDL_Surface**: replace the 5 `Renderer*_Init`
   functions and their per-mode `EndScene` / `PresentFrame`. The
   `Helper_PostCreateWindow` post-creation hook is the cleanest
   place to inject a shim.
4. **Replace DSound with SDL_audio or OpenAL**: hook `DSound_Init`,
   `Audio_UpdateChannels`, and `Helper_AudioStop` / `Helper_AudioRelease`.
   The 16-channel queue (see [audio.md](audio.md)) is the unified
   playback interface.
5. **Replace MCI music with libsndfile or libvlc**: hook
   `Audio_TimerSet`. The function builds an MCI playback packet; just
   substitute your own play call.

The Win32 surface is **shallow** - 135 imports, only ~70 of them
game-visible. Total porting work is bounded by how cleanly each
wrapper isolates the Win32 dependency, and most wrappers are pure C
([src/platform/](../../src/platform/), [src/audio/](../../src/audio/)).
