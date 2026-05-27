/**
 * Auto-split from misc_matchesX.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern void Mul10Tail_00404af0(void);

/* @addr 0x00457ff0 (62b)
 *   call F1; pause-test +0x2f → ret
 *   call F2; pause-test +0x21 → ret
 *   call F3; pause-test +0x13 → ret
 *   call F4; pause-test +0x05 → ret
 *   jmp     T
 *   ret
 */
extern void DoublePackedPtrInstall_00458ba0(void);
extern void DualPathCallSetup_00458030(void);
extern void Screen_EnterInitials(void);
extern void CameraProjectionInitSweep_00458160(void);
extern void SpawnTrioInitCluster_00458440(void);
void QuadCallPauseJmp_00457ff0(void) {
    DoublePackedPtrInstall_00458ba0();
    if (g_framePauseFlag != 0) {
        return;
    }
    DualPathCallSetup_00458030();
    if (g_framePauseFlag != 0) {
        return;
    }
    Screen_EnterInitials();
    if (g_framePauseFlag != 0) {
        return;
    }
    CameraProjectionInitSweep_00458160();
    if (g_framePauseFlag != 0) {
        return;
    }
    SpawnTrioInitCluster_00458440();
}
