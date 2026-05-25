/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00423870 (55b)
 *   mov     eax, [0x0052aac4]
 *   cmp     eax, 2
 *   mov     [g_walkCallback], eax
 *   je      +0x0e
 *   mov     eax, [0x00542004]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   mov     eax, [g_xformDirtyFlags]
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_tickFlagF;
extern u32 g_dlMode;
void Cmp2DirtyToggle_00423870(void) {
    unsigned int state;
    unsigned int mode;
    state = g_tickFlagF;
    g_walkCallback = (void (*)(void))state;
    if (state == 2) goto clear_bit;
    mode = g_dlMode;
    g_walkCallback = (void (*)(void))mode;
    if (mode == 0) goto clear_bit;
    g_xformDirtyFlags |= 1;
    return;
clear_bit:
    g_xformDirtyFlags &= 0xfffffffe;
}
