/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x0042f850 (69b)
 *   eax = [0x52aac4]; cmp eax, 2; mov [walk] = eax; jne +5; jmp T1.
 *   else: mov fightGroupHead = [0x52ab10]; call F1; pause → ret;
 *   mov [g_baseSel*4 + 0x64] = walk; jmp T2.
 */
extern unsigned int g_data_0052aac4;
extern unsigned int g_data_0052ab10;
extern unsigned int g_baseSel_00542060;
extern void StoreByteJmp_0042f840(void);
extern void CameraAimSplineDriver_00430e60(void);
extern void PhaseInstall2DInterpDispatch_0042f8a0(void);
void DispatchOrInitFightGroup_0042f850(void) {
    unsigned int v = g_data_0052aac4;
    g_walkCallback = (void(*)(void))v;
    if (v == 2) {
        StoreByteJmp_0042f840();
        return;
    }
    g_fightGroupHead = g_data_0052ab10;
    CameraAimSplineDriver_00430e60();
    if (g_framePauseFlag) return;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x64) = (unsigned int)g_walkCallback;
    PhaseInstall2DInterpDispatch_0042f8a0();
}
