/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00421c50 (68b)
 *   if (g_clamp_0053a6dc == 0x10000) ret;
 *   if (g_clamp_00537f2c == 0x10000) ret;
 *   reset 3 globals to 0; call F; return 1.
 */
extern unsigned int g_clamp_0053a6dc;
extern unsigned int g_clamp_00537f2c;
extern unsigned int g_active_0053a408;
extern unsigned int g_active_00537e88;
extern void func_00420060(void);
int CmpDualStateMatch_00421c50(void) {
    unsigned int v;
    v = g_clamp_0053a6dc;
    g_walkCallback = (void (*)(void))v;
    if (v != 0x10000) return 0;
    v = g_clamp_00537f2c;
    g_walkCallback = (void (*)(void))v;
    if (v != 0x10000) return 0;
    g_walkCallback = 0;
    g_active_0053a408 = 0;
    g_active_00537e88 = 0;
    func_00420060();
    return 1;
}
