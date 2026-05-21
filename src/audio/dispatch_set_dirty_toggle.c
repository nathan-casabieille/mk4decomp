/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x004ac150 (69b)
 *   ecx = g_fightGroupHead; edx = [0x538158]; eax = [0x53a510];
 *   walk = eax; if ecx == edx, skip override; else
 *     eax = [0x52aafc]; walk = eax;
 *   edx = dirty; ecx = 4; edx |= 4; flag if eax == 0; store edx;
 *   if eax == 0: ret; else clear bit 4 (xor): store edx ^ 4.
 */
extern unsigned int g_data_0052aafc;
extern unsigned int g_data_0053a510;
void DispatchSetDirtyToggle_004ac150(void) {
    unsigned int v = g_data_0053a510;
    g_walkCallback = (void (*)(void))v;
    if (g_fightGroupHead != g_data_00538158) {
        v = g_data_0052aafc;
        g_walkCallback = (void (*)(void))v;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 4;
    if (v != 0) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
}
