/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004af650 (56b)
 *   if g_state_0058c7d4 != 0:
 *     load [eax]; call vtable[+8](eax); store ret to g_renderer2_present_rc;
 *   load g_state_0058c7c4; clear g_state_0058c7d4;
 *   if g_state_0058c7c4 != 0: call vtable[+8](eax);
 *   clear g_state_0058c7c4; ret.
 */
extern unsigned int g_state_0058c7d4;
extern unsigned int g_state_0058c7c4;
extern int g_renderer2_present_rc;
void DualVtable8Call_004af650(void) {
    void *p1 = g_state_0058c7d4;
    void *p2;
    if (p1) {
        g_renderer2_present_rc = ((unsigned int (__stdcall **)(void*))(*(void**)p1))[2](p1);
    }
    p2 = g_state_0058c7c4;
    g_state_0058c7d4 = 0;
    if (p2) {
        ((unsigned int (__stdcall **)(void*))(*(void**)p2))[2](p2);
    }
    g_state_0058c7c4 = 0;
}
