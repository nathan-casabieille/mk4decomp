/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_x_00537e94_v2;

/* @addr 0x004353f0 (65b)
 *   call F1; test eax → jne ret
 *   call F2; pause → jne ret
 *   load g_walkCallback; test → jge skip → jmp T_inner
 *   load g_table_00535ddc; cmp 0x30000; store; jle → jmp T1; jmp T2
 *   ret
 */
extern void Cmp2CallDirtyCall_004398b0(void);
extern void Wrapper_00439310(void);
extern unsigned int g_state_00535ddc_y;
extern void TriEntryGateMain_00435440(void);
extern void GuardedSeq_00433bb0(void);
extern void PrefixThunkInstallSelf3State_00438f80(void);
void DualCallTestPauseRange_004353f0(void) {
    int state_y;
    if (((int (*)(void))Cmp2CallDirtyCall_004398b0)() != 0) return;
    Wrapper_00439310();
    if (g_framePauseFlag != 0) return;
    if ((int)g_walkCallback < 0) {
        TriEntryGateMain_00435440();
        return;
    }
    state_y = (int)g_state_00535ddc_y;
    g_walkCallback = (void (*)(void))state_y;
    if (state_y > 0x30000) {
        GuardedSeq_00433bb0();
        return;
    }
    PrefixThunkInstallSelf3State_00438f80();
}
