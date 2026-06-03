/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_phaseTimer;

/* @addr 0x004353f0 (65b)
 *   call F1; test eax → jne ret
 *   call F2; pause → jne ret
 *   load g_walkCallback; test → jge skip → jmp T_inner
 *   load g_fightStateProgress; cmp 0x30000; store; jle → jmp T1; jmp T2
 *   ret
 */
extern void Cmp2CallDirtyCall(void);
extern void Wrapper_ScaledIndexCondCopy(void);
extern unsigned int g_fightStateProgress;
extern void TriEntryGateMain(void);
extern void GuardedSeq_PackedSelectLoad6_then_GuardedSeq(void);
extern void PrefixThunkInstallSelf3State(void);
void DualCallTestPauseRange(void) {
    int state_y;
    if (((int (*)(void))Cmp2CallDirtyCall)() != 0) return;
    Wrapper_ScaledIndexCondCopy();
    if (g_framePauseFlag != 0) return;
    if ((int)g_walkCallback < 0) {
        TriEntryGateMain();
        return;
    }
    state_y = (int)g_fightStateProgress;
    g_walkCallback = (void (*)(void))state_y;
    if (state_y > 0x30000) {
        GuardedSeq_PackedSelectLoad6_then_GuardedSeq();
        return;
    }
    PrefixThunkInstallSelf3State();
}
