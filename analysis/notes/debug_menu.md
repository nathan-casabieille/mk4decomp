# MK4.EXE - Hidden debug / "kheat" menu

MK4 ships with a hidden developer/cheat menu (the MK community "Kheat
Menu") that exposes match-setup toggles, fatality/ending unlocks, and
a persistent Kombat Rating stat readout. It is drawn as **scene text
nodes** every frame by a cluster of functions in `0x004a2000`..
`0x004a5000` that the previous symbol pass had mislabelled as "audio
voice" dispatchers (they share that address neighbourhood with the
real audio state machine, but touch no DSound/ESF state).

This doc covers how the menu text is rendered and what each section
shows. The top-level menu FSM that owns the screen states is in
[menu_state.md](menu_state.md); the 3D-font glyph atlas that actually
rasterises the text is in [render.md](render.md) / [scenegraph.md](scenegraph.md).

## Render mechanism (per row, per frame)

Each section function walks a per-row record table (36-byte stride)
and for every row does:

```
Helper_Sprintf(g_voiceBankTickBase, "<Label> %s", value_string)
                                     ^ 0x00543450  ^ "ON" / "OFF" / a value
GuardedSetupCallTailJmp(node_packed_ptr, mask)   ; insert as scene text node
```

- `g_voiceBankTickBase` (`0x00543450`) is the shared scratch text
  buffer the row is formatted into.
- The `%s` value is looked up from the dword table at `0x004f2fc0`,
  whose first two entries are the literal strings **`"OFF"`** (`[0]`)
  and **`"ON"`** (`[1]`); the remaining entries are pointers to the
  toggle-state globals (`0x004d50xx`, `0x00543368/6c/70`, ...). So a
  row resolves to e.g. `"Background ON"` / `"Background OFF"`.
- `GuardedSetupCallTailJmp_004a1fa0(node, mask)` is the generic
  scene-node insert (sets node event-type 4 + callback `0xa000`); it
  is NOT a text-specific primitive - the text just rides on a normal
  scene node so the 3D-font renderer picks it up.

The stats section uses `%d` instead of `%s` (numeric counters, not
toggles).

## Sections

### Match-setup options - `DebugMenu_DrawMatchOptions` (`0x004a3120`)

(was `VoiceBankTickDispatch_004a3120`.) Six ON/OFF/value rows:

| Row | Label format |
|-----|--------------|
| 0 | `Player 1 %s`     |
| 1 | `Player 2 %s`     |
| 2 | `Difficulty %s`   |
| 3 | `Opponent %s`     |
| 4 | `Background %s`   |
| 5 | `Practice Info %s`|

### Unlock toggles - `DebugMenu_DrawUnlockToggles` (`0x004a4c10`)

(was `VoicePoolTickDispatch_004a4c10`.) Four ON/OFF rows (the classic
MK cheat toggles):

| Row | Label format |
|-----|--------------|
| 0 | `Endings %s`          |
| 1 | `Fatalities I %s`      |
| 2 | `Fatalities II %s`     |
| 3 | `Level Fatalities %s`  |

### Kombat Rating stats - `RoundDisplayInitCluster_004a4f00`

(name unchanged - it is a 595-byte 4-helper cluster that also does
round-display init, so the umbrella name still fits.) Renders the
persistent record using `%d` counters:

| Label format |
|--------------|
| `Kombat Rating:`  |
| `Fatalities %d`   |
| `Perfect Kills %d`|
| `Body Count %d`   |

## Globals

| VA           | Name                         | Meaning |
|--------------|------------------------------|---------|
| `0x00543450` | `g_voiceBankTickBase`        | Shared scratch buffer each row is sprintf'd into before the node insert. |
| `0x004f2fc0` | (ON/OFF + state-ptr table)   | `[0]="OFF"`, `[1]="ON"`; later entries point at the per-toggle state globals. Indexed by a small per-row state var to pick the displayed value. |
| `0x004f42e0`..`0x004f432c` | match-option label format strings | "Player 1/2", "Difficulty", "Opponent", "Background", "Practice Info" (each `... %s`). |
| `0x004f433c`..`0x004f4374` | unlock-toggle label format strings | "Level Fatalities", "Fatalities II", "Fatalities I", "Endings". |
| `0x004f4380`..`0x004f43b4` | stat label format strings | "Kombat Rating:", "Fatalities %d", "Perfect Kills %d", "Body Count %d". |
| `0x004d50b4`, `0x004d50b8` | toggle-state bytes | Among the state globals the table points at. NB: these are the same bytes `InputPollFlagBits_004a1b00`/`_004a1b50` read - see [input.md](input.md) TODO; the linkage between those predicates and these toggles is not yet pinned. |
| `0x00543368/6c/70` | `g_dispatchSave25/26/27` | Fight action-accumulator flags (also written by `Input_TickPlayers`); referenced by the ON/OFF table. |

## Relation to the main mode-select menu

The mode-select menu strings live in the same `.rdata` block
(`0x004f4298`..`0x004f42d0`): `ARCADE`, `TEAM`, `ENDURANCE`,
`TOURNAMENT`, `PRACTICE`, `EXIT GAME`. The 28-byte-record mode table
at `0x004f30c4` (see [menu_state.md](menu_state.md)) references these.
The debug menu appears to be reachable from / layered over the same
state-machine cluster that drives mode select.

## TODOs

- **Access path / activation**. How the player opens this menu (a
  button code at the title, or a build flag) is not yet traced. Find
  the writer that flips the state into the section drawers.
- **Per-toggle backing global**. Each row's ON/OFF reads a specific
  state global via the `0x4f2fc0` table; map row -> global -> the
  gameplay effect (e.g. which flag actually gates "Level Fatalities").
- **`VoiceMixerTickDispatch_004a27c0`** is the structural "sister" of
  these drawers (same loop shape) but did not surface any text format
  strings in the scan - confirm whether it is a real audio mixer tick
  or another (value-less) section drawer before renaming it.
- **`RoundDisplayInitCluster_004a4f00`** mixes round-display init with
  the Kombat Rating stat rows; if the cluster is ever split, the
  stat-drawing helper deserves its own `DebugMenu_DrawStats` name.
- **Resolve `InputPollFlagBits_004a1b00/_004a1b50`** (input.md TODO):
  they read `0x4d50b4/b8`, which this menu treats as toggle state -
  understanding the menu may finally pin those predicates' meaning.
