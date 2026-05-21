/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048fa20 (44b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_scaledInit_00542044], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void CopyJmp_00406ba0(void);
extern void func_00490d30(void);
extern void func_0049020a(void);
void StoreCallPauseCallPauseJmp_0048fa20(void) {
    g_scaledInit_00542044 = g_fightGroupHead;
    CopyJmp_00406ba0();
    if (g_framePauseFlag != 0) return;
    func_00490d30();
    if (g_framePauseFlag != 0) return;
    func_0049020a();
}
