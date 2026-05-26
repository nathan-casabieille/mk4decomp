# Audio subsystem

This is the per-subsystem deep dive for the audio code in MK4.EXE.
It explains how the pieces fit together so a contributor can modify
the subsystem without breaking the byte-identical rebuild.

For the binary formats themselves (ESF + ECM) see the corresponding
sections in [architecture.md](architecture.md) - this document covers
the in-engine plumbing.


## Three independent audio paths

MK4 uses three Windows audio APIs simultaneously, each driving a
different layer of the soundscape:

| Path                | Windows API              | Used for                                     | Hot entry point          |
|---------------------|--------------------------|----------------------------------------------|--------------------------|
| **DirectSound**     | `DSOUND.DLL`             | All in-game SFX + voice clips + ECM audio    | `DSound_Init` `0x004c3ef0` |
| **MCI**             | `WINMM.DLL` mciSendCommandA | CD-DA / MIDI background music             | `Audio_TimerSet` `0x004ac650` |
| **AuxOut master**   | `WINMM.DLL` aux*         | Hardware master-volume across all aux devs   | `AuxAudio_Init` `0x004ac8f0` |

The complete IAT footprint (from `config/iat_map.yaml`):

```
DSOUND.DLL: DirectSoundCreate
WINMM.DLL:  mciSendCommandA, timeGetTime, timeBeginPeriod,
            timeEndPeriod, auxGetNumDevs, auxGetDevCapsA,
            auxGetVolume, auxSetVolume
            (also joyGetDevCapsA / joyGetPos / joyGetPosEx,
             shared with input handling)
```

That is the entire audio surface. There is no `DirectMusic`, no
`waveOut`, no `midiOut` direct use - MIDI/CD music goes through MCI.


## Init sequence

Called from `AppInit` ([src/boot/app_init.c:23](../../src/boot/app_init.c#L23)):

```c
AuxAudio_Init(hwnd);                          // 0x004ac8f0
AuxAudio_SetMasterVol(g_audioMasterVol & 0xff); // 0x004ac9c0
DSound_Init(hwnd);                            // 0x004c3ef0
AppInit_AudioPostInit(g_audioPostFlag);       // 0x004c3eb0 (== Helper_TitleSetMaxVolume)
AppInit_PostDSound();                         // 0x004b21b0 (1-byte clear of g_byte_007af508)
```

`AuxAudio_Init`:
- Zero-clears 10 timer/MCI globals (`g_timerActive`, `g_timerStartSec`,
  `g_timerEndSec`, `g_timerHandle`, `g_timerLastNow`, `g_timerFlag`,
  `g_audioState00`, `g_audioState08`, `g_audioState0C`, `g_audioPreState`).
- Calls `auxGetNumDevs`, then for each device 0..n calls
  `auxGetDevCapsA` and `auxGetVolume`, populating `g_auxChannels[]`
  and recording `g_auxCount`.

`AuxAudio_SetMasterVol(vol)`:
- Clamps `vol` to `[0, 100]`, packs it as `vol * 0x028F028F`
  (= 0xFFFF/100 in each 16-bit half), then `auxSetVolume`s every
  active aux device. This is the only knob that adjusts the overall
  hardware mixer.

`DSound_Init`:
- Builds a 256x100-row **volume-curve table** (each cell three int16s:
  left gain, right gain, signed-dB delta). The inner loop is a fixed
  FP sequence (`fld/fmul/fcom/fnstsw/fchs/fyl2x/fstp`) plus three
  `_ftol` calls per cell. This is the per-channel pan + attenuation
  lookup used at every `Helper_DSI_post1` / `Helper_DSI_post2` call.
- Zero-clears `g_dsoundScratch[]` (0x3c28 dwords starting at
  `0x00f8fac8` - this is the **same memory** as `g_audioChannelTable`,
  see "Per-channel state" below).
- Calls `DirectSoundCreate` -> `g_dsoundContext`. On failure returns 0
  and the game continues silent.
- Builds a `DSBUFFERDESC` for the primary buffer, calls
  `IDirectSound::CreateSoundBuffer` -> `g_dsoundPrimary`.

`AppInit_AudioPostInit` and `AppInit_PostDSound` are tiny one-byte
state updaters; they are the same symbol as `Helper_TitleSetMaxVolume`
(reused from two call sites at different abstraction levels).


## Per-frame tick loop

`GameLogicStep` ([analysis/notes/architecture.md](architecture.md))
makes three audio-related calls per game tick:

| Order | Function              | Address      | Role                                          |
|-------|-----------------------|--------------|-----------------------------------------------|
| 1     | `Audio_TimerTick`     | `0x004ac4b0` | MCI music timer - fires `Audio_TimerSet` when scheduled |
| 2     | `Audio_UpdateChannels`| `0x004c37f0` | DSound channel sweep - reaps finished sounds |
| 3     | `UpdateWindowTitle`   | `0x004b22e0` | (also touches audio state during title-bar updates) |

### Audio_TimerTick

Pure C ([src/audio/timer.c](../../src/audio/timer.c)):

```c
void Audio_TimerTick(void) {
    if (g_timerActive == 0) return;
    if (timeGetTime() - g_timerLastNow <
        (g_timerEndSec - g_timerStartSec) * 1000) return;
    g_timerFlag = 0;
    Audio_TimerSet(g_timerActive, g_timerHandle,
                   g_timerEndSec, g_timerHandle);
}
```

The threshold is `(end - start) * 1000` ms, computed via the
`5*5*5*8 = 1000` `lea`/`shl` chain MSVC pattern-matches on.

### Audio_TimerSet / Audio_TimerTeardown

Drives MCI music playback (CD-DA tracks or .MID files via the MCI
device handle in `g_timerHandle`). The set path builds an MCI
`PLAY` packet using `mciSendCommandA` (`0x806`) plus a `SET` packet
(`0x80d`) converting `esi`/`edi` second values to TMSF format via
the `0x88888889` reciprocal-multiply for `/60`.

The teardown calls `Helper_AuxAudio_PostInit` and, if it returns
non-zero, fires `mciSendCommandA(g_audioPreState, MCI_CLOSE=0x808, 2, 0)`
to release the MCI device, then zeros all six timer-state globals.

### Audio_UpdateChannels

Walks the **16-slot active-channel queue** at `g_audioChannelQueue`
(`0x00f9eb80`). Each entry is `(u16 channel_id, u16 owner_id)`; the
list is terminated by an entry with `channel_id == 0xffff`.

For each live entry:
1. Compute `entry_offset = id * 28` into `g_audioChannelTable`.
2. Load the COM object pointer at that offset; if NULL, mark the slot
   dead (`0xffff`) and continue.
3. Compute a second offset `id*7 + owner` (also into the same table)
   and call vtable method 9 (`[ecx + 0x24]`) on the inner COM object -
   this is `IDirectSoundBuffer::GetStatus`.
4. Inspect the returned status byte:
   - bit 0 ("playing") + `flags[+0x16] & 2` -> needs release -> call
     `Helper_AudioStop(owner)`
   - if `g_audioMute` is set, skip remaining work
   - if not playing -> mark dead (`0xffff`)
   - otherwise call `Helper_AudioRelease`

`Helper_AudioStop` / `Helper_AudioRelease` (`0x004c3710` /
`0x004c3490`) call `IDirectSoundBuffer::Stop` / `Release` through the
cached COM vtable and then zero the slot.


## Per-channel state - the channel table

The big shared structure is at `0x00f8fac8` and is referred to by
**three different names** in different files (they point at the same
bytes - the engine deliberately overlays them):

| Symbol              | Used by                       | Treated as                       |
|---------------------|-------------------------------|----------------------------------|
| `g_audioChannelTable` | `Audio_UpdateChannels`, `Helper_AudioStop/Release` | 28-byte entries, byte at +0x16 = flags |
| `g_dsoundScratch`     | `DSound_Init` zero-clear     | 0x3c28 dwords (one big buffer)   |
| `g_arr_00f8fac8`      | `Helper_AudioStart` (naked)  | per-entry COM pointer arrays     |

So the channel table is **16 entries x 28 bytes** sitting inside a
larger scratch area also used as DSound-side storage. The 0xf8fac8
base is load-bearing; do not relocate.

Per-entry layout (28 bytes):

```
+0x00  IDirectSoundBuffer*  (or NULL = slot free)
+0x04  ... (12 bytes: per-channel state, not yet fully decoded)
+0x10  uint16  current_status_word
+0x14  uint16  ...
+0x16  uint8   flags (bit 1 = "needs release on status==playing")
+0x17..+0x1b   ... (5 bytes: per-channel state, not yet fully decoded)
```

### Active-channel queue

`g_audioChannelQueue` at `0x00f9eb80` is a 16-entry ring of
`(channel_id, owner_id)` u16 pairs (so 64 bytes total). The terminator
sentinel is `channel_id = 0xffff`. The queue is dense (no holes) -
`Audio_UpdateChannels` rewrites the terminator in place when slots
free up.


## Voice mixer pipeline

The most directly named mixer step is at `0x004ab700`
([src/audio/audio_mixer_step.c](../../src/audio/audio_mixer_step.c)),
which folds per-frame deltas into a 16-bit accumulator pair:

```
sum    = g_dispatchSave1163_004d5100 + g_dispatchSave1164_004d5104
sign   = sum >> 31  (arithmetic)
adj    = sign + sum
low16  = sum & 0xffff
new_d4 = g_dispatchSave1164 + adj
store sum, new_d4, low16, walk_callback
call Mul10Tail(low16, walk_callback)
```

This is a per-tick "wrap and dispatch" stage; the actual sample mixing
happens inside `Mul10Tail` (`0x00404af0`) and its callees, which
ultimately reach into the channel-table COM pointers.

The bulk of mixer-related code is in `*_dispatch.c` files in
`src/audio/` that were auto-split from `misc_matchesQQ.c`. These
files share a large boilerplate header listing dozens of
`extern void Xxx_NNNNNNNN(void)` forward decls - **most of those
externs are not audio-related**, they are shared dispatch-table
entries. The real audio logic per file is the single `__declspec(naked)`
body at the bottom; look there, ignore the cross-subsystem extern
wall.


## ESF + ECM streaming

Both content paths feed audio into DirectSound secondary buffers.
For the binary formats see [architecture.md](architecture.md) sections
"ESF audio format" and "ECM cinematic format". Engine entry points:

| Function          | Address      | Role                                          |
|-------------------|--------------|-----------------------------------------------|
| `ESF_Open`        | `0x004b1090` | Open + parse 8-byte ESF header                |
| `ESF_ReadData`    | `0x004b1150` | Decode raw PCM or IMA ADPCM into dst buffer   |
| `ESF_DecodeADPCM` | `0x004ac200` | MS-IMA decoder (state = packed predictor:step)|
| `ESF_Close`       | `0x004b1200` | fclose                                        |
| `ECM_Open`        | `0x004b06f0` | Parse cinematic header + spawn play thread    |
| `ECM_PlayThread`  | `0x004b0a50` | Background streaming worker                   |
| `ECM_Cleanup`     | `0x004b0cb0` | Stop thread + release secondary buffer        |

The ADPCM decoder is a textbook MS-IMA implementation, with the two
LUTs at `g_imaStepTable[89]` (`0x004f4520`) and `g_imaIndexTable[16]`
(`0x004f44e0`) matching the canonical spec exactly.


## Globals reference

All audio globals, grouped by purpose.

### DirectSound state (in HEAP_DATA, ~0x00f8...0x00f9...)

| Symbol              | Address     | Size  | Role                                      |
|---------------------|-------------|-------|-------------------------------------------|
| `g_dsoundContext`   | `0x00f9efc8`| 4     | `IDirectSound*` from `DirectSoundCreate`  |
| `g_dsoundPrimary`   | `0x00f9efcc`| 4     | `LPDIRECTSOUNDBUFFER` primary             |
| `g_dsoundHwnd`      | `0x00f9efd0`| 4     | HWND passed to cooperative-level set      |
| `g_dsoundFieldDc`   | `0x00f9efdc`| 1     | Init success byte                         |
| `g_audioMute`       | `0x00f9efd4`| 1     | "Audio fully active" flag (0 = active)    |
| `g_dsoundFieldE0`   | `0x00f9efe0`| 4     | Re-init guard (see `Helper_AudioStart`)   |
| `g_dsoundFieldE4`   | `0x00f9efe4`| 4     | (init scratch)                            |
| `g_dsoundFieldE8`   | `0x00f9efe8`| 4     | (init scratch)                            |
| `g_audioChannelQueue`| `0x00f9eb80`| 64   | 16 x (id, owner) ring, 0xffff terminator  |
| `g_audioChannelTable`| `0x00f8fac8`| 0x3c28*4 | 16 x 28-byte channel state (overlays g_dsoundScratch) |

### MCI music timer state (low data segment)

| Symbol              | Address     | Size  | Role                                      |
|---------------------|-------------|-------|-------------------------------------------|
| `g_auxAudioHwnd`    | `0x00543910`| 4     | HWND for MCI playback                     |
| `g_audioPreState`   | `0x005438e8`| 4     | Previous MCI device id                    |
| `g_timerActive`     | `0x005438ec`| 4     | 1 = MCI timer armed                       |
| `g_timerStartSec`   | `0x005438f0`| 4     | playback start position (s)               |
| `g_timerEndSec`     | `0x005438f4`| 4     | playback end position (s)                 |
| `g_timerHandle`     | `0x005438f8`| 4     | MCI device handle                         |
| `g_timerLastNow`    | `0x005438fc`| 4     | `timeGetTime()` of last tick (ms)         |
| `g_audioState00`    | `0x00543900`| 4     | (timer scratch)                           |
| `g_timerFlag`       | `0x00543904`| 4     | "currently playing" gate                  |
| `g_audioState08`    | `0x00543908`| 4     | (timer scratch)                           |
| `g_audioState0C`    | `0x0054390c`| 4     | "MCI unsupported" sticky flag             |

### AuxOut device inventory

| Symbol             | Address     | Size  | Role                                       |
|--------------------|-------------|-------|--------------------------------------------|
| `g_auxCount`       | `0x005438a0`| 4     | Number of populated aux devices            |
| `g_auxChannels[8]` | `0x005438a8`| 64    | `{deviceId, _pad}` per device              |
| `g_audioMasterVol` | `0x00543a88`| 1     | 0..100, fed to `AuxAudio_SetMasterVol`     |
| `g_audioPostFlag`  | `0x00543a90`| 1     | Post-init max-volume gate                  |

### ESF / ADPCM tables (.rdata)

| Symbol             | Address     | Size  | Role                                       |
|--------------------|-------------|-------|--------------------------------------------|
| `g_imaIndexTable`  | `0x004f44e0`| 64    | `[-1,-1,-1,-1, 2,4,6,8] x 2` (MS-IMA spec) |
| `g_imaStepTable`   | `0x004f4520`| 356   | 89 step sizes from 7 to 32767              |

### DSound volume-curve constants (.rdata)

`k_dsoundC1..C6` at `0x004d2a68..0x004d2a90` - six `double` values
consumed by the `DSound_Init` FP loop. C1 appears multiple times in
clamping branches (likely 1.0), the rest are scale/limit factors for
the dB-to-linear conversion.


## What's safe to change vs not

The byte-identical rebuild constrains what kinds of changes can land.

**Safe** (won't affect codegen):
- Renaming symbols if applied consistently and `make matching` still
  passes. Globals at the addresses listed above are all
  rename-eligible.
- Adding new top-of-file doc comments inside `*.c` files.
- Editing headers in `include/audio/sound.h` so long as the new types
  produce the same codegen for callers (be conservative: changing
  `u32` to `int` is fine, changing it to `u8` is not).
- Adding NEW source files in `src/audio/` for purely additive code
  that isn't called by the existing binary.

**Unsafe** (will break byte match):
- Changing the in-memory layout of `g_audioChannelTable` entries
  (28-byte stride + the `+0x16` flags byte are load-bearing - the
  COM-call dispatch math hardcodes them).
- Moving any DirectSound global out of the `0x00f8fac8` / `0x00f9...`
  cluster. The 0xf8fac8 base is referenced by the channel update via
  `lea esi, [eax*8] - sub esi, eax - shl esi, 2 - mov ecx, [esi + g_audioChannelTable]`.
- Changing the IMA step or index tables - both must match the MS-IMA
  spec byte-for-byte (they are referenced directly via `[reg*4 +
  g_imaStepTable]`).
- Reordering the timer-state globals at `0x005438e8..0x0054390c`.
  `AuxAudio_Init` zero-clears them in a specific declaration order
  that encodes their relative addresses into the prologue's repeated
  `mov [g], edi` stores. Any reorder changes 10 store offsets.
- Touching the volume-curve constants `k_dsoundC1..C6` - they are
  loaded by absolute address inside the FP loop.

**Already converted to pure C** (44% of `src/audio/`):
- `Audio_TimerTick`, `AuxAudio_SetVolume`, `GetExeDirectory`,
  `DebugStub_NoOp_*`, `Helper_AudioStartFresh`, `Helper_TitleAudioReset`,
  `Audio_TimerTeardown_004ac5f0`, plus dozens of small dispatch helpers.

**Still naked** (44%) - DO NOT attempt to convert:
- `DSound_Init` - FP loop + three `_ftol`s + partial-init struct pattern
- `Audio_UpdateChannels` - hand-encoded `test bl, al` (84 c3 vs MASM's 84 d8)
- `ESF_DecodeADPCM` - sete-toggle nibble alternation + edi-threaded predictor
- `AuxAudio_Init` - 10-store xor-edi zero-clear prologue
- `UpdateWindowTitle` - 8-pair cascade reusing eax across cmps
- `ResetConfigToDefaults` - interleaved 26-dword struct copy
- `Audio_TimerSet` - MCI packet build with `0x88888889` reciprocal

The per-function `NON-COAXABLE:` comment in each naked file explains
the specific MSVC SP3 codegen quirk that blocks conversion. Respect
these comments - the survey is complete.


## File map for `src/audio/`

Of the 174 files in `src/audio/`, only a focused subset is "real"
audio code. The rest are dispatch helpers that got bucketed here by
filename heuristic during the QQ.c auto-split. The focused set:

| File                              | Role                                        |
|-----------------------------------|---------------------------------------------|
| `dsound_init.c`                   | `DSound_Init` (creates IDirectSound + primary buffer) |
| `channels.c`                      | `Audio_UpdateChannels` (per-frame channel sweep) |
| `adpcm.c`                         | `ESF_DecodeADPCM` (MS-IMA decoder)         |
| `timer.c`                         | `Audio_TimerTick` (per-frame MCI timer)    |
| `audio_timer_set.c`               | `Audio_TimerSet` (MCI play/seek packet)     |
| `audio_timer_teardown.c`          | `Audio_TimerTeardown` (MCI close + zero state) |
| `aux_init.c`                      | `AuxAudio_Init` (enumerate aux devices)    |
| `auxout.c`                        | `AuxAudio_SetVolume` (broadcast pack)      |
| `aux_audio_dev_caps_query.c`      | `auxGetDevCapsA` wrapper                   |
| `aux_audio_teardown.c`            | aux device cleanup                         |
| `debug.c`                         | `DebugStub_NoOp_A/B` (empty hooks)         |
| `integrity.c`                     | `GetExeDirectory` + `Helper_ComputeExeHash` (audio init gate) |
| `reset_config.c`                  | `ResetConfigToDefaults` (restore .rdata defaults) |
| `validate_install.c`              | `ValidateInstall` (registry + path check) |
| `install_path.c`                  | `CheckInstallPath` (registry lookup + chdir) |
| `window_title.c`                  | `UpdateWindowTitle` (title-bar + audio sync) |
| `helper_audio_start_fresh.c`      | `Helper_AudioStartFresh`                   |
| `helper_aux_audio_post_init.c`    | `Helper_AuxAudio_PostInit`                 |
| `helper_title_audio_reset.c`      | `Helper_TitleAudioReset`                   |
| `helper_title_enter_state_a.c`    | `Helper_TitleEnterStateA`                  |
| `helper_title_enter_state_b.c`    | `Helper_TitleEnterStateB`                  |
| `audio_mixer_step.c`              | `AudioMixerStep_004ab700` (per-tick fold)  |
| `audio_mixer_knob_update.c`       | mixer knob update dispatcher               |
| `audio_voice_sequencer_cluster.c` | voice sequencer cluster                    |
| `voice_mixer_tick_dispatch.c`     | per-frame voice mixer fan-out              |
| `voice_pool_tick_dispatch.c`      | voice pool per-frame tick                  |
| `voice_bank_tick_dispatch.c`      | voice bank per-frame tick                  |
| `voice_table_init.c`              | voice table init                           |
| `voice_trio_bind_and_kick.c`      | voice bind + kick (3-arg variant)         |

The remaining ~140 `*.c` files in `src/audio/` are auto-split dispatch
helpers; their canonical home will be re-curated as the
function-naming pass proceeds.


## Where to start when modifying audio

1. **Re-skin volume curve**: edit `k_dsoundC1..C6` in `src/data.c`. The
   curve table generated by `DSound_Init` will change accordingly.
   Note: changing these breaks the byte match - the constants are
   referenced by absolute address.
2. **Mute everything**: set `g_audioMute = 1` before `DSound_Init`.
   `Audio_UpdateChannels` short-circuits on it.
3. **Add a new SFX**: route through `ESF_Open` + `ESF_ReadData`; the
   channel allocation is automatic via `Helper_AudioStart`. Asset must
   be a valid ESF file (header + 8-bit PCM or IMA ADPCM payload).
4. **Replace MCI music with a modern codec**: hook `Audio_TimerSet`.
   The existing function does `mciSendCommandA(handle, MCI_PLAY=0x806,
   ..., MCI_FROM | MCI_TO packet)`. Substitute your own play call;
   keep the function signature stable so callers in
   `helper_gsm_sub_other1.c` still link.
5. **Replace ECM cinematics with a modern container**: hook `ECM_Open`
   / `ECM_PlayThread`. As `architecture.md` notes, re-encoding the 16
   cinematics is far cheaper than re-implementing the Huffman video
   codec.
