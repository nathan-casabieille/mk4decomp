/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer;

/* @addr 0x0045fca0 (65b)
 *   call F; pause → ret
 *   load baseSel; mov eax,0x2001; store walk and [ecx*4+0x74]
 *   push lit; call F2; pause → ret; add esp,4; jmp T
 */
extern void SlotPhaseResetInstallChain(void);
extern int IterStepScaledStore24(void *);
extern void *g_dispatchSave419;
extern void SelfInstallPhaseDispatch_DualGatedStateYield_0045fd30(void);
void CallPauseScaledStorePushCall(void) {
    SlotPhaseResetInstallChain();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x2001;
    ((ScenegraphNode *)(g_baseSel * 4))->fsm_state = 0x2001;
    IterStepScaledStore24(&g_dispatchSave419);
    if (g_framePauseFlag != 0) return;
    SelfInstallPhaseDispatch_DualGatedStateYield_0045fd30();
}
