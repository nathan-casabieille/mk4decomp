# Combat FSM + game-tick subsystem

Per-subsystem deep dive for MK4's gameplay state machine, the
fight-mode tick, and the per-player event queue. Covers the two
parallel tracks (menu FSM + fight tick) that run every frame, the
dispatch tables, and how player nodes plug into the scenegraph.

For the scenegraph walker that consumes the per-tick state see
[scenegraph.md](scenegraph.md). For the render pipeline that turns
fight state into draw calls see [render.md](render.md).


## Two parallel tracks

`MainLoopStep` ([architecture.md](architecture.md) "Main loop")
calls `GameLogicStep` ~60 times per second. That function runs two
tracks in parallel each tick:

| Track          | Entry point          | Address       | Purpose                       |
|----------------|----------------------|---------------|-------------------------------|
| **Menu FSM**   | `GameStateMachine(0)`| `0x004b6340`  | Top-level UI screens          |
| **Fight tick** | `GameTick(0)`        | `0x0041fd70`  | Active fight per-frame work   |

Both run unconditionally each frame; `g_gameMode` decides which one
actually does work. When `g_gameMode == 0` (active fight), the
menu FSM short-circuits to the "default" tail and the fight tick
runs full bore. When `g_gameMode != 0`, the menu FSM dispatches to
one of the screen handlers and `GameTick` mostly no-ops.

```c
void GameLogicStep(void) {
    ++g_frameCounter;
    g_gameStateResult = GameStateMachine(0);          // menu FSM
    if (g_gameStateResult == 0)
        Input_TickPlayers();
    Audio_UpdateChannels();
    Audio_TimerTick();
    if (Renderer_GetMode() == 4 && g_mode4PauseGate == 0) {
        GameStateMachine(8);                          // SW-Windowed pause
    } else {
        XformChainAdvance();
        GameTick(0);                                  // fight tick
    }
    g_logicStepFlag = 0;
}
```

(Source: [src/game/tick.c](../../src/game/tick.c) - this function
is already pure C.)


## Menu FSM - GameStateMachine (0x004b6340)

Naked, ~700 bytes. Dispatch shape:

```
state = g_gameState                  ; range [0, 0x1c]
if (state > 0x1c) goto tail          ; out-of-range
idx   = g_gsmByteTable[state]        ; 29-byte sparse map
goto  g_gsmJumpTable1[idx]           ; 16-entry jump table
```

Two co-located dispatch tables live as data in the same `.text`
section, immediately after the function body:

| Symbol             | Address     | Size     | Role                                |
|--------------------|-------------|----------|-------------------------------------|
| `g_gsmJumpTable1[16]`| `0x004b6540`| 64 bytes | First-level handler table           |
| `g_gsmByteTable[29]` | `0x004b6580`| 29 bytes | state -> table1 index               |
| `g_gsmJumpTable2[8]` | `0x004b65a0`| 32 bytes | Main-menu sub-dispatch on `cmd`     |

### Byte-table contents (state -> handler index)

Decoded from the `_emit` block in [src/game/statemachine.c](../../src/game/statemachine.c):

```
state  0   -> idx 0  (main-menu sub-dispatch on cmd via table2)
state  1   -> idx 0xf (default no-op)
state  2   -> idx 0xf
state  3   -> idx 0xf
state  4   -> idx 1  (DrawMenu - menu redraw/transition)
state  5   -> idx 2  (Menu_HelpScreen)
state  6   -> idx 3  (Helper_GSM_HandleEvent)
state  7   -> idx 4  (Menu_PauseMenu)
state  8   -> idx 5  (Menu_GlideUnavailableDialog)
state  9   -> idx 6  (Menu_Direct3DUnavailableDialog)
state  0xa -> idx 7  (Menu_DirectDrawUnavailableDialog)
state  0xb -> idx 8  (Menu_InsertCDDialog)
state  0xc -> idx 9  (Menu_ColorDepthErrorDialog)
states 0xd..0x17 -> idx 0xf (default)
state  0x18 -> idx 0xa (Helper_GSM_VS)
state  0x19 -> idx 0xb (Helper_GSM_Tournament)
state  0x1a -> idx 0xc (Helper_GSM_Practice)
state  0x1b -> idx 0xd (Helper_GSM_Options)
state  0x1c -> idx 0xe (Helper_GSM_Config)
```

### State -> screen mapping

| State (g_gameState) | Handler                            | Screen                          |
|---------------------|------------------------------------|---------------------------------|
| 0                   | (main-menu sub-dispatch)           | Top-level menu                  |
| 4                   | `DrawMenu`                         | Menu redraw / transition        |
| 5                   | `Menu_HelpScreen`                  | F1 HELP overlay                 |
| 6                   | `Helper_GSM_HandleEvent`           | event / transition dispatch     |
| 7                   | `Menu_PauseMenu`                   | in-match PAUSE menu             |
| 8                   | `Menu_GlideUnavailableDialog`      | "GLIDE 3D NOT AVAILABLE"         |
| 9                   | `Menu_Direct3DUnavailableDialog`   | "DIRECT3D NOT AVAILABLE"         |
| 0xa                 | `Menu_DirectDrawUnavailableDialog` | "DIRECT-DRAW NOT AVAILABLE"      |
| 0xb                 | `Menu_InsertCDDialog`              | no-CD / RESCAN dialog           |
| 0xc                 | `Menu_ColorDepthErrorDialog`       | windowed 8-bit-color error       |
| 0x18                | `Helper_GSM_VS`                    | VS / arcade fight flow          |
| 0x19                | `Helper_GSM_Tournament`            | tournament setup                |
| 0x1a                | `Helper_GSM_Practice`              | practice setup                  |
| 0x1b                | `Helper_GSM_Options`               | options page                    |
| 0x1c                | `Helper_GSM_Config`                | controls config                 |

CORRECTION: prior revisions guessed the gameplay modes
(ARCADE/VS/TOURNAMENT/PRACTICE/OPTIONS) were at states 5-9 and that
0x18-0x1c were char/stage-select sub-states. Both were wrong. The
mechanical byte-table -> jumptable1 -> call-target decode above (cross
-checked against the raw disassembly of each dispatch label) shows the
**gameplay modes live at 0x18-0x1c** and the **help/error/pause
dialogs at 0x05-0x0c**. Handler identities are independently confirmed
from each dialog's menu-item strings (see [menu_state.md](menu_state.md)).
The old `GAMESTATE_*` symbol names below are retained only as a record
of the superseded guess.

### `cmd` sub-dispatch (state 0)

When state is 0 and `cmd` is in [1..8], a second jump table
`g_gsmJumpTable2[8]` sets a new state. Decoded from the actual
`mov ecx, imm32` in each target block (verified against the EXE),
the `cmd` values are **direct screen/dialog requests**, not
gameplay-mode selectors - `cmd 1` is F1=HELP (matches WndProc's
`F1 -> GameStateMachine(1)`), and the rest open the engine's
error/pause dialogs:

| cmd | New state | Resulting handler                  |
|-----|-----------|------------------------------------|
| 1   | 5         | `Menu_HelpScreen` (F1 HELP)        |
| 2   | 6 (gated by `g_gsmFlag`) | `Helper_GSM_HandleEvent` |
| 3   | 7         | `Menu_PauseMenu`                   |
| 4   | 9         | `Menu_Direct3DUnavailableDialog`   |
| 5   | 0xa       | `Menu_DirectDrawUnavailableDialog` |
| 6   | 8         | `Menu_GlideUnavailableDialog`      |
| 7   | 0xb       | `Menu_InsertCDDialog`              |
| 8   | 0xc       | `Menu_ColorDepthErrorDialog`       |

(Superseded guess: an earlier revision read these as
`sub_practice`/`sub_arcade`/`sub_options`/... main-menu mode launches.
The `mov ecx` constants + the verified state->handler map disprove
that - these eight commands all open help/error/pause overlays. The
gameplay modes at states 0x18-0x1c are entered by a different path,
most likely the state-0 `DrawMenu` row selection rather than this
`cmd` table.)

After setting the new state, the function falls through to an
**audio re-arm** sequence:

```c
Helper_AudioRelease2(0x4a);
Audio_PlaySoundId(0x4a, -1, -1);
```

So every menu transition triggers a music release + restart, which
is how MK4 plays the menu music continuously across screen
transitions without gapping.

### Per-state handlers

Each non-trivial state in the dispatch table calls a per-state
helper that returns an int "post-action code". The codes the FSM
acts on:

| Return code | Action                                                     |
|-------------|------------------------------------------------------------|
| `0x45`      | Set `g_gameState = 4` (menu redraw / transition)           |
| `0x18..0x1c`| Set `g_gameState = retval` (enter a gameplay mode: VS / Tournament / Practice / Options / Config) |
| `0x3`       | Set `g_gameState = 6`                                      |

The helpers themselves:

| Symbol                       | Address      | Role                           |
|------------------------------|--------------|--------------------------------|
| `Helper_GSM_HandleEvent`     | `0x004b84d0` | State-6 handler; returns the next gameplay state (0x18-0x1c) or 0x45. This return value is how the mode-select menu enters VS/Tournament/Practice/Options/Config (see `case_handle_event`). |
| `Helper_GSM_VS`              | `0x004b6900` | VS-mode tick                   |
| `Helper_GSM_Tournament`      | `0x004b7260` | Tournament-mode tick           |
| `Helper_GSM_Practice`        | `0x004b7b10` | Practice-mode tick             |
| `Helper_GSM_Options`         | `0x004b7df0` | Options menu tick              |
| `Helper_GSM_Config`          | `0x004b81f0` | Config menu tick               |
| `Menu_HelpScreen` ..`Menu_PauseMenu` | `0x004b8630..8a30` | Help / renderer-unavailable / pause dialogs |
| `Menu_ColorDepthErrorDialog`, `Menu_InsertCDDialog` | `0x004b8bd0/8d70` | Color-depth + no-CD error dialogs |
| `Helper_GSM_Reset`           | `0x004b5840` | Reset menu dirty flags         |

The actual menu logic (selection cursor, options crawl, etc.) lives
inside these per-state helpers. They share a few "dirty" globals
(`g_gsmDirty1/2/3`) that the FSM tail reads to issue
`Helper_GSM_PlayMusic` etc.

### The mode-4 pause path

The conditional `if (Renderer_GetMode() == 4 && g_mode4PauseGate == 0)`
in `GameLogicStep` is a **SW-Windowed-only single-step path**. When
the renderer is mode 4 (software windowed) AND the pause gate has
just been cleared, the FSM is called recursively with `cmd = 8`
instead of running the fight tick. This is the menu's way of
re-entering itself for the practice-tournament sub-dispatch -
practice mode reuses `cmd = 8` (PRACTICE), but only when SW-Win is
active. The exact rationale isn't fully decoded.


## Fight tick - GameTick (0x0041fd70)

Pure C ([src/game/game_tick.c](../../src/game/game_tick.c)). The
per-frame fight workflow:

```c
void GameTick(int param) {
    /* 1. Debug stubs (compiled out) */
    if (g_gameMode != 0)        DebugStub_NoOp_*(g_gtPauseMode);
    if (g_gtOtherFlag == 1)     DebugStub_NoOp_*(g_gtModeFlag);
    if (g_gtConfig4f != 2 && g_gtState438 != 0) DebugStub_NoOp_*();

    /* 2. Main fight pump */
    if (g_gameMode == 0) {
        FightFrameStep();
        if (g_framePauseFlag != 0) return;
        ++g_gtFightTickCounter;
        DispatchEventQueue();
        if (g_framePauseFlag != 0) return;
    }

    /* 3. Misc + post-fight (runs in all modes) */
    Helper_TickFrame_Misc();
    if (g_framePauseFlag != 0) return;
    Helper_TickFrame_PostFight();
    if (g_framePauseFlag != 0) return;

    /* 4. Per-player tick (only in fight mode) */
    if (g_gameMode == 0) {
        g_walkCallback = (void *)g_player1NodeIdx;
        if (g_player1NodeIdx != 0) Helper_PerPlayerTick();
        if (g_framePauseFlag != 0) return;
        Helper_PostPlayerTick();
        if (g_framePauseFlag != 0) return;
        Helper_TickFrameTail();
        if (g_framePauseFlag != 0) return;
    }

    /* 5. 4-player overlay scan (param == 0 only) */
    if (param == 0) {
        for each of 4 players:
            scan player's scenegraph node for state == 0x501;
            toggle flag bit 0x1000 in node[+0x34] based on
            (player_enabled AND y > -0xffff_0000)
    }

    /* 6. Axis lowpass + sentinel reset */
    g_gtAxisX += (0x8000 - g_gtAxisX) / 8;  /* etc for Y, Z */
    if (g_gameMode == -1) g_gameMode = 0;
}
```

`g_framePauseFlag` is the ubiquitous **abort gate**: any per-frame
helper that wants to pause the rest of the frame just sets it
non-zero, and every caller (here, `GameLogicStep`, `Helper_TickInner`,
`RenderSceneNode`) checks and short-circuits. This is how the engine
handles paused-frame, dropped-frame, and one-shot single-step.


## Fight outer dispatch - FightFrameStep (0x0045c5c0)

Pure C ([src/game/fight.c](../../src/game/fight.c)). Three iterations
walking three different entity sub-trees:

```c
void FightFrameStep(void) {
    /* group 0: players + per-character entities */
    g_currentNodeIdx  = (u32)&g_fightGroupHeads[0] >> 2;
    g_xformEntityIdx  = (u32)&g_fightGroupHeads[1] >> 2;
    g_pendingNodeType = (u32)&g_fightTableA0 >> 2;
    g_eventQueueTotal = (u32)&g_fightTableB0 >> 2;
    g_fightGroupHead  = (u32)&g_fightTableC0 >> 2;
    FightFrameStep_Inner();
    if (g_framePauseFlag != 0) return;

    /* group 1: arena props + stage elements */
    /* group 2: HUD + status overlays */
    /* ... two more identical blocks with the A1/B1/C1 + A2/B2/C2 sets */
}
```

The 6-entry `g_fightGroupHeads[]` array (`0x0053a4a0`) holds three
`(head_a, head_b)` packed-ptr pairs - one per sub-tree. The
corresponding A/B/C tables are constant pointers into per-group
state structures:

| Group | TableA          | TableB          | TableC          | What                   |
|-------|-----------------|-----------------|-----------------|------------------------|
| 0     | `0x004e9250`    | `0x00542948`    | `0x004d50a4`    | Players + per-char fx  |
| 1     | `0x004e92c8`    | `0x004e9300`    | `0x004d50a8`    | Arena props + stage    |
| 2     | `0x004e9318`    | `0x0054294c`    | `0x004d50b0`    | HUD + status overlays  |

(The exact mapping is best-guess from naming and the call patterns
around each group's tables.)


## Fight inner pump - FightFrameStep_Inner (0x0045c6c0)

Naked, the entity-sibling walker. For one group, it:

1. Loads the head pair, packs them into the walk-state globals
   (`g_walkCallback`, `g_eventQueueCurrent`, `g_eventQueueWorkType`).
2. XORs head_a with head_b; if zero, exit early (no change since
   last frame).
3. Otherwise pushes esi/edi, walks the linked list off the head,
   AND-merging child masks into `g_eventQueueChild`.
4. When the queue cursor reaches the primary end, clamps to a
   secondary range.

This is the **scenegraph-driven event scatter** for one group of
entities. The merged child mask in `g_eventQueueChild` drives which
sub-handlers fire on the next `DispatchEventQueue` call.


## Event queue - the entity messaging layer

Per-frame events are stashed in a 20-entry ring buffer at
`g_eventQueueDrainBase` (`0x0053a4b8..0x0053a508`). Two cursors
form a ping-pong:

| Symbol               | Address     | Role                                  |
|----------------------|-------------|---------------------------------------|
| `g_eventQueuePending`| `0x00542048`| Where new events accumulate this tick |
| `g_eventQueueActive` | `0x0053a31c`| What `DispatchEventQueue` walks       |
| `g_eventQueueHead`   | `0x0053a2f0`| Walker cursor (advances during drain) |
| `g_eventQueueEnd`    | `0x00542054`| Cached end (= base + 80)              |
| `g_eventQueueWorkType`| `0x00542074`| Type tag captured at `AllocateNode`   |
| `g_eventQueueCurrent`| `0x00542070`| Active head value                     |
| `g_eventQueueChild`  | `0x00542080`| AND-merged child mask from the walk   |
| `g_eventQueueIdx`    | `0x00542058`| Per-iter counter                      |
| `g_eventQueueNotMask`| `0x0054207c`| Negated mask (early-out helper)       |

```c
void DispatchEventQueue(void) {
    g_eventQueueTotal = ((u32)&g_eventQueueDrainBase + 80) >> 2;
    g_xformEntityIdx  = g_eventQueueActive;
    EventQueueDrainLoop_0045c840();   /* walks pending events */
}

void DispatchEventQueue_Commit(void) {
    g_eventQueueActive = g_eventQueuePending;  /* promote pending -> active */
}
```

The "active vs pending" split is classic for fixed-tick games: this
frame's events are populated into Pending while the previous
frame's events are being drained from Active, then `Commit` swaps
at end-of-frame. No reader can be mid-walk when the swap happens
because `Commit` runs in the same single thread as the walker.

The drain loop at `0x0045c840` ([src/engine/...](../../src/engine/)
- spillage into one of the dispatch files) walks the buffer until
the active cursor reaches the cached end, dispatching each event
to its target node's handler.


## Per-player state - the four player slots

Four packed-ptr globals point at the four players' scene nodes:

| Symbol              | Address       | Role                          |
|---------------------|---------------|-------------------------------|
| `g_player1NodeIdx`  | `0x00538158`  | P1 root node (packed_ptr)     |
| `g_player2NodeIdx`  | `0x0053815c`  | P2 root node                  |
| `g_player3NodeIdx`  | `0x00538160`  | P3 root node                  |
| `g_player4NodeIdx`  | `0x00538164`  | P4 root node                  |

Each is a scenegraph node (see [scenegraph.md](scenegraph.md))
allocated at character-select time. Field offsets that `GameTick`
reads on the per-player overlay scan:

| Offset | Field           | Interpretation                              |
|--------|-----------------|---------------------------------------------|
| `+0x30`| `player_id`     | 1..4 (validated against the index)          |
| `+0x34`| `state_mask`    | OR `0x1000` when on-screen, ANDed otherwise |
| `+0x54`| `position_x`    | s32 16.16 - ground-plane X (see below)      |
| `+0x58`| `position_y`    | s32 16.16 - vertical; gravity integrates here |
| `+0x5c`| `position_z`    | s32 16.16 - ground-plane depth              |
| `+0x74`| `pose / move_state` | u32 - `0x501` is the "special" sentinel |
| `+0x84`| `task_fsm_state`| u32 - the cooperative task-FSM dispatch state (distinct from +0x74) |

The `0x501` value is checked but never written within the per-player
overlay scan - it's set elsewhere by the per-player tick. It likely
means "victory pose / fatality" - the special state that the rest
of the engine treats as inert.

#### `move_state` (+0x74) value map

Identified by which function writes each value to the **current
player node** (`g_baseSel`)`+0x74` - the writer's role names the state.
Values look packed as `category<<8 | variant`:

| Value  | Writer (function/file)            | Meaning |
|--------|-----------------------------------|---------|
| 0x404  | `combo_finisher_event_cluster`    | combo finisher move |
| 0x406  | `aerial_block_fsm_cluster`        | aerial block |
| 0x501  | (per-player tick)                 | victory pose / fatality (the inert sentinel above) |
| 0x1002 | `boss_roar_cluster` / `cinematic_c_fsm_cluster` | cinematic / boss-roar special |
| 0x4004 | `round_result_slot_init_table`    | round-result pose |

Category nibbles seen: `0x4xx` = combat moves, `0x5xx` = victory/
fatality, `0x1xxx` = cinematic/special, `0x4xxx` = round result.

Caveats: the values `0x10b / 0x112 / 0xCCC / 0x1000 / 0x1011 / 0x1015 /
0x11eb` are written only by generic scheduler primitives, so their
move meaning is unresolved. Negative writes to +0x74 (`0xffffc000` =
-0.25, by `audio_stream_fsm5_way` / `round_display_init_cluster`) are
the node-pool **polymorphism** - in those non-combat node types +0x74
is a 16.16 scalar, not a move_state (see
[node_struct.md](node_struct.md)).

**Position axes (confirmed):** `+0x54`/`+0x58`/`+0x5c` are a 16.16
position vector. `HitContactDispatcherCluster` range-checks
`dx*dx + dz*dz <= g_rangeSqLimit_0053a180` using only X(+0x54) and
Z(+0x5c) - the horizontal floor plane - while gravity adds to
Y(+0x58). Full field map in [node_struct.md](node_struct.md).

### Inter-fighter geometry (distance + facing axis)

`helper_per_player_tick` computes, each frame, the relative geometry of
the two combatants and publishes it through five globals consumed by
the reaction FSMs:

- **Distance** `g_table_00535ddc` = `sqrt(Sum d^2)` - squared deltas
  accumulated via `Mul10Tail`, then `FpuSqrtMul` (`fsqrt`). The
  computed **actor distance**; `HitReactionStateCluster` tiers its
  reaction on it (thresholds 1.0/2.0/3.0 units).
- **Facing axis** `g_fightAxisPosX/PosY` (`0x535e78`/`0x535e7c`) and
  `g_fightAxisNegX/NegY` (`0x535e70`/`0x535e74`). The "Neg" pair is
  literally the **negation** of the "Pos" pair (`neg eax` right after
  each store): a single 2D direction vector `(dx,dy)` from
  `FixedDiv16_004ab2a0` stored as `+v` and `-v` so each fighter can
  grab the sign pointing at its opponent. This is the per-frame
  **inter-fighter facing vector**; the per-player facing-sign math
  (yielding +1.0/-1.0 = `0x10000`/`0xffff0000`) reads it together with
  node `+0x6c` (see [node_struct.md](node_struct.md) "+0x6c facing
  lead").

So distance (a scalar) and the facing axis (a +/- vector pair) are the
two outputs of the same per-frame geometry pass, and together they
drive range-tiered reactions and which way each fighter turns.

### Hit / reaction cluster inventory

The hit-handling logic is spread across these named clusters. They do
**not** call each other directly - each is a node task-FSM scheduled
via continuations (see [node_struct.md](node_struct.md) "cooperative
task-FSM pattern"), reacting to flags and the `move_state` (+0x74).
Inventory for navigation (precise flag semantics still need a runtime
trace):

| Address    | Name                          | Apparent role |
|------------|-------------------------------|---------------|
| 0x004335f0 | `HitReactionStateCluster`     | hit-reaction / hitstun FSM. Dispatches on `g_table_00535ddc` thresholded at 1.0/2.0/3.0 units - that global is a **computed actor distance**: `helper_per_player_tick` accumulates squared deltas via `Mul10Tail` then `FpuSqrtMul` (`fsqrt`) and stores `sqrt(Sum dx^2)` there, so the reaction tier is chosen by range. |
| 0x00437300 | `HitFsmCluster`               | hit task-FSM wrapper (dispatch on `+0x84`, calls HitReactionStateCluster) |
| 0x0045c080 | `HitReactionCluster`          | hit-reaction handler |
| 0x0045f650 | `HitReactionDispatcher`       | flag-driven reaction dispatch (tests node `+0x40` bit 0x200, `g_dispatchSave34_0054207e` bits) |
| 0x0046c7c0 | `HitStateCluster`             | hit-state handler |
| 0x00480240 | `HitContactDispatcherCluster` | move + horizontal-distance leash (`dx^2+dz^2 <= g_rangeSqLimit`) |
| 0x004816d0 | `BlockedCounterCluster`       | 3 packed helpers: H1 decrements node `+0x64` by `0x191eb` (~1.57 in 16.16); H2 fires a paired event (id 0x26, ground-impact); H3 is a task-FSM (reads `+0x6c`/`move_state`) that tail-calls `BossArrivalSequence_00481950` (same file). Name only loosely fits - it is boss-arrival-adjacent. |
| 0x00451b90 | `JuggleFsmCluster`            | air-juggle FSM |
| 0x004539d0 | `JuggleSetupCluster`          | juggle setup |

Move-trigger writers that set `move_state` (combo finisher, aerial
block, etc.) are listed in the move_state table above.

### Per-player state blocks + health bar

Beyond the four `g_playerNNodeIdx` render-node pointers, there are two
larger **per-player fight-state blocks**, 0x320 bytes apart:

| Symbol            | Address      | Role |
|-------------------|--------------|------|
| `g_player1State`  | `0x0053a3e0` | P1 fight-state block (was `g_state4_0053a3e0`) |
| `g_player2State`  | `0x0053a700` | P2 fight-state block (was `g_state4_0053a700`) |

`HealthBarTickDriver_00458cc0` reads one of these (selected by
`g_stateFlag_00537e98` = current side) as the value that drives the
health-bar segment loop; `globals_reset_init` clears both at match
reset; the AI walk counter and `GameMode_EnterScene` (mode entry) also
use them as the per-player node base (`base >> 2` packed). The first
dword is the bar/energy value the health bar renders. (Exact split
between "true health" and "displayed bar value" still TBD.)

A second probe object exists per player: `g_gtPlayerProbe1/2`
(`0x0053803c/8038`). These look like "the opposing player's overlay
pointer" - the per-player scan checks `g_gtPlayerProbe1->fsm_state
!= 0x501` to skip updating P1 if P2 is in the special state.


## Character download workflow

`DownloadPlayerChar_Variant` (`0x0048bff0`) is the per-frame
character-asset loader for one of the four player slots:

| Symbol            | Address       | Role                                 |
|-------------------|---------------|--------------------------------------|
| `g_dlEnabledFlag` | `0x0054371c`  | 0 = skip the workflow this frame     |
| `g_dlMode`        | `0x00542004`  | Which player to download (0..3)      |
| `g_dlChar13`      | `0x00541ec4`  | P1/P3 character ID                   |
| `g_dlChar24`      | `0x00541ec8`  | P2/P4 character ID                   |
| `g_dlNalt1..4`    | `0x00537f48 ..0x0053a250` | Per-player "nalt" (skin) variant |
| `g_dlVariantTable`| `0x004d5718`  | 9-byte rows: per-character skin LUT  |

The workflow:
1. Pick which player based on `g_dlMode` (0..3 -> P1..P4)
2. Look up character (P1/P3 share `g_dlChar13`, P2/P4 share `g_dlChar24`)
3. Index `g_dlVariantTable[char_id * 9 + nalt]` to get the texture id
4. Call `LoadGeoAsset_Textures(texture_id)` to read the .geo file
   for that character/skin combo
5. Save the current node index, update player node's mesh ref,
   restore the saved node index

`DownloadPlayerChar` (`0x0048bcf0`) is the 4-player superset that
also handles the "P2/P4 auto-bump if their slot is empty" cases the
`_Variant` form skips.


## TickAllEntities - the post-fight scenegraph sweep

After `GameTick`, the per-frame work continues in `TickAllEntities`
(`0x004b9e50`, in [src/engine/tick_all.c](../../src/engine/tick_all.c) -
see [scenegraph.md](scenegraph.md) for the full description).

On the **first** tick (after `g_tickInitFlag` is 0), it walks 5
fixed entity sub-trees in sequence; on **subsequent** ticks, just
the main sub-tree at `0x538070`. Each pass primes
`(g_currentNodeIdx, g_walkCallback, g_curMask)` and calls
`Helper_TickInner` (or `Helper_TickAlt` if a sticky flag is set).

The callback for fight-mode sub-trees is `Helper_FightSceneCallback`
(`0x004ba1c0`) - in fact, that's `RenderSceneGraphIterate_004ba1c0`,
the camera-transform + frustum-cull + RenderSceneNode wrapper.

This is the unification point: **the fight FSM updates the player
node state; the scenegraph walker reads it and submits draw
entries**. There is no "compose render command list" step - the
fight FSM operates directly on the scenegraph's per-node state.


## Globals reference

### FSM top-level

| Symbol              | Address       | Role                                    |
|---------------------|---------------|-----------------------------------------|
| `g_gameState`       | `0x00ab438c`  | Current top-level UI state (0..0x1c)    |
| `g_gameMode`        | `0x00543800`  | 0 = active fight, !=0 = menu mode       |
| `g_gameStateResult` | `0x007af918`  | Last `GameStateMachine` return code     |
| `g_gsmFlag`         | `0x00543930`  | Sub-state gate for VS-mode re-arm       |
| `g_gsmActiveFlag`   | `0x00ab4334`  | Set by FSM tail = (state != 0)          |
| `g_gsmStateAa4`     | `0x00543aa4`  | Music track picked by Config-state exit |
| `g_gsmDirty1/2/3`   | `0x00ab4374/78/7c` | Per-screen dirty flags             |
| `g_gsmOut1/2/3/4`   | `0x00543810/14/18/20` | Set by FSM tail when dirty      |

### Tick state

| Symbol                | Address     | Role                                   |
|-----------------------|-------------|----------------------------------------|
| `g_frameCounter`      | `0x007af930`| Monotonic 60 Hz counter                |
| `g_logicFrameCounter` | `0x0053a79c`| Per-state-machine logic frame counter  |
| `g_framePauseFlag`    | `0x00541e6c`| Non-zero = abort rest of frame         |
| `g_logicStepFlag`     | `0x0054381c`| Reset to 0 at end of each step         |
| `g_mode4PauseGate`    | `0x004ffd78`| SW-Win pause/single-step gate          |
| `g_gtPauseMode`       | `0x00543804`| Pause sub-mode flag                    |
| `g_gtFightTickCounter`| `0x0053a498`| Increments per active-fight tick       |

### Players + per-player scratch

| Symbol               | Address       | Role                                  |
|----------------------|---------------|---------------------------------------|
| `g_player1..4NodeIdx`| `0x00538158/5c/60/64`| Player root node (packed_ptr)  |
| `g_gtPlayerProbe1/2` | `0x0053803c/8038`    | Opposing-player probe pointers |
| `g_gtPlayerEnabled`  | `0x004d5714`         | Per-frame enable mask          |
| `g_gtAxisX/Y/Z`      | `0x00ab4e44/48/4c`   | Axis lowpass scratch (s16)     |

### Fight subsystem

| Symbol                | Address       | Role                                  |
|-----------------------|---------------|---------------------------------------|
| `g_fightGroupHeads[6]`| `0x0053a4a0`  | 3 `(head_a, head_b)` packed-ptr pairs |
| `g_fightTableA0/A1/A2`| `0x004e9250/c8/318` | Per-group source A pointers     |
| `g_fightTableB0/B1/B2`| `0x00542948/4e9300/54294c` | Per-group source B       |
| `g_fightTableC0/C1/C2`| `0x004d50a4/a8/b0`  | Per-group source C              |

### Event queue

| Symbol               | Address       | Role                                  |
|----------------------|---------------|---------------------------------------|
| `g_eventQueueDrainBase`| `0x0053a4b8`| Base of 20-entry ring buffer          |
| `g_eventQueueActive` | `0x0053a31c`  | Cursor being drained this frame       |
| `g_eventQueuePending`| `0x00542048`  | Cursor being filled this frame        |
| `g_eventQueueHead`   | `0x0053a2f0`  | Drain walker cursor                   |
| `g_eventQueueEnd`    | `0x00542054`  | Cached end-of-buffer (= base + 80)    |

### Download workflow

| Symbol              | Address       | Role                                   |
|---------------------|---------------|----------------------------------------|
| `g_dlEnabledFlag`   | `0x0054371c`  | Workflow enable                        |
| `g_dlMode`          | `0x00542004`  | Which player to process (0..3)         |
| `g_dlChar13/24`     | `0x00541ec4/c8`| Shared P1/P3 and P2/P4 character IDs  |
| `g_dlNalt1..4`      | `0x00537f48/5380e0/53a178/53a250` | Per-player skin |
| `g_dlVariantTable`  | `0x004d5718`  | 9-byte-rows skin LUT                   |


## What's safe to change vs not

**Safe**:
- Renaming any of the globals above (apply consistently + `make matching`).
- Adding new states to the FSM **only if you also extend
  `g_gsmByteTable` and `g_gsmJumpTable1`**. Both tables are in
  `.text` immediately after the function - their offsets matter
  because the function loads them via absolute addresses.
- Adding new per-state helpers and wiring them in to an existing
  byte-table index, **provided the helper returns one of the
  post-action codes the FSM tail handles** (`0x45`, `0x18..0x1c`,
  `0x3`).
- Changing the `(0x8000 - axis) / 8` lowpass coefficient in
  `GameTick` - it'd shift the byte match by a few instructions but
  is contained.

**Unsafe**:
- Reordering `g_gsmByteTable[29]` or `g_gsmJumpTable1[16]`. They
  live in `.text` after `GameStateMachine` and the function
  references them by absolute address.
- Removing the audio re-arm sequence in the main-menu sub-dispatch
  tail (`Helper_AudioRelease2(0x4a)` / `Audio_PlaySoundId`).
  The `0x4a` track-id is the menu music; baking it out would change
  the byte match of the FSM tail.
- Changing the event queue size (20 entries = base + 80). Hardcoded
  in `DispatchEventQueue`'s `+ 80` calculation.
- Reordering the four `g_player[1-4]NodeIdx` slots. The per-player
  scan in `GameTick` reads them in declaration order; reordering
  changes the 4 `mov reg, [g_X]` site offsets.
- Changing the `0x501` "special state" sentinel. Read inline by the
  per-player scan; renaming would have to update the `cmp imm32` site.
- Touching the 3-group structure in `FightFrameStep`. The three
  `(A_n, B_n, C_n)` table triples are baked into the function as
  absolute address sequences; you can rename them but cannot
  introduce a 4th group without rewriting the function.


## What's still naked vs pure C

In `src/game/`:

- **Pure C** (already converted):
  `GameLogicStep`, `GameTick`, `FightFrameStep`,
  `DispatchEventQueue`, `DispatchEventQueue_Commit`.

- **Still naked**:
  `GameStateMachine` - byte-table + jump-table dispatch + hand-tuned
  audio re-arm tail; the dispatch idiom can't be reproduced from a
  natural C switch.
  `FightFrameStep_Inner` - scaled-base addressing with the table
  address kept as `addr >> 2`, asymmetric epilogue (early-out vs
  full pop).
  Most per-state helpers (`Helper_GSM_VS`, `_Tournament`, `_Practice`,
  etc.) - each has its own naked-blocking pattern (sticky flag tests,
  cross-path register threading, etc.).
  `Helper_PerPlayerTick` and friends - dense scenegraph reads with
  packed-ptr arithmetic.
  `DownloadPlayerChar` and `DownloadPlayerChar_Variant` - 4-player
  switch with shared character/nalt lookup; pure-C version diverges
  on register choice for the per-player branches.


## Where to start when modifying

1. **Add a new game mode**: pick an unused `g_gameState` value. The
   byte table only maps 0, 4-0xc and 0x18-0x1c; states 0xd-0x17 and
   0x1d+ fall through to the default no-op, so they are free. Extend
   `g_gsmByteTable` + `g_gsmJumpTable1` and add a `Helper_GSM_NewMode`
   returning one of the recognized post-codes.
2. **Skip the menu**: set `g_gameState = 0x18` (the VS / arcade fight
   handler `Helper_GSM_VS`) before `GameLogicStep`. The fight tick
   runs as if you'd selected a mode from the main menu. (NB: state 5
   is the HELP overlay, not arcade - see the verified state map above.)
3. **Force a fatal pose**: write `0x501` to a player node's `+0x74`
   field. The per-player scan in `GameTick` will skip updating that
   player; the scenegraph walker will keep rendering it. Useful for
   debugging the death animation hooks.
4. **Disable the per-frame asset download**: clear `g_dlEnabledFlag`.
   `DownloadPlayerChar_Variant` short-circuits on it; useful when
   profiling frame time.
5. **Profile event queue saturation**: log
   `g_eventQueuePending - g_eventQueueActive` (mod 20) each frame.
   Pure observation, no matching-code change.
6. **Pause everything**: set `g_framePauseFlag = 1`. Every per-frame
   helper checks it and aborts. The render still runs (the flag is
   read inside the tick path, not the present path). Useful for
   freeze-frame debugging.


## What's NOT in this subsystem

The actual gameplay logic - move recognition, hitbox checks,
animation playback, damage calculation - lives inside the per-state
helpers (`Helper_PerPlayerTick`, `Helper_TickFrame_Misc`, etc.)
and in the per-character `.geo` data. None of that is documented in
this file because:

- Per-character move tables, frame data, damage formulas: all data,
  not code. They live in the per-character `.geo` and per-game
  `.GAME` files. See `tools/geo_dump_blocks.py` for the .geo header
  table layout.
- Hitbox lookups: encoded in the `.geo` block data (per-frame AABB
  + radius), consumed by the still-naked per-player tick functions
  in the `0x00489000..0x004890ff` range.
- Move recognition (input pattern -> special move): a
  state-machine-within-the-state-machine driven by `Helper_GSM_HandleEvent`
  and the per-player input buffer. The input buffer itself is at
  `g_joyButtonState[16]` (see [scenegraph.md](scenegraph.md) for the
  reset path) and a per-player history ring whose exact location is
  TBD.

Decoding these would each take 1-2 sessions of focused per-function
analysis. The current state-machine + tick scaffolding is enough
to **port the game** without touching them: replace
`Helper_PerPlayerTick` etc. with your own implementations and the
FSM + scenegraph will keep working.
