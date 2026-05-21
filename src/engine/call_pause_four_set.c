/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_pendingNodeType;
extern packed_ptr g_fightGroupHead;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00482be0 (68b): set 1, call F1, pause, set 0x9999, call F2, pause, call F3, pause, jmp T */
extern void func_0048a456(void);
extern void func_00482a8e(void);
extern void func_00489248(void);
extern void func_00482c50(void);
void CallPauseFourSet_00482be0(void) {
    g_walkCallback = (void (*)(void))1;
    func_0048a456();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x9999;
    func_00482a8e();
    if (g_framePauseFlag != 0) return;
    func_00489248();
    if (g_framePauseFlag != 0) return;
    func_00482c50();
}
