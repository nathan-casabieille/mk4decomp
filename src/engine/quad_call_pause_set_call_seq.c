/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00451550 (68b): 4-call pause cleanup with set walk=5 then walk=6 */
extern void func_004089e0_kk(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void GuardedSeq_ChainDirtyBitWalker_then_DualScaledLoadStoreJmp(void);
extern void GuardedSeq_ChainDirtyBitWalker_then_DualScaledLoadStoreJmp(void);
void QuadCallPauseSetCallSeq(void) {
    func_004089e0_kk();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))5;
    GuardedSeq_ChainDirtyBitWalker_then_DualScaledLoadStoreJmp();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))6;
    GuardedSeq_ChainDirtyBitWalker_then_DualScaledLoadStoreJmp();
}
