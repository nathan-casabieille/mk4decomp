/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00470500 (48b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret2
 *   call    F3
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void func_00488282(void);
extern void InitThreeFields_00490e90(void);
extern void func_00490c14(void);
extern void ScaledChainNegStore_00470310(void);
void TripleCallPauseJmp_00470500(void) {
    func_00488282();
    if (g_framePauseFlag != 0) return;
    InitThreeFields_00490e90();
    if (g_framePauseFlag != 0) return;
    func_00490c14();
    if (g_framePauseFlag != 0) return;
    ScaledChainNegStore_00470310();
}
