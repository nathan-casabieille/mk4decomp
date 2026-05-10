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

/* Per-call printf-like helper used by DownloadPlayerChar_Variant.
 * Compiles to a single `ret` in the shipping build (debug callout
 * compiled out). */
void Helper_DownloadDebugPrint(const char *fmt, ...);    /* 0x0048bfe0 */

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

/* Full DownloadPlayerChar (the 4-player superset that handles the
 * "p2/p4 char auto-bump" cases the _Variant skips). */
void DownloadPlayerChar(void);                            /* 0x0048bcf0 */

/* Per-frame "is the download workflow active" flag - skips out
 * immediately if zero. */
extern u8  g_dlEnabledFlag;     /* 0x0054371c */

/* Selects which player's variant pass to run on this entry
 * (0..3). Persists across frames so consecutive frames can chain. */
extern u32 g_dlMode;            /* 0x00542004 */

/* Sticky scratch flags read on each "edi" reload (nalt fallback). */
extern u32 g_dlSomeFlag1;       /* 0x0053a510 */
extern u32 g_dlSomeFlag2;       /* 0x0052aafc */

/* Two more sticky bookkeeping slots reset each call. */
extern u32 g_dlState;           /* 0x00541e34 */
extern u32 g_dlAux;             /* 0x00541e38 */

/* Four "saved current-node-index" slots, written before each
 * LoadGeoAsset_Textures call so the cleanup tail can restore. */
extern u32 g_dlSavedNodeIdx[4]; /* 0x00541ed4 .. 0x00541ee0 */

/* === DrawMenu state ========================================= */

/* DrawMenu remembers the previous-frame menu pointer to detect a
 * fresh open (and reset the slide-in animation counter). The
 * "current" + "counter" pair drives the per-frame animation. */
extern void *g_menuCurrent;     /* 0x00ab433c - current menu pointer */
extern void *g_menuPrev;        /* 0x00ab4340 - previous-frame menu pointer */
extern s32   g_menuCounter;     /* 0x00ab4344 - 0..100 anim counter */
extern s32   g_menuExtraDelta;  /* 0x00ab4348 - cursor extra-delta */
extern s32   g_menuExtraSign;   /* 0x004f579c */

/* Cursor box render state - DrawMenu populates this before calling
 * Helper_DrawCursor(out_buf). 28 bytes laid out as:
 *   +0..+7   scratch / vertices,
 *   +8..+0xb cur_x.s16 / cur_x_delta.s16,
 *   +0xc..   ... (mostly written-not-read fields). */
extern u8    g_menuCursorBuf[];     /* 0x00ab41a8 */

/* Helpers called by DrawMenu. */
void Helper_GetMenuExtents(s32 *out_w, s32 *out_h);     /* 0x004b3dc0 */
void Helper_DrawMenuText(s32 x, s32 y, const char *txt,
                         s32 b, s32 c);                  /* 0x004b21d0 */
void Helper_DrawCursor(u8 *cursor_buf);                  /* 0x004c3360 */
void Helper_DrawMenu_PostRender(s32 maxw, s32 cur_x,
                                s32 cur_y_save,
                                void *menu_items);        /* 0x004b6880 */

/* === GameStateMachine support =============================== */

/* Switch dispatch tables (data in .text, immediately after the
 * function's body - 16-byte aligned). MASM emits `8a 81 + reloc`
 * for `mov al, [ecx + byte_table]` and `ff 24 85 + reloc` for the
 * `jmp [eax*4 + jump_table]` indirect dispatches. */
extern u8  g_gsmByteTable[];     /* 0x004b6580 (29 bytes) */
extern u32 g_gsmJumpTable1[];    /* 0x004b6540 (16 entries) */
extern u32 g_gsmJumpTable2[];    /* 0x004b65a0 (8 entries) */

/* Sub-state flag the (state,cmd) dispatch checks before re-arming
 * GAMESTATE_VS. */
extern u32 g_gsmFlag;            /* 0x00543930 */

/* Various dispatch-output globals written by per-state helpers. */
extern u32 g_gsmStateAa4;        /* 0x00543aa4 */
extern u32 g_gsmDirty1;          /* 0x00ab4374 */
extern u32 g_gsmDirty2;          /* 0x00ab4378 */
extern u32 g_gsmDirty3;          /* 0x00ab437c */
extern u32 g_gsmOut1;            /* 0x00543818 */
extern u32 g_gsmOut2;            /* 0x00543814 */
extern u32 g_gsmOut3;            /* 0x00543810 */
extern u32 g_gsmOut4;            /* 0x00543820 */
extern u32 g_gsmActiveFlag;      /* 0x00ab4334 */

/* Per-state helper functions. */
void Helper_AudioRelease2(s32 channel);                  /* 0x004c3490 */
void Helper_AudioStartMusic(s32 a, s32 b, s32 c);        /* 0x004c3960 */
s32  Helper_GSM_HandleEvent(void);                       /* 0x004b84d0 */
s32  Helper_GSM_VS(void);                                /* 0x004b6900 */
s32  Helper_GSM_Tournament(void);                        /* 0x004b7260 */
s32  Helper_GSM_Practice(void);                          /* 0x004b7b10 */
s32  Helper_GSM_Options(void);                           /* 0x004b7df0 */
s32  Helper_GSM_Config(void);                            /* 0x004b81f0 */
void Helper_GSM_PlayMusic(s32 track);                    /* 0x004b40a0 */
s32  Helper_GSM_Sub18(s32 cmd);                          /* 0x004b8630 */
s32  Helper_GSM_Sub19(s32 cmd);                          /* 0x004b8730 */
s32  Helper_GSM_Sub1A(s32 cmd);                          /* 0x004b8830 */
s32  Helper_GSM_Sub1B(s32 cmd);                          /* 0x004b8930 */
s32  Helper_GSM_Sub1C(s32 cmd);                          /* 0x004b8a30 */
s32  Helper_GSM_Sub_Other1(s32 cmd);                     /* 0x004b8bd0 */
s32  Helper_GSM_Sub_Other2(s32 cmd);                     /* 0x004b8d70 */
void Helper_GSM_Reset(void);                             /* 0x004b5840 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_GAME_STATEMACHINE_H */
