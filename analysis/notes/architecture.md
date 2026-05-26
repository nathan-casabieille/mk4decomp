# MK4.EXE - Architecture (live document)

Living high-level map of the binary, updated as reverse engineering progresses.
Every claim should be backed by concrete evidence noted in the prose.
Suspicions that haven't been verified are tagged **(suspected)**.

## Per-subsystem deep dives

Once the high-level map was complete, each major subsystem got its own
dedicated doc. This file remains the top-level overview; the deep dives
below carry the in-engine plumbing details for porters and contributors:

- [audio.md](audio.md) - DSound/MCI/AuxOut paths, channel queue, ESF/ECM streaming
- [scenegraph.md](scenegraph.md) - 63-slot node pool, transform stack, dispatch table
- [render.md](render.md) - 5 renderer modes, draw queue, counting sort, vertex pipeline
- [combat_fsm.md](combat_fsm.md) - menu FSM, fight tick, event queue, per-player state
- [install.md](install.md) - registry probe, FSYS archive, ESF/ECM/GEO loaders
- [win32_surface.md](win32_surface.md) - complete IAT inventory by DLL and use case

Most of the "(suspected)" / "(TBD)" tags below this point have since been
resolved; the sub-docs are the up-to-date source of truth for their
subsystems. This file is kept as the historical narrative of how the RE
unfolded.

---

## Binary at a glance

| | |
|---|---|
| Type | PE32 (Win32, Intel 80386) |
| Size | 1 187 840 bytes (1.13 MiB) |
| `.text` | ~830 KiB code |
| `.data` | ~314 KiB writable globals |
| Date | 1998-07-09 |
| Compiler | **MSVC 5.0 SP3** (CONFIRMED, CL 11.00.7022 Pro Optimizing - see "Compiler identification" section) |
| Original source path | `C:\source\mk4\win\` (leaked debug string in `AppInit_Misc1` `0x004b6180`) |

**Imports (7 DLLs)**
- `KERNEL32`, `USER32`, `GDI32`, `ADVAPI32` - Win32 base
- `WINMM` - multimedia + CD audio (CD-DA + auxGetVolume + joy*)
- `DDRAW` - DirectDraw (2D + Direct3D 5/6 era)
- `DSOUND` - DirectSound

Notably absent: `DINPUT.DLL`. Input via:
- Keyboard: `WM_KEYDOWN`/`WM_KEYUP` in WndProc, decoded via `MapVirtualKeyA`
- Joystick: WINMM legacy `joyGetDevCapsA` / `joyGetPos`

`glide2x.dll` is loaded dynamically via `LoadLibraryA` + `GetProcAddress`
into a function-pointer table at `g_glideFnTable` (`0x007b0000`). It is
**not in the IAT** - if `glide2x.dll` is absent the game silently falls
through to the next renderer mode. See [render.md](render.md) and
[win32_surface.md](win32_surface.md).

**In-game render-mode hotkeys** (from strings):
| Key | Mode |
|---|---|
| F6 | Direct3D card (hardware) |
| F7 | Software fullscreen |
| F8 | Software windowed |
| F9 | Software fullscreen hi-res |

---

## Top-level call graph

```
entry  (CRT MSVC)                                     0x004c6cb0
└── WinMain(hInst, NULL, lpCmdLine, nCmdShow)         0x004c53c0
    ├── CreateFileMappingA("Mortal Kombat 4")         single-instance lock
    │     └── on GetLastError() != 0 → ExitGame
    ├── Boot                                          0x004c5070
    │   ├── RegisterClassA → wndclass.lpfnWndProc = WndProc
    │   ├── CreateWindowExA  → g_hMainWindow
    │   └── Show/UpdateWindow
    ├── AppInit(g_hMainWindow)                        0x004b2500
    │   └── [27 init helpers - see Subsystem map]
    └── do { MainLoopStep × 2 ; PumpMessages } while(true)
```

---

## Subsystem map (from AppInit, in call order)

`AppInit` is the master initializer, called from WinMain after window creation.
It calls 27 helpers - the order itself reveals the boot sequence.

| # | Function | VA | Subsystem | Evidence |
|---|---|---|---|---|
| 1 | `Timer_Init` | `0x004c4470` | High-precision timer | imports `QueryPerformanceCounter`, `QueryPerformanceFrequency`, `timeBeginPeriod` |
| 2 | `Joystick_Init` | `0x004b5230` | Joystick input | imports `joyGetDevCapsA`, `joyGetPos` |
| 3 | `ValidateInstall` | `0x004ad270` | Install / registry check | see [install.md](install.md) |
| 4 | `AppInit_PostJoy` | `0x004b5a10` | Joystick post-init | small wrapper, no further signal |
| 5 | **`FSYS_Init`** (== `AppInit_PreInstall`) | `0x004b1cf0` | **Asset archive (filesys.dat)** | strings `'filesys.dat'`, `'FSYS_Init(1..3)'` |
| 6 | **`Gfx_Init`** | `0x004b4370` | **Graphics base** | string `'Gfx_Init()'`, see [render.md](render.md) |
| 7 | `AuxAudio_Init` | `0x004ac8f0` | CD-DA mixer / aux line | imports `auxGetDevCapsA`, `auxGetNumDevs`, `auxGetVolume`, see [audio.md](audio.md) |
| 8 | `AuxAudio_SetMasterVol` | `0x004ac9c0` | Sets master volume from `g_audioMasterVol` | import `auxSetVolume` |
| 9 | **`DSound_Init`** | `0x004c3ef0` | **DirectSound (SFX)** | import `DirectSoundCreate` |
| 10 | `AppInit_AudioPostInit` (== `Helper_TitleSetMaxVolume`) | `0x004c3eb0` | DSound post-init max-vol gate | called after DSound_Init with `g_audioPostFlag` |
| 11 | `AppInit_PostDSound` | `0x004b21b0` | 1-byte clear of `g_byte_007af508` | 8-byte stub |
| 12 | `AppInit_Misc1` | `0x004b6180` | Menu / TGA loader pre-init | string `'c:\source\mk4\win\menu.tga'`, imports `MapVirtualKeyA` |
| 13 | `AppInit_Misc2` | `0x004b5a80` | (TBD) | small |
| 14 | `AppInit_Misc3` | `0x004b2ac0` | (TBD) | 17-byte stub |
| 15 | **`SetRendererMode(N)`** + **`TryInitRenderer()`** | `0x004b40a0` / `0x004b3ed0` | **Renderer fallback chain** | iterates modes 1, 2, 3, 5 (mode 4 = SW-Win fallback always available), see [render.md](render.md) |
| 16 | `UpdateWindowTitle` | `0x004b22e0` | Window title | import `SetWindowTextA`; strings "Mortal Kombat 4", "...Demo Mode", "...Waiting" |
| 17 | `AppInit_Misc4` | `0x004bd960` | (TBD) | small |
| 18 | `AppInit_Misc5` | `0x004054c0` | (TBD) | tiny (14 bytes) |
| 19 | `AppInit_Misc6` | `0x00418f10` | (TBD) | small with 7 callees |
| 20 | `AppInit_Misc7` | `0x00464830` | (TBD) | tiny (18 bytes) |
| 21 | `AppInit_Misc8` | `0x004c51f0` | (TBD) | moderate (171 bytes) |
| 22 | `GameStateMachine(7)` | `0x004b6340` | Initial state = TOURNAMENT (cmd 7 maps to GAMESTATE 7) | called only if `g_demoModeFlag == 0`, see [combat_fsm.md](combat_fsm.md) |
| 23 | `GetExeDirectory` | `0x004aca60` | Path resolution + EXE integrity hash | imports `GetModuleFileNameA`, see [install.md](install.md) |
| 24 | `Crt_srand(timeGetTime())` | `0x004c6500` | RNG seed | confirmed (CRT signature) |
| 25 | `Crt_rand` | `0x004c6510` | RNG read | result OR'd with `0x1881` flag mask |

---

## Install validation chain (FULLY MAPPED)

The "Mortal Kombat 4 is not installed. Run SETUP from the CD." popup comes from
this chain. Confirmed via static decomp + WINEDEBUG=+reg trace.

| Function | VA | Role |
|---|---|---|
| `ValidateInstall` | `0x004ad270` | Top-level orchestrator. Caches result in `g_installValidated`. |
| `CheckInstallPath` | `0x004acc50` | Reads registry `Path` value, then `SetCurrentDirectoryA`. False on any failure → triggers popup. |
| `ShowErrorMessage` | `0x004c48c0` | Generic fatal-error reporter. `MessageBoxA` with title "Mortal Kombat 4 Error". Drains up to 1000 messages first. |
| `DeobfuscateConfig` | `0x004ad250` | XOR-decrypts the 588-byte `Config` blob in place: `byte[i] ^= (i * 123) & 0xff`. |
| `ComputeConfigHash` | `0x004ad210` | Hash over `Config[4..583]`. Seed `0x43464729 = "FCG)"`. `hash += byte[i] << (i %% 23)`. |
| `ResetConfigToDefaults` | `0x004acf90` | Zero `g_configBuffer`, restore defaults from constant table at `0x004f46a0`. |

**Registry layout (32-bit visible, under `Wow6432Node` on wine64):**
```
HKLM\Software\GT Interactive\Mortal Kombat 4\1.00\
    Path     REG_SZ     install directory (chdir target)
    Config   REG_BINARY [0..3]  = stored hash (= ComputeConfigHash() or 0xFFFFFFFF)
                       [4..583] = XOR-obfuscated settings payload
                       [584..587] tail
```

**Config validation is non-blocking**: even with a bad hash, `ValidateInstall`
returns true after calling `ResetConfigToDefaults`.

---

## Renderer modes (MAPPED)

The game has 5 renderer modes selectable via F5-F9 (confirmed in WndProc's
WM_KEYDOWN switch) and via fallback chain in AppInit (modes 1, 2, 3, 5).

| Mode | Key | Type | Init function | Availability flag |
|---|---|---|---|---|
| **1** | F5 | **3dfx Glide** (CONFIRMED) | `Renderer1_Init_Glide` (`0x004b49a0`) | `g_pumpFlagD8` (`0x00f9f7d8`) |
| **2** | F6 | **Direct3D 2** (CONFIRMED - via DDraw QueryInterface) | `Renderer2_Init_D3D` (`0x004ad6a0`) | `g_pumpFlagDC` (`0x00f9f7dc`) |
| **3** | F7 | **DirectDraw fullscreen 320x240** (CONFIRMED) | `Renderer3_Init_SW_FS` (`0x004af8c0`) | `g_pumpFlagE0` (`0x00f9f7e0`) |
| **4** | F8 | **DirectDraw windowed 640x480** (CONFIRMED) | _none - always-available fallback_ | _always_ |
| **5** | F9 | **DirectDraw fullscreen hi-res** (CONFIRMED) | `Renderer5_Init_SW_FS_Hi` (`0x004b00f0`) | `g_pumpFlagE4` (`0x00f9f7e4`) |

Full per-mode init details, including the D3D vtable surface and the
counting-sort draw queue, are in [render.md](render.md).

Glide confirmed via:
- ~20 calls through a function-pointer dispatch table at `DAT_007b0008..0070`
  (canonical `LoadLibraryA("glide2x.dll")` + `GetProcAddress` pattern)
- Hard-coded resolution `0x280 × 0x1e0` = 640 × 480 (canonical Glide res)
- `glide2x.dll` literal in `.data`

All five mode mappings have been verified by decompilation and runtime
behavior. Mode 4 is special: no init function, used unconditionally as
the fallback when modes 1/2/3/5 fail or are unset.

`SetRendererMode(N)` (`0x004b40a0`) stores the requested mode in
`g_clampedRendererMode`. `TryInitRenderer()` (`0x004b3ed0`) reads that
global and dispatches to the relevant init function via a switch.

---

## WndProc (MAPPED)

The window procedure at `0x004c49b0` handles these messages:

| `uMsg` | Symbol | Behavior |
|---|---|---|
| `0x02` | `WM_DESTROY` | `PostQuitMessage(0)` |
| `0x05` | `WM_SIZE` | track minimised state, force renderer mode 4 if window collapsed |
| `0x0F` | `WM_PAINT` | `BeginPaint`; if mode 4, call `PresentFrame` (`0x004b3e90`); else fill black; `EndPaint` |
| `0x10` | `WM_CLOSE` | call `AppShutdown` (`0x004b2690`) cleanup hook then default |
| `0x14` | `WM_ERASEBKGND` | return 1 (no auto-erase, game owns repaint) |
| `0x1C` | `WM_ACTIVATEAPP` | focus tracking; `SetRendererMode(4)` if losing focus |
| `0x20` | `WM_SETCURSOR` | `SetCursor(NULL)` in fullscreen modes |
| `0x7E` | `WM_DISPLAYCHANGE` | dismiss popup; reset `DAT_004ffd78` |
| `0xA1, 0xA4, 0xA7, 0x116` | NC mouse / menu | `SetRendererMode(4)`, update title |
| `0x100` | `WM_KEYDOWN` | game key bindings (see below) |
| `0x101` | `WM_KEYUP` | PrintScreen → screenshot to `scrngrab.bmp` |
| `0x102` | `WM_CHAR` | (default) |
| `0x104, 0x105` | `WM_SYSKEYDOWN/UP` | call `Helper_TitleAudioReset` (`0x004b5840`) then default |
| `0x112` | `WM_SYSCOMMAND` | block SC_MONITORPOWER (0xF170); on SC_MAXIMIZE, retry renderer chain 1→2→3→5 |

**Key bindings (from `WM_KEYDOWN`):**

| Vkey | Key | Action |
|---|---|---|
| `0x1B` | ESC | exit submenu / mode-switch |
| `0x70-0x71` | F1, F2 | `GameStateMachine(1 or 2)` - sub-dispatches main-menu commands |
| `0x73` | F4 | set `DAT_0054381c` flag (debug?) |
| `0x74-0x78` | F5-F9 | `SetRendererMode(1..5)` (renderer hot-swap) |

The popup that says "Mortal Kombat 4 Error" (from `ShowErrorMessage`) is
drained here through `PeekMessageA` flush (up to 1000 messages) before
being shown - so it doesn't pile up behind a stuck input queue.

---

## FILESYS.DAT format (deduced from FSYS_Init)

The asset archive `filesys.dat` (24,099,408 bytes) is loaded by
`FSYS_Init` (`0x004b1cf0`). Layout:

```
0x0000   ┌──────────────────────────────────┐
         │ Header table (12 KB / 0x3000)    │
         │   array of entries:              │
         │     struct fsys_entry {          │
         │       DWORD hash_or_id;          │  ← sort key (entries sorted ascending)
         │       DWORD offset;              │  ← byte offset of payload
         │       DWORD size;                │  ← payload size
         │     };                            │
         │   max 1024 entries, terminated   │
         │   by an entry with first DWORD=0 │
0x3000   ├──────────────────────────────────┤
         │ Payload data                     │
         │   addressed by `offset` from     │
         │   header entries                 │
         └──────────────────────────────────┘
```

Entry 0 from the actual file:
```
hash=0x2da2df95   offset=0x00003000   size=0x00000b94
```
0x3000 = end-of-header - entry 0 starts immediately after, confirming the
layout. Subsequent entries are sorted by hash but their payload offsets are
NOT sequential - the archive is essentially a hash-indexed flat directory.

A secondary 1024-DWORD buffer at `DAT_007ae0e0` is initialized to `-1` -
likely a per-slot cache of FILE handles or unpacked-data pointers.

**Init failure messages** (debug strings in the binary):
- `FSYS_Init(1)` - fopen failed
- `FSYS_Init(2)` - fread failed
- `FSYS_Init(3)` - sort-order violation in header

**Asset open API** - `FSYS_fopen` (`0x004b1e00`) is the public API. Logic:

```c
int FSYS_fopen(char *filename) {
    char *normalized = FSYS_NormalizePath(filename);  // uppercase, validate X:\..
    uint hash = FSYS_HashName(normalized);             // see formula below
    int idx = binary_search(entries, hash);            // by hash
    if (entries[idx].hash != hash) {
        char buf[1024];
        sprintf(buf, "FSYS_fopen(\"%s\")", filename);
        ShowErrorMessage(buf);   // fatal
    }
    cache[idx] = 0;     // mark slot in-use
    return idx + 1;     // 1-based handle
}
```

### Path normalization (FSYS_NormalizePath @ 0x004b1ec0)

Just uppercases ASCII a-z to A-Z. **Crucially: NO prefix stripping.** Asserts
that the result is a fully-qualified Windows path (`X:\...`) - emits
`"Partial filename"` fatal error otherwise. Therefore asset names in the hash
table are the **full dev-machine paths**, e.g. `C:\SOURCE\MK4\WIN\MENU.TGA`.

### Hash function (FSYS_HashName @ 0x004b1f50, RECOVERED)

```python
def fsys_hash(path):
    upper = path.upper()
    h, shift = 0, 0
    for ch in upper:
        b = ord(ch)
        if b >= 0x80: b -= 0x100   # signed-char extension
        h = (h + (b << shift)) & 0xFFFFFFFF
        shift = (shift + 8) if shift < 24 else 0
    return (h + len(upper)) & 0xFFFFFFFF
```

Each char gets summed at one of 4 byte positions (0, 8, 16, 24), cycling
every 4 chars. Final result = sum + length. Implementation in
[tools/fsys_hash.py](../../tools/fsys_hash.py).

### Asset name discovery (RECOVERED, 99.9%)

Found 4 path patterns leaked in `MK4.EXE` strings:
- `c:\source\mk4\win\menu.tga` (single)
- `c:\source\mk4\win\anim\` (directory prefix)
- `c:\source\mk4\win\geogfx\%s` (printf format)
- `c:\source\mk4\win\sound\pcmk%04ld.esf` (numbered sound files)

Plus **128 explicit filenames** were extracted from `MK4.EXE` strings via:
```sh
strings -n 4 game/MK4.EXE | grep -iE "\.(tga|geo|...)$" | grep -v -i "\.exe\|\.dll" | sort -u
```

Brute-forcing all combinations against the 799-entry table yielded:
- **674 sound files**: `pcmk0021.esf` through `pcmk0694.esf` (no gaps in range)
- **~120 .geo files** in `\geogfx\` with character/scene naming patterns
  (e.g., `sc_geo.geo` = Scorpion, `sz_geo.geo` = SubZero, `lk_geo.geo` =
  Liu Kang, with `_a_/_g_/_m_/_e_geo` variants for animations/geometry/
  meshes/endings; backgrounds: `tomb_geo`, `well_geo`, `wind_geo`,
  `forest_g`, `ice_pit_`, `lair_geo`, `theatre_`, `shaolin_`, ...)
- `menu.tga` (256×256 16-bit TGA, 131 KB)

**Coverage: 797 / 799 = 99.7%**. Two entries (0, 1) remain unidentified -
hashes `0x2da2df95` (small, 2964 B) and `0x2da3df95` (1.1 MB). The
1-char-off pattern in their hashes suggests they're a numbered pair or
a base/data pair (e.g. `*idx.bin` + `*data.bin`). Not in any of the
known directories.

See [tools/fsys_hash.py](../../tools/fsys_hash.py) (hash + table reader)
and [tools/fsys_bruteforce.py](../../tools/fsys_bruteforce.py) (name
discovery).

### Character / scene naming convention

Decoded from the recovered `.geo` names:

| Prefix | Character | Suffix | Variant |
|---|---|---|---|
| `sc_*` | Scorpion | `_geo` | base mesh |
| `sz_*` | Sub-Zero | `_a_geo` | animations? |
| `lk_*` | Liu Kang | `_g_geo` | additional geometry |
| `jc_*` | Johnny Cage | `_m_geo` | (unknown - moves?) |
| `jx_*` | Jax | `_e_geo` | endings? |
| `ja_*` | Jarek | `_fat_g` | fatality |
| `me_*` | Mileena? | | |
| `ki_*` | Kitana? | | |
| `fj_*` | Fujin | | |
| `ta_*` | Tanya | | |
| `wg_*` | (unknown - Goro? "Winged"?) | | |
| `sh_*` | Shinnok? | | |
| `re_*` | Reptile? | | |
| `ra_*` | Raiden? | | |
| `qc_*` | Quan Chi? | | |
| `rv_*` | Reiko? | | |
| `ns_*` | Noob Saibot? | | |
| `wr_*` | (?) | | |

`vs_<XX>_ge.geo` files exist for each character (versus-screen art).

---

## Window creation (MAPPED)

`CreateMainWindow` registers a class named `"Mortal Kombat 4"` with:
- `style = 0x102b` (CS_VREDRAW|HREDRAW|DBLCLKS|OWNDC|BYTEALIGNCLIENT)
- `lpfnWndProc = WndProc` (`0x004c49b0`) - yet to be decompiled
- icon resource id 128, `IDC_ARROW`, `BLACK_BRUSH`

Window dimensions: `(0x140 + extraW) × (0xf0 + extraH)` = base 320×240.
Strongly suggests the game runs at a multiple of 320×240 (likely 640×480).

---

## Render pipeline (MAPPED - queue-based architecture)

The render pipeline turns out NOT to be a direct mesh-walking renderer.
It's a **queue-based architecture** with counting sort:

```
   game logic / scene update                  GameLogicStep
   ─────────────────────────                  └─ scenegraph walk -> DrawMeshBlock per leaf
                                                  └─ SubmitDrawEntry(28-byte entry) -> g_drawQueue
        │
        ▼
   BeginFrame  (0x004b4200)
   └─ mode-specific begin (Glide/D3D/SW)
   └─ SetViewport(x, y, w, h)
        │
        ▼
   DrawScene  (0x004b42e0)          ← profiled with timeGetTime
   └─ FlushDrawQueue  (0x004bf460)          ← THE big one (~3.8 KB of code)
   │  ├─ zero g_drawQueueBuckets (1024 dwords)
   │  ├─ pass 1: histogram by entry sort key
   │  ├─ cumulative-sum the buckets (= counting sort)
   │  └─ pass 2: dispatch each entry's triangle to the per-mode submit
   │             (Glide: GlideTriColorFlush 0x004b46f0,
   │              D3D:   GlideTriBatchEmit 0x004adca0)
   │
   └─ Renderer<N>_EndScene_<mode>           ← per-mode finalize
                                              (D3D: vtable[11] = EndScene,
                                               SW:  vtable[32] = Flip)
        │
        ▼
   PresentFrame  (0x004b3e90)
   └─ mode-specific present (Glide: 0x004b46d0, D3D: 0x004ae950, ...)
```

Full per-mode pipeline details in [render.md](render.md).

### Draw queue layout

| Symbol | VA | Description |
|---|---|---|
| `g_drawQueueSize` | `0x00f85b40` | Number of entries currently queued |
| `g_drawQueue` | `0x00f71322` | Base of the queue. **28 bytes per entry** |
| `g_drawQueueBuckets` | `0x00f6d050` | 1024-dword histogram for counting sort |

Each queue entry is 28 bytes (14 `ushort`). The **first ushort is the sort
key** (range 0..1023, used as a bucket index - probably a quantized z-depth
or material id). The remaining 26 bytes contain triangle data: short
coordinates + a flag byte at index 13 (`psVar14[0xd]`). Full layout TBD.

The per-mode submit functions (`GlideTriColorFlush` `0x004b46f0` for
Glide, `GlideTriBatchEmit` `0x004adca0` for D3D) take ~16 args including
7+ floats (vertex positions and UVs). These are the actual per-triangle
GPU/SW dispatches.

### How the .geo mesh data reaches the queue (DECODED)

The "submitter" bridging static `.geo` data to `g_drawQueue` is
**`DrawMeshBlock`** (`0x004bb250`), called from `RenderSceneNode`
(`0x004ba720`) for each leaf node in the scenegraph traversal.

```
TickAllEntities -> Helper_FightSceneCallback (0x004ba1c0)
                    -> camera transform + frustum cull
                    -> RenderSceneNode (recursive descent on +0x3c..+0x44 children)
                        -> g_nodeDispatchTable[idx] for transform handlers
                        -> DrawMeshBlock for leaf meshes
                            -> ProjectTwoVertices + ProjectVertex + TransformVertex
                            -> SubmitDrawEntry per triangle
                                -> g_drawQueue[g_drawQueueSize++] = entry
```

Full walkthrough in [scenegraph.md](scenegraph.md) and [render.md](render.md).

---

## Main loop (MAPPED)

```
do {
    MainLoopStep();    // call site 0x004c5446
    MainLoopStep();    // call site 0x004c544b
    PumpMessages();    // call site 0x004c5450
} while (true);        // jmp back, exits via SEH/ExitGame
```

`MainLoopStep` (`0x004b2750`) is the frame-rate-limited tick. Each invocation:
- Runs **4 helpers** unconditionally:
  - **`BeginFrame(1)`** (`0x004b4200`) - per-mode renderer begin + SetViewport
  - **`GameLogicStep`** (`0x004b26d0`) - fixed-step game logic:
    - only callee re-run by the catch-up loop
    - NOT called by Gfx_Init (the other 3 are)
  - **`DrawScene`** (`0x004b42e0`) - FlushDrawQueue + per-mode EndScene
  - **`PresentFrame`** (`0x004b3e90`) - per-mode present/flip
- Catch-up loop (max 3 extra ticks): re-runs only `GameLogicStep` if delta > 20 ms,
  advancing virtual time by `0x411b µs = 16 667 µs = 1/60 s` per iteration
- Throttle: `Sleep(min(needed_ms, 16))`

**The double-call**: WinMain calls `MainLoopStep` twice per outer iteration
(asm-verified at `0x004c5446` and `0x004c544b`). Working theory: call#1 does
the work; call#2 (delta ≈ 0) skips catch-up but still runs the 4 helpers AND
sleeps until the next 60 Hz tick. The 4 helpers running twice per real frame
is a real side-effect - possibly intentional, possibly vestigial.

`QueryMicroTimer` (`0x004c4510`) is the time base: `QueryPerformanceCounter`
+ `__ftol`, with `timeGetTime` fallback.

---

## Globals identified

| VA | Name | Meaning |
|---|---|---|
| `0x00543928` | `g_configBuffer` | 588-byte Config blob (hash + XOR'd payload) |
| `0x0054392c` | `g_configValidationCounter` | Incremented on each successful Config validation |
| `0x00543b78` | `g_installPath` | 1024-byte buffer for the install dir from registry |
| `0x00543f78` | `g_installValidated` | 0 = not yet, 1 = passed |
| `0x00f9f7c0` | `g_hMainWindow` | Main window HWND |
| `0x00f9f7c4` | `g_hInstance` | Application HINSTANCE |

---

## .geo format (TEXTURES MAPPED, mesh data still TBD)

`.geo` files are the engine's geometry+texture container. The texture
portion has been fully reverse-engineered and decoded.

### File header (12 bytes)

```c
struct geo_header {
    char     magic[4];           // "0.1v"
    uint32_t tex_table_offset;   // offset to texture chunk header
    uint32_t file_size;
};
```

### Texture chunk

At `tex_table_offset` in the file:

```c
struct geo_tex_chunk {
    uint8_t  sub_header[4];      // unknown - pair of WORDs that look related
                                 // per file (e.g. midway: 38b1 38b1, sz: 9e01 a201).
                                 // Possibly chunk_id + crc16, possibly two version
                                 // tags. Not used by Tex_DecodeRLE16.
    uint32_t count;              // number of texture entries
    geo_tex_entry entries[count];
};

struct geo_tex_entry {
    uint16_t width;              // always 256 in observed files
    uint16_t height;             // always 256 in observed files
    uint32_t data_size;          // size of the RLE stream below
    uint8_t  rle[data_size];     // see RLE format
};
```

### Mesh portion (MOSTLY MAPPED - vertex format and walker found)

The bytes from `0x0C` to `tex_table_offset` are mesh data. The first part
of the mesh region is a **block-header table**: an array of 16-byte
records, one per submesh / body-part.

```c
struct geo_mesh_block {
    uint16_t type;      // observed: always 1 in characters; varies in environments
    uint16_t count;     // per-block element count (6..112 in characters)
    uint32_t ofs_a;     // file offset of one sub-table
    uint32_t ofs_b;     // file offset of another sub-table (always 12-20 less than ofs_a)
    uint32_t ofs_c;     // file offset of the end of this block's data
};
```

Recovered counts:
- `sc_geo.geo` (Scorpion): 37 blocks → 37 submeshes (head, torso, arms, legs, weapon...)
- `sz_geo.geo` (Sub-Zero): 41 blocks
- `lk_geo.geo` (Liu Kang): observed similar pattern

Patterns observed in blocks:
- `count` × ~12 bytes ≈ `ofs_c - ofs_a` → suggests `ofs_a..ofs_c` is an array of fixed-size records (faces? indices? skin weights?) of `count` entries × 12-bytes-each.
- `ofs_b..ofs_a` is a 12/16/20 byte sub-header (possibly bounding box + material ref).
- The block-header table spans from `0x0C` to the smallest `ofs_b` of any block (typically ~`0x230..0x290`).

### Per-block data layout (FOUND via DrawMeshBlock @ 0x004bb250)

The block-header offsets are **relative to the field that holds them**:
- `block + 4 + ofs_a` → start of the **VERTEX stream**
- `block + 8 + ofs_b` → start of the **HEADER stream**
- (ofs_c not yet observed in DrawMeshBlock; possibly an end pointer)

#### VERTEX stream (at block+4+ofs_a)

A flat array of **3D positions in fixed-point 16-bit signed integers**
(NOT floats). Triangles are loaded by the walker as triples of
`(short x, short y, short z)`. Two base vertices are read first
(consuming 24 bytes / 12 ushorts), then more vertices in an inner
per-triangle loop (each 6 bytes / 3 shorts).

The use of int16 fixed-point instead of float is typical of late-90s
console-derived 3D engines (and matches MK4's PSX/N64 release timeline).

#### HEADER stream (at block+8+ofs_b)

A flat array of `(uint16 flag, int16 count)` pairs - one pair per
"strip" of triangles in the block. Iteration sentinel: when
`(int16)count < 0`, stop. Each pair drives:
- `flag` - bit 0 negotiates with `param_2` (probably culling/flip mode)
- `count` - number of additional vertices in this strip

#### Render flow (per block) - TRIANGLE STRIP, refined

```c
void DrawMeshBlock(block_t *block, int mode_param, ...) {
    ushort *header = block + 8 + block->ofs_b;
    short  *verts  = block + 4 + block->ofs_a;
    
    while (true) {
        uint flag  = header[0];                  // bit 0 = winding flip
        int  count = (int16)header[1];           // # of triangles in this strip
        header += 2;
        if (count < 0) break;                    // sentinel ends the block
        
        // Load 2 base vertices (24 bytes consumed)
        load_pos(v0, verts[0..2]);     TransformVertex(verts[3..5]);  // pos+normal
        load_pos(v1, verts[6..8]);     TransformVertex(verts[9..11]);
        ProjectTwoVertices();          // -> g_triRingScreenXY[0,1], g_triRingZ[0,1]
        verts += 12;                   // 12 ushorts = 24 bytes
        
        // Inner loop: 1 new vertex per triangle, forming a strip
        for (int i = 0; i <= count; i++) {
            AdvanceTriStripRing(verts[0..2]);    // shift ring: v0←v1, v1←v2
            TransformVertex(verts[3..5]);
            ProjectVertex();                     // -> g_triRingScreenXY[2], g_triRingZ[2]
            
            // 2D cross-product winding test for back-face cull:
            int cross = (g_triRingScreenXY[2].y - g_triRingScreenXY[0].y) *
                        (g_triRingScreenXY[1].x - g_triRingScreenXY[0].x) -
                        (g_triRingScreenXY[1].y - g_triRingScreenXY[0].y) *
                        (g_triRingScreenXY[2].x - g_triRingScreenXY[0].x);
            int facing_camera = (cross < 1) ? 0 : 1;
            
            // Z-clip + back-face cull combined:
            if (facing_camera != flag_winding && all_z_positive) {
                fill_draw_entry(puVar8, /* ... */);
                SubmitDrawEntry(puVar8);
            }
            
            verts += 6;     // 6 ushorts = 12 bytes per delta vertex
        }
    }
}
```

#### Vertex stream layout (12 bytes per vertex)

```c
struct geo_vertex {
    int16 pos_x, pos_y, pos_z;        // bytes 0-5: model-space position
    int16 nrm_x, nrm_y, nrm_z;        // bytes 6-11: 3-vector - likely normal
                                       // (transformed by TransformVertex,
                                       // which is rotation - normals rotate
                                       // but UVs don't, hence "normal" guess)
};
```

#### Header stream layout (4 bytes per strip, terminated by count<0)

```c
struct geo_strip_hdr {
    uint16 flag;       // bit 0: winding direction (XOR'd with mode_param)
                        // bit 8: passed to draw entry's flag-byte bit 7
    int16  count;      // number of triangles in this strip
                        // (int16, count < 0 means END OF BLOCK)
};
```

The data is **triangle-strip-encoded**, not arbitrary triangle list - much
more compact (each triangle after the first 2 base vertices only adds 1
new vertex of 12 bytes instead of 36).

Helper tools: [tools/geo_dump_blocks.py](../../tools/geo_dump_blocks.py)
prints the block-header table.

The mesh references textures via slot indices (0..14, since
`Tex_DecodeRLE16` clamps `slot` to 14). Each character has 1 texture
atlas → all submesh material refs point to slot 0.

### Draw queue entry layout

Each entry in `g_drawQueue` is **28 bytes** (verified via
`SubmitDrawEntry` decomp):

```c
struct draw_entry {                  // 28 bytes
    int16  x0, y0;                   // [0..3]    vertex 0 screen XY
    int16  x1, y1;                   // [4..7]    vertex 1 screen XY (skipped if flag&0x20)
    int16  x2, y2;                   // [8..11]   vertex 2 screen XY
    int16  unk[3];                   // [12..17]  more coords / UVs / colors
    uint16 sort_key;                 // [18..19]  pre-LUT key
    int16  unk2[3];                  // [20..25]
    uint16 flags;                    // [26..27]  bit 0x20 = "skip vertex 1" (tri vs quad)
};
```

`SubmitDrawEntry` performs frustum culling (X in [-100, 740], Y in
[-100, 580] for an extended 640×480 canvas), copies the 28 bytes,
then remaps the sort key through a 65 KB lookup table at
`DAT_00b0d008`.

### Outer walker - RenderSceneNode (ASM-VERIFIED)

`DrawMeshBlock`'s only caller is `RenderSceneNode` (`0x004ba720`,
1899 bytes, recursive). After ASM-level review the architecture is
fully clear.

**The dispatch table is at `0x004f7888`** (a 16-entry array of
function pointers, all in `.text` at `0x004bdb50..0x004be130`).
My earlier interpretation that pointed at `0x004f78c8` (one struct
later in `.data`) was due to an arithmetic mistake. The bytes at
`0x004f78c8` are unrelated ECM-filename descriptors.

#### Dispatch logic (from asm at 0x004ba842)

```asm
mov  eax, g_currentNodeFlags      ; load flag word
sar  eax, 24                      ; eax = flags >> 24
and  eax, 7                       ; eax = (flags >> 24) & 7   (node type, 0-7)
test g_currentNodeFlags, 0x100
je   .skip
add  eax, 8                       ; +8 if mode bit set         (node mode, 0/1)
.skip:
mov  eax, [g_nodeDispatchTable + eax*4]   ; eax = handler
call eax
```

So `node_type ∈ [0,7]` and `node_mode ∈ {0,1}` form a 4-bit index
into a 16-entry function-pointer table.

#### The 16 entries (9 distinct handlers)

| Idx (type/mode) | Handler | Size | Calls helper |
|---|---|---|---|
| 0/0, 6/0, 7/0 | `NodeApplyTransform_A` `0x004bdb50` | 0xa3 | `BuildRotMatrix_OrderA` `0x004b3800` |
| 1/0 | `NodeApplyTransform_C` `0x004bde90` | 0xa3 | `BuildRotMatrix_OrderC` `0x004b36c0` |
| 2/0 | `NodeApplyTransform_B` `0x004bdca0` | 0xa3 | `BuildRotMatrix_OrderB` `0x004b3940` |
| 3/0 | `NodeApplyTransform_C_Inverse` `0x004bdfb0` | 0x9d | `BuildRotMatrix_OrderC` (no negation) |
| 4/0, 4/1 | `NodeApplyMatrix` `0x004be050` | 0xd6 | (no callee - copies pre-built 3x3 matrix) |
| 5/0, 5/1 | `NodeApplyTransform_B_Swapped` `0x004be130` | 0xe0 | wraps `NodeApplyTransform_B` |
| 0/1, 3/1, 6/1, 7/1 | `NodeApplyTransform_A_Direct` `0x004bdc00` | 0x62 | `BuildRotMatrix_OrderA` (BAM input) |
| 1/1 | `NodeApplyTransform_C_Direct` `0x004bdf40` | 0x62 | `BuildRotMatrix_OrderC` (BAM input) |
| 2/1 | `NodeApplyTransform_B_Direct` `0x004bdd50` | 0x62 | `BuildRotMatrix_OrderB` (BAM input) |

The "small" mode-1 variants (0x62 bytes vs 0xa3 in mode 0) suggest a
simpler render path - maybe alpha-blended polygons or no Z-buffer.

#### Node descriptor layout (deduced from RenderSceneNode reads)

Each scene-graph node has a descriptor of at least 0x48 bytes
(18 dwords). Confirmed fields read:

| Offset | Meaning |
|---|---|
| `+0x00` | (DWORD, dword index 0) |
| `+0x0c` | (dword index 3) |
| `+0x10` | (dword index 4) |
| `+0x20` | **flag word** (`g_currentNodeFlags`) - encodes type, mode, and other bits |
| `+0x24` | (dword index 9) |
| `+0x3c..0x44` | child references (3 dwords, can all be zero) |

`g_currentNodeIdx` is a packed pointer (= `node_descriptor_address / 4`),
multiplied by 4 to recover the actual address. Quirky encoding from
the original PSX/N64 codebase.

**Reframing the "37 records" finding**: those 37 records inside a
character `.geo` are scene-graph nodes (mesh skeleton parts),
each dispatched to one of 9 different render handlers based on
its type/mode bits. The recursion in `RenderSceneNode` walks the
hierarchy through the `+0x3c..0x44` child fields.

### The 9 handlers ARE NOT renderers - they're TRANSFORM SETTERS

After decompiling all 9 handlers (post-RenderSceneNode dispatch), a
clearer picture emerges: **none of them call DrawMeshBlock or any
draw routine directly**. They all manipulate the transform stack:

```c
// Generic mode-0 handler (0xa3 bytes - types 0, 1, 2, 3 / mode 0):
void NodeApplyTransform_X(void) {
    // Read 3 components from node descriptor, scale 16.16 radians → 12-bit BAM
    short angles[3] = {
        ±scale(node[0]),    // x
        ±scale(node[1]),    // y
        ±scale(node[2]),    // z
    };
    BuildRotMatrix_OrderX(angles, current_transform);   // build 3x3 rot matrix
    g_transformDirty |= 0x30;     // mark dirty
}
```

The "modes" come in pairs:
- **Mode 0** (0xa3 bytes): input is 16.16 fixed-point radians,
  conversion `(x >> 2) * 0x28BE >> 0x12` ≈ `x * 651.9 / 65536`
  (= radian → 12-bit BAM). Used when angles are stored as floats.
- **Mode 1** (0x62 bytes): input is already a 16-bit BAM angle,
  copied directly. Faster, used when angles are pre-converted.

So MK4's skeleton stores joint angles in TWO POSSIBLE FORMATS per
joint, with a flag bit selecting which. Animation playback can use
the smaller representation; rest poses might use the higher-precision
float form.

### Three Euler axis orderings = three joint types

Instead of using one universal Euler order, MK4 has three distinct
3×3-matrix builders:

| Helper | VA | Used by node types |
|---|---|---|
| `BuildRotMatrix_OrderA` | `0x004b3800` | 0, 3, 6, 7 (default) |
| `BuildRotMatrix_OrderB` | `0x004b3940` | 2, 5 |
| `BuildRotMatrix_OrderC` | `0x004b36c0` | 1, 3 (inverse) |

Each builds a 3×3 rotation matrix from 3 Euler angles, but with
different multiplication orderings. The exact axis sequences (XYZ,
ZYX, YXZ, ...) are recoverable from the matrix-element formulas
in each function - a future pass can decode this.

### The sin lookup table

`g_sinTable` at `0x007b01a0` is a 4096-entry × 4-byte fixed-point
sine table (16 KB total). Indexed by binary angle measure (BAM):
`0x1000 = 2π`. The lookup trick:

```c
sin(angle) =  g_sinTable[angle & 0xfff]
cos(angle) = -g_sinTable[(angle - 0x400) & 0xfff]
```

(Because `sin(a - π/2) = -cos(a)` and `0x400 = π/2` in BAM.)

This is a textbook fighting-game-engine optimization: avoid float
sin/cos by precomputing a table, use BAM for cheap arithmetic, and
share the same table for both sin and cos via offset.

### Two special handlers (no transform builder call)

- **`NodeApplyMatrix`** (`0x004be050`, types 4): copies a pre-built
  9-dword (3×3) matrix from a sub-descriptor at `node[+0x28]`. Used
  for rest-poses or pre-baked transforms.
- **`NodeApplyTransform_B_Swapped`** (`0x004be130`, types 5): reorders
  the 3-vector `[a,b,c] → [a,c,b]` (swaps Y/Z) before delegating to
  `NodeApplyTransform_B`. Coordinate-system flip - common when
  importing from a tool with different axis conventions.

### Implication for the .geo file format

A character `.geo` is now understood as a **skeleton + mesh archive**:

1. **Block-header table** at offset `0x0C` lists ~37 records. Each
   record describes one **joint** (or a leaf mesh) of the skeleton.
2. **Node descriptors** (≥ 0x48 bytes each) live in the per-block
   data area pointed to by `ofs_a` / `ofs_b`. They contain:
   - 3 angles (in radians 16.16 OR BAM 16-bit, per the mode bit)
   - flag word with `type` (bits 24-26) and `mode` (bit 8)
   - child references (offsets +0x3c..0x44)
3. **`RenderSceneNode`** is invoked once at the root and recurses
   through the joint hierarchy. At each joint, it picks the correct
   transform handler from `g_nodeDispatchTable`, which sets the
   joint's local rotation onto the transform stack. After all
   transforms are applied, leaf meshes call `DrawMeshBlock` (which
   we already decoded - short-int vertex stream + sentinel face
   stream + back-face cull → SubmitDrawEntry).

This is a **standard skeletal-animation format** in late-90s console
3D engines: BAM angles for compactness, sine LUT for speed, multiple
Euler orderings for flexibility, fixed-point math throughout.

### What's still open

- **The full node format** - per-type layout of the 12-20 byte
  sub-header between `ofs_b` and `ofs_a`. Likely contains the node's
  local transform (matrix or quaternion) plus child references.
- ~~**Outer walker decompilation**~~ - **DONE** - `RenderSceneNode`
  (`0x004ba720`) fully analyzed; the 16-entry dispatch table at
  `g_nodeDispatchTable` (`0x004f7888`) drives 9 distinct handlers
  by node type/mode bits. See [scenegraph.md](scenegraph.md).
- **Per-primitive draw routines** - 12 functions call
  `SubmitDrawEntry`, each presumably handles a specific node-type.
  Cataloging them would reveal all the .geo node variants.
- **UV coordinates and texture-slot reference per triangle** - must
  be in either the VERTEX stream or the HEADER stream (`flag` byte).
- **Skinning** (joint weights) - for animated characters, vertices
  must be associated with bones. Probably in `ofs_c`.
- ~~**Sort key LUT at `DAT_00b0d008`**~~ - **DECODED** - `g_zSortKeyLUT`
  is built by `BuildSortKeyLUT` (`0x004bf290`) with the hyperbolic
  formula `(s32)(i / (i * 31 / 65536 + 1))`. See [render.md](render.md).

### RLE-16 stream

Per-scanline 16-bit RLE format. Pixel format is **RGB-555**
(top bit = unused or alpha, then 5/5/5 BGR or RGB - observed BGR is
correct). Decoder writes into a fixed 256-pixel-stride destination buffer.

```
while (pixels_emitted < width):
    token = read_uint16(src)
    if (token & 0x8000) == 0:
        # 2-byte literal
        emit_pixel(token)
    else:
        # 3-byte RLE run
        color = (token & 0x7fff) ? ((token & 0x7fff) ^ g_xorKey) : 0
        run_length = read_uint8(src)
        emit_n_pixels(color, run_length)
```

`g_xorKey` (`DAT_007af91c`) is conditionally set in AppInit:
```c
DVar2 = timeGetTime();
seed_rng(DVar2);
uVar3 = rng();
if ((uVar3 & 3) != 0) {
    g_runtimeFlag = 1;
    return;            // g_xorKey stays at 0
}
uVar3 = rng();
g_xorKey = uVar3 | 0x1881;
```

So in 75% of runs, `g_xorKey == 0` and textures decode as plain RLE-555.
The other 25% would produce scrambled colors - purpose unclear (possibly
a developer flag for a build mode that was left in).

### Decoder & verification

Implementation: [tools/geo_decode.py](../../tools/geo_decode.py).

Successfully decoded (visual confirmation, RGB-555 + xor_key=0):
- `sc_geo.geo` → Scorpion's texture atlas (face, yellow ninja outfit,
  gold dragon medallion)
- `sz_geo.geo` → Sub-Zero's texture atlas (blue ice costume, dragon)
- `lk_geo.geo` → Liu Kang's texture atlas (red headband + tank top)
- `tomb_geo.geo` → Tomb stage backgrounds (stone walls, torches, bars)
- `font3d_g.geo` → 3D font glyph atlases (2 textures)
- `midway_g.geo` → Midway logo
- `vs_sc_ge.geo` → vs-screen Scorpion portrait

100% successful end-to-end.

### Loader code in MK4.EXE

| Function | VA | Role |
|---|---|---|
| `LoadGeoAsset_Textures` | `0x004bd6e0` | Loads a .geo file via FSYS_fload, then iterates the texture entries and dispatches each to a cache slot |
| `Tex_DecodeRLE16` | `0x004bd5f0` | Decodes RLE-16 to a 256-stride buffer, then calls `Helper_TexUpload(slot, 0, 0, w, h)` (`0x004bf370` - GPU upload) |
| `FSYS_fopen` | `0x004b1e00` | Open by name (binary search by hash) |
| `FSYS_fload` | `0x004b2160` | Read entire asset into a buffer |
| `FSYS_fsize` | `0x004b2120` | Size by name (suspected) |
| `Mem_Malloc` | `0x004b5bc0` | Game's allocator wrapper |

---

### Character file variants (DECODED via texture inspection)

Each character has 4-5 `.geo` files in `c:\source\mk4\win\geogfx\`:

| File | Content | Verified by |
|---|---|---|
| `<char>_geo.geo` | Default in-game model + texture atlas | Sub-Zero blue ninja, Liu Kang red, Scorpion yellow |
| `<char>_a_geo.geo` | **Alternate skin / costume** (same skeleton, different texture/colors) | Scorpion in orange instead of yellow |
| `<char>_g_geo.geo` | **Third skin variant** (often a "demon" / "skeleton" / "alt mask" form) | Scorpion shows skull face; Liu Kang shows black-clothed variant |
| `<char>_m_geo.geo` | **MOVE LIST screen** (texture-only, 256x256) - UI overlay listing inputs | "SCORPION / WEAPON F.F.HK / SPEAR B.B.LP / ..." text decoded ✓ |
| `<char>_e_geo.geo` | (suspected) **Ending screen** | Some chars only |
| `<char>_fat<N>_.geo` | Fatality-specific mesh | Scorpion has `sc_fat2_.geo` for FATALITY II |

Plus shared assets:
| File | Content |
|---|---|
| `vs_<XX>_ge.geo` | Versus-screen portrait per character |
| `tomb_geo.geo`, `well_geo.geo`, etc. | Stage backgrounds |
| `font3d_g.geo` | 3D font glyph atlas |
| `MKlogo_g.geo`, `midway_g.geo` | Logos |

### Sort key LUT (DECODED - hyperbolic z-bucketing)

`g_zSortKeyLUT` at `0x00b0d008` is a **128 KB lookup table** (65536 × uint16)
built once at startup by `BuildSortKeyLUT`. Maps a 16-bit z-value to a
coarse bucket index used as the sort key in `g_drawQueue`:

```
bucket(z) = 65536·z / (31·z + 65536)    # for z ∈ [0, 65535]
```

Sample mappings:
- z=100 → bucket=95
- z=1000 → bucket=678
- z=10000 → bucket=1745
- z=65535 → bucket=2047

This is a **hyperbolic 1/z mapping**: more bucket precision near the
camera, compression at the far plane. The 1024-entry counting-sort
histogram (`g_drawQueueBuckets`) only uses 1024 of the ~2048-bucket
range - z values past ~32k are merged into the back of the queue.

Constants live in `.rdata`:
- C1 = 31.0 at 0x004d2a50
- C2 = 1.52587890625e-05 (= 2⁻¹⁶) at 0x004d2a58
- C3 = -1.0 at 0x004d2a60

### Mystery entries 0 and 1 of FILESYS.DAT (PARTIAL)

The two FILESYS.DAT entries we couldn't recover names for via brute
force. Hashes differ by exactly `0x00010000`, indicating their names
differ by ±1 in a single character at position `N % 4 == 2` (i.e. pos
6, 10, 14, …). Both extracted directly via offset/size (see
[tools/fsys_extract_by_offset.py](../../tools/fsys_extract_by_offset.py)).

**Entry 0** (2964 B = 741 × 4-byte records):

```
records   IDs                         purpose (suspected)
─────────────────────────────────────────────────────────
0..127    all (0x0001, varying)       homogeneous batch - 128 base resources?
128..639  sparse 0x002c..0x024b       512 distinct items (non-sequential IDs)
640..739  sequential 0x8000..0x8263   100 items in a numbered series (with gaps)
740       (0xFFFF, 0x0000)            terminator
```

The "second short" is small (0x60 to 0x2640) - looks like sizes or
counts. **Sum of all 'b' fields = 1,269,068 bytes** - does NOT match
entry 1's size (1,138,516), so the two are not in a simple
"index → bundle" relationship. They might be unrelated files, or
the index has a more complex layout.

**Entry 1** (1.1 MB) starts with what looks like an offset table:
DWORDs `0x3e1, 0xd98, 0x23b0, 0x2d44, 0x8113, 0x614e, ...` - generally
increasing then dropping, suggesting a bundled-asset format with TOC.

**What it could be**: a sound/speech bank, an animation database, or a
generic asset bundle. Without runtime tracing of `FSYS_fopen` calls
to identify which game features access these, definitive
identification isn't possible from static analysis alone.

**To resolve next**: run the game under x64dbg (or equivalent) with a
breakpoint on FSYS_fopen, log the filenames passed in, and look for
the hashes 0x2da2df95 / 0x2da3df95.

### Euler axis identification (PARTIAL)

The 3 `BuildRotMatrix_OrderX` helpers have been verified to be Euler-to-
matrix builders that:
- Use `g_sinTable` for sin/cos
- Build a 3×3 matrix from 3 angles
- Multiply with `>> 12` divisor (fixed-point precision 1/4096)
- Differ in multiplication order (3 of the 6 possible Euler orderings)

Identifying the EXACT axis sequence (XYZ vs ZYX vs YZX vs ...) requires
either (a) algebraic comparison against canonical Euler-matrix forms for
all 6 orderings, or (b) numerical experiments (substituting specific
angle values and comparing output matrices). Neither is critical for
understanding the engine - knowing the helper signature and that they
produce valid 3×3 rotation matrices is sufficient for porting.

---

## ESF audio format (FULLY DECODED)

ESF files are MK4's proprietary audio format. Header is 8 bytes followed
by either raw PCM (8-bit) or IMA ADPCM (16-bit, 4:1 compressed).

### Header

```c
struct esf_header {
    char     magic[4];      // "ESF\x06"  (= 0x06465345 LE)
    uint32_t format_word;
    //  bits 0..28 : decoded byte count (output buffer size)
    //  bits 2..28 : encoded byte count (for ADPCM only - bits 0-1 unused)
    //  bit 29     : 0 = 8-bit raw, 1 = 16-bit IMA ADPCM
    //  bit 30     : 0 = 11025 Hz,  1 = 22050 Hz
    //  bit 31     : 0 = mono,      1 = stereo
};
```

### 8-bit format (354/385 PCMK files)

Raw unsigned PCM samples, centered at 0x80, mono 11025 Hz. Trivial to
wrap in a WAV container. Used for short SFX (punches, kicks, hit sounds).

### 16-bit format (29/385 PCMK files - high quality voices)

**MS-IMA ADPCM** at 22050 Hz mono. Encoded data is `(format_word>>2) &
0x7FFFFFF` bytes (= 4-bit nibbles per sample). Decoder produces signed
int16 LE samples.

The decoder in MK4.EXE (`ESF_DecodeADPCM` at `0x004ac200`) follows the
canonical MS-IMA algorithm:

```c
diff = step >> 3
if (nibble & 4) diff += step           // 1.0 of step
if (nibble & 2) diff += step >> 1      // 0.5
if (nibble & 1) diff += step >> 2      // 0.25
if (nibble & 8) diff = -diff           // sign

predictor = clamp(predictor + diff, -32768, 32767)
step_index = clamp(step_index + indexTable[nibble], 0, 88)
step = stepTable[step_index]
```

Initial state: `predictor = 0, step_index = 0`. High nibble first per byte.

The lookup tables in MK4.EXE match the canonical MS-IMA spec exactly:
- `g_imaIndexTable` at `0x004f44e0`: `[-1,-1,-1,-1, 2,4,6,8] × 2`
- `g_imaStepTable` at `0x004f4520`: 89 entries from 7 to 32767

### Read flow

```c
int decoded_size = ESF_Open(filename, &bits, &rate, &channels);
char *buf = malloc(decoded_size);
ESF_ReadData(buf);           // for 16-bit, decodes ADPCM 4:1 in-place
ESF_Close();
```

### Decoded output

356 of 385 PCMK ESF files (range 0021-0694) successfully extracted
and converted to playable WAV. See [tools/esf_to_wav.py](../../tools/esf_to_wav.py).

| File range | Format | Use |
|---|---|---|
| ~354 files | 8-bit / 11025 Hz / mono | SFX (punches, kicks, hits) |
| ~29 files  | IMA ADPCM / 22050 Hz / mono | Character voices, fatality clips |
| 2 files | 8-bit / 11025 Hz / stereo | Special (intro? music?) |

The ESF subsystem in MK4.EXE:

| Function | VA | Role |
|---|---|---|
| `ESF_Open` | `0x004b1090` | Read 8-byte header, validate magic, parse format flags |
| `ESF_ReadData` | `0x004b1150` | Read PCM (raw) or ADPCM (decode 4:1) into dst buffer |
| `ESF_DecodeADPCM` | `0x004ac200` | MS-IMA ADPCM decoder |
| `ESF_Close` | `0x004b1200` | fclose the handle |
| `FSYS_fread/fseek/fclose` | (same range) | FSYS-layer I/O wrappers |

---

## ECM cinematic format (Eurocom Custom Movie) - partially mapped

ECM = Eurocom Custom Movie. Used for the 16 character bios (`B_*.ECM`),
15 endings (`E_*.ECM`), and 4 large cinematics (`m_intro.ecm`,
`m_midway.ecm`, `m_euro.ecm`, `m_komerc.ecm`).

### File layout (mapped)

```
0x0000   ┌──────────────────────────────────┐
         │ Header (3608 bytes / 0xe18)      │
         │   magic[4]    = "ECM\x02"        │
         │   frame_count : uint32           │
         │   group_offs[]: 900 × int32      │  ← byte-size of each group
         │                  (one per ~15 frames)
0x0e18   ├──────────────────────────────────┤
         │ Frame data, sequential groups,   │
         │ each starting with "SEC\0"       │  ← group magic = 0x00434553
         │   (= 0x00434553 LE)              │
         │                                   │
         │ Each group encodes 15 frames      │
         │ with interleaved video + audio    │
         └──────────────────────────────────┘
```

Sample frame counts:
- `M_INTRO.ECM` (16.8 MB): 1000 frames
- `E_FUJIN.ECM` (13.5 MB): 840 frames
- `B_FUJIN.ECM` (3.2 MB): 225 frames
- `M_MIDWAY.ECM` (1.8 MB): 152 frames

### Playback model

ECM is **threaded streaming** with audio synchronized via DirectSound:

```
ECM_Open(filename, dsound_iface, ?, frame_skip)
  ├── fread 3608 bytes header @ g_ecmHeader, validate magic
  ├── allocate DirectSound secondary buffer:
  │     supported rates: 11025 / 22050 / 44100 Hz
  │     16-bit PCM, mono
  ├── fseek past skipped groups (sum group_offs[0..frame_skip/15])
  ├── CreateThread(ECM_PlayThread)
  │     thread streams groups, decodes audio + video,
  │     fills DSound buffer + drives video frame output
  └── return frame_count
```

`ECM_Cleanup` reverses: signals thread, terminates after 3-sec timeout,
releases DSound buffer (vtable[8] = IUnknown::Release), zeros the
header buffer, fcloses the file.

### Functions identified

| Function | VA | Role |
|---|---|---|
| `ECM_Open` | `0x004b06f0` | Open file, parse header, start playback thread |
| `ECM_Cleanup` | `0x004b0cb0` | Stop thread, release DirectSound, close file |
| `ECM_PlayThread` | `0x004b0a50` | Background streaming + decoding worker |

### Per-group structure (DECODED)

Each group (after the 4-byte `"SEC\0"` magic) contains the audio +
video data for 15 frames packed contiguously:

```
Offset 0    : "SEC\0" magic (4 bytes)
Offset 4    : Audio - IMA ADPCM payload
              encoded ~11025 bytes → decoded 0xac44 = 44100 bytes
              (= 1 second of 22050 Hz mono 16-bit PCM)
              Decoded by ESF_DecodeADPCM (same as ESF audio).
After audio : Video frames (15 of them, packed back-to-back)
              Each frame begins with a 12-byte sub-header:
                +0  3 bytes "EDL" magic
                +3  1 byte: bit 7 = flag, bits 0-6 = compression mode
                +4  uint32 frame_size (decoded byte count)
                +8  uint32 extra (palette/offset?)
                +12 frame_size bytes of compressed/raw data
```

The video portion is dispatched by mode:

| Mode | Decoder | Logic |
|---|---|---|
| 0 | `ECM_DecodeFrame_Raw` | trivial `memmove(dst, src+12, frame_size)` (handles overlap) |
| 1 | `ECM_DecodeFrame_Huffman` | variable-length entropy decode (~2400 bytes of code) |

Mode 1 is a **classic Huffman/entropy decoder**:
- Reads a bit stream from the encoded data
- Builds a 16-symbol frequency table on the stack (32 bytes)
- Sorts symbols by frequency, builds a prefix-code table
- Decodes `frame_size` bytes one symbol at a time

Full bit-by-bit specification of the Huffman decoder is left for a
future round (~2400 bytes of carefully reversed asm). For PRACTICAL
porting purposes, replacing the ECM playback subsystem with a modern
video container (`.webm` / `.mp4`) is **far** simpler than re-
implementing the codec - re-encoding the cinematics by capture is a
one-time job; preserving the codec implementation is recurring
maintenance.

### Audio sync mechanism (mapped)

Each group provides exactly 1 second of decoded audio (44100 bytes =
22050 samples at 16-bit mono). The video portion has 15 frames per
group → **15 fps for video, audio sample-perfect at 22050 Hz**.

The DirectSound buffer is treated as a 4-slot ring (`slot = (frame_idx
+ 1) & 3`). The thread Locks the next slot, decodes audio into it,
Unlocks, and the buffer plays continuously - classic "streaming PCM"
pattern. On `DSERR_BUFFERLOST` (0x88780096), the thread Restore+Stop+
re-Lock+zero-fill+Unlock sequence recovers the buffer.

### Functions identified

| Function | VA | Role |
|---|---|---|
| `ECM_Open` | `0x004b06f0` | Open file, parse header, start playback thread |
| `ECM_Cleanup` | `0x004b0cb0` | Stop thread, release DSound, close file |
| `ECM_PlayThread` | `0x004b0a50` | Background streaming + decoding worker |
| `ECM_DecodeFrame` | `0x004b1c90` | Setup state, dispatch decode |
| `ECM_DecodeFrameDispatch` | `0x004b1bf0` | Parse header, dispatch by mode |
| `ECM_ParseFrameHeader` | `0x004b1c30` | "EDL" magic + mode + sizes |
| `ECM_DecodeFrame_Raw` | `0x004b1220` | mode 0: memmove |
| `ECM_DecodeFrame_Huffman` | `0x004b1270` | mode 1: Huffman entropy decoder |

### What's still TBD

- **Bit-by-bit Huffman decoder spec** for mode 1 (~2400 bytes asm).
  Doable but tedious - would yield byte-perfect frame reproduction.
- **Per-frame video format** - the decoded data layout (size, color
  format, palette ref via the `extra` field). Probably 8-bit
  paletted. The output buffer at offset 0xac44 within a 0x16ad7-byte
  slot suggests video frames are also written into the same big
  staging area as audio.
- **15 fps timing** - confirmed conceptually but the exact frame
  pacing in the playback loop has subtle Sleep/sync logic.

---

## Compiler identification (CONFIRMED)

**Microsoft Visual C++ 5.0** (released 1997), linker version 5.10.

Evidence:
- PE `MajorLinkerVersion=5, MinorLinkerVersion=10` - exact MSVC 5.0
  signature (4.x linker is 3.x; 6.x linker is 6.0+)
- `MajorSubsystemVersion=4` - targets Win95/NT 4.0
- CRT R-codes present: `R6002`, `R6016..R6019`, `R6024..R6028` -
  complete MSVC 5.x/6.x runtime error set
- String `"Microsoft Visual C++ Runtime Library"` + `"Runtime Error!"`
- Classic SEH-based mainCRTStartup prologue at the entry point:
  ```
  push -1; push <frame>; push <handler>; mov fs:[0], esp
  ```
- No `MSVCRT.DLL` in imports → **statically-linked CRT** (built
  with `/MT` flag)
- Rich header is scrubbed (only the resource compiler entry remains
  intact, with build 0x684 = 1668; the rest XOR'd to zero/padding) -
  intentional post-processing, was common in 1998 game shipping

### Bonus discovery: this is a PSX/N64 codebase port

The leaked symbol `_guDrawTriangleWithClip@12` (`@12` = stdcall) uses
the **`gu_` prefix from libultra** - Nintendo's N64 SDK graphics
helper namespace. Cross-referenced with all other engine quirks we've
identified, MK4's PC engine is clearly a port of the N64/PSX
codebase:

- 16-bit fixed-point vertex coordinates (no FPU on PSX MIPS R3000A)
- BAM (binary angle measure, 4096 = 2π) for joint rotations
- 4096-entry sine LUT (typical N64 / PSX optimization)
- Packed pointer/4 encoding in `g_currentNodeIdx` (MIPS-style)
- `>> 12` fixed-point division everywhere (4096 = 1.0 in fixed-point)
- Triangle-strip mesh encoding with sentinel termination
- Per-renderer dispatch tables (multiple render backends - N64 had
  multiple ucodes; PC has SW / Glide / D3D / SW-hires)

This is consistent with the cross-platform release strategy: the same
Eurocom engine code was retargeted from N64 microcode + MIPS R3000A
PSX builds to PC via MSVC 5.0 + DirectDraw/DirectSound wrappers.

### Implications for the matching build target

To produce a byte-identical `MK4.EXE` from reconstructed C source, the
matching build chain needs:
- **Microsoft Visual C++ 5.0** compiler (CL.EXE) and linker (LINK.EXE 5.10)
  - likely with one of the published Service Packs (SP1-SP3, 1997-1998)
- Compiler flags `/MT /O2 /W3` (typical for MSVC 5.0 game binaries)
- `RC.EXE` (resource compiler) - though the recovered Rich entry's
  build 0x684 doesn't cleanly match a known SP, so the original
  build probably mixed tools
- A post-build step that **scrubs/zeroes most of the Rich header**
  (or simply skip Rich generation by using a custom linker invocation)

For practical purposes the matching toolchain is straightforward to
acquire (MSVC 5.0 archive copies are findable, run under wine64 on
macOS via Whisky). The post-build Rich scrubbing is a one-line
hexedit if needed.

For NON-matching (`/portable`) builds, MinGW-w64 is fine - already
installed via `tools/setup-macos.sh`.

---

## Game state machine (DECODED)

`GameStateMachine` (`0x004b6340`) is the heart of MK4's gameplay flow.
It's a switch-based FSM driven by a state variable `g_gameState`
(`DAT_00ab438c`):

```
                    ┌──────────────────────┐
                    │  STATE 0 - main menu │
                    └─┬─────────────────────┘
                      │ caller passes cmd 1..8
        ┌─────────────┼──────────────┬─────┬─────┬─────┐
        ▼             ▼              ▼     ▼     ▼     ▼
   STATE 5         STATE 6        STATE 7  ...  STATE 0xc
   FUN_004b8630    FUN_004b84d0   ...
                      │
                      │ result 0x45 → STATE 4 (in-game)
                      │ result 0x18..0x1c → enter sub-state
                      ▼
              SUB-STATES 0x18..0x1c
              (FUN_004b6900 / 7260 / 7b10 / 7df0 / 81f0)
                      │ result 3 → back to STATE 6
                      ▼
                STATE 6 again
```

| State | Handler                       | Role (DECODED via byte-table dispatch)    |
|-------|-------------------------------|-------------------------------------------|
| 0     | (main menu, sub-dispatches on `cmd` via `g_gsmJumpTable2`) | MAINMENU       |
| 4     | `Helper_GSM_HandleEvent` `0x004b84d0` | TRANSITION (audio re-arm)            |
| 5     | `Helper_GSM_VS` `0x004b6900`  | ARCADE                                    |
| 6     | `Helper_GSM_Tournament` `0x004b7260` | VS                                  |
| 7     | `Helper_GSM_Practice` `0x004b7b10` | TOURNAMENT                            |
| 8     | `Helper_GSM_Options` `0x004b7df0` | PRACTICE                              |
| 9     | `Helper_GSM_Config` `0x004b81f0` | OPTIONS                                |
| 0xa   | (handler reused)              | CONFIG                                    |
| 0xb   | (default no-op)               | CREDITS (falls through to default tail)   |
| 0xc   | (default no-op)               | SETTINGS                                  |
| 0x18  | `Helper_GSM_Sub18` `0x004b8630` | CHAR_SELECT_1                            |
| 0x19  | `Helper_GSM_Sub19` `0x004b8730` | CHAR_SELECT_2                            |
| 0x1a  | `Helper_GSM_Sub1A` `0x004b8830` | STAGE_SELECT                             |
| 0x1b  | `Helper_GSM_Sub1B` `0x004b8930` | PRE_FIGHT_INTRO                          |
| 0x1c  | `Helper_GSM_Sub1C` `0x004b8a30` | GFX_OPTIONS                              |

Full byte-table + sub-dispatch decoding in [combat_fsm.md](combat_fsm.md).

The 4 callers of `GameStateMachine`:
- **`AppInit`** - sets initial state during boot
- **`GameLogicStep`** - per-frame tick (cmd=0)
- **`WndProc`** - handles key events that map to menu commands
  (we already decoded F1/F2 → cmd 1/2 in WndProc)
- **`PumpMessages`** - on WM_QUIT, signals shutdown

## Gameplay architecture (DECODED - corrected model)

After deeper RE, the gameplay vs menu split is **two parallel systems**,
not a single FSM:

```
┌─────────────────────────────────┐  ┌─────────────────────────────────┐
│  GameStateMachine (menus)       │  │  GameTick (gameplay)             │
│  switches on g_gameState        │  │  gated by g_gameMode == 0        │
│  - state 0  : main menu          │  │                                  │
│  - state 4  : transition         │  │  - up to 4 players (P1..P4)     │
│  - state 5..0xc : 8 menu screens │  │  - per-entity tick               │
│  - state 0x18..0x1c : sub-screens│  │  - physics + collision           │
│  - calls DrawMenu helper         │  │  - camera shake / lighting decay │
└─────────────────────────────────┘  └─────────────────────────────────┘
        ▲                                        ▲
        │                                        │
   GameLogicStep ─────────────────────────────────
   (the 60Hz tick called from MainLoopStep)
```

The FSM (`g_gameState`) is **menu-only** - it dispatches between UI
screens. The fight itself runs through `GameTick`, which is gated by
`g_gameMode = 0`. Both run every frame; their effects are independent.

### GameTick architecture (current pure-C body)

The function is now pure C in [src/game/game_tick.c](../../src/game/game_tick.c).
The placeholder names "Physics" / "Collision" / "TickEntity_A/B" from
my earlier interpretation were wrong - see the explicit correction
section below. Current accurate flow:

```c
void GameTick(int param) {
    /* 1. Debug stubs (DebugStub_NoOp_A/B are compiled out - 1-byte ret) */
    if (g_gameMode != 0) DebugStub_NoOp_*(g_gtPauseMode);
    if (g_gtOtherFlag == 1) DebugStub_NoOp_*(g_gtModeFlag);
    if (g_gtConfig4f != 2 && g_gtState438 != 0) DebugStub_NoOp_*();

    /* 2. Main fight pump */
    if (g_gameMode == 0) {
        FightFrameStep();                /* 0x0045c5c0 - 3-pass scenegraph */
        if (g_framePauseFlag) return;
        ++g_gtFightTickCounter;
        DispatchEventQueue();            /* 0x0045c820 - drain pending events */
        if (g_framePauseFlag) return;
    }

    Helper_TickFrame_Misc();             /* 0x004a1d50 */
    if (g_framePauseFlag) return;
    Helper_TickFrame_PostFight();        /* 0x0049cbe0 */
    if (g_framePauseFlag) return;

    /* 3. Per-player tick (only in fight mode) */
    if (g_gameMode == 0) {
        g_walkCallback = (void *)g_player1NodeIdx;
        if (g_player1NodeIdx != 0) Helper_PerPlayerTick();
        if (g_framePauseFlag) return;
        Helper_PostPlayerTick();         /* 0x004227b0 */
        if (g_framePauseFlag) return;
        Helper_TickFrameTail();          /* 0x004051e0 */
        if (g_framePauseFlag) return;
    }

    /* 4. 4-player overlay scan (toggles +0x1000 flag based on y-position) */
    if (param == 0) {
        for (i = 1..4) {
            p = g_playerN_NodeIdx;
            if (p && nodes[p].player_id == i && probes != 0 && state != 0x501) {
                if (enabled && nodes[p].pos_y > -0xffff_0000)
                    nodes[p].flags |= 0x1000;
                else
                    nodes[p].flags &= ~0x1000;
            }
        }
    }

    /* 5. Axis lowpass + sentinel reset */
    g_gtAxisX += (0x8000 - g_gtAxisX) / 8;    /* same for Y, Z */
    if (g_gameMode == -1) g_gameMode = 0;
}
```

See [combat_fsm.md](combat_fsm.md) for the full per-frame breakdown
including the event queue ping-pong and the 4-player state machine.

### Player descriptor layout

Each player's character has a node descriptor at
`g_playerN_NodeIdx * 4`. Confirmed fields:

| Offset | Type | Meaning |
|---|---|---|
| `+0x30` | int | player_id (1..4, validation) |
| `+0x34` | uint | flags (bit 0x1000 = "on screen") |
| `+0x58` | int | y-position component (signed, clamped to -0xffff) |
| `+0x74` | int | state machine value (0x501 = special state) |

### Per-frame audio updates

Three of GameLogicStep's auxiliary calls are audio updates:

| Function | VA | Role |
|---|---|---|
| `Audio_TimerTick` | `0x004ac4b0` | Schedules background audio via timeGetTime |
| `Audio_UpdateChannels` | `0x004c37f0` | Iterates active sound channels, ticks each via vtable[0x24], removes finished ones |

The other GameLogicStep helpers (`Input_TickPlayers` at
`0x004b5850` for idle-when-state-0 logic, `XformChainAdvance` at
`0x004bd990` for per-frame xform update) are minor cleanup wrappers.

## GameLogicStep - the per-frame heart of gameplay

```c
void GameLogicStep(void) {
    ++g_frameCounter;                                  // 60 Hz monotonic counter
    g_gameStateResult = GameStateMachine(0);           // menu FSM tick
    if (g_gameStateResult == 0) {
        Input_TickPlayers();                // 0x004b5850 - idle when state==0
    }
    Audio_UpdateChannels();                            // 0x004c37f0 - DSound channel sweep
    Audio_TimerTick();                                 // 0x004ac4b0 - MCI music timer
    if (Renderer_GetMode() == 4 && g_mode4PauseGate == 0) {
        GameStateMachine(8);                           // SW-Windowed pause path
        g_logicStepFlag = 0;
        return;
    }
    XformChainAdvance();                               // 0x004bd990 - per-frame xform update
    GameTick(0);                                       // 0x0041fd70 - active-fight tick
    g_logicStepFlag = 0;
}
```

All 5 helpers are now identified. The pure-C body lives in
[src/game/tick.c](../../src/game/tick.c). Full per-frame breakdown
(menu FSM, fight tick, event queue, per-player overlay scan) in
[combat_fsm.md](combat_fsm.md).

---

## Fight subsystem (PARTIAL - names corrected after deeper analysis)

After decompiling the gameplay calls in `GameTick`, the picture is
**not** "physics + collision" as I originally guessed - it's
**input pattern matching + event dispatching** built on a
**dynamic node allocator**.

### Scene-graph node allocator (DECODED)

`AllocateNode` (`0x0041f290`) is the heart of the engine's dynamic
state. It manages a fixed pool of 63 nodes:

```
Pool: DAT_0053e440 .. DAT_00541e40
Each node: 0xe8 = 232 bytes (= 0x3a uint32)
Linked list field at +0xe4 (= idx 0x39)
Sanity tag 0x12345678 at +0xd4 (= idx 0x35)
Head pointer: DAT_0052ab3c
Total alloc count: DAT_00541e64
```

When called:
1. Walks the existing list to find its tail
2. Scans the pool for a free slot (field 0 == 0)
3. Initializes the slot from the current node-context globals
4. Writes the magic at +0xd4
5. Links into the list
6. Returns the new node pointer (or NULL on pool exhaustion)

`AllocNode` (`0x0049cb60`) is a 15-byte wrapper that pulls the type
from `DAT_0054204c` and calls `AllocateNode`. It has **14 distinct
callers across the engine** - heavily-used utility for spawning
projectiles, hit effects, state-transition events, etc.

### Fight tick pipeline (corrected interpretation)

The `g_gameMode == 0` (active fight) branch in `GameTick` runs:

```
GameTick
├── FightFrameStep ──── runs 3 times with different node contexts:
│   │                    Set 1: indices 0x14e928, 0x14e929, ...
│   │                    Set 2: indices 0x14e92a, 0x14e92b, ...
│   │                    Set 3: indices 0x14e92c, 0x14e92d, ...
│   │                    (Suspected: 3 input/control entities - P1, P2, and
│   │                    a third - possibly debug controller or shared bus)
│   └── FightFrameStep_Inner - per-entity state evolution:
│       - reads (curr_state, prev_state, expected_mask) from 3 node fields
│       - XORs to detect changed bits
│       - shifts state forward (prev := curr)
│       - iterates a "pattern table" (advancing by 2)
│       - on match, queues an event in circular buffer 0x14e92e..0x14e942
│
└── DispatchEventQueue ── drains the queue:
    │                     - reads from DAT_0053a2f0 to DAT_0053a31c
    │                     - for each pending event:
    │                       · sets type=0x11
    │                       · calls AllocNode to spawn the result
    │                     - advances read ptr with wrap
    └── DispatchEventQueue_Commit - write-back read pointer
```

Interpretation: this looks very much like **fighting-game input/move
recognition**:

- Inputs (button states) update each frame
- XOR detects pressed/released bits
- A "pattern table" encodes special-move sequences (e.g. "D, D-F, P"
  for a fireball)
- When a sequence completes, an event is queued
- The event spawns a new scene-graph node - projectile, hit effect,
  pose change, sound trigger, etc.

The 20-slot circular event ring suggests max 20 in-flight actions
per frame - plenty for fighting-game pace.

### Important: previous "Physics + Collision" labels were wrong

In a previous session I labeled `FUN_0045c5c0` as "Physics" and
`FUN_0045c820` as "Collision" based on the active-fight gating -
those labels were **wrong**. After decompilation:
- `FUN_0045c5c0` = `FightFrameStep` (input pattern matching)
- `FUN_0045c820` = `DispatchEventQueue` (drains action queue, spawns nodes)

Then I guessed `FUN_004a4170` / `FUN_004a4150` as "TickEntity_A/B"
(per-character ticks). Those were **also wrong** - they're 1-byte
**no-op stubs** (just `ret`). Stripped debug hooks. Renamed to
`DebugStub_NoOp_A` / `DebugStub_NoOp_B`.

### The real per-entity tick architecture

After more digging, the per-entity update lives in a **scene-graph
callback walker**, not in dedicated tick functions:

```
GameTick                                 (0x0041fd70)
└── ... → FrameFinalize                  (0x00405400, end of GameTick)
    └── TickAllEntities                  (0x004b9e50)
        for each of 6 root subtrees in scene graph:
            (HUD, P1, P2, effects, BG, ... at fixed indices)
            └── Helper_TickInner         (0x004ba130 - sibling-walker)
                follows nodes[i].field_4 next-ptr linked list
                for each entity:
                    └── Helper_FightSceneCallback (0x004ba1c0)
                        = the camera-transform + frustum-cull +
                          RenderSceneNode wrapper. Reads node
                          handler at +0x18, flags at +0x34,
                          compares idx to g_player1..4NodeIdx.
                        (Full body large - see [scenegraph.md])
```

So the per-frame loop is:
1. `FightFrameStep` (input → pattern match → enqueue events)
2. `DispatchEventQueue` (drain queue → AllocNode for each event)
3. ... other subsystem ticks ...
4. `TickAllEntities` (walk 6 subtrees → tick each entity via callback)
5. `FrameFinalize` (counter)

This is an **event-driven, scene-graph callback architecture** - common
in late-90s game engines that needed to fit a generic "execute action
sequences" engine on tight memory budgets, with per-character moves /
behaviors encoded as **data tables** rather than code paths.

### Where actual physics / collision / damage live

In an event-driven engine like this, "physics" (gravity, velocity,
position update) and "collision" (hitbox tests, damage application)
are **inside the per-entity tick callback** (`LAB_004ba1c0`) and the
data-tables it consumes. The callback dispatches based on entity type,
runs the entity's current "behavior script" (a state machine in data),
and writes back to the node's position/velocity/state fields.

Decompiling `LAB_004ba1c0` to that level of detail is a **large effort**
(probably 1000+ bytes of asm with many sub-dispatches) and would mostly
re-derive what the data tables already encode. For PORTING:

- **Replace LAB_004ba1c0 with a bytecode interpreter** that reads the
  same data tables → behavior matches the original
- **OR** translate the data tables into idiomatic C → cleaner port,
  more work
- **OR** rewrite gameplay from scratch using the original as a
  reference → simplest but loses original behavior fidelity

The architecture has been mapped enough to choose any of these
strategies. Going deeper into `LAB_004ba1c0` is incremental work that
doesn't reveal further architectural surprises.

---

## Open questions / TODO

### Resolved since this section was written

- ~~**`.geo` mesh portion**~~ - **DONE**. Block-header table, vertex
  stream (12 bytes / vertex), header stream (4 bytes / strip), triangle-
  strip encoding all decoded. `DrawMeshBlock` is the per-leaf submitter.
  See [scenegraph.md](scenegraph.md) and [render.md](render.md).
- ~~**`.esf` sound format**~~ - **FULLY DECODED**. 8-byte header, MS-IMA
  ADPCM decoder verified, 356 of 385 PCMK files extracted to WAV. See
  the dedicated section above and [install.md](install.md).
- ~~**Graphics frame-step trio**~~ - **DONE**. `BeginFrame` /
  `DrawScene` / `PresentFrame` confirmed and their per-mode dispatchers
  decompiled. See [render.md](render.md).
- ~~**Confirm Renderer2/3/5 identities**~~ - **DONE**. R2 = Direct3D 2
  via DDraw QueryInterface; R3 = DDraw FS 320x240; R5 = DDraw FS hi-res.
- ~~**`FUN_004b6340`**~~ - **IDENTIFIED**. It's `GameStateMachine` -
  the top-level menu FSM. F1/F2 keys map to `cmd 1/2` sub-dispatch.
  See [combat_fsm.md](combat_fsm.md).
- ~~**Compiler identification**~~ - **CONFIRMED MSVC 5.0 SP3** (CL
  11.00.7022 Pro Optimizing). Byte-identical rebuild produced from
  reconstructed C source as proof.

### Still open

- **2 unidentified FILESYS.DAT entries** (entries 0 and 1) - small (3 KB)
  and large (1.1 MB), with hashes `0x2da2df95` / `0x2da3df95` differing
  by one char. Probably a base/data pair outside the standard
  `c:\source\mk4\` prefix.
- **Bit-by-bit Huffman decoder spec** for ECM mode 1 (~2400 bytes asm).
  For porting, replacing ECM with a modern video container is far
  cheaper than implementing the codec. See [install.md](install.md).
- ~~**Per-primitive draw routines**~~ - **DONE**. 12 distinct
  functions call `SubmitDrawEntry` (producers); 10 distinct functions
  are dispatched by `FlushDrawQueue` (consumers / SW rasterizers).
  Full inventory + dispatch table in [render.md](render.md)
  ("The 12 draw-queue submitters" and "Software rasterizers").
- **Euler axis identification** - 3 `BuildRotMatrix_Order*` builders
  use different multiplication orderings; the exact axis sequence
  (XYZ vs ZYX vs YXZ vs ...) hasn't been pinned down for each.
- **Skinning (joint weights)** - if animated characters have per-vertex
  bone weights, they likely live in `ofs_c` of each .geo block.
