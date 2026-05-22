/**
 * Auto-split from misc_matchesAA.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueNotMask;
extern u32 g_eventQueueIdx;
extern u32 g_eventQueueEnd;

/* @addr 0x0046a1e0 (65b)
 *   set 0xa → walk; call F; pause → ret;
 *   load g_fightGroupHead, g_state_00538158; cmp; set 0x26 (or 0x27 if !eq); jmp T.
 */
extern unsigned int g_state_00538158;
extern void SpecialAnimBuilder_004937b0(void);
extern void func_00489ff0_aa(void);
void Set0xaCmpEqSet0x26Jmp_0046a1e0(void) {
    g_walkCallback = (void(*)(void))0x0a;
    SpecialAnimBuilder_004937b0();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))0x26;
    if (g_fightGroupHead != g_state_00538158) {
        g_walkCallback = (void(*)(void))0x27;
    }
    func_00489ff0_aa();
}
