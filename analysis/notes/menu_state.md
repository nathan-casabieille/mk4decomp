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

                                          state 0 (main menu)
                                            sub-dispatch on `cmd` (1..8):
                                              1 -> state 8   Practice
                                              2 -> state 9   Options
                                              3 -> state 0xa Settings
                                              4 -> state 5   Arcade
                                              5 -> state 6   Options (gated by g_gsmFlag)
                                              6 -> state 0xb Credits
                                              7 -> state 0xc Config (controls)
                                              8 -> state 7   Settings (alt)
                                            tail: re-arm music id 0x4a

                                          per-state handlers:
                                            Helper_GSM_VS         (versus mode select)
                                            Helper_GSM_Tournament (tournament setup)
                                            Helper_GSM_Practice   (practice mode setup)
                                            Helper_GSM_Options    (options page)
                                            Helper_GSM_Config     (config page)
                                            Helper_GSM_HandleEvent(event/cutscene dispatch)
                                            Helper_GSM_Sub18..1C  (5 themed menu pages)
                                            Helper_GSM_Sub_Other1 (a menu page)
                                            Helper_GSM_Sub_Other2 (a menu page)

                                          tail (default):
                                            g_gsmActiveFlag = (state != 0)
```

`g_gameState` is set to `7` (TOURNAMENT) by `AppInit` (entry #22 in
the boot table) when demo mode is off. Otherwise the attract loop
drives it.

## Per-page handler shape (Sub18..Sub_Other2)

Every Sub* helper has the same skeleton, parameterised only by the
menu-items table it points at:

```c
void Helper_GSM_SubXX(void) {
    static unsigned char init_flag;   // 1 bit
    static int           selected;    // current row index
    static int           sub_state;   // 0 / 2 / 0x45

    if ((init_flag & 1) == 0) {        // first entry
        init_flag |= 1;
        selected = Menu_FindNextSelectable(0, &g_subXX_items);
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
            if (nav & 0x10) sub_state = items[selected].link;   // ENTER
            if (nav & 0x20) sub_state = 0x45;                   // BACK
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

The variations (Sub1C in particular) add per-row action callbacks
through a small embedded jump table - for example "I=14: set
g_gsmDirty1 = 1 on ENTER" so the parent state machine knows to
re-emit a sound cue or reload an asset.

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
| 0x004b8080 | `MenuPageTailDispatch_004b8080` |    360 | (TODO - common tail used by several Helper_GSM_Sub* handlers, exact pattern still unverified.) |
| 0x004b81f0 | `Helper_GSM_Config`           |      722 | State handler for the controls config page. Calls `Input_RebindKeyToAction` / `Input_RebindButtonToAction` when the user assigns a new VK / button to an action. |
| 0x004b84d0 | `Helper_GSM_HandleEvent`      |      346 | Cutscene / scripted-event dispatcher used during state transitions (returns 0x45/0x18/0x19/0x1a/0x1b/0x1c to switch to the matching menu state). |
| 0x004b8630..0x004b8a30 | `Helper_GSM_Sub18..1C` |     ~255 each | Generic menu-page handlers; each owns one menu items table (`g_gsmSub18Base_004f5090`, `g_gsmVar3_004f5018`, `g_gsmVar2_004f5050`, `g_gsmVar_004f5070`, `g_gsmHelperBase_004f4f30`). Pattern documented above. Sub1C additionally dispatches per-row action callbacks via an inline jump table. |
| 0x004b8bd0 | `Helper_GSM_Sub_Other1`       |      408 | Another menu-page handler (specific table base TBD). |
| 0x004b8d70 | `Helper_GSM_Sub_Other2`       |      311 | Another menu-page handler; table base `g_gsmVar4_004f4fd0`. |
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
| `0x004f5090` | `g_gsmSub18Base`                    | Menu items table for Sub18 (label/selectable/link triplets). |
| `0x004f5018` | `g_gsmVar3`                         | Menu items table for Sub19. |
| `0x004f5050` | `g_gsmVar2`                         | Menu items table for Sub1A. |
| `0x004f5070` | `g_gsmVar`                          | Menu items table for Sub1B. |
| `0x004f4f30` | `g_gsmHelperBase`                   | Menu items table for Sub1C (with per-row action callbacks). |
| `0x004f4fd0` | `g_gsmVar4`                         | Menu items table for Sub_Other2. |

## Menu items table layout (8 bytes per entry)

Deduced from `Menu_FindNextSelectable` / `Menu_FindPrevSelectable`
and the per-page handler's use of `items[idx].link`:

```c
struct menu_item {
    int16  label_id;    // index into the menu-string pool (UI text)
    int16  selectable;  // 1 = navigable, 0 = header/separator (skipped by nav)
    int32  link;        // 'next sub_state' value when this row is confirmed
                        // (Sub18 uses it as the new sub_state, Sub1C uses
                        //  it as an opcode to drive its inline jump table)
};
```

Termination: the search functions stop on `label_id == 0` (Asc) or
on running off the start (Desc).

## TODOs

- **Per-state -> handler mapping**. `g_gsmByteTable` is currently
  reachable as in-text data inside `GameStateMachine`. Decoding the
  29-byte translation table would let us label every state value
  (0..0x1c) with a human name (TITLE, ARCADE_CHAR_SELECT,
  PRACTICE_OPTS_PAGE, ...) and confirm which state value lands on
  which Sub18..1C handler.
- **Which menu is which Sub*?** Sub18..1C and Sub_Other1/2 each own
  one menu items table at a specific `.data` offset. The first row
  label of each table would identify the page (likely strings like
  "DIFFICULTY", "TIME LIMIT", etc). A runtime trap on
  `Menu_FindNextSelectable` would print the table base on first call.
- **`FormatMenuItemsAndDraw_004b7ce0`** is still a hand-emit byte
  stream; the role above is a hypothesis. Worth a focused decompile
  pass to confirm.
- **`MenuPageTailDispatch_004b8080`** is referenced from multiple
  Sub* handlers but its exact role (table re-init? music re-arm?
  audio gate?) is unconfirmed.
- **`Helper_GSM_HandleEvent` event ID space**. The function returns
  0x18/0x19/0x1a/0x1b/0x1c/0x45 (each switches to a state of the
  same value) - but the inputs that produce each return value
  haven't been traced. Likely tied to the cutscene packet decoder
  at `EventPacketDecoder_0045de60`.
