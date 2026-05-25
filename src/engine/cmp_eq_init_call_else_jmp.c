/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048d4b0 (78b)
 *   if walk == 8: g_scaledInit = 0x542db8>>2; call F; pause → ret;
 *   if (dirty & 1) → ret; push 0x1392; call F2; add esp, 4; ret.
 *   else: g_scaledInit = 0x542db8>>2; jmp F.
 */
extern void MStackChainInstallDispatch_0048d500(void);
extern void TableHitOrSchedule_004be7a0(int);
extern unsigned char g_data_00542db8;
void CmpEqInitCallElseJmp_0048d4b0(void) {
    if ((unsigned int)g_walkCallback == 8) {
        g_scaledInit_00542044 = (unsigned int)&g_data_00542db8 >> 2;
        MStackChainInstallDispatch_0048d500();
        if (g_framePauseFlag != 0) return;
        if ((g_xformDirtyFlags & 1) != 0) return;
        TableHitOrSchedule_004be7a0(0x1392);
        return;
    }
    g_scaledInit_00542044 = (unsigned int)&g_data_00542db8 >> 2;
    MStackChainInstallDispatch_0048d500();
}
