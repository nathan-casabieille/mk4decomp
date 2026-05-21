/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00414fe0 (40b)
 *   mov     [g_walkCallback], 0xb1
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], 0xb2
 *   jmp     T
 *   ret
 */
extern void func_0049cc28(void);
extern void func_00414e3c(void);
void SetCallSetJmp_00414fe0(void) {
    g_walkCallback = (void (*)(void))0xb1;
    func_0049cc28();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_walkCallback = (void (*)(void))0xb2;
    func_00414e3c();
}
