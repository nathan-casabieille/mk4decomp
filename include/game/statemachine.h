/**
 * Menu state machine - drives main menu navigation, character select, etc.
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

/* Sub-states 0x18..0x1c - reachable from VS state's result codes. */
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

/* === Player character download ============================== */

/* Per-frame helper that prints a "DOWNLOAD Player N ..." debug
 * string for one of the four players (selected by g_eventQueueCurrent),
 * then loads that player's GeoAsset textures via LoadGeoAsset_Textures.
 * The four players share two character slots: P1+P3 read g_dlChar13,
 * P2+P4 read g_dlChar24; nalt slots are per-player. */
void DownloadPlayerChar_Variant(void);                   /* 0x0048bff0 */

/* Per-call printf-like helper used by DownloadPlayerChar_Variant. */
s32  Helper_DownloadDebugPrint(const char *fmt, ...);    /* 0x0048bfe0 */

/* Setup helper invoked just before LoadGeoAsset_Textures. */
void Helper_DownloadSetup(void);                         /* 0x0048bc40 */

extern s32 g_dlChar13;          /* 0x00541ec4 - P1/P3 character */
extern s32 g_dlChar24;          /* 0x00541ec8 - P2/P4 character */
extern s32 g_dlNalt1;           /* 0x00537f48 - P1 nalt */
extern s32 g_dlNalt2;           /* 0x005380e0 - P2 nalt */
extern s32 g_dlNalt3;           /* 0x0053a178 - P3 nalt */
extern s32 g_dlNalt4;           /* 0x0053a250 - P4 nalt */

/* 9-byte rows of "valid texture id" lookup; one row per character,
 * indexed by [char + nalt*4 + base]. */
extern s8  g_dlVariantTable[];  /* 0x004d5718 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_GAME_STATEMACHINE_H */
