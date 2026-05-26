# MK4.EXE - Input subsystem

How the game reads the keyboard and joystick(s) and turns them into
per-player action bitmasks. MK4 ships WITHOUT `DINPUT.DLL`:

- Keyboard goes through Win32 `GetAsyncKeyState` (IAT 0x4d21c0) - the
  WndProc's `WM_KEYDOWN/WM_KEYUP` path is only used for F1-F9 renderer
  hotkeys and PrintScreen; the gameplay-time key polling is fully
  async, not message-driven.
- Joystick goes through the WINMM legacy API (`joyGetPos` at
  0x4d222c, `joyGetPosEx` at 0x4d2228, `joyGetDevCapsA` at 0x4d221c).
- `MapVirtualKeyA` (IAT 0x4d21c4) is used at boot but for HUD font
  asset-name patching, not input (see `AppInit_Misc1`).

The user-visible result of one input frame is a small set of action
accumulators (per player) that the fight FSM and the menu state machine
read on the next tick.

## Top-level call shape

```
   [boot]                                Joystick_Init           0x004b5230
                                          for each WINMM device with
                                          joyGetPos+joyGetDevCapsA OK:
                                          - compute axis center +-33/50
                                            calibration into g_joyCalA/B/C
                                          - cache the per-device button
                                            byte into g_joyButtonState
                                          for i in 0..0xff:
                                            Input_GetAsyncKey(i)       <- pre-warm

   [per frame, from GameLogicStep]       Input_TickPlayers       0x004b5850
                                          clears the 4 action accumulators
                                          Input_PollPlayerKeyboard(0)
                                          Input_PollPlayerKeyboard(1)
                                          Input_PollPlayerJoystick(0)
                                          Input_PollPlayerJoystick(1)
                                          if (gate-flag was already set)
                                            check ENTER/SPACE/ESC; clear
                                            gate if any held
                                          tail: invert each accumulator
                                          into its 'released' shadow

   [per frame, from menus]               Menu_PollNavInput        0x004b7020
                                          polls 8 nav VKs + 2 selected
                                          joysticks, returns packed nav
                                          bitmask with 0x8000 auto-repeat
                                          and plays nav SFX on fresh press

   [per frame, from attract loops]       Input_AnyConfirmPressed  0x004be3c0
                                          1 if ENTER/SPACE/ESC held OR
                                          any selected joystick reports
                                          a button in mask 0x0fffffff
```

## Functions in this subsystem

| Address    | Name                                       | Size (b) | Role |
|------------|--------------------------------------------|---------:|------|
| 0x004b5230 | `Joystick_Init`                            |      319 | Enumerates 16 WINMM joystick slots, builds axis-calibration tables (`g_joyCalA/B/C`), stashes per-device button byte, then pre-warms `GetAsyncKeyState` for all 256 VK codes. |
| 0x004b5380 | `Input_PollJoystick`                       |      196 | `joyGetPosEx(idx, &JOYINFOEX{0x34, flags=0x483})`; aggregates 13 button bits via mask table at `0x4f4ea0`, plus 4 axis-out-of-range flags (X<min/X>max/Y<min/Y>max) into bits `0x10000000`..`0x80000000`. Returns the packed bit value. |
| 0x004b5450 | `Input_GetAsyncKey`                        |       18 | Wraps `GetAsyncKeyState(vk)`; returns `(ret >> 15) & 1` (the 'currently held' bit). The primitive used by every key-polling path. |
| 0x004b5470 | `Input_PollPlayerJoystick`                 |      475 | Per-player joystick scan. Reads `g_joySelected_00543b68[player]`; if -1 returns. Calls `Input_PollJoystick` to get raw bits, then maps 4 axis bits (`0x40000000..0x20000000`) to the player's direction action targets, plus 9 button bindings at `g_btnBindings_00543b20..b60` (1-based index, 0 = unbound) to the same per-player action mask table at `0x4f4dc8..0x4f4e8c`. |
| 0x004b5650 | `Input_PollPlayerKeyboard`                 |      494 | Per-player keyboard analog of the above. Bails if VK_MENU (0x12) is held (lets Alt+key sequences pass to the OS). Iterates 13 (VK, action mask) bindings at `g_keyBindings_00543ab8..b18` and ORs each pressed key's action mask into the player's action target via `Input_GetAsyncKey`. |
| 0x004b5850 | `Input_TickPlayers`                        |      448 | Per-frame input tick (was `GameStateMachineMaybeRebuild`). Clears the 4 action accumulators (`g_fightTableC0/C1/C2`, `g_phaseThunkInst_004d50ac`); runs keyboard + joystick polls for players 0 and 1; on a pending paused state checks ENTER/SPACE/ESC to release it; tail inverts each accumulator into the 'released' shadow used by edge-trigger code. |
| 0x004b7020 | `Menu_PollNavInput`                        |      312 | Menu navigation poll. Reads 8 VKs (up/down/left/right/enter/space/esc/back) + the 2 selected joysticks. Returns a packed nav bitmask: bits 1/2/4/8 = dirs, 0x10 = confirm, 0x20/0x60 = back/cancel. Auto-repeat: if previous nonzero AND current nonzero, sets bit 0x8000. Plays nav SFX (sound id 0xa0) on fresh press. |
| 0x004be3c0 | `Input_AnyConfirmPressed`                  |      125 | Returns 1 if ENTER (0x0d), SPACE (0x20) or ESC (0x1b) is held via `Input_GetAsyncKey`, OR if either selected joystick reports any button in mask `0x0fffffff`. The 'press anything to advance' probe used by the attract loop in `SceneFrameStepWithInputs_004be250`. |
| 0x004c49b0 | `WndProc`                                  |     1728 | The MK4 window procedure registered by `Boot` (WNDCLASS 'Mortal Kombat 4'). Handles WM_DESTROY/SIZE/PAINT/CLOSE/ERASEBKGND/ACTIVATEAPP/SETCURSOR/DISPLAYCHANGE/SYSCOMMAND. WM_KEYDOWN for F1-F9 renderer hotkeys, WM_KEYUP for the PrintScreen `scrngrab.bmp` capture, WM_SYSKEYDOWN/UP for the Alt-key audio-reset cleanup path. NB: gameplay key polling is async (GetAsyncKeyState), NOT via WndProc. |

## Shared globals

| VA         | Name (shown in source)              | Meaning |
|------------|-------------------------------------|---------|
| `0x00543b68` | `g_joySelP0_00543b68`         | Selected joystick index for player 0 (-1 = no joystick bound). |
| `0x00543b6c` | `g_joySelP1_00543b6c`         | Selected joystick index for player 1 (-1 = no joystick bound). |
| `0x00543b20..b60` | (9 dwords, 2 players each)     | Per-player joystick button bindings (1-based button index per action slot; 0 = unbound). |
| `0x00543ab8..b18` | (13 dwords, 2 players each)    | Per-player keyboard VK bindings - one VK per of the 13 action slots. |
| `0x004f4dc8..0x004f4e8c` | (per-player action table) | For each of the 4 directions + 9 buttons: a (target-ptr, action-mask) pair. The pollers OR the mask into `*target` when the bound input is held. |
| `0x004f4ea0..0x004f4f10` | (joystick button-bit masks)   | 13-entry table used by `Input_PollJoystick` to translate raw joystick button bits to packed action bits. |
| `0x007b00c8`, `0x007b0088`, `0x007b0108`, `0x007b0148` | | Per-axis (X-low, X-high, Y-low, Y-high) per-joy threshold tables built by `Joystick_Init`. Compared against the JOYINFOEX X/Y to set the 4 axis-out-of-range bits in `Input_PollJoystick`'s return. |
| `0x004d21c0` | `g_iat_004d21c0`                    | IAT slot: `GetAsyncKeyState`. |
| `0x004d21c4` | `g_iat_004d21c4`                    | IAT slot: `MapVirtualKeyA` (only used by HUD font precache, not input). |
| `0x004d221c` | `g_iat_004d221c`                    | IAT slot: `joyGetDevCapsA`. |
| `0x004d2228` | `g_iat_004d2228`                    | IAT slot: `joyGetPosEx`. |
| `0x004d222c` | `g_iat_004d222c`                    | IAT slot: `joyGetPos`. |

## Bit layout of the action accumulator

Each player has 13 action slots, encoded as bits in a target dword.
Slot mapping (deduced from the parallel-indexed (target, mask) table
shared by `Input_PollPlayerKeyboard` and `Input_PollPlayerJoystick`):

| Slot | Source (table layout) |
|-----:|------------------------|
| 0    | LEFT  - keyboard binding `g_keyBindings_00543ab8`, joystick axis bit `0x40000000` |
| 1    | RIGHT - keyboard binding `g_keyBindings_00543ac0`, joystick axis bit `0x80000000` |
| 2    | UP    - keyboard binding `g_keyBindings_00543ac8`, joystick axis bit `0x10000000` |
| 3    | DOWN  - keyboard binding `g_keyBindings_00543ad0`, joystick axis bit `0x20000000` |
| 4    | Button A - keyboard binding `g_keyBindings_00543ad8`, joystick button-index in `g_btnBindings_00543b20` |
| 5    | Button B - bindings `_00543ae0` / `_00543b28` |
| 6    | Button C - bindings `_00543ae8` / `_00543b30` |
| 7    | Button D - bindings `_00543af0` / `_00543b38` |
| 8    | Button E - bindings `_00543af8` / `_00543b40` |
| 9    | Button F - bindings `_00543b00` / `_00543b48` |
| 10   | Button G - bindings `_00543b08` / `_00543b50` |
| 11   | Button H - bindings `_00543b58` |
| 12   | Button I - bindings `_00543b18` / `_00543b60` |

The mapping of slot -> in-game action (HP, LP, HK, LK, BL, RUN ...) is
TODO - the MK series uses 6 attack buttons + run + block in the cabinet
layout, so 9 button slots is plausible (6 attacks + block + run + extra).

## Calibration formula (Joystick_Init)

For each joystick index `i` (0..15), Joystick_Init reads JOYINFO and
JOYCAPS, then writes 4 dwords per joystick into `g_joyCalA[i]`,
`g_joyCalB[i]`, `g_joyCalC[i]`, plus the equivalent fourth slot.
For each axis, the value stored is:

```
center + ((max - min) * 33 / 50)     ; "67% of range, centered on min"
```

The `* 33 / 50` is emitted via the classic 0x51eb851f multiply +
`shr edx, 5` magic divide. A parallel pair uses `* 66 / 50` (twice the
above) for what looks like an outer-deadzone threshold.

## Functions whose names look related but AREN'T input

- `AppInit_PostJoy` (0x004b5a10) - despite the name, fills the 4096-entry
  `g_sinTable` at `0x007b01a0` with `(int)(cos(i*2pi/4096)*scale - bias)`.
  Called right after the joystick block in the boot sequence, hence the
  misleading prefix. See [scenegraph.md](scenegraph.md) (BAM sine LUT).
- `AppInit_Misc1` (0x004b6180) - HUD font precache. Uses `MapVirtualKeyA`
  but on the loop index (`MapVirtualKeyA(i, MAPVK_VK_TO_CHAR=2)`) to
  patch the first byte of dot-prefixed asset names. Not input handling.
- `InputCheckCluster_0045e1e0` - actually a scripted-event packet
  dispatcher (events 0xdd, 0xaa), reached from the event-queue decoder.
  The name has 'Input' but it's the cutscene/event interpreter, not the
  keyboard/pad path. Misnomer; flagged for a separate rename pass.
- `InputPollFlagBits_004a1b00` and `InputPollFlagBitsHalf_004a1b50` -
  read individual bits of `g_byte_004d50b8` and `g_byte_004d50b4`
  (which look like already-aggregated per-player action accumulators).
  Used from the audio path. Without knowing the exact slot meanings
  (see TODO below), can't be safely renamed.
- `SceneFrameStepWithInputs_004be250` - attract/intro playback loop.
  Drives ECM track playback and calls `Input_AnyConfirmPressed` to
  exit. Already descriptively named, left alone.

## TODOs

- **Slot -> action ID mapping**. The 13 action slots have a fixed
  layout in the (target, mask) table but the specific in-game action
  per slot (HP, LP, HK, LK, BL, RUN, ...) needs runtime confirmation:
  trap one of the action targets, hold the corresponding key, and read
  the bit that was set.
- **Default key + button bindings**. The 13 keyboard bindings at
  `g_keyBindings_00543ab8` and the 9 button bindings at
  `g_btnBindings_00543b20` are initialized somewhere during boot but
  the init function hasn't been pinpointed yet. Likely loaded from
  the `Config` registry blob (see `install.md`).
- **Joystick deadzone vs outer threshold**. Two parallel calibration
  tables exist (`g_joyCalA/B` 33/50 and the corresponding 66/50
  variant). One is likely the inner deadzone, the other the
  edge-triggered max threshold. Need a runtime test.
- **`InputCheckCluster_0045e1e0` rename**. The name is misleading -
  it's an event-packet dispatcher, not input. Belongs in the
  event-queue rename pass.
- **`InputPollFlagBits_004a1b00` / `_004a1b50` clarification**. Once
  the slot mapping above is confirmed, these two `g_byte_004d50b4/b8`
  bit-checkers can be renamed to descriptive predicates (likely
  variations of 'any direction held' / 'any button held').
- **Runtime verification on Whisky+dgVoodoo2**. The whole subsystem
  has been mapped from static analysis. A runtime trace (e.g. WINEDEBUG
  hooks on `GetAsyncKeyState` + `joyGetPosEx`) would confirm the
  per-slot semantics.
