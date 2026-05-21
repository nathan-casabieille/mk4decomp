/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048d0c0 (48b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      ah, 8
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern void func_00426d80(void);
extern void func_00414fa6(void);
void ScaledOrAh8CallPauseJmp_0048d0c0(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x34) | 0x800;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(idx * 4 + 0x34) = v;
    func_00426d80();
    if (g_framePauseFlag != 0) return;
    func_00414fa6();
}
