/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0046a520 (50b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_table_00535ddc]
 *   cmp     eax, 0x00030000
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     +0x1c
 *   push    0x004eabb0
 *   call    F2
 *   add     esp, 4
 *   ret
 */
extern unsigned int g_table_00535ddc;
extern void ScaledZeroFour_00490740(void);
extern void ArgSarStoreJmp_004594f0(void *p);
extern void *g_dispatchSave1280_004eabb0;
extern void GuardedPushCall_0046a560(void);
void CallPauseCmpStateJmp_0046a520(void) {
    unsigned int v;
    ScaledZeroFour_00490740();
    if (g_framePauseFlag != 0) return;
    v = g_table_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if ((int)v > 0x30000) {
        GuardedPushCall_0046a560();
        return;
    }
    ArgSarStoreJmp_004594f0(&g_dispatchSave1280_004eabb0);
}
