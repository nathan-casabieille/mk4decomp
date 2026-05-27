# MK4.EXE - Menu state machine

How `g_gameState` drives every front-end screen (title, mode select,
options, controls, credits, attract loop) and how the per-page
handlers consume `Menu_PollNavInput` to navigate them.

The fight FSM and the per-mode mode logic (versus, tournament,
practice) are documented in [combat_fsm.md](combat_fsm.md). This
document covers the menu/UI layer above them.

## Top-level dispatch

```
   [each frame, from GameLogicStep]      GameStateMachine(cmd)    0x004b6340
                                          state = g_gameState (0..0x1c)
                                          dispatch_index = g_gsmByteTable[state]
                                          jump to g_gsmJumpTable1[dispatch_index]:

   state 0 + cmd 1..8: open an overlay/dialog (cmd is a direct screen
                       request, e.g. F1 -> cmd 1 -> HELP):
                         cmd 1 -> state 5   Menu_HelpScreen
                         cmd 2 -> state 6   Helper_GSM_HandleEvent (gated)
                         cmd 3 -> state 7   Menu_PauseMenu
                         cmd 4 -> state 9   Menu_Direct3DUnavailableDialog
                         cmd 5 -> state 0xa Menu_DirectDrawUnavailableDialog
                         cmd 6 -> state 8   Menu_GlideUnavailableDialog
                         cmd 7 -> state 0xb Menu_InsertCDDialog
                         cmd 8 -> state 0xc Menu_ColorDepthErrorDialog
                       tail: re-arm menu music id 0x4a

   state -> handler (verified via g_gsmByteTable -> g_gsmJumpTable1):
     0x05 Menu_HelpScreen           0x08 Menu_GlideUnavailableDialog
     0x06 Helper_GSM_HandleEvent    0x09 Menu_Direct3DUnavailableDialog
     0x07 Menu_PauseMenu            0x0a Menu_DirectDrawUnavailableDialog
                                    0x0b Menu_InsertCDDialog
                                    0x0c Menu_ColorDepthErrorDialog
     0x18 Helper_GSM_VS             0x1b Helper_GSM_Options
     0x19 Helper_GSM_Tournament     0x1c Helper_GSM_Config
     0x1a Helper_GSM_Practice

                                          tail (default):
                                            g_gsmActiveFlag = (state != 0)
```

NOTE: the gameplay modes (VS / Tournament / Practice / Options /
Config) are at states **0x18-0x1c**, and the help/error/pause dialogs
at **0x05-0x0c**. The `cmd` argument selects a dialog/overlay (F1 =
HELP), NOT a gameplay mode - those are entered from the state-0
`DrawMenu` row selection. (An earlier revision had this backwards;
the mapping above is decoded directly from the byte + jump tables.)

`g_gameState` is initialised by `AppInit` (entry #22 in the boot
table) when demo mode is off; otherwise the attract loop drives it.

## Per-page handler shape (the 7 Menu_* dialogs)

Every page helper (`Menu_HelpScreen`, the three renderer-unavailable
dialogs, `Menu_PauseMenu`, `Menu_ColorDepthErrorDialog`,
`Menu_InsertCDDialog`) has the same skeleton, parameterised only by
the menu-items table it points at:

```c
void Menu_SomePage(void) {
    static unsigned char init_flag;   // 1 bit
    static int           selected;    // current row index
    static int           sub_state;   // 0 / 2 / 0x45

    if ((init_flag & 1) == 0) {        // first entry
        init_flag |= 1;
        selected = Menu_FindNextSelectable(0, &g_page_items);
    }

    switch (sub_state) {
    case 0:                            // arming
        sub_state = 2;
        break;
    case 2:                            // active - read input
        unsigned nav = Menu_PollNavInput(1);
        bool repeat = (nav & 0x8000);
        if (!repeat) {
            if (nav & 0x01) selected = Menu_FindPrevSelectable(selected, &items);
            if (nav & 0x02) selected = Menu_FindNextSelectable(selected, &items);
            if (nav & 0x10) sub_state = items[selected].action_code; // ENTER
            if (nav & 0x20) sub_state = 0x45;                        // BACK
        }
        break;
    case 0x45:                          // exit page
        sub_state = 0;
        break;
    }

    DrawMenu(&items, selected);
    return sub_state;
}
```

The variations (`Menu_PauseMenu` in particular) add per-row action
callbacks through a small embedded jump table - for example the QUIT
MATCH row sets `g_gsmDirty1 = 1` on ENTER so the parent state machine
knows to tear down the match and return to the title.

## Functions in this subsystem

| Address    | Name                          | Size (b) | Role |
|------------|-------------------------------|---------:|------|
| 0x004b6340 | `GameStateMachine`            |      640 | Per-frame top-level dispatcher. Switches on `g_gameState` (0..0x1c) via a byte-to-index table + 16-entry jump table. State 0 sub-dispatches `cmd` (1..8) to 8 main-menu destinations; other states call one of the `Helper_GSM_*` page handlers below. Tail computes `g_gsmActiveFlag = (state != 0)`. |
| 0x004b62c0 | `Menu_FindPrevSelectable`     |       55 | Walks a menu-items table (8-byte stride, fields: label / selectable / link) backwards from `cur - 1` until it finds an entry with `selectable == 1`. Returns -1 to wrap to the end. |
| 0x004b6300 | `Menu_FindNextSelectable`     |       58 | Same shape, walks forward from `cur + 1`. Used together for keyboard up/down nav. |
| 0x004b65c0 | `DrawMenu`                    |      691 | Renders a menu items table at the current scroll/selected position; handles highlight, scroll-into-view, and per-row formatting. |
| 0x004b6880 | `Helper_DrawMenu_PostRender`  |      114 | Post-render hook for special effects (e.g. flashing 'PRESS START' on the title page). |
| 0x004b6900 | `Helper_GSM_VS`               |     1820 | State handler for the versus-mode character/stage select screen. |
| 0x004b7020 | `Menu_PollNavInput`           |      312 | Polls keyboard nav VKs + 2 selected joysticks, returns a packed nav bitmask with bit 0x8000 = auto-repeat. See [input.md](input.md). |
| 0x004b7160 | `Menu_FillColonField`         |       73 | String template helper: walks `*p_str` until the first `:`, then overwrites every following byte with the next char from `value_str` (space-pads if value runs out). Renders settings rows like `MUSIC VOL:  N  `. |
| 0x004b71b0 | `Input_RebindKeyToAction`     |      176 | Controls-config helper: scans the 13-slot per-player keyboard binding table at `0x543ab8..0x543b18` for any slot equal to the user's new VK and swaps it with the previous value at `*p_target` before storing the new VK. Ensures no two actions share a VK. See [input.md](input.md). |
| 0x004b7260 | `Helper_GSM_Tournament`       |     2004 | State handler for the tournament setup screen (character roster, bracket). |
| 0x004b7a40 | `Input_RebindButtonToAction`  |      193 | Joystick analog of `Input_RebindKeyToAction`. Scans the 9-slot button binding table at `0x543b20..b60` (per-player via the `idx` argument). Same swap semantics. |
| 0x004b7b10 | `Helper_GSM_Practice`         |      464 | State handler for the practice-mode setup screen. |
| 0x004b7ce0 | `FormatMenuItemsAndDraw_004b7ce0` | 272  | (TODO - hand-rolled byte-stream, exact role still unclear; appears to fetch a row from `g_dispatchVar40_004d52d8` and format it via `Menu_FillColonField`.) |
| 0x004b7df0 | `Helper_GSM_Options`          |      656 | State handler for the audio/video options page. |
| 0x004b8080 | `Menu_FillOptionValues` |    360 | Options-page value formatter (was `MenuPageTailDispatch`). Walks the options rows; per row, a jump table on the row type (`[row+4] - 0x3c`, 0..5) picks the value string - ON/OFF, difficulty name ("VERY EASY".."ULTIMATE"), control style ("ARCADE STYLE"/"KEYB FRIENDLY"), or an sprintf'd number - and fills it after the colon via `Menu_FillColonField`. Called as the render tail of `Helper_GSM_Options`/`Config`. |
| 0x004b81f0 | `Helper_GSM_Config`           |      722 | State handler for the controls config page. Calls `Input_RebindKeyToAction` / `Input_RebindButtonToAction` when the user assigns a new VK / button to an action. |
| 0x004b84d0 | `Helper_GSM_HandleEvent`      |      346 | Cutscene / scripted-event dispatcher used during state transitions (returns 0x45/0x18/0x19/0x1a/0x1b/0x1c to switch to the matching menu state). |
| 0x004b8630 | `Menu_HelpScreen`             |      255 | HELP overlay (table `0x4f5090`): "MORTAL KOMBAT 4 / (C) 1997 MIDWAY / F1-HELP / F2-OPTIONS / F4-PAUSE & QUIT". |
| 0x004b8730 | `Menu_GlideUnavailableDialog` |      255 | "GLIDE 3D NOT AVAILABLE / TRY INSTALLING THE LATEST GLIDE DRIVERS / PRESS ENTER TO CONTINUE" (table `0x4f5018`). Shown when the F5 Glide renderer fails to init. |
| 0x004b8830 | `Menu_Direct3DUnavailableDialog` |   255 | "DIRECT3D NOT AVAILABLE / PRESS ENTER TO CONTINUE" (table `0x4f5050`). F6 D3D init failure. |
| 0x004b8930 | `Menu_DirectDrawUnavailableDialog` | 255 | "DIRECT-DRAW NOT AVAILABLE / PRESS ENTER TO CONTINUE" (table `0x4f5070`). DDraw init failure. |
| 0x004b8a30 | `Menu_PauseMenu`              |      408 | In-match PAUSE menu (table `0x4f4f30`): "PAUSED / CONTINUE MATCH (20) / MOVES LIST (21) / QUIT MATCH (23)". The action codes drive its inline jump table (sets g_gsmDirty1..3). |
| 0x004b8bd0 | `Menu_ColorDepthErrorDialog`  |      408 | "THE GAME CANNOT RUN IN THIS WINDOW BECAUSE YOUR DISPLAY IS NOT IN A HIGH OR TRUE COLOR MODE / INSTEAD, TRY A FULLSCREEN MODE BY PRESSING:" (table `0x4f4f60`). Shown for windowed 8-bit-color displays. |
| 0x004b8d70 | `Menu_InsertCDDialog`         |      311 | "TO PLAY MORTAL KOMBAT 4 YOU MUST CLOSE ALL OTHER CD APPLICATIONS AND INSERT THE GAME CD / RESCAN CD (17) / DEMO MODE (18) / EXIT GAME (19)" (table `0x4f4fd0`). |
| 0x004ad810 | `Helper_GSM_PlayMusic`        |       - | Menu-side music control. Called from `GameStateMachine`'s tail when transitioning between states (each state has a music id; switching states cues the new track). |

## Globals

| VA           | Name                                | Meaning |
|--------------|-------------------------------------|---------|
| `0x00aa3a90` | `g_gameState`                       | Current top-level menu/game state (0..0x1c). 0 = idle (main menu visible), 7 = tournament, see the boot init call `GameStateMachine(7)`. |
| `0x004b6541` | `g_gsmByteTable` (in-text data)     | 29-byte state-to-jump-index translation table embedded at the tail of `GameStateMachine`. |
| `0x004b6565` | `g_gsmJumpTable1` (in-text data)    | 16-entry jump table indexed by `g_gsmByteTable[state]`. |
| `0x004b6580` | `g_gsmJumpTable2` (in-text data)    | 8-entry jump table for the main-menu sub-dispatch on `cmd`. |
| (g_gsm*Flag) | `g_gsmActiveFlag`                   | 1 iff `g_gameState != 0`. Read by `MainLoopStep` to know if the fight is paused for a menu. |
| (g_gsm*Out)  | `g_gsmOut1..4`, `g_gsmDirty1..3`    | Edge-trigger shadows: when the per-page handler sets a dirty flag (e.g. user changed audio volume), the next `GameStateMachine` invocation publishes the change into the corresponding Out latch. |
| `0x004f5090` | `g_gsmSub18Base`                    | Items table for `Menu_HelpScreen`. |
| `0x004f5018` | `g_gsmVar3`                         | Items table for `Menu_GlideUnavailableDialog`. |
| `0x004f5050` | `g_gsmVar2`                         | Items table for `Menu_Direct3DUnavailableDialog`. |
| `0x004f5070` | `g_gsmVar`                          | Items table for `Menu_DirectDrawUnavailableDialog`. |
| `0x004f4f30` | `g_gsmHelperBase`                   | Items table for `Menu_PauseMenu` (with per-row action callbacks). |
| `0x004f4f60` | (Menu_ColorDepthErrorDialog table) | Items table for `Menu_ColorDepthErrorDialog`. |
| `0x004f4fd0` | `g_gsmVar4`                         | Items table for `Menu_InsertCDDialog`. |

## Menu items table layout (8 bytes per entry)

Deduced from `Menu_FindNextSelectable` / `Menu_FindPrevSelectable`
and the per-page handler's use of `items[idx].link`:

```c
struct menu_item {            // 8 bytes (confirmed by dumping the tables)
    char  *label;       // direct pointer to the UI string (NOT an index)
    uint16 action_code; // 1 = plain text line; other values are the
                        //   selectable action ID (e.g. PAUSE menu uses
                        //   20/21/23, the dialogs use 0x45 = 'press
                        //   ENTER to dismiss'). 0 in label terminates.
    uint16 link;        // secondary flags / next-state hint
};
```

Termination: the search functions stop on a zero `label` pointer
(Asc) or on running off the start (Desc). Selectable rows are those
whose `action_code` marks them navigable; pure-text/header rows are
skipped during up/down navigation.

## TODOs

- ~~**Per-state -> handler mapping**~~ - DONE. Decoded
  `g_gsmByteTable` (state -> jt index), `g_gsmJumpTable1` (index ->
  dispatch label), and the `call` each label makes, all from the EXE.
  The verified map is in the dispatch diagram above and in
  [combat_fsm.md](combat_fsm.md) / [architecture.md](architecture.md).
  Key correction: gameplay modes are at 0x18-0x1c, dialogs at
  0x05-0x0c (earlier revisions had these swapped).
- ~~**What enters states 0x18-0x1c?**~~ - ANSWERED. There is no direct
  `mov g_gameState, 0x18` anywhere; the gameplay states arrive as a
  handler **return code**. `Helper_GSM_HandleEvent` (state 6) returns
  0x18/0x19/0x1a/0x1b/0x1c, and `GameStateMachine`'s `case_handle_event`
  block compares the return value and does `mov g_gameState, eax` for
  each (the 5 such writes in [statemachine.c](../../src/game/statemachine.c)
  lines 87-103). A return of 0x45 instead routes back to state 4
  (menu redraw). So the mode-select menu feeds its choice through
  `Helper_GSM_HandleEvent`'s return value, not through the `cmd` table.
- ~~**Mode-select item table**~~ - DECODED. The main mode menu is a
  table of **28-byte records** starting at `0x004f308c`. Per-record
  layout (confirmed against the EXE):

  | Off | Field | Notes |
  |----:|-------|-------|
  | +0x00 | `char *label` | the row text |
  | +0x04 | (0) | unused / second-label slot |
  | +0x08 | `ypos << 16` | screen Y in 16.16 (rows step ~0x16) |
  | +0x0c | `0x00010000` | scale 1.0 (16.16) |
  | +0x10 | flags | low byte = row index 0..4; high byte 2..5 |
  | +0x14 | `void (*on_select)()` | per-row handler, invoked when chosen |
  | +0x18 | `int row_id` | menu row id (NOT a g_gameState value) |

  The six selectable rows + their handlers and ids:

  | Row | on_select VA | row_id |
  |-----|-------------|-------:|
  | `ARCADE`     | `0x004a7620` | 0x0f |
  | `TEAM`       | `0x004a99d0` | 0x10 |
  | `ENDURANCE`  | `0x004a5290` (`EnduranceMode_Handler`) | 0x12 |
  | `TOURNAMENT` | `0x004a2720` (`GameMode_EnterScene`) | 0x13 |
  | `PRACTICE`   | `0x004a27b0` (`GameMode_EnterScene`+0x90) | 0x14 |
  | `EXIT GAME`  | `0` (none)   | 0x15 |

  Trailing rows (flags `0xffff`, non-selectable) are the footer hint
  text: "UP/DOWN ... TO CHOOSE", "ACTION KEYS ... SELECT".

  The `on_select` handlers live in the `0x004a2000`..`0x004a9000`
  cluster that the symbol table mislabels as "audio" - they are
  actually **mode-entry / scene-setup routines**. Verified by reading
  `0x004a2720` (renamed `GameMode_EnterScene`; the TOURNAMENT handler,
  shared with PRACTICE at the `+0x90` sub-entry): it branches on
  `g_gtModeFlag`, sets the node cursors, clears `g_dlMode`, and
  tail-calls the match-setup chain.
  Most are packed multi-entry / stateful handlers (e.g. `EnduranceMode_Handler` `0x004a5290`
  is a multi-state per-frame handler), so they are documented here
  rather than renamed - a clean single-role name would misrepresent
  the packed bodies. See [debug_menu.md](debug_menu.md) for the rest
  of this cluster (the option-toggle drawers share the same region).
- ~~**Which menu is which Sub\*?**~~ - DONE. Identified by dumping each
  handler's menu-items table from the EXE and reading the row strings:
  HELP overlay, the three renderer-unavailable dialogs, the in-match
  PAUSE menu, the windowed-color-depth error, and the insert-CD
  dialog. Renamed `Helper_GSM_Sub18/19/1A/1B/1C/Other1/Other2` to the
  `Menu_*` names in the function table above.
- **`FormatMenuItemsAndDraw_004b7ce0`** is still a hand-emit byte
  stream; the role above is a hypothesis. Worth a focused decompile
  pass to confirm.
- ~~**`Menu_FillOptionValues`** role~~ - DONE. It is the options-page
  value-column formatter (see the function table above): per options
  row a jump table picks ON/OFF / difficulty name / control style / a
  number and fills it via `Menu_FillColonField`.
- **`Helper_GSM_HandleEvent` event ID space**. The function returns
  0x18/0x19/0x1a/0x1b/0x1c/0x45 (each switches to a state of the
  same value) - but the inputs that produce each return value
  haven't been traced. Likely tied to the cutscene packet decoder
  at `EventPacketDecoder_0045de60`.
