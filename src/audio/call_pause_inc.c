/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ab670 (21b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +6
 *   inc     dword ptr [g_walkCallback]
 *   ret
 */
extern void StorePauseImulShr16_004ab630(void);
void CallPauseInc_004ab670(void) {
    StorePauseImulShr16_004ab630();
    if (g_framePauseFlag == 0) {
        g_walkCallback = (void (*)(void))((unsigned int)g_walkCallback + 1);
    }
}
