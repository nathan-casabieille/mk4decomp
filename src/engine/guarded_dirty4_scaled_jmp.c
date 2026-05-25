/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00473d50 (75b)
 *   call F1; pause → ret; if (dirty & 4) jmp T1; call F2;
 *   pause → ret; call F3; pause → ret; walk = 0x4ec9e8 >> 2;
 *   jmp T2.
 */
extern void SetJmp_00405420(void);
extern void ScaledLoadStore_00473ed0(void);
extern void TripleChainSetupDualCall_00473da0(void);
extern unsigned int g_table_004ec9e8;
void GuardedDirty4ScaledJmp_00473d50(void) {
    SetJmp_00405420();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((g_xformDirtyFlags & 4) == 0) {
        ScaledLoadStore_00473ed0();
        return;
    }
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag != 0) {
        return;
    }
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_walkCallback = (void (*)(void))((unsigned int)&g_table_004ec9e8 >> 2);
    TripleChainSetupDualCall_00473da0();
}
