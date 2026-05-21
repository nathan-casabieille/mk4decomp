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

/* @addr 0x00451550 (68b): 4-call pause cleanup with set walk=5 then walk=6 */
extern void func_004089e0_kk(void);
extern void func_004b8f90(void);
extern void func_00451580(void);
extern void func_00451598(void);
void QuadCallPauseSetCallSeq_00451550(void) {
    func_004089e0_kk();
    if (g_framePauseFlag != 0) return;
    func_004b8f90();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))5;
    func_00451580();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))6;
    func_00451598();
}
