/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00486530 (68b)
 *   load baseSel*4+0x74; cmp 0x1003; jne →skip; call F1; pause →ret;
 *   call F2; pause →ret; set walk=0x3b; jmp T.
 */
extern void func_0048cf38(void);
extern void GuardedScaled_0040cd20(void);
extern void func_00489fb2(void);
void ScaledLoadCmp1003JmpDispatch_00486530(void) {
    unsigned int v = ((ScenegraphNode *)(g_baseSel_00542060 * 4))->fsm_state;
    g_walkCallback = (void (*)(void))v;
    if (v != 0x1003) return;
    func_0048cf38();
    if (g_framePauseFlag != 0) return;
    GuardedScaled_0040cd20();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x3b;
    func_00489fb2();
}
