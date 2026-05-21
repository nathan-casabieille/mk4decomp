/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00439b50 (39b)
 *   mov     [g_walkCallback], 0x258
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      .doit
 *   jmp     T
 * .doit:
 *   ret    (actually fall-through to next; je 5 then jmp tail)
 *
 * Wait let me re-check: c7 05 6c 20 54 00 58 02 00 00 e8 31 1b 07 00 a1 6c 1e 54 00 85 c0 75 0e f6 05 8c 20 54 00 01 74 05 e9 aa 00 00 00 c3
 * Decoded:
 * - mov [g_walkCallback], 0x258
 * - call F
 * - mov eax, [g_framePauseFlag]
 * - test eax, eax
 * - jne +0xe (taken if pause)
 * - test byte [g_xformDirtyFlags], 1
 * - je +5 (taken if NOT dirty)
 * - jmp T
 * - ret
 */
extern void AudioVolumeRescale_004ab690(void);
extern void func_00439bff(void);
void Set258Call_PauseDirtyJmp_00439b50(void) {
    g_walkCallback = (void (*)(void))0x258;
    AudioVolumeRescale_004ab690();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) == 0) return;
    func_00439bff();
}
