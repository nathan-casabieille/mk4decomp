/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004838d0 (44b)
 *   mov     [g_walkCallback], 0x1f4
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      +5
 *   jmp     T1
 *   jmp     +5
 *   ret
 */
extern void AudioVolumeRescale_004ab690(void);
extern void func_004874f0(void);
extern void func_00483906(void);
void Set1f4CallDirtyJmp_004838d0(void) {
    g_walkCallback = (void (*)(void))0x01f4;
    AudioVolumeRescale_004ab690();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) != 0) {
        func_004874f0();
        return;
    }
    func_00483906();
}
