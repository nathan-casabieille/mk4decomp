# Install + asset I/O subsystem

Per-subsystem deep dive for MK4's install validation, the FSYS asset
archive, and the per-format loaders (ESF, ECM, GEO). This is the
bridge between the disk and the engine; everything the game plays
flows through here.

For the on-disk binary formats themselves see [architecture.md](architecture.md)
sections "FILESYS.DAT format", "ESF audio format", "ECM cinematic format",
"GEO format". This doc covers the in-engine plumbing.


## Boot-time validation chain

`AppInit` ([src/boot/app_init.c:23](../../src/boot/app_init.c#L23))
runs a multi-stage check before the engine touches any asset:

```c
Timer_Init();
Joystick_Init();
ValidateInstall();         /* 0x004ad270 - the gate */
AppInit_PostJoy();
AppInit_PreInstall();      /* 0x004b1cf0 = FSYS_Init() */
Gfx_Init(g_appInitHwnd);
AuxAudio_Init(g_appInitHwnd);
...
```

The gate is **3-stage** with the result cached in `g_validInstall`:

```
ValidateInstall (0x004ad270)
  ├── stage 1: CheckInstallPath()  -> registry lookup + chdir
  │              on failure: ShowErrorMessage("\x15") (= short msg), set g_validInstall=0
  │
  ├── stage 2: GetModuleFileName + Helper_SplitPath + GetDriveTypeA
  │              on non-FIXED drive: bail (user-relocatable install rejected)
  │
  └── stage 3: RegOpenKeyEx + RegQueryValueEx on the "Config" value
                 cross-check 588-byte expected size + ComputeConfigHash
                 on mismatch: bail with -10
```

If any stage fails, `g_validInstall` stays 0 and the game refuses to
load any asset. Cached result skips re-validation on subsequent calls.

Once `ValidateInstall` succeeds, **the current working directory is
the install dir** (set by `CheckInstallPath`), and the engine can
look for assets via relative paths.


## Stage 1 - CheckInstallPath (0x004acc50)

Pure C ([src/audio/install_path.c](../../src/audio/install_path.c)):

```c
s32 CheckInstallPath(void) {
    HKEY  hkey = NULL;
    DWORD cbData = 1024;

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE,
                      "Software\\GT Interactive\\Mortal Kombat 4\\1.00",
                      0, KEY_READ, &hkey) != 0) return 0;

    if (RegQueryValueExA(hkey, "Path", 0, NULL,
                         (BYTE *)g_installPath, &cbData) != 0) return 0;
    RegCloseKey(hkey);
    return SetCurrentDirectoryA(g_installPath) != 0 ? 1 : 0;
}
```

The registry footprint is **tiny**:

| Key                                                       | Value | Type | Content                  |
|-----------------------------------------------------------|-------|------|--------------------------|
| `HKLM\Software\GT Interactive\Mortal Kombat 4\1.00`       | `Path`| REG_SZ| Install directory       |
| (same key)                                                | `Config`| REG_BINARY | 588-byte settings blob |

This is the **only place** MK4 looks to find its install directory.

On wine64 / Whisky, the key lives under `Wow6432Node`:
`HKLM\SOFTWARE\Wow6432Node\GT Interactive\Mortal Kombat 4\1.00`.

Failure leaks the `HKEY` on the `RegQueryValueExA` path - this is
faithful to the original (matching decomp); fixing the leak would
change byte output.

`g_installPath[1024]` at `0x00543b78` is where the registry value
lands before `SetCurrentDirectoryA` chdirs into it.


## Stage 2 - drive type check

`ValidateInstall` `0x004ad270` (still naked - dual rep-scasb/rep-movsd
path concat). Logic:

1. `GetModuleFileNameA` to recover the EXE's full path.
2. `Helper_SplitPath` (CRT `_splitpath`) to break it into drive +
   dir + name + ext.
3. Build a "drive root" string ("X:\\") and call `GetDriveTypeA`.
4. Bail unless the result is `DRIVE_FIXED` (= 3).

This **rejects CD-ROM, removable, and network installs**. The game
will not run from a USB stick or a SMB share. For modern porting
this check is the first thing you'd want to neutralize - it makes
no sense in a 2026 environment.

For Whisky / dgVoodoo2 the bottle's C: drive maps to a Mac directory
that already shows as `DRIVE_FIXED` - so the check passes
transparently.


## Stage 3 - Config blob check

`ValidateInstall`'s final stage does a second `RegOpenKeyEx` on the
same key, reads the `Config` value (588 bytes of registry-stored
settings) into `g_configBuffer`, validates:

- Reported size == 588 bytes exactly.
- `ComputeConfigHash` ([src/platform/install.c](../../src/platform/install.c))
  matches a stored checksum.
- `Helper_ValidateA` / `Helper_ValidateB` (`0x004ad20e` / `0x004ad24e`)
  do further structural checks.

If anything mismatches, the Config buffer is reset to defaults via
`ResetConfigToDefaults` ([src/audio/reset_config.c](../../src/audio/reset_config.c)) -
this is the **fallback path** that gives a fresh install consistent
defaults even if the registry is corrupted.

`ComputeConfigHash` ([src/platform/install.c](../../src/platform/install.c)):

```c
s32 ComputeConfigHash(void) {
    s32 hash = 0x43464729;             /* "GFCB" little-endian = Eurocom magic */
    for (i = 4; i < 0x248; i++)
        hash += (s32)(signed char)g_configBuffer[i] << (i % 23);
    return hash;
}
```

Plus an XOR-stream deobfuscation step (`DeobfuscateConfig`) XORs each
byte with `(i * 0x7b) & 0xff` - so the registry blob is stored
lightly obfuscated.


## EXE integrity check - the second gate

A separate integrity check fires at **audio init time**:

```
GetExeDirectory (0x004aca60)
  ├── GetModuleFileNameA(NULL, path, 1024)
  ├── Helper_ComputeExeHash(path)
  └── compare g_exeIntegrityValueA/B against g_exeIntegrityRefA/B
        on mismatch: return -10
```

`Helper_ComputeExeHash` (`0x004acae0`, naked) `fopen("rb")`s the
running EXE, reads it in 0x4010-byte chunks, and accumulates a
64-bit running sum (`g_exeIntegrityValueA/B`) of every dword that
isn't the **marker** (`g_exeIntegrityRefA/B`).

When the marker is found, its position is stashed in
`g_exeIntegrityFoundPos`. Finding it **twice** is treated as
tampering and returns -5.

Important quirks:
- The fseek calls use deliberately invalid whence values (-16 / esi+8).
  This is a **deliberate anti-tamper** trick - the original ignores the
  failure return because it doesn't actually want overlap; the scan
  walks the file as consecutive non-overlapping chunks. A naive
  reverse-engineer might "fix" the fseek and break the protection.
- The expected hash constants `g_exeIntegrityRefA/B` live at
  `0x004f4690..0x004f4694` - 8 bytes baked into .rdata. If you
  modify the EXE, the constants need updating; otherwise the audio
  layer refuses to come up.

For the matching rebuild, the EXE bytes are identical to the
shipping binary, so the integrity check passes naturally.

| Symbol                  | Address       | Role                                       |
|-------------------------|---------------|--------------------------------------------|
| `g_exeIntegrityValueA`  | `0x00543920`  | Computed lo (running sum)                  |
| `g_exeIntegrityValueB`  | `0x00543924`  | Computed hi                                |
| `g_exeIntegrityRefA`    | `0x004f4690`  | Expected lo (compile-time constant)        |
| `g_exeIntegrityRefB`    | `0x004f4694`  | Expected hi                                |
| `g_exeIntegrityFoundPos`| `0x00543918`  | File pos where marker was found            |


## FSYS - the asset archive

After install validation, `FSYS_Init` (`0x004b1cf0`) opens the bulk
asset archive `filesys.dat` (24,099,408 bytes shipped) and loads its
header table.

### On-disk layout

```
0x0000   ┌──────────────────────────────────────────┐
         │ Header (0x3000 bytes = 12 KB)            │
         │   array of fsys_entry, max 1024 entries  │
         │   struct fsys_entry {                    │
         │       u32 hash_or_id;   /* sort key */   │
         │       u32 offset;       /* payload pos */│
         │       u32 size;         /* payload sz */ │
         │   };                                      │
         │   terminated by entry with hash == 0     │
0x3000   ├──────────────────────────────────────────┤
         │ Payload data                             │
         │   addressed by entry.offset (absolute    │
         │   from file start, not relative to       │
         │   end-of-header)                          │
         └──────────────────────────────────────────┘
```

Entries are **sorted ascending by hash**. `FSYS_Init` validates the
sort order; if violated, it `ShowErrorMessage("FSYS_Init(3)")` fatal.

### In-memory state

| Symbol                        | Address       | Role                                |
|-------------------------------|---------------|-------------------------------------|
| `g_fsys_entries[1024]`        | `0x007ab0d8`  | In-memory copy of header table      |
| `g_fsys_entry_count`          | `0x007af4e4`  | Populated entry count               |
| `g_fsys_archive`              | `0x007af4e0`  | CRT FILE* for filesys.dat           |
| `g_fsys_files[0x401]`         | `0x007ae0dc`  | Per-handle slot state (current read offset, -1 = free) |
| `g_fsys_normalized_path[1024]`| `0x007af0e0`  | Static scratch for `FSYS_NormalizePath` |
| `g_fsys_lastSeekFh`           | `0x004f4a50`  | Cache of last fseek'd handle        |

### Init failure modes

| Message       | Cause                                                  |
|---------------|--------------------------------------------------------|
| `FSYS_Init(1)`| fopen failed (filesys.dat missing or unreadable)       |
| `FSYS_Init(2)`| fread failed (truncated header)                        |
| `FSYS_Init(3)`| Sort-order violation (header corrupt or tampered)      |

All are `ShowErrorMessage` calls - the user sees a popup and the
process exits.


## FSYS public API

### Path normalization + hash

`FSYS_NormalizePath` (`0x004b1ec0`) uppercases ASCII a-z to A-Z,
writes the result into `g_fsys_normalized_path`, and validates that
the path begins with a drive letter (`X:\...`). Empty or NULL path
returns NULL. Missing drive prefix triggers
`ShowErrorMessage("Partial filename")` fatal.

So **all asset names in the hash table are full dev-machine paths**,
e.g. `C:\SOURCE\MK4\WIN\GEOGFX\MENU.GEO`. The game still works on
your machine because:
- The registry's `Path` value chdirs into the install root.
- The asset's filename in the FSYS header is a full path string
  that was hashed at archive build time.
- At runtime, the game passes paths that match the same dev-machine
  format - whether or not your install dir has the same structure
  is irrelevant because the lookup is by hash, not by path resolution.

`FSYS_HashName` (`0x004b1f50`) - decoded:

```python
def fsys_hash(path):
    upper = path.upper()
    h, shift = 0, 0
    for ch in upper:
        b = ord(ch)
        if b >= 0x80: b -= 0x100        # signed-char extension
        h = (h + (b << shift)) & 0xFFFFFFFF
        shift = (shift + 8) if shift < 24 else 0
    return (h + len(upper)) & 0xFFFFFFFF
```

Each character contributes at one of 4 byte positions (0, 8, 16, 24),
cycling every 4 chars. Final result = sum + length.

Implementation in [tools/fsys_hash.py](../../tools/fsys_hash.py).

### fopen / fread / fseek / ftell / fclose

The five wrappers:

```c
int  FSYS_fopen(const char *path, const char *mode);    /* 0x004b1e00 */
int  FSYS_fread(void *buf, u32 size, u32 count, int fh);/* 0x004b1fb0 */
int  FSYS_fseek(int fh, u32 off, int whence);           /* 0x004b2070 */
int  FSYS_ftell(int fh);                                /* 0x004b2100 */
int  FSYS_fclose(int fh);                               /* 0x004b1f90 */
```

`FSYS_fopen`:
1. `FSYS_NormalizePath(path)` -> uppercased copy in static buffer.
2. `FSYS_HashName(normalized)` -> 32-bit hash.
3. Binary search `g_fsys_entries[0..g_fsys_entry_count]` by hash.
4. If entry not found, `ShowErrorMessage("FSYS_fopen(\"%s\")")` fatal.
5. Mark the slot as in-use, return `idx + 1` as the file handle
   (1-based; 0 means "closed").

`FSYS_fread` skips its initial fseek if `g_fsys_lastSeekFh == fh`
(common case when reading sequentially). On any other handle, it
seeks first to the entry's `offset + per_handle_pos`.

`FSYS_fseek` updates the per-handle position counter
(`g_fsys_files[fh]`) without an actual disk seek - that happens
inside `FSYS_fread` when needed.

`FSYS_ftell` returns the cached position. Out-of-range handle returns -1.

`FSYS_fclose` resets the handle slot.

There's also a convenience:

```c
void FSYS_fload(const char *path, void *buf, u32 size);  /* 0x004b2160 */
u32  FSYS_fsize(const char *path);                       /* 0x004b2120 */
```

`fload` does open + read + close in one call (reports
`FSYS_fload()` on read-size mismatch). `fsize` returns the entry's
`size` field without opening the file.

### Asset name discovery

From `strings -n 4 MK4.EXE`, four path patterns were found:
- `c:\source\mk4\win\menu.tga` (single asset)
- `c:\source\mk4\win\anim\` (directory prefix)
- `c:\source\mk4\win\geogfx\%s` (printf format used by `LoadGeoAsset_Textures`)
- `c:\source\mk4\win\sound\pcmk%04ld.esf` (numbered SFX files)

Plus 128 explicit filenames in the strings table. The full set of
hashes can be reconstructed by hashing each known filename via
`tools/fsys_hash.py` and looking up the matching FSYS entries.


## ESF loader - the SFX/voice format

ESF = Eurocom Sound Format. Per-file 8-byte header, payload is
either raw 8-bit unsigned PCM or 16-bit IMA ADPCM.

```c
struct esf_header {
    u32 magic;          /* "ESF\x06" = 0x06465345 */
    u32 format_word;
    /*  bits 0..28 : decoded byte count
        bit 29     : 16-bit IMA ADPCM (vs 8-bit raw PCM)
        bit 30     : 22050 Hz (vs 11025 Hz)
        bit 31     : stereo (vs mono)              */
};
```

### Entry points

| Function          | Address      | Role                                  |
|-------------------|--------------|---------------------------------------|
| `ESF_Open`        | `0x004b1090` | Open + parse header, return decoded size |
| `ESF_ReadData`    | `0x004b1150` | Read payload (decode ADPCM in place if needed) |
| `ESF_Close`       | `0x004b1200` | Close FSYS handle                     |
| `ESF_DecodeADPCM` | `0x004ac200` | MS-IMA decoder (used by ESF + ECM)    |

`ESF_Open` calls `FSYS_fopen` then `FSYS_fread` for the 8 header bytes,
validates the magic, and writes the decoded `bits/rate/channels` to
the caller's out args. State for the open file is in three globals:

| Symbol         | Address      | Role                                       |
|----------------|--------------|--------------------------------------------|
| `g_esf_magic`  | `0x007ab088` | Magic word from header[0..3]               |
| `g_esf_state`  | `0x007ab08c` | Packed format word from header[4..7]       |
| `g_esf_handle` | `0x007ab090` | FSYS handle id (0 = closed)                |

Note: only **one ESF file open at a time**. The engine reads each
SFX into a malloc'd buffer immediately, then closes. The handle is
not held across frames.

### ADPCM decoder

Textbook MS-IMA decoder (see [audio.md](audio.md) and
[architecture.md](architecture.md) for the bit-level spec). The
state argument is a packed 32-bit `(predictor << 8) | step_index`.
LUTs:

| Symbol             | Address     | Size | Content                            |
|--------------------|-------------|------|------------------------------------|
| `g_imaIndexTable`  | `0x004f44e0`| 64   | `[-1,-1,-1,-1, 2,4,6,8] x 2`       |
| `g_imaStepTable`   | `0x004f4520`| 356  | 89 step sizes from 7 to 32767      |


## ECM loader - the cinematic format

ECM = Eurocom Custom Movie. Used for the 16 character bios
(`B_*.ECM`), 15 endings (`E_*.ECM`), and 4 large cinematics
(`m_intro.ecm`, `m_midway.ecm`, `m_euro.ecm`, `m_komerc.ecm`).

### On-disk layout

```
0x0000   ┌──────────────────────────────────┐
         │ Header (3608 bytes / 0x0e18)     │
         │   magic[4]    = "ECM\x02"        │
         │   frame_count : u32              │
         │   group_offs[]: 900 x s32        │  size of each group
0x0e18   ├──────────────────────────────────┤
         │ Frame data, sequential groups,   │
         │ each starting with "SEC\0"       │
         │ magic. Each group encodes 15     │
         │ frames + 1 second of audio.      │
         └──────────────────────────────────┘
```

### Entry points

| Function              | Address      | Role                                  |
|-----------------------|--------------|---------------------------------------|
| `ECM_Open`            | `0x004b06f0` | Open file, parse header, spawn play thread |
| `ECM_Cleanup`         | `0x004b0cb0` | Stop thread, release DSound buffer, close |
| `ECM_PlayThread`      | `0x004b0a50` | Background streaming worker           |
| `ECM_DecodeFrame`     | `0x004b1c90` | Setup parse state, dispatch decode    |
| `ECM_DecodeFrameDispatch`| `0x004b1bf0`| Parse "EDL" header, dispatch by mode |
| `ECM_ParseFrameHeader`| `0x004b1c30` | Magic + mode + sizes parse            |
| `ECM_DecodeFrame_Raw` | `0x004b1220` | Mode 0: memmove                        |
| `ECM_DecodeFrame_Huffman`| `0x004b1270`| Mode 1: Huffman entropy decoder      |

### Per-frame parse state

```c
typedef struct ecm_state {     /* 32 bytes */
    void *dst;         /* +0x00 destination buffer */
    u8   *buffer;      /* +0x04 source bitstream */
    s32   offset_a;    /* +0x08 copied from buffer[4..7] */
    s32   offset_b;    /* +0x0c decoded byte count (buffer[8..11]) */
    s32   mode;        /* +0x10 0=raw, 1=huffman, else=skip */
    u32   _14;         /* +0x14 zero-init scratch */
    s32   flag;        /* +0x18 high bit of magic byte 3 */
    s32   status;      /* +0x1c 0=ok, -3=bad magic, -4=bad mode */
} ecm_state;
```

### Playback architecture - threaded

ECM is **the only threading in MK4**:

```
ECM_Open
  ├── FSYS_fopen + read header
  ├── allocate DirectSound secondary buffer
  │     (44100 Hz mono 16-bit, 4-slot ring = 4 seconds)
  ├── seek past skipped groups (sum group_offs[0..frame_skip/15])
  ├── CreateThread(ECM_PlayThread)
  │
  └── ECM_PlayThread runs in background:
        for each group:
          ├── decode IMA ADPCM (1 second of audio)
          ├── Lock(slot = (frame_idx+1) & 3)
          ├── memcpy decoded audio
          ├── Unlock
          ├── decode + dispatch 15 video frames
          └── SuspendThread (yield)
        on DSERR_BUFFERLOST: Restore + Stop + re-Lock + zero-fill + Unlock
```

The 4-slot DSound buffer ring is treated as classic **streaming PCM**:
write to the next slot just before the playback cursor catches up.

### Video codec - the unresolved part

Each per-frame has a 12-byte sub-header (`"EDL"` magic + mode + size +
extra), followed by `frame_size` bytes:

| Mode | Decoder                       | Notes                                  |
|------|-------------------------------|----------------------------------------|
| 0    | `ECM_DecodeFrame_Raw`         | `memmove(dst, src+12, frame_size)`     |
| 1    | `ECM_DecodeFrame_Huffman`     | ~2400 bytes of carefully reversed asm |

Mode 1 is a textbook Huffman/entropy decoder:
- Reads a bitstream from the encoded data.
- Builds a 16-symbol frequency table on the stack (32 bytes).
- Sorts symbols by frequency, builds a prefix-code table.
- Decodes `frame_size` bytes one symbol at a time.

Full bit-by-bit spec is left for a future round. For practical
porting, **replacing the ECM playback with a modern video container
(.webm / .mp4) is far simpler than re-implementing the codec** -
re-encoding the 16 cinematics from frame captures is a one-time job;
preserving the codec is recurring maintenance.


## GEO loader - meshes + textures

GEO is the per-character + per-stage geometry container. Loaded
through `LoadGeoAsset_Textures` (`0x004bd6e0`, naked) and friends.

The load path:

```
LoadGeoAsset_Textures(flag)
  ├── Helper_GeoLoadPre()
  │     (calls func_00444c98(4) + func_00444c98(2) - palette pre-init)
  ├── sprintf(g_geoAssetPath, "c:\\source\\mk4\\win\\geogfx\\%s", name)
  ├── FSYS_fsize(g_geoAssetPath)
  ├── (allocate buffer of that size)
  ├── FSYS_fload(g_geoAssetPath, buffer, size)
  └── (parse + bind textures into the scenegraph node)
```

The path prefix `c:\source\mk4\win\geogfx\` is the dev-machine
location at build time; it's hashed into the FSYS table.

For the .geo format itself - block header table, vertex/face streams,
triangle-strip encoding, BAM angles - see [scenegraph.md](scenegraph.md)
and [architecture.md](architecture.md).

| Symbol            | Address     | Role                                       |
|-------------------|-------------|--------------------------------------------|
| `g_geoAssetPath`  | (TBD)       | sprintf scratch for the .geo filename      |


## Globals reference

### Registry + install path

| Symbol              | Address       | Role                                  |
|---------------------|---------------|---------------------------------------|
| `g_installPath[1024]`| `0x00543b78` | Registry-resolved install dir         |
| `g_validInstall`    | `0x00543f78`  | Cached ValidateInstall result         |
| `g_configBuffer[588]`| `0x00543928` | Registry-stored config blob           |
| `g_configChecksum`  | `0x0054392c`  | Per-load validation counter           |
| `g_resetCfgDefaults[26]`| `0x004f46a0` | Compile-time config defaults       |
| `g_resetCfgRegion[58]` | `0x00543a84` | Live config region                  |

### EXE integrity

| Symbol                  | Address       | Role                                  |
|-------------------------|---------------|---------------------------------------|
| `g_exeIntegrityValueA`  | `0x00543920`  | Computed lo half of running sum       |
| `g_exeIntegrityValueB`  | `0x00543924`  | Computed hi half                      |
| `g_exeIntegrityRefA`    | `0x004f4690`  | Expected lo (.rdata constant)         |
| `g_exeIntegrityRefB`    | `0x004f4694`  | Expected hi                           |
| `g_exeIntegrityFoundPos`| `0x00543918`  | File pos where marker was found       |

### FSYS state

| Symbol                       | Address       | Role                              |
|------------------------------|---------------|-----------------------------------|
| `g_fsys_entries[1024]`       | `0x007ab0d8`  | In-memory header table            |
| `g_fsys_entry_count`         | `0x007af4e4`  | Populated entry count             |
| `g_fsys_archive`             | `0x007af4e0`  | CRT FILE* for filesys.dat         |
| `g_fsys_files[0x401]`        | `0x007ae0dc`  | Per-handle position cache         |
| `g_fsys_normalized_path[1024]`| `0x007af0e0` | Path uppercase scratch            |
| `g_fsys_lastSeekFh`          | `0x004f4a50`  | Cache for skipping redundant seek |

### ESF state

| Symbol                  | Address       | Role                                  |
|-------------------------|---------------|---------------------------------------|
| `g_esf_magic`           | `0x007ab088`  | Header[0..3]                          |
| `g_esf_state`           | `0x007ab08c`  | Header[4..7] format word              |
| `g_esf_handle`          | `0x007ab090`  | FSYS handle id (0 = closed)           |
| `g_imaIndexTable[16]`   | `0x004f44e0`  | MS-IMA index deltas                   |
| `g_imaStepTable[89]`    | `0x004f4520`  | MS-IMA step sizes                     |

### ECM state

| Symbol                      | Address     | Role                                |
|-----------------------------|-------------|-------------------------------------|
| `g_ecmHeaderBuf[3608]`      | (TBD)       | In-memory copy of ECM header        |
| `g_ecmPlayState`            | (TBD)       | Worker thread alive flag            |
| `g_ecmThreadStatus`         | (TBD)       | Yield/resume coordination           |
| `g_iat_SuspendThread`       | `0x004d2090`| Cached IAT slot for self-suspend    |


## What's safe to change vs not

**Safe**:
- Replacing `CheckInstallPath` with a non-registry lookup (env var,
  config file, sibling-binary auto-detect). Pure C, single-file edit -
  see "Where to start" below.
- Removing the `GetDriveTypeA` fixed-disk requirement. Edit
  `ValidateInstall`'s drive check (currently still naked).
- Adding new file formats handled by `FSYS_fopen`. Path is hashed,
  so new files just need to be present in `filesys.dat` with their
  hash registered.
- Caching FSYS reads in a separate in-memory dict. Layer above
  `FSYS_fopen` without modifying it.

**Unsafe**:
- Changing the FSYS header size (`0x3000`). Hardcoded as the
  payload start offset; affects every `entry.offset` value in the
  shipped `filesys.dat`.
- Modifying the FSYS hash function. Every entry in `filesys.dat` is
  pre-hashed at archive build time; changing the hash invalidates
  the entire archive.
- Reordering `g_fsys_entries` columns (hash / offset / size). The
  binary search code reads at fixed byte offsets within the
  12-byte stride.
- Changing the EXE integrity constants `g_exeIntegrityRefA/B`
  without also updating the marker placement and the
  ComputeExeHash logic. The check pre-validates the binary's bytes;
  any modification to the EXE that touches non-marker dwords will
  change the running sum.
- Reordering the registry-stored Config blob (588 bytes laid out
  in a specific way that `ResetConfigToDefaults` matches).


## What's still naked vs pure C

In `src/audio/`:

- **Pure C**:
  `CheckInstallPath`, `GetExeDirectory`, `AuxAudio_SetVolume`,
  `ComputeConfigHash`, `DeobfuscateConfig`.

- **Still naked**:
  `ValidateInstall` - dual rep-scasb/rep-movsd path concat for
  GetDriveType pre-call.
  `Helper_ComputeExeHash` - chunked scan with invalid-fseek
  anti-tamper.
  `ResetConfigToDefaults` - interleaved 26-dword struct copy.

In `src/engine/`:

- **Pure C**:
  `FSYS_ftell`, `FSYS_fclose`, `FSYS_Init` (partial, in
  [src/engine/fsys.c](../../src/engine/fsys.c)).

- **Still naked**:
  `FSYS_NormalizePath` - byte spill / partial-register-stall
  workaround MSVC SP3 won't reproduce.
  `FSYS_HashName` - position-shifted byte folding with sign
  extension; pure C diverges by 2-3 bytes.
  `FSYS_fopen` - binary search + handle-slot allocation.
  `FSYS_fread` / `FSYS_fseek` - position-cache logic.
  `ESF_Open` - 8-byte read + magic check + format-bit extraction
  via neg/sbb idioms.
  `ESF_DecodeADPCM` - sete-toggle nibble alternation +
  edi-threaded predictor.
  `ECM_Open` - SEH-style stack-built struct + COM-vtable + FP
  volume curve.
  `ECM_PlayThread` - threaded loop with self-suspend + magic-divide
  + IDirectSoundBuffer ops.


## Where to start when modifying

### Replace registry with config file

The cleanest porting path. Edit
[src/audio/install_path.c](../../src/audio/install_path.c):

```c
s32 CheckInstallPath(void) {
    /* Read MK4_INSTALL_PATH env var; fall back to CWD. */
    const char *p = getenv("MK4_INSTALL_PATH");
    if (p != NULL) {
        strcpy(g_installPath, p);
    } else if (getcwd(g_installPath, 1024) == NULL) {
        return 0;
    }
    return SetCurrentDirectoryA(g_installPath) != 0 ? 1 : 0;
}
```

This breaks the byte match (the registry-call sequence is gone), so
gate it behind `#ifdef PORTABLE_BUILD`.

### Disable the fixed-disk requirement

`ValidateInstall`'s drive type check is in the still-naked body.
The simplest neutralization is to early-return success after
`CheckInstallPath`:

```c
s32 ValidateInstall(void) {
    if (g_validInstall != 0) return 1;
    if (CheckInstallPath() == 0) return 0;
    g_validInstall = 1;
    return 1;
}
```

Again, gate behind `#ifdef PORTABLE_BUILD`.

### Disable the EXE integrity check

`GetExeDirectory` is pure C - the do-while-0 + break pattern
makes the success-tail second. Substitute:

```c
s32 GetExeDirectory(void) {
    /* Always succeed - integrity bypass for ports. */
    return 0;
}
```

### Replace FSYS with a directory-walking loader

Decompose `FSYS_fopen` into a path-hash lookup that falls back to a
filesystem read if the hash isn't in the archive. Useful for
modding: drop a replacement asset in a sibling directory and the
game picks it up without touching `filesys.dat`.

The hook point is `FSYS_fopen` (still naked) - wrap it with a C
pre-check:

```c
int FSYS_fopen_modded(const char *path, const char *mode) {
    char modpath[1024];
    snprintf(modpath, sizeof(modpath), "mods/%s", basename(path));
    FILE *f = fopen(modpath, mode);
    if (f != NULL) return /* a synthetic handle id */;
    return FSYS_fopen(path, mode);   /* fall through to archive */
}
```

Each `FSYS_*` API call site would need to be redirected to the
`_modded` variant. Breaks byte match - flag as `#ifdef MOD_SUPPORT`.

### Replace ECM playback with a modern video container

Hook `ECM_Open` / `ECM_PlayThread` / `ECM_Cleanup`. The function
signatures stay; just substitute the body. For each `m_*.ecm`,
provide a corresponding `m_*.webm` (re-encoded from frame captures)
and call into ffmpeg/libavformat instead of the Huffman codec. The
DirectSound buffer ring can be reused unchanged - feed it the
decoded audio from the new container.

This is **the highest-ROI port task**: it eliminates the 2400-byte
unresolved Huffman codec, lets you ship modern video with
sharpening/anti-aliasing, and the game has no idea you've changed
the format.
