/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ac150 (69b)
 *   ecx = g_fightGroupHead; edx = [0x538158]; eax = [0x53a510];
 *   walk = eax; if ecx == edx, skip override; else
 *     eax = [0x52aafc]; walk = eax;
 *   edx = dirty; ecx = 4; edx |= 4; flag if eax == 0; store edx;
 *   if eax == 0: ret; else clear bit 4 (xor): store edx ^ 4.
 */
extern u32 g_dlSomeFlag2;
extern u32 g_dlSomeFlag1;
void DispatchSetDirtyToggle_004ac150(void) {
    unsigned int v = g_dlSomeFlag1;
    g_walkCallback = (void (*)(void))v;
    if (g_fightGroupHead != g_player1NodeIdx) {
        v = g_dlSomeFlag2;
        g_walkCallback = (void (*)(void))v;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    if (v != 0) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
}
