/**
 * Menu state machine — drives main menu navigation, character select, etc.
 *
 * Distinct from the active-fight tick (see game/tick.h). Both run
 * every frame in parallel; only one is "active" depending on
 * g_gameMode.
 */
#ifndef MK4_GAME_STATEMACHINE_H
#define MK4_GAME_STATEMACHINE_H

#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* g_gameState values (top-level UI screens). */
#define GAMESTATE_MAINMENU        0
#define GAMESTATE_TRANSITION      4
#define GAMESTATE_ARCADE          5
#define GAMESTATE_VS              6
#define GAMESTATE_TOURNAMENT      7
#define GAMESTATE_PRACTICE        8
#define GAMESTATE_OPTIONS         9
#define GAMESTATE_CONFIG          10  /* 0xa */
#define GAMESTATE_CREDITS         11  /* 0xb */
#define GAMESTATE_SETTINGS        12  /* 0xc */

/* Sub-states 0x18..0x1c — reachable from VS state's result codes. */
#define SUBSTATE_CHAR_SELECT_1    0x18
#define SUBSTATE_CHAR_SELECT_2    0x19
#define SUBSTATE_STAGE_SELECT     0x1a
#define SUBSTATE_PRE_FIGHT_INTRO  0x1b
#define SUBSTATE_GFX_OPTIONS      0x1c

/* === API ==================================================== */

s32 GameStateMachine(s32 cmd);                           /* 0x004b6340 */

void DrawMenu(void *menu_items, s32 selection);          /* 0x004b65c0 */

/* === Globals ================================================ */

extern s32 g_gameState;        /* 0x00ab438c */

#ifdef __cplusplus
}
#endif

#endif /* MK4_GAME_STATEMACHINE_H */
