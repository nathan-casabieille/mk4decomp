/**
 * Auto-split from misc_matchesLL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048e330 (70b)
 *   load g_fightGroupHead, g_player1NodeIdx; cmp; load g_dlNalt1;
 *   jne skip; load g_dlNalt2 → walk;
 *   load dirty | 4; cmp eax,6; if eq: dirty stays; else: dirty ^= 4;
 *   ret.
 */
extern unsigned int g_player1NodeIdx;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
void LoadCmpStateOrDirtyToggle_0048e330(void) {
    unsigned int v = g_dlNalt1;
    g_walkCallback = (void (*)(void))v;
    if (g_fightGroupHead != g_player1NodeIdx) {
        v = g_dlNalt2;
        g_walkCallback = (void (*)(void))v;
    }
    g_xformDirtyFlags |= 4;
    if (v != 6) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
}
