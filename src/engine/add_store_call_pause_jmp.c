/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00431da0 (47b)
 *   mov     eax, [g_eventQueueChild]
 *   add     eax, 0x00011f1f
 *   mov     [g_eventQueueWorkType], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x11
 *   mov     ecx, [g_walkCallback]
 *   mov     [g_eventQueueCurrent], ecx
 *   jmp     T
 *   ret
 */
extern void MStackMagicModMul10(void);
extern void ModMagicMul10Index(void);
void AddStoreCallPauseJmp(void) {
    g_eventQueueWorkType = g_xformScratch2088 + 0x0001921f;
    MStackMagicModMul10();
    if (g_framePauseFlag != 0) return;
    g_eventQueueCurrent = (unsigned int)g_walkCallback;
    ModMagicMul10Index();
}
