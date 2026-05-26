/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bd510 (22b)
 *   mov     eax, [g_scaledInit_00542044]
 *   lea     ecx, [eax*4 + 0x48]
 *   push    ecx
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int CleanupCallTwice_004bd530(void *);
void LeaScaledCall_004bd510(void) {
    CleanupCallTwice_004bd530((void *)(g_scaledInit_00542044 * 4 + 0x48));
}
