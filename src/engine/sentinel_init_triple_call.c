/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x0048bbf0 (73b)
 *   eax = 0x8a9dcbef; [0x53e35c] = 0xfedcba98; walk = eax;
 *   [0x541dbc] = eax. Then 3 chained calls with pause-test → ret;
 *   final call → jmp T.
 */
extern unsigned int g_phase1ModelChain;
extern unsigned int g_dispatchSave415;
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
