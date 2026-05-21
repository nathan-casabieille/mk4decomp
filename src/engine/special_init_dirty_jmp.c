/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x00446000 (61b)
 *   set g_xformEntityIdx = 0x51140c >> 2; call F; pause → ret;
 *   testb 4,[dirty]; jne ret; load baseSel, scaled, store into [ecx*4 + 0x5c]; jmp T.
 */
extern void MStackBracket1_TreeWalkRecursive2_00406dd0(void);
extern void ScaledTestPauseStore_00408860(void);
extern unsigned int g_table_0051140c;
void SpecialInitDirtyJmp_00446000(void) {
    g_xformEntityIdx = (unsigned int)&g_table_0051140c >> 2;
    MStackBracket1_TreeWalkRecursive2_00406dd0();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((g_xformDirtyFlags & 4) != 0) {
        return;
    }
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x5c) = g_scaledInit_00542044;
    ScaledTestPauseStore_00408860();
}
