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

/* @addr 0x00460260 (66b)
 *   call F1; pause → ret; call F2; pause → ret;
 *   set walk = 0xc; inc g_state_004d57ac;
 *   push 0x004602b0 onto stack[idx*4]; jmp T.
 */
extern void ScaledZeroFour_00490740(void);
extern void ScaledInit_0048f720(void);
extern void func_004602b0_pp(void);
extern void MstackPopScaledChainPlusThunks_00471250(void);
void GuardedDoubleCallSetJmp_00460260(void) {
    unsigned int top;
    ScaledZeroFour_00490740();
    if (g_framePauseFlag != 0) {
        return;
    }
    ScaledInit_0048f720();
    if (g_framePauseFlag != 0) {
        return;
    }
    top = g_state_004d57ac;
    g_walkCallback = (void (*)(void))0x0c;
    top++;
    g_state_004d57ac = top;
    *(unsigned int *)(top * 4) = (unsigned int)&func_004602b0_pp;
    MstackPopScaledChainPlusThunks_00471250();
}
