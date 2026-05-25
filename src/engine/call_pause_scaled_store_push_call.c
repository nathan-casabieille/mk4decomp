/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer_00537e94;

/* @addr 0x0045fca0 (65b)
 *   call F; pause → ret
 *   load baseSel; mov eax,0x2001; store walk and [ecx*4+0x74]
 *   push lit; call F2; pause → ret; add esp,4; jmp T
 */
extern void SlotPhaseResetInstallChain_0048e0e0(void);
extern int IterStepScaledStore24_00428730(void *);
extern void *g_data_00542958;
extern void SelfInstallPhaseDispatch_0045fd30(void);
void CallPauseScaledStorePushCall_0045fca0(void) {
    SlotPhaseResetInstallChain_0048e0e0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x2001;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x74) = 0x2001;
    IterStepScaledStore24_00428730(&g_data_00542958);
    if (g_framePauseFlag != 0) return;
    SelfInstallPhaseDispatch_0045fd30();
}
