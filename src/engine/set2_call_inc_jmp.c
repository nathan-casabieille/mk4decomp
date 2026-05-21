/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00472860 (36b)
 *   mov     [g_walkCallback], 2
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .skip
 *   inc     dword ptr [g_walkCallback]
 *   jmp     T
 * .skip:
 *   ret
 */
extern void func_004ab620(void);
extern void func_00489f7e(void);
void Set2CallIncJmp_00472860(void) {
    g_walkCallback = (void (*)(void))2;
    func_004ab620();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))((unsigned int)g_walkCallback + 1);
    func_00489f7e();
}
