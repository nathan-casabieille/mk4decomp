/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x0048f6d0 (73b)
 *   call F; pause → ret; if (dirty & 4) → ret;
 *   ecx = fightGroupHead; edx = [0x538158]; eax = [0x542038];
 *   xformEntityIdx = eax; cmp ecx,edx; if !=, eax = [0x54203c],
 *   xformEntityIdx = eax; edx = g_currentNodeIdx;
 *   [eax*4+0] = edx; ret.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave416;
extern unsigned int g_dispatchSave417;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave416 (*(unsigned int *)MK4_VA(unsigned int, 0x542038u))
#define g_dispatchSave417 (*(unsigned int *)MK4_VA(unsigned int, 0x54203cu))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_player1NodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x538158u))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif

extern void DirtyToggleByGate(void);
void GuardedDirtyXformFromTable(void) {
    unsigned int v;
    DirtyToggleByGate();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    v = g_dispatchSave416;
    g_xformEntityIdx = v;
    if (g_fightGroupHead != g_player1NodeIdx) {
        v = g_dispatchSave417;
        g_xformEntityIdx = v;
    }
    *(unsigned int *)MK4_PTR((v * 4)) = g_currentNodeIdx;
}
