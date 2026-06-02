/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004cc030 (61b)
 *   if (g_crtCleanupFlag == 1 || (==0 && g_crtFdCloseSlot == 1)):
 *     call F2(0xfc); call (g_dispatchSave1442); call F2(0xff).
 */
extern unsigned int g_crtCleanupFlag;
extern unsigned int g_crtFdCloseSlot;
extern void (*g_dispatchSave1442)(void);
extern void func_004cc070_gg(int);
void DualCondCleanupCall(void) {
    unsigned int v = g_crtCleanupFlag;
    if (v != 1) {
        if (v != 0) return;
        if (g_crtFdCloseSlot != 1) return;
    }
    func_004cc070_gg(0xfc);
    if (g_dispatchSave1442 != 0) {
        g_dispatchSave1442();
    }
    func_004cc070_gg(0xff);
}
