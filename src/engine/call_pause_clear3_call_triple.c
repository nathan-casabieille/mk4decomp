/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00428030 (78b)
 *   call F; pause-test → ret; clear walk + state_00538158 + state_0053815c;
 *   call F2; pause → ret; call F3; pause → ret; jmp T.
 */
extern void BootInitChainHeavy_00404f20(void);
extern unsigned int g_player1NodeIdx;
extern unsigned int g_state_0053815c_kk;
extern void DualEntryInitCmp_00425b20(void);
extern void StageParticleEmitterInit_00464350(void);
extern void func_00431230(void);
void CallPauseClear3CallTriple_00428030(void) {
    BootInitChainHeavy_00404f20();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = 0;
    g_player1NodeIdx = 0;
    g_state_0053815c_kk = 0;
    DualEntryInitCmp_00425b20();
    if (g_framePauseFlag != 0) return;
    StageParticleEmitterInit_00464350();
    if (g_framePauseFlag != 0) return;
    func_00431230();
}
