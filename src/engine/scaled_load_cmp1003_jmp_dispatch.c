/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00486530 (68b)
 *   load baseSel*4+0x74; cmp 0x1003; jne →skip; call F1; pause →ret;
 *   call F2; pause →ret; set walk=0x3b; jmp T.
 */
extern void MStackPush2TripleCallChain(void);
extern void GuardedScaled_MStackPush8_then_PendingMatch(void);
extern void TableLookupCall_00489ff0(void);
void ScaledLoadCmp1003JmpDispatch(void) {
    unsigned int v = ((ScenegraphNode *)(g_baseSel * 4))->fsm_state;
    g_walkCallback = (void (*)(void))v;
    if (v != 0x1003) return;
    MStackPush2TripleCallChain();
    if (g_framePauseFlag != 0) return;
    GuardedScaled_MStackPush8_then_PendingMatch();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x3b;
    TableLookupCall_00489ff0();
}
