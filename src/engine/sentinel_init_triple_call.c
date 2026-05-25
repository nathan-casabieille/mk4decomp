/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048bbf0 (73b)
 *   eax = 0x8a9dcbef; [0x53e35c] = 0xfedcba98; walk = eax;
 *   [0x541dbc] = eax. Then 3 chained calls with pause-test → ret;
 *   final call → jmp T.
 */
extern unsigned int g_phase1ModelChain_0053e35c;
extern unsigned int g_dispatchSave415_00541dbc;
extern void DualEntryInitCmp_00425b20(void);
extern void Thunk_0049cbf0(void);
extern void Init6Globals_004051b0(void);
extern void PendingMatch_0045c8e0(void);
void SentinelInitTripleCall_0048bbf0(void) {
    g_phase1ModelChain_0053e35c = 0xfedcba98;
    g_walkCallback = (void(*)(void))0x8a9dcbef;
    g_dispatchSave415_00541dbc = 0x8a9dcbef;
    DualEntryInitCmp_00425b20();
    if (g_framePauseFlag) return;
    Thunk_0049cbf0();
    if (g_framePauseFlag) return;
    Init6Globals_004051b0();
    if (g_framePauseFlag) return;
    PendingMatch_0045c8e0();
}
