/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004cc030 (61b)
 *   if (g_state_00f9f84c == 1 || (==0 && g_state_00520064 == 1)):
 *     call F2(0xfc); call (g_state_00f9fbfc); call F2(0xff).
 */
extern unsigned int g_state_00f9f84c_gg;
extern unsigned int g_state_00520064;
extern void (*g_state_00f9fbfc)(void);
extern void func_004cc070_gg(int);
void DualCondCleanupCall_004cc030(void) {
    unsigned int v = g_state_00f9f84c_gg;
    if (v != 1) {
        if (v != 0) return;
        if (g_state_00520064 != 1) return;
    }
    func_004cc070_gg(0xfc);
    if (g_state_00f9fbfc != 0) {
        g_state_00f9fbfc();
    }
    func_004cc070_gg(0xff);
}
