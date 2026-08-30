/**
 * The GAME PLAY options screen - 0x4b7df0 (656b).
 *
 * Same shape as the SOUND screen (src/game/menu_sound_screen.c), with six
 * editable rows instead of four. The symbol name Helper_GSM_Options is the
 * auto-namer's guess from position; the screen's own menu table at
 * 0x4f5328 says what it is: CONTINUES, DIFFICULTY, ROUNDS TO WIN, VS
 * SCREEN, BLOOD, FATALITIES.
 *
 * Each row's action id routes through the byte table at 0x4b8190 into an
 * editor, and again through the table at 0x4b81d0 into a value formatter:
 *
 *   60 CONTINUES     0..9,  select wraps  -> "%ld"
 *   61 DIFFICULTY    0..5,  select wraps  -> one of six names, VERY EASY
 *                                            through ULTIMATE
 *   62 ROUNDS TO WIN 2..9,  select wraps to 1 rather than 0 - the original
 *                    really does treat this one differently
 *   63 VS SCREEN     toggle -> ON / OFF
 *   64 BLOOD         toggle -> ON / OFF
 *   65 FATALITIES    toggle -> KEYB FRIENDLY / ARCADE STYLE
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern int  Menu_FindNextSelectable(int cur, void *table);
extern int  Menu_FindPrevSelectable(int cur, void *table);
extern unsigned int Menu_PollNavInput(int joy_selects);
extern int  DrawMenu(void *menu_items, int selection);
extern int  Helper_Sprintf(char *buf, const char *fmt, ...);
extern void Menu_FillColonField(unsigned int *slot, const char *value);

#define g_gpFlags    (*(unsigned char *)MK4_VA(unsigned char, 0xab42e0u))
#define g_gpSel      (*(unsigned int  *)MK4_VA(unsigned int,  0xab4328u))
#define g_gpState    (*(unsigned int  *)MK4_VA(unsigned int,  0xab4358u))
#define g_menuScratch ((char *)MK4_VA(char, 0xab41c8u))

#define g_continues  (*(int *)MK4_VA(int, 0x543aa0u))
#define g_difficulty (*(int *)MK4_VA(int, 0x543a9cu))
#define g_rounds     (*(int *)MK4_VA(int, 0x543ab0u))
#define g_vsScreen   (*(int *)MK4_VA(int, 0x543aacu))
#define g_blood      (*(int *)MK4_VA(int, 0x543ab4u))
#define g_fatalities (*(int *)MK4_VA(int, 0x543a98u))

#define GP_MENU      MK4_VA(void, 0x4f5328u)
#define TXT_ON       ((const char *)MK4_VA(char, 0x4f42d8u))
#define TXT_OFF      ((const char *)MK4_VA(char, 0x4f42dcu))
#define TXT_KEYB     ((const char *)MK4_VA(char, 0x4f61a0u))
#define TXT_ARCADE   ((const char *)MK4_VA(char, 0x4f6190u))
#define FMT_LD       ((const char *)MK4_VA(char, 0x4f6164u))

typedef struct { unsigned int text; short action; short pad; } MenuRow;

/* the six difficulty labels, in the order the original stacks them */
static const unsigned int gp_difficulty_names[6] = {
    0x4f61e0u, 0x4f61d8u, 0x4f61d0u, 0x4f61c8u, 0x4f61bcu, 0x4f61b0u
};

/* left/right step with a floor and a ceiling, select wraps modulo `wrap` */
static void gp_step(int *v, unsigned int nav, unsigned int held,
                    int floor_at, int ceil_at, int wrap)
{
    if (!held && (nav & 4) && *v > floor_at)
        (*v)--;
    if (!held && (nav & 8) && *v < ceil_at)
        (*v)++;
    if (!held && (nav & 0x10))
        *v = (*v + 1) % wrap;
}

int Helper_GSM_Options(void)
{
    unsigned int nav = 0, held = 0;
    MenuRow *row;

    if ((g_gpFlags & 1) == 0) {
        g_gpFlags |= 1;
        g_gpSel = (unsigned int)Menu_FindNextSelectable(0, GP_MENU);
    }

    if (g_gpState == 0)
        g_gpState = 2;

    if (g_gpState == 2) {
        nav  = Menu_PollNavInput(1);
        held = nav & 0x8000u;

        if (!held && (nav & 1))
            g_gpSel = (unsigned int)Menu_FindPrevSelectable((int)g_gpSel, GP_MENU);
        if (!held && (nav & 2))
            g_gpSel = (unsigned int)Menu_FindNextSelectable((int)g_gpSel, GP_MENU);
        if (!held && (nav & 0x20))
            g_gpState = 3;

        row = (MenuRow *)GP_MENU + g_gpSel;
        switch (row->action) {
        case 3:
            if (!held && (nav & 0x10))
                g_gpState = 3;
            break;
        case 60: gp_step(&g_continues,  nav, held, 0, 9, 10); break;
        case 61: gp_step(&g_difficulty, nav, held, 0, 5, 6);  break;
        case 62:
            /* rounds: floor 2, ceiling 9, and select wraps to ONE */
            if (!held && (nav & 4) && g_rounds > 2)
                g_rounds--;
            if (!held && (nav & 8) && g_rounds < 9)
                g_rounds++;
            if (!held && (nav & 0x10))
                g_rounds = (g_rounds < 9) ? g_rounds + 1 : 1;
            break;
        case 63:
            if (!held && (nav & 0x1c)) g_vsScreen  = (g_vsScreen  == 0);
            break;
        case 64:
            if (!held && (nav & 0x1c)) g_blood     = (g_blood     == 0);
            break;
        case 65:
            if (!held && (nav & 0x1c)) g_fatalities = (g_fatalities == 0);
            break;
        default:
            break;
        }
    } else if (g_gpState == 3) {
        g_gpState = 0;
    }

    for (row = (MenuRow *)GP_MENU; row->text != 0; row++) {
        const char *val = 0;

        switch (row->action) {
        case 60: Helper_Sprintf(g_menuScratch, FMT_LD, g_continues); break;
        case 62: Helper_Sprintf(g_menuScratch, FMT_LD, g_rounds);    break;
        case 61: {
            int i = g_difficulty;
            if (i < 0) i = 0;
            if (i > 5) i = 5;
            val = (const char *)MK4_PTR(gp_difficulty_names[i]);
            break;
        }
        case 63: val = g_vsScreen   ? TXT_ON   : TXT_OFF;    break;
        case 64: val = g_blood      ? TXT_ON   : TXT_OFF;    break;
        case 65: val = g_fatalities ? TXT_KEYB : TXT_ARCADE; break;
        default: continue;
        }
        Menu_FillColonField(&row->text, val ? val : g_menuScratch);
    }

    DrawMenu(GP_MENU, (int)g_gpSel);
    return (int)g_gpState;
}

#endif /* NON_MATCHING */
