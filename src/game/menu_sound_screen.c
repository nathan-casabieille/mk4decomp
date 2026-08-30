/**
 * The SOUND options screen and the two leaves every options screen needs.
 *
 * This is one of the five mode screens the in-game menu dispatches to
 * (state 26). All five were hollow, so selecting anything in the visible
 * OPTIONS menu led to a blank frame. This is the smallest of them and it
 * carries the whole shape the others repeat.
 *
 * Helper_GSM_Practice - 0x4b7b10 (464b). Despite the symbol name (the
 * auto-namer guessed from position, and the menu table proves otherwise)
 * this is the SOUND screen: its entries are SOUNDFX VOLUME, SOUNDFX,
 * CD MUSIC VOLUME and CD MUSIC.
 *
 *   On first entry it latches bit 0 of the screen flags and seeds the
 *   selection with the first selectable row. Then, per tick:
 *     state 0 -> becomes state 2 and falls straight into it
 *     state 2 -> poll navigation; up / down move the selection, Back
 *                leaves (state 3); then the SELECTED ROW's action id
 *                routes through the byte table at 0x4b7da4 into one of
 *                four editors - two volumes stepped by ten between 0 and
 *                100, two ON/OFF toggles - or the "leave on select" case
 *     state 3 -> back to state 0
 *   Every tick then rebuilds the labels: each row whose action is in
 *   0x38..0x3b gets its "???" placeholder overwritten with the current
 *   value, and DrawMenu paints the result.
 *
 * Menu_FillColonField - 0x4b7160 (73b): overwrite the characters AFTER the
 *   first colon in a row's label with a value string, padding with spaces
 *   once the value runs out. That is how "SOUNDFX : ??" becomes
 *   "SOUNDFX : ON".
 *
 * Helper_Sprintf - 0x4c5580 (104b): the game's sprintf. The original is a
 *   thin wrapper over the MSVC CRT's formatter; a port has nothing to gain
 *   from transcribing that, so this is the host's vsnprintf with the same
 *   contract (returns the character count, always terminates).
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include <stdarg.h>
#include <stdio.h>
#include "portable/mem_model.h"

extern int  Menu_FindNextSelectable(int cur, void *table);
extern int  Menu_FindPrevSelectable(int cur, void *table);
extern unsigned int Menu_PollNavInput(int joy_selects);
extern int  DrawMenu(void *menu_items, int selection);

#define g_menuFlags8   (*(unsigned char *)MK4_VA(unsigned char, 0xab4318u))
#define g_menuSel      (*(unsigned int  *)MK4_VA(unsigned int,  0xab42e4u))
#define g_menuState    (*(unsigned int  *)MK4_VA(unsigned int,  0xab4354u))
#define g_menuScratch  ((char *)MK4_VA(char, 0xab41c8u))

#define g_sfxVolume    (*(int *)MK4_VA(int, 0x543a90u))
#define g_sfxOn        (*(int *)MK4_VA(int, 0x543a8cu))
#define g_cdVolume     (*(int *)MK4_VA(int, 0x543a88u))
#define g_cdOn         (*(int *)MK4_VA(int, 0x543a84u))

#define SOUND_MENU     MK4_VA(void, 0x4f52d8u)
#define TXT_ON         ((const char *)MK4_VA(char, 0x4f42d8u))
#define TXT_OFF        ((const char *)MK4_VA(char, 0x4f42dcu))
#define FMT_PERCENT    ((const char *)MK4_VA(char, 0x4f6188u))
#define FMT_STRING     ((const char *)MK4_VA(char, 0x4f4338u))

/* one menu row: a VA to the label, then a 16-bit action id */
typedef struct { unsigned int text; short action; short pad; } MenuRow;

int Helper_Sprintf(char *buf, const char *fmt, ...)
{
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = vsnprintf(buf, 0x7fffffff, fmt, ap);
    va_end(ap);
    return n;
}

void Menu_FillColonField(unsigned int *slot, const char *value)
{
    char *s = (char *)MK4_PTR(*slot);
    int seen_colon = 0;
    int i = 0;

    if (s[0] == 0)
        return;
    while (s[i] != 0) {
        if (s[i] == ':') {
            if (!seen_colon) {
                seen_colon = 1;
                i++;
                s = (char *)MK4_PTR(*slot);
                continue;
            }
        } else if (!seen_colon) {
            s = (char *)MK4_PTR(*slot);
            i++;
            continue;
        }
        s[i] = *value ? *value++ : ' ';
        s = (char *)MK4_PTR(*slot);
        i++;
    }
}

/* step a 0..100 volume by ten, the way both volume rows do */
static void snd_step_volume(int *v, unsigned int nav, unsigned int held)
{
    int cur = (*v / 10) * 10;           /* the original's magic-divide by 10 */

    if (!held && (nav & 4) && cur >= 0x14)
        cur -= 10;
    if (!held && (nav & 8) && cur <= 0x5a)
        cur += 10;
    if (cur != *v)
        *v = cur;
}

int Helper_GSM_Practice(void)
{
    unsigned int nav = 0, held = 0;
    MenuRow *row;

    if ((g_menuFlags8 & 1) == 0) {
        g_menuFlags8 |= 1;
        g_menuSel = (unsigned int)Menu_FindNextSelectable(0, SOUND_MENU);
    }

    if (g_menuState == 0)
        g_menuState = 2;

    if (g_menuState == 2) {
        nav  = Menu_PollNavInput(1);
        held = nav & 0x8000u;

        if (!held && (nav & 1))
            g_menuSel = (unsigned int)Menu_FindPrevSelectable((int)g_menuSel, SOUND_MENU);
        if (!held && (nav & 2))
            g_menuSel = (unsigned int)Menu_FindNextSelectable((int)g_menuSel, SOUND_MENU);
        if (!held && (nav & 0x20))
            g_menuState = 3;

        row = (MenuRow *)SOUND_MENU + g_menuSel;
        switch (row->action) {
        case 3:                                   /* leave on select */
            if (!held && (nav & 0x10))
                g_menuState = 3;
            break;
        case 0x38: snd_step_volume(&g_sfxVolume, nav, held); break;
        case 0x3a: snd_step_volume(&g_cdVolume,  nav, held); break;
        case 0x39:
            if (!held && (nav & 0x1c))
                g_sfxOn = (g_sfxOn == 0);
            break;
        case 0x3b:
            if (!held && (nav & 0x1c))
                g_cdOn = (g_cdOn == 0);
            break;
        default:
            break;
        }
    } else if (g_menuState == 3) {
        g_menuState = 0;
    }

    /* rebuild every value field, then paint */
    for (row = (MenuRow *)SOUND_MENU; row->text != 0; row++) {
        const char *val = 0;

        switch (row->action) {
        case 0x38: Helper_Sprintf(g_menuScratch, FMT_PERCENT, g_sfxVolume); break;
        case 0x3a: Helper_Sprintf(g_menuScratch, FMT_PERCENT, g_cdVolume);  break;
        case 0x39: val = g_sfxOn ? TXT_ON : TXT_OFF; break;
        case 0x3b: val = g_cdOn  ? TXT_ON : TXT_OFF; break;
        default:   continue;
        }
        if (val)
            Helper_Sprintf(g_menuScratch, FMT_STRING, val);
        Menu_FillColonField(&row->text, g_menuScratch);
    }

    DrawMenu(SOUND_MENU, (int)g_menuSel);
    return (int)g_menuState;
}

#endif /* NON_MATCHING */
