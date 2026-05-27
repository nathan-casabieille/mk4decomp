# MK4.EXE - Fight-flow screens (title / select / outcome)

The functions that implement MK4's between-fight screen flow - the
title/attract "press start", the character-select screens, the
loading screen, and the win/lose/champion result screens - all live
in the `0x004a2000`..`0x004a9000` region. The symbol table groups this
whole region as **`audio`**, which is wrong: these are screen/state
handlers that only touch audio incidentally (cueing voice banks and
music for the selected mode/characters). They were identified by the
on-screen text strings each one formats and draws.

This sits below the menu FSM ([menu_state.md](menu_state.md)): the
mode-select rows' `on_select` handlers (`GameMode_EnterScene`,
`EnduranceMode_Handler`, etc.) hand off into these screen handlers.
The in-match tick is in [combat_fsm.md](combat_fsm.md); the hidden
options overlay drawn from the same cluster is in
[debug_menu.md](debug_menu.md).

## Screens identified (by their on-screen text)

| Address    | Name (was)                          | On-screen text -> role |
|------------|-------------------------------------|------------------------|
| 0x004a2060 | `Title_PressStartScreen` (`AudioStoreXfer3SelfInstall`) | "DEMO MODE", "Press Any Button To Start" - title / attract screen |
| 0x004a3ce0 | `Match_OutcomeScreen` (`BossFight6StateSequencer`) | "Game Over", "Player 1 Wins", "Player 2 Wins" - 1v1 round/match result |
| 0x004a42d0 | `Screen_Loading` (`PendingMatch_004a42d0`) | "LOADING" - asset-load screen |
| 0x004a5160 | `CharSelect_CpuBattlesToggle` (`AudioByteTable7LoopChainPick`) | "SHOW CPU BATTLES", "SKIP CPU BATTLES" - arcade-ladder toggle |
| 0x004a5540 | `CharSelect_HelpPrompts` (`Audio11SlotInitLoop`) | "CHOOSE CHARACTER", "HUMAN OR CPU", "CHANGE CPU SKILL", "LEFT/RIGHT TO", "FINISHED" - select-screen prompt strip |
| 0x004a70f0 | `Match_ChampionScreen` (`PendingMatch_004a70f0`) | "CONGRATULATIONS", "IS TODAYS CHAMPION.", "PRESS ACTION KEY TO CONTINUE" - arcade winner screen |
| 0x004a76e0 | `CharSelect_TeamSize` (`AudioByteTableLoop`) | "TEAM 1 SIZE", "TEAM 2 SIZE" - team-size picker |
| 0x004a7f50 | `CharSelect_Team` (`AudioByteTable8Loop`) | "Team 1/2 Choose Character", "... Select Fighter", "... WAITING" - team character select |
| 0x004a8970 | `CharSelect_1v1` (`AudioByteTable5Loop`) | "Player 1/2 Choose Character", "... Select Fighter", "... WAITING" - 1v1 character select |
| 0x004a93c0 | `Match_TeamOutcomeScreen` (`PendingMatch_004a93c0`) | "GAME OVER", "TEAM 1/2 WINS", "TEAM 1/2 LOSES", "ACTION Keys Continue" - team-mode result |
| 0x004a9940 | `TeamMode_JoinScreen` (`PendingMatch_004a9940`) | "JOIN IN", "READY" - team/2P join-in screen; also the TEAM row's `on_select` handler (see mode table) |

(`RoundDisplayInitCluster_004a4f00` - the Kombat Rating / Body Count /
Perfect Kills / Fatalities stat readout - and the two `DebugMenu_*`
option drawers live in the same cluster; see
[debug_menu.md](debug_menu.md). They were left under their existing
names because they are packed multi-helper clusters.)

## How a screen draws its text

Same primitive as the debug menu: each screen formats label text with
`Helper_Sprintf` into a scratch buffer, then inserts it as a
scene text node (the 3D-font renderer rasterises it). The screens are
per-frame state machines (most dispatch on a `+0x84` node state word),
so the draw calls re-issue each frame while the screen is active.

## Still under shape-names in this cluster (not renamed)

These remain because they are large packed/stateful bodies where a
single role name would mislead, or are genuinely audio:

| Address    | Name | Note |
|------------|------|------|
| 0x004a62b0 | `PendingMatch_004a62b0` | 3004b; only "PRESS ACTION KEY"/"WAITING" - too generic to pin which screen |
| 0x004a2a80 / 0x004a3400 / 0x004a8ca0 | `PendingMatch_*` | large fight-setup state machines (no distinctive strings) |
| 0x004a3f50 | `AudioStreamFsm5Way` | "Game Over" - likely the game-over *music* sequence (genuinely audio) |
| 0x004a27c0 | `VoiceMixerTickDispatch` | per-frame voice mixer tick (genuinely audio) |
| 0x004a6e70 | `AudioPreloadStreamingTrack` | streaming-track preload (genuinely audio) |
| 0x004a38d0 | `LoadGeoAssetsStateMachine` | already descriptively named (geo asset loader) |

## TODOs

- **`group: audio` is wrong for the screen handlers.** The whole
  `0x004a2000`..`0x004a9000` region is tagged `audio` in symbols.yaml,
  but it's the fight-flow/select state machine that *uses* audio. A
  cleaner split would tag the screen handlers `game.flow` (or similar)
  and leave only the genuine voice/mixer/stream functions as `audio`.
  Deferred - the boundary is interleaved and `group` is cosmetic
  (does not affect the byte-identical build).
- **Mode -> screen routing.** Confirm each mode row's full screen
  sequence (e.g. ARCADE: select -> CpuBattles toggle -> load ->
  fight -> outcome -> champion). The `on_select` handlers in the mode
  table ([menu_state.md](menu_state.md)) are the entry points.
- **`PendingMatch_004a62b0`** (the 3004-byte "PRESS ACTION KEY" screen)
  is the largest unidentified screen - likely the VS / pre-fight
  screen. Worth a focused disassembly.
