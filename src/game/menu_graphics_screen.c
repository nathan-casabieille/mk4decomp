/**
 * The GRAPHICS options screen - 0x4b81f0 (722b).
 *
 * Third of the five mode screens, and the last of the simple ones. Its
 * table at 0x4f5178 names it: DISPLAY, LIGHTING, GAMMA, GO BACK. The
 * symbol name Helper_GSM_Config is the auto-namer's positional guess.
 *
 *   66 DISPLAY   1..5, select wraps as (v % 5) + 1 - it is ONE-based, and
 *                the five labels are GLIDE 3D CARD, DIRECT3D CARD,
 *                FULLSCREEN S/W, WINDOW S/W, HIRES S/W
 *   67 LIGHTING  toggle -> ON / OFF
 *   68 GAMMA     stepped by TWO between 2 and 0x62, and each step calls
 *                the renderer's post-init so the change takes effect
 *
 * One faithful oddity: the GAMMA case is the only editor in any of these
 * screens that does NOT gate on the repeat-suppression bit, so holding
 * left or right ramps it continuously while every other row moves once
 * per press. That is what the original does.
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
extern void Helper_RendererPostInit(int gamma);

#define g_gfxFlags   (*(unsigned char *)MK4_VA(unsigned char, 0xab42fcu))
#define g_gfxSel     (*(unsigned int  *)MK4_VA(unsigned int,  0xab42c8u))
#define g_gfxState   (*(unsigned int  *)MK4_VA(unsigned int,  0xab435cu))
#define g_menuScratch ((char *)MK4_VA(char, 0xab41c8u))

#define g_display    (*(int *)MK4_VA(int, 0x543aa4u))
#define g_lighting   (*(int *)MK4_VA(int, 0x543aa8u))
#define g_gamma      (*(int *)MK4_VA(int, 0x543a94u))

#define GFX_MENU     MK4_VA(void, 0x4f5178u)
#define TXT_ON       ((const char *)MK4_VA(char, 0x4f42d8u))
#define TXT_OFF      ((const char *)MK4_VA(char, 0x4f42dcu))
#define FMT_PERCENT  ((const char *)MK4_VA(char, 0x4f6188u))

typedef struct { unsigned int text; short action; short pad; } MenuRow;

/* one-based, in the order the original stacks them */
static const unsigned int gfx_display_names[5] = {
    0x4f6224u, 0x4f6214u, 0x4f6204u, 0x4f61f8u, 0x4f61ecu
};

int Helper_GSM_Config(void)
{
    unsigned int nav = 0, held = 0;
    MenuRow *row;

    if ((g_gfxFlags & 1) == 0) {
        g_gfxFlags |= 1;
        g_gfxSel = (unsigned int)Menu_FindNextSelectable(0, GFX_MENU);
    }

    if (g_gfxState == 0)
        g_gfxState = 2;

    if (g_gfxState == 2) {
        nav  = Menu_PollNavInput(1);
        held = nav & 0x8000u;

        if (!held && (nav & 1))
            g_gfxSel = (unsigned int)Menu_FindPrevSelectable((int)g_gfxSel, GFX_MENU);
        if (!held && (nav & 2))
            g_gfxSel = (unsigned int)Menu_FindNextSelectable((int)g_gfxSel, GFX_MENU);
        if (!held && (nav & 0x20))
            g_gfxState = 3;

        row = (MenuRow *)GFX_MENU + g_gfxSel;
        switch (row->action) {
        case 3:
            if (!held && (nav & 0x10))
                g_gfxState = 3;
            break;
        case 66:
            if (!held && (nav & 4) && g_display > 1)
                g_display--;
            if (!held && (nav & 8) && g_display < 5)
                g_display++;
            if (!held && (nav & 0x10))
                g_display = (g_display % 5) + 1;
            break;
        case 67:
            if (!held && (nav & 0x1c))
                g_lighting = (g_lighting == 0);
            break;
        case 68:
            /* no held gate here - the original really does ramp gamma
             * while the key stays down */
            if ((nav & 4) && g_gamma >= 2) {
                g_gamma -= 2;
                Helper_RendererPostInit(g_gamma);
            }
            if ((nav & 8) && g_gamma <= 0x62) {
                g_gamma += 2;
                Helper_RendererPostInit(g_gamma);
            }
            break;
        default:
            break;
        }
    } else if (g_gfxState == 3) {
        g_gfxState = 0;
    }

    for (row = (MenuRow *)GFX_MENU; row->text != 0; row++) {
        const char *val = 0;

        switch (row->action) {
        case 66: {
            int i = g_display;
            if (i < 1) i = 1;
            if (i > 5) i = 5;
            val = (const char *)MK4_PTR(gfx_display_names[i - 1]);
            break;
        }
        case 67: val = g_lighting ? TXT_ON : TXT_OFF; break;
        case 68: Helper_Sprintf(g_menuScratch, FMT_PERCENT, g_gamma); break;
        default: continue;
        }
        Menu_FillColonField(&row->text, val ? val : g_menuScratch);
    }

    DrawMenu(GFX_MENU, (int)g_gfxSel);
    return (int)g_gfxState;
}

#endif /* NON_MATCHING */
