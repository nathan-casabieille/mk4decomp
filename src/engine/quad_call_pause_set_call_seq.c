/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00451550 (68b): 4-call pause cleanup with set walk=5 then walk=6 */
extern void func_004089e0_kk(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void GuardedSeq_004515a0(void);
extern void GuardedSeq_004515a0(void);
void QuadCallPauseSetCallSeq_00451550(void) {
    func_004089e0_kk();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))5;
    GuardedSeq_004515a0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))6;
    GuardedSeq_004515a0();
}
