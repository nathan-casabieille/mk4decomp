/**
 * Auto-split from misc_matchesX.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern void Mul10Tail(void);

/* @addr 0x00457ff0 (62b)
 *   call F1; pause-test +0x2f → ret
 *   call F2; pause-test +0x21 → ret
 *   call F3; pause-test +0x13 → ret
 *   call F4; pause-test +0x05 → ret
 *   jmp     T
 *   ret
 */
extern void DoublePackedPtrInstall(void);
extern void DualPathCallSetup(void);
extern void Screen_EnterInitials(void);
extern void CameraProjectionInitSweep(void);
extern void SpawnTrioInitCluster(void);
void QuadCallPauseJmp(void) {
    DoublePackedPtrInstall();
    if (g_framePauseFlag != 0) {
        return;
    }
    DualPathCallSetup();
    if (g_framePauseFlag != 0) {
        return;
    }
    Screen_EnterInitials();
    if (g_framePauseFlag != 0) {
        return;
    }
    CameraProjectionInitSweep();
    if (g_framePauseFlag != 0) {
        return;
    }
    SpawnTrioInitCluster();
}
