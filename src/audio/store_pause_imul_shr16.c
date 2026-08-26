/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x004ab630 (53b)
 *   load g_walkCallback; store to g_dispatchSave_00538150;
 *   call F; pause-test → ret;
 *   load walk; and 0xffff; imul g_dispatchSave_00538150; shr 16; store walk.
 */
extern unsigned int g_dispatchSave_00538150;
extern void DualAddSar(void);
void StorePauseImulShr16(void) {
    g_dispatchSave_00538150 = (unsigned int)g_walkCallback;
    DualAddSar();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_walkCallback = (void (*)(void))((((unsigned int)g_walkCallback & 0xffff) * g_dispatchSave_00538150) >> 16);
}
