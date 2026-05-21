/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004ac520 (70b)
 *   if g_state_00543904 != 0:
 *     call F; if ret == 0:
 *       load g_state_005438e8; push 0,2,0x808,it,IAT;
 *     if g_state_00543900 == 0: clear via IAT [g_iat_00...4022240];
 *     g_state_00543900 = ret; clear g_state_00543904.
 */
extern unsigned int g_state_00543904;
extern unsigned int g_state_00543900;
extern unsigned int g_state_005438e8;
extern int func_004ac318(void);
extern void (__stdcall *g_iat_004d2244)(int, int, int, int);
extern int (__stdcall *g_iat_004d2240)(void);
void Helper_TitleEnterStateC(void) {
    if (g_state_00543904 != 0 && func_004ac318() != 0) {
        g_iat_004d2244((int)g_state_005438e8, 0x808, 2, 0);
    }
    if (g_state_00543900 == 0) {
        g_state_00543900 = (unsigned int)g_iat_004d2240();
    }
    g_state_00543904 = 0;
}

