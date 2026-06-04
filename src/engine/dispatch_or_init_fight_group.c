/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x0042f850 (69b)
 *   eax = [0x52aac4]; cmp eax, 2; mov [walk] = eax; jne +5; jmp T1.
 *   else: mov fightGroupHead = [0x52ab10]; call F1; pause → ret;
 *   mov [g_baseSel*4 + 0x64] = walk; jmp T2.
 */
extern unsigned int g_tickFlagF;
extern unsigned int g_eventQueueSeed;
extern unsigned int g_baseSel;
extern void StoreByteJmp(void);
extern void CameraAimSplineDriver(void);
extern void PhaseInstall2DInterpDispatch(void);
void DispatchOrInitFightGroup(void) {
    unsigned int v = g_tickFlagF;
    g_walkCallback = (void(*)(void))v;
    if (v == 2) {
        StoreByteJmp();
        return;
    }
    g_fightGroupHead = g_eventQueueSeed;
    CameraAimSplineDriver();
    if (g_framePauseFlag) return;
    *(unsigned int *)(g_baseSel * 4 + 0x64) = (unsigned int)g_walkCallback;
    PhaseInstall2DInterpDispatch();
}
