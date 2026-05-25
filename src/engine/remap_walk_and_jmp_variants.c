/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00491e70 (80b)
 *   walk = [0x537f48]; if walk == 0xf, walk = 6;
 *   if walk == 0x10, walk = 2; if walk == 0x11, walk = 7;
 *   eventQueueCurrent = 1; eventQueueWorkType = 0xffff0000; jmp T.
 */
extern s32 g_dlNalt1;
extern void ThrowPoseCallbackSetup_00491f10(void);
void RemapWalkAndJmp_00491e70(void) {
    unsigned int v = g_dlNalt1;
    g_walkCallback = (void (*)(void))v;
    if (v == 0x0f) {
        v = 6;
        g_walkCallback = (void (*)(void))v;
    }
    if (v == 0x10) {
        v = 2;
        g_walkCallback = (void (*)(void))v;
    }
    if (v == 0x11) {
        g_walkCallback = (void (*)(void))7;
    }
    g_eventQueueCurrent = 1;
    g_eventQueueWorkType = 0xffff0000;
    ThrowPoseCallbackSetup_00491f10();
}

/* @addr 0x00491ec0 (80b)
 *   Same as RemapWalkAndJmp_00491e70 but loads [0x5380e0]; sets
 *   eventQueueCurrent = 0 and eventQueueWorkType = 0x10000.
 */
extern s32 g_dlNalt2;
void RemapWalkAndJmp_00491ec0(void) {
    unsigned int v = g_dlNalt2;
    g_walkCallback = (void (*)(void))v;
    if (v == 0x0f) {
        v = 6;
        g_walkCallback = (void (*)(void))v;
    }
    if (v == 0x10) {
        v = 2;
        g_walkCallback = (void (*)(void))v;
    }
    if (v == 0x11) {
        g_walkCallback = (void (*)(void))7;
    }
    g_eventQueueCurrent = 0;
    g_eventQueueWorkType = 0x10000;
    ThrowPoseCallbackSetup_00491f10();
}
