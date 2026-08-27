/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x0048bbf0 (73b)
 *   eax = 0x8a9dcbef; [0x53e35c] = 0xfedcba98; walk = eax;
 *   [0x541dbc] = eax. Then 3 chained calls with pause-test → ret;
 *   final call → jmp T.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_phase1ModelChain;
extern unsigned int g_dispatchSave415;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave415 (*(unsigned int *)MK4_VA(unsigned int, 0x541dbcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_phase1ModelChain (*(unsigned int *)MK4_VA(unsigned int, 0x53e35cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

extern void DualEntryInitCmp(void);
extern void Thunk_ZeroLargeBlock(void);
extern void Init6Globals(void);
extern void PendingMatch_ZeroNDwords(void);
void SentinelInitTripleCall(void) {
    g_phase1ModelChain = 0xfedcba98;
    g_walkCallback = (void(*)(void))0x8a9dcbef;
    g_dispatchSave415 = 0x8a9dcbef;
    DualEntryInitCmp();
    if (g_framePauseFlag) return;
    Thunk_ZeroLargeBlock();
    if (g_framePauseFlag) return;
    Init6Globals();
    if (g_framePauseFlag) return;
    PendingMatch_ZeroNDwords();
}
