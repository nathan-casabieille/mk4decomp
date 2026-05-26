# MK4.EXE - Settings save / load

MK4 has no `.sav` file format - all persistent state lives in a
single 588-byte `REG_BINARY` value under
`HKLM\Software\GT Interactive\Mortal Kombat 4\1.00\Config`.
There is no per-character profile, no high-score file, no campaign
save: only the global preferences (audio volume, video mode, input
bindings) survive a relaunch.

The format and the hash/checksum primitives are documented in
[install.md](install.md). This document covers the in-memory <->
buffer <-> registry pipeline.

## End-to-end pipeline

```
   ==== LOAD (at boot, from ValidateInstall @ 0x004ad270) ====

   RegOpenKeyExA(HKLM, "Software\GT...\1.00", KEY_QUERY=0x20019, &hKey)
   RegQueryValueExA(hKey, "Config", NULL, NULL, &g_configBuffer, 0x24c)
   RegCloseKey(hKey)
   Helper_ValidateB   ; DeobfuscateConfig prefix - in-place XOR decrypt
   Helper_ValidateA   ; ComputeConfigHash prefix - verify checksum
   if (g_configBuffer[0] != hash && g_configBuffer[0] != 0xFFFFFFFF):
       ResetConfigToDefaults()       ; bad/missing settings - use defaults
   else:
       g_configChecksum++            ; mark cached state valid
   g_validInstall = 1

   [later, when audio/menu code needs the settings]:
   Config_RestoreGlobals()           ; payload@0x543934 -> ~80 live globals

   ==== SAVE (at shutdown, from AppShutdown @ 0x004b2690) ====

   Config_SaveToRegistry @ 0x004ad410:
     if (g_installValidated == 0): return       ; no settings to save
     Config_SnapshotGlobals()                   ; live globals -> payload@0x543934
     g_configBuffer[0] = ComputeConfigHash()    ; rewrite hash
     DeobfuscateConfig()                        ; XOR re-encrypt
     RegCreateKeyExA(HKLM, "...", KEY_ALL=0x20006, &hKey)
     RegSetValueExA(hKey, "Config", REG_BINARY=3, &g_configBuffer, 588)
     RegCloseKey(hKey)
     g_installValidated = 0                     ; one-shot guard
```

The XOR is its own inverse (`byte[i] ^= (i*123) & 0xff` per
[install.md](install.md)), so the same `DeobfuscateConfig` routine
both encrypts (on save) and decrypts (on load).

The hash is recomputed on save - the game does NOT preserve the
original loaded hash; any tampering in the registry between sessions
is detected by ValidateInstall on the next boot and silently
reset to defaults (the popup is install-path-related, not
config-related; see [install.md](install.md)).

## g_configBuffer layout (588 bytes @ 0x00543928)

| Offset | Size | Field |
|-------:|-----:|-------|
| 0      | 4    | `g_configBuffer[0]` - stored hash (= `ComputeConfigHash()` of bytes [4..583], or `0xFFFFFFFF` for 'always-accept' debug builds). |
| 4      | 8    | (header padding / version stamp, exact use TBD). |
| 12     | 240  | The 60-dword block copied to `g_table_0053a53c` by Config_RestoreGlobals (audio FSM tables + main game settings). Lives at the constant offset `g_configBuffer + 0x0c = 0x00543934`. |
| 252    | 1    | The single byte `g_byte_004f3238` (an audio state flag). |
| 253    | 20   | The 5-dword block copied to `g_table_004f3f28` (audio per-channel state). |
| 273    | ~315 | The ~18-slot snapshot region (controls config, video mode, FSM scratch). See `Config_SnapshotGlobals` for the exact slot list. |

The 'Audio*' field names left over from the previous symbol pass are
misleading - only ~20 of the ~80 snapshotted dwords are audio-related.
The rest are video, input, and game-state.

## Functions in this subsystem

| Address    | Name                       | Size (b) | Role |
|------------|----------------------------|---------:|------|
| 0x004acce0 | `Config_RestoreGlobals`    |      376 | Copies the 588-byte buffer payload at `g_configBuffer + 0x0c` back into ~80 live in-memory settings. Lazy-init guard: if neither gate flag (`g_gsmFlag`, `g_configInitGate_00543f7c`) is set, sets both and calls `Config_SnapshotGlobals` first to seed the buffer from the current globals. Used as the 'apply settings' path from the menus. |
| 0x004ace60 | `Config_SnapshotGlobals`   |      292 | Inverse direction. Copies the ~80 live settings globals into the buffer payload, ready for hashing + XOR + registry write. Bails if not initialized (both gate flags must be set). |
| 0x004acf90 | `ResetConfigToDefaults`    |      634 | Zeroes `g_configBuffer` then re-fills it from the constant table at `0x004f46a0`. Called when ValidateInstall detects a bad hash or missing registry value. |
| 0x004ad210 | `ComputeConfigHash`        |       52 | Hash over `g_configBuffer[4..583]`. Seed `0x43464729` (= "FCG)"). Algorithm: `hash += byte[i] << (i % 23)`. See [install.md](install.md). |
| 0x004ad250 | `DeobfuscateConfig`        |       32 | In-place XOR with the per-byte mask `(i * 123) & 0xff` over bytes [4..583]. Self-inverse: same routine encrypts on save and decrypts on load. |
| 0x004ad270 | `ValidateInstall`          |      402 | Boot-time load path. CheckInstallPath -> GetDriveType (must be DRIVE_FIXED=3) -> RegOpenKeyExA -> RegQueryValueExA('Config', 588 bytes) -> DeobfuscateConfig + ComputeConfigHash verify. On hash mismatch: `ResetConfigToDefaults`. On success: bump `g_configChecksum`. Caches result in `g_validInstall`. |
| 0x004ad410 | `Config_SaveToRegistry`    |      138 | Shutdown-time save path. Guarded by `g_installValidated`: snapshot + hash + XOR + `RegCreateKeyExA` + `RegSetValueExA(REG_BINARY)` + `RegCloseKey`. Clears `g_installValidated` afterwards (one-shot). Called from `AppShutdown`. |

## Globals

| VA            | Name                                 | Meaning |
|---------------|--------------------------------------|---------|
| `0x00543928`  | `g_configBuffer`                     | 588-byte working buffer. Mirrors the `Config` REG_BINARY value, with the same XOR obfuscation on disk and in memory between RegQuery and Helper_ValidateB. |
| `0x0054392c`  | `g_configChecksum`                   | Incremented each time ValidateInstall verifies a registry-loaded Config hash. Effectively a 'how many successful loads this session' counter. |
| `0x00543934`  | (payload @ buffer + 0x0c)            | Start of the 60-dword 'audio/state machine' block that Config_RestoreGlobals fans out to live globals. |
| `0x00543a6c`  | (payload @ buffer + 0x144)           | Start of the 5-dword 'audio per-channel state' block. |
| `0x00543a24..0x00543a68` | (payload tail)            | ~18 individual slot mirrors for FSM state, joystick selection, input bindings. |
| `0x00543f7c`  | `g_configInitGate_00543f7c`          | Gate flag #1: set on first successful snapshot. While 0, Config_SnapshotGlobals bails. (Renamed from `g_audioRestoreSlot_00543f7c` - only ~20 of the ~80 snapshotted slots are audio-related, so the original name was misleading.) |
| `0x00543f78`  | `g_validInstall` / `g_installValidated` | 1 if the registry load succeeded (or defaults were applied). Read by Config_SaveToRegistry as 'do we have something to save?'. |
| `0x004d2000`  | IAT: `RegCreateKeyExA`               |  |
| `0x004d2004`  | IAT: `RegCloseKey`                   |  |
| `0x004d2008`  | IAT: `RegQueryValueExA`              |  |
| `0x004d200c`  | IAT: `RegOpenKeyExA`                 |  |
| `0x004d2010`  | IAT: `RegSetValueExA`                |  |

## Registry surface

```
HKLM\Software\GT Interactive\Mortal Kombat 4\1.00\
    Path     REG_SZ      install directory (chdir target at boot; not in Config)
    Config   REG_BINARY  588 bytes:
                          [0..3]    stored hash (= ComputeConfigHash() of bytes [4..583], OR 0xFFFFFFFF)
                          [4..583]  XOR-obfuscated settings payload
                          [584..587] tail (zero-filled, exact role TBD)
```

Same key is read by ValidateInstall (with `KEY_QUERY = 0x20019`) and
written by Config_SaveToRegistry (with `KEY_ALL_ACCESS = 0x20006`).

The 32-bit installer registers under `Wow6432Node` on a 64-bit Wine
prefix - see [install.md](install.md) for the runtime-testing path.

## Callers

| Path | Function calling | Subsystem |
|------|------------------|-----------|
| Boot init #3 | `ValidateInstall` <- `AppInit` (entry 3, see [architecture.md](architecture.md)) | load path |
| Live apply | `Config_RestoreGlobals` <- multiple options/audio paths | runtime |
| Shutdown | `Config_SaveToRegistry` <- `AppShutdown` (0x004b2690) | save path |

## TODOs

- **`g_configInitGate_00543f7c`** is the config-init gate, not an
  'audio restore slot'. Belongs in a globals rename pass.
- **Buffer tail (bytes 584..587)** - 4 bytes at the very end of the
  588-byte blob. ResetConfigToDefaults zeros them; nothing else reads
  them. Possibly a tombstone or version stamp left for forward-compat.
- **`Helper_ValidateA` / `Helper_ValidateB`** are stubs at
  `0x004ad20e` / `0x004ad24e` - 2 bytes before `ComputeConfigHash` /
  `DeobfuscateConfig`. They are 'overlapping entry-points': calling
  one falls through into the next. Their byte content is two extra
  prologue instructions that the load path uses to pass the buffer
  base implicitly. Currently emitted as empty stubs in `src/stubs.c`
  to satisfy the linker - they could be folded into the source of
  the parent functions for clarity.
- **Exact slot list in `Config_SnapshotGlobals`** - the 18 individual
  globals copied after the two rep movsd blocks are documented inline
  in the asm but not yet annotated with what each one means in-game
  (e.g. 'difficulty', 'time-limit', 'blood toggle'). A controls-config
  smoke test (change one option, save, hexdump the registry value)
  would map slot-> setting quickly.
- **Why is there no per-player save?** The lack of a save file is
  consistent with MK4 being an arcade-port-first design - no campaign,
  no persistent unlocks. Settings only.
- **No network multiplayer** - MK4 imports zero socket APIs
  (`WSOCK32`, `WS2_32`, etc are absent from the IAT). The
  `network` subsystem listed in some earlier briefings does not
  exist in this binary. LAN/modem play was never implemented for
  this port.
